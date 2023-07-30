#include "common.h"
#include "effects.h"
#include "hud_element.h"
#include "message_ids.h"
#include "ld_addrs.h"
#include "model.h"
#include "script_api/battle.h"
#include "entity.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleBombette.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/Goompa.h"
#include "sprite/npc/BattleWatt.h"
#include "sprite/npc/BattleSushie.h"
#include "sprite/npc/BattleLakilester.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/player.h"

extern HudScript HES_ProjectorBeam;
extern IconHudScriptPair gItemHudScripts[];

// menu position index for level up screen
enum {
    MENU_HP  = 0,
    MENU_FP  = 1,
    MENU_BP  = 2,
};

// first index for LevelUpStatTextIDs
enum {
    LVL_UP_FP  = 0,
    LVL_UP_HP  = 1,
    LVL_UP_BP  = 2,
};

// second index for LevelUpStatTextIDs
enum {
    LVL_UP_TITLE        = 0,
    LVL_UP_CUR_TENS     = 1,
    LVL_UP_CUR_ONES     = 2,
    LVL_UP_ARROW        = 3,
    LVL_UP_NEXT_TENS    = 4,
    LVL_UP_NEXT_ONES    = 5,
    LVL_UP_BONUS        = 6,
};

BSS HudElemID LevelUpStatEmblemIDs[4];
BSS HudElemID LevelUpStatTextIDs[3][7];
BSS s32 D_8029FAE4; // unused?
BSS HudElemID LevelUpSpotlightID;
BSS s32 D_8029FAEC[23]; // unused?

BSS HudElemID LevelUpSelectTextID;
BSS s32 CelebrateSubstateTime;
BSS s32 D_8029FB50;
BSS s32 EndBattleRewardStep;
BSS s32 D_8029FB58[2]; // unused?
BSS s32 CantLevelUpStat[3];
BSS s32 EndBattleRewardTotal;
BSS s32 EndBattleRewardIncrement;
BSS s32 pendingLevelUps;
BSS s32 EndBattleRewardsDone;
BSS Evt* LevelUpScriptPtr;
BSS s32 LevelUpScriptID;
BSS s32 CelebrateStateTime;
BSS s32 LevelUpSelectTextOffsetX;
BSS s32 LevelUpSelectTextVelX;

extern EntityModelScript EMS_starpoint_starpoint;
extern EntityModelScript EMS_starpoint_starpoints;
extern EntityModelScript EMS_starpoint_digit_0;
extern EntityModelScript EMS_starpoint_digit_1;
extern EntityModelScript EMS_starpoint_digit_2;
extern EntityModelScript EMS_starpoint_digit_3;
extern EntityModelScript EMS_starpoint_digit_4;
extern EntityModelScript EMS_starpoint_digit_5;
extern EntityModelScript EMS_starpoint_digit_6;
extern EntityModelScript EMS_starpoint_digit_7;
extern EntityModelScript EMS_starpoint_digit_8;
extern EntityModelScript EMS_starpoint_digit_9;
extern EntityModelScript EMS_starpoint_dummy;

extern EntityModelScript EMS_level_up;

extern HudScript HES_level_up_flower;
extern HudScript HES_level_up_leaves;
extern HudScript HES_level_up_heart;
extern HudScript HES_level_up_heart_copy;
extern HudScript HES_level_up_badge;

extern HudScript HES_level_up_FP;
extern HudScript HES_level_up_HP;
extern HudScript HES_level_up_BP;

extern HudScript HES_level_up_green_digit_0;
extern HudScript HES_level_up_green_digit_1;
extern HudScript HES_level_up_green_digit_2;
extern HudScript HES_level_up_green_digit_3;
extern HudScript HES_level_up_green_digit_4;
extern HudScript HES_level_up_green_digit_5;
extern HudScript HES_level_up_green_digit_6;
extern HudScript HES_level_up_green_digit_7;
extern HudScript HES_level_up_green_digit_8;
extern HudScript HES_level_up_green_digit_9;
extern HudScript HES_level_up_red_digit_0;
extern HudScript HES_level_up_red_digit_1;
extern HudScript HES_level_up_red_digit_2;
extern HudScript HES_level_up_red_digit_3;
extern HudScript HES_level_up_red_digit_4;
extern HudScript HES_level_up_red_digit_5;
extern HudScript HES_level_up_red_digit_6;
extern HudScript HES_level_up_red_digit_7;
extern HudScript HES_level_up_red_digit_8;
extern HudScript HES_level_up_red_digit_9;
extern HudScript HES_level_up_blue_digit_0;
extern HudScript HES_level_up_blue_digit_1;
extern HudScript HES_level_up_blue_digit_2;
extern HudScript HES_level_up_blue_digit_3;
extern HudScript HES_level_up_blue_digit_4;
extern HudScript HES_level_up_blue_digit_5;
extern HudScript HES_level_up_blue_digit_6;
extern HudScript HES_level_up_blue_digit_7;
extern HudScript HES_level_up_blue_digit_8;
extern HudScript HES_level_up_blue_digit_9;

extern HudScript HES_level_up_small_green_digit_0;
extern HudScript HES_level_up_small_green_digit_1;
extern HudScript HES_level_up_small_green_digit_2;
extern HudScript HES_level_up_small_green_digit_3;
extern HudScript HES_level_up_small_green_digit_4;
extern HudScript HES_level_up_small_green_digit_5;
extern HudScript HES_level_up_small_green_digit_6;
extern HudScript HES_level_up_small_green_digit_7;
extern HudScript HES_level_up_small_green_digit_8;
extern HudScript HES_level_up_small_green_digit_9;
extern HudScript HES_level_up_small_green_arrow;
extern HudScript HES_level_up_small_red_digit_0;
extern HudScript HES_level_up_small_red_digit_1;
extern HudScript HES_level_up_small_red_digit_2;
extern HudScript HES_level_up_small_red_digit_3;
extern HudScript HES_level_up_small_red_digit_4;
extern HudScript HES_level_up_small_red_digit_5;
extern HudScript HES_level_up_small_red_digit_6;
extern HudScript HES_level_up_small_red_digit_7;
extern HudScript HES_level_up_small_red_digit_8;
extern HudScript HES_level_up_small_red_digit_9;
extern HudScript HES_level_up_small_red_arrow;
extern HudScript HES_level_up_small_blue_digit_0;
extern HudScript HES_level_up_small_blue_digit_1;
extern HudScript HES_level_up_small_blue_digit_2;
extern HudScript HES_level_up_small_blue_digit_3;
extern HudScript HES_level_up_small_blue_digit_4;
extern HudScript HES_level_up_small_blue_digit_5;
extern HudScript HES_level_up_small_blue_digit_6;
extern HudScript HES_level_up_small_blue_digit_7;
extern HudScript HES_level_up_small_blue_digit_8;
extern HudScript HES_level_up_small_blue_digit_9;
extern HudScript HES_level_up_small_blue_arrow;

