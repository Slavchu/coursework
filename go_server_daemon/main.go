package httpserver_go

import (
	"fmt"
	"io"
	"log"
	"mime"
	"net/http"
	"os"
	"strings"

	pb "http_railway_server/railway_grpc"

	"google.golang.org/grpc"
)

func reader(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case "GET":
		println("New get request:" + r.URL.Path)
		var file []byte
		var err error
		if r.URL.Path == "/" {
			file, err = os.ReadFile("site/index.html")
			w.Header().Set("Content-Type", "text.html")
		} else {
			file, err = os.ReadFile("site" + r.URL.Path)
			sliced := strings.Split(r.URL.Path, ".")
			type_ := sliced[len(sliced)-1]
			w.Header().Set("Content-Type", mime.TypeByExtension(type_)) //Fix mime type
		}
		if err != nil {

			file, err = os.ReadFile("site/404.html")
			if err != nil {
				log.Fatal("We fucked up")
				os.Exit(-1)
			}
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
	railway_server_ip := "localhost:50051"
	conn, err := grpc.Dial(*&railway_server_ip, opts...)
	if err != nil {

	}
	defer conn.Close()
	client := pb.NewRouteGuideClient(conn)
	train, err := client.GetTrain(4)
	if err == nil {
		println(train.state)
	}
	http.Handle("/image/", http.StripPrefix("/image/", http.FileServer(http.Dir("./site/image")))) //Image Fix...'''
	http.HandleFunc("/", reader)
	println("SERVER STARTED")
	log.Fatal(http.ListenAndServe(":8080", nil))

}
