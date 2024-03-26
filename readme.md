<h1>Railway station</h1>
<h2>How to run?</h2>
To run this program you have to have those packages:
<ul>
    <li>CMake</li>
    <li>C++ compiler</li>
    <li>go compiler</li>
    <li>grpc</li>
    <li>protoc compiler</li>
</ul>
</br>
On <p style="display:inline; color:red">linux</p> you have to run script in go_server_daemon/build_proto.sh.

```
./go_server_daemon/build_proto.sh
```

</br></br> 
<p style="display:inline; color:red;"> On windows</p> you have to run those commands in go_server_daemon directory:

```
go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.28
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.2
protoc --go_out=railway_grpc/ --go_opt=paths=source_relative     --go-grpc_out=railway_grpc/ --go-grpc_opt=paths=source_relative --proto_path=../protobufs/ messages.proto 

``` 
</br></br>
Next step you need to build all application

```shell
cmake --build build
```

In "bin" dir you'll have two executables. Firstly you'll have to run Train_Station, after http_server. Also you can create config for each executables;

<h2>Technologies used:</h2>
<ul>
    <li>CMake</li>
    <li>C++</li>
    <li>GO</li>
    <li>STL</li>
    <li>gRPC</li>
    <li>REST api</li>
    <li>Multithreading</li>
    
</ul>