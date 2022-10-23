#include "CLIParser.H"
#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"

CLIParser::CLIParser(int num_args, char** argv)
{
    if (num_args < 2) {
        throw std::exception("Please input a stock symbol");
    }

    std::string input = argv[1];

    // Step 1: Pull from API endpoint
    Puller* puller_stock;
    puller_stock = new Puller(input);
   
    // Step 2: Create `Stock` object
    Stock* stock = new Stock(puller_stock->get_d_inc_stmt(), puller_stock->get_d_bal_sheet(), puller_stock->get_d_cash_flow());

    // Step 3: Pass `Stock` object to `Scorer` object
    Scorer* scorer = new Scorer(*stock);

    // Step 4: Use the scorer to iterate through metrics
    scorer->process();
    std::cout << std::endl << "[*] === Processing complete... Printing debug statements" << std::endl;
    std::cout << "Curr Score: " << scorer->get_curr_score() << std::endl << std::endl;
    std::cout << "Category scores..." << std::endl;
    std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
    for (auto category : scorer->get_categoryscores())
    {
        std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
    }
    std::cout << std::endl << "Metrics scores..." << std::endl;
    for (auto metric : scorer->get_metricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
    std::cout << std::endl << "Category maximum scores..." << std::endl;
    for (auto category : scorer->get_maxcategoryscores())
    {
        std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
    }
    std::cout << std::endl << "Metrics maximum scores..." << std::endl;
    for (auto metric : scorer->get_maxmetricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
    std::cout << std::endl << "Metrics individual performances ..." << std::endl;
    for (auto metric : scorer->get_metricperformance())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
    std::cout << "=== End of processing ===" << std::endl;

}

void CLIParser::parse_input()
{
    std::cout << "+++++++++++ PARSE INPUT  ===" << std::endl;
}