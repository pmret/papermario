#include "obk_01.h"
#include "sprite.h"
#include "sprite/player.h"

API_CALLABLE(N(SetPortraitItemAlpha)) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAG_TRANSPARENT);
    item->alpha = 255;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateSpeakingPortrait) = {
    // hide empty frames
    EVT_CALL(EnableModel, MODEL_n1, FALSE)
    EVT_CALL(EnableModel, MODEL_n2, FALSE)
    EVT_LOOP(0)
        // toggle different frames of the speaking 'animation'
        EVT_CALL(EnableModel, MODEL_u1, TRUE)
        EVT_CALL(EnableModel, MODEL_u2, TRUE)
        EVT_CALL(EnableModel, MODEL_si1, FALSE)
        EVT_CALL(EnableModel, MODEL_si2, FALSE)
        EVT_WAIT(5)
        EVT_CALL(EnableModel, MODEL_u1, FALSE)
        EVT_CALL(EnableModel, MODEL_u2, FALSE)
        EVT_CALL(EnableModel, MODEL_si1, TRUE)
        EVT_CALL(EnableModel, MODEL_si2, TRUE)
        EVT_WAIT(5)
        EVT_SUB(LVar0, 1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_LowerPortrait) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_GOT_BOO_PORTRAIT)
            EVT_IF_EQ(GF_OBK01_Met_Portrait, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_002B, 160, 40)
                EVT_SET(GF_OBK01_Met_Portrait, TRUE)
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_002C, 160, 40)
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH3_GOT_BOO_PORTRAIT)
            EVT_CALL(ShowKeyChoicePopup)
            EVT_CALL(CloseChoicePopup)
            EVT_SWITCH(LVar0)
                EVT_CASE_GE(1)
                    EVT_CALL(RemoveKeyItemAt, LVar1)
                    EVT_WAIT(10 * DT)
                    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_Lift)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar1, 40)
                    EVT_CALL(MakeItemEntity, ITEM_BOO_PORTRAIT, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
                    EVT_CALL(N(SetPortraitItemAlpha))
                    EVT_SET(LVarA, LVar0)
                    EVT_WAIT(30 * DT)
                    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                    EVT_SET(LVar6, 40)
                    EVT_ADD(LVar6, LVar4)
                    EVT_SET(LVar7, 70)
                    EVT_ADD(LVar7, LVar4)
                    EVT_CALL(MakeLerp, LVar6, LVar7, 20 * DT, EASING_LINEAR)
                    EVT_LOOP(0)
                        EVT_CALL(UpdateLerp)
                        EVT_CALL(SetItemPos, LVarA, LVar3, LVar0, LVar5)
                        EVT_WAIT(1)
                        EVT_IF_EQ(LVar1, 0)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                    EVT_CALL(MakeLerp, 255, 0, 30 * DT, EASING_LINEAR)
                    EVT_LOOP(0)
                        EVT_CALL(UpdateLerp)
                        EVT_CALL(SetItemAlpha, LVarA, LVar0)
                        EVT_WAIT(1)
                        EVT_IF_EQ(LVar1, 0)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                    EVT_WAIT(30 * DT)
                    EVT_CALL(RemoveItemEntity, LVarA)
                    EVT_IF_EQ(GF_OBK01_Met_Portrait, TRUE)
                        EVT_SET(LVar0, 25)
                        EVT_EXEC(N(EVS_AnimateSpeakingPortrait))
                        EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_002D, 160, 40)
                    EVT_ELSE
                        EVT_SET(LVar0, 35)
                        EVT_EXEC(N(EVS_AnimateSpeakingPortrait))
                        EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_002E, 160, 40)
                    EVT_END_IF
                    EVT_SET(GB_StoryProgress, STORY_CH3_RESTORED_BOO_PORTRAIT)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_BeforeJump)
            EVT_WAIT(3)
            EVT_CALL(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_Jump)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
            EVT_CALL(PlayerJump, 812, -170, -2, 20 * DT)
            EVT_CALL(PlaySoundAtPlayer, SOUND_TRANSPORTER_IN, SOUND_SPACE_DEFAULT)
            EVT_WAIT(10 * DT)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 812, 0, 28)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 812, 0, 28)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_WAIT(10 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
            EVT_WAIT(1)
            EVT_CALL(PlaySoundAtPlayer, SOUND_TRANSPORTER_OUT, SOUND_SPACE_DEFAULT)
            EVT_CALL(SetPlayerPos, 812, 61, -2)
            EVT_CALL(PlayerJump, 812, 0, 28, 8 * DT)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(EnablePartnerAI)
            EVT_IF_EQ(GF_OBK01_Portrait_Farewell, FALSE)
                EVT_WAIT(10 * DT)
                EVT_SET(LVar0, 5)
                EVT_EXEC(N(EVS_AnimateSpeakingPortrait))
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_002F, 160, 40)
                EVT_SET(GF_OBK01_Portrait_Farewell, TRUE)
            EVT_END_IF
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_WAIT(2)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_UpperPortrait) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_BeforeJump)
    EVT_WAIT(3)
    EVT_CALL(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_Jump)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 812, 40, -2, 20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_TRANSPORTER_IN, SOUND_SPACE_DEFAULT)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 812, -210, 28)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 812, -210, 28)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtPlayer, SOUND_TRANSPORTER_OUT, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerPos, 812, -146, -2)
    EVT_CALL(PlayerJump, 812, -210, 28, 8 * DT)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT(2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PortraitFrame_ShakeWhenNear) = {
    EVT_LOOP(0)
        EVT_IF_EQ(AF_OBK01_IsPlayerNearPortrait, TRUE)
            EVT_IF_NE(AF_OBK01_WasPlayerNearPortrait, AF_OBK01_IsPlayerNearPortrait)
                EVT_LOOP(3)
                    EVT_CALL(RotateModel, MODEL_n1, 5, 0, 0, 1)
                    EVT_WAIT(2)
                    EVT_CALL(RotateModel, MODEL_n1, 0, 0, 0, 1)
                    EVT_WAIT(1)
                    EVT_CALL(RotateModel, MODEL_n1, 5, 0, 0, 1)
                    EVT_WAIT(2)
                    EVT_CALL(RotateModel, MODEL_n1, 0, 0, 0, 1)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_SET(AF_OBK01_WasPlayerNearPortrait, AF_OBK01_IsPlayerNearPortrait)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PortraitFrame_MonitorPlayerPos) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SET(AF_OBK01_IsPlayerNearPortrait, FALSE)
        EVT_IF_EQ(GF_OBK01_Met_Portrait, FALSE)
            EVT_IF_GE(LVar1, -210)
                EVT_IF_LE(LVar1, -100)
                    EVT_IF_GE(LVar0, 775)
                        EVT_SET(AF_OBK01_IsPlayerNearPortrait, TRUE)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_BooPortrait)[] = {
    ITEM_BOO_PORTRAIT,
    ITEM_NONE
};

