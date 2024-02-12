cmake_minimum_required(VERSION 3.26)
project(AdvancedDesktop)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -static-libstdc++ -static-libgcc -fpermissive")
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(include)

file(GLOB HEADER_FILES "include/**/*.hpp" "include/*.hpp")
file(GLOB SOURCE_FILES "src/**/*.cpp" "src/*.cpp")

add_executable(AdvancedDesktop ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(AdvancedDesktop PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
