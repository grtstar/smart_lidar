"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

import mars_message.Point

class Segment(object):
    __slots__ = ["begin", "end"]

    __typenames__ = ["mars_message.Point", "mars_message.Point"]

    __dimensions__ = [None, None]

    def __init__(self):
        self.begin = mars_message.Point()
        self.end = mars_message.Point()

    def encode(self):
        buf = BytesIO()
        buf.write(Segment._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        assert self.begin._get_packed_fingerprint() == mars_message.Point._get_packed_fingerprint()
        self.begin._encode_one(buf)
        assert self.end._get_packed_fingerprint() == mars_message.Point._get_packed_fingerprint()
        self.end._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Segment._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Segment._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Segment()
        self.begin = mars_message.Point._decode_one(buf)
        self.end = mars_message.Point._decode_one(buf)
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Segment in parents: return 0
        newparents = parents + [Segment]
        tmphash = (0x8dd6acf370332ecf+ mars_message.Point._get_hash_recursive(newparents)+ mars_message.Point._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Segment._packed_fingerprint is None:
            Segment._packed_fingerprint = struct.pack(">Q", Segment._get_hash_recursive([]))
        return Segment._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Segment._get_packed_fingerprint())[0]