extern HudScript HES_level_up_select_one_to_upgrade;

s32 bFadeToBlackAmt = 255;

s32 D_80284154[] = {
    [PARTNER_NONE]          = 0,
    [PARTNER_GOOMBARIO]     = ANIM_BattleGoombario_Walk,
    [PARTNER_KOOPER]        = ANIM_BattleKooper_Walk,
    [PARTNER_BOMBETTE]      = ANIM_BattleBombette_Walk,
    [PARTNER_PARAKARRY]     = ANIM_BattleParakarry_Walk,
    [PARTNER_GOOMPA]        = ANIM_Goompa_Walk,
    [PARTNER_WATT]          = ANIM_BattleWatt_Walk,
    [PARTNER_SUSHIE]        = ANIM_BattleSushie_Walk,
    [PARTNER_LAKILESTER]    = ANIM_BattleLakilester_Walk,
    [PARTNER_BOW]           = ANIM_BattleBow_Walk,
    [PARTNER_GOOMBARIA]     = 0,
    [PARTNER_TWINK]         = 0,
    0
};

EntityModelScript* starpoint_digit_scripts[] = {
    &EMS_starpoint_digit_0,
    &EMS_starpoint_digit_1,
    &EMS_starpoint_digit_2,
    &EMS_starpoint_digit_3,
    &EMS_starpoint_digit_4,
    &EMS_starpoint_digit_5,
    &EMS_starpoint_digit_6,
    &EMS_starpoint_digit_7,
    &EMS_starpoint_digit_8,
    &EMS_starpoint_digit_9,
};

EntityModelScript* starpoint_space_script = &EMS_starpoint_dummy;

HudScript* levelup_stat_scripts[3] = {
    &HES_level_up_FP,
    &HES_level_up_HP,
    &HES_level_up_BP,
};

HudScript* HES_LevelUpDigits[3][10] = {
    {
        &HES_level_up_green_digit_0,
        &HES_level_up_green_digit_1,
        &HES_level_up_green_digit_2,
        &HES_level_up_green_digit_3,
        &HES_level_up_green_digit_4,
        &HES_level_up_green_digit_5,
        &HES_level_up_green_digit_6,
        &HES_level_up_green_digit_7,
        &HES_level_up_green_digit_8,
        &HES_level_up_green_digit_9,
    },
    {
        &HES_level_up_red_digit_0,
        &HES_level_up_red_digit_1,
        &HES_level_up_red_digit_2,
        &HES_level_up_red_digit_3,
        &HES_level_up_red_digit_4,
        &HES_level_up_red_digit_5,
        &HES_level_up_red_digit_6,
        &HES_level_up_red_digit_7,
        &HES_level_up_red_digit_8,
        &HES_level_up_red_digit_9,
    },
    {
        &HES_level_up_blue_digit_0,
        &HES_level_up_blue_digit_1,
        &HES_level_up_blue_digit_2,
        &HES_level_up_blue_digit_3,
        &HES_level_up_blue_digit_4,
        &HES_level_up_blue_digit_5,
        &HES_level_up_blue_digit_6,
        &HES_level_up_blue_digit_7,
        &HES_level_up_blue_digit_8,
        &HES_level_up_blue_digit_9,
    },
};

HudScript* level_up_small_digit_scripts[3][10] = {
    {
        &HES_level_up_small_green_digit_0,
        &HES_level_up_small_green_digit_1,
        &HES_level_up_small_green_digit_2,
        &HES_level_up_small_green_digit_3,
        &HES_level_up_small_green_digit_4,
        &HES_level_up_small_green_digit_5,
        &HES_level_up_small_green_digit_6,
        &HES_level_up_small_green_digit_7,
        &HES_level_up_small_green_digit_8,
        &HES_level_up_small_green_digit_9,
    },
    {
        &HES_level_up_small_red_digit_0,
        &HES_level_up_small_red_digit_1,
        &HES_level_up_small_red_digit_2,
        &HES_level_up_small_red_digit_3,
        &HES_level_up_small_red_digit_4,
        &HES_level_up_small_red_digit_5,
        &HES_level_up_small_red_digit_6,
        &HES_level_up_small_red_digit_7,
        &HES_level_up_small_red_digit_8,
        &HES_level_up_small_red_digit_9,
    },
    {
        &HES_level_up_small_blue_digit_0,
        &HES_level_up_small_blue_digit_1,
        &HES_level_up_small_blue_digit_2,
        &HES_level_up_small_blue_digit_3,
        &HES_level_up_small_blue_digit_4,
        &HES_level_up_small_blue_digit_5,
        &HES_level_up_small_blue_digit_6,
        &HES_level_up_small_blue_digit_7,
        &HES_level_up_small_blue_digit_8,
        &HES_level_up_small_blue_digit_9,
    },
};

s32* virtual_entity_get_by_index(s32);

void draw_content_level_up_textbox(void* data, s32 posX, s32 posY);
void draw_content_cant_increase_popup(void* data, s32 posX, s32 posY);

