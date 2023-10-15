#include "trd_09.h"
#include "effects.h"

#include "world/common/enemy/BulletBill.h"

API_CALLABLE(N(GetBulletBillVar)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 varIdx = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    if (npc != NULL) {
        evt_set_variable(script, outVar, npc->varTable[varIdx]);
    } else {
        evt_set_variable(script, outVar, -1);
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAuxAI_BillBlaster) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240844_9BDEA4) = {
    EVT_LABEL(0)
        EVT_SETF(LVar0, EVT_FLOAT(400.0))
        EVT_SET(LVar1, 1)
        EVT_CALL(GetNpcYaw, NPC_SELF, LVar2)
        EVT_SET(LVar3, 10)
        EVT_SET(LVarA, ANIM_BillBlaster_Idle)
        EVT_SET(LVarB, ANIM_BillBlaster_Idle)
        EVT_EXEC_WAIT(EVS_800936C0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Fire)
        EVT_WAIT(15)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcYaw, NPC_SELF, LVar3)
        EVT_CALL(AddVectorPolar, LVar0, LVar2, EVT_FLOAT(20.0), LVar3)
        EVT_ADD(LVar1, 12)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Idle)
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(SetNpcVar, LVar0, 0, 1)
        EVT_LABEL(1)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(GetNpcVar, LVar0, 0, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_WAIT(1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_BillBlaster) = {
    EVT_CALL(SetBattleMusic, SONG_SPECIAL_BATTLE)
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_SET(LVar0, ANIM_BillBlaster_Hurt)
            EVT_EXEC_WAIT(EVS_NpcHitRecoil)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_SPIN)
            EVT_THREAD
                EVT_CALL(func_800458CC, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_LOOP(30)
                        EVT_ADD(LVarA, 40)
                        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVarA, 0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240B80_9BE1E0) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_BulletBill) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240C1C_9BE27C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240C2C_9BE28C) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(missing_80240CE4) = {
    .defaultAnim = ANIM_BillBlaster_Idle,
    .height = 26,
    .radius = 32,
    .level = ACTOR_LEVEL_BILL_BLASTER,
    .otherAI = &N(EVS_NpcAuxAI_BillBlaster),
    .ai = &N(D_80240844_9BDEA4),
    .onHit = &N(EVS_NpcHit_BillBlaster),
    .onDefeat = &N(D_80240B80_9BE1E0),
};

