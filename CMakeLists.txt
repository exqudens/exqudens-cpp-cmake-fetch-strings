cmake_minimum_required(VERSION 3.17)

set(PROJECT_GROUP "exqudens")

project("${PROJECT_GROUP}-cpp-cmake-fetch-strings" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

# set '${USER_HOME}'
if(WIN32)
    string(REPLACE "\\" "/" USER_HOME "$ENV{USERPROFILE}")
elseif(UNIX)
    set(USER_HOME "$ENV{HOME}")
else()
    message(FATAL_ERROR "Can't set USER_HOME")
endif()

# set install path to '${USER_HOME}/.cmake/packages'
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${USER_HOME}/.cmake/packages" CACHE PATH "..." FORCE)
    set(CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}" CACHE PATH "..." FORCE)
endif()

find_package(exqudens-cpp-cmake-strings 1.0.0 REQUIRED)

get_target_property(
        VAR_1
        exqudens-cpp-cmake-strings::exqudens-cpp-cmake-strings
        INTERFACE_INCLUDE_DIRECTORIES
)
message(STATUS "exqudens-cpp-cmake-strings::exqudens-cpp-cmake-strings INTERFACE_INCLUDE_DIRECTORIES: ${VAR_1}")

enable_testing()
add_executable(${PROJECT_NAME}_tests_1 src/test/cpp/tests_1.cpp)
target_link_libraries(${PROJECT_NAME}_tests_1
    PRIVATE
        exqudens-cpp-cmake-strings::exqudens-cpp-cmake-strings
)
target_include_directories(${PROJECT_NAME}_tests_1
    PRIVATE
        ${VAR_1}
)

add_test(${PROJECT_NAME}_tests_1_test_1 ${PROJECT_NAME}_tests_1 test_1)

add_custom_command(
        TARGET ${PROJECT_NAME}_tests_1
        POST_BUILD
        COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --output-on-failure
)
