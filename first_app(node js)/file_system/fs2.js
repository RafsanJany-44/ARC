//using stream it si the best type of reading a file
var fs = require('fs');

var strm= fs.createReadStream('input2.txt');

var data='';
strm.setEncoding('UTF8');
strm.on('data',function(chunk){
    data+=chunk;
});

strm.on('end',function(){
    console.log(data);
});