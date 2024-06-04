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

class IrCode(object):
    __slots__ = ["timestampMs", "count", "code"]

    __typenames__ = ["int64_t", "int8_t", "int8_t"]

    __dimensions__ = [None, None, ["count"]]

    def __init__(self):
        self.timestampMs = 0
        self.count = 0
        self.code = []

    def encode(self):
        buf = BytesIO()
        buf.write(IrCode._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">qb", self.timestampMs, self.count))
        buf.write(struct.pack('>%db' % self.count, *self.code[:self.count]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != IrCode._get_packed_fingerprint():
            raise ValueError("Decode error")
        return IrCode._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = IrCode()
        self.timestampMs, self.count = struct.unpack(">qb", buf.read(9))
        self.code = struct.unpack('>%db' % self.count, buf.read(self.count))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if IrCode in parents: return 0
        tmphash = (0x21aca91f9434ae5a) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if IrCode._packed_fingerprint is None:
            IrCode._packed_fingerprint = struct.pack(">Q", IrCode._get_hash_recursive([]))
        return IrCode._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", IrCode._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.timestampMs = j["timestampMs"]
        self.count = j["count"]
        self.code = j["code"]

    def to_dict(self):
        j = {}
        j["timestampMs"] = self.timestampMs
        j["count"] = self.count
        j["code"] = self.code
        return j

