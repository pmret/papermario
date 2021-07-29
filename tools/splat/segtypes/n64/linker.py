from segtypes.n64.segment import N64Segment

class N64SegLinker(N64Segment):
    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        return [LinkerEntry(self, [], self.name, "linker")]

