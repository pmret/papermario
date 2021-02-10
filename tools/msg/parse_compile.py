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
        return None, [], source
    source = source[1:] # "["

    inside_brackets = ""
    while source[0] != "]":
        if source[0] == "\n":
            return None, [], source

        inside_brackets += source[0]
        source = source[1:]
    source = source[1:] # "]"

    command, *raw_args = inside_brackets.split(":")

    """
    args = []
    named_args = {}

    if "=" in command:
        key, value = command.split("=", 1)
        command = key
        named_args[key] = try_convert_int(value)

    for arg in args:
        if "=" in arg:
            key, value = arg.split("=", 1)
            named_args[key.lower()] = try_convert_int(value.lower())
        else:
            args.append(try_convert_int(arg))
    """

    args = []
    for arg in raw_args:
        args.append(try_convert_int(arg.lower()))

    return command.lower(), args, source

def color_to_code(color, style):
    """
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
    """
    COLORS = {}

    if type(color) is int:
        return color

    return COLORS.get(ctx, {
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

def resolve_effect(fx):
    if type(fx) is int:
        return fx

    FX = {
        "jitter": 0x00,
        "wavy": 0x01,
        "noise": 0x02,
        "fadednoise": 0x03, # 1 arg
        "unknown": 0x04,
        "fadedjitter": 0x05, # 1 arg
        "rainbow": 0x06,
        "faded": 0x07, # 1 arg
        "wavyb": 0x08,
        "rainbowb": 0x09,
        "shrinking": 0x0a,
        "growing": 0x0b,
        "sizejitter": 0x0c,
        "sizewave": 0x0d,
        "dropshadow": 0x0e,
    }

    return FX.get(fx)

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
        style = None
        explicit_end = False

        while len(source) > 0:
            if source[0] == "\r":
                source = source[1:]
                continue

            if source[0] == "\n":
                lineno += 1
                source = source[1:]

                for i in range(indent_level):
                    if source[0] == " " or source[0] == "\t":
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
                while source[0] == " " or source[0] == "\t" or source[0] == "\n" or source[0] == "\r":
                    if source[0] == " " or source[0] == "\t":
                        indent_level += 1
                    source = source[1:]

                    # TODO: lookahead at all lines until "}" to determine lowest indent value
                    if indent_level == 4:
                        break
            else:
                command, args, source = parse_command(source)

                if command:
                    if command == "end":
                        message.bytes += [0xFD]
                        explicit_end = True
                    elif command == "raw":
                        message.bytes += [*args]
                    #elif command == "func":
                    #    message.bytes += [0xFF, *args]
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
                    elif command == "func_04":
                        message.bytes += [0xFF, 0x04]
                    elif command == "pushcolor":
                        message.bytes += [0xFF, 0x24]
                    elif command == "popcolor":
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
                        color_stack.append(color)
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
                                if len(args) != 4:
                                    print(f"{filename}:{lineno}: 'choice' style requires 4 parameters")
                                    exit(1)

                                message.bytes += [0x05, *args]
                            elif style == "inspect":
                                message.bytes += [0x06]
                            elif style == "sign":
                                message.bytes += [0x07]
                            elif style == "lamppost":
                                if len(args) != 1:
                                    print(f"{filename}:{lineno}: 'lamppost' style requires 1 parameter")
                                    exit(1)

                                message.bytes += [0x08, args[0]]
                            elif style == "postcard":
                                if len(args) != 1:
                                    print(f"{filename}:{lineno}: 'lamppost' style requires 1 parameter")
                                    exit(1)

                                message.bytes += [0x09, args[0]]
                            elif style == "popup":
                                message.bytes += [0x0A]
                            elif style == "upgrade":
                                if len(args) != 4:
                                    print(f"{filename}:{lineno}: 'upgrade' style requires 4 parameters")
                                    exit(1)

                                message.bytes += [0x0C, *args]
                            elif style == "narrate":
                                message.bytes += [0x0D]
                            elif style == "epilogue":
                                message.bytes += [0x0E]
                    elif command == "font":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: font command requires 1 parameter")
                            exit(1)

                        font = args[0]

                        if font == "normal":
                            font = 0
                        elif font == "title":
                            font = 3
                        elif font == "subtitle":
                            font = 4

                        if type(font) is not int:
                            print(f"{filename}:{lineno}: unknown font '{font}'")
                            exit(1)

                        message.bytes += [0xFF, 0x00, font]
                        font_stack.append(font)

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
                    elif command == "kerning":
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
                        if len(args) != 2:
                            print(f"{filename}:{lineno}: {command} command requires 2 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x0D, *args]
                    elif command == "sizereset":
                        message.bytes += [0xFF, 0x0E]
                    elif command == "speed":
                        if len(args) != 2:
                            print(f"{filename}:{lineno}: {command} command requires 2 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x0F, *args]
                    # elif command == "pos":
                    #     if "y" not in named_args:
                    #         print(f"{filename}:{lineno}: pos command requires parameter: y (x is optional)")
                    #         exit(1)

                    #     if "x" in named_args:
                    #         message.bytes += [0xFF, 0x10, named_args["x"], named_args["y"]]
                    #     else:
                    #         message.bytes += [0xFF, 0x11, named_args["y"]]
                    elif command == "setprintpos":
                        if len(args) != 2:
                            print(f"{filename}:{lineno}: {command} command requires 2 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x10, *args]
                    elif command == "setprinty":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x11, *args]
                    elif command == "indent":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: indent command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x12, args[0]]
                    # elif command == "image":
                    #     if len(args) == 1:
                    #         message.bytes += [0xFF, 0x15, args[0]]
                    #     elif len(args) == 7:
                    #         message.bytes += [0xFF, 0x18, *args]
                    #     else:
                    #         print(f"{filename}:{lineno}: image command requires 1 or 7 parameters")
                    #         exit(1)
                    elif command == "image1":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x15, *args]
                    elif command == "image7":
                        if len(args) != 7:
                            print(f"{filename}:{lineno}: {command} command requires 7 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x18, *args]
                    elif command == "sprite":
                        if len(args) != 3:
                            print(f"{filename}:{lineno}: sprite command requires 3 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x16, *args]
                    elif command == "item":
                        if len(args) != 2:
                            print(f"{filename}:{lineno}: item command requires 2 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x17, *args]
                    elif command == "cursor":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: cursor command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x1E, *args]
                    elif command == "option":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: option command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x21, *args]
                    elif command == "endchoice":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x1F, args[0]]
                    elif command == "setcancel":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x20, args[0]]
                    elif command == "startfx":
                        message.bytes += [0xFF, 0x26, resolve_effect(args[0]), *args[1:]]
                    elif command == "endfx":
                        message.bytes += [0xFF, 0x27, resolve_effect(args[0]), *args[1:]]
                    # elif command == "shaky":
                    #     message.bytes += [0xFF, 0x26, 0x00]
                    # elif command == "/shaky":
                    #     message.bytes += [0xFF, 0x27, 0x00]
                    # elif command == "wavy":
                    #     message.bytes += [0xFF, 0x26, 0x01]
                    # elif command == "/wavy":
                    #     message.bytes += [0xFF, 0x27, 0x01]
                    # elif command == "shaky":
                    #     if "opacity" in named_args:
                    #         print(f"{filename}:{lineno}: shaky command doesn't accept parameter 'fade' (hint: did you mean 'faded-shaky'?)")
                    #         exit(1)
                    #     message.bytes += [0xFF, 0x26, 0x00]
                    # elif command == "/shaky":
                    #     message.bytes += [0xFF, 0x27, 0x00]
                    # elif command == "noise":
                    #     message.bytes += [0xFF, 0x26, 0x03, named_args.get("fade", 3)]
                    # elif command == "/noise":
                    #     message.bytes += [0xFF, 0x27, 0x03]
                    # elif command == "faded-shaky":
                    #     message.bytes += [0xFF, 0x26, 0x05, named_args.get("fade", 5)]
                    # elif command == "/faded-shaky":
                    #     message.bytes += [0xFF, 0x27, 0x05]
                    # elif command == "fade":
                    #     message.bytes += [0xFF, 0x26, 0x07, named_args.get("fade", 7)]
                    # elif command == "/fade":
                    #     message.bytes += [0xFF, 0x27, 0x07]
                    # elif command == "shout" or command == "shrinking":
                    #     message.bytes += [0xFF, 0x26, 0x0A]
                    # elif command == "/shout" or command == "/shrinking":
                    #     message.bytes += [0xFF, 0x27, 0x0A]
                    # elif command == "whisper" or command == "growing":
                    #     message.bytes += [0xFF, 0x26, 0x0B]
                    # elif command == "/whisper" or command == "/growing":
                    #     message.bytes += [0xFF, 0x27, 0x0B]
                    # elif command == "scream" or command == "shaky-size":
                    #     message.bytes += [0xFF, 0x26, 0x0C]
                    # elif command == "/scream" or command == "/shaky-size":
                    #     message.bytes += [0xFF, 0x27, 0x0C]
                    # elif command == "chortle" or command == "wavy-size":
                    #     message.bytes += [0xFF, 0x26, 0x0D]
                    # elif command == "/chortle" or command == "/wavy-size":
                    #     message.bytes += [0xFF, 0x27, 0x0D]
                    # elif command == "shadow":
                    #     message.bytes += [0xFF, 0x26, 0x0E]
                    # elif command == "/shadow":
                    #     message.bytes += [0xFF, 0x27, 0x0E]
                    elif command == "var":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: var command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x28, *args]
                    elif command == "func_29":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x29, *args]
                    elif command == "volume":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x2E, *args]
                    elif command == "speechsound":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        sound = args[0]

                        # if sound == "normal":
                        #     sound = 0
                        # elif sound == "bowser":
                        #     sound = 1
                        # elif sound == "star":
                        #     sound = 2

                        if type(sound) is not int:
                            print(f"{filename}:{lineno}: unknown sound '{sound}'")
                            exit(1)

                        message.bytes += [0xFF, 0x2F, sound]
                        sound_stack.append(sound)
                    # elif command == "/sound":
                    #     sound_stack.pop()
                    #     message.bytes += [0xFF, 0x2F, sound_stack[0]]
                    # elif command == "a":
                    #     color_code = color_to_code(named_args.get("color", "blue"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x98, 0xFF, 0x25]
                    # elif command == "b":
                    #     color_code = color_to_code(named_args.get("color", "green"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x99, 0xFF, 0x25]
                    # elif command == "l":
                    #     color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9A, 0xFF, 0x25]
                    # elif command == "r":
                    #     color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9B, 0xFF, 0x25]
                    # elif command == "z":
                    #     color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9C, 0xFF, 0x25]
                    # elif command == "c-up":
                    #     color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9D, 0xFF, 0x25]
                    # elif command == "c-down":
                    #     color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9E, 0xFF, 0x25]
                    # elif command == "c-left":
                    #     color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9F, 0xFF, 0x25]
                    # elif command == "c-right":
                    #     color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0xA0, 0xFF, 0x25]
                    # elif command == "start":
                    #     color_code = color_to_code(named_args.get("color", "red"), named_args.get("ctx", "button"))
                    #     message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0xA1, 0xFF, 0x25]
                    elif command == "a":
                        message.bytes += [0x98]
                    elif command == "b":
                        message.bytes += [0x99]
                    elif command == "l":
                        message.bytes += [0x9a]
                    elif command == "r":
                        message.bytes += [0x9b]
                    elif command == "z":
                        message.bytes += [0x9c]
                    elif command == "c-up":
                        message.bytes += [0x9d]
                    elif command == "c-down":
                        message.bytes += [0x9e]
                    elif command == "c-left":
                        message.bytes += [0x9f]
                    elif command == "c-right":
                        message.bytes += [0xa0]
                    elif command == "start":
                        message.bytes += [0xa1]
                    elif command == "note":
                        message.bytes += [0x00]
                    elif command == "heart":
                        message.bytes += [0x90]
                    elif command == "star":
                        message.bytes += [0x91]
                    elif command == "up":
                        if len(args) == 1:
                            message.bytes += [0xFF, 0x14, args[0]]
                        else:
                            message.bytes += [0x92]
                    elif command == "down":
                        if len(args) == 1:
                            message.bytes += [0xFF, 0x13, args[0]]
                        else:
                            message.bytes += [0x93]
                    elif command == "left":
                        message.bytes += [0x94]
                    elif command == "right":
                        message.bytes += [0x95]
                    elif command == "circle":
                        message.bytes += [0x96]
                    elif command == "cross":
                        message.bytes += [0x97]
                    # elif command == "wait":
                    #     print(f"{filename}:{lineno}: unknown command 'wait' (hint: did you mean 'prompt'?)")
                    #     exit(1)
                    # elif command == "pause":
                    #     print(f"{filename}:{lineno}: unknown command 'pause' (hint: did you mean 'sleep'?)")
                    #     exit(1)
                    elif command == "func_1a":
                        if len(args) != 3:
                            print(f"{filename}:{lineno}: {command} command requires 3 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x1A, *args]
                    elif command == "func_1b":
                        if len(args) != 2:
                            print(f"{filename}:{lineno}: {command} command requires 2 parameters")
                            exit(1)

                        message.bytes += [0xFF, 0x1B, *args]
                    elif command == "func_1c":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)

                        message.bytes += [0xFF, 0x1C, *args]
                    elif command == "startanim":
                        message.bytes += [0xFF, 0x22]
                    elif command == "endanim":
                        message.bytes += [0xFF, 0x23]
                    elif command == "func_2b":
                        message.bytes += [0xFF, 0x2b]
                    else:
                        print(f"{filename}:{lineno}: unknown command '{command}'")
                        exit(1)
                else:
                    if source[0] == "}":
                        if not explicit_end:
                            print(f"{filename}:{lineno}: warning: string lacks an [end] command")
                            #message.bytes += [0xFD]
                        explicit_end = False

                        # padding
                        while len(message.bytes) % 4 != 0:
                            message.bytes += [0x00]

                        message = None
                        source = source[1:] # }
                        indent_level = 0
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
            print(f"{filename}: missing [/message]")
            exit(1)

    with open(outfile, "wb") as f:
        msgpack.pack([{
            "section": message.section,
            "index": message.index,
            "name": message.name,
            "bytes": bytes(message.bytes),
        } for message in messages], f)
