#include "obk_07.h"
#include "effects.h"
#include "sprite/player.h"

Vec3i N(ExplosionPositions1)[] = {
    {  5,  5, -220 },
    { 10, 10, -200 },
    { 15, 15, -180 },
    { 20, 20, -160 },
    { 25, 25, -140 },
    { 30, 30, -120 },
    { 35, 35, -100 },
};

Vec3i N(ExplosionPositions2)[] = {
    {  -5,  5, -220 },
    { -10, 10, -200 },
    { -15, 15, -180 },
    { -20, 20, -160 },
    { -25, 25, -140 },
    { -30, 30, -120 },
    { -35, 25, -100 },
};

Vec3i N(ExplosionPositions3)[] = {
    { 0, 10, -220 },
    { 0, 20, -200 },
    { 0, 30, -180 },
    { 0, 40, -160 },
    { 0, 50, -140 },
    { 0, 60, -120 },
    { 0, 70, -100 },
};

EvtScript N(EVS_PlayExplosionFX) = {
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(1.203), 20)
    EVT_WAIT(1)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(1.5), 20)
    EVT_WAIT(1)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(2.0), 20)
    EVT_WAIT(1)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(2.5), 20)
    EVT_WAIT(1)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(3.0), 20)
    EVT_WAIT(1)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(3.5), 20)
    EVT_WAIT(1)
    EVT_BUF_READ3(LVarA, LVarB, LVarC)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, EVT_FLOAT(4.0), 80)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlaySmokeFX) = {
    EVT_LOOP(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 30, LVar3)
        EVT_CALL(RandInt, 30, LVar4)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar2, 10)
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 20)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Fireplace) = {
    EVT_IF_EQ(MV_InspectingFireplace, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_InspectingFireplace, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(250.0), EVT_FLOAT(17.5), EVT_FLOAT(-10.0))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 25)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_FIREPLACE_BURST, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, EVT_PTR(N(ExplosionPositions1)))
    EVT_EXEC(N(EVS_PlayExplosionFX))
    EVT_SET(LVar0, EVT_PTR(N(ExplosionPositions2)))
    EVT_EXEC(N(EVS_PlayExplosionFX))
    EVT_SET(LVar0, EVT_PTR(N(ExplosionPositions3)))
    EVT_EXEC(N(EVS_PlayExplosionFX))
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Burnt)
    EVT_WAIT(60)
    EVT_EXEC_WAIT(N(EVS_PlaySmokeFX))
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_SET(MV_InspectingFireplace, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupFireplace) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Fireplace)), TRIGGER_WALL_PRESS_A, COLLIDER_o283, 1, 0)
    EVT_RETURN
    EVT_END
};
