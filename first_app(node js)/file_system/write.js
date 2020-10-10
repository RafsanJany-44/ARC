var fs = require('fs');

var writeData="lets try new what is going on";
var writeableStream = fs.createWriteStream('output2.txt');
writeableStream.write(writeData,'UTF8');
writeableStream.end();
writeableStream.on('finish',function(){
    console.log("write complite");
});