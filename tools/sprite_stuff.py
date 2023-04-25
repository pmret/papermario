#! /usr/bin/python3

from dataclasses import dataclass
from typing import List

from splat.util.n64.Yay0decompress import Yay0Decompressor

END = "big"

@dataclass
class RasterInfo:
    offset: int
    size: int

def get_raster_infos(data: bytes) -> List[RasterInfo]:
    raster_infos = []
    for i in range(0, len(data) - 4, 4):
        packed = int.from_bytes(data[i:i+4])

        size = (packed >> 20) << 4
        offset = packed & 0xFFFFF
        raster_infos.append(RasterInfo(offset, size))
    return raster_infos

with open("assets/us/1943020.bin", "rb") as f:
    player_sprite_raster_data = f.read()

# Header parsing
index_ranges_offset = int.from_bytes(player_sprite_raster_data[0:0x4], END)
packed_raster_info_offset = int.from_bytes(player_sprite_raster_data[0x4:0x8], END)
ci4_raster_data_offset = int.from_bytes(player_sprite_raster_data[0x8:0xC], END)

index_ranges = player_sprite_raster_data[index_ranges_offset:packed_raster_info_offset]
packed_raster_info_data = player_sprite_raster_data[packed_raster_info_offset:ci4_raster_data_offset]
ci4_raster_data = player_sprite_raster_data[ci4_raster_data_offset:]

# Create raster info intervals
raster_info_intervals: List[tuple[int, int]] = []
for i in range(0, len(index_ranges) - 4, 4):
    start = int.from_bytes(index_ranges[i:i+4], END)
    end = int.from_bytes(index_ranges[i+4:i+8], END)
    raster_info_intervals.append((start, end))

raster_infos = get_raster_infos(packed_raster_info_data)

raster_info_groups: List[List[RasterInfo]] = []
for interval in raster_info_intervals:
    raster_info_groups.append(raster_infos[interval[0]:interval[1]])

raster_groups = [
    [
    player_sprite_raster_data[info.offset:info.offset + info.size] for info in group
    ] for group in raster_info_groups
]

with open("assets/us/19E0970.bin", "rb") as f:
    yay0_sprite_data_chunked = f.read()

yay0_splits = []
for i in range(14):
    yay0_splits.append(int.from_bytes(yay0_sprite_data_chunked[i*4:i*4+4], END))

yay0_sprite_data = []
for i in range(0, len(yay0_splits) - 1):
    yay0_sprite_data.append(yay0_sprite_data_chunked[yay0_splits[i]:yay0_splits[i+1]])

yay0decompressor = Yay0Decompressor()
sprite_data = [
    yay0decompressor.decompress(yay0_piece, END)
for yay0_piece in yay0_sprite_data]

for file in sprite_data:
    raster_list_offset = int.from_bytes(file[0:4], END)
    palette_list_offset = int.from_bytes(file[4:8], END)
    max_anim_components = int.from_bytes(file[8:0xC], END)
    num_color_variatons = int.from_bytes(file[0xC:0x10], END)

    anim_list_offsets = []
    raster_list_offsets = []
    palette_list_offsets = []

    palettes_bytes = []
    rasters_bytes = []

    i = 0x10
    while file[i:i+4] != b'\xFF\xFF\xFF\xFF':
        anim_list_offsets.append(int.from_bytes(file[i:i+4], END))
        i += 4

    i = raster_list_offset
    while file[i:i+4] != b'\xFF\xFF\xFF\xFF':
        raster_list_offsets.append(int.from_bytes(file[i:i+4], END))
        i += 4

    i = palette_list_offset
    while file[i:i+4] != b'\xFF\xFF\xFF\xFF':
        palette_list_offsets.append(int.from_bytes(file[i:i+4], END))
        i += 4

    # Read palettes
    for pal_offset in palette_list_offsets:
        pal = file[pal_offset:pal_offset+0x20]
        palettes_bytes.append(pal)
    dog = 5
