#include "kkj_13.h"
#include "effects.h"
#include "sprite.h"
#include "sprite/player.h"

API_CALLABLE(N(UpdatePropellerSoundPos_Intro)) {
    Npc* npc = get_npc_safe(NPC_Bowser_Prop);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z;

    sfx_adjust_env_sound_pos(SOUND_LRAW_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT, x, y, z);
    script->varTable[0] = y;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePropellerSounds_Intro) = {
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_Prop, SOUND_LOOP_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT)
    EVT_LOOP(0)
        EVT_CALL(N(UpdatePropellerSoundPos_Intro))
        EVT_IF_LT(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_LOOP_BOWSER_PROPELLER)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(ScreenWhiteFlashOn)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 64;

    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_color(SCREEN_LAYER_FRONT, 160, 160, 160);
    set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ScreenWhiteFlashOff)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 64;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(SCREEN_LAYER_FRONT, 160, 160, 160);
    set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

typedef struct GlassShardPosition {
    /* 0x00 */ s16 radius;
    /* 0x02 */ s16 angle;
} GlassShardPosition; // size = 0x4

GlassShardPosition N(GlassPositions)[] = {
    { .radius =  5, .angle =   0 },
    { .radius =  5, .angle =  90 },
    { .radius =  5, .angle = 180 },
    { .radius =  5, .angle = 270 },
    { .radius = 10, .angle =  30 },
    { .radius = 10, .angle =  90 },
    { .radius = 10, .angle = 150 },
    { .radius = 10, .angle = 210 },
    { .radius = 10, .angle = 270 },
    { .radius = 10, .angle = 330 },
    { .radius = 20, .angle =   0 },
    { .radius = 20, .angle =  60 },
    { .radius = 20, .angle = 120 },
    { .radius = 20, .angle = 180 },
    { .radius = 20, .angle = 240 },
    { .radius = 20, .angle = 300 },
    { .radius = 30, .angle =  15 },
    { .radius = 30, .angle =  45 },
    { .radius = 30, .angle =  75 },
    { .radius = 30, .angle = 105 },
    { .radius = 30, .angle = 135 },
    { .radius = 30, .angle = 165 },
    { .radius = 30, .angle = 195 },
    { .radius = 30, .angle = 225 },
    { .radius = 30, .angle = 255 },
    { .radius = 30, .angle = 285 },
    { .radius = 30, .angle = 315 },
    { .radius = 30, .angle = 345 },
};

API_CALLABLE(N(ShatterWindow)) {
    EffectInstance* effect;
    f32 radius;
    f32 x, y;
    s32 type;
    f32 posX;
    f32 posY;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(N(GlassPositions)); i++) {
        type = (i & 1) + 2;
        radius = N(GlassPositions)[i].radius;
        x = (radius * cos_deg(N(GlassPositions)[i].angle)) * 1.3;
        y = (radius * sin_deg(N(GlassPositions)[i].angle)) * 1.5;
        posX = x + 600.0f;
        posY = y + 100.0f;
        x *= 0.1;
        y *= 0.1;
        x += cos_deg(radius * 15.0f) * 5.0f;
        effect = fx_ice_shard(type, posX, posY, -150.0f, ((i & 3) * 0.4) + 1.0, ((i & 3) * 4) + 30);
        effect->data.iceShard->animFrame = 0;
        effect->data.iceShard->animRate = (rand_int(10) * 0.2) + 0.1;
        effect->data.iceShard->rot = 35 * i;
        effect->data.iceShard->angularVel = rand_int(10) - 5;
        effect->data.iceShard->vel.x = x;
        effect->data.iceShard->vel.y = y;
        effect->data.iceShard->vel.z = 2.0f;
        effect->data.iceShard->gravAccel = -0.1f;
    }
    return ApiStatus_DONE2;
}

Vec3f N(FlyThroughWindowPath)[] = {
    {  450.0,   150.0, -300.0 },
    {  550.0,   105.0, -180.0 },
    {  650.0,    60.0,  -75.0 },
    {  850.0,    90.0,    0.0 },
};

Vec3f N(PlayerThrownPath)[] = {
    {  660.0,     0.0,   15.0 },
    {  634.0,    60.0,  -83.0 },
    {  608.0,    80.0, -150.0 },
    {  582.0,    60.0, -233.0 },
    {  556.0,     0.0, -315.0 },
    {  530.0,   -60.0, -398.0 },
};

