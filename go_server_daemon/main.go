package main

import (
	"context"
	"encoding/json"
	"fmt"
	pb "http_railway_server/railway_grpc"
	"io"
	"log"
	"mime"
	"net/http"
	"os"
	"strconv"
	"strings"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

var client pb.RailwayClient

func rest_request(w http.ResponseWriter, r *http.Request) {
	println("rest request:" + r.URL.Path)

	w.Header().Set("Contetnt-Type", "application/json")
	switch r.Method {
	case "GET":
		if r.URL.Path == "/rest/get_railway_state" {

			railway, err := client.GetRailwayState(context.Background(), &pb.Empty{})

			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			println(railway.RailNum)
			answer, err := json.Marshal(railway)
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			w.Write(answer)
			return
		}
		if r.URL.Path == "/rest/get_all_trains" {
			trains, err := client.GetAllTrain(context.Background(), &pb.Empty{})

			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}

			answer, err := json.Marshal(trains)
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			w.Write(answer)
			return
		}
		if r.URL.Path == "/rest/get_trains_in_queue" {
			trains, err := client.GetTrainInQueue(context.Background(), &pb.Empty{})
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}

			answer, err := json.Marshal(trains)
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			w.Write(answer)
			return
		}
		if r.URL.Path == "/rest/get_trains_on_rail" {
			trains, err := client.GetTrainOnRail(context.Background(), &pb.Empty{})
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}

			answer, err := json.Marshal(trains)
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			w.Write(answer)
			return
		}
		if strings.Contains(r.URL.Path, "get_train") {
			request_body := strings.Split(r.URL.Path, "/")
			id, err := strconv.Atoi(request_body[len(request_body)-1])
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			request := pb.Train{}
			request.Id = uint32(id)
			train, err := client.GetTrain(context.Background(), &request)
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			answer, err := json.Marshal(train)
			if err != nil {
				io.WriteString(w, "{\"error\" : true}")
				return
			}
			w.Write(answer)
			return
		}

		io.WriteString(w, "{\"error\" : true}")
		return
	}
}
func reader(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case "GET":
		println("New get request:" + r.URL.Path)
		var file []byte
		var err error

		if r.URL.Path == "/" {
			file, err = os.ReadFile("site/index.html")
			sliced := strings.Split(r.URL.Path, ".")
			doc_type := sliced[len(sliced)-1]
			w.Header().Set("Content-Type", mime.TypeByExtension("."+doc_type))
		} else {
			file, err = os.ReadFile("site" + r.URL.Path)
			sliced := strings.Split(r.URL.Path, ".")
			doc_type := sliced[len(sliced)-1]
			w.Header().Set("Content-Type", mime.TypeByExtension("."+doc_type)) //Fix mime type
		}
		if err != nil {

			file, err = os.ReadFile("site/404.html")
			if err != nil {
				log.Fatal("We fucked up")
				os.Exit(-1)
			}
			sliced := strings.Split(r.URL.Path, ".")
			doc_type := sliced[len(sliced)-1]
			w.Header().Set("Content-Type", mime.TypeByExtension("."+doc_type))
		}
		io.WriteString(w, string(file))

	case "POST":
		if err := r.ParseForm(); err != nil {
			fmt.Fprintf(w, "ParseForm() err: %v", err)
			return
		}
		fmt.Fprintf(os.Stdout, "New post request:%v\n", r.PostForm)
	}

}
func main() {

	var opts []grpc.DialOption
	railway_server_ip := "127.0.0.1:50051"
	opts = append(opts, grpc.WithTransportCredentials(insecure.NewCredentials()))
	conn, err := grpc.Dial(railway_server_ip, opts...)
	if err != nil {
		log.Fatalf("fail to dial: %v", err)
	}
	defer conn.Close()

	client = pb.NewRailwayClient(conn)

	http.HandleFunc("/", reader)
	http.HandleFunc("/rest/", rest_request)
	println("SERVER STARTED")
	log.Fatal(http.ListenAndServe(":8080", nil))

}
