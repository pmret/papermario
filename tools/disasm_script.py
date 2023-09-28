#!/usr/bin/env python3

import sym_info
from pathlib import Path


_script_lib = None


def script_lib(offset=0):
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
                    raddr = line.split("rom:", 1)[1]
                    if " " in raddr:
                        raddr = raddr.split(" ", 1)[0]
                raddr = raddr.strip()

                if vaddr not in _script_lib:
                    _script_lib[vaddr] = []
                _script_lib[vaddr].append([int(raddr, 16), name])

        """
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
        """
    return _script_lib


def extend_symbol_map(a, b):
    for k in b:
        if k not in a:
            a[k] = b[k]
        else:
            a[k] += b[k]

    return a


def round_fixed(f: float) -> float:
    g = f * 100.0
    whole = round(g)
    if abs(g - whole) <= 100.0 / 1024.0:
        f = whole / 100.0
    return f


def find_symbol_in_overlay(symbol_map, overlay_rom_addr, symbol_ram_addr):
    if not symbol_ram_addr in symbol_map:
        return None

    lowest_delta = None
    lowest_symbol_name = None

    for rom_addr, symbol_name in symbol_map[symbol_ram_addr]:
        delta = rom_addr - overlay_rom_addr

        if delta >= 0 and (lowest_delta is None or delta <= lowest_delta):
            lowest_delta = delta
            lowest_symbol_name = symbol_name

    if lowest_symbol_name:
        return lowest_symbol_name

    return symbol_map[symbol_ram_addr][0][1]


def browse_header(valid_enums, enums):
    # enums
    for i, line in enumerate(enums):
        if (line.startswith("enum ")) or (line.startswith("typedef enum ")):
            enum_name = line.split("enum ", 1)[1].split(" {", 1)[0]
            if enum_name in valid_enums:
                CONSTANTS[enum_name] = {}
                last_num = -1
                i += 1
                while "}" not in enums[i]:
                    if not enums[i]:
                        i += 1
                        continue

                    if "//" in enums[i]:
                        name = enums[i].split("//", 1)[0].strip()
                    else:
                        name = enums[i].strip()
                    val = last_num + 1
                    if "=" in name:
                        name, val = name.split(" = ")
                        val = int(val[:-1], 0)
                        if val > 0x80000000:
                            val -= 0x100000000
                    else:
                        name = name[:-1]
                    name = name.strip()
                    # print("\"" + name + "\"", "===", val)

                    CONSTANTS[enum_name][val] = name.strip()
                    i += 1
                    last_num = val
    return


# Grab CONSTANTS from the include/ folder to save manual work
CONSTANTS = {}
SWITCH_TYPES = []
LOCAL_WORDS = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
SAVE_VARS = set()


def get_constants():
    global CONSTANTS
    global VALID_SAVE_VARS

    valid_enums = {
        "StoryProgress",
        "ItemIDs",
        "PlayerAnims",
        "ActorType",
        "ActorIDs",
        "Events",
        "SoundIDs",
        "SongIDs",
        "Locations",
        "AmbientSounds",
        "NpcIDs",
        "Emotes",
        "NpcFlags",
        "Statuses",
        "Elements",
        "DamageTypes",
        "ElementImmunityFlags",
        "HitResults",
        "ActorFlags",
        "ActorPartFlags",
        "ActorEventFlags",
        "ElementFlags",
        "EncounterTriggers",
        "Abilities",
        "EasingType",
        "DecorationIDs",
        "HitResults",
        "Phases",
        "ItemSpawnModes",
        "ActionStates",
        "Triggers",
        "Buttons",
        "ActionCommand",
        "MoveIDs",
        "BattleStatusFlags1",
        "BattleStatusFlags2",
        "BtlCameraPreset",
        "EffectID",
        "StatusFlags",
    }
    for enum in valid_enums:
        CONSTANTS[enum] = {}
    CONSTANTS["NPC_SPRITE"] = {}
    CONSTANTS["MAP_NPCS"] = {}

    [SAVE_VARS.add(x) for x in ["GB_WorldLocation", "GB_StoryProgress"]]

    include_path = Path(Path(__file__).resolve().parent.parent / "include")
    enums = Path(include_path / "enums.h").read_text().splitlines()
    browse_header(valid_enums, enums)
    enums = Path(include_path / "effects.h").read_text().splitlines()
    browse_header(valid_enums, enums)

    include_path = Path(Path(__file__).resolve().parent.parent / "src" / "battle")
    enums = Path(include_path / "battle.h").read_text().splitlines()
    browse_header(valid_enums, enums)

    """
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
    """

    # exit()
    # sprites
    sprite_path = Path(
        Path(__file__).resolve().parent.parent / "ver" / "current" / "build" / "include" / "sprite" / "npc"
    )
    for file in sprite_path.iterdir():
        fd = file.read_text()
        for line in fd.splitlines():
            if "#define NPC_ANIM_" not in line:
                continue

            header_file_name = file.parts[-1]

            name = line.split(" ", 2)[1]
            value = int(line.split("0x", 1)[1], base=16)

            CONSTANTS["NPC_SPRITE"][value] = name
            CONSTANTS["NPC_SPRITE"][str(value) + ".h"] = header_file_name

    return


def make_anim_macro(self, sprite, palette, anim):
    if sprite == 0xFF and palette == 0xFF and anim == 0xFF:
        return "-1"

    value = (sprite << 16) | (palette << 8) | anim

    if value in CONSTANTS["NPC_SPRITE"]:
        self.INCLUDES_NEEDED["sprites"].add(CONSTANTS["NPC_SPRITE"][str(value) + ".h"])
        return CONSTANTS["NPC_SPRITE"][value]
    else:
        return f"0x{sprite:02X}{palette:02X}{anim:02X}"


def remove_evt_ptr(s):
    if s.startswith("EVT_PTR("):
        return s[8:-1]
    else:
        return s


