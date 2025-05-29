#include "kkj_15.h"
#include "sprite/player.h"

Vec3f N(TwinkFollowCh1Path1)[] = {
    {  -70.0,   120.0,  -70.0 },
    {  -40.0,   110.0,  -70.0 },
    {  -10.0,   120.0,  -70.0 },
    {   20.0,   110.0,  -70.0 },
    {   50.0,   120.0,  -70.0 },
    {   80.0,   110.0,  -70.0 },
    {  110.0,   120.0,  -70.0 },
    {  140.0,   110.0,  -70.0 },
    {  170.0,   120.0,  -70.0 },
    {  200.0,   110.0,  -70.0 },
    {  230.0,   120.0,  -70.0 },
};

Vec3f N(TwinkFollowCh1Path2)[] = {
    {  230.0,   120.0,  -70.0 },
    {  220.0,    60.0,  -70.0 },
    {  250.0,    40.0,  -70.0 },
};

EvtScript N(EVS_ApproachPeach_Ch1) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Sub(LVar0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_01, 5)
        Call(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_02, 5)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10 * DT)
    Return
    End
};

EvtScript N(EVS_PickUpPeach_Ch1) = {
    Thread
        Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(1)
    Loop(4)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach2_Carried)
    Sub(LVar0, 10)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway_Ch1) = {
    Call(InterpNpcYaw, NPC_Koopatrol_02, 90, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
            Add(LVar0, 10)
            Add(LVar2, 2)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(7.5))
        Call(NpcMoveTo, NPC_Koopatrol_01, 249, -72, 0)
        Call(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(7.5))
        Call(NpcMoveTo, NPC_Koopatrol_02, 281, -68, 0)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        Call(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Inspect_Door) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_004A)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_BowsersDiary) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 50, 0, 37)
        Call(SetPanTarget, CAM_DEFAULT, -237, 0, 37)
        Call(SetCamDistance, CAM_DEFAULT, 300)
        Call(SetCamPosA, CAM_DEFAULT, -180, -20)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(SetPlayerPos, -164, 0, -53)
    Call(InterpPlayerYaw, 225, 0)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    Call(DisablePartnerAI, 0)
    Call(NpcJump0, NPC_PARTNER, -225, 50, -80, 20 * DT)
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_004B)
    Call(SetPlayerAnimation, ANIM_Peach2_Curious)
    Call(ShowChoice, MSG_Choice_0022)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_004C)
    Call(NpcFlyTo, NPC_PARTNER, -210, 40, -70, 20 * DT, 0, EASING_LINEAR)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_004D)
    Call(SetPlayerAnimation, ANIM_Peach2_Curious)
    Call(ShowChoice, MSG_Choice_0023)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_004E)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    Call(NpcJump0, NPC_PARTNER, -210, 40, -70, 10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 0, MSG_Peach_004F)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(ShowChoice, MSG_Choice_0024)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0050)
        Call(ShowChoice, MSG_Choice_0025)
    EndIf
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0051)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    Call(NpcJump0, NPC_PARTNER, -210, 40, -70, 10 * DT)
    Call(NpcJump0, NPC_PARTNER, -210, 40, -70, 10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 0, MSG_Peach_0052)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Shout, ANIM_Peach2_EndShout, 5, MSG_Peach_0053)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 0, MSG_Peach_0054)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(NpcFlyTo, NPC_PARTNER, -180, 40, -100, 10 * DT, 0, EASING_LINEAR)
    Wait(10 * DT)
    Call(SetMusic, 0, SONG_BOWSER_THEME, 0, VOL_LEVEL_FULL)
    Call(SetPanTarget, CAM_DEFAULT, 237, 0, 37)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-12.0))
    Call(SetCamPosB, CAM_DEFAULT, 170, -20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(30 * DT)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_OPEN, 0)
        Call(MakeLerp, 0, 120, 20, EASING_COS_FAST_OVERSHOOT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Bowser, 280, 0, -70)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    Call(SetNpcSpeed, NPC_Bowser, Float(3.0 / DT))
    Call(NpcMoveTo, NPC_Bowser, 170, -40, 0)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0055)
    Thread
        Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
        Wait(10 * DT)
        Call(SetPanTarget, CAM_DEFAULT, -110, 0, -40)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
        Call(NpcJump0, NPC_PARTNER, -168, 38, -112, 10)
        Wait(30 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_SadStill)
    EndThread
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Bowser, -70, -40, 80 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
    Call(NpcJump0, NPC_Bowser, -70, 0, -40, 10 * DT)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0056)
    Call(NpcJump0, NPC_Bowser, -70, 0, -40, 10 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0057)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 240, 0, 37)
    Call(SetPanTarget, CAM_DEFAULT, 240, 0, 37)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPosB, CAM_DEFAULT, 134, -20)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(5 * DT)
    Call(SetNpcPos, NPC_Bowser, -100, 0, -70)
    Call(SetNpcYaw, NPC_Bowser, 90)
    Call(SetNpcPos, NPC_Koopatrol_01, 280, 0, -70)
    Call(SetNpcPos, NPC_Koopatrol_02, 310, 0, -70)
    Call(SetPlayerPos, -136, 0, -20)
    Thread
        Loop(0)
            Call(NpcFaceNpc, NPC_Bowser, NPC_Koopatrol_02, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, -50, -30, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_02, -20, -30, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EndThread
    Loop(0)
        Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        Sub(LVar0, 40)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 5, NPC_Bowser, MSG_Peach_0058)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, NPC_Koopatrol_01, MSG_Peach_0059)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 5, NPC_Bowser, MSG_Peach_005A)
    ExecWait(N(EVS_ApproachPeach_Ch1))
    ExecWait(N(EVS_PickUpPeach_Ch1))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_005B)
    ExecWait(N(EVS_CarryPeachAway_Ch1))
    Wait(10 * DT)
    Call(SetNpcPos, NPC_PARTNER, -70, 120, -70)
    Call(LoadPath, 80 * DT, Ref(N(TwinkFollowCh1Path1)), ARRAY_COUNT(N(TwinkFollowCh1Path1)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
    Loop(2)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 7)
        Wait(5)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 7)
        Wait(5)
    EndLoop
    Call(InterpNpcYaw, NPC_PARTNER, 270, 7)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 7 * DT)
    Call(LoadPath, 15 * DT, Ref(N(TwinkFollowCh1Path2)), ARRAY_COUNT(N(TwinkFollowCh1Path2)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30 * DT)
    Call(FadeOutMusic, 0, 1000 * DT)
    ExecWait(N(EVS_EndPeachChapter1))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupChapter1) = {
    BindTrigger(Ref(N(EVS_Inspect_BowsersDiary)), TRIGGER_WALL_PRESS_A, COLLIDER_o100, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_Door)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};
