#include "kmr_12.h"

static EntryList entryList = {
    { -126.0f, 0.0f, 12.0f, 90.0f }, // west, towards Red/Blue Goomba miniboss room
    { 471.0f, 0.0f, 12.0f, 270.0f }, // east, towards Goomba King's Fortress
};

MapHeader header = {
    .main = kmr_12_main,
    .entryList = entryList,
    .entryCount = ENTRY_COUNT(entryList),
    .background = 0x80200000,
    .tattle = MessageID_TATTLE_KMR_12,
};

Script kmr_12_play_music = {
    SI_CALL(SetMusicTrack, 0, Song_PLEASANT_PATH, 0, 8),
    SI_RETURN(),
    SI_END(),
};

ApiStatus kmr_12_get_goomba_ref(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_enemy_safe(NpcId_GOOMBA);
    return ApiStatus_DONE2;
}
