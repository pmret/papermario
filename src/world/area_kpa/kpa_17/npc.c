#include "kpa_17.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_Scene_FallIntoCell) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 1042, 30, -496)
    Call(SetPanTarget, CAM_DEFAULT, 1042, 30, -496)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(InterpPlayerYaw, 270, 0)
    Wait(60)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, TRUE)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Else
        Call(func_802CF56C, 1)
    EndIf
    Call(PlaySoundAtPlayer, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Loop(0)
        Sub(LVar1, 16)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLe(LVar1, 30)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Call(PlaySoundAtPlayer, SOUND_PLAYER_COLLAPSE, SOUND_SPACE_DEFAULT)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(0.6))
    EndThread
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump1, 1030, 30, -496, 10)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(1)
    Call(DisablePlayerPhysics, FALSE)
    Wait(1)
    Call(InterpPlayerYaw, 90, 0)
    Wait(5)
    Call(DisablePlayerPhysics, TRUE)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(1)
    Call(ShowMessageAtScreenPos, MSG_CH8_0007, 1000, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10)
    Call(DisablePlayerPhysics, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(func_802CF56C, 0)
    Return
    End
};

EvtScript N(EVS_BlastWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 8, 8, 1, 10, 30)
    Call(EnableModel, MODEL_g296, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_KPA17_BombedWall, TRUE)
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Wait(80 * DT)
    Call(DisablePartnerAI, 0)
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH8_0016)
    Call(EnablePartnerAI)
    Wait(10 * DT)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    Switch(GF_KPA17_BombedWall)
        CaseEq(0)
            Switch(AB_KPA17_Toad1_Dialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH8_0009)
                    Set(AB_KPA17_Toad1_Dialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH8_000A)
                    Set(AB_KPA17_Toad1_Dialogue, 0)
            EndSwitch
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH8_000B)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    Switch(GF_KPA17_BombedWall)
        CaseEq(0)
            Switch(AB_KPA17_Toad2_Dialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_000C)
                    Set(AB_KPA17_Toad2_Dialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_000D)
                    Set(AB_KPA17_Toad2_Dialogue, 0)
            EndSwitch
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_000E)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadGuard) = {
    Switch(GF_KPA17_BombedWall)
        CaseEq(0)
            Switch(AB_KPA17_Toad3_Dialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_000F)
                    Set(AB_KPA17_Toad3_Dialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_0010)
                    Set(AB_KPA17_Toad3_Dialogue, 0)
            EndSwitch
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_0011)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadMinister) = {
    Switch(GF_KPA17_BombedWall)
        CaseEq(0)
            Switch(AB_KPA17_Toad4_Dialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0012)
                    Set(AB_KPA17_Toad4_Dialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0013)
                    Set(AB_KPA17_Toad4_Dialogue, 2)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0014)
                    Set(AB_KPA17_Toad4_Dialogue, 1)
            EndSwitch
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0015)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Call(SetNpcPos, NPC_SELF, 813, 30, -394)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
    Call(SetNpcPos, NPC_SELF, 870, 30, -465)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadGuard) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadGuard)))
    Call(SetNpcPos, NPC_SELF, 930, 30, -400)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadMinister) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadMinister)))
    Call(SetNpcPos, NPC_SELF, 1100, 30, -450)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Return
    End
};

NpcData N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadA,
    },
    {
        .id = NPC_Toad_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadB,
    },
    {
        .id = NPC_ToadGuard,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ToadGuard),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierA,
    },
    {
        .id = NPC_ToadMinister,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ToadMinister),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_MINISTER_ANIMS,
        .tattle = MSG_NpcTattle_KPA_ToadMinister,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Prisoners)),
    {}
};