API_CALLABLE(GetRemainingStarPointsReward) {
    script->varTable[0] = (s8)gBattleStatus.totalStarPoints;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetStarPointDigitScripts) {
    s32 levelUp = FALSE;

    script->varTable[10] = gBattleStatus.totalStarPoints / 100; // star points in hundreds (levels to gain)
    script->varTable[11] = (gBattleStatus.totalStarPoints % 100) / 10; // star points in tens
    script->varTable[12] = gBattleStatus.totalStarPoints % 10; // star points in ones

    if (script->varTable[10] > 0) {
        script->varTablePtr[10] = starpoint_digit_scripts[script->varTable[10]];
        levelUp = TRUE;
    } else {
        script->varTablePtr[10] = starpoint_space_script;
    }

    if ((script->varTable[11] > 0) || levelUp) {
        script->varTablePtr[11] = starpoint_digit_scripts[script->varTable[11]];
    } else {
        script->varTablePtr[11] = starpoint_space_script;
    }

    script->varTablePtr[12] = starpoint_digit_scripts[script->varTable[12]];
    return ApiStatus_DONE2;
}

API_CALLABLE(AwaitBattleRewardsDone) {
    if (EndBattleRewardsDone) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(InitStarPointModelFlags) {
    EntityModel* model;

    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[6]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAG_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[7]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAG_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[8]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAG_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAG_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

API_CALLABLE(InitLevelUpModelFlags) {
    EntityModel* model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0;
    model->flags |= MODEL_FLAG_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

API_CALLABLE(MakeLevelUpConfetti) {
    fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 120);
    return ApiStatus_DONE2;
}

EvtScript EVS_ShowStarpoints = {
    EVT_SET(LVarF, 0)
    EVT_CALL(GetRemainingStarPointsReward)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(LVar0, 2)
        EVT_CALL(CreateVirtualEntity, LVar6, EVT_PTR(EMS_starpoint_starpoint))
        EVT_CALL(SetVirtualEntityPosition, LVar6, -278, 68, 70)
        EVT_CALL(SetVirtualEntityScale, LVar6, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_ELSE
        EVT_CALL(CreateVirtualEntity, LVar6, EVT_PTR(EMS_starpoint_starpoints))
        EVT_CALL(SetVirtualEntityPosition, LVar6, -278, 68, 70)
        EVT_CALL(SetVirtualEntityScale, LVar6, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_SET(LVarF, 3)
        EVT_CASE_GT(9)
            EVT_SET(LVarF, 2)
        EVT_CASE_DEFAULT
            EVT_SET(LVarF, 1)
    EVT_END_SWITCH
    EVT_CALL(GetStarPointDigitScripts)
    EVT_CALL(CreateVirtualEntity, LVar7, LVarA)
    EVT_CALL(SetVirtualEntityPosition, LVar7, -353, 68, 70)
    EVT_CALL(SetVirtualEntityScale, LVar7, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(CreateVirtualEntity, LVar8, LVarB)
    EVT_CALL(SetVirtualEntityPosition, LVar8, -338, 68, 70)
    EVT_CALL(SetVirtualEntityScale, LVar8, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(CreateVirtualEntity, LVar9, LVarC)
    EVT_CALL(SetVirtualEntityPosition, LVar9, -323, 68, 70)
    EVT_CALL(SetVirtualEntityScale, LVar9, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(InitStarPointModelFlags)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, -197)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, -204)
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, -211)
    EVT_END_SWITCH
    EVT_LOOP(10)
        EVT_ADD(LVar0, 20)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -78)
        EVT_CALL(SetVirtualEntityPosition, LVar6, LVar1, 68, 70)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -146)
        EVT_CALL(SetVirtualEntityPosition, LVar7, LVar1, 68, 70)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -131)
        EVT_CALL(SetVirtualEntityPosition, LVar8, LVar1, 68, 70)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -116)
        EVT_CALL(SetVirtualEntityPosition, LVar9, LVar1, 68, 70)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(AwaitBattleRewardsDone)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 3)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, -4)
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, -11)
    EVT_END_SWITCH
    EVT_LOOP(10)
        EVT_ADD(LVar0, 20)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -78)
        EVT_CALL(SetVirtualEntityPosition, LVar6, LVar1, 68, 70)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -154)
        EVT_CALL(SetVirtualEntityPosition, LVar7, LVar1, 68, 70)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -139)
        EVT_CALL(SetVirtualEntityPosition, LVar8, LVar1, 68, 70)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, -124)
        EVT_CALL(SetVirtualEntityPosition, LVar9, LVar1, 68, 70)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DeleteVirtualEntity, LVar6)
    EVT_CALL(DeleteVirtualEntity, LVar7)
    EVT_CALL(DeleteVirtualEntity, LVar8)
    EVT_CALL(DeleteVirtualEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ShowLevelUp = {
    EVT_CALL(CreateVirtualEntity, LVar9, EVT_PTR(EMS_level_up))
    EVT_CALL(SetVirtualEntityPosition, LVar9, 0, 210, 70)
    EVT_CALL(InitLevelUpModelFlags)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_CALL(MakeLevelUpConfetti)
    EVT_END_CHILD_THREAD
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(2.25))
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.2))
        EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.45))
        EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.15))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 210)
        EVT_LOOP(10)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetVirtualEntityPosition, LVar9, 0, LVar0, 70)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