def make_flags(argNum, flags, new_args):
    enabled = []
    for x in range(32):
        flag = argNum & (1 << x)
        if flag:
            if flag in CONSTANTS[flags]:
                enabled.append(CONSTANTS[flags][flag])
            else:
                enabled.append(f"0x{flag:08X}")
    if not enabled:
        enabled.append(f"0")
    new_args.append(" | ".join(enabled))


def fix_args(self, func, args, info):
    global CONSTANTS

    new_args = []
    args = args.split(", ")
    for i, arg in enumerate(args):
        if (remove_evt_ptr(arg).startswith("D_B")) or (i == 0 and func == "MakeEntity" and arg.startswith("D_")):
            if func == "MakeEntity":
                arg = "MAKE_ENTITY_END"
            else:
                arg = "0x" + remove_evt_ptr(arg)[2:]

        if "0x" in arg and int(remove_evt_ptr(arg), 16) >= 0xF0000000:
            arg = f"{int(remove_evt_ptr(arg), 16) - 0x100000000}"

        if i in info or (i + 1 == len(args) and -1 in info):
            if arg.startswith("LW"):
                argNum = trim_lw(arg)
                LOCAL_WORDS[int(argNum)] = info[i]
                new_args.append(f"{arg}")
                # print(LOCAL_WORDS)
                continue

            if i + 1 == len(args) and -1 in info:
                i = -1
            if "_" in arg:
                new_args.append(f"{arg}")
                continue
            try:
                argNum = int(arg, 0)
            except ValueError:
                new_args.append(f"{arg}")
                continue

            if info[i] == "Bool":
                new_args.append(f"{'TRUE' if argNum == True else 'FALSE'}")
            elif info[i] == "Hex" and argNum > 0:
                new_args.append(f"0x{argNum:08X}")
            elif info[i] == "CustomAnim":
                if argNum != -1:
                    try:
                        value = argNum & 0x00FFFFFF

                        if func == "SetAnimation" and int(new_args[1], 10) == 0:
                            call = f"{CONSTANTS['PlayerAnims'][argNum]}"
                        elif value in CONSTANTS["NPC_SPRITE"]:
                            self.INCLUDES_NEEDED["sprites"].add(CONSTANTS["NPC_SPRITE"][str(value) + ".h"])
                            call = CONSTANTS["NPC_SPRITE"][value]
                        else:
                            call = f"{argNum:06X}"
                    except ValueError:
                        call = f"0x{argNum:06X}"
                    except KeyError:
                        call = f"0x{argNum:06X}"
                else:
                    call = "-1"
                new_args.append(call)
            elif info[i] == "CustomMsg":
                type_ = (argNum & 0xFF0000) >> 16
                num_ = (argNum & 0xFFFF) >> 0
                new_args.append(f"MESSAGE_ID(0x{type_:02X}, 0x{num_:04X})")
            elif info[i] == "NpcFlags":
                make_flags(argNum, "NpcFlags", new_args)
            elif info[i] == "DamageTypes":
                make_flags(argNum, "DamageTypes", new_args)
            elif info[i] == "ActorPartFlags":
                make_flags(argNum, "ActorPartFlags", new_args)
            elif info[i] == "ActorFlags":
                make_flags(argNum, "ActorFlags", new_args)
            elif info[i] == "BattleStatusFlags1":
                make_flags(argNum, "BattleStatusFlags1", new_args)
            elif info[i] == "BattleStatusFlags2":
                make_flags(argNum, "BattleStatusFlags2", new_args)
            elif info[i] == "StatusFlags":
                make_flags(argNum, "StatusFlags", new_args)
            elif info[i] == "NpcIDs":
                if argNum >= 0:
                    if argNum in CONSTANTS["MAP_NPCS"]:
                        new_args.append(CONSTANTS["MAP_NPCS"][argNum])
                    else:
                        new_args.append(str(argNum))
                else:
                    new_args.append(CONSTANTS["NpcIDs"][argNum])
            elif info[i] == "SoundIDs":
                if argNum in CONSTANTS["SoundIDs"]:
                    new_args.append(CONSTANTS["SoundIDs"][argNum])
                else:
                    new_args.append("0x%X" % argNum)
            elif info[i] == "StoryProgress":
                print(info[i])
                if argNum in CONSTANTS["StoryProgress"]:
                    new_args.append(CONSTANTS["StoryProgress"][argNum])
                else:
                    new_args.append(str(argNum))
            else:
                try:
                    new_args.append(f"{CONSTANTS[info[i]][argNum]}")
                except KeyError:
                    if not (info[i] == "NpcIDs" and argNum > 0):
                        print(
                            f"0x{argNum:X} was not found within {info[i]} constants for function {func} arg {i}, add it."
                        )

                    if info[i] == "ItemIDs" and argNum < 0:
                        new_args.append(f"{int(argNum)}")
                    else:
                        # Print the unknowns in hex
                        new_args.append(self.var(argNum))

        else:
            new_args.append(f"{arg}")
    return ", ".join(new_args)


