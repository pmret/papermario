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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o116, SOUND_ICE_SHATTER, 0)
    EVT_CALL(N(AnimateIceShattering))
    EVT_LOOP(10)
        EVT_CALL(SetGroupVisibility, MODEL_move1, MODEL_GROUP_VISIBLE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
        EVT_CALL(EnableModel, MODEL_m1_yuka, TRUE)
        EVT_CALL(EnableModel, MODEL_m1_kabe, TRUE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TouchFloor_FragileIce) = {
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_IF_NE(LVar0, ACTION_STATE_TORNADO_POUND)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GF_SAM07_IceBroken, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_SAM07_IceBroken, TRUE)
    EVT_WAIT(5)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o116, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_BreakIce))
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Blast_FragileIce) = {
    EVT_IF_EQ(GF_SAM07_IceBroken, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_SAM07_IceBroken, TRUE)
    EVT_WAIT(5)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o116, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_BreakIce))
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGreenSwitch) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_SwitchEntityID, LVar7, LVar8, LVar9)
    EVT_IF_EQ(GF_SAM07_FloorRaised, FALSE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_m1_yuka, SOUND_SAM07_RAISE_FLOOR, 0)
        EVT_SUB(LVar8, -180)
        EVT_CALL(MakeLerp, -180, 0, 120, EASING_COS_IN_OUT)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_m1_yuka, 0, LVar0, 0)
            EVT_CALL(TranslateModel, MODEL_m1_kabe, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_m1_yuka)
            EVT_ADD(LVar0, LVar8)
            EVT_CALL(N(SetEntityPositionF), MV_SwitchEntityID, LVar7, LVar0, LVar9)
            EVT_CALL(N(EnableCameraFollowPlayerY))
            EVT_WAIT(1)
            EVT_CALL(N(AwaitPlayerNotPoundingFloor), COLLIDER_m1_yuka, ENTITY_COLLIDER_ID(0))
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CALL(EnableModel, MODEL_o135, TRUE)
        EVT_CALL(EnableModel, MODEL_o137, FALSE)
        EVT_SET(GF_SAM07_FloorRaised, TRUE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o137, TRUE)
        EVT_CALL(EnableModel, MODEL_o135, FALSE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_m1_yuka, SOUND_SAM07_LOWER_FLOOR, 0)
        EVT_CALL(MakeLerp, 0, -180, 120, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_m1_yuka, 0, LVar0, 0)
            EVT_CALL(TranslateModel, MODEL_m1_kabe, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_m1_yuka)
            EVT_ADD(LVar0, LVar8)
            EVT_CALL(N(SetEntityPositionF), MV_SwitchEntityID, LVar7, LVar0, LVar9)
            EVT_CALL(N(EnableCameraFollowPlayerY))
            EVT_WAIT(1)
            EVT_CALL(N(AwaitPlayerNotPoundingFloor), COLLIDER_m1_yuka, ENTITY_COLLIDER_ID(0))
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_SET(GF_SAM07_FloorRaised, FALSE)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

BombTriggerF N(BombPos_Ice) = {
    .pos = { -940.0f, -130.0f, -75.0f },
    .radius = 60.0f
};

EvtScript N(EVS_SetupPit) = {
    EVT_CALL(EnableGroup, MODEL_g72, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m1_kabe, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ParentColliderToModel, COLLIDER_m1_yuka, MODEL_m1_yuka)
    EVT_CALL(ParentColliderToModel, COLLIDER_o116, MODEL_m1_yuka)
    EVT_IF_EQ(GF_SAM07_IceBroken, FALSE)
        EVT_CALL(EnableModel, MODEL_o137, TRUE)
        EVT_CALL(TranslateGroup, MODEL_move1, 0, -180, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_m1_yuka)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o116)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TouchFloor_FragileIce)), TRIGGER_FLOOR_TOUCH, COLLIDER_o116, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Blast_FragileIce)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Ice)), 1, 0)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o116, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
        EVT_CALL(EnableModel, MODEL_m1_yuka, TRUE)
        EVT_CALL(EnableModel, MODEL_m1_kabe, TRUE)
        EVT_CALL(EnableModel, MODEL_o135, TRUE)
        EVT_IF_EQ(GF_SAM07_FloorRaised, FALSE)
            EVT_CALL(EnableModel, MODEL_o137, TRUE)
            EVT_CALL(TranslateGroup, MODEL_move1, 0, -180, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_m1_yuka)
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_o135, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
