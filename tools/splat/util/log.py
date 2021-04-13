import sys
from colorama import init, Fore, Style
from typing import Union

init(autoreset=True)

newline = True

Status = Union[None, str]

def write(*args, status=None, **kwargs):
    global newline

    if not newline:
        print("")
        newline = True

    print(status_to_ansi(status) + str(args[0]), *args[1:], **kwargs)

def error(*args, **kwargs):
    write(*args, **kwargs, status="error")
    sys.exit(2)

def dot(status: Status = None):
    global newline

    print(status_to_ansi(status) + ".", end="")
    newline = False

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
