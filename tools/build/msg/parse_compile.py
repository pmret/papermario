#! /usr/bin/python3

from sys import argv
from collections import OrderedDict
import re
import msgpack # way faster than pickle

class Message:
    def __init__(self, name, section, index):
        self.name = name
        self.section = section
        self.index = index

        self.bytes = [] # XXX: bytearray would be better

def try_convert_int(s):
    try:
        return int(s, base=0)
    except:
        return s

def parse_command(source):
    if source[0] != "[":
        return None, [], {}, source
    source = source[1:] # "["

    inside_brackets = ""
    while source[0] != "]":
        if source[0] == "\n":
            return None, [], {}, source

        inside_brackets += source[0]
        source = source[1:]
    source = source[1:] # "]"

    command, *raw_args = inside_brackets.split(" ")

    args = []
    named_args = {}

    for arg in raw_args:
        if "=" in arg:
            key, value = arg.split("=", 1)

            if "," in value:
                named_args[key.lower()] = [try_convert_int(v) for v in value.lower().split(",")]
            else:
                named_args[key.lower()] = try_convert_int(value.lower())
        else:
            if "," in arg:
                args.append([try_convert_int(value) for value in arg.lower().split(",")])
            else:
                args.append(try_convert_int(arg.lower()))

    # args = []
    # for arg in raw_args:
    #     args.append(try_convert_int(arg.lower()))

    return command.lower(), args, named_args, source

def color_to_code(color, style):
    COLORS = {
        "diary": {
            "normal": 0x00,
            "red": 0x07,
        },
        "inspect": {
            "dark": 0x17,
        },
        "button": {
            "blue": 0x10,
            "green": 0x11,
            "red": 0x12,
            "yellow": 0x13,
            "gray": 0x14,
            "grey": 0x14,
        },
        "popup": {
            "red": 0x28,
            "pink": 0x29,
            "purple": 0x2A,
            "blue": 0x2B,
            "teal": 0x2C,
            "green": 0x2D,
            "yellow": 0x2E,
            "normal": 0x2F,
        },
        "sign": {
            "normal": 0x18,
            "red": 0x19,
            "blue": 0x1A,
            "green": 0x1B,
        }
    }

    if type(color) is int:
        return color

    return COLORS.get(style, {
        # [style:left], [style:right]
        "normal": 0x0A,
        "red": 0x20,
        "pink": 0x21,
        "purple": 0x22,
        "blue": 0x23,
        "cyan": 0x24,
        "green": 0x25,
        "yellow": 0x26,
    }).get(color)

