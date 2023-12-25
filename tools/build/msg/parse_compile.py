#!/usr/bin/env python3

from sys import argv
from collections import OrderedDict
import re
import msgpack  # way faster than pickle


class Message:
    def __init__(self, name, section, index):
        self.name = name
        self.section = section
        self.index = index

        self.bytes = []  # XXX: bytearray would be better


def try_convert_int(s):
    try:
        return int(s, base=0)
    except:
        return s


def parse_command(source):
    if source[0] != "[":
        return None, [], {}, source
    source = source[1:]  # "["

    inside_brackets = ""
    while source[0] != "]":
        if source[0] == "\n":
            return None, [], {}, source

        inside_brackets += source[0]
        source = source[1:]
    source = source[1:]  # "]"

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
        },
    }

    if type(color) is int:
        return color

    return COLORS.get(
        style,
        {
            # [style:left], [style:right]
            "normal": 0x0A,
            "red": 0x20,
            "pink": 0x21,
            "purple": 0x22,
            "blue": 0x23,
            "cyan": 0x24,
            "green": 0x25,
            "yellow": 0x26,
        },
    ).get(color)


CHARSET_STANDARD = {
    # "𝅘𝅥𝅮": 0x00,
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
    "　": 0xF7,
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
    "　": 0xF8,
}

