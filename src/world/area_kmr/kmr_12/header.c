#include "kmr_12.h"

Vec4f M(entryList)[] = {
    { -126.0f, 0.0f, 12.0f, 90.0f }, // west, towards Red/Blue Goomba miniboss room
    { 471.0f, 0.0f, 12.0f, 270.0f }, // east, towards Goomba King's Fortress
};

MapConfig M(config) = {
    .main = M(Main),
    .entryList = M(entryList),
    .entryCount = ENTRY_COUNT(M(entryList)),
    .background = &gBackgroundImage,
    .tattle = MessageID_TATTLE_KMR_12,
};

Script M(PlayMusic) = SCRIPT({
    SetMusicTrack(0, Song_PLEASANT_PATH, 0, 8);
});

ApiStatus GetGoomba(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_enemy_safe(NpcId_GOOMBA);
    return ApiStatus_DONE2;
}
