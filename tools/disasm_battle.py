#! /usr/bin/python3

import struct
import os
from disasm_script import ScriptDisassembler, get_constants, CONSTANTS

AREA_ADDRESSES = {
    "pra3": (0x669D80, 0x66BC90, 0x684A30, 0x80232888, 0x8023298C),
    "pra2": (0x660750, 0x661150, 0x669D80, 0x802215A0, 0x802215C8),
    "sam": (0x623BA0, 0x626A30, 0x63D1E0, 0x80231164, 0x80231290),
    "sam2": (0x63D1E0, 0x63F040, 0x648E10, 0x802234F0, 0x8022352C),
    "omo2_1": (0x543570, 0x543620, 0x5483E0, None, None),
    "omo2_2": (0x5483E0, 0x548500, 0x54CC70, None, None),
    "omo2_3": (0x54CC70, 0x54CCA0, 0x552440, None, None),
    "omo2_4": (0x552440, 0x552440, 0x552BB0, None, None),
    "omo2_5": (0x552BB0, 0x552BB0, 0x556C90, None, None),
    "omo2_6": (0x556C90, 0x556C90, 0x5573E0, None, None),
    "omo2": (0x52B6A0, 0x52B9D0, 0x543570, 0x8022FBF4, 0x8022FC1C),
    "omo3": (0x5573E0, 0x558190, 0x56E2A0, 0x8022EA2C, 0x8022EB1C),
    "pra": (0x648E10, 0x64A340, 0x660750, 0x8022F4D4, 0x8022F614),
    "dig": (0x6DDDC0, 0x6DE670, 0x6F0B30, 0x8022A7C4, 0x8022A83C),
}
BASE_VRAM = 0x80218000
ROMFILE = "../ver/us/baserom.z64"
ROMFILEOPENED = None

GLOBALS = {}
SYMBOLMAP = None

DECOMPED = set()

def findall(p, s):
    '''Yields all the positions of
    the pattern p in the string s.'''
    i = s.find(p)
    while i != -1:
        yield i
        i = s.find(p, i+1)

class RangeHandler:
    def __init__(self, start, end):
        self.free = [[start, end]]
        self.length = end - start

    def add_range(self, start, end):
        found = False
        for i, f in enumerate(self.free):
            if f[0] <= start and f[1] >= end:
                if f[0] == start and f[1] == end:
                    del self.free[i]
                elif f[0] == start and end < f[1]:
                    self.free[i][0] = end
                elif f[0] < start and end == f[1]:
                    self.free[i][1] = start
                else:
                    new_end = self.free[i][1]
                    self.free[i][1] = start
                    self.free.insert(i+1, [end, new_end])
                found = True
                break
        if not found:
            raise Exception(f"Error adding range {hex(start + BASE_VRAM)} : {hex(end + BASE_VRAM)}")

    def getPercent(self):
        total = sum(b-a for a,b in self.free)
        return int(total / self.length * 10000) / 100


class StringComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        pos = self.offset
        while self.parent.rom[pos] != 0:
            pos += 1
        self.value = self.parent.rom[self.offset: pos].decode('utf-8')
        pos += 1
        while pos % 4 != 0:
            pos += 1
        self.parent.add_range(self.offset, pos)
        self.size = pos - self.offset

class JapStringComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):

        length = 0
        is_dbl_char = False
        for byte in self.parent.rom[self.offset:]:
            if byte == 0 and not is_dbl_char:
                break

            # ignore null terminator when reading double-byte char
            if is_dbl_char:
                is_dbl_char = False
            else:
                is_dbl_char = False
                if byte & 0xF0 == 0x80:
                    is_dbl_char = True
                if byte & 0xF0 == 0x90:
                    is_dbl_char = True
                if byte & 0xF0 == 0xE0:
                    is_dbl_char = True
                if byte & 0xF0 == 0xF0:
                    is_dbl_char = True
            length += 1

        self.value = self.parent.rom[self.offset: self.offset + length].decode('shift-jis')
        length += 1
        while length % 4 != 0:
            length += 1
        self.parent.add_range(self.offset, self.offset + length)
        self.size = length

class StageListComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        self.value = f"StageList N({self.offset:08X}) = {{\n"
        self.externs = ""
        pos = self.offset
        while True:
            stringRef, stageRef = struct.unpack(">II", self.parent.rom[pos:pos+8])
            if stringRef == 0 and stageRef == 0:
                break
            stageName = self.parent.getText("string", stringRef)
            self.parent.addComponent("stage", [stageRef])
            self.value += f'    {{ "{stageName}", &N({stageRef:08X}) }},\n'
            pos += 8
        self.value += "    {},\n};\n"
        pos += 8
        self.size = pos - self.offset
        self.parent.add_range(self.offset, pos)

class StageComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        tex, shape, hit, pre, post, bg, fgml, spSize, spForm, u24 = struct.unpack(">IIIIIIIIII", self.parent.rom[self.offset:self.offset + 0x28])
        #swizzle
        if tex != 0:
            self.tex = self.parent.getText("string", tex)
        else:
            self.tex = None
        if shape != 0:
            self.shape = self.parent.getText("string", shape)
        else:
            self.shape = None
        if hit != 0:
            self.hit = self.parent.getText("string", hit)
        else:
            self.hit = None
        if pre != 0:
            self.pre = pre
        else:
            self.pre = None
        if post != 0:
            self.post = post
        else:
            self.post = None
        if bg != 0:
            self.bg = self.parent.getText("string", bg)
        else:
            self.bg = None
        if fgml != 0:
            self.fgml = fgml
        else:
            self.fgml = None
        self.spSize = spSize
        if spForm != 0:
            self.spForm = spForm
        else:
            self.spForm = None
        self.u24 = u24

        self.value = f'Stage N({self.offset+BASE_VRAM:08X}) = {{\n'
        if self.tex is not None:
            self.value += f'    .texture = "{self.tex}",\n'
        if self.shape is not None:
            self.value += f'    .shape = "{self.shape}",\n'
        if self.hit is not None:
            self.value += f'    .hit = "{self.hit}",\n'
        if self.bg is not None:
            self.value += f'    .bg = "{self.bg}",\n'
        if self.pre is not None:
            self.value += f'    .preBattle = &N({self.pre:08X}),\n'
            self.parent.addComponent("script", [self.pre])
        if self.post is not None:
            self.value += f'    .postBattle = &N({self.post:08X}),\n'
            self.parent.addComponent("script", [self.post])
        if self.fgml is not None:
            self.value += f'    .foregroundModelList = N({self.fgml:08X}),\n'
            self.parent.addComponent("modelList", [self.fgml, self.shape])
        if self.spForm is not None:
            self.value += f'    .specialFormationSize = {self.spSize:08X},\n'
            self.value += f'    .specialFormation = N({self.spForm:08X}),\n'
            self.parent.addComponent("formation", [self.spForm, self.spSize])
        if self.u24 != 0:
            raise Exception("unk_24 in stage")
        self.value += '};\n'

        self.size = 0x28
        self.parent.add_range(self.offset, self.offset + 0x28)

class ModelListComponent:
    def __init__(self, parent, offset, shapeName):
        self.parent = parent
        self.offset = offset
        self.shapeName = shapeName

    def parse(self):
        #open shape header
        self.modelsDict = {}
        with open(f'../include/mapfs/{self.shapeName}.h', 'r') as f:
            for line in f.readlines():
                define, name, value = line.split()
                value = int(value, base=16)
                self.modelsDict[value] = name

        pos = self.offset
        self.value = f"s32 N({self.offset:08X})[] = {{\n"
        self.value += '    '
        while True:
            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            if val32 != 0 and val32 in self.modelsDict:
                self.value += f'{self.modelsDict[val32]},'
            else:
                self.value += f'{val32},'
            if val32 != 0:
                self.value += ' '
            if val32 == 0:
                break
        self.value += '\n};\n'
        self.parent.add_range(self.offset, pos)

class BattleListComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        self.value = f"BattleList N({self.offset+BASE_VRAM:08X}) = {{\n"
        self.refs = []
        pos = self.offset
        formationIndex = 0
        self.formationDict = {}
        while True:
            stringRef, size, formRef, stageRef, u10 = struct.unpack(">IIIII", self.parent.rom[pos:pos+20])
            if stringRef == 0 and size == 0 and formRef == 0 and stageRef == 0 and u10 == 0:
                break
            battleName = self.parent.getText("japString", stringRef)
            formationName = f'{formRef:08X}'
            self.parent.addComponent("formation", [formRef, size])
            stageName = f'{stageRef:08X}'
            self.parent.addComponent("stage", [stageRef])
            if u10 != 0:
                u10Name = f' ,unk_10 = &N{u10:08X}'
            else:
                u10Name = ''
            self.value += f'    BATTLE("{battleName}", N({formationName}), &N({stageName}){u10Name}),\n'
            pos += 20
        self.value += "    {},\n};\n"
        pos += 20
        self.size = pos - self.offset
        self.parent.add_range(self.offset, pos)


