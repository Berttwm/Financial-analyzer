#include "../Header/Puller.H"

Puller::Puller(std::string ticker)
    :ticker() // TODO: Check valid ticker
{
    /* Step1: Upper case ticker before storage */
    std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
    this->ticker = ticker;
    /* Step 2: Pull statements from API Endpoints (For test, just read from json) */
    // Actual: Pull statements from API endpoint
    // this->pull_stmt_annual();
    // For testing: Read statements from stored json files
    this->read_stmt_annual_from_files(); // TEST METHOD
    
    /* Step 3: Parse JSON data*/
    this->parse_json();
}

void Puller::pull_stmt_annual()
{
    // Income statement url string
    std::stringstream income_statement_url_ss;
    income_statement_url_ss << "https://financialmodelingprep.com/api/v3/income-statement/"<< this->ticker << "?limit=120&apikey=" << api_key;
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
        throw std::exception("Pull statement search resulted in unsuccessful HTTP response code");
    if (resp_inc_stmt.text == "[ ]" || resp_bal_sheet.text == "[ ]" || resp_cash_flow.text == "[ ]")
        throw std::exception("Pull statement search resulted in empty result");

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

    this->inc_stmt_json_cstr = resp_inc_stmt.text.c_str();
    this->bal_sheet_json_cstr = resp_bal_sheet.text.c_str();
    this->cash_flow_json_cstr = resp_cash_flow.text.c_str();

    std::cout << "[*LOG] Successfully pulled income statement, balance sheet statement, and cash flow statement" << std::endl;
}

void Puller::read_stmt_annual_from_files()
{
    std::ifstream inc_stmt_file("../files/inc_stmt.json");
    std::ifstream bal_sheet_file("../files/bal_sheet.json");
    std::ifstream cash_flow_file("../files/cash_flow.json");

    std::stringstream inc_stmt_ss;
    std::stringstream bal_sheet_ss;
    std::stringstream cash_flow_ss;

    inc_stmt_ss << inc_stmt_file.rdbuf();
    bal_sheet_ss << bal_sheet_file.rdbuf();
    cash_flow_ss << cash_flow_file.rdbuf();

    inc_stmt_file.close();
    bal_sheet_file.close();
    cash_flow_file.close();

    inc_stmt_json_cstr = inc_stmt_ss.str().c_str();
    bal_sheet_json_cstr = bal_sheet_ss.str().c_str();
    cash_flow_json_cstr = cash_flow_ss.str().c_str();

    std::cout << "[*LOG] Successfully read statements from files..." << std::endl;

}

void Puller::parse_json()
{
    //std::cout << inc_stmt_json_cstr << std::endl;

    rapidjson::Document d_inc_stmt;
    d_inc_stmt.Parse(inc_stmt_json_cstr);

    //std::cout << "Symbol used is: " << d_inc_stmt[0]["symbol"].GetString() << std::endl;

    std::cout << "[*LOG] Successfully Parsed Json" << std::endl;
}
