#include "sam_12.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(SetScreenFadeAmount)) {
    Bytecode* args = script->ptrReadPos;

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, evt_get_float_variable(script, *args++));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetItemPositionF)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    ItemEntity* item = get_item_entity(idx);

    item->pos.x = x;
    item->pos.y = y;
    item->pos.z = z;
    return ApiStatus_DONE2;
}

#include "world/common/todo/PlayRisingBubble.inc.c"

API_CALLABLE(N(SpawnSleepBubble)) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f26 = evt_get_float_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    f32 t = evt_get_float_variable(script, *args++);
    s32 outVar = *args++;
    EffectInstance* effect;

    fx_sleep_bubble(
        0,
        gPlayerStatus.pos.x + x,
        gPlayerStatus.pos.y + ((gPlayerStatus.colliderHeight * 2) / 3) + y,
        gPlayerStatus.pos.z + z,
        (gPlayerStatus.colliderHeight / 3) + t,
        temp_f26,
        &effect
    );
    evt_set_variable(script, outVar, (s32) effect);
    return ApiStatus_DONE2;
}

s32 N(FlickeringStaticAmts)[] = {
    EVT_FLOAT(50.0),
    EVT_FLOAT(80.0),
    EVT_FLOAT(70.0),
    EVT_FLOAT(60.0),
    EVT_FLOAT(50.0),
};

EvtScript N(EVS_MerlarFlickering) = {
    EVT_LABEL(0)
        EVT_CALL(RandInt, 90, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(RandInt, 100, LVar1)
        EVT_IF_LT(LVar1, 80)
            EVT_SET(LVar1, 1)
        EVT_ELSE
            EVT_SET(LVar1, 2)
        EVT_END_IF
        EVT_LOOP(LVar1)
            EVT_USE_BUF(EVT_PTR(N(FlickeringStaticAmts)))
            EVT_LOOP(5)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetNpcImgFXParams, NPC_Merlar, IMGFX_HOLOGRAM, EVT_FLOAT(0.0), LVar0, EVT_FLOAT(200.0), EVT_FLOAT(100.0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcImgFXParams, NPC_Merlar, IMGFX_HOLOGRAM, EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(100.0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpawnStarStoneSparkles) = {
    EVT_CALL(PlaySoundAt, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT, 230, 30, 0)
    EVT_LABEL(0)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, 230, 30, 0, 30)
        EVT_WAIT(20)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpawnMerlarSparkles) = {
    EVT_CALL(PlaySoundAtNpc, NPC_Merlar, SOUND_MERLAR_APPEARS, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_Merlar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_LOOP(8)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, LVar0, LVar1, LVar2, 30)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MarioSleeping) = {
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtPlayer, SOUND_SNORE_INHALE_A, SOUND_SPACE_DEFAULT)
        EVT_WAIT(60)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#define LOOPCOUNT_1 ((s32)(5 * DT) * 10)
#define LOOPCOUNT_2 ((s32)(10 * DT) * 10)

EvtScript N(EVS_Scene_MeetMerlar) = {
    EVT_LABEL(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 160, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 160, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 90, 0, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_EXEC_GET_TID(N(EVS_SpawnStarStoneSparkles), LVar9)
    EVT_WAIT(100 * DT)
    EVT_CALL(SetNpcPos, NPC_Merlar, 200, 50, 0)
    EVT_EXEC(N(EVS_SpawnMerlarSparkles))
    EVT_CALL(PlaySoundAtNpc, NPC_Merlar, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(LOOPCOUNT_2)
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcImgFXParams, NPC_Merlar, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC_GET_TID(N(EVS_MerlarFlickering), LVar8)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0133)
    EVT_CALL(GetNpcPos, NPC_Merlar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(225.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(60.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0134)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 160, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0135)
    EVT_EXEC_GET_TID(N(EVS_MarioSleeping), LVarA)
    EVT_CALL(EndSpeech, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(LOOPCOUNT_1)
        EVT_ADDF(LVar0, EVT_FLOAT(255.0 / LOOPCOUNT_1))
        EVT_CALL(N(SetScreenFadeAmount), LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(SpawnSleepBubble), -90, 6, -5, 2, 0, LVar7)
    EVT_THREAD
        EVT_SET(MF_DoneFadingIn, FALSE)
        EVT_SETF(LVar0, EVT_FLOAT(255.0))
        EVT_LOOP(LOOPCOUNT_2)
            EVT_ADDF(LVar0, EVT_FLOAT(-255.0 / LOOPCOUNT_2))
            EVT_CALL(N(SetScreenFadeAmount), LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SET(MF_DoneFadingIn, TRUE)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0136)
    EVT_LABEL(6)
        EVT_IF_EQ(MF_DoneFadingIn, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(6)
        EVT_END_IF
    EVT_WAIT(30 * DT)
    EVT_CALL(RemoveEffect, LVar7)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SNAP_AWAKE_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(30 * DT)
    EVT_CALL(GetNpcPos, NPC_Merlar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(225.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(60.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0137)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 230, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(230.0), EVT_FLOAT(60.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_LOOP(5)
            EVT_CALL(N(PlayRisingBubble), 232, 31, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(LOOPCOUNT_1)
        EVT_ADDF(LVar0, EVT_FLOAT(31.0 / LOOPCOUNT_1))
        EVT_CALL(N(SetItemPositionF), MV_StarStoneItemID, EVT_FLOAT(230.0), LVar0, EVT_FLOAT(0.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 160, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0138)
    EVT_KILL_THREAD(LVar8)
    EVT_KILL_THREAD(LVar9)
    EVT_THREAD
        EVT_SET(LVar0, 30)
        EVT_LOOP(5)
            EVT_SUB(LVar0, 5)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, 230, 30, 0, LVar0)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SETF(LVar0, EVT_FLOAT(100.0))
    EVT_LOOP(LOOPCOUNT_2)
        EVT_ADDF(LVar0, EVT_FLOAT(-100.0 / LOOPCOUNT_2))
        EVT_CALL(SetNpcImgFXParams, NPC_Merlar, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Merlar, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH7_GOT_STAR_STONE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
