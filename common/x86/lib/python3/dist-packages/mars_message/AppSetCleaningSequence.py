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

class AppSetCleaningSequence(object):
    __slots__ = ["version", "count", "roomId"]

    __typenames__ = ["int8_t", "int8_t", "int8_t"]

    __dimensions__ = [None, None, ["count"]]

    def __init__(self):
        self.version = 0
        self.count = 0
        self.roomId = []

    def encode(self):
        buf = BytesIO()
        buf.write(AppSetCleaningSequence._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">bb", self.version, self.count))
        buf.write(struct.pack('>%db' % self.count, *self.roomId[:self.count]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != AppSetCleaningSequence._get_packed_fingerprint():
            raise ValueError("Decode error")
        return AppSetCleaningSequence._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = AppSetCleaningSequence()
        self.version, self.count = struct.unpack(">bb", buf.read(2))
        self.roomId = struct.unpack('>%db' % self.count, buf.read(self.count))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if AppSetCleaningSequence in parents: return 0
        tmphash = (0x5a2ffb0350b0befa) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if AppSetCleaningSequence._packed_fingerprint is None:
            AppSetCleaningSequence._packed_fingerprint = struct.pack(">Q", AppSetCleaningSequence._get_hash_recursive([]))
        return AppSetCleaningSequence._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", AppSetCleaningSequence._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.version = j["version"]
        self.count = j["count"]
        self.roomId = j["roomId"]

    def to_dict(self):
        j = {}
        j["version"] = self.version
        j["count"] = self.count
        j["roomId"] = self.roomId
        return j
