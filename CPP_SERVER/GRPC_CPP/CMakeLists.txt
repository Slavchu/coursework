cmake_minimum_required(VERSION 3.15)

find_package(gRPC CONFIG REQUIRED)
add_library(GRPC_CPP_RAILWAY messages.grpc.pb.cc)
target_link_libraries(GRPC_CPP_RAILWAY grpc++)
target_include_directories (GRPC_CPP_RAILWAY PUBLIC .)
