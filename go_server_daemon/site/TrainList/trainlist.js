async function rest_request( request) {
    response = await fetch("/rest/" + request, { mode: "no-cors" })
    return response.json();
}
function set_train_table(trains_json, table_id){
    let all_trains_table = document.getElementById(table_id)
    all_trains_table.innerHTML = "<tr> <th>ID</th> <th>Name</th> <th>State</th> <th>Wagons</th> </tr>";
    if(trains_json["train_array"]){ 
    let trains = trains_json["train_array"]
    for(i = 0; i < trains.length; i++){
        let appended_code = document.createElement("tr")
        let th = document.createElement("th") 
        th.appendChild( document.createTextNode(trains[i]["id"]))
        appended_code.appendChild(th);
        th = document.createElement("th") 
        th.appendChild( document.createTextNode(trains[i]["name"]))
        appended_code.appendChild(th);
        
        
        switch(trains[i]["train_state"]){
            
            case 1:{
                th = document.createElement("th") 
                th.appendChild( document.createTextNode("IN QUEUE"))
                appended_code.appendChild(th);
                break;
            }
            case 2:{
                th = document.createElement("th") 
                th.appendChild( document.createTextNode("ARRIVED"))
                appended_code.appendChild(th);
                break;
            }
            case 3:{
                th = document.createElement("th") 
                th.appendChild( document.createTextNode("DEPARTURED"))
                appended_code.appendChild(th);
                break;
            }
            default :{
                th = document.createElement("th") 
                th.appendChild( document.createTextNode("IN TRIP"))
                appended_code.appendChild(th);
            }
        }
        th = document.createElement("th") 
        th.appendChild( document.createTextNode(trains[i]["wagons"]))
        appended_code.appendChild(th);
        
        all_trains_table.appendChild(appended_code)
        
    }
}
}

async function main(){
    let all_trains = await rest_request("get_all_trains");
    let trains_in_queue = await rest_request("get_trains_in_queue")
    
    let trains_on_rail = await rest_request("get_trains_on_rail")
    console.log(trains_on_rail)
    set_train_table(all_trains, "all_trains")    
    set_train_table(trains_in_queue, "trains_in_queue")
    set_train_table(trains_on_rail, "trains_on_rail")

}
main()
setInterval(main, 1000)