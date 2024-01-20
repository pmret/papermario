#include "tik_08.h"
#include "entity.h"

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_SpawnSwitch) = {
    Call(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, 90, 200, 100)
    Call(MakeLerp, 200, -10, 25, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_BlueSwitch, 90, LVar0, 100)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, 90, LVar0, 100)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(10)
    Return
    End
};

EvtScript N(EVS_GotoMap_jan_03_3) = {
    Call(GotoMap, Ref("jan_03"), jan_03_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnSwitchActivate) = {
    Wait(10)
    Call(PlaySound, SOUND_GROW)
    Set(GF_TIK08_WarpPipe, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TIK08_WarpPipe, FALSE)
        Call(MakeEntity, Ref(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TIK_04))
        Set(MV_BlueSwitch, LVar0)
        BindTrigger(Ref(N(EVS_OnSwitchActivate)), TRIGGER_AREA_FLAG_SET, AF_TIK_04, 1, 0)
        IfEq(GF_TIK08_Defeated_Blooper, TRUE)
            Call(N(SetEntityPosition), MV_BlueSwitch, 90, -10, 100)
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_BlueWarpPipe), 95, -10, -88, 0, tik_08_ENTRY_4, Ref(N(EVS_GotoMap_jan_03_3)), EVT_INDEX_OF_GAME_FLAG(GF_TIK08_WarpPipe), MAKE_ENTITY_END)
    Return
    End
};
