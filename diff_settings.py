import argparse


def add_custom_arguments(parser: argparse.ArgumentParser):
    parser.add_argument("--version", default="current")


def apply(config, args):
    ver_dir = f"ver/{args.version}/"
    config["baseimg"] = f"{ver_dir}baserom.z64"
    config["myimg"] = f"{ver_dir}build/papermario.z64"
    config["mapfile"] = f"{ver_dir}build/papermario.map"
    config["source_directories"] = [
        "src",
        f"{ver_dir}asm",
        "include",
        f"{ver_dir}assets",
    ]
    config["make_command"] = ["ninja"]
    config["objdump_flags"] = ["-M", "reg-names=32"]
    config["expected_dir"] = f"{ver_dir}/expected/"
