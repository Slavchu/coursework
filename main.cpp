#include <iostream>
#include <railway.hpp>
#include <grpc_server.h>


int main(){
    srand(time(0));
    time_t current_time = time(0);
    std::cout << "CURRENT TIME"<< ctime(&current_time) << std::endl;
    railway::RailwayStation Railway (rand()%5);

    for(int i = 0; i < 50; i++)
        Railway.register_train(std::make_shared<railway::VirtualTrain>(rand()%10, rand()%20+5));
    
    while(1){

    }
    
    return 0;

}