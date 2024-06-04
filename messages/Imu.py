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

import mars_message.Quaternion

class Imu(object):
    __slots__ = ["timestampMs", "orientation", "orientationCovariance", "angularVelocity", "angularVelocityCovariance", "linearAcceleraion", "linearAcceleraionCovariance"]

    __typenames__ = ["int64_t", "mars_message.Quaternion", "double", "mars_message.Vector3", "double", "mars_message.Vector3", "double"]

    __dimensions__ = [None, None, [9], None, [9], None, [9]]

    def __init__(self):
        self.timestampMs = 0
        self.orientation = mars_message.Quaternion()
        self.orientationCovariance = [ 0.0 for dim0 in range(9) ]
        self.angularVelocity = mars_message.Vector3()
        self.angularVelocityCovariance = [ 0.0 for dim0 in range(9) ]
        self.linearAcceleraion = mars_message.Vector3()
        self.linearAcceleraionCovariance = [ 0.0 for dim0 in range(9) ]

    def encode(self):
        buf = BytesIO()
        buf.write(Imu._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">q", self.timestampMs))
        assert self.orientation._get_packed_fingerprint() == mars_message.Quaternion._get_packed_fingerprint()
        self.orientation._encode_one(buf)
        buf.write(struct.pack('>9d', *self.orientationCovariance[:9]))
        assert self.angularVelocity._get_packed_fingerprint() == mars_message.Vector3._get_packed_fingerprint()
        self.angularVelocity._encode_one(buf)
        buf.write(struct.pack('>9d', *self.angularVelocityCovariance[:9]))
        assert self.linearAcceleraion._get_packed_fingerprint() == mars_message.Vector3._get_packed_fingerprint()
        self.linearAcceleraion._encode_one(buf)
        buf.write(struct.pack('>9d', *self.linearAcceleraionCovariance[:9]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Imu._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Imu._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Imu()
        self.timestampMs = struct.unpack(">q", buf.read(8))[0]
        self.orientation = mars_message.Quaternion._decode_one(buf)
        self.orientationCovariance = struct.unpack('>9d', buf.read(72))
        self.angularVelocity = mars_message.Vector3._decode_one(buf)
        self.angularVelocityCovariance = struct.unpack('>9d', buf.read(72))
        self.linearAcceleraion = mars_message.Vector3._decode_one(buf)
        self.linearAcceleraionCovariance = struct.unpack('>9d', buf.read(72))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Imu in parents: return 0
        newparents = parents + [Imu]
        tmphash = (0xbfe728daf8400e28+ mars_message.Quaternion._get_hash_recursive(newparents)+ mars_message.Vector3._get_hash_recursive(newparents)+ mars_message.Vector3._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Imu._packed_fingerprint is None:
            Imu._packed_fingerprint = struct.pack(">Q", Imu._get_hash_recursive([]))
        return Imu._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Imu._get_packed_fingerprint())[0]

