#include "dro_01.h"

API_CALLABLE(N(AwaitPlayerApproachShop)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_variable(script, *args++);
    f32 temp_f0 = (var4 - var2) / (var3 - var1);

    if (playerStatus->pos.z < ((temp_f0 * playerStatus->pos.x) + (var2 - (temp_f0 * var1)))) {
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcIdle_ShopOwner) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_LEFT_SHOP)
            EVT_CALL(N(AwaitPlayerApproachShop), 16, 190, -134, -131)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -180)
            EVT_EXEC_WAIT(N(EVS_OpenShopDoor))
            EVT_WAIT(10 * DT)
            EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 32, 0, -67)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, -210)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, 20, -12)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(20 * DT)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
#if VERSION_PAL
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.961))
#else
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
#endif
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, -23, -105, 20)
            EVT_WAIT(10 * DT)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 65, 0)
            EVT_WAIT(10 * DT)
            EVT_EXEC_WAIT(N(EVS_CloseShopDoor))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 37, -27, 20 * DT)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 142, 0, -67)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 62, -6, 20 * DT)
            EVT_CALL(NpcMoveTo, NPC_SELF, 103, 11, 20 * DT)
            EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20 * DT)
            EVT_CALL(EnableNpcBlur, NPC_SELF, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_174, SOUND_SPACE_MODE_0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 554, -12, 20 * DT)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_WAIT(30 * DT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(GB_StoryProgress, STORY_CH2_SHADY_MOUSE_LEFT_SHOP)
        EVT_CASE_LT(STORY_CH2_SPOKE_WITH_SHEEK)
        EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
            EVT_CALL(EnableNpcBlur, NPC_SELF, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_174, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcPos, NPC_SELF, 470, 0, 18)
            EVT_CALL(NpcMoveTo, NPC_SELF, 287, 9, 20 * DT)
            EVT_CALL(NpcMoveTo, NPC_SELF, 102, -14, 20 * DT)
            EVT_CALL(NpcMoveTo, NPC_SELF, -32, -96, 20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_EXEC_WAIT(N(EVS_OpenShopDoor))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 20, -375, 30 * DT)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_EXEC_WAIT(N(EVS_CloseShopDoor))
            EVT_CALL(EnableNpcBlur, NPC_SELF, FALSE)
            EVT_SET(GB_StoryProgress, STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -375)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShopOwner) = {
    EVT_IF_EQ(AB_DRO_SHOP_PREV1, 4)
        EVT_IF_EQ(AB_DRO_SHOP_PREV2, 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
            EVT_EXEC_WAIT(N(EVS_LetterPrompt_ShopOwner))
            EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(ItemShopInteract)
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_ShopOwner))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShopOwner) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShopOwner)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShopOwner)))
    EVT_RETURN
    EVT_END
};
