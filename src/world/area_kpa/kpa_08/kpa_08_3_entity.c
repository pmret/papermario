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
    IfNe(AF_KPA08_PlatformRaised, FALSE)
        Return
    EndIf
    Set(AF_KPA08_PlatformRaised, TRUE)
    Call(N(EnableCameraFollowPlayerY))
    Thread
        SetGroup(EVT_GROUP_EF)
        Call(PlaySoundAtCollider, COLLIDER_o19, SOUND_KPA_RAISE_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, -50, 0, 15, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(N(ElevatePlayer), 15, 100)
            Call(TranslateGroup, MODEL_move, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o19)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(80)
        Call(PlaySoundAtCollider, COLLIDER_o19, SOUND_KPA_LOWER_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, -50, 20, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(N(ElevatePlayer), 15, 100)
            Call(TranslateGroup, MODEL_move, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o19)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        SetGroup(EVT_GROUP_EF)
        Call(DisablePlayerInput, TRUE)
        Call(PlaySoundAtCollider, COLLIDER_o90, SOUND_KPA_RAISE_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, -99, 0, 15, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(N(ElevatePlayer), 17, 100)
            Call(TranslateGroup, MODEL_move2, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o90)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(DisablePlayerInput, FALSE)
        Wait(80)
        Call(PlaySoundAtCollider, COLLIDER_o90, SOUND_KPA_LOWER_STONE_PLATFORM, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, -99, 15, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(N(ElevatePlayer), 17, 100)
            Call(TranslateGroup, MODEL_move2, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o90)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(TranslateGroup, MODEL_move2, 0, -99, -1)
        Set(AF_KPA08_PlatformRaised, FALSE)
    EndThread
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Set(AF_KPA08_PlatformRaised, FALSE)
    Call(MakeEntity, Ref(Entity_RedSwitch), 10, 0, 0, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ActivateSwitch)))
    Call(ParentColliderToModel, COLLIDER_o19, MODEL_m_yuka)
    Call(TranslateGroup, MODEL_move, 0, -50, 0)
    Call(UpdateColliderTransform, COLLIDER_o19)
    Call(ParentColliderToModel, COLLIDER_o90, MODEL_m2_yuka)
    Call(TranslateGroup, MODEL_move2, 0, -99, -1)
    Call(UpdateColliderTransform, COLLIDER_o90)
    Return
    End
};
