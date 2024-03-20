cmake_minimum_required(VERSION 3.14)
project(Train_Station)


add_executable(Train_Station main.cpp)

add_subdirectory(railway)
target_link_libraries(Train_Station RailwayManager)