NpcSettings N(missing_80240D10) = {
    .defaultAnim = ANIM_BulletBill_Idle,
    .height = 14,
    .radius = 31,
    .level = ACTOR_LEVEL_BULLET_BILL,
    .otherAI = &N(EVS_NpcAuxAI_BulletBill),
    .ai = &N(D_80240C1C_9BE27C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(D_80240C2C_9BE28C),
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Red) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_Red) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, -370)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(20 * DT)
    EVT_CALL(FadeOutMusic, 0, 2000 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 1300, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 1490, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 1466, EVT_FLOAT(41.6))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 1466, EVT_FLOAT(41.6))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 1490, 60, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 25, -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySound, SOUND_METAL_DOOR_OPEN)
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_BROS_THEME, 0, 8)
    EVT_CALL(MakeLerp, 0, 110, 10, EASING_COS_IN_OUT)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o60, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o65, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(SetNpcVar, NPC_KoopaBros_Green, 0, 1)
    EVT_CALL(SetNpcVar, NPC_KoopaBros_Yellow, 0, 1)
    EVT_CALL(SetNpcVar, NPC_KoopaBros_Black, 0, 1)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(NpcMoveTo, NPC_SELF, 1490, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaBros_Red_PointForward, ANIM_KoopaBros_Red_PointForward, 0, MSG_CH1_00F2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 1300, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 1466, EVT_FLOAT(41.6))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 1250, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Land)
    EVT_CALL(NpcJump0, NPC_SELF, 1440, 30, 0, 20 * DT)
    EVT_CALL(NpcJump0, NPC_SELF, 1380, 0, 0, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 1360, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Idle)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaBros_Red_PointForward, ANIM_KoopaBros_Red_PointForward, 0, MSG_CH1_00F3)
    EVT_CALL(SetNpcVar, NPC_KoopaBros_Green, 0, 2)
    EVT_CALL(SetNpcVar, NPC_KoopaBros_Yellow, 0, 2)
    EVT_CALL(SetNpcVar, NPC_KoopaBros_Black, 0, 2)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetMusicTrack, 0, SONG_BULLET_BILL_ASSAULT, 0, 8)
    EVT_WAIT(60 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 1300, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_SET(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RotateModel, MODEL_o60, 0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o65, 0, 0, 1, 0)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Black) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Yellow) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Green) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_Black) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(10)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(NpcMoveTo, NPC_SELF, 1520, 20, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Land)
    EVT_CALL(NpcJump0, NPC_SELF, 1470, 30, 30, 20 * DT)
    EVT_CALL(NpcJump0, NPC_SELF, 1410, 0, 40, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 1330, 50, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_StillCrouch)
    EVT_LABEL(20)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_PointForward)
    EVT_WAIT(100 * DT)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_Yellow) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(10)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(NpcMoveTo, NPC_SELF, 1505, 5, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_Land)
    EVT_CALL(NpcJump0, NPC_SELF, 1455, 30, 5, 20 * DT)
    EVT_CALL(NpcJump0, NPC_SELF, 1395, 0, 5, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 1315, 5, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_StillCrouch)
    EVT_LABEL(20)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_PointForward)
    EVT_WAIT(100 * DT)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_Green) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(10)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(NpcMoveTo, NPC_SELF, 1490, -10, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_Land)
    EVT_CALL(NpcJump0, NPC_SELF, 1440, 30, -20, 20 * DT)
    EVT_CALL(NpcJump0, NPC_SELF, 1380, 0, -30, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 1300, -40, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_StillCrouch)
    EVT_LABEL(20)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_PointForward)
    EVT_WAIT(100 * DT)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_BillBlaster) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        EVT_LABEL(100)
            EVT_CALL(GetNpcVar, NPC_KoopaBros_Red, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_WAIT(1)
                EVT_GOTO(100)
            EVT_END_IF
    EVT_END_IF
    EVT_LABEL(0)
        EVT_SET(LVarA, NPC_BulletBill_01)
        EVT_LOOP(10)
            // if the bullet bill does not have an assigned owner, assign ourself and fire
            EVT_CALL(N(GetBulletBillVar), LVarA, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetSelfNpcID, LVar0)
                EVT_CALL(SetNpcVar, LVarA, 0, LVar0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Fire)
                EVT_WAIT(15)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Idle)
                EVT_CALL(RandInt, 100, LVar0)
                EVT_ADD(LVar0, 60)
                EVT_WAIT(LVar0)
            EVT_END_IF
            EVT_ADD(LVarA, 1)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_BulletBill) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, 1)
    EVT_LABEL(1)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SelfEnemyOverrideSyncPos, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_LABEL(2)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_WAIT(1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BulletBill_Fire)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SelfEnemyOverrideSyncPos, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(GetNpcYaw, LVar0, LVar4)
        EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(14.0), LVar4)
        EVT_ADD(LVar2, 11)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar4, 0)
        EVT_CALL(func_80045838, -1, SOUND_BLASTER_FIRE, SOUND_PARAM_MORE_QUIET)
        EVT_SET(LVarA, LVar1)
        EVT_SUB(LVarA, 10)
        EVT_SET(LVarB, LVar2)
        EVT_ADD(LVarB, 5)
        EVT_SET(LVarC, LVar3)
        EVT_ADD(LVarC, 3)
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVarA, LVarB, LVarC, 0, 0)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(6.0))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(NPC_BillBlaster_01)
                EVT_CALL(NpcMoveTo, NPC_SELF, -437, LVar3, 0)
            EVT_CASE_EQ(NPC_BillBlaster_02)
                EVT_CALL(NpcMoveTo, NPC_SELF, -460, LVar3, 0)
            EVT_CASE_EQ(NPC_BillBlaster_03)
                EVT_CALL(NpcMoveTo, NPC_SELF, -450, LVar3, 0)
        EVT_END_SWITCH
        EVT_CALL(func_80045838, -1, SOUND_SEQ_BULLET_BILL_EXPLODE, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BulletBill_Hurt)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 5)
        EVT_ADD(LVar2, 1)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.05), 20)
        EVT_ADD(LVar2, 1)
        EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.2), 25)
        EVT_WAIT(3)
        EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_BulletBill) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_THREAD
                EVT_WAIT(20)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_BulletBill)))
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_KoopaBros_Red) = {
    .defaultAnim = ANIM_KoopaBros_Red_Walk,
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_Red),
    .ai = &N(EVS_NpcAI_KoopaBros_Red),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
};

