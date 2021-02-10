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
        print("usage: combine.py [out.bin] [out.h] [compiled...]")
        exit(1)

    _, outfile, header_file, *infiles = argv

    messages = []
    #header_files = []

    for i, infile in enumerate(infiles):
        # if infile == "--headers":
        #     header_files = infiles[i+1:]
        #     break

        with open(infile, "rb") as f:
            messages.extend(Message(msg, i) for msg in msgpack.unpack(f))

    with open(outfile, "wb") as f:
        # sectioned+indexed, followed by just sectioned, followed by just indexed, followed by named (unsectioned & unindexed)
        #messages.sort(key=lambda msg: bool(msg.section)<<2 + bool(msg.index))

        names = set()

        sections = []
        #messages_by_file = {}

        # this logic could probably be a bit better (i.e. read ahead, so no overwriting happens)
        def section_get_unused_id(section):
            max_index = 0
            for index in section:
                if index > max_index:
                    max_index = index
            return max_index + 1

        for message in messages:
            if message.section is None:
                # allocate a section
                for section_idx, section in enumerate(sections):
                    if len(section) < 0xFFF:
                        break
                message.section = section_idx
            else:
                section_idx = message.section
            while len(sections) <= section_idx:
                sections.append({})
            section = sections[section_idx]

            if message.index is None:
                message.index = section_get_unused_id(section)

            # if message.name:
            #     if message.name in names:
            #         print(f"error: multiple messages with name '{message.name}'")
            #         exit(1)
            #     else:
            #         names.add(message.name)

                # if message.header_file_index in messages_by_file:
                #     messages_by_file[message.header_file_index].add(message)
                # else:
                #     messages_by_file[message.header_file_index] = set([message])

            if message.index in section:
                print(f"warning: multiple messages allocated to id {section_idx:02X}:{message.index:03X}")

            section[message.index] = message

        f.seek((len(sections) + 1) * 4) # skip past table of contents

        section_offsets = []
        for section in sections:
            # convert dict into sorted list
            section = [msg for idx, msg in sorted(section.items(), key=lambda ele: ele[0])]

            message_offsets = []
            for message in section:
                message_offsets.append(f.tell())
                f.write(message.bytes)

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

    with open(header_file, "w") as f:
        f.write(
            f"#ifndef _MESSAGE_IDS_H_\n"
            f"#define _MESSAGE_IDS_H_\n"
            "\n"
            '#include "messages.h"\n'
            "\n"
        )

        for message in messages:
            if message.name:
                f.write(f"#define MSG_{message.name} MESSAGE_ID(0x{message.section:02X}, 0x{message.index:03X})\n")

        f.write("\n#endif\n")
