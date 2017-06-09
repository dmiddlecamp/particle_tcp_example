
SYSTEM_THREAD(ENABLED);
TCPClient client;

#define SERVER_ADDRESS "192.168.1.100"
#define SERVER_TCP_PORT 5550

#define VERSION_NUMBER 1

#define TX_BUFFER_MAX 1024
uint8_t tx_buffer[TX_BUFFER_MAX + 1];
int tx_buffer_index = 0;



void setup()
{
    Particle.publish("status", "Good morning, Version: " + String(VERSION_NUMBER));
    delay(1000);

    client.connect(SERVER_ADDRESS, SERVER_TCP_PORT);
}



void loop()
{
    if (!client.connected()) {
        //client.stop();
        Particle.publish("status", "Attempting to reconnect to TCP Server...");
        if (!client.connect(SERVER_ADDRESS, SERVER_TCP_PORT)) {
            delay(1000);
            return;
        }
    }

    int size = random(TX_BUFFER_MAX);
    for(int i=0;i<size;i++) {
        tx_buffer[i] = random(255);
    }
    sendBuffer(&tx_buffer, size);

    delay(100);
}


int sendBuffer(uint8_t *buffer, int size) {
    if (!client.connected()) {
        return -1;
    }

    // send the chunk length prefix

    uint8_t high = (uint8_t)(size >> 8);
    uint8_t low = (uint8_t)(size & 0xFF);

    uint8_t prefix[2];
    prefix[0] = high;
    prefix[1] = low;

    client.write(prefix, 2);
    return client.write(buffer, size);
}