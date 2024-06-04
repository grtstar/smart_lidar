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

import mars_message.Vector3

import mars_message.Quaternion

class Pose(object):
    __slots__ = ["pose", "orientation"]

    __typenames__ = ["mars_message.Vector3", "mars_message.Quaternion"]

    __dimensions__ = [None, None]

    def __init__(self):
        self.pose = mars_message.Vector3()
        self.orientation = mars_message.Quaternion()

    def encode(self):
        buf = BytesIO()
        buf.write(Pose._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        assert self.pose._get_packed_fingerprint() == mars_message.Vector3._get_packed_fingerprint()
        self.pose._encode_one(buf)
        assert self.orientation._get_packed_fingerprint() == mars_message.Quaternion._get_packed_fingerprint()
        self.orientation._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Pose._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Pose._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Pose()
        self.pose = mars_message.Vector3._decode_one(buf)
        self.orientation = mars_message.Quaternion._decode_one(buf)
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Pose in parents: return 0
        newparents = parents + [Pose]
        tmphash = (0x55798f1bab660288+ mars_message.Vector3._get_hash_recursive(newparents)+ mars_message.Quaternion._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Pose._packed_fingerprint is None:
            Pose._packed_fingerprint = struct.pack(">Q", Pose._get_hash_recursive([]))
        return Pose._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Pose._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.pose.from_dict(j["pose"])
        self.orientation.from_dict(j["orientation"])

    def to_dict(self):
        j = {}
        j["pose"] = self.pose.to_dict()
        j["orientation"] = self.orientation.to_dict()
        return j

