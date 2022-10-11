#include "dead.h"
#include "common.h"

// Copy of flo_13 (CC3850.c)

#define NAMESPACE EDEA00

#include "world/common/util/ChangeNpcToPartner.inc.c"

// must include this before LakituAI for the debug string to end up in the right position
#include "world/common/enemy/FlyingAI.inc.c"

const char D_80247B44_EE6504[] = "JUGEMU MOVE";

#define AI_LAKITU_FIRST_SPINY_ID    50
#define AI_LAKITU_LAST_SPINY_ID     55
#include "world/common/enemy/LakituAI.inc.c"
#include "world/common/enemy/SpinyAI.inc.c"

const char D_80247BB8_EE6578[] = "TOGEZO TYPE1 : NORMAL MOVE";

#include "world/common/UnkFunc42.inc.c"

ApiStatus func_80243470_EE1E30(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(1);
    s16 param1;
    s16 param2;

    script->functionTemp[1] = evt_get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == (script->functionTemp[0] / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
                                         &param1, &param2, 0x200002);

        sfx_play_sound_with_params(SOUND_295, param1, param2,
                                   update_lerp(0, 500.0f, 0.0f, script->functionTemp[0], script->functionTemp[1]));
    }

    script->functionTemp[0]++;
    return (script->functionTemp[1] < script->functionTemp[0]) * ApiStatus_DONE2;
}

ApiStatus func_80243584_EE1F44(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);
    s16 param1;
    s16 param2;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == (script->functionTemp[0] / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
                                         &param1, &param2, 0x200002);

        sfx_play_sound_with_params(SOUND_295, param1, param2,
                                   update_lerp(0, 500.0f, 0.0f, script->functionTemp[0], 0x50));
    }

    script->functionTemp[0]++;
    return (script->functionTemp[0] > 0x50) * ApiStatus_DONE2;
}
