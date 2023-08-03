#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#include "../Header/Parser/ParseHelpCmd.h"
#include "../Header/Parser/Commands.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"


ParseHelpCmd::ParseHelpCmd(Scorer* scorer) : Commands(scorer) {};

void ParseHelpCmd::execute()
{

    if (prev_cmd) {
        prev_cmd->get_help();
    }
    else {
        get_help();
    }

}

void ParseHelpCmd::add_prev_cmd(Commands* input)
{   
    prev_cmd = input;
}

void ParseHelpCmd::get_help()
{
    std::cout << std::endl << "Basic Commands: \n"
        "   --all                   Returns all information regarding the input stock \n"
        "   --c                     Returns the information of all the categories of the input stock \n"
        "   --c [CATEGORY]          Returns the information of the specified category of the input stock \n"
        "   --i                     Returns the information of all the metric score of the input stock \n"
        "   --i [METRIC]            Returns the information of the specified metric score of the input stock \n"

        "\nUsage : .\main.exe STOCK [commands] \n"
        "Use .\main.exe STOCK <command> --help for more information about a given command." << std::endl;
}

