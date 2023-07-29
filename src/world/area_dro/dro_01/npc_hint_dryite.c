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
    EVT_LOOP(0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_EQ(LVar0, COLLIDER_ground)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, NPC_Dryite_03, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0078)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Dryite_03, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADDF(LVar0, LVar3)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_DIVF(LVar0, EVT_FLOAT(2.0))
    EVT_DIVF(LVar1, EVT_FLOAT(2.0))
    EVT_DIVF(LVar2, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0079)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007A)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(N(SaveSpinningRoofHintTime))
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
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
    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, TRUE)
        EVT_IF_EQ(GF_DRO01_HeardHintAboutSpinningRoof, TRUE)
            // in case the player forgets, remind them after a half hour
            EVT_CALL(N(HasBeenHalfHourSinceTreeOrbit))
            EVT_IF_EQ(LVar0, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_01, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006C)
                EVT_CALL(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006D)
                EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006E)
                EVT_SET(AF_DRO_01, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006F)
                EVT_CALL(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0070)
                EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0071)
                EVT_SET(AF_DRO_01, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0072)
            EVT_CALL(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0073)
            EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0074)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0075)
            EVT_CALL(SpeakToPlayer, NPC_Dryite_04, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0076)
            EVT_CALL(SpeakToPlayer, NPC_Dryite_03, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0077)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HintDryite) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(dro_01_ENTRY_3)
        EVT_CASE_OR_EQ(dro_01_ENTRY_4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HintDryite)))
    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, TRUE)
        EVT_THREAD
            EVT_CALL(N(MonitorPlayerOrbiting), EVT_PTR(N(RunAroundTarget)))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
