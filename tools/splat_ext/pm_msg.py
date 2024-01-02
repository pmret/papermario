import shutil
from splat.segtypes.n64.segment import N64Segment
from pathlib import Path
from splat.util import options
import re

import pylibyaml
import yaml as yaml_loader


CHARSET_COMMON = {
    0xF7: " ",
    0xF0: "[BR]\n",
    0xF1: "[Wait]",
    0xF2: {None: lambda d: (f"[Pause {d[0]}]", 1)},
    0xF3: "[Variant0]",
    0xF4: "[Variant1]",
    0xF5: "[Variant2]",
    0xF6: "[Variant3]",
    0xFB: "[Next]\n",
    0xFC: {
        0x01: "[Style right]\n",
        0x02: "[Style left]\n",
        0x03: "[Style center]\n",
        0x04: "[Style tattle]\n",
        0x05: {
            None: lambda d: (
                f"[Style choice pos={d[0]},{d[1]} size={d[2]},{d[3]}]\n",
                4,
            )
        },
        0x06: "[Style inspect]\n",
        0x07: "[Style sign]\n",
        0x08: {None: lambda d: (f"[Style lamppost height={d[0]}]\n", 1)},
        0x09: {None: lambda d: (f"[Style postcard index={d[0]}]\n", 1)},
        0x0A: "[Style popup]\n",
        0x0B: "[Style popup2]\n",
        0x0C: {
            None: lambda d: (
                f"[Style upgrade pos={d[0]},{d[1]} size={d[2]},{d[3]}]\n",
                4,
            )
        },
        0x0D: "[Style narrate]\n",
        0x0E: "[Style epilogue]\n",
    },
    0xFF: {
        0x00: {
            0: "[Font standard]\n",
            1: "[Font menu]\n",
            2: "[Font menu2]\n",
            3: "[Font title]\n",
            4: "[Font subtitle]\n",
        },
        0x04: "[Yield]",
        0x05: {
            # 0x0A: "[color:normal]",
            # 0x20: "[color:red]",
            # 0x21: "[color:pink]",
            # 0x22: "[color:purple]",
            # 0x23: "[color:blue]",
            # 0x24: "[color:cyan]",
            # 0x25: "[color:green]",
            # 0x26: "[color:yellow]",
            # 0x00: "[color=normal ctx=diary]",
            # 0x07: "[color=red ctx=diary]",
            # 0x17: "[color=dark ctx=inspect]",
            # 0x18: "[color=normal ctx=sign]",
            # 0x19: "[color=red ctx=sign]",
            # 0x1A: "[color=blue ctx=sign]",
            # 0x1B: "[color=green ctx=sign]",
            # 0x28: "[color=red ctx=popup]",
            # 0x29: "[color=pink ctx=popup]",
            # 0x2A: "[color=purple ctx=popup]",
            # 0x2B: "[color=blue ctx=popup]",
            # 0x2C: "[color=teal ctx=popup]",
            # 0x2D: "[color=green ctx=popup]",
            # 0x2E: "[color=yellow ctx=popup]",
            # 0x2F: "[color=normal ctx=popup]",
            None: lambda d: (f"[Color 0x{d[0]:X}]", 1),
        },
        0x07: "[InputOff]\n",
        0x08: "[InputOn]\n",
        0x09: "[DelayOff]\n",
        0x0A: "[DelayOn]\n",
        0x0B: {None: lambda d: (f"[CharWidth {d[0]}]", 1)},
        0x0C: {None: lambda d: (f"[Scroll {d[0]}]", 1)},
        0x0D: {None: lambda d: (f"[Size {d[0]},{d[1]}]\n", 2)},
        0x0E: "[SizeReset]\n",
        0x0F: {None: lambda d: (f"[Speed delay={d[0]} chars={d[1]}]", 2)},
        0x10: {None: lambda d: (f"[SetPosX {(d[0] << 8) + d[1]}]", 2)},
        0x11: {None: lambda d: (f"[SetPosY {d[0]}]", 1)},
        0x12: {None: lambda d: (f"[Right {d[0]}]", 1)},
        0x13: {None: lambda d: (f"[Down {d[0]}]", 1)},
        0x14: {None: lambda d: (f"[Up {d[0]}]", 1)},
        0x15: {None: lambda d: (f"[InlineImage index={d[0]}]\n", 1)},
        0x16: {
            None: lambda d: (
                f"[AnimSprite spriteID=0x{d[0]:02X}{d[1]:02X} raster={d[2]}]\n",
                3,
            )
        },
        0x17: {None: lambda d: (f"[ItemIcon itemID=0x{d[0]:02X}{d[1]:02X}]\n", 2)},
        0x18: {
            None: lambda d: (
                f"[Image index={d[0]} pos={(d[1] << 8) + d[2]},{d[3]} hasBorder={d[4]} alpha={d[5]} fadeAmount={d[6]}]\n",
                7,
            )
        },
        0x19: {None: lambda d: (f"[HideImage fadeAmount={d[0]}]\n", 1)},
        0x1A: {None: lambda d: (f"[AnimDelay index={d[1]} delay={d[2]}]", 3)},
        0x1B: {None: lambda d: (f"[AnimLoop {d[0]} {d[1]}]", 2)},
        0x1C: {None: lambda d: (f"[AnimDone {d[0]}]", 1)},
        0x1E: {None: lambda d: (f"[Cursor {d[0]}]", 1)},
        0x1F: {None: lambda d: (f"[EndChoice {d[0]}]", 1)},
        0x20: {None: lambda d: (f"[SetCancel {d[0]}]", 1)},
        0x21: {None: lambda d: (f"[Option {d[0]}]", 1)},
        0x22: "[SavePos]",
        0x23: "[RestorePos]",
        0x24: {
            0xFF: {
                0x05: {
                    0x10: {0x98: {0xFF: {0x25: "[A]"}}},
                    0x11: {0x99: {0xFF: {0x25: "[B]"}}},
                    0x12: {0xA1: {0xFF: {0x25: "[START]"}}},
                    0x13: {
                        0x9D: {0xFF: {0x25: "[C-UP]"}},
                        0x9E: {0xFF: {0x25: "[C-DOWN]"}},
                        0x9F: {0xFF: {0x25: "[C-LEFT]"}},
                        0xA0: {0xFF: {0x25: "[C-RIGHT]"}},
                    },
                    0x14: {0x9C: {0xFF: {0x25: "[Z]"}}},
                }
            }
        },
        # 0x24: "[SaveColor]",
        # 0x25: "[RestoreColor]",
        0x26: {
            0x00: "[Shake]",
            0x01: "[Wave]",
            0x02: "[NoiseOutline]",
            0x03: {None: lambda d: (f"[Static {d[0]}]", 1)},
            0x05: {None: lambda d: (f"[Blur dir={['x', 'y', 'xy'][d[0]]}]", 1)},
            0x07: {None: lambda d: (f"[DitherFade {d[0]}]", 1)},
            0x0A: "[PrintRising]",
            0x0B: "[PrintGrowing]",
            0x0C: "[SizeJitter]",
            0x0D: "[SizeWave]",
            0x0E: "[DropShadow]",
        },
        0x27: {
            0x00: "[/Shake]",
            0x01: "[/Wave]",
            0x03: "[/Static]",
            0x05: "[/Blur]",
            0x07: "[/DitherFade]",
            0x0A: "[/PrintRising]",
            0x0B: "[/PrintGrowing]",
            0x0C: "[/SizeJitter]",
            0x0D: "[/SizeWave]",
            0x0E: "[/DropShadow]",
        },
        0x28: {None: lambda d: (f"[Var {d[0]}]", 1)},
        0x29: {None: lambda d: (f"[CenterX {d[0]}]", 1)},
        0x2B: "[EnableCDownNext]",
        0x2C: {
            None: lambda d: (
                f"[CustomVoice soundIDs=0x{d[0]:02X}{d[1]:02X}{d[2]:02X}{d[3]:02X},0x{d[4]:02X}{d[5]:02X}{d[6]:02X}{d[7]:02X}]",
                8,
            )
        },
        0x2E: {None: lambda d: (f"[Volume {d[0]}]", 1)},
        0x2F: {
            0: "[Voice normal]\n",
            1: "[Voice bowser]\n",
            2: "[Voice star]\n",
            None: lambda d: (f"[Voice {d[0]}]\n", 1),
        },
        # None: lambda d: (f"[func_{d[0]:02X}]", 1),
    },
    None: lambda d: (f"[Raw 0x{d[0]:02X}]", 1),
}

