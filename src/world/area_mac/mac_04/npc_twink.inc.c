#include "sprite/player.h"

EvtScript N(EVS_NpcInit_TwinkEndCh4) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, mac_04_ENTRY_5)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath_TwinkArrive)[] = {
    {  -70.0,   106.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {    0.0,     0.0,    0.0 },
};

Vec3f N(FlightPath_TwinkDepart)[] = {
    {    0.0,     0.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {  -70.0,   106.0,    0.0 },
};

EvtScript N(EVS_NpcIdle_TwinkStartCh4) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PushSong, SONG_TWINK_THEME, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Bridge_008F, 160, 40)
    EVT_CALL(GetPlayerPos, LVar4, LVar5, LVar6)
    EVT_SUBF(LVar4, EVT_FLOAT(50.0))
    EVT_ADDF(LVar5, EVT_FLOAT(40.0))
    EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
    EVT_CALL(LoadPath, 35 * DT, EVT_PTR(N(FlightPath_TwinkArrive)), ARRAY_COUNT(N(FlightPath_TwinkArrive)), EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), -10, -300, 15, -9)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0090)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0091)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Chuckle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0092)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), -40, -200, 15, -15)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0093)
    EVT_WAIT(5 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 35 * DT, EVT_PTR(N(FlightPath_TwinkDepart)), ARRAY_COUNT(N(FlightPath_TwinkDepart)), EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_ADD(LVar3, LVar6)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    EVT_CALL(PopSong)
    EVT_SET(GB_StoryProgress, STORY_CH4_MET_WITH_TWINK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TwinkStartCh4) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TwinkStartCh4)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
