#include "kkj_25.h"
#include "effects.h"

#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/npc/WorldBow.h"

API_CALLABLE(N(func_80240C60_B07660)) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240CD4_B076D4)) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpgradeStarBeam)) {
    gPlayerData.starBeamLevel = 2;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.specialBarsFilled = gPlayerData.maxStarPower * 256;

    sync_status_menu();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240D30_B07730)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
    }

    switch (script->functionTemp[2]) {
        case 0:
            set_screen_overlay_color(0, 208, 0, 0);
            set_screen_overlay_params_front(1, script->functionTemp[1]);
            if (script->functionTemp[1] == 255) {
                script->functionTemp[1] = 0;
                script->functionTemp[2] = 1;
            } else {
                script->functionTemp[1] += 7;
                if (script->functionTemp[1] > 255) {
                    script->functionTemp[1] = 255;
                }
            }
            break;
        case 1:
            set_screen_overlay_color(
                0,
                208,
                (script->functionTemp[1] * 208) / 255,
                (script->functionTemp[1] * 208) / 255
            );
            set_screen_overlay_params_front(1, 255.0f);
            if (script->functionTemp[1] == 255) {
                script->functionTemp[2] = 2;
            }
            script->functionTemp[1] += 14;
            if (script->functionTemp[1] > 255) {
                script->functionTemp[1] = 255;
            }
    }
    return (script->functionTemp[2] == 2) * 2;
}

API_CALLABLE(N(func_80240E54_B07854)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240EB8_B078B8)) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240F2C_B0792C)) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

Vec3f N(D_80248880_B0F280)[] = {
    {  510.0,    30.0,    0.0 },
    {  430.0,    15.0,   15.0 },
    {  350.0,    20.0,    0.0 },
};

EvtScript N(D_802488A4_B0F2A4) = {
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
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
    EVT_CALL(N(func_80240C60_B07660))
    EVT_SET(MV_Unk_01, LVar0)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 90, 0)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach_C0000)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach_C0026)
    EVT_CALL(SpeakToPlayer, NPC_Peach_01, ANIM_Peach_C0001, ANIM_Peach_C0026, 5, MSG_CH8_009C)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 90, 0)
    EVT_CALL(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_009D)
    EVT_WAIT(10)
    EVT_CALL(StopSound, SOUND_22D)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_WISHES, 0, 8)
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Peach_01, ANIM_Peach_C0001, ANIM_Peach_C0026, 5, MSG_CH8_009E)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_CH8_009F)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach_C0002)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach_D000F)
    EVT_WAIT(10)
    EVT_CALL(LoadPath, 20, EVT_PTR(N(D_80248880_B0F280)), 3, EASING_QUADRATIC_IN)
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
    EVT_CALL(PlaySoundAt, SOUND_2051, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 5, LVar0, LVar1, LVar2, 40, 120, 45, 150)
    EVT_WAIT(150)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_RearUpLaugh)
    EVT_CALL(SetNpcDecoration, NPC_Bowser_02, 0, NPC_DECORATION_BOWSER_AURA)
    EVT_CALL(SetNpcDecoration, NPC_Bowser_02, 1, NPC_DECORATION_CHARGED)
    EVT_SET(LVar8, 5)
    EVT_EXEC(N(D_802479C4_B0E3C4))
    EVT_WAIT(5)
    EVT_CALL(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -50)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(LVar0, MV_Unk_01)
    EVT_CALL(N(func_80240CD4_B076D4))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_02, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 0, MSG_CH8_00A0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_Twink_01, 500, 200, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Twink_01, 205, 90, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_Twink_01, SOUND_HIT_NORMAL, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Shock)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, 3, 205, 90, 0, -1, -1, 0, 3)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 8, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.3))
    EVT_CALL(NpcJump0, NPC_Twink_01, 195, 200, 0, 20)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
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
    EVT_CALL(PlaySound, SOUND_2051)
    EVT_WAIT(30)
    EVT_SET(LVar0, NPC_Eldstar)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_SET(LVar0, NPC_Mamar)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_SET(LVar0, NPC_Skolar)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_SET(LVar0, NPC_Muskular)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_SET(LVar0, NPC_Misstar)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_SET(LVar0, NPC_Klevar)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_SET(LVar0, NPC_Kalmar)
    EVT_EXEC(N(D_802488A4_B0F2A4))
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(PlaySoundAt, SOUND_B000001E, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_SETF(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADDF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(func_802CFD30, 8, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(15)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH8_00A1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAt, SOUND_64, 0, LVar0, LVar1, LVar2)
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
        EVT_CALL(func_802CFD30, NPC_Mamar,    FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Skolar,   FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Muskular, FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Misstar,  FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Klevar,   FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Kalmar,   FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(func_802CFD30, NPC_Eldstar,  FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Mamar,    FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Skolar,   FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Muskular, FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Misstar,  FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Klevar,   FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Kalmar,   FOLD_TYPE_NONE, 0, 0, 0, 0)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Eldstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Eldstar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Eldstar, LVar6, LVar7, LVar8, 5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Mamar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Mamar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Mamar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(21)
        EVT_CALL(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Skolar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Skolar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Skolar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22)
        EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Muskular, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Muskular, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Misstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Misstar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(21)
        EVT_CALL(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Klevar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Klevar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Klevar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22)
        EVT_CALL(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Kalmar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Kalmar, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(23)
        EVT_CALL(SetNpcFlagBits, NPC_Twink_01, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Twink_01, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Twink_01, LVar6, LVar7, LVar8, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 2, 100, 28, 10, EVT_FLOAT(2.8), 100)
        EVT_CALL(PlaySound, SOUND_212D)
        EVT_WAIT(115)
        EVT_ADD(LVar1, 20)
        EVT_CALL(PlaySoundAt, SOUND_188, 0, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 110, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 110, 20, 3, 10)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 100, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 100, 20, 3, 15)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 90, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 90, 20, 3, 20)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 110, 20, 3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 110, 20, 3, 25)
    EVT_WAIT(6)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_LOOP(3)
        EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 100, 20, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 100, 20, 3, 30)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 90, 20, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 90, 20, 3, 30)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAt, SOUND_B000001F, 0, 110, 20, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 110, 20, 3, 30)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_CALL(N(UpgradeStarBeam))
    EVT_WAIT(30)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0199, 160, 40)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
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

