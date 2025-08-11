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
    if (npc != nullptr) {
        evt_set_variable(script, outVar, npc->varTable[varIdx]);
    } else {
        evt_set_variable(script, outVar, -1);
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAuxAI_BillBlaster) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, true)
    Return
    End
};

EvtScript N(D_80240844_9BDEA4) = {
    Label(0)
        SetF(LVar0, Float(400.0))
        Set(LVar1, 1)
        Call(GetNpcYaw, NPC_SELF, LVar2)
        Set(LVar3, 10)
        Set(LVarA, ANIM_BillBlaster_Idle)
        Set(LVarB, ANIM_BillBlaster_Idle)
        ExecWait(EVS_800936C0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Fire)
        Wait(15)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(GetNpcYaw, NPC_SELF, LVar3)
        Call(AddVectorPolar, LVar0, LVar2, Float(20.0), LVar3)
        Add(LVar1, 12)
        Call(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Idle)
        Call(GetSelfNpcID, LVar0)
        Add(LVar0, 1)
        Call(SetNpcVar, LVar0, 0, 1)
        Label(1)
            Call(GetSelfNpcID, LVar0)
            Add(LVar0, 1)
            Call(GetNpcVar, LVar0, 0, LVar1)
            IfEq(LVar1, 0)
                Wait(1)
                Goto(1)
            EndIf
        Call(RandInt, 30, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcHit_BillBlaster) = {
    Call(SetBattleMusic, SONG_SPECIAL_BATTLE)
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_NONE)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Set(LVar0, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_NpcHitRecoil)
        CaseEq(ENCOUNTER_TRIGGER_SPIN)
            Thread
                Call(func_800458CC, LVar0)
                IfEq(LVar0, 0)
                    Set(LVarA, 0)
                    Loop(30)
                        Add(LVarA, 40)
                        Call(SetNpcRotation, NPC_SELF, 0, LVarA, 0)
                        Wait(1)
                    EndLoop
                EndIf
            EndThread
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(D_80240B80_9BE1E0) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_BulletBill) = {
    Return
    End
};

EvtScript N(D_80240C1C_9BE27C) = {
    Return
    End
};

