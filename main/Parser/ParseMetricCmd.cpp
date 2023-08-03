#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#include "../Header/Parser/ParseMetricCmd.h"
#include "../Header/Parser/Commands.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"


ParseMetricCmd::ParseMetricCmd(Scorer* scorer) : Commands(scorer){};

void ParseMetricCmd::execute()
{
    std::cout << std::endl << "Metrics individual performances ..." << std::endl;
    // output all metrics if no selected metric
    if (args.empty())
    {
        for (auto metric : scorer->get_metricperformance())
        {
            std::string current_metric = MetricTypeString.find(metric.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

            std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
        }

        return;
    }

    int found_metric = 0;
    // output only selected metrics
    for (auto selected_metric : args) {

        for (auto metric : scorer->get_metricperformance())
        {
            std::string current_metric = MetricTypeString.find(metric.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

            if (current_metric.compare(*selected_metric) == 0) {
                std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
                found_metric = 1;
            }
        }
    }

    if (found_metric == 0) {
        throw InputException("No such metric found");
    }
   
}

void ParseMetricCmd::get_help()
{
    if (args.empty()) {
        std::cout << std::endl <<
            "Returns the information of all the metric score of the input stock\n\n"

            "Usage : .\\main.exe STOCK --i [METRIC] \n\n"

            "Things to take note: \n"
            "   Keywords in uppercase e.g STOCK / PARAMS means that, it is a user input \n"
            "   Keywords in [] means that, this parameter can be omitted \n\n"

            "Examples: \n"
            "   .\\main.exe tsla --i             Returns the information of all the metric score of Tesla \n"
            "   .\\main.exe AAPL --i             Returns the information of all the metric score of Apple \n"

            "\nUse .\\main.exe STOCK --i [METRIC] --help for more information about a given command." << std::endl;
    }
    else {
        std::cout << std::endl <<
            "Get specific help" << std::endl;
    }
}


