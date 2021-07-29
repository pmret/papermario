#include "kzn_19.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_8024030C_C8DEBC);
/*
ApiStatus N(func_8024030C_C8DEBC)(ScriptInstance* script, s32 isInitialCall) {
    arn_07_struct* ptr = script->varTable[0];

    sfx_adjust_env_sound_pos(0xA2, 0, ptr->unk_00, ptr->unk_04, ptr->unk_08);
    return ((ptr->unk_44 < 2) == 0) * ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240358_C8DF08);
/*
ApiStatus N(func_80240358_C8DF08)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        arn_07_struct* ptr = heap_malloc(sizeof(arn_07_struct));
        script->varTable[0] = ptr;
        set_variable(NULL, SI_MAP_VAR(1), ptr);
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_3C = get_variable(script, *args++);
        ptr->unk_0C = get_float_variable(script, *args++);
        ptr->unk_10 = get_float_variable(script, *args++);
        ptr->unk_14 = get_float_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_1C = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_50 = (struct N(temp)*)playFX_83(2, ptr->unk_0C, ptr->unk_10, ptr->unk_14, 1.0f, 0);
        ptr->unk_4E = 0;
        ptr->unk_48 = 0;
        ptr->unk_4A = 0;
        ptr->unk_44 = 0;
        ptr->unk_46 = 0;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802404B8_C8E068);

static char* N(exit_str_0) = "kmr_23";
static char* N(exit_str_1) = "kzn_18";
static char* N(exit_str_2) = "kzn_20";

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802408C8_C8E478);
/*
ApiStatus N(func_802408C8_C8E478)(ScriptInstance* script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    arn_07_struct* ptr = script->varTable[0];

    return (ptr->unk_4E == var) * ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240908_C8E4B8);
/*
ApiStatus N(func_80240908_C8E4B8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        arn_07_struct* ptr = heap_malloc(sizeof(arn_07_struct));
        script->varTable[0] = ptr;
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_54 = playFX_7B(1, ptr->unk_18, ptr->unk_24, ptr->unk_20, 1.0f, 0);
        ptr->unk_54->unk_0C->unk_34 = ptr->unk_38;
        ptr->unk_54->unk_0C->unk_20 = 0;
        ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
        ptr->unk_4C = 0x10E;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240A14_C8E5C4);
/*
ApiStatus N(func_80240A14_C8E5C4)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    arn_07_struct* ptr = script->varTable[0];

    ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
    ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
    if (dist2D(playerStatus->position.x, playerStatus->position.z,
               ptr->unk_18, ptr->unk_20) <= 30.0f) {
        ptr->unk_4E = 3;
    }
    ptr->unk_54->unk_0C->unk_04 = ptr->unk_18;
    ptr->unk_54->unk_0C->unk_08 = ptr->unk_04;
    ptr->unk_54->unk_0C->unk_0C = ptr->unk_20;

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240B00_C8E6B0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240BD4_C8E784);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240CD8_C8E888);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240DA4_C8E954);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240E2C_C8E9DC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413C0_C8EF70);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413FC_C8EFAC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_8024140C_C8EFBC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241468_C8F018);
/*
ApiStatus N(func_80241468_C8F018)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80243D74_C91924) == NULL) {
        N(D_80243D74_C91924) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80243D74_C91924)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80243D74_C91924)[i];
        }
        heap_free(N(D_80243D74_C91924));
        N(D_80243D74_C91924) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802417AC_C8F35C);
/*
ApiStatus N(func_802417AC_C8F35C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80243DD8_C91988) = FALSE;
    }

    if (N(D_80243DD8_C91988)) {
        N(D_80243DD8_C91988) = FALSE;
        set_variable(script, *args, N(D_80243DDC_C9198C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241800_C8F3B0);
/*
ApiStatus N(func_80241800_C8F3B0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80243DDC_C9198C) = get_variable(script, *args);
    N(D_80243DD8_C91988) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241838_C8F3E8);
/*
ApiStatus N(func_80241838_C8F3E8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241B50_C8F700);
/*
ApiStatus N(func_80241B50_C8F700)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241B94_C8F744);
/*
ApiStatus N(func_80241B94_C8F744)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241BC0_C8F770);
