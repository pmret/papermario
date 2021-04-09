from segtypes.n64.segment import N64Segment
from pathlib import Path
from util.n64 import Yay0decompress
from util.iter import iter_in_groups
from util.color import unpack_color
from util import options
import png
import xml.etree.ElementTree as ET

import pylibyaml
import yaml

class Sprite:
    def __init__(self):
        self.max_components = 0
        self.num_variations = 0

        self.images = []
        self.palettes = []
        self.animations = []

        self.image_names = []
        self.palette_names = []
        self.animation_names = []

    @staticmethod
    def from_bytes(data):
        self = Sprite()

        image_offsets = Sprite.read_offset_list(data[int.from_bytes(data[0:4], byteorder="big"):])
        palette_offsets = Sprite.read_offset_list(data[int.from_bytes(data[4:8], byteorder="big"):])
        self.max_components = int.from_bytes(data[8:0xC], byteorder="big")
        self.num_variations = int.from_bytes(data[0xC:0x10], byteorder="big")
        animation_offsets = Sprite.read_offset_list(data[0x10:])

        for offset in palette_offsets:
            # 16 colors
            color_data = data[offset : offset + 16 * 2]
            self.palettes.append([unpack_color(c) for c in iter_in_groups(color_data, 2)])

        for offset in image_offsets:
            img = Image.from_bytes(data[offset:], data)
            self.images.append(img)

        for offset in animation_offsets:
            anim = []

            for comp_offset in Sprite.read_offset_list(data[offset:]):
                comp = Component.from_bytes(data[comp_offset:], data)
                anim.append(comp)

            self.animations.append(anim)

        return self

    @staticmethod
    def read_offset_list(data):
        l = []
        pos = 0

        while True:
            offset = int.from_bytes(data[pos:pos+4], byteorder="big", signed=True)

            if offset == -1:
                break

            l.append(offset)

            pos += 4

        return l

    def write_to_dir(self, path):
        SpriteSheet = ET.Element("SpriteSheet", {
            "a": str(self.max_components),
            "b": str(self.num_variations),
        })

        PaletteList = ET.SubElement(SpriteSheet, "PaletteList")
        RasterList = ET.SubElement(SpriteSheet, "RasterList")
        AnimationList = ET.SubElement(SpriteSheet, "AnimationList")

        palette_to_raster = {}

        for i, image in enumerate(self.images):
            name = self.image_names[i] if self.image_names else f"Raster_{i:02X}"
            image.write(path / (name + ".png"), self.palettes[image.palette_index])

            if image.palette_index not in palette_to_raster:
                palette_to_raster[image.palette_index] = []
            palette_to_raster[image.palette_index].append(image)

            ET.SubElement(RasterList, "Raster", {
                "id": f"{i:X}",
                "palette": f"{image.palette_index:X}",
                "src": name + ".png",
            })

        for i, palette in enumerate(self.palettes):
            name = self.palette_names[i] if self.palette_names else f"Palette_{i:02X}"

            if i in palette_to_raster:
                img = palette_to_raster[i][0]
            else:
                img = self.images[0]

            img.write(path / (name + ".png"), palette)

            ET.SubElement(PaletteList, "Palette", {
                "id": f"{i:X}",
                "src": name + ".png",
            })

        for i, components in enumerate(self.animations):
            Animation = ET.SubElement(AnimationList, "Animation", {
                "name": self.animation_names[i] if self.animation_names else f"Anim_{i:X}",
            })

            for j, comp in enumerate(components):
                Component = ET.SubElement(Animation, "Component", {
                    "name": f"Comp_{j:X}",
                    "xyz": ",".join(map(str, [comp.x, comp.y, comp.z])),
                })

                for cmd in comp.commands:
                    ET.SubElement(Component, "Command", {"val": f"{cmd:X}"})

        xml = ET.ElementTree(SpriteSheet)

        # pretty print (Python 3.9+)
        if hasattr(ET, "indent"):
            ET.indent(xml, "    ")

        xml.write(str(path / "SpriteSheet.xml"), encoding="unicode")

    @staticmethod
    def from_dir(path, read_images=True):
        self = Sprite()

        xml = ET.parse(str(path / "SpriteSheet.xml"))
        SpriteSheet = xml.getroot()

        true_max_components = 0
        self.max_components = int(SpriteSheet.get("a") or SpriteSheet.get("maxComponents")) # ignored
        self.num_variations = int(SpriteSheet.get("b") or SpriteSheet.get("paletteGroups"))

        for Palette in SpriteSheet.findall("./PaletteList/Palette"):
            if read_images:
                img = png.Reader(str(path / Palette.get("src")))
                img.preamble(True)
                palette = img.palette(alpha="force")

                palette = palette[0:16]
                assert len(palette) == 16

                self.palettes.append(palette)

            self.palette_names.append(Palette.get("name", Palette.get("src").split(".png")[0]))

        for Raster in SpriteSheet.findall("./RasterList/Raster"):
            if read_images:
                img_path = str(path / Raster.get("src"))
                width, height, raster, info = png.Reader(img_path).read_flat()

                image = Image()
                image.width = width
                image.height = height
                image.raster = raster
                image.palette_index = int(Raster.get("palette"), base=16)

                assert (image.width % 8) == 0, f"{img_path} width is not a multiple of 8"
                assert (image.height % 8) == 0, f"{img_path} height is not a multiple of 8"

                self.images.append(image)

            self.image_names.append(Raster.get("src").split(".png")[0])

        for i, Animation in enumerate(SpriteSheet.findall("./AnimationList/Animation")):
            components = []

            for ComponentEl in Animation.findall("Component"):
                comp = Component()

                x, y, z = ComponentEl.get("xyz", "0,0,0").split(",")
                comp.x = int(x)
                comp.y = int(y)
                comp.z = int(z)

                for Command in ComponentEl:
                    comp.commands.append(int(Command.get("val"), base=16))

                components.append(comp)

            self.animation_names.append(Animation.get("name"))
            self.animations.append(components)

            if len(components) > true_max_components:
                true_max_components = len(components)

        self.max_components = true_max_components
        #assert self.max_components == true_max_components, f"{true_max_components} component(s) used, but SpriteSheet.a = {self.max_components}"

        return self

