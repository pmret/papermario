#include "kpa_09.h"
#include "entity.h"

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

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
    EVT_IF_NE(AF_KPA09_PlatformRaised, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_KPA09_PlatformRaised, TRUE)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_EF)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o19, SOUND_0227, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, -50, 0, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 16, 100)
            EVT_CALL(TranslateGroup, MODEL_move, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o19)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(80)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o19, SOUND_0228, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, -50, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 16, 100)
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
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o106, SOUND_0227, SOUND_SPACE_DEFAULT)
        EVT_CALL(EnableGroup, MODEL_move2, TRUE)
        EVT_CALL(MakeLerp, -50, 0, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 18, 100)
            EVT_CALL(TranslateGroup, MODEL_move2, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o106)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_WAIT(80)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o106, SOUND_0228, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, -50, 15, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ElevatePlayer), 18, 100)
            EVT_CALL(TranslateGroup, MODEL_move2, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o106)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SET(AF_KPA09_PlatformRaised, FALSE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(AF_KPA09_PlatformRaised, FALSE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), -325, 0, -8, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ActivateSwitch)))
    EVT_CALL(ParentColliderToModel, COLLIDER_o19, MODEL_m_yuka)
    EVT_CALL(TranslateGroup, MODEL_move, 0, -50, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o19)
    EVT_CALL(ParentColliderToModel, COLLIDER_o106, MODEL_m_yuka2)
    EVT_CALL(TranslateGroup, MODEL_move2, 0, -50, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o106)
    EVT_RETURN
    EVT_END
};
