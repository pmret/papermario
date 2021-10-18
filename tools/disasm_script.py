#! /usr/bin/python3

import sys
from pathlib import Path

_script_lib = None
def script_lib(offset):
    global _script_lib

    if not _script_lib:
        _script_lib = {}

        from os import path
        import re

        # star rod database
        """
        LIB_LINE_RE = re.compile(r"\s+:\s+")
        NAME_RE = re.compile(r"({[^}]*})?\s*([a-zA-Z0-9_]+)")

        for filename in Path(path.dirname(__file__), "star-rod", "database").rglob("*.lib"):
            with open(filename, "r") as file:
                for line in file.readlines():
                    parts = LIB_LINE_RE.split(line)

                    if len(parts) >= 3:
                        try:
                            kind = parts[0]
                            vaddr = int(parts[1].split(", ")[0], 16)
                            if name := NAME_RE.match(parts[2]):
                                name = name.group(2)

                                _script_lib[vaddr] = name
                        except:
                            pass
        """

        repo_root = Path(__file__).resolve().parent.parent
        symbols = Path(repo_root / "ver" / "current" / "symbol_addrs.txt")
        with open(symbols, "r") as file:
            for line in file.readlines():
                s = [s.strip() for s in line.split("=", 1)]
                name = s[0]
                vaddr = int(s[1].split(";")[0].split(" ")[0], 16)

                raddr = "0xFFFFFFFF"
                if "rom:" in line:
                    raddr = line.split("rom:",1)[1]
                    if " " in raddr:
                        raddr = raddr.split(" ",1)[0]
                raddr = raddr.strip()

                if vaddr not in _script_lib:
                    _script_lib[vaddr] = []
                _script_lib[vaddr].append([int(raddr, 16), name])

        # Sort the symbols for each vram address by the difference
        # between their rom address and the offset passed in.
        # If offset - rom address goes below 0, it's part of the
        # previous file, so treat it as min priority, same as a default.
        # After sorting, the first rom address and name should be the best candidate.
        for k in _script_lib.keys():
            for i,entry in enumerate(_script_lib[k]):
                diff = offset - entry[0]
                entry[0] = 0xFFFFFFFF if diff < 0 else diff
                _script_lib[k][i][0] = entry[0]
            _script_lib[k] = sorted(_script_lib[k], key=lambda x: x[0])
    return _script_lib

def round_fixed(f: float) -> float:
    g = f * 100.0
    whole = round(g)
    if abs(g - whole) <= 100.0/1024.0:
        f = whole / 100.0
    return f

# Grab CONSTANTS from the include/ folder to save manual work
CONSTANTS = {}
SAVE_VARS = set()
def get_constants():
    global CONSTANTS
    global VALID_SAVE_VARS

    valid_enums = { "StoryProgress", "ItemIDs", "PlayerAnims",
        "ActorIDs", "Events", "SoundIDs", "SongIDs", "Locations",
        "AmbientSounds", "NpcIDs", "Emotes", "NpcFlags",
        "Events", "Statuses", "Elements", "DamageTypes", "HitResults",
        "ActorFlags", "ActorPartFlags", "ActorEventFlags", "ElementFlags" }
    for enum in valid_enums:
        CONSTANTS[enum] = {}
    CONSTANTS["NPC_SPRITE"] = {}
    CONSTANTS["MAP_NPCS"] = {}

    [SAVE_VARS.add(x) for x in ["EVT_WORLD_LOCATION", "EVT_STORY_PROGRESS"]]

    include_path = Path(Path(__file__).resolve().parent.parent / "include")
    enums = Path(include_path / "enums.h").read_text().splitlines()

    '''
    # defines
    for line in enums:
        this_enum = ""
        for enum in valid_defines:
            if f"#define {enum}_" in line:
                this_enum = enum
                break;

        if this_enum:
            name = line.split(" ",2)[1]
            id_ = line.split("0x", 1)[1]
            if " " in id_:
                id_ = id_.split(" ",1)[0]
            CONSTANTS[this_enum][int(id_, 16)] = name
    '''

    # enums
    for i,line in enumerate(enums):
        if line.startswith("enum "):
            enum_name = line.split(" ",1)[1].split(" {",1)[0]
            if enum_name in valid_enums:
                CONSTANTS[enum_name] = {}
                last_num = -1
                i += 1
                while "}" not in enums[i]:
                    if not enums[i]:
                        i += 1
                        continue

                    if "//" in enums[i]:
                        name = enums[i].split("//",1)[0].strip()
                    else:
                        name = enums[i].strip()
                    val = last_num+1
                    if "=" in name:
                        name, val = name.split(" = ")
                        val = int(val[:-1], 0)
                        if val >= 0x80000000:
                            val -= 0x100000000
                    else:
                        name = name[:-1]
                    name = name.strip()
                    #print("\"" + name + "\"", "===", val)

                    CONSTANTS[enum_name][val] = name.strip()
                    i += 1
                    last_num = val

    #exit()
    # sprites
    sprite_path = Path(Path(__file__).resolve().parent.parent / "ver" / "current" / "build" / "include" / "sprite" / "npc")
    for file in sprite_path.iterdir():
        fd = file.read_text()
        for line in fd.splitlines():
            if "#define _NPC_SPRITE_" in line:
                enum = "NPC_SPRITE"
            elif "#define _NPC_PALETTE_" in line:
                enum = "NPC_PALETTE"
            elif "#define _NPC_ANIM_" in line:
                enum = "NPC_ANIM"
            else:
                continue

            name = line.split(" ",2)[1]
            id_ = line.split("0x", 1)[1]
            if " " in id_:
                id_ = id_.split(" ",1)[0]
            name = name.split(f"_{enum}_", 1)[1]
            if enum == "NPC_SPRITE":
                saved_name = name
                saved_id = id_
            else:
                name = name.rsplit(f"{saved_name}_")[1]

            if enum == "NPC_SPRITE":
                if int(id_, 16) not in CONSTANTS["NPC_SPRITE"]:
                    CONSTANTS[enum][int(id_, 16)] = {"name":"", "palettes":{}, "anims":{}}
                CONSTANTS[enum][int(id_, 16)]["name"] = name
            elif enum == "NPC_PALETTE":
                CONSTANTS["NPC_SPRITE"][int(saved_id, 16)]["palettes"][int(id_, 16)] = name
            elif enum == "NPC_ANIM":
                CONSTANTS["NPC_SPRITE"][int(saved_id, 16)]["anims"][int(id_, 16)] = name

    return

