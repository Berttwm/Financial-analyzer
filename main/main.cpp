#include <iostream>
#include <cpr/cpr.h>
//#include <CLI11.hpp>

#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"
#include "CLIParser.h"
#include "ParserException.h"

#define stringify( name ) #name

using namespace std;

int main(int argc, char** argv)
{
    CLIParser* cli_parser;
    try
    {
        cli_parser = new CLIParser(argc, argv);
        cli_parser->parse_input();
    }
    catch (ParserException pe)
    {
        // speciffic handling for parse exception error
        std::cerr << pe.what() << std::endl;
    }

    return 0;
}