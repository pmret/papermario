import os
import struct
import sys
from pathlib import Path
from typing import List, Tuple

TOOLS_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(str(Path(TOOLS_DIR) / "build/imgfx"))
from imgfx_data import Anim, Triangle, Vertex

from splat.segtypes.n64.segment import N64Segment
from splat.util import log, options


class N64SegPm_imgfx_data(N64Segment):
    anims: List[Anim] = []

    OUT_DIR: Path = options.opts.asset_path / "imgfx"

    def scan(self, rom_bytes) -> None:
        data = rom_bytes[self.rom_start : self.rom_end]

        for name, offset in self.yaml.get("animations"):
            pos = offset

            # Animations start with vtx data which is followed by gfx data and ends with the header at `offset`
            (
                vtx_offset,
                gfx_offset,
                vtx_count,
                gfx_count,
                keyframes,
                flags,
            ) = struct.unpack(">IIHHHH", data[pos : pos + 16])

            frames: List[List[Vertex]] = []

            pos = vtx_offset
            for i in range(keyframes):
                frame: List[Vertex] = []

                for j in range(vtx_count):
                    x, y, z, u, v, r, g, b, a = struct.unpack(">hhhBBbbbB", data[pos : pos + 12])
                    pos += 12
                    frame.append(Vertex(j, x, y, z, u, v, r, g, b, a))

                frames.append(frame)

            triangles: List[Triangle] = []
            vtx_buf: List[int] = []

            # Align to 8 bytes
            pos = (pos + 7) & ~(8 - 1)
            assert pos == gfx_offset

            def unpack_tri(word: int, vtx_buf: List[int]) -> Tuple[int, int, int]:
                i = (word >> 16) & 0xFF
                j = (word >> 8) & 0xFF
                k = word & 0xFF

                i = vtx_buf[int(i / 2)]
                j = vtx_buf[int(j / 2)]
                k = vtx_buf[int(k / 2)]

                return (i, j, k)

            for i in range(gfx_count):
                w0, w1 = struct.unpack(">II", data[pos : pos + 8])
                pos += 8

                op = (w0 >> 24) & 0xFF

                if op == 1:  # G_VTX
                    num = w0 >> 12 & 0xFF
                    end = int((w0 & 0xFF) / 2)
                    src_idx = int((w1 - vtx_offset) / 12)
                    start = end - num

                    for j in range(num):
                        to_place_pos = start + j
                        while len(vtx_buf) <= to_place_pos:
                            vtx_buf.append(0)
                        vtx_buf[to_place_pos] = src_idx + j
                elif op == 5:  # G_TRI1
                    triangles.append(Triangle(*unpack_tri(w0, vtx_buf)))
                elif op == 6:  # G_TRI2
                    triangles.append(Triangle(*unpack_tri(w0, vtx_buf)))
                    triangles.append(Triangle(*unpack_tri(w1, vtx_buf)))
                elif op == 0xDF:  # G_ENDDL
                    pass
                else:
                    log.error(f"Unknown op: {op}")

            self.anims.append(
                Anim(
                    name,
                    offset,
                    vtx_offset,
                    gfx_offset,
                    vtx_count,
                    gfx_count,
                    keyframes,
                    flags,
                    frames,
                    triangles,
                )
            )

    def split(self, rom_bytes):
        self.OUT_DIR.mkdir(parents=True, exist_ok=True)
        for anim in self.anims:
            with open(f"{self.OUT_DIR}/{anim.name}.json", "w") as f:
                f.write(anim.toJSON())

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        return [
            LinkerEntry(
                self,
                [self.OUT_DIR / f"{name}.json" for name, _ in self.yaml.get("animations")],
                options.opts.asset_path / "imgfx" / f"{self.name}.c",
                self.get_linker_section(),
                self.get_linker_section(),
            )
        ]
