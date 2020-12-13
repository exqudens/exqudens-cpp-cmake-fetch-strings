cmake_minimum_required(VERSION 3.17)
project(exqudens_cpp_cmake_fetch_strings)

# set install path to '${HOME}/.cmake/packages'
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

# enable module 'FetchContent'
include(FetchContent)

# dependency: 'exqudens_strings'
FetchContent_Declare(
        project_exqudens_strings
        URL file://C:/Users/Video/work/tmp/exqudens_strings-1.0.0/master.zip
)
FetchContent_GetProperties(project_exqudens_strings)
if(NOT project_exqudens_strings_POPULATED)
    FetchContent_Populate(project_exqudens_strings)
    add_subdirectory(${project_exqudens_strings_SOURCE_DIR} ${project_exqudens_strings_BINARY_DIR})
    include_directories(${project_exqudens_strings_SOURCE_DIR}/src/main/cpp)
endif()

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}_tests_1 src/test/cpp/tests_1.cpp)
target_link_libraries(
        ${PROJECT_NAME}_tests_1
        PUBLIC
        exqudens_strings
)
