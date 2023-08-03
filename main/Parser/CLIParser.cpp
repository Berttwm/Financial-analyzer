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
#include "../Header/Parser/ParseAllCmd.h"


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

            if (cmd_type == CommandType::all)
            {
                ParseAllCmd cmd = ParseAllCmd(scorer);
                cmd_stack.push(&cmd);
            }

        } else if (!cmd_stack.empty()) {
            cmd_stack.top()->add_args(&argv[i]);

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
    std::cout << std::endl << "[*LOG] Successfully executed all commands" << std::endl;

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
