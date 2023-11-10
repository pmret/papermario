import os
import re
from pathlib import Path
from segtypes.n64.segment import N64Segment
import n64img.image
from util.color import unpack_color
from common import iter_in_groups
from util import options
import yaml as yaml_loader
import xml.etree.ElementTree as ET

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))


def indent(elem, level=0):
    i = "\n" + level * "    "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "    "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for elem in elem:
            indent(elem, level + 1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i


def pretty_print_xml(tree: ET.ElementTree, path: Path):
    root = tree.getroot()
    indent(root)
    xml_str = ET.tostring(root, encoding="unicode")
    xml_str = re.sub(" />", "/>", xml_str)
    with open(path, "w") as f:
        f.write(xml_str)


def parse_palette(data):
    palette = []

    for a, b in iter_in_groups(data, 2):
        palette.append(unpack_color([a, b]))

    return palette


class N64SegPm_icons(N64Segment):
    def split(self, rom_bytes):
        self.out_dir = options.opts.asset_path / "icon"

        with open(script_dir / "icon.yaml") as f:
            self.icons = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

        data = rom_bytes[self.rom_start : self.rom_end]
        pos = 0
        self.files = []

        def write_img(name, img):
            out_file = self.out_dir / (name + ".png")
            os.makedirs(os.path.dirname(out_file), exist_ok=True)
            img.write(out_file)
            self.files.append(out_file)

        IconList = ET.Element("Icons")

        for _, icon in enumerate(self.icons):
            # read yaml entry
            fmt = icon[0]
            name = icon[1]
            w = int(icon[2])
            h = int(icon[3])

            if fmt == "solo" or fmt == "pair":
                img_size = w * h // 2
                img_bytes = data[pos : pos + img_size]
                pos += img_size

                pal_bytes = data[pos : pos + 32]
                pos += 32

                img = n64img.image.CI4(data=img_bytes, width=w, height=h)
                img.palette = parse_palette(pal_bytes)
                write_img(name, img)

                if fmt == "pair":
                    pal_bytes = data[pos : pos + 32]
                    pos += 32

                    img.palette = parse_palette(pal_bytes)
                    write_img(name + ".disabled", img)

            elif fmt == "rgba16":
                img_size = w * h * 2
                img_bytes = data[pos : pos + img_size]
                pos += img_size
                img = n64img.image.RGBA16(data=img_bytes, width=w, height=h)
                write_img(name, img)

            ET.SubElement(
                IconList,
                "Icon",
                {
                    "type": f"{fmt}",
                    "name": f"{name}",
                },
            )

            xml = ET.ElementTree(IconList)
            pretty_print_xml(xml, self.out_dir / "Icons.xml")

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        return [
            LinkerEntry(
                self,
                [options.opts.asset_path / "icon" / "Icons.xml"],
                options.opts.asset_path / "icons.bin",
                self.get_linker_section(),
                self.get_linker_section(),
            )
        ]