def make_anim_macro(self, sprite, palette, anim):
    if sprite == 0xFF and palette == 0xFF and anim == 0xFF:
        return "-1"

    call = "NPC_ANIM("
    if sprite in CONSTANTS["NPC_SPRITE"]:
        call += f"{CONSTANTS['NPC_SPRITE'][sprite]['name']}, "
        if palette in CONSTANTS["NPC_SPRITE"][sprite]["palettes"]:
            call += f"{CONSTANTS['NPC_SPRITE'][sprite]['palettes'][palette]}, "
        else:
            call += f"0x{palette:02X}, "
        if anim in CONSTANTS["NPC_SPRITE"][sprite]["anims"]:
            call += f"{CONSTANTS['NPC_SPRITE'][sprite]['anims'][anim]}"
        else:
            call += f"0x{anim:02X}"
        call += ")"
        self.INCLUDES_NEEDED["sprites"].add(CONSTANTS['NPC_SPRITE'][sprite]['name'])
    else:
        call += f"0x{sprite:02X}, 0x{palette:02X}, 0x{anim:02X})"
    return call

def fix_args(self, func, args, info):
    global CONSTANTS

    new_args = []
    args = args.split(", ")
    for i,arg in enumerate(args):
        if ((arg == "D_80000000") or (arg.startswith("D_B")) or
            (i == 0 and func == "MakeEntity" and arg.startswith("D_"))):
            arg = "0x" + arg[2:]
        if "0x" in arg and int(arg, 16) >= 0xF0000000:
            arg = f"{int(arg, 16) - 0x100000000}"
        if i in info or (i+1 == len(args) and -1 in info):
            if i+1 == len(args) and -1 in info:
                i = -1
            if "_" in arg:
                new_args.append(f"{arg}")
                continue
            argNum = int(arg, 0)

            if info[i] == "Bool":
                new_args.append(f"{'TRUE' if argNum == True else 'FALSE'}")
            elif info[i] == "Hex":
                new_args.append(f"0x{argNum:08X}")
            elif info[i] == "CustomAnim":
                sprite  = (argNum & 0xFF0000) >> 16
                palette = (argNum & 0xFF00)   >> 8
                anim    = (argNum & 0xFF)     >> 0

                #if argNum not in CONSTANTS["MAP_NPCS"]:
                #    new_args.append(f"0x{argNum:X}")
                #    continue

                if func == "SetAnimation" and int(new_args[1], 10) == 0:
                    call = f"{CONSTANTS['PlayerAnims'][argNum]}"
                elif "EVT_" not in args[0] and int(args[0]) >= 0 and CONSTANTS["MAP_NPCS"].get(int(args[0])) == "NPC_PLAYER":
                    if sprite == 0:
                        print(f"Func {func} arg {i} ({CONSTANTS['MAP_NPCS'][int(args[0])]}) -- sprite was 0, is this really valid? Arg 0x{argNum:X} -- sprite: {sprite}, palette: {palette}, anim: {anim}")
                        call = f"0x{argNum:X}"
                    else:
                        call = f"{CONSTANTS['PlayerAnims'][argNum]}"
                else:
                    if sprite == 0:
                        print(f"Func {func} arg {i} ({CONSTANTS['MAP_NPCS'][int(args[0])]}) -- sprite was 0, is this really valid? Arg 0x{argNum:X} -- sprite: {sprite}, palette: {palette}, anim: {anim}")
                        call = f"0x{argNum:X}"
                    else:
                        call = make_anim_macro(self, sprite, palette, anim)
                new_args.append(call)
            elif info[i] == "CustomMsg":
                type_ = (argNum & 0xFF0000) >> 16
                num_ =  (argNum & 0xFFFF)   >> 0
                new_args.append(f"MESSAGE_ID(0x{type_:02X}, 0x{num_:04X})")
            elif info[i] == "NpcFlags":
                enabled = []
                for x in range(32):
                    flag = argNum & (1 << x)
                    if flag:
                        if flag in CONSTANTS["NpcFlags"]:
                            enabled.append(CONSTANTS["NpcFlags"][flag])
                        else:
                            enabled.append(f"0x{flag:08X}")
                if not enabled:
                    enabled.append(f"0")
                new_args.append("((" + " | ".join(enabled) + "))")
            elif info[i] == "NpcIDs":
                if argNum not in CONSTANTS["MAP_NPCS"]:
                    new_args.append(f"0x{argNum:X}")
                    continue

                if argNum >= 0:
                    new_args.append(CONSTANTS["MAP_NPCS"][argNum])
                else:
                    new_args.append(CONSTANTS["NpcIDs"][argNum])
            elif info[i] == "DamageTypes":
                enabled = []
                for x in range(32):
                    flag = argNum & (1 << x)
                    if flag:
                        if flag in CONSTANTS["DamageTypes"]:
                            enabled.append(CONSTANTS["DamageTypes"][flag])
                        else:
                            enabled.append(f"0x{flag:08X}")
                if not enabled:
                    enabled.append(f"0")
                new_args.append("((" + " | ".join(enabled) + "))")
            elif argNum in CONSTANTS[info[i]]:
                new_args.append(f"{CONSTANTS[info[i]][argNum]}")
            else:
                if not (info[i] == "NpcIDs" and argNum > 0):
                    print(f"0x{argNum:X} was not found within {info[i]} constants for function {func} arg {i}, add it.")

                if (info[i] == "ItemIDs" and argNum < 0):
                    new_args.append(f"{int(argNum)}")
                else:
                    #Print the unknowns in hex
                    new_args.append(self.var(argNum))

        else:
            new_args.append(f"{arg}")
    return ", ".join(new_args)

