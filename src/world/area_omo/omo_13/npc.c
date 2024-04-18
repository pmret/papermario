#include "omo_13.h"
#include "sprite/player.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"
#include "world/common/enemy/GrooveGuy.inc.c"

NpcSettings N(NpcSettings_AntiGuy) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/complete/NormalItemChoice.inc.c"

s32 N(BribeItemList)[] = {
    ITEM_LEMON_CANDY,
    -1
};

EvtScript N(EVS_NpcInteract_AntiGuy) = {
    IfEq(GF_OMO13_Defeated_AntiGuy, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim15, ANIM_ShyGuy_Black_Anim15, 5, MSG_CH4_004D)
        Return
    EndIf
    Call(AdjustCam, CAM_DEFAULT, Float(5.0), 10, Float(300.0), Float(15.0), Float(-7.5))
    Call(FindItem, ITEM_LEMON_CANDY, LVar0)
    IfEq(LVar0, -1)
        Thread
            Wait(10)
            Call(SetPlayerAnimation, ANIM_MarioW2_TouchNose)
            Wait(20)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0046)
        Call(EndSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim13, ANIM_ShyGuy_Black_Anim01, 0)
        Call(ShowChoice, MSG_Choice_0044)
        IfEq(LVar0, 0)
            Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
        Else
            Wait(5)
            Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0047)
            Call(ShowChoice, MSG_Choice_0044)
            IfEq(LVar0, 0)
                Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
            Else
                Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0049)
                Call(SetNpcVar, NPC_SELF, 0, 1)
            EndIf
        EndIf
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_004A)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
        Wait(30)
        Call(EndSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0)
        Wait(15)
        Call(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
        Wait(15)
        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
        Wait(15)
        Call(EndSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0)
        Set(LVar0, Ref(N(BribeItemList)))
        Set(LVar1, -1)
        ExecWait(N(EVS_ChooseItem))
        IfEq(LVar0, -1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_004B)
            Call(ShowChoice, MSG_Choice_0044)
            IfEq(LVar0, 0)
                Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
            Else
                Wait(5)
                Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0047)
                Call(ShowChoice, MSG_Choice_0044)
                IfEq(LVar0, 0)
                    Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
                Else
                    Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0049)
                    Call(SetNpcVar, NPC_SELF, 0, 1)
                EndIf
            EndIf
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_004C)
            Wait(20)
            Set(GF_OMO13_Defeated_AntiGuy, TRUE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_he, COLLIDER_FLAGS_UPPER_MASK)
            Call(SetNpcVar, NPC_SELF, 0, 2)
        EndIf
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Return
    End
};

API_CALLABLE(N(UpdateAntiGuyPosition)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(NPC_AntiGuy);
    f32 theta;
    f32 x, y, z;

    dist2D(110.0f, -45.0f, playerStatus->pos.x, playerStatus->pos.z);
    theta = clamp_angle(atan2(110.0f, -45.0f, playerStatus->pos.x, playerStatus->pos.z));
    x = 110.0f + (sin_deg(theta) * 30.0f);
    if (script->varTable[11] != 0) {
        y = playerStatus->pos.y * 0.7f;
    } else {
        y = npc->pos.y;
    }
    z = -45.0f - (cos_deg(theta) * 30.0f);

    if (script->varTable[11] != 0 && npc->pos.y == 0.0f) {
        script->varTable[11] = 0;
    }

    if (npc->pos.x != x || npc->pos.y != y || npc->pos.z != z) {
        if (npc->curAnim != ANIM_ShyGuy_Black_Anim02 && script->varTable[10]++ >= 6) {
            npc->curAnim = ANIM_ShyGuy_Black_Anim02;
            script->varTable[10] = 0;
        }
        npc->pos.x = x;
        npc->pos.z = z;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.y = npc->pos.y;
        npc->colliderPos.z = npc->pos.z;
        npc->flags |= NPC_FLAG_DIRTY_SHADOW;
    } else if (npc->curAnim != ANIM_ShyGuy_Black_Anim01) {
        npc->curAnim = ANIM_ShyGuy_Black_Anim01;
    }
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_AntiGuy) = {
    Label(0)
        Call(N(UpdateAntiGuyPosition))
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(0)
        EndIf
        IfEq(LVar0, 1)
            Call(StartBossBattle, SONG_SPECIAL_BATTLE)
            Label(1)
                Call(GetSelfVar, 0, LVar0)
                IfNe(LVar0, 0)
                    Wait(1)
                    Goto(1)
                EndIf
            Goto(0)
        Else
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Black_Anim02)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            IfLt(LVar2, -60)
                IfLt(LVar0, 110)
                    Add(LVar0, 60)
                Else
                    Add(LVar0, -60)
                EndIf
            Else
                IfLt(LVar0, 110)
                    Add(LVar0, -60)
                Else
                    Add(LVar0, 60)
                EndIf
            EndIf
            Call(SetNpcSpeed, NPC_SELF, Float(3.0))
            Call(NpcMoveTo, NPC_SELF, LVar0, -100, 0)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Black_Anim15)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Label(9)
                Wait(1)
                Goto(9)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_AntiGuy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_OMO13_Defeated_AntiGuy, TRUE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_he, COLLIDER_FLAGS_UPPER_MASK)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
            Call(SetSelfVar, 0, 0)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetSelfVar, 0, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_AntiGuy) = {
    IfEq(GF_OMO13_Defeated_AntiGuy, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_AntiGuy)))
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_AntiGuy)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_AntiGuy)))
    Else
        Call(RemoveEncounter, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_AntiGuy) = {
    .id = NPC_AntiGuy,
    .pos = { 110.0f, 0.0f, -20.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_AntiGuy),
    .settings = &N(NpcSettings_AntiGuy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_ShyGuy_Black_Anim01,
        .walk   = ANIM_ShyGuy_Black_Anim02,
        .run    = ANIM_ShyGuy_Black_Anim03,
        .chase  = ANIM_ShyGuy_Black_Anim02,
        .anim_4 = ANIM_ShyGuy_Black_Anim01,
        .anim_5 = ANIM_ShyGuy_Black_Anim01,
        .death  = ANIM_ShyGuy_Black_Anim0C,
        .hit    = ANIM_ShyGuy_Black_Anim0C,
        .anim_8 = ANIM_ShyGuy_Black_Anim15,
        .anim_9 = ANIM_ShyGuy_Black_Anim12,
        .anim_A = ANIM_ShyGuy_Black_Anim11,
        .anim_B = ANIM_ShyGuy_Black_Anim10,
        .anim_C = ANIM_ShyGuy_Black_Anim05,
        .anim_D = ANIM_ShyGuy_Black_Anim01,
        .anim_E = ANIM_ShyGuy_Black_Anim01,
        .anim_F = ANIM_ShyGuy_Black_Anim01,
    },
    .tattle = MSG_NpcTattle_AntiGuy,
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .pos = { 300.0f, 0.0f, 50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 300, 0, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 300, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = YELLOW_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_GrooveGuy) = {
    .id = NPC_GrooveGuy,
    .pos = { -222.0f, 0.0f, 35.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -222, 0, 35 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -222, 0, 35 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_GrooveGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = GROOVE_GUY_DROPS_B,
    .animations = GROOVE_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_AntiGuy), BTL_OMO_FORMATION_2C, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO_FORMATION_03, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_GrooveGuy), BTL_OMO_FORMATION_25, BTL_OMO_STAGE_00),
    {}
};
