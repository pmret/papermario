#include "mac_04.h"

extern EvtScript ItemShopInteract;

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

NpcSettings N(NpcSettings_ChetRippo) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/npc/GoombaFamily.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

NpcSettings N(NpcSettings_Twink) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(D_802467AC_84937C) = {
    EVT_CALL(func_802D2884, -440, -150, 0)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 50)
        EVT_SETF(LVar5, 3)
        EVT_CALL(MakeItemEntity, ITEM_TOY_TRAIN, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(LVar7, LVar0)
        EVT_CALL(MakeLerp, LVar4, -150, 30, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemPos, LVar7, -440, LVar3, LVar0)
            EVT_ADDF(LVar5, EVT_FLOAT(-0.5))
            EVT_ADD(LVar3, LVar5)
            EVT_IF_LT(LVar3, 0)
                EVT_SET(LVar3, 0)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, LVar7)
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024697C_84954C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_IF_LE(LVar2, 0)
        EVT_IF_EQ(LVar2, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Toybox, 160, 40)
        EVT_END_IF
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_1AA, 0)
    EVT_CALL(MakeLerp, 0, -90, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, 0)
        EVT_SUB(LVar2, LVar0)
        EVT_DIV(LVar2, 3)
        EVT_CALL(RotateGroup, MODEL_box_top, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_WAIT(N(D_802467AC_84937C))
    EVT_CALL(MakeLerp, -90, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, 0)
        EVT_SUB(LVar2, LVar0)
        EVT_DIV(LVar2, 3)
        EVT_CALL(RotateGroup, MODEL_box_top, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_1AA, 0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_CALL(GotoMap, EVT_PTR("omo_03"), omo_03_ENTRY_6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(ToyTrainList)[] = {
    ITEM_TOY_TRAIN,
    ITEM_NONE
};

EvtScript N(EVS_80246C58) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        EVT_BIND_PADLOCK(EVT_PTR(N(D_8024697C_84954C)), TRIGGER_WALL_PRESS_A, COLLIDER_o468, EVT_PTR(N(ToyTrainList)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(func_80241848_844418)(void) {
    s32 bpCost = 0;
    s32 i = 0;
    ItemData* itemTable = gItemTable;

    for (; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
        s16 badge = gPlayerData.equippedBadges[i];

        if (badge != 0) {
            bpCost += gMoveTable[itemTable[badge].moveID].costBP;
        }
    }
    return bpCost;
}

API_CALLABLE(N(func_802418AC_84447C)) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 bpCost = N(func_80241848_844418)();
    s32 i;

    if (gPlayerData.maxBP >= bpCost) {
        evt_set_variable(script, outVar, FALSE);
        return ApiStatus_DONE2;
    } else {
        s16* badges = gPlayerData.equippedBadges;

        for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
            badges[i] = 0;
        }
        enforce_hpfp_limits();
        evt_set_variable(script, outVar, TRUE);
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(PostChapter4StatUpdate)) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetFloorCollider.inc.c"

API_CALLABLE(N(IsPartnerBow)) {
    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Muskular) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246D94_849964) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcPos, NPC_Muskular, -520, 40, 270)
    EVT_CALL(PlayerFaceNpc, NPC_Muskular, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Muskular, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -420, 20, 235)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C5)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C6)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Muskular, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_CALL(PlaySoundAtPlayer, SOUND_139, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_188, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    EVT_CALL(EnableNpcAI, NPC_Muskular, TRUE)
    EVT_CALL(N(PostChapter4StatUpdate))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0194, 160, 40)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C7)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Housing_00C8, 160, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -500)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Twink, -600, 200, 350)
    EVT_CALL(NpcFlyTo, NPC_Twink, -437, 60, 270, 0, -10, EASING_LINEAR)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00C9)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_WAIT(20)
    EVT_CALL(NpcJump1, NPC_Twink, -460, 45, 220, 10)
    EVT_CALL(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 512, NPC_Muskular, MSG_MAC_Housing_00CA)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(1)
    EVT_CALL(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CB)
    EVT_CALL(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, NPC_Muskular, MSG_MAC_Housing_00CC)
    EVT_CALL(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CD)
    EVT_CALL(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, NPC_Muskular, MSG_MAC_Housing_00CE)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CF)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -450, 20, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_40000, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0x00000708)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Muskular, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, NPC_Muskular, SOUND_2045, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(115)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -450, 20, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcSpeed, NPC_Twink, 4)
    EVT_CALL(NpcFlyTo, NPC_Twink, -480, 40, 270, 0, 10, EASING_LINEAR)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D0)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_WAIT(30)
    EVT_CALL(NpcFacePlayer, NPC_Twink, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Question)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D2)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(NpcFlyTo, NPC_Twink, -600, 200, 350, 0, -10, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Twink, 0, -1000, 0)
    EVT_SET(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_04_ENTRY_5)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Muskular)))
        EVT_EXEC(N(D_80246D94_849964))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink2) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, mac_04_ENTRY_5)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(D_80247BD4_84A7A4)[] = {
    {  -70.0,   106.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {    0.0,     0.0,    0.0 },
};

Vec3f N(D_80247BF8_84A7C8)[] = {
    {    0.0,     0.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {  -70.0,   106.0,    0.0 },
};

EvtScript N(EVS_NpcIdle_Twink) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PushSong, 112, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Bridge_008F, 160, 40)
    EVT_CALL(GetPlayerPos, LVar4, LVar5, LVar6)
    EVT_SUBF(LVar4, EVT_FLOAT(50.0))
    EVT_ADDF(LVar5, EVT_FLOAT(40.0))
    EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
    EVT_CALL(LoadPath, 35, EVT_PTR(N(D_80247BD4_84A7A4)), 3, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), -10, -300, 15, -9)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0090)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(15)
    EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0091)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002D)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0092)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), -40, -200, 15, -15)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0093)
    EVT_WAIT(5)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 35, EVT_PTR(N(D_80247BF8_84A7C8)), 3, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_ADD(LVar3, LVar6)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Twink, 0, -1000, 0)
    EVT_CALL(PopSong)
    EVT_SET(GB_StoryProgress, STORY_CH4_MET_WITH_TWINK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink1) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Twink)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802480E0_84ACB0) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_B0000021, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248128_84ACF8) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hu, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 3)
        EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 90)
    EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802481E0_84ADB0) = {
    EVT_SET(LVar0, 90)
    EVT_LOOP(20)
        EVT_ADD(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hu, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248298_84AE68) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hk, SOUND_1AB, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(36)
        EVT_ADD(LVar0, 10)
        EVT_CALL(RotateModel, MODEL_hkai1, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_hkai2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_CALL(RotateModel, MODEL_hkai1, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_hkai2, LVar0, 0, 1, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hk, SOUND_1AC, 0)
    EVT_CALL(PlaySound, SOUND_A)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802483B8_84AF88) = {
    EVT_WAIT(20)
    EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_01, NPC_FLAG_100, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 5, MSG_MAC_Housing_00B3)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim03)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim04)
    EVT_WAIT(4)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -440, 3, 50)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 180, 10)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 0, 10)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 180, 10)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 0, 10)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 5, MSG_MAC_Housing_00B4)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim08)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim09)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim0A)
    EVT_EXEC(N(D_80248298_84AE68))
    EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_01, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, -440, 20, -75, 20)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        EVT_SET(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        EVT_EXEC_WAIT(N(D_80242E08_8459D8))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248624_84B1F4) = {
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_203E, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_ShyGuy_01, EMOTE_EXCLAMATION, 0, 20, TRUE, 0, 0, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 0, MSG_MAC_Housing_00B2)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 180, 10)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim03)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim04)
    EVT_WAIT(4)
    EVT_EXEC_WAIT(N(D_80248128_84ACF8))
    EVT_SET(LVar0, 14)
    EVT_EXEC_GET_TID(N(D_802480E0_84ACB0), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -501, 223, 15)
    EVT_KILL_THREAD(LVarA)
    EVT_EXEC_WAIT(N(D_802481E0_84ADB0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248798_84B368) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_IF_NE(GB_StoryProgress, STORY_CH4_MET_WITH_TWINK)
        EVT_RETURN
    EVT_END_IF
    EVT_LOOP(150)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar2, 200)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar7, 0)
    EVT_LOOP(0)
        EVT_CALL(N(IsPartnerBow))
        EVT_IF_NE(LVar0, 0)
            EVT_SET(LVar7, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar2, 100)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_GT(LVar2, 200)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(D_80248128_84ACF8))
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, -501, 20, 223)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -506, 168, 15)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    EVT_EXEC_WAIT(N(D_802481E0_84ADB0))
    EVT_IF_EQ(LVar7, 1)
        EVT_EXEC_WAIT(N(D_802483B8_84AF88))
    EVT_ELSE
        EVT_EXEC_WAIT(N(D_80248624_84B1F4))
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_THREAD
            EVT_WAIT(10)
            EVT_EXEC(N(D_80248798_84B368))
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, 0, -1000, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248A14_84B5E4) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy_02, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_VIS_GROUP(ITEM_STOREROOM_KEY, VIS_GROUP_1), LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(30)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_02, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80248B08) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_GOT_STOREROOM_KEY)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC04_StoreroomKeyStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_ShyGuy_02, 250, 20, -402)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0000)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(20)
        EVT_SET(LVar0, 0)
        EVT_LOOP(36)
            EVT_CALL(InterpPlayerYaw, LVar0, 0)
            EVT_ADD(LVar0, 45)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(InterpPlayerYaw, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(23)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_mu, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_mu, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_END_THREAD
    EVT_EXEC(N(D_80248A14_84B5E4))
    EVT_SET(LVar0, 15)
    EVT_EXEC_GET_TID(N(D_802480E0_84ACB0), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_02, 254, -66, 30)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_02, 0, -1000, 0)
    EVT_SET(GF_MAC04_StoreroomKeyStolen, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    EVT_RETURN
    EVT_END
};

