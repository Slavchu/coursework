#include <iostream>
#include <railway.hpp>
int main(){
    srand(time(0));
    railway::RailwayStation Railway (rand()%5);
    for(int i = 0; i < 5; i++)
        Railway.register_train(std::make_shared<railway::VirtualTrain>(rand()%10, rand()%20));
    

    
    return 0;

}