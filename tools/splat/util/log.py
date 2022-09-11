import sys
from colorama import init, Fore, Style
from typing import Optional

init(autoreset=True)

newline = True

Status = Optional[str]


def write(*args, status=None, **kwargs):
    global newline

    if not newline:
        print("")
        newline = True

    print(status_to_ansi(status) + str(args[0]), *args[1:], **kwargs)


def error(*args, **kwargs):
    write(*args, **kwargs, status="error")
    sys.exit(2)


# The line_num is expected to be zero-indexed
def parsing_error_preamble(path, line_num, line):
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
