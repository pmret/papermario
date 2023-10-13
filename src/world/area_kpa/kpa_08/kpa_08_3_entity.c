#include "kpa_08.h"
#include "entity.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"

API_CALLABLE(N(ElevatePlayer)) {
    Bytecode* args = script->ptrReadPos;
    s32 floor = evt_get_variable(script, *args++);
    s32 yOffset = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (floor == gCollisionStatus.curFloor) {
        playerStatus->pos.y = script->varTable[0] + yOffset;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ActivateSwitch) = {
    EVT_IF_NE(AF_KPA08_PlatformRaised, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_KPA08_PlatformRaised, TRUE)
    EVT_CALL(N(EnableCameraFollowPlayerY))
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_EF)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o19, SOUND_KPA_RAISE_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, -50, 0, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 15, 100)
            EVT_CALL(TranslateGroup, MODEL_move, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o19)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(80)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o19, SOUND_KPA_LOWER_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, -50, 20, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 15, 100)
            EVT_CALL(TranslateGroup, MODEL_move, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o19)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_EF)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o90, SOUND_KPA_RAISE_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, -99, 0, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 17, 100)
            EVT_CALL(TranslateGroup, MODEL_move2, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o90)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_WAIT(80)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o90, SOUND_KPA_LOWER_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, -99, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 17, 100)
            EVT_CALL(TranslateGroup, MODEL_move2, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o90)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(TranslateGroup, MODEL_move2, 0, -99, -1)
        EVT_SET(AF_KPA08_PlatformRaised, FALSE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(AF_KPA08_PlatformRaised, FALSE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), 10, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ActivateSwitch)))
    EVT_CALL(ParentColliderToModel, COLLIDER_o19, MODEL_m_yuka)
    EVT_CALL(TranslateGroup, MODEL_move, 0, -50, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o19)
    EVT_CALL(ParentColliderToModel, COLLIDER_o90, MODEL_m2_yuka)
    EVT_CALL(TranslateGroup, MODEL_move2, 0, -99, -1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o90)
    EVT_RETURN
    EVT_END
};
