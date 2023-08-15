#include "omo_02.h"
#include "model.h"
#include "effects.h"

s32 N(BarricadeModels)[] = {
    MODEL_t2, MODEL_t3, MODEL_t4, MODEL_t5,
    MODEL_t2_2, MODEL_t2_3, MODEL_t2_4, MODEL_t2_5,
    MODEL_t3_1, MODEL_t3_3, MODEL_t3_4, MODEL_t3_5,
};

s32 N(BarricadeColliders)[] = {
    COLLIDER_t2, COLLIDER_t3, COLLIDER_t4, COLLIDER_t5,
    COLLIDER_t2_2, COLLIDER_t2_3, COLLIDER_t2_4, COLLIDER_t2_5,
    COLLIDER_t3_1, COLLIDER_t3_3, COLLIDER_t3_4, COLLIDER_t3_5,
};

typedef struct BarricadePart {
    /* 0x00 */ s32 state;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f origin;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f angularVel;
    /* 0x34 */ f32 verticalVel;
    /* 0x38 */ f32 planarVel;
    /* 0x3C */ f32 velocityAngle;
    /* 0x40 */ s32 modelID;
    /* 0x44 */ s32 colliderID;
    /* 0x48 */ Matrix4f transformMatrix;
    /* 0x88 */ s32 radius;
} BarricadePart; // size = 0x8C

enum {
    BARRICADE_STATE_FLYING      = 0,
    BARRICADE_STATE_CLEANUP     = 100,
    BARRICADE_STATE_DONE        = 101,
};

// iterate through the display list, checking each vertex's distance from (0,0,0) and return the minimum distance
// this creates a spherical collision volume for the flying debris
void N(DetermineSphericalSize)(Gfx* displayList, s32* outDist) {
    char pad[0x8];
    Gfx* dlist = displayList;
    u8 cmd;

    do {
        u32 w0 = dlist->words.w0;
        u32 w1 = dlist->words.w1;

        cmd = w0 >> 0x18;
        if (cmd == G_DL) {
            N(DetermineSphericalSize)((Gfx*) w1, outDist);
        }
        if (cmd == G_VTX) {
            s32 numVertices = (w0 >> 0xC) & 0xFF;
            Vtx* vtx = (Vtx*) w1;
            f32 subX, subY, subZ;
            s32 i;

            subX = subY = subZ = 0.0f;

            *outDist = -1;

            for (i = 0; i < numVertices; i++) {
                f32 dx = vtx[i].v.ob[0] - subX;
                f32 dy = vtx[i].v.ob[1] - subY;
                f32 dz = vtx[i].v.ob[2] - subZ;
                f32 dist = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));

                if (*outDist < dist) {
                    *outDist = dist;
                }
            }
        }
        dlist++;
    } while (cmd != G_ENDDL);
}

