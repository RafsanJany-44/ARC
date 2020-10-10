console.log("----------");
console.log(__filename);
console.log(__dirname);

function say(){
console.log("this line will be printed after 5 sec");

}

//setTimeout(say,5000);// pause the prograam for 5 sec

setInterval(say,2000);// the function will be called for each 2 second
