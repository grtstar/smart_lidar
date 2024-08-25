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

import baofei_message.RectArea

class RectAreas(object):
    __slots__ = ["count", "area"]

    __typenames__ = ["int8_t", "baofei_message.RectArea"]

    __dimensions__ = [None, ["count"]]

    def __init__(self):
        self.count = 0
        self.area = []

    def encode(self):
        buf = BytesIO()
        buf.write(RectAreas._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">b", self.count))
        for i0 in range(self.count):
            assert self.area[i0]._get_packed_fingerprint() == baofei_message.RectArea._get_packed_fingerprint()
            self.area[i0]._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != RectAreas._get_packed_fingerprint():
            raise ValueError("Decode error")
        return RectAreas._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = RectAreas()
        self.count = struct.unpack(">b", buf.read(1))[0]
        self.area = []
        for i0 in range(self.count):
            self.area.append(baofei_message.RectArea._decode_one(buf))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if RectAreas in parents: return 0
        newparents = parents + [RectAreas]
        tmphash = (0x6a317762cd552654+ baofei_message.RectArea._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if RectAreas._packed_fingerprint is None:
            RectAreas._packed_fingerprint = struct.pack(">Q", RectAreas._get_hash_recursive([]))
        return RectAreas._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", RectAreas._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.count = j["count"]
        self.area = [x.from_dict() for x in j["area"]]

    def to_dict(self):
        j = {}
        j["count"] = self.count
        j["area"] = [x.to_dict() for x in self.area]
        return j
