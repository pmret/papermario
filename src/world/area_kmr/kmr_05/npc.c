#include "kmr_05.h"

#include "world/common/enemy/Goomba_Wander.inc.c"
#include "world/common/enemy/Paragoomba_Wander.inc.c"
#include "world/common/enemy/SpikedGoomba_Wander.inc.c"

EvtScript N(EVS_GoompaRemark) = {
    Call(DisablePlayerInput, TRUE)
    Wait(10 * DT)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -60, -19, 0)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00B7)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcAux_SpikedGoomba) = {
    Label(0)
    Call(TranslateModel, MODEL_usokinoko, -1, 0, 0)
    Wait(1)
    Call(TranslateModel, MODEL_usokinoko, 1, 0, 0)
    Wait(20)
    Call(TranslateModel, MODEL_usokinoko, 1, 0, 0)
    Wait(1)
    Call(TranslateModel, MODEL_usokinoko, -1, 0, 0)
    Wait(8)
    Call(TranslateModel, MODEL_usokinoko, -1, 0, 0)
    Wait(1)
    Call(TranslateModel, MODEL_usokinoko, 1, 0, 0)
    Wait(30)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_SpikedGoomba) = {
    Call(func_800445D4, LVar0)
    Switch(LVar0)
        CaseEq(100)
            Label(10)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
            IfLt(LVar1, 100)
                Goto(10)
            EndIf
            IfLt(LVar0, 560)
                Goto(10)
            EndIf
            IfGt(LVar0, 700)
                Goto(10)
            EndIf
            Call(SetNpcAux, NPC_SELF, 0)
            Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, -30, 12, EMOTER_NPC, 0, 0, 0, 0)
            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
            Call(SetNpcSpeed, NPC_SELF, Float(5.0))
            Call(NpcJump0, NPC_SELF, 685, 100, -35, 0)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, TRUE)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpikedGoomba_Wander)))
        CaseOrEq(102)
        CaseOrEq(3)
        CaseOrEq(103)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpikedGoomba_Wander)))
        EndCaseGroup
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Goomba_01) = {
    .id = NPC_Goomba_01,
    .pos = { 305.0f, 50.0f, -13.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 305, 50, -13 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 330, 50, 20 },
            .detectSize = { 120, 130 },
        }
    },
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Goomba_02) = {
    .id = NPC_Goomba_02,
    .pos = { 700.0f, 210.0f, -165.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 700, 210, -165 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 700, 210, -165 },
            .detectSize = { 120, 130 },
        }
    },
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

EvtScript N(EVS_NpcInit_SpikedGoomba) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SpikedGoomba)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_SpikedGoomba)))
    Return
    End
};

NpcData N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .pos = { 712.0f, 100.0f, -95.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 630, 100, 25 },
            .wanderSize = { 40, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 660, 100, 30 },
            .detectSize = { 165, 150 },
        }
    },
    .init = &N(EVS_NpcInit_SpikedGoomba),
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPIKED_GOOMBA_DROPS,
    .animations = SPIKED_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .pos = { 960.0f, 210.0f, -20.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 960, 210, -20 },
            .wanderSize = { 50, 25 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 995, 210, -57 },
            .detectSize = { 210, 100 },
        }
    },
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = PARAGOOMBA_DROPS,
    .animations = PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(NpcsBefore) = {
    NPC_GROUP(N(NpcData_Goomba_01), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_03),
    NPC_GROUP(N(NpcData_Goomba_02), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_03),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_3_FORMATION_00, BTL_KMR_3_STAGE_03),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_3_FORMATION_01, BTL_KMR_3_STAGE_03),
    {}
};

NpcGroupList N(NpcsAfter) = {
    NPC_GROUP(N(NpcData_Goomba_01), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_03),
    NPC_GROUP(N(NpcData_Goomba_02), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_03),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_1_FORMATION_0A, BTL_KMR_1_STAGE_03),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_1_FORMATION_08, BTL_KMR_1_STAGE_03),
    {}
};
