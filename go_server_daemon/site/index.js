async function rest_request( request) {
    response = await fetch("/rest/" + request, { mode: "no-cors" })
    return response.json();
}


let rail_width = 5
let field = document.getElementsByClassName("RailwayField")
let rail_positions;


let canvas = document.querySelector('canvas')

canvas.width = window.innerWidth
canvas.height = window.innerHeight
let c = canvas.getContext('2d')
console.log(canvas.width, " ", canvas.height)

async function main() {
    
    let railway_state = await rest_request("get_railway_state")
    console.log(railway_state)
    let rail_num = railway_state["rail_num"]
    console.log(rail_num)
    update_canvas( rail_num, railway_state["trains"]);
        

}
main()
setInterval(main, 1000)





function update_canvas(rail_num, trains){
    
    console.log("update_canvas")
    c.clearRect(0, 0, canvas.width, canvas.height);
    rail_positions = render_rails(rail_num, rail_width)
    for(integer = 0; integer < rail_num; integer++){
        if(trains[integer]["id"] > 0)
        
            render_train(trains[integer]["name"], trains[integer]["id"], trains[integer]["wagons"], integer);
        //console.log(integer);
    }

}

function render_train(name, id, wagons, rail){
    render_nose(rail,rail_width*10 )
    render_wagons( rail, wagons, canvas.width-rail_width*10*3, rail_width*10);
    c.font = "16px Raleway sans-serif"
    c.fillStyle = 'black'
    c.fillText(name, canvas.width+5-rail_width*10*3,rail_positions[rail], rail_width*10*2-5 )
    c.fillText("id:" + id, canvas.width+5-rail_width*10*3,rail_positions[rail]+16, rail_width*10*2-5 )
    c.fillText("wagons:" + wagons, canvas.width+5-rail_width*10*5-10,rail_positions[rail], rail_width*10*2-5 )
}

function render_wagons(rail, num, start_position, size){
    let overloaded = false;
    let overloaded_num  = 0;
    let y = rail_positions[rail]-size/2 + rail_width/2 ;
    let x=start_position-10-size*2
    if((size*2+10) *num > canvas.width){
        overloaded_num = num
        num = Math.floor(start_position/(size*2+10));
        overloaded=true;
        
    }
    for(i = 0; i < num; i++){
        c.fillStyle = 'rgb(204, 255, 204)';
        c.fillRect(x, y, size*2, size)
        x-=10+size*2
    }
    
    
    

}
function render_nose(rail, size){
    c.fillStyle = 'rgb(204, 255, 204)';
    y = rail_positions[rail]-size/2 + rail_width/2 ;
    x = canvas.width-(size*3);
    c.fillRect(x,y, size*2, size);
    c.beginPath();
    c.arc(x+size*2, y+size/2, size/2, -Math.PI/2, Math.PI/2);
    c.fill();
    c.beginPath();
    c.fillStyle = '#00CCCC';
    c.arc(x+size*2, y+size/2, size/3, -Math.PI/2, Math.PI/2);
    c.fill();
    
}

function render_rails(rail_num, rail_width){
    let rail_positions = new Array;
    c.fillStyle = 'white'
    for(i = 1; i < rail_num+1; i++){
        c.fillRect(0,i*canvas.height/(rail_num+1),canvas.width, rail_width);
        rail_positions.push(i*canvas.height/(rail_num+1));
    }
    return rail_positions;
}