CHARSET_STANDARD = {
    **CHARSET_COMMON,
    0x00: "[NOTE]",
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
    0x90: "[HEART]",
    0x91: "[STAR]",
    0x92: "[UP]",
    0x93: "[DOWN]",
    0x94: "[LEFT]",
    0x95: "[RIGHT]",
    0x96: "[CIRCLE]",
    0x97: "[CROSS]",
    0x98: "[~A]",
    0x99: "[~B]",
    0x9A: "[~L]",
    0x9B: "[~R]",
    0x9C: "[~Z]",
    0x9D: "[~C-UP]",
    0x9E: "[~C-DOWN]",
    0x9F: "[~C-LEFT]",
    0xA0: "[~C-RIGHT]",
    0xA1: "[~START]",
    0xA2: "“",
    0xA3: "”",
    0xA4: "‘",
    0xA5: "’",
}

CHARSET_CREDITS = {
    **CHARSET_COMMON,
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
}

CHARSET_JP_COMMON = {
    **CHARSET_COMMON,
    0xF3: "[Charset Kana]",
    0xF4: "[Charset Latin]",
    0xF5: "[Charset Kanji]",
    0xF6: "[Charset Buttons]",
    0xF7: " ",
    0xF8: "　",
    0xF9: "[HALFSPACE]",
    0xFF: {
        **CHARSET_COMMON[0xFF],
        0x24: {
            0xFF: {
                0x05: {
                    0x10: {0xF6: {0x00: {0xFF: {0x25: "[A]"}}}},
                    0x11: {0xF6: {0x01: {0xFF: {0x25: "[B]"}}}},
                    0x12: {0xF6: {0x02: {0xFF: {0x25: "[START]"}}}},
                    0x13: {
                        0xF6: {
                            0x03: {0xFF: {0x25: "[C-UP]"}},
                            0x04: {0xFF: {0x25: "[C-DOWN]"}},
                            0x05: {0xFF: {0x25: "[C-LEFT]"}},
                            0x06: {0xFF: {0x25: "[C-RIGHT]"}},
                        }
                    },
                    0x14: {
                        0xF6: {
                            0x07: {0xFF: {0x25: "[Z]"}},
                            0x08: {0xFF: {0x25: "[L]"}},
                            0x09: {0xFF: {0x25: "[R]"}},
                        }
                    },
                }
            }
        },
    },
}

