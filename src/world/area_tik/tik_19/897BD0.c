#include "tik_19.h"

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_19/897BD0", func_8024062C_897C0C);
/*
ApiStatus N(func_8024062C_897C0C)(Evt* script, s32 isInitialCall) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
*/

#include "world/common/UnkFunc18.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_19/897BD0", func_802407BC_897D9C);

#include "world/common/SwitchToPartner.inc.c"

#include "world/common/UnkFunc19.inc.c"

#include "world/common/UnkFunc20.inc.c"

#include "world/common/UnkFunc39.inc.c"

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_19/897BD0", func_80240BF0_8981D0);
/*
ApiStatus N(func_80240BF0_8981D0)(Evt *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    Npc* npc = get_npc_safe(-4);
    f32 sinTheta, cosTheta;
    s32 i;
    f32 var;
    N(UserData)* userDataPtr;
    N(UserData)* scriptPtr;
    f32 save, save2;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (N(UserData)*)general_heap_malloc(0x68);
        scriptPtr = (N(UserData)*)script->userData;

        scriptPtr->unk_5C = get_entity_by_index(evt_get_variable(script, *args));

        for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
            userDataPtr->unk_08[i] = playFX_51(0, scriptPtr->unk_5C->position.x, scriptPtr->unk_5C->position.y + 12.5f, scriptPtr->unk_5C->position.z, 1.0f, -1);
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
            add_vec2D_polar(&var, &scriptPtr->unk_44[i], save, N(D_80242708_899CE8)[i]);
            userDataPtr->unk_38[i] = cosTheta * var;
            userDataPtr->unk_50[i] = sinTheta * var;
            userDataPtr->unk_38[i] = npc->pos.x - (scriptPtr->unk_5C->position.x + userDataPtr->unk_38[i]);
            userDataPtr->unk_44[i] = npc->pos.y - (scriptPtr->unk_5C->position.y + userDataPtr->unk_44[i]);
            userDataPtr->unk_50[i] = npc->pos.z - (scriptPtr->unk_5C->position.z + userDataPtr->unk_50[i]);
        }
    }

    scriptPtr = (N(UserData)*)script->userData;
    switch (scriptPtr->unk_00) {
        case 0:
            save = update_lerp(5, 0.0f, 50.0f, scriptPtr->unk_60, 0x14);
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, N(D_80242708_899CE8)[i]);
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
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, N(D_80242708_899CE8)[i]);
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

#include "world/common/UnkFunc23.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/UnkFunc40.inc.c"