s32 N(D_80248E24_84B9F4)[] = {
    ITEM_STOREROOM_KEY,
    ITEM_NONE 
};

EvtScript N(EVS_NpcInteract_HarryT) = {
    EVT_SET(LVar9, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_SET(LVar9, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar9, 1)
        EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0001)
        EVT_SET(LVar0, EVT_PTR(N(D_80248E24_84B9F4)))
        EVT_SET(LVar1, 0)
        EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0002)
            EVT_CASE_EQ(0)
            EVT_CASE_DEFAULT
                EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0003)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100 | NPC_FLAG_GRAVITY, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Run)
                EVT_CALL(NpcMoveTo, NPC_HarryT, 295, -460, 0)
                EVT_CALL(NpcMoveTo, NPC_HarryT, 230, -480, 0)
                EVT_CALL(NpcJump0, NPC_HarryT, 198, 30, -480, 0)
                EVT_CALL(NpcJump0, NPC_HarryT, 162, 40, -480, 0)
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
                EVT_WAIT(20)
                EVT_EXEC(N(EVS_8024F24C))
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Run)
                EVT_CALL(NpcMoveTo, NPC_HarryT, 200, -524, 0)
                EVT_CALL(SetNpcPos, NPC_HarryT, 200, 30, -524)
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
                EVT_CALL(InterpNpcYaw, NPC_HarryT, 180, 0)
                EVT_CALL(PlayerFaceNpc, NPC_HarryT, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0005)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100 | NPC_FLAG_GRAVITY, FALSE)
                EVT_SET(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_EXEC_WAIT(ItemShopInteract)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HarryT) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HarryT)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/GetPlayerCoins.inc.c"

