from util.gc import gcfst


def init(target_bytes: bytes):
    gcfst.split_iso(target_bytes)
