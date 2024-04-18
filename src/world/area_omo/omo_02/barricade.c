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
    .diameter = 0.0f
};

EvtScript N(EVS_Scene_BreakBarricade) = {
    Call(DisablePlayerInput, TRUE)
    Call(EnableGroup, MODEL_hibi, FALSE)
    Thread
        Call(N(AnimateBarricadeParts))
        Loop(10)
            UseBuf(Ref(N(BarricadeModels)))
            Loop(ARRAY_COUNT(N(BarricadeModels)))
                BufRead1(LVar0)
                Call(EnableModel, LVar0, TRUE)
            EndLoop
            Wait(2)
            UseBuf(Ref(N(BarricadeModels)))
            Loop(ARRAY_COUNT(N(BarricadeModels)))
                BufRead1(LVar0)
                Call(EnableModel, LVar0, FALSE)
            EndLoop
            Wait(2)
        EndLoop
        UseBuf(Ref(N(BarricadeColliders)))
        Loop(ARRAY_COUNT(N(BarricadeColliders)))
            BufRead1(LVar0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar0, COLLIDER_FLAGS_UPPER_MASK)
        EndLoop
    EndThread
    Thread
        Wait(30)
        KillThread(MV_RestrictCamScript)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Wait(1)
        Call(UseSettingsFrom, CAM_DEFAULT, -380, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, -380, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Thread
        Call(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_t1, LVar0, Float(0.518), 0, Float(1.931))
            Call(UpdateColliderTransform, COLLIDER_t1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_t1, LVar0, Float(0.518), 0, Float(1.931))
            Call(UpdateColliderTransform, COLLIDER_t1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_t1, LVar0, Float(0.518), 0, Float(1.931))
            Call(UpdateColliderTransform, COLLIDER_t1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtModel, MODEL_t1, SOUND_OMO_BARRICADE_DROP, SOUND_SPACE_DEFAULT)
        Call(GetModelCenter, MODEL_t1)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    EndThread
    Thread
        Wait(5)
        Call(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_t2_1, LVar0, Float(0.518), 0, Float(1.931))
            Call(UpdateColliderTransform, COLLIDER_t2_1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_t2_1, LVar0, Float(0.518), 0, Float(1.931))
            Call(UpdateColliderTransform, COLLIDER_t2_1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_t2_1, LVar0, Float(0.518), 0, Float(1.931))
            Call(UpdateColliderTransform, COLLIDER_t2_1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtModel, MODEL_t2_1, SOUND_OMO_BARRICADE_DROP, SOUND_SPACE_DEFAULT)
        Call(GetModelCenter, MODEL_t2_1)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    EndThread
    Set(LVar0, 1)
    Loop(10)
        Thread
            Wait(10)
            Call(SetNpcJumpscale, LVar0, Float(1.5))
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            IfEq(LVar2, 0)
                Call(NpcJump0, LVar0, LVar1, 0, LVar3, 20)
            EndIf
        EndThread
        Add(LVar0, 1)
    EndLoop
    Call(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_t3_2, LVar0, Float(0.518), 0, Float(1.931))
        Call(UpdateColliderTransform, COLLIDER_t3_2)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, -10, 7, 40, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_t3_2, LVar0, Float(0.518), 0, Float(1.931))
        Call(UpdateColliderTransform, COLLIDER_t3_2)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 7, -90, 30, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_t3_2, LVar0, Float(0.518), 0, Float(1.931))
        Call(UpdateColliderTransform, COLLIDER_t3_2)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtModel, MODEL_t3_2, SOUND_OMO_BARRICADE_DROP, SOUND_SPACE_DEFAULT)
    Call(GetModelCenter, MODEL_t3_2)
    PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Thread
        Wait(35)
        Call(PlaySound, SOUND_LOOP_SHY_GUY_CROWD_2)
    EndThread
    Set(LVar0, 1)
    Set(LVar5, 1)
    Loop(10)
        Thread
            Call(SetNpcJumpscale, LVar0, Float(1.5))
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Call(RandInt, 10, LVar4)
            Add(LVar4, 10)
            IfEq(LVar2, 0)
                Call(NpcJump0, LVar0, LVar1, 0, LVar3, LVar4)
            EndIf
            Call(SetNpcVar, LVar0, 0, CROWD_STATE_TURN_AROUND)
            Wait(LVar5)
            Call(SetNpcVar, LVar0, 0, CROWD_STATE_RUN_AWAY)
        EndThread
        Add(LVar0, 1)
        Add(LVar5, 12)
    EndLoop
    Wait(60)
    Call(UseSettingsFrom, CAM_DEFAULT, -125, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -125, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(165)
    Call(PlaySound, SOUND_LRAW_SHY_GUY_CROWD_2 | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(StopTrackingSoundPos, SOUND_LRAW_SHY_GUY_CROWD_2)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    Call(SetNpcPos, NPC_ShyGuy_01, -285, 0, 35)
    Call(SetNpcSpeed, NPC_ShyGuy_01, Float(8.0))
    Call(NpcMoveTo, NPC_ShyGuy_01, -135, 23, 0)
    Call(NpcMoveTo, NPC_ShyGuy_01, -110, -13, 0)
    Call(SetNpcJumpscale, NPC_ShyGuy_01, Float(1.0))
    Call(SetNpcRotationPivot, NPC_ShyGuy_01, 10)
    Thread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, -9)
            Call(SetNpcRotation, NPC_ShyGuy_01, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(10)
        Call(SetNpcRotation, NPC_ShyGuy_01, 0, 0, 0)
        Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim10)
    EndThread
    Call(NpcJump0, NPC_ShyGuy_01, -45, 0, -8, 10)
    Call(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_ACTOR_TRIP, SOUND_SPACE_DEFAULT)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(50)
    Loop(2)
        Call(PlaySoundAtNpc, LVar9, SOUND_ACTOR_TWITCH, SOUND_SPACE_DEFAULT)
        Wait(7)
    EndLoop
    Call(SetNpcRotationPivot, NPC_ShyGuy_01, 0)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim01)
    Call(NpcJump0, NPC_ShyGuy_01, -50, 0, -8, 10)
    Call(InterpNpcYaw, NPC_ShyGuy_01, 270, 0)
    Wait(20)
    Call(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_SHY_GUY_FLEE_LOOP, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    Call(SetNpcSpeed, NPC_ShyGuy_01, Float(6.0))
    Call(NpcMoveTo, NPC_ShyGuy_01, 100, 50, 0)
    Call(RemoveNpc, NPC_ShyGuy_01)
    Wait(30)
    Call(StopSound, SOUND_SHY_GUY_FLEE_LOOP)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Set(GF_OMO02_BombedWall, TRUE)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupBarricade) = {
    Call(ParentColliderToModel, COLLIDER_t1, MODEL_t1)
    Call(ParentColliderToModel, COLLIDER_t2, MODEL_t2)
    Call(ParentColliderToModel, COLLIDER_t3, MODEL_t3)
    Call(ParentColliderToModel, COLLIDER_t4, MODEL_t4)
    Call(ParentColliderToModel, COLLIDER_t5, MODEL_t5)
    Call(ParentColliderToModel, COLLIDER_t2_1, MODEL_t2_1)
    Call(ParentColliderToModel, COLLIDER_t2_2, MODEL_t2_2)
    Call(ParentColliderToModel, COLLIDER_t2_3, MODEL_t2_3)
    Call(ParentColliderToModel, COLLIDER_t2_4, MODEL_t2_4)
    Call(ParentColliderToModel, COLLIDER_t2_5, MODEL_t2_5)
    Call(ParentColliderToModel, COLLIDER_t3_1, MODEL_t3_1)
    Call(ParentColliderToModel, COLLIDER_t3_2, MODEL_t3_2)
    Call(ParentColliderToModel, COLLIDER_t3_3, MODEL_t3_3)
    Call(ParentColliderToModel, COLLIDER_t3_4, MODEL_t3_4)
    Call(ParentColliderToModel, COLLIDER_t3_5, MODEL_t3_5)
    IfEq(GF_OMO02_BombedWall, FALSE)
        BindTrigger(Ref(N(EVS_Scene_BreakBarricade)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Barricade)), 1, 0)
    Else
        Call(EnableGroup, MODEL_hibi, FALSE)
        UseBuf(Ref(N(BarricadeModels)))
        Loop(ARRAY_COUNT(N(BarricadeModels)))
            BufRead1(LVar0)
            Call(EnableModel, LVar0, FALSE)
        EndLoop
        UseBuf(Ref(N(BarricadeColliders)))
        Loop(ARRAY_COUNT(N(BarricadeColliders)))
            BufRead1(LVar0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar0, COLLIDER_FLAGS_UPPER_MASK)
        EndLoop
        Call(RotateModel, MODEL_t1, -90, Float(0.518), 0, Float(1.931))
        Call(RotateModel, MODEL_t2_1, -90, Float(0.518), 0, Float(1.931))
        Call(RotateModel, MODEL_t3_2, -90, Float(0.518), 0, Float(1.931))
        Call(UpdateColliderTransform, COLLIDER_t1)
        Call(UpdateColliderTransform, COLLIDER_t2_1)
        Call(UpdateColliderTransform, COLLIDER_t3_2)
    EndIf
    Return
    End
};
