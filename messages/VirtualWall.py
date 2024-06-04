"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

import mars_message.Segment

class VirtualWall(object):
    __slots__ = ["count", "wall"]

    __typenames__ = ["int8_t", "mars_message.Segment"]

    __dimensions__ = [None, ["count"]]

    def __init__(self):
        self.count = 0
        self.wall = []

    def encode(self):
        buf = BytesIO()
        buf.write(VirtualWall._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">b", self.count))
        for i0 in range(self.count):
            assert self.wall[i0]._get_packed_fingerprint() == mars_message.Segment._get_packed_fingerprint()
            self.wall[i0]._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != VirtualWall._get_packed_fingerprint():
            raise ValueError("Decode error")
        return VirtualWall._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = VirtualWall()
        self.count = struct.unpack(">b", buf.read(1))[0]
        self.wall = []
        for i0 in range(self.count):
            self.wall.append(mars_message.Segment._decode_one(buf))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if VirtualWall in parents: return 0
        newparents = parents + [VirtualWall]
        tmphash = (0x6a317762f933343e+ mars_message.Segment._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if VirtualWall._packed_fingerprint is None:
            VirtualWall._packed_fingerprint = struct.pack(">Q", VirtualWall._get_hash_recursive([]))
        return VirtualWall._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", VirtualWall._get_packed_fingerprint())[0]

