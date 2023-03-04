#include "../Header/CLIParser.h"
#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"


CLIParser::CLIParser(int num_args, char** argv)
    :num_args(num_args),
    argv(argv){}

void CLIParser::parse_input()
{
    switch (num_args) {
    case 2:
        // If clause to separate parser
        if (argv[1] == CLIParser::help) {
            parse_help();
        }
        else {
            parse_entire_stock();
        }
        break;
    case 3:
        parse_whole_category();
        break;
    case 4:
        parse_specified_category();
        break;
    default:
        throw InputException("Inavlid input arguments");
        // Expected argument: CLIPArser.exe -h 
    }
}

void CLIParser::parse_help()
{
    std::cout << "+++++++++++ HELP +++++++++++" << std::endl;

}

Scorer* CLIParser::get_scorer()
{
    // Step 1: Pull from API endpoint
    std::string input = argv[1];

    Puller* puller_stock = new Puller(input);

    // Step 2: Create `Stock` object
    Stock* stock = new Stock(puller_stock->get_d_inc_stmt(), puller_stock->get_d_bal_sheet(), puller_stock->get_d_cash_flow());

    // Step 3: Pass `Stock` object to `Scorer` object
    Scorer* scorer = new Scorer(*stock);

    // Step 4: Use the scorer to iterate through metrics
    scorer->process();

    return scorer;
}


void CLIParser::parse_entire_stock()
{

    std::cout << std::endl << "[*] === Processing complete... Printing debug statements" << std::endl;
    std::cout << "+++++++++++ OUTPUT ALL STOCK INFO +++++++++++" << std::endl;

    Scorer* scorer = get_scorer();

    // Output current score of stock
    std::cout << "Curr Score: " << scorer->get_curr_score() << std::endl << std::endl;

    // Output all category scores of stock
    get_category_scores(scorer);

    // Output maximum category scores
    get_max_category_scores(scorer);

    // Output all metric performances 
    get_metrics_performances(scorer);

    // Output all metric scores of stock
    get_metric_scores(scorer);

    // Output maximum metric scores
    get_max_metric_scores(scorer);

    std::cout << "=== End of processing ===" << std::endl;
}

void CLIParser::parse_whole_category()
{
    std::cout << "+++++++++++ OUTPUT ALL SCORING OF INPUT CATEGORY+++++++++++" << std::endl;
    
    Scorer* scorer = get_scorer();

    std::string type = argv[2];
    if (type == "-i") {
        get_metrics_performances(scorer);
    }
    else if (type == "-c") {
        get_category_scores(scorer);
    }
    else {
        throw InputException("Please enter a valid argument");
    }

}

void CLIParser::parse_specified_category()
{
    std::cout << "+++++++++++ OUTPUT SCORE OF INPUT CATEGORY AND METRIC +++++++++++" << std::endl;
    
    Scorer* scorer = get_scorer();

    std::string type = argv[2];
    std::string selected_metric = argv[3];
    std::transform(selected_metric.begin(), selected_metric.end(), selected_metric.begin(), ::tolower);

    if (type == "-i") {
        get_metrics_performances(scorer, selected_metric);
    }
    else if (type == "-c") {
        get_category_scores(scorer, selected_metric);
    }
    else {
        throw InputException("Please enter a valid argument");
    }
}

void CLIParser::get_metrics_performances(Scorer* scorer, std::string selected_metric)
{
    int found_metric = 0;
    int has_selected_metric = selected_metric.compare("");

    std::cout << std::endl << "Metrics individual performances ..." << std::endl;
    for (auto metric : scorer->get_metricperformance())
    {
        std::string current_metric = MetricTypeString.find(metric.first)->second;
        std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

        if (current_metric.compare(selected_metric) == 0 || has_selected_metric == 0) {
            std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
            found_metric = 1;
        }
    }

    if (found_metric == 0) {
        throw InputException("No such metric found");
    }
}

void CLIParser::get_category_scores(Scorer* scorer, std::string selected_category)
{
    int found_category = 0;
    int has_selected_category = selected_category.compare("");

    std::cout << std::endl << "Category scores..." << std::endl;
    std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
    for (auto category : scorer->get_categoryscores())
    {
        std::string current_metric = CategoryTypeString.find(category.first)->second;
        std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);
        if (current_metric.compare(selected_category) == 0 || has_selected_category == 0) {
            std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
            found_category = 1;
        }
    }

    if (found_category == 0) {
        throw InputException("No such category found");
    }
}

void CLIParser::get_metric_scores(Scorer* scorer)
{
    // Output all metric scores of stock
    std::cout << std::endl << "Metrics scores..." << std::endl;
    for (auto metric : scorer->get_metricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}

void CLIParser::get_max_category_scores(Scorer* scorer)
{
    // Output maximum category scores
    std::cout << std::endl << "Category maximum scores..." << std::endl;
    for (auto category : scorer->get_maxcategoryscores())
    {
        std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
    }
}

void CLIParser::get_max_metric_scores(Scorer* scorer)
{
    // Output maximum metric scores
    std::cout << std::endl << "Metrics maximum scores..." << std::endl;
    for (auto metric : scorer->get_maxmetricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}