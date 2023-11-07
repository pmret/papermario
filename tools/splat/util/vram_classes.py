from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional

from util import log


@dataclass(frozen=True)
class VramClass:
    name: str
    vram: int
    given_vram_symbol: Optional[str] = None
    follows_classes: List[str] = field(default_factory=list, compare=False)

    @property
    def vram_symbol(self) -> Optional[str]:
        if self.given_vram_symbol is not None:
            return self.given_vram_symbol
        elif self.follows_classes:
            return self.name + "_CLASS_VRAM"
        else:
            return None


_vram_classes: Dict[str, VramClass] = {}


def initialize(yaml: Any):
    global _vram_classes

    _vram_classes = {}

    if yaml is None:
        return

    if not isinstance(yaml, list):
        log.error("vram_classes must be a list")

    class_names = set()
    for vram_class in yaml:
        if isinstance(vram_class, dict):
            if "name" not in vram_class:
                log.error(f"vram_class ({vram_class}) must have a name")
            class_names.add(vram_class["name"])
        elif isinstance(vram_class, list):
            class_names.add(vram_class[0])

    for vram_class in yaml:
        name: str
        vram: int
        vram_symbol: Optional[str] = None
        follows_classes: List[str] = []

        if isinstance(vram_class, dict):
            if "name" not in vram_class:
                log.error(f"vram_class ({vram_class}) must have a name")
            name = vram_class["name"]

            if "vram" not in vram_class:
                log.error(f"vram_class ({vram_class}) must have a vram")
            vram = vram_class["vram"]

            if "vram_symbol" in vram_class:
                vram_symbol = vram_class["vram_symbol"]
                if not isinstance(vram_symbol, str):
                    log.error(
                        f"vram_symbol ({vram_symbol})must be a string, got {type(vram_symbol)}"
                    )

            if "follows_classes" in vram_class:
                follows_classes = vram_class["follows_classes"]
                if not isinstance(follows_classes, list):
                    log.error(
                        f"vram_symbol ({follows_classes})must be a list, got {type(follows_classes)}"
                    )
                for follows_class in follows_classes:
                    if follows_class not in class_names:
                        log.error(
                            f"follows_class ({follows_class}) not found in vram_classes"
                        )
        elif isinstance(vram_class, list):
            if len(vram_class) != 2:
                log.error(
                    f"vram_class ({vram_class}) must have 2 elements, got {len(vram_class)}"
                )
            name = vram_class[0]
            vram = vram_class[1]
        else:
            log.error(f"vram_class must be a dict or list, got {type(vram_class)}")

        if not isinstance(name, str):
            log.error(f"vram_class name ({name}) must be a string, got {type(name)}")
        if not isinstance(vram, int):
            log.error(f"vram_class vram ({vram}) must be an int, got {type(vram)}")
        if name in _vram_classes:
            log.error(f"Duplicate vram class name '{name}'")
        _vram_classes[name] = VramClass(name, vram, vram_symbol, follows_classes)


def resolve(name: str) -> VramClass:
    if name not in _vram_classes:
        log.error(f"Unknown vram class '{name}'")
    return _vram_classes[name]
