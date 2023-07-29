#include "osr_03.h"
#include "effects.h"

API_CALLABLE(N(SetPlayerAsPeach)) {
    gGameStatusPtr->peachFlags |= PEACH_STATUS_FLAG_IS_PEACH;
    script->varTable[0] = gPlayerData.curPartner;
    gPlayerData.curPartner = PARTNER_TWINK;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetKammyFlightEmitterPos)) {
    Npc* npc = get_npc_unsafe(NPC_Kammy);

    script->varTable[0] = npc->pos.x + (sin_deg(npc->yaw + gCameras[CAM_DEFAULT].curYaw + 180.0f) * 20.0f);
    script->varTable[1] = npc->pos.y + 18.0f;
    script->varTable[2] = npc->pos.z - (cos_deg(npc->yaw + gCameras[CAM_DEFAULT].curYaw + 180.0f) * 20.0f);
    return ApiStatus_DONE2;
}

Vec3f N(KammyFlightPath1)[] = {
    { -700.0,  -370.0, 1600.0 },
    { -750.0,  -450.0, 1550.0 },
    { -700.0,  -530.0, 1550.0 },
    { -630.0,  -550.0, 1550.0 },
};

Vec3f N(KammyFlightPath2)[] = {
    { -630.0,  -550.0, 1550.0 },
    { -430.0,  -520.0, 1525.0 },
    { -350.0,  -430.0, 1500.0 },
    { -100.0,  -100.0, 1000.0 },
    {    0.0,     0.0,  500.0 },
    {    0.0,     0.0,    0.0 },
};

EvtScript N(EVS_PlayKammyFlightFX) = {
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 110)
        EVT_LOOP(0)
            EVT_CALL(PlaySoundWithVolume, SOUND_295, LVar0)
            EVT_ADD(LVar0, -2)
            EVT_IF_LT(LVar0, 10)
                EVT_SET(LVar0, 10)
            EVT_END_IF
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    EVT_LOOP(0)
        EVT_CALL(N(GetKammyFlightEmitterPos))
        EVT_CALL(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        EVT_SET(LVar3, LVar9)
        EVT_SET(LVar4, LVarA)
        EVT_SET(LVar5, LVarB)
        EVT_SUB(LVar3, LVar6)
        EVT_SUB(LVar4, LVar7)
        EVT_SUB(LVar5, LVar8)
        EVT_SET(LVar6, LVar9)
        EVT_SET(LVar7, LVarA)
        EVT_SET(LVar8, LVarB)
        EVT_IF_EQ(LVar3, 0)
            EVT_IF_EQ(LVar5, 0)
            EVT_ELSE
                EVT_PLAY_EFFECT(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
            EVT_END_IF
        EVT_ELSE
            EVT_PLAY_EFFECT(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
        EVT_END_IF
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KammyReturnsToCastle) = {
    EVT_WAIT(30)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFacePlayer, NPC_Kammy, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(EVS_PlayKammyFlightFX), LVar9)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim1A)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(KammyFlightPath1)), ARRAY_COUNT(N(KammyFlightPath1)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(LoadPath, 150, EVT_PTR(N(KammyFlightPath2)), ARRAY_COUNT(N(KammyFlightPath2)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BeginInterlude) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(EnableGroup, MODEL_hiru, FALSE)
    EVT_CALL(EnableGroup, MODEL_niwa, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimidori, FALSE)
    EVT_CALL(EnableGroup, MODEL_kumo, FALSE)
    EVT_CALL(EnableGroup, MODEL_ki1, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimen, FALSE)
    EVT_CALL(EnableGroup, MODEL_kemuri, FALSE)
    EVT_CALL(EnableGroup, MODEL_obj, FALSE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-13.0), EVT_FLOAT(18.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_CastleLiftDist, 0)
    EVT_EXEC(N(EVS_AnimateSwingingChains))
    EVT_EXEC(N(EVS_AnimateSpinningRing))
    EVT_WAIT(30)
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_EXEC_WAIT(N(EVS_KammyReturnsToCastle))
    EVT_END_IF
    EVT_WAIT(80)
    EVT_CALL(N(SetPlayerAsPeach))
    EVT_SET(GB_KKJ_LastPartner, LVar0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
            EVT_CALL(GotoMap, EVT_PTR("kkj_15"), kkj_15_ENTRY_2)
        EVT_CASE_LT(STORY_CH0_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_3)
        EVT_CASE_LT(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_4)
        EVT_CASE_LT(STORY_CH2_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_5)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_6)
        EVT_CASE_LT(STORY_CH4_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_7)
        EVT_CASE_LT(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_8)
        EVT_CASE_LT(STORY_CH6_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_9)
        EVT_CASE_LT(STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(GotoMap, EVT_PTR("kkj_26"), kkj_26_ENTRY_1)
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