#define NAME_SUFFIX _Unused2A
#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"
#define NAME_SUFFIX _Unused2B
#include "world/common/npc/Dummy.inc.c"
#define NAME_SUFFIX _Unused2A
#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/StarRod.inc.c"
#define NAME_SUFFIX

s32 N(D_8024A9FC_B113FC)[] = {
      0,    0,   0, 30, EVT_FLOAT(3.0), EVT_FLOAT(1.0),
    450,  -50, 330, 40, EVT_FLOAT(4.0), EVT_FLOAT(2.0),
    280, -100, 350, 50, EVT_FLOAT(5.0), EVT_FLOAT(2.0),
     80, -200, -60, 30, EVT_FLOAT(3.0), EVT_FLOAT(1.0),
    500, -200,  20, 30, EVT_FLOAT(3.0), EVT_FLOAT(1.0),
    350, -120, 350, 50, EVT_FLOAT(5.0), EVT_FLOAT(2.0),
};

EvtScript N(D_8024AA8C_B1148C) = {
    EVT_LOOP(0)
        EVT_IF_GT(MV_Unk_0C, 0)
            EVT_SET(MV_Unk_0D, MV_Unk_0C)
        EVT_END_IF
        EVT_SWITCH(MV_Unk_0C)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(2)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 50, EVT_FLOAT(2.0))
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(3)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(4)
                EVT_USE_BUF(EVT_PTR(N(D_8024A9FC_B113FC)))
                EVT_LOOP(7)
                    EVT_BUF_READ4(LVar0, LVar1, LVar2, LVar3)
                    EVT_FBUF_READ2(LVar4, LVar5)
                    EVT_CALL(PlaySoundAt, SOUND_B000001C, 0, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, LVar4, LVar3)
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, LVar5)
                EVT_END_LOOP
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(5)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(6)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(7)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(3.0))
                EVT_SET(MV_Unk_0C, -1)
            EVT_CASE_EQ(10)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(2.0))
            EVT_CASE_EQ(-1)
                EVT_THREAD
                    EVT_SET(LVar0, MV_Unk_0D)
                    EVT_LOOP(0)
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.7))
                        EVT_WAIT(1)
                        EVT_IF_NE(LVar0, MV_Unk_0D)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_SET(MV_Unk_0C, 0)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_8024ADF8_B117F8)[] = {
    400, -10, 400, 20, 350, -50, 370, 25, 
    300, -30, 340, 25, 350, -40, 310, 20, 
    300, -80, 280, 20, 280, -60, 250, 20, 
    300, -50, 220, 20, 250, -100, 190, 20, 
    280, -70, 160, 20, 250, -50, 130, 20, 
    230, -100, 100, 20, 
};

