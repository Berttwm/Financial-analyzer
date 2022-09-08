#include <iostream>
#include <cpr/cpr.h>

#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"

#define stringify( name ) #name

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
    Scorer* scorer = new Scorer(*tsla_stock);

    // Step 4: Use the scorer to iterate through metrics
    scorer->process();
    std::cout << std::endl << "[*] === Processing complete... Printing debug statements" << std::endl;
    std::cout << "Curr Score: " << scorer->get_curr_score() << std::endl;
    std::cout << "Category scores..." << std::endl;
    std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
    for (auto category : scorer->get_categoryscores())
    {
        std::cout << "category value: " << category.second << std::endl;
    }
    std::cout<<std::endl;
    for (auto metric : scorer->get_metricscores())
    {

    }
    std::cout << std::endl;
    for (auto category : scorer->get_maxcategoryscores())
    {

    }
    std::cout << std::endl;
    for (auto metric : scorer->get_maxmetricscores())
    {

    }
    std::cout << "=== End of processing ===" << std::endl;
    return 0;
}