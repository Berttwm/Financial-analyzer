#pragma once
#include <cpr/cpr.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <algorithm>
#include <exception>
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
private:

    std::string base_site = "https://financialmodelingprep.com/";
    std::string api_key = "65a3fae3b56225e0caf11e3c9ccbcccf";
    std::string ticker;
};