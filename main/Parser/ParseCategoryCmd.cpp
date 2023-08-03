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
    for (auto selected_category : args) {

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

void ParseCategoryCmd::get_help()
{
    if (args.empty()) {
        std::cout << std::endl <<
            "Returns the information of all the categories of the input stock\n\n"

            "Usage : .\\main.exe STOCK --c [CATEGORY] \n\n"

            "Things to take note: \n"
            "   Keywords in uppercase e.g STOCK / PARAMS means that, it is a user input \n"
            "   Keywords in [] means that, this parameter can be omitted \n\n"

            "Examples: \n"
            "   .\\main.exe tsla --c             Returns the information of all the categories of Tesla \n"
            "   .\\main.exe AAPL --c             Returns the information of all the categories of Apple \n"

            "\nUse .\\main.exe STOCK --c [CATEGORY] --help for more information about a given command." << std::endl;
    }
    else {
        std::cout << std::endl <<
            "Get specific help" << std::endl;
    }
}


