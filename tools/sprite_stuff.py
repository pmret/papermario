#! /usr/bin/python3

from dataclasses import dataclass
from typing import List

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

raster_infos_sorted = sorted(raster_infos, key=lambda x: x.offset)
dog = 5
