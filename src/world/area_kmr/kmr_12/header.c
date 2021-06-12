#include "kmr_12.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -126.0f, 0.0f, 12.0f, 90.0f }, // west, towards Red/Blue Goomba miniboss room
    { 471.0f, 0.0f, 12.0f, 270.0f }, // east, towards Goomba King's Fortress
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_kmr_12_tattle },
};

Script N(PlayMusic) = SCRIPT({
    SetMusicTrack(0, SONG_PLEASANT_PATH, 0, 8);
});

ApiStatus GetGoomba(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0].s = get_enemy_safe(NPC_GOOMBA);
    return ApiStatus_DONE2;
}
