from typing import Dict
from segtypes.n64.palette import N64SegPalette as Palette
from segtypes.n64.ci8 import N64SegCi8 as Raster
from segtypes.common.group import CommonSegGroup

# Resolve Raster#palette and Palette#raster links
def initialize(all_segments):
    global palettes_remaining

    def process(segments):
        raster_map: Dict[str, Raster] = {}
        palette_map: Dict[str, Palette] = {}

        for segment in segments:
            if isinstance(segment, Palette):
                palette_map[segment.name] = segment

            if isinstance(segment, Raster):
                raster_map[segment.name] = segment

            if isinstance(segment, CommonSegGroup):
                process(segment.subsegments)

        for raster_name in raster_map:
            raster = raster_map[raster_name]
            #print(f"{raster_name} -> {raster.palette_name}")
            raster.palette = palette_map.get(raster.palette_name)

        for palette_name in palette_map:
            palette = palette_map[palette_name]
            #print(f"{palette_name} -> {palette.raster_name}")
            palette.raster = raster_map.get(palette.raster_name)

    process(all_segments)