API_CALLABLE(N(func_802419E4_8445B4)) {
    Bytecode* args = script->ptrReadPos;
    s32 out1 = *args++;
    s32 out2 = *args++;
    s32 out3 = *args++;

    evt_set_variable(script, out1, gPlayerData.hardMaxHP);
    evt_set_variable(script, out2, gPlayerData.hardMaxFP);
    evt_set_variable(script, out3, gPlayerData.maxBP);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241A64_844634)) {
    PlayerData* playerData = &gPlayerData;
    s32 bp = 0;
    s32 fp = 0;
    s32 hp = 0;

    switch (script->varTable[10]) {
        case 0:
            hp = 10;
            fp = -5;
            bp = -3;
            break;
        case 1:
            hp = -5;
            fp = 10;
            bp = -3;
            break;
        case 2:
            hp = -5;
            fp = -5;
            bp = 6;
            break;
    }

    playerData->hardMaxHP += hp;
    playerData->curMaxHP += hp;
    if (playerData->curMaxHP > 75) {
        playerData->curMaxHP = 75;
    }
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    playerData->hardMaxFP += fp;
    playerData->curMaxFP += fp;
    if (playerData->curMaxFP > 75) {
        playerData->curMaxFP = 75;
    }
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    playerData->maxBP += bp;
    if (playerData->maxBP > 30) {
        playerData->maxBP = 30;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241B90_844760)) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = playerData->curMaxHP;
    script->varTable[1] = playerData->curMaxFP;
    script->varTable[2] = playerData->maxBP;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetNpcShadowScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(80241C20_8447F0)) {
    func_800E9894();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241C40_844810)) {
    func_800E98C4();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241C60_844830)) {
    func_800E98C4();
    open_status_menu_long();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_ChetRippo) = {
    EVT_IF_EQ(GF_MAC04_Met_ChetRippo, FALSE)
        EVT_SET(LVar0, MSG_MAC_Housing_00A8)
        EVT_SET(GF_MAC04_Met_ChetRippo, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Housing_00A9)
    EVT_END_IF
    EVT_CALL(N(80241C20_8447F0))
    EVT_CALL(SpeakToPlayer, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, LVar0)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_000E)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AA)
        EVT_CALL(N(func_80241C40_844810))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetPlayerCoins))
    EVT_IF_LT(LVar0, 39)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AB)
        EVT_CALL(N(func_80241C40_844810))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(func_80241B90_844760))
    EVT_CALL(SetMessageValue, LVar0, 0)
    EVT_CALL(SetMessageValue, LVar1, 1)
    EVT_CALL(SetMessageValue, LVar2, 2)
    EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AC)
    EVT_CALL(ShowChoice, MSG_Choice_000B)
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AD)
        EVT_CALL(N(func_80241C40_844810))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar2, 0)
    EVT_CALL(N(func_802419E4_8445B4), LVar3, LVar4, LVar5)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_GT(LVar3, 40)
                EVT_SET(LVar2, 1)
            EVT_END_IF
            EVT_SET(LVar1, 0x001D00D1)
        EVT_CASE_EQ(1)
            EVT_IF_GT(LVar4, 40)
                EVT_SET(LVar2, 1)
            EVT_END_IF
            EVT_SET(LVar1, 0x001D00D2)
        EVT_CASE_EQ(2)
            EVT_IF_GT(LVar5, 24)
                EVT_SET(LVar2, 1)
            EVT_END_IF
            EVT_SET(LVar1, 0x001D00D3)
    EVT_END_SWITCH
    EVT_SET(LVarA, LVar0)
    EVT_IF_EQ(LVar2, 1)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00B1)
        EVT_CALL(N(func_80241C40_844810))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AddCoin, -39)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(SetMessageMsg, LVar1, 0)
    EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AE)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_Spread)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_ChetRippo, SOUND_24B, 0)
    EVT_CALL(GetNpcPos, NPC_ChetRippo, LVar6, LVar7, LVar8)
    EVT_ADD(LVar7, 26)
    EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 0, LVar6, LVar7, LVar8, 1, 60)
    EVT_CALL(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_ShakeSlow)
    EVT_WAIT(80)
    EVT_CALL(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_Idle)
    EVT_CALL(N(func_80241A64_844634))
    EVT_CALL(N(func_802418AC_84447C), LVar6)
    EVT_IF_EQ(LVar6, 0)
        EVT_SET(LVar7, MSG_MAC_Housing_00AF)
    EVT_ELSE
        EVT_SET(LVar7, MSG_MAC_Housing_00B0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, LVar7)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_ChetRippo, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, NPC_ChetRippo, SOUND_2098, 0)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    EVT_CALL(SetNpcPos, NPC_ChetRippo, 0, -1000, 0)
    EVT_SET(AF_MAC_32, TRUE)
    EVT_CALL(N(func_80241C60_844830))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ChetRippo) = {
    EVT_IF_EQ(AF_MAC_32, FALSE)
        EVT_SET(LVar0, 0)
        EVT_CALL(N(func_802419E4_8445B4), LVar1, LVar2, LVar3)
        EVT_IF_LE(LVar1, 5)
            EVT_SET(LVar0, 1)
        EVT_END_IF
        EVT_IF_LE(LVar2, 5)
            EVT_SET(LVar0, 1)
        EVT_END_IF
        EVT_IF_LE(LVar3, 3)
            EVT_SET(LVar0, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 38, 52)
        EVT_CALL(N(SetNpcShadowScale), -1, EVT_FLOAT(2.0))
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_DIRTY_SHADOW, TRUE)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ChetRippo)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0006)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0007)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0008)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0009)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_000A)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_000B)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_000C)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_000D)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_000E)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_000F)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0010)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0011)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_0012)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_01) = {
    EVT_SET(AF_MAC_2D, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0013)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0014)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0015)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0016)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0017)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0018)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_0019)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_001A)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_001B)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_001C)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_001D)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_001E)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_001F)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_02) = {
    EVT_SET(AF_MAC_2E, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0020)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0021)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0022)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0023)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0024)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0025)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_0026)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0027)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_0028)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0029)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_002A)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_002B)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_002C)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_002D)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_002E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_002F)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0030)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0031)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0032)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_0033)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0034)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_0035)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0036)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0037)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0038)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_0039)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadKid_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_003A)
                EVT_SET(LVar1, MSG_MAC_Housing_003B)
                EVT_SET(LVar2, MSG_MAC_Housing_003C)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_003D)
                EVT_SET(LVar1, MSG_MAC_Housing_003E)
                EVT_SET(LVar2, MSG_MAC_Housing_003F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0040)
            EVT_SET(LVar1, MSG_MAC_Housing_0041)
            EVT_SET(LVar2, MSG_MAC_Housing_0042)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0043)
                EVT_SET(LVar1, MSG_MAC_Housing_0044)
                EVT_SET(LVar2, MSG_MAC_Housing_0045)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0046)
                EVT_SET(LVar1, MSG_MAC_Housing_0047)
                EVT_SET(LVar2, MSG_MAC_Housing_0048)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0049)
            EVT_SET(LVar1, MSG_MAC_Housing_004A)
            EVT_SET(LVar2, MSG_MAC_Housing_004B)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_004C)
            EVT_SET(LVar1, MSG_MAC_Housing_004D)
            EVT_SET(LVar2, MSG_MAC_Housing_004E)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_004F)
            EVT_SET(LVar1, MSG_MAC_Housing_0050)
            EVT_SET(LVar2, MSG_MAC_Housing_0051)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_0052)
            EVT_SET(LVar1, MSG_MAC_Housing_0053)
            EVT_SET(LVar2, MSG_MAC_Housing_0054)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0055)
            EVT_SET(LVar1, MSG_MAC_Housing_0056)
            EVT_SET(LVar2, MSG_MAC_Housing_0057)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0058)
            EVT_SET(LVar1, MSG_MAC_Housing_0059)
            EVT_SET(LVar2, MSG_MAC_Housing_005A)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_005B)
            EVT_SET(LVar1, MSG_MAC_Housing_005C)
            EVT_SET(LVar2, MSG_MAC_Housing_005D)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_005E)
            EVT_SET(LVar1, MSG_MAC_Housing_005F)
            EVT_SET(LVar2, MSG_MAC_Housing_0060)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_01, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle, 0, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar1)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_03, ANIM_ToadKid_Green_Talk, ANIM_ToadKid_Green_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0061)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0062)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0063)
        EVT_CASE_LT(STORY_CH4_ENTERED_THE_TOY_BOX)
            EVT_SET(LVar0, MSG_MAC_Housing_0064)
        EVT_CASE_LT(STORY_CH4_GOT_STOREROOM_KEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0065)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0066)
        EVT_CASE_LT(STORY_CH4_GOT_FRYING_PAN)
            EVT_SET(LVar0, MSG_MAC_Housing_0067)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MAC_Housing_0068)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_CALL(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Housing_0069)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Housing_006B)
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_006A)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_006C)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_006D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_006E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_006F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0070)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0071)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0072)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_0073)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPIRIT_RESCUED, STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, -300, 0, 325)
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0074)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0075)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0076)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0077)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0078)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0079)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_007A)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_007B)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_007C)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_007D)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_007E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_007F)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_0080)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0081)
                EVT_SET(LVar1, MSG_MAC_Housing_0082)
                EVT_SET(LVar2, MSG_MAC_Housing_0083)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0084)
                EVT_SET(LVar1, MSG_MAC_Housing_0085)
                EVT_SET(LVar2, MSG_MAC_Housing_0086)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0087)
            EVT_SET(LVar1, MSG_MAC_Housing_0088)
            EVT_SET(LVar2, MSG_MAC_Housing_0089)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_008A)
                EVT_SET(LVar1, MSG_MAC_Housing_008B)
                EVT_SET(LVar2, MSG_MAC_Housing_008C)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_008D)
                EVT_SET(LVar1, MSG_MAC_Housing_008E)
                EVT_SET(LVar2, MSG_MAC_Housing_008F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0090)
            EVT_SET(LVar1, MSG_MAC_Housing_0091)
            EVT_SET(LVar2, MSG_MAC_Housing_0092)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_0093)
            EVT_SET(LVar1, MSG_MAC_Housing_0094)
            EVT_SET(LVar2, MSG_MAC_Housing_0095)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0096)
            EVT_SET(LVar1, MSG_MAC_Housing_0097)
            EVT_SET(LVar2, MSG_MAC_Housing_0098)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_0099)
            EVT_SET(LVar1, MSG_MAC_Housing_009A)
            EVT_SET(LVar2, MSG_MAC_Housing_009B)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_009C)
            EVT_SET(LVar1, MSG_MAC_Housing_009D)
            EVT_SET(LVar2, MSG_MAC_Housing_009E)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_009F)
            EVT_SET(LVar1, MSG_MAC_Housing_00A0)
            EVT_SET(LVar2, MSG_MAC_Housing_00A1)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_00A2)
            EVT_SET(LVar1, MSG_MAC_Housing_00A3)
            EVT_SET(LVar2, MSG_MAC_Housing_00A4)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_00A5)
            EVT_SET(LVar1, MSG_MAC_Housing_00A6)
            EVT_SET(LVar2, MSG_MAC_Housing_00A7)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar1)
    EVT_CALL(SpeakToPlayer, NPC_Toad_06, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goomama) = {
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_GOOMBARIO)
        EVT_CALL(DisablePartnerAI, 1)
        EVT_IF_EQ(GF_MAC04_HeardGoombaFamilyArgument, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B6)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00B7)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B8)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00B9)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00BA)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00BB)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00BC)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00BD)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00BE)
            EVT_SET(GF_MAC04_HeardGoombaFamilyArgument, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00BF)
        EVT_END_IF
        EVT_CALL(EnablePartnerAI)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B5)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goombaria) = {
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_GOOMBARIO)
        EVT_CALL(DisablePartnerAI, 1)
        EVT_IF_EQ(AF_MAC_30, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C1)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00C2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C3)
            EVT_SET(AF_MAC_30, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C4)
        EVT_END_IF
        EVT_CALL(EnablePartnerAI)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomama) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goomama)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goombaria)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_ChetRippo)[] = {
    {
        .id = NPC_ChetRippo,
        .settings = &N(NpcSettings_ChetRippo),
        .pos = { 410.0f, 20.0f, -200.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_ChetRippo),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ChetRippo_Idle,
        },
        .tattle = MSG_NpcTattle_ChetRippo,
    },
    {
        .id = NPC_HarryT,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 310.0f, 20.0f, -430.0f },
        .yaw = 230,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_HarryT),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .tattle = MSG_NpcTattle_HarryT_ShopOwner,
    },
    {
        .id = NPC_ThreeSisters_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -80.0f, 20.0f, -100.0f },
        .yaw = 133,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ThreeSisters_01),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewResidentA,
    },
    {
        .id = NPC_ThreeSisters_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -133.0f, 20.0f, -82.0f },
        .yaw = 133,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ThreeSisters_02),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewResidentB,
    },
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_Wander),
        .pos = { 48.0f, 0.0f, 153.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_01),
        .drops = TOAD_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 48, 0, 153 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 48, 0, 153 },
                .detectSize = { 10 },
            }
        },
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_TalksAlot,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -239.0f, 20.0f, 105.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_02),
        .drops = TOAD_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_WaryListener,
    },
    {
        .id = NPC_ToadKid_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 254.0f, 20.0f, 436.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ToadKid_01),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_CarefreeKids,
    },
    {
        .id = NPC_ToadKid_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 304.0f, 20.0f, 410.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ToadKid_02),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_OutdoorKids,
    },
    {
        .id = NPC_ToadKid_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 345.0f, 20.0f, 438.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ToadKid_03),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShyKid,
    },
    {
        .id = NPC_ThreeSisters_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -274.0f, 0.0f, 400.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ThreeSisters_03),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .tattle = MSG_NpcTattle_ToadWhoWalks,
    },
    {
        .id = NPC_Toad_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 500.0f, 20.0f, -160.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_03),
        .drops = TOAD_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GuideToad,
    },
    {
        .id = NPC_Toad_04,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -110.0f, 0.0f, 568.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_04),
        .drops = TOAD_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioA,
    },
    {
        .id = NPC_Toad_05,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -114.0f, 0.0f, 498.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_05),
        .drops = TOAD_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioB,
    },
    {
        .id = NPC_Toad_06,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -52.0f, 0.0f, 525.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_06),
        .drops = TOAD_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioC,
    },
};

