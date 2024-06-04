"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct
import json

class MacAddrCode(object):
    __slots__ = ["timestampMs", "code0", "code1", "code2", "code3", "code4", "code5"]

    __typenames__ = ["int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t"]

    __dimensions__ = [None, None, None, None, None, None, None]

    def __init__(self):
        self.timestampMs = 0
        self.code0 = 0
        self.code1 = 0
        self.code2 = 0
        self.code3 = 0
        self.code4 = 0
        self.code5 = 0

    def encode(self):
        buf = BytesIO()
        buf.write(MacAddrCode._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">iiiiiii", self.timestampMs, self.code0, self.code1, self.code2, self.code3, self.code4, self.code5))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != MacAddrCode._get_packed_fingerprint():
            raise ValueError("Decode error")
        return MacAddrCode._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = MacAddrCode()
        self.timestampMs, self.code0, self.code1, self.code2, self.code3, self.code4, self.code5 = struct.unpack(">iiiiiii", buf.read(28))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if MacAddrCode in parents: return 0
        tmphash = (0xa4968b58f18d8cc6) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if MacAddrCode._packed_fingerprint is None:
            MacAddrCode._packed_fingerprint = struct.pack(">Q", MacAddrCode._get_hash_recursive([]))
        return MacAddrCode._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", MacAddrCode._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.timestampMs = j["timestampMs"]
        self.code0 = j["code0"]
        self.code1 = j["code1"]
        self.code2 = j["code2"]
        self.code3 = j["code3"]
        self.code4 = j["code4"]
        self.code5 = j["code5"]

    def to_dict(self):
        j = {}
        j["timestampMs"] = self.timestampMs
        j["code0"] = self.code0
        j["code1"] = self.code1
        j["code2"] = self.code2
        j["code3"] = self.code3
        j["code4"] = self.code4
        j["code5"] = self.code5
        return j

