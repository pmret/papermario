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
    EVT_CALL(GetEntryID, LVar0)
    EVT_THREAD
        EVT_CALL(N(ManageEffects))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(N(WaitForContinueInput))
    EVT_CALL(FadeOutMusic, 0, 2000)
    EVT_WAIT(30)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kmr_22_ENTRY_0)
            EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_00"), kmr_00_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_1)
            EVT_CALL(GotoMapSpecial, EVT_PTR("nok_11"), nok_11_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_2)
            EVT_CALL(GotoMapSpecial, EVT_PTR("iwa_10"), iwa_10_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_3)
            EVT_CALL(GotoMapSpecial, EVT_PTR("mim_01"), mim_01_ENTRY_1, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_4)
            EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_4, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_5)
            EVT_CALL(GotoMapSpecial, EVT_PTR("jan_00"), jan_00_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_6)
            EVT_CALL(GotoMapSpecial, EVT_PTR("flo_00"), flo_00_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_7)
            EVT_CALL(GotoMapSpecial, EVT_PTR("sam_02"), sam_02_ENTRY_2, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_CASE_EQ(kmr_22_ENTRY_8)
            EVT_CALL(GotoMapSpecial, EVT_PTR("kpa_63"), kpa_63_ENTRY_1, TRANSITION_BEGIN_OR_END_CHAPTER)
    EVT_END_SWITCH
    EVT_CALL(N(DismissCurtains))
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_22_ENTRY_0)
        EVT_CALL(SetPlayerPos, -200, 0, 0)
    EVT_ELSE
        EVT_CALL(SetPlayerPos, -95, 0, 0)
    EVT_END_IF
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 208, 208, 208)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 440)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 100)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 65)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kmr_22_ENTRY_1)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter1)))
        EVT_CASE_EQ(kmr_22_ENTRY_2)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter2)))
        EVT_CASE_EQ(kmr_22_ENTRY_3)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter3)))
        EVT_CASE_EQ(kmr_22_ENTRY_4)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter4)))
        EVT_CASE_EQ(kmr_22_ENTRY_5)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter5)))
        EVT_CASE_EQ(kmr_22_ENTRY_6)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter6)))
        EVT_CASE_EQ(kmr_22_ENTRY_7)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter7)))
        EVT_CASE_EQ(kmr_22_ENTRY_8)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Chapter8)))
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(SetMusicTrack, 0, SONG_CHAPTER_START, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