void btl_state_update_celebration(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s8 currentSubmenu;
    s32 newSubmenu;
    s32 id;
    s32 x, y, z;
    s32 width;
    s32 itemHudElemID;

    Evt* takeTurnScript;
    Evt* script;

    s32 tensDigit;
    s32 onesDigit;

    s32 deltaSP;
    s32 prevSP;

    s32 i;
    s32 j;

    HudScript* new_var;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_INIT:
            if (battleStatus->pendingStarPoints <= 0) {
                player->flags &= ~ACTOR_FLAG_8000000;
                EndBattleRewardTotal = battleStatus->totalStarPoints * 100;
                pendingLevelUps = 0;
                D_8029FB50 = 0;
                bFadeToBlackAmt = 0;
                LevelUpSelectTextOffsetX = 0;
                LevelUpSelectTextVelX = 0;
                sfx_play_sound(SOUND_D4);

                prevSP = playerData->starPoints + battleStatus->totalStarPoints;
                if (prevSP > 99) {
                    bgm_set_song(0, SONG_LEVEL_UP, 0, 250, 8);
                } else {
                    bgm_set_song(0, SONG_BATTLE_END, 0, 250, 8);
                }

                CelebrateStateTime = 0;
                btl_cam_use_preset(BTL_CAM_VICTORY);
                EndBattleRewardStep = 0;
                CelebrateSubstateTime = 1;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LOAD_STAR_POINTS;
                gBattleStatus.flags2 |= BS_FLAGS2_1;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LOAD_STAR_POINTS:
            if (CelebrateSubstateTime != 0) {
                CelebrateSubstateTime--;
            } else if (btl_cam_is_moving_done()) {
                DMA_COPY_SEGMENT(starpoint);
                script = start_script(&EVS_ShowStarpoints, EVT_PRIORITY_A, 0);
                EndBattleRewardsDone = FALSE;
                // divide reward into 20 increments
                EndBattleRewardStep = 20;
                EndBattleRewardIncrement = EndBattleRewardTotal / EndBattleRewardStep;
                player->takeTurnScript = script;
                CelebrateSubstateTime = 1;
                player->takeTurnScriptID = script->id;
                script->owner1.actorID = ACTOR_PLAYER;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_TALLY_STAR_POINTS;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_TALLY_STAR_POINTS:
            if (CelebrateSubstateTime == 0) {
                if (battleStatus->totalStarPoints != 0) {
                    // determine the remaining star point reward after this step and give the difference to the player
                    EndBattleRewardTotal -= EndBattleRewardIncrement;
                    prevSP = battleStatus->totalStarPoints;
                    battleStatus->totalStarPoints = EndBattleRewardTotal / 100;
                    deltaSP = prevSP - battleStatus->totalStarPoints;
                    if (deltaSP > 0) {
                        sfx_play_sound(SOUND_215);
                    }

                    playerData->starPoints += deltaSP;
                    bFadeToBlackAmt++; // ??
                    if (EndBattleRewardStep == 0 && battleStatus->totalStarPoints != 0) {
                        playerData->starPoints++;
                    }
                }
                if (playerData->level >= 27) {
                    playerData->starPoints = 0;
                }
                if (playerData->starPoints >= 100) {
                    pendingLevelUps = 1;
                    playerData->starPoints -= 100;
                }
                if (playerData->level + pendingLevelUps == 27) {
                    playerData->starPoints = 0;
                }
                if (battleStatus->totalStarPoints == 0) {
                    if (EndBattleRewardStep == 0) {
                        EndBattleRewardsDone = TRUE;
                        player->flags &= ~(ACTOR_FLAG_4000000 | ACTOR_FLAG_8000000);
                        if (partner != NULL) {
                            partner->flags &= ~(ACTOR_FLAG_4000000 | ACTOR_FLAG_8000000);
                        }
                        battleStatus->battlePhase = PHASE_CELEBRATE;
                        script = start_script(&EVS_Mario_HandlePhase, EVT_PRIORITY_A, 0);
                        player->takeTurnScript = script;
                        player->takeTurnScriptID = script->id;
                        script->owner1.actorID = ACTOR_PLAYER;
                        if (partner != NULL) {
                            script = start_script(partner->takeTurnSource, EVT_PRIORITY_A, 0);
                            partner->takeTurnScript = script;
                            partner->takeTurnScriptID = script->id;
                            script->owner1.actorID = ACTOR_PARTNER;
                        }
                        CelebrateSubstateTime = 40;
                        gBattleSubState = BTL_SUBSTATE_CELEBRATE_POST_STAR_POINTS;
                    } else {
                        EndBattleRewardStep--;
                    }
                }
            } else {
                CelebrateSubstateTime--;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_POST_STAR_POINTS:
            if (CelebrateSubstateTime == 0) {
                if (pendingLevelUps == 0) {
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_SKIPPABLE_END_DELAY;
                } else {
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_LOAD;
                }
                break;
            }
            CelebrateSubstateTime--;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_LOAD:
            if (CelebrateStateTime >= 99) {
                playerData->level++;
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(5);
                DMA_COPY_SEGMENT(level_up);
                sfx_play_sound(SOUND_80000008);
                CelebrateStateTime = 0;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_BEGIN;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_BEGIN:
            LevelUpScriptPtr = start_script(&EVS_ShowLevelUp, EVT_PRIORITY_A, 0);
            LevelUpScriptID = LevelUpScriptPtr->id;
            CelebrateSubstateTime = 25;
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CREATE_HUD;
            mdl_set_all_fog_mode(FOG_MODE_1);
            *gBackgroundFogModePtr = FOG_MODE_1;
            set_background_color_blend(0, 0, 0, 0);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CREATE_HUD:
            if (CelebrateSubstateTime == 18) {
                playerData->curHP = playerData->curMaxHP;
                playerData->curFP = playerData->curMaxFP;
                x = player->curPos.x + 0.0f;
                y = player->curPos.y + 35.0f;
                z = player->curPos.z;
                fx_recover(0, x, y, z, playerData->curHP);
                x = player->curPos.x + 20.0f;
                y = player->curPos.y + 25.0f;
                z = player->curPos.z;
                fx_recover(1, x, y, z, playerData->curFP);
                playerData->specialBarsFilled = playerData->maxStarPower * 256;
            }

            if (CelebrateSubstateTime != 0) {
                CelebrateSubstateTime--;
                if (CelebrateSubstateTime < 10) {
                    set_background_color_blend(0, 0, 0, ((10 - CelebrateSubstateTime) * 16) & 0xF0);
                }
            } else {
                id = hud_element_create(&HES_level_up_heart);
                LevelUpStatEmblemIDs[0] = id;
                hud_element_set_render_pos(id, 310, 140);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                id = hud_element_create(&HES_level_up_flower);
                LevelUpStatEmblemIDs[1] = id;
                hud_element_set_render_pos(id, 158, 340);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                id = hud_element_create(&HES_level_up_leaves);
                LevelUpStatEmblemIDs[3] = id;
                hud_element_set_render_pos(id, 158, 340);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                id = hud_element_create(&HES_level_up_badge);
                LevelUpStatEmblemIDs[2] = id;
                hud_element_set_render_pos(id, 6, 140);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                id = hud_element_create(levelup_stat_scripts[0]);
                LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_TITLE] = id;
                hud_element_set_render_pos(id, 160, 317);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                for (i = 1; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                    id = hud_element_create(HES_LevelUpDigits[LVL_UP_FP][0]);
                    LevelUpStatTextIDs[LVL_UP_FP][i] = id;
                    hud_element_set_render_pos(id, 160, 317);
                    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
                }

                id = hud_element_create(levelup_stat_scripts[1]);
                LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_TITLE] = id;
                hud_element_set_render_pos(id, 312, 117);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                for (i = 1; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_HP]); i++) {
                    id = hud_element_create(HES_LevelUpDigits[LVL_UP_HP][0]);
                    LevelUpStatTextIDs[LVL_UP_HP][i] = id;
                    hud_element_set_render_pos(id, 312, 117);
                    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
                }

                id = hud_element_create(levelup_stat_scripts[2]);
                LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_TITLE] = id;
                hud_element_set_render_pos(id, 8, 117);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);

                for (i = 1; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_BP]); i++) {
                    id = hud_element_create(HES_LevelUpDigits[LVL_UP_BP][0]);
                    LevelUpStatTextIDs[LVL_UP_BP][i] = id;
                    hud_element_set_render_pos(id, 8, 117);
                    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
                }

                CantLevelUpStat[MENU_HP] = FALSE;
                CantLevelUpStat[MENU_FP] = FALSE;
                CantLevelUpStat[MENU_BP] = FALSE;

                if (playerData->hardMaxFP != 50) {
                    // current FP
                    tensDigit = playerData->curMaxFP / 10;
                    onesDigit = playerData->curMaxFP % 10;
                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_CUR_TENS];
                    hud_element_set_script(id, level_up_small_digit_scripts[LVL_UP_FP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 14, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_CUR_ONES];
                    hud_element_set_script(id, level_up_small_digit_scripts[LVL_UP_FP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 8, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_ARROW];
                    hud_element_set_script(id, &HES_level_up_small_green_arrow);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 3, y + 46);

                    // upgraded FP
                    tensDigit = (playerData->curMaxFP + 5) / 10;
                    onesDigit = (playerData->curMaxFP + 5) % 10;
                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_FP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 3, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_FP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 10, y + 46);
                } else {
                    // upgraded FP only
                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_NEXT_TENS];
                    tensDigit = playerData->curMaxFP / 10;
                    onesDigit = playerData->curMaxFP % 10;
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_FP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 6, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_FP][onesDigit]);
                    hud_element_clear_flags(id, 2);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 2, y + 46);
                    CantLevelUpStat[MENU_FP] = TRUE;
                }

                if (is_ability_active(ABILITY_FP_PLUS)) {
                    id = LevelUpStatTextIDs[LVL_UP_FP][LVL_UP_BONUS];
                    itemHudElemID = gItemTable[ITEM_FP_PLUS_A].hudElemID;
                    hud_element_set_script(id, gItemHudScripts[itemHudElemID].enabled);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_set_scale(id, 0.5f);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 17, y + 46);
                }

                if (playerData->hardMaxHP != 50) {
                    // current HP
                    tensDigit = playerData->curMaxHP / 10;
                    onesDigit = playerData->curMaxHP % 10;

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_CUR_TENS];
                    hud_element_set_script(id, level_up_small_digit_scripts[LVL_UP_HP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 14, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_CUR_ONES];
                    hud_element_set_script(id, level_up_small_digit_scripts[LVL_UP_HP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 8, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_ARROW];
                    hud_element_set_script(id, &HES_level_up_small_red_arrow);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 3, y + 46);

                    tensDigit = (playerData->curMaxHP + 5) / 10;
                    onesDigit = (playerData->curMaxHP + 5) % 10;

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_HP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 3, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_HP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 10, y + 46);
                } else {
                    tensDigit = playerData->curMaxHP / 10;
                    onesDigit = playerData->curMaxHP % 10;

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_HP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 6, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_HP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 2, y + 46);
                    CantLevelUpStat[MENU_HP] = TRUE;
                }

                if (is_ability_active(ABILITY_HP_PLUS)) {
                    id = LevelUpStatTextIDs[LVL_UP_HP][LVL_UP_BONUS];
                    itemHudElemID = gItemTable[ITEM_HP_PLUS_A].hudElemID;
                    hud_element_set_script(id, gItemHudScripts[itemHudElemID].enabled);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_set_scale(id, 0.5f);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 17, y + 46);
                }

                if (playerData->maxBP != 30) {
                    tensDigit = playerData->maxBP / 10;
                    onesDigit = playerData->maxBP % 10;

                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_CUR_TENS];
                    hud_element_set_script(id, level_up_small_digit_scripts[LVL_UP_BP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 14, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_CUR_ONES];
                    hud_element_set_script(id, level_up_small_digit_scripts[LVL_UP_BP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 8, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_ARROW];
                    hud_element_set_script(id, &HES_level_up_small_blue_arrow);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 3, y + 46);

                    tensDigit = (playerData->maxBP + 3) / 10;
                    onesDigit = (playerData->maxBP + 3) % 10;

                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_BP][tensDigit]);
                    if (tensDigit != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 3, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_BP][onesDigit]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 10, y + 46);
                } else {
                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_BP][3]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 6, y + 46);

                    id = LevelUpStatTextIDs[LVL_UP_BP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, HES_LevelUpDigits[LVL_UP_BP][0]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 2, y + 46);
                    CantLevelUpStat[MENU_BP] = TRUE;
                }

                id = LevelUpSpotlightID = hud_element_create(&HES_ProjectorBeam);
                hud_element_create_transform_B(id);
                hud_element_set_render_pos(id, 156, 13);
                hud_element_set_tint(id, 255, 255, 255);
                hud_element_set_transform_rotation_pivot(id, 0, -35);
                hud_element_set_transform_rotation(id, 0.0f, 0.0f, 180.0f);
                hud_element_set_transform_scale(id, 1.0f, 1.5f, 1.0f);
                hud_element_set_alpha(id, 200);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);

                id = LevelUpSelectTextID = hud_element_create(&HES_level_up_select_one_to_upgrade);
                hud_element_set_render_pos(id, 0, 0);
                hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);
                battleStatus->curSubmenu = 1;

                CelebrateSubstateTime = 10;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD:
            id = LevelUpStatEmblemIDs[0];
            hud_element_get_render_pos(id, &x, &y);
            x -= 20;
            hud_element_set_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_HP]); i++) {
                id = LevelUpStatTextIDs[LVL_UP_HP][i];
                hud_element_get_render_pos(id, &x, &y);
                x -= 20;
                hud_element_set_render_pos(id, x, y);
            }

            id = LevelUpStatEmblemIDs[1];
            hud_element_get_render_pos(id, &x, &y);
            y -= 20;
            hud_element_set_render_pos(id, x, y);

            id = LevelUpStatEmblemIDs[3];
            hud_element_get_render_pos(id, &x, &y);
            y -= 20;
            hud_element_set_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                id = LevelUpStatTextIDs[LVL_UP_FP][i];
                hud_element_get_render_pos(id, &x, &y);
                y -= 20;
                hud_element_set_render_pos(id, x, y);
            }

            id = LevelUpStatEmblemIDs[2];
            hud_element_get_render_pos(id, &x, &y);
            x += 20;
            hud_element_set_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_BP]); i++) {
                id = LevelUpStatTextIDs[LVL_UP_BP][i];
                hud_element_get_render_pos(id, &x, &y);
                x += 20;
                hud_element_set_render_pos(id, x, y);
            }

            CelebrateSubstateTime--;
            if (CelebrateSubstateTime == 0) {
                hud_element_set_tint(id, 128, 128, 128);
                x = 20;
                y = 186;
                set_window_properties(WINDOW_ID_8, 20, 186, 280, 32, WINDOW_PRIORITY_20, draw_content_level_up_textbox, NULL, -1);
                set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
            if (battleStatus->curButtonsPressed & BUTTON_A) {
                if (!CantLevelUpStat[battleStatus->curSubmenu]) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    sfx_play_sound(SOUND_349 | SOUND_ID_TRIGGER_CHANGE_SOUND);
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE;
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID;
                }
                break;
            }

            newSubmenu = currentSubmenu = battleStatus->curSubmenu;
            if (battleStatus->curButtonsHeld & BUTTON_STICK_LEFT) {
                newSubmenu--;
            }
            if (battleStatus->curButtonsHeld & BUTTON_STICK_RIGHT) {
                newSubmenu++;
            }
            if (newSubmenu < 0) {
                newSubmenu = 0;
            }
            if (newSubmenu > 2) {
                newSubmenu = 2;
            }
            if (newSubmenu != currentSubmenu) {
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                battleStatus->curSubmenu = newSubmenu;
            }

            CelebrateStateTime++;
            if (CelebrateStateTime > 100) {
                fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 120);
                CelebrateStateTime = 0;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE:
            hud_element_free(LevelUpSpotlightID);
            set_window_update(WINDOW_ID_8, WINDOW_UPDATE_HIDE);

            switch (battleStatus->curSubmenu) {
                case 0:
                    playerData->hardMaxHP += 5;
                    playerData->curMaxHP += 5;
                    playerData->curHP += 5;
                    if (playerData->curMaxHP > 75) {
                        playerData->curMaxHP = 75;
                    }
                    if (playerData->curHP > playerData->curMaxHP) {
                        playerData->curHP = playerData->curMaxHP;
                    }
                    player->maxHP = playerData->curMaxHP;
                    player->curHP = playerData->curHP;
                    break;
                case 1:
                    playerData->hardMaxFP += 5;
                    playerData->curMaxFP += 5;
                    playerData->curFP += 5;
                    if (playerData->curMaxFP > 75) {
                        playerData->curMaxFP = 75;
                    }
                    if (playerData->curFP > playerData->curMaxFP) {
                        playerData->curFP = playerData->curMaxFP;
                    }
                    break;
                case 2:
                    playerData->maxBP += 3;
                    if (playerData->maxBP > 30) {
                        playerData->maxBP = 30;
                    }
                    break;
            }

            set_animation(0, 0, ANIM_MarioB1_AdjustCap);

            if (partner != NULL) {
                script = start_script(partner->takeTurnSource, EVT_PRIORITY_A, 0);
                partner->takeTurnScript = script;
                partner->takeTurnScriptID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            if (!(gBattleStatus.flags2 & BS_FLAGS2_DONT_STOP_MUSIC)) {
                bgm_set_song(0, -1, 0, 2000, 8);
            }
            bFadeToBlackAmt = 0;
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT:
            if ((gGameStatusPtr->frameCounter % 2) != 0) {
                switch (battleStatus->curSubmenu) {
                    case 0:
                        hud_element_set_flags(LevelUpStatEmblemIDs[0], HUD_ELEMENT_FLAG_DISABLED);
                        break;
                    case 1:
                        hud_element_set_flags(LevelUpStatEmblemIDs[1], HUD_ELEMENT_FLAG_DISABLED);
                        hud_element_set_flags(LevelUpStatEmblemIDs[3], HUD_ELEMENT_FLAG_DISABLED);
                        break;
                    case 2:
                        hud_element_set_flags(LevelUpStatEmblemIDs[2], HUD_ELEMENT_FLAG_DISABLED);
                        break;
                }
            } else {
                switch (battleStatus->curSubmenu) {
                    case 0:
                        hud_element_clear_flags(LevelUpStatEmblemIDs[0], HUD_ELEMENT_FLAG_DISABLED);
                        break;
                    case 1:
                        hud_element_clear_flags(LevelUpStatEmblemIDs[1], HUD_ELEMENT_FLAG_DISABLED);
                        hud_element_clear_flags(LevelUpStatEmblemIDs[3], HUD_ELEMENT_FLAG_DISABLED);
                        break;
                    case 2:
                        hud_element_clear_flags(LevelUpStatEmblemIDs[2], HUD_ELEMENT_FLAG_DISABLED);
                        break;
                }
            }
            if (bFadeToBlackAmt == 255) {
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_DESTROY_HUD;
                break;
            }
            bFadeToBlackAmt += 10;
            if (bFadeToBlackAmt > 255) {
                bFadeToBlackAmt = 255;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_DESTROY_HUD:
            hud_element_free(LevelUpStatEmblemIDs[0]);
            hud_element_free(LevelUpStatEmblemIDs[1]);
            hud_element_free(LevelUpStatEmblemIDs[3]);
            hud_element_free(LevelUpStatEmblemIDs[2]);

            for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs); i++) {
                for (j = 0; j < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); j++) {
                    hud_element_free(LevelUpStatTextIDs[i][j]);
                }
            }

            hud_element_free(LevelUpSelectTextID);
            set_background_color_blend(0, 0, 0, 0);
            btl_set_state(BATTLE_STATE_END_BATTLE);
            gBattleSubState = BTL_SUBSTATE_END_BATTLE_EXEC_STAGE_SCRIPT;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID:
            width = get_msg_width(MSG_Menus_CantIncrease, 0) + 31;
            x = 160 - (width / 2);
            y = 80;
            set_window_properties(WINDOW_ID_BATTLE_POPUP, x, y, width, 28, WINDOW_PRIORITY_10, draw_content_cant_increase_popup, NULL, -1);
            set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            CelebrateSubstateTime = 60;
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                CelebrateSubstateTime = 0;
            }
            if (CelebrateSubstateTime != 0) {
                CelebrateSubstateTime--;
                break;
            }
            set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_HIDE);
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE;
            break;
        case BTL_SUBSTATE_CELEBRATE_SKIPPABLE_END_DELAY:
            if (battleStatus->curButtonsPressed & (BUTTON_A | BUTTON_B)) {
                CelebrateStateTime = 99;
            }
            if (CelebrateStateTime >= 99) {
                if (!(gBattleStatus.flags2 & BS_FLAGS2_DONT_STOP_MUSIC)) {
                    bgm_set_song(0, -1, 0, 1500, 8);
                }
                bFadeToBlackAmt = 0;
                btl_cam_set_params(1, 270, 100, 8, 0, 0x2400, 0, 100);
                set_animation(0, 0, ANIM_MarioB1_AdjustCap);
                if (partner != NULL) {
                    set_animation(ACTOR_PARTNER, 0, D_80284154[playerData->curPartner]);
                }
                CelebrateSubstateTime = 6;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_WALK_AWAY;
                break;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_WALK_AWAY:
            if (CelebrateSubstateTime != 0) {
                CelebrateSubstateTime--;
                if (CelebrateSubstateTime == 0) {
                    set_animation(0, 0, ANIM_Mario1_Walk);
                }
            } else {
                player->yaw = 0.0f;
                if (partner != NULL) {
                    partner->yaw = 0.0f;
                }

                player->curPos.x += 4.0f;
                if (partner != NULL) {
                    partner->curPos.x += 4.0f;
                }
            }
            if (bFadeToBlackAmt == 255) {
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_DONE;
                break;
            }
            bFadeToBlackAmt += 20;
            if (bFadeToBlackAmt > 255) {
                bFadeToBlackAmt = 255;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_DONE:
            if (does_script_exist(player->takeTurnScriptID)) {
                kill_script_by_ID(player->takeTurnScriptID);
            }
            if (partner != NULL && does_script_exist(partner->takeTurnScriptID)) {
                kill_script_by_ID(partner->takeTurnScriptID);
            }
            btl_set_state(BATTLE_STATE_END_BATTLE);
            gBattleSubState = BTL_SUBSTATE_END_BATTLE_EXEC_STAGE_SCRIPT;
            break;
    }
    CelebrateStateTime++;
}

