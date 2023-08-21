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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH6_00DB, 300, 120)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TossItemIntoWell) = {
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_Toss)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_SET(LVar6, 35)
        EVT_SET(LVar5, 5)
        EVT_CALL(MakeItemEntity, LVar8, LVar2, LVar6, 0, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(LVar7, LVar0)
        EVT_CALL(MakeLerp, LVar2, 35, 20, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemPos, LVar7, LVar0, LVar6, 0)
            EVT_ADD(LVar6, LVar5)
            EVT_ADD(LVar5, -1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, LVar7)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAt, SOUND_FALL_LONG, SOUND_SPACE_DEFAULT, 35, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnInteract_Well) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar8, LVar0)
    EVT_SWITCH(LVar8)
        EVT_CASE_LE(-1)
        EVT_CASE_LE(ITEM_NONE)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Well, 160, 40)
        EVT_CASE_EQ(ITEM_BLUE_BERRY)
            EVT_EXEC_WAIT(N(EVS_TossItemIntoWell))
            EVT_CALL(RemoveItemAt, LVar1)
            EVT_IF_EQ(GF_FLO22_ThrewBlueBerryDownWell, FALSE)
                EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00DD, 35, 35, 0)
                EVT_SET(GF_FLO22_ThrewBlueBerryDownWell, TRUE)
                EVT_CALL(MakeItemEntity, ITEM_FLOWER_SAVER_B, -35, 0, 0, ITEM_SPAWN_MODE_KEY, GF_FLO22_Item_FlowerSaverB)
                EVT_SET(LVar7, LVar0)
                EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_HAS_SHADOW, FALSE)
                EVT_CALL(SetNpcPos, NPC_Dummy, 35, 0, 0)
                EVT_CALL(SetNpcJumpscale, NPC_Dummy, EVT_FLOAT(1.0))
                EVT_THREAD
                    EVT_CALL(NpcJump0, NPC_Dummy, -53, 0, 0, 25)
                    EVT_CALL(NpcJump0, NPC_Dummy, -73, 0, 0, 15)
                    EVT_CALL(NpcJump0, NPC_Dummy, -83, 0, 0, 8)
                EVT_END_THREAD
                EVT_LOOP(53)
                    EVT_CALL(GetNpcPos, NPC_Dummy, LVar1, LVar2, LVar3)
                    EVT_CALL(SetItemPos, LVar7, LVar1, LVar2, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetNpcPos, NPC_Dummy, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_INVISIBLE, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_HAS_SHADOW, TRUE)
            EVT_ELSE
                EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00DE, 35, 35, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_TossItemIntoWell))
            EVT_CALL(RemoveItemAt, LVar1)
            EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00DC, 35, 35, 0)
            EVT_CALL(RandInt, 1, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(SetNpcJumpscale, NPC_Bzzap, EVT_FLOAT(0.0))
                EVT_CALL(NpcFacePlayer, NPC_Bzzap, 0)
                EVT_WAIT(1)
                EVT_CALL(SetNpcPos, NPC_Bzzap, 30, 0, 0)
                EVT_CALL(SetNpcAnimation, NPC_Bzzap, ANIM_Bzzap_Anim01)
                EVT_CALL(NpcJump0, NPC_Bzzap, 30, 60, 0, 20)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_Bzzap, ANIM_Bzzap_Anim04)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 20)
                EVT_CALL(NpcJump0, NPC_Bzzap, LVar0, LVar1, LVar2, 5)
                EVT_SET(MV_Bzzap_State, 1)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_Dayzee, 30, 0, 0)
                EVT_CALL(SetNpcAnimation, NPC_Dayzee, ANIM_Dayzee_Anim0E)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 20)
                EVT_CALL(SetNpcJumpscale, NPC_Dayzee, EVT_FLOAT(2.0))
                EVT_CALL(NpcJump0, NPC_Dayzee, LVar0, LVar1, LVar2, 20)
                EVT_SET(MV_Dayzee_State, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupWell) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_OnInteract_Well)), TRIGGER_WALL_PRESS_A, COLLIDER_o5, EVT_PTR(N(BerryList)), 0, 1)
    EVT_IF_EQ(GF_FLO22_ThrewBlueBerryDownWell, TRUE)
        EVT_CALL(MakeItemEntity, ITEM_FLOWER_SAVER_B, -83, 0, 0, ITEM_SPAWN_MODE_KEY, GF_FLO22_Item_FlowerSaverB)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