CHARSET_KANA = {
    **CHARSET_JP_COMMON,
    0x00: "あ",
    0x01: "い",
    0x02: "う",
    0x03: "え",
    0x04: "お",
    0x05: "か",
    0x06: "き",
    0x07: "く",
    0x08: "け",
    0x09: "こ",
    0x0A: "さ",
    0x0B: "し",
    0x0C: "す",
    0x0D: "せ",
    0x0E: "そ",
    0x0F: "た",
    0x10: "ち",
    0x11: "つ",
    0x12: "て",
    0x13: "と",
    0x14: "な",
    0x15: "に",
    0x16: "ぬ",
    0x17: "ね",
    0x18: "の",
    0x19: "は",
    0x1A: "ひ",
    0x1B: "ふ",
    0x1C: "へ",
    0x1D: "ほ",
    0x1E: "ま",
    0x1F: "み",
    0x20: "む",
    0x21: "め",
    0x22: "も",
    0x23: "や",
    0x24: "ゆ",
    0x25: "よ",
    0x26: "ら",
    0x27: "り",
    0x28: "る",
    0x29: "れ",
    0x2A: "ろ",
    0x2B: "わ",
    0x2C: "を",
    0x2D: "ん",
    0x2E: "ゔ",
    0x2F: "が",
    0x30: "ぎ",
    0x31: "ぐ",
    0x32: "げ",
    0x33: "ご",
    0x34: "ざ",
    0x35: "じ",
    0x36: "ず",
    0x37: "ぜ",
    0x38: "ぞ",
    0x39: "だ",
    0x3A: "ぢ",
    0x3B: "づ",
    0x3C: "で",
    0x3D: "ど",
    0x3E: "ば",
    0x3F: "び",
    0x40: "ぶ",
    0x41: "べ",
    0x42: "ぼ",
    0x43: "ぱ",
    0x44: "ぴ",
    0x45: "ぷ",
    0x46: "ぺ",
    0x47: "ぽ",
    0x48: "ぁ",
    0x49: "ぃ",
    0x4A: "ぅ",
    0x4B: "ぇ",
    0x4C: "ぉ",
    0x4D: "っ",
    0x4E: "ゃ",
    0x4F: "ゅ",
    0x50: "ょ",
    0x51: "ア",
    0x52: "イ",
    0x53: "ウ",
    0x54: "エ",
    0x55: "オ",
    0x56: "カ",
    0x57: "キ",
    0x58: "ク",
    0x59: "ケ",
    0x5A: "コ",
    0x5B: "サ",
    0x5C: "シ",
    0x5D: "ス",
    0x5E: "セ",
    0x5F: "ソ",
    0x60: "タ",
    0x61: "チ",
    0x62: "ツ",
    0x63: "テ",
    0x64: "ト",
    0x65: "ナ",
    0x66: "ニ",
    0x67: "ヌ",
    0x68: "ネ",
    0x69: "ノ",
    0x6A: "ハ",
    0x6B: "ヒ",
    0x6C: "フ",
    0x6D: "ヘ",
    0x6E: "ホ",
    0x6F: "マ",
    0x70: "ミ",
    0x71: "ム",
    0x72: "メ",
    0x73: "モ",
    0x74: "ヤ",
    0x75: "ユ",
    0x76: "ヨ",
    0x77: "ラ",
    0x78: "リ",
    0x79: "ル",
    0x7A: "レ",
    0x7B: "ロ",
    0x7C: "ワ",
    0x7D: "ヲ",
    0x7E: "ン",
    0x7F: "ヴ",
    0x80: "ガ",
    0x81: "ギ",
    0x82: "グ",
    0x83: "ゲ",
    0x84: "ゴ",
    0x85: "ザ",
    0x86: "ジ",
    0x87: "ズ",
    0x88: "ゼ",
    0x89: "ゾ",
    0x8A: "ダ",
    0x8B: "ヂ",
    0x8C: "ヅ",
    0x8D: "デ",
    0x8E: "ド",
    0x8F: "バ",
    0x90: "ビ",
    0x91: "ブ",
    0x92: "ベ",
    0x93: "ボ",
    0x94: "パ",
    0x95: "ピ",
    0x96: "プ",
    0x97: "ペ",
    0x98: "ポ",
    0x99: "ァ",
    0x9A: "ィ",
    0x9B: "ゥ",
    0x9C: "ェ",
    0x9D: "ォ",
    0x9E: "ッ",
    0x9F: "ャ",
    0xA0: "ュ",
    0xA1: "ョ",
    0xA2: "ー",
    0xA3: "～",
    0xA4: {0xA5: {0xA6: "[LONGDASH]"}},
    0xA7: "０",
    0xA8: "１",
    0xA9: "２",
    0xAA: "３",
    0xAB: "４",
    0xAC: "５",
    0xAD: "６",
    0xAE: "７",
    0xAF: "８",
    0xB0: "９",
    0xB1: "[UP]",
    0xB2: "[DOWN]",
    0xB3: "[LEFT]",
    0xB4: "[RIGHT]",
    0xB5: "！",
    0xB6: "？",
    0xB7: "＋",
    0xB8: "－",
    0xB9: "／",
    0xBA: "．",
    0xBB: "＆",
    0xBC: "＃",
    0xBD: "[HEART]",
    0xBE: "[STAR]",
    0xBF: "（",
    0xC0: "）",
    0xC1: "『",
    0xC2: "』",
    0xC3: "・",
    0xC4: "[HIRAGANA SmallN]",
    0xC5: "[KATAKANA SmallN]",
    # existing characters without small counterparts
    # 0xC4: "ん",
    # 0xC5: "ン",
    0xC6: "星",
    # 0xC7 is unused
}

