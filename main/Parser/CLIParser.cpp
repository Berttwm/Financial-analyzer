#include <boost/program_options.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "../Header/Parser/CLIParser.h"
#include "../Header/Puller.h"
#include "../Header/Scorer.h"
#include "../Header/Stock.h"
#include "../Header/ParserException.h"
#include "../Header/InputException.h"

namespace boost_opt = boost::program_options;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    return os;
}

CLIParser::CLIParser(int num_args, char** argv)
    :num_args(num_args),
    argv(argv){}


void CLIParser::parse_input()
{
    try {
        boost_opt::variables_map var_map;
        vector<string> def_val = { "This default" };
        string call_i;
        std::vector<uint16_t> c;

        auto split_ports =
            [&c](std::vector<std::string> const& vv) {
            for (auto& v : vv) {
                auto it = boost::make_split_iterator(
                    v, boost::token_finder(boost::algorithm::is_any_of(" ,")));
                std::transform(it, {}, back_inserter(c), [](auto& s) {
                    return boost::lexical_cast<uint16_t>(s);
                    });
            }
        };


        boost_opt::options_description generic_options("Program Options");
        generic_options.add_options()
            ("stock", boost_opt::value< vector<string> >(), "Display stock data")
            ("help", "Display help menu");


        // Declare a group of options that will be 
        // allowed both on command line and in
        // config file boost_opt::value< vector<string> >()->multitoken()->notifier(split_ports), 
        boost_opt::options_description config("Configuration");
        config.add_options()
            ("i", "Display individual stock metric")
            ("c", "Display category of stock");
       
        boost_opt::options_description cmdline_options;
        cmdline_options.add(generic_options).add(config);

        boost_opt::options_description config_options;
        config_options.add(config);

        boost_opt::positional_options_description pos;
        //pos.add("stock", -1);
        //pos.add("i", -1);

        boost_opt::store(boost_opt::command_line_parser(num_args, argv).options(cmdline_options).positional(pos).run(), var_map);
        boost_opt::notify(var_map);

        std::string stock;

        if (var_map.count("stock")) {
            if (var_map["stock"].as< vector<string> >().size() > 1) {
                throw InputException("Inavlid input arguments. More than 1 stock detected");
            }
            else {
                std::vector<std::string> input = var_map["stock"].as< vector<string> >();
                for (auto const& s : input) { stock += s; } // convert vector to string
                std::cout << "Input Stock: " << stock << "\n";
                parse_entire_stock(stock);

            }
        }

        if (var_map.count("i")) {
            if (stock.empty()) {
                throw InputException("No stock input");
            } 

            std::cout << "==============================================Boost i selected" << std::endl;
            Scorer* scorer = get_scorer(stock);
            get_metrics_performances(scorer);

        }

        if (var_map.count("c")) {
            if (stock.empty()) {
                throw InputException("No stock input");
            }

            std::cout << "=============================================BOOST -c +++++++++++" << std::endl;
            Scorer* scorer = get_scorer(stock);
            get_category_scores(scorer);
        }
         
        if (var_map.count("help")) {
            std::cout << cmdline_options << std::endl;
        }
        /*else {
            throw ParserException("Unable to parse input");
        }*/

    }
    catch (FAException& pe)
    {
        // specific handling for the type of exception error
        std::cerr << "Boost error: " << pe.what() << std::endl;
    }
}


Scorer* CLIParser::get_scorer(std::string input)
{
    // Step 1: Pull from API endpoint
    //std::string input = argv[1];

    Puller* puller_stock = new Puller(input);

    // Step 2: Create `Stock` object
    Stock* stock = new Stock(puller_stock->get_d_inc_stmt(), puller_stock->get_d_bal_sheet(), puller_stock->get_d_cash_flow());

    // Step 3: Pass `Stock` object to `Scorer` object
    Scorer* scorer = new Scorer(*stock);

    // Step 4: Use the scorer to iterate through metrics
    scorer->process();

    return scorer;
}