class FormationComponent:
    def __init__(self, parent, offset, count):
        self.parent = parent
        self.offset = offset
        self.count = count

    def parse(self):
        #find actor names
        if "actorNamesShort" not in GLOBALS:
            GLOBALS["actorNamesShort"] = {}
            GLOBALS["actorNamesLong"] = {}
            with open(f'../src/battle/battle.h', 'r') as f:
                inActorNames = False
                for line in f.readlines():
                    if inActorNames:
                        if 'ActorType' in line:
                            inActorNames = False
                        else:
                            if line.strip() != '':
                                name, eq, value = line.split()
                                value = int(value[:-1], base=16)
                                GLOBALS["actorNamesLong"][value] = name
                                name = name[11:].lower()
                                GLOBALS["actorNamesShort"][value] = name
                    else:
                        if 'ActorType' in line:
                            inActorNames = True
        self.value = f'Formation N({self.offset+BASE_VRAM:08X}) = {{\n'
        pos = self.offset
        for i in range(self.count):
            actorRef, home, priority, var0, var1, var2, var3 = struct.unpack(">IIIIIII", self.parent.rom[pos:pos+28])
            varsString = ""
            if var0 != 0:
                varsString += f" .var0 = 0x{var0:08X},"
            if var1 != 0:
                varsString += f" .var1 = 0x{var1:08X},"
            if var2 != 0:
                varsString += f" .var2 = 0x{var2:08X},"
            if var3 != 0:
                varsString += f" .var3 = 0x{var3:08X},"
            #get actorRef type
            #actorType = struct.unpack(">B", self.parent.rom[actorRef - BASE_VRAM + 5: actorRef - BASE_VRAM + 6])[0]
            #actorName = GLOBALS["actorNamesShort"][actorType]
            #self.actorBPDict[actorRef] = actorName
            #print(f'=========================                 {hex(home)}')
            if home < 1000:
                self.value += f'    {{ .actor = &N({actorRef:08X}), .home = {{ .index = {home} }}, .priority = {priority},{varsString} }},\n'
            else:
                self.value += f'    {{ .actor = &N({actorRef:08X}), .home = {{ .vec = &N({home:08X}) }}, .priority = {priority},{varsString} }},\n'
                self.parent.addComponent("vector3D", [home])
            self.parent.addComponent("actorBlueprint", [actorRef])
            pos += 28
        self.value += "};\n"
        self.size = pos - self.offset
        self.parent.add_range(self.offset, pos)


class Vector3DComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        pos = self.offset
        i1, i2, i3 = struct.unpack(">iii", self.parent.rom[pos:pos+12])
        self.value = f'Vec3i N({self.offset + BASE_VRAM:08X}) = {{ {i1}, {i2}, {i3} }};\n'
        pos += 12
        self.size = pos - self.offset
        self.parent.add_range(self.offset, pos)

class ScriptComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        ROMFILEOPENED.seek(self.parent.romStart + self.offset)
        script_disasm = ScriptDisassembler(ROMFILEOPENED, f'N({self.offset+BASE_VRAM:08X})', symbol_map=SYMBOLMAP, use_script_lib=False)
        script_value = script_disasm.disassemble()
        while True:
            q = script_value.find('0x8')
            if q == -1:
                break
            evt = script_value.rfind('EVT', 0, q)
            evt_subs = script_value[evt:q]
            if evt_subs.startswith('EVT_EXEC') or evt_subs.startswith('EVT_CALL(Bind'):
                self.parent.addComponent("script", [int(script_value[q+2:q+10], base=16)])
            elif evt_subs.startswith('EVT_CALL(SetIdleAnimations'):
                self.parent.addComponent("idleAnimations", [int(script_value[q+2:q+10], base=16)])
            elif evt_subs.startswith('EVT_CALL(SetDefenseTable'):
                self.parent.addComponent("defenseTable", [int(script_value[q+2:q+10], base=16)])
            elif evt_subs.startswith('EVT_CALL(SetStatusTable'):
                self.parent.addComponent("statusTable", [int(script_value[q+2:q+10], base=16)])
            elif evt_subs.startswith('EVT_CALL(SummonEnemy'):
                self.parent.addComponent("formation", [int(script_value[q+2:q+10], base=16), 1])
            elif evt_subs.startswith('EVT_CALL(LoadAnimatedModel'):
                self.parent.addComponent("animatedModel", [int(script_value[q+2:q+10], base=16)])
            elif evt_subs.startswith('EVT_CALL(PlayModelAnimation'):
                self.parent.addComponent("animationScript", [int(script_value[q+2:q+10], base=16)])
            else:
                print(script_value[evt:q+10])
            script_value = script_value[:q] + 'N(' + script_value[q+2:q+10] + ')' + script_value[q+10:]

        self.value = script_value
        self.size = script_disasm.end_pos - self.parent.romStart - self.offset
        self.parent.add_range(self.offset, script_disasm.end_pos - self.parent.romStart)
        #print(self.value)

class ActorBlueprintComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        self.flags, self.u04, self.typ, self.level, self.maxHP, self.partCount, self.u0A, self.partsData, self.script,\
               self.statusTable, self.escapeChance, self.airLiftChance, self.spookChance, self.baseStatusChance,\
               self.upAndAwayChance, self.spinSmashReq, self.powerBounceChance, self.coinReward, self.sizeX, self.sizeY,\
               self.hpX, self.hpY, self.iconX, self.iconY, self.msgX, self.msgY = struct.unpack(">IBBBBhhIIIBBBBBBBBbbbbbbbb", self.parent.rom[self.offset:self.offset + 0x28])
        if "actorFlags" not in GLOBALS:
            GLOBALS["actorFlags"] = {}
            with open(f'../include/enums.h', 'r') as f:
                inActorFlags = False
                for line in f.readlines():
                    if inActorFlags:
                        if '};' in line:
                            inActorFlags = False
                        else:
                            if line.strip() != '':
                                name, eq, value, *_ = line.split()
                                value = int(value[:-1], base=16)
                                GLOBALS["actorFlags"][value] = name
                    else:
                        if 'enum ActorFlags {' in line:
                            inActorFlags = True
        #find actor names
        if "actorNamesShort" not in GLOBALS:
            GLOBALS["actorNamesShort"] = {}
            GLOBALS["actorNamesLong"] = {}
            with open(f'../src/battle/battle.h', 'r') as f:
                inActorNames = False
                for line in f.readlines():
                    if inActorNames:
                        if 'ActorType' in line:
                            inActorNames = False
                        else:
                            if line.strip() != '':
                                name, eq, value = line.split()
                                value = int(value[:-1], base=16)
                                GLOBALS["actorNamesLong"][value] = name
                                name = name[11:].lower()
                                GLOBALS["actorNamesShort"][value] = name
                    else:
                        if 'ActorType' in line:
                            inActorNames = True
        self.value = f"ActorBlueprint N({self.offset+BASE_VRAM:08X}) = {{\n"
        flagsValue = ""
        for i in range(32):
            if self.flags & (2**i):
                if flagsValue != "":
                    flagsValue += " | "
                flagsValue += GLOBALS["actorFlags"][2**i]
        if flagsValue == "":
            flagsValue = "0"
        self.value += f'    .flags = {flagsValue},\n'
        self.name = GLOBALS["actorNamesShort"][self.typ]
        self.value += f'    .type = {GLOBALS["actorNamesLong"][self.typ]},\n'
        self.value += f'    .level = {self.level},\n'
        self.value += f'    .maxHP = {self.maxHP},\n'
        self.value += f'    .partCount = ARRAY_COUNT(N({self.partsData:08X})),\n'
        self.value += f'    .partsData = N({self.partsData:08X}),\n'
        self.value += f'    .script = &N({self.script:08X}),\n'
        if self.statusTable != 0:
            self.value += f'    .statusTable = N({self.statusTable:08X}),\n'
            self.parent.addComponent("statusTable", [self.statusTable])
        else:
            self.value += f'    .statusTable = NULL,\n'
        self.value += f'    .escapeChance = {self.escapeChance},\n'
        self.value += f'    .airLiftChance = {self.airLiftChance},\n'
        self.value += f'    .spookChance = {self.spookChance},\n'
        self.value += f'    .baseStatusChance = {self.baseStatusChance},\n'
        self.value += f'    .upAndAwayChance = {self.upAndAwayChance},\n'
        self.value += f'    .spinSmashReq = {self.spinSmashReq},\n'
        self.value += f'    .powerBounceChance = {self.powerBounceChance},\n'
        self.value += f'    .coinReward = {self.coinReward},\n'
        self.value += f'    .size = {{ {self.sizeX}, {self.sizeY} }},\n'
        self.value += f'    .hpBarOffset = {{ {self.hpX}, {self.hpY} }},\n'
        self.value += f'    .statusIconOffset = {{ {self.iconX}, {self.iconY} }},\n'
        self.value += f'    .statusMessageOffset = {{ {self.msgX}, {self.msgY} }},\n'
        self.value += '};\n'
        self.parent.addComponent("actorPartsBlueprint", [self.partsData, self.partCount])
        self.parent.addComponent("script", [self.script])
        self.parent.add_range(self.offset, self.offset + 0x28)

