#include "../Header/Puller.H"

Puller::Puller(std::string ticker)
    :ticker() // TODO: Check valid ticker
{
    // Upper case ticker before storage
    std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
    this->ticker = ticker;
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


    cpr::Response resp_inc_stmt = cpr::Get(cpr::Url{ income_statement_url });
    cpr::Response resp_bal_sheet = cpr::Get(cpr::Url{ balance_sheet_url });
    cpr::Response resp_cash_flow = cpr::Get(cpr::Url{ cash_flow_url });
    //r.status_code;                  // 200
    //r.header["content-type"];       // application/json; charset=utf-8
    //std::string resp = r.text;                         // JSON text string

    if (resp_inc_stmt.status_code != 200 || resp_bal_sheet.status_code != 200 || resp_cash_flow.status_code != 200)
        throw std::exception("Pull statement search resulted in unsuccessful HTTP response code");

    if (resp_inc_stmt.text == "[ ]" || resp_bal_sheet.text == "[ ]" || resp_cash_flow.text == "[ ]")
        throw std::exception("Pull statement search resulted in empty result");

    std::cout << "Successfully pulled income statement, balance sheet statement, and cash flow statement" << std::endl;
}