NpcSettings N(NpcSettings_KoopaBros_Black) = {
    .defaultAnim = ANIM_KoopaBros_Black_Walk,
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_Black),
    .ai = &N(EVS_NpcAI_KoopaBros_Black),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
};

NpcSettings N(NpcSettings_KoopaBros_Yellow) = {
    .defaultAnim = ANIM_KoopaBros_Yellow_Walk,
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_Yellow),
    .ai = &N(EVS_NpcAI_KoopaBros_Yellow),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
};

NpcSettings N(NpcSettings_KoopaBros_Green) = {
    .defaultAnim = ANIM_KoopaBros_Green_Walk,
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_Green),
    .ai = &N(EVS_NpcAI_KoopaBros_Green),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
};

NpcSettings N(NpcSettings_BillBlaster) = {
    .defaultAnim = ANIM_BillBlaster_Idle,
    .height = 26,
    .radius = 32,
    .level = ACTOR_LEVEL_BILL_BLASTER,
    .otherAI = &N(EVS_NpcAuxAI_BillBlaster),
    .ai = &N(EVS_NpcAI_BillBlaster),
    .onHit = &N(EVS_NpcHit_BillBlaster),
};

NpcSettings N(NpcSettings_BulletBill) = {
    .defaultAnim = ANIM_BulletBill_Idle,
    .height = 14,
    .radius = 31,
    .level = ACTOR_LEVEL_BULLET_BILL,
    .otherAI = &N(EVS_NpcAuxAI_BulletBill),
    .ai = &N(EVS_NpcAI_BulletBill),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_BulletBill),
};

EvtScript N(EVS_NpcDefeat_BillBlaster) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_TRD09_Defeated_BillBlasters, TRUE)
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BillBlaster) = {
    EVT_IF_EQ(GF_TRD09_Defeated_BillBlasters, FALSE)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_BillBlaster)))
    EVT_ELSE
        EVT_CALL(RemoveEncounter, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_BillBlasters)[] = {
    {
        .id = NPC_BillBlaster_01,
        .pos = { 1260.0f, 0.0f, -40.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_BillBlaster),
        .settings = &N(NpcSettings_BillBlaster),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = BILL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_03,
        .pos = { 1275.0f, 0.0f, 5.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_BillBlaster),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = BILL_BLASTER_DROPS,
        .animations = BILL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_02,
        .pos = { 1290.0f, 0.0f, 50.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_BillBlaster),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = BILL_BLASTER_ANIMS,
    },
};

NpcData N(NpcData_BulletBill_01) = BULLET_BILL_NPC(NPC_BulletBill_01);
NpcData N(NpcData_BulletBill_02) = BULLET_BILL_NPC(NPC_BulletBill_02);
NpcData N(NpcData_BulletBill_03) = BULLET_BILL_NPC(NPC_BulletBill_03);
NpcData N(NpcData_BulletBill_04) = BULLET_BILL_NPC(NPC_BulletBill_04);
NpcData N(NpcData_BulletBill_05) = BULLET_BILL_NPC(NPC_BulletBill_05);
NpcData N(NpcData_BulletBill_06) = BULLET_BILL_NPC(NPC_BulletBill_06);
NpcData N(NpcData_BulletBill_07) = BULLET_BILL_NPC(NPC_BulletBill_07);
NpcData N(NpcData_BulletBill_08) = BULLET_BILL_NPC(NPC_BulletBill_08);
NpcData N(NpcData_BulletBill_09) = BULLET_BILL_NPC(NPC_BulletBill_09);
NpcData N(NpcData_BulletBill_10) = BULLET_BILL_NPC(NPC_BulletBill_10);

