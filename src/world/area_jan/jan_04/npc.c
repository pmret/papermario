#include "jan_04.h"
#include "sprite/player.h"

#include "world/common/npc/Sushie.inc.c"
#include "world/common/npc/Bubulb.inc.c"
#include "world/common/npc/YoshiKid.inc.c"

EvtScript N(EVS_ShakeTree_Sushie) = {
    Call(GetNpcVar, NPC_Sushie, 0, LVar0)
    IfEq(LVar0, 2)
        Return
    EndIf
    IfEq(AF_JAN_08, TRUE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Set(AF_JAN_08, TRUE)
    Call(SetNpcFlagBits, NPC_Sushie, NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    IfEq(GF_JAN04_SushieTreeHitCounterB, FALSE)
        IfEq(GF_JAN04_SushieTreeHitCounterA, FALSE)
            Call(SetNpcJumpscale, NPC_Sushie, Float(1.0))
            Call(PlaySoundAtNpc, NPC_Sushie, SOUND_SUSHIE_FLOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_Sushie, 90, 140, -85, 20 * DT)
            Call(UseSettingsFrom, CAM_DEFAULT, 90, 140, -85)
            Call(SetPanTarget, CAM_DEFAULT, 90, 140, -85)
            Call(SetCamDistance, CAM_DEFAULT, 280)
            Call(SetCamPitch, CAM_DEFAULT, 16, Float(-6.0))
#if VERSION_PAL
            Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
            Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(SpeakToPlayer, NPC_Sushie, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A1)
            Call(ResetCam, CAM_DEFAULT, Float(90.0))
            Set(GF_JAN04_SushieTreeHitCounterA, TRUE)
            Wait(10 * DT)
            Set(AF_JAN_08, FALSE)
        Else
            Call(SetNpcJumpscale, NPC_Sushie, Float(1.0))
            Call(PlaySoundAtNpc, NPC_Sushie, SOUND_SUSHIE_FLOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_Sushie, -10, 112, -80, 15 * DT)
            Set(GF_JAN04_SushieTreeHitCounterA, FALSE)
            Set(GF_JAN04_SushieTreeHitCounterB, TRUE)
            Wait(10 * DT)
            Set(AF_JAN_08, FALSE)
        EndIf
    Else
        Call(SetNpcJumpscale, NPC_Sushie, Float(1.0))
        Call(PlaySoundAtNpc, NPC_Sushie, SOUND_SUSHIE_FLOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Sushie, 50, 0, 0, 20 * DT)
        Set(GF_JAN04_SushieTreeHitCounterA, TRUE)
        Call(EnableNpcShadow, NPC_Sushie, TRUE)
        Call(SetNpcAnimation, NPC_Sushie, ANIM_WorldSushie_Hurt)
        Call(SetNpcVar, NPC_Sushie, 0, 10)
        Unbind
    EndIf
    Call(SetNpcFlagBits, NPC_Sushie, NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Sushie_ScoldPlayerLeaving) = {
    Label(1)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(AwaitPlayerLeave, 0, 0, 170)
                Call(DisablePlayerInput, TRUE)
                Call(SetSelfVar, 0, 2)
                Set(LVar0, GF_JAN04_SushieTreeHitCounterA)
                Set(LVar1, GF_JAN04_SushieTreeHitCounterB)
                Add(LVar0, LVar1)
                IfEq(LVar0, 0)
                    Call(ShowMessageAtScreenPos, MSG_CH5_00A2, 160, 40)
                Else
                    Call(ShowMessageAtScreenPos, MSG_CH5_00A3, 160, 40)
                EndIf
                Call(DisablePlayerInput, FALSE)
                Call(SetSelfVar, 0, 1)
            CaseEq(1)
                Call(AwaitPlayerApproach, 0, 0, 130)
                Call(SetSelfVar, 0, 0)
        EndSwitch
        Wait(1)
        Goto(1)
    Return
    End
};

EvtScript N(EVS_Sushie_ShoutAtChildren) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH5_009E, 320, 60)
    Call(DisablePlayerInput, FALSE)
    Call(AwaitPlayerApproach, 0, 0, 130)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH5_009F, 160, 40)
    Call(SetPlayerAnimation, ANIM_MarioW2_LookAround)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetPanTarget, CAM_DEFAULT, 30, 140, -60)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, 16, Float(-6.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Hurt, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A0)
#if VERSION_PAL
    Call(ResetCam, CAM_DEFAULT, Float(3 / DT))
#else
    Call(ResetCam, CAM_DEFAULT, 3)
#endif
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

BombTrigger N(BombPos_SushieTree) = {
    .pos = { 30.0f, 0.0f, -110.0f },
    .diameter = 0.0f
};

