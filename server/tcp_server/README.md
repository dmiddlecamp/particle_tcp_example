Simple Node.js Server for Reciving Data
---

This program listens on port 5550 for connections from your device running the "tcp_client" code in the 
firmware folder.  If you want to use this in production, this server would benefit from encryption, 
and some header metadata (message type, device id, etc).

How to setup
---

Make sure you have Node.js installed, and install the dependencies in this folder:

```
 cd services/tcp_server
 npm install
 #...
 node main.js
 
 #success!
```

How to run
---

Just run `node main.js`, and as you receive data, it'll log out the length of the messages in the console.  Open up 
main.js and look for "magic here!" for where the action happens.


Bugs / Issues?
---

Please feel free to open issues on this repo if you find bugs:

https://github.com/dmiddlecamp/particle_tcp_example/issues

Thanks!
