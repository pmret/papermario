#include "dgb_18.h"
#include "effects.h"
#include "sprite/player.h"

extern EvtScript N(EVS_NpcAI_Tubba_Chase);
extern EvtScript N(EVS_NpcAI_Tubba_WakeUp);

#include "world/common/enemy/TubbaBlubba_Patrol.inc.c"
#include "world/common/enemy/TubbaBlubba.inc.c"

#include "world/common/todo/UnkFunc1.inc.c"

API_CALLABLE(N(UnusedChasePlayer)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(NPC_Tubba);
    f32 posX, posZ;

    if (isInitialCall) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        npc->moveSpeed = 3.7f;
        npc->yaw = atan2(posX, posZ, playerStatus->pos.x, playerStatus->pos.z);
        script->functionTemp[1] = 0;
        npc->duration = 15;
    }

    if (script->functionTemp[1] == 0) {
        if (npc->duration == 0) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            npc->duration = 15;
        }
        npc->duration--;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    return ApiStatus_BLOCK;
}

NpcSettings N(NpcSettings_Yakkey) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_CLUBBA,
};

EvtScript N(EVS_Scene_TubbaFallsAsleep) = {
    EVT_LABEL(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 700)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_GT(LVar2, 185)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_LOOP(3)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
        EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT, 382, 0, 218)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_LOOP(2)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -40, 0, 180)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -40, 0, 180)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerPos, 740, 0, 180)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 765, 0, 180)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LookClosely)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.3))
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim09)
    EVT_CALL(SetNpcPos, NPC_SELF, -210, 0, 180)
    EVT_CALL(NpcMoveTo, NPC_SELF, -60, 180, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim06)
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 5, MSG_CH3_00F4)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim09)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.3))
            EVT_WAIT(9)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.15))
            EVT_WAIT(12)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 45, 215, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 140, 245, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 615, 245, 0)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim06)
    EVT_WAIT(15)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 5, MSG_CH3_00F5)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim14)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim15)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim16)
        EVT_WAIT(5)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_SELF, 600, 50, 115, 20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim05)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.2), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.35), EVT_FLOAT(1.15), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.45), EVT_FLOAT(1.05), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.35), EVT_FLOAT(1.15), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.2), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_SELF, LVar3, 30, LVar5, 23)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 50, 18, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotationPivot, NPC_SELF, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -90, 18, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcRotationPivot, NPC_SELF, 0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim02)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim24)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(SetSelfVar, 1, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 1, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_EXHALE, SOUND_SPACE_DEFAULT)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 15)
            EVT_CALL(ShowSleepBubble, NPC_Tubba, 0, 0, 2, 628, 121, 127, LVar1, LVar0)
            EVT_WAIT(48)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 10)
            EVT_CALL(SetSleepBubbleTimeLeft, LVar0, LVar1)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_StoryProgress, STORY_CH3_TUBBA_BEGAN_NAPPING)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Tubba_Asleep) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(SetNpcPos, NPC_SELF, 600, 50, 115)
    EVT_CALL(SetNpcRotationPivot, NPC_SELF, 0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim02)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim24)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(SetSelfVar, 1, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 1, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_EXHALE, SOUND_SPACE_DEFAULT)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 15)
            EVT_CALL(ShowSleepBubble, NPC_Tubba, 0, 0, 2, 628, 121, 127, LVar1, LVar0)
            EVT_WAIT(48)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 10)
            EVT_CALL(SetSleepBubbleTimeLeft, LVar0, LVar1)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Tubba_WakeUp) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_EXHALE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowSleepBubble, NPC_Tubba, 0, 50, 2, 552, 111, 128, 30, LVar0)
    EVT_WAIT(360)
    EVT_CALL(SetSleepBubbleTimeLeft, LVar0, 20)
    EVT_CALL(SetNpcVar, NPC_SELF, 1, 2)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SNAP_AWAKE_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim19)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(NpcJump0, NPC_SELF, 650, 0, 250, 25)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1A)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1B)
    EVT_WAIT(12)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1C)
    EVT_WAIT(5)
    EVT_CALL(BindNpcAI, NPC_Tubba, EVT_PTR(N(EVS_NpcAI_Tubba_Chase)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Tubba_Chase) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0D)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_Tubba_Patrol)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Tubba) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tubba)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_BEGAN_NAPPING)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_TubbaFallsAsleep)))
        EVT_CASE_LT(STORY_CH3_TUBBA_WOKE_UP)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tubba_Asleep)))
        EVT_CASE_LT(STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
            EVT_CALL(SetNpcPos, NPC_SELF, 245, 0, 250)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Tubba_Chase)))
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_YakkeyShouts) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 845, 0, 140)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(NpcJump1, NPC_SELF, 845, 35, 145, 15)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_WAIT(15)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 800, 245)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 5, MSG_CH3_00F6)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 5, MSG_CH3_00F7)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00F8)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00F9)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 740, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 800, 245)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_SET(MF_Sync_YakkeyDialogue, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 517, MSG_CH3_00FA)
        EVT_SET(MF_Sync_YakkeyDialogue, TRUE)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(550.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_Sync_YakkeyDialogue, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
    EVT_CALL(SetNpcVar, NPC_Tubba, 1, 1)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim25)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcVar, NPC_Tubba, 1, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(RandInt, 40, LVar0)
            EVT_CALL(RandInt, 40, LVar1)
            EVT_ADD(LVar0, 537)
            EVT_ADD(LVar1, 110)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 2, LVar0, LVar1, 128, EVT_FLOAT(0.3), 24)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim05)
    EVT_CALL(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim13, ANIM_WorldTubba_Anim05, 5, MSG_CH3_00FB)
    EVT_WAIT(15)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00FC)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00FD)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00FE)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00FF)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_0100)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(15)
    EVT_CALL(BindNpcAI, NPC_Tubba, EVT_PTR(N(EVS_NpcAI_Tubba_WakeUp)))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SUB(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH3_TUBBA_WOKE_UP)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yakkey) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_YakkeyShouts)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Tubba) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 5,
            .points  = {
                { 0, 0, 240 },
                { 175, 0, 240 },
                { 350, 0, 240 },
                { 525, 0, 240 },
                { 700, 0, 240 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 300, 0, 240 },
            .detectSize = { 1000, 250 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = TUBBA_ANGRY_ANIMS,
};

NpcData N(NpcData_Yakkey) = {
    .id = NPC_Yakkey,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Yakkey),
    .settings = &N(NpcSettings_Yakkey),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Yakkey_Idle,
        .walk   = ANIM_Yakkey_Idle,
        .run    = ANIM_Yakkey_Idle,
        .chase  = ANIM_Yakkey_Idle,
        .anim_4 = ANIM_Yakkey_Idle,
        .anim_5 = ANIM_Yakkey_Idle,
        .death  = ANIM_Yakkey_Idle,
        .hit    = ANIM_Yakkey_Idle,
        .anim_8 = ANIM_Yakkey_Idle,
        .anim_9 = ANIM_Yakkey_Idle,
        .anim_A = ANIM_Yakkey_Idle,
        .anim_B = ANIM_Yakkey_Idle,
        .anim_C = ANIM_Yakkey_Idle,
        .anim_D = ANIM_Yakkey_Idle,
        .anim_E = ANIM_Yakkey_Idle,
        .anim_F = ANIM_Yakkey_Idle,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_DGB_FORMATION_04),
    NPC_GROUP(N(NpcData_Yakkey)),
    {}
};
