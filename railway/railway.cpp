#include <railway.hpp>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <iomanip>
using namespace railway;

std::mutex io_mutex;

RailwayStation*  RailwayStation::station_instance = 0;
std::atomic<unsigned int> RailwayStation::id_counter = 0;

railway::RailwayStation::RailwayStation(const int &rail_num){
    if(station_instance) return;
    station_instance = this;
    rails.resize(rail_num);
    id_counter = 0;

}

void railway::RailwayStation::train_event(const unsigned int &train_id, const ETrainEvent &train_event){
    io_mutex.lock();
    std::cout << "Registred event. \tTRAIN_ID:" << std::setw(5) << train_id << "\tEVENT:";
    switch(train_event){    
        case ETrainEvent::TRAIN_ARRIVED:{
            std::cout << "TRAIN_ARRIVED\n";
            for(auto &it : rails){
                if(it == NULL){
                    it=trains[train_id];
                    it->state= ETrainState::ARRIVED;
                    io_mutex.unlock();

                    return;
                }
            }
            std::cout << "Train in QUEUE.\n";
            auto train = trains[train_id];
            train->state = ETrainState::IN_QUEUE;
            train_queue.push(train);
            io_mutex.unlock();

            break;
        }
        case ETrainEvent::TRAIN_DEPARTURING:{
            std::cout << "TRAIN_DEPARTURING\n";
            io_mutex.unlock();
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
            std::cout << "TRAIN_LATE\n";
            io_mutex.unlock();
            break;
        }
        default:{
            io_mutex.unlock();
        }
    }
}

std::shared_ptr<ITrain> railway::RailwayStation::get_train_by_id(unsigned int id){
    if(trains.find(id) != trains.end()){
        return trains[id];
    }
    return 0;
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
    std::cout << "[DEBUG INFO]" << id_counter << std::endl;
    if(train){
        
        if(!train->id){
            id_counter++;
            train->id = id_counter;
        }
        trains.insert(std::make_pair(train->id, train));
        io_mutex.lock();
        std::cout << "TRAIN REGISTRED\tID:"<< std::setw(5) << train->id << "\tARIIVING TIME:" << ctime(&train->arriving_time) << std::endl;
        io_mutex.unlock();
    }
}

void railway::VirtualTrain::tick(){
    
    while(1){
        if(time(0) >= arriving_time){
            RailwayStation::get_instance()->train_event(this->id, ETrainEvent::TRAIN_ARRIVED);
            break;   
        }
        if(random()%30 == 1){
            arriving_time+= random()%15;
            RailwayStation::get_instance()->train_event(this->id, ETrainEvent::TRAIN_LATE);
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    RailwayStation::get_instance()->train_event(this->id, ETrainEvent::TRAIN_DEPARTURING);
}

railway::VirtualTrain::VirtualTrain(unsigned int wagons, unsigned int time_to_arrive){
    
    this->id = 0;
    this->wagons = wagons;
    this->time_for_road = time_to_arrive;
    this->state = ETrainState::IN_TRIP;
    time_t depart_time = time(0); 
    arriving_time = time_for_road + depart_time; 
    std::thread(&VirtualTrain::tick, this).detach();
}

void railway::VirtualTrain::update_params(){

}
unsigned int railway::ITrain::get_id() const{
    return this->id;
}
ETrainState railway::ITrain::get_state() const
{
    return this->state;
}
railway::ITrain::ITrain(){
    
}
