#include "flo_18.h"
#include "sprite/player.h"

#include "world/common/todo/UnkFunc42.inc.c"

#include "world/common/enemy/Lakitu.h"
#include "world/common/enemy/YMagikoopa.h"

NpcSettings N(NpcSettings_Lakitu) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_LAKITU,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Magikoopa) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

Vec3f N(RetreatPath_Magikoopa)[] = {
    {  -55.0,    15.0,   35.0 },
    { -155.0,    35.0,   35.0 },
    { -255.0,    75.0,   35.0 },
    { -355.0,   155.0,   35.0 },
    { -455.0,   315.0,   35.0 },
};

Vec3f N(RetreatPath_Lakitu_01)[] = {
    {  -20.0,    15.0,   30.0 },
    { -120.0,    35.0,   30.0 },
    { -220.0,    75.0,   30.0 },
    { -320.0,   155.0,   30.0 },
    { -420.0,   315.0,   30.0 },
};

Vec3f N(RetreatPath_Lakitu_02)[] = {
    {   65.0,    15.0,   30.0 },
    {  -35.0,    35.0,   30.0 },
    { -135.0,    75.0,   30.0 },
    { -235.0,   155.0,   30.0 },
    { -335.0,   315.0,   30.0 },
};

Vec3f N(RetreatPath_Lakitu_03)[] = {
    {  120.0,    15.0,   30.0 },
    {   20.0,    35.0,   30.0 },
    {  -80.0,    75.0,   30.0 },
    { -180.0,   155.0,   30.0 },
    { -280.0,   315.0,   30.0 },
};

