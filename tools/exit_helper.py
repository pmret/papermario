#!/usr/bin/python3

def qc(words_string):
    words = words_string.split(",")
    byte_array = b""
    for word in words:
        data = word.strip()[2:]
        byte_array += bytearray.fromhex(data)
    strings = byte_array.split(b"\0")

    idx = 0
    for string in strings:
        if len(string) > 0:
            dec = string.decode("ascii")
            print(f"static char* N(exit_str_{idx}) = \"{dec}\";")
            idx += 1

qc("0x666C6F5F, 0x30300000, 0x6B6D725F, 0x32320000")
