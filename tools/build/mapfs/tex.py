import argparse
from pathlib import Path


def build(out_path: Path, in_path: Path, endian: str = "big"):
    dummy_out = b"meow"
    out_path.write_bytes(dummy_out)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Sprite shading profiles")
    parser.add_argument("bin_out", type=Path, help="Output binary file path")
    parser.add_argument("input", type=Path)
    parser.add_argument(
        "--endian", choices=["big", "little"], default="big", help="Output endianness"
    )
    args = parser.parse_args()

    build(args.bin_out, args.input, args.endian)