replace_funcs = {
    "ActorExists": {0: "ActorIDs", 1: "Bool"},
    "ActorSpeak": {0: "CustomMsg", 1: "ActorIDs", 3: "CustomAnim", 4: "CustomAnim"},
    "AddActorDecoration": {0: "ActorIDs"},
    "AddActorVar": {0: "ActorIDs"},
    "AddKeyItem": {0: "ItemIDs"},
    "AddGoalPos": {0: "ActorIDs"},
    "BattleCamTargetActor": {0: "ActorIDs"},
    "BindHandleEvent": {0: "ActorIDs"},
    "BindIdle": {0: "ActorIDs"},
    "BindHandlePhase": {0: "ActorIDs"},
    "BindNpcAI": {0: "NpcIDs"},
    "BindNpcDefeat": {0: "NpcIDs"},
    "BindNpcIdle": {0: "NpcIDs"},
    "BindNpcInteract": {0: "NpcIDs"},
    "BindTakeTurn": {0: "ActorIDs"},
    "CheckButtonDown": {0: "Hex", 1: "Bool"},
    "ContinueSpeech": {1: "CustomAnim", 2: "CustomAnim", 4: "CustomMsg"},
    "CopyBuffs": {0: "ActorIDs", 1: "ActorIDs"},
    "CopyStatusEffects": {0: "ActorIDs", 1: "ActorIDs"},
    "CountPlayerTargets": {0: "ActorIDs"},
    "DisablePlayerInput": {0: "Bool"},
    "DisablePlayerPhysics": {0: "Bool"},
    "DispatchDamagePlayerEvent": {1: "Events"},
    "DispatchEvent": {0: "ActorIDs", 1: "Events"},
    "EnableActorBlur": {0: "ActorIDs"},
    "EnableActorGlow": {0: "ActorIDs", 1: "Bool"},
    "EnableIdleScript": {0: "ActorIDs"},
    "EnableNpcShadow": {0: "NpcIDs", 1: "Bool"},
    "EndActorSpeech": {0: "ActorIDs", 2: "CustomAnim", 3: "CustomAnim"},
    "EndSpeech": {1: "CustomAnim", 2: "CustomAnim"},
    "EnemyDamageTarget": {
        0: "ActorIDs",
        1: "HitResults",
        2: "DamageTypes",
        4: "StatusFlags",
        6: "BattleStatusFlags1",
    },
    "EnemyTestTarget": {
        0: "ActorIDs",
        1: "HitResults",
        2: "DamageTypes",
        3: "StatusFlags",
        5: "BattleStatusFlags1",
    },
    "FallToGoal": {0: "ActorIDs"},
    "FindKeyItem": {0: "ItemIDs"},
    "FlyPartTo": {0: "ActorIDs"},
    "FlyToGoal": {0: "ActorIDs"},
    "ForceHomePos": {0: "ActorIDs"},
    "GetPartAnimNotify": {0: "ActorIDs"},
    "SetActorPaletteEffect": {0: "ActorIDs"},
    "SetActorPaletteSwapParams": {0: "ActorIDs"},
    "EnableActorPaletteEffects": {0: "ActorIDs"},
    "HideHealthBar": {0: "ActorIDs"},
    "func_8027D434": {0: "ActorIDs"},
    "SetProjectileTargetOffset": {0: "ActorIDs"},
    "GetInstigatorValue": {0: "ActorIDs"},
    "SetNpcFoldParams": {0: "NpcIDs"},
    "SetNpcFoldFlags": {0: "NpcIDs"},
    "UpdatePlayerFold": {0: "PlayerAnims"},
    "GetAnimation": {0: "ActorIDs", 2: "CustomAnim"},
    "GetActorFlags": {0: "ActorIDs", 1: "ActorFlags"},
    "GetActorHP": {0: "ActorIDs"},
    "GetActorPos": {0: "ActorIDs"},
    "GetActorSize": {0: "ActorIDs"},
    "GetActorVar": {0: "ActorIDs"},
    "GetBattleFlags": {0: "BattleStatusFlags1"},
    "GetBattlePhase": {0: "Phases"},
    "GetDistanceToGoal": {0: "ActorIDs"},
    "GetEnemyMaxHP": {0: "ActorIDs"},
    "GetGoalPos": {0: "ActorIDs"},
    "GetHomePos": {0: "ActorIDs"},
    "GetIdleGoal": {0: "ActorIDs"},
    "GetIndexFromHome": {0: "ActorIDs"},
    "GetIndexFromPos": {0: "ActorIDs"},
    "GetItemPower": {0: "ItemIDs"},
    "GetLastDamage": {0: "ActorIDs"},
    "GetLastElement": {0: "DamageTypes"},
    "GetLastEvent": {0: "ActorIDs", 1: "Events"},
    "GetPartOffset": {0: "ActorIDs"},
    "GetPartPos": {0: "ActorIDs"},
    "GetPartRotation": {0: "ActorIDs"},
    "GetNpcPos": {0: "NpcIDs"},
    "GetOriginalActorType": {0: "ActorIDs", 1: "ActorType"},
    "GetStatusFlags": {0: "ActorIDs", 1: "StatusFlags"},
    "HidePlayerShadow": {0: "Bool"},
    "HPBarToCurrent": {0: "ActorIDs"},
    "HPBarToHome": {0: "ActorIDs"},
    "IdleFlyToGoal": {0: "ActorIDs"},
    "IdleJumpToGoal": {0: "ActorIDs"},
    "IdleRunToGoal": {0: "ActorIDs"},
    "InterpNpcYaw": {0: "NpcIDs"},
    "JumpPartTo": {0: "ActorIDs"},
    "JumpToGoal": {0: "ActorIDs", 2: "Bool", 3: "Bool", 4: "Bool"},
    "JumpWithBounce": {0: "ActorIDs"},
    "LandJump": {0: "ActorIDs"},
    "LoadActionCommand": {0: "ActionCommand"},
    "MakeEntity": {0: "Hex"},
    "MakeItemEntity": {0: "ItemIDs"},
    "ModifyColliderFlags": {2: "Hex"},
    "NpcFaceNpc": {0: "NpcIDs", 1: "NpcIDs"},
    "NpcFacePlayer": {0: "NpcIDs"},
    "NpcJump0": {0: "NpcIDs"},
    "NpcJump1": {0: "NpcIDs"},
    "NpcMoveTo": {0: "NpcIDs"},
    "PlayAmbientSounds": {0: "AmbientSounds"},
    "PlayEffect": {0: "EffectID"},
    "PlayLoopingSoundAtActor": {0: "ActorIDs", 2: "SoundIDs"},
    "PlaySound": {0: "SoundIDs"},
    "PlaySoundAt": {0: "SoundIDs"},
    "PlaySoundAtActor": {0: "ActorIDs", 1: "SoundIDs"},
    "PlaySoundAtModel": {1: "SoundIDs"},
    "PlaySoundAtNpc": {0: "NpcIDs", 1: "SoundIDs"},
    "PlaySoundAtPart": {0: "ActorIDs", 2: "SoundIDs"},
    "RemoveActor": {0: "ActorIDs"},
    "RemoveActorDecoration": {0: "ActorIDs"},
    "RemoveNpc": {0: "NpcIDs"},
    "ResetActorSounds": {0: "ActorIDs"},
    "ResetAllActorSounds": {0: "ActorIDs"},
    "RunToGoal": {0: "ActorIDs", 2: "Bool"},
    "SetActorDispOffset": {0: "ActorIDs"},
    "SetActorFlagBits": {0: "ActorIDs", 1: "ActorFlags"},
    "SetActorIdleSpeed": {0: "ActorIDs"},
    "SetActorIdleJumpGravity": {0: "ActorIDs"},
    "SetActorJumpGravity": {0: "ActorIDs"},
    "SetActorPos": {0: "ActorIDs"},
    "SetActorRotation": {0: "ActorIDs"},
    "SetActorRotationOffset": {0: "ActorIDs"},
    "SetActorScale": {0: "ActorIDs"},
    "SetActorSize": {0: "ActorIDs"},
    "SetActorSounds": {0: "ActorIDs"},
    "SetActorSpeed": {0: "ActorIDs"},
    "SetActorType": {0: "ActorIDs", 1: "ActorType"},
    "SetActorVar": {0: "ActorIDs"},
    "SetActorYaw": {0: "ActorIDs"},
    "SetAnimation": {0: "ActorIDs", 2: "CustomAnim"},
    "SetAnimationRate": {0: "ActorIDs"},
    "SetBattleFlagBits": {0: "BattleStatusFlags1"},
    "SetBattleFlagBits2": {0: "BattleStatusFlags2"},
    "SetDefenseTable": {0: "ActorIDs"},
    "SetEnemyHP": {0: "ActorIDs"},
    "SetEnemyTargetOffset": {0: "ActorIDs"},
    "SetGoalPos": {0: "ActorIDs"},
    "SetGoalToFirstTarget": {0: "ActorIDs"},
    "SetGoalToHome": {0: "ActorIDs"},
    "SetGoalToIndex": {0: "ActorIDs"},
    "SetGoalToTarget": {0: "ActorIDs"},
    "SetHomePos": {0: "ActorIDs"},
    "SetIdleAnimations": {0: "ActorIDs"},
    "SetIdleGoal": {0: "ActorIDs"},
    "SetIdleGoalToHome": {0: "ActorIDs"},
    "SetJumpAnimations": {
        0: "ActorIDs",
        2: "PlayerAnims",
        3: "PlayerAnims",
        4: "PlayerAnims",
    },
    "SetMusicTrack": {1: "SongIDs"},
    "SetNpcAnimation": {0: "NpcIDs", 1: "CustomAnim"},
    "SetNpcAux": {0: "NpcIDs"},
    "SetNpcFlagBits": {0: "NpcIDs", 1: "NpcFlags", 2: "Bool"},
    "SetNpcJumpscale": {0: "NpcIDs"},
    "SetNpcPos": {0: "NpcIDs"},
    "SetNpcRotation": {0: "NpcIDs"},
    "SetNpcScale": {0: "NpcIDs"},
    "SetNpcSpeed": {0: "NpcIDs"},
    "SetNpcSprite": {1: "Hex"},
    "SetNpcYaw": {0: "NpcIDs"},
    "SetOwnerID": {0: "ActorIDs"},
    "SetPartAlpha": {0: "ActorIDs"},
    "SetPartDispOffset": {0: "ActorIDs"},
    "SetPartEventBits": {0: "ActorIDs", 2: "ActorEventFlags"},
    "SetPartFlags": {0: "ActorIDs", 2: "ActorPartFlags"},
    "SetPartFlagBits": {0: "ActorIDs", 2: "ActorPartFlags"},
    "SetPartJumpGravity": {0: "ActorIDs"},
    "SetPartMoveSpeed": {0: "ActorIDs"},
    "SetPartPos": {0: "ActorIDs"},
    "SetPartRotation": {0: "ActorIDs"},
    "SetPartRotationOffset": {0: "ActorIDs"},
    "SetPartScale": {0: "ActorIDs"},
    "SetPartSize": {0: "ActorIDs"},
    "SetPartSounds": {0: "ActorIDs"},
    "SetPartTargetFlagBits": {0: "ActorIDs"},
    "SetPartYaw": {0: "ActorIDs"},
    "SetPlayerAnimation": {0: "PlayerAnims"},
    "SetSelfEnemyFlagBits": {0: "NpcFlags", 1: "Bool"},
    # "SetSelfVar"                :{1:"Bool"}, # apparently this was a bool in some scripts but it passes non-0/1 values, including negatives
    "SetSpriteShading": {0: "CustomAnim"},
    "SetStatusTable": {0: "ActorIDs"},
    "SetTargetActor": {0: "ActorIDs", 1: "ActorIDs"},
    "SetTargetOffset": {0: "ActorIDs"},
    "ShowChoice": {0: "CustomMsg"},
    "ShowEmote": {1: "Emotes"},
    "ShowMessageAtScreenPos": {0: "CustomMsg"},
    "ShowMessageAtWorldPos": {0: "CustomMsg"},
    "SpeakToPlayer": {0: "NpcIDs", 1: "CustomAnim", 2: "CustomAnim", -1: "CustomMsg"},
    "StopLoopingSoundAtActor": {0: "ActorIDs"},
    "SwitchMessage": {0: "CustomMsg"},
    "UseBattleCamPreset": {0: "BtlCameraPreset"},
    "UseIdleAnimation": {0: "ActorIDs", 1: "Bool"},
    "WasStatusInflicted": {0: "ActorIDs", 1: "Bool"},
}


