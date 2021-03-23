#! /usr/bin/python3

import argparse
import yaml
from pathlib import PurePath
from util import options

from split import initialize_segments

parser = argparse.ArgumentParser(description="List output objects for linker script")
parser.add_argument("config", help="path to a compatible config .yaml file")

def main(config_path):
    # Load config
    with open(config_path) as f:
        config = yaml.safe_load(f.read())

    options.initialize(config)
    replace_ext = options.get("ld_o_replace_extension", True)

    # Initialize segments
    all_segments = initialize_segments(options, config_path, config["segments"])

    for segment in all_segments:
        for subdir, path, obj_type, start in segment.get_ld_files():
            path = PurePath(subdir) / PurePath(path)
            path = path.with_suffix(".o" if replace_ext else path.suffix + ".o")

            print(path)

if __name__ == "__main__":
    args = parser.parse_args()
    main(args.config)
