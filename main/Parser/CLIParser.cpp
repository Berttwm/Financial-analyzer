#pragma once
#include <iostream>
#include <stack>

#include "../Header/Parser/CLIParser.h"
#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"
#include "../Header/Parser/ParserUtils.h"
#include "../Header/Parser/ParseMetricCmd.h"
#include "../Header/Parser/ParseCategoryCmd.h"
#include "../Header/Parser/ParseHelpCmd.h"


CLIParser::CLIParser(int num_args, char** argv)
    :num_args(num_args),
    argv(argv) {}

void CLIParser::parse_input()
{
    std::stack<Commands*> cmd_stack;

    std::string stock_input = argv[1];
    Scorer* scorer = get_scorer();

    // i starts from 1 to exclude the command line and stock input 
    for (int i = 2; i < num_args; i++) {
        // parse argument and convert to lowercase
        std::string input = argv[i];
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        // if valid command
        if (InputStringToCommand.count(input)) {

            CommandType cmd_type = InputStringToCommand.at(input);
            
            if (cmd_type == CommandType::metric)
            {
                ParseMetricCmd cmd = ParseMetricCmd(scorer);
                cmd_stack.push(&cmd);
            }

            if (cmd_type == CommandType::category)
            {
                ParseCategoryCmd cmd = ParseCategoryCmd(scorer);
                cmd_stack.push(&cmd);
            }

            if (cmd_type == CommandType::help)
            {
                ParseHelpCmd cmd = ParseHelpCmd(scorer);
                cmd_stack.push(&cmd);
            }

        } else if (!cmd_stack.empty()) {
            cmd_stack.top()->add_args(&input);

        }
        else {
            throw InputException("Invalid input arguments");
        }

    }
    
    // pop command stack and execute commands
    while (!cmd_stack.empty()) {
        cmd_stack.top()->execute();
        cmd_stack.pop();
    }

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