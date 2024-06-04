/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef __mars_message_LaserScan_hpp__
#define __mars_message_LaserScan_hpp__

#include <lcm/lcm_coretypes.h>

#include <vector>

namespace mars_message
{

class LaserScan
{
    public:
        int64_t    timestampMs;

        float      angleMin;

        float      angleMax;

        float      angleIncrement;

        float      timeIncrement;

        float      scanTime;

        float      rangeMin;

        float      rangeMax;

        int32_t    count;

        std::vector< float > ranges;

        std::vector< float > intensities;

#ifdef __NLOHMANN_JSON_CPP
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(LaserScan, timestampMs, angleMin, angleMax, angleIncrement, timeIncrement, scanTime, rangeMin, rangeMax, count, ranges, intensities)
#endif
#ifdef __MSGPACK
    public:
        MSGPACK_DEFINE(LaserScan, timestampMs, angleMin, angleMax, angleIncrement, timeIncrement, scanTime, rangeMin, rangeMax, count, ranges, intensities)
#endif
    public:
        bool operator==(const LaserScan& other) const
        {
            return timestampMs == other.timestampMs && angleMin == other.angleMin && angleMax == other.angleMax && angleIncrement == other.angleIncrement && timeIncrement == other.timeIncrement && scanTime == other.scanTime && rangeMin == other.rangeMin && rangeMax == other.rangeMax && count == other.count && ranges == other.ranges && intensities == other.intensities;
        }
    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to read while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "LaserScan"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int LaserScan::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int LaserScan::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int LaserScan::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t LaserScan::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* LaserScan::getTypeName()
{
    return "LaserScan";
}

int LaserScan::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->timestampMs, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->angleMin, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->angleMax, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->angleIncrement, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->timeIncrement, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->scanTime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->rangeMin, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->rangeMax, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->count, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    if(this->count > 0) {
        tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->ranges[0], this->count);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    if(this->count > 0) {
        tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->intensities[0], this->count);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int LaserScan::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->timestampMs, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->angleMin, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->angleMax, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->angleIncrement, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->timeIncrement, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->scanTime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->rangeMin, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->rangeMax, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->count, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    if(this->count) {
        this->ranges.resize(this->count);
        tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->ranges[0], this->count);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    if(this->count) {
        this->intensities.resize(this->count);
        tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->intensities[0], this->count);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int LaserScan::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, this->count);
    enc_size += __float_encoded_array_size(NULL, this->count);
    return enc_size;
}

uint64_t LaserScan::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x5b820cc0794077cfLL;
    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
