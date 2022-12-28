import argparse
import os
import sys
from ctypes import *
from struct import pack, unpack_from
from typing import Optional

try:
    from .. import log
    from .decompressor import Decompressor
except ImportError:
    print(f"Run as python3 -m util.n64.Yay0decompress")
    sys.exit(1)

tried_loading = False
lib: Optional[CDLL] = None


def setup_lib():
    global lib
    global tried_loading
    if lib:
        return True
    if tried_loading:
        return False
    try:
        tried_loading = True
        lib = cdll.LoadLibrary(
            os.path.dirname(os.path.realpath(__file__)) + "/Yay0decompress"
        )
        return True
    except Exception:
        log.write(
            "Failed to load Yay0 C library; falling back to Python method",
            status="warn",
        )
        tried_loading = True
        return False


class Yay0Decompressor(Decompressor):
    def decompress(self, in_bytes, byte_order="big") -> bytearray:
        # attempt to load the library only once per execution
        global lib
        if not setup_lib():
            return self.decompress_python(in_bytes, byte_order)
        assert lib is not None

        class Yay0(Structure):
            _fields_ = [
                ("magic", c_uint32),
                ("uncompressedLength", c_uint32),
                ("opPtr", c_uint32),
                ("dataPtr", c_uint32),
            ]

        # read the file header
        bigEndian = byte_order == "big"
        if bigEndian:
            # the struct is only a view, so when passed to C it will keep
            # its BigEndian values and crash. Explicitly convert them here to little
            hdr = Yay0.from_buffer_copy(
                pack("<IIII", *unpack_from(">IIII", in_bytes, 0))
            )
        else:
            hdr = Yay0.from_buffer_copy(in_bytes, 0)

        magic = getattr(hdr, hdr._fields_[0][0])
        if magic != int.from_bytes(str.encode("Yay0"), byteorder="big"):
            log.error(f"Yay0 magic is incorrect: {magic}")

        # create the input/output buffers, copying data to in
        src = (c_uint8 * len(in_bytes)).from_buffer_copy(in_bytes, 0)
        dst = (c_uint8 * hdr.uncompressedLength)()

        # call decompress, equivilant to, in C:
        # decompress(&hdr, &src, &dst, bigEndian)
        lib.decompress(byref(hdr), byref(src), byref(dst), c_bool(bigEndian))

        # other functions want the results back as a non-ctypes type
        return bytearray(dst)

    @staticmethod
    def decompress_python(in_bytes, byte_order="big"):
        if in_bytes[:4] != b"Yay0":
            log.error("Input file is not Yay0")

        decompressed_size = int.from_bytes(in_bytes[4:8], byteorder=byte_order)
        link_table_offset = int.from_bytes(in_bytes[8:12], byteorder=byte_order)
        chunk_offset = int.from_bytes(in_bytes[12:16], byteorder=byte_order)

        link_table_idx = link_table_offset
        chunk_idx = chunk_offset
        other_idx = 16

        mask_bit_counter = 0
        current_mask = 0

        # preallocate result and index into it
        idx = 0
        ret = bytearray(decompressed_size)

        while idx < decompressed_size:
            # If we're out of bits, get the next mask
            if mask_bit_counter == 0:
                current_mask = int.from_bytes(
                    in_bytes[other_idx : other_idx + 4], byteorder=byte_order
                )
                other_idx += 4
                mask_bit_counter = 32

            if current_mask & 0x80000000:
                ret[idx] = in_bytes[chunk_idx]
                idx += 1
                chunk_idx += 1
            else:
                link = int.from_bytes(
                    in_bytes[link_table_idx : link_table_idx + 2], byteorder=byte_order
                )
                link_table_idx += 2

                offset = idx - (link & 0xFFF)

                count = link >> 12

                if count == 0:
                    count_modifier = in_bytes[chunk_idx]
                    chunk_idx += 1
                    count = count_modifier + 18
                else:
                    count += 2

                # Copy the block
                for i in range(count):
                    ret[idx] = ret[offset + i - 1]
                    idx += 1

            current_mask <<= 1
            mask_bit_counter -= 1

        return ret


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("infile")
    parser.add_argument("outfile")
    parser.add_argument("--byte-order", default="big", choices=["big", "little"])
    args = parser.parse_args()

    with open(args.infile, "rb") as f:
        raw_bytes = f.read()

    yay0decompressor = Yay0Decompressor()
    decompressed = yay0decompressor.decompress(raw_bytes, args.byte_order)

    with open(args.outfile, "wb") as f:
        f.write(decompressed)


if __name__ == "__main__":
    main()
