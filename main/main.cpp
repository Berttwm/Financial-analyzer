#include <iostream>
#include <cpr/cpr.h>

#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"

using namespace std;

int main()
{
    // Step 1: Pull from API endpoint
    Puller* puller_tsla;
    try
    {
        puller_tsla = new Puller("TSLA");
    }
    catch (...)
    {
        throw;
    }

    // Step 2: Create `Stock` object
    Stock* tsla_stock = new Stock(puller_tsla->get_d_inc_stmt(), puller_tsla->get_d_bal_sheet(), puller_tsla->get_d_cash_flow());

    // Step 3: Pass `Stock` object to `Scorer` object
    Scorer* scorer = new Scorer(tsla_stock);

    return 0;
}