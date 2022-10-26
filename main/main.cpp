#include <iostream>
#include <cpr/cpr.h>
#include <CLI11.hpp>

#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"
#include "CLIParser.h"

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
    catch (const std::runtime_error& re)
    {
        // speciffic handling for runtime_error
        std::cerr << "[*Runtime error]: " << re.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        // speciffic handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "[*Error occurred]: " << ex.what() << std::endl;
    }
    catch (...)
    {
        // catch any other errors (that we have no information about)
        std::cerr << "Unknown error occurred." << std::endl;
    }

    return 0;
}