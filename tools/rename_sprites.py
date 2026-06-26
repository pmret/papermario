#!/usr/bin/env python3

from __future__ import annotations

import argparse
import os
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

import yaml


SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent
RENAME_FILE = SCRIPT_DIR / "sprite_renames.txt"
NPC_NAMES_YAML = SCRIPT_DIR / "splat_ext" / "npc_sprite_names.yaml"

TEXT_SUFFIXES = {
    ".c",
    ".h",
    ".inc",
    ".s",
    ".yaml",
    ".yml",
    ".xml",
    ".json",
    ".txt",
    ".md",
}
SKIP_DIRS = {
    ".git",
    ".mypy_cache",
    ".pytest_cache",
    "__pycache__",
    "build",
}
WORD_EDGE = r"[A-Za-z0-9_]"
INPUT_KIND_TO_INTERNAL = {"anim": "anim", "raster": "img"}
DISPLAY_KIND_BY_INTERNAL = {"anim": "anim", "img": "raster"}


def warn(message: str) -> None:
    print(f"warning: {message}")


def display_kind(kind: str) -> str:
    return DISPLAY_KIND_BY_INTERNAL.get(kind, kind)


@dataclass(frozen=True)
class Rename:
    kind: str
    sprite: str
    old: str
    new: str
    line_num: int


def parse_renames(path: Path) -> list[Rename]:
    renames: list[Rename] = []
    seen: set[tuple[str, str, str]] = set()

    with path.open() as f:
        for line_num, line in enumerate(f, start=1):
            stripped = line.strip()
            if not stripped or stripped.startswith("#"):
                continue

            parts = stripped.split()
            if len(parts) != 4 or parts[1] not in INPUT_KIND_TO_INTERNAL:
                raise ValueError(
                    f"{path}:{line_num}: expected: "
                    "SpriteName anim|raster OldName NewName"
                )

            sprite, kind_text, old, new = parts
            rename = Rename(
                kind=INPUT_KIND_TO_INTERNAL[kind_text],
                sprite=sprite,
                old=old,
                new=new,
                line_num=line_num,
            )
            key = (rename.kind, rename.sprite, rename.old)
            if key in seen:
                raise ValueError(
                    f"{path}:{line_num}: duplicate rename for "
                    f"{rename.sprite} {display_kind(rename.kind)} {rename.old}"
                )
            seen.add(key)
            renames.append(rename)

    return renames


def load_npc_config(path: Path) -> dict:
    with path.open() as f:
        data = yaml.load(f, Loader=yaml.SafeLoader)
    if not isinstance(data, dict):
        raise ValueError(f"{path}: expected top-level mapping")
    return data


def get_sprite_cfg(npc_cfg: dict, sprite: str, yaml_path: Path) -> dict:
    if sprite not in npc_cfg:
        raise ValueError(f"{yaml_path}: sprite '{sprite}' does not exist")
    cfg = npc_cfg[sprite]
    if not isinstance(cfg, dict):
        raise ValueError(f"{yaml_path}: sprite '{sprite}' entry is not a mapping")
    return cfg


def validate_yaml_renames(npc_cfg: dict, renames: Iterable[Rename]) -> list[Rename]:
    list_key_by_kind = {"anim": "animations", "img": "frames"}
    valid_renames: list[Rename] = []

    for rename in renames:
        list_key = list_key_by_kind[rename.kind]
        cfg = npc_cfg.get(rename.sprite)
        if cfg is None:
            warn(
                f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' does not exist; "
                f"skipping YAML update for line {rename.line_num}"
            )
            continue
        if not isinstance(cfg, dict):
            warn(
                f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' entry is not a mapping; "
                f"skipping YAML update for line {rename.line_num}"
            )
            continue

        values = cfg.get(list_key)
        if not isinstance(values, list):
            warn(
                f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' has no '{list_key}' list; "
                f"skipping YAML update for line {rename.line_num}"
            )
            continue
        if rename.old not in values:
            warn(
                f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' {list_key} does not "
                f"contain '{rename.old}'; skipping YAML update for line {rename.line_num}"
            )
            continue
        if rename.new in values and rename.new != rename.old:
            raise ValueError(
                f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' {list_key} already "
                f"contains '{rename.new}'"
            )

        valid_renames.append(rename)

    return valid_renames