class ActorPartsBlueprintComponent:
    def __init__(self, parent, offset, count):
        self.parent = parent
        self.offset = offset
        self.count = count

    def parse(self):
        pos = self.offset
        self.value = f'ActorPartBlueprint N({self.offset+BASE_VRAM:08X})[] = {{\n'
        for i in range(self.count):
            self.flags, self.index, self.posX, self.posY, self.posZ, self.targetX,\
                        self.targetY, self.opacity, self.idleAnims, self.defTable,\
                        self.eventFlags, self.immunFlags, self.u1C, self.u1D, self.u1E, self.u20 = struct.unpack(">IbbbbbbhIIIIbbhi", self.parent.rom[pos:pos + 0x24])
            pos += 0x24
            self.value += '    {\n'
            if "actorPartFlags" not in GLOBALS:
                GLOBALS["actorPartFlags"] = {}
                with open(f'../include/enums.h', 'r') as f:
                    inActorPartFlags = False
                    for line in f.readlines():
                        if inActorPartFlags:
                            if '};' in line:
                                inActorPartFlags = False
                            else:
                                if line.strip() != '':
                                    name, eq, value, *_ = line.split()
                                    value = int(value[:-1], base=16)
                                    GLOBALS["actorPartFlags"][value] = name
                        else:
                            if 'enum ActorPartFlags {' in line:
                                inActorPartFlags = True
            if "actorEventFlags" not in GLOBALS:
                GLOBALS["actorEventFlags"] = {}
                with open(f'../include/enums.h', 'r') as f:
                    inActorPartFlags = False
                    for line in f.readlines():
                        if inActorPartFlags:
                            if '};' in line:
                                inActorPartFlags = False
                            else:
                                if line.strip() != '':
                                    name, eq, value, *_ = line.split()
                                    value = int(value[:-1], base=16)
                                    GLOBALS["actorEventFlags"][value] = name
                        else:
                            if 'enum ActorEventFlags {' in line:
                                inActorPartFlags = True
            flagsValue = ""
            for i in range(32):
                if self.flags & (2**i):
                    if flagsValue != "":
                        flagsValue += " | "
                    flagsValue += GLOBALS["actorPartFlags"][2**i]
            if flagsValue == "":
                flagsValue = "0"
            self.value += f'        .flags = {flagsValue},\n'
            self.value += f'        .index = {self.index},\n'
            self.value += f'        .posOffset = {{ {self.posX}, {self.posY}, {self.posZ} }},\n'
            self.value += f'        .targetOffset = {{ {self.targetX}, {self.targetY} }},\n'
            self.value += f'        .opacity = {self.opacity},\n'
            if self.idleAnims != 0:
                self.value += f'        .idleAnimations = N({self.idleAnims:08X}),\n'
                self.parent.addComponent("idleAnimations", [self.idleAnims])
            else:
                self.value += f'        .idleAnimations = NULL,\n'
            if self.defTable != 0:
                self.value += f'        .defenseTable = N({self.defTable:08X}),\n'
                self.parent.addComponent("defenseTable", [self.defTable])
            else:
                self.value += f'        .defenseTable = NULL,\n'
            flagsValue = ""
            for i in range(32):
                if self.eventFlags & (2**i):
                    if flagsValue != "":
                        flagsValue += " | "
                    flagsValue += GLOBALS["actorEventFlags"][2**i]
            if flagsValue == "":
                flagsValue = "0"
            self.value += f'        .eventFlags = {flagsValue},\n'
            self.value += f'        .elementImmunityFlags = {self.immunFlags},\n'
            if self.immunFlags != 0:
                raise Exception("ActorPartBlueprint->immunFlags")
            self.value += f'        .unk_1C = {self.u1C},\n'
            self.value += f'        .unk_1D = {self.u1D},\n'
            if self.u1E != 0:
                raise Exception("ActorPartBlueprint->u1E")
            if self.u20 != 0:
                self.value += f'        .unk_20 = {self.u20},\n'
            self.value += '    },\n'

        self.value += '};\n'
        self.parent.add_range(self.offset, self.offset + 0x24 * self.count)

class IdleAnimationsComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        if "Statuses" not in GLOBALS:
            GLOBALS["Statuses"] = {}
            with open(f'../include/enums.h', 'r') as f:
                inActorPartFlags = False
                for line in f.readlines():
                    if inActorPartFlags:
                        if '};' in line:
                            inActorPartFlags = False
                        else:
                            if line.strip() != '':
                                name, eq, value, *_ = line.split()
                                value = int(value[:-1], base=16)
                                GLOBALS["Statuses"][value] = name
                    else:
                        if 'enum StatusKeys {' in line:
                            inActorPartFlags = True
        pos = self.offset
        self.value = f's32 N({self.offset+BASE_VRAM:08X})[] = {{\n'
        while True:
            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            if val32 == 0:
                self.value += '    STATUS_END,\n'
                break
            else:
                self.value += f'    {GLOBALS["Statuses"][val32]}, '
            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            self.value += f'{CONSTANTS["NPC_SPRITE"][val32]},\n'
        self.value += '};\n'
        self.parent.add_range(self.offset, pos)

class DefenseTableComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        if "Elements" not in GLOBALS:
            GLOBALS["Elements"] = {}
            with open(f'../include/enums.h', 'r') as f:
                inActorPartFlags = False
                for line in f.readlines():
                    if inActorPartFlags:
                        if '};' in line:
                            inActorPartFlags = False
                        else:
                            if line.strip() != '':
                                name, eq, value, *_ = line.split()
                                value = int(value[:-1], base=16)
                                GLOBALS["Elements"][value] = name
                    else:
                        if 'enum Elements {' in line:
                            inActorPartFlags = True
        pos = self.offset
        self.value = f's32 N({self.offset + BASE_VRAM:08X})[] = {{\n'
        while True:
            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            if val32 == 0:
                self.value += '    ELEMENT_END,\n'
                break
            else:
                self.value += f'    {GLOBALS["Elements"][val32]}, '
            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            self.value += f'{val32},\n'
        self.value += '};\n'
        self.parent.add_range(self.offset, pos)

class StatusTableComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        if "Statuses" not in GLOBALS:
            GLOBALS["Statuses"] = {}
            with open(f'../include/enums.h', 'r') as f:
                inActorPartFlags = False
                for line in f.readlines():
                    if inActorPartFlags:
                        if '};' in line:
                            inActorPartFlags = False
                        else:
                            if line.strip() != '':
                                name, eq, value, *_ = line.split()
                                value = int(value[:-1], base=16)
                                GLOBALS["Statuses"][value] = name
                    else:
                        if 'enum StatusKeys {' in line:
                            inActorPartFlags = True
        pos = self.offset
        self.value = f's32 N({self.offset+BASE_VRAM:08X})[] = {{\n'
        while True:
            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            if val32 == 0:
                self.value += '    STATUS_END,\n'
                break
            else:
                self.value += f'    {GLOBALS["Statuses"][val32]}, '

            val32 = struct.unpack(">i", self.parent.rom[pos:pos+4])[0]
            pos += 4
            self.value += f'{val32},\n'
        self.value += '};\n'
        self.parent.add_range(self.offset, pos)

class AnimatedModelComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        pos = self.offset
        self.value = f'StaticAnimatorNode* N({self.offset+BASE_VRAM:08X})[] = {{\n'
        while True:
            val32 = struct.unpack(">I", self.parent.rom[pos:pos+4])[0]
            pos += 4
            if val32 == 0:
                self.value += '    NULL,\n'
                break
            self.value += f'    &N({val32:08X}),\n'
            self.parent.addComponent("animatorNode", [val32])
        self.value += '};\n'
        self.parent.add_range(self.offset, pos)

def read(f):
    return struct.unpack('>h', f.read(2))[0]

def i2f(x):
    return round(x * 180 / 32767 * 200) / 200

class AnimationScriptComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        romOffset = self.parent.romStart + self.offset
        self.value = f'AnimScript N({self.offset+BASE_VRAM:08X})[] = {{\n'
        indent = '    '
        with open(ROMFILE, 'rb') as f:
            f.seek(romOffset)
            while True:
                op = read(f)
                if op == 0:
                    self.value += f'{indent}AS_END,\n'
                    break
                if op == 1:
                    self.value += f'{indent}AS_WAIT, {read(f)},\n'
                elif op == 3:
                    indent = indent[:-4]
                    self.value += f'{indent}AS_END_LOOP,\n'
                elif op == 5:
                    self.value += f'{indent}AS_SET_ROTATION, {read(f)}, AS_F({i2f(read(f))}), AS_F({i2f(read(f))}), AS_F({i2f(read(f))}),\n'
                elif op == 6:
                    self.value += f'{indent}AS_ADD_ROTATION, {read(f)}, AS_F({i2f(read(f))}), AS_F({i2f(read(f))}), AS_F({i2f(read(f))}),\n'
                elif op == 8:
                    self.value += f'{indent}AS_SET_POS, {read(f)}, {read(f)}, {read(f)}, {read(f)},\n'
                elif op == 10:
                    self.value += f'{indent}AS_LOOP,\n'
                    indent += '    '
                elif op == 14:
                    self.value += f'{indent}AS_SET_FLAGS, {read(f)},\n'
                elif op == 15:
                    self.value += f'{indent}AS_SET_NODE_FLAGS, {read(f)}, {read(f)},\n'
                elif op == 16:
                    self.value += f'{indent}AS_CLEAR_NODE_FLAGS, {read(f)}, {read(f)},\n'
                elif op == 17:
                    self.value += f'{indent}AS_SET_SCALE, {read(f)}, AS_F({i2f(read(f))}), AS_F({i2f(read(f))}), AS_F({i2f(read(f))}),\n'
                elif op == 18:
                    self.value += f'{indent}AS_SET_RENDER_MODE, {read(f)},\n'
                elif op == 19:
                    self.value += f'{indent}AS_OP_19,\n'
                else:
                    raise Exception(str(f'Unknown opcode {op}'))
            endPos = f.tell()
            print(self.offset, endPos - self.parent.romStart)
            self.value += '};'
        self.parent.add_range(self.offset, endPos - self.parent.romStart)

