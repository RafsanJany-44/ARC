var ev = require('events');
var evEmitter = new ev.EventEmitter();

var ringbell=function(){
    console.log("ring ring ring");
}

evEmitter.on("Rafsan",ringbell);    // the first peramater is the name of event, 2nd is is the function  
evEmitter.on("jany",function(massage){
    console.log(massage);
});

evEmitter.emit("Rafsan");
evEmitter.emit("jany","Welcome");// the passing value 

var fun=function(m){
    console.log(" this is the extra= " +m);
}

evEmitter.on("event_name",fun)
evEmitter.emit("event_name","this the massage");