def find_top_level_block(lines: list[str], sprite: str) -> tuple[int, int]:
    start_re = re.compile(rf"^{re.escape(sprite)}:\s*(?:#.*)?$")
    start = next((i for i, line in enumerate(lines) if start_re.match(line)), None)
    if start is None:
        raise ValueError(f"{NPC_NAMES_YAML}: could not find sprite block '{sprite}'")

    end = len(lines)
    for i in range(start + 1, len(lines)):
        if re.match(r"^[A-Za-z0-9_]+:\s*(?:#.*)?$", lines[i]):
            end = i
            break
    return start, end


def find_list_block(
    lines: list[str], sprite_start: int, sprite_end: int, list_key: str
) -> tuple[int, int]:
    key_re = re.compile(rf"^  {re.escape(list_key)}:\s*(?:#.*)?$")
    key_index = next(
        (i for i in range(sprite_start + 1, sprite_end) if key_re.match(lines[i])),
        None,
    )
    if key_index is None:
        raise ValueError(f"{NPC_NAMES_YAML}: could not find '{list_key}' list")

    end = sprite_end
    for i in range(key_index + 1, sprite_end):
        if re.match(r"^  [A-Za-z0-9_]+:\s*(?:#.*)?$", lines[i]):
            end = i
            break
    return key_index + 1, end


def update_yaml_text(path: Path, renames: Iterable[Rename]) -> int:
    list_key_by_kind = {"anim": "animations", "img": "frames"}
    lines = path.read_text().splitlines(keepends=True)
    changed = 0

    for rename in renames:
        try:
            sprite_start, sprite_end = find_top_level_block(lines, rename.sprite)
            list_start, list_end = find_list_block(
                lines, sprite_start, sprite_end, list_key_by_kind[rename.kind]
            )
        except ValueError as err:
            warn(f"{err}; skipping YAML update for line {rename.line_num}")
            continue

        item_re = re.compile(rf"^(\s*-\s*){re.escape(rename.old)}(\s*(?:#.*)?\n?)$")

        for i in range(list_start, list_end):
            match = item_re.match(lines[i])
            if match:
                lines[i] = f"{match.group(1)}{rename.new}{match.group(2)}"
                changed += 1
                break
        else:
            warn(
                f"{path}: could not update {display_kind(rename.kind)} "
                f"{rename.sprite} {rename.old}; skipping YAML update for "
                f"line {rename.line_num}"
            )

    path.write_text("".join(lines), newline="\n")
    return changed


def animation_symbol_renames(npc_cfg: dict, rename: Rename) -> dict[str, str]:
    replacements = {
        f"ANIM_{rename.sprite}_{rename.old}": f"ANIM_{rename.sprite}_{rename.new}"
    }

    cfg = npc_cfg.get(rename.sprite)
    if cfg is None:
        warn(
            f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' does not exist; "
            f"only replacing base animation symbol for line {rename.line_num}"
        )
        return replacements
    if not isinstance(cfg, dict):
        warn(
            f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' entry is not a mapping; "
            f"only replacing base animation symbol for line {rename.line_num}"
        )
        return replacements

    palettes = cfg.get("palettes") or ["Default"]
    if not isinstance(palettes, list):
        warn(
            f"{NPC_NAMES_YAML}: sprite '{rename.sprite}' palettes entry is not a list; "
            f"only replacing base animation symbol for line {rename.line_num}"
        )
        return replacements

    for palette in palettes:
        if palette == "Default":
            continue
        replacements[f"ANIM_{rename.sprite}_{palette}_{rename.old}"] = (
            f"ANIM_{rename.sprite}_{palette}_{rename.new}"
        )
    return replacements


def build_text_replacements(npc_cfg: dict, renames: Iterable[Rename]) -> dict[str, str]:
    replacements: dict[str, str] = {}

    for rename in renames:
        if rename.kind == "anim":
            replacements.update(animation_symbol_renames(npc_cfg, rename))
        else:
            replacements[f"IMG_{rename.sprite}_{rename.old}"] = (
                f"IMG_{rename.sprite}_{rename.new}"
            )

    return replacements


