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

class AppCleanInfo(object):
    __slots__ = ["cleanTimeSecond", "cleanArea", "cleanTimeTotalSecond", "cleanAreaTotal", "cleanCountTotal", "esimateArea", "carpetArea", "numberOfTasksCompleted", "sweepTimeTotalSecond", "washTimeTotalSecond"]

    __typenames__ = ["int32_t", "float", "int32_t", "float", "int32_t", "float", "float", "int32_t", "int32_t", "int32_t"]

    __dimensions__ = [None, None, None, None, None, None, None, None, None, None]

    def __init__(self):
        self.cleanTimeSecond = 0
        self.cleanArea = 0.0
        self.cleanTimeTotalSecond = 0
        self.cleanAreaTotal = 0.0
        self.cleanCountTotal = 0
        self.esimateArea = 0.0
        self.carpetArea = 0.0
        self.numberOfTasksCompleted = 0
        self.sweepTimeTotalSecond = 0
        self.washTimeTotalSecond = 0

    def encode(self):
        buf = BytesIO()
        buf.write(AppCleanInfo._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">ifififfiii", self.cleanTimeSecond, self.cleanArea, self.cleanTimeTotalSecond, self.cleanAreaTotal, self.cleanCountTotal, self.esimateArea, self.carpetArea, self.numberOfTasksCompleted, self.sweepTimeTotalSecond, self.washTimeTotalSecond))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != AppCleanInfo._get_packed_fingerprint():
            raise ValueError("Decode error")
        return AppCleanInfo._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = AppCleanInfo()
        self.cleanTimeSecond, self.cleanArea, self.cleanTimeTotalSecond, self.cleanAreaTotal, self.cleanCountTotal, self.esimateArea, self.carpetArea, self.numberOfTasksCompleted, self.sweepTimeTotalSecond, self.washTimeTotalSecond = struct.unpack(">ifififfiii", buf.read(40))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if AppCleanInfo in parents: return 0
        tmphash = (0x5b806652b6850371) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if AppCleanInfo._packed_fingerprint is None:
            AppCleanInfo._packed_fingerprint = struct.pack(">Q", AppCleanInfo._get_hash_recursive([]))
        return AppCleanInfo._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", AppCleanInfo._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.cleanTimeSecond = j["cleanTimeSecond"]
        self.cleanArea = j["cleanArea"]
        self.cleanTimeTotalSecond = j["cleanTimeTotalSecond"]
        self.cleanAreaTotal = j["cleanAreaTotal"]
        self.cleanCountTotal = j["cleanCountTotal"]
        self.esimateArea = j["esimateArea"]
        self.carpetArea = j["carpetArea"]
        self.numberOfTasksCompleted = j["numberOfTasksCompleted"]
        self.sweepTimeTotalSecond = j["sweepTimeTotalSecond"]
        self.washTimeTotalSecond = j["washTimeTotalSecond"]

    def to_dict(self):
        j = {}
        j["cleanTimeSecond"] = self.cleanTimeSecond
        j["cleanArea"] = self.cleanArea
        j["cleanTimeTotalSecond"] = self.cleanTimeTotalSecond
        j["cleanAreaTotal"] = self.cleanAreaTotal
        j["cleanCountTotal"] = self.cleanCountTotal
        j["esimateArea"] = self.esimateArea
        j["carpetArea"] = self.carpetArea
        j["numberOfTasksCompleted"] = self.numberOfTasksCompleted
        j["sweepTimeTotalSecond"] = self.sweepTimeTotalSecond
        j["washTimeTotalSecond"] = self.washTimeTotalSecond
        return j

