from pathlib import Path

def parse_folder(path):
    for entry in path.iterdir():
        if entry.is_dir():
            parse_folder(entry)
        else:
            fd = entry.read_text().splitlines()
            if fd[-1] != "":
                fd.append("")
                entry.write_text("\n".join(fd))

parse_folder(Path("src"))
