#include "common.h"
#include "script_api/map.h"

Bytecode kmr_12_main[];

f32 entryList[][4] = {
    { -126.0f, 0.0f, 12.0f, 90.0f }, // west, towards Red/Blue Goomba miniboss room
    { 471.0f, 0.0f, 12.0f, 270.0f }, // east, towards Goomba King's Fortress
};

MapHeader header = {
    .mainScript = &kmr_12_main,
    .entryList = entryList,
    .background = 0x80200000,
    .tattle = 0x00190040,
};

Bytecode kmr_12_play_music[] = {
    SI_CALL(&SetMusicTrack, 0, Song_PLEASANT_PATH, 0, 8),
    SI_RETURN(),
    SI_END(),
};
