var http=require('http');

http.createServer(function(request,response){

    response.writeHead(200,{"Content-Type":"text/plain"});
    response.write("Hello World");
    response.write("<br>");
    response.write("I can write this inside the web");
    response.end();


}
).listen(8888);