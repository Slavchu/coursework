#include <messages.grpc.pb.h>
#include <string>
class RailwayService : public GRPCRailway::Railway::Service{
    virtual ::grpc::Status GetRailwayState(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::RailwayState* response) override;
    virtual ::grpc::Status GetTrain(::grpc::ServerContext* context, const ::GRPCRailway::Train* request, ::GRPCRailway::Train* response) override;
};
class Server{
    std::string ip;
    unsigned int port;
    public:
    Server(std::string ip, unsigned int port);
    
};