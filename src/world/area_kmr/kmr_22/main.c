#include "kmr_22.h"
#include "effects.h"
#include "sprite/player.h"

BSS EffectInstance* N(ChapterEffect);
BSS s32 N(ChapterEffectTime);

#if VERSION_PAL
#define CHUNK_SIZE (8)
#else
#define CHUNK_SIZE (10)
#endif


s16 N(AnimTextOffsets)[CHUNK_SIZE * 2] = {
#if VERSION_PAL
    310, 270, 240, 210,
    180, 150, 120, 100,
     80,  50,  24,  12,
      5,   3,   2,   1,
#else
    310, 290, 270, 250, 230,
    210, 190, 170, 150, 130,
    110,  90,  70,  50,  32,
     16,   8,   4,   2,   1,
#endif
};

API_CALLABLE(N(ManageEffects)) {
    s32 var_s0 = script->varTable[0];
    s32 x, y;
    s32 xOffset = 0;

    if (var_s0 == 0) {
        var_s0 = 9;
        xOffset = 38;
    }

    if (isInitialCall) {
        set_curtain_scale_goal(1.0f);
        N(ChapterEffect) = fx_chapter_change(var_s0, 100.0f, 100.0f, 0.0f, 1.0f, 0);
        N(ChapterEffectTime) = 0;
    }

    x = xOffset + 117;
    if (N(ChapterEffectTime) >= 0) {
        if (N(ChapterEffectTime) < 2 * CHUNK_SIZE) {
            x -= N(AnimTextOffsets)[N(ChapterEffectTime)];
        }
    } else {
        x = xOffset - 193;
    }
    y = 58;
    N(ChapterEffect)->data.chapterChange->chapterPos.x = x;
    N(ChapterEffect)->data.chapterChange->chapterPos.y = y;

    x = xOffset + 117;
    if (N(ChapterEffectTime) >= CHUNK_SIZE) {
        if (N(ChapterEffectTime) < 3 * CHUNK_SIZE) {
            y -= N(AnimTextOffsets)[N(ChapterEffectTime) - CHUNK_SIZE];
        }
    } else {
        y = -252;
    }
    N(ChapterEffect)->data.chapterChange->endOfPos.x = x;
    N(ChapterEffect)->data.chapterChange->endOfPos.y = y;

    x = 280;
    if (N(ChapterEffectTime) >= 2 * CHUNK_SIZE) {
        if (N(ChapterEffectTime) < 4 * CHUNK_SIZE) {
            x += N(AnimTextOffsets)[N(ChapterEffectTime) - 2 * CHUNK_SIZE];
        }
    } else {
        x = 590;
    }
    y = 90;
    N(ChapterEffect)->data.chapterChange->unk_40 = x;
    N(ChapterEffect)->data.chapterChange->unk_44 = y;
    N(ChapterEffectTime)++;

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(DismissCurtains)) {
    set_curtain_scale_goal(2.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WaitForContinueInput)) {
    ApiStatus ret;

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_START) {
        ret = ApiStatus_DONE2;
    } else {
        ret = ApiStatus_BLOCK;
    }

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        ret = ApiStatus_DONE2;
        script->varTable[0] = -1;
    }
    return ret;
}

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Thread
        Call(N(ManageEffects))
    EndThread
    Wait(50)
    Call(N(WaitForContinueInput))
    Call(FadeOutMusic, 0, 2000)
    Wait(30)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kmr_22_ENTRY_0)
            Call(GotoMapSpecial, Ref("kmr_00"), kmr_00_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_1)
            Call(GotoMapSpecial, Ref("nok_11"), nok_11_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_2)
            Call(GotoMapSpecial, Ref("iwa_10"), iwa_10_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_3)
            Call(GotoMapSpecial, Ref("mim_01"), mim_01_ENTRY_1, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_4)
            Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_4, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_5)
            Call(GotoMapSpecial, Ref("jan_00"), jan_00_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_6)
            Call(GotoMapSpecial, Ref("flo_00"), flo_00_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_7)
            Call(GotoMapSpecial, Ref("sam_02"), sam_02_ENTRY_2, TRANSITION_BEGIN_OR_END_CHAPTER)
        CaseEq(kmr_22_ENTRY_8)
            Call(GotoMapSpecial, Ref("kpa_63"), kpa_63_ENTRY_1, TRANSITION_BEGIN_OR_END_CHAPTER)
    EndSwitch
    Call(N(DismissCurtains))
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_22_ENTRY_0)
        Call(SetPlayerPos, -200, 0, 0)
    Else
        Call(SetPlayerPos, -95, 0, 0)
    EndIf
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(InterpPlayerYaw, 90, 0)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EndIf
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 208, 208, 208)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 440)
    Call(SetCamPosA, CAM_DEFAULT, 0, 100)
    Call(SetCamPosB, CAM_DEFAULT, 0, 0)
    Call(SetCamPosC, CAM_DEFAULT, 0, 65)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kmr_22_ENTRY_1)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter1)))
        CaseEq(kmr_22_ENTRY_2)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter2)))
        CaseEq(kmr_22_ENTRY_3)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter3)))
        CaseEq(kmr_22_ENTRY_4)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter4)))
        CaseEq(kmr_22_ENTRY_5)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter5)))
        CaseEq(kmr_22_ENTRY_6)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter6)))
        CaseEq(kmr_22_ENTRY_7)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter7)))
        CaseEq(kmr_22_ENTRY_8)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Chapter8)))
    EndSwitch
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Wait(1)
    Exec(N(EVS_EnterMap))
    Call(SetMusicTrack, 0, SONG_CHAPTER_START, 0, 8)
    Call(ClearAmbientSounds, 250)
    Return
    End
};
