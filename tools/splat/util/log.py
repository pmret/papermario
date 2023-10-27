import sys
from typing import NoReturn, Optional
from pathlib import Path

from colorama import Fore, init, Style

init(autoreset=True)

newline = True

Status = Optional[str]


def write(*args, status=None, **kwargs):
    global newline

    if not newline:
        print("")
        newline = True

    print(status_to_ansi(status) + str(args[0]), *args[1:], **kwargs)


def error(*args, **kwargs) -> NoReturn:
    write(*args, **kwargs, status="error")
    sys.exit(2)


# The line_num is expected to be zero-indexed
def parsing_error_preamble(path: Path, line_num: int, line: str):
    write("")
    write(f"error reading {path}, line {line_num + 1}:", status="error")
    write(f"\t{line}")


def status_to_ansi(status: Status):
    if status == "ok":
        return Fore.GREEN
    elif status == "warn":
        return Fore.YELLOW + Style.BRIGHT
    elif status == "error":
        return Fore.RED + Style.BRIGHT
    elif status == "skip":
        return Style.DIM
    else:
        return ""