CHARSET = {
    #"𝅘𝅥𝅮": 0x00,
    "!": 0x01,
    '"': 0x02,
    "#": 0x03,
    "$": 0x04,
    "%": 0x05,
    "&": 0x06,
    "'": 0x07,
    "(": 0x08,
    ")": 0x09,
    "*": 0x0A,
    "+": 0x0B,
    ",": 0x0C,
    "-": 0x0D,
    ".": 0x0E,
    "/": 0x0F,
    "0": 0x10,
    "1": 0x11,
    "2": 0x12,
    "3": 0x13,
    "4": 0x14,
    "5": 0x15,
    "6": 0x16,
    "7": 0x17,
    "8": 0x18,
    "9": 0x19,
    ":": 0x1A,
    ";": 0x1B,
    "<": 0x1C,
    "=": 0x1D,
    ">": 0x1E,
    "?": 0x1F,
    "@": 0x20,
    "A": 0x21,
    "B": 0x22,
    "C": 0x23,
    "D": 0x24,
    "E": 0x25,
    "F": 0x26,
    "G": 0x27,
    "H": 0x28,
    "I": 0x29,
    "J": 0x2A,
    "K": 0x2B,
    "L": 0x2C,
    "M": 0x2D,
    "N": 0x2E,
    "O": 0x2F,
    "P": 0x30,
    "Q": 0x31,
    "R": 0x32,
    "S": 0x33,
    "T": 0x34,
    "U": 0x35,
    "V": 0x36,
    "W": 0x37,
    "X": 0x38,
    "Y": 0x39,
    "Z": 0x3A,
    "[": 0x3B,
    "¥": 0x3C,
    "]": 0x3D,
    "^": 0x3E,
    "_": 0x3F,
    "`": 0x40,
    "a": 0x41,
    "b": 0x42,
    "c": 0x43,
    "d": 0x44,
    "e": 0x45,
    "f": 0x46,
    "g": 0x47,
    "h": 0x48,
    "i": 0x49,
    "j": 0x4A,
    "k": 0x4B,
    "l": 0x4C,
    "m": 0x4D,
    "n": 0x4E,
    "o": 0x4F,
    "p": 0x50,
    "q": 0x51,
    "r": 0x52,
    "s": 0x53,
    "t": 0x54,
    "u": 0x55,
    "v": 0x56,
    "w": 0x57,
    "x": 0x58,
    "y": 0x59,
    "z": 0x5A,
    "{": 0x5B,
    "|": 0x5C,
    "}": 0x5D,
    "~": 0x5E,
    "°": 0x5F,
    "À": 0x60,
    "Á": 0x61,
    "Â": 0x62,
    "Ä": 0x63,
    "Ç": 0x64,
    "È": 0x65,
    "É": 0x66,
    "Ê": 0x67,
    "Ë": 0x68,
    "Ì": 0x69,
    "Í": 0x6A,
    "Î": 0x6B,
    "Ï": 0x6C,
    "Ñ": 0x6D,
    "Ò": 0x6E,
    "Ó": 0x6F,
    "Ô": 0x70,
    "Ö": 0x71,
    "Ù": 0x72,
    "Ú": 0x73,
    "Û": 0x74,
    "Ü": 0x75,
    "ß": 0x76,
    "à": 0x77,
    "á": 0x78,
    "â": 0x79,
    "ä": 0x7A,
    "ç": 0x7B,
    "è": 0x7C,
    "é": 0x7D,
    "ê": 0x7E,
    "ë": 0x7F,
    "ì": 0x80,
    "í": 0x81,
    "î": 0x82,
    "ï": 0x83,
    "ñ": 0x84,
    "ò": 0x85,
    "ó": 0x86,
    "ô": 0x87,
    "ö": 0x88,
    "ù": 0x89,
    "ú": 0x8A,
    "û": 0x8B,
    "ü": 0x8C,
    "¡": 0x8D,
    "¿": 0x8E,
    "ª": 0x8F,
    # "♥": 0x90,
    # "★": 0x91,
    # "↑": 0x92,
    # "↓": 0x93,
    # "←": 0x94,
    # "→": 0x95,
    # "●": 0x96,
    # "✖": 0x97,
    "“": 0xA2,
    "”": 0xA3,
    "‘": 0xA4,
    "’": 0xA5,
    " ": 0xF7,
    # "Ⓐ": [0xFF, 0x24, 0xFF, 0x05, 0x10, 0x98, 0xFF, 0x25],
    # "Ⓑ": [0xFF, 0x24, 0xFF, 0x05, 0x11, 0x99, 0xFF, 0x25],
    # "Ⓢ": [0xFF, 0x24, 0xFF, 0x05, 0x12, 0xA1, 0xFF, 0x25],
    # "▲": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0x9D, 0xFF, 0x25],
    # "▼": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0x9E, 0xFF, 0x25],
    # "◀": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0x9F, 0xFF, 0x25],
    # "▶": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0xA0, 0xFF, 0x25],
    # "Ⓛ": [0xFF, 0x24, 0xFF, 0x05, 0x14, 0x9A, 0xFF, 0x25],
    # "Ⓡ": [0xFF, 0x24, 0xFF, 0x05, 0x14, 0x9B, 0xFF, 0x25],
    # "Ⓩ": [0xFF, 0x24, 0xFF, 0x05, 0x14, 0x9C, 0xFF, 0x25],
}

