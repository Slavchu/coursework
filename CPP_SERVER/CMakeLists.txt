add_subdirectory(GRPC_CPP)
add_library(grpc_server grpc_server.cpp include/grpc_server.h)
target_include_directories(grpc_server PUBLIC include)
target_link_libraries(grpc_server GRPC_CPP_RAILWAY)
target_link_libraries(grpc_server RailwayManager)
find_package(gRPC CONFIG REQUIRED)
target_link_libraries(grpc_server gRPC::grpc++   ${_PROTOBUF_LIBPROTOBUF}
${_REFLECTION}
${_GRPC_GRPCPP})