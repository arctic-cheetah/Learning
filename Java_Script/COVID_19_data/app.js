//Make a webserver to send data to twilio
const http = require("http");
//Use local host
const host = "127.0.0.1";
//Port 3000 is vacant
const port = 3000;


//Initialise the server
const server = http.createServer((req, res) => {

    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain");
    res.end("Toysky!\n");
});

server.listen(port, host, () => {
    console.log("Server initialised!");
});
