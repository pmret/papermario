from dataclasses import dataclass


def dotless_type(type: str) -> str:
    return type[1:] if type[0] == "." else type


@dataclass
class LinkerSection:
    name: str
    started: bool = False
    ended: bool = False
