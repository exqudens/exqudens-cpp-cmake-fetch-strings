cmake_minimum_required(VERSION 3.17)

set(PROJECT_GROUP "exqudens")

project("${PROJECT_GROUP}-cpp-cmake-fetch-strings" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/extension.cmake")
    file(
            DOWNLOAD
            "https://raw.githubusercontent.com/exqudens/exqudens-cmake/1.2.0/extension.cmake"
            "${CMAKE_CURRENT_SOURCE_DIR}/extension.cmake"
    )
endif()
include("${CMAKE_CURRENT_SOURCE_DIR}/extension.cmake")

dependency(
        exqudens-strings
        1.0.0
        https://github.com/exqudens/exqudens-cpp-cmake-strings/archive/master.zip
)

dependencies()

add_executable(${PROJECT_NAME}_tests_1 src/test/cpp/tests_1.cpp)
target_link_libraries(
        ${PROJECT_NAME}_tests_1
        PUBLIC
        ${DEPENDENCY_exqudens-strings_EXPORT_LIBRARIES}
)
