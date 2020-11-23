cmake_minimum_required(VERSION 3.17)
project(exqudens_cpp_cmake_fetch_strings)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# dependency: 'exqudens_strings'
FetchContent_Declare(
        project_exqudens_strings
        URL https://github.com/exqudens/exqudens-cpp-cmake-strings/archive/master.zip
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
)
FetchContent_GetProperties(project_exqudens_strings)
if(NOT project_exqudens_strings_POPULATED)
    FetchContent_Populate(project_exqudens_strings)
    add_subdirectory(${project_exqudens_strings_SOURCE_DIR} ${project_exqudens_strings_BINARY_DIR})
    include_directories(${project_exqudens_strings_SOURCE_DIR}/src/main/cpp)
endif()

add_executable(${PROJECT_NAME}_tests_1 src/test/cpp/tests_1.cpp)
target_link_libraries(
        ${PROJECT_NAME}_tests_1
        PUBLIC
        exqudens_strings
)