def trim_lw(arg):
    return arg[arg.find("(") + 1 : arg.find(")")]


def replace_constants(self, func, args):
    global replace_funcs
    global LOCAL_WORDS

    new_args = []
    new_args = args.split(", ")
    for i, new_arg in enumerate(new_args):
        if new_arg.startswith("LW"):
            new_arg = trim_lw(new_arg)
            LOCAL_WORDS[int(new_arg)] = 0

    if func in replace_funcs:
        return fix_args(self, func, args, replace_funcs[func])

    return args


def fix_1_arg(self, lw, arg, format):
    if lw:
        lw = int(trim_lw(lw))
        if LOCAL_WORDS[lw]:
            info = {0: LOCAL_WORDS[lw]}
            args = f"{arg}"
            return fix_args(self, 0, args, info)

    if format:
        info = {0: format}
        args = f"{arg}"
        return fix_args(self, 0, args, info)

    return arg


class ScriptDisassembler:
    def __init__(
        self,
        bytes,
        script_name="script",
        symbol_map={},
        romstart=0,
        INCLUDES_NEEDED={"forward": [], "sprites": set(), "npcs": []},
        INCLUDED={"functions": set(), "includes": set()},
        prelude=True,
        transform_symbol_name=None,
        use_script_lib=True,
    ):
        self.bytes = bytes
        self.script_name = script_name
        self.prelude = prelude

        if use_script_lib:
            self.symbol_map = extend_symbol_map(symbol_map, script_lib(self.bytes.tell()))
        else:
            self.symbol_map = symbol_map

        self.romstart = romstart
        self.transform_symbol_name = transform_symbol_name
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

            # print(f"Op {opcode:X}, argc {argc}")

            if opcode > 0xFF or argc > 0xFF:
                raise Exception(f"script '{self.script_name}' is malformed (opcode {opcode:X}, argc {argc:X})")

            argv = []
            for i in range(0, argc):
                argv.append(self.read_word())

            # print(argv)

            self.disassemble_command(opcode, argc, argv)

            self.instructions += 1

            if self.done:
                self.end_pos = self.bytes.tell()
                return self.prefix + self.out

    def write(self, line):
        if self.indent < 0:
            self.indent = 0
        if self.indent > 1:
            self.indent_used = True

        self.out += "    " * self.indent
        self.out += line

    def write_line(self, line):
        self.write(line)
        self.out += "\n"

    def prefix_line(self, line):
        self.prefix += line
        self.prefix += "\n"

    def var(self, arg, prefer_hex=False, use_evt_ptr=True):
        if arg in self.symbol_map:
            s = self.symbol_map[arg][0][1]
            return f"EVT_PTR({s})" if use_evt_ptr else s

        v = arg - 2**32  # convert to s32
        if v > -250000000:
            if v <= -220000000:
                return f"EVT_FLOAT({round_fixed((v + 230000000) / 1024)})"
            elif v <= -200000000:
                return f"ArrayFlag({v + 210000000})"
            elif v <= -180000000:
                return f"ArrayVar({v + 190000000})"
            elif v <= -160000000:
                return f"GameByte({v + 170000000})"
            elif v <= -140000000:
                return f"AreaByte({v + 150000000})"
            elif v <= -120000000:
                return f"GameFlag({v + 130000000})"
            elif v <= -100000000:
                return f"AreaFlag({v + 110000000})"
            elif v <= -80000000:
                return f"MapFlag({v + 90000000})"
            elif v <= -60000000:
                return f"LocalFlag({v + 70000000})"
            elif v <= -40000000:
                return f"MapVar({v + 50000000})"
            elif v <= -20000000:
                return f"LocalVar({v + 30000000})"

        if arg == 0xFFFFFFFF:
            return "-1"
        elif (arg & 0xFF000000) == 0x80000000:
            return f"0x{arg:X}"
        elif arg >= 0x80000000:
            return f"{arg - 0x100000000}"
        elif prefer_hex and arg > 0:
            return f"0x{arg:X}"
        else:
            return f"{arg}"

    def replace_star_rod_function_name(self, name):
        vram = int(name.split("_", 1)[1], 16)
        name = "N(" + name.replace("function", "func") + f"_{(vram - 0x80240000)+self.romstart:X}" + ")"
        return name

    def replace_star_rod_prefix(self, addr, isArg=False):
        if type(addr) is str:
            return addr
        if addr > 0x80000000 and addr in self.symbol_map:
            name = find_symbol_in_overlay(self.symbol_map, self.romstart, addr)
            if self.transform_symbol_name:
                name = self.transform_symbol_name(name)
            toReplace = True
            suffix = ""
            if False and name.startswith("N(func_"):
                prefix = "ApiStatus "
                name = self.replace_star_rod_function_name(name[2:-1])
                suffix = "(Evt* script, s32 isInitialCall)"
            elif name[2:-1] in self.INCLUDED["includes"]:
                prefix = "ApiStatus "
                suffix = "(Evt* script, s32 isInitialCall)"
            elif name.startswith("N(npcAISettings_"):
                prefix = "MobileAISettings "
            elif name.startswith("N(npcSettings_"):
                prefix = "NpcSettings "
            elif name.startswith("N(npcGroup_"):
                prefix = "NpcData "
            elif name.startswith("N(entryList_"):
                prefix = "EntryList "
            elif name.startswith("N(npcGroupList_"):
                prefix = "NpcGroupList "
            elif name.startswith("N("):
                prefix = "EvtScript "
            else:
                toReplace = False

            if toReplace:
                if name not in self.INCLUDED["functions"]:
                    self.INCLUDES_NEEDED["forward"].append(prefix + name + suffix + ";")
                    self.INCLUDED["functions"].add(name)
                return name
            elif not isArg or name.startswith('"'):
                return name
            else:
                return str(addr)
        return addr

    def addr_ref(self, addr, isArg=False):
        if addr in self.symbol_map:
            return self.replace_star_rod_prefix(addr, isArg)
        return self.var(addr)  # f"0x{addr:08X}"

    def trigger(self, trigger):
        if trigger == 0x00000040:
            trigger = "TRIGGER_WALL_PUSH"
        if trigger == 0x00000080:
            trigger = "TRIGGER_FLOOR_TOUCH"
        if trigger == 0x00000100:
            trigger = "TRIGGER_WALL_PRESS_A"
        if trigger == 0x00000200:
            trigger = "TRIGGER_FLOOR_JUMP"
        if trigger == 0x00000400:
            trigger = "TRIGGER_WALL_TOUCH"
        if trigger == 0x00000800:
            trigger = "TRIGGER_FLOOR_PRESS_A"
        if trigger == 0x00001000:
            trigger = "TRIGGER_WALL_HAMMER"
        if trigger == 0x00010000:
            trigger = "TRIGGER_GAME_FLAG_SET"
        if trigger == 0x00020000:
            trigger = "TRIGGER_AREA_FLAG_SET"
        if trigger == 0x00040000:
            trigger = "TRIGGER_CEILING_TOUCH"
        if trigger == 0x00080000:
            trigger = "TRIGGER_FLOOR_ABOVE"
        if trigger == 0x00100000:
            trigger = "TRIGGER_POINT_BOMB"
        return f"0x{trigger:X}" if type(trigger) is int else trigger

    def read_word(self):
        return int.from_bytes(self.bytes.read(4), byteorder="big")

    def disassemble_command(self, opcode, argc, argv):
        if opcode == 0x01:
            self.write_line("EVT_END")
            self.indent -= 1

            if self.prelude:
                try:
                    self.prefix_line(
                        f"EvtScript D_{self.script_name - info[0] + info[2]:08X}_{self.script_name:06X} = {{"
                    )
                    self.write_line("};")
                except:
                    self.prefix_line(f"EvtScript {self.script_name} = {{")
                    self.write_line("};")
            self.done = True
        elif opcode == 0x02:
            self.write_line(f"EVT_RETURN")
        elif opcode == 0x03:
            self.write_line(f"EVT_LABEL({self.var(argv[0])})")
        elif opcode == 0x04:
            self.write_line(f"EVT_GOTO({self.var(argv[0])})")
        elif opcode == 0x05:
            self.write_line(f"EVT_LOOP({self.var(argv[0])})")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("EVT_END_LOOP")
        elif opcode == 0x07:
            self.write_line(f"EVT_BREAK_LOOP")
        elif opcode == 0x08:
            self.write_line(f"EVT_WAIT({self.var(argv[0])})")
        elif opcode == 0x09:
            self.write_line(f"EVT_WAIT_SECS({self.var(argv[0])})")
        elif opcode == 0x0A:
            if self.var(argv[0]).startswith("LW"):
                args_str = fix_1_arg(self, self.var(argv[0]), self.var(argv[1]), 0)
            else:
                args_str = self.var(argv[1])
            self.write_line(f"EVT_IF_EQ({self.var(argv[0])}, {args_str})")
            self.indent += 1
        elif opcode == 0x0B:
            if self.var(argv[0]).startswith("LW"):
                args_str = fix_1_arg(self, self.var(argv[0]), self.var(argv[1]), 0)
            else:
                args_str = self.var(argv[1])
            self.write_line(f"EVT_IF_NE({self.var(argv[0])}, {args_str})")
            self.indent += 1
        elif opcode == 0x0C:
            self.write_line(f"EVT_IF_LT({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0D:
            self.write_line(f"EVT_IF_GT({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0E:
            self.write_line(f"EVT_IF_LE({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x0F:
            self.write_line(f"EVT_IF_GE({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x10:
            args_str = fix_1_arg(self, self.var(argv[0]), self.var(argv[1]), "Hex")
            self.write_line(f"EVT_IF_FLAG({self.var(argv[0])}, {args_str})")
            self.indent += 1
        elif opcode == 0x11:
            args_str = fix_1_arg(self, self.var(argv[0]), self.var(argv[1]), "Hex")
            self.write_line(f"EVT_IF_NOT_FLAG({self.var(argv[0])}, {args_str})")
            self.indent += 1
        elif opcode == 0x12:
            self.indent -= 1
            self.write_line(f"EVT_ELSE")
            self.indent += 1
        elif opcode == 0x13:
            self.indent -= 1
            self.write_line(f"EVT_END_IF")
        elif opcode == 0x14:
            new_arg = trim_lw(self.var(argv[0]))
            SWITCH_TYPES.append(LOCAL_WORDS[int(new_arg)])
            self.write_line(f"EVT_SWITCH({self.var(argv[0])})")
            self.indent += 2
        elif opcode == 0x15:
            self.write_line(f"EVT_SWITCH_CONST(0x{argv[0]:X})")
            self.indent += 2
        elif opcode == 0x16:
            self.indent -= 1
            args_str = fix_1_arg(self, 0, self.var(argv[0]), SWITCH_TYPES[-1])
            self.write_line(f"EVT_CASE_EQ({args_str})")
            self.indent += 1
        elif opcode == 0x17:
            self.indent -= 1
            args_str = fix_1_arg(self, 0, self.var(argv[0]), SWITCH_TYPES[-1])
            self.write_line(f"EVT_CASE_NE({args_str})")
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
            args_str = fix_1_arg(self, 0, self.var(argv[0]), SWITCH_TYPES[-1])
            self.write_line(f"EVT_CASE_OR_EQ({args_str})")
            self.indent += 1
        elif opcode == 0x1E:
            self.indent -= 1
            args_str = fix_1_arg(self, 0, self.var(argv[0]), SWITCH_TYPES[-1])
            self.write_line(f"EVT_CASE_AND_EQ({args_str})")
            self.indent += 1
        elif opcode == 0x1F:
            self.indent -= 1
            args_str = fix_1_arg(self, 0, self.var(argv[0]), SWITCH_TYPES[-1])
            self.write_line(f"EVT_CASE_FLAG({args_str})")
            self.indent += 1
        elif opcode == 0x20:
            self.indent -= 1
            self.write_line(f"EVT_END_CASE_GROUP")
            self.indent += 1
        elif opcode == 0x21:
            self.indent -= 1
            self.write_line(f"EVT_CASE_RANGE({self.var(argv[0])}, {self.var(argv[1])})")
            self.indent += 1
        elif opcode == 0x22:
            self.write_line(f"EVT_BREAK_SWITCH")
        elif opcode == 0x23:
            self.indent -= 2
            del SWITCH_TYPES[-1]
            self.write_line(f"EVT_END_SWITCH")
        elif opcode == 0x24:
            if self.var(argv[0]).startswith("LW"):
                new_arg = trim_lw(self.var(argv[0]))
                if self.var(argv[1]).startswith("LW"):
                    from_arg = trim_lw(self.var(argv[1]))  # Carry type info of LW if being set from an LW
                else:
                    from_arg = 0  # If a constant, we no longer know the type
                LOCAL_WORDS[int(new_arg)] = LOCAL_WORDS[int(from_arg)]

            self.write_line(f"EVT_SET({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x25:
            argNum = argv[1]
            sprite = (argNum & 0xFF0000) >> 16
            palette = (argNum & 0xFF00) >> 8
            anim = (argNum & 0xFF) >> 0
            if sprite > 0:
                value = make_anim_macro(self, sprite, palette, anim)
            elif argNum > 100:
                value = f"0x{argNum:08X}"
            else:
                value = f"{argNum}"
            self.write_line(f"EVT_SET_CONST({self.var(argv[0])}, {value})")
        elif opcode == 0x26:
            self.write_line(f"EVT_SETF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x27:
            self.write_line(f"EVT_ADD({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x28:
            self.write_line(f"EVT_SUB({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x29:
            self.write_line(f"EVT_MUL({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2A:
            self.write_line(f"EVT_DIV({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2B:
            self.write_line(f"EVT_MOD({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2C:
            self.write_line(f"EVT_ADDF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2D:
            self.write_line(f"EVT_SUBF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2E:
            self.write_line(f"EVT_MULF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x2F:
            self.write_line(f"EVT_DIVF({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x30:
            self.write_line(f"EVT_USE_BUF({self.var(argv[0])})")
        elif opcode == 0x31 or opcode == 0x32 or opcode == 0x33 or opcode == 0x34:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_BUF_READ{opcode - 0x30}({', '.join(args)})")
        elif opcode == 0x35:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_BUF_PEEK({', '.join(args)})")
        elif opcode == 0x36:
            self.write_line(f"EVT_USE_FBUF({self.var(argv[0])})")
        elif opcode == 0x37 or opcode == 0x38 or opcode == 0x39 or opcode == 0x3A:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_FBUF_READ{opcode - 0x36}({', '.join(args)})")
        elif opcode == 0x3B:
            args = [*map(self.var, argv)]
            self.write_line(f"EVT_FBUF_PEEK({', '.join(args)})")
        elif opcode == 0x3C:
            self.write_line(f"EVT_USE_ARRAY({self.var(argv[0])})")
        elif opcode == 0x3D:
            self.write_line(f"EVT_USE_FLAG_ARRAY({self.var(argv[0])})")
        elif opcode == 0x3E:
            self.write_line(f"EVT_MALLOC_ARRAY({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x3F:
            self.write_line(f"EVT_BITWISE_AND({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x40:
            self.write_line(f"EVT_BITWISE_AND_CONST({self.var(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x41:
            self.write_line(f"EVT_BITWISE_OR({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x42:
            self.write_line(f"EVT_BITWISE_OR_CONST({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x43:
            func = self.addr_ref(argv[0])
            args = [self.var(a, use_evt_ptr=True) for a in argv[1:]]
            args_str = ", ".join(args)
            args_str = replace_constants(self, func, args_str)
            if func.startswith("evt_"):
                # use func-specific macro
                self.write_line(f"{func}({args_str})")
            # Since the map ascii for map transitions is global, and several of them share the same RAM address,
            # or ar not migrated, we have to create a placeholder
            elif func == "GotoMap" or func == "GotoMapSpecial":
                args = [self.var(a, use_evt_ptr=True) for a in argv[2:]]
                args_str = ", ".join(args)
                self.write_line(f"EVT_CALL({func}, EVT_PTR(UNK_STR_{argv[1]:X}), {args_str})")
            elif args_str:
                self.write_line(f"EVT_CALL({func}, {args_str})")
            else:
                self.write_line(f"EVT_CALL({func})")  # no args
        elif opcode == 0x44:
            self.write_line(f"EVT_EXEC({self.addr_ref(argv[0])})")
        elif opcode == 0x45:
            self.write_line(f"EVT_EXEC_GET_TID({self.addr_ref(argv[0])}, {self.var(argv[1])})")
        elif opcode == 0x46:
            self.write_line(f"EVT_EXEC_WAIT({self.addr_ref(argv[0])})")
        elif opcode == 0x47:
            args = [
                self.addr_ref(argv[0]),
                self.trigger(argv[1]),
                self.collider_id(argv[2]),
                *map(self.var, argv[3:]),
            ]
            self.write_line(f"EVT_BIND_TRIGGER({', '.join(args)})")
        elif opcode == 0x48:
            self.write_line(f"EVT_UNBIND")
        elif opcode == 0x49:
            self.write_line(f"EVT_KILL_THREAD({self.var(argv[0])})")
        elif opcode == 0x4A:
            self.write_line(f"EVT_JUMP({self.var(argv[0])})")
        elif opcode == 0x4B:
            self.write_line(f"EVT_SET_PRIORITY({self.var(argv[0])})")
        elif opcode == 0x4C:
            self.write_line(f"EVT_SET_TIMESCALE({self.var(argv[0])})")
        elif opcode == 0x4D:
            self.write_line(f"EVT_SET_GROUP({self.var(argv[0])})")
        elif opcode == 0x4E:
            args = [
                self.addr_ref(argv[0]),
                self.trigger(argv[1]),
                self.collider_id(argv[2]),
                *map(self.var, argv[3:]),
            ]
            self.write_line(f"EVT_BIND_PADLOCK({', '.join(args)})")
        elif opcode == 0x4F:
            self.write_line(f"EVT_SUSPEND_GROUP({self.var(argv[0])})")
        elif opcode == 0x50:
            self.write_line(f"EVT_RESUME_GROUP({self.var(argv[0])})")
        elif opcode == 0x51:
            self.write_line(f"EVT_SUSPEND_OTHERS({self.var(argv[0])})")
        elif opcode == 0x52:
            self.write_line(f"EVT_RESUME_OTHERS({self.var(argv[0])})")
        elif opcode == 0x53:
            self.write_line(f"EVT_SUSPEND_THREAD({self.var(argv[0])})")
        elif opcode == 0x54:
            self.write_line(f"EVT_RESUME_THREAD({self.var(argv[0])})")
        elif opcode == 0x55:
            self.write_line(f"EVT_IS_THREAD_RUNNING({self.var(argv[0])}, {self.var(argv[1])})")
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

    def collider_id(self, arg):
        if arg >= 0x4000 and arg <= 0x5000:
            return f"EVT_ENTITY_INDEX({arg - 0x4000})"
        else:
            return self.var(arg)


class UnsupportedScript(Exception):
    pass


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, help="File to dissassemble from")
    parser.add_argument("offset", help="Offset to start dissassembling from")
    parser.add_argument(
        "-end",
        "-e",
        "--e",
        type=lambda x: int(x, 16),
        default=0,
        dest="end",
        required=False,
        help="End offset to stop dissassembling from.\nOnly used as a way to find valid scripts.",
    )
    parser.add_argument(
        "-vram",
        "-v",
        "--v",
        type=lambda x: int(x, 16),
        default=0,
        dest="vram",
        required=False,
        help="VRAM start will be tracked and used for the script output name",
    )
    parser.add_argument(
        "-si",
        "--si",
        action="store_true",
        default=False,
        dest="si",
        required=False,
        help="Force si script output",
    )
    parser.add_argument(
        "-blob",
        "--b",
        action="store_true",
        default=False,
        dest="blob",
        required=False,
        help="If there is a blob of scripts.",
    )
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
    try:
        offset = int(args.offset, 0)
    except ValueError:
        info = sym_info.search_symbol(args.offset)
        if info is None:
            print(f"{args.offset} is not a valid symbol name")
            exit(1)
        offset = info[0]
    if args.end > offset:
        # Search the given memory range and report scripts
        with open(args.file, "rb") as f:
            gap = False
            first_print = False
            while offset < args.end:
                f.seek(offset)
                script = ScriptDisassembler(f, args.offset, {}, 0x978DE0, INCLUDES_NEEDED, INCLUDED)
                try:
                    script_text = script.disassemble()
                    if script.instructions > 1 and "_EVT_CMD" not in script_text:
                        if gap and first_print:
                            potential_struct_sizes = {
                                "NpcData": 0x1F0,
                                "MobileAISettings": 0x30,
                                "NpcSettings": 0x2C,
                                "NpcGroupList": 0xC,
                            }
                            gap_size = offset - gap_start
                            potential_struct = "Unknown data"
                            potential_count = 1
                            for k, v in potential_struct_sizes.items():
                                if gap_size % v == 0:
                                    potential_struct = k
                                    potential_count = gap_size // v
                            print(
                                f"========== 0x{gap_size:X} byte gap ({potential_count} {potential_struct}?) 0x{gap_start:X} - 0x{offset:X} =========="
                            )
                            print()
                            gap = False
                        # print(f"EvtScript read from 0x{script.start_pos:X} to 0x{script.end_pos:X} "
                        #      f"(0x{script.end_pos - script.start_pos:X} bytes, {script.instructions} instructions)")
                        # print()
                        vram = f"{args.vram:X}_" if vram_base > 0 else f""
                        script_text = script_text.replace(
                            "EvtScript script = SCRIPT({",
                            f"EvtScript N(D_{vram}{offset:X}) = " + "SCRIPT({",
                        )
                        print(script_text, end="")
                        print()
                        # print(f"Valid script found at 0x{offset:X}")
                        args.vram += script.end_pos - offset
                        offset = script.end_pos
                        first_print = True
                    else:
                        if not gap:
                            gap_start = offset
                            gap = True
                        offset += 4
                        args.vram += 4
                except Exception:
                    if not gap:
                        gap_start = offset
                        gap = True
                    offset += 4
                    args.vram += 4
    else:
        with open(args.file, "rb") as f:
            f.seek(offset)
            loffset = args.offset
            looping = 1
            while looping:
                try:
                    script = ScriptDisassembler(f, loffset, {}, 0x978DE0, INCLUDES_NEEDED, INCLUDED)

                    if args.si:
                        print(
                            ScriptDisassembler(f, loffset, {}, 0x978DE0, INCLUDES_NEEDED, INCLUDED).disassemble(),
                            end="",
                        )
                    else:
                        try:
                            script_text = script.disassemble()

                            # print(f"EvtScript read from 0x{script.start_pos:X} to 0x{script.end_pos:X} "
                            #     f"(0x{script.end_pos - script.start_pos:X} bytes, {script.instructions} instructions)")
                            print()
                            print(script_text, end="")

                        except UnsupportedScript:
                            f.seek(offset)
                            print(ScriptDisassembler(f).disassemble(), end="")
                            break
                except Exception as e:
                    print(e)

                loffset = script.end_pos
                LOCAL_WORDS = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
                looping = args.blob
                try:
                    loffset = _script_lib[loffset - info[0] + info[2]][0][1]
                except:
                    pass
