cmake_minimum_required(VERSION 3.17)
project(exqudens_cpp_cmake_fetch_strings)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    if(WIN32)
        string(REPLACE "\\" "/" USER_HOME "$ENV{USERPROFILE}")
        set(CMAKE_INSTALL_PREFIX "${USER_HOME}/.cmake/packages" CACHE PATH "..." FORCE)
        set(CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}" CACHE PATH "..." FORCE)
    elseif(UNIX)
        set(USER_HOME "$ENV{HOME}" CACHE PATH "..." FORCE)
        set(CMAKE_INSTALL_PREFIX "${USER_HOME}/.cmake/packages" CACHE PATH "..." FORCE)
        set(CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}" CACHE PATH "..." FORCE)
    endif()
endif()

set(CMAKE_CXX_STANDARD 20)

find_package(exqudens_strings 1.0.0 REQUIRED)

message(STATUS "exqudens_strings_VERSION: '${exqudens_strings_VERSION}'")

include_directories("${CMAKE_PREFIX_PATH}/exqudens_strings-${exqudens_strings_VERSION}/include")

add_executable(${PROJECT_NAME}_tests_1 src/test/cpp/tests_1.cpp)
target_link_libraries(
        ${PROJECT_NAME}_tests_1
        PUBLIC
        exqudens_strings
)
