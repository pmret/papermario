#include "common.h"
#include "npc.h"
#include "effects.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    EffectGraphics* unk_08[3]; // TODO this is wrong
    f32 unk_14[3];
    f32 unk_20[3];
    f32 unk_2C[3];
    f32 unk_38[3];
    f32 unk_44[3];
    f32 unk_50[3];
    Entity* unk_5C;
    s32 unk_60;
    s32 unk_64;
} N(UserData);

extern f32 N(bigFuncFloats)[];

ApiStatus N(UnkFunc60)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner = get_npc_safe(NPC_PARTNER);
    N(UserData)* userData;
    f32 sinTheta, cosTheta;
    f32 x;
    f32 t1;
    s32 i;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (N(UserData)*)general_heap_malloc(0x68);
        userData = (N(UserData)*)script->userData;

        userData->unk_5C = get_entity_by_index(evt_get_variable(script, *args++));

        for (i = 0; i < ARRAY_COUNT(userData->unk_08); i++) {
            userData->unk_08[i] = (EffectGraphics*) fx_motion_blur_flame(0, userData->unk_5C->position.x,
                                                          userData->unk_5C->position.y + 12.5f,
                                                          userData->unk_5C->position.z, 1.0f, -1);
            t1 = 0.0f;
            userData->unk_2C[i] = t1;
            userData->unk_20[i] = t1;
            userData->unk_14[i] = t1;
            userData->unk_50[i] = t1;
            userData->unk_44[i] = t1;
            userData->unk_38[i] = t1;
        }

        userData->unk_00 = 0;
        userData->unk_04 = 0;
        userData->unk_60 = 0;
        userData->unk_64 = 0;

        t1 = 50.0f;
        for (i = 0; i < ARRAY_COUNT(userData->unk_38); i++) {
            x = 0.0f;
            add_vec2D_polar(&x, &userData->unk_44[i], t1, N(bigFuncFloats)[i]);
            userData->unk_38[i] = cosTheta * x;
            userData->unk_50[i] = sinTheta * x;
            userData->unk_38[i] = partner->pos.x - (userData->unk_5C->position.x + userData->unk_38[i]);
            userData->unk_44[i] = partner->pos.y - (userData->unk_5C->position.y + userData->unk_44[i]);
            userData->unk_50[i] = partner->pos.z - (userData->unk_5C->position.z + userData->unk_50[i]);
        }
    }

    userData = (N(UserData)*)script->userData;
    switch (userData->unk_00) {
        case 0:
            t1 = update_lerp(5, 0.0f, 50.0f, userData->unk_60, 20);
            for (i = 0; i < ARRAY_COUNT(userData->unk_20); i++) {
                x = userData->unk_20[i] = 0.0f;
                add_vec2D_polar(&x, &userData->unk_20[i], t1, N(bigFuncFloats)[i]);
                userData->unk_14[i] = cosTheta * x;
                userData->unk_2C[i] = sinTheta * x;
            }

            userData->unk_60++;
            if (userData->unk_60 >= 0x15) {
                userData->unk_00 = 1;
                userData->unk_60 = 0;
            }
            break;
        case 1:
            t1 = 50.0f;
            for (i = 0; i < ARRAY_COUNT(userData->unk_20); i++) {
                x = userData->unk_20[i] = 0.0f;
                add_vec2D_polar(&x, &userData->unk_20[i], t1, N(bigFuncFloats)[i]);
                userData->unk_14[i] = cosTheta * x;
                userData->unk_2C[i] = sinTheta * x;
            }

            userData->unk_60++;
            if (userData->unk_60 > 15) {
                userData->unk_60 = 15;
                userData->unk_00 = 2;
            }
            break;
        case 2:
            userData->unk_60++;
            if (userData->unk_60 > 30) {
                for (i = 0; i < ARRAY_COUNT(userData->unk_08); i++) {
                    userData->unk_08[i]->flags |= 0x10;
                }
                return ApiStatus_DONE2;
            }
            break;
    }

    switch (userData->unk_04) {
        case 0:
            userData->unk_64++;
            if (userData->unk_64 > 15) {
                userData->unk_04 = 1;
                userData->unk_64 = 0;
            }
            break;
        case 1:
            for (i = 0; i < ARRAY_COUNT(userData->unk_14); i++) {
                userData->unk_14[i] += update_lerp(1, 0.0f, userData->unk_38[i], userData->unk_64, 20);
                userData->unk_20[i] += update_lerp(1, 0.0f, userData->unk_44[i], userData->unk_64, 20);
                userData->unk_2C[i] += update_lerp(1, 0.0f, userData->unk_50[i], userData->unk_64, 20);
            }

            userData->unk_64++;
            if (userData->unk_64 > 20) {
                userData->unk_04 = 2;
                userData->unk_64 = 0;
            }
            break;
    }

    for (i = 0; i < ARRAY_COUNT(userData->unk_08); i++) {
        ((EffectInstanceData*)userData->unk_08[i]->freeDelay)->rotation.x = userData->unk_14[i];
        ((EffectInstanceData*)userData->unk_08[i]->freeDelay)->rotation.y = userData->unk_20[i];
        ((EffectInstanceData*)userData->unk_08[i]->freeDelay)->rotation.z = userData->unk_2C[i];
    }

    return ApiStatus_BLOCK;
}
