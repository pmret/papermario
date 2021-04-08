#include "flo_08.h"

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_8024003C_CAED7C);
/*
ApiStatus N(func_8024003C_CAED7C)(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
*/

#include "world/common/UnkFunc18.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_802400D4_CAEE14);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_80240120_CAEE60);
/*
ApiStatus N(func_80240120_CAEE60)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 i;
    s16 var = script->varTable[12] >= 0;

    script->varTable[0] = -1;

    for (i = 1; i < 12; i++) {
        if (playerData->partners[i].enabled && N(func_802424A4_C389D4)(i, var) != -1) {
            script->varTable[0] = 1;
            break;
        }
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_802401CC_CAEF0C);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_8024041C_CAF15C);
/*
ApiStatus N(func_8024041C_CAF15C)(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
*/

#include "world/common/UnkFunc19.inc.c"

#include "world/common/UnkFunc20.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_80240510_CAF250);
/*
ApiStatus N(func_80240510_CAF250)(ScriptInstance *script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);

    effect->flags |= 0x10;

    return ApiStatus_DONE2;
}
*/

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_80240600_CAF340);
/*
ApiStatus N(func_80240600_CAF340)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    Npc* npc = get_npc_safe(-4);
    f32 sinTheta, cosTheta;
    s32 i;
    f32 var;
    UserData* userDataPtr;
    UserData* scriptPtr;
    f32 save, save2;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (UserData*)general_heap_malloc(0x68);
        scriptPtr = (UserData*)script->userData;

        scriptPtr->unk_5C = get_entity_by_index(get_variable(script, *args));

        for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
            userDataPtr->unk_08[i] = func_800716F0(0, scriptPtr->unk_5C->position.x, scriptPtr->unk_5C->position.y + 12.5f, scriptPtr->unk_5C->position.z, 1.0f, -1);
            save = 0.0f;
            userDataPtr->unk_2C[i] = save;
            userDataPtr->unk_20[i] = save;
            userDataPtr->unk_14[i] = save;
            userDataPtr->unk_50[i] = save;
            userDataPtr->unk_44[i] = save;
            userDataPtr->unk_38[i] = save;
        }

        scriptPtr->unk_00 = 0;
        scriptPtr->unk_04 = 0;
        scriptPtr->unk_60 = 0;
        scriptPtr->unk_64 = 0;

        userDataPtr = scriptPtr;
        for (i = 0, save = 50.0f; i < 3; i++) {
            var = 0;
            add_vec2D_polar(&var, &scriptPtr->unk_44[i], save, *(N(D_80243D88_C3A2B8) + i)); //*(dataPtr++));
            userDataPtr->unk_38[i] = cosTheta * var;
            userDataPtr->unk_50[i] = sinTheta * var;
            userDataPtr->unk_38[i] = npc->pos.x - (scriptPtr->unk_5C->position.x + userDataPtr->unk_38[i]);
            userDataPtr->unk_44[i] = npc->pos.y - (scriptPtr->unk_5C->position.y + userDataPtr->unk_44[i]);
            userDataPtr->unk_50[i] = npc->pos.z - (scriptPtr->unk_5C->position.z + userDataPtr->unk_50[i]);
        }
    }

    scriptPtr = (UserData*)script->userData;
    switch (scriptPtr->unk_00) {
        case 0:
            save = update_lerp(5, 0.0f, 50.0f, scriptPtr->unk_60, 0x14);
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, *(N(D_80243D88_C3A2B8) + i));
                scriptPtr->unk_14[i] = cosTheta * var;
                scriptPtr->unk_2C[i] = sinTheta * var;
            }

            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x15) {
                scriptPtr->unk_00 = 1;
                scriptPtr->unk_60 = 0;
            }
            break;

        case 1:
            save = 50.0f;
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, *(N(D_80243D88_C3A2B8) + i));
                scriptPtr->unk_14[i] = cosTheta * var;
                scriptPtr->unk_2C[i] = sinTheta * var;
            }

            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x10) {
                scriptPtr->unk_60 = 0xF;
                scriptPtr->unk_00 = 2;
            }
            break;

        case 2:
            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x1F) {
                for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
                    userDataPtr->unk_08[i]->flags |= 0x10;
                }
                return ApiStatus_DONE2;
            }
    }

    switch (scriptPtr->unk_04) {
        case 0:
            scriptPtr->unk_64++;
            if (scriptPtr->unk_64 >= 0x10) {
                scriptPtr->unk_04 = 1;
                scriptPtr->unk_64 = 0;
            }
            break;

        case 1:
            for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
                userDataPtr->unk_14[i] = userDataPtr->unk_14[i] + update_lerp(1, 0.0f, userDataPtr->unk_38[i], scriptPtr->unk_64, 0x14);
                userDataPtr->unk_20[i] = userDataPtr->unk_20[i] + update_lerp(1, 0.0f, userDataPtr->unk_44[i], scriptPtr->unk_64, 0x14);
                userDataPtr->unk_2C[i] = userDataPtr->unk_2C[i] + update_lerp(1, 0.0f, userDataPtr->unk_50[i], scriptPtr->unk_64, 0x14);
            }

            scriptPtr->unk_64++;
            if (scriptPtr->unk_64 >= 0x15) {
                scriptPtr->unk_04 = 2;
                scriptPtr->unk_64 = 0;
            }
            break;
    }

    for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
        ((EffectInstanceData*)userDataPtr->unk_08[i]->unk_0C)->rotation.x = userDataPtr->unk_14[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->unk_0C)->rotation.y = userDataPtr->unk_20[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->unk_0C)->rotation.z = userDataPtr->unk_2C[i];
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_80240B38_CAF878);
/*
s32 N(func_80240B38_CAF878)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 ret = 0;

    if (isInitialCall) {
        script->varTable[0] = get_variable(script, *args++);
        script->varTable[1] = get_variable(script, *args++);
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 0;
        set_transition_stencil_color(0, 0xD0, 0xD0, 0xD0);
    }

    switch (script->functionTemp[0].s) {
        case 0:
            if (script->functionTemp[1].s == 0xFF) {
                script->functionTemp[0].s = 1;
                script->functionTemp[2].s = 0;
            }
            script->functionTemp[1].s += script->varTable[0];
            if (script->functionTemp[1].s >= 0x100) {
                script->functionTemp[1].s = 0xFF;
            }
            break;

        case 1:
            script->functionTemp[2].s++;
            if (script->functionTemp[2].s >= 2) {
                script->functionTemp[0].s = 2;
            }
            break;

        case 2:
            if (script->functionTemp[1].s == 0) {
                ret = 1;
            }
            script->functionTemp[1].s -= script->varTable[1];
            if (script->functionTemp[1].s < 0) {
                script->functionTemp[1].s = 0;
            }
            break;
    }

    set_transition_stencil_zoom_0(1, script->functionTemp[1].s);

    return ret;
}
*/

#include "world/common/UnkPartnerPosFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAED40", func_80240D08_CAFA48);