#include "world/common/util/ChangeNpcToPartner.inc.c"

EvtScript N(EVS_NpcIdle_Sushie) = {
    Set(LVar0, GF_JAN04_SushieTreeHitCounterA)
    Set(LVar1, GF_JAN04_SushieTreeHitCounterB)
    Add(LVar0, LVar1)
    IfEq(LVar0, 0)
        ExecWait(N(EVS_Sushie_ShoutAtChildren))
    Else
        Call(SetSelfVar, 0, 1)
    EndIf
    Set(AF_JAN_08, FALSE)
    BindTrigger(Ref(N(EVS_ShakeTree_Sushie)), TRIGGER_WALL_HAMMER, COLLIDER_o34, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Sushie)), TRIGGER_POINT_BOMB, Ref(N(BombPos_SushieTree)), 1, 0)
    ExecGetTID(N(EVS_Sushie_ScoldPlayerLeaving), LVar9)
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 10)
            Wait(1)
            Goto(0)
        EndIf
    KillThread(LVar9)
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerSpeed, Float(4.0 / DT))
    Call(PlayerMoveTo, 10, 0, 0)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Idle)
    Call(AdjustCam, CAM_DEFAULT, Float(5.0 / DT), 20, 301, Float(17.0), Float(-7.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A4)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(40 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Sad)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A6)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(40 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A7)
    Call(CloseMessage)
    Call(N(ChangeNpcToPartner), NPC_Sushie, PARTNER_SUSHIE)
    Call(N(LoadPartyImage))
    Exec(N(EVS_PushNewPartnerSong))
    Wait(15 * DT)
    Call(ShowMessageAtScreenPos, MSG_Menus_018F, 160, 40)
    Exec(N(EVS_PopSong))
    Wait(10 * DT)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Set(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Sushie) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_04_ENTRY_3)
        Return
    EndIf
    IfEq(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Sad)
        Call(SetNpcYaw, NPC_SELF, 270)
        IfEq(GF_JAN04_SushieTreeHitCounterB, FALSE)
            IfEq(GF_JAN04_SushieTreeHitCounterA, FALSE)
                Call(SetNpcPos, NPC_SELF, 55, 150, -95)
            Else
                Call(SetNpcPos, NPC_SELF, 90, 140, -85)
            EndIf
        Else
            IfEq(GF_JAN04_SushieTreeHitCounterA, FALSE)
                Call(SetNpcPos, NPC_SELF, -10, 112, -80)
            Else
                Call(SetNpcPos, NPC_SELF, 50, 0, 0)
                Call(EnableNpcShadow, NPC_SELF, TRUE)
            EndIf
        EndIf
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Sushie)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bubulb) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
            IfEq(GF_JAN04_Met_Bubulb, FALSE)
                Wait(30)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Yellow_PopUp)
                Wait(10)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
                Wait(35)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Yellow_Idle)
                Call(SetNpcCollisionSize, NPC_SELF, 45, 26)
                Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00A8)
                Set(GF_JAN04_Met_Bubulb, TRUE)
                Call(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_JAN_Bubulb_Revealed)
                Return
            Else
                Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00A9)
            EndIf
        CaseLt(STORY_CH5_TRADED_VASE_FOR_SEED)
            Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00AA)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00AB)
        CaseDefault
            Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00AC)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb)))
    IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
        IfEq(GF_JAN04_Met_Bubulb, FALSE)
            Call(SetNpcCollisionSize, NPC_SELF, 25, 25)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Yellow_BuriedIdle)
            Call(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Hidden)
        EndIf
    EndIf
    Return
    End
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Sushie,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Sushie),
        .settings = &N(NpcSettings_Sushie),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = SUSHIE_ANIMS,
    },
    {
        .id = NPC_Bubulb,
        .pos = { -230.0f, 0.0f, -320.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bubulb),
        .settings = &N(NpcSettings_Bubulb),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = BUBULB_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_JAN_Bubulb_Revealed,
    },
};

NpcData N(NpcData_YoshiKids)[] = {
    {
        .id = NPC_YoshiKid_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreenYoshiKid,
    },
    {
        .id = NPC_YoshiKid_02,
        .pos = { 45.0f, 0.0f, -70.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_RedYoshiKid,
    },
    {
        .id = NPC_YoshiKid_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_BlueYoshiKid,
    },
    {
        .id = NPC_YoshiKid_04,
        .pos = { 20.0f, 0.0f, -70.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_YellowYoshiKid,
    },
    {
        .id = NPC_YoshiKid_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_PurpleYoshiKid,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    NPC_GROUP(N(NpcData_YoshiKids)),
    {}
};
