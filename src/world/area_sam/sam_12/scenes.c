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
    Float(50.0),
    Float(80.0),
    Float(70.0),
    Float(60.0),
    Float(50.0),
};

EvtScript N(EVS_MerlarFlickering) = {
    Label(0)
        Call(RandInt, 90, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Call(RandInt, 100, LVar1)
        IfLt(LVar1, 80)
            Set(LVar1, 1)
        Else
            Set(LVar1, 2)
        EndIf
        Loop(LVar1)
            UseBuf(Ref(N(FlickeringStaticAmts)))
            Loop(5)
                BufRead1(LVar0)
                Call(SetNpcImgFXParams, NPC_Merlar, IMGFX_HOLOGRAM, Float(0.0), LVar0, Float(200.0), Float(100.0))
                Wait(1)
            EndLoop
            Call(SetNpcImgFXParams, NPC_Merlar, IMGFX_HOLOGRAM, Float(0.0), Float(0.0), Float(0.0), Float(100.0))
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SpawnStarStoneSparkles) = {
    Call(PlaySoundAt, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT, 230, 30, 0)
    Label(0)
        PlayEffect(EFFECT_SPARKLES, 2, 230, 30, 0, 30)
        Wait(20)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SpawnMerlarSparkles) = {
    Call(PlaySoundAtNpc, NPC_Merlar, SOUND_MERLAR_APPEARS, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_Merlar, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    Loop(8)
        PlayEffect(EFFECT_SPARKLES, 2, LVar0, LVar1, LVar2, 30)
        Wait(10)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MarioSleeping) = {
    Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    Loop(0)
        Call(PlaySoundAtPlayer, SOUND_SNORE_INHALE_A, SOUND_SPACE_DEFAULT)
        Wait(60)
    EndLoop
    Return
    End
};

#define LOOPCOUNT_1 ((s32)(5 * DT) * 10)
#define LOOPCOUNT_2 ((s32)(10 * DT) * 10)

EvtScript N(EVS_Scene_MeetMerlar) = {
    Label(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar0, 0)
            Goto(1)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, 160, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 160, 0, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 90, 0, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20 * DT)
    ExecGetTID(N(EVS_SpawnStarStoneSparkles), LVar9)
    Wait(100 * DT)
    Call(SetNpcPos, NPC_Merlar, 200, 50, 0)
    Exec(N(EVS_SpawnMerlarSparkles))
    Call(PlaySoundAtNpc, NPC_Merlar, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(0.0))
    Loop(LOOPCOUNT_2)
        AddF(LVar0, Float(1.0))
        Call(SetNpcImgFXParams, NPC_Merlar, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    ExecGetTID(N(EVS_MerlarFlickering), LVar8)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0133)
    Call(GetNpcPos, NPC_Merlar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(225.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(60.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0134)
    Call(SetPanTarget, CAM_DEFAULT, 160, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0135)
    ExecGetTID(N(EVS_MarioSleeping), LVarA)
    Call(EndSpeech, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0)
    SetF(LVar0, Float(0.0))
    Loop(LOOPCOUNT_1)
        AddF(LVar0, Float(255.0 / LOOPCOUNT_1))
        Call(N(SetScreenFadeAmount), LVar0)
        Wait(1)
    EndLoop
    Call(N(SpawnSleepBubble), -90, 6, -5, 2, 0, LVar7)
    Thread
        Set(MF_DoneFadingIn, FALSE)
        SetF(LVar0, Float(255.0))
        Loop(LOOPCOUNT_2)
            AddF(LVar0, Float(-255.0 / LOOPCOUNT_2))
            Call(N(SetScreenFadeAmount), LVar0)
            Wait(1)
        EndLoop
        Set(MF_DoneFadingIn, TRUE)
    EndThread
    Call(ContinueSpeech, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0136)
    Label(6)
        IfEq(MF_DoneFadingIn, FALSE)
            Wait(1)
            Goto(6)
        EndIf
    Wait(30 * DT)
    Call(RemoveEffect, LVar7)
    KillThread(LVarA)
    Call(PlaySoundAtPlayer, SOUND_SNAP_AWAKE_A, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(30 * DT)
    Call(GetNpcPos, NPC_Merlar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(225.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(60.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0137)
    Wait(30 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 230, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, Float(230.0), Float(60.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Loop(5)
            Call(N(PlayRisingBubble), 232, 31, 0)
            Wait(10)
        EndLoop
    EndThread
    Wait(10)
    SetF(LVar0, Float(0.0))
    Loop(LOOPCOUNT_1)
        AddF(LVar0, Float(31.0 / LOOPCOUNT_1))
        Call(N(SetItemPositionF), MV_StarStoneItemID, Float(230.0), LVar0, Float(0.0))
        Wait(1)
    EndLoop
    Call(SetPanTarget, CAM_DEFAULT, 160, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merlar, ANIM_Merlar_Talk, ANIM_Merlar_Hover, 0, MSG_CH7_0138)
    KillThread(LVar8)
    KillThread(LVar9)
    Thread
        Set(LVar0, 30)
        Loop(5)
            Sub(LVar0, 5)
            PlayEffect(EFFECT_SPARKLES, 2, 230, 30, 0, LVar0)
            Wait(20)
        EndLoop
    EndThread
    SetF(LVar0, Float(100.0))
    Loop(LOOPCOUNT_2)
        AddF(LVar0, Float(-100.0 / LOOPCOUNT_2))
        Call(SetNpcImgFXParams, NPC_Merlar, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_Merlar, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH7_GOT_STAR_STONE)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
