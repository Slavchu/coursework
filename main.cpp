#include <iostream>
#include <railway.hpp>
#include <grpc_server.h>
#include <fstream>

int main(){
    std::string ip = "0.0.0.0";
    unsigned int port = 50051;
    std::ifstream server_conf("server.config");
    if(server_conf.is_open()){
        server_conf >> ip;
        server_conf >> port;
    }
    else{
        std::cout << "server.config not found. Running grpc server on 0.0.0.0:50051\n";
    }
    Server(ip, port);
    srand(time(0));
    unsigned int rails = 5;
    std::ifstream railway_conf("railway.config");
    if(railway_conf.is_open()){
        railway_conf >> rails;
    }
    else{
        std::cout << "server.config not found. Railway will have default params\n";
    }
    railway::RailwayStation Railway (rails);
    
    
    

    return 0;

}