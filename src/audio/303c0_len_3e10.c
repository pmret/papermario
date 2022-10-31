#include "common.h"
#include "audio.h"

typedef struct BufferEntry {
    /* 0x0 */ u16 fileIndex;
    /* 0x2 */ u8 bankIndex;
    /* 0x3 */ u8 bankGroup;
} BufferEntry; // size = 4

void au_load_BK_headers(AuGlobals* globals, ALHeap* heap) {
    SBNFileEntry fileEntry;
    BufferEntry buffer[80];
    s32 i;

    au_read_rom(globals->bkFileListOffset, &buffer, globals->bkListLength);

    for (i = 0; i < ARRAY_COUNT(buffer); i++) {
        if (buffer[i].fileIndex == 0xFFFF) {
            break;
        }

        au_fetch_SBN_file(buffer[i].fileIndex, AU_FMT_BK, &fileEntry);
        au_load_BK_to_bank(fileEntry.offset, NULL, buffer[i].bankIndex, buffer[i].bankGroup);
    }
}