s32 N(D_8024CCF8_84F8C8)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Talk,
    -1
};

StaticNpc N(NpcData_Twink)[] = {
    {
        .id = NPC_Twink,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Twink1),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Twink_Idle,
            .walk   = ANIM_Twink_Fly,
            .run    = ANIM_Twink_Angry,
            .chase  = ANIM_Twink_Angry,
            .anim_4 = ANIM_Twink_Idle,
            .anim_5 = ANIM_Twink_Idle,
            .death  = ANIM_Twink_Idle,
            .hit    = ANIM_Twink_Idle,
            .anim_8 = ANIM_Twink_Idle,
            .anim_9 = ANIM_Twink_Idle,
            .anim_A = ANIM_Twink_Idle,
            .anim_B = ANIM_Twink_Idle,
            .anim_C = ANIM_Twink_Idle,
            .anim_D = ANIM_Twink_Idle,
            .anim_E = ANIM_Twink_Idle,
            .anim_F = ANIM_Twink_Idle,
        },
        .extraAnimations = N(D_8024CCF8_84F8C8),
    },
    {
        .id = NPC_ShyGuy_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ShyGuy_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
};

StaticNpc N(NpcData_Muskular)[] = {
    {
        .id = NPC_Muskular,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { -486.0f, 20.0f, 259.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_Muskular),
        .drops = MUSKULAR_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_Twink,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_Twink2),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Twink_Idle,
            .walk   = ANIM_Twink_Fly,
            .run    = ANIM_Twink_Angry,
            .chase  = ANIM_Twink_Angry,
            .anim_4 = ANIM_Twink_Idle,
            .anim_5 = ANIM_Twink_Idle,
            .death  = ANIM_Twink_Idle,
            .hit    = ANIM_Twink_Idle,
            .anim_8 = ANIM_Twink_Idle,
            .anim_9 = ANIM_Twink_Idle,
            .anim_A = ANIM_Twink_Idle,
            .anim_B = ANIM_Twink_Idle,
            .anim_C = ANIM_Twink_Idle,
            .anim_D = ANIM_Twink_Idle,
            .anim_E = ANIM_Twink_Idle,
            .anim_F = ANIM_Twink_Idle,
        },
    },
};