void CLIParser::parse_entire_stock(std::string stock)
{

    std::cout << std::endl << "[*] === Processing complete... Printing debug statements" << std::endl;
    std::cout << "+++++++++++ OUTPUT ALL STOCK INFO +++++++++++" << std::endl;

    Scorer* scorer = get_scorer(stock);

    // Output current score of stock
    std::cout << "Curr Score: " << scorer->get_curr_score() << std::endl << std::endl;

    // Output all category scores of stock
    get_category_scores(scorer);

    // Output maximum category scores
    get_max_category_scores(scorer);

    // Output all metric performances 
    get_metrics_performances(scorer);

    // Output all metric scores of stock
    get_metric_scores(scorer);

    // Output maximum metric scores
    get_max_metric_scores(scorer);

    std::cout << "=== End of processing ===" << std::endl;
}

void CLIParser::parse_whole_category(std::string stock)
{
    std::cout << "+++++++++++ OUTPUT ALL SCORING OF INPUT CATEGORY+++++++++++" << std::endl;
    
    Scorer* scorer = get_scorer(stock);

    std::string type = argv[2];
    if (type == "-i") {
        get_metrics_performances(scorer);
    }
    else if (type == "-c") {
        get_category_scores(scorer);
    }
    else {
        throw InputException("Please enter a valid argument");
    }

}

void CLIParser::parse_specified_category(std::string stock)
{
    std::cout << "+++++++++++ OUTPUT SCORE OF INPUT CATEGORY AND METRIC +++++++++++" << std::endl;
    
    Scorer* scorer = get_scorer(stock);

    std::string type = argv[2];
    std::string selected_metric = argv[3];
    std::transform(selected_metric.begin(), selected_metric.end(), selected_metric.begin(), ::tolower);

    if (type == "-i") {
        get_metrics_performances(scorer, selected_metric);
    }
    else if (type == "-c") {
        get_category_scores(scorer, selected_metric);
    }
    else {
        throw InputException("Please enter a valid argument");
    }
}

void CLIParser::get_metrics_performances(Scorer* scorer, std::string selected_metric)
{
    int found_metric = 0;
    int has_selected_metric = selected_metric.compare("");

    std::cout << std::endl << "Metrics individual performances ..." << std::endl;
    for (auto metric : scorer->get_metricperformance())
    {
        std::string current_metric = MetricTypeString.find(metric.first)->second;
        std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);

        if (current_metric.compare(selected_metric) == 0 || has_selected_metric == 0) {
            std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
            found_metric = 1;
        }
    }

    if (found_metric == 0) {
        throw InputException("No such metric found");
    }
}

void CLIParser::get_category_scores(Scorer* scorer, std::string selected_category)
{
    int found_category = 0;
    int has_selected_category = selected_category.compare("");

    std::cout << std::endl << "Category scores..." << std::endl;
    std::unordered_map<CategoryType, int> CategoryScores = scorer->get_categoryscores();
    for (auto category : scorer->get_categoryscores())
    {
        std::string current_metric = CategoryTypeString.find(category.first)->second;
        std::transform(current_metric.begin(), current_metric.end(), current_metric.begin(), ::tolower);
        if (current_metric.compare(selected_category) == 0 || has_selected_category == 0) {
            std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
            found_category = 1;
        }
    }

    if (found_category == 0) {
        throw InputException("No such category found");
    }
}

void CLIParser::get_metric_scores(Scorer* scorer)
{
    // Output all metric scores of stock
    std::cout << std::endl << "Metrics scores..." << std::endl;
    for (auto metric : scorer->get_metricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}

void CLIParser::get_max_category_scores(Scorer* scorer)
{
    // Output maximum category scores
    std::cout << std::endl << "Category maximum scores..." << std::endl;
    for (auto category : scorer->get_maxcategoryscores())
    {
        std::cout << "category: " << CategoryTypeString.find(category.first)->second << ", value: " << category.second << std::endl;
    }
}

void CLIParser::get_max_metric_scores(Scorer* scorer)
{
    // Output maximum metric scores
    std::cout << std::endl << "Metrics maximum scores..." << std::endl;
    for (auto metric : scorer->get_maxmetricscores())
    {
        std::cout << "metric: " << MetricTypeString.find(metric.first)->second << ", value: " << metric.second << std::endl;
    }
}