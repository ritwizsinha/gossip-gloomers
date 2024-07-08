# CMakeLists.txt

cmake_minimum_required(VERSION 3.2.0)

# Set the project name
project(gossip-gloomers)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(gossip-gloomers 
src/main.cc
src/echo.cc
src/initialization.cc
src/idgen.cc
)


target_include_directories(
    gossip-gloomers
    PUBLIC
    ${CMAKE_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}/src
    )

# Find nlohmann_json package
find_package(nlohmann_json 3.2.0 REQUIRED)

# Link nlohmann_json to the executable
target_link_libraries(gossip-gloomers PRIVATE nlohmann_json::nlohmann_json)
enable_testing()
# add_subdirectory("tests")