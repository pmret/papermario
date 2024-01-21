#include "dro_01.h"
#include "world/common/util/MonitorPlayerOrbiting.h"
#include "sprite/player.h"

API_CALLABLE(N(SaveSpinningRoofHintTime)) {
    PlayerData* playerData = &gPlayerData;

    playerData->droTreeHintTime = playerData->frameCounter;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetFloorCollider)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_TreeOrbitReaction) = {
    Loop(0)
        Call(N(GetFloorCollider), LVar0)
        IfEq(LVar0, COLLIDER_ground)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(func_802CF56C, 1)
    Thread
        Wait(20)
        Call(func_802CF56C, 0)
        Call(NpcFacePlayer, NPC_PARTNER, 0)
    EndThread
    Call(PlayerFaceNpc, NPC_Dryite_03, FALSE)
    Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0078)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Dryite_03, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    AddF(LVar0, LVar3)
    AddF(LVar1, LVar4)
    AddF(LVar2, LVar5)
    DivF(LVar0, Float(2.0))
    DivF(LVar1, Float(2.0))
    DivF(LVar2, Float(2.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(-300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0079)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(30)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007A)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(N(SaveSpinningRoofHintTime))
    Set(GF_DRO01_HeardHintAboutSpinningRoof, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

void N(red_tree_orbit_listener)(PlayerOrbitState* orbit, s32 event) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (event) {
        case PLAYER_ORBIT_CONTINUE_ORBIT:
            if (orbit->numRotations >= 6) {
                // wait to be near NPC with at least 6 full rotations complete
                f32 angle1 = atan2(125.0f, -42.0f, 152.0f, -61.0f);
                f32 angle2 = atan2(125.0f, -42.0f, playerStatus->pos.x, playerStatus->pos.z);
                f32 deltaAngle = get_clamped_angle_diff(angle1, angle2);
                if (fabsf(deltaAngle) < 30.0f) {
                    start_script(&N(EVS_Scene_TreeOrbitReaction), EVT_PRIORITY_1, 0);
                    orbit->state = ORBIT_STATE_BREAK_ORBIT;
                }
            }
            break;

        case PLAYER_ORBIT_BEGIN:
        case PLAYER_ORBIT_COMPLETE_ROTATION:
        case PLAYER_ORBIT_CHANGE_DIRECTION:
        case PLAYER_ORBIT_LEFT_REGION:
            break;
    }
}

API_CALLABLE(N(HasBeenHalfHourSinceTreeOrbit)) {
    PlayerData* playerData = &gPlayerData;
    s32 minutes = (playerData->frameCounter - playerData->droTreeHintTime) / 3600;

    if (minutes < 30) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    return ApiStatus_DONE2;
}

PlayerOrbitTarget N(RunAroundTarget) = {
    .pos = { 125, 0, -42 },
    .startRadius = 75,
    .orbitRadius = 75,
    .eventListener = N(red_tree_orbit_listener),
};

EvtScript N(EVS_NpcInteract_HintDryite) = {
    IfEq(GF_MAC01_Merlon_HeardAboutDream, TRUE)
        IfEq(GF_DRO01_HeardHintAboutSpinningRoof, TRUE)
            // in case the player forgets, remind them after a half hour
            Call(N(HasBeenHalfHourSinceTreeOrbit))
            IfEq(LVar0, TRUE)
                Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007B)
                Return
            EndIf
        EndIf
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(AF_DRO_01, FALSE)
                Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006C)
                Call(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006D)
                Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006E)
                Set(AF_DRO_01, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006F)
                Call(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0070)
                Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0071)
                Set(AF_DRO_01, FALSE)
            EndIf
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0072)
            Call(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0073)
            Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0074)
        CaseDefault
            Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0075)
            Call(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0076)
            Call(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0077)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_HintDryite) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(dro_01_ENTRY_3)
        CaseOrEq(dro_01_ENTRY_4)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            Return
        EndCaseGroup
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_HintDryite)))
    IfEq(GF_MAC01_Merlon_HeardAboutDream, TRUE)
        Thread
            Call(N(MonitorPlayerOrbiting), Ref(N(RunAroundTarget)))
        EndThread
    EndIf
    Return
    End
};
