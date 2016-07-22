const net = require('net');
const PORT = 8080;

net.createServer((socket) => {
    
    console.log('connect : ' + socket.remoteAddress + ':'
    + socket.remotePort);

    socket.on('error', (evt)=> {
        console.log(evt);
    });

    socket.on('close', (evt)=> {
        console.log('connection close!');
        console.log(evt);
    });

    socket.on('data', (evt)=> {
        let data = JSON.arse(evt);

        console.log(evt.toSource());
    });
}).listen(PORT);