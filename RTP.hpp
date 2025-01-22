/*
    0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |V=2|P|X|  CC   |M|     PT      |       sequence number         |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                           timestamp                           |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |           synchronization source (SSRC) identifier            |
    +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
    |            contributing source (CSRC) identifiers             |
    |                             ....                              |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

*/

#pragma once
#include <cstdint>
#include <cstring>
#include <iostream>

// MASKS DEFINE
const uint8_t VERSION_MASK = 0x3;
const uint8_t PADDING_MASK = 0x1;
const uint8_t EXTENSION_MASK = 0x1;
const uint8_t CC_MASK = 0xF;
const uint8_t MARKER_MASK = 0x1;
const uint16_t PT_MASK = 0x7F;
const uint16_t SEQUENCE_MASK = 0xFFFF;

//SHIFTING DEFINES

struct test_struct {
  int i;
  int j;
}typedef ts;


class RtpHeader {
private :
    uint16_t set; 
    uint16_t sequence_number;
    unsigned int time_stamp;
    unsigned int ssrc_identifier;
    unsigned int csrc_list[15];
public : 
    static const int buffer_len = sizeof(ts);
    RtpHeader(uint8_t version, bool padding,uint8_t cc, bool x, bool m, uint8_t pt, uint16_t sequence);
    void set_timestamp(unsigned int );
    void set_ssrc_identifier(unsigned int);
    void printInfo();
};

