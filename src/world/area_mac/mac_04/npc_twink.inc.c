#include "sprite/player.h"

EvtScript N(EVS_NpcInit_TwinkEndCh4) = {
    Call(GetEntryID, LVar0)
    IfNe(LVar0, mac_04_ENTRY_5)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
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
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Call(PushSong, SONG_TWINK_THEME, 0)
    Call(ShowMessageAtScreenPos, MSG_MAC_Bridge_008F, 160, 40)
    Call(GetPlayerPos, LVar4, LVar5, LVar6)
    SubF(LVar4, Float(50.0))
    AddF(LVar5, Float(40.0))
    Call(InterpNpcYaw, NPC_Twink, 90, 0)
    Call(LoadPath, 35 * DT, Ref(N(FlightPath_TwinkArrive)), ARRAY_COUNT(N(FlightPath_TwinkArrive)), EASING_COS_IN_OUT)
    Loop(0)
        Call(GetNextPathPos)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), -10, -300, 15, -9)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0090)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(15 * DT)
    Call(SetNpcJumpscale, NPC_Twink, Float(1.0))
    Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 10 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0091)
    Call(SetPlayerAnimation, ANIM_Mario1_Chuckle)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0092)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), -40, -200, 15, -15)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Bridge_0093)
    Wait(5 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(InterpNpcYaw, NPC_Twink, 270, 0)
    Call(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    Call(LoadPath, 35 * DT, Ref(N(FlightPath_TwinkDepart)), ARRAY_COUNT(N(FlightPath_TwinkDepart)), EASING_QUADRATIC_IN)
    Loop(0)
        Call(GetNextPathPos)
        Add(LVar1, LVar4)
        Add(LVar2, LVar5)
        Add(LVar3, LVar6)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    Call(PopSong)
    Set(GB_StoryProgress, STORY_CH4_MET_WITH_TWINK)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TwinkStartCh4) = {
    IfEq(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TwinkStartCh4)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};
