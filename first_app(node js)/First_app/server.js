var http = require('http');
var url=require('url');
 
function start(route,handle){
function fun(request,response){
    var reviewData = "";
    var pathname = url.parse(request.url).pathname;
    console.log("Request Received.........." +pathname);

    request.setEncoding("utf8");
    request.addListener("data", function(chunk) {
        reviewData += chunk;
    });

    request.addListener("end",function() {
        route(handle,pathname,response,reviewData);
    });
}


http.createServer(fun).listen(8888);


 console.log("Server started on loval host.....this line is being  shown in console.");
}

exports.start=start;