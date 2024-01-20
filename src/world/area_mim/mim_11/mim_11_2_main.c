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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, -800, 0, 0)
    Call(SetNpcPos, NPC_PARTNER, -800, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamType, CAM_DEFAULT, 1, TRUE)
    Call(SetCamPitch, CAM_DEFAULT, Float(40.0), Float(-63.59375))
    Call(SetCamDistance, CAM_DEFAULT, 720)
    Call(SetCamPosA, CAM_DEFAULT, 89, 84)
    Call(SetCamPosB, CAM_DEFAULT, 89, 84)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 75, 0, 309)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(N(func_8024066C_BB76DC))
    Wait(30)
    ChildThread
        Call(N(func_80240790_BB7800))
        Wait(90)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, -350)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        EndLoop
    EndChildThread
    Wait(50)
    Call(SetPlayerPos, -701, 0, -34)
    Call(SetNpcPos, NPC_PARTNER, -701, 0, -34)
    Call(DisablePlayerPhysics, FALSE)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(PlayerMoveTo, -407, 103, 120)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    Wait(10)
    Thread
        Wait(15)
        Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EndThread
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH3_0024)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_CH3_0025)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 5, MSG_CH3_0026)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_CH3_0027)
    EndSwitch
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

// interesting broken, unused snippet for starting next peach sequence
EvtScript N(EVS_ExitWarp_osr_03_4) = {
    Call(FadeOutMusic, 0, 1500)
    Call(GotoMapSpecial, Ref("osr_03"), osr_03_ENTRY_4, 0xB)
    Wait(100)
};

EvtScript N(EVS_ExitWalk_mim_07_3) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, mim_11_ENTRY_0)
    Exec(ExitWalk)
    Set(GF_MIM_ChoosingPath, FALSE)
    Call(GotoMap, Ref("mim_07"), mim_07_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_mim_12_0) = EVT_EXIT_WALK(60, mim_11_ENTRY_1, "mim_12", mim_12_ENTRY_0);

EvtScript N(EVS_ExitWalk_obk_01_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, mim_11_ENTRY_2)
    Set(LVar1, COLLIDER_ttd)
    Set(LVar2, MODEL_doa)
    Set(LVar3, MODEL_o166)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_01"), obk_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mim_07_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mim_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_obk_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttd, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(AF_MIM_01, TRUE)
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_11_ENTRY_0)
            Set(AF_MIM_01, FALSE)
            IfLt(GB_StoryProgress, STORY_CH3_ARRIVED_AT_BOOS_MANSION)
                Set(GB_StoryProgress, STORY_CH3_ARRIVED_AT_BOOS_MANSION)
                ExecWait(N(EVS_Scene_ReachedMansion))
                Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 0)
                Exec(N(EVS_BindExitTriggers))
            Else
                Set(LVar0, Ref(N(EVS_BindExitTriggers)))
                Exec(EnterWalk)
            EndIf
        CaseEq(mim_11_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_11_ENTRY_2)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_doa)
            Set(LVar3, MODEL_o166)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(mim_11_ENTRY_3)
            IfEq(GF_MIM11_WarpPipe, FALSE)
                Call(DisablePlayerInput, TRUE)
                Call(DisablePlayerPhysics, TRUE)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                Wait(30)
                Call(PlaySound, SOUND_GROW)
                Set(GF_MIM11_WarpPipe, TRUE)
                Wait(30)
                Call(SetPlayerActionState, ACTION_STATE_IDLE)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(DisablePlayerPhysics, FALSE)
                Call(DisablePlayerInput, FALSE)
            EndIf
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            ExecWait(N(EVS_Pipe_EnterVertical))
        CaseEq(mim_11_ENTRY_4)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(mim_11_ENTRY_5)
            Call(InterpPlayerYaw, 227, 0)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Set(GF_MAP_BoosMansion, TRUE)
    Call(SetSpriteShading, SHADING_MIM_11)
    SetUP_CAMERA_NO_LEAD()
    Call(EnableGroup, MODEL_g62, FALSE)
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(D_802430E0_BBA150))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Call(N(func_802405EC_BB765C))
    Return
    End
};
