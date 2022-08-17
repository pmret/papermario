#include "mac_02.h"

ApiStatus func_802405F0_8238B0(Evt* script, s32 isInitialCall) {
    Npc* npc;
    s32 i;

    func_8011B950(71, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = get_npc_by_index(i);
        if (npc != NULL) {
            if (npc->flags != 0 && npc->npcID != NPC_PARTNER) {
                npc->flags |= NPC_FLAG_NO_DROPS;
            }
        }
    }

    return ApiStatus_DONE2;
}
