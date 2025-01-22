
#include "RTP.hpp"


RtpHeader::RtpHeader(uint8_t version, bool padding,uint8_t cc, bool x, bool m, uint8_t pt, uint16_t sequence){
    uint8_t first_byte;
    first_byte = (cc & CC_MASK);
    first_byte |= (x & EXTENSION_MASK) << 4;
    first_byte |= (padding & PADDING_MASK) << 5;
    first_byte |= (version & VERSION_MASK) << 6;
    uint8_t second_byte;
    second_byte = (pt & PT_MASK);
    second_byte |= (m & MARKER_MASK) << 7;

    this->set = second_byte;
    this->set |= first_byte << 8;

    this->sequence_number = sequence_number;
}

void RtpHeader::set_timestamp(unsigned int timestamp){
    this->time_stamp = (timestamp);
    return;
}

void RtpHeader::set_ssrc_identifier(unsigned int ssrc_id){
    this->ssrc_identifier = ssrc_id;
    return;
}

void RtpHeader::printInfo()
{
    uint8_t first_byte = static_cast<uint8_t>( (set >> 8) & 0xFF );
    uint8_t second_byte = static_cast<uint8_t>( set & 0xFF );

    uint8_t version   = (first_byte >> 6) & VERSION_MASK;
    bool    padding   = ((first_byte >> 5) & PADDING_MASK) == 1;
    bool    extension = ((first_byte >> 4) & EXTENSION_MASK) == 1;
    uint8_t cc        = first_byte & CC_MASK;

    bool    marker      = ((second_byte >> 7) & MARKER_MASK) == 1;
    uint8_t payloadType = second_byte & PT_MASK;

    std::cout << "RtpHeader Info:\n"
            << "  Version:          " << static_cast<int>(version)       << "\n"
            << "  Padding:          " << padding                         << "\n"
            << "  Extension:        " << extension                       << "\n"
            << "  CC:               " << static_cast<int>(cc)            << "\n"
            << "  Marker:           " << marker                          << "\n"
            << "  Payload Type:     " << static_cast<int>(payloadType)    << "\n"
            << "  Sequence Number:  " << this->sequence_number                  << "\n"
            << "  Timestamp:        " << this->time_stamp                      << "\n"
            << "  SSRC:             " << this->ssrc_identifier                 << "\n";

}