var fs = require('fs');

fs.readFile("input.txt",function(err,data){

    if (err){
        console.log(err);
    }
    else{
        console.log("Async daa is =" + data.toString());
    }

});


var data = fs.readFileSync("input.txt");
console.log('Sync data is =' + data.toString());
console.log("This is the end..");


// read files using stream 

var strm = fs.createReadStream("input2.txt");
var data="";
strm.setEncoding("UTF8");
strm.on("data",function(chunk){
    data += chunk;
});

strm.on("end",function(){
    console.log(data);
});