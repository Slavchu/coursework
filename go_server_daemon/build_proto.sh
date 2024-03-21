#!/bin/bash
#Building protobuf for golang 
go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.28
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.2
export PATH="$PATH:$(go env GOPATH)/bin"
protoc --go_out=railway_grpc/ --go_opt=paths=source_relative     --go-grpc_out=railway_grpc/ --go-grpc_opt=paths=source_relative --proto_path=../protobufs/ messages.proto 