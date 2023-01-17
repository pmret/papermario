#include "omo_02.h"
#include "model.h"

extern s32 D_802434F8_DA09C8[2]; // TODO: remove hard-coded size once the data is migrated
extern s32 D_80243580_DA0A50[12]; // TODO: remove hard-coded size once the data is migrated
extern s32 D_802435B0_DA0A80[];

ApiStatus func_80240040_D9D510(Evt* script, s32 isInitialCall) {
    Matrix4f sp18, sp58;
    UnkOmo* it;
    Model* model;
    f32 temp_f20;
    f32 temp_f24;
    u32 i;

    if (isInitialCall) {
        it = heap_malloc(sizeof(*it) * 2);
        script->functionTempPtr[0] = it;

        for (i = 0; i < ARRAY_COUNT(D_802434F8_DA09C8); i++, it++) {
            s32 treeIndex = D_802434F8_DA09C8[i];

            it->treeIndex = treeIndex;
            model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
            it->unk_00 = model->center.x;
            it->unk_04 = model->center.z;
            it->unk_0C = 3.5f;
            it->unk_10 = 0;
            it->unk_08 = 0;
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(D_802434F8_DA09C8); i++, it++) {
        it->unk_10 += it->unk_0C;
        it->unk_10 = clamp_angle(it->unk_10);
        temp_f20 = sin_rad((it->unk_10 * 3.14f) / 180.0f) * 20.0f;
        temp_f24 = SQ(temp_f20) / 90.0f;
        if (i == 0) {
            if ((it->unk_08 >= 0.0f && temp_f20 < 0.0f) || (it->unk_08 < 0.0f && temp_f20 >= 0.0f)) {
                sfx_play_sound_at_position(SOUND_CREAKY_ROCKING_CHAIR, 0, -706.0f, 0.0f, 102.0f);
            }
            it->unk_08 = temp_f20;
        }
        model = get_model_from_list_index(get_model_list_index_from_tree_index(it->treeIndex));
        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(sp18, -it->unk_00, 0.0f, -it->unk_04);
        guRotateF(sp58, temp_f20, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp18, sp58, model->transformMatrix);
        guTranslateF(sp18, it->unk_00, temp_f24, it->unk_04);
        guMtxCatF(model->transformMatrix, sp18, model->transformMatrix);
    }
    return ApiStatus_BLOCK;
}

void func_802402C0_D9D790(Gfx* displayList, s32* outDist) {
    char pad[0x8];
    Gfx* dlist = displayList;
    u8 cmd;

    do {
        u32 temp_s2 = dlist->words.w0;
        u32 temp_s3 = dlist->words.w1;

        cmd = temp_s2 >> 0x18;
        if (cmd == G_DL) {
            func_802402C0_D9D790((Gfx*) temp_s3, outDist);
        }
        if (cmd == G_VTX) {
            s32 numVertices = (temp_s2 >> 0xC) & 0xFF;
            Vtx* vtx = (Vtx*) temp_s3;
            f32 subX, subY, subZ;
            s32 i;

            subX = subY = subZ = 0.0f;

            *outDist = -1;

            for (i = 0; i < numVertices; i++) {
                f32 x = vtx[i].v.ob[0] - subX;
                f32 y = vtx[i].v.ob[1] - subY;
                f32 z = vtx[i].v.ob[2] - subZ;
                f32 dist = sqrtf(SQ(x) + SQ(y) + SQ(z));

                if (*outDist < dist) {
                    *outDist = dist;
                }
            }
        }
        dlist++;
    } while (cmd != G_ENDDL);
}

typedef struct UnkOmoThing {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f center;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f unk_28;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 treeIndex;
    /* 0x44 */ s32 colliderID;
    /* 0x48 */ Matrix4f transformMatrix;
    /* 0x88 */ s32 unk_88;
} UnkOmoThing; // size = 0x8C

ApiStatus func_8024043C_D9D90C(Evt* script, s32 isInitialCall) {
    Matrix4f sp18, sp58, sp98, spD8;
    Model* model;
    UnkOmoThing* data;
    UnkOmoThing* it;
    u32 i;
    s32 j, k;

    if (isInitialCall) {
        script->functionTempPtr[0] = heap_malloc(sizeof(*data) * 12);
        script->functionTemp[1] = 0;

        it = (UnkOmoThing*) script->functionTempPtr[0];
        for (i = 0; i < ARRAY_COUNT(D_80243580_DA0A50); i++, it++) {
            it->treeIndex = D_80243580_DA0A50[i];
            it->colliderID = D_802435B0_DA0A80[i];
            model = get_model_from_list_index(get_model_list_index_from_tree_index(it->treeIndex));
            it->unk_00 = 0;
            it->center.x = model->center.x;
            it->center.y = model->center.y;
            it->center.z = model->center.z;
            it->rot.x = 0.0f;
            it->rot.y = 0.0f;
            it->rot.z = 0.0f;
            it->unk_10.x = it->center.x;
            it->unk_10.y = it->center.y;
            it->unk_10.z = it->center.z;
            it->unk_28.x = rand_int(20) - 10;
            it->unk_28.y = rand_int(20) - 10;
            it->unk_28.z = rand_int(20) - 10;
            it->unk_34 = (rand_int(40) + 100.0f) / 10.0f;
            it->unk_38 = (rand_int(30) + 60.0f) / 10.0f;
            it->unk_3C = ((rand_int(100) % 2) * 180.0f) + 90.0f;
            func_802402C0_D9D790(model->modelNode->displayData->displayList, &it->unk_88);

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = model->transformMatrix[j][k];
                }
            }
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(D_80243580_DA0A50); i++, it++) {
        model = get_model_from_list_index(get_model_list_index_from_tree_index(it->treeIndex));
        if (it->unk_00 != 100) {
            if (it->unk_00 < 101) {
                if (it->unk_00 == 0) {
                    add_vec2D_polar(&it->center.x, &it->center.z, it->unk_38, it->unk_3C);
                    it->unk_34 -= 0.8f;
                    it->center.y += it->unk_34;
                    if (it->unk_34 <= 0.0f && it->center.y < it->unk_88) {
                        it->center.y = it->unk_88;
                        it->unk_34 *= -0.7f;
                        if (it->unk_34 < 1.0f) {
                            it->unk_00 = 100;
                            it->unk_28.x = 0.0f;
                            it->unk_28.y = 0.0f;
                            it->unk_28.z = 0.0f;
                        }
                        if (i & 1) {
                            exec_ShakeCam1(0, 0, 1);
                        }
                    }
                }
            }
        } else {
            update_collider_transform(it->colliderID);
            script->functionTemp[1]++;
            it->unk_00 = 101;
        }

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                model->transformMatrix[j][k] = it->transformMatrix[j][k];
            }
        }

        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(sp18, it->center.x - it->unk_10.x, it->center.y - it->unk_10.y, it->center.z - it->unk_10.z);
        it->rot.x += it->unk_28.x;
        it->rot.y += it->unk_28.y;
        it->rot.z += it->unk_28.z;
        it->rot.x = clamp_angle(it->rot.x);
        it->rot.y = clamp_angle(it->rot.y);
        it->rot.z = clamp_angle(it->rot.z);
        guRotateF(sp58, it->rot.x, 1.0f, 0.0f, 0.0f);
        guRotateF(sp98, it->rot.y, 0.0f, 1.0f, 0.0f);
        guRotateF(spD8, it->rot.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(spD8, sp58, sp58);
        guMtxCatF(sp58, sp98, sp98);
        guMtxCatF(sp98, sp18, sp18);
        guMtxCatF(model->transformMatrix, sp18, model->transformMatrix);
    }

    if ((u32) script->functionTemp[1] >= ARRAY_COUNT(D_80243580_DA0A50)) {
        heap_free(script->functionTempPtr[0]);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/ai/StationaryAI.inc.c"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

#include "world/common/todo/SetInstigatorValue_3.inc.c"

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"