class AnimatorNodeComponent:
    def __init__(self, parent, offset):
        self.parent = parent
        self.offset = offset

    def parse(self):
        dlist, rotX, rotY, rotZ, _, posX, posY, posZ, sibling, child, vertexStartOffset, _, vtxList, modelID, _ = struct.unpack(">IhhhhfffIIhhIhh", self.parent.rom[self.offset:self.offset+0x2C])
        self.value = f'StaticAnimatorNode N({self.offset+BASE_VRAM:08X}) {{\n'
        if dlist != 0:
            raise Exception('dlist in StaticAnimatorNode')
        if rotX != 0 or rotY != 0 or rotZ != 0:
            self.value += f'    .rot = {{ {rotX}, {rotY}, {rotZ} }},\n'
        if posX != 0 or posY != 0 or posZ != 0:
            self.value += f'    .pos = {{ {posX}f, {posY}f, {posZ}f }},\n'
        if sibling != 0:
            self.value += f'    .sibling = &N({sibling:08X}),\n'
        if child != 0:
            self.value += f'    .child = &N({child:08X}),\n'
        if vertexStartOffset != 0:
            self.value += f'    .vertexStartOffset = {vertexStartOffset},\n'
        if vtxList != 0:
            self.value += f'    .vtxList = &N({vtxList:08X}),\n'
        if modelID != 0:
            self.value += f'    .modelID = {modelID},\n'
        self.value += '};\n'
        self.parent.add_range(self.offset, self.offset + 0x2C)

class IceShardArrayComponent:
    def __init__(self, parent, offset, count):
        self.parent = parent
        self.offset = offset
        self.count = count

    def parse(self):
        pos = self.offset
        self.value = f'IceShardBlueprint N({self.offset+BASE_VRAM:08X})[] = {{\n'
        for i in range(self.count):
            self.value += '    {\n'
            u00, u04, u08, u0C, u10, u14, u18, u1C, u20, u24 = struct.unpack(">IffffIffff", self.parent.rom[pos:pos+0x28])
            pos += 0x28
            self.value += f'        .unk_00 = {u00:},\n'
            self.value += f'        .unk_04 = {u04:.1f}f,\n'
            self.value += f'        .unk_08 = {u08:.1f}f,\n'
            self.value += f'        .unk_0C = {u0C:.1f}f,\n'
            self.value += f'        .unk_10 = {u10:.1f}f,\n'
            self.value += f'        .unk_14 = {u14},\n'
            self.value += f'        .unk_18 = {u18:.1f}f,\n'
            self.value += f'        .unk_1C = {u1C:.1f}f,\n'
            self.value += f'        .unk_20 = {u20:.1f}f,\n'
            self.value += f'        .unk_24 = {u24:.1f}f,\n'
            self.value += '    },\n'
        self.value += '\n};\n'
        self.parent.add_range(self.offset, pos)

class UnknownComponent:
    def __init__(self, parent, offset, count):
        self.parent = parent
        self.offset = offset
        self.count = count

    def parse(self):
        pos = self.offset
        self.value = f's32 N(UNKNOWN_{self.offset+BASE_VRAM:08X})[] = {{\n'
        self.value += '    '
        for i in range(self.count):
            val32 = struct.unpack(">I", self.parent.rom[pos:pos+4])[0]
            pos += 4
            self.value += f'0x{val32:08X}, '
        self.value += '\n};\n'
        self.parent.add_range(self.offset, pos)

class Unknown8Component:
    def __init__(self, parent, offset, count):
        self.parent = parent
        self.offset = offset
        self.count = count

    def parse(self):
        pos = self.offset
        self.value = f's8 N(UNKNOWN_{self.offset+BASE_VRAM:08X})[] = {{\n'
        self.value += '    '
        for i in range(self.count):
            val32 = struct.unpack(">b", self.parent.rom[pos:pos+1])[0]
            pos += 1
            self.value += f'0x{val32:X}, '
        self.value += '\n};\n'
        self.parent.add_range(self.offset, pos)

