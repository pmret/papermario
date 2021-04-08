#include "common.h"
#include "audio.h"

typedef struct BufferEntry {
    /* 0x0 */ u16 fileIndex;
    /* 0x2 */ u8 bankIndex;
    /* 0x3 */ u8 unk_3;
} BufferEntry; // size = 4

void snd_load_BK_headers(UnkAl19E0* soundData, ALHeap* arg1) {
    SBNFileEntry fileEntry;
    BufferEntry buffer[80];
    s32 i;

    snd_read_rom(soundData->bkFileListOffset, &buffer, soundData->bkListLength);

    for (i = 0; i < ARRAY_COUNT(buffer); i++) {
        if (buffer[i].fileIndex == 0xFFFF) {
            break;
        }

        snd_fetch_SBN_file(buffer[i].fileIndex, 0x30, &fileEntry);
        snd_load_BK_to_bank(fileEntry.offset, NULL, buffer[i].bankIndex, buffer[i].unk_3);
    }
}