API_CALLABLE(N(AnimateBarricadeParts)) {
    Matrix4f mtxTransform, mtxRotX, mtxRotY, mtxRotZ;
    BarricadePart* part;
    Model* model;
    u32 i;
    s32 j, k;

    if (isInitialCall) {
        script->functionTempPtr[0] = heap_malloc(sizeof(*part) * ARRAY_COUNT(N(BarricadeModels)));
        script->functionTemp[1] = 0;

        part = (BarricadePart*) script->functionTempPtr[0];
        for (i = 0; i < ARRAY_COUNT(N(BarricadeModels)); i++, part++) {
            part->modelID = N(BarricadeModels)[i];
            part->colliderID = N(BarricadeColliders)[i];
            model = get_model_from_list_index(get_model_list_index_from_tree_index(part->modelID));
            part->state = BARRICADE_STATE_FLYING;
            part->pos.x = model->center.x;
            part->pos.y = model->center.y;
            part->pos.z = model->center.z;
            part->rot.x = 0.0f;
            part->rot.y = 0.0f;
            part->rot.z = 0.0f;
            part->origin.x = part->pos.x;
            part->origin.y = part->pos.y;
            part->origin.z = part->pos.z;
            part->angularVel.x = rand_int(20) - 10;
            part->angularVel.y = rand_int(20) - 10;
            part->angularVel.z = rand_int(20) - 10;
            part->verticalVel = (rand_int(40) + 100.0f) / 10.0f;
            part->planarVel = (rand_int(30) + 60.0f) / 10.0f;
            part->velocityAngle = ((rand_int(100) % 2) * 180.0f) + 90.0f;
            N(DetermineSphericalSize)(model->modelNode->displayData->displayList, &part->radius);

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    part->transformMatrix[j][k] = model->userTransformMtx[j][k];
                }
            }
        }
    }

    part = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(BarricadeModels)); i++, part++) {
        model = get_model_from_list_index(get_model_list_index_from_tree_index(part->modelID));
        switch (part->state) {
            case BARRICADE_STATE_FLYING:
                    add_vec2D_polar(&part->pos.x, &part->pos.z, part->planarVel, part->velocityAngle);
                    part->verticalVel -= 0.8f;
                    part->pos.y += part->verticalVel;
                    if (part->verticalVel <= 0.0f && part->pos.y < part->radius) {
                        part->pos.y = part->radius;
                        part->verticalVel *= -0.7f;
                        if (part->verticalVel < 1.0f) {
                            part->state = BARRICADE_STATE_CLEANUP;
                            part->angularVel.x = 0.0f;
                            part->angularVel.y = 0.0f;
                            part->angularVel.z = 0.0f;
                        }
                        if (i & 1) {
                            exec_ShakeCam1(0, 0, 1);
                        }
                    }
                break;
            case BARRICADE_STATE_CLEANUP:
                update_collider_transform(part->colliderID);
                script->functionTemp[1]++;
                part->state = BARRICADE_STATE_DONE;
                break;
            case BARRICADE_STATE_DONE:
                break;
        }

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                model->userTransformMtx[j][k] = part->transformMatrix[j][k];
            }
        }

        model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
        guTranslateF(mtxTransform, part->pos.x - part->origin.x, part->pos.y - part->origin.y, part->pos.z - part->origin.z);
        part->rot.x += part->angularVel.x;
        part->rot.y += part->angularVel.y;
        part->rot.z += part->angularVel.z;
        part->rot.x = clamp_angle(part->rot.x);
        part->rot.y = clamp_angle(part->rot.y);
        part->rot.z = clamp_angle(part->rot.z);
        guRotateF(mtxRotX, part->rot.x, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, part->rot.y, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxRotZ, part->rot.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxRotZ, mtxRotX, mtxRotX);
        guMtxCatF(mtxRotX, mtxRotY, mtxRotY);
        guMtxCatF(mtxRotY, mtxTransform, mtxTransform);
        guMtxCatF(model->userTransformMtx, mtxTransform, model->userTransformMtx);
    }

    if ((u32) script->functionTemp[1] >= ARRAY_COUNT(N(BarricadeModels))) {
        heap_free(script->functionTempPtr[0]);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

BombTrigger N(BombPos_Barricade) = {
    .pos = { -520.0f, 0.0f, 0.0f },
    .radius = 0.0f
};

EvtScript N(EVS_Scene_BreakBarricade) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(EnableGroup, MODEL_hibi, FALSE)
    EVT_THREAD
        EVT_CALL(N(AnimateBarricadeParts))
        EVT_LOOP(10)
            EVT_USE_BUF(EVT_PTR(N(BarricadeModels)))
            EVT_LOOP(ARRAY_COUNT(N(BarricadeModels)))
                EVT_BUF_READ1(LVar0)
                EVT_CALL(EnableModel, LVar0, TRUE)
            EVT_END_LOOP
            EVT_WAIT(2)
            EVT_USE_BUF(EVT_PTR(N(BarricadeModels)))
            EVT_LOOP(ARRAY_COUNT(N(BarricadeModels)))
                EVT_BUF_READ1(LVar0)
                EVT_CALL(EnableModel, LVar0, FALSE)
            EVT_END_LOOP
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_USE_BUF(EVT_PTR(N(BarricadeColliders)))
        EVT_LOOP(ARRAY_COUNT(N(BarricadeColliders)))
            EVT_BUF_READ1(LVar0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar0, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_KILL_THREAD(MV_RestrictCamScript)
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
            EVT_CALL(RotateModel, MODEL_t1, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t1, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t1, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtModel, MODEL_t1, SOUND_OMO_BARRICADE_DROP, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetModelCenter, MODEL_t1)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t2_1, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t2_1, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_t2_1, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
            EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtModel, MODEL_t2_1, SOUND_OMO_BARRICADE_DROP, SOUND_SPACE_DEFAULT)
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
        EVT_CALL(RotateModel, MODEL_t3_2, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t3_2, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t3_2, LVar0, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtModel, MODEL_t3_2, SOUND_OMO_BARRICADE_DROP, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetModelCenter, MODEL_t3_2)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(PlaySound, SOUND_LOOP_SHY_GUY_CROWD_2)
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
            EVT_CALL(SetNpcVar, LVar0, 0, CROWD_STATE_TURN_AROUND)
            EVT_WAIT(LVar5)
            EVT_CALL(SetNpcVar, LVar0, 0, CROWD_STATE_RUN_AWAY)
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
    EVT_CALL(PlaySound, SOUND_LRAW_SHY_GUY_CROWD_2 | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_SHY_GUY_CROWD_2)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, -285, 0, 35)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy_01, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -135, 23, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -110, -13, 0)
    EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_01, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcRotationPivot, NPC_ShyGuy_01, 10)
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
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_ACTOR_TRIP, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(50)
    EVT_LOOP(2)
        EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_ACTOR_TWITCH, SOUND_SPACE_DEFAULT)
        EVT_WAIT(7)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotationPivot, NPC_ShyGuy_01, 0)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, -50, 0, -8, 10)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 270, 0)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_SHY_GUY_FLEE_LOOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy_01, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 100, 50, 0)
    EVT_CALL(RemoveNpc, NPC_ShyGuy_01)
    EVT_WAIT(30)
    EVT_CALL(StopSound, SOUND_SHY_GUY_FLEE_LOOP)
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

EvtScript N(EVS_SetupBarricade) = {
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
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_BreakBarricade)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Barricade)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_hibi, FALSE)
        EVT_USE_BUF(EVT_PTR(N(BarricadeModels)))
        EVT_LOOP(ARRAY_COUNT(N(BarricadeModels)))
            EVT_BUF_READ1(LVar0)
            EVT_CALL(EnableModel, LVar0, FALSE)
        EVT_END_LOOP
        EVT_USE_BUF(EVT_PTR(N(BarricadeColliders)))
        EVT_LOOP(ARRAY_COUNT(N(BarricadeColliders)))
            EVT_BUF_READ1(LVar0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar0, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_LOOP
        EVT_CALL(RotateModel, MODEL_t1, -90, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
        EVT_CALL(RotateModel, MODEL_t2_1, -90, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
        EVT_CALL(RotateModel, MODEL_t3_2, -90, EVT_FLOAT(0.518), 0, EVT_FLOAT(1.931))
        EVT_CALL(UpdateColliderTransform, COLLIDER_t1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_t2_1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_t3_2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