EvtScript N(D_80240C2C_9BE28C) = {
    Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseEq(OUTCOME_PLAYER_FLED)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
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
    IfGe(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_Red) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar0, -370)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, true)
    Wait(20 * DT)
    Call(FadeOutMusic, 0, 2000 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 1300, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 1490, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 1466, Float(41.6))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20 * DT)
    Call(SetCamPosB, CAM_DEFAULT, 1466, Float(41.6))
    Call(SetPanTarget, CAM_DEFAULT, 1490, 60, 0)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, 25, -9)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(20 * DT)
    Call(PlaySound, SOUND_METAL_DOOR_OPEN)
    Call(SetMusic, 0, SONG_KOOPA_BROS_THEME, 0, VOL_LEVEL_FULL)
    Call(MakeLerp, 0, 110, 10, EASING_COS_IN_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o60, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o65, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(SetNpcVar, NPC_KoopaBros_Green, 0, 1)
    Call(SetNpcVar, NPC_KoopaBros_Yellow, 0, 1)
    Call(SetNpcVar, NPC_KoopaBros_Black, 0, 1)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
    Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
    Call(NpcMoveTo, NPC_SELF, 1490, 0, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_KoopaBros_Red_PointForward, ANIM_KoopaBros_Red_PointForward, 0, MSG_CH1_00F2)
    Call(UseSettingsFrom, CAM_DEFAULT, 1300, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 1466, Float(41.6))
    Call(SetPanTarget, CAM_DEFAULT, 1250, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Land)
    Call(NpcJump0, NPC_SELF, 1440, 30, 0, 20 * DT)
    Call(NpcJump0, NPC_SELF, 1380, 0, 0, 20 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Run)
    Call(NpcMoveTo, NPC_SELF, 1360, 0, 0)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Red_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_KoopaBros_Red_PointForward, ANIM_KoopaBros_Red_PointForward, 0, MSG_CH1_00F3)
    Call(SetNpcVar, NPC_KoopaBros_Green, 0, 2)
    Call(SetNpcVar, NPC_KoopaBros_Yellow, 0, 2)
    Call(SetNpcVar, NPC_KoopaBros_Black, 0, 2)
    Call(SetSelfVar, 0, 1)
    Call(SetMusic, 0, SONG_BULLET_BILL_ASSAULT, 0, VOL_LEVEL_FULL)
    Wait(60 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 1300, 0, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Set(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
    Call(DisablePlayerInput, false)
    Call(RotateModel, MODEL_o60, 0, 0, -1, 0)
    Call(RotateModel, MODEL_o65, 0, 0, 1, 0)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Black) = {
    IfGe(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Yellow) = {
    IfGe(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_Green) = {
    IfGe(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_Black) = {
    Call(SetSelfVar, 0, 0)
    Label(10)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(10)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
    Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
    Call(NpcMoveTo, NPC_SELF, 1520, 20, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Land)
    Call(NpcJump0, NPC_SELF, 1470, 30, 30, 20 * DT)
    Call(NpcJump0, NPC_SELF, 1410, 0, 40, 20 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    Call(NpcMoveTo, NPC_SELF, 1330, 50, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_StillCrouch)
    Label(20)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(20)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_PointForward)
    Wait(100 * DT)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_Yellow) = {
    Call(SetSelfVar, 0, 0)
    Label(10)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(10)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
    Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
    Call(NpcMoveTo, NPC_SELF, 1505, 5, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_Land)
    Call(NpcJump0, NPC_SELF, 1455, 30, 5, 20 * DT)
    Call(NpcJump0, NPC_SELF, 1395, 0, 5, 20 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_Run)
    Call(NpcMoveTo, NPC_SELF, 1315, 5, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_StillCrouch)
    Label(20)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(20)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Yellow_PointForward)
    Wait(100 * DT)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_Green) = {
    Call(SetSelfVar, 0, 0)
    Label(10)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(10)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
    Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
    Call(NpcMoveTo, NPC_SELF, 1490, -10, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_Land)
    Call(NpcJump0, NPC_SELF, 1440, 30, -20, 20 * DT)
    Call(NpcJump0, NPC_SELF, 1380, 0, -30, 20 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_Run)
    Call(NpcMoveTo, NPC_SELF, 1300, -40, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_StillCrouch)
    Label(20)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(20)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Green_PointForward)
    Wait(100 * DT)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcAI_BillBlaster) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        Label(100)
            Call(GetNpcVar, NPC_KoopaBros_Red, 0, LVar0)
            IfEq(LVar0, 0)
                Wait(1)
                Goto(100)
            EndIf
    EndIf
    Label(0)
        Set(LVarA, NPC_BulletBill_01)
        Loop(10)
            // if the bullet bill does not have an assigned owner, assign ourself and fire
            Call(N(GetBulletBillVar), LVarA, 0, LVar0)
            IfEq(LVar0, 0)
                Call(GetSelfNpcID, LVar0)
                Call(SetNpcVar, LVarA, 0, LVar0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Fire)
                Wait(15)
                Call(SetNpcAnimation, NPC_SELF, ANIM_BillBlaster_Idle)
                Call(RandInt, 100, LVar0)
                Add(LVar0, 60)
                Wait(LVar0)
            EndIf
            Add(LVarA, 1)
        EndLoop
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcAI_BulletBill) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, true)
    Label(1)
        Call(SetSelfVar, 0, 0)
        Call(EnableNpcShadow, NPC_SELF, false)
        Call(SelfEnemyOverrideSyncPos, 0)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, true)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Label(2)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 0)
                Wait(1)
                Goto(2)
            EndIf
        Wait(15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_BulletBill_Fire)
        Call(EnableNpcShadow, NPC_SELF, true)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, false)
        Call(SelfEnemyOverrideSyncPos, 1)
        Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        Call(GetNpcYaw, LVar0, LVar4)
        Call(AddVectorPolar, LVar1, LVar3, Float(14.0), LVar4)
        Add(LVar2, 11)
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        Call(InterpNpcYaw, NPC_SELF, LVar4, 0)
        Call(func_80045838, -1, SOUND_BLASTER_FIRE, SOUND_PARAM_MORE_QUIET)
        Set(LVarA, LVar1)
        Sub(LVarA, 10)
        Set(LVarB, LVar2)
        Add(LVarB, 5)
        Set(LVarC, LVar3)
        Add(LVarC, 3)
        PlayEffect(EFFECT_WALKING_DUST, 2, LVarA, LVarB, LVarC, 0, 0)
        Call(SetNpcSpeed, NPC_SELF, Float(6.0))
        Switch(LVar0)
            CaseEq(NPC_BillBlaster_01)
                Call(NpcMoveTo, NPC_SELF, -437, LVar3, 0)
            CaseEq(NPC_BillBlaster_02)
                Call(NpcMoveTo, NPC_SELF, -460, LVar3, 0)
            CaseEq(NPC_BillBlaster_03)
                Call(NpcMoveTo, NPC_SELF, -450, LVar3, 0)
        EndSwitch
        Call(func_80045838, -1, SOUND_SEQ_BULLET_BILL_EXPLODE, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_BulletBill_Hurt)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 5)
        Add(LVar2, 1)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, Float(0.05), 20)
        Add(LVar2, 1)
        PlayEffect(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, Float(1.2), 25)
        Wait(3)
        Goto(1)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_BulletBill) = {
    Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Thread
                Wait(20)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, true)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_BulletBill)))
            EndThread
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(OnPlayerFled, 0)
    EndSwitch
    Return
    End
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
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_TRD09_Defeated_BillBlasters, true)
    Call(DoNpcDefeat)
    Return
    End
};

EvtScript N(EVS_NpcInit_BillBlaster) = {
    IfEq(GF_TRD09_Defeated_BillBlasters, false)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_BillBlaster)))
    Else
        Call(RemoveEncounter, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_BillBlasters)[] = {
    {
        .id = NPC_BillBlaster_01,
        .pos = { 1260.0f, 0.0f, -40.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
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
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = BILL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_03,
        .pos = { 1275.0f, 0.0f, 5.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
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
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = BILL_BLASTER_DROPS,
        .animations = BILL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_02,
        .pos = { 1290.0f, 0.0f, 50.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
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
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
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
    Call(GetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    Call(SetNpcSpeed, NPC_SELF, Float(6.0))
    Call(NpcMoveTo, NPC_SELF, -460, LVar3, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_BulletBill_Demo) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BulletBill_Demo)))
    Call(SelfEnemyOverrideSyncPos, 1)
    Return
    End
};

NpcData N(NpcData_BulletBill_Demo1) = {
    .id = NPC_BulletBill_Demo1,
    .pos = { -100.0f, 11.0f, 50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
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
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DONT_SUSPEND_SCRIPTS,
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
            .isFlying = true,
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
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DONT_SUSPEND_SCRIPTS,
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
            .isFlying = true,
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
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DONT_SUSPEND_SCRIPTS,
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
            .isFlying = true,
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
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DONT_SUSPEND_SCRIPTS,
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
            .isFlying = true,
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
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DONT_SUSPEND_SCRIPTS,
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
