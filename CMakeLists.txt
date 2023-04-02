cmake_minimum_required(VERSION 2.8.12)

PROJECT(EikonalEquation)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

ADD_EXECUTABLE(EikonalEquation src/main.cpp)

TARGET_LINK_LIBRARIES(EikonalEquation dl m)