EvtScript N(EVS_FocusCam_Everyone) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 720, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 720, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_OnPeach) = {
    EVT_CALL(GetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_OnBowser) = {
    EVT_CALL(GetNpcPos, NPC_Bowser_Body, LVar1, LVar2, LVar3)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar1, LVar2, LVar3)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar1, LVar2, LVar3)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BowserAttacks) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 0, 8)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Peach, 680, 0, -15)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 600, 0, -15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 600, 0, -15)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_LOOP_KKJ_RUMBLING)
#if VERSION_PAL
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 60 * DT, EVT_FLOAT(0.5))
#else
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.5))
#endif
        EVT_CALL(PlaySound, SOUND_LRAW_KKJ_RUMBLING | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_KKJ_RUMBLING)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, 0)
        EVT_LOOP(2)
            EVT_CALL(InterpPlayerYaw, 270, 0)
            EVT_CALL(PlayerJump1, 550, 0, 0, 20 * DT)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(PlayerJump1, 630, 0, 0, 20 * DT)
        EVT_END_LOOP
        EVT_CALL(PlayerMoveTo, 550, 0, 30 * DT)
        EVT_CALL(PlayerMoveTo, 575, 0, 30 * DT)
        EVT_CALL(InterpPlayerYaw, 90, 7 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_CarryAboveRun)
            EVT_WAIT(15 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Run)
            EVT_WAIT(15 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_RunLiftDress)
        EVT_LOOP(2)
            EVT_CALL(NpcMoveTo, NPC_Peach, 600, -2, 20 * DT)
            EVT_CALL(NpcMoveTo, NPC_Peach, 680, -2, 20 * DT)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
        EVT_CALL(NpcMoveTo, NPC_Peach, 600, -2, 30 * DT)
        EVT_CALL(NpcMoveTo, NPC_Peach, 625, -2, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Peach, 270, 7 * DT)
    EVT_END_THREAD
    EVT_WAIT(160 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk,ANIM_Peach2_TalkIdle, 0, MSG_Intro_004E)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, SPRITE_ID_BACK_FACING | ANIM_Peach1_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Peach, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 0, 7 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 600, 0, -15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 600, 0, -15)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 * DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Peach, SPRITE_ID_BACK_FACING | ANIM_Peach1_Idle, SPRITE_ID_BACK_FACING | ANIM_Peach1_Idle, 5, MSG_Intro_004F)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
        EVT_CALL(SetNpcYaw, NPC_Bowser_Body, 90)
        EVT_CALL(SetNpcYaw, NPC_Bowser_Prop, 90)
        EVT_EXEC(N(EVS_UpdatePropellerSounds_Intro))
        EVT_CALL(LoadPath, 50 * DT, EVT_PTR(N(FlyThroughWindowPath)), ARRAY_COUNT(N(FlyThroughWindowPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Bowser_Body, LVar1, LVar2, LVar3)
            EVT_CALL(SetNpcPos, NPC_Bowser_Prop, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
        EVT_CALL(SetNpcPos, NPC_Bowser_Body, 820, 20, 0)
        EVT_CALL(SetNpcYaw, NPC_Bowser_Body, 270)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0B)
        EVT_CALL(SetNpcYaw, NPC_Kammy, 90)
        EVT_WAIT(10 * DT)
        EVT_CALL(LoadPath, 50 * DT, EVT_PTR(N(FlyThroughWindowPath)), ARRAY_COUNT(N(FlyThroughWindowPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
        EVT_CALL(SetNpcPos, NPC_Kammy, 920, 0, 0)
        EVT_CALL(SetNpcYaw, NPC_Kammy, 270)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(N(ScreenWhiteFlashOn))
        EVT_CALL(EnableGroup, MODEL_g133, FALSE)
        EVT_CALL(EnableGroup, MODEL_g147, FALSE)
        EVT_CALL(EnableGroup, MODEL_g152, TRUE)
        EVT_CALL(EnableGroup, MODEL_g154, TRUE)
        EVT_CALL(PlaySoundAt, SOUND_GLASS_SHATTER, SOUND_SPACE_DEFAULT, 600, 60, -150)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 600, 60, -150, 120)
        EVT_CALL(N(ShatterWindow))
        EVT_WAIT(1)
        EVT_CALL(N(ScreenWhiteFlashOff))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_LOOP(70 * DT)
        EVT_WAIT(1)
        EVT_CALL(PlayerFaceNpc, NPC_Bowser_Body, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_Peach, NPC_Bowser_Body, 0)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcJumpscale, NPC_Bowser_Body, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_Bowser_Body, 810, 0, 0, 5)
        EVT_CALL(PlaySoundAtNpc, NPC_Bowser_Body, SOUND_LARGE_NPC_IMPACT, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_PostJump)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20 * DT, EVT_FLOAT(2.0))
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 740, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        EVT_CALL(NpcMoveTo, NPC_Kammy, 880, 0, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_END_THREAD
    EVT_CALL(SpeakToNpc, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Peach, MSG_Intro_0050)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 625, 0, -15)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SpeakToNpc, NPC_Peach, ANIM_Peach2_Shout, ANIM_Peach2_EndShout, 0, NPC_Bowser_Body, MSG_Intro_0051)
    EVT_SET(LVar0, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnBowser))
    EVT_CALL(SpeakToNpc, NPC_Bowser_Body, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, NPC_Peach, MSG_Intro_0052)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Walk)
        EVT_CALL(NpcMoveTo, NPC_Bowser_Body, 770, 0, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        EVT_CALL(NpcMoveTo, NPC_Kammy, 840, 0, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_END_THREAD
    EVT_WAIT(5 * DT)
    EVT_SET(LVar0, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_Everyone))
    EVT_WAIT(5 * DT)
    EVT_CALL(PlayerMoveTo, 660, 0, 15 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Intro_0053)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Intro_0054)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_RearUpLaugh)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 0, MSG_Intro_0055)
    EVT_SET(LVar0, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnBowser))
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_RearUpTalk, ANIM_WorldBowser_RearUpTalk, 0, MSG_Intro_0056)
    EVT_SET(LVar0, EVT_FLOAT(5.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_Everyone))
    EVT_CALL(SetNpcVar, NPC_Bowser_Body, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(PlayerMoveTo, 695, 0, 10)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.75))
    EVT_CALL(PlayerJump, 720, 80, 0, 20 * DT)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Bowser_Body, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetPlayerPos, 660, 0, 15)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_FallDown)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_GaspStill)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_RearUpLaugh)
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPeach))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_GaspStill, ANIM_Peach2_GaspStill, 5, MSG_Intro_005D)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 790, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 790, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 5, MSG_Intro_005E)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Intro_005F)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_Body, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Brandish)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_BrandishIdle)
    EVT_CALL(SpeakToNpc, NPC_Bowser_Body, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0, NPC_Kammy, MSG_Intro_0060)
    EVT_WAIT(10 * DT)
    EVT_SET(LVar0, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_Everyone))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_Body, 270, 10)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Intro_0061)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Brandish)
    EVT_WAIT(10 * DT)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_Body, SOUND_BOWSER_STAR_ROD_USE, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, 780, 95, 27, 1, 30)
    EVT_WAIT(40 * DT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_BOWSER_LIGHTNING, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING, 4, LVar0, LVar1, LVar2, 0, 0)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPlayer, SOUND_TOSS_PLAYER, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Hurt)
        EVT_CALL(LoadPath, 30 * DT, EVT_PTR(N(PlayerThrownPath)), ARRAY_COUNT(N(PlayerThrownPath)), EASING_LINEAR)
        EVT_SET(LVar4, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
            EVT_ADD(LVar4, 45)
            EVT_CALL(InterpPlayerYaw, LVar4, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(GotoMap, EVT_PTR("osr_03"), osr_03_ENTRY_2)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_PeachCaptured) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Peach, SPRITE_ID_BACK_FACING | ANIM_Peach1_Idle)
    EVT_CALL(SetNpcYaw, NPC_Peach, 315)
    EVT_CALL(SetNpcPos, NPC_Peach, 613, 0, -90)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_RearUpLaugh)
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, 750, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_CALL(SetNpcPos, NPC_Kammy, 820, 0, 0)
    EVT_SET(LVar0, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_Everyone))
    EVT_CALL(SetNpcSpeed, NPC_Peach, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Peach, 570, -130, 0)
    EVT_CALL(SpeakToPlayer, NPC_Peach, SPRITE_ID_BACK_FACING | ANIM_Peach1_Idle, SPRITE_ID_BACK_FACING | ANIM_Peach1_Idle, 5, MSG_Intro_0062)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim04)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_CaptivePeach, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcPos, NPC_CaptivePeach, 900, 0, 30)
        EVT_CALL(SetNpcSpeed, NPC_CaptivePeach, EVT_FLOAT(4.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_CaptivePeach, 660, 30, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_02, 940, 0, 30)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(4.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 700, 30, 0)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 0)
    EVT_CALL(GotoMap, EVT_PTR("hos_10"), hos_10_ENTRY_5)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
