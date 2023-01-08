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

extern HudScript HES_ProjectorBeam;
extern IconHudScriptPair gItemHudScripts[];

enum {
    LVL_UP_FP  = 0,
    LVL_UP_HP  = 1,
    LVL_UP_BP  = 2,
};

enum {
    LVL_UP_TITLE        = 0,
    LVL_UP_CUR_TENS     = 1,
    LVL_UP_CUR_ONES     = 2,
    LVL_UP_ARROW        = 3,
    LVL_UP_NEXT_TENS    = 4,
    LVL_UP_NEXT_ONES    = 5,
    LVL_UP_BONUS        = 6,
};

BSS s32 D_8029FA80[4];
BSS s32 D_8029FA90[3][7];
BSS s32 D_8029FAE4; // unused?
BSS s32 D_8029FAE8;
BSS s32 D_8029FAEC[23]; // unused?

BSS s32 D_8029FB48;
BSS s32 CelebrateStateTimer;
BSS s32 D_8029FB50;
BSS s32 D_8029FB54;
BSS s32 D_8029FB58[2]; // unused?
BSS s32 CantLevelUpStat[3];
BSS s32 D_8029FB6C;
BSS s32 D_8029FB70;
BSS s32 pendingLevelUps;
BSS s32 D_8029FB78;
BSS Evt* LevelUpScriptPtr;
BSS s32 LevelUpScriptID;
BSS s32 bCelebrateStateTime;
BSS s32 D_8029FB88;
BSS s32 D_8029FB8C;

extern EntityModelScript starpoint_model_script_starpoint;
extern EntityModelScript starpoint_model_script_starpoints;
extern EntityModelScript starpoint_model_script_digit_0;
extern EntityModelScript starpoint_model_script_digit_1;
extern EntityModelScript starpoint_model_script_digit_2;
extern EntityModelScript starpoint_model_script_digit_3;
extern EntityModelScript starpoint_model_script_digit_4;
extern EntityModelScript starpoint_model_script_digit_5;
extern EntityModelScript starpoint_model_script_digit_6;
extern EntityModelScript starpoint_model_script_digit_7;
extern EntityModelScript starpoint_model_script_digit_8;
extern EntityModelScript starpoint_model_script_digit_9;
extern EntityModelScript starpoint_model_script_dummy;

extern EntityModelScript level_up_model_script;

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
    &starpoint_model_script_digit_0,
    &starpoint_model_script_digit_1,
    &starpoint_model_script_digit_2,
    &starpoint_model_script_digit_3,
    &starpoint_model_script_digit_4,
    &starpoint_model_script_digit_5,
    &starpoint_model_script_digit_6,
    &starpoint_model_script_digit_7,
    &starpoint_model_script_digit_8,
    &starpoint_model_script_digit_9,
};

EntityModelScript* starpoint_space_script = &starpoint_model_script_dummy;

HudScript* levelup_stat_scripts[3] = {
    &HES_level_up_FP,
    &HES_level_up_HP,
    &HES_level_up_BP,
};

HudScript* level_up_digit_scripts[3][10] = {
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

void func_80260948(void* data, s32 posX, s32 posY);
void func_80260A20(void* data, s32 posX, s32 posY);

ApiStatus func_8025DEB0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s8)gBattleStatus.totalStarPoints;
    return ApiStatus_DONE2;
}

