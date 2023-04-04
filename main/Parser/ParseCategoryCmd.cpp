#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#include "../Header/Parser/ParseCategoryCmd.h"
#include "../Header/Parser/Commands.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"


ParseCategoryCmd::ParseCategoryCmd(Scorer* scorer) : Commands(scorer) {};

void ParseCategoryCmd::execute()
{

    std::cout << std::endl << "Category scores..." << std::endl;
    // output all metrics if no selected metric
    if (args.empty())
    {
        for (auto category : scorer->get_categoryscores())
        {
            std::string current_metric = CategoryTypeString.find(category.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

            std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
        }

        return;
    }

    int found_category = 0;
    // output only selected category
    for (auto& selected_category : args) {

        for (auto category : scorer->get_categoryscores())
        {
            std::string current_metric = CategoryTypeString.find(category.first)->second;
            std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

            if (current_metric.compare(*selected_category) == 0) {
                std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
                found_category = 1;
            }
        }
    }

    if (found_category == 0) {
        throw InputException("No such category found");
    }

}


