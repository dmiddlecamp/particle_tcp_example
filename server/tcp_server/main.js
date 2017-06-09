var fs = require('fs');
var net = require('net');
var ChunkingStream = require("./lib/ChunkingStream.js");

var settings = {
    ip: "127.0.0.1",
    port: 5550
};

var session_key = 0;
var sessions = {};

var onChunkedData = function(session) {
	var chunk = session.chunkingIn.read();

	// magic here!
	console.log("got chunk of size ", chunk.length);

}

var onConnect = function (socket) {

    console.log("Connection received ");	//TODO: from, ip?

	var session = {
		key: "_" + (session_key++),
		socket: socket
	};
	sessions[session.key] = session;

	session.chunkingIn = new ChunkingStream({outgoing: false });
	session.chunkingOut = new ChunkingStream({outgoing: true });
	session.socket.pipe(session.chunkingIn);

	session.chunkingIn.on('readable', onChunkedData.bind(this, session));
	session.chunkingOut.pipe(session.socket);

	// ready!
};


var server = net.createServer(onConnect);
server.listen(settings.port, function () {
	console.log('Listening for TCP packets on port ' + settings.port + ' ...');
});

