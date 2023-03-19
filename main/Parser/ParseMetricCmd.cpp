#pragma once
#include <iostream>
#include <algorithm>

#include "../Header/Parser/Commands.h"
#include "../Header/Parser/ParseMetricCmd.h"
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
    for (auto& selected_metric : args) {

        for (auto metric : scorer->get_metricperformance())
        {
            std::string current_metric = MetricTypeString.find(metric.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

            if (current_metric.compare(selected_metric) == 0) {
                std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
                found_metric = 1;
            }
        }
    }

    if (found_metric == 0) {
        throw InputException("No such metric found");
    }
}


