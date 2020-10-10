function avg(a,b,c){
    var c = (a+b+c)/3;
    console.log("this the avarage= "+c);
}

function mult(a,v){
    var c= a*v;
    console.log("this the multiplication= ",+c);
}

module.exports.avg=avg;
module.exports.mult=mult;
