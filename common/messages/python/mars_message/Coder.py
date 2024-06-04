"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class Coder(object):
    __slots__ = ["coderL", "coderR", "coderLPerSec", "coderRPerSec"]

    __typenames__ = ["int32_t", "int32_t", "int16_t", "int16_t"]

    __dimensions__ = [None, None, None, None]

    def __init__(self):
        self.coderL = 0
        self.coderR = 0
        self.coderLPerSec = 0
        self.coderRPerSec = 0

    def encode(self):
        buf = BytesIO()
        buf.write(Coder._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">iihh", self.coderL, self.coderR, self.coderLPerSec, self.coderRPerSec))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Coder._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Coder._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Coder()
        self.coderL, self.coderR, self.coderLPerSec, self.coderRPerSec = struct.unpack(">iihh", buf.read(12))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Coder in parents: return 0
        tmphash = (0x79d94d4670e55dcd) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Coder._packed_fingerprint is None:
            Coder._packed_fingerprint = struct.pack(">Q", Coder._get_hash_recursive([]))
        return Coder._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Coder._get_packed_fingerprint())[0]
