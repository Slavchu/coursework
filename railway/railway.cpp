#include <railway.hpp>
using namespace railway;

RailwayStation*  RailwayStation::station_instance = 0;


railway::RailwayStation::RailwayStation(const int &rail_num){
    if(station_instance) return;
    station_instance = this;
    rails.resize(rail_num);
    

}

int railway::RailwayStation::get_rail_num() const{
    return 0;
}

int railway::RailwayStation::get_train_queue_size() const{
    return 0;
}

std::vector<std::shared_ptr<const ITrain>> railway::RailwayStation::get_trains_on_rail() const{
}

RailwayStation *railway::RailwayStation::get_instance(){
    return nullptr;
}
