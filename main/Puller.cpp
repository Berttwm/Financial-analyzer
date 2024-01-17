#include "../Header/Puller.H"
#include "../Header/ParserException.h";

/* Getter Methods */
rapidjson::Document& Puller::get_d_inc_stmt()
{
    return this->d_inc_stmt;
}
rapidjson::Document& Puller::get_d_bal_sheet()
{
    return this->d_bal_sheet;
}
rapidjson::Document& Puller::get_d_cash_flow()
{
    return this->d_cash_flow;
}


Puller::Puller(std::string ticker)
    :ticker(ticker) // TODO: Check valid ticker
{
    /* Step1: Upper case ticker before storage */
    std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
    /* Step 2: Pull statements from API Endpoints (For test, just read from json) */
    // Actual: Pull statements from API endpoint
    //this->pull_stmt_annual();
    // For testing: Read statements from stored json files
    this->read_stmt_annual_from_files(); // TEST METHOD

    /* Step 3: Parse JSON data*/
    this->parse_json();

}

void Puller::pull_stmt_annual()
{
    // Income statement url string
    std::stringstream income_statement_url_ss;
    income_statement_url_ss << "https://financialmodelingprep.com/api/v3/income-statement/" << this->ticker << "?limit=120&apikey=" << api_key;
    std::string income_statement_url = income_statement_url_ss.str();

    // Balance sheet url string
    std::stringstream balance_sheet_url_ss;
    balance_sheet_url_ss << "https://financialmodelingprep.com/api/v3/balance-sheet-statement/" << this->ticker << "?limit=120&apikey=" << api_key;
    std::string balance_sheet_url = balance_sheet_url_ss.str();

    // Cash flow url string
    std::stringstream cash_flow_url_ss;
    cash_flow_url_ss << "https://financialmodelingprep.com/api/v3/cash-flow-statement/" << this->ticker << "?limit=120&apikey=" << api_key;
    std::string cash_flow_url = cash_flow_url_ss.str();

    //std::cout << "inc stmt : " << income_statement_url << std::endl;
    //std::cout << "bal sheet : " << balance_sheet_url << std::endl;
    //std::cout << "cash flow : " << cash_flow_url << std::endl;

    // Get response from each of the 3 URLs
    cpr::Response resp_inc_stmt = cpr::Get(cpr::Url{ income_statement_url });
    cpr::Response resp_bal_sheet = cpr::Get(cpr::Url{ balance_sheet_url });
    cpr::Response resp_cash_flow = cpr::Get(cpr::Url{ cash_flow_url });
    //r.status_code;                  // 200
    //r.header["content-type"];       // application/json; charset=utf-8
    //std::string resp = r.text;                         // JSON text string

    // Exception checks on 3 URLs

    if (resp_inc_stmt.status_code != 200 || resp_bal_sheet.status_code != 200 || resp_cash_flow.status_code != 200)
        throw ParserException("Pull statement search resulted in unsuccessful HTTP response code");
    if (resp_inc_stmt.text == "[ ]" || resp_bal_sheet.text == "[ ]" || resp_cash_flow.text == "[ ]")
        throw ParserException("Pull statement search resulted in empty result");

    /* Intermediary step, save and load from file */
    std::ofstream inc_stmt_file;
    std::ofstream bal_sheet_file;
    std::ofstream cash_flow_file;

    inc_stmt_file.open("../files/inc_stmt.json");
    bal_sheet_file.open("../files/bal_sheet.json");
    cash_flow_file.open("../files/cash_flow.json");

    inc_stmt_file << resp_inc_stmt.text;
    bal_sheet_file << resp_bal_sheet.text;
    cash_flow_file << resp_cash_flow.text;

    inc_stmt_file.close();
    bal_sheet_file.close();
    cash_flow_file.close();

    this->inc_stmt_json_str = resp_inc_stmt.text;
    this->bal_sheet_json_str = resp_bal_sheet.text;
    this->cash_flow_json_str = resp_cash_flow.text;

    std::cout << "[*LOG] Successfully pulled income statement, balance sheet statement, and cash flow statement" << std::endl;
}

void Puller::read_stmt_annual_from_files()
{
    std::ifstream filepath("../files/" + ticker + "/inc_stmt.json");
    if (!filepath)
    {
        throw ParserException("The file doesn't exist");
    }

    std::ifstream inc_stmt_file("../files/" + ticker + "/inc_stmt.json");
    std::stringstream inc_stmt_ss;
    inc_stmt_ss << inc_stmt_file.rdbuf();
    inc_stmt_file.close();
    inc_stmt_json_str = inc_stmt_ss.str();


    std::ifstream bal_sheet_file("../files/" + ticker + "/bal_sheet.json");
    std::stringstream bal_sheet_ss;
    bal_sheet_ss << bal_sheet_file.rdbuf();
    bal_sheet_file.close();
    bal_sheet_json_str = bal_sheet_ss.str();

    std::ifstream cash_flow_file("../files/" + ticker + "/cash_flow.json");
    std::stringstream cash_flow_ss;
    cash_flow_ss << cash_flow_file.rdbuf();
    cash_flow_file.close();
    cash_flow_json_str = cash_flow_ss.str();

    //std::cout << "[*LOG] Successfully read statements from files" << std::endl;

}

void Puller::parse_json()
{
    //std::cout << bal_sheet_json_str << std::endl;
   // d_inc_stmt.Parse(inc_stmt_json_cstr);
   //std::cout << inc_stmt_json_str << std::endl;
   //d_inc_stmt = new rapidjson::Document();
    if (this->d_inc_stmt.Parse<0>(inc_stmt_json_str.c_str()).HasParseError()) throw std::runtime_error("[*ERROR] Unable to parse income statement");
    if (this->d_bal_sheet.Parse<0>(bal_sheet_json_str.c_str()).HasParseError()) throw std::runtime_error("[*ERROR] Unable to parse balance sheet");
    if (this->d_cash_flow.Parse<0>(cash_flow_json_str.c_str()).HasParseError()) throw std::runtime_error("[*ERROR] Unable to parse cash flow");

    // Test print method to play around with json parser - Example to play around with
    //      d_inc_stmt[0] = latest year, d_inc_stmt[1] = second latest year
    //      d_inc_stmt[0]["symbol"] = income statement latest year "symbol" 
    //std::string test_str_inc_stmt = d_inc_stmt[0]["symbol"].GetString();
    //std::string test_str_bal_sheet = d_bal_sheet[0]["symbol"].GetString();
    //std::string test_str_cash_flow = d_inc_stmt[0]["symbol"].GetString();
    //std::cout << "test string for inc stmt = " << test_str_inc_stmt << std::endl;
    //std::cout << "test string for bal sheet = " << test_str_bal_sheet << std::endl;
    //std::cout << "test string for cash flow = " << test_str_cash_flow << std::endl;

    //std::cout << "[*LOG] Successfully parsed Json" << std::endl;
}