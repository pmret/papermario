#include "kkj_25.h"
#include "effects.h"
#include "sprite/player.h"

#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/npc/WorldBow.h"

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

API_CALLABLE(N(FadeScreenToRedAndWhite)) {
    enum FT_states {
        TEMP_FADE_TO_RED    = 0,
        TEMP_FADE_TO_WHITE  = 1,
        TEMP_FADE_COMPLETE  = 2,
    };
    #define FT_state  functionTemp[2]
    #define FT_alpha  functionTemp[1]

    if (isInitialCall) {
        script->FT_alpha = 0;
        script->FT_state = 0;
    }

    switch (script->FT_state) {
        case TEMP_FADE_TO_RED:
            set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 0, 0);
            set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->FT_alpha);
            if (script->FT_alpha == 255) {
                script->FT_alpha = 0;
                script->FT_state = TEMP_FADE_TO_WHITE;
            } else {
                script->FT_alpha += 7;
                if (script->FT_alpha > 255) {
                    script->FT_alpha = 255;
                }
            }
            break;
        case TEMP_FADE_TO_WHITE:
            set_screen_overlay_color(
                0,
                208,
                (script->FT_alpha * 208) / 255,
                (script->FT_alpha * 208) / 255
            );
            set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, 255.0f);
            if (script->FT_alpha == 255) {
                script->FT_state = TEMP_FADE_COMPLETE;
            }
            script->FT_alpha += 14;
            if (script->FT_alpha > 255) {
                script->FT_alpha = 255;
            }
    }

    if (script->FT_state == TEMP_FADE_COMPLETE) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }

    #undef FT_state
    #undef FT_alpha
}

API_CALLABLE(N(FadeScreenFromWhite)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SpawnStarsOrbitingBowser)) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DismissStarsOrbitingBowser)) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->enabled = FALSE;
    return ApiStatus_DONE2;
}

s32 N(ArenaExplosions)[][6] = {
    {   0,    0,   0, 30, EVT_FLOAT(3.0), EVT_FLOAT(1.0) },
    { 450,  -50, 330, 40, EVT_FLOAT(4.0), EVT_FLOAT(2.0) },
    { 280, -100, 350, 50, EVT_FLOAT(5.0), EVT_FLOAT(2.0) },
    {  80, -200, -60, 30, EVT_FLOAT(3.0), EVT_FLOAT(1.0) },
    { 500, -200,  20, 30, EVT_FLOAT(3.0), EVT_FLOAT(1.0) },
    { 350, -120, 350, 50, EVT_FLOAT(5.0), EVT_FLOAT(2.0) },
};

EvtScript N(EVS_ManageShaking) = {
    EVT_LOOP(0)
        EVT_IF_GT(MV_DestructState, DESTRUCT_STATE_NONE)
            EVT_SET(MV_PrevDestructState, MV_DestructState)
        EVT_END_IF
        EVT_SWITCH(MV_DestructState)
            EVT_CASE_EQ(DESTRUCT_STATE_NONE)
            EVT_CASE_EQ(DESTRUCT_STATE_1)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_2)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 50, EVT_FLOAT(2.0))
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_3)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_4)
                EVT_USE_BUF(EVT_PTR(N(ArenaExplosions)))
                EVT_LOOP(1 + ARRAY_COUNT(N(ArenaExplosions))) //@bug extra iteration reads garbage
                    EVT_BUF_READ4(LVar0, LVar1, LVar2, LVar3)
                    EVT_FBUF_READ2(LVar4, LVar5)
                    EVT_CALL(PlaySoundAt, SOUND_SEQ_FINALE_EXPLOSION, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, LVar4, LVar3)
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, LVar5)
                EVT_END_LOOP
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_5)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_6)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_7)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(3.0))
                EVT_SET(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            EVT_CASE_EQ(DESTRUCT_STATE_10)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(2.0))
            EVT_CASE_EQ(DESTRUCT_STATE_TREMBLE)
                EVT_THREAD
                    EVT_SET(LVar0, MV_PrevDestructState)
                    EVT_LOOP(0)
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.7))
                        EVT_WAIT(1)
                        // wait for the state to change
                        EVT_IF_NE(LVar0, MV_PrevDestructState)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_SET(MV_DestructState, DESTRUCT_STATE_NONE)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

// x, y, z, delay
s32 N(ChainExplosionLocations)[][4] = {
    { 400,  -10, 400, 20 },
    { 350,  -50, 370, 25 },
    { 300,  -30, 340, 25 },
    { 350,  -40, 310, 20 },
    { 300,  -80, 280, 20 },
    { 280,  -60, 250, 20 },
    { 300,  -50, 220, 20 },
    { 250, -100, 190, 20 },
    { 280,  -70, 160, 20 },
    { 250,  -50, 130, 20 },
    { 230, -100, 100, 20 },
};

