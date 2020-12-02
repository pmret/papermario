#! /usr/bin/python3

def decode(data):
    length = 0
    is_dbl_char = False
    for byte in data:
        if byte == 0 and not is_dbl_char:
            break

        # ignore null terminator when reading double-byte char
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

    return data[:length].decode('shift-jis')

if __name__ == "__main__":
    import sys

    if len(sys.argv) <= 1:
        print("usage: ./sjis.py <bytes...>")
        print("decodes zero-terminated SJIS from arbitrary hex bytes.")
        print("e.g.")
        print("    ./sjis.py 80072F64 80072F90 80072FA8 00000000")
        print("    エリア ＫＭＲ その１")
        exit(1)

    s = "".join(sys.argv[1:])

    data = bytearray()
    for i in range(0, len(s), 2):
        byte = eval(f"0x{s[i]}{s[i + 1]}")
        data.append(byte)

    print(data)

    print(decode(data))
