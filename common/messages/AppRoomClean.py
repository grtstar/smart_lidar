"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class AppRoomClean(object):
    __slots__ = ["version", "cleanRepeat", "count", "id"]

    __typenames__ = ["int8_t", "int8_t", "int8_t", "int8_t"]

    __dimensions__ = [None, None, None, ["count"]]

    def __init__(self):
        self.version = 0
        self.cleanRepeat = 0
        self.count = 0
        self.id = []

    def encode(self):
        buf = BytesIO()
        buf.write(AppRoomClean._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">bbb", self.version, self.cleanRepeat, self.count))
        buf.write(struct.pack('>%db' % self.count, *self.id[:self.count]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != AppRoomClean._get_packed_fingerprint():
            raise ValueError("Decode error")
        return AppRoomClean._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = AppRoomClean()
        self.version, self.cleanRepeat, self.count = struct.unpack(">bbb", buf.read(3))
        self.id = struct.unpack('>%db' % self.count, buf.read(self.count))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if AppRoomClean in parents: return 0
        tmphash = (0x29e42f8aefe578fb) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if AppRoomClean._packed_fingerprint is None:
            AppRoomClean._packed_fingerprint = struct.pack(">Q", AppRoomClean._get_hash_recursive([]))
        return AppRoomClean._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", AppRoomClean._get_packed_fingerprint())[0]

