#include "sam_07.h"
#include "model.h"

s32 N(IceShardModels)[] = {
    MODEL_o59,  MODEL_o61,  MODEL_o89,  MODEL_o105, MODEL_o56,
    MODEL_o58,  MODEL_o63,  MODEL_o86,  MODEL_o52,  MODEL_o46,
    MODEL_o54,  MODEL_o67,  MODEL_o66,  MODEL_o64,  MODEL_o98,
    MODEL_o93,  MODEL_o100, MODEL_o82,  MODEL_o77,  MODEL_o84,
    MODEL_o75,  MODEL_o51,  MODEL_o44,  MODEL_o47,  MODEL_o55,
    MODEL_o70,  MODEL_o68,  MODEL_o65,  MODEL_o94,  MODEL_o91,
    MODEL_o81,  MODEL_o78,  MODEL_o48,  MODEL_o50,  MODEL_o73,
    MODEL_o80,  MODEL_o106, MODEL_o107, MODEL_o116, MODEL_o109,
    MODEL_o118, MODEL_o117, MODEL_o111, MODEL_o119, MODEL_o120,
    MODEL_o112, MODEL_o122, MODEL_o121, MODEL_o113, MODEL_o123,
    MODEL_o124, MODEL_o114, MODEL_o126, MODEL_o125, MODEL_o115,
};

typedef struct IceShard {
    /* 0x00 */ s32 state;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f initialPos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f rotVel;
    /* 0x34 */ f32 velY;
    /* 0x38 */ f32 moveSpeed;
    /* 0x3C */ f32 moveAngle;
    /* 0x40 */ Matrix4f transformMatrix;
} IceShard; // size = 0x80

API_CALLABLE(N(AnimateIceShattering)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f mtxTransform, mtxRotX, mtxRotY, mtxRotZ;
    IceShard* it;
    Model* model;
    u32 i;
    s32 j, k;

    if (isInitialCall) {

        script->functionTempPtr[0] = heap_malloc(sizeof(*it) * ARRAY_COUNT(N(IceShardModels)));
        script->functionTemp[1] = 0;

        it = script->functionTempPtr[0];
        for (i = 0; i < ARRAY_COUNT(N(IceShardModels)); i++, it++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(N(IceShardModels)[i]));
            it->state = 0;
            it->pos.x = model->center.x;
            it->pos.y = model->center.y;
            it->pos.z = model->center.z;
            it->rot.x = 0.0f;

            it->rot.y = 0.0f;
            it->rot.z = 0.0f;
            it->initialPos.x = it->pos.x;
            it->initialPos.y = it->pos.y;
            it->initialPos.z = it->pos.z;
            it->rotVel.x = rand_int(20) - 10;
            it->rotVel.y = rand_int(20) - 10;
            it->rotVel.z = rand_int(20) - 10;
            it->velY = rand_int(5) + 5.0f;
            it->moveSpeed = rand_int(3) + 1.0f;
            it->moveAngle = rand_int(360);

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    it->transformMatrix[j][k] = model->userTransformMtx[j][k];
                }
            }
        }
    }

    it = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(IceShardModels)); i++, it++) {
        model = get_model_from_list_index(get_model_list_index_from_tree_index(N(IceShardModels)[i]));
        if (it->state == 0) {
            add_vec2D_polar(&it->pos.x, &it->pos.z, it->moveSpeed, it->moveAngle);
            it->velY -= 1.0f;
            it->pos.y += it->velY;
            if (it->velY < 0.0f) {
                if (it->pos.y < playerStatus->pos.y - 150.0f) {
                    // this shard is done, stop moving and increment the 'done' counter
                    script->functionTemp[1]++;
                    it->state = 101;
                }
            }
        }

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                model->userTransformMtx[j][k] = it->transformMatrix[j][k];
            }
        }

        model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
        guTranslateF(mtxTransform, it->pos.x - it->initialPos.x, it->pos.y - it->initialPos.y, it->pos.z - it->initialPos.z);
        it->rot.x += it->rotVel.x;
        it->rot.y += it->rotVel.y;
        it->rot.z += it->rotVel.z;
        it->rot.x = clamp_angle(it->rot.x);
        it->rot.y = clamp_angle(it->rot.y);
        it->rot.z = clamp_angle(it->rot.z);
        guRotateF(mtxRotX, it->rot.x, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, it->rot.y, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxRotZ, it->rot.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxRotZ, mtxRotX, mtxRotX);
        guMtxCatF(mtxRotX, mtxRotY, mtxRotY);
        guMtxCatF(mtxRotY, mtxTransform, mtxTransform);
        guMtxCatF(mtxTransform, model->userTransformMtx, model->userTransformMtx);
    }

    if ((u32) script->functionTemp[1] >= ARRAY_COUNT(N(IceShardModels))) {
        // all shards are in 'done' state, free them all and return
        heap_free(script->functionTempPtr[0]);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#include "world/common/todo/SetEntityPositionF.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

API_CALLABLE(N(AwaitPlayerNotPoundingFloor)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 floor1 = evt_get_variable(script, *args++);
    s32 floor2 = evt_get_variable(script, *args++);

    if (gCollisionStatus.curFloor == floor1 || gCollisionStatus.curFloor == floor2) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_POUND ||
            playerStatus->actionState == ACTION_STATE_TORNADO_POUND)
        {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/EnableCameraFollowPlayerY.inc.c"

EvtScript N(EVS_BreakIce) = {
    Call(PlaySoundAtCollider, COLLIDER_o116, SOUND_ICE_SHATTER, 0)
    Call(N(AnimateIceShattering))
    Loop(10)
        Call(SetGroupVisibility, MODEL_move1, MODEL_GROUP_VISIBLE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
        Call(EnableModel, MODEL_m1_yuka, TRUE)
        Call(EnableModel, MODEL_m1_kabe, TRUE)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TouchFloor_FragileIce) = {
    Call(GetPlayerActionState, LVar0)
    IfNe(LVar0, ACTION_STATE_SPIN_POUND)
        IfNe(LVar0, ACTION_STATE_TORNADO_POUND)
            Return
        EndIf
    EndIf
    IfEq(GF_SAM07_IceBroken, TRUE)
        Return
    EndIf
    Set(GF_SAM07_IceBroken, TRUE)
    Wait(5)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o116, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_BreakIce))
    Unbind
    Return
    End
};

EvtScript N(EVS_Blast_FragileIce) = {
    IfEq(GF_SAM07_IceBroken, TRUE)
        Return
    EndIf
    Set(GF_SAM07_IceBroken, TRUE)
    Wait(5)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o116, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_BreakIce))
    Unbind
    Return
    End
};

