


#include <grpc_server.h>
#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <railway.hpp>

::grpc::Status RailwayService::GetRailwayState(::grpc::ServerContext *context, const ::GRPCRailway::Empty *request, ::GRPCRailway::RailwayState *response){
    if(!railway::RailwayStation::get_instance()) return ::grpc::Status::CANCELLED;
    response->set_rail_num(railway::RailwayStation::get_instance()->get_rail_num());
    auto rails = railway::RailwayStation::get_instance()->get_trains_on_rail();
    
    for(auto it : rails)
        if(it){
            auto train = it;
            auto trains = response->add_trains();
            trains->set_name(train->get_train_name());
            trains->set_train_state((::GRPCRailway::ETrainState) train->get_state());
            trains->set_id(train->get_id());
            trains->set_wagons(train->get_wagons());
        }
        else{ 
            response->add_trains()->set_id(0);
        }
    return ::grpc::Status::OK;
}

::grpc::Status RailwayService::GetTrain(::grpc::ServerContext *context, const ::GRPCRailway::Train *request, ::GRPCRailway::Train *response)
{
    unsigned int id = request->id();
    auto train = railway::RailwayStation::get_instance()->get_train_by_id(request->id());
    response->set_train_state((GRPCRailway::ETrainState)train->get_state());
    return ::grpc::Status::OK;
}

::grpc::Status RailwayService::GetTrainInQueue(::grpc::ServerContext *context, const ::GRPCRailway::Empty *request, ::GRPCRailway::TrainArray *response)
{
    if(!railway::RailwayStation::get_instance()) return ::grpc::Status::CANCELLED;
    auto all_in_queue = railway::RailwayStation::get_instance()->get_trains_in_queue();

    for(auto &it : all_in_queue){
        
        auto res = response->add_train_array();
        res->set_id( it->get_id());
        res->set_name(it->get_train_name());
        res->set_train_state((::GRPCRailway::ETrainState)it->get_state());
        res->set_wagons(it->get_wagons());
    }
    return ::grpc::Status::OK;
}

::grpc::Status RailwayService::GetAllTrain(::grpc::ServerContext *context, const ::GRPCRailway::Empty *request, ::GRPCRailway::TrainArray *response)
{
    if(!railway::RailwayStation::get_instance()) return ::grpc::Status::CANCELLED;
    auto all_trains = railway::RailwayStation::get_instance()->get_all_trains();
    for(auto &it : all_trains){
        
        auto res = response->add_train_array();
        res->set_id( it->get_id());
        res->set_name(it->get_train_name());
        res->set_train_state((::GRPCRailway::ETrainState)it->get_state());
        res->set_wagons(it->get_wagons());
    }
    return ::grpc::Status::OK;
}

::grpc::Status RailwayService::GetTrainOnRail(::grpc::ServerContext *context, const ::GRPCRailway::Empty *request, ::GRPCRailway::TrainArray *response)
{
    if(!railway::RailwayStation::get_instance()) return ::grpc::Status::CANCELLED;
    auto all_on_rail = railway::RailwayStation::get_instance()->get_trains_on_rail();
    for(auto &it : all_on_rail){
        if(it){
            auto res = response->add_train_array();
            res->set_id( it->get_id());
            res->set_name(it->get_train_name());
            res->set_train_state((::GRPCRailway::ETrainState)it->get_state());
            res->set_wagons(it->get_wagons());
        }
        
    }
    return ::grpc::Status::OK;
}

Server::Server(std::string ip, unsigned int port){
    RailwayService service;
    this->ip = ip;
    this->port = port;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(ip+":"+std::to_string(port), grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    auto server = builder.BuildAndStart();
    std::cout << "Server Started!\n";
    server->Wait();
    
}
