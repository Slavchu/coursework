#include <railway.hpp>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace railway;
std::mutex railway_state_mutex;

std::mutex io_mutex;
std::mutex train_mutex;
RailwayStation*  RailwayStation::class_instance = 0;
std::atomic<unsigned int> RailwayStation::id_counter = 0;
RailwayStationStat * RailwayStationStat::class_instance = 0;


railway::RailwayStation::RailwayStation(const int &rail_num){
    if(class_instance) return;
    this->rail_num = rail_num;
    std::cout << "Rail num:" << rail_num << std::endl;
    class_instance = this;
    rails.resize(rail_num);
    id_counter = 0;

}

void railway::RailwayStation::train_event(const unsigned int &train_id, const ETrainEvent &train_event){
    io_mutex.lock();
    std::cout << "Registred event. \tTRAIN_ID:" << std::setw(5) << train_id << "\tEVENT:";
    train_mutex.lock();

    switch(train_event){    
        case ETrainEvent::TRAIN_ARRIVED:{
            std::cout << "TRAIN_ARRIVED\n";
            for(auto &it : rails){
                if(it == NULL){
                    it=trains[train_id];
                    it->state= ETrainState::ARRIVED;
                    train_mutex.unlock();
                    io_mutex.unlock();
                    return;
                }
            }
            std::cout << "Train in QUEUE.\n";
            auto train = trains[train_id];
            train->state = ETrainState::IN_QUEUE;
            train_queue.push_back(train);
            io_mutex.unlock();
            train_mutex.unlock();
            break;
        }
        case ETrainEvent::TRAIN_DEPARTURING:{
            std::cout << "TRAIN_DEPARTURING\n";
            io_mutex.unlock();
            for(auto &it : rails){
                
                if(it && it->id == train_id ){    
                    it->state= ETrainState::DEPARTURED;
                    it=NULL;
                    if(!train_queue.empty()){
                        it = train_queue.front();
                        train_queue.pop_front();
                        it->state = ETrainState::ARRIVED;
                    }
                }
            }
            train_mutex.unlock();
            break;
        }
        case ETrainEvent::TRAIN_LATE:{
            std::cout << "TRAIN_LATE\n";
            io_mutex.unlock();
            train_mutex.unlock();
            break;
        }
        default:{
            train_mutex.unlock();
            io_mutex.unlock();
        }
    }
}

std::shared_ptr<ITrain> railway::RailwayStation::get_train_by_id(const unsigned int &id){
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

std::vector<std::shared_ptr<ITrain>> railway::RailwayStation::get_all_trains() const{
    std::vector <std::shared_ptr<ITrain>> trains;
    for(auto it: this->trains){
        trains.push_back(it.second);
    }

    return trains;
}

std::vector<std::shared_ptr<ITrain>> railway::RailwayStation::get_trains_in_queue() const
{
    std::vector <std::shared_ptr<ITrain>> trains;
    for(auto it: train_queue){
        trains.push_back(it);
    }

    return trains;
}

std::vector<std::shared_ptr<ITrain>> railway::RailwayStation::get_trains_on_rail() const{
    return rails;
}

RailwayStation *railway::RailwayStation::get_instance(){

    return RailwayStation::class_instance;
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
        if(random()%30 == 1 && delayed_times < 4){
            delayed_times++;
            if(random()%4)
                lateness += random()%120 + 1;
            else lateness += random()%20 + 1;
            arriving_time+= lateness; 
            this->state = ETrainState::IN_TRIP_LATE;
            RailwayStation::get_instance()->train_event(this->id, ETrainEvent::TRAIN_LATE);
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    RailwayStation::get_instance()->train_event(this->id, ETrainEvent::TRAIN_DEPARTURING);
}

railway::VirtualTrain::VirtualTrain(unsigned int wagons, unsigned int time_to_arrive, unsigned int time_to_stay){
    this->train_name = "Virtual";
    this->id = 0;
    delayed_times = 0;
    this->wagons = wagons;
    this->time_for_road = time_to_arrive;
    this->state = ETrainState::IN_TRIP;
    this->time_to_stay = time_to_stay;
    time_t depart_time = time(0); 
    arriving_time = time_for_road + depart_time; 
    std::thread(&VirtualTrain::tick, this).detach();
}

void railway::VirtualTrain::update_params(){

}
unsigned int railway::ITrain::get_lateness() const
{
    return this->lateness;
}
unsigned int railway::ITrain::get_id() const
{
    return this->id;
}
unsigned int railway::ITrain::get_wagons() const
{
    return this->wagons;
}
std::time_t railway::ITrain::get_arriving_time() const
{
    return this->arriving_time;
}
std::string railway::ITrain::get_arriving_time_string() const //todo
{
    return std::string();
}
std::string railway::ITrain::get_train_name() const
{
    return train_name;
}
void railway::ITrain::set_train_name(const std::string &name){
    train_name = name;
}

ETrainState railway::ITrain::get_state() const
{
    return this->state;
}
railway::ITrain::ITrain(){
    
}

unsigned int railway::RailwayStationStat::get_average_delay(){
    auto trains = RailwayStation::get_instance()->get_all_trains();
    unsigned int sum = 0;
    unsigned int counter = 0;
    for(auto it : trains){
        if(it->get_state() == ETrainState::IN_TRIP_LATE){
            sum+=it->get_lateness();
            counter++;
        }
    }
    railway_state_mutex.lock();
    if(counter > trains.size()/5 && counter > 5){
        this->average_delay = sum/counter + (sum%counter > counter/2);   //Avoid float trick
    }
    auto average = this->average_delay;
    railway_state_mutex.unlock();
    return average;

}

RailwayStationStat *railway::RailwayStationStat::get_instance()
{
    if(!class_instance){ 
        class_instance = new RailwayStationStat();
        class_instance->average_delay = 0;
    }
    
    return class_instance;
}
