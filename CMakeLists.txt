cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")

project(leetcode)

include_directories(include
    ${PROJECT_SOURCE_DIR}
)

add_executable(burst-balloons
    ${PROJECT_SOURCE_DIR}/src/working/312_burst-balloons.cpp
)

add_executable(remove-dup
    ${PROJECT_SOURCE_DIR}/src/working/316_remove-dup-char.cpp
)

#add_executable(buy-sell-stock
#    ${PROJECT_SOURCE_DIR}/src/working/188_buy-sell-stock.c
#)
