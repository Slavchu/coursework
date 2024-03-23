
/*async function simple_get_request(){
    let response = await fetch("/RAILWAY_REQUEST/get_railway_state",
      {method :"GET"})
    if(response.ok){
        console.log = response.json()
}
}
*/
let field = document.getElementsByClassName("RailwayField")

var canvas = document.querySelector('canvas')

canvas.width = window.innerWidth
canvas.height = window.innerHeight
var c = canvas.getContext('2d')
console.log(canvas.width, " ", canvas.height)