CHARSET_CREDITS = {
    "A": 0x00,
    "B": 0x01,
    "C": 0x02,
    "D": 0x03,
    "E": 0x04,
    "F": 0x05,
    "G": 0x06,
    "H": 0x07,
    "I": 0x08,
    "J": 0x09,
    "K": 0x0A,
    "L": 0x0B,
    "M": 0x0C,
    "N": 0x0D,
    "O": 0x0E,
    "P": 0x0F,
    "Q": 0x10,
    "R": 0x11,
    "S": 0x12,
    "T": 0x13,
    "U": 0x14,
    "V": 0x15,
    "W": 0x16,
    "X": 0x17,
    "Y": 0x18,
    "Z": 0x19,
    "'": 0x1A,
    ".": 0x1B,
    ",": 0x1C,
    "0": 0x1D,
    "1": 0x1E,
    "2": 0x1F,
    "3": 0x20,
    "4": 0x21,
    "5": 0x22,
    "6": 0x23,
    "7": 0x24,
    "8": 0x25,
    "9": 0x26,
    "©": 0x27,
    "&": 0x28,
    " ": 0xF7,
}

def strip_c_comments(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " "
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)

if __name__ == "__main__":
    if len(argv) < 3:
        print("usage: parse_compile.py [in.msg] [out.msgpack]")
        exit(1)

    _, filename, outfile = argv

    messages = []

    message = None
    with open(filename, "r") as f:
        source = strip_c_comments(f.read())
        lineno = 1

        directive = ""
        indent_level = 0

        charset = CHARSET
        font_stack = [0]
        sound_stack = [0]
        color_stack = [0x0A]
        fx_stack = []
        style = None
        explicit_end = False
        choiceindex = -1

        while len(source) > 0:
            if source[0] == "\r" or source[0] == "\t":
                source = source[1:]
                continue

            if source[0] == "\n":
                lineno += 1
                source = source[1:]

                for i in range(indent_level):
                    if source[0] == "\t":
                        source = source[1:]
                    else:
                        break

                continue

            if message is None:
                directive = ""
                while source[0] != " ":
                    if source[0] == "\n":
                        lineno += 1
                    elif source[0] == "\r":
                        pass
                    else:
                        directive += source[0]
                    source = source[1:]

                directive = directive.split(":")

                if directive[0] != "#message" or len(directive) != 3:
                    print(f"{filename}:{lineno}: expected #message:SECTION:INDEX directive")
                    exit(1)

                section = int(directive[1], 16)

                if directive[2].startswith("(") and directive[2].endswith(")"):
                    name = directive[2][1:-1]
                    index = None
                else:
                    name = None
                    index = int(directive[2], 16)

                directive = ""

                message = Message(name, section, index)
                messages.append(message)

                while source[0] != "{":
                    source = source[1:]

                    if source[0] == "\n":
                        lineno += 1
                    elif source[0] == "\r":
                        pass
                    elif source[0] == "{":
                        break
                    elif source[0] != " " and source[0] != "\t":
                        print(f"{filename}:{lineno}: expected opening brace ('{{')")
                        exit(1)

                source = source[1:] # {

                # count indent level
                indent_level = 0
                """
                while source[0] == " " or source[0] == "\t" or source[0] == "\n" or source[0] == "\r":
                    if source[0] == " " or source[0] == "\t":
                        indent_level += 1
                    source = source[1:]
                """
            else:
                command, args, named_args, source = parse_command(source)

                if command:
                    if command == "end":
                        message.bytes += [0xFD]
                        explicit_end = True
                    elif command == "raw":
                        message.bytes += [*args]
                    elif command == "br":
                        message.bytes += [0xF0]
                    elif command == "wait":
                        message.bytes += [0xF1]
                    elif command == "pause":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xF2, args[0]]
                    elif command == "next":
                        message.bytes += [0xFB]
                    elif command == "yield":
                        message.bytes += [0xFF, 0x04]
                    elif command == "savecolor":
                        message.bytes += [0xFF, 0x24]
                    elif command == "restorecolor":
                        message.bytes += [0xFF, 0x25]
                    elif command == "color":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: color command requires 1 parameter")
                            exit(1)

                        color = color_to_code(args[0], style)

                        if color is None:
                            print(f"{filename}:{lineno}: unknown color")
                            exit(1)

                        message.bytes += [0xFF, 0x05, color]
                        #color_stack.append(color)
                    #elif command == "/color":
                    #    color_stack.pop()
                    #    message.bytes += [0xFF, 0x05, color_stack[0]]
                    elif command == "style":
                        message.bytes += [0xFC]

                        style = args[0]
                        args = args[1:]
                        if type(style) is int:
                            message.bytes += [style, *args]
                        else:
                            if style == "right":
                                message.bytes += [0x01]
                            elif style == "left":
                                message.bytes += [0x02]
                            elif style == "center":
                                message.bytes += [0x03]
                            elif style == "tattle":
                                message.bytes += [0x04]
                            elif style == "choice":
                                pos = named_args.get("pos")

                                if not isinstance(pos, list) or len(pos) != 2:
                                    print(f"{filename}:{lineno}: 'choice' style requires pos=_,_")
                                    exit(1)

                                size = named_args.get("size")

                                if not isinstance(size, list) or len(size) != 2:
                                    print(f"{filename}:{lineno}: 'choice' style requires size=_,_")
                                    exit(1)

                                message.bytes += [0x05, pos[0], pos[1], size[0], size[1]]
                            elif style == "inspect":
                                message.bytes += [0x06]
                            elif style == "sign":
                                message.bytes += [0x07]
                            elif style == "lamppost":
                                height = named_args.get("height")

                                if not isinstance(height, int):
                                    print(f"{filename}:{lineno}: 'lamppost' style requires height=_")
                                    exit(1)

                                message.bytes += [0x08, height]
                            elif style == "postcard":
                                index = named_args.get("index")

                                if not isinstance(index, int):
                                    print(f"{filename}:{lineno}: 'postcard' style requires index=_")
                                    exit(1)

                                message.bytes += [0x09, index]
                            elif style == "popup":
                                message.bytes += [0x0A]
                            elif style == "upgrade":
                                pos = named_args.get("pos")

                                if not isinstance(pos, list) or len(pos) != 2:
                                    print(f"{filename}:{lineno}: 'upgrade' style requires pos=_,_")
                                    exit(1)

                                size = named_args.get("size")

                                if not isinstance(size, list) or len(size) != 2:
                                    print(f"{filename}:{lineno}: 'upgrade' style requires size=_,_")
                                    exit(1)

                                message.bytes += [0x0C, pos[0], pos[1], size[0], size[1]]
                            elif style == "narrate":
                                message.bytes += [0x0D]
                            elif style == "epilogue":
                                message.bytes += [0x0E]
                    elif command == "font":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: font command requires 1 parameter")
                            exit(1)

                        font = args[0]

                        if font == "standard":
                            font = 0
                        elif font == "menu":
                            font = 1
                        elif font == "title":
                            font = 3
                        elif font == "subtitle":
                            font = 4

                        if type(font) is not int:
                            print(f"{filename}:{lineno}: unknown font '{font}'")
                            exit(1)

                        message.bytes += [0xFF, 0x00, font]
                        #font_stack.append(font)

                        if font == 3 or font == 4:
                            charset = CHARSET_CREDITS
                        else:
                            charset = CHARSET
                    # elif command == "/font":
                    #     font_stack.pop()
                    #     message.bytes += [0xFF, 0x00, font_stack[0]]

                    #     if font == 3 or font == 4:
                    #         charset = CHARSET_CREDITS
                    #     else:
                    #         charset = CHARSET
                    elif command == "inputoff":
                        message.bytes += [0xFF, 0x07]
                    elif command == "inputon":
                        message.bytes += [0xFF, 0x08]
                    elif command == "delayoff":
                        message.bytes += [0xFF, 0x09]
                    elif command == "delayon":
                        message.bytes += [0xFF, 0x0A]
                    elif command == "charwidth":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x0B, args[0]]
                    elif command == "scroll":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x0C, args[0]]
                    elif command == "size":
                        args = args[0]

                        if len(args) == 1:
                            args.append(args[0])

                        if len(args) != 2:
                            print(f"{filename}:{lineno}: {command} command requires 2 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x0D, args[0], args[1]]
                    elif command == "sizereset":
                        message.bytes += [0xFF, 0x0E]
                    elif command == "speed":
                        delay = named_args.get("delay")

                        if not isinstance(delay, int):
                            print(f"{filename}:{lineno}: {command} command requires delay=_")
                            exit(1)

                        chars = named_args.get("chars")

                        if not isinstance(delay, int):
                            print(f"{filename}:{lineno}: {command} command requires chars=_")
                            exit(1)

                        message.bytes += [0xFF, 0x0F, delay, chars]
                    # elif command == "pos":
                    #     if "y" not in named_args:
                    #         print(f"{filename}:{lineno}: pos command requires parameter: y (x is optional)")
                    #         exit(1)

                    #     if "x" in named_args:
                    #         message.bytes += [0xFF, 0x10, named_args["x"], named_args["y"]]
                    #     else:
                    #         message.bytes += [0xFF, 0x11, named_args["y"]]
                    elif command == "setposx":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x10, args[0] >> 8, args[0] & 0xFF]
                    elif command == "setposy":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x11, *args]
                    elif command == "right":
                        if len(args) == 0:
                            message.bytes += [0x95]
                        else:
                            if len(args) != 1:
                                print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x12, args[0]]
                    elif command == "down":
                        if len(args) == 0:
                            message.bytes += [0x93]
                        else:
                            if len(args) != 1:
                                print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x13, args[0]]
                    elif command == "up":
                        if len(args) == 0:
                            message.bytes += [0x92]
                        else:
                            if len(args) != 1:
                                print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x14, args[0]]
                    elif command == "inlineimage":
                        index = named_args.get("index")

                        if not isinstance(index, int):
                            print(f"{filename}:{lineno}: {command} command requires index=_")
                            exit(1)

                        message.bytes += [0xFF, 0x15, index]
                    elif command == "animsprite":
                        spriteid = named_args.get("spriteid")
                        raster = named_args.get("raster")

                        # TODO: named sprite id and raster

                        if not isinstance(spriteid, int):
                            print(f"{filename}:{lineno}: {command} command requires spriteid=_")
                            exit(1)
                        if not isinstance(raster, int):
                            print(f"{filename}:{lineno}: {command} command requires raster=_")
                            exit(1)

                        message.bytes += [0xFF, 0x16, spriteid >> 8, spriteid & 0xFF, raster]
                    elif command == "itemicon":
                        itemid = named_args.get("itemid")

                        # TODO: itemname

                        if not isinstance(itemid, int):
                            print(f"{filename}:{lineno}: {command} command requires itemid=_")
                            exit(1)

                        message.bytes += [0xFF, 0x17, itemid >> 8, itemid & 0xFF]
                    elif command == "image":
                        index = named_args.get("index")
                        pos = named_args.get("pos") # xx,y
                        hasborder = named_args.get("hasborder")
                        alpha = named_args.get("alpha")
                        fadeamount = named_args.get("fadeamount")

                        if not isinstance(index, int):
                            print(f"{filename}:{lineno}: {command} command requires index=_")
                            exit(1)
                        if not isinstance(pos, list) or len(pos) != 2:
                            print(f"{filename}:{lineno}: {command} command requires pos=_,_")
                            exit(1)
                        if not isinstance(hasborder, int):
                            print(f"{filename}:{lineno}: {command} command requires hasborder=_")
                            exit(1)
                        if not isinstance(alpha, int):
                            print(f"{filename}:{lineno}: {command} command requires alpha=_")
                            exit(1)
                        if not isinstance(fadeamount, int):
                            print(f"{filename}:{lineno}: {command} command requires fadeamount=_")
                            exit(1)

                        message.bytes += [0xFF, 0x18, index, pos[0] >> 8, pos[0] & 0xFF, pos[1], hasborder, alpha, fadeamount]
                    elif command == "hideimage":
                        fadeamount = named_args.get("fadeamount", 0)

                        if not isinstance(fadeamount, int):
                            print(f"{filename}:{lineno}: {command} command requires fadeamount=_")
                            exit(1)

                        message.bytes += [0xFF, 0x19, fadeamount]
                    elif command == "animdelay":
                        index = named_args.get("index")
                        delay = named_args.get("delay")

                        if not isinstance(index, int):
                            print(f"{filename}:{lineno}: {command} command requires index=_")
                            exit(1)
                        if not isinstance(delay, int):
                            print(f"{filename}:{lineno}: {command} command requires delay=_")
                            exit(1)

                        message.bytes += [0xFF, 0x1A, 0, index, delay]
                    elif command == "animloop":
                        message.bytes += [0xFF, 0x1B, 0, 0]
                    elif command == "animdone":
                        message.bytes += [0xFF, 0x1C, 0]
                    elif command == "setcursorpos":
                        index = named_args.get("index")
                        pos = named_args.get("pos")

                        if not isinstance(index, int):
                            print(f"{filename}:{lineno}: {command} command requires index=_")
                            exit(1)
                        if not isinstance(pos, list) or len(pos) != 2:
                            print(f"{filename}:{lineno}: {command} command requires pos=_,_")
                            exit(1)

                        message.bytes += [0xFF, 0x1D, index, pos, pos]
                    elif command == "cursor":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: cursor command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x1E, *args]
                    elif command == "option" and choiceindex == -1:
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: option command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x21, *args]
                    elif command == "endchoice" and choiceindex == -1:
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x1F, args[0]]
                    elif command == "setcancel":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x20, args[0]]
                    # elif command == "startfx":
                    #     message.bytes += [0xFF, 0x26, resolve_effect(args[0]), *args[1:]]
                    # elif command == "endfx":
                    #     message.bytes += [0xFF, 0x27, resolve_effect(args[0]), *args[1:]]
                    elif command == "/fx":
                        message.bytes += [0xFF, 0x27, fx_stack.pop()]
                    elif command == "shake":
                        fx_stack.append(0x00)
                        message.bytes += [0xFF, 0x26, 0x00]
                    elif command == "/shake":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x00]
                    elif command == "wave":
                        fx_stack.append(0x01)
                        message.bytes += [0xFF, 0x26, 0x01]
                    elif command == "/wave":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x01]
                    elif command == "noiseoutline":
                        fx_stack.append(0x02)
                        message.bytes += [0xFF, 0x26, 0x02]
                    elif command == "/noiseoutline":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x02]
                    elif command == "static":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        fx_stack.append(0x03)
                        message.bytes += [0xFF, 0x26, 0x03, args[0]]
                    elif command == "/static":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x03]
                    elif command == "blur":
                        _dir = named_args.get("dir")

                        if _dir == "x":
                            _dir = 0
                        elif _dir == "y":
                            _dir = 1
                        elif _dir == "xy":
                            _dir = 2

                        if not isinstance(_dir, int):
                            print(f"{filename}:{lineno}: {command} command requires dir=_")
                            exit(1)

                        fx_stack.append(0x05)
                        message.bytes += [0xFF, 0x26, 0x05, _dir]
                    elif command == "/blur":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x05]
                    elif command == "rainbow":
                        fx_stack.append(0x06)
                        message.bytes += [0xFF, 0x27, 0x06]
                    elif command == "/rainbow":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x06]
                    elif command == "ditherfade":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        fx_stack.append(0x07)
                        message.bytes += [0xFF, 0x26, 0x07, args[0]]
                    elif command == "/ditherfade":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x07]
                    elif command == "printrising":
                        fx_stack.append(0x0A)
                        message.bytes += [0xFF, 0x26, 0x0A]
                    elif command == "/printrising":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x0A]
                    elif command == "printgrowing":
                        fx_stack.append(0x0B)
                        message.bytes += [0xFF, 0x26, 0x0B]
                    elif command == "/printgrowing":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x0B]
                    elif command == "sizejitter":
                        fx_stack.append(0x0C)
                        message.bytes += [0xFF, 0x26, 0x0C]
                    elif command == "/sizejitter":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x0C]
                    elif command == "sizewave":
                        fx_stack.append(0x0D)
                        message.bytes += [0xFF, 0x26, 0x0D]
                    elif command == "/sizewave":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x0D]
                    elif command == "dropshadow":
                        fx_stack.append(0x0E)
                        message.bytes += [0xFF, 0x26, 0x0E]
                    elif command == "/dropshadow":
                        fx_stack.pop()
                        message.bytes += [0xFF, 0x27, 0x0E]
                    elif command == "var":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: var command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x28, *args]
                    elif command == "centerx":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x29, *args]
                    elif command == "rewindoff":
                        message.bytes += [0xFF, 0x2A, 0]
                    elif command == "rewindon":
                        message.bytes += [0xFF, 0x2A, 1]
                    elif command == "customvoice":
                        soundids = named_args.get("soundids")

                        if not isinstance(soundids, list) or len(pos) != 2:
                            print(f"{filename}:{lineno}: {command} command requires soundids=_,_")
                            exit(1)

                        message.bytes += [
                            0xFF, 0x2C,
                            soundids[0] >> 24, (soundids[0] >> 16) & 0xFF, (soundids[0] >> 8) & 0xFF, soundids[0] & 0xFF,
                            soundids[1] >> 24, (soundids[1] >> 16) & 0xFF, (soundids[1] >> 8) & 0xFF, soundids[1] & 0xFF,
                        ]
                    elif command == "volume":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x2E, *args]
                    elif command == "voice":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        sound = args[0]

                        if sound == "normal":
                            sound = 0
                        elif sound == "bowser":
                            sound = 1
                        elif sound == "star" or sound == "spirit":
                            sound = 2

                        if type(sound) is not int:
                            print(f"{filename}:{lineno}: unknown voice '{sound}'")
                            exit(1)

                        message.bytes += [0xFF, 0x2F, sound]
                        #sound_stack.append(sound)
                    # elif command == "/sound":
                    #     sound_stack.pop()
                    #     message.bytes += [0xFF, 0x2F, sound_stack[0]]
                    elif command == "a":
                        color_code = color_to_code("blue", "button")
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x98, 0xFF, 0x25]
                    elif command == "b":
                        color_code = color_to_code(named_args.get("color", "green"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x99, 0xFF, 0x25]
                    elif command == "l":
                        color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9A, 0xFF, 0x25]
                    elif command == "r":
                        color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9B, 0xFF, 0x25]
                    elif command == "z":
                        color_code = color_to_code("grey", "button")
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9C, 0xFF, 0x25]
                    elif command == "c-up":
                        color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9D, 0xFF, 0x25]
                    elif command == "c-down":
                        color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9E, 0xFF, 0x25]
                    elif command == "c-left":
                        color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9F, 0xFF, 0x25]
                    elif command == "c-right":
                        color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0xA0, 0xFF, 0x25]
                    elif command == "start":
                        color_code = color_to_code(named_args.get("color", "red"), named_args.get("ctx", "button"))#
                        assert color_code is not None
                        message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0xA1, 0xFF, 0x25]
                    elif command == "~a":
                        message.bytes += [0x98]
                    elif command == "~b":
                        message.bytes += [0x99]
                    elif command == "~l":
                        message.bytes += [0x9a]
                    elif command == "~r":
                        message.bytes += [0x9b]
                    elif command == "~z":
                        message.bytes += [0x9c]
                    elif command == "~c-up":
                        message.bytes += [0x9d]
                    elif command == "~c-down":
                        message.bytes += [0x9e]
                    elif command == "~c-left":
                        message.bytes += [0x9f]
                    elif command == "~c-right":
                        message.bytes += [0xa0]
                    elif command == "~start":
                        message.bytes += [0xa1]
                    elif command == "note":
                        message.bytes += [0x00]
                    elif command == "heart":
                        message.bytes += [0x90]
                    elif command == "star":
                        message.bytes += [0x91]
                    elif command == "left":
                        message.bytes += [0x94]
                    elif command == "circle":
                        message.bytes += [0x96]
                    elif command == "cross":
                        message.bytes += [0x97]
                    elif command == "savepos":
                        message.bytes += [0xFF, 0x22]
                    elif command == "restorepos":
                        message.bytes += [0xFF, 0x23]
                    elif command == "enablecdownnext":
                        message.bytes += [0xFF, 0x2b]
                    elif command == "beginchoice":
                        choiceindex = 0
                        message.bytes += [0xFF, 0x09] # delayoff
                    elif command == "option" and choiceindex >= 0:
                        message.bytes += [0xFF, 0x1E, choiceindex] # cursor n
                        message.bytes += [0xFF, 0x21, choiceindex] # option n
                        choiceindex += 1
                    elif command == "endchoice" and choiceindex >= 0:
                        cancel = named_args.get("cancel")

                        message.bytes += [0xFF, 0x21, 255] # option 255
                        message.bytes += [0xFF, 0x0A] # delayon

                        if isinstance(cancel, int):
                            message.bytes += [0xFF, 0x20, cancel] # setcancel n

                        message.bytes += [0xFF, 0x1F, choiceindex] # endchoice n

                        choiceindex = -1
                    elif command == "animation" and choiceindex >= 0:
                        # TODO
                        print(f"{filename}:{lineno}: '{command}' tag is not yet implemented")
                        exit(1)
                    else:
                        print(f"{filename}:{lineno}: unknown command '{command}'")
                        exit(1)
                else:
                    if source[0] == "}":
                        if not explicit_end:
                            print(f"{filename}:{lineno}: warning: string lacks an [end] command")
                            #message.bytes += [0xFD]
                        explicit_end = False

                        # sanity check
                        for b in message.bytes:
                            if not isinstance(b, int):
                                print(b)

                        # padding
                        while len(message.bytes) % 4 != 0:
                            message.bytes += [0x00]

                        message = None
                        source = source[1:] # }
                        indent_level = 0
                        choiceindex = -1
                        continue

                    if source[0] == "\\":
                        source = source[1:]

                    if source[0] in charset:
                        data = charset[source[0]]

                        if type(data) is int:
                            message.bytes.append(data)
                        else:
                            message.bytes += data

                        source = source[1:]
                    else:
                        print(f"{filename}:{lineno}: unsupported character '{source[0]}' for current font")
                        exit(1)

        if message != None:
            print(f"{filename}: missing [end]")
            exit(1)

    with open(outfile, "wb") as f:
        msgpack.pack([{
            "section": message.section,
            "index": message.index,
            "name": message.name,
            "bytes": bytes(message.bytes),
        } for message in messages], f)
