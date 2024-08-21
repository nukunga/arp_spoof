#ifndef TCP_HEADER_H
#define TCP_HEADER_H

#include <cstdint>
#include <arpa/inet.h>
#include <iostream>

#pragma pack(push, 1)
struct TcpHeader {
    uint16_t source;        // Source port
    uint16_t dest;          // Destination port
    uint32_t seq;           // Sequence number
    uint32_t ack_seq;       // Acknowledgment number
    uint8_t  doff:4;        // Data offset (header length)
    uint8_t  res1:4;        // Reserved
    uint8_t  flags;         // TCP flags (CWR, ECE, URG, ACK, PSH, RST, SYN, FIN)
    uint16_t window;        // Window size
    uint16_t check;         // Checksum
    uint16_t urg_ptr;       // Urgent pointer
};
#pragma pack(pop)

#endif // TCP_HEADER_H