NpcData N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_Red,
        .pos = { 1590.0f, 60.0f, 0.0f },
        .yaw = 270,
        .initVarCount = 1,
        .initVar = { .value = 0 },
        .settings = &N(NpcSettings_KoopaBros_Red),
        .flags = ENEMY_FLAG_PASSIVE,
    },
    {
        .id = NPC_KoopaBros_Green,
        .pos = { 1590.0f, 60.0f, -10.0f },
        .yaw = 270,
        .initVarCount = 1,
        .initVar = { .value = 0 },
        .settings = &N(NpcSettings_KoopaBros_Green),
        .flags = ENEMY_FLAG_PASSIVE,
    },
    {
        .id = NPC_KoopaBros_Yellow,
        .pos = { 1605.0f, 60.0f, 5.0f },
        .yaw = 270,
        .initVarCount = 1,
        .initVar = { .value = 0 },
        .settings = &N(NpcSettings_KoopaBros_Yellow),
        .flags = ENEMY_FLAG_PASSIVE,
    },
    {
        .id = NPC_KoopaBros_Black,
        .pos = { 1620.0f, 60.0f, 20.0f },
        .yaw = 270,
        .initVarCount = 1,
        .initVar = { .value = 0 },
        .settings = &N(NpcSettings_KoopaBros_Black),
        .flags = ENEMY_FLAG_PASSIVE,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BillBlasters), BTL_TRD_1_FORMATION_17, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_01), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_02), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_03), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_04), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_05), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_06), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_07), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_08), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_09), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_10), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_KoopaBros)),
    {}
};

EvtScript N(EVS_NpcIdle_BulletBill_Demo) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, -460, LVar3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BulletBill_Demo) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_BulletBill_Demo)))
    EVT_CALL(SelfEnemyOverrideSyncPos, 1)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_BulletBill_Demo1) = {
    .id = NPC_BulletBill_Demo1,
    .pos = { -100.0f, 11.0f, 50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BulletBill_Demo),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BulletBill),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_80000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 3,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
    },
    .animations = {
        .idle   = ANIM_BulletBill_Idle,
        .walk   = ANIM_BulletBill_TenseCopy,
        .run    = ANIM_BulletBill_Tense,
        .chase  = ANIM_BulletBill_Tense,
        .anim_4 = ANIM_BulletBill_Idle,
        .anim_5 = ANIM_BulletBill_Fire,
        .death  = ANIM_BulletBill_Hurt,
        .hit    = ANIM_BulletBill_Hurt,
        .anim_8 = ANIM_BulletBill_Idle,
        .anim_9 = ANIM_BulletBill_Idle,
        .anim_A = ANIM_BulletBill_Idle,
        .anim_B = ANIM_BulletBill_Idle,
        .anim_C = ANIM_BulletBill_Idle,
        .anim_D = ANIM_BulletBill_Idle,
        .anim_E = ANIM_BulletBill_Idle,
        .anim_F = ANIM_BulletBill_Idle,
    },
};

NpcData N(NpcData_BulletBill_Demo2) = {
    .id = NPC_BulletBill_Demo2,
    .pos = { -150.0f, 11.0f, 5.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BulletBill_Demo),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BulletBill),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_80000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 3,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
    },
    .animations = {
        .idle   = ANIM_BulletBill_Idle,
        .walk   = ANIM_BulletBill_TenseCopy,
        .run    = ANIM_BulletBill_Tense,
        .chase  = ANIM_BulletBill_Tense,
        .anim_4 = ANIM_BulletBill_Idle,
        .anim_5 = ANIM_BulletBill_Fire,
        .death  = ANIM_BulletBill_Hurt,
        .hit    = ANIM_BulletBill_Hurt,
        .anim_8 = ANIM_BulletBill_Idle,
        .anim_9 = ANIM_BulletBill_Idle,
        .anim_A = ANIM_BulletBill_Idle,
        .anim_B = ANIM_BulletBill_Idle,
        .anim_C = ANIM_BulletBill_Idle,
        .anim_D = ANIM_BulletBill_Idle,
        .anim_E = ANIM_BulletBill_Idle,
        .anim_F = ANIM_BulletBill_Idle,
    },
};