s32 func_8025DEC4(Evt* script, s32 isInitialCall) {
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

ApiStatus func_8025E030(Evt* script, s32 isInitialCall) {
    return D_8029FB78 != 0 ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus func_8025E044(Evt* script, s32 isInitialCall) {
    EntityModel* model;

    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[6]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[7]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[8]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E108(Evt* script, s32 isInitialCall) {
    EntityModel* model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~(MODEL_FLAGS_USES_CUSTOM_GFX | MODEL_FLAGS_FLAG_20 | MODEL_FLAGS_FLAG_40
        | MODEL_FLAGS_HAS_LOCAL_VERTEX_COPY | MODEL_FLAGS_USE_CAMERA_UNK_MATRIX | MODEL_FLAGS_FLAG_200
        | MODEL_FLAGS_HAS_TRANSFORM_APPLIED | MODEL_FLAGS_HAS_TEX_PANNER | MODEL_FLAGS_USES_TRANSFORM_MATRIX
        | MODEL_FLAGS_FLAG_2000 | MODEL_FLAGS_FLAG_4000 | MODEL_FLAGS_FLAG_8000);
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E14C(Evt* script, s32 isInitialCall) {
    fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 120);
    return ApiStatus_DONE2;
}

EvtScript EVS_ShowStarpoints = {
    EVT_SET(LVarF, 0)
    EVT_CALL(func_8025DEB0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(LVar0, 2)
        EVT_CALL(CreateVirtualEntity, LVar6, EVT_PTR(starpoint_model_script_starpoint))
        EVT_CALL(SetVirtualEntityPosition, LVar6, -278, 68, 70)
        EVT_CALL(SetVirtualEntityScale, LVar6, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_ELSE
        EVT_CALL(CreateVirtualEntity, LVar6, EVT_PTR(starpoint_model_script_starpoints))
        EVT_CALL(SetVirtualEntityPosition, LVar6, -278, 68, 70)
        EVT_CALL(SetVirtualEntityScale, LVar6, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_SET(LVarF, 3)
        EVT_CASE_GT(9)
            EVT_SET(LVarF, 2)
        EVT_CASE_DEFAULT
            EVT_SET(LVarF, 1)
    EVT_END_SWITCH
    EVT_CALL(func_8025DEC4)
    EVT_CALL(CreateVirtualEntity, LVar7, LVarA)
    EVT_CALL(SetVirtualEntityPosition, LVar7, -353, 68, 70)
    EVT_CALL(SetVirtualEntityScale, LVar7, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(CreateVirtualEntity, LVar8, LVarB)
    EVT_CALL(SetVirtualEntityPosition, LVar8, -338, 68, 70)
    EVT_CALL(SetVirtualEntityScale, LVar8, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(CreateVirtualEntity, LVar9, LVarC)
    EVT_CALL(SetVirtualEntityPosition, LVar9, -323, 68, 70)
    EVT_CALL(SetVirtualEntityScale, LVar9, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(func_8025E044)
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
    EVT_CALL(func_8025E030)
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
    EVT_CALL(CreateVirtualEntity, LVar9, EVT_PTR(level_up_model_script))
    EVT_CALL(SetVirtualEntityPosition, LVar9, 0, 210, 70)
    EVT_CALL(func_8025E108)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_CALL(func_8025E14C)
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
    s32 x;
    s32 y;
    s32 z;
    s32 width;

    Evt* takeTurnScript;
    Evt* script;

    s32 temp_v1_4;
    s32 temp_v1_5;

    s32 fpTens;
    s32 fpOnes;

    s32 leftoverSP;
    s32 resultSP;

    s32 i;
    s32 j;

    HudScript* new_var;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_INIT:
            if (battleStatus->pendingStarPoints <= 0) {
                player->flags &= ~ACTOR_FLAG_8000000;
                D_8029FB6C = battleStatus->totalStarPoints * 100;
                pendingLevelUps = 0;
                D_8029FB50 = 0;
                bFadeToBlackAmt = 0;
                D_8029FB88 = 0;
                D_8029FB8C = 0;
                sfx_play_sound(SOUND_D4);

                resultSP = playerData->starPoints + battleStatus->totalStarPoints;
                if (resultSP > 99) {
                    bgm_set_song(0, SONG_LEVEL_UP, 0, 250, 8);
                } else {
                    bgm_set_song(0, SONG_BATTLE_END, 0, 250, 8);
                }

                bCelebrateStateTime = 0;
                btl_cam_use_preset(BTL_CAM_PRESET_23);
                D_8029FB54 = 0;
                CelebrateStateTimer = 1;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LOAD_STAR_POINTS;
                gBattleStatus.flags2 |= BS_FLAGS2_1;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LOAD_STAR_POINTS:
            if (CelebrateStateTimer != 0) {
                CelebrateStateTimer--;
            } else if (btl_cam_is_moving_done()) {
                dma_copy(starpoint_ROM_START, starpoint_ROM_END, starpoint_VRAM);
                script = start_script(&EVS_ShowStarpoints, EVT_PRIORITY_A, 0);
                D_8029FB78 = 0;
                D_8029FB54 = 20;
                D_8029FB70 = D_8029FB6C / D_8029FB54;
                player->takeTurnScript = script;
                CelebrateStateTimer = 1;
                player->takeTurnID = script->id;
                script->owner1.enemyID = 0;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_TALLY_STAR_POINTS;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_TALLY_STAR_POINTS:
            if (CelebrateStateTimer == 0) {
                if (battleStatus->totalStarPoints != 0) {
                    D_8029FB6C -= D_8029FB70;
                    resultSP = battleStatus->totalStarPoints;
                    battleStatus->totalStarPoints = D_8029FB6C / 100;
                    leftoverSP = resultSP - battleStatus->totalStarPoints;
                    if (leftoverSP > 0) {
                        sfx_play_sound(SOUND_215);
                    }

                    playerData->starPoints += leftoverSP;
                    bFadeToBlackAmt++;
                    if (D_8029FB54 == 0 && battleStatus->totalStarPoints != 0) {
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
                    if (D_8029FB54 == 0) {
                        D_8029FB78 = 1;
                        player->flags &= ~(ACTOR_FLAG_4000000 | ACTOR_FLAG_8000000);
                        if (partner != NULL) {
                            partner->flags &= ~(ACTOR_FLAG_4000000 | ACTOR_FLAG_8000000);
                        }
                        battleStatus->battlePhase = PHASE_CELEBRATE;
                        script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
                        player->takeTurnScript = script;
                        player->takeTurnID = script->id;
                        script->owner1.actorID = ACTOR_PLAYER;
                        if (partner != NULL) {
                            script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
                            partner->takeTurnScript = script;
                            partner->takeTurnID = script->id;
                            script->owner1.actorID = ACTOR_PARTNER;
                        }
                        CelebrateStateTimer = 40;
                        gBattleSubState = BTL_SUBSTATE_CELEBRATE_POST_STAR_POINTS;
                    } else {
                        D_8029FB54--;
                    }
                }
            } else {
                CelebrateStateTimer--;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_POST_STAR_POINTS:
            if (CelebrateStateTimer == 0) {
                if (pendingLevelUps == 0) {
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_SKIPPABLE_END_DELAY;
                } else {
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_LOAD;
                }
                break;
            }
            CelebrateStateTimer--;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_LOAD:
            if (bCelebrateStateTime >= 99) {
                playerData->level++;
                btl_cam_use_preset(BTL_CAM_PRESET_C);
                btl_cam_move(5);
                dma_copy(level_up_ROM_START, level_up_ROM_END, level_up_VRAM);
                sfx_play_sound(SOUND_80000008);
                bCelebrateStateTime = 0;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_BEGIN;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_BEGIN:
            LevelUpScriptPtr = start_script(&EVS_ShowLevelUp, EVT_PRIORITY_A, 0);
            LevelUpScriptID = LevelUpScriptPtr->id;
            CelebrateStateTimer = 25;
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CREATE_HUD;
            mdl_set_all_fog_mode(1);
            *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_1;
            set_background_color_blend(0, 0, 0, 0);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CREATE_HUD:
            if (CelebrateStateTimer == 18) {
                playerData->curHP = playerData->curMaxHP;
                playerData->curFP = playerData->curMaxFP;
                x = player->currentPos.x + 0.0f;
                y = player->currentPos.y + 35.0f;
                z = player->currentPos.z;
                fx_recover(0, x, y, z, playerData->curHP);
                x = player->currentPos.x + 20.0f;
                y = player->currentPos.y + 25.0f;
                z = player->currentPos.z;
                fx_recover(1, x, y, z, playerData->curFP);
                playerData->specialBarsFilled = playerData->maxStarPower * 256;
            }

            if (CelebrateStateTimer != 0) {
                CelebrateStateTimer--;
                if (CelebrateStateTimer < 10) {
                    set_background_color_blend(0, 0, 0, ((10 - CelebrateStateTimer) * 16) & 0xF0);
                }
            } else {
                id = hud_element_create(&HES_level_up_heart);
                D_8029FA80[0] = id;
                hud_element_set_render_pos(id, 310, 140);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                id = hud_element_create(&HES_level_up_flower);
                D_8029FA80[1] = id;
                hud_element_set_render_pos(id, 158, 340);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                id = hud_element_create(&HES_level_up_leaves);
                D_8029FA80[3] = id;
                hud_element_set_render_pos(id, 158, 340);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                id = hud_element_create(&HES_level_up_badge);
                D_8029FA80[2] = id;
                hud_element_set_render_pos(id, 6, 140);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                id = hud_element_create(levelup_stat_scripts[0]);
                D_8029FA90[LVL_UP_FP][LVL_UP_TITLE] = id;
                hud_element_set_render_pos(id, 160, 317);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                for (i = 1; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                    id = hud_element_create(level_up_digit_scripts[0][0]);
                    D_8029FA90[LVL_UP_FP][i] = id;
                    hud_element_set_render_pos(id, 160, 317);
                    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
                }

                id = hud_element_create(levelup_stat_scripts[1]);
                D_8029FA90[LVL_UP_HP][LVL_UP_TITLE] = id;
                hud_element_set_render_pos(id, 312, 117);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                for (i = 1; i < ARRAY_COUNT(D_8029FA90[LVL_UP_HP]); i++) {
                    id = hud_element_create(level_up_digit_scripts[1][0]);
                    D_8029FA90[LVL_UP_HP][i] = id;
                    hud_element_set_render_pos(id, 312, 117);
                    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
                }

                id = hud_element_create(levelup_stat_scripts[2]);
                D_8029FA90[LVL_UP_BP][LVL_UP_TITLE] = id;
                hud_element_set_render_pos(id, 8, 117);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);

                for (i = 1; i < ARRAY_COUNT(D_8029FA90[LVL_UP_BP]); i++) {
                    id = hud_element_create(level_up_digit_scripts[2][0]);
                    D_8029FA90[LVL_UP_BP][i] = id;
                    hud_element_set_render_pos(id, 8, 117);
                    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
                }

                CantLevelUpStat[0] = FALSE;
                CantLevelUpStat[1] = FALSE;
                CantLevelUpStat[2] = FALSE;

                if (playerData->hardMaxFP != 50) {
                    // current FP
                    fpTens = playerData->curMaxFP / 10;
                    fpOnes = playerData->curMaxFP % 10;
                    id = D_8029FA90[LVL_UP_FP][LVL_UP_CUR_TENS];
                    hud_element_set_script(id, level_up_small_digit_scripts[0][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 14, y + 46);

                    id = D_8029FA90[LVL_UP_FP][LVL_UP_CUR_ONES];
                    hud_element_set_script(id, level_up_small_digit_scripts[0][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 8, y + 46);

                    id = D_8029FA90[LVL_UP_FP][LVL_UP_ARROW];
                    hud_element_set_script(id, &HES_level_up_small_green_arrow);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 3, y + 46);

                    // upgraded FP
                    fpTens = (playerData->curMaxFP + 5) / 10;
                    fpOnes = (playerData->curMaxFP + 5) % 10;
                    id = D_8029FA90[LVL_UP_FP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, level_up_digit_scripts[0][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 3, y + 46);

                    id = D_8029FA90[LVL_UP_FP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, level_up_digit_scripts[0][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 10, y + 46);
                } else {
                    // upgraded FP only
                    id = D_8029FA90[LVL_UP_FP][LVL_UP_NEXT_TENS];
                    fpTens = playerData->curMaxFP / 10;
                    fpOnes = playerData->curMaxFP % 10;
                    hud_element_set_script(id, level_up_digit_scripts[0][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 6, y + 46);

                    id = D_8029FA90[LVL_UP_FP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, level_up_digit_scripts[0][fpOnes]);
                    hud_element_clear_flags(id, 2);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 2, y + 46);
                    CantLevelUpStat[1] = TRUE;
                }

                if (is_ability_active(ABILITY_FP_PLUS)) {
                    id = D_8029FA90[LVL_UP_FP][LVL_UP_BONUS];
                    hud_element_set_script(id, gItemHudScripts[gItemTable[ITEM_FP_PLUS_A].hudElemID].enabled);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_set_scale(id, 0.5f);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 17, y + 46);
                }

                if (playerData->hardMaxHP != 50) {
                    // current HP
                    fpTens = playerData->curMaxHP / 10;
                    fpOnes = playerData->curMaxHP % 10;

                    id = D_8029FA90[LVL_UP_HP][1];
                    hud_element_set_script(id, level_up_small_digit_scripts[1][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 14, y + 46);

                    id = D_8029FA90[LVL_UP_HP][2];
                    hud_element_set_script(id, level_up_small_digit_scripts[1][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 8, y + 46);

                    id = D_8029FA90[LVL_UP_HP][LVL_UP_ARROW];
                    hud_element_set_script(id, &HES_level_up_small_red_arrow);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 3, y + 46);

                    fpTens = (playerData->curMaxHP + 5) / 10;
                    fpOnes = (playerData->curMaxHP + 5) % 10;

                    id = D_8029FA90[LVL_UP_HP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, level_up_digit_scripts[1][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 3, y + 46);

                    id = D_8029FA90[LVL_UP_HP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, level_up_digit_scripts[1][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 10, y + 46);
                } else {
                    fpTens = playerData->curMaxHP / 10;
                    fpOnes = playerData->curMaxHP % 10;

                    id = D_8029FA90[LVL_UP_HP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, level_up_digit_scripts[1][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 6, y + 46);

                    id = D_8029FA90[LVL_UP_HP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, level_up_digit_scripts[1][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 2, y + 46);
                    CantLevelUpStat[0] = TRUE;
                }

                if (is_ability_active(ABILITY_HP_PLUS)) {
                    id = D_8029FA90[LVL_UP_HP][LVL_UP_BONUS];
                    hud_element_set_script(id, gItemHudScripts[gItemTable[ITEM_HP_PLUS_A].hudElemID].enabled);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_set_scale(id, 0.5f);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 17, y + 46);
                }

                if (playerData->maxBP != 30) {
                    fpTens = playerData->maxBP / 10;
                    fpOnes = playerData->maxBP % 10;

                    id = D_8029FA90[LVL_UP_BP][1];
                    hud_element_set_script(id, level_up_small_digit_scripts[2][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 14, y + 46);

                    id = D_8029FA90[LVL_UP_BP][2];
                    hud_element_set_script(id, level_up_small_digit_scripts[2][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 8, y + 46);

                    id = D_8029FA90[LVL_UP_BP][LVL_UP_ARROW];
                    hud_element_set_script(id, &HES_level_up_small_blue_arrow);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 3, y + 46);

                    fpTens = (playerData->maxBP + 3) / 10;
                    fpOnes = (playerData->maxBP + 3) % 10;

                    id = D_8029FA90[LVL_UP_BP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, level_up_digit_scripts[2][fpTens]);
                    if (fpTens != 0) {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 3, y + 46);

                    id = D_8029FA90[LVL_UP_BP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, level_up_digit_scripts[2][fpOnes]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 10, y + 46);
                } else {
                    id = D_8029FA90[LVL_UP_BP][LVL_UP_NEXT_TENS];
                    hud_element_set_script(id, level_up_digit_scripts[2][3]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x - 6, y + 46);

                    id = D_8029FA90[LVL_UP_BP][LVL_UP_NEXT_ONES];
                    hud_element_set_script(id, level_up_digit_scripts[2][0]);
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    hud_element_get_render_pos(id, &x, &y);
                    hud_element_set_render_pos(id, x + 2, y + 46);
                    CantLevelUpStat[2] = TRUE;
                }

                id = D_8029FAE8 = hud_element_create(&HES_ProjectorBeam);
                hud_element_create_transform_B(id);
                hud_element_set_render_pos(id, 156, 13);
                hud_element_set_tint(id, 255, 255, 255);
                hud_element_set_transform_rotation_pivot(id, 0, -35);
                hud_element_set_transform_rotation(id, 0.0f, 0.0f, 180.0f);
                hud_element_set_transform_scale(id, 1.0f, 1.5f, 1.0f);
                hud_element_set_alpha(id, 200);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX | HUD_ELEMENT_FLAGS_80);

                id = D_8029FB48 = hud_element_create(&HES_level_up_select_one_to_upgrade);
                hud_element_set_render_pos(id, 0, 0);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
                battleStatus->currentSubmenu = 1;

                CelebrateStateTimer = 10;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD:
            id = D_8029FA80[0];
            hud_element_get_render_pos(id, &x, &y);
            x -= 20;
            hud_element_set_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_HP]); i++) {
                id = D_8029FA90[LVL_UP_HP][i];
                hud_element_get_render_pos(id, &x, &y);
                x -= 20;
                hud_element_set_render_pos(id, x, y);
            }

            id = D_8029FA80[1];
            hud_element_get_render_pos(id, &x, &y);
            y -= 20;
            hud_element_set_render_pos(id, x, y);

            id = D_8029FA80[3];
            hud_element_get_render_pos(id, &x, &y);
            y -= 20;
            hud_element_set_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                id = D_8029FA90[LVL_UP_FP][i];
                hud_element_get_render_pos(id, &x, &y);
                y -= 20;
                hud_element_set_render_pos(id, x, y);
            }

            id = D_8029FA80[2];
            hud_element_get_render_pos(id, &x, &y);
            x += 20;
            hud_element_set_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_BP]); i++) {
                id = D_8029FA90[LVL_UP_BP][i];
                hud_element_get_render_pos(id, &x, &y);
                x += 20;
                hud_element_set_render_pos(id, x, y);
            }

            CelebrateStateTimer--;
            if (CelebrateStateTimer == 0) {
                hud_element_set_tint(id, 128, 128, 128);
                x = 20;
                y = 186;
                set_window_properties(WINDOW_ID_8, 20, 186, 280, 32, 20, func_80260948, NULL, -1);
                set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                if (!CantLevelUpStat[battleStatus->currentSubmenu]) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    sfx_play_sound(SOUND_749);
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE;
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID;
                }
                break;
            }

            newSubmenu = currentSubmenu = battleStatus->currentSubmenu;
            if (battleStatus->currentButtonsHeld & BUTTON_STICK_LEFT) {
                newSubmenu--;
            }
            if (battleStatus->currentButtonsHeld & BUTTON_STICK_RIGHT) {
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
                battleStatus->currentSubmenu = newSubmenu;
            }

            bCelebrateStateTime++;
            if (bCelebrateStateTime > 100) {
                fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 120);
                bCelebrateStateTime = 0;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE:
            hud_element_free(D_8029FAE8);
            set_window_update(WINDOW_ID_8, WINDOW_UPDATE_HIDE);

            switch (battleStatus->currentSubmenu) {
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
                    player->currentHP = playerData->curHP;
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

            set_animation(0, 0, ANIM_Mario_30009);

            if (partner != NULL) {
                script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
                partner->takeTurnScript = script;
                partner->takeTurnID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
                bgm_set_song(0, -1, 0, 2000, 8);
            }
            bFadeToBlackAmt = 0;
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT:
            if ((gGameStatusPtr->frameCounter % 2) != 0) {
                switch (battleStatus->currentSubmenu) {
                    case 0:
                        hud_element_set_flags(D_8029FA80[0], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 1:
                        hud_element_set_flags(D_8029FA80[1], HUD_ELEMENT_FLAGS_DISABLED);
                        hud_element_set_flags(D_8029FA80[3], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 2:
                        hud_element_set_flags(D_8029FA80[2], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                }
            } else {
                switch (battleStatus->currentSubmenu) {
                    case 0:
                        hud_element_clear_flags(D_8029FA80[0], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 1:
                        hud_element_clear_flags(D_8029FA80[1], HUD_ELEMENT_FLAGS_DISABLED);
                        hud_element_clear_flags(D_8029FA80[3], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 2:
                        hud_element_clear_flags(D_8029FA80[2], HUD_ELEMENT_FLAGS_DISABLED);
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
            hud_element_free(D_8029FA80[0]);
            hud_element_free(D_8029FA80[1]);
            hud_element_free(D_8029FA80[3]);
            hud_element_free(D_8029FA80[2]);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90); i++) {
                for (j = 0; j < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); j++) {
                    hud_element_free(D_8029FA90[i][j]);
                }
            }

            hud_element_free(D_8029FB48);
            set_background_color_blend(0, 0, 0, 0);
            btl_set_state(BATTLE_STATE_END_BATTLE);
            gBattleSubState = BTL_END_BATTLE_SUBSTATE_INIT;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID:
            width = get_msg_width(MSG_Menus_CantIncrease, 0) + 31;
            x = 160 - (width / 2);
            y = 80;
            set_window_properties(WINDOW_ID_9, x, y, width, 28, 10, func_80260A20, NULL, -1);
            set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
            CelebrateStateTimer = 60;
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY;
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                CelebrateStateTimer = 0;
            }
            if (CelebrateStateTimer != 0) {
                CelebrateStateTimer--;
                break;
            }
            set_window_update(WINDOW_ID_9, WINDOW_UPDATE_HIDE);
            gBattleSubState = BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE;
            break;
        case BTL_SUBSTATE_CELEBRATE_SKIPPABLE_END_DELAY:
            if (battleStatus->currentButtonsPressed & (BUTTON_A | BUTTON_B)) {
                bCelebrateStateTime = 99;
            }
            if (bCelebrateStateTime >= 99) {
                if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
                    bgm_set_song(0, -1, 0, 1500, 8);
                }
                bFadeToBlackAmt = 0;
                btl_cam_set_params(1, 270, 100, 8, 0, 0x2400, 0, 100);
                set_animation(0, 0, ANIM_Mario_30009);
                if (partner != NULL) {
                    set_animation(ACTOR_PARTNER, 0, D_80284154[playerData->currentPartner]);
                }
                CelebrateStateTimer = 6;
                gBattleSubState = BTL_SUBSTATE_CELEBRATE_WALK_AWAY;
                break;
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_WALK_AWAY:
            if (CelebrateStateTimer != 0) {
                CelebrateStateTimer--;
                if (CelebrateStateTimer == 0) {
                    set_animation(0, 0, ANIM_Mario_Walking);
                }
            } else {
                player->yaw = 0.0f;
                if (partner != NULL) {
                    partner->yaw = 0.0f;
                }

                player->currentPos.x += 4.0f;
                if (partner != NULL) {
                    partner->currentPos.x += 4.0f;
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
            if (does_script_exist(player->takeTurnID)) {
                kill_script_by_ID(player->takeTurnID);
            }
            if (partner != NULL && does_script_exist(partner->takeTurnID)) {
                kill_script_by_ID(partner->takeTurnID);
            }
            btl_set_state(BATTLE_STATE_END_BATTLE);
            gBattleSubState = BTL_END_BATTLE_SUBSTATE_INIT;
            break;
    }
    bCelebrateStateTime++;
}

void btl_draw_upgrade_windows(s32 arg0) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x;
    s32 y;
    s32 d1;
    s32 d2;
    s32 d3;

    switch (arg0) {
        case 0:
            d1 = 100;
            d2 = 100;
            d3 = 100;
            break;
        case 1:
            switch (battleStatus->currentSubmenu) {
                case 0:
                    d1 = 0;
                    d2 = 100;
                    d3 = 100;
                    break;
                case 1:
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
        default:
            d1 = 100;
            d2 = 100;
            d3 = 100;
            break;
    }

    hud_element_get_render_pos(D_8029FA80[0], &x, &y);
    draw_box(0, WINDOW_STYLE_15, x - 22, y - 22, 0, 44, 44, 255, d1, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    hud_element_get_render_pos(D_8029FA80[3], &x, &y);
    draw_box(0, WINDOW_STYLE_15, x - 22, y - 22, 0, 44, 44, 255, d2, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    hud_element_get_render_pos(D_8029FA80[2], &x, &y);
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
            id = D_8029FA80[0];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);
            id = D_8029FA80[3];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);
            id = D_8029FA80[1];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);
            id = D_8029FA80[2];
            hud_element_set_tint(id, 128, 128, 128);
            hud_element_draw_clipped(id);

            for (j = 0; j < ARRAY_COUNT(D_8029FA90); j++) {
                for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                    id = D_8029FA90[j][i];

                    hud_element_set_tint(id, 128, 128, 128);
                    hud_element_draw_clipped(id);
                }
            }
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY:
            switch (battleStatus->currentSubmenu) {
                case 0:
                    rotZ = 152;
                    hud_element_set_tint(D_8029FA80[0], 255, 255, 255);
                    hud_element_set_tint(D_8029FA80[3], 128, 128, 128);
                    hud_element_set_tint(D_8029FA80[1], 128, 128, 128);
                    hud_element_set_tint(D_8029FA80[2], 128, 128, 128);

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                        id = D_8029FA90[LVL_UP_FP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_HP]); i++) {
                        id = D_8029FA90[LVL_UP_HP][i];

                        hud_element_set_tint(id, 255, 255, 255);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_BP]); i++) {
                        id = D_8029FA90[LVL_UP_BP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    id = D_8029FA80[0];
                    if (hud_element_get_script(id) != &HES_level_up_heart_copy) {
                        hud_element_set_script(id, &HES_level_up_heart_copy);
                    }
                    id = D_8029FA80[3];
                    if (hud_element_get_script(id) != &HES_level_up_leaves) {
                        hud_element_set_script(id, &HES_level_up_leaves);
                    }
                    id = D_8029FA80[1];
                    if (hud_element_get_script(id) != &HES_level_up_flower) {
                        hud_element_set_script(id, &HES_level_up_flower);
                    }
                    id = D_8029FA80[2];
                    if (hud_element_get_script(id) != &HES_level_up_badge) {
                        hud_element_set_script(id, &HES_level_up_badge);
                    }
                    break;
                case 1:
                    rotZ = 180;
                    hud_element_set_tint(D_8029FA80[0], 128, 128, 128);
                    hud_element_set_tint(D_8029FA80[3], 255, 255, 255);
                    hud_element_set_tint(D_8029FA80[1], 255, 255, 255);
                    hud_element_set_tint(D_8029FA80[2], 128, 128, 128);

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                        id = D_8029FA90[LVL_UP_FP][i];

                        hud_element_set_tint(id, 255, 255, 255);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_HP]); i++) {
                        id = D_8029FA90[LVL_UP_HP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_BP]); i++) {
                        id = D_8029FA90[LVL_UP_BP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }
                    break;
                case 2:
                default:
                    rotZ = 208;
                    hud_element_set_tint(D_8029FA80[0], 128, 128, 128);
                    hud_element_set_tint(D_8029FA80[3], 128, 128, 128);
                    hud_element_set_tint(D_8029FA80[1], 128, 128, 128);
                    hud_element_set_tint(D_8029FA80[2], 255, 255, 255);

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                        id = D_8029FA90[LVL_UP_FP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_HP]); i++) {
                        id = D_8029FA90[LVL_UP_HP][i];

                        hud_element_set_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_BP]); i++) {
                        id = D_8029FA90[LVL_UP_BP][i];

                        hud_element_set_tint(id, 255, 255, 255);
                    }
                    break;
            }

            btl_draw_upgrade_windows(1);
            hud_element_draw_clipped(D_8029FA80[0]);
            hud_element_draw_clipped(D_8029FA80[3]);
            hud_element_draw_clipped(D_8029FA80[1]);
            hud_element_draw_clipped(D_8029FA80[2]);

            for (j = 0; j < ARRAY_COUNT(D_8029FA90); j++) {
                for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                    hud_element_draw_clipped(D_8029FA90[j][i]);
                }
            }

            func_80144218(-1);
            id = D_8029FAE8;
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, rotZ);
            func_80144238(id);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT:
            btl_draw_upgrade_windows(1);
            hud_element_draw_clipped(D_8029FA80[0]);
            hud_element_draw_clipped(D_8029FA80[3]);
            hud_element_draw_clipped(D_8029FA80[1]);
            hud_element_draw_clipped(D_8029FA80[2]);

            for (j = 0; j < ARRAY_COUNT(D_8029FA90); j++) {
                for (i = 0; i < ARRAY_COUNT(D_8029FA90[LVL_UP_FP]); i++) {
                    hud_element_draw_clipped(D_8029FA90[j][i]);
                }
            }

            set_screen_overlay_params_front(0, bFadeToBlackAmt);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_DESTROY_HUD:
            set_screen_overlay_params_front(0, bFadeToBlackAmt);
            break;
        case BTL_SUBSTATE_CELEBRATE_WALK_AWAY:
            if (bFadeToBlackAmt != 0) {
                set_screen_overlay_params_front(0, bFadeToBlackAmt);
            }
            break;
    }

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE:
            D_8029FB8C += 2;
            D_8029FB88 += D_8029FB8C;
            if (D_8029FB88 > 200) {
                D_8029FB88 = 200;
                D_8029FB8C = -D_8029FB8C / 3;
            }
            id = D_8029FB48;
            hud_element_set_render_pos(id, D_8029FB88 - 43, 176);
            hud_element_draw_clipped(id);
            break;
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT:
            D_8029FB8C += 4;
            D_8029FB88 += D_8029FB8C;
            if (D_8029FB88 > 500) {
                D_8029FB88 = 500;
            }
            id = D_8029FB48;
            hud_element_set_render_pos(id, D_8029FB88 - 43, 176);
            hud_element_draw_clipped(id);
            break;
    }
}

void func_80260948(void* data, s32 posX, s32 posY) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 xOffset;
    s32 msgID;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID:
        case BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY:
            switch (battleStatus->currentSubmenu) {
                case 0:
                    if (!CantLevelUpStat[0]) {
                        msgID = MSG_Menus_LevelUp_HP;
                    } else {
                        msgID = MSG_Menus_LevelUp_MaxedHP;
                    }
                    xOffset = 9;
                    break;
                case 1:
                    if (!CantLevelUpStat[1]) {
                        msgID = MSG_Menus_LevelUp_FP;
                    } else {
                        msgID = MSG_Menus_LevelUp_MaxedFP;
                    }
                    xOffset = 9;
                    break;
                default:
                    if (!CantLevelUpStat[2]) {
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

void func_80260A20(void* data, s32 posX, s32 posY) {
    draw_msg(MSG_Menus_CantIncrease, posX + 11, posY + 6, 255, MSG_PAL_0F, 0);
}