replace_funcs = {
    "AddActorDecoration"        :{0:"ActorIDs"},
    "AddKeyItem"                :{0:"ItemIDs"},
    "AddGoalPos"                :{0:"ActorIDs"},

    "BattleCamTargetActor"      :{0:"ActorIDs"},
    "BindNpcAI"                 :{0:"NpcIDs"},
    "BindNpcDefeat"             :{0:"NpcIDs"},
    "BindNpcIdle"               :{0:"NpcIDs"},
    "BindNpcInteract"           :{0:"NpcIDs"},

    "ContinueSpeech"            :{1:"CustomAnim", 2:"CustomAnim", 4:"CustomMsg"},

    "DisablePlayerInput"        :{0:"Bool"},
    "DisablePlayerPhysics"      :{0:"Bool"},
    "DispatchDamagePlayerEvent" :{1:"Events"},
    "DispatchEvent"             :{0:"ActorIDs"},

    "EnableIdleScript"          :{0:"ActorIDs"},
    "EnableNpcShadow"           :{0:"NpcIDs", 1:"Bool"},
    "EndSpeech"                 :{1:"CustomAnim", 2:"CustomAnim"},
    "EnemyDamageTarget"         :{0:"ActorIDs", 2:"DamageTypes"},
    "EnemyTestTarget"           :{0:"ActorIDs", 2:"DamageTypes"},

    "FindKeyItem"               :{0:"ItemIDs"},
    "ForceHomePos"              :{0:"ActorIDs"},

    "func_802CFE2C"             :{0:"NpcIDs"},
    "func_802CFD30"             :{0:"NpcIDs"},
    "func_802D2520"             :{0:"PlayerAnims"},

    "GetActorPos"               :{0:"ActorIDs"},
    "GetGoalPos"                :{0:"ActorIDs"},
    "GetItemPower"              :{0:"ItemIDs"},
    "GetLastEvent"              :{0:"ActorIDs"},
    "GetNpcPos"                 :{0:"NpcIDs"},

    "HidePlayerShadow"          :{0:"Bool"},
    "HPBarToHome"               :{0:"ActorIDs"},

    "InterpNpcYaw"              :{0:"NpcIDs"},

    "JumpToGoal"                :{0:"ActorIDs"},

    "MakeEntity"                :{0:"Hex", 5:"ItemIDs"},
    "MakeItemEntity"            :{0:"ItemIDs"},
    "ModifyColliderFlags"       :{2:"Hex"},

    "NpcFaceNpc"                :{0:"NpcIDs", 1:"NpcIDs"},
    "NpcFacePlayer"             :{0:"NpcIDs"},
    "NpcJump0"                  :{0:"NpcIDs"},
    "NpcJump1"                  :{0:"NpcIDs"},
    "NpcMoveTo"                 :{0:"NpcIDs"},

    "PlayAmbientSounds"         :{0:"AmbientSounds"},
    "PlaySound"                 :{0:"SoundIDs"},
    "PlaySoundAt"               :{0:"SoundIDs"},
    "PlaySoundAtActor"          :{0:"ActorIDs", 1:"SoundIDs"},
    "PlaySoundAtNpc"            :{0:"NpcIDs", 1:"SoundIDs"},

    "RemoveActorDecoration"     :{0:"ActorIDs"},
    "RemoveNpc"                 :{0:"NpcIDs"},
    "RunToGoal"                 :{0:"ActorIDs", 2:"Bool"},
    "JumpToGoal"                :{0:"ActorIDs", 2:"Bool", 3:"Bool", 4:"Bool"},

    "SetActorDispOffset"        :{0:"ActorIDs"},
    "SetActorJumpGravity"       :{0:"ActorIDs"},
    "SetActorRotation"          :{0:"ActorIDs"},
    "SetActorSpeed"             :{0:"ActorIDs"},
    "SetActorScale"             :{0:"ActorIDs"},
    "SetActorYaw"               :{0:"ActorIDs"},
    "SetAnimation"              :{0:"ActorIDs", 2:"CustomAnim"},
    "SetAnimationRate"          :{0:"ActorIDs"},
    "SetGoalPos"                :{0:"ActorIDs"},
    "SetGoalToHome"             :{0:"ActorIDs"},
    "SetGoalToTarget"           :{0:"ActorIDs"},
    "SetJumpAnimations"         :{0:"ActorIDs", 2:"PlayerAnims", 3:"PlayerAnims", 4:"PlayerAnims"},
    "SetMusicTrack"             :{1:"SongIDs"},
    "SetNpcAnimation"           :{0:"NpcIDs", 1:"CustomAnim"},
    "SetNpcAux"                 :{0:"NpcIDs"},
    "SetNpcFlagBits"            :{0:"NpcIDs", 1:"NpcFlags", 2:"Bool"},
    "SetNpcJumpscale"           :{0:"NpcIDs"},
    "SetNpcPos"                 :{0:"NpcIDs"},
    "SetNpcRotation"            :{0:"NpcIDs"},
    "SetNpcScale"               :{0:"NpcIDs"},
    "SetNpcSpeed"               :{0:"NpcIDs"},
    "SetNpcSprite"              :{1:"Hex"},
    "SetNpcYaw"                 :{0:"NpcIDs"},
    "SetPlayerAnimation"        :{0:"PlayerAnims"},
    "SetSelfEnemyFlagBits"      :{0:"NpcFlags", 1:"Bool"},
    #"SetSelfVar"                :{1:"Bool"}, # apparently this was a bool in some scripts but it passes non-0/1 values, including negatives
    "SetTargetActor"            :{0:"ActorIDs", 1:"ActorIDs"},
    "ShowChoice"                :{0:"CustomMsg"},
    "ShowEmote"                 :{1:"Emotes"},
    "ShowMessageAtScreenPos"    :{0:"CustomMsg"},
    "ShowMessageAtWorldPos"     :{0:"CustomMsg"},
    "SpeakToPlayer"             :{0:"NpcIDs", 1:"CustomAnim", 2:"CustomAnim", -1:"CustomMsg"},
    "SwitchMessage"             :{0:"CustomMsg"},

    "UseIdleAnimation"          :{0:"ActorIDs", 1:"Bool"},
    "BindTakeTurn"              :{0:"ActorIDs"},
    "BindIdle"                  :{0:"ActorIDs"},
    "BindHandleEvent"           :{0:"ActorIDs"},
    "SetActorIdleSpeed"         :{0:"ActorIDs"},
    "SetIdleAnimations"         :{0:"ActorIDs"},
    "SetIdleGoal"               :{0:"ActorIDs"},
    "IdleFlyToGoal"             :{0:"ActorIDs"},
    "GetStatusFlags"            :{0:"ActorIDs"},
    "ResetAllActorSounds"       :{0:"ActorIDs"},
    "FlyToGoal"                 :{0:"ActorIDs"},
    "SetActorPos"               :{0:"ActorIDs"},
    "HPBarToCurrent"            :{0:"ActorIDs"},
    "SetActorFlagBits"          :{0:"ActorIDs"}, # TODO: 1:"ActorFlags"
    "SetPartFlags"              :{0:"ActorIDs"},
    "SetPartPos"                :{0:"ActorIDs"},
    "SetPartDispOffset"         :{0:"ActorIDs"},
}

def replace_constants(self, func, args):
    global replace_funcs

    if func in replace_funcs:
        return fix_args(self, func, args, replace_funcs[func])
    elif func == "PlayEffect":
        argsZ = args.split(", ")
        if "0x" not in argsZ[0]:
            argsZ[0] = f"0x{int(argsZ[0], 10):X}"
        args = ", ".join(argsZ)
    return args

