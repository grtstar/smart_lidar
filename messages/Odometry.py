"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

import mars_message.Vector3

import mars_message.Pose

class Odometry(object):
    __slots__ = ["timestampMs", "pose", "linearVelocity", "angularVelocity"]

    __typenames__ = ["int64_t", "mars_message.Pose", "mars_message.Vector3", "mars_message.Vector3"]

    __dimensions__ = [None, None, None, None]

    def __init__(self):
        self.timestampMs = 0
        self.pose = mars_message.Pose()
        self.linearVelocity = mars_message.Vector3()
        self.angularVelocity = mars_message.Vector3()

    def encode(self):
        buf = BytesIO()
        buf.write(Odometry._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">q", self.timestampMs))
        assert self.pose._get_packed_fingerprint() == mars_message.Pose._get_packed_fingerprint()
        self.pose._encode_one(buf)
        assert self.linearVelocity._get_packed_fingerprint() == mars_message.Vector3._get_packed_fingerprint()
        self.linearVelocity._encode_one(buf)
        assert self.angularVelocity._get_packed_fingerprint() == mars_message.Vector3._get_packed_fingerprint()
        self.angularVelocity._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Odometry._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Odometry._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Odometry()
        self.timestampMs = struct.unpack(">q", buf.read(8))[0]
        self.pose = mars_message.Pose._decode_one(buf)
        self.linearVelocity = mars_message.Vector3._decode_one(buf)
        self.angularVelocity = mars_message.Vector3._decode_one(buf)
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Odometry in parents: return 0
        newparents = parents + [Odometry]
        tmphash = (0xe4aab0d36821bf89+ mars_message.Pose._get_hash_recursive(newparents)+ mars_message.Vector3._get_hash_recursive(newparents)+ mars_message.Vector3._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Odometry._packed_fingerprint is None:
            Odometry._packed_fingerprint = struct.pack(">Q", Odometry._get_hash_recursive([]))
        return Odometry._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Odometry._get_packed_fingerprint())[0]

