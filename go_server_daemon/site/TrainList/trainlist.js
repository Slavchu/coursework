async function rest_request( request) {
    response = await fetch("/rest/" + request, { mode: "no-cors" })
    return response.json();
}
function set_train_table(trains_json, table_id){
    if(trains_json["average_delay"]){
            let seconds = trains_json["average_delay"]
            let minutes = Math.floor(seconds/60);
            seconds%=60;
            let hours = Math.floor(minutes/ 60);
            minutes%=60;
        let stat_component = document.getElementById("Stats")
        stat_component.innerHTML = "<p>Average delay:" + hours + ":" + minutes + ":" + seconds+"</p>";
    }
    let all_trains_table = document.getElementById(table_id)
    all_trains_table.innerHTML = "<tr> <th>ID</th>  <th>State</th> <th>Wagons</th>  <th>Delay time</th> </tr>";
    if(trains_json["train_array"]){ 
    let trains = trains_json["train_array"]
    for(i = 0; i < trains.length; i++){
        let appended_code = document.createElement("tr")
        let th = document.createElement("th") 
        th.appendChild( document.createTextNode(trains[i]["id"]))
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
            case 4:{
                th = document.createElement("th") 
                th.appendChild( document.createTextNode("DELAYED"))
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
        if(trains[i]["train_state"] == 4){

            let seconds = trains[i]["lateness"]
            let minutes = Math.floor(seconds/60);
            seconds%=60;
            let hours = Math.floor(minutes/ 60);
            minutes%=60;
            th = document.createElement("th") 
            th.appendChild( document.createTextNode(hours + ":" + minutes + ":" + seconds))
            appended_code.appendChild(th);
            
        }
        all_trains_table.appendChild(appended_code)
        
    }
}
}

async function main(){
    let all_trains = await rest_request("get_all_trains");
    let trains_in_queue = await rest_request("get_trains_in_queue")
    
    let trains_on_rail = await rest_request("get_trains_on_rail")
    console.log(all_trains)
    set_train_table(all_trains, "all_trains")    
    set_train_table(trains_in_queue, "trains_in_queue")
    set_train_table(trains_on_rail, "trains_on_rail")

}
main()
setInterval(main, 1000)