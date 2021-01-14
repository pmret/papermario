#! /usr/bin/python3

from sys import argv
from collections import OrderedDict
import re
import msgpack
import os

class Message:
    def __init__(self, d: dict, header_file_index: int):
        self.section = d.get("section")
        self.index = d.get("index")
        self.name = d.get("name")
        self.bytes = d["bytes"]
        self.header_file_index = header_file_index

if __name__ == "__main__":
    if len(argv) < 3:
        print("usage: combine.py [out.bin] [compiled...] --headers [out.h]")
        exit(1)

    _, outfile, *infiles = argv

    messages = []
    header_files = []

    for i, infile in enumerate(infiles):
        if infile == "--headers":
            header_files = infiles[i+1:]
            break

        with open(infile, "rb") as f:
            messages.extend(Message(msg, i) for msg in msgpack.unpack(f))

    with open(outfile, "wb") as f:
        # sectioned+indexed, followed by just sectioned, followed by just indexed, followed by named (unsectioned & unindexed)
        messages.sort(key=lambda msg: bool(msg.section)<<2 + bool(msg.index))

        names = set()

        sections = [] * 0x2E
        messages_by_file = {}

        for message in messages:
            if message.section is None:
                # allocate a section
                for section_idx, section in enumerate(sections):
                    if len(section) < 0xFFF:
                        break
            else:
                section_idx = message.section
            while len(sections) <= section_idx:
                sections.append([])
            section = sections[section_idx]

            index = message.index if message.index is not None else len(section)

            if message.name:
                if message.name in names:
                    print(f"warning: multiple messages with name '{message.name}'")
                else:
                    names.add(message.name)

                if message.header_file_index in messages_by_file:
                    messages_by_file[message.header_file_index].add(message)
                else:
                    messages_by_file[message.header_file_index] = set([message])

            section.append(message.bytes)

        f.seek((len(sections) + 1) * 4) # skip past table of contents

        section_offsets = []
        for section in sections:
            message_offsets = []
            for message in section:
                message_offsets.append(f.tell())
                f.write(message)

            section_offset = f.tell()
            section_offsets.append(section_offset)
            for offset in message_offsets:
                f.write(offset.to_bytes(4, byteorder="big"))
            f.write(section_offset.to_bytes(4, byteorder="big"))

            # padding
            while f.tell() % 0x10 != 0:
                f.write(b'\0\0\0\0')

        f.seek(0)
        for offset in section_offsets:
            f.write(offset.to_bytes(4, byteorder="big"))
        f.write(b'\0\0\0\0')

    for i, header_file in enumerate(header_files):
        messages = messages_by_file.get(i, [])

        h = (
            f"#ifndef _MESSAGE_IDS_{i}_H_\n"
            f"#define _MESSAGE_IDS_{i}_H_\n"
            "\n"
            '#include "messages.h"\n'
            "\n"
        )

        for message in messages:
            h += f"#define MessageID_{message.name} MESSAGE_ID({message.section}, {message.index})\n"

        h += "\n#endif\n"
        h_lines = h.splitlines()

        # this doesnt work properly with ninja. the build is fast enough anyway
        """
        # only rewrite the header file if its content changed
        with open(header_file, "r") as f:
            cur_h_lines = f.read().splitlines()
            is_different = cur_h_lines != h_lines

        if is_different:
            with open(header_file, "w") as f:
                f.write(h)
        """

        with open(header_file, "w") as f:
            f.write(h)
