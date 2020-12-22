from segtypes.segment import N64Segment
from pathlib import Path

CHARSET = {
    0x00: "𝅘𝅥𝅮",
    0x01: "!",
    0x02: '"',
    0x03: "#",
    0x04: "$",
    0x05: "%",
    0x06: "&",
    0x07: "'",
    0x08: "(",
    0x09: ")",
    0x0A: "*",
    0x0B: "+",
    0x0C: ",",
    0x0D: "-",
    0x0E: ".",
    0x0F: "/",
    0x10: "0",
    0x11: "1",
    0x12: "2",
    0x13: "3",
    0x14: "4",
    0x15: "5",
    0x16: "6",
    0x17: "7",
    0x18: "8",
    0x19: "9",
    0x1A: ":",
    0x1B: ";",
    0x1C: "<",
    0x1D: "=",
    0x1E: ">",
    0x1F: "?",
    0x20: "@",
    0x21: "A",
    0x22: "B",
    0x23: "C",
    0x24: "D",
    0x25: "E",
    0x26: "F",
    0x27: "G",
    0x28: "H",
    0x29: "I",
    0x2A: "J",
    0x2B: "K",
    0x2C: "L",
    0x2D: "M",
    0x2E: "N",
    0x2F: "O",
    0x30: "P",
    0x31: "Q",
    0x32: "R",
    0x33: "S",
    0x34: "T",
    0x35: "U",
    0x36: "V",
    0x37: "W",
    0x38: "X",
    0x39: "Y",
    0x3A: "Z",
    0x3B: "\\[",
    0x3C: "¥",
    0x3D: "]",
    0x3E: "^",
    0x3F: "_",
    0x40: "`",
    0x41: "a",
    0x42: "b",
    0x43: "c",
    0x44: "d",
    0x45: "e",
    0x46: "f",
    0x47: "g",
    0x48: "h",
    0x49: "i",
    0x4A: "j",
    0x4B: "k",
    0x4C: "l",
    0x4D: "m",
    0x4E: "n",
    0x4F: "o",
    0x50: "p",
    0x51: "q",
    0x52: "r",
    0x53: "s",
    0x54: "t",
    0x55: "u",
    0x56: "v",
    0x57: "w",
    0x58: "x",
    0x59: "y",
    0x5A: "z",
    0x5B: "{",
    0x5C: "|",
    0x5D: "}",
    0x5E: "~",
    0x5F: "°",
    0x60: "À",
    0x61: "Á",
    0x62: "Â",
    0x63: "Ä",
    0x64: "Ç",
    0x65: "È",
    0x66: "É",
    0x67: "Ê",
    0x68: "Ë",
    0x69: "Ì",
    0x6A: "Í",
    0x6B: "Î",
    0x6C: "Ï",
    0x6D: "Ñ",
    0x6E: "Ò",
    0x6F: "Ó",
    0x70: "Ô",
    0x71: "Ö",
    0x72: "Ù",
    0x73: "Ú",
    0x74: "Û",
    0x75: "Ü",
    0x76: "ß",
    0x77: "à",
    0x78: "á",
    0x79: "â",
    0x7A: "ä",
    0x7B: "ç",
    0x7C: "è",
    0x7D: "é",
    0x7E: "ê",
    0x7F: "ë",
    0x80: "ì",
    0x81: "í",
    0x82: "î",
    0x83: "ï",
    0x84: "ñ",
    0x85: "ò",
    0x86: "ó",
    0x87: "ô",
    0x88: "ö",
    0x89: "ù",
    0x8A: "ú",
    0x8B: "û",
    0x8C: "ü",
    0x8D: "¡",
    0x8E: "¿",
    0x8F: "ª",
    0x90: "♥",
    0x91: "★",
    0x92: "↑",
    0x93: "↓",
    0x94: "←",
    0x95: "→",
    0x96: "●",
    0x97: "✖",
    0xA2: "“",
    0xA3: "”",
    0xA4: "‘",
    0xA5: "’",
    0xF7: " ",
    0xF0: "[br]\n",
    0xF1: "[prompt]",
    0xF2: {None: lambda d: (f"[sleep {d[0]}]", 1)},
    0xFB: "[next]\n",
    0xFC: {
        0x01: "[style=right]\n",
        0x02: "[style=left]\n",
        0x03: "[style=center]\n",
        0x04: "[style=tattle]\n",
        0x05: {None: lambda d: (f"[style=choice x={d[0]} y={d[1]} w={d[2]} h={d[3]}]\n", 4)},
        0x06: "[style=inspect]\n",
        0x07: "[style=sign]\n",
        0x08: "[style=lamppost]\n",
        0x09: "[style=postcard]\n",
        0x0A: "[style=popup]\n",
        0x0C: {None: lambda d: (f"[style=upgrade x={d[1]} y={d[3]} w={d[0]} h={d[2]}]\n", 4)},
        0x0D: "[style=narrate]\n",
        0x0E: "[style=epilogue]\n",
    },
    0xFF: {
        0x00: {
            0: "[font=normal]",
            3: "[font=title]\n",
            4: "[font=subtitle]\n",
        },
        0x05: {
            0x0A: "[color=normal]",
            0x20: "[color=red]",
            0x21: "[color=pink]",
            0x22: "[color=purple]",
            0x23: "[color=blue]",
            0x24: "[color=cyan]",
            0x25: "[color=green]",
            0x26: "[color=yellow]",

            0x00: "[color=normal ctx=diary]",
            0x07: "[color=red ctx=diary]",

            0x17: "[color=dark ctx=inspect]",

            0x18: "[color=normal ctx=sign]",
            0x19: "[color=red ctx=sign]",
            0x1A: "[color=blue ctx=sign]",
            0x1B: "[color=green ctx=sign]",

            0x28: "[color=red ctx=popup]",
            0x29: "[color=pink ctx=popup]",
            0x2A: "[color=purple ctx=popup]",
            0x2B: "[color=blue ctx=popup]",
            0x2C: "[color=teal ctx=popup]",
            0x2D: "[color=green ctx=popup]",
            0x2E: "[color=yellow ctx=popup]",
            0x2F: "[color=normal ctx=popup]",
        },
        0x07: "[noskip]\n",
        0x08: "[/noskip]\n",
        0x09: "[instant]\n",
        0x0A: "[/instant]\n",
        0x0B: {None: lambda d: (f"[kerning={d[0]}]", 1)},
        0x0C: {None: lambda d: (f"[scroll {d[0]}]", 1)},
        0x0D: {None: lambda d: (f"[size x={d[0]} y={d[0]}]\n", 2)},
        0x0E: "[/size]\n",
        0x0F: {None: lambda d: (f"[speed delay={d[0]} chars={d[1]}]", 2)},
        0x10: {None: lambda d: (f"[pos x={d[0]} y={d[1]}]", 2)},
        0x11: {None: lambda d: (f"[pos y={d[0]}]", 1)},
        0x12: {None: lambda d: (f"[indent {d[0]}]", 1)},
        0x13: {None: lambda d: (f"[down {d[0]}]", 1)},
        0x14: {None: lambda d: (f"[up {d[0]}]", 1)},
        0x15: {None: lambda d: (f"[image {d[0]}]\n", 1)},
        0x16: {None: lambda d: (f"[sprite {d[0]} {d[1]} {d[2]}]\n", 3)},
        0x17: {None: lambda d: (f"[item {d[0]} {d[1]}]\n", 2)},
        0x18: {None: lambda d: (f"[image {d[0]} {d[1]} {d[2]} {d[3]} {d[4]} {d[5]} {d[6]}]\n", 7)},
        0x1E: {None: lambda d: (f"[cursor {d[0]}]", 1)},
        0x1F: {None: lambda d: (f"[choicecount={d[0]}]", 1)},
        0x20: {None: lambda d: (f"[cancel={d[0]}]", 1)},
        0x21: {None: lambda d: (f"[option {d[0]}]", 1)},
        0x24: {0xFF: {0x05: {
            0x10: {0x98: {0xFF: {0x25: "Ⓐ"}}},
            0x11: {0x99: {0xFF: {0x25: "Ⓑ"}}},
            0x12: {0xA1: {0xFF: {0x25: "Ⓢ"}}},
            0x13: {
                0x9D: {0xFF: {0x25: "▲"}},
                0x9E: {0xFF: {0x25: "▼"}},
                0x9F: {0xFF: {0x25: "◀"}},
                0xA0: {0xFF: {0x25: "▶"}},
            },
            0x14: {0x9C: {0xFF: {0x25: "Ⓩ"}}},
        }}},
        0x26: {
            0x00: "[shaky]",
            0x01: "[wavy]",
            0x03: {None: lambda d: (f"[noise fade={d[0]}]", 1)},
            0x05: {None: lambda d: (f"[faded-shaky fade={d[0]}]", 1)},
            0x07: {None: lambda d: (f"[fade={d[0]}]", 1)},
            0x0A: "[shout]",
            0x0B: "[whisper]",
            0x0C: "[scream]",
            0x0D: "[chortle]",
            0x0E: "[shadow]",
        },
        0x27: {
            0x00: "[/shaky]",
            0x01: "[/wavy]",
            0x03: "[/noise]",
            0x05: "[/faded-shaky]",
            0x07: "[/fade]",
            0x0A: "[/shout]",
            0x0B: "[/whisper]",
            0x0C: "[/scream]",
            0x0D: "[/chortle]",
            0x0E: "[/shadow]",
        },
        0x28: {None: lambda d: (f"[var {d[0]}]", 1)},
        0x29: {None: lambda d: (f"[center {d[0]}]", 1)},
        0x2E: {None: lambda d: (f"[volume={d[0]}]", 1)},
        0x2F: {
            1: "[sound=bowser]\n",
            2: "[sound=spirit]\n",
            None: lambda d: (f"[sound={d[0]}]\n", 1),
        },
        None: lambda d: (f"[func 0x{d[0]:X}]", 1),
    },
    None: lambda d: (f"[raw 0x{d[0]:02X}]", 1),
}

