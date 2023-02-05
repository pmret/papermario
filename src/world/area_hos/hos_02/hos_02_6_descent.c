#include "hos_02.h"

EvtScript N(EVS_DescendStarBeam) = {
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 2, 8)
    EVT_CALL(N(func_80240F68_A17188), MV_StarBeamEffect)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -1105, 230, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_PARTNER, -1105, -171, 220, 5)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 90)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 2)
            EVT_ADD(LVar1, LVar0)
            EVT_CALL(InterpPlayerYaw, LVar1, 0)
            EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_SET(LVar5, LVar4)
    EVT_ADD(LVar5, -10)
    EVT_CALL(MakeLerp, LVar3, -600, 40, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, LVar2, LVar0, LVar4)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar2, LVar0, LVar5)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
