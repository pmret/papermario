from math import ceil

from util import options

# RRRRRGGG GGBBBBBA
def unpack_color(data):
    s = int.from_bytes(data[0:2], byteorder=options.get_endianess())

    r = (s >> 11) & 0x1F
    g = (s >> 6) & 0x1F
    b = (s >> 1) & 0x1F
    a = (s & 1) * 0xFF

    r = ceil(0xFF * (r / 31))
    g = ceil(0xFF * (g / 31))
    b = ceil(0xFF * (b / 31))

    return r, g, b, a
