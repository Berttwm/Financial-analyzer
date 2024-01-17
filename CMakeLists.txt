cmake_minimum_required(VERSION 3.27)
project(Financial_analyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

include_directories(Header)
include_directories(Header/Metric)
include_directories(Header/Parser)
include_directories(Include)
include_directories(Include/curl)
include_directories(Include/rapidjson)
include_directories(Include/rapidjson/error)
include_directories(Include/rapidjson/internal)

# TODO: Add conditional to include this when on Windows
#include_directories(Include/rapidjson/msinttypes)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8)
FetchContent_MakeAvailable(cpr)

add_executable(Financial_analyzer
        Header/Metric/AdjustedTotalDebtShareHolderEquityRatio_MY.h
        Header/Metric/AdjustedTotalDebtShareHolderEquityRatio_SY.h
        Header/Metric/CapexMargin_MY.h
        Header/Metric/CapexMargin_SY.h
        Header/Metric/DebtRatio_MY.h
        Header/Metric/DebtRatio_SY.h
        Header/Metric/Depreciation_MY.h
        Header/Metric/Depreciation_SY.h
        Header/Metric/EarningsGrowth_MY.h
        Header/Metric/Goodwill_MY.h
        Header/Metric/GrossProfitMargin_SY.h
        Header/Metric/InterestExpense_MY.h
        Header/Metric/InterestExpense_SY.h
        Header/Metric/LongTermDebtEarningsRatio_MY.h
        Header/Metric/Metric.h
        Header/Metric/MetricMY.h
        Header/Metric/MetricSY.h
        Header/Metric/NegativeEarnings_MY.h
        Header/Metric/NetEarnings_MY.h
        Header/Metric/NetEarningsOverRevenue_MY.h
        Header/Metric/OperatingExpenses_MY.h
        Header/Metric/PPEDebtRatio_MY.h
        Header/Metric/PPEDebtRatio_SY.h
        Header/Metric/PreferredStock_MY.h
        Header/Metric/PreferredStock_SY.h
        Header/Metric/ReturnOnTotalAsset_MY.h
        Header/Metric/ReturnOnTotalAsset_SY.h
        Header/Metric/RND_MY.h
        Header/Metric/RND_SY.h
        Header/Metric/SellingAndBuyingStock_MY.h
        Header/Metric/SGA_MY.h
        Header/Metric/SGA_SY.h
        Header/Metric/ShortLongTermDebtRatio_MY.h
        Header/Metric/ShortLongTermDebtRatio_SY.h
        Header/Metric/TotalCurrentRatio_MY.h
        Header/Metric/TotalCurrentRatio_SY.h
        Header/Metric/TotalInventory_MY.h
        Header/Metric/TotalReceivablesOverRevenue_MY.h
        Header/Parser/CLIParser.h
        Header/Parser/Commands.h
        Header/Parser/ParseAllCmd.h
        Header/Parser/ParseCategoryCmd.h
        Header/Parser/ParseHelpCmd.h
        Header/Parser/ParseMetricCmd.h
        Header/Parser/ParserUtils.h
        Header/BalanceSheet.h
        Header/BalStatement.h
        Header/CashFlow.h
        Header/FAException.h
        Header/IncomeStatement.h
        Header/IncStatement.h
        Header/InputException.h
        Header/Interval.h
        Header/ParserException.h
        Header/Puller.h
        Header/Scorer.h
        Header/ScorerUtils.h
        Header/Statements.h
        Header/Stock.h
        Header/StockUtils.h
        Include/curl/curl.h
        Include/curl/curlver.h
        Include/curl/easy.h
        Include/curl/mprintf.h
        Include/curl/multi.h
        Include/curl/options.h
        Include/curl/stdcheaders.h
        Include/curl/system.h
        Include/curl/typecheck-gcc.h
        Include/curl/urlapi.h
        Include/rapidjson/error/en.h
        Include/rapidjson/error/error.h
        Include/rapidjson/internal/biginteger.h
        Include/rapidjson/internal/clzll.h
        Include/rapidjson/internal/diyfp.h
        Include/rapidjson/internal/dtoa.h
        Include/rapidjson/internal/ieee754.h
        Include/rapidjson/internal/itoa.h
        Include/rapidjson/internal/meta.h
        Include/rapidjson/internal/pow10.h
        Include/rapidjson/internal/regex.h
        Include/rapidjson/internal/stack.h
        Include/rapidjson/internal/strfunc.h
        Include/rapidjson/internal/strtod.h
        Include/rapidjson/internal/swap.h
        Include/rapidjson/allocators.h
        Include/rapidjson/cursorstreamwrapper.h
        Include/rapidjson/document.h
        Include/rapidjson/encodedstream.h
        Include/rapidjson/encodings.h
        Include/rapidjson/filereadstream.h
        Include/rapidjson/filewritestream.h
        Include/rapidjson/fwd.h
        Include/rapidjson/istreamwrapper.h
        Include/rapidjson/memorybuffer.h
        Include/rapidjson/memorystream.h
        Include/rapidjson/ostreamwrapper.h
        Include/rapidjson/pointer.h
        Include/rapidjson/prettywriter.h
        Include/rapidjson/rapidjson.h
        Include/rapidjson/reader.h
        Include/rapidjson/schema.h
        Include/rapidjson/stream.h
        Include/rapidjson/stringbuffer.h
        Include/rapidjson/uri.h
        Include/rapidjson/writer.h
        main/Metric/AdjustedTotalDebtShareHolderEquityRatio_MY.cpp
        main/Metric/AdjustedTotalDebtShareHolderEquityRatio_SY.cpp
        main/Metric/CapexMargin_MY.cpp
        main/Metric/CapexMargin_SY.cpp
        main/Metric/DebtRatio_MY.cpp
        main/Metric/DebtRatio_SY.cpp
        main/Metric/Depreciation_MY.cpp
        main/Metric/Depreciation_SY.cpp
        main/Metric/EarningsGrowth_MY.cpp
        main/Metric/Goodwill_MY.cpp
        main/Metric/GrossProfitMargin_SY.cpp
        main/Metric/InterestExpense_MY.cpp
        main/Metric/InterestExpense_SY.cpp
        main/Metric/LongTermDebtEarningsRatio_MY.cpp
        main/Metric/NegativeEarnings_MY.cpp
        main/Metric/NetEarnings_MY.cpp
        main/Metric/NetEarningsOverRevenue_MY.cpp
        main/Metric/OperatingExpenses_MY.cpp
        main/Metric/PPEDebtRatio_MY.cpp
        main/Metric/PPEDebtRatio_SY.cpp
        main/Metric/PreferredStock_MY.cpp
        main/Metric/PreferredStock_SY.cpp
        main/Metric/ReturnOnTotalAsset_MY.cpp
        main/Metric/ReturnOnTotalAsset_SY.cpp
        main/Metric/RND_MY.cpp
        main/Metric/RND_SY.cpp
        main/Metric/SellingAndBuyingStock_MY.cpp
        main/Metric/SGA_MY.cpp
        main/Metric/SGA_SY.cpp
        main/Metric/ShortLongTermDebtRatio_MY.cpp
        main/Metric/ShortLongTermDebtRatio_SY.cpp
        main/Metric/TotalCurrentRatio_MY.cpp
        main/Metric/TotalCurrentRatio_SY.cpp
        main/Metric/TotalInventory_MY.cpp
        main/Metric/TotalReceivablesOverRevenue_MY.cpp
        main/Parser/CLIParser.cpp
        main/Parser/ParseAllCmd.cpp
        main/Parser/ParseCategoryCmd.cpp
        main/Parser/ParseHelpCmd.cpp
        main/Parser/ParseMetricCmd.cpp
        main/BalanceSheet.cpp
        main/CashFlow.cpp
        main/IncomeStatement.cpp
        main/main.cpp
        main/Puller.cpp
        main/Scorer.cpp
        main/Stock.cpp)

target_link_libraries(Financial_analyzer PUBLIC cpr::cpr)

# TODO: Add conditional to compile this when on Windows
#Include/rapidjson/msinttypes/inttypes.h
#Include/rapidjson/msinttypes/stdint.h

# Old way to include cpr
# TODO: Remove if not needed for Windows
#        Include/cpr/api.h
#        Include/cpr/auth.h
#        Include/cpr/bearer.h
#        Include/cpr/body.h
#        Include/cpr/callback.h
#        Include/cpr/connect_timeout.h
#        Include/cpr/cookies.h
#        Include/cpr/cpr.h
#        Include/cpr/cprtypes.h
#        Include/cpr/cprver.h
#        Include/cpr/curl_container.h
#        Include/cpr/curlholder.h
#        Include/cpr/digest.h
#        Include/cpr/error.h
#        Include/cpr/http_version.h
#        Include/cpr/interface.h
#        Include/cpr/limit_rate.h
#        Include/cpr/low_speed.h
#        Include/cpr/multipart.h
#        Include/cpr/ntlm.h
#        Include/cpr/parameters.h
#        Include/cpr/payload.h
#        Include/cpr/proxies.h
#        Include/cpr/proxyauth.h
#        Include/cpr/range.h
#        Include/cpr/redirect.h
#        Include/cpr/response.h
#        Include/cpr/session.h
#        Include/cpr/ssl_options.h
#        Include/cpr/status_codes.h
#        Include/cpr/timeout.h
#        Include/cpr/unix_socket.h
#        Include/cpr/user_agent.h
#        Include/cpr/util.h
#        Include/cpr/verbose.h