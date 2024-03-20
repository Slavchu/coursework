#include <railway.hpp>
#include <thread>
#include <mutex>
#include <chrono>

using namespace railway;

RailwayStation*  RailwayStation::station_instance = 0;
std::atomic<unsigned int> RailwayStation::id_counter = 0;

railway::RailwayStation::RailwayStation(const int &rail_num){
    if(station_instance) return;
    station_instance = this;
    rails.resize(rail_num);
    

}

void railway::RailwayStation::train_event(const unsigned int &train_id, const ETrainEvent &train_event){
    switch(train_event){
        case ETrainEvent::TRAIN_ARRIVED:{
            for(auto &it : rails){
                if(it == NULL){
                    it=trains[train_id];
                    it->state= ETrainState::ARRIVED;
                    return;
                }
            }
            auto train = trains[train_id];
            train->state = ETrainState::IN_QUEUE;
            train_queue.push(train);
            break;
        }
        case ETrainEvent::TRAIN_DEPARTURING:{
            for(auto &it : rails){
                if(it == NULL){
                    
                    it->state= ETrainState::DEPARTURED;
                    
                    it = train_queue.front();
                    train_queue.pop();
                    it->state = ETrainState::ARRIVED;
                }
            }
            break;
        }
        case ETrainEvent::TRAIN_LATE:{
            break;
        }
    }
}

int railway::RailwayStation::get_rail_num() const{
    return rail_num;
}

int railway::RailwayStation::get_train_queue_size() const{
    return train_queue.size();
}

std::vector<std::shared_ptr<ITrain>> railway::RailwayStation::get_trains_on_rail() const{
    return rails;
}

RailwayStation *railway::RailwayStation::get_instance(){

    return RailwayStation::station_instance;
}

void railway::RailwayStation::register_train(std::shared_ptr<ITrain> train){
    if(train){
        
        if(!train->id){
            id_counter++;
            train->id = id_counter;
        }
        trains.insert(std::make_pair(train->id, train));
        
    }
}

void railway::VirtualTrain::tick(){
    time_t depart_time = time(0); 
    arriving_time = depart_time = time_for_road + depart_time; 
    while(1){
        
        if(!random()%30){
            arriving_time+= random()%15;
            RailwayStation::get_instance()->train_event(this->id, ETrainEvent::TRAIN_LATE);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

railway::VirtualTrain::VirtualTrain(unsigned int wagons, unsigned int time_to_arrive)
{
    
    this->wagons = wagons;
    this->time_for_road = time_to_arrive;
    this->state = ETrainState::IN_TRIP;
    std::thread(&VirtualTrain::tick, this).detach();
}

void railway::VirtualTrain::update_params(){

}
railway::ITrain::ITrain(){

}
