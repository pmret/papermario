#include "sam_03.h"

#include "world/common/npc/JrTroopa.inc.c"

API_CALLABLE(N(GetAngleToPlayer)) {
    Npc* npc = get_npc_unsafe(NPC_JrTroopa);

    script->varTable[0] = atan2(npc->pos.x, npc->pos.z, gPlayerStatus.pos.x, gPlayerStatus.pos.z);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_JR_TROOPA)
        Return
    EndIf
    Label(11)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar0, 400)
            Goto(11)
        EndIf
    Call(InterruptUsePartner)
    Call(DisablePlayerInput, TRUE)
    Call(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH7_00D8)
    Call(SetNpcJumpscale, NPC_JrTroopa, Float(1.0))
    Call(NpcJump0, NPC_JrTroopa, 520, 0, -68, 20 * DT)
    Call(PlayerFaceNpc, NPC_JrTroopa, FALSE)
    Wait(15 * DT)
    Call(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
    Add(LVar0, -20)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(225.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_Idle, 0, MSG_CH7_00D9)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH7_00DA)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_JrTroopa, LVar3, LVar4, LVar5)
    Call(GetDist2D, LVar6, LVar0, LVar2, LVar3, LVar5)
    MulF(LVar6, Float(0.7))
    Call(N(GetAngleToPlayer))
    Call(AddVectorPolar, LVar3, LVar5, LVar6, LVar0)
    Call(SetNpcSpeed, NPC_JrTroopa, Float(4.0 / DT))
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Charge)
    Thread
        Call(NpcMoveTo, NPC_JrTroopa, LVar3, LVar5, 0)
    EndThread
    Call(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_JrTroopa) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH7_00DF)
    Return
    End
};

EvtScript N(EVS_NpcHit_JrTroopaHitbox) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(DisablePlayerInput, TRUE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Hurt, ANIM_JrTroopa_Collapse, 5, MSG_CH7_00DF)
            Call(DisablePlayerInput, FALSE)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_JrTroopa) = {
    Call(ClearDefeatedEnemies)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GB_StoryProgress, STORY_CH7_DEFEATED_JR_TROOPA)
            Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Defeated)
            Call(SetNpcAnimation, NPC_JrTroopa_Hitbox, ANIM_JrTroopa_Defeated)
            Call(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Thread
                Wait(5 * DT)
                Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
                Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
            EndThread
            Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH7_00DF)
            Call(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_JrTroopa_Hitbox, LVar0, LVar1, LVar2)
            Call(SetNpcCollisionSize, NPC_JrTroopa, 26, 24)
            Call(SetNpcCollisionSize, NPC_JrTroopa_Hitbox, 26, 24)
            Call(SetNpcFlagBits, NPC_JrTroopa_Hitbox, NPC_FLAG_INVISIBLE, TRUE)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_JrTroopa)))
            Call(BindNpcHit, NPC_JrTroopa_Hitbox, Ref(N(EVS_NpcHit_JrTroopaHitbox)))
            Exec(N(EVS_SetupMusic))
            Call(DisablePlayerInput, FALSE)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_JrTroopa)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_DEFEATED_JR_TROOPA)
            Call(SetNpcPos, NPC_JrTroopa, 600, 0, -65)
        CaseGe(STORY_CH7_DEFEATED_JR_TROOPA)
            Call(SetNpcPos, NPC_JrTroopa, 399, 6, -100)
            Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Collapse)
            Call(EnableModel, MODEL_o44, TRUE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o44, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopaHitbox) = {
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

// first Jr Troopa is for interacting with player, the second is 'hostile' and can respond to being hit
NpcData N(NpcData_JrTroopa)[] = {
    {
        .id = NPC_JrTroopa,
        .pos = { 261.0f, 0.0f, -76.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_JrTroopa),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
    {
        .id = NPC_JrTroopa_Hitbox,
        .pos = { 261.0f, 0.0f, -76.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_JrTroopaHitbox),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa), BTL_KMR_3_FORMATION_06),
    {}
};
