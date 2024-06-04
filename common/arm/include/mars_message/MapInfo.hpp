/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef __mars_message_MapInfo_hpp__
#define __mars_message_MapInfo_hpp__

#include <lcm/lcm_coretypes.h>

#include <string>

namespace mars_message
{

class MapInfo
{
    public:
        int32_t    createTime;

        int32_t    mapSign;

        int32_t    editTime;

        std::string name;

        int8_t     isFormalMap;

        int8_t     isSaveToFlash;

#ifdef __NLOHMANN_JSON_CPP
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MapInfo, createTime, mapSign, editTime, name, isFormalMap, isSaveToFlash)
#endif
#ifdef __MSGPACK
    public:
        MSGPACK_DEFINE(MapInfo, createTime, mapSign, editTime, name, isFormalMap, isSaveToFlash)
#endif
    public:
        bool operator==(const MapInfo& other) const
        {
            return createTime == other.createTime && mapSign == other.mapSign && editTime == other.editTime && name == other.name && isFormalMap == other.isFormalMap && isSaveToFlash == other.isSaveToFlash;
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
         * Returns "MapInfo"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int MapInfo::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int MapInfo::decode(const void *buf, int offset, int maxlen)
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

int MapInfo::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t MapInfo::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* MapInfo::getTypeName()
{
    return "MapInfo";
}

int MapInfo::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->createTime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->mapSign, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->editTime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* name_cstr = const_cast<char*>(this->name.c_str());
    tlen = __string_encode_array(
        buf, offset + pos, maxlen - pos, &name_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &this->isFormalMap, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &this->isSaveToFlash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int MapInfo::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->createTime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->mapSign, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->editTime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    int32_t __name_len__;
    tlen = __int32_t_decode_array(
        buf, offset + pos, maxlen - pos, &__name_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__name_len__ > maxlen - pos) return -1;
    this->name.assign(
        static_cast<const char*>(buf) + offset + pos, __name_len__ - 1);
    pos += __name_len__;

    tlen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &this->isFormalMap, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &this->isSaveToFlash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int MapInfo::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += this->name.size() + 4 + 1;
    enc_size += __int8_t_encoded_array_size(NULL, 1);
    enc_size += __int8_t_encoded_array_size(NULL, 1);
    return enc_size;
}

uint64_t MapInfo::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0xb62a0f0823cf5107LL;
    return (hash<<1) + ((hash>>63)&1);
}

}

#endif