CHARSET_KANA = {
    "あ": 0x00,
    "い": 0x01,
    "う": 0x02,
    "え": 0x03,
    "お": 0x04,
    "か": 0x05,
    "き": 0x06,
    "く": 0x07,
    "け": 0x08,
    "こ": 0x09,
    "さ": 0x0A,
    "し": 0x0B,
    "す": 0x0C,
    "せ": 0x0D,
    "そ": 0x0E,
    "た": 0x0F,
    "ち": 0x10,
    "つ": 0x11,
    "て": 0x12,
    "と": 0x13,
    "な": 0x14,
    "に": 0x15,
    "ぬ": 0x16,
    "ね": 0x17,
    "の": 0x18,
    "は": 0x19,
    "ひ": 0x1A,
    "ふ": 0x1B,
    "へ": 0x1C,
    "ほ": 0x1D,
    "ま": 0x1E,
    "み": 0x1F,
    "む": 0x20,
    "め": 0x21,
    "も": 0x22,
    "や": 0x23,
    "ゆ": 0x24,
    "よ": 0x25,
    "ら": 0x26,
    "り": 0x27,
    "る": 0x28,
    "れ": 0x29,
    "ろ": 0x2A,
    "わ": 0x2B,
    "を": 0x2C,
    "ん": 0x2D,
    "ゔ": 0x2E,
    "が": 0x2F,
    "ぎ": 0x30,
    "ぐ": 0x31,
    "げ": 0x32,
    "ご": 0x33,
    "ざ": 0x34,
    "じ": 0x35,
    "ず": 0x36,
    "ぜ": 0x37,
    "ぞ": 0x38,
    "だ": 0x39,
    "ぢ": 0x3A,
    "づ": 0x3B,
    "で": 0x3C,
    "ど": 0x3D,
    "ば": 0x3E,
    "び": 0x3F,
    "ぶ": 0x40,
    "べ": 0x41,
    "ぼ": 0x42,
    "ぱ": 0x43,
    "ぴ": 0x44,
    "ぷ": 0x45,
    "ぺ": 0x46,
    "ぽ": 0x47,
    "ぁ": 0x48,
    "ぃ": 0x49,
    "ぅ": 0x4A,
    "ぇ": 0x4B,
    "ぉ": 0x4C,
    "っ": 0x4D,
    "ゃ": 0x4E,
    "ゅ": 0x4F,
    "ょ": 0x50,
    "ア": 0x51,
    "イ": 0x52,
    "ウ": 0x53,
    "エ": 0x54,
    "オ": 0x55,
    "カ": 0x56,
    "キ": 0x57,
    "ク": 0x58,
    "ケ": 0x59,
    "コ": 0x5A,
    "サ": 0x5B,
    "シ": 0x5C,
    "ス": 0x5D,
    "セ": 0x5E,
    "ソ": 0x5F,
    "タ": 0x60,
    "チ": 0x61,
    "ツ": 0x62,
    "テ": 0x63,
    "ト": 0x64,
    "ナ": 0x65,
    "ニ": 0x66,
    "ヌ": 0x67,
    "ネ": 0x68,
    "ノ": 0x69,
    "ハ": 0x6A,
    "ヒ": 0x6B,
    "フ": 0x6C,
    "ヘ": 0x6D,
    "ホ": 0x6E,
    "マ": 0x6F,
    "ミ": 0x70,
    "ム": 0x71,
    "メ": 0x72,
    "モ": 0x73,
    "ヤ": 0x74,
    "ユ": 0x75,
    "ヨ": 0x76,
    "ラ": 0x77,
    "リ": 0x78,
    "ル": 0x79,
    "レ": 0x7A,
    "ロ": 0x7B,
    "ワ": 0x7C,
    "ヲ": 0x7D,
    "ン": 0x7E,
    "ヴ": 0x7F,
    "ガ": 0x80,
    "ギ": 0x81,
    "グ": 0x82,
    "ゲ": 0x83,
    "ゴ": 0x84,
    "ザ": 0x85,
    "ジ": 0x86,
    "ズ": 0x87,
    "ゼ": 0x88,
    "ゾ": 0x89,
    "ダ": 0x8A,
    "ヂ": 0x8B,
    "ヅ": 0x8C,
    "デ": 0x8D,
    "ド": 0x8E,
    "バ": 0x8F,
    "ビ": 0x90,
    "ブ": 0x91,
    "ベ": 0x92,
    "ボ": 0x93,
    "パ": 0x94,
    "ピ": 0x95,
    "プ": 0x96,
    "ペ": 0x97,
    "ポ": 0x98,
    "ァ": 0x99,
    "ィ": 0x9A,
    "ゥ": 0x9B,
    "ェ": 0x9C,
    "ォ": 0x9D,
    "ッ": 0x9E,
    "ャ": 0x9F,
    "ュ": 0xA0,
    "ョ": 0xA1,
    "ー": 0xA2,
    "～": 0xA3,
    "~": 0xA3,
    # "―": 0xA4,
    # "―": 0xA5,
    # "―": 0xA6,
    "０": 0xA7,
    "0": 0xA7,
    "１": 0xA8,
    "1": 0xA8,
    "２": 0xA9,
    "2": 0xA9,
    "３": 0xAA,
    "3": 0xAA,
    "４": 0xAB,
    "4": 0xAB,
    "５": 0xAC,
    "5": 0xAC,
    "６": 0xAD,
    "6": 0xAD,
    "７": 0xAE,
    "7": 0xAE,
    "８": 0xAF,
    "8": 0xAF,
    "９": 0xB0,
    "9": 0xB0,
    "[up]": 0xB1,
    "[down]": 0xB2,
    "[left]": 0xB3,
    "[right]": 0xB4,
    "！": 0xB5,
    "!": 0xB5,
    "？": 0xB6,
    "?": 0xB6,
    "＋": 0xB7,
    "+": 0xB7,
    "－": 0xB8,
    "／": 0xB9,
    "/": 0xB9,
    "．": 0xBA,
    ".": 0xBA,
    "＆": 0xBB,
    "&": 0xBB,
    "＃": 0xBC,
    "#": 0xBC,
    "[heart]": 0xBD,
    "[star]": 0xBE,
    "（": 0xBF,
    "(": 0xBF,
    "）": 0xC0,
    ")": 0xC0,
    "『": 0xC1,
    "』": 0xC2,
    "・": 0xC3,
    "[hiragana smalln]": 0xC4,
    "[katakana smalln]": 0xC5,
    "星": 0xC6,
    # 0xC7 is unused
    " ": 0xF7,
    "　": 0xF8,
}

