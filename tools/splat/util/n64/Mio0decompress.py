import argparse
import struct
import sys

try:
    from .. import log
    from .decompressor import Decompressor
except ImportError:
    print(f"Run as python3 -m util.n64.Miodecompress")
    sys.exit(1)


class GenericMio0Decompressor(Decompressor):
    def __init__(
        self, unpacked_offset, compressed_offset, uncompressed_offset, header_length
    ):
        self.unpacked_offset = unpacked_offset
        self.compressed_offset = compressed_offset
        self.uncompressed_offset = uncompressed_offset
        self.header_length = header_length

    @staticmethod
    def read_word(data, offset):
        (res,) = struct.unpack(">I", data[offset : offset + 4])
        return res

    @staticmethod
    def read_short(data, offset):
        (res,) = struct.unpack(">H", data[offset : offset + 2])
        return res

    def decompress(self, in_bytes, byte_order="big") -> bytearray:
        magic = in_bytes[0:4]
        if magic != b"MIO0":
            log.error(f"MIO0 magic is incorrect: {magic}")

        unpacked_size = self.read_word(in_bytes, self.unpacked_offset)
        comp_offset = self.read_word(in_bytes, self.compressed_offset)
        uncomp_offset = self.read_word(in_bytes, self.uncompressed_offset)

        layout_data = struct.iter_unpack(">I", in_bytes[self.header_length :])
        uncompressed_data = struct.iter_unpack(">B", in_bytes[uncomp_offset:])
        compressed_data = struct.iter_unpack(">H", in_bytes[comp_offset:])

        idx = 0
        ret = bytearray(unpacked_size)

        mask_bit_counter = 0
        while idx < unpacked_size:
            if mask_bit_counter == 0:
                (current_mask,) = next(layout_data)
                mask_bit_counter = 32

            if current_mask & 0x80000000:
                (ud,) = next(uncompressed_data)
                ret[idx] = ud
                idx += 1
            else:
                (length_offset,) = next(compressed_data)

                length = (length_offset >> 12) + 3
                index = (length_offset & 0xFFF) + 1
                offset = idx - index

                if not (3 <= length <= 18):
                    log.error(f"Invalid length: {length}, corrupt data?")

                if not (1 <= index <= 4096):
                    log.error(f"Invalid index: {index}, corrupt data?")

                for i in range(length):
                    ret[idx] = ret[offset + i]
                    idx += 1

            current_mask <<= 1
            mask_bit_counter -= 1

        return ret


class Mio0Decompressor(GenericMio0Decompressor):
    def __init__(self):
        super().__init__(
            unpacked_offset=4,
            compressed_offset=8,
            uncompressed_offset=12,
            header_length=16,
        )


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("infile")
    parser.add_argument("outfile")
    args = parser.parse_args()

    with open(args.infile, "rb") as f:
        raw_bytes = f.read()

    miodecompress = Mio0Decompressor()
    decompressed = miodecompress.decompress(raw_bytes)

    with open(args.outfile, "wb") as f:
        f.write(decompressed)


if __name__ == "__main__":
    main()