def build_asset_replacements(rename: Rename) -> dict[str, str]:
    if rename.kind == "anim":
        return {f'name="{rename.old}"': f'name="{rename.new}"'}
    return {f"{rename.old}.png": f"{rename.new}.png"}


def is_text_path(path: Path) -> bool:
    return path.suffix in TEXT_SUFFIXES or path.name in {"splat.yaml", "symbol_addrs.txt"}


def iter_text_files(root: Path) -> Iterable[Path]:
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        for filename in filenames:
            path = Path(dirpath) / filename
            if is_text_path(path):
                yield path


def replace_identifiers(text: str, replacements: dict[str, str]) -> str:
    if not replacements:
        return text

    keys = sorted(replacements, key=len, reverse=True)
    pattern = re.compile(
        r"(?<!"
        + WORD_EDGE
        + r")("
        + "|".join(re.escape(key) for key in keys)
        + r")(?!"
        + WORD_EDGE
        + r")"
    )
    return pattern.sub(lambda match: replacements[match.group(1)], text)


def replace_text_files(replacements: dict[str, str], dry_run: bool) -> int:
    changed = 0

    for path in iter_text_files(ROOT_DIR):
        text = path.read_text(errors="ignore")
        new_text = replace_identifiers(text, replacements)
        if new_text == text:
            continue
        changed += 1
        if not dry_run:
            path.write_text(new_text, newline="\n")

    return changed


def replace_sprite_asset_text(renames: Iterable[Rename], dry_run: bool) -> int:
    changed = 0

    for rename in renames:
        replacements = build_asset_replacements(rename)
        for sprite_dir in ROOT_DIR.glob(f"assets/*/sprite/npc/{rename.sprite}"):
            for path in iter_text_files(sprite_dir):
                text = path.read_text(errors="ignore")
                new_text = replace_identifiers(text, replacements)
                if new_text == text:
                    continue
                changed += 1
                if not dry_run:
                    path.write_text(new_text, newline="\n")

    return changed


def rename_raster_files(renames: Iterable[Rename], dry_run: bool) -> int:
    changed = 0

    for rename in renames:
        if rename.kind != "img":
            continue

        for old_path in ROOT_DIR.glob(
            f"assets/*/sprite/npc/{rename.sprite}/rasters/{rename.old}.png"
        ):
            new_path = old_path.with_name(f"{rename.new}.png")
            if new_path.exists() and old_path != new_path:
                raise FileExistsError(f"refusing to overwrite existing file: {new_path}")
            changed += 1
            if not dry_run:
                old_path.rename(new_path)

    return changed


def apply_renames(rename_file: Path, dry_run: bool) -> None:
    renames = parse_renames(rename_file)
    if not renames:
        print(f"No renames found in {rename_file}")
        return

    npc_cfg = load_npc_config(NPC_NAMES_YAML)
    yaml_renames = validate_yaml_renames(npc_cfg, renames)
    replacements = build_text_replacements(npc_cfg, renames)

    print(f"Loaded {len(renames)} sprite renames")
    print(f"Prepared {len(replacements)} text replacements")

    if dry_run:
        print("Dry run: no files will be changed")
    else:
        yaml_changes = update_yaml_text(NPC_NAMES_YAML, yaml_renames)
        print(f"Updated {yaml_changes} entries in {NPC_NAMES_YAML.relative_to(ROOT_DIR)}")

    text_files = replace_text_files(replacements, dry_run)
    asset_text_files = replace_sprite_asset_text(renames, dry_run)
    raster_files = rename_raster_files(renames, dry_run)

    action = "Would update" if dry_run else "Updated"
    print(f"{action} {text_files} text files")
    print(f"{action} {asset_text_files} sprite asset text files")
    print(f"{action} {raster_files} raster files")


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Apply NPC sprite animation and raster renames."
    )
    parser.add_argument(
        "--file",
        type=Path,
        default=RENAME_FILE,
        help=f"rename list to consume, default: {RENAME_FILE.relative_to(ROOT_DIR)}",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="validate and report changes without writing files",
    )
    args = parser.parse_args()

    apply_renames(args.file, args.dry_run)


if __name__ == "__main__":
    main()
