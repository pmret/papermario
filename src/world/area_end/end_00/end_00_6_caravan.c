#include "end_00.h"

EvtScript N(EVS_CaravanStopMarching) = {
    EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_SETF(LVar1, LVar1)
    EVT_LOOP(0)
        EVT_ADDF(LVar1, EVT_FLOAT(0.8702 / DT))
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

// unused
EvtScript N(EVS_MoustafaStopMarching) = {
    EVT_CALL(GetNpcPos, NPC_Moustafa, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_LOOP(0)
        EVT_ADDF(LVar0, EVT_FLOAT(0.8702 / DT))
        EVT_CALL(SetNpcPos, NPC_Moustafa, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Caravan) = {
    EVT_CALL(SetNpcScale, NPC_Rhuff, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(0.75))
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Rowf, -1447, -2, 200 * DT)
        EVT_SET(LVar0, NPC_Rowf)
        EVT_EXEC_GET_TID(N(EVS_CaravanStopMarching), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedIdle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedTalk)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedCheer)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedIdle)
        EVT_WAIT(60 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedTalk)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedCheer)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedIdle)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedWalk)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_Rowf, -785, -2, 300 * DT)
        EVT_CALL(SetNpcPos, NPC_Rowf, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Rhuff, -1412, -2, 200 * DT)
        EVT_SET(LVar0, NPC_Rhuff)
        EVT_EXEC_GET_TID(N(EVS_CaravanStopMarching), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_PackedIdle)
        EVT_WAIT(220 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_PackedWalk)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_Rhuff, -750, -2, 300 * DT)
        EVT_CALL(SetNpcPos, NPC_Rhuff, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Moustafa, -1380, 2, 180 * DT)
        EVT_SET(LVar0, NPC_Moustafa)
        EVT_EXEC_GET_TID(N(EVS_CaravanStopMarching), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Shout)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Talk)
        EVT_WAIT(30 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Moustafa, 90, 0)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Shout)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Talk)
        EVT_WAIT(30 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Moustafa, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Shout)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Talk)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Run)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_Moustafa, -1360, 2, 180 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(NpcMoveTo, NPC_Mouser1, -1342, 2, 180 * DT)
        EVT_SET(LVar0, NPC_Mouser1)
        EVT_EXEC_GET_TID(N(EVS_CaravanStopMarching), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_IdleOnlyBlink)
        EVT_WAIT(110 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_Whisper)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_IdleOnlyBlink)
        EVT_WAIT(90 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_Run)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_Mouser1, -1330, 2, 180 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(NpcMoveTo, NPC_Mouser2, -1312, 2, 180 * DT)
        EVT_SET(LVar0, NPC_Mouser2)
        EVT_EXEC_GET_TID(N(EVS_CaravanStopMarching), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_Mouser2, ANIM_Mouser_Blue_IdleOnlyBlink)
        EVT_WAIT(230 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mouser2, ANIM_Mouser_Blue_Run)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_Mouser2, -1300, 2, 180 * DT)
    EVT_END_THREAD
    // tutankoopa is chased around by chomp
    EVT_THREAD
        EVT_WAIT(240 * DT)
        EVT_CALL(NpcMoveTo, NPC_Tutankoopa1, -1540, 30, 60 * DT)
        EVT_WAIT(210 * DT)
        EVT_CALL(SetNpcPos, NPC_Tutankoopa1, -1350, 0, 30 * DT)
        EVT_CALL(SetNpcYaw, NPC_Tutankoopa1, 90)
        EVT_CALL(NpcMoveTo, NPC_Tutankoopa1, -1110, 30, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Tutankoopa1, ANIM_Tutankoopa_LevitateStill)
        EVT_CALL(MakeLerp, 0, 90, 5, EASING_LINEAR)
        EVT_LOOP(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Tutankoopa1, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20 * DT)
        EVT_CALL(ShowEmote, NPC_Tutankoopa1, EMOTE_ELLIPSIS, 0, 60 * DT, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(60 * DT)
        EVT_CALL(MakeLerp, 90, 0, 5, EASING_LINEAR)
        EVT_LOOP(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Tutankoopa1, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_Tutankoopa1, ANIM_Tutankoopa_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Tutankoopa1, 270, 7)
        EVT_WAIT(15 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Tutankoopa1, 90, 7)
        EVT_WAIT(15 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Tutankoopa1, 270, 7)
        EVT_WAIT(15 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Tutankoopa1, ANIM_Tutankoopa_Lift)
        EVT_CALL(SetNpcJumpscale, NPC_Tutankoopa1, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_Tutankoopa1, -1140, 0, 30, 15 * DT)
        EVT_CALL(NpcJump0, NPC_Tutankoopa1, -1170, 0, 30, 15 * DT)
        EVT_CALL(NpcJump0, NPC_Tutankoopa1, -1200, 0, 30, 15 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(240 * DT)
        EVT_CALL(NpcMoveTo, NPC_ChainChomp1, -1480, 30, 60 * DT)
        EVT_WAIT(210 * DT)
        EVT_CALL(SetNpcPos, NPC_ChainChomp1, -1410, 0, 30 * DT)
        EVT_CALL(SetNpcYaw, NPC_ChainChomp1, 90)
        EVT_CALL(NpcMoveTo, NPC_ChainChomp1, -690, 30, 90 * DT)
        EVT_CALL(SetNpcPos, NPC_ChainChomp1, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

Vec3f N(BuzzarFlightPath)[] = {
    { -805.0,   100.0,  -80.0 },
    { -675.0,   100.0, -230.0 },
    { -805.0,   100.0, -280.0 },
    { -935.0,   100.0, -230.0 },
    { -805.0,   100.0,  -80.0 },
};

EvtScript N(EVS_ParadePhase_BuzzarNest) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BUZZAR + 175)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(200 * DT)
    EVT_CALL(ShowEmote, NPC_Buzzar, EMOTE_SHOCK, 45, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim03)
    EVT_CALL(NpcFlyTo, NPC_Buzzar, -855, 100, -180, 60 * DT, 0, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick1, ANIM_ParadeChick_EggTremble)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick2, ANIM_ParadeChick_EggTremble)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick3, ANIM_ParadeChick_EggTremble)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick1, ANIM_ParadeChick_BreakEgg)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick2, ANIM_ParadeChick_BreakEggFwd)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick3, ANIM_ParadeChick_BreakEgg)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick1, ANIM_ParadeChick_Chirp)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick2, ANIM_ParadeChick_ChirpFwd)
    EVT_CALL(SetNpcAnimation, NPC_VultureChick3, ANIM_ParadeChick_Chirp)
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Buzzar, 90, 0)
    EVT_CALL(NpcFlyTo, NPC_Buzzar, -805, 100, -80, 30 * DT, 0, EASING_LINEAR)
    EVT_THREAD
        EVT_LOOP(6)
            EVT_WAIT(20 * DT)
            EVT_CALL(InterpNpcYaw, NPC_Buzzar, 270, 0)
            EVT_WAIT(40 * DT)
            EVT_CALL(InterpNpcYaw, NPC_Buzzar, 90, 0)
            EVT_WAIT(20 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(BuzzarFlightPath)), ARRAY_COUNT(N(BuzzarFlightPath)), EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(GetNextPathPos)
                EVT_CALL(SetNpcPos, NPC_Buzzar, LVar1, LVar2, LVar3)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
