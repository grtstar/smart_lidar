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

class Vector3(object):
    __slots__ = ["x", "y", "z"]

    __typenames__ = ["double", "double", "double"]

    __dimensions__ = [None, None, None]

    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0

    def encode(self):
        buf = BytesIO()
        buf.write(Vector3._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">ddd", self.x, self.y, self.z))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Vector3._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Vector3._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Vector3()
        self.x, self.y, self.z = struct.unpack(">ddd", buf.read(24))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Vector3 in parents: return 0
        tmphash = (0x573f2fdd2f76508f) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Vector3._packed_fingerprint is None:
            Vector3._packed_fingerprint = struct.pack(">Q", Vector3._get_hash_recursive([]))
        return Vector3._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Vector3._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.x = j["x"]
        self.y = j["y"]
        self.z = j["z"]

    def to_dict(self):
        j = {}
        j["x"] = self.x
        j["y"] = self.y
        j["z"] = self.z
        return j

