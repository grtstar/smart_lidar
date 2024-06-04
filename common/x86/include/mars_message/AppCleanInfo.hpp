/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef __mars_message_AppCleanInfo_hpp__
#define __mars_message_AppCleanInfo_hpp__

#include <lcm/lcm_coretypes.h>


namespace mars_message
{

class AppCleanInfo
{
    public:
        int32_t    cleanTimeSecond;

        float      cleanArea;

        int32_t    cleanTimeTotalSecond;

        float      cleanAreaTotal;

        int32_t    cleanCountTotal;

        float      esimateArea;

        float      carpetArea;

        int32_t    numberOfTasksCompleted;

        int32_t    sweepTimeTotalSecond;

        int32_t    washTimeTotalSecond;

#ifdef __NLOHMANN_JSON_CPP
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AppCleanInfo, cleanTimeSecond, cleanArea, cleanTimeTotalSecond, cleanAreaTotal, cleanCountTotal, esimateArea, carpetArea, numberOfTasksCompleted, sweepTimeTotalSecond, washTimeTotalSecond)
#endif
#ifdef __MSGPACK
    public:
        MSGPACK_DEFINE(AppCleanInfo, cleanTimeSecond, cleanArea, cleanTimeTotalSecond, cleanAreaTotal, cleanCountTotal, esimateArea, carpetArea, numberOfTasksCompleted, sweepTimeTotalSecond, washTimeTotalSecond)
#endif
    public:
        bool operator==(const AppCleanInfo& other) const
        {
            return cleanTimeSecond == other.cleanTimeSecond && cleanArea == other.cleanArea && cleanTimeTotalSecond == other.cleanTimeTotalSecond && cleanAreaTotal == other.cleanAreaTotal && cleanCountTotal == other.cleanCountTotal && esimateArea == other.esimateArea && carpetArea == other.carpetArea && numberOfTasksCompleted == other.numberOfTasksCompleted && sweepTimeTotalSecond == other.sweepTimeTotalSecond && washTimeTotalSecond == other.washTimeTotalSecond;
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
         * Returns "AppCleanInfo"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int AppCleanInfo::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int AppCleanInfo::decode(const void *buf, int offset, int maxlen)
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

int AppCleanInfo::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t AppCleanInfo::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* AppCleanInfo::getTypeName()
{
    return "AppCleanInfo";
}

int AppCleanInfo::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->cleanTimeSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->cleanArea, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->cleanTimeTotalSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->cleanAreaTotal, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->cleanCountTotal, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->esimateArea, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_encode_array(buf, offset + pos, maxlen - pos, &this->carpetArea, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->numberOfTasksCompleted, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->sweepTimeTotalSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->washTimeTotalSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int AppCleanInfo::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->cleanTimeSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->cleanArea, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->cleanTimeTotalSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->cleanAreaTotal, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->cleanCountTotal, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->esimateArea, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __float_decode_array(buf, offset + pos, maxlen - pos, &this->carpetArea, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->numberOfTasksCompleted, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->sweepTimeTotalSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->washTimeTotalSecond, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int AppCleanInfo::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __float_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    return enc_size;
}

uint64_t AppCleanInfo::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x5b806652b6850371LL;
    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