EvtScript N(EVS_UseGreenSwitch) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(GetEntityPosition), MV_SwitchEntityID, LVar7, LVar8, LVar9)
    IfEq(GF_SAM07_FloorRaised, FALSE)
        Call(PlaySoundAtCollider, COLLIDER_m1_yuka, SOUND_SAM07_RAISE_FLOOR, 0)
        Sub(LVar8, -180)
        Call(MakeLerp, -180, 0, 120, EASING_COS_IN_OUT)
        Label(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_m1_yuka, 0, LVar0, 0)
            Call(TranslateModel, MODEL_m1_kabe, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_m1_yuka)
            Add(LVar0, LVar8)
            Call(N(SetEntityPositionF), MV_SwitchEntityID, LVar7, LVar0, LVar9)
            Call(N(EnableCameraFollowPlayerY))
            Wait(1)
            Call(N(AwaitPlayerNotPoundingFloor), COLLIDER_m1_yuka, ENTITY_COLLIDER_ID(0))
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
        Call(EnableModel, MODEL_o135, TRUE)
        Call(EnableModel, MODEL_o137, FALSE)
        Set(GF_SAM07_FloorRaised, TRUE)
    Else
        Call(EnableModel, MODEL_o137, TRUE)
        Call(EnableModel, MODEL_o135, FALSE)
        Call(PlaySoundAtCollider, COLLIDER_m1_yuka, SOUND_SAM07_LOWER_FLOOR, 0)
        Call(MakeLerp, 0, -180, 120, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_m1_yuka, 0, LVar0, 0)
            Call(TranslateModel, MODEL_m1_kabe, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_m1_yuka)
            Add(LVar0, LVar8)
            Call(N(SetEntityPositionF), MV_SwitchEntityID, LVar7, LVar0, LVar9)
            Call(N(EnableCameraFollowPlayerY))
            Wait(1)
            Call(N(AwaitPlayerNotPoundingFloor), COLLIDER_m1_yuka, ENTITY_COLLIDER_ID(0))
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Set(GF_SAM07_FloorRaised, FALSE)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

BombTriggerF N(BombPos_Ice) = {
    .pos = { -940.0f, -130.0f, -75.0f },
    .radius = 60.0f
};

EvtScript N(EVS_SetupPit) = {
    Call(EnableGroup, MODEL_g72, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m1_kabe, COLLIDER_FLAGS_UPPER_MASK)
    Call(ParentColliderToModel, COLLIDER_m1_yuka, MODEL_m1_yuka)
    Call(ParentColliderToModel, COLLIDER_o116, MODEL_m1_yuka)
    IfEq(GF_SAM07_IceBroken, FALSE)
        Call(EnableModel, MODEL_o137, TRUE)
        Call(TranslateGroup, MODEL_move1, 0, -180, 0)
        Call(UpdateColliderTransform, COLLIDER_m1_yuka)
        Call(UpdateColliderTransform, COLLIDER_o116)
        BindTrigger(Ref(N(EVS_TouchFloor_FragileIce)), TRIGGER_FLOOR_TOUCH, COLLIDER_o116, 1, 0)
        BindTrigger(Ref(N(EVS_Blast_FragileIce)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Ice)), 1, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o116, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
        Call(EnableModel, MODEL_m1_yuka, TRUE)
        Call(EnableModel, MODEL_m1_kabe, TRUE)
        Call(EnableModel, MODEL_o135, TRUE)
        IfEq(GF_SAM07_FloorRaised, FALSE)
            Call(EnableModel, MODEL_o137, TRUE)
            Call(TranslateGroup, MODEL_move1, 0, -180, 0)
            Call(UpdateColliderTransform, COLLIDER_m1_yuka)
        Else
            Call(EnableModel, MODEL_o135, TRUE)
        EndIf
    EndIf
    Return
    End
};