class ScriptDisassembler:
    def __init__(self, bytes, script_name = "script", symbol_map = {}, romstart = 0, INCLUDES_NEEDED = {}, INCLUDED = {"functions": set(), "includes": set()}, prelude = True):
        self.bytes = bytes
        self.script_name = script_name
        self.prelude = prelude

        self.symbol_map = { **script_lib(self.bytes.tell()), **symbol_map }
        self.romstart = romstart
        self.INCLUDES_NEEDED = INCLUDES_NEEDED
        self.INCLUDED = INCLUDED

        self.out = ""
        self.prefix = ""

        self.indent = 1
        self.indent_used = False

        self.done = False

        self.start_pos = self.bytes.tell()
        self.end_pos = 0
        self.instructions = 0

    def disassemble(self):
        while True:
            opcode = self.read_word()
            argc = self.read_word()

            #print(f"Op {opcode:X}, argc {argc}")

            if opcode > 0xFF or argc > 0xFF:
                raise Exception(f"script '{self.script_name}' is malformed")

            argv = []
            for i in range(0, argc):
                argv.append(self.read_word())

            #print(argv)

            self.disassemble_command(opcode, argc, argv)

            self.instructions += 1

            if self.done:
                self.end_pos = self.bytes.tell()
                return self.prefix + self.out

    def write(self, line):
        if self.indent < 0: self.indent = 0
        if self.indent > 1: self.indent_used = True

        self.out += "    " * self.indent
        self.out += line

    def write_line(self, line):
        self.write(line)
        self.out += "\n"

    def prefix_line(self, line):
        self.prefix += line
        self.prefix += "\n"

    def var(self, arg):
        if arg in self.symbol_map:
            return self.symbol_map[arg][0][1]

        v = arg - 2**32 # convert to s32
        if v > -250000000:
            if v <= -220000000: return f"EVT_FIXED({(v + 230000000) / 1024})"
            elif v <= -200000000: return f"EVT_ARRAY_FLAG({v + 210000000})"
            elif v <= -180000000: return f"EVT_ARRAY({v + 190000000})"
            elif v <= -160000000: return f"EVT_SAVE_VAR({v + 170000000})"
            elif v <= -140000000: return f"EVT_AREA_VAR({v + 150000000})"
            elif v <= -120000000: return f"EVT_SAVE_FLAG({v + 130000000})"
            elif v <= -100000000: return f"EVT_AREA_FLAG({v + 110000000})"
            elif v <= -80000000: return f"EVT_MAP_FLAG({v + 90000000})"
            elif v <= -60000000: return f"EVT_FLAG({v + 70000000})"
            elif v <= -40000000: return f"EVT_MAP_VAR({v + 50000000})"
            elif v <= -20000000: return f"EVT_VAR({v + 30000000})"

        if arg == 0xFFFFFFFF:
            return "-1"
        elif (arg & 0xFF000000) == 0x80000000:
            return f"0x{arg:X}"
        elif arg >= 0x80000000:
            return f"{arg - 0x100000000}"
        else:
            return f"{arg}"

    def replace_star_rod_function_name(self, name):
        vram = int(name.split("_",1)[1], 16)
        name = "N(" + name.replace("function", "func") + f"_{(vram - 0x80240000)+self.romstart:X}" + ")"
        return name

    def replace_star_rod_prefix(self, addr, isArg=False):
        if type(addr) is str:
            return addr
        if addr > 0x80000000 and addr in self.symbol_map:
            name = self.symbol_map[addr][0][1]
            toReplace = True
            suffix = ""
            if name.startswith("N(func_"):
                prefix = "ApiStatus "
                name = self.replace_star_rod_function_name(name[2:-1])
                suffix = "(Evt* script, s32 isInitialCall)"
            elif name[2:-1] in self.INCLUDED["includes"]:
                prefix = "ApiStatus "
                suffix = "(Evt* script, s32 isInitialCall)"
            elif name.startswith("N(npcAISettings_"):
                prefix = "NpcAISettings "
            elif name.startswith("N(npcSettings_"):
                prefix = "NpcSettings "
            elif name.startswith("N(npcGroup_"):
                prefix = "StaticNpc "
            elif name.startswith("N(entryList_"):
                prefix = "EntryList "
            elif name.startswith("N(npcGroupList_"):
                prefix = "NpcGroupList "
            elif name.startswith("N("):
                prefix = "EvtSource "
            else:
                toReplace = False

            if toReplace:
                if name not in self.INCLUDED["functions"]:
                    self.INCLUDES_NEEDED["forward"].append(prefix + name + suffix + ";")
                    self.INCLUDED["functions"].add(name)
                return name
            elif not isArg or name.startswith("\""):
                return name
            else:
                return str(addr)
        return addr

    def addr_ref(self, addr, isArg=False):
        if addr in self.symbol_map:
            return self.replace_star_rod_prefix(addr, isArg)
        return self.var(addr) #f"0x{addr:08X}"

    def trigger(self, trigger):
        if trigger == 0x00000040: trigger = "TRIGGER_WALL_PUSH"
        if trigger == 0x00000080: trigger = "TRIGGER_FLOOR_TOUCH"
        if trigger == 0x00000100: trigger = "TRIGGER_WALL_PRESS_A"
        if trigger == 0x00000200: trigger = "TRIGGER_FLOOR_JUMP"
        if trigger == 0x00000400: trigger = "TRIGGER_WALL_TOUCH"
        if trigger == 0x00000800: trigger = "TRIGGER_FLOOR_PRESS_A"
        if trigger == 0x00001000: trigger = "TRIGGER_WALL_HAMMER"
        if trigger == 0x00010000: trigger = "TRIGGER_GAME_FLAG_SET"
        if trigger == 0x00020000: trigger = "TRIGGER_AREA_FLAG_SET"
        if trigger == 0x00040000: trigger = "TRIGGER_CEILING_TOUCH"
        if trigger == 0x00080000: trigger = "TRIGGER_FLOOR_ABOVE"
        if trigger == 0x00100000: trigger = "TRIGGER_POINT_BOMB"
        return f"0x{trigger:X}" if type(trigger) is int else trigger

    def read_word(self):
        return int.from_bytes(self.bytes.read(4), byteorder="big")

    def disassemble_command(self, opcode, argc, argv):
        if opcode == 0x01:
            self.write_line("EVT_END")
            self.indent -= 1

            if self.prelude:
                self.prefix_line(f"EvtSource {self.script_name} = {{")
                self.write_line("};")

            self.done = True
        elif opcode == 0x02: self.write_line(f"EVT_RETURN")
        elif opcode == 0x03: self.write_line(f"EVT_LABEL({self.var(argv[0])})")
        elif opcode == 0x04: self.write_line(f"EVT_GOTO({self.var(argv[0])})")
        elif opcode == 0x05:
            self.write_line(f"EVT_LOOP({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("EVT_END_LOOP")
        elif opcode == 0x07: self.write_line(f"EVT_BREAK_LOOP")
        elif opcode == 0x08: self.write_line(f"EVT_WAIT_FRAMES({self.var(argv[0])})")
        elif opcode == 0x09: self.write_line(f"EVT_WAIT_SECS({self.var(argv[0])})")
        elif opcode == 0x0A:
            self.write_line(f"EVT_IF_EQ({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0B:
            self.write_line(f"EVT_IF_NE({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0C:
            self.write_line(f"EVT_IF_LT({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0D:
            self.write_line(f"EVT_IF_GT({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0E:
            self.write_line(f"EVT_IF_LE{self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0F:
            self.write_line(f"EVT_IF_GE{self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x10:
            self.write_line(f"EVT_IF_FLAG({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x11:
            self.write_line(f"EVT_IF_NOT_FLAG(({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x12:
            self.indent -= 1
            self.write_line(f"EVT_ELSE")
            self.indent += 1
        elif opcode == 0x13:
            self.indent -= 1
            self.write_line(f"EVT_END_IF")
        elif opcode == 0x14:
            self.write_line(f"EVT_SWITCH({self.var(argv[0])})")
            self.indent += 2
        elif opcode == 0x15:
            self.write_line(f"EVT_SWITCH_CONST(0x{argv[0]:X})")
            self.indent += 2
        elif opcode == 0x16:
            self.indent -= 1
            self.write_line(f"EVT_CASE_EQ({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x17:
            self.indent -= 1
            self.write_line(f"EVT_CASE_NE({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x18:
            self.indent -= 1
            self.write_line(f"EVT_CASE_LT({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x19:
            self.indent -= 1
            self.write_line(f"EVT_CASE_GT({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x1A:
            self.indent -= 1
            self.write_line(f"EVT_CASE_LE({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x1B:
            self.indent -= 1
            self.write_line(f"EVT_CASE_GE({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x1C:
            self.indent -= 1
            self.write_line(f"EVT_CASE_DEFAULT")
            self.indent += 1
        elif opcode == 0x1D:
            self.indent -= 1
            self.write_line(f"EVT_CASE_OR_EQ({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x1E:
            self.indent -= 1
            self.write_line(f"EVT_CASE_AND_EQ({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x1F:
            self.indent -= 1
            self.write_line(f"EVT_CASE_FLAG({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x20:
            self.indent -= 1
            self.write_line(f"EVT_END_CASE_GROUP")
            self.indent += 1
        elif opcode == 0x21:
            self.indent -= 1
            self.write_line(f"EVT_CASE_RANGE({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x22: self.write_line(f"EVT_BREAK_SWITCH")
        elif opcode == 0x23:
            self.indent -= 2
            self.write_line(f"EVT_END_SWITCH")
        elif opcode == 0x24: self.write_line(f"EVT_SET({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x25: self.write_line(f"EVT_SET_CONST({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x26: self.write_line(f"EVT_SETF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x27: self.write_line(f"EVT_ADD({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x28: self.write_line(f"EVT_SUB({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x29: self.write_line(f"EVT_MUL({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2A: self.write_line(f"EVT_DIV({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2B: self.write_line(f"EVT_MOD({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2C: self.write_line(f"EVT_ADDF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2D: self.write_line(f"EVT_SUBF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2E: self.write_line(f"EVT_MULF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2F: self.write_line(f"EVT_DIVF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x30: self.write_line(f"EVT_USE_BUF({self.var(argv[0])})")
        elif opcode == 0x31 or opcode == 0x32 or opcode == 0x33 or opcode == 0x34:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_BUF_READ{opcode - 0x30}({', '.join(args)})")
        elif opcode == 0x35:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_BUF_PEEK({', '.join(args)})")
        elif opcode == 0x36: self.write_line(f"EVT_USE_FBUF({self.var(argv[0])})")
        elif opcode == 0x37 or opcode == 0x38 or opcode == 0x39 or opcode == 0x3A:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_FBUF_READ{opcode - 0x36}({', '.join(args)})")
        elif opcode == 0x3B:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_FBUF_PEEK({', '.join(args)})")
        elif opcode == 0x3C: self.write_line(f"EVT_USE_ARRAY({self.var(argv[0])})")
        elif opcode == 0x3D: self.write_line(f"EVT_USE_FLAG_ARRAY({self.var(argv[0])})")
        elif opcode == 0x3E: self.write_line(f"EVT_MALLOC_ARRAY({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x3F: self.write_line(f"EVT_BITWISE_AND({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x40: self.write_line(f"EVT_BITWISE_OR({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x41: self.write_line(f"EVT_BITWISE_AND_CONST({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x42: self.write_line(f"EVT_BITWISE_OR_CONST({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x43:
            args = [*map(self.var, argv[1:])]
            self.write_line(f"{self.addr_ref(argv[0])}({', '.join(args)})")
        elif opcode == 0x44: self.write_line(f"EVT_EXEC({self.addr_ref(argv[0])})")
        elif opcode == 0x45: self.write_line(f"EVT_EXEC_GET_TID({self.addr_ref(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x46: self.write_line(f"EVT_EXEC_WAIT({self.addr_ref(argv[0])})")
        elif opcode == 0x47:
            args = [self.addr_ref(argv[0]), self.trigger(argv[1]), *map(self.var, argv[2:])]
            self.write_line(f"EVT_BIND_TRIGGER({', '.join(args)})")
        elif opcode == 0x48: self.write_line(f"EVT_UNBIND")
        elif opcode == 0x49: self.write_line(f"EVT_KILL_THREAD({self.var(argv[0])})")
        elif opcode == 0x4A: self.write_line(f"EVT_JUMP({self.var(argv[0])})")
        elif opcode == 0x4B: self.write_line(f"EVT_SET_PRIORITY({self.var(argv[0])})")
        elif opcode == 0x4C: self.write_line(f"EVT_SET_TIMESCALE({self.var(argv[0])})")
        elif opcode == 0x4D: self.write_line(f"EVT_SET_GROUP({self.var(argv[0])})")
        elif opcode == 0x4E:
            args = [self.addr_ref(argv[0]), self.trigger(argv[1]), *map(self.var, argv[2:])]
            self.write_line(f"EVT_BIND_PADLOCK({', '.join(args)})")
        elif opcode == 0x4F: self.write_line(f"EVT_SUSPEND_GROUP({self.var(argv[0])})")
        elif opcode == 0x50: self.write_line(f"EVT_RESUME_GROUP({self.var(argv[0])})")
        elif opcode == 0x51: self.write_line(f"EVT_SUSPEND_OTHERS({self.var(argv[0])})")
        elif opcode == 0x52: self.write_line(f"EVT_RESUME_OTHERS({self.var(argv[0])})")
        elif opcode == 0x53: self.write_line(f"EVT_SUSPEND_THREAD({self.var(argv[0])})")
        elif opcode == 0x54: self.write_line(f"EVT_RESUME_THREAD({self.var(argv[0])})")
        elif opcode == 0x55: self.write_line(f"EVT_IS_THREAD_RUNNING({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x56:
            self.write_line("EVT_THREAD")
            self.indent += 1
        elif opcode == 0x57:
            self.indent -= 1
            self.write_line("EVT_END_THREAD")
        elif opcode == 0x58:
            self.write_line("EVT_CHILD_THREAD")
            self.indent += 1
        elif opcode == 0x59:
            self.indent -= 1
            self.write_line("EVT_END_CHILD_THREAD")
        else:
            # unknown opcode
            argv_str = ""
            for arg in argv:
                argv_str += ", "
                argv_str += f"0x{arg:X}"
            self.write_line(f"0x{opcode:02X}{argv_str}),")

class UnsupportedScript(Exception):
    pass

class ScriptDSLDisassembler(ScriptDisassembler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        # True: case block
        # CASE: single condition
        # MULTI: multi-condition(s)
        # MATCH: match block
        self.case_stack = []
        # stores the variable type the case is switching on
        self.case_variable = ""
        self.save_variable = ""
        self.was_multi_case = False

    @property
    def in_case(self):
        return self.case_stack[-1] if self.case_stack else False

    def var(self, arg):
        if arg in self.symbol_map and arg >= 0x80000000:
            return self.symbol_map[arg][0][1]
        elif type(arg) is str:
            return arg

        v = arg - 2**32 # convert to s32
        if v > -250000000:
            if v <= -220000000: return str(round_fixed((v + 230000000) / 1024))
            elif v <= -200000000: return f"EVT_ARRAY_FLAG({v + 210000000})"
            elif v <= -180000000: return f"EVT_ARRAY({v + 190000000})"
            elif v <= -160000000:
                if v + 170000000 == 0:
                    self.save_variable = "EVT_STORY_PROGRESS"
                elif v + 170000000 == 425:
                    self.save_variable = "EVT_WORLD_LOCATION"
                else:
                    self.save_variable = f"EVT_SAVE_VAR({v + 170000000})"
                return self.save_variable
            elif v <= -140000000: return f"EVT_AREA_VAR({v + 150000000})"
            elif v <= -120000000: return f"EVT_SAVE_FLAG({v + 130000000})"
            elif v <= -100000000: return f"EVT_AREA_FLAG({v + 110000000})"
            elif v <= -80000000: return f"EVT_MAP_FLAG({v + 90000000})"
            elif v <= -60000000: return f"EVT_FLAG({v + 70000000})"
            elif v <= -40000000: return f"EVT_MAP_VAR({v + 50000000})"
            elif v <= -20000000: return f"EVT_VAR({v + 30000000})"

        if arg == 0xFFFFFFFF:
            return "-1"
        elif (arg & 0xFF000000) == 0x80000000:
            return f"0x{arg:X}"
        elif arg >= 0x80000000:
            return f"{arg - 0x100000000}"
        else:
            return f"{arg}"

    # TODO: use map's collider names when split
    def collider_id(self, arg):
        if arg >= 0x4000 and arg <= 0x5000:
            return f"entity({arg - 0x4000})"
        else:
            return arg

    def is_float(self, var):
        try:
            float(var)
            return True
        except Exception:
            return False

    def replace_enum(self, var, case=False):
        varO = self.var(var)

        if case:
            self.save_variable = ""

        try:
            var = int(varO, 0)
        except Exception:
            return varO

        if var > 0x10000000:
            var -= 0x100000000

        # put cases for replacing vars here
        if case and "handleEvent" in self.script_name and var in CONSTANTS["Events"]:
            return CONSTANTS["Events"][var]
        elif case and "takeTurn" in self.script_name and var in CONSTANTS["HitResults"]:
            return CONSTANTS["HitResults"][var]
        elif ((    case and self.case_variable == "EVT_STORY_PROGRESS") or
            (not case and self.save_variable == "EVT_STORY_PROGRESS")):
            if var in CONSTANTS["StoryProgress"]:
                return CONSTANTS["StoryProgress"][var]
        elif ((    case and self.case_variable == "EVT_WORLD_LOCATION") or
              (not case and self.save_variable == "EVT_WORLD_LOCATION")):
            if var in CONSTANTS["Locations"]:
                return CONSTANTS["Locations"][var]

        return varO

    def disassemble_command(self, opcode, argc, argv):
        # hacky hacky
        if opcode == 0x43 and len(argv) > 1 and argv[-1] == 0x80000000:
            argv[-1] = "MAKE_ENTITY_END"

        # write case block braces
        if self.in_case == "CASE" or self.in_case == "MULTI":
            if opcode == 0x1D: # multi case
                pass
            elif 0x16 <= opcode <= 0x21: # standard case conditions
                # open and close empty case
                self.out += " {}\n"

                self.case_stack.pop()
                assert self.in_case == "MATCH"

                self.was_multi_case = False
            else:
                # open case
                self.out += " {\n"

                self.case_stack.append(True)

                self.indent += 1
        elif self.in_case != "MATCH" and 0x16 <= opcode <= 0x21: # new case, not including the first
            assert self.case_stack.pop() == True
            self.was_multi_case = self.case_stack.pop() == "MULTI"
            assert self.in_case == "MATCH"

            self.indent -= 1
            self.write_line("}")

        #print(f"Op 0x{opcode:2X} saved_var \"{self.save_variable}\" case_var \"{self.case_variable}\"")
        # case variables need to be saved ahead of time, since they span many instructions
        if ((self.in_case and 0x16 <= opcode <= 0x1B and self.case_variable == "EVT_STORY_PROGRESS") or
            (self.in_case and 0x16 <= opcode <= 0x1B and self.case_variable == "EVT_WORLD_LOCATION")):
            argv[0] = self.replace_enum(argv[0], case=True)

        if opcode == 0x01:
            if self.out.endswith("return;\n"):
                # implicit return; break
                self.out = self.out[:-8].rstrip() + "\n"
            else:
                self.write_line("break;")

            self.indent -= 1

            self.INCLUDED["functions"].add(self.script_name)

            self.prefix_line(f"EvtSource {self.script_name} = SCRIPT({{")
            self.write_line("});")

            self.done = True
        elif opcode == 0x02: self.write_line(f"return;")
        elif opcode == 0x03:
            self.indent -= 1
            self.write_line(f"{self.var(argv[0])}:")
            self.indent += 1
        elif opcode == 0x04: self.write_line(f"goto {self.var(argv[0])};")
        elif opcode == 0x05:
            if argv[0] == 0:
                self.write_line("loop {")
            else:
                self.write_line(f"loop {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x07: self.write_line(f"break loop;")
        elif opcode == 0x08: self.write_line(f"sleep {self.var(argv[0])};")
        elif opcode == 0x09: self.write_line(f"sleep {self.var(argv[0])} secs;")
        elif opcode == 0x0A:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB in SAVE_VARS:
                varA = self.replace_enum(argv[0])
            self.write_line(f"if ({varA} == {varB}) {{")
            self.indent += 1
        elif opcode == 0x0B:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB in SAVE_VARS:
                varA = self.replace_enum(argv[0])
            self.write_line(f"if ({varA} != {varB}) {{")
            self.indent += 1
        elif opcode == 0x0C:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB in SAVE_VARS:
                varA = self.replace_enum(argv[0])
            self.write_line(f"if ({varA} < {varB}) {{")
            self.indent += 1
        elif opcode == 0x0D:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB in SAVE_VARS:
                varA = self.replace_enum(argv[0])
            self.write_line(f"if ({varA} > {varB}) {{")
            self.indent += 1
        elif opcode == 0x0E:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB in SAVE_VARS:
                varA = self.replace_enum(argv[0])
            self.write_line(f"if ({varA} <= {varB}) {{")
            self.indent += 1
        elif opcode == 0x0F:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB in SAVE_VARS:
                varA = self.replace_enum(argv[0])
            self.write_line(f"if ({varA} >= {varB}) {{")
            self.indent += 1
        elif opcode == 0x10:
            self.write_line(f"if ({self.var(argv[0])} & {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x11:
            self.write_line(f"if ({self.var(argv[0])} !& {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x12:
            self.indent -= 1
            self.write_line("} else {")
            self.indent += 1
        elif opcode == 0x13:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x14:
            self.write_line(f"match {self.var(argv[0])} {{")
            self.indent += 1
            self.case_variable = self.var(argv[0])
            self.case_stack.append("MATCH")
        elif opcode == 0x15:
            self.write_line(f"matchc {self.var(argv[0])} {{")
            self.indent += 1
            self.case_variable = self.var(argv[0])
            self.case_stack.append("MATCH")
        elif opcode == 0x16:
            self.case_stack.append("CASE")
            self.write(f"== {self.replace_enum(argv[0], True)}")
        elif opcode == 0x17:
            self.case_stack.append("CASE")
            self.write(f"!= {self.replace_enum(argv[0], True)}")
        elif opcode == 0x18:
            self.case_stack.append("CASE")
            self.write(f"< {self.replace_enum(argv[0], True)}")
        elif opcode == 0x19:
            self.case_stack.append("CASE")
            self.write(f"> {self.replace_enum(argv[0], True)}")
        elif opcode == 0x1A:
            self.case_stack.append("CASE")
            self.write(f"<= {self.replace_enum(argv[0], True)}")
        elif opcode == 0x1B:
            self.case_stack.append("CASE")
            self.write(f">= {self.replace_enum(argv[0], True)}")
        elif opcode == 0x1C:
            self.case_stack.append("CASE")
            self.write(f"else")
        elif opcode == 0x1D:
            if self.in_case == "CASE" or self.in_case == "MULTI":
                self.out += f", {self.replace_enum(argv[0], True)}"

                # replace(!) CASE with MULTI
                self.case_stack.pop()
                self.case_stack.append("MULTI")
            else:
                self.write(f"{self.replace_enum(argv[0], True)}")
                self.case_stack.append("MULTI")
        # opcode 0x1E?
        elif opcode == 0x1F:
            self.case_stack.append("CASE")
            self.write_line(f"? {self.replace_enum(argv[0], True)}")
        elif opcode == 0x20:
            #if not self.was_multi_case:
            #    raise UnsupportedScript("unexpected END_MULTI_CASE")
            pass
        elif opcode == 0x21:
            self.case_stack.append("CASE")
            self.write(f"{self.replace_enum(argv[0], True)} ... {self.replace_enum(argv[1], True)}")
        elif opcode == 0x22: self.write_line("break match;")
        elif opcode == 0x23:
            # close open case if needed
            if self.in_case != "MATCH":
                self.case_stack.pop() == True
                self.case_stack.pop() in ["MULTI", "CASE"]

                self.indent -= 1
                self.write_line("}")

            assert self.case_stack.pop() == "MATCH"

            self.indent -= 1
            self.case_variable = ""
            self.write_line("}")
        elif opcode == 0x24:
            varA = self.replace_enum(argv[0])
            varB = self.replace_enum(argv[1])
            if varB.startswith("script_"):
                varB = "N(" + varB + ")"
            self.write_line(f"{varA} = {varB};")
        elif opcode == 0x25:
            varA = self.replace_enum(argv[0])
            argNum = argv[1]

            sprite  = (argNum & 0xFF0000) >> 16
            palette = (argNum & 0xFF00)   >> 8
            anim    = (argNum & 0xFF)     >> 0

            call = make_anim_macro(self, sprite, palette, anim)

            if "0x" in call:
                call = self.var(argNum)

            self.write_line(f"{varA} = (const) {call};")
        elif opcode == 0x26:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} = {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} = (float) {lhs};")
        elif opcode == 0x27: self.write_line(f"{self.var(argv[0])} += {self.var(argv[1])};")
        elif opcode == 0x28: self.write_line(f"{self.var(argv[0])} -= {self.var(argv[1])};")
        elif opcode == 0x29: self.write_line(f"{self.var(argv[0])} *= {self.var(argv[1])};")
        elif opcode == 0x2A: self.write_line(f"{self.var(argv[0])} /= {self.var(argv[1])};")
        elif opcode == 0x2B: self.write_line(f"{self.var(argv[0])} %= {self.var(argv[1])};")
        elif opcode == 0x2C:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} += {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} += (float) {lhs};")
        elif opcode == 0x2D:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} -= {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} -= (float) {lhs};")
        elif opcode == 0x2E:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} *= {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} *= (float) {lhs};")
        elif opcode == 0x2F:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} /= {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} /= (float) {lhs};")
        elif opcode == 0x30: self.write_line(f"buf_use {self.addr_ref(argv[0])};")
        elif opcode == 0x31: self.write_line(f"buf_read {self.var(argv[0])};")
        elif opcode == 0x32: self.write_line(f"buf_read {self.var(argv[0])} {self.var(argv[1])};")
        elif opcode == 0x33: self.write_line(f"buf_read {self.var(argv[0])} {self.var(argv[1])} {self.var(argv[2])};")
        elif opcode == 0x34: self.write_line(f"buf_read {self.var(argv[0])} {self.var(argv[1])} {self.var(argv[2])} {self.var(argv[3])};")
        elif opcode == 0x35: self.write_line(f"buf_peek {self.var(argv[0])} {self.var(argv[1])};")
        elif opcode == 0x36: self.write_line(f"buf_usef {self.var(argv[0])};")
        elif opcode == 0x37: self.write_line(f"buf_readf {self.var(argv[0])};")
        elif opcode == 0x38: self.write_line(f"buf_readf {self.var(argv[0])} {self.var(argv[1])};")
        elif opcode == 0x39: self.write_line(f"buf_readf {self.var(argv[0])} {self.var(argv[1])} {self.var(argv[2])};")
        elif opcode == 0x3A: self.write_line(f"buf_readf {self.var(argv[0])} {self.var(argv[1])} {self.var(argv[2])} {self.var(argv[3])};")
        elif opcode == 0x3B: self.write_line(f"buf_peekf {self.var(argv[0])} {self.var(argv[1])};")
        elif opcode == 0x3C: self.write_line(f"arr_use {self.addr_ref(argv[0])};")
        elif opcode == 0x3D: self.write_line(f"flags_use {self.addr_ref(argv[0])};")
        elif opcode == 0x3E: self.write_line(f"arr_new {self.var(argv[0])} {self.addr_ref(argv[1])};")
        elif opcode == 0x3F: self.write_line(f"{self.var(argv[0])} &= {self.var(argv[1])};")
        elif opcode == 0x40: self.write_line(f"{self.var(argv[0])} |= {self.var(argv[1])};")
        elif opcode == 0x41: self.write_line(f"{self.var(argv[0])} &= (const) 0x{argv[1]:X};")
        elif opcode == 0x42: self.write_line(f"{self.var(argv[0])} |= (const) 0x{argv[1]:X};")
        elif opcode == 0x43:
            addr = argv[0]
            if addr in self.symbol_map:
                func_name = self.addr_ref(addr)
                for i,arg in enumerate(argv):
                    argv[i] = self.replace_star_rod_prefix(arg, isArg=True)
                argv_str = ", ".join(self.var(arg) for arg in argv[1:])
                argv_str = replace_constants(self, func_name, argv_str)

                self.write_line(f"{func_name}({argv_str});")
            else:
                print(f"script API function {addr:X} is not present in symbol_addrs.txt, please add it")
                exit(1)
        elif opcode == 0x44:
            name = self.addr_ref(argv[0])
            if name.startswith("N("):
                self.INCLUDED["functions"].add(name)
            self.write_line(f"spawn {name};")
        elif opcode == 0x45: self.write_line(f"{self.var(argv[1])} = spawn {self.addr_ref(argv[0])};")
        elif opcode == 0x46:
            name = self.addr_ref(argv[0])
            if name.startswith("N("):
                self.INCLUDED["functions"].add(name)
            self.write_line(f"await {name};")
        elif opcode == 0x47:
            assert argv[3] == 1
            if argv[4] != 0:
                self.write_line(f"{self.var(argv[4])} = bind {self.addr_ref(argv[0])} {self.trigger(argv[1])} {self.collider_id(argv[2])};")
            else:
                self.write_line(f"bind {self.addr_ref(argv[0])} {self.trigger(argv[1])} {self.collider_id(argv[2])};")
        elif opcode == 0x48: self.write_line(f"unbind;")
        elif opcode == 0x49: self.write_line(f"kill {self.var(argv[0])};")
        elif opcode == 0x4A: self.write_line(f"jump {self.var(argv[0])};")
        elif opcode == 0x4B: self.write_line(f"priority ({self.var(argv[0])};")
        elif opcode == 0x4C: self.write_line(f"timescale {self.var(argv[0])};")
        elif opcode == 0x4D: self.write_line(f"group {self.var(argv[0])};")
        elif opcode == 0x4E:
            assert argv[4] == 0
            assert argv[5] == 1
            self.write_line(f"bind_padlock {self.addr_ref(argv[0])} {self.trigger(argv[1])} {self.collider_id(argv[2])} {self.addr_ref(argv[3])};")
        elif opcode == 0x4F: self.write_line(f"suspend group {self.var(argv[0])};")
        elif opcode == 0x50: self.write_line(f"resume group {self.var(argv[0])};")
        elif opcode == 0x51: self.write_line(f"suspend others {self.var(argv[0])};")
        elif opcode == 0x52: self.write_line(f"resume others {self.var(argv[0])};")
        elif opcode == 0x53: self.write_line(f"suspend {self.var(argv[0])};")
        elif opcode == 0x54: self.write_line(f"resume {self.var(argv[0])};")
        elif opcode == 0x55: self.write_line(f"{self.var(argv[1])} = does_script_exist {self.var(argv[0])};")
        elif opcode == 0x56:
            self.write_line("spawn {")
            self.indent += 1
        elif opcode == 0x57:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x58:
            self.write_line("parallel {")
            self.indent += 1
        elif opcode == 0x59:
            self.indent -= 1
            self.write_line("}")
        else:
            raise UnsupportedScript(f"DSL does not support script opcode 0x{opcode:X}")

        # reset this at the end of each instruction
        self.save_variable = ""


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, help="File to dissassemble from")
    parser.add_argument("offset", type=lambda x: int(x, 16), default=0, help="Offset to start dissassembling from")
    parser.add_argument("-end", "-e", "--e", type=lambda x: int(x, 16), default=0, dest="end", required=False, help="End offset to stop dissassembling from.\nOnly used as a way to find valid scripts.")
    parser.add_argument("-vram", "-v", "--v", type=lambda x: int(x, 16), default=0, dest="vram", required=False, help="VRAM start will be tracked and used for the script output name")
    parser.add_argument("-si", "--si", action="store_true", default=False, dest="si", required=False, help="Force si script output")

    args = parser.parse_args()
    vram_base = args.vram
    get_constants()

    INCLUDED = {}
    INCLUDED["functions"] = set()
    INCLUDED["includes"] = set()
    INCLUDES_NEEDED = {}
    INCLUDES_NEEDED["include"] = []
    INCLUDES_NEEDED["forward"] = []
    INCLUDES_NEEDED["npcs"] = {}
    INCLUDES_NEEDED["sprites"] = set()

    if args.end > args.offset:
        # Search the given memory range and report scripts
        with open(args.file, "rb") as f:
            gap = False
            first_print = False

            while args.offset < args.end:
                f.seek(args.offset)

                script = ScriptDSLDisassembler(f, "", {}, 0x978DE0, INCLUDES_NEEDED, INCLUDED)
                try:
                    script_text = script.disassemble()

                    if script.instructions > 1 and "EVT_CMD" not in script_text:
                        if gap and first_print:
                            potential_struct_sizes = { "StaticNpc": 0x1F0, "NpcAISettings":0x30, "NpcSettings":0x2C, "NpcGroupList":0xC }
                            gap_size = args.offset - gap_start
                            potential_struct = "Unknown data"
                            potential_count = 1
                            for k,v in potential_struct_sizes.items():
                                if gap_size % v == 0:
                                    potential_struct = k
                                    potential_count = gap_size // v

                            print(f"========== 0x{gap_size:X} byte gap ({potential_count} {potential_struct}?) 0x{gap_start:X} - 0x{args.offset:X} ==========")
                            print()
                            gap = False
                        #print(f"EvtSource read from 0x{script.start_pos:X} to 0x{script.end_pos:X} "
                        #      f"(0x{script.end_pos - script.start_pos:X} bytes, {script.instructions} instructions)")
                        #print()
                        vram = f"{args.vram:X}_" if vram_base > 0 else f""
                        script_text = script_text.replace("EvtSource script = SCRIPT({", f"EvtSource N(D_{vram}{args.offset:X}) = " + "SCRIPT({")
                        print(script_text, end="")
                        print()
                        #print(f"Valid script found at 0x{args.offset:X}")
                        args.vram += script.end_pos - args.offset
                        args.offset = script.end_pos
                        first_print = True
                    else:
                        if not gap:
                            gap_start = args.offset
                            gap = True
                        args.offset += 4
                        args.vram += 4
                except Exception:
                    if not gap:
                        gap_start = args.offset
                        gap = True
                    args.offset += 4
                    args.vram += 4
    else:
        with open(args.file, "rb") as f:

            f.seek(args.offset)

            script = ScriptDSLDisassembler(f, "", {}, 0x978DE0, INCLUDES_NEEDED, INCLUDED)

            if args.si:
                print(ScriptDisassembler(f, "", {}, 0x978DE0, INCLUDES_NEEDED, INCLUDED).disassemble(), end="")
            else:
                try:
                    script_text = script.disassemble()

                    print(f"EvtSource read from 0x{script.start_pos:X} to 0x{script.end_pos:X} "
                          f"(0x{script.end_pos - script.start_pos:X} bytes, {script.instructions} instructions)")
                    print()
                    print(script_text, end="")

                except UnsupportedScript:
                    f.seek(args.offset)
                    print(ScriptDisassembler(f).disassemble(), end="")
