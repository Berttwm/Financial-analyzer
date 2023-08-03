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

    std::cout << "+++++++++++ HELP EXECUTED +++++++++++" << std::endl;
    if (prev_cmd) {
        prev_cmd->execute();
    }
    else {
        std::cout << "+++++++++++ no prev cmd +++++++++++" << std::endl;
    }

}

void ParseHelpCmd::add_prev_cmd(Commands* input)
{   
    prev_cmd = input;
}


