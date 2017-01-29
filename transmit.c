#include "include/sound.c"
#define __BAUD_ID_PADDING__ 8

struct Wire {
    unsigned long baud;
    unsigned short baseFreq;
    unsigned short binSize;
    unsigned char binNum;
};

struct Packet {
  /*unsigned char baud[__BAUD_ID_PADDING__];*/
    unsigned long to;
    unsigned long from;
    unsigned short dataSize;
    unsigned char *data;
    unsigned char more;
};

void transmitData(struct Wire wire, struct Packet packet) {
    initPlay();
    for (int i = 0; i < __BAUD_ID_PADDING__; i++) {
        if ((i % 2) == 0) {
            playTone(wire.baseFreq, (double)(1 / wire.baud));
        } else {
            wait((double)(1 / wire.baud));
        }
    }
    char bitBufferSize;
    char bitBuffer;
    for i
