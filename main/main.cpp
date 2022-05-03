#include <iostream>
#include <cpr/cpr.h>

#include "../Header/Puller.H"
using namespace std;

int main()
{
    try
    {
        Puller* puller_tsla = new Puller("TSLA");
        puller_tsla->pull_stmt_annual();

    }
    catch (...)
    {
        throw;
    }

    return 0;
}