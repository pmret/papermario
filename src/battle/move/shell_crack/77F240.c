#include "common.h"

#include "effects.h"

#define NAMESPACE battle_move_shell_crack

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

ApiStatus func_802A10A4_77F2E4(Evt* script, s32 isInitialCall) {
    ActorState* playerActorState = &gBattleStatus.playerActor->state;
    s32 i;

    for (i = 0; i < 20; i++) {
        fx_floating_cloud_puff(0, 
                               (playerActorState->goalPos.x + (f32) rand_int(30)) - 15.0f, 
                               (playerActorState->goalPos.y + (f32) rand_int(20)) - 15.0f, 
                               playerActorState->goalPos.z + 5.0f, 1.0f, 25);   
    }

    return ApiStatus_DONE2;
}
