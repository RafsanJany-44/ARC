//here the program will read from a file and write another file..
// the pipe will be used
var fs = require('fs');
var read_f= fs.createReadStream('read_file.txt');
var write_f=fs.createWriteStream('write_file.txt');
console.log("process starts");
console.log("----------------------------------");
read_f.pipe(write_f);
console.log("done");

