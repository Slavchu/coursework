package main

import (
	"fmt"
	"io"
	"log"
	"mime"
	"net/http"
	"os"
	"strings"
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
	http.Handle("/image/", http.StripPrefix("/image/", http.FileServer(http.Dir("./site/image")))) //Image Fix...'''
	http.HandleFunc("/", reader)
	println("SERVER STARTED")
	log.Fatal(http.ListenAndServe(":8080", nil))

}