class Image:
    @staticmethod
    def from_bytes(data, sprite_data):
        self = Image()

        raster_offset = int.from_bytes(data[0:4], byteorder="big")
        self.width = data[4] & 0xFF
        self.height = data[5] & 0xFF
        self.palette_index = data[6]
        assert data[7] == 0xFF

        self.set_raster_from_bytes(sprite_data[raster_offset:])

        return self

    # CI-4
    def set_raster_from_bytes(self, data):
        self.raster = bytearray()

        for i in range(self.width * self.height // 2):
            self.raster.append(data[i] >> 4)
            self.raster.append(data[i] & 0xF)

    def write(self, path, palette):
        w = png.Writer(self.width, self.height, palette=palette)

        with open(path, "wb") as f:
            w.write_array(f, self.raster)

class Component:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0
        self.commands = []

    @staticmethod
    def from_bytes(data, sprite_data):
        self = Component()

        commands_offset = int.from_bytes(data[0:4], byteorder="big")
        commands_size = int.from_bytes(data[4:6], byteorder="big") # size in bytes, not length!
        commands_data = sprite_data[commands_offset : commands_offset + commands_size]
        self.commands = [int.from_bytes(d[0:2], byteorder="big") for d in iter_in_groups(commands_data, 2)]

        self.x = int.from_bytes(data[6:8], byteorder="big", signed=True)
        self.y = int.from_bytes(data[8:10], byteorder="big", signed=True)
        self.z = int.from_bytes(data[10:12], byteorder="big", signed=True)

        return self

class N64SegPaperMarioNpcSprites(N64Segment):
    DEFAULT_SPRITE_NAMES = [f"{i:02X}" for i in range(0xEA)]

    def __init__(self, segment, next_segment):
        super().__init__(segment, next_segment)

        self.files = segment["files"]

        with (Path(__file__).parent / f"{self.name}.yaml").open("r") as f:
            self.sprite_cfg = yaml.load(f.read(), Loader=yaml.SafeLoader)

    def split(self, rom_bytes):
        out_dir = options.get_asset_path() / self.dir / self.name

        data = rom_bytes[self.rom_start:self.rom_end]
        pos = 0

        for i, sprite_name in enumerate(self.files):
            self.log(f"Splitting sprite {sprite_name}...")

            sprite_dir = out_dir / sprite_name
            sprite_dir.mkdir(parents=True, exist_ok=True)

            start = int.from_bytes(data[i * 4 : (i + 1) * 4], byteorder="big")
            end = int.from_bytes(data[(i + 1) * 4 : (i + 2) * 4], byteorder="big")

            sprite_data = Yay0decompress.decompress_yay0(data[start:end])
            sprite = Sprite.from_bytes(sprite_data)

            if sprite_name in self.sprite_cfg:
                sprite.image_names = self.sprite_cfg[sprite_name].get("frames", [])
                sprite.palette_names = self.sprite_cfg[sprite_name].get("palettes", [])
                sprite.animation_names = self.sprite_cfg[sprite_name].get("animations", [])

            sprite.write_to_dir(sprite_dir)

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        basepath = options.get_asset_path() / "sprite" / f"{self.name}"
        out_paths = [options.get_asset_path() / "sprite" / self.name / (f["name"] if type(f) is dict else f)
                     for f in self.files]

        return [LinkerEntry(self, out_paths, basepath, ".data")]

    def cache(self):
        return (self.config, self.rom_end, self.sprite_cfg)