StaticNpc N(NpcData_Goomama)[] = {
    {
        .id = NPC_Goomama,
        .settings = &N(NpcSettings_Goomba_Family),
        .pos = { -126.0f, 0.0f, 329.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Goomama),
        .drops = GOOMAMA_DROPS,
        .animations = GOOMAMA_ANIMS,
        .tattle = MSG_NpcTattle_Goomama,
    },
    {
        .id = NPC_Goombaria,
        .settings = &N(NpcSettings_Goomba_Family),
        .pos = { -117.0f, 0.0f, 305.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Goombaria),
        .drops = GOOMBARIA_DROPS,
        .animations = GOOMBARIA_ANIMS,
        .tattle = MSG_NpcTattle_Goombaria,
    },
};

StaticNpc N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .settings = &N(Quizmo_NpcSettings),
    .pos = { 57.0f, 20.0f, -114.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_4000,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_04 }},
    .drops = QUIZMO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ChetRippo)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(Chapter4NPCs) = {
    NPC_GROUP(N(NpcData_ChetRippo)),
    NPC_GROUP(N(NpcData_Twink)),
    {}
};

NpcGroupList N(Chapter5NPCs) = {
    NPC_GROUP(N(NpcData_ChetRippo)),
    NPC_GROUP(N(NpcData_Muskular)),
    {}
};

NpcGroupList N(Chapter7NPCs) = {
    NPC_GROUP(N(NpcData_ChetRippo)),
    NPC_GROUP(N(NpcData_Goomama)),
    {}
};
