#! /usr/bin/python3

from sys import argv
from collections import OrderedDict
import re

class Message:
    def __init__(self, name, section, index):
        self.name = name
        self.section = section
        self.index = index

        self.bytes = []

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

    command, *args = inside_brackets.split(" ")

    positional_args = []
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
            positional_args.append(try_convert_int(arg))

    return command.lower(), positional_args, named_args, source

def color_to_code(color, ctx="normal"):
    COLORS = {
        "normal": {
            "normal": 0x0A,
            "red": 0x20,
            "pink": 0x21,
            "purple": 0x22,
            "blue": 0x23,
            "cyan": 0x24,
            "green": 0x25,
            "yellow": 0x26,
        },
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

    return COLORS.get(ctx, {}).get(color)

CHARSET = {
    "𝅘𝅥𝅮": 0x00,
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
    "♥": 0x90,
    "★": 0x91,
    "↑": 0x92,
    "↓": 0x93,
    "←": 0x94,
    "→": 0x95,
    "●": 0x96,
    "✖": 0x97,
    "“": 0xA2,
    "”": 0xA3,
    "‘": 0xA4,
    "’": 0xA5,
    " ": 0xF7,
    "Ⓐ": [0xFF, 0x24, 0xFF, 0x05, 0x10, 0x98, 0xFF, 0x25],
    "Ⓑ": [0xFF, 0x24, 0xFF, 0x05, 0x11, 0x99, 0xFF, 0x25],
    "Ⓢ": [0xFF, 0x24, 0xFF, 0x05, 0x12, 0xA1, 0xFF, 0x25],
    "⬆": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0x9D, 0xFF, 0x25],
    "⬇": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0x9E, 0xFF, 0x25],
    "⬅": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0x9F, 0xFF, 0x25],
    "➡": [0xFF, 0x24, 0xFF, 0x05, 0x13, 0xA0, 0xFF, 0x25],
    "Ⓛ": [0xFF, 0x24, 0xFF, 0x05, 0x14, 0x9A, 0xFF, 0x25],
    "Ⓡ": [0xFF, 0x24, 0xFF, 0x05, 0x14, 0x9B, 0xFF, 0x25],
    "Ⓩ": [0xFF, 0x24, 0xFF, 0x05, 0x14, 0x9C, 0xFF, 0x25],
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

