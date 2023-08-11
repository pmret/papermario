#include "mim_11.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(func_802405EC_BB765C)) {
    enable_world_fog();
    set_world_fog_dist(960, 1000);
    set_world_fog_color(32, 30, 28, 255);

    enable_entity_fog();
    set_entity_fog_dist(990, 1000);
    set_entity_fog_color(0, 0, 0, 255);

    gCameras[CAM_DEFAULT].bgColor[0] = 24;
    gCameras[CAM_DEFAULT].bgColor[1] = 24;
    gCameras[CAM_DEFAULT].bgColor[2] = 24;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024066C_BB76DC)) {
    Camera* cam = &gCameras[gCurrentCameraID];
    s32 retVal = ApiStatus_BLOCK;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
        script->functionTemp[3] = 100;
    }

    switch (script->functionTemp[1]) {
        case 0:
            script->functionTemp[2] = script->functionTemp[2] + script->functionTemp[3];
            if (script->functionTemp[2] >= 16000) {
                script->functionTemp[1] = 1;
            }
            break;
        case 1:
            script->functionTemp[2] += script->functionTemp[3];
            script->functionTemp[3] -= 2;
            if (script->functionTemp[2] >= 18000) {
                retVal = ApiStatus_DONE2;
            }
            break;
    }
    cam->controlSettings.boomPitch = (script->functionTemp[2] * 0.0010500001f) + 40.0f;
    cam->controlSettings.viewPitch = (script->functionTemp[2] * 0.0025833333f) + -63.6f;
    return retVal;
}

API_CALLABLE(N(func_80240790_BB7800)) {
    Camera* cam = &gCameras[CAM_DEFAULT];
    f32 angle1, angle2, moveAngle;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    angle1 = atan2(89.0f, 84.0f, 75.0f, 309.0f);
    angle2 = atan2(89.0f, 84.0f, 245.0f, 85.0f);
    moveAngle = (((angle2 - angle1) / 40.0f) * script->functionTemp[1]) + angle1;
    cam->movePos.x = (s32) (sin_deg(moveAngle) * 100.0f) + 89;
    cam->movePos.z = (s32)(-cos_deg(moveAngle) * 100.0f) + 84;
    cam->panActive = TRUE;

    script->functionTemp[1]++;
    if (script->functionTemp[1] < 41) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

EvtScript N(EVS_Scene_ReachedMansion) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, -800, 0, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -800, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, TRUE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(40.0), EVT_FLOAT(-63.59375))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 720)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 89, 84)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 89, 84)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 75, 0, 309)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(func_8024066C_BB76DC))
    EVT_WAIT(30)
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80240790_BB7800))
        EVT_WAIT(90)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(50)
    EVT_CALL(SetPlayerPos, -701, 0, -34)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -701, 0, -34)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(PlayerMoveTo, -407, 103, 120)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EVT_END_THREAD
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH3_0024)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_CH3_0025)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 5, MSG_CH3_0026)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_CH3_0027)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

// interesting broken, unused snippet for starting next peach sequence
EvtScript N(EVS_ExitWarp_osr_03_4) = {
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_CALL(GotoMapSpecial, EVT_PTR("osr_03"), osr_03_ENTRY_4, 0xB)
    EVT_WAIT(100)
};

EvtScript N(EVS_ExitWalk_mim_07_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, mim_11_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_SET(GF_MIM_ChoosingPath, FALSE)
    EVT_CALL(GotoMap, EVT_PTR("mim_07"), mim_07_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_mim_12_0) = EVT_EXIT_WALK(60, mim_11_ENTRY_1, "mim_12", mim_12_ENTRY_0);

EvtScript N(EVS_ExitWalk_obk_01_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, mim_11_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_ttd)
    EVT_SET(LVar2, MODEL_doa)
    EVT_SET(LVar3, MODEL_o166)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_01"), obk_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mim_07_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mim_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_obk_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttd, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(AF_MIM_01, TRUE)
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mim_11_ENTRY_0)
            EVT_SET(AF_MIM_01, FALSE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH3_ARRIVED_AT_BOOS_MANSION)
                EVT_SET(GB_StoryProgress, STORY_CH3_ARRIVED_AT_BOOS_MANSION)
                EVT_EXEC_WAIT(N(EVS_Scene_ReachedMansion))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_ELSE
                EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
                EVT_EXEC(EnterWalk)
            EVT_END_IF
        EVT_CASE_EQ(mim_11_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(mim_11_ENTRY_2)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_doa)
            EVT_SET(LVar3, MODEL_o166)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(mim_11_ENTRY_3)
            EVT_IF_EQ(GF_MIM11_WarpPipe, FALSE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                EVT_WAIT(30)
                EVT_CALL(PlaySound, SOUND_GROW)
                EVT_SET(GF_MIM11_WarpPipe, TRUE)
                EVT_WAIT(30)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC_WAIT(N(EVS_Pipe_EnterVertical))
        EVT_CASE_EQ(mim_11_ENTRY_4)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(mim_11_ENTRY_5)
            EVT_CALL(InterpPlayerYaw, 227, 0)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_SET(GF_MAP_BoosMansion, TRUE)
    EVT_CALL(SetSpriteShading, SHADING_MIM_11)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(EnableGroup, MODEL_g62, FALSE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(D_802430E0_BBA150))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(N(func_802405EC_BB765C))
    EVT_RETURN
    EVT_END
};
