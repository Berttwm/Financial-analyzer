include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Header)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Metric)
add_library(Parser
            CLIParser.cpp
            CMakeLists.txt
            ParseAllCmd.cpp
            ParseCategoryCmd.cpp
            ParseHelpCmd.cpp
            ParseMetricCmd.cpp
            )
target_link_libraries(Parser PRIVATE Include)