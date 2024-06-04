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

import mars_message.Time

import mars_message.Component

class Order(object):
    __slots__ = ["orderId", "sign", "valid", "time", "mode", "sweepPower", "mopPower", "componentCount", "components", "roomCount", "rooms"]

    __typenames__ = ["int8_t", "int32_t", "int8_t", "mars_message.Time", "int8_t", "int8_t", "int8_t", "int8_t", "mars_message.Component", "int8_t", "int8_t"]

    __dimensions__ = [None, None, None, None, None, None, None, None, ["componentCount"], None, ["roomCount"]]

    def __init__(self):
        self.orderId = 0
        self.sign = 0
        self.valid = 0
        self.time = mars_message.Time()
        self.mode = 0
        self.sweepPower = 0
        self.mopPower = 0
        self.componentCount = 0
        self.components = []
        self.roomCount = 0
        self.rooms = []

    def encode(self):
        buf = BytesIO()
        buf.write(Order._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">bib", self.orderId, self.sign, self.valid))
        assert self.time._get_packed_fingerprint() == mars_message.Time._get_packed_fingerprint()
        self.time._encode_one(buf)
        buf.write(struct.pack(">bbbb", self.mode, self.sweepPower, self.mopPower, self.componentCount))
        for i0 in range(self.componentCount):
            assert self.components[i0]._get_packed_fingerprint() == mars_message.Component._get_packed_fingerprint()
            self.components[i0]._encode_one(buf)
        buf.write(struct.pack(">b", self.roomCount))
        buf.write(struct.pack('>%db' % self.roomCount, *self.rooms[:self.roomCount]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Order._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Order._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Order()
        self.orderId, self.sign, self.valid = struct.unpack(">bib", buf.read(6))
        self.time = mars_message.Time._decode_one(buf)
        self.mode, self.sweepPower, self.mopPower, self.componentCount = struct.unpack(">bbbb", buf.read(4))
        self.components = []
        for i0 in range(self.componentCount):
            self.components.append(mars_message.Component._decode_one(buf))
        self.roomCount = struct.unpack(">b", buf.read(1))[0]
        self.rooms = struct.unpack('>%db' % self.roomCount, buf.read(self.roomCount))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if Order in parents: return 0
        newparents = parents + [Order]
        tmphash = (0x23d0ba046f4b8922+ mars_message.Time._get_hash_recursive(newparents)+ mars_message.Component._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Order._packed_fingerprint is None:
            Order._packed_fingerprint = struct.pack(">Q", Order._get_hash_recursive([]))
        return Order._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", Order._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.orderId = j["orderId"]
        self.sign = j["sign"]
        self.valid = j["valid"]
        self.time.from_dict(j["time"])
        self.mode = j["mode"]
        self.sweepPower = j["sweepPower"]
        self.mopPower = j["mopPower"]
        self.componentCount = j["componentCount"]
        self.components = [x.from_dict() for x in j["components"]]
        self.roomCount = j["roomCount"]
        self.rooms = j["rooms"]

    def to_dict(self):
        j = {}
        j["orderId"] = self.orderId
        j["sign"] = self.sign
        j["valid"] = self.valid
        j["time"] = self.time.to_dict()
        j["mode"] = self.mode
        j["sweepPower"] = self.sweepPower
        j["mopPower"] = self.mopPower
        j["componentCount"] = self.componentCount
        j["components"] = [x.to_dict() for x in self.components]
        j["roomCount"] = self.roomCount
        j["rooms"] = self.rooms
        return j
