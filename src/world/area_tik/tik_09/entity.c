#include "tik_09.h"
#include "entity.h"

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_SpawnSwitch) = {
    Call(AwaitPlayerLeave, -10, 10, 50)
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 8)
        Loop(0)
            Call(GetPlayerActionState, LVar0)
            Wait(1)
            IfEq(LVar0, ACTION_STATE_IDLE)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(DisablePlayerPhysics, TRUE)
    Call(InterpCamTargetPos, 0, 1, -10, -10, 10, 20)
    Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
    Call(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, -10, 200, 10)
    Call(MakeLerp, 200, -10, 25, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_Unk_00, -10, LVar0, 10)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, -10, LVar0, 10)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(InterpCamTargetPos, 0, 1, LVar0, LVar1, LVar2, 20)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_GotoMap_mim_11_3) = {
    Call(GotoMap, Ref("mim_11"), mim_11_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_PlayRisingPipeSound) = {
    Wait(10)
    Call(PlaySound, SOUND_GROW)
    Set(GF_TIK09_WarpPipe, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TIK09_WarpPipe, FALSE)
        Call(MakeEntity, Ref(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TIK_05))
        Set(MV_Unk_00, LVar0)
        BindTrigger(Ref(N(EVS_PlayRisingPipeSound)), TRIGGER_AREA_FLAG_SET, AF_TIK_05, 1, 0)
        IfEq(GF_TIK09_Defeated_Ambush, TRUE)
            Call(N(SetEntityPosition), MV_Unk_00, -10, -10, 10)
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_BlueWarpPipe), -30, -10, -40, 0, tik_09_ENTRY_2, Ref(N(EVS_GotoMap_mim_11_3)), EVT_INDEX_OF_GAME_FLAG(GF_TIK09_WarpPipe), MAKE_ENTITY_END)
    Return
    End
};

MAP_RODATA_PAD(1,entity);
