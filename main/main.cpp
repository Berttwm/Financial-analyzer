#include <iostream>
#include <cpr/cpr.h>

#include "../Header/CLIParser.h"
#include "../Header/InputException.h"

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
    catch (FAException& pe)
    {
        // specific handling for the type of exception error
        std::cerr << pe.what() << std::endl;
    }

    return 0;
}