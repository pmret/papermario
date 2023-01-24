#include "omo_02.h"
#include "model.h"
#include "effects.h"

void N(func_802402C0_D9D790)(Gfx* displayList, s32* outDist) {
    char pad[0x8];
    Gfx* dlist = displayList;
    u8 cmd;

    do {
        u32 temp_s2 = dlist->words.w0;
        u32 temp_s3 = dlist->words.w1;

        cmd = temp_s2 >> 0x18;
        if (cmd == G_DL) {
            N(func_802402C0_D9D790)((Gfx*) temp_s3, outDist);
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

s32 N(D_80243580_DA0A50)[] = {
    84, 86, 88, 90,
    95, 97, 99, 101, 
    104, 108, 110, 112, 
};

s32 N(D_802435B0_DA0A80)[] = {
    44, 46, 48, 50,
    55, 57, 59, 61, 
    64, 68, 70, 72, 
};

typedef struct OmoUnkThing {
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
} OmoUnkThing; // size = 0x8C

API_CALLABLE(N(func_8024043C_D9D90C)) {
    Matrix4f sp18, sp58, sp98, spD8;
    Model* model;
    OmoUnkThing* data;
    OmoUnkThing* it;
    u32 i;
    s32 j, k;

    if (isInitialCall) {
        script->functionTempPtr[0] = heap_malloc(sizeof(*data) * 12);
        script->functionTemp[1] = 0;

        it = (OmoUnkThing*) script->functionTempPtr[0];
        for (i = 0; i < ARRAY_COUNT(N(D_80243580_DA0A50)); i++, it++) {
            it->treeIndex = N(D_80243580_DA0A50)[i];
            it->colliderID = N(D_802435B0_DA0A80)[i];
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
            N(func_802402C0_D9D790)(model->modelNode->displayData->displayList, &it->unk_88);

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = model->transformMatrix[j][k];
                }
            }
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(D_80243580_DA0A50)); i++, it++) {
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

    if ((u32) script->functionTemp[1] >= ARRAY_COUNT(N(D_80243580_DA0A50))) {
        heap_free(script->functionTempPtr[0]);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

BombTrigger N(D_802435E0_DA0AB0) = {
    .pos = { -520.0f, 0.0f, 0.0f },
    .radius = 0.0f
};

EvtScript N(D_802435F0_DA0AC0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(EnableGroup, MODEL_hibi, FALSE)
    EVT_THREAD
        EVT_CALL(N(func_8024043C_D9D90C))
        EVT_LOOP(10)
            EVT_USE_BUF(EVT_PTR(N(D_80243580_DA0A50)))
            EVT_LOOP(12)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(EnableModel, LVar0, TRUE)
            EVT_END_LOOP
            EVT_WAIT(2)
            EVT_USE_BUF(EVT_PTR(N(D_80243580_DA0A50)))
            EVT_LOOP(12)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(EnableModel, LVar0, FALSE)
            EVT_END_LOOP
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_USE_BUF(EVT_PTR(N(D_802435B0_DA0A80)))
        EVT_LOOP(12)
            EVT_BUF_READ1(LVar0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar0, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_KILL_THREAD(MV_Unk_0A)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -380, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -380, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t1, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t1, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t1, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtModel, MODEL_t1, SOUND_1F4, 0)
        EVT_CALL(GetModelCenter, MODEL_t1)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t2_1, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t2_1, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t2_1, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtModel, MODEL_t2_1, SOUND_1F4, 0)
        EVT_CALL(GetModelCenter, MODEL_t2_1)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_SET(LVar0, 1)
    EVT_LOOP(10)
        EVT_THREAD
            EVT_WAIT(10)
            EVT_CALL(SetNpcJumpscale, LVar0, EVT_FLOAT(1.5))
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_IF_EQ(LVar2, 0)
                EVT_CALL(NpcJump0, LVar0, LVar1, 0, LVar3, 20)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t3_2, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t3_2, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t3_2, LVar0, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtModel, MODEL_t3_2, SOUND_1F4, 0)
    EVT_CALL(GetModelCenter, MODEL_t3_2)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(PlaySound, SOUND_8000004D)
    EVT_END_THREAD
    EVT_SET(LVar0, 1)
    EVT_SET(LVar5, 1)
    EVT_LOOP(10)
        EVT_THREAD
            EVT_CALL(SetNpcJumpscale, LVar0, EVT_FLOAT(1.5))
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(RandInt, 10, LVar4)
            EVT_ADD(LVar4, 10)
            EVT_IF_EQ(LVar2, 0)
                EVT_CALL(NpcJump0, LVar0, LVar1, 0, LVar3, LVar4)
            EVT_END_IF
            EVT_CALL(SetNpcVar, LVar0, 0, 11)
            EVT_WAIT(LVar5)
            EVT_CALL(SetNpcVar, LVar0, 0, 20)
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar5, 12)
    EVT_END_LOOP
    EVT_WAIT(60)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -125, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -125, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(165)
    EVT_CALL(PlaySound, SOUND_76D)
    EVT_CALL(func_802D62E4, 877)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, -285, 0, 35)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy_01, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -135, 23, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -110, -13, 0)
    EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_01, EVT_FLOAT(1.0))
    EVT_CALL(func_802CDE68, 0, 10)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -9)
            EVT_CALL(SetNpcRotation, NPC_ShyGuy_01, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcRotation, NPC_ShyGuy_01, 0, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim10)
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, -45, 0, -8, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_MISS_JUMP, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(50)
    EVT_LOOP(2)
        EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_3E4, 0)
        EVT_WAIT(7)
    EVT_END_LOOP
    EVT_CALL(func_802CDE68, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, -50, 0, -8, 10)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 270, 0)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_3A2, 0)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy_01, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 100, 50, 0)
    EVT_CALL(RemoveNpc, NPC_ShyGuy_01)
    EVT_WAIT(30)
    EVT_CALL(StopSound, SOUND_3A2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GF_OMO02_BombedWall, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024455C) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_t1, MODEL_t1)
    EVT_CALL(ParentColliderToModel, COLLIDER_t2, MODEL_t2)
    EVT_CALL(ParentColliderToModel, COLLIDER_t3, MODEL_t3)
    EVT_CALL(ParentColliderToModel, COLLIDER_t4, MODEL_t4)
    EVT_CALL(ParentColliderToModel, COLLIDER_t5, MODEL_t5)
    EVT_CALL(ParentColliderToModel, COLLIDER_t2_1, MODEL_t2_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_t2_2, MODEL_t2_2)
    EVT_CALL(ParentColliderToModel, COLLIDER_t2_3, MODEL_t2_3)
    EVT_CALL(ParentColliderToModel, COLLIDER_t2_4, MODEL_t2_4)
    EVT_CALL(ParentColliderToModel, COLLIDER_t2_5, MODEL_t2_5)
    EVT_CALL(ParentColliderToModel, COLLIDER_t3_1, MODEL_t3_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_t3_2, MODEL_t3_2)
    EVT_CALL(ParentColliderToModel, COLLIDER_t3_3, MODEL_t3_3)
    EVT_CALL(ParentColliderToModel, COLLIDER_t3_4, MODEL_t3_4)
    EVT_CALL(ParentColliderToModel, COLLIDER_t3_5, MODEL_t3_5)
    EVT_IF_EQ(GF_OMO02_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(D_802435F0_DA0AC0)), TRIGGER_POINT_BOMB, EVT_PTR(N(D_802435E0_DA0AB0)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_hibi, FALSE)
        EVT_USE_BUF(EVT_PTR(N(D_80243580_DA0A50)))
        EVT_LOOP(12)
            EVT_BUF_READ1(LVar0)
            EVT_CALL(EnableModel, LVar0, FALSE)
        EVT_END_LOOP
        EVT_USE_BUF(EVT_PTR(N(D_802435B0_DA0A80)))
        EVT_LOOP(12)
            EVT_BUF_READ1(LVar0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar0, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_LOOP
        EVT_CALL(RotateModel, MODEL_t1, -90, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
        EVT_CALL(RotateModel, MODEL_t2_1, -90, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
        EVT_CALL(RotateModel, MODEL_t3_2, -90, EVT_FLOAT(0.5185547), 0, EVT_FLOAT(1.9316406))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
