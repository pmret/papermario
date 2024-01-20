#include "kzn_09.h"
#include "sprite/player.h"

#include "world/common/npc/Kolorado.inc.c"

#include "world/common/enemy/PutridPiranha.inc.c"
#include "world/common/enemy/SpikeTop.inc.c"

NpcSettings N(NpcSettings_Zipline) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Fallen, ANIM_Kolorado_Fallen,
    MSG_CH5_00E8, MSG_CH5_00E9, MSG_CH5_00EA, MSG_CH5_00EB,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_Scene_KoloradoFallsDown) = {
    Label(0)
    Call(GetPlayerPos, LVar6, LVar7, LVar8)
    IfLt(LVar7, 800)
        Return
    EndIf
    Call(AwaitPlayerLeave, -455, -60, 85)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0), 0, 400, Float(15.0), Float(-7.0))
    Call(SetSelfVar, 1, 1)
    Thread
        Wait(10 * DT)
        Loop(0)
            Wait(1)
            Call(PlayerFaceNpc, NPC_SELF, FALSE)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            Call(GetSelfVar, 1, LVar0)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Wait(30 * DT)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetNpcSpeed, NPC_PARTNER, Float(2.0))
        Add(LVar0, 20)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
        Call(NpcFacePlayer, NPC_PARTNER, 0)
        Call(EnablePartnerAI)
    EndThread
    Call(SetNpcPos, NPC_SELF, -500, 870, -15)
    Wait(1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_SELF, -425, -15, 0)
    Call(InterpNpcYaw, NPC_SELF, 270, 3)
    Wait(5)
    Call(InterpNpcYaw, NPC_SELF, 90, 3)
    Wait(5)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25 * DT)
    Call(SetSelfVar, 0, 2)
    Thread
        Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
        Label(1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, -410, 870, -15, 10 * DT)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 1)
            Wait(15)
            Goto(1)
        EndIf
        Call(SetSelfVar, 0, 0)
    EndThread
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00F4)
    Call(SetSelfVar, 0, 1)
    Label(2)
    Call(GetSelfVar, 0, LVar0)
    IfNe(LVar0, 0)
        Wait(1)
        Goto(2)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, -310, 870, -15)
    Call(SetPanTarget, CAM_DEFAULT, -310, 870, -15)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_SELF, -390, -15, 0)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.5))
    Set(LVar3, -350)
    Set(LVar4, 870)
    Set(LVar5, -15)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10 * DT)
    Add(LVar3, 90)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Thrown)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10 * DT)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Call(SetSelfVar, 0, 1)
    Thread
        Label(3)
        Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            Wait(25)
            Goto(3)
        EndIf
    EndThread
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Loop(10)
        Call(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        Sub(LVar4, 1)
        Wait(1)
    EndLoop
    Loop(20)
        Call(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        SubF(LVar3, Float(0.6))
        AddF(LVar4, Float(1.5))
        Wait(1)
    EndLoop
    Loop(10)
        Call(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        SubF(LVar3, Float(1.0))
        Sub(LVar4, 2)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    Call(SetNpcJumpscale, NPC_SELF, Float(3.0))
    Call(NpcJump0, NPC_SELF, LVar3, 700, LVar5, 5)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 0)
    Wait(5 * DT)
    Call(SetSelfVar, 0, 1)
    Thread
        Call(SetPlayerAnimation, ANIM_Mario1_VacantStare)
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Run)
        Call(SetPlayerSpeed, Float(4.0 / DT))
        Call(PlayerMoveTo, -360, 0, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_SpinFall)
        Label(5)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(5)
        EndIf
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Call(ShowMessageAtScreenPos, MSG_CH5_00F5, 160, 40)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(7.0))
    Wait(10 * DT)
    Call(SetSelfVar, 0, 0)
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Set(GB_StoryProgress, STORY_CH5_KOLORADO_FELL_IN_PIT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Kolorado_Interact) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Fallen, ANIM_Kolorado_Fallen, 0, MSG_CH5_00F6)
    EVT_LETTER_CHECK(Kolorado)
    Return
    End
};

EvtScript N(EVS_Kolorado_Init) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_KOLORADO_FELL_IN_PIT)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_KoloradoFallsDown)))
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_Kolorado_Interact)))
            Return
        CaseLt(STORY_CH5_KOLORADO_AT_DEAD_END)
            Call(SetNpcPos, NPC_SELF, -270, 375, -15)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_Kolorado_Interact)))
            Return
    EndSwitch
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_SyncZiplineDummyNPC) = {
    Loop(0)
        Call(GetModelCenter, MODEL_kassya_koma)
        Call(SetNpcPos, NPC_ZiplineDummy, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Dummy_Init) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcScale, NPC_SELF, Float(0.3), 1, Float(0.3))
    Return
    End
};

NpcData N(NpcData_PassiveNPCs)[] = {
    {
        .id = NPC_Kolorado,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_Kolorado_Init),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_Dummy_Init),
        .settings = &N(NpcSettings_Zipline),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

NpcData N(NpcData_SpikeTop) = {
    .id = NPC_SpikeTop,
    .pos = { -100.0f, 350.0f, 50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -100, 350, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -100, 350, 50 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_PutridPiranha)[] = {
    {
        .id = NPC_Piranha,
        .pos = { 200.0f, 350.0f, 100.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 350, 100 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 10, 350, 25 },
                .detectSize = { 220, 165 },
            }
        },
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = PUTRID_PIRANHA_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox)
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PassiveNPCs)),
    NPC_GROUP(N(NpcData_SpikeTop), BTL_KZN_FORMATION_0B, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_PutridPiranha), BTL_KZN_FORMATION_0F, BTL_KZN_STAGE_01),
    {}
};
