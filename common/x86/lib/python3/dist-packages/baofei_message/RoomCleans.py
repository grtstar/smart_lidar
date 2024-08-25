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

import baofei_message.RoomClean

class RoomCleans(object):
    __slots__ = ["count", "room"]

    __typenames__ = ["int8_t", "baofei_message.RoomClean"]

    __dimensions__ = [None, ["count"]]

    def __init__(self):
        self.count = 0
        self.room = []

    def encode(self):
        buf = BytesIO()
        buf.write(RoomCleans._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">b", self.count))
        for i0 in range(self.count):
            assert self.room[i0]._get_packed_fingerprint() == baofei_message.RoomClean._get_packed_fingerprint()
            self.room[i0]._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != RoomCleans._get_packed_fingerprint():
            raise ValueError("Decode error")
        return RoomCleans._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = RoomCleans()
        self.count = struct.unpack(">b", buf.read(1))[0]
        self.room = []
        for i0 in range(self.count):
            self.room.append(baofei_message.RoomClean._decode_one(buf))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if RoomCleans in parents: return 0
        newparents = parents + [RoomCleans]
        tmphash = (0x6a317762ef4f3a3c+ baofei_message.RoomClean._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if RoomCleans._packed_fingerprint is None:
            RoomCleans._packed_fingerprint = struct.pack(">Q", RoomCleans._get_hash_recursive([]))
        return RoomCleans._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", RoomCleans._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.count = j["count"]
        self.room = [x.from_dict() for x in j["room"]]

    def to_dict(self):
        j = {}
        j["count"] = self.count
        j["room"] = [x.to_dict() for x in self.room]
        return j
