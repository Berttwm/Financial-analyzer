#pragma once
#include <cpr/cpr.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/* Example URL for json
  https://financialmodelingprep.com/api/v3/income-statement/AAPL?limit=120&apikey=YOUR_API_KEY'
*/

/* To extract and parse data pulled from financialmodelingprep.com */
class Puller
{
public:
    Puller(std::string ticker);

    // Pull all 3 statements (income_stmt, balance_sheet, cash_flow)
    void pull_stmt_annual();
    void read_stmt_annual_from_files(); // Used as a testing method when reading the json files from ../files/ instead of pulling from api endpoint
    void parse_json();

    rapidjson::Document* get_d_inc_stmt();
    rapidjson::Document* get_d_bal_sheet();
    rapidjson::Document* get_d_cash_flow();
private:
    std::string inc_stmt_json_str;
    std::string bal_sheet_json_str;
    std::string cash_flow_json_str;

    rapidjson::Document* d_inc_stmt;
    rapidjson::Document* d_bal_sheet;
    rapidjson::Document* d_cash_flow;


    std::string base_site = "https://financialmodelingprep.com/";
    std::string api_key = "65a3fae3b56225e0caf11e3c9ccbcccf";
    std::string ticker;
};