CHARSET_CREDITS = {
    **CHARSET,
    0x00: "A",
    0x01: "B",
    0x02: "C",
    0x03: "D",
    0x04: "E",
    0x05: "F",
    0x06: "G",
    0x07: "H",
    0x08: "I",
    0x09: "J",
    0x0A: "K",
    0x0B: "L",
    0x0C: "M",
    0x0D: "N",
    0x0E: "O",
    0x0F: "P",
    0x10: "Q",
    0x11: "R",
    0x12: "S",
    0x13: "T",
    0x14: "U",
    0x15: "V",
    0x16: "W",
    0x17: "X",
    0x18: "Y",
    0x19: "Z",
    0x1A: "'",
    0x1B: ".",
    0x1C: ",",
    0x1D: "0",
    0x1E: "1",
    0x1F: "2",
    0x20: "3",
    0x21: "4",
    0x22: "5",
    0x23: "6",
    0x24: "7",
    0x25: "8",
    0x26: "9",
    0x27: "©",
    0x28: "&",
    0xF7: " ",
}

class N64SegPaperMarioMessages(N64Segment):
    def __init__(self, segment, next_segment, options):
        super().__init__(segment, next_segment, options)
        self.files = segment.get("files", []) if type(segment) is dict else []

    def split(self, rom_bytes, base_path):
        data = rom_bytes[self.rom_start: self.rom_end]

        section_offsets = []
        pos = 0
        while True:
            offset = int.from_bytes(data[pos:pos+4], byteorder="big")

            if offset == 0:
                break

            section_offsets.append(offset)
            pos += 4

        for i, section_offset in enumerate(section_offsets):
            name = f"{i:02X}"
            if len(self.files) >= i:
                name = self.files[i]

            msg_offsets = []
            pos = section_offset
            while True:
                offset = int.from_bytes(data[pos:pos+4], byteorder="big")

                if offset == section_offset:
                    break

                msg_offsets.append(offset)
                pos += 4

            self.log(f"Reading {len(msg_offsets)} messages in section {name} (0x{i:02X})")

            path = Path(base_path, self.name, name + ".msg")
            path.parent.mkdir(parents=True, exist_ok=True)
            with open(path, "w") as self.f:
                for j, msg_offset in enumerate(msg_offsets):
                    if j != 0:
                        self.f.write("\n")
                    self.f.write(f"[message section=0x{i:02X} index={j}]\n")
                    self.write_message_markup(data[msg_offset:])
                    self.f.write("\n[/message]\n")

    def get_ld_files(self):
        return [("", self.name, ".data", self.rom_start)]

    @staticmethod
    def get_default_name(addr):
        return "msg"

    def write_message_markup(self, data):
        pos = 0
        self.root_charset = CHARSET

        while data[pos] != 0xFD:
            self.charset = self.root_charset

            while True:
                char = data[pos]

                if char in self.charset:
                    value = self.charset[char]
                elif None in self.charset:
                    value = self.charset[None]

                if value is None:
                    value = fallback

                if isinstance(value, str):
                    self.write_markup(value)
                    pos += 1
                    break
                elif callable(value):
                    markup, delta = value(data[pos:])
                    self.write_markup(markup)
                    pos += delta
                    break
                elif isinstance(value, dict):
                    if None in self.charset:
                        fallback = self.charset[None]
                    self.charset = value
                    pos += 1
                else:
                    raise ValueError(value)

    def write_markup(self, markup):
        self.f.write(markup)

        if markup == "[font=title]\n" or markup == "[font=subtitle]\n":
            self.root_charset = CHARSET_CREDITS
        elif markup == "[font=normal]":
            self.root_charset = CHARSET
