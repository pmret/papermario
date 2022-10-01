#include "kmr_12.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -126.0f, 0.0f, 12.0f, 90.0f }, // west, towards Red/Blue Goomba miniboss room
    { 471.0f, 0.0f, 12.0f, 270.0f }, // east, towards Goomba King's Fortress
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_12 },
};

EvtScript N(PlayMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    EVT_RETURN
    EVT_END
};

ApiStatus GetGoomba(Evt* script, s32 isInitialCall) {
    script->varTablePtr[0] = get_enemy_safe(NPC_GOOMBA);
    return ApiStatus_DONE2;
}
