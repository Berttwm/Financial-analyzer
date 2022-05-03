#include <iostream>
#include <cpr/cpr.h>

#include "../Header/Puller.H"
using namespace std;

int main()
{
    try
    {
        Puller* puller_tsla = new Puller("TSLA");
    }
    catch (...)
    {
        throw;
    }

    return 0;
}