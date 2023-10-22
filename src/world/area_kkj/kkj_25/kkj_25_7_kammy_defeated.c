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
    EVT_LOOP(0)
        EVT_LOOP(5)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 1)
            EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_LOOP(5)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, -1)
            EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_KammyDefeated) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_CALL(SetPlayerPos, 100, 0, 0)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 60, 10, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PARTNER, 60, 0, 0)
    EVT_END_IF
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetNpcPos, NPC_Kammy_04, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_SET(LVar3, 20)
    EVT_SET(LVar4, 3)
    EVT_CALL(N(SpawnStarsOrbitingKammy2))
    EVT_SET(MV_OrbitingEffectBIdx, LVar0)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 90, 0)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach_01, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_CH8_009C)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 90, 0)
    EVT_CALL(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_009D)
    EVT_WAIT(10)
    EVT_CALL(StopSound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_WISHES, 0, 8)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Peach_01, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_CH8_009E)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_CH8_009F)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_LowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach3_Pray)
    EVT_WAIT(10)
    EVT_CALL(LoadPath, 20, EVT_PTR(N(TwinkStrikeBowserPath)), ARRAY_COUNT(N(TwinkStrikeBowserPath)), EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Twink_01, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 245)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAt, SOUND_WISH_ASCENDING, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 5, LVar0, LVar1, LVar2, 40, 120, 45, 150)
    EVT_WAIT(150)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_RearUpLaugh)
    EVT_CALL(SetNpcDecoration, NPC_Bowser_02, 0, NPC_DECORATION_BOWSER_AURA)
    EVT_CALL(SetNpcDecoration, NPC_Bowser_02, 1, NPC_DECORATION_CHARGED)
    EVT_SET(LVar8, NPC_Bowser_02)
    EVT_EXEC(N(EVS_SpawnBowserStarEnergyWaves))
    EVT_WAIT(5)
    EVT_CALL(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -50)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(LVar0, MV_OrbitingEffectBIdx)
    EVT_CALL(N(DismissStarsOrbitingKammy2))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_02, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 0, MSG_CH8_00A0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_Twink_01, 500, 200, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Twink_01, 205, 90, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_Twink_01, SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Shock)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 205, 90, 0, -1, -1, 0, 3)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 8, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.3))
    EVT_CALL(NpcJump0, NPC_Twink_01, 195, 200, 0, 20)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Bowser_02, 90, 0)
        EVT_WAIT(15)
        EVT_CALL(InterpNpcYaw, NPC_Bowser_02, 270, 0)
        EVT_WAIT(15)
        EVT_CALL(InterpNpcYaw, NPC_Bowser_02, 90, 0)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Walk)
        EVT_CALL(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 50)
        EVT_CALL(NpcMoveTo, NPC_Bowser_02, LVar0, LVar2, 50)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 300, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 5, 100, 45, -66, 40, 50, 45, 80)
    EVT_CALL(PlaySound, SOUND_WISH_ASCENDING)
    EVT_WAIT(30)
    EVT_SET(LVar0, NPC_Eldstar)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_SET(LVar0, NPC_Mamar)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_SET(LVar0, NPC_Skolar)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_SET(LVar0, NPC_Muskular)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_SET(LVar0, NPC_Misstar)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_SET(LVar0, NPC_Klevar)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_SET(LVar0, NPC_Kalmar)
    EVT_EXEC(N(AddStarSpiritHovering))
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_APPEAR, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_SETF(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADDF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(SetNpcImgFXParams, NPC_Eldstar, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(15)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAt, SOUND_MULTIPLE_STAR_SPIRITS_APPEAR, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_SETF(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADDF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(SetNpcImgFXParams, NPC_Mamar,    IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Skolar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Muskular, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Misstar,  IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Klevar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcImgFXParams, NPC_Eldstar,  IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Mamar,    IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Skolar,   IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Muskular, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Misstar,  IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Klevar,   IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Twink_01, 140, 65, 30, 20)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_00A2)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A3)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A4)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Eldstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Eldstar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Eldstar, LVar6, LVar7, LVar8, 5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Mamar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Mamar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Mamar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(21)
        EVT_CALL(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Skolar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Skolar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Skolar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22)
        EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Muskular, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Muskular, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Misstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Misstar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(21)
        EVT_CALL(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Klevar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Klevar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Klevar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22)
        EVT_CALL(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Kalmar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Kalmar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(23)
        EVT_CALL(SetNpcFlagBits, NPC_Twink_01, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Twink_01, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Twink_01, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 2, 100, 28, 10, EVT_FLOAT(2.8), 100)
        EVT_CALL(PlaySound, SOUND_RELEASE_ENERGY)
        EVT_WAIT(115)
        EVT_ADD(LVar1, 20)
        EVT_CALL(PlaySoundAt, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 110, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 110, 20, 3, 10)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 100, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 100, 20, 3, 15)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 90, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 90, 20, 3, 20)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 110, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 110, 20, 3, 25)
    EVT_WAIT(6)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_LOOP(3)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 100, 20, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 100, 20, 3, 30)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 90, 20, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 90, 20, 3, 30)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 110, 20, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 110, 20, 3, 30)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_CALL(N(UpgradeStarBeam))
    EVT_WAIT(30)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0199, 160, 40)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 45)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(SpeakToPlayer, NPC_Bowser_02, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_00A5)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_02, 270, 0)
    EVT_WAIT(25)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
        EVT_CALL(PlayerJump, 100, 0, 0, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 20)
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Bowser_02, 0, 1)
    EVT_RETURN
    EVT_END
};
