cmake_minimum_required(VERSION 3.15)
find_package(gRPC CONFIG REQUIRED)
message("GENERAATING GRPC")
message("${CMAKE_CURRENT_SOURCE_DIR}")

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/messages.grpc.pb.cc ${CMAKE_CURRENT_SOURCE_DIR}/messages.grpc.pb.h ${CMAKE_CURRENT_SOURCE_DIR}/messages.pb.cc ${CMAKE_CURRENT_SOURCE_DIR}/messages.pb.h 
    COMMAND "protoc"
    ARGS 
        -I "${CMAKE_CURRENT_SOURCE_DIR}/../../protobufs" 
        "--plugin=protoc-gen-grpc=/usr/bin/grpc_cpp_plugin"
        --grpc_out="${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../protobufs/messages.proto" 
    DEPENDS "../../protobufs/messages.proto"
)



add_library(GRPC_CPP_RAILWAY messages.grpc.pb.cc messages.pb.cc messages.pb.h messages.grpc.pb.h)
target_link_libraries(GRPC_CPP_RAILWAY grpc++ ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})
target_include_directories (GRPC_CPP_RAILWAY PUBLIC .)
target_link_libraries(GRPC_CPP_RAILWAY gRPC::grpc++   ${_REFLECTION}
${_GRPC_GRPCPP}
${_PROTOBUF_LIBPROTOBUF})