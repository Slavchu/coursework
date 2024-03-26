#include <messages.grpc.pb.h>
#include <string>
class RailwayService : public GRPCRailway::Railway::Service{
    virtual ::grpc::Status AddVirtualTrains(::grpc::ServerContext* context, const ::GRPCRailway::VirtualTrainTemplate* request, ::GRPCRailway::Empty* response) override;
    virtual ::grpc::Status GetRailwayState(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::RailwayState* response) override;
    virtual ::grpc::Status GetTrain(::grpc::ServerContext* context, const ::GRPCRailway::Train* request, ::GRPCRailway::Train* response) override;
    virtual ::grpc::Status GetTrainInQueue(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response) override;
    virtual ::grpc::Status GetAllTrain(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response) override;
    virtual ::grpc::Status GetTrainOnRail(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response) override;
};
class Server{
    std::string ip;
    unsigned int port;
    public:
    Server(std::string ip, unsigned int port);
    
};