CHARSET_LATIN = {
    **CHARSET_JP_COMMON,
    0x00: "Ａ",
    0x01: "Ｂ",
    0x02: "Ｃ",
    0x03: "Ｄ",
    0x04: "Ｅ",
    0x05: "Ｆ",
    0x06: "Ｇ",
    0x07: "Ｈ",
    0x08: "Ｉ",
    0x09: "Ｊ",
    0x0A: "Ｋ",
    0x0B: "Ｌ",
    0x0C: "Ｍ",
    0x0D: "Ｎ",
    0x0E: "Ｏ",
    0x0F: "Ｐ",
    0x10: "Ｑ",
    0x11: "Ｒ",
    0x12: "Ｓ",
    0x13: "Ｔ",
    0x14: "Ｕ",
    0x15: "Ｖ",
    0x16: "Ｗ",
    0x17: "Ｘ",
    0x18: "Ｙ",
    0x19: "Ｚ",
    0x1A: "ｚ",
}

CHARSET_KANJI = {
    **CHARSET_JP_COMMON,
    0x00: "上",
    0x01: "下",
    0x02: "左",
    0x03: "右",
    0x04: "中",
    0x05: "東",
    0x06: "西",
    0x07: "南",
    0x08: "北",
    0x09: "一",
    0x0A: "二",
    0x0B: "三",
    0x0C: "名",
    0x0D: "国",
    0x0E: "城",
    0x0F: "姫",
    0x10: "大",
    0x11: "王",
    0x12: "花",
    0x13: "世",
    0x14: "界",
    0x15: "草",
    0x16: "気",
    0x17: "間",
    0x18: "門",
    0x19: "家",
    0x1A: "地",
    0x1B: "岩",
    0x1C: "駅",
    0x1D: "山",
    0x1E: "海",
    0x1F: "火",
    0x20: "水",
    0x21: "氷",
    0x22: "日",
    0x23: "根",
    0x24: "雲",
    0x25: "口",
    0x26: "原",
    0x27: "前",
    0x28: "店",
    0x29: "天",
    0x2A: "森",
    0x2B: "木",
    0x2C: "力",
    0x2D: "空",
    0x2E: "人",
    0x2F: "島",
    0x30: "出",
    0x31: "入",
    0x32: "本",
    0x33: "石",
    0x34: "村",
    0x35: "休",
    0x36: "先",
    0x37: "見",
    0x38: "近",
    0x39: "方",
    0x3A: "法",
    0x3B: "手",
    0x3C: "紙",
    0x3D: "引",
    0x3E: "場",
    0x3F: "所",
    0x40: "使",
    0x41: "回",
    0x42: "道",
    0x43: "物",
    0x44: "弟",
    0x45: "子",
    0x46: "汽",
    0x47: "車",
    0x48: "何",
    0x49: "黒",
    0x4A: "分",
    0x4B: "時",
    0x4C: "屋",
    0x4D: "音",
    0x4E: "目",
    0x4F: "行",
    0x50: "絵",
    0x51: "月",
    0x52: "野",
    0x53: "外",
    0x54: "図",
    0x55: "部",
    0x56: "小",
    0x57: "風",
    0x58: "魔",
    0x59: "元",
    0x5A: "太",
    0x5B: "陽",
    0x5C: "実",
    0x5D: "赤",
    0x5E: "雪",
    0x5F: "谷",
    0x60: "通",
    0x61: "[CIRCLE]",
    0x62: "[CROSS]",
    0x63: "長",
    0x64: "話",
    0x65: "色",
    0x66: "光",
    0x67: "合",
    0x68: "青",
    0x69: "黄",
    0x6A: "[NOTE]",
    0x6B: "当",
    0x6C: "数",
    0x6D: "兄",
    0x6E: "用",
    0x6F: "心",
    0x70: "今",
    0x71: "正",
    0x72: "直",
    0x73: "全",
    0x74: "体",
    0x75: "夜",
    0x76: "面",
    0x77: "虫",
    0x78: "ｘ",
}