CHARSET_LATIN = {
    "A": 0x00,
    "Ａ": 0x00,
    "B": 0x01,
    "Ｂ": 0x01,
    "C": 0x02,
    "Ｃ": 0x02,
    "D": 0x03,
    "Ｄ": 0x03,
    "E": 0x04,
    "Ｅ": 0x04,
    "F": 0x05,
    "Ｆ": 0x05,
    "G": 0x06,
    "Ｇ": 0x06,
    "H": 0x07,
    "Ｈ": 0x07,
    "I": 0x08,
    "Ｉ": 0x08,
    "J": 0x09,
    "Ｊ": 0x09,
    "K": 0x0A,
    "Ｋ": 0x0A,
    "L": 0x0B,
    "Ｌ": 0x0B,
    "M": 0x0C,
    "Ｍ": 0x0C,
    "N": 0x0D,
    "Ｎ": 0x0D,
    "O": 0x0E,
    "Ｏ": 0x0E,
    "P": 0x0F,
    "Ｐ": 0x0F,
    "Q": 0x10,
    "Ｑ": 0x10,
    "R": 0x11,
    "Ｒ": 0x11,
    "S": 0x12,
    "Ｓ": 0x12,
    "T": 0x13,
    "Ｔ": 0x13,
    "U": 0x14,
    "Ｕ": 0x14,
    "V": 0x15,
    "Ｖ": 0x15,
    "W": 0x16,
    "Ｗ": 0x16,
    "X": 0x17,
    "Ｘ": 0x17,
    "Y": 0x18,
    "Ｙ": 0x18,
    "Z": 0x19,
    "Ｚ": 0x19,
    "z": 0x1A,
    "ｚ": 0x1A,
    " ": 0xF7,
    "　": 0xF8,
}

CHARSET_KANJI = {
    "上": 0x00,
    "下": 0x01,
    "左": 0x02,
    "右": 0x03,
    "中": 0x04,
    "東": 0x05,
    "西": 0x06,
    "南": 0x07,
    "北": 0x08,
    "一": 0x09,
    "二": 0x0A,
    "三": 0x0B,
    "名": 0x0C,
    "国": 0x0D,
    "城": 0x0E,
    "姫": 0x0F,
    "大": 0x10,
    "王": 0x11,
    "花": 0x12,
    "世": 0x13,
    "界": 0x14,
    "草": 0x15,
    "気": 0x16,
    "間": 0x17,
    "門": 0x18,
    "家": 0x19,
    "地": 0x1A,
    "岩": 0x1B,
    "駅": 0x1C,
    "山": 0x1D,
    "海": 0x1E,
    "火": 0x1F,
    "水": 0x20,
    "氷": 0x21,
    "日": 0x22,
    "根": 0x23,
    "雲": 0x24,
    "口": 0x25,
    "原": 0x26,
    "前": 0x27,
    "店": 0x28,
    "天": 0x29,
    "森": 0x2A,
    "木": 0x2B,
    "力": 0x2C,
    "空": 0x2D,
    "人": 0x2E,
    "島": 0x2F,
    "出": 0x30,
    "入": 0x31,
    "本": 0x32,
    "石": 0x33,
    "村": 0x34,
    "休": 0x35,
    "先": 0x36,
    "見": 0x37,
    "近": 0x38,
    "方": 0x39,
    "法": 0x3A,
    "手": 0x3B,
    "紙": 0x3C,
    "引": 0x3D,
    "場": 0x3E,
    "所": 0x3F,
    "使": 0x40,
    "回": 0x41,
    "道": 0x42,
    "物": 0x43,
    "弟": 0x44,
    "子": 0x45,
    "汽": 0x46,
    "車": 0x47,
    "何": 0x48,
    "黒": 0x49,
    "分": 0x4A,
    "時": 0x4B,
    "屋": 0x4C,
    "音": 0x4D,
    "目": 0x4E,
    "行": 0x4F,
    "絵": 0x50,
    "月": 0x51,
    "野": 0x52,
    "外": 0x53,
    "図": 0x54,
    "部": 0x55,
    "小": 0x56,
    "風": 0x57,
    "魔": 0x58,
    "元": 0x59,
    "太": 0x5A,
    "陽": 0x5B,
    "実": 0x5C,
    "赤": 0x5D,
    "雪": 0x5E,
    "谷": 0x5F,
    "通": 0x60,
    "[circle]": 0x61,
    "[cross]": 0x62,
    "長": 0x63,
    "話": 0x64,
    "色": 0x65,
    "光": 0x66,
    "合": 0x67,
    "青": 0x68,
    "黄": 0x69,
    "[note]": 0x6A,
    "当": 0x6B,
    "数": 0x6C,
    "兄": 0x6D,
    "用": 0x6E,
    "心": 0x6F,
    "今": 0x70,
    "正": 0x71,
    "直": 0x72,
    "全": 0x73,
    "体": 0x74,
    "夜": 0x75,
    "面": 0x76,
    "虫": 0x77,
    "ｘ": 0x78,
    "x": 0x78,
    " ": 0xF7,
    "　": 0xF8,
}

