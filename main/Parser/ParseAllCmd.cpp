#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#include "../Header/Parser/ParseAllCmd.h"
#include "../Header/Parser/Commands.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"


ParseAllCmd::ParseAllCmd(Scorer* scorer) : Commands(scorer) {};

void ParseAllCmd::execute()
{
    if (!args.empty())
    {
        throw InputException("No arguments needed for --all command");
    }
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

}

void ParseAllCmd::get_category_scores(Scorer* scorer)
{

    std::cout << std::endl << "Category scores..." << std::endl;
    std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
    for (auto category : scorer->get_categoryscores())
    {
        std::string current_metric = CategoryTypeString.find(category.first)->second;
        std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);
        std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
    }
}

void ParseAllCmd::get_max_category_scores(Scorer* scorer)
{
    // Output maximum category scores
    std::cout << std::endl << "Category maximum scores..." << std::endl;
    for (auto category : scorer->get_maxcategoryscores())
    {
        std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
    }
}

void ParseAllCmd::get_metrics_performances(Scorer* scorer)
{

    std::cout << std::endl << "Metrics individual performances ..." << std::endl;
    for (auto metric : scorer->get_metricperformance())
    {
        std::string current_metric = MetricTypeString.find(metric.first)->second;
        std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}


void ParseAllCmd::get_metric_scores(Scorer* scorer)
{
    // Output all metric scores of stock
    std::cout << std::endl << "Metrics scores..." << std::endl;
    for (auto metric : scorer->get_metricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}


void ParseAllCmd::get_max_metric_scores(Scorer* scorer)
{
    // Output maximum metric scores
    std::cout << std::endl << "Metrics maximum scores..." << std::endl;
    for (auto metric : scorer->get_maxmetricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}