void btl_draw_upgrade_windows(s32 phase) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x;
    s32 y;
    s32 d1;
    s32 d2;
    s32 d3;

    switch (phase) {
        case 0: // before choice
            d1 = 100;
            d2 = 100;
            d3 = 100;
            break;
        case 1: // choosing
            switch (battleStatus->curSubmenu) {
                case MENU_HP:
                    d1 = 0;
                    d2 = 100;
                    d3 = 100;
                    break;
                case MENU_FP:
                    d1 = 100;
                    d2 = 0;
                    d3 = 100;
                    break;
                default:
                    d1 = 100;
                    d2 = 100;
                    d3 = 0;
                    break;
            }
            break;
        default: // after choice
            d1 = 100;
            d2 = 100;
            d3 = 100;
            break;
    }

    hud_element_get_render_pos(LevelUpStatEmblemIDs[0], &x, &y);
    draw_box(0, WINDOW_STYLE_15, x - 22, y - 22, 0, 44, 44, 255, d1, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    hud_element_get_render_pos(LevelUpStatEmblemIDs[3], &x, &y);
    draw_box(0, WINDOW_STYLE_15, x - 22, y - 22, 0, 44, 44, 255, d2, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    hud_element_get_render_pos(LevelUpStatEmblemIDs[2], &x, &y);
    draw_box(0, WINDOW_STYLE_15, x - 22, y - 22, 0, 44, 44, 255, d3, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
}

void btl_state_draw_celebration(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 rotZ;
    s32 id;
    s32 i;
    s32 j;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD:
            btl_draw_upgrade_windows(0);
            id = LevelUpStatEmblemIDs[0];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);
            id = LevelUpStatEmblemIDs[3];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);
            id = LevelUpStatEmblemIDs[1];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);
            id = LevelUpStatEmblemIDs[2];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);

            for (j = 0; j < ARRAY_COUNT(LevelUpStatTextIDs); j++) {
                for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                    id = LevelUpStatTextIDs[j][i];

                    hud_element_set_tint(id, 128, 128, 128);
                    hud_element_draw_clipped(id);
                }
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY:
            switch (battleStatus->curSubmenu) {
                case 0:
                    rotZ = 152;
                    hud_element_set_tint(LevelUpStatEmblemIDs[0], 255, 255, 255);
                    hud_element_set_tint(LevelUpStatEmblemIDs[3], 128, 128, 128);
                    hud_element_set_tint(LevelUpStatEmblemIDs[1], 128, 128, 128);
                    hud_element_set_tint(LevelUpStatEmblemIDs[2], 128, 128, 128);

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_FP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_HP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_HP][i];

                        hud_element_set_tint(id, 255, 255, 255);
                    }

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_BP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_BP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    id = LevelUpStatEmblemIDs[0];
                    if (hud_element_get_script(id) != &HES_level_up_heart_copy) {
                        hud_element_set_script(id, &HES_level_up_heart_copy);
                    }
                    id = LevelUpStatEmblemIDs[3];
                    if (hud_element_get_script(id) != &HES_level_up_leaves) {
                        hud_element_set_script(id, &HES_level_up_leaves);
                    }
                    id = LevelUpStatEmblemIDs[1];
                    if (hud_element_get_script(id) != &HES_level_up_flower) {
                        hud_element_set_script(id, &HES_level_up_flower);
                    }
                    id = LevelUpStatEmblemIDs[2];
                    if (hud_element_get_script(id) != &HES_level_up_badge) {
                        hud_element_set_script(id, &HES_level_up_badge);
                    }
                    break;
                case 1:
                    rotZ = 180;
                    hud_element_set_tint(LevelUpStatEmblemIDs[0], 128, 128, 128);
                    hud_element_set_tint(LevelUpStatEmblemIDs[3], 255, 255, 255);
                    hud_element_set_tint(LevelUpStatEmblemIDs[1], 255, 255, 255);
                    hud_element_set_tint(LevelUpStatEmblemIDs[2], 128, 128, 128);

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_FP][i];

                        hud_element_set_tint(id, 255, 255, 255);
                    }

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_HP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_HP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_BP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_BP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }
                    break;
                case 2:
                default:
                    rotZ = 208;
                    hud_element_set_tint(LevelUpStatEmblemIDs[0], 128, 128, 128);
                    hud_element_set_tint(LevelUpStatEmblemIDs[3], 128, 128, 128);
                    hud_element_set_tint(LevelUpStatEmblemIDs[1], 128, 128, 128);
                    hud_element_set_tint(LevelUpStatEmblemIDs[2], 255, 255, 255);

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_FP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_HP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_HP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_BP]); i++) {
                        id = LevelUpStatTextIDs[LVL_UP_BP][i];

                        hud_element_set_tint(id, 255, 255, 255);
                    }
                    break;
            }

            btl_draw_upgrade_windows(1);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[0]);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[3]);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[1]);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[2]);

            for (j = 0; j < ARRAY_COUNT(LevelUpStatTextIDs); j++) {
                for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                    hud_element_draw_clipped(LevelUpStatTextIDs[j][i]);
                }
            }

            func_80144218(-1);
            id = LevelUpSpotlightID;
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, rotZ);
            func_80144238(id);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT:
            btl_draw_upgrade_windows(1);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[0]);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[3]);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[1]);
            hud_element_draw_clipped(LevelUpStatEmblemIDs[2]);

            for (j = 0; j < ARRAY_COUNT(LevelUpStatTextIDs); j++) {
                for (i = 0; i < ARRAY_COUNT(LevelUpStatTextIDs[LVL_UP_FP]); i++) {
                    hud_element_draw_clipped(LevelUpStatTextIDs[j][i]);
                }
            }

            set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, bFadeToBlackAmt);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_DESTROY_HUD:
            set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, bFadeToBlackAmt);
            break;
        case BTL_SUBSTATE_CELEBRATE_WALK_AWAY:
            if (bFadeToBlackAmt != 0) {
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, bFadeToBlackAmt);
            }
            break;
    }

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE:
            LevelUpSelectTextVelX += 2;
            LevelUpSelectTextOffsetX += LevelUpSelectTextVelX;
            if (LevelUpSelectTextOffsetX > 200) {
                LevelUpSelectTextOffsetX = 200;
                LevelUpSelectTextVelX = -LevelUpSelectTextVelX / 3; // rebounding
            }
            id = LevelUpSelectTextID;
            hud_element_set_render_pos(id, LevelUpSelectTextOffsetX - 43, 176);
            hud_element_draw_clipped(id);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT:
            LevelUpSelectTextVelX += 4;
            LevelUpSelectTextOffsetX += LevelUpSelectTextVelX;
            if (LevelUpSelectTextOffsetX > 500) {
                LevelUpSelectTextOffsetX = 500;
            }
            id = LevelUpSelectTextID;
            hud_element_set_render_pos(id, LevelUpSelectTextOffsetX - 43, 176);
            hud_element_draw_clipped(id);
            break;
    }
}

