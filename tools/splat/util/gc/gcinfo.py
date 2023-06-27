#! /usr/bin/env python3


import argparse

import hashlib

from pathlib import Path
from typing import Optional

parser = argparse.ArgumentParser(
    description="Gives information on GameCube disc images"
)
parser.add_argument("iso", help="path to a GameCube disc image")

system_codes = {
    "D": "GameCube Demo",
    "G": "GameCube",
    "P": "GameCube Promotional",
    "R": "Early Wii",
    "S": "Later Wii",
}

region_codes = {"E": "NTSC-U", "J": "NTSC-J", "P": "PAL"}

publisher_codes = {"01": "Nintendo", "08": "Capcom", "8P": "Sega", "E9": "Natsume"}


def get_info(iso_path: Path, iso_bytes: Optional[bytes] = None):
    if iso_bytes is None:
        iso_bytes = iso_path.read_bytes()

    return get_info_bytes(iso_bytes)


def get_info_bytes(iso_bytes: bytes):
    system_code = chr(iso_bytes[0x00])
    game_code = iso_bytes[0x01:0x03].decode("utf-8")
    region_code = chr(iso_bytes[0x03])
    publisher_code = iso_bytes[0x04:0x06].decode("utf-8")

    name = str(iso_bytes[0x20:0x400], "utf-8").strip("\x00")
    root = "filesystem"

    compiler = "mwcc"
    sha1 = hashlib.sha1(iso_bytes).hexdigest()

    return GCIso(
        name,
        root,
        system_code,
        game_code,
        region_code,
        publisher_code,
        compiler,
        sha1,
    )


class GCIso:
    def __init__(
        self,
        name: str,
        root: str,
        system_code,
        game_code,
        region_code,
        publisher_code,
        compiler,
        sha1,
    ):
        self.name = name
        self.root = root
        self.system_code = system_code
        self.game_code = game_code
        self.region_code = region_code
        self.publisher_code = publisher_code
        self.compiler = compiler
        self.sha1 = sha1

    def get_system_name(self):
        return system_codes[self.system_code]

    def get_publisher_name(self):
        return publisher_codes[self.publisher_code]

    def get_region_name(self):
        return region_codes[self.region_code]
