#include "dead.h"
#include "common.h"

#define NAMESPACE EA0C10

const char ascii_EA6D70[] = "kzn_11";
const char ascii_EA6D78[] = "kzn_18";
extern s32 D_802466D0[];

INCLUDE_ASM(s32, "EA0C10", func_80240310_EA0C10);

INCLUDE_ASM(s32, "EA0C10", func_8024037C_EA0C7C);

INCLUDE_ASM(s32, "EA0C10", func_802403EC_EA0CEC);

INCLUDE_ASM(s32, "EA0C10", func_802404C4_EA0DC4);

INCLUDE_ASM(s32, "EA0C10", func_80240518_EA0E18);

INCLUDE_ASM(s32, "EA0C10", func_802406CC_EA0FCC);

INCLUDE_ASM(s32, "EA0C10", func_8024097C_EA127C);

#include "world/common/UnkNpcAIFunc31.inc.c"

#include "world/common/UnkNpcAIFunc32.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_80240DC4_EA16C4);

INCLUDE_ASM(s32, "EA0C10", func_80241804_EA2104);

INCLUDE_ASM(s32, "EA0C10", func_80241894_EA2194);

INCLUDE_ASM(s32, "EA0C10", func_80241994_EA2294);

INCLUDE_ASM(s32, "EA0C10", func_802419F4_EA22F4);

INCLUDE_ASM(s32, "EA0C10", func_80241AE0_EA23E0);

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_8024207C_EA297C);

INCLUDE_ASM(s32, "EA0C10", func_802420FC_EA29FC);

INCLUDE_ASM(s32, "EA0C10", func_80242568_EA2E68);

INCLUDE_ASM(s32, "EA0C10", func_802425B0_EA2EB0);

INCLUDE_ASM(s32, "EA0C10", func_80242608_EA2F08);

INCLUDE_ASM(s32, "EA0C10", func_8024267C_EA2F7C);

#include "world/common/DeadGetItemName.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_80242794_EA3094);

INCLUDE_ASM(s32, "EA0C10", func_802427F0_EA30F0);

INCLUDE_ASM(s32, "EA0C10", func_802429C0_EA32C0);

INCLUDE_ASM(s32, "EA0C10", func_80242A14_EA3314);

ApiStatus func_80242A4C_EA334C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802466D0[i] = ptr[i];
        }
        D_802466D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802466D0[i] = i + 16;
            D_802466D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EA0C10", func_80242AE8_EA33E8);

//INCLUDE_ASM(s32, "EA0C10", func_80242BD8_EA34D8);
//#include "world/common/UnkYawFunc.inc.c"
ApiStatus N(UnkYawFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    f32 a = evt_get_variable(script, a0);
    s32 a1 = *args++;
    f32 b = evt_get_variable(script, a1);
    s32 a2 = *args++;
    f32 c = evt_get_variable(script, a2);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    f32 currentCamYaw = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);

    add_vec2D_polar(&a, &c, 15.0f, partner->yaw);
    add_vec2D_polar(&a, &c, 10.0f, currentCamYaw);

    evt_set_variable(script, a0, a);
    evt_set_variable(script, a1, b);
    evt_set_variable(script, a2, c);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EA0C10", func_80242D64_EA3664);

INCLUDE_ASM(s32, "EA0C10", func_80242DA8_EA36A8);
