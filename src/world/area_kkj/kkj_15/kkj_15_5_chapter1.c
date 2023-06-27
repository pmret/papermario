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
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_01, 5)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_02, 5)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach_Ch1) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(1)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Carried)
    EVT_SUB(LVar0, 10)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway_Ch1) = {
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_02, 90, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 10)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(7.5))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, 249, -72, 0)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(7.5))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 281, -68, 0)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Door) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_004A)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_BowsersDiary) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 0, 37)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -237, 0, 37)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, -180, -20)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(SetPlayerPos, -164, 0, -53)
    EVT_CALL(InterpPlayerYaw, 225, 0)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(NpcJump0, NPC_PARTNER, -225, 50, -80, 20 * DT)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_004B)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Curious)
    EVT_CALL(ShowChoice, MSG_Choice_0022)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_004C)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, -210, 40, -70, 20 * DT, 0, EASING_LINEAR)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_004D)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Curious)
    EVT_CALL(ShowChoice, MSG_Choice_0023)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_004E)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    EVT_CALL(NpcJump0, NPC_PARTNER, -210, 40, -70, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 0, MSG_Peach_004F)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(ShowChoice, MSG_Choice_0024)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0050)
        EVT_CALL(ShowChoice, MSG_Choice_0025)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0051)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    EVT_CALL(NpcJump0, NPC_PARTNER, -210, 40, -70, 10 * DT)
    EVT_CALL(NpcJump0, NPC_PARTNER, -210, 40, -70, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 0, MSG_Peach_0052)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Shout, ANIM_Peach2_EndShout, 5, MSG_Peach_0053)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 0, MSG_Peach_0054)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, -180, 40, -100, 10 * DT, 0, EASING_LINEAR)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 237, 0, 37)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-12.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 170, -20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_CALL(MakeLerp, 0, 120, 20, EASING_COS_FAST_OVERSHOOT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Bowser, 280, 0, -70)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Bowser, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Bowser, 170, -40, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0055)
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -110, 0, -40)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
        EVT_CALL(NpcJump0, NPC_PARTNER, -168, 38, -112, 10)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_SadStill)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Bowser, -70, -40, 80 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
    EVT_CALL(NpcJump0, NPC_Bowser, -70, 0, -40, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0056)
    EVT_CALL(NpcJump0, NPC_Bowser, -70, 0, -40, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0057)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 240, 0, 37)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 240, 0, 37)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 134, -20)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcPos, NPC_Bowser, -100, 0, -70)
    EVT_CALL(SetNpcYaw, NPC_Bowser, 90)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_01, 280, 0, -70)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_02, 310, 0, -70)
    EVT_CALL(SetPlayerPos, -136, 0, -20)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFaceNpc, NPC_Bowser, NPC_Koopatrol_02, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -50, -30, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -20, -30, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 40)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 5, NPC_Bowser, MSG_Peach_0058)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, NPC_Koopatrol_01, MSG_Peach_0059)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 5, NPC_Bowser, MSG_Peach_005A)
    EVT_EXEC_WAIT(N(EVS_ApproachPeach_Ch1))
    EVT_EXEC_WAIT(N(EVS_PickUpPeach_Ch1))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_005B)
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway_Ch1))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -70, 120, -70)
    EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(TwinkFollowCh1Path1)), ARRAY_COUNT(N(TwinkFollowCh1Path1)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
    EVT_LOOP(2)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 7)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 7)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 7)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 7 * DT)
    EVT_CALL(LoadPath, 15 * DT, EVT_PTR(N(TwinkFollowCh1Path2)), ARRAY_COUNT(N(TwinkFollowCh1Path2)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30 * DT)
    EVT_CALL(FadeOutMusic, 0, 1000 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter1))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupChapter1) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_BowsersDiary)), TRIGGER_WALL_PRESS_A, COLLIDER_o100, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Door)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};