EvtScript N(D_8024AEA8_B118A8) = {
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Bowser_03, EVT_FLOAT(0.1))
        EVT_CALL(NpcJump0, NPC_Bowser_03, 700, -50, 1000, 100)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -1800, 100, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Bowser_03, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Kammy_05, EVT_FLOAT(0.1))
        EVT_CALL(NpcJump0, NPC_Kammy_05, 600, -250, 1000, 100)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -2160, 100, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Kammy_05, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(MV_Unk_0C, 10)
    EVT_THREAD
        EVT_CALL(MakeLerp, -150, -430, 100, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar2, LVar0)
            EVT_ADD(LVar2, 150)
            EVT_DIV(LVar2, 2)
            EVT_CALL(TranslateGroup, MODEL_g2, LVar0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g31, LVar0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g7, LVar0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g54, LVar0, LVar2, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_USE_BUF(EVT_PTR(N(D_8024ADF8_B117F8)))
        EVT_LOOP(11)
            EVT_BUF_READ4(LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(PlaySoundAt, SOUND_B000001C, 0, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 30)
            EVT_WAIT(LVar3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(120)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BowserDefeated) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(D_8024AA8C_B1148C))
    EVT_CALL(SetPlayerPos, 150, 0, 0)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 110, 10, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PARTNER, 110, 0, 0)
    EVT_END_IF
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -40)
    EVT_ADD(LVar1, 60)
    EVT_SET(LVar3, 20)
    EVT_SET(LVar4, 3)
    EVT_CALL(N(func_80240EB8_B078B8))
    EVT_SET(MV_Unk_00, LVar0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 300, 0, 50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 0, 50)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 375)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 30)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_SET(LVar0, MV_Unk_00)
        EVT_CALL(N(func_80240F2C_B0792C))
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 150)
    EVT_CALL(ClearAmbientSounds, 150)
    EVT_WAIT(10)
    EVT_CALL(SetMusicTrack, 0, SONG_RECOVERED_STAR_ROD, 0, 8)
    EVT_CALL(NpcJump0, NPC_StarRod, 230, 18, 0, 25)
    EVT_CALL(NpcJump0, NPC_StarRod, 190, 18, 0, 20)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_6000C)
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_StarRod, 150, 60, 0, 15)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 14, 150, 60, 0, 1, 330)
    EVT_WAIT(310)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_00AA, 160, 40)
    EVT_CALL(PlaySound, SOUND_22D)
    EVT_CALL(RemoveNpc, NPC_StarRod)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_ThumbsUp)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_SET(LVar1, ANIM_WorldGoombario_Celebrate)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_SET(LVar1, ANIM_WorldKooper_Celebrate)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_SET(LVar1, ANIM_WorldBombette_Celebrate)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_SET(LVar1, ANIM_WorldParakarry_Celebrate)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_SET(LVar1, ANIM_WorldBow_CelebrateSlow)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_SET(LVar1, ANIM_WorldWatt_Celebrate)
        EVT_CASE_EQ(PARTNER_SUSHIE)
            EVT_SET(LVar1, ANIM_WorldSushie_Celebrate)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_SET(LVar1, ANIM_WorldLakilester_Celebrate)
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(PARTNER_SUSHIE)
        EVT_CASE_OR_EQ(PARTNER_BOW)
            EVT_WAIT(30)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_LOOP(3)
                EVT_CALL(GetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
                EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 10)
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Peach_02, ANIM_Peach_C0000, ANIM_Peach_A0001, 0, MSG_CH8_00AB)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach_A0002)
        EVT_CALL(NpcMoveTo, NPC_Peach_02, 200, 0, 85)
        EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach_A0001)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 25)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.2))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Twink_02, 230, 30, 85)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Peach_02, ANIM_Peach_C0000, ANIM_Peach_A0001, 0, MSG_CH8_00AC)
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_8000006B)
    EVT_SET(MV_Unk_0C, 1)
    EVT_CALL(PlaySoundAtPlayer, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_Bowser_01, EMOTE_EXCLAMATION, 0, 20, FALSE, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Peach_02, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_Peach_02, EMOTE_EXCLAMATION, 0, 20, TRUE, 0, 0, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_Peach_02, 90, 0)
    EVT_WAIT(15)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Peach_02, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(3.0), EVT_FLOAT(-1.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 750)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_203C, 0, 220, -43, 350)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 220, -43, 350, EVT_FLOAT(8.0), 40)
    EVT_SET(MV_Unk_0C, 2)
    EVT_WAIT(50)
    EVT_SET(MV_Unk_0B, 10)
    EVT_CALL(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach_C0006)
    EVT_CALL(SetNpcAnimation, NPC_Twink_02, ANIM_Twink_Cringe)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
    EVT_CALL(SetNpcJumpscale, NPC_Bowser_03, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Bowser_03, 300, 0, 40, 20)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EVT_CALL(SetNpcRotation, NPC_Bowser_03, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_03, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_03, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_03, 90, 0)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, MSG_CH8_00AD)
    EVT_CALL(PlaySoundAt, SOUND_203C, 0, 370, -10, 180)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 370, -10, 180, EVT_FLOAT(6.0), 40)
    EVT_SET(MV_Unk_0C, 3)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Peach_02, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Twink_02, 90, 0)
    EVT_WAIT(30)
    EVT_CALL(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(5.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1100)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Walk)
        EVT_CALL(NpcMoveTo, NPC_Bowser_03, 450, 0, 140)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_SET(MV_Unk_0C, 4)
    EVT_WAIT(155)
    EVT_CALL(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToNpc, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, NPC_Kammy_05, MSG_CH8_00AE)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAt, SOUND_203C, 0, 350, 50, -100)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 350, 50, -100, EVT_FLOAT(4.0), 20)
    EVT_SET(MV_Unk_0C, 5)
    EVT_WAIT(25)
    EVT_CALL(SpeakToNpc, NPC_Kammy_05, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 512, NPC_Bowser_03, MSG_CH8_00AF)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_203C, 0, 570, 0, 100)
        EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 570, 0, 100, EVT_FLOAT(4.0), 20)
        EVT_SET(MV_Unk_0C, 6)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SpeakToNpc, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, NPC_Kammy_05, MSG_CH8_00B0)
    EVT_SET(MV_Unk_0B, -1)
    EVT_WAIT(20)
    EVT_CALL(StopSound, SOUND_3BC)
    EVT_CALL(PlaySoundAt, SOUND_230, 0, 500, 0, 100)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 500, 0, 100, EVT_FLOAT(8.0), 90)
    EVT_SET(MV_Unk_0C, 7)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_00B1, 160, 40)
    EVT_CALL(N(func_80240D30_B07730))
    EVT_CALL(TranslateGroup, MODEL_Root, -200, 0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o128)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -200)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Peach_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -200)
    EVT_CALL(SetNpcPos, NPC_Peach_02, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Twink_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -200)
    EVT_CALL(SetNpcPos, NPC_Twink_02, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 500)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1100)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Kammy_05, 90, 0)
    EVT_WAIT(5)
    EVT_CALL(SetNpcRotationPivot, NPC_Bowser_03, 34)
    EVT_CALL(SetNpcRotationPivot, NPC_Kammy_05, 12)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(N(func_80240E54_B07854))
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(D_8024AEA8_B118A8))
    EVT_CALL(GotoMap, EVT_PTR("osr_03"), osr_03_ENTRY_5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
