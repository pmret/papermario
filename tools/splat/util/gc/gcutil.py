def read_string_from_bytes(name_offset, string_table_bytes):
    bytes = bytearray()

    for offset in range(len(string_table_bytes) - name_offset):
        cur_byte = string_table_bytes[name_offset + offset]
        if cur_byte == 0x00:
            break

        bytes.append(cur_byte)

    return bytes.decode("shift-jis")
