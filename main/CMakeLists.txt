cmake_minimum_required(VERSION 3.10)

project(Financial-analyzer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

add_subdirectory(Metric)
add_subdirectory(Parser)
add_subdirectory(Storage)

add_executable(Analyzer main.cpp)

target_link_libraries(Analyzer PUBLIC Metric Parser Storage)
target_include_directories(Analyzer PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/../Include"
                            "${PROJECT_SOURCE_DIR}/Metric"
                            "${PROJECT_SOURCE_DIR}/Parser"
                            "${PROJECT_SOURCE_DIR}/Storage"
                            )