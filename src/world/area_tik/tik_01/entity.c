#include "tik_01.h"
#include "entity.h"

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_SpawnSwitch) = {
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Add(LVar2, -75)
    Call(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, LVar2, 200, 25)
    Call(MakeLerp, 200, -10, 25, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_Unk_01, LVar2, LVar0, 25)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar2, LVar0, 25)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(10)
    Return
    End
};

EvtScript N(EVS_SmashBlock) = {
    Set(GF_TIK01_Hammer2Block, true)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o64, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_GotoMap_kmr_02_3) = {
    Call(GotoMap, Ref("kmr_02"), kmr_02_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_nok_02_2) = {
    Call(GotoMap, Ref("nok_02"), nok_02_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_dro_01_2) = {
    Call(GotoMap, Ref("dro_01"), dro_01_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnSwitchActivate) = {
    Wait(10)
    Call(PlaySound, SOUND_GROW)
    Set(GF_TIK01_WarpPipes, true)
    Unbind
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TIK01_Hammer2Block, false)
        Call(MakeEntity, Ref(Entity_Hammer2Block), -240, -10, 0, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_SmashBlock)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o64, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o63, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(GF_TIK01_WarpPipes, false)
        Call(MakeEntity, Ref(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TIK_03))
        Set(MV_Unk_01, LVar0)
        BindTrigger(Ref(N(EVS_OnSwitchActivate)), TRIGGER_AREA_FLAG_SET, AF_TIK_03, 1, 0)
        IfEq(GF_TIK01_Defeated_Blooper, true)
            Call(N(SetEntityPosition), MV_Unk_01, 125, -10, 25)
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_BlueWarpPipe), 150, -10, -82, 0, tik_01_ENTRY_2,
        Ref(N(EVS_GotoMap_kmr_02_3)), EVT_INDEX_OF_GAME_FLAG(GF_TIK01_WarpPipes), MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BlueWarpPipe),  50, -10, -82, 0, tik_01_ENTRY_3,
        Ref(N(EVS_GotoMap_nok_02_2)), EVT_INDEX_OF_GAME_FLAG(GF_TIK01_WarpPipes), MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BlueWarpPipe), -50, -10, -82, 0, tik_01_ENTRY_4,
        Ref(N(EVS_GotoMap_dro_01_2)), EVT_INDEX_OF_GAME_FLAG(GF_TIK01_WarpPipes), MAKE_ENTITY_END)
    Return
    End
};
