#include "CLIParser.H"
#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"

CLIParser::CLIParser(int num_args, char** argv)
    :num_args(num_args),
    argv(argv)
{
    if (num_args < 2) {
        throw std::exception("Please input a stock symbol");
    }

}

void CLIParser::parse_input()
{
    std::cout << "+++++++++++ PARSE INPUT +++++++++++" << std::endl;
    switch (num_args) {
    case 2:
        parse_entire_stock();
        break;
    case 3:
        parse_whole_category();
        break;
    case 4:
        parse_specified_category();
        break;
    default:
        throw std::exception("Inavlid input arguments");
    }
    std::cout << "+++++++++++ PARSE ENDDDDD +++++++++++" << std::endl;

}


void CLIParser::parse_entire_stock()
{
    
    std::cout << std::endl << "[*] === Processing complete... Printing debug statements" << std::endl;
    std::cout << "+++++++++++ PARSE STOCK ONLY +++++++++++" << std::endl;
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

void CLIParser::parse_whole_category()
{
    std::cout << "+++++++++++ PARSE ALL SCORING +++++++++++" << std::endl;
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

    std::string type = argv[2];
    if (type == "-i") {
        std::cout << std::endl << "Metrics individual performances ..." << std::endl;
        for (auto metric : scorer->get_metricperformance())
        {
            std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
        }
    }
    else if (type == "-c") {
        std::cout << std::endl << "Category scores..." << std::endl;
        std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
        for (auto category : scorer->get_categoryscores())
        {
            std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
        }
    }
    else {
        throw std::exception("Please enter a valid argument");
    }
   
}

void CLIParser::parse_specified_category()
{
    std::cout << "+++++++++++ PARSE SELECT SCORE +++++++++++" << std::endl;
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

    std::string type = argv[2];
    std::string selected_metric = argv[3];
    std::transform(selected_metric.begin(), selected_metric.end(), selected_metric.begin(), ::tolower);

    if (type == "-i") {
        std::cout << std::endl << "Metrics individual performances ..." << std::endl;
        for (auto metric : scorer->get_metricperformance())
        {
            std::string current_metric = MetricTypeString.find(metric.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);
            if (current_metric.compare(selected_metric) == 0) {
                std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
            }
        }
    }
    else if (type == "-c") {
        std::cout << std::endl << "Category scores..." << std::endl;
        std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
        for (auto category : scorer->get_categoryscores())
        {
            std::string current_metric = CategoryTypeString.find(category.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);
            if (current_metric.compare(selected_metric) == 0) {
                std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
            }
        }
    }
    else {
        throw std::exception("Please enter a valid argument");
    }
}