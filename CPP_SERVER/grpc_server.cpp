#include <grpc_server.h>
#include <railway.hpp>

::grpc::Status RailwayService::GetRailwayState(::grpc::ServerContext *context, const ::GRPCRailway::Empty *request, ::GRPCRailway::RailwayState *response){
    if(!railway::RailwayStation::get_instance()) return ::grpc::Status::CANCELLED;
    response->set_rail_num(railway::RailwayStation::get_instance()->get_rail_num());
    auto rails = railway::RailwayStation::get_instance()->get_trains_on_rail();
    for(auto it : rails)
        if(it)
            response->add_id(it->get_id());
        else 
            response->add_id(0);
    return ::grpc::Status::OK;
}

::grpc::Status RailwayService::GetTrain(::grpc::ServerContext *context, const ::GRPCRailway::Train *request, ::GRPCRailway::Train *response)
{
    unsigned int id = request->id();
    auto train = railway::RailwayStation::get_instance()->get_train_by_id(request->id());
    response->set_train_state((GRPCRailway::ETrainState)train->get_state());
    return ::grpc::Status::OK;
}
