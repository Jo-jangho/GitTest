/**
 * Created by KICT-15 on 2016-07-15.
 */
const http = require('http');

const sever = http.createServer(function (req, res)
{
  res.statusCode = 200;
  res.setHeader("Content-Type", "text/html");
  res.end("<h1> hello world Jo-jangho </h1>");
});

sever.listen(8081, function()
{
    console.log("http sever start");
});