CHARSET_BUTTONS = {
    "[~a]": 0x00,
    "[~b]": 0x01,
    "[~start]": 0x02,
    "[~c-up]": 0x03,
    "[~c-down]": 0x04,
    "[~c-left]": 0x05,
    "[~c-right]": 0x06,
    "[~z]": 0x07,
    "[~l]": 0x08,
    "[~r]": 0x09,
}


def check_if_correct_charset(char, cur_charset, filename, lineno):
    warn_msg = f"{filename}:{lineno}: Warning: character '{char}' is present but is completely in a wrong charset currently set. Add {{}} before the character to silence this warning."

    if char == " " or char == "　":
        return -1, cur_charset
    elif char in CHARSET_KANA and cur_charset is not CHARSET_KANA:
        print(warn_msg.format("[Charset Kana]"))
        return 0, CHARSET_KANA
    elif char in CHARSET_LATIN and cur_charset is not CHARSET_LATIN:
        print(warn_msg.format("[Charset Latin]"))
        return 1, CHARSET_LATIN
    elif char in CHARSET_KANJI and cur_charset is not CHARSET_KANJI:
        print(warn_msg.format("[Charset Kanji]"))
        return 2, CHARSET_KANJI
    elif char in CHARSET_BUTTONS and cur_charset is not CHARSET_BUTTONS:
        print(warn_msg.format("[Charset Buttons]"))
        return 3, CHARSET_BUTTONS

    return -1, cur_charset


def strip_c_comments(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith("/"):
            return " "
        else:
            return s

    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE,
    )
    return re.sub(pattern, replacer, text)