EvtScript N(EVS_BowserAndKammyBlownAway) = {
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
    EVT_SET(MV_DestructState, DESTRUCT_STATE_10)
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
        EVT_USE_BUF(EVT_PTR(N(ChainExplosionLocations)))
        EVT_LOOP(ARRAY_COUNT(N(ChainExplosionLocations)))
            EVT_BUF_READ4(LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(PlaySoundAt, SOUND_SEQ_FINALE_EXPLOSION, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
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
    EVT_EXEC(N(EVS_ManageShaking))
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
    EVT_CALL(N(SpawnStarsOrbitingBowser))
    EVT_SET(MV_OrbitingEffectAIdx, LVar0)
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
        EVT_SET(LVar0, MV_OrbitingEffectAIdx)
        EVT_CALL(N(DismissStarsOrbitingBowser))
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 150)
    EVT_CALL(ClearAmbientSounds, 150)
    EVT_WAIT(10)
    EVT_CALL(SetMusicTrack, 0, SONG_RECOVERED_STAR_ROD, 0, 8)
    EVT_CALL(NpcJump0, NPC_StarRod, 230, 18, 0, 25 * DT)
    EVT_CALL(NpcJump0, NPC_StarRod, 190, 18, 0, 20 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_Lift)
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_StarRod, 150, 60, 0, 15 * DT)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 14, 150, 60, 0, 1, 330)
    EVT_WAIT(310 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_00AA, 160, 40)
    EVT_CALL(PlaySound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    EVT_CALL(RemoveNpc, NPC_StarRod)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Peach_02, ANIM_Peach2_RaiseArms, ANIM_Peach1_Idle, 0, MSG_CH8_00AB)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach1_Walk)
        EVT_CALL(NpcMoveTo, NPC_Peach_02, 200, 0, 85)
        EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach1_Idle)
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
    EVT_CALL(SpeakToPlayer, NPC_Peach_02, ANIM_Peach2_RaiseArms, ANIM_Peach1_Idle, 0, MSG_CH8_00AC)
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_LOOP_RUMBLE)
    EVT_SET(MV_DestructState, DESTRUCT_STATE_1)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Peach_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Peach_02, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
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
    EVT_CALL(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 220, -43, 350)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 220, -43, 350, EVT_FLOAT(8.0), 40)
    EVT_SET(MV_DestructState, DESTRUCT_STATE_2)
    EVT_WAIT(50)
    EVT_SET(MV_ArenaState, ARENA_STATE_OVERLOADING)
    EVT_CALL(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach2_GaspStill)
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
    EVT_CALL(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 370, -10, 180)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 370, -10, 180, EVT_FLOAT(6.0), 40)
    EVT_SET(MV_DestructState, DESTRUCT_STATE_3)
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
    EVT_SET(MV_DestructState, DESTRUCT_STATE_4)
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
    EVT_CALL(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 350, 50, -100)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 350, 50, -100, EVT_FLOAT(4.0), 20)
    EVT_SET(MV_DestructState, DESTRUCT_STATE_5)
    EVT_WAIT(25)
    EVT_CALL(SpeakToNpc, NPC_Kammy_05, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 512, NPC_Bowser_03, MSG_CH8_00AF)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 570, 0, 100)
        EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 570, 0, 100, EVT_FLOAT(4.0), 20)
        EVT_SET(MV_DestructState, DESTRUCT_STATE_6)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SpeakToNpc, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, NPC_Kammy_05, MSG_CH8_00B0)
    EVT_SET(MV_ArenaState, ARENA_STATE_BROKEN)
    EVT_WAIT(20)
    EVT_CALL(StopSound, SOUND_LRAW_RUMBLE)
    EVT_CALL(PlaySoundAt, SOUND_KPA_EXPLOSION_CLUSTER, SOUND_SPACE_DEFAULT, 500, 0, 100)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 500, 0, 100, EVT_FLOAT(8.0), 90)
    EVT_SET(MV_DestructState, DESTRUCT_STATE_7)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_00B1, 160, 40)
    EVT_CALL(N(FadeScreenToRedAndWhite))
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
        EVT_CALL(N(FadeScreenFromWhite))
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(EVS_BowserAndKammyBlownAway))
    EVT_CALL(GotoMap, EVT_PTR("osr_03"), osr_03_ENTRY_5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
