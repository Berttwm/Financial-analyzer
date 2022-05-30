#include <iostream>
#include <cpr/cpr.h>

#include "../Header/Puller.h"
#include "../Header/Stock.h"

using namespace std;

int main()
{
    Puller* puller_tsla;
    try
    {
        puller_tsla = new Puller("TSLA");
    }
    catch (...)
    {
        throw;
    }
    Stock* tsla_stock = new Stock(puller_tsla->get_d_inc_stmt(), puller_tsla->get_d_bal_sheet(), puller_tsla->get_d_cash_flow());


    return 0;
}