EvtScript N(EVS_SetupPortrait) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_Interact_LowerPortrait)), TRIGGER_WALL_PRESS_A, COLLIDER_aa1, EVT_PTR(N(ItemList_BooPortrait)), 0, 1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_UpperPortrait)), TRIGGER_WALL_PRESS_A, COLLIDER_aa2, 1, 0)
    EVT_EXEC(N(EVS_PortraitFrame_MonitorPlayerPos))
    EVT_EXEC(N(EVS_PortraitFrame_ShakeWhenNear))
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_RESTORED_BOO_PORTRAIT)
        EVT_CALL(EnableModel, MODEL_n1, TRUE)
        EVT_CALL(EnableModel, MODEL_u1, FALSE)
        EVT_CALL(EnableModel, MODEL_si1, FALSE)
        EVT_CALL(EnableModel, MODEL_n2, TRUE)
        EVT_CALL(EnableModel, MODEL_u2, FALSE)
        EVT_CALL(EnableModel, MODEL_si2, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_n1, FALSE)
        EVT_CALL(EnableModel, MODEL_n2, FALSE)
        EVT_CALL(EnableModel, MODEL_u1, TRUE)
        EVT_CALL(EnableModel, MODEL_u2, TRUE)
        EVT_CALL(EnableModel, MODEL_si1, FALSE)
        EVT_CALL(EnableModel, MODEL_si2, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(Unused_80243C7C_3C7C)[] = {
    0, 1, 0, 5, 1, 0, 5, 1,
    0, 5, 1, 1, 5, 1, 1, 5,
    2, 2, 5, 2, 2, 5, 2, 2,
    5, 2, 3, 5, 2, 3, 5, 3,
    4, 5, 3, 4, 5, 3, 4, 5,
    3, 5, 5, 3, 5, 5, 4, 6,
    5, 4, 6, 5, 4, 6, 5, 4,
    7, 5, 4, 7, 5,
};
