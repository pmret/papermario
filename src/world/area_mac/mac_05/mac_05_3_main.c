#include "mac_05.h"

#include "world/common/atomic/TexturePan.inc.c"

#define NAMESPACE dup_mac_05
#include "world/common/todo/UnkFloatFunc001.inc.c"
#define NAMESPACE mac_05

API_CALLABLE(N(func_8024047C_8525EC)) {
    gGameStatusPtr->exitTangent = 0.0f;
    return ApiStatus_BLOCK;
}

EvtScript N(D_8024457C_8566EC) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVarC, 0)
    EVT_LABEL(0)
        EVT_IF_GE(LVarC, 60)
            EVT_SET(LVarC, 0)
        EVT_END_IF
        EVT_CALL(dup_mac_05_UnkFloatFunc001, LVarC, LVar0, EVT_FLOAT(-1.0), EVT_FLOAT(1.0), 30, 0, 0)
        EVT_CALL(ScaleModel, MODEL_kaimen, 1, LVar0, 1)
        EVT_ADD(LVarC, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244648_8567B8) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 600, -240, 320, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o177, LVar0, -25, -75)
            EVT_CALL(RotateModel, MODEL_o177, 0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -240, 600, 320, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o177, LVar0, -25, -75)
            EVT_CALL(RotateModel, MODEL_o177, 180, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_mac_04_1) = EVT_EXIT_WALK(60, mac_05_ENTRY_0, "mac_04", mac_04_ENTRY_1);

EvtScript N(D_80244810_856980) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, mac_05_ENTRY_3)
    EVT_EXEC(ExitWalk)
    EVT_SET(GB_StoryProgress, STORY_CH5_ENTERED_WHALE)
    EVT_CALL(GotoMap, EVT_PTR("kgr_01"), kgr_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80244810_856980)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilit9, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802448C4_856A34) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mac_05_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(mac_05_ENTRY_1)
            EVT_EXEC(N(EVS_802496FC))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(mac_05_ENTRY_2)
            EVT_EXEC(N(EVS_80248878))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(mac_05_ENTRY_3)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerPos, -160, -10, 371)
            EVT_CALL(SetNpcPos, NPC_PARTNER, -160, -10, 371)
            EVT_CALL(SetEnemyFlagBits, NPC_Whale, ENEMY_FLAG_CANT_INTERACT, 1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(InterruptUsePartner)
            EVT_WAIT(10)
            EVT_THREAD
                EVT_CALL(MakeLerp, -160, -220, 30, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetPlayerPos, LVar0, -10, 371)
                    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, -10, 371)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerPos, -280, -10, 371)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC_WAIT(EnterWalk)
            EVT_CALL(SetNpcPos, NPC_Whale, -220, 10, 372)
            EVT_CALL(SetEnemyFlagBits, NPC_Whale, ENEMY_FLAG_CANT_INTERACT, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, EVT_PTR(N(NpcSetA)))
        EVT_CASE_LT(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_SET(LVar0, EVT_PTR(N(NpcSetB)))
        EVT_CASE_LT(STORY_CH5_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(GetEntryID, LVar1)
            EVT_IF_EQ(LVar1, mac_05_ENTRY_1)
                EVT_IF_EQ(GF_MAC01_Defeated_JrTroopa4, FALSE)
                    EVT_SET(LVar0, EVT_PTR(N(NpcSetC)))
                EVT_ELSE
                    EVT_SET(LVar0, EVT_PTR(N(NpcSetB)))
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LVar0, EVT_PTR(N(NpcSetA)))
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_BEGAN_PEACH_MISSION)
            EVT_SET(LVar0, EVT_PTR(N(NpcSetA)))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(NpcSetA)))
    EVT_END_SWITCH
    EVT_CALL(MakeNpcs, FALSE, LVar0)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupWhale))
    EVT_CALL(GetEntryID, LVar0)
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(D_802448C4_856A34))
    EVT_WAIT(1)
    EVT_EXEC(N(D_8024457C_8566EC))
    EVT_CALL(SetTexPanner, MODEL_kaimen, 1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,  100,  -70,  -50)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(D_80244648_8567B8))
    EVT_EXEC(N(EVS_AnimateClub64Sign))
    EVT_RETURN
    EVT_END
};
