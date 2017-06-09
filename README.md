# particle_tcp_example

This code sample demonstrates sending data in bulk over TCP to a dedicated server.


# what do I do?

Clone the repository onto your computer / server.  Make sure you have Node.js installed, 
and run the server using node with something like:
 
    cd /server/tcp_server
    node main.js

Make sure you open up "main.ino", and change the server IP address to match the IP or domain name of your server:

    // change me!
    #define SERVER_ADDRESS "192.168.1.100"
    

Build the firmware and flash it to your device using the particle-cli, something like this:

    particle compile electron . --saveTo firmware.bin
    
    # put your device in DFU mode 
    particle flash --usb firmware.bin
    

# What this demo doesn't show

This demo is meant to be a quick primer, and doesn't demonstrate receiving messages on the device, 
or encryption and authentication for the device and data.  That's an exercise left for the reader for now, 
or something that can come in future versions.

Thanks!
