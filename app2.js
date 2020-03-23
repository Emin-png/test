var express=require('express');
var app=express();
app.get('/',function(req,res){
    res.send("This is home");
});
app.get('/news',function(req,res){
    res.send("This is news");
});
app.listen(3000);