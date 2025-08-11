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
    UseBuf(LVar0)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(1.203), 20)
    Wait(1)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(1.5), 20)
    Wait(1)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(2.0), 20)
    Wait(1)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(2.5), 20)
    Wait(1)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(3.0), 20)
    Wait(1)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(3.5), 20)
    Wait(1)
    BufRead3(LVarA, LVarB, LVarC)
    PlayEffect(EFFECT_RING_BLAST, 0, LVarA, LVarB, LVarC, Float(4.0), 80)
    Return
    End
};

EvtScript N(EVS_PlaySmokeFX) = {
    Loop(10)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(RandInt, 30, LVar3)
        Call(RandInt, 30, LVar4)
        Add(LVar0, -15)
        Add(LVar2, 10)
        Add(LVar0, LVar3)
        Add(LVar1, LVar4)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 20)
        Wait(6)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Inspect_Fireplace) = {
    IfEq(MV_InspectingFireplace, true)
        Return
    EndIf
    Set(MV_InspectingFireplace, true)
    Call(DisablePlayerInput, true)
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(250.0), Float(17.5), Float(-10.0))
    EndThread
    Wait(10)
    Thread
        Call(DisablePartnerAI, 0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 25)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
        Call(EnablePartnerAI)
        Call(InterpPlayerYaw, 90, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    Call(PlaySoundAtPlayer, SOUND_FIREPLACE_BURST, SOUND_SPACE_DEFAULT)
    Set(LVar0, Ref(N(ExplosionPositions1)))
    Exec(N(EVS_PlayExplosionFX))
    Set(LVar0, Ref(N(ExplosionPositions2)))
    Exec(N(EVS_PlayExplosionFX))
    Set(LVar0, Ref(N(ExplosionPositions3)))
    Exec(N(EVS_PlayExplosionFX))
    Wait(5)
    Call(SetPlayerAnimation, ANIM_Mario1_Burnt)
    Wait(60)
    ExecWait(N(EVS_PlaySmokeFX))
    Wait(40)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Set(MV_InspectingFireplace, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_SetupFireplace) = {
    BindTrigger(Ref(N(EVS_Inspect_Fireplace)), TRIGGER_WALL_PRESS_A, COLLIDER_o283, 1, 0)
    Return
    End
};