CHARSET_BUTTONS = {
    **CHARSET_JP_COMMON,
    0x00: "[~A]",
    0x01: "[~B]",
    0x02: "[~START]",
    0x03: "[~C-UP]",
    0x04: "[~C-DOWN]",
    0x05: "[~C-LEFT]",
    0x06: "[~C-RIGHT]",
    0x07: "[~Z]",
    0x08: "[~L]",
    0x09: "[~R]",
}


class N64SegPm_msg(N64Segment):
    def __init__(
        self,
        rom_start,
        rom_end,
        type,
        name,
        vram_start,
        args,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

        self.files = yaml.get("files", []) if isinstance(yaml, dict) else []

        with (Path(__file__).parent / f"{self.name}.yaml").open("r") as f:
            self.msg_names = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

    def split(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]

        section_offsets = []
        pos = 0
        while True:
            offset = int.from_bytes(data[pos : pos + 4], byteorder="big")

            if offset == 0:
                break

            section_offsets.append(offset)
            pos += 4

        msg_dir = options.opts.asset_path / self.name
        msg_dir.mkdir(parents=True, exist_ok=True)

        for i, section_offset in enumerate(section_offsets):
            name = f"{i:02X}"
            if len(self.files) >= i:
                name = self.files[i]

            msg_offsets = []
            pos = section_offset
            while True:
                offset = int.from_bytes(data[pos : pos + 4], byteorder="big")

                if offset == section_offset:
                    break

                msg_offsets.append(offset)
                pos += 4

            # self.log(f"Reading {len(msg_offsets)} messages in section {name} (0x{i:02X})")

            path = msg_dir / Path(name + ".msg")

            with open(path, "w") as self.f:
                for j, msg_offset in enumerate(msg_offsets):
                    if j != 0:
                        self.f.write("\n")

                    msg_name = None
                    for d in self.msg_names:
                        section, index, goodname = d[:3]

                        if i == section and j == index:
                            msg_name = goodname
                            break

                    if msg_name is None:
                        self.f.write(f"#message:{i:02X}:{j:03X} {{\n\t")
                    else:
                        self.f.write(f"#message:{i:02X}:({msg_name}) {{\n\t")
                    self.write_message_markup(data[msg_offset:])
                    self.f.write("\n}\n")

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        base_path = options.opts.asset_path / f"{self.name}"
        out_paths = [base_path / Path(f + ".msg") for f in self.files]

        return [LinkerEntry(self, out_paths, base_path, ".data", ".data")]

    @staticmethod
    def get_default_name(addr):
        return "msg"

    def write_message_markup(self, data):
        pos = 0
        if "ver/jp" in str(options.opts.target_path):
            self.root_charset = CHARSET_KANA
        else:
            self.root_charset = CHARSET_STANDARD

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

        self.write_markup("[End]")

    def write_markup(self, markup):
        self.f.write(re.sub("\n", "\n\t", markup))

        markup_lower = markup.lower()

        if markup_lower == "[font title]\n" or markup_lower == "[font subtitle]\n":
            self.root_charset = CHARSET_CREDITS
        elif markup_lower == "[font standard]":
            self.root_charset = CHARSET_STANDARD
        elif "ver/jp" in str(options.opts.target_path):
            if markup_lower == "[charset kana]":
                self.root_charset = CHARSET_KANA
            elif markup_lower == "[charset latin]":
                self.root_charset = CHARSET_LATIN
            elif markup_lower == "[charset kanji]":
                self.root_charset = CHARSET_KANJI
            elif markup_lower == "[charset buttons]":
                self.root_charset = CHARSET_BUTTONS

    def cache(self):
        return (self.yaml, self.rom_end, self.msg_names)