if __name__ == "__main__":
    if len(argv) < 4:
        print("usage: compile_messages.py [OUTBIN] [OUTHEADER] [INFILES]")
        exit(1)

    _, outfile, outheader, *infiles = argv

    messages = []

    for filename in infiles:
        message = None
        with open(filename, "r") as f:
            source = f.read()
            lineno = 1

            charset = CHARSET
            font_stack = [0]
            sound_stack = [0]
            color_stack = [0x0A]

            while len(source) > 0:
                if source.startswith("\n"):
                    lineno += 1
                    source = source[1:]
                    continue

                if message is None:
                    if source.startswith("//"):
                        while source[0] != "\n":
                            source = source[1:]
                    else:
                        command, positional_args, named_args, source = parse_command(source)

                        if not command:
                            print(f"{filename}:{lineno}: expected [message]")
                            exit(1)

                        name = positional_args[0] if len(positional_args) > 0 else None
                        message = Message(name, named_args.get("section"), named_args.get("index"))
                        messages.append(message)
                else:
                    command, positional_args, named_args, source = parse_command(source)

                    if command:
                        if command == "/message":
                            message.bytes += [0xFD]

                            # padding
                            while len(message.bytes) % 4 != 0:
                                message.bytes += [0x00]

                            message = None
                        elif command == "raw":
                            message.bytes += [*positional_args]
                        elif command == "func":
                            message.bytes += [0xFF, *positional_args]
                        elif command == "br":
                            message.bytes += [0xF0]
                        elif command == "prompt":
                            message.bytes += [0xF1]
                        elif command == "sleep":
                            if len(positional_args) == 0:
                                print(f"{filename}:{lineno}: {command} command requires a positional parameter")
                                exit(1)

                            message.bytes += [0xF2, positional_args[0]]
                        elif command == "next":
                            message.bytes += [0xFB]
                        elif command == "color":
                            if "color" not in named_args:
                                print(f"{filename}:{lineno}: color command requires a 'color' parameter")
                                exit(1)

                            color = color_to_code(**named_args)

                            if color is None:
                                print(f"{filename}:{lineno}: unknown color combination {named_args}")
                                exit(1)

                            message.bytes += [0xFF, 0x05, color]
                            color_stack.append(color)
                        elif command == "/color":
                            color_stack.pop()
                            message.bytes += [0xFF, 0x05, color_stack[0]]
                        elif command == "style":
                            if "style" not in named_args:
                                print(f"{filename}:{lineno}: style command requires a 'style' parameter")
                                exit(1)

                            message.bytes += [0xFC]

                            style = named_args["style"]
                            if type(style) is int:
                                message.bytes += [style, *positional_args]
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
                                    if "w" not in named_args or "h" not in named_args or "x" not in named_args or "y" not in named_args:
                                        print(f"{filename}:{lineno}: 'choice' style requires parameters: x, y, w, h")
                                        exit(1)

                                    message.bytes += [0x05, named_args["w"], named_args["x"], named_args["h"], named_args["y"]]
                                elif style == "inspect":
                                    message.bytes += [0x06]
                                elif style == "sign":
                                    message.bytes += [0x07]
                                elif style == "lamppost":
                                    message.bytes += [0x08]
                                elif style == "postcard":
                                    message.bytes += [0x09]
                                elif style == "popup":
                                    message.bytes += [0x0A]
                                elif style == "upgrade":
                                    if "w" not in named_args or "h" not in named_args or "x" not in named_args or "y" not in named_args:
                                        print(f"{filename}:{lineno}: 'upgrade' style requires parameters: x, y, w, h")
                                        exit(1)

                                    message.bytes += [0x0C, named_args["w"], named_args["x"], named_args["h"], named_args["y"]]
                                elif style == "narrate":
                                    message.bytes += [0x0D]
                                elif style == "epilogue":
                                    message.bytes += [0x0E]
                        elif command == "font":
                            if "font" not in named_args:
                                print(f"{filename}:{lineno}: font command requires a 'font' parameter")
                                exit(1)

                            font = named_args["font"]

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
                        elif command == "/font":
                            font_stack.pop()
                            message.bytes += [0xFF, 0x00, font_stack[0]]

                            if font == 3 or font == 4:
                                charset = CHARSET_CREDITS
                            else:
                                charset = CHARSET
                        elif command == "noskip":
                            message.bytes += [0xFF, 0x07]
                        elif command == "/noskip":
                            message.bytes += [0xFF, 0x08]
                        elif command == "instant":
                            message.bytes += [0xFF, 0x09]
                        elif command == "/instant":
                            message.bytes += [0xFF, 0x0A]
                        elif command == "kerning":
                            if "kerning" not in named_args:
                                print(f"{filename}:{lineno}: kerning command requires a 'kerning' parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x0B, named_args["kerning"]]
                        elif command == "scroll":
                            if len(positional_args) == 0:
                                print(f"{filename}:{lineno}: scroll command requires a positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x0C, positional_args[0]]
                        elif command == "size":
                            if "x" not in named_args or "y" not in named_args:
                                print(f"{filename}:{lineno}: size command requires parameters: x, y")
                                exit(1)

                            message.bytes += [0xFF, 0x0D, named_args["x"], named_args["y"]]
                        elif command == "/size":
                            message.bytes += [0xFF, 0x0E]
                        elif command == "speed":
                            if "delay" not in named_args or "chars" not in named_args:
                                print(f"{filename}:{lineno}: speed command requires parameters: delay, chars")
                                exit(1)

                            message.bytes += [0xFF, 0x0F, named_args["delay"], named_args["chars"]]
                        elif command == "pos":
                            if "y" not in named_args:
                                print(f"{filename}:{lineno}: pos command requires parameter: y (x is optional)")
                                exit(1)

                            if "x" in named_args:
                                message.bytes += [0xFF, 0x10, named_args["x"], named_args["y"]]
                            else:
                                message.bytes += [0xFF, 0x11, named_args["y"]]
                        elif command == "indent":
                            if len(positional_args) == 0:
                                print(f"{filename}:{lineno}: indent command requires a positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x12, positional_args[0]]
                        elif command == "down":
                            if len(positional_args) == 0:
                                print(f"{filename}:{lineno}: down command requires a positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x13, positional_args[0]]
                        elif command == "up":
                            if len(positional_args) == 0:
                                print(f"{filename}:{lineno}: up command requires a positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x14, positional_args[0]]
                        elif command == "image":
                            if len(positional_args) == 1:
                                message.bytes += [0xFF, 0x15, positional_args[0]]
                            elif len(positional_args) == 7:
                                message.bytes += [0xFF, 0x18, *positional_args]
                            else:
                                print(f"{filename}:{lineno}: image command requires 1 or 7 positional parameters")
                                exit(1)
                        elif command == "sprite":
                            if len(positional_args) != 3:
                                print(f"{filename}:{lineno}: sprite command requires 3 positional parameters")
                                exit(1)

                            message.bytes += [0xFF, 0x16, *positional_args]
                        elif command == "item":
                            if len(positional_args) != 2:
                                print(f"{filename}:{lineno}: item command requires 2 positional parameters")
                                exit(1)

                            message.bytes += [0xFF, 0x17, *positional_args]
                        elif command == "cursor":
                            if len(positional_args) != 1:
                                print(f"{filename}:{lineno}: cursor command requires 1 positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x1E, *positional_args]
                        elif command == "option":
                            if len(positional_args) != 1:
                                print(f"{filename}:{lineno}: option command requires 1 positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x21, *positional_args]
                        elif command == "choice":
                            if len(positional_args) != 1:
                                print(f"{filename}:{lineno}: choice command requires 1 positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x1E, positional_args[0], 0xFF, 0x21, positional_args[0]]
                        elif command == "choicecount":
                            if "choicecount" not in named_args:
                                print(f"{filename}:{lineno}: choicecount command requires a 'choicecount' parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x1F, named_args["choicecount"]]
                        elif command == "cancel":
                            if "cancel" not in named_args:
                                print(f"{filename}:{lineno}: cancel command requires a 'cancel' parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x20, named_args["cancel"]]
                        elif command == "shaky":
                            message.bytes += [0xFF, 0x26, 0x00]
                        elif command == "/shaky":
                            message.bytes += [0xFF, 0x27, 0x00]
                        elif command == "wavy":
                            message.bytes += [0xFF, 0x26, 0x01]
                        elif command == "/wavy":
                            message.bytes += [0xFF, 0x27, 0x01]
                        elif command == "shaky":
                            if "opacity" in named_args:
                                print(f"{filename}:{lineno}: shaky command doesn't accept parameter 'fade' (hint: did you mean 'faded-shaky'?)")
                                exit(1)
                            message.bytes += [0xFF, 0x26, 0x00]
                        elif command == "/shaky":
                            message.bytes += [0xFF, 0x27, 0x00]
                        elif command == "noise":
                            message.bytes += [0xFF, 0x26, 0x03, named_args.get("fade", 3)]
                        elif command == "/noise":
                            message.bytes += [0xFF, 0x27, 0x03]
                        elif command == "faded-shaky":
                            message.bytes += [0xFF, 0x26, 0x05, named_args.get("fade", 5)]
                        elif command == "/faded-shaky":
                            message.bytes += [0xFF, 0x27, 0x05]
                        elif command == "fade":
                            message.bytes += [0xFF, 0x26, 0x07, named_args.get("fade", 7)]
                        elif command == "/fade":
                            message.bytes += [0xFF, 0x27, 0x07]
                        elif command == "shout" or command == "shrinking":
                            message.bytes += [0xFF, 0x26, 0x0A]
                        elif command == "/shout" or command == "/shrinking":
                            message.bytes += [0xFF, 0x27, 0x0A]
                        elif command == "whisper" or command == "growing":
                            message.bytes += [0xFF, 0x26, 0x0B]
                        elif command == "/whisper" or command == "/growing":
                            message.bytes += [0xFF, 0x27, 0x0B]
                        elif command == "scream" or command == "shaky-size":
                            message.bytes += [0xFF, 0x26, 0x0C]
                        elif command == "/scream" or command == "/shaky-size":
                            message.bytes += [0xFF, 0x27, 0x0C]
                        elif command == "chortle" or command == "wavy-size":
                            message.bytes += [0xFF, 0x26, 0x0D]
                        elif command == "/chortle" or command == "/wavy-size":
                            message.bytes += [0xFF, 0x27, 0x0D]
                        elif command == "shadow":
                            message.bytes += [0xFF, 0x26, 0x0E]
                        elif command == "/shadow":
                            message.bytes += [0xFF, 0x27, 0x0E]
                        elif command == "var":
                            if len(positional_args) != 1:
                                print(f"{filename}:{lineno}: var command requires 1 positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x28, *positional_args]
                        elif command == "center":
                            if len(positional_args) != 1:
                                print(f"{filename}:{lineno}: center command requires 1 positional parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x29, *positional_args]
                        elif command == "volume":
                            if "volume" not in named_args:
                                print(f"{filename}:{lineno}: volume command requires a 'volume' parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x2E, named_args["volume"]]
                        elif command == "sound":
                            if "sound" not in named_args:
                                print(f"{filename}:{lineno}: sound command requires a 'sound' parameter")
                                exit(1)

                            sound = named_args["sound"]

                            if sound == "normal":
                                sound = 0
                            elif sound == "bowser":
                                sound = 1
                            elif sound == "spirit":
                                sound = 2

                            if type(sound) is not int:
                                print(f"{filename}:{lineno}: unknown sound '{sound}'")
                                exit(1)

                            message.bytes += [0xFF, 0x2F, sound]
                            sound_stack.append(sound)
                        elif command == "/sound":
                            sound_stack.pop()
                            message.bytes += [0xFF, 0x2F, sound_stack[0]]
                        elif command == "a":
                            color_code = color_to_code(named_args.get("color", "blue"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x98, 0xFF, 0x25]
                        elif command == "b":
                            color_code = color_to_code(named_args.get("color", "green"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x99, 0xFF, 0x25]
                        elif command == "l":
                            color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9A, 0xFF, 0x25]
                        elif command == "r":
                            color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9B, 0xFF, 0x25]
                        elif command == "z":
                            color_code = color_to_code(named_args.get("color", "gray"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9C, 0xFF, 0x25]
                        elif command == "c-up":
                            color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9D, 0xFF, 0x25]
                        elif command == "c-down":
                            color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9E, 0xFF, 0x25]
                        elif command == "c-left":
                            color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0x9F, 0xFF, 0x25]
                        elif command == "c-right":
                            color_code = color_to_code(named_args.get("color", "yellow"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0xA0, 0xFF, 0x25]
                        elif command == "start":
                            color_code = color_to_code(named_args.get("color", "red"), named_args.get("ctx", "button"))
                            message.bytes += [0xFF, 0x24, 0xFF, 0x05, color_code, 0xA1, 0xFF, 0x25]
                        elif command == "note":
                            message.bytes += [0x00]
                        elif command == "heart":
                            message.bytes += [0x90]
                        elif command == "star":
                            message.bytes += [0x91]
                        elif command == "up":
                            message.bytes += [0x92]
                        elif command == "down":
                            message.bytes += [0x93]
                        elif command == "left":
                            message.bytes += [0x94]
                        elif command == "right":
                            message.bytes += [0x95]
                        elif command == "circle":
                            message.bytes += [0x96]
                        elif command == "cross":
                            message.bytes += [0x97]
                        elif command == "wait":
                            print(f"{filename}:{lineno}: unknown command 'wait' (hint: did you mean 'prompt'?)")
                            exit(1)
                        elif command == "pause":
                            print(f"{filename}:{lineno}: unknown command 'pause' (hint: did you mean 'sleep'?)")
                            exit(1)
                        else:
                            print(f"{filename}:{lineno}: unknown command '{command}'")
                            exit(1)
                    else:
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
        messages.sort(key=lambda msg: bool(msg.section) + bool(msg.index))

        names = OrderedDict()

        sections = [] * 0x2E
        for message in messages:
            if message.section is None:
                # allocate a section
                for section_idx, section in enumerate(sections):
                    if len(section) < 0xFFF:
                        break
            else:
                section_idx = message.section
            while len(sections) <= section_idx:
                sections.append([])
            section = sections[section_idx]

            index = message.index if message.index is not None else len(section)

            if message.name:
                if message.name in names:
                    print(f"warning: multiple messages with name '{message.name}'")

                names[message.name] = (section_idx, index)

            section.append(bytes(message.bytes))

        f.seek((len(sections) + 1) * 4) # skip past table of contents

        section_offsets = []
        for section in sections:
            message_offsets = []
            for message in section:
                message_offsets.append(f.tell())
                f.write(message)

            section_offset = f.tell()
            section_offsets.append(section_offset)
            for offset in message_offsets:
                f.write(offset.to_bytes(4, byteorder="big"))
            f.write(section_offset.to_bytes(4, byteorder="big"))

            # padding
            while f.tell() % 0x10 != 0:
                f.write(b'\0\0\0\0')

        f.seek(0)
        for offset in section_offsets:
            f.write(offset.to_bytes(4, byteorder="big"))
        f.write(b'\0\0\0\0')

        with open(outheader, "w") as f:
            f.write(
                "#ifndef _MESSAGE_IDS_H_\n"
                "#define _MESSAGE_IDS_H_\n"
                "\n"
                '#include "messages.h"\n'
                "\n"
            )

            for name, i in names.items():
                section, index = i
                f.write(f"#define MessageID_{name} MESSAGE_ID({section}, {index})\n")

            f.write("\n#endif\n")
