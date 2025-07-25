#include "flo_22.h"
#include "sprite/player.h"

API_CALLABLE(N(UnusedCallback)) {
    return ApiStatus_DONE2;
}

s32 N(BerryList)[] = {
    ITEM_RED_BERRY,
    ITEM_BLUE_BERRY,
    ITEM_YELLOW_BERRY,
    ITEM_BUBBLE_BERRY,
    ITEM_NONE
};

EvtScript N(EVS_SniffleHint) = {
    Call(DisablePlayerInput, true)
    Wait(20)
    Call(ShowMessageAtScreenPos, MSG_CH6_00DB, 300, 120)
    Wait(10)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_TossItemIntoWell) = {
    Call(SetPlayerAnimation, ANIM_MarioW1_Toss)
    Thread
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Set(LVar6, 35)
        Set(LVar5, 5)
        Call(MakeItemEntity, LVar8, LVar2, LVar6, 0, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(LVar7, LVar0)
        Call(MakeLerp, LVar2, 35, 20, EASING_CUBIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(SetItemPos, LVar7, LVar0, LVar6, 0)
            Add(LVar6, LVar5)
            Add(LVar5, -1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(RemoveItemEntity, LVar7)
    EndThread
    Wait(10)
    Call(PlaySoundAt, SOUND_FALL_LONG, SOUND_SPACE_DEFAULT, 35, 0, 0)
    Wait(5)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10)
    Return
    End
};

EvtScript N(EVS_OnInteract_Well) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerInput, false)
    Call(ShowConsumableChoicePopup)
    Call(CloseChoicePopup)
    Call(DisablePlayerInput, true)
    Set(LVar8, LVar0)
    Switch(LVar8)
        CaseLe(-1)
        CaseLe(ITEM_NONE)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Well, 160, 40)
        CaseEq(ITEM_BLUE_BERRY)
            ExecWait(N(EVS_TossItemIntoWell))
            Call(RemoveItemAt, LVar1)
            IfEq(GF_FLO22_ThrewBlueBerryDownWell, false)
                Call(ShowMessageAtWorldPos, MSG_CH6_00DD, 35, 35, 0)
                Set(GF_FLO22_ThrewBlueBerryDownWell, true)
                Call(MakeItemEntity, ITEM_FLOWER_SAVER_B, -35, 0, 0, ITEM_SPAWN_MODE_KEY, GF_FLO22_Item_FlowerSaverB)
                Set(LVar7, LVar0)
                Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_INVISIBLE, true)
                Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_HAS_SHADOW, false)
                Call(SetNpcPos, NPC_Dummy, 35, 0, 0)
                Call(SetNpcJumpscale, NPC_Dummy, Float(1.0))
                Thread
                    Call(NpcJump0, NPC_Dummy, -53, 0, 0, 25)
                    Call(NpcJump0, NPC_Dummy, -73, 0, 0, 15)
                    Call(NpcJump0, NPC_Dummy, -83, 0, 0, 8)
                EndThread
                Loop(53)
                    Call(GetNpcPos, NPC_Dummy, LVar1, LVar2, LVar3)
                    Call(SetItemPos, LVar7, LVar1, LVar2, LVar3)
                    Wait(1)
                EndLoop
                Call(SetNpcPos, NPC_Dummy, NPC_DISPOSE_LOCATION)
                Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_INVISIBLE, false)
                Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_HAS_SHADOW, true)
            Else
                Call(ShowMessageAtWorldPos, MSG_CH6_00DE, 35, 35, 0)
            EndIf
        CaseDefault
            ExecWait(N(EVS_TossItemIntoWell))
            Call(RemoveItemAt, LVar1)
            Call(ShowMessageAtWorldPos, MSG_CH6_00DC, 35, 35, 0)
            Call(RandInt, 1, LVar1)
            IfEq(LVar1, 0)
                Call(SetNpcJumpscale, NPC_Bzzap, Float(0.0))
                Call(NpcFacePlayer, NPC_Bzzap, 0)
                Wait(1)
                Call(SetNpcPos, NPC_Bzzap, 30, 0, 0)
                Call(SetNpcAnimation, NPC_Bzzap, ANIM_Bzzap_Anim01)
                Call(NpcJump0, NPC_Bzzap, 30, 60, 0, 20)
                Wait(10)
                Call(SetNpcAnimation, NPC_Bzzap, ANIM_Bzzap_Anim04)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar1, 20)
                Call(NpcJump0, NPC_Bzzap, LVar0, LVar1, LVar2, 5)
                Set(MV_Bzzap_State, 1)
            Else
                Call(SetNpcPos, NPC_Dayzee, 30, 0, 0)
                Call(SetNpcAnimation, NPC_Dayzee, ANIM_Dayzee_Anim0E)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar1, 20)
                Call(SetNpcJumpscale, NPC_Dayzee, Float(2.0))
                Call(NpcJump0, NPC_Dayzee, LVar0, LVar1, LVar2, 20)
                Set(MV_Dayzee_State, 1)
            EndIf
    EndSwitch
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_SetupWell) = {
    BindPadlock(Ref(N(EVS_OnInteract_Well)), TRIGGER_WALL_PRESS_A, COLLIDER_o5, Ref(N(BerryList)), 0, 1)
    IfEq(GF_FLO22_ThrewBlueBerryDownWell, true)
        Call(MakeItemEntity, ITEM_FLOWER_SAVER_B, -83, 0, 0, ITEM_SPAWN_MODE_KEY, GF_FLO22_Item_FlowerSaverB)
    EndIf
    Return
    End
};
