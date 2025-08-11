#include "kkj_25.h"
#include "effects.h"
#include "sprite/player.h"

#define KNOCK_DOWN_MAP_VAR MV_Unk_0A
#include "world/common/complete/KnockDownPlayer.inc.c"

API_CALLABLE(N(SpawnStarsOrbitingKammy1)) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DismissStarsOrbitingKammy1)) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->enabled = false;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetEnergyWaveOrigin)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);

    effect->data.energyInOut->pos.x = posX;
    effect->data.energyInOut->pos.y = posY;
    effect->data.energyInOut->pos.z = posZ;

    return ApiStatus_DONE2;
}

Vec3f N(TwinkArrivePath)[] = {
    {  445.0,    60.0,    0.0 },
    {  480.0,    40.0,  -20.0 },
    {  510.0,    25.0,    0.0 },
};

EvtScript N(EVS_SpawnBowserStarEnergyWaves) = {
    Call(GetNpcPos, LVar8, LVar0, LVar1, LVar2)
    Add(LVar1, Float(54.0))
    PlayEffect(EFFECT_ENERGY_IN_OUT, 4, LVar0, LVar1, LVar2, Float(1.5), -1)
    Loop(0)
        Wait(1)
        Call(GetNpcPos, LVar8, LVar0, LVar1, LVar2)
        Add(LVar1, Float(54.0))
        Call(N(SetEnergyWaveOrigin), LVarF, LVar0, LVar1, LVar2)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_PeachBreaksFree) = {
    Call(DisablePlayerInput, true)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Call(SetPlayerPos, 100, 0, 0)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, false)
        Call(SetNpcPos, NPC_PARTNER, 60, 10, 0)
    Else
        Call(SetNpcPos, NPC_PARTNER, 60, 0, 0)
    EndIf
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcPos, NPC_Bowser_01, 200, 0, 0)
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    Call(SetNpcPos, NPC_Peach_01, 475, 0, 0)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_TiedIdle)
    Call(SetNpcPos, NPC_Kammy_01, 550, 10, -50)
    Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim04)
    Call(SetNpcDecoration, NPC_Bowser_01, 0, NPC_DECORATION_BOWSER_AURA)
    Call(SetNpcDecoration, NPC_Bowser_01, 1, NPC_DECORATION_CHARGED)
    Set(LVar8, NPC_Bowser_01)
    Exec(N(EVS_SpawnBowserStarEnergyWaves))
    Call(SetCamType, CAM_DEFAULT, 0, false)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 30)
    Call(SetCamPosB, CAM_DEFAULT, 0, 20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(30)
    Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(15)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_Peach_01, ANIM_Peach3_TiedShout, ANIM_Peach2_TiedIdle, 0, MSG_CH8_008E)
    Wait(10)
    Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(NpcMoveTo, NPC_Kammy_01, 520, -50, 15)
    Thread
        Wait(10)
        Call(InterpNpcYaw, NPC_Peach_01, 90, 0)
    EndThread
    Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim0B)
    Call(SpeakToPlayer, NPC_Kammy_01, ANIM_BattleKammy_Anim07, ANIM_BattleKammy_Anim0B, 0, MSG_CH8_008F)
    Wait(10)
    Call(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Sad)
    Call(SetNpcPos, NPC_Twink_01, 850, 400, 0)
    Call(SetNpcJumpscale, NPC_Twink_01, Float(0.0))
    Call(NpcJump0, NPC_Twink_01, 530, 45, -50, 30)
    Call(PlaySoundAtNpc, NPC_Kammy_01, SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 530, 45, -50, -1, -1, 0, 3)
    Thread
        Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim0C)
        Call(SetNpcPos, NPC_Kammy_02, 530, 15, -50)
        Call(SetNpcJumpscale, NPC_Kammy_01, Float(0.0))
        Call(NpcJump1, NPC_Kammy_01, 540, 10, -50, 30)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_Kammy_02, Float(0.4))
        Call(NpcJump0, NPC_Kammy_02, 545, 0, -30, 25)
        Call(GetNpcPos, NPC_Kammy_02, LVar0, LVar1, LVar2)
        Add(LVar1, 30)
        Set(LVar3, 20)
        Set(LVar4, 3)
        Call(N(SpawnStarsOrbitingKammy1))
        Set(MV_OrbitingEffectAIdx, LVar0)
        Call(PlaySound, SOUND_KNOCKOUT_CHIRPING)
        Wait(5)
        Call(SetNpcAnimation, NPC_Kammy_02, ANIM_BattleKammy_Anim03)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_Twink_01, Float(0.5))
        Call(NpcJump0, NPC_Twink_01, 445, 60, 0, 30)
        Call(InterpNpcYaw, NPC_Twink_01, 90, 0)
    EndThread
    Wait(50)
    Call(LoadPath, 30, Ref(N(TwinkArrivePath)), ARRAY_COUNT(N(TwinkArrivePath)), EASING_QUADRATIC_IN)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Twink_01, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Idle)
    Call(InterpNpcYaw, NPC_Twink_01, 270, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_0090)
    Wait(10)
    Call(SetNpcJumpscale, NPC_Twink_01, Float(0.0))
    Call(NpcJump0, NPC_Twink_01, 490, 18, 0, 20)
    Wait(10)
    Call(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Back)
    Call(GetNpcPos, NPC_Peach_01, LVar3, LVar4, LVar5)
    Add(LVar4, 20)
    Thread
        Call(GetNpcPos, NPC_Twink_01, LVar0, LVar1, LVar2)
        Loop(2)
            Loop(6)
                Add(LVar1, -1)
                Call(SetNpcPos, NPC_Twink_01, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            PlayEffect(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
            Wait(3)
            Loop(6)
                Add(LVar1, 1)
                Call(SetNpcPos, NPC_Twink_01, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            PlayEffect(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
            Wait(3)
        EndLoop
    EndThread
    Call(SpeakToPlayer, NPC_Peach_01, ANIM_Peach3_TiedTalk, ANIM_Peach3_TiedLaugh, 5, MSG_CH8_0091)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach3_TiedLaugh)
    Set(LVar2, 12)
    Loop(4)
        Call(MakeLerp, 90, 450, LVar2, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Add(LVar0, 90)
            IfGt(LVar0, 359)
                Sub(LVar0, 360)
            EndIf
            Call(InterpNpcYaw, NPC_Peach_01, LVar0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Sub(LVar2, 2)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
    EndLoop
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach1_Idle)
    Call(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Idle)
    Wait(20)
    Set(LVar0, MV_OrbitingEffectAIdx)
    Call(N(DismissStarsOrbitingKammy1))
    Call(SetNpcAnimation, NPC_Kammy_02, ANIM_BattleKammy_Anim00)
    Wait(5)
    Call(InterpNpcYaw, NPC_Twink_01, 90, 0)
    Call(NpcFaceNpc, NPC_Kammy_02, NPC_Kammy_01, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Sad)
    Call(SetNpcAnimation, NPC_Kammy_02, ANIM_BattleKammy_Anim02)
    Call(SetNpcJumpscale, NPC_Kammy_02, Float(1.0))
    Call(GetNpcPos, NPC_Kammy_01, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Sub(LVar2, 5)
    Call(NpcJump0, NPC_Kammy_02, LVar0, LVar1, LVar2, 20)
    Call(SetNpcPos, NPC_Kammy_02, 300, -100, 0)
    Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim04)
    Wait(10)
    Call(SpeakToPlayer, NPC_Kammy_01, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 0, MSG_CH8_0092)
    Wait(10)
    Call(SetNpcVar, NPC_Kammy_01, 0, 1)
    Return
    End
};
