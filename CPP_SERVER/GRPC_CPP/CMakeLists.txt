cmake_minimum_required(VERSION 3.15)

add_library(GRPC_CPP_RAILWAY messages.grpc.pb.cc messages.pb.cc messages.pb.h messages.grpc.pb.h)
target_link_libraries(GRPC_CPP_RAILWAY grpc++ ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})
target_include_directories (GRPC_CPP_RAILWAY PUBLIC .)
find_package(gRPC CONFIG REQUIRED)
target_link_libraries(GRPC_CPP_RAILWAY gRPC::grpc++   ${_REFLECTION}
${_GRPC_GRPCPP}
${_PROTOBUF_LIBPROTOBUF})