class BattleDisassembler:
    def __init__(self, name):
        if name not in AREA_ADDRESSES:
            raise Exception("Unknown area name")

        self.area = name
        self.romStart, self.dataStart, self.dataEnd, self.battleVram, self.stageVram = AREA_ADDRESSES[name]

        with open(ROMFILE, "rb") as f:
            data = f.read()
            self.rom = data[self.romStart:self.dataEnd]

        global ROMFILEOPENED
        ROMFILEOPENED = open(ROMFILE, "rb")
        self.rangeHandler = RangeHandler(self.dataStart - self.romStart, self.dataEnd - self.romStart)

        global SYMBOLMAP
        get_constants()
        if SYMBOLMAP is None:
            script_disasm = ScriptDisassembler(ROMFILEOPENED)
            SYMBOLMAP = script_disasm.symbol_map
        else:
            pass
        vramStart = BASE_VRAM
        vramEnd = BASE_VRAM + self.dataEnd - self.romStart
        for addr in list(SYMBOLMAP.keys()):
            if vramStart <= addr < vramEnd:
                del SYMBOLMAP[addr]

        self.components = {}


    def add_range(self, start, end):
        self.rangeHandler.add_range(start, end)

    def addComponent(self, name, params):
        if params[0] in self.components:
            return None
        #if name != "unknown":
            #print(name, hex(params[0] - BASE_VRAM), params[1:])
        offset = params[0] - BASE_VRAM
        if offset >= self.dataEnd - self.romStart:
            print("BAD OFFSET")
            return
        if name == "stageList":
            comp = StageListComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "stage":
            comp = StageComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "script":
            comp = ScriptComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "modelList":
            comp = ModelListComponent(self, offset, params[1])
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "battleList":
            comp = BattleListComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "formation":
            comp = FormationComponent(self, offset, params[1])
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "vector3D":
            comp = Vector3DComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "actorBlueprint":
            comp = ActorBlueprintComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "actorPartsBlueprint":
            comp = ActorPartsBlueprintComponent(self, offset, params[1])
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "idleAnimations":
            comp = IdleAnimationsComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "defenseTable":
            comp = DefenseTableComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "statusTable":
            comp = StatusTableComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "animatedModel":
            comp = AnimatedModelComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "animatorNode":
            comp = AnimatorNodeComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "animationScript":
            comp = AnimationScriptComponent(self, offset)
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "iceShardArray":
            comp = IceShardArrayComponent(self, offset, params[1])
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "unknown":
            comp = UnknownComponent(self, offset, params[1])
            self.components[params[0]] = comp
            comp.parse()
            return comp
        elif name == "unknown8":
            comp = Unknown8Component(self, offset, params[1])
            self.components[params[0]] = comp
            comp.parse()
            return comp
        else:
            raise Exception(f"Unknown component {name}")

    def getComponent(self, vram):
        return self.components[vram]

    def getText(self, name, vram):
        if vram in self.components:
            return self.components[vram].value
        else:
            offset = vram - BASE_VRAM
            if name == "string":
                comp = StringComponent(self, offset)
                self.components[vram] = comp
                comp.parse()
                return comp.value
            elif name == "japString":
                comp = JapStringComponent(self, offset)
                self.components[vram] = comp
                comp.parse()
                return comp.value
            else:
                raise Exception(f"Unknown text component {name}")

    def addUnknown(self):
        while len(self.rangeHandler.free) > 0:
            a,b = self.rangeHandler.free[-1]
            if a % 4 == 0 and b % 4 == 0:
                self.addComponent("unknown", [a + BASE_VRAM, (b - a) // 4])
            else:
                self.addComponent("unknown8", [a + BASE_VRAM, b - a])

    def run(self):
        self.addComponent("stageList", [self.stageVram])
        self.addComponent("battleList", [self.battleVram])
        self.addSpecial()
        print(self.rangeHandler.getPercent())
        self.addUnknown()

    def addSpecial(self):
        self.addComponent("script", [0x8022A870])
        self.addComponent("script", [0x8022A910])
        self.addComponent("script", [0x8022A9F0])
        self.addComponent("script", [0x8022AAA0])
        self.addComponent("script", [0x8022AB40])
        self.addComponent("unknown", [0x80228FC4, 8])
        self.addComponent("unknown", [0x80228FE4, 8])
        self.addComponent("actorBlueprint", [0x80228028])
        self.addComponent("actorBlueprint", [0x802189B8])
        self.addComponent("script", [0x80225BF0])
        self.addComponent("statusTable", [0x80226F00])
        #self.addComponent("actorBlueprint", [0x802224C8])
        #self.addComponent("actorBlueprint", [0x80227E98])
        #self.addComponent("script", [0x8022EC90])
        #self.addComponent("script", [0x8022ED7C])
        #self.addComponent("script", [0x8022E700])
        #self.addComponent("script", [0x8022E7EC])
        #self.addComponent("animationScript", [802224C8])
        #self.addComponent("animationScript", [0x8022AE48])
        #self.addComponent("iceShardArray", [0x8022FC30, 15])

    def print(self):
        offsets = sorted(list(self.components.keys()))
        with open("output.c", "w", encoding="utf-8") as f:
            for offset in offsets:
                f.write(self.components[offset].value)
                f.write('\n')

if __name__ == "__main__":
    disasm = BattleDisassembler("dig")
    disasm.run()
    disasm.print()
