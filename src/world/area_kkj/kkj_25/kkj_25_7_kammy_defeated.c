#include "kkj_25.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(SpawnStarsOrbitingKammy2)) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DismissStarsOrbitingKammy2)) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->enabled = FALSE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpgradeStarBeam)) {
    gPlayerData.starBeamLevel = 2;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.starPower = gPlayerData.maxStarPower * SP_PER_BAR;

    sync_status_bar();
    return ApiStatus_DONE2;
}

Vec3f N(TwinkStrikeBowserPath)[] = {
    {  510.0,    30.0,    0.0 },
    {  430.0,    15.0,   15.0 },
    {  350.0,    20.0,    0.0 },
};

EvtScript N(AddStarSpiritHovering) = {
    Loop(0)
        Loop(5)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Add(LVar2, 1)
            Call(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Wait(2)
        EndLoop
        Loop(5)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Add(LVar2, -1)
            Call(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Wait(2)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_KammyDefeated) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Call(SetPlayerPos, 100, 0, 0)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, FALSE)
        Call(SetNpcPos, NPC_PARTNER, 60, 10, 0)
    Else
        Call(SetNpcPos, NPC_PARTNER, 60, 0, 0)
    EndIf
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.5))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(GetNpcPos, NPC_Kammy_04, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    Set(LVar3, 20)
    Set(LVar4, 3)
    Call(N(SpawnStarsOrbitingKammy2))
    Set(MV_OrbitingEffectBIdx, LVar0)
    Wait(20)
    Call(InterpNpcYaw, NPC_Peach_01, 90, 0)
    Wait(20)
    Call(InterpNpcYaw, NPC_Peach_01, 270, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach_01, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_CH8_009C)
    Wait(10)
    Call(InterpNpcYaw, NPC_Peach_01, 90, 0)
    Call(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_009D)
    Wait(10)
    Call(StopSound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    Call(SetMusicTrack, 0, SONG_PEACH_WISHES, 0, 8)
    Call(InterpNpcYaw, NPC_Peach_01, 270, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_Peach_01, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_CH8_009E)
    Wait(10)
    Call(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_CH8_009F)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_LowerArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach3_Pray)
    Wait(10)
    Call(LoadPath, 20, Ref(N(TwinkStrikeBowserPath)), ARRAY_COUNT(N(TwinkStrikeBowserPath)), EASING_QUADRATIC_IN)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Twink_01, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 245)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Call(PlaySoundAt, SOUND_WISH_ASCENDING, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_STARS_SHIMMER, 5, LVar0, LVar1, LVar2, 40, 120, 45, 150)
    Wait(150)
    Call(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_RearUpLaugh)
    Call(SetNpcDecoration, NPC_Bowser_02, 0, NPC_DECORATION_BOWSER_AURA)
    Call(SetNpcDecoration, NPC_Bowser_02, 1, NPC_DECORATION_CHARGED)
    Set(LVar8, NPC_Bowser_02)
    Exec(N(EVS_SpawnBowserStarEnergyWaves))
    Wait(5)
    Call(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
    Add(LVar0, -50)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Set(LVar0, MV_OrbitingEffectBIdx)
    Call(N(DismissStarsOrbitingKammy2))
    Wait(20)
    Call(SpeakToPlayer, NPC_Bowser_02, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 0, MSG_CH8_00A0)
    Wait(10)
    Call(SetNpcPos, NPC_Twink_01, 500, 200, 0)
    Call(SetNpcJumpscale, NPC_Twink_01, Float(0.0))
    Call(NpcJump0, NPC_Twink_01, 205, 90, 0, 20)
    Call(PlaySoundAtNpc, NPC_Twink_01, SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Shock)
    PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 205, 90, 0, -1, -1, 0, 3)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 8, Float(1.5))
    EndThread
    Call(SetNpcJumpscale, NPC_Twink_01, Float(0.3))
    Call(NpcJump0, NPC_Twink_01, 195, 200, 0, 20)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Thread
        Call(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
        Call(InterpNpcYaw, NPC_Bowser_02, 90, 0)
        Wait(15)
        Call(InterpNpcYaw, NPC_Bowser_02, 270, 0)
        Wait(15)
        Call(InterpNpcYaw, NPC_Bowser_02, 90, 0)
        Wait(20)
        Call(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Walk)
        Call(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
        Add(LVar0, 50)
        Call(NpcMoveTo, NPC_Bowser_02, LVar0, LVar2, 50)
        Call(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
    EndThread
    Wait(15)
    Call(AdjustCam, CAM_DEFAULT, Float(2.0), 0, 300, Float(17.0), Float(-13.0))
    PlayEffect(EFFECT_STARS_SHIMMER, 5, 100, 45, -66, 40, 50, 45, 80)
    Call(PlaySound, SOUND_WISH_ASCENDING)
    Wait(30)
    Set(LVar0, NPC_Eldstar)
    Exec(N(AddStarSpiritHovering))
    Set(LVar0, NPC_Mamar)
    Exec(N(AddStarSpiritHovering))
    Set(LVar0, NPC_Skolar)
    Exec(N(AddStarSpiritHovering))
    Set(LVar0, NPC_Muskular)
    Exec(N(AddStarSpiritHovering))
    Set(LVar0, NPC_Misstar)
    Exec(N(AddStarSpiritHovering))
    Set(LVar0, NPC_Klevar)
    Exec(N(AddStarSpiritHovering))
    Set(LVar0, NPC_Kalmar)
    Exec(N(AddStarSpiritHovering))
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_APPEAR, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    SetF(LVar0, 0)
    Loop(20)
        AddF(LVar0, Float(12.0))
        Call(SetNpcImgFXParams, NPC_Eldstar, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(10)
    Thread
        Wait(15)
        Call(InterpPlayerYaw, 270, 0)
        Wait(15)
        Call(InterpPlayerYaw, 90, 0)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EndThread
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A1)
    Wait(10)
    Call(PlaySoundAt, SOUND_MULTIPLE_STAR_SPIRITS_APPEAR, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    SetF(LVar0, 0)
    Loop(20)
        AddF(LVar0, Float(12.0))
        Call(SetNpcImgFXParams, NPC_Mamar,    IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Skolar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Misstar,  IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Klevar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcImgFXParams, NPC_Eldstar,  IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Mamar,    IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Skolar,   IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Misstar,  IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Klevar,   IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcJumpscale, NPC_Twink_01, Float(0.0))
    Call(NpcJump0, NPC_Twink_01, 140, 65, 30, 20)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Add(LVar0, 15)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10)
    Call(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_00A2)
    Wait(10)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A3)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A4)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(15)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(5)
    Thread
        Call(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Eldstar, Float(3.2))
        Call(GetNpcPos, NPC_Eldstar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Eldstar, LVar6, LVar7, LVar8, 5)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EndThread
    Thread
        Wait(20)
        Call(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Mamar, Float(3.2))
        Call(GetNpcPos, NPC_Mamar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Mamar, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        Wait(21)
        Call(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Skolar, Float(3.2))
        Call(GetNpcPos, NPC_Skolar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Skolar, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        Wait(22)
        Call(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Muskular, Float(3.2))
        Call(GetNpcPos, NPC_Muskular, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Muskular, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        Wait(20)
        Call(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Misstar, Float(3.2))
        Call(GetNpcPos, NPC_Misstar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Misstar, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        Wait(21)
        Call(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Klevar, Float(3.2))
        Call(GetNpcPos, NPC_Klevar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Klevar, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        Wait(22)
        Call(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Kalmar, Float(3.2))
        Call(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Kalmar, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        Wait(23)
        Call(SetNpcFlagBits, NPC_Twink_01, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Twink_01, Float(3.2))
        Call(GetNpcPos, NPC_Twink_01, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Twink_01, LVar6, LVar7, LVar8, 5)
    EndThread
    Thread
        PlayEffect(EFFECT_RADIAL_SHIMMER, 2, 100, 28, 10, Float(2.8), 100)
        Call(PlaySound, SOUND_RELEASE_ENERGY)
        Wait(115)
        Add(LVar1, 20)
        Call(PlaySoundAt, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, Float(0.3), 30)
    EndThread
    Wait(40)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 110, 20, 3)
    PlayEffect(EFFECT_SPARKLES, 0, 110, 20, 3, 10)
    Wait(6)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 100, 20, 3)
    PlayEffect(EFFECT_SPARKLES, 0, 100, 20, 3, 15)
    Wait(6)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 90, 20, 3)
    PlayEffect(EFFECT_SPARKLES, 0, 90, 20, 3, 20)
    Wait(6)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 110, 20, 3)
    PlayEffect(EFFECT_SPARKLES, 0, 110, 20, 3, 25)
    Wait(6)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Loop(3)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 100, 20, 3)
        PlayEffect(EFFECT_SPARKLES, 0, 100, 20, 3, 30)
        Wait(6)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 90, 20, 3)
        PlayEffect(EFFECT_SPARKLES, 0, 90, 20, 3, 30)
        Wait(6)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 110, 20, 3)
        PlayEffect(EFFECT_SPARKLES, 0, 110, 20, 3, 30)
        Wait(6)
    EndLoop
    Call(N(UpgradeStarBeam))
    Wait(30)
    Call(ShowMessageAtScreenPos, MSG_Menus_0199, 160, 40)
    Wait(30)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 45)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Call(SpeakToPlayer, NPC_Bowser_02, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_00A5)
    EndThread
    Wait(5)
    Call(InterpNpcYaw, NPC_Bowser_02, 270, 0)
    Wait(25)
    Call(FadeOutMusic, 0, 500)
    Wait(20)
    Thread
        Call(SetPlayerJumpscale, Float(0.5))
        Call(PlayerJump, 100, 0, 0, 20)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 20)
    EndThread
    Call(SetNpcVar, NPC_Bowser_02, 0, 1)
    Return
    End
};