NpcData N(NpcData_BulletBill_Demo3) = {
    .id = NPC_BulletBill_Demo3,
    .pos = { 120.0f, 11.0f, 50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BulletBill_Demo),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BulletBill),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_80000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 3,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
    },
    .animations = {
        .idle   = ANIM_BulletBill_Idle,
        .walk   = ANIM_BulletBill_TenseCopy,
        .run    = ANIM_BulletBill_Tense,
        .chase  = ANIM_BulletBill_Tense,
        .anim_4 = ANIM_BulletBill_Idle,
        .anim_5 = ANIM_BulletBill_Fire,
        .death  = ANIM_BulletBill_Hurt,
        .hit    = ANIM_BulletBill_Hurt,
        .anim_8 = ANIM_BulletBill_Idle,
        .anim_9 = ANIM_BulletBill_Idle,
        .anim_A = ANIM_BulletBill_Idle,
        .anim_B = ANIM_BulletBill_Idle,
        .anim_C = ANIM_BulletBill_Idle,
        .anim_D = ANIM_BulletBill_Idle,
        .anim_E = ANIM_BulletBill_Idle,
        .anim_F = ANIM_BulletBill_Idle,
    },
};

NpcData N(NpcData_BulletBill_Demo4) = {
    .id = NPC_BulletBill_Demo4,
    .pos = { 330.0f, 11.0f, 5.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BulletBill_Demo),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BulletBill),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_80000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 3,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
    },
    .animations = {
        .idle   = ANIM_BulletBill_Idle,
        .walk   = ANIM_BulletBill_TenseCopy,
        .run    = ANIM_BulletBill_Tense,
        .chase  = ANIM_BulletBill_Tense,
        .anim_4 = ANIM_BulletBill_Idle,
        .anim_5 = ANIM_BulletBill_Fire,
        .death  = ANIM_BulletBill_Hurt,
        .hit    = ANIM_BulletBill_Hurt,
        .anim_8 = ANIM_BulletBill_Idle,
        .anim_9 = ANIM_BulletBill_Idle,
        .anim_A = ANIM_BulletBill_Idle,
        .anim_B = ANIM_BulletBill_Idle,
        .anim_C = ANIM_BulletBill_Idle,
        .anim_D = ANIM_BulletBill_Idle,
        .anim_E = ANIM_BulletBill_Idle,
        .anim_F = ANIM_BulletBill_Idle,
    },
};

NpcData N(NpcData_BulletBill_Demo5) = {
    .id = NPC_BulletBill_Demo5,
    .pos = { 380.0f, 11.0f, -40.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BulletBill_Demo),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BulletBill),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_80000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 3,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
    },
    .animations = {
        .idle   = ANIM_BulletBill_Idle,
        .walk   = ANIM_BulletBill_TenseCopy,
        .run    = ANIM_BulletBill_Tense,
        .chase  = ANIM_BulletBill_Tense,
        .anim_4 = ANIM_BulletBill_Idle,
        .anim_5 = ANIM_BulletBill_Fire,
        .death  = ANIM_BulletBill_Hurt,
        .hit    = ANIM_BulletBill_Hurt,
        .anim_8 = ANIM_BulletBill_Idle,
        .anim_9 = ANIM_BulletBill_Idle,
        .anim_A = ANIM_BulletBill_Idle,
        .anim_B = ANIM_BulletBill_Idle,
        .anim_C = ANIM_BulletBill_Idle,
        .anim_D = ANIM_BulletBill_Idle,
        .anim_E = ANIM_BulletBill_Idle,
        .anim_F = ANIM_BulletBill_Idle,
    },
};

NpcGroupList N(DemoNPCs) = {
    NPC_GROUP(N(NpcData_BulletBill_Demo1), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_Demo2), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_Demo3), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_Demo4), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    NPC_GROUP(N(NpcData_BulletBill_Demo5), BTL_TRD_1_FORMATION_1A, BTL_TRD_1_STAGE_06),
    {}
};
