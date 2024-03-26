// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: messages.proto

#include "messages.pb.h"
#include "messages.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace GRPCRailway {

static const char* Railway_method_names[] = {
  "/GRPCRailway.Railway/GetRailwayState",
  "/GRPCRailway.Railway/GetTrain",
  "/GRPCRailway.Railway/GetTrainInQueue",
  "/GRPCRailway.Railway/GetAllTrain",
  "/GRPCRailway.Railway/GetTrainOnRail",
  "/GRPCRailway.Railway/AddVirtualTrains",
};

std::unique_ptr< Railway::Stub> Railway::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Railway::Stub> stub(new Railway::Stub(channel, options));
  return stub;
}

Railway::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetRailwayState_(Railway_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTrain_(Railway_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTrainInQueue_(Railway_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetAllTrain_(Railway_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTrainOnRail_(Railway_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddVirtualTrains_(Railway_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Railway::Stub::GetRailwayState(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::GRPCRailway::RailwayState* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::RailwayState, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetRailwayState_, context, request, response);
}

void Railway::Stub::async::GetRailwayState(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::RailwayState* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::RailwayState, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRailwayState_, context, request, response, std::move(f));
}

void Railway::Stub::async::GetRailwayState(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::RailwayState* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRailwayState_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::RailwayState>* Railway::Stub::PrepareAsyncGetRailwayStateRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GRPCRailway::RailwayState, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetRailwayState_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::RailwayState>* Railway::Stub::AsyncGetRailwayStateRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRailwayStateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Railway::Stub::GetTrain(::grpc::ClientContext* context, const ::GRPCRailway::Train& request, ::GRPCRailway::Train* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GRPCRailway::Train, ::GRPCRailway::Train, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetTrain_, context, request, response);
}

void Railway::Stub::async::GetTrain(::grpc::ClientContext* context, const ::GRPCRailway::Train* request, ::GRPCRailway::Train* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GRPCRailway::Train, ::GRPCRailway::Train, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrain_, context, request, response, std::move(f));
}

void Railway::Stub::async::GetTrain(::grpc::ClientContext* context, const ::GRPCRailway::Train* request, ::GRPCRailway::Train* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrain_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::Train>* Railway::Stub::PrepareAsyncGetTrainRaw(::grpc::ClientContext* context, const ::GRPCRailway::Train& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GRPCRailway::Train, ::GRPCRailway::Train, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetTrain_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::Train>* Railway::Stub::AsyncGetTrainRaw(::grpc::ClientContext* context, const ::GRPCRailway::Train& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetTrainRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Railway::Stub::GetTrainInQueue(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::GRPCRailway::TrainArray* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetTrainInQueue_, context, request, response);
}

void Railway::Stub::async::GetTrainInQueue(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainInQueue_, context, request, response, std::move(f));
}

void Railway::Stub::async::GetTrainInQueue(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainInQueue_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::TrainArray>* Railway::Stub::PrepareAsyncGetTrainInQueueRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GRPCRailway::TrainArray, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetTrainInQueue_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::TrainArray>* Railway::Stub::AsyncGetTrainInQueueRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetTrainInQueueRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Railway::Stub::GetAllTrain(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::GRPCRailway::TrainArray* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetAllTrain_, context, request, response);
}

void Railway::Stub::async::GetAllTrain(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetAllTrain_, context, request, response, std::move(f));
}

void Railway::Stub::async::GetAllTrain(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetAllTrain_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::TrainArray>* Railway::Stub::PrepareAsyncGetAllTrainRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GRPCRailway::TrainArray, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetAllTrain_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::TrainArray>* Railway::Stub::AsyncGetAllTrainRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetAllTrainRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Railway::Stub::GetTrainOnRail(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::GRPCRailway::TrainArray* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetTrainOnRail_, context, request, response);
}

void Railway::Stub::async::GetTrainOnRail(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainOnRail_, context, request, response, std::move(f));
}

void Railway::Stub::async::GetTrainOnRail(::grpc::ClientContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetTrainOnRail_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::TrainArray>* Railway::Stub::PrepareAsyncGetTrainOnRailRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GRPCRailway::TrainArray, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetTrainOnRail_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::TrainArray>* Railway::Stub::AsyncGetTrainOnRailRaw(::grpc::ClientContext* context, const ::GRPCRailway::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetTrainOnRailRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Railway::Stub::AddVirtualTrains(::grpc::ClientContext* context, const ::GRPCRailway::VirtualTrainTemplate& request, ::GRPCRailway::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GRPCRailway::VirtualTrainTemplate, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddVirtualTrains_, context, request, response);
}

void Railway::Stub::async::AddVirtualTrains(::grpc::ClientContext* context, const ::GRPCRailway::VirtualTrainTemplate* request, ::GRPCRailway::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GRPCRailway::VirtualTrainTemplate, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddVirtualTrains_, context, request, response, std::move(f));
}

void Railway::Stub::async::AddVirtualTrains(::grpc::ClientContext* context, const ::GRPCRailway::VirtualTrainTemplate* request, ::GRPCRailway::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddVirtualTrains_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::Empty>* Railway::Stub::PrepareAsyncAddVirtualTrainsRaw(::grpc::ClientContext* context, const ::GRPCRailway::VirtualTrainTemplate& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GRPCRailway::Empty, ::GRPCRailway::VirtualTrainTemplate, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddVirtualTrains_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GRPCRailway::Empty>* Railway::Stub::AsyncAddVirtualTrainsRaw(::grpc::ClientContext* context, const ::GRPCRailway::VirtualTrainTemplate& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddVirtualTrainsRaw(context, request, cq);
  result->StartCall();
  return result;
}

Railway::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Railway_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Railway::Service, ::GRPCRailway::Empty, ::GRPCRailway::RailwayState, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Railway::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GRPCRailway::Empty* req,
             ::GRPCRailway::RailwayState* resp) {
               return service->GetRailwayState(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Railway_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Railway::Service, ::GRPCRailway::Train, ::GRPCRailway::Train, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Railway::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GRPCRailway::Train* req,
             ::GRPCRailway::Train* resp) {
               return service->GetTrain(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Railway_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Railway::Service, ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Railway::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GRPCRailway::Empty* req,
             ::GRPCRailway::TrainArray* resp) {
               return service->GetTrainInQueue(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Railway_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Railway::Service, ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Railway::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GRPCRailway::Empty* req,
             ::GRPCRailway::TrainArray* resp) {
               return service->GetAllTrain(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Railway_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Railway::Service, ::GRPCRailway::Empty, ::GRPCRailway::TrainArray, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Railway::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GRPCRailway::Empty* req,
             ::GRPCRailway::TrainArray* resp) {
               return service->GetTrainOnRail(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Railway_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Railway::Service, ::GRPCRailway::VirtualTrainTemplate, ::GRPCRailway::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Railway::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GRPCRailway::VirtualTrainTemplate* req,
             ::GRPCRailway::Empty* resp) {
               return service->AddVirtualTrains(ctx, req, resp);
             }, this)));
}

Railway::Service::~Service() {
}

::grpc::Status Railway::Service::GetRailwayState(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::RailwayState* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Railway::Service::GetTrain(::grpc::ServerContext* context, const ::GRPCRailway::Train* request, ::GRPCRailway::Train* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Railway::Service::GetTrainInQueue(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Railway::Service::GetAllTrain(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Railway::Service::GetTrainOnRail(::grpc::ServerContext* context, const ::GRPCRailway::Empty* request, ::GRPCRailway::TrainArray* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Railway::Service::AddVirtualTrains(::grpc::ServerContext* context, const ::GRPCRailway::VirtualTrainTemplate* request, ::GRPCRailway::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace GRPCRailway

