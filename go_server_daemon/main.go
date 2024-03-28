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

type VirtualTrainTemplate struct {
	Train_num         string
	Time_interval_min string
	Time_interval_max string
	Time_to_stay      string
}
type GrpcServerConf struct {
	GRPC_server_ip string
	HTTP_server_ip string
}

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

	case "POST":
		if r.URL.Path == "/rest/add_virtual_trains" {
			var v_template pb.VirtualTrainTemplate
			body, err := io.ReadAll(r.Body)
			if err != nil {
				return
			}
			var unmarshaled VirtualTrainTemplate
			err = json.Unmarshal(body, &unmarshaled)
			if err != nil {
				return
			}
			val, err := strconv.Atoi(unmarshaled.Train_num)
			if err != nil {
				return
			}
			v_template.Num = uint32(val)
			val, err = strconv.Atoi(unmarshaled.Time_to_stay)
			if err != nil {
				return
			}
			v_template.TimeToStay = uint32(val)
			val, err = strconv.Atoi(unmarshaled.Time_interval_min)
			if err != nil {
				return
			}
			v_template.TimeIntervalMin = uint32(val)
			val, err = strconv.Atoi(unmarshaled.Time_interval_max)
			if err != nil {
				return
			}
			v_template.TimeIntervalMax = uint32(val)
			_, err = client.AddVirtualTrains(context.Background(), &v_template)
			if err != nil {
				return
			}
		}
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
	var server_conf GrpcServerConf
	server_conf.GRPC_server_ip = "127.0.0.1:50051"
	server_conf.HTTP_server_ip = ":8080"
	conf_file, err := os.ReadFile("http_server_config.json")
	if err == nil {
		json.Unmarshal(conf_file, &server_conf)
	} else {
		println("No http_server_config.json file found. using default options. Http server ip 127.0.0.1:8080; GRPC server ip 127.0.0.1:50051")
	}
	opts = append(opts, grpc.WithTransportCredentials(insecure.NewCredentials()))
	conn, err := grpc.Dial(server_conf.GRPC_server_ip, opts...)
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