EvtScript N(EVS_Scene_LakilesterLikesBeingGood) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerPos, 30, 0, 50)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetNpcPos, NPC_PARTNER, 65, 0, 50)
    Wait(30 * DT)
    Call(AdjustCam, CAM_DEFAULT, Float(8.0 / DT), 0, 300, Float(19.0), Float(-8.5))
    Call(GetCurrentPartnerID, LVar0)
    Call(BringPartnerOut, PARTNER_LAKILESTER)
    IfNe(LVar0, PARTNER_LAKILESTER)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        Add(LVar1, 20)
        Add(LVar2, 20)
        Add(LVar3, 20)
        Call(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30 * DT)
    EndIf
    Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00C9)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Wait(20 * DT)
    Call(EnablePartnerAI)
    Call(PutPartnerAway)
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_GangRetreat) = {
    Thread
        Call(PlaySoundAtNpc, NPC_FlyingMagikoopa, SOUND_FLO_MAGIKOOPA_FLY_AWAY, SOUND_SPACE_DEFAULT)
        Call(SetNpcFlagBits, NPC_FlyingMagikoopa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(InterpNpcYaw, NPC_FlyingMagikoopa, 270, 0)
        Call(LoadPath, 60 * DT, Ref(N(RetreatPath_Magikoopa)), ARRAY_COUNT(N(RetreatPath_Magikoopa)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_FlyingMagikoopa, LVar1, LVar2, LVar3)
            Wait(1)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(15 * DT)
    Thread
        Call(PlaySoundAtNpc, NPC_Lakitu_01, SOUND_FLO_LAKITU_FLY_AWAY, SOUND_SPACE_DEFAULT)
        Call(SetNpcFlagBits, NPC_Lakitu_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(InterpNpcYaw, NPC_Lakitu_01, 270, 0)
        Call(LoadPath, 60 * DT, Ref(N(RetreatPath_Lakitu_01)), ARRAY_COUNT(N(RetreatPath_Lakitu_01)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            Wait(1)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Lakitu_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(InterpNpcYaw, NPC_Lakitu_02, 270, 0)
        Call(LoadPath, 70 * DT, Ref(N(RetreatPath_Lakitu_02)), ARRAY_COUNT(N(RetreatPath_Lakitu_02)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
            Wait(1)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(PlaySoundAtNpc, NPC_Lakitu_03, SOUND_FLO_LAKITU_FLY_AWAY, SOUND_SPACE_DEFAULT)
    Call(SetNpcFlagBits, NPC_Lakitu_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(InterpNpcYaw, NPC_Lakitu_03, 270, 0)
    Call(LoadPath, 80 * DT, Ref(N(RetreatPath_Lakitu_03)), ARRAY_COUNT(N(RetreatPath_Lakitu_03)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Lakitu_03, LVar1, LVar2, LVar3)
        Wait(1)
        IfNe(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_ChargeAtPlayer) = {
    Wait(5)
    Call(IsPlayerWithin, 40, 0, 200, LVar0)
    IfEq(LVar0, 0)
        Set(LVar3, 45)
    Else
        Set(LVar3, 25)
    EndIf
    Set(LVar4, LVar3)
    Add(LVar4, -5)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar2, -61)
        ChildThread
            Call(SetNpcFlagBits, NPC_Lakitu_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(NpcMoveTo, NPC_Lakitu_01, LVar0, 55, LVar3)
        EndChildThread
        ChildThread
            Call(SetNpcFlagBits, NPC_Lakitu_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(NpcMoveTo, NPC_Lakitu_02, LVar0, 55, LVar3)
        EndChildThread
        ChildThread
            Call(SetNpcFlagBits, NPC_Lakitu_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(NpcMoveTo, NPC_Lakitu_03, LVar0, 55, LVar3)
        EndChildThread
        Wait(LVar4)
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_GangDefeated) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, 65, LVar1, 80)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(AdjustCam, CAM_DEFAULT, Float(8.0 / DT), 0, 450, Float(17.0), Float(-6.0))
    Call(SpeakToPlayer, NPC_FlyingMagikoopa, ANIM_FlyingMagikoopa_Yellow_Anim09, ANIM_FlyingMagikoopa_Yellow_Anim01, 0, MSG_CH6_00BB)
    Wait(20 * DT)
    Exec(N(EVS_GangRetreat))
    Wait(80 * DT)
    Call(AdjustCam, CAM_DEFAULT, Float(8.0 / DT), 0, 300, Float(19.0), Float(-8.5))
    Call(GetCurrentPartnerID, LVar0)
    Call(BringPartnerOut, PARTNER_LAKILESTER)
    IfNe(LVar0, PARTNER_LAKILESTER)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        Add(LVar1, 20)
        Add(LVar2, 20)
        Add(LVar3, 20)
        Call(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30 * DT)
    EndIf
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00C1)
    Call(EnablePartnerAI)
    Wait(20 * DT)
    Call(PutPartnerAway)
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Set(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
    Call(DisablePlayerInput, FALSE)
    Call(AwaitPlayerApproach, -250, 0, 50)
    Call(DisablePlayerInput, TRUE)
    Call(GetCurrentPartnerID, LVar0)
    Call(BringPartnerOut, PARTNER_LAKILESTER)
    IfNe(LVar0, PARTNER_LAKILESTER)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        Add(LVar1, 20)
        Add(LVar2, 20)
        Add(LVar3, 20)
        Call(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30 * DT)
    EndIf
    Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00C2)
    Call(EnablePartnerAI)
    Call(PutPartnerAway)
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Magikoopa) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 1000)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Lakitu) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, 3)
                Call(SetNpcPos, NPC_Magikoopa, NPC_DISPOSE_LOCATION)
                Call(SetNpcPos, NPC_FlyingMagikoopa, -55, 15, 35)
                Call(GetNpcYaw, NPC_Magikoopa, LVar0)
                Call(SetNpcYaw, NPC_FlyingMagikoopa, 90)
                Call(InterpPlayerYaw, 180, 0)
                Call(SetPlayerPos, 30, 0, 80)
                Call(SetNpcYaw, NPC_Lakitu_01, 90)
                Call(SetNpcPos, NPC_Lakitu_01, -20, 15, 30)
                Call(SetNpcYaw, NPC_Lakitu_02, 270)
                Call(SetNpcPos, NPC_Lakitu_02, 65, 15, 30)
                Call(SetNpcYaw, NPC_Lakitu_03, 270)
                Call(SetNpcPos, NPC_Lakitu_03, 120, 15, 30)
                Exec(N(EVS_Scene_GangDefeated))
            EndIf
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ReactionFacePlayer) = {
    Switch(MV_ReactingNpc)
        CaseEq(0)
            Call(NpcFacePlayer, NPC_Magikoopa, 1)
        CaseEq(1)
            Call(NpcFacePlayer, NPC_Lakitu_01, 1)
        CaseEq(2)
            Call(NpcFacePlayer, NPC_Lakitu_02, 1)
        CaseEq(3)
            Call(NpcFacePlayer, NPC_Lakitu_03, 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_FirstReactionDialogue) = {
    Switch(MV_ReactingNpc)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_Magikoopa, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 16, MSG_CH6_00B9)
            Call(InterpNpcYaw, NPC_Magikoopa, 90, 0)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_Lakitu_01, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00BF)
            Call(InterpNpcYaw, NPC_Lakitu_01, 90, 0)
        CaseEq(2)
            Call(SpeakToPlayer, NPC_Lakitu_02, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00BF)
            Call(InterpNpcYaw, NPC_Lakitu_02, 270, 0)
        CaseEq(3)
            Call(SpeakToPlayer, NPC_Lakitu_03, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00BF)
            Call(InterpNpcYaw, NPC_Lakitu_03, 270, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SecondReactionDialogue) = {
    Switch(MV_ReactingNpc)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_Magikoopa, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 16, MSG_CH6_00BA)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_Lakitu_01, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00C0)
        CaseEq(2)
            Call(SpeakToPlayer, NPC_Lakitu_02, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00C0)
        CaseEq(3)
            Call(SpeakToPlayer, NPC_Lakitu_03, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00C0)
    EndSwitch
    Call(SetNpcVar, NPC_Magikoopa, 0, 1)
    Wait(5)
    Exec(N(EVS_ChargeAtPlayer))
    Return
    End
};

EvtScript N(EVS_GenericHitReaction) = {
    IfGe(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(func_802D2C14, 1)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(AdjustCam, CAM_DEFAULT, Float(8.0 / DT), 0, 300, Float(17.0), Float(-6.0))
    ExecWait(N(EVS_ReactionFacePlayer))
    Switch(AB_FLO_GuardedMachineHitCount)
        CaseEq(0)
            ExecWait(N(EVS_FirstReactionDialogue))
            Add(AB_FLO_GuardedMachineHitCount, 1)
            Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
        CaseEq(1)
            ExecWait(N(EVS_SecondReactionDialogue))
    EndSwitch
    Call(func_802D2C14, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_HitReaction_Magikoopa) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 0)
        ExecWait(N(EVS_GenericHitReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitReaction_Lakitu_01) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 1)
        ExecWait(N(EVS_GenericHitReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitReaction_Lakitu_02) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 2)
        ExecWait(N(EVS_GenericHitReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitReaction_Lakitu_03) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 3)
        ExecWait(N(EVS_GenericHitReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_GenericBombReaction) = {
    IfGe(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(8.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_ReactionFacePlayer))
    IfEq(AB_FLO_GuardedMachineHitCount, 0)
        ExecWait(N(EVS_FirstReactionDialogue))
        Add(AB_FLO_GuardedMachineHitCount, 1)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Else
        ExecWait(N(EVS_SecondReactionDialogue))
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BombReaction_Magikoopa) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 0)
        Call(GetNpcPos, NPC_Magikoopa, LVar0, LVar1, LVar2)
        ExecWait(N(EVS_GenericBombReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_BombReaction_Lakitu_01) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 1)
        Call(GetNpcPos, NPC_Lakitu_01, LVar0, LVar1, LVar2)
        ExecWait(N(EVS_GenericBombReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_BombReaction_Lakitu_02) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 2)
        Call(GetNpcPos, NPC_Lakitu_02, LVar0, LVar1, LVar2)
        ExecWait(N(EVS_GenericBombReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

EvtScript N(EVS_BombReaction_Lakitu_03) = {
    IfEq(MV_ReactingNpc, -1)
        Set(MV_ReactingNpc, 3)
        Call(GetNpcPos, NPC_Lakitu_03, LVar0, LVar1, LVar2)
        ExecWait(N(EVS_GenericBombReaction))
        Set(MV_ReactingNpc, -1)
    EndIf
    Return
    End
};

BombTrigger N(Npc_BombTrigger_01) = {
    .pos = { 5.0f, 0.0f, -10.0f },
    .diameter = 0.0f
};

BombTrigger N(Npc_BombTrigger_02) = {
    .pos = { -5.0f, 0.0f, -20.0f },
    .diameter = 0.0f
};

BombTrigger N(Npc_BombTrigger_03) = {
    .pos = { 50.0f, 0.0f, -10.0f },
    .diameter = 0.0f
};

BombTrigger N(Npc_BombTrigger_04) = {
    .pos = { 105.0f, 0.0f, -10.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_SetupMachineDamageReactions) = {
    Set(MV_ReactingNpc, -1)
    BindTrigger(Ref(N(EVS_HitReaction_Magikoopa)),  TRIGGER_WALL_HAMMER, COLLIDER_o174, 1, 0)
    BindTrigger(Ref(N(EVS_HitReaction_Magikoopa)),  TRIGGER_WALL_HAMMER, COLLIDER_o130, 1, 0)
    BindTrigger(Ref(N(EVS_BombReaction_Magikoopa)), TRIGGER_POINT_BOMB,  Ref(N(Npc_BombTrigger_02)), 1, 0)
    BindTrigger(Ref(N(EVS_BombReaction_Lakitu_01)), TRIGGER_POINT_BOMB,  Ref(N(Npc_BombTrigger_01)), 1, 0)
    BindTrigger(Ref(N(EVS_HitReaction_Lakitu_02)),  TRIGGER_WALL_HAMMER, COLLIDER_o127, 1, 0)
    BindTrigger(Ref(N(EVS_BombReaction_Lakitu_02)), TRIGGER_POINT_BOMB,  Ref(N(Npc_BombTrigger_03)), 1, 0)
    BindTrigger(Ref(N(EVS_HitReaction_Lakitu_03)),  TRIGGER_WALL_HAMMER, COLLIDER_o131, 1, 0)
    BindTrigger(Ref(N(EVS_BombReaction_Lakitu_03)), TRIGGER_POINT_BOMB,  Ref(N(Npc_BombTrigger_04)), 1, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Lakitu) = {
    Switch(AB_FLO_GuardLakituTalkCount)
        CaseEq(0)
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, 3)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 5, MSG_CH6_00B6)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 5, MSG_CH6_00BC)
            EndIf
            Add(AB_FLO_GuardLakituTalkCount, 1)
        CaseEq(1)
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, 3)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 5, MSG_CH6_00B7)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 5, MSG_CH6_00BD)
            EndIf
            Add(AB_FLO_GuardLakituTalkCount, 1)
        CaseEq(2)
            Call(AdjustCam, CAM_DEFAULT, Float(8.0 / DT), 0, 300, Float(19.0), Float(-9.0))
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, 3)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 5, MSG_CH6_00B8)
                Call(NpcFacePlayer, NPC_SELF, 0)
                Wait(15)
                Call(EndSpeech, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 0)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 5, MSG_CH6_00BE)
                Call(NpcFacePlayer, NPC_SELF, 0)
                Wait(15)
                Call(EndSpeech, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0)
            EndIf
            Call(SetNpcVar, NPC_Magikoopa, 0, 1)
            Wait(5)
            Exec(N(EVS_ChargeAtPlayer))
            Call(BindNpcInteract, NPC_Lakitu_01, 0)
            Call(BindNpcInteract, NPC_Lakitu_02, 0)
            Call(BindNpcInteract, NPC_Lakitu_03, 0)
            Call(BindNpcInteract, NPC_Magikoopa, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Magikoopa) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Magikoopa)))
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lakitu)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_FlyingMagikoopa) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakitu_01) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lakitu)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakitu_02) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lakitu)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakitu_03) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lakitu)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

