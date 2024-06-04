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

class KeyValue(object):
    __slots__ = ["key", "value"]

    __typenames__ = ["string", "int32_t"]

    __dimensions__ = [None, None]

    def __init__(self):
        self.key = ""
        self.value = 0

    def encode(self):
        buf = BytesIO()
        buf.write(KeyValue._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        __key_encoded = self.key.encode('utf-8')
        buf.write(struct.pack('>I', len(__key_encoded)+1))
        buf.write(__key_encoded)
        buf.write(b"\0")
        buf.write(struct.pack(">i", self.value))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != KeyValue._get_packed_fingerprint():
            raise ValueError("Decode error")
        return KeyValue._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = KeyValue()
        __key_len = struct.unpack('>I', buf.read(4))[0]
        self.key = buf.read(__key_len)[:-1].decode('utf-8', 'replace')
        self.value = struct.unpack(">i", buf.read(4))[0]
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if KeyValue in parents: return 0
        tmphash = (0xb2b9e7f49509ad2c) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if KeyValue._packed_fingerprint is None:
            KeyValue._packed_fingerprint = struct.pack(">Q", KeyValue._get_hash_recursive([]))
        return KeyValue._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", KeyValue._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.key = j["key"]
        self.value = j["value"]

    def to_dict(self):
        j = {}
        j["key"] = self.key
        j["value"] = self.value
        return j

