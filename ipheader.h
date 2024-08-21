#ifndef IP_HEADER_H
#define IP_HEADER_H

#include <cstdint>
#include <arpa/inet.h>
#include <iostream>

#pragma pack(push, 1)

// IPv4 헤더 구조체
struct Ip4Header {
    uint8_t  ihl:4, version:4;   // IP header length and version
    uint8_t  tos;                // Type of service
    uint16_t tot_len;            // Total length
    uint16_t id;                 // Identification
    uint16_t frag_off;           // Fragment offset field
    uint8_t  ttl;                // Time to live
    uint8_t  protocol;           // Protocol (TCP, UDP, etc.)
    uint16_t check;              // Checksum
    uint32_t saddr;              // Source address
    uint32_t daddr;              // Destination address
};

// IPv6 헤더 구조체
struct Ip6Header {
    uint32_t version:4, traffic_class:8, flow_label:20; // Version, Traffic class, Flow label
    uint16_t payload_len;        // Payload length
    uint8_t  next_header;        // Next header (protocol)
    uint8_t  hop_limit;          // Hop limit (similar to TTL)
    uint8_t  saddr[16];          // Source address (128-bit)
    uint8_t  daddr[16];          // Destination address (128-bit)
};

// 공통 IP 헤더 구조체
struct IpHeader {
    union {
        Ip4Header ip4;
        Ip6Header ip6;
    };
    uint8_t version() const { return (ip4.version == 4) ? 4 : (ip6.version == 6) ? 6 : 0; }
};

#pragma pack(pop)

#endif // IP_HEADER_H