NpcData N(NpcData_MachineGang)[] = {
    {
        .id = NPC_Lakitu_01,
        .pos = { 0.0f, 15.0f, 60.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Lakitu_01),
        .settings = &N(NpcSettings_Lakitu),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
        .tattle = MSG_NpcTattle_PuffPuffOperator,
    },
    {
        .id = NPC_Lakitu_02,
        .pos = { 65.0f, 15.0f, 60.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakitu_02),
        .settings = &N(NpcSettings_Lakitu),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
        .tattle = MSG_NpcTattle_PuffPuffOperator,
    },
    {
        .id = NPC_Lakitu_03,
        .pos = { 135.0f, 15.0f, 35.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakitu_03),
        .settings = &N(NpcSettings_Lakitu),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
        .tattle = MSG_NpcTattle_PuffPuffOperator,
    },
    {
        .id = NPC_Magikoopa,
        .pos = { -60.0f, 0.0f, 50.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Magikoopa),
        .settings = &N(NpcSettings_Magikoopa),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = MAGINO_DROPS,
        .animations = MAGIKOOPA_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_PuffPuffOperator,
    },
    {
        .id = NPC_FlyingMagikoopa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_FlyingMagikoopa),
        .settings = &N(NpcSettings_Magikoopa),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = MAGINO_DROPS,
        .animations = FLYING_MAGIKOOPA_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_PuffPuffOperator,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_MachineGang), BTL_FLO_FORMATION_0B, BTL_FLO_STAGE_06),
    {}
};
