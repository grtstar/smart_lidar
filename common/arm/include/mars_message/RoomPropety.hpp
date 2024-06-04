/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef __mars_message_RoomPropety_hpp__
#define __mars_message_RoomPropety_hpp__

#include <lcm/lcm_coretypes.h>

#include <string>
#include "mars_message/MapRect.hpp"

namespace mars_message
{

class RoomPropety
{
    public:
        int32_t    roomNo;

        mars_message::MapRect roomArea;

        std::string roomName;

        int32_t    cleanOrder;

        int32_t    cleanRepeat;

        int32_t    mopRepeat;

        int32_t    colorOrder;

        int32_t    donotSweep;

        int32_t    donotMop;

        int32_t    fanPower;

        int32_t    waterLevel;

        int32_t    enableYMop;

#ifdef __NLOHMANN_JSON_CPP
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(RoomPropety, roomNo, roomArea, roomName, cleanOrder, cleanRepeat, mopRepeat, colorOrder, donotSweep, donotMop, fanPower, waterLevel, enableYMop)
#endif
    public:
        bool operator==(const RoomPropety& other) const
        {
            return roomNo == other.roomNo && roomArea == other.roomArea && roomName == other.roomName && cleanOrder == other.cleanOrder && cleanRepeat == other.cleanRepeat && mopRepeat == other.mopRepeat && colorOrder == other.colorOrder && donotSweep == other.donotSweep && donotMop == other.donotMop && fanPower == other.fanPower && waterLevel == other.waterLevel && enableYMop == other.enableYMop;
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
         * Returns "RoomPropety"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int RoomPropety::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int RoomPropety::decode(const void *buf, int offset, int maxlen)
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

int RoomPropety::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t RoomPropety::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* RoomPropety::getTypeName()
{
    return "RoomPropety";
}

int RoomPropety::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->roomNo, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->roomArea._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    char* roomName_cstr = const_cast<char*>(this->roomName.c_str());
    tlen = __string_encode_array(
        buf, offset + pos, maxlen - pos, &roomName_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->cleanOrder, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->cleanRepeat, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->mopRepeat, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->colorOrder, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->donotSweep, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->donotMop, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->fanPower, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->waterLevel, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->enableYMop, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int RoomPropety::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->roomNo, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->roomArea._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    int32_t __roomName_len__;
    tlen = __int32_t_decode_array(
        buf, offset + pos, maxlen - pos, &__roomName_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__roomName_len__ > maxlen - pos) return -1;
    this->roomName.assign(
        static_cast<const char*>(buf) + offset + pos, __roomName_len__ - 1);
    pos += __roomName_len__;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->cleanOrder, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->cleanRepeat, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->mopRepeat, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->colorOrder, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->donotSweep, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->donotMop, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->fanPower, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->waterLevel, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->enableYMop, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int RoomPropety::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += this->roomArea._getEncodedSizeNoHash();
    enc_size += this->roomName.size() + 4 + 1;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    return enc_size;
}

uint64_t RoomPropety::_computeHash(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for(fp = p; fp != NULL; fp = fp->parent)
        if(fp->v == RoomPropety::getHash)
            return 0;
    const __lcm_hash_ptr cp = { p, RoomPropety::getHash };

    uint64_t hash = 0x5061726d461d805bLL +
         mars_message::MapRect::_computeHash(&cp);

    return (hash<<1) + ((hash>>63)&1);
}

}

#endif