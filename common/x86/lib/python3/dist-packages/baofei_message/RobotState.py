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

class RobotState(object):
    __slots__ = ["cleanTime", "cleanArea", "battery", "brush", "voice", "direction", "fan", "watertank", "workMode", "workState", "chargerStandType", "mopInstallState", "mopBoard", "waterMark", "attract", "carpetColor", "uvSwitch", "mapUpdateSign", "hadWork", "quiet", "openRegion", "workType", "carpetpressure", "bsChildLock", "bsLinkState", "autoDry", "aiVision", "workStep", "washMopFrequency", "wipeMode", "pauseOpType", "washWorkType", "mop", "aiImgAgreementId", "clearComponent", "relocationState", "dustCollector", "faultStatus"]

    __typenames__ = ["int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "int32_t", "string", "int32_t", "int32_t", "int32_t", "int32_t"]

    __dimensions__ = [None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None]

    def __init__(self):
        self.cleanTime = 0
        self.cleanArea = 0
        self.battery = 0
        self.brush = 0
        self.voice = 0
        self.direction = 0
        self.fan = 0
        self.watertank = 0
        self.workMode = 0
        self.workState = 0
        self.chargerStandType = 0
        self.mopInstallState = 0
        self.mopBoard = 0
        self.waterMark = 0
        self.attract = 0
        self.carpetColor = 0
        self.uvSwitch = 0
        self.mapUpdateSign = 0
        self.hadWork = 0
        self.quiet = 0
        self.openRegion = 0
        self.workType = 0
        self.carpetpressure = 0
        self.bsChildLock = 0
        self.bsLinkState = 0
        self.autoDry = 0
        self.aiVision = 0
        self.workStep = 0
        self.washMopFrequency = 0
        self.wipeMode = 0
        self.pauseOpType = 0
        self.washWorkType = 0
        self.mop = 0
        self.aiImgAgreementId = ""
        self.clearComponent = 0
        self.relocationState = 0
        self.dustCollector = 0
        self.faultStatus = 0

    def encode(self):
        buf = BytesIO()
        buf.write(RobotState._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", self.cleanTime, self.cleanArea, self.battery, self.brush, self.voice, self.direction, self.fan, self.watertank, self.workMode, self.workState, self.chargerStandType, self.mopInstallState, self.mopBoard, self.waterMark, self.attract, self.carpetColor, self.uvSwitch, self.mapUpdateSign, self.hadWork, self.quiet, self.openRegion, self.workType, self.carpetpressure, self.bsChildLock, self.bsLinkState, self.autoDry, self.aiVision, self.workStep, self.washMopFrequency, self.wipeMode, self.pauseOpType, self.washWorkType, self.mop))
        __aiImgAgreementId_encoded = self.aiImgAgreementId.encode('utf-8')
        buf.write(struct.pack('>I', len(__aiImgAgreementId_encoded)+1))
        buf.write(__aiImgAgreementId_encoded)
        buf.write(b"\0")
        buf.write(struct.pack(">iiii", self.clearComponent, self.relocationState, self.dustCollector, self.faultStatus))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != RobotState._get_packed_fingerprint():
            raise ValueError("Decode error")
        return RobotState._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = RobotState()
        self.cleanTime, self.cleanArea, self.battery, self.brush, self.voice, self.direction, self.fan, self.watertank, self.workMode, self.workState, self.chargerStandType, self.mopInstallState, self.mopBoard, self.waterMark, self.attract, self.carpetColor, self.uvSwitch, self.mapUpdateSign, self.hadWork, self.quiet, self.openRegion, self.workType, self.carpetpressure, self.bsChildLock, self.bsLinkState, self.autoDry, self.aiVision, self.workStep, self.washMopFrequency, self.wipeMode, self.pauseOpType, self.washWorkType, self.mop = struct.unpack(">iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", buf.read(132))
        __aiImgAgreementId_len = struct.unpack('>I', buf.read(4))[0]
        self.aiImgAgreementId = buf.read(__aiImgAgreementId_len)[:-1].decode('utf-8', 'replace')
        self.clearComponent, self.relocationState, self.dustCollector, self.faultStatus = struct.unpack(">iiii", buf.read(16))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if RobotState in parents: return 0
        tmphash = (0xbb2ca750d4788c28) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if RobotState._packed_fingerprint is None:
            RobotState._packed_fingerprint = struct.pack(">Q", RobotState._get_hash_recursive([]))
        return RobotState._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

    def get_hash(self):
        """Get the LCM hash of the struct"""
        return struct.unpack(">Q", RobotState._get_packed_fingerprint())[0]

    def from_dict(self, j):
        self.cleanTime = j["cleanTime"]
        self.cleanArea = j["cleanArea"]
        self.battery = j["battery"]
        self.brush = j["brush"]
        self.voice = j["voice"]
        self.direction = j["direction"]
        self.fan = j["fan"]
        self.watertank = j["watertank"]
        self.workMode = j["workMode"]
        self.workState = j["workState"]
        self.chargerStandType = j["chargerStandType"]
        self.mopInstallState = j["mopInstallState"]
        self.mopBoard = j["mopBoard"]
        self.waterMark = j["waterMark"]
        self.attract = j["attract"]
        self.carpetColor = j["carpetColor"]
        self.uvSwitch = j["uvSwitch"]
        self.mapUpdateSign = j["mapUpdateSign"]
        self.hadWork = j["hadWork"]
        self.quiet = j["quiet"]
        self.openRegion = j["openRegion"]
        self.workType = j["workType"]
        self.carpetpressure = j["carpetpressure"]
        self.bsChildLock = j["bsChildLock"]
        self.bsLinkState = j["bsLinkState"]
        self.autoDry = j["autoDry"]
        self.aiVision = j["aiVision"]
        self.workStep = j["workStep"]
        self.washMopFrequency = j["washMopFrequency"]
        self.wipeMode = j["wipeMode"]
        self.pauseOpType = j["pauseOpType"]
        self.washWorkType = j["washWorkType"]
        self.mop = j["mop"]
        self.aiImgAgreementId = j["aiImgAgreementId"]
        self.clearComponent = j["clearComponent"]
        self.relocationState = j["relocationState"]
        self.dustCollector = j["dustCollector"]
        self.faultStatus = j["faultStatus"]

    def to_dict(self):
        j = {}
        j["cleanTime"] = self.cleanTime
        j["cleanArea"] = self.cleanArea
        j["battery"] = self.battery
        j["brush"] = self.brush
        j["voice"] = self.voice
        j["direction"] = self.direction
        j["fan"] = self.fan
        j["watertank"] = self.watertank
        j["workMode"] = self.workMode
        j["workState"] = self.workState
        j["chargerStandType"] = self.chargerStandType
        j["mopInstallState"] = self.mopInstallState
        j["mopBoard"] = self.mopBoard
        j["waterMark"] = self.waterMark
        j["attract"] = self.attract
        j["carpetColor"] = self.carpetColor
        j["uvSwitch"] = self.uvSwitch
        j["mapUpdateSign"] = self.mapUpdateSign
        j["hadWork"] = self.hadWork
        j["quiet"] = self.quiet
        j["openRegion"] = self.openRegion
        j["workType"] = self.workType
        j["carpetpressure"] = self.carpetpressure
        j["bsChildLock"] = self.bsChildLock
        j["bsLinkState"] = self.bsLinkState
        j["autoDry"] = self.autoDry
        j["aiVision"] = self.aiVision
        j["workStep"] = self.workStep
        j["washMopFrequency"] = self.washMopFrequency
        j["wipeMode"] = self.wipeMode
        j["pauseOpType"] = self.pauseOpType
        j["washWorkType"] = self.washWorkType
        j["mop"] = self.mop
        j["aiImgAgreementId"] = self.aiImgAgreementId
        j["clearComponent"] = self.clearComponent
        j["relocationState"] = self.relocationState
        j["dustCollector"] = self.dustCollector
        j["faultStatus"] = self.faultStatus
        return j