if __name__ == "__main__":
    if len(argv) < 3:
        print("usage: parse_compile.py [version] [in.msg] [out.msgpack] [--c]")
        exit(1)

    version = argv[1]
    filename = argv[2]
    outfile = argv[3]
    is_output_format_c = "--c" in argv

    messages = []

    message = None
    with open(filename, "r") as f:
        source = strip_c_comments(f.read())
        lineno = 1

        directive = ""
        indent_level = 0

        if version == "jp":
            charset = CHARSET_KANA
        else:
            charset = CHARSET_STANDARD
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

                if directive[0] != "#message":
                    print(f"{filename}:{lineno}: expected #message directive")
                    exit(1)
                if is_output_format_c:
                    if len(directive) != 2:
                        print(f"{filename}:{lineno}: expected #message:NAME directive")
                        exit(1)

                    message = Message(directive[1], None, None)
                else:
                    if len(directive) != 3:
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

                if version == "jp":
                    charset = CHARSET_KANA
                else:
                    charset = CHARSET_STANDARD

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

                source = source[1:]  # {

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
                        # color_stack.append(color)
                    # elif command == "/color":
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

                                message.bytes += [
                                    0x05,
                                    pos[0],
                                    pos[1],
                                    size[0],
                                    size[1],
                                ]
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
                            elif style == "popup2":
                                message.bytes += [0x0B]
                            elif style == "upgrade":
                                pos = named_args.get("pos")

                                if not isinstance(pos, list) or len(pos) != 2:
                                    print(f"{filename}:{lineno}: 'upgrade' style requires pos=_,_")
                                    exit(1)

                                size = named_args.get("size")

                                if not isinstance(size, list) or len(size) != 2:
                                    print(f"{filename}:{lineno}: 'upgrade' style requires size=_,_")
                                    exit(1)

                                message.bytes += [
                                    0x0C,
                                    pos[0],
                                    pos[1],
                                    size[0],
                                    size[1],
                                ]
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
                        elif font == "menu2":
                            font = 2
                        elif font == "title":
                            font = 3
                        elif font == "subtitle":
                            font = 4

                        if type(font) is not int:
                            print(f"{filename}:{lineno}: unknown font '{font}'")
                            exit(1)

                        message.bytes += [0xFF, 0x00, font]
                        # font_stack.append(font)

                        if font == 3 or font == 4:
                            charset = CHARSET_CREDITS
                        else:
                            if version == "jp":
                                charset = CHARSET_KANA
                            else:
                                charset = CHARSET_STANDARD
                    # elif command == "/font":
                    #     font_stack.pop()
                    #     message.bytes += [0xFF, 0x00, font_stack[0]]

                    #     if font == 3 or font == 4:
                    #         charset = CHARSET_CREDITS
                    #     else:
                    #         charset = CHARSET
                    elif command == "charset":
                        if version != "jp":
                            print(f"{filename}:{lineno}: charset command is only supported in the JP version")
                            exit(1)

                        if len(args) != 1:
                            print(f"{filename}:{lineno}: charset command requires 1 parameter")
                            exit(1)

                        arg_charset = args[0]

                        if arg_charset == "kana":
                            arg_charset = 0
                        elif arg_charset == "latin":
                            arg_charset = 1
                        elif arg_charset == "kanji":
                            arg_charset = 2
                        elif arg_charset == "buttons":
                            arg_charset = 3

                        if type(arg_charset) is not int:
                            print(f"{filename}:{lineno}: unknown charset '{arg_charset}'")
                            exit(1)

                        message.bytes += [0xF3 + arg_charset]

                        if arg_charset == 0:
                            charset = CHARSET_KANA
                        elif arg_charset == 1:
                            charset = CHARSET_LATIN
                        elif arg_charset == 2:
                            charset = CHARSET_KANJI
                        elif arg_charset == 3:
                            charset = CHARSET_BUTTONS

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
                            if version == "jp":
                                charset_byte, charset = check_if_correct_charset("[right]", charset, filename, lineno)
                                if charset_byte != -1:
                                    message.bytes += [0xF3 + charset_byte]
                                message.bytes += [0xB4]
                            else:
                                message.bytes += [0x95]
                        else:
                            if len(args) != 1:
                                print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x12, args[0]]
                    elif command == "down":
                        if len(args) == 0:
                            if version == "jp":
                                charset_byte, charset = check_if_correct_charset("[down]", charset, filename, lineno)
                                if charset_byte != -1:
                                    message.bytes += [0xF3 + charset_byte]
                                message.bytes += [0xB2]
                            else:
                                message.bytes += [0x93]
                        else:
                            if len(args) != 1:
                                print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                                exit(1)

                            message.bytes += [0xFF, 0x13, args[0]]
                    elif command == "up":
                        if len(args) == 0:
                            if version == "jp":
                                charset_byte, charset = check_if_correct_charset("[up]", charset, filename, lineno)
                                if charset_byte != -1:
                                    message.bytes += [0xF3 + charset_byte]
                                message.bytes += [0xB1]
                            else:
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

                        message.bytes += [
                            0xFF,
                            0x16,
                            spriteid >> 8,
                            spriteid & 0xFF,
                            raster,
                        ]
                    elif command == "itemicon":
                        itemid = named_args.get("itemid")

                        # TODO: itemname

                        if not isinstance(itemid, int):
                            print(f"{filename}:{lineno}: {command} command requires itemid=_")
                            exit(1)

                        message.bytes += [0xFF, 0x17, itemid >> 8, itemid & 0xFF]
                    elif command == "image":
                        index = named_args.get("index")
                        pos = named_args.get("pos")  # xx,y
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

                        message.bytes += [
                            0xFF,
                            0x18,
                            index,
                            pos[0] >> 8,
                            pos[0] & 0xFF,
                            pos[1],
                            hasborder,
                            alpha,
                            fadeamount,
                        ]
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
                        if len(args) != 2:
                            print(f"{filename}:{lineno}: {command} command requires 2 parameters")
                            exit(1)
                        message.bytes += [0xFF, 0x1B, args[0], args[1]]
                    elif command == "animdone":
                        if len(args) != 1:
                            print(f"{filename}:{lineno}: {command} command requires 1 parameter")
                            exit(1)
                        message.bytes += [0xFF, 0x1C, args[0]]
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
                        message.bytes += [0xFF, 0x26, 0x06]
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
                            0xFF,
                            0x2C,
                            soundids[0] >> 24,
                            (soundids[0] >> 16) & 0xFF,
                            (soundids[0] >> 8) & 0xFF,
                            soundids[0] & 0xFF,
                            soundids[1] >> 24,
                            (soundids[1] >> 16) & 0xFF,
                            (soundids[1] >> 8) & 0xFF,
                            soundids[1] & 0xFF,
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
                        # sound_stack.append(sound)
                    # elif command == "/sound":
                    #     sound_stack.pop()
                    #     message.bytes += [0xFF, 0x2F, sound_stack[0]]
                    elif command == "a":
                        color_code = color_to_code("blue", "button")
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x00,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x98,
                                0xFF,
                                0x25,
                            ]
                    elif command == "b":
                        color_code = color_to_code(
                            named_args.get("color", "green"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x01,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x99,
                                0xFF,
                                0x25,
                            ]
                    elif command == "l":
                        color_code = color_to_code(
                            named_args.get("color", "gray"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x08,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x9A,
                                0xFF,
                                0x25,
                            ]
                    elif command == "r":
                        color_code = color_to_code(
                            named_args.get("color", "gray"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x09,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x9B,
                                0xFF,
                                0x25,
                            ]
                    elif command == "z":
                        color_code = color_to_code("grey", "button")
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x07,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x9C,
                                0xFF,
                                0x25,
                            ]
                    elif command == "c-up":
                        color_code = color_to_code(
                            named_args.get("color", "yellow"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x03,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x9D,
                                0xFF,
                                0x25,
                            ]
                    elif command == "c-down":
                        color_code = color_to_code(
                            named_args.get("color", "yellow"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x04,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x9E,
                                0xFF,
                                0x25,
                            ]
                    elif command == "c-left":
                        color_code = color_to_code(
                            named_args.get("color", "yellow"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x05,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0x9F,
                                0xFF,
                                0x25,
                            ]
                    elif command == "c-right":
                        color_code = color_to_code(
                            named_args.get("color", "yellow"),
                            named_args.get("ctx", "button"),
                        )
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x06,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xA0,
                                0xFF,
                                0x25,
                            ]
                    elif command == "start":
                        color_code = color_to_code(
                            named_args.get("color", "red"),
                            named_args.get("ctx", "button"),
                        )  #
                        assert color_code is not None
                        if version == "jp":
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xF6,
                                0x02,
                                0xFF,
                                0x25,
                            ]
                        else:
                            message.bytes += [
                                0xFF,
                                0x24,
                                0xFF,
                                0x05,
                                color_code,
                                0xA1,
                                0xFF,
                                0x25,
                            ]
                    elif command == "~a":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~a]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x00]
                        else:
                            message.bytes += [0x98]
                    elif command == "~b":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~b]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x01]
                        else:
                            message.bytes += [0x99]
                    elif command == "~l":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~l]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x08]
                        else:
                            message.bytes += [0x9A]
                    elif command == "~r":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~r]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x09]
                        else:
                            message.bytes += [0x9B]
                    elif command == "~z":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~z]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x07]
                        else:
                            message.bytes += [0x9C]
                    elif command == "~c-up":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~c-up]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x03]
                        else:
                            message.bytes += [0x9D]
                    elif command == "~c-down":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~c-down]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x04]
                        else:
                            message.bytes += [0x9E]
                    elif command == "~c-left":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~c-left]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x05]
                        else:
                            message.bytes += [0x9F]
                    elif command == "~c-right":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~c-right]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x06]
                        else:
                            message.bytes += [0xA0]
                    elif command == "~start":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[~start]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x02]
                        else:
                            message.bytes += [0xA1]
                    elif command == "note":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[note]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x6A]
                        else:
                            message.bytes += [0x00]
                    elif command == "heart":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[heart]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0xBD]
                        else:
                            message.bytes += [0x90]
                    elif command == "star":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[star]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0xBE]
                        else:
                            message.bytes += [0x91]
                    elif command == "left":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[left]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0xB3]
                        else:
                            message.bytes += [0x94]
                    elif command == "circle":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[circle]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x61]
                        else:
                            message.bytes += [0x96]
                    elif command == "cross":
                        if version == "jp":
                            charset_byte, charset = check_if_correct_charset("[cross]", charset, filename, lineno)
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0x62]
                        else:
                            message.bytes += [0x97]
                    elif command == "katakana":
                        if version != "jp":
                            print(f"{filename}:{lineno}: Command katakana is only supported in the JP version")
                            exit(1)

                        kana_char = args[0]

                        if kana_char == "smalln":
                            charset_byte, charset = check_if_correct_charset(
                                "[katakana smalln]", charset, filename, lineno
                            )
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0xC5]
                        else:
                            print(f"{filename}:{lineno}: Invalid or unimplemented katakana character name {kana_char}")
                            exit(1)
                    elif command == "hiragana":
                        if version != "jp":
                            print(f"{filename}:{lineno}: Command hiragana is only supported in the JP version")
                            exit(1)

                        kana_char = args[0]

                        if kana_char == "smalln":
                            charset_byte, charset = check_if_correct_charset(
                                "[hiragana smalln]", charset, filename, lineno
                            )
                            if charset_byte != -1:
                                message.bytes += [0xF3 + charset_byte]
                            message.bytes += [0xC4]
                        else:
                            print(f"{filename}:{lineno}: Invalid or unimplemented hiragana character name {kana_char}")
                            exit(1)
                    elif command == "fullspace":
                        message.bytes += [0xF8]
                    elif command == "halfspace":
                        message.bytes += [0xF9]
                    elif command == "savepos":
                        message.bytes += [0xFF, 0x22]
                    elif command == "restorepos":
                        message.bytes += [0xFF, 0x23]
                    elif command == "enablecdownnext":
                        message.bytes += [0xFF, 0x2B]
                    elif command == "beginchoice":
                        choiceindex = 0
                        message.bytes += [0xFF, 0x09]  # delayoff
                    elif command == "option" and choiceindex >= 0:
                        message.bytes += [0xFF, 0x1E, choiceindex]  # cursor n
                        message.bytes += [0xFF, 0x21, choiceindex]  # option n
                        choiceindex += 1
                    elif command == "endchoice" and choiceindex >= 0:
                        cancel = named_args.get("cancel")

                        message.bytes += [0xFF, 0x21, 255]  # option 255
                        message.bytes += [0xFF, 0x0A]  # delayon

                        if isinstance(cancel, int):
                            message.bytes += [0xFF, 0x20, cancel]  # setcancel n

                        message.bytes += [0xFF, 0x1F, choiceindex]  # endchoice n

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
                            # message.bytes += [0xFD]
                        explicit_end = False

                        # sanity check
                        for b in message.bytes:
                            if not isinstance(b, int):
                                print(b)

                        # padding
                        while len(message.bytes) % 4 != 0:
                            message.bytes += [0x00]

                        message = None
                        source = source[1:]  # }
                        indent_level = 0
                        choiceindex = -1
                        continue

                    if source[0] == "\\":
                        source = source[1:]

                    if version == "jp" and charset is not CHARSET_CREDITS:
                        charset_byte, charset = check_if_correct_charset(source[0], charset, filename, lineno)
                        if charset_byte != -1:
                            message.bytes += [0xF3 + charset_byte]
                        elif (
                            source[0] not in CHARSET_KANA
                            and source[0] not in CHARSET_LATIN
                            and source[0] not in CHARSET_KANJI
                            and source[0] not in CHARSET_BUTTONS
                        ):
                            print(f"{filename}:{lineno}: unsupported character '{source[0]}' for current font")
                            exit(1)

                        data = charset[source[0]]

                        if type(data) is int:
                            message.bytes.append(data)
                        else:
                            message.bytes += data

                        source = source[1:]
                    else:
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

    if is_output_format_c:
        with open(outfile, "w") as f:
            f.write(f"#include <ultra64.h>\n")

            for message in messages:
                f.write(f"static s8 {message.name}[] = {{\n")
                for b in message.bytes:
                    f.write(f"0x{b:02X},")
                f.write(f"\n}};\n")

    else:
        with open(outfile, "wb") as f:
            msgpack.pack(
                [
                    {
                        "section": message.section,
                        "index": message.index,
                        "name": message.name,
                        "bytes": bytes(message.bytes),
                    }
                    for message in messages
                ],
                f,
            )
