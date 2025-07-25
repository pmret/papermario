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

    effect->data.starsOrbiting->enabled = false;
    return ApiStatus_DONE2;
}

s32 N(ArenaExplosions)[][6] = {
    {   0,    0,   0, 30, Float(3.0), Float(1.0) },
    { 450,  -50, 330, 40, Float(4.0), Float(2.0) },
    { 280, -100, 350, 50, Float(5.0), Float(2.0) },
    {  80, -200, -60, 30, Float(3.0), Float(1.0) },
    { 500, -200,  20, 30, Float(3.0), Float(1.0) },
    { 350, -120, 350, 50, Float(5.0), Float(2.0) },
};

EvtScript N(EVS_ManageShaking) = {
    Loop(0)
        IfGt(MV_DestructState, DESTRUCT_STATE_NONE)
            Set(MV_PrevDestructState, MV_DestructState)
        EndIf
        Switch(MV_DestructState)
            CaseEq(DESTRUCT_STATE_NONE)
            CaseEq(DESTRUCT_STATE_1)
                Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_2)
                Call(ShakeCam, CAM_DEFAULT, 0, 50, Float(2.0))
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_3)
                Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_4)
                UseBuf(Ref(N(ArenaExplosions)))
                Loop(1 + ARRAY_COUNT(N(ArenaExplosions))) //@bug extra iteration reads garbage
                    BufRead4(LVar0, LVar1, LVar2, LVar3)
                    FBufRead2(LVar4, LVar5)
                    Call(PlaySoundAt, SOUND_SEQ_FINALE_EXPLOSION, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, LVar4, LVar3)
                    Call(ShakeCam, CAM_DEFAULT, 0, 20, LVar5)
                EndLoop
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_5)
                Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_6)
                Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_7)
                Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(3.0))
                Set(MV_DestructState, DESTRUCT_STATE_TREMBLE)
            CaseEq(DESTRUCT_STATE_10)
                Call(ShakeCam, CAM_DEFAULT, 0, 100, Float(2.0))
            CaseEq(DESTRUCT_STATE_TREMBLE)
                Thread
                    Set(LVar0, MV_PrevDestructState)
                    Loop(0)
                        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(0.7))
                        Wait(1)
                        // wait for the state to change
                        IfNe(LVar0, MV_PrevDestructState)
                            BreakLoop
                        EndIf
                    EndLoop
                EndThread
                Set(MV_DestructState, DESTRUCT_STATE_NONE)
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
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
    Thread
        Call(SetNpcJumpscale, NPC_Bowser_03, Float(0.1))
        Call(NpcJump0, NPC_Bowser_03, 700, -50, 1000, 100)
    EndThread
    Thread
        Call(MakeLerp, 0, -1800, 100, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Bowser_03, 0, 0, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_Kammy_05, Float(0.1))
        Call(NpcJump0, NPC_Kammy_05, 600, -250, 1000, 100)
    EndThread
    Thread
        Call(MakeLerp, 0, -2160, 100, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Kammy_05, 0, 0, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Set(MV_DestructState, DESTRUCT_STATE_10)
    Thread
        Call(MakeLerp, -150, -430, 100, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(LVar2, LVar0)
            Add(LVar2, 150)
            Div(LVar2, 2)
            Call(TranslateGroup, MODEL_g2, LVar0, LVar2, 0)
            Call(TranslateGroup, MODEL_g31, LVar0, LVar2, 0)
            Call(TranslateGroup, MODEL_g7, LVar0, LVar2, 0)
            Call(TranslateGroup, MODEL_g54, LVar0, LVar2, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        UseBuf(Ref(N(ChainExplosionLocations)))
        Loop(ARRAY_COUNT(N(ChainExplosionLocations)))
            BufRead4(LVar0, LVar1, LVar2, LVar3)
            Call(PlaySoundAt, SOUND_SEQ_FINALE_EXPLOSION, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, Float(2.0), 30)
            Wait(LVar3)
        EndLoop
    EndThread
    Wait(120)
    Return
    End
};

EvtScript N(EVS_Scene_BowserDefeated) = {
    Call(DisablePlayerInput, true)
    Call(DisablePartnerAI, 0)
    Exec(N(EVS_ManageShaking))
    Call(SetPlayerPos, 150, 0, 0)
    Call(InterpPlayerYaw, 90, 0)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, false)
        Call(SetNpcPos, NPC_PARTNER, 110, 10, 0)
    Else
        Call(SetNpcPos, NPC_PARTNER, 110, 0, 0)
    EndIf
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    Add(LVar0, -40)
    Add(LVar1, 60)
    Set(LVar3, 20)
    Set(LVar4, 3)
    Call(N(SpawnStarsOrbitingBowser))
    Set(MV_OrbitingEffectAIdx, LVar0)
    Call(SetCamType, CAM_DEFAULT, 0, false)
    Call(UseSettingsFrom, CAM_DEFAULT, 300, 0, 50)
    Call(SetPanTarget, CAM_DEFAULT, 300, 0, 50)
    Call(SetCamDistance, CAM_DEFAULT, 375)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 30)
    Call(SetCamPosB, CAM_DEFAULT, 0, 20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Set(LVar0, MV_OrbitingEffectAIdx)
        Call(N(DismissStarsOrbitingBowser))
    EndThread
    Call(FadeOutMusic, 0, 150)
    Call(ClearAmbientSounds, 150)
    Wait(10)
    Call(SetMusic, 0, SONG_RECOVERED_STAR_ROD, 0, VOL_LEVEL_FULL)
    Call(NpcJump0, NPC_StarRod, 230, 18, 0, 25 * DT)
    Call(NpcJump0, NPC_StarRod, 190, 18, 0, 20 * DT)
    Thread
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_MarioW1_Lift)
    EndThread
    Call(NpcJump0, NPC_StarRod, 150, 60, 0, 15 * DT)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 14, 150, 60, 0, 1, 330)
    Wait(310 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH8_00AA, 160, 40)
    Call(PlaySound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    Call(RemoveNpc, NPC_StarRod)
    Call(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Set(LVar1, ANIM_WorldGoombario_Celebrate)
        CaseEq(PARTNER_KOOPER)
            Set(LVar1, ANIM_WorldKooper_Celebrate)
        CaseEq(PARTNER_BOMBETTE)
            Set(LVar1, ANIM_WorldBombette_Celebrate)
        CaseEq(PARTNER_PARAKARRY)
            Set(LVar1, ANIM_WorldParakarry_Celebrate)
        CaseEq(PARTNER_BOW)
            Set(LVar1, ANIM_WorldBow_CelebrateSlow)
        CaseEq(PARTNER_WATT)
            Set(LVar1, ANIM_WorldWatt_Celebrate)
        CaseEq(PARTNER_SUSHIE)
            Set(LVar1, ANIM_WorldSushie_Celebrate)
        CaseEq(PARTNER_LAKILESTER)
            Set(LVar1, ANIM_WorldLakilester_Celebrate)
    EndSwitch
    Call(SetNpcAnimation, NPC_PARTNER, LVar1)
    Switch(LVar0)
        CaseOrEq(PARTNER_SUSHIE)
        CaseOrEq(PARTNER_BOW)
            Wait(30)
        EndCaseGroup
        CaseDefault
            Loop(3)
                Call(GetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
                Call(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 10)
            EndLoop
    EndSwitch
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(20)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(20)
    Call(SpeakToPlayer, NPC_Peach_02, ANIM_Peach2_RaiseArms, ANIM_Peach1_Idle, 0, MSG_CH8_00AB)
    Thread
        Call(SetNpcAnimation, NPC_Peach_02, ANIM_Peach1_Walk)
        Call(NpcMoveTo, NPC_Peach_02, 200, 0, 85)
        Call(SetNpcAnimation, NPC_Peach_02, ANIM_Peach1_Idle)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 25)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 275)
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.2))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Call(NpcMoveTo, NPC_Twink_02, 230, 30, 85)
    Wait(10)
    Call(SpeakToPlayer, NPC_Peach_02, ANIM_Peach2_RaiseArms, ANIM_Peach1_Idle, 0, MSG_CH8_00AC)
    Wait(20)
    Call(PlaySound, SOUND_LOOP_RUMBLE)
    Set(MV_DestructState, DESTRUCT_STATE_1)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_Peach_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Peach_02, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_Peach_02, 90, 0)
    Wait(15)
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_Peach_02, 270, 0)
    Wait(10)
    Call(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(3.0), Float(-1.5))
    Call(SetCamDistance, CAM_DEFAULT, 750)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(40)
    Call(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 220, -43, 350)
    PlayEffect(EFFECT_RING_BLAST, 0, 220, -43, 350, Float(8.0), 40)
    Set(MV_DestructState, DESTRUCT_STATE_2)
    Wait(50)
    Set(MV_ArenaState, ARENA_STATE_OVERLOADING)
    Call(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.5))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetNpcAnimation, NPC_Peach_02, ANIM_Peach2_GaspStill)
    Call(SetNpcAnimation, NPC_Twink_02, ANIM_Twink_Cringe)
    Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
    Call(SetNpcJumpscale, NPC_Bowser_03, Float(1.0))
    Call(NpcJump0, NPC_Bowser_03, 300, 0, 40, 20)
    Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    Call(SetNpcRotation, NPC_Bowser_03, 0, 0, 0)
    Wait(10)
    Call(InterpNpcYaw, NPC_Bowser_03, 90, 0)
    Wait(10)
    Call(InterpNpcYaw, NPC_Bowser_03, 270, 0)
    Wait(10)
    Call(InterpNpcYaw, NPC_Bowser_03, 90, 0)
    Wait(20)
    Call(SpeakToPlayer, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, MSG_CH8_00AD)
    Call(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 370, -10, 180)
    PlayEffect(EFFECT_RING_BLAST, 0, 370, -10, 180, Float(6.0), 40)
    Set(MV_DestructState, DESTRUCT_STATE_3)
    Wait(20)
    Call(InterpNpcYaw, NPC_Peach_02, 90, 0)
    Call(InterpNpcYaw, NPC_Twink_02, 90, 0)
    Wait(30)
    Call(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(6.0), Float(5.0))
    Call(SetCamDistance, CAM_DEFAULT, 1100)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Thread
        Wait(10)
        Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Walk)
        Call(NpcMoveTo, NPC_Bowser_03, 450, 0, 140)
        Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EndThread
    Set(MV_DestructState, DESTRUCT_STATE_4)
    Wait(155)
    Call(GetNpcPos, NPC_Bowser_03, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.5))
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToNpc, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, NPC_Kammy_05, MSG_CH8_00AE)
    Wait(5)
    Call(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 350, 50, -100)
    PlayEffect(EFFECT_RING_BLAST, 0, 350, 50, -100, Float(4.0), 20)
    Set(MV_DestructState, DESTRUCT_STATE_5)
    Wait(25)
    Call(SpeakToNpc, NPC_Kammy_05, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 512, NPC_Bowser_03, MSG_CH8_00AF)
    Wait(10)
    Thread
        Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
        Wait(20)
        Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    EndThread
    Thread
        Call(PlaySoundAt, SOUND_KPA_ARENA_EXPLODING, SOUND_SPACE_DEFAULT, 570, 0, 100)
        PlayEffect(EFFECT_RING_BLAST, 0, 570, 0, 100, Float(4.0), 20)
        Set(MV_DestructState, DESTRUCT_STATE_6)
    EndThread
    Wait(30)
    Call(SpeakToNpc, NPC_Bowser_03, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 512, NPC_Kammy_05, MSG_CH8_00B0)
    Set(MV_ArenaState, ARENA_STATE_BROKEN)
    Wait(20)
    Call(StopSound, SOUND_LRAW_RUMBLE)
    Call(PlaySoundAt, SOUND_KPA_EXPLOSION_CLUSTER, SOUND_SPACE_DEFAULT, 500, 0, 100)
    PlayEffect(EFFECT_RING_BLAST, 0, 500, 0, 100, Float(8.0), 90)
    Set(MV_DestructState, DESTRUCT_STATE_7)
    Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Shock)
    Call(ShowMessageAtScreenPos, MSG_CH8_00B1, 160, 40)
    Call(N(FadeScreenToRedAndWhite))
    Call(TranslateGroup, MODEL_Root, -200, 0, 0)
    Call(UpdateColliderTransform, COLLIDER_o128)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -200)
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Peach_02, LVar0, LVar1, LVar2)
    Add(LVar0, -200)
    Call(SetNpcPos, NPC_Peach_02, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Twink_02, LVar0, LVar1, LVar2)
    Add(LVar0, -200)
    Call(SetNpcPos, NPC_Twink_02, LVar0, LVar1, LVar2)
    Set(LVar0, 500)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(0.0), Float(-7.0))
    Call(SetCamDistance, CAM_DEFAULT, 1100)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_Idle)
    Call(InterpNpcYaw, NPC_Kammy_05, 90, 0)
    Wait(5)
    Call(SetNpcRotationPivot, NPC_Bowser_03, 34)
    Call(SetNpcRotationPivot, NPC_Kammy_05, 12)
    Wait(10)
    Thread
        Call(N(FadeScreenFromWhite))
    EndThread
    ExecWait(N(EVS_BowserAndKammyBlownAway))
    Call(GotoMap, Ref("osr_03"), osr_03_ENTRY_5)
    Wait(100)
    Return
    End
};