void draw_content_level_up_textbox(void* data, s32 posX, s32 posY) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 xOffset;
    s32 msgID;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY:
            switch (battleStatus->curSubmenu) {
                case MENU_HP:
                    if (!CantLevelUpStat[MENU_HP]) {
                        msgID = MSG_Menus_LevelUp_HP;
                    } else {
                        msgID = MSG_Menus_LevelUp_MaxedHP;
                    }
                    xOffset = 9;
                    break;
                case MENU_FP:
                    if (!CantLevelUpStat[MENU_FP]) {
                        msgID = MSG_Menus_LevelUp_FP;
                    } else {
                        msgID = MSG_Menus_LevelUp_MaxedFP;
                    }
                    xOffset = 9;
                    break;
                default:
                    if (!CantLevelUpStat[MENU_BP]) {
                        msgID = MSG_Menus_LevelUp_BP;
                    } else {
                        msgID = MSG_Menus_LevelUp_MaxedBP;
                    }
                    xOffset = 9;
                    break;
            }
            draw_msg(msgID, posX + xOffset + 17, posY, 255, MSG_PAL_STANDARD, 0);
            break;
    }
}

void draw_content_cant_increase_popup(void* data, s32 posX, s32 posY) {
    draw_msg(MSG_Menus_CantIncrease, posX + 11, posY + 6, 255, MSG_PAL_0F, 0);
}
