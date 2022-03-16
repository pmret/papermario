#include "common.h"

#define NAMESPACE battle_move_shell_crack

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

extern void fx_floating_cloud_puff(int, f32, f32, f32, f32, s32); /* extern */

int func_802A10A4_77F2E4(void) {
    ActorState *temp_s0;
    f32 temp_f20;
    s32 temp_s1;
    s32 phi_s1;

    temp_s0 = &gBattleStatus.playerActor->state;
    phi_s1 = 0;
    do {
        temp_f20 = (temp_s0->goalPos.x + (f32) rand_int(0x1E)) - 15.0f;
        temp_s1 = ++phi_s1;
        fx_floating_cloud_puff(0, temp_f20, (temp_s0->goalPos.y + (f32) rand_int(0x14)) - 15.0f, temp_s0->goalPos.z + 5.0f, 1.0f, 0x19);
        phi_s1 = temp_s1;
    } while (temp_s1 < 0x14);
    return 2;
}
/* Warning: struct EffectInstance is not defined (only forward-declared) */
/* Warning: struct ActorBlueprint is not defined (only forward-declared) */

