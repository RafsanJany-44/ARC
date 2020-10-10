function say(name,name2){
    console.log("-------------------------");
    console.log("hello= "+name);
    console.log("hi ki khobor");
    console.log("hi hi hi hi hi hi= "+name2);
    console.log("-------------------------")
}

function add(a,b){
    console.log("The addtion= "+(a+b));
}

var mult=function(a,b){             // the anynomouse function
    console.log("The multiplication= "+(a*b));
}

say("rafsan");
add(9,10);

function main(say_fun, value1,value2 ){ // calling funtion in another function
    say_fun(value1,value2);
}

main(say,"this is first line","this is the second line.");
main(add,20,30);
main(mult,4,2);








