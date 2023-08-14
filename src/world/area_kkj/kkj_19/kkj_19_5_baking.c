#include "kkj_19.h"
#include "sprite/player.h"

#include "hud_element.h"
#include "battle/action_cmd.h"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

#define MIXING_TIME_IN_FRAMES   10 * 30 * DT
#define MIXING_REQUIRED_INPUTS  27

#define BAKING_TIME_MIN_FRAMES  23 * 30 * DT
#define BAKING_TIME_MAX_FRAMES  36 * 30 * DT

// similar to CAKE_TYPE with semantically distinct usage
enum {
    BAKE_STEP_ADD_SUGAR_AND_EGGS    = 1,
    BAKE_STEP_MIXING                = 2,
    BAKE_STEP_ADD_FLOUR_AND_BUTTER  = 3,
    BAKE_STEP_BAKING                = 4,
    BAKE_STEP_DECORATING            = 5,
    BAKE_STEP_DONE                  = 6,
};

BSS s32 N(MixingGameInputs);
BSS s32 N(MixingAnimState);
BSS s32 N(MixingGameUnused);
BSS s32 N(MixingGameTimeLeft);
BSS s32 N(MixingGameMashIntervals)[6];
BSS s32 N(MixingGameMashSegments);
BSS s32 N(MixingGameUIRenderer);
BSS u32 N(MixingGameState);
BSS s32 N(MixingGameUIBaseX);
BSS s32 N(MixingGameUIBaseY);
BSS s32 N(D_80246564); // unused? related to missing gauge hud element?
BSS s32 N(MixingGameHudElems)[4];
BSS s32 N(MixingGameInputBuffer)[10];
BSS s32 N(MixingGameInputBufferPos);

void N(worker_draw_mixing_game_ui)(void) {
    hud_element_draw_clipped(N(MixingGameHudElems)[0]);
}

enum MixingGameStates {
    MIXING_STATE_INIT       = 0,
    MIXING_STATE_APPEAR     = 1,
    MIXING_STATE_BEGIN      = 10,
    MIXING_STATE_MASHING    = 11,
    MIXING_STATE_END        = 12,
};

enum MixingAnimStates {
    MIXING_ANIM_INIT        = 0,
    MIXING_ANIM_IDLE        = 2,
    MIXING_ANIM_NEXT        = 3,
};

// basically the typical mash meter with the gauge removed
API_CALLABLE(N(RunMixingMinigame)) {
    Bytecode* args = script->ptrReadPos;
    s32 hudElemID;
    s32 maxMashAmount;
    s32 i;

    if (isInitialCall) {
        N(MixingGameState) = MIXING_STATE_INIT;
    }

    switch (N(MixingGameState)) {
        case MIXING_STATE_INIT:
            N(MixingGameTimeLeft) = evt_get_variable(script, *args++);
            N(MixingGameUIRenderer) = create_worker_frontUI(NULL, N(worker_draw_mixing_game_ui));
            N(MixingGameInputs) = 0;
            N(MixingGameUnused) = 0;
            for (i = 0; i < ARRAY_COUNT(N(MixingGameInputBuffer)); i++) {
                N(MixingGameInputBuffer)[i] = 0;
            }
            N(MixingGameInputBufferPos) = 0;
            N(MixingGameMashIntervals)[0] = 0;
            N(MixingGameMashIntervals)[1] = 12;
            N(MixingGameMashIntervals)[2] = 24;
            N(MixingGameMashIntervals)[3] = 36;
            N(MixingGameMashIntervals)[4] = 48;
            N(MixingGameMashIntervals)[5] = 60;
            N(MixingGameMashSegments) = 5;

            N(MixingGameUIBaseX) = -48;
            N(MixingGameUIBaseY) = 64;

            hudElemID = hud_element_create(&HES_AButton);
            N(MixingGameHudElems)[0] = hudElemID;
            hud_element_set_render_pos(hudElemID, N(MixingGameUIBaseX), N(MixingGameUIBaseY));
            hud_element_set_render_depth(hudElemID, 0);
            hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

            hudElemID = hud_element_create(&HES_BlueMeter);
            N(MixingGameHudElems)[1] = hudElemID;
            hud_element_set_render_pos(hudElemID, N(MixingGameUIBaseX), N(MixingGameUIBaseY) + 28);
            hud_element_set_render_depth(hudElemID, 0);
            hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

            hudElemID = N(MixingGameHudElems)[0];
            hud_element_set_alpha(hudElemID, 255);
            hud_element_clear_flags(hudElemID, HUD_ELEMENT_FLAG_DISABLED);

            hudElemID = N(MixingGameHudElems)[1];
            hud_element_set_alpha(hudElemID, 255);
            hud_element_clear_flags(hudElemID, HUD_ELEMENT_FLAG_DISABLED);

            N(MixingGameState) = MIXING_STATE_APPEAR;
            script->functionTemp[0] = 10;
            break;
        case MIXING_STATE_APPEAR:
            N(MixingGameUIBaseX) += 20;
            if (N(MixingGameUIBaseX) > 50) {
                N(MixingGameUIBaseX) = 50;
            }
            hud_element_set_render_pos(N(MixingGameHudElems)[0], N(MixingGameUIBaseX), N(MixingGameUIBaseY));
            hud_element_set_render_pos(N(MixingGameHudElems)[1], N(MixingGameUIBaseX), N(MixingGameUIBaseY) + 28);
            if (script->functionTemp[0] != 0) {
                script->functionTemp[0]--;
            } else {
                N(MixingGameState) = MIXING_STATE_BEGIN;
            }
            break;
        case MIXING_STATE_BEGIN:
            hud_element_set_script(N(MixingGameHudElems)[0], &HES_MashAButton);
            N(MixingGameInputs) = 0;
            N(MixingAnimState) = MIXING_ANIM_INIT;
            N(MixingGameState) = MIXING_STATE_MASHING;
            // fallthrough
        case MIXING_STATE_MASHING:
            maxMashAmount = N(MixingGameMashIntervals)[N(MixingGameMashSegments)];
            if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                N(MixingGameInputs)++;
            }
            if (N(MixingGameInputs) > maxMashAmount) {
                N(MixingGameInputs) = maxMashAmount;
            }
            if (N(MixingAnimState) == MIXING_ANIM_IDLE) {
                N(MixingAnimState) = MIXING_ANIM_NEXT;
            }
            for (i = 0; i < ARRAY_COUNT(N(MixingGameInputBuffer)); i++) {
                if (N(MixingGameInputBuffer)[i] != 0) {
                    break;
                }
            }
            if (i >= ARRAY_COUNT(N(MixingGameInputBuffer))) {
                N(MixingAnimState) = MIXING_ANIM_IDLE;
            } else if (N(MixingAnimState) != MIXING_ANIM_NEXT) {
                N(MixingAnimState) = MIXING_ANIM_IDLE;
            }
            N(MixingGameTimeLeft)--;
            if (N(MixingGameTimeLeft) == 0) {
                N(MixingGameTimeLeft) = 5;
                N(MixingGameState) = MIXING_STATE_END;
            }
            break;
        case MIXING_STATE_END:
            if (N(MixingGameTimeLeft) != 0) {
                N(MixingGameTimeLeft)--;
                break;
            }
            script->varTable[0] = N(MixingGameInputs);
            hud_element_free(N(MixingGameHudElems)[0]);
            hud_element_free(N(MixingGameHudElems)[1]);
            free_worker(N(MixingGameUIRenderer));
            return ApiStatus_DONE2;
    }

    N(MixingGameInputBuffer)[N(MixingGameInputBufferPos)++] = gGameStatusPtr->pressedButtons[0] & BUTTON_A;

    if (N(MixingGameInputBufferPos) >= ARRAY_COUNT(N(MixingGameInputBuffer))) {
        N(MixingGameInputBufferPos) = 0;
    }

    evt_set_variable(script, AB_KKJ19_BakeStepProgress, N(MixingAnimState));
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AwaitPlayerPressATimer)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[0] = script->functionTemp[1];
        return ApiStatus_DONE2;
    }

    script->functionTemp[1]++;
    return ApiStatus_BLOCK;
}

#if VERSION_PAL
typedef struct BakingIngredient {
    s32 itemID;
    s32 nameID;
} BakingIngredient;
struct BakingIngredient N(BakingIngredientsNames)[] = {
    {ITEM_BAKING_FLOUR,      MSG_Menus_BakingFlour},
    {ITEM_BAKING_SUGAR,      MSG_Menus_BakingSugar},
    {ITEM_BAKING_SALT,       MSG_Menus_BakingSalt},
    {ITEM_BAKING_EGG,        MSG_Menus_BakingEgg},
    {ITEM_BAKING_MILK,       MSG_Menus_BakingMilk},
    {ITEM_BAKING_STRAWBERRY, MSG_Menus_BakingStrawberry},
    {ITEM_BAKING_CREAM,      MSG_Menus_BakingCream},
    {ITEM_BAKING_BUTTER,     MSG_Menus_BakingButter},
    {ITEM_BAKING_CLEANSER,   MSG_Menus_BakingCleanser},
    {ITEM_BAKING_WATER,      MSG_Menus_BakingWater},
};
#endif

s32 N(BakingIngredientsList)[] = {
    ITEM_BAKING_SUGAR,
    ITEM_BAKING_SALT,
    ITEM_BAKING_EGG,
    ITEM_BAKING_STRAWBERRY,
    ITEM_BAKING_CREAM,
    ITEM_BAKING_BUTTER,
    ITEM_BAKING_CLEANSER,
    ITEM_BAKING_WATER,
    ITEM_BAKING_FLOUR,
    ITEM_BAKING_MILK,
};

// unlike the common import, does not mask out 0xF0000 from itemID
#if VERSION_PAL

API_CALLABLE(N(GetItemNameRaw)) {
    Bytecode* args = script->ptrReadPos;
    s32 inOutVar = *args++;
    s32 itemID = evt_get_variable(script, inOutVar);
    s32 i;

    for (i = 0; i < ARRAY_COUNT(N(BakingIngredientsNames)); i++) {
        if (itemID == N(BakingIngredientsNames)[i].itemID) {
            evt_set_variable(script, inOutVar, N(BakingIngredientsNames)[i].nameID);
            break;
        }
    }
    return ApiStatus_DONE2;
}
#else
API_CALLABLE(N(GetItemNameRaw)) {
    Bytecode* args = script->ptrReadPos;
    s32 inOutVar = *args++;
    s32 itemID = evt_get_variable(script, inOutVar);

    evt_set_variable(script, inOutVar, gItemTable[itemID].nameMsg);
    return ApiStatus_DONE2;
}
#endif

#include "world/common/todo/GetFloorCollider.inc.c"

API_CALLABLE(N(SetHeldBakingItem)) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.peachItemHeld = evt_get_variable(script, *args++);
    gGameStatusPtr->peachBakingIngredient = gPlayerStatus.peachItemHeld;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(FadeScreenToBlack)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 16;

    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(FadeScreenFromBlack)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_SetCookwareOnTable) = {
    EVT_SWITCH(AB_KKJ_CompletedBakeStep)
        EVT_CASE_EQ(CAKE_TYPE_NONE)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_BOWL, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
        EVT_CASE_EQ(CAKE_TYPE_BEGUN)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_BOWL, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
        EVT_CASE_EQ(CAKE_TYPE_READY_TO_MIX)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
        EVT_CASE_EQ(CAKE_TYPE_MIXED)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
        EVT_CASE_EQ(CAKE_TYPE_READY_TO_BAKE)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
        EVT_CASE_EQ(CAKE_TYPE_BAKED)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_BARE, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
            EVT_CALL(MakeItemEntity, ITEM_CAKE_BOWL, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdatePeachMixingAnimations) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Mixing1)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_SWITCH(AB_KKJ19_BakeStepProgress)
            EVT_CASE_EQ(MIXING_ANIM_IDLE)
                // increment the animation on next MIXING_ANIM_NEXT
                EVT_SET(LVar1, 0)
            EVT_CASE_EQ(MIXING_ANIM_NEXT)
                EVT_IF_EQ(LVar1, 0)
                    // increment the animation
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(0)
                            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Mixing1)
                            EVT_SET(LVar0, 1)
                        EVT_CASE_EQ(1)
                            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Mixing2)
                            EVT_SET(LVar0, 2)
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Mixing3)
                            EVT_SET(LVar0, 3)
                        EVT_CASE_EQ(3)
                            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Mixing4)
                            EVT_SET(LVar0, 0)
                    EVT_END_SWITCH
                    EVT_SET(LVar1, 1)
                EVT_ELSE
                    // wait until next MIXING_ANIM_NEXT to increment the animation
                    EVT_SET(LVar1, 0)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHeldIngredient) = {
    EVT_IF_NE(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
        EVT_CALL(FindKeyItem, AB_KKJ19_HeldIngredient, LVar0)
        EVT_CALL(RemoveKeyItemAt, LVar0)
        EVT_SET(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
        EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeIngredient) = {
    EVT_IF_EQ(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DONE)
        EVT_RETURN
    EVT_END_IF
    // get itemID of current station
    EVT_CALL(N(GetFloorCollider), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(COLLIDER_o101)
            EVT_SET(LVar0, ITEM_BAKING_SUGAR)
        EVT_CASE_EQ(COLLIDER_o102)
            EVT_SET(LVar0, ITEM_BAKING_SALT)
        EVT_CASE_EQ(COLLIDER_o103)
            EVT_SET(LVar0, ITEM_BAKING_EGG)
        EVT_CASE_EQ(COLLIDER_o105)
            EVT_SET(LVar0, ITEM_BAKING_STRAWBERRY)
        EVT_CASE_EQ(COLLIDER_o106)
            EVT_SET(LVar0, ITEM_BAKING_CREAM)
        EVT_CASE_EQ(COLLIDER_o107)
            EVT_SET(LVar0, ITEM_BAKING_BUTTER)
        EVT_CASE_EQ(COLLIDER_o108)
            EVT_SET(LVar0, ITEM_BAKING_CLEANSER)
        EVT_CASE_EQ(COLLIDER_o114)
            EVT_SET(LVar0, ITEM_BAKING_WATER)
        EVT_CASE_EQ(COLLIDER_o109)
            EVT_SET(LVar0, ITEM_BAKING_FLOUR)
        EVT_CASE_EQ(COLLIDER_o110)
            EVT_SET(LVar0, ITEM_BAKING_MILK)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(AF_KKJ19_CanTakeIngredients, FALSE)
    EVT_WAIT(5)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar0)
    EVT_IF_EQ(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
        // picking up an ingredient while not holding any
        EVT_CALL(N(GetItemNameRaw), LVarA)
        EVT_CALL(SetMessageText, LVarA, 0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(COLLIDER_o101)
                EVT_SET(LVar0, PEACH_BAKING_SUGAR)
            EVT_CASE_EQ(COLLIDER_o102)
                EVT_SET(LVar0, PEACH_BAKING_SALT)
            EVT_CASE_EQ(COLLIDER_o103)
                EVT_SET(LVar0, PEACH_BAKING_EGG)
            EVT_CASE_EQ(COLLIDER_o105)
                EVT_SET(LVar0, PEACH_BAKING_STRAWBERRY)
            EVT_CASE_EQ(COLLIDER_o106)
                EVT_SET(LVar0, PEACH_BAKING_CREAM)
            EVT_CASE_EQ(COLLIDER_o107)
                EVT_SET(LVar0, PEACH_BAKING_BUTTER)
            EVT_CASE_EQ(COLLIDER_o108)
                EVT_SET(LVar0, PEACH_BAKING_CLEANSER)
            EVT_CASE_EQ(COLLIDER_o114)
                EVT_SET(LVar0, PEACH_BAKING_WATER)
            EVT_CASE_EQ(COLLIDER_o109)
                EVT_SET(LVar0, PEACH_BAKING_FLOUR)
            EVT_CASE_EQ(COLLIDER_o110)
                EVT_SET(LVar0, PEACH_BAKING_MILK)
        EVT_END_SWITCH
        EVT_CALL(N(SetHeldBakingItem), LVar0)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_SET(AB_KKJ19_HeldIngredient, LVarB)
        EVT_CALL(AddKeyItem, LVarB)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_00E7, 160, 40)
    EVT_ELSE
        // exchanging held ingredient for current station
        EVT_CALL(FindKeyItem, LVar0, LVar1)
        EVT_IF_EQ(LVar1, -1)
            EVT_SET(LVar9, AB_KKJ19_HeldIngredient)
            EVT_CALL(N(GetItemNameRaw), LVar9)
            EVT_CALL(N(GetItemNameRaw), LVarA)
            EVT_CALL(SetMessageText, LVar9, 0)
            EVT_CALL(SetMessageText, LVarA, 1)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_00E9, 160, 40)
            EVT_CALL(ShowChoice, MSG_Choice_002B)
            EVT_IF_EQ(LVar0, 0)
                EVT_EXEC_WAIT(N(EVS_ReturnHeldIngredient))
                EVT_CALL(N(GetFloorCollider), LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(COLLIDER_o101)
                        EVT_SET(LVar0, PEACH_BAKING_SUGAR)
                    EVT_CASE_EQ(COLLIDER_o102)
                        EVT_SET(LVar0, PEACH_BAKING_SALT)
                    EVT_CASE_EQ(COLLIDER_o103)
                        EVT_SET(LVar0, PEACH_BAKING_EGG)
                    EVT_CASE_EQ(COLLIDER_o105)
                        EVT_SET(LVar0, PEACH_BAKING_STRAWBERRY)
                    EVT_CASE_EQ(COLLIDER_o106)
                        EVT_SET(LVar0, PEACH_BAKING_CREAM)
                    EVT_CASE_EQ(COLLIDER_o107)
                        EVT_SET(LVar0, PEACH_BAKING_BUTTER)
                    EVT_CASE_EQ(COLLIDER_o108)
                        EVT_SET(LVar0, PEACH_BAKING_CLEANSER)
                    EVT_CASE_EQ(COLLIDER_o114)
                        EVT_SET(LVar0, PEACH_BAKING_WATER)
                    EVT_CASE_EQ(COLLIDER_o109)
                        EVT_SET(LVar0, PEACH_BAKING_FLOUR)
                    EVT_CASE_EQ(COLLIDER_o110)
                        EVT_SET(LVar0, PEACH_BAKING_MILK)
                EVT_END_SWITCH
                EVT_CALL(N(SetHeldBakingItem), LVar0)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
                EVT_SET(AB_KKJ19_HeldIngredient, LVarB)
                EVT_CALL(AddKeyItem, LVarB)
                EVT_CALL(SwitchMessage, MSG_Peach_00EA)
            EVT_ELSE
                EVT_CALL(CloseMessage)
            EVT_END_IF
        EVT_ELSE
            // placing ingredient back at its station
            EVT_CALL(N(GetItemNameRaw), LVarA)
            EVT_CALL(SetMessageText, LVarA, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_00E6, 160, 40)
            EVT_CALL(ShowChoice, MSG_Choice_002B)
            EVT_IF_EQ(LVar0, 0)
                EVT_EXEC_WAIT(N(EVS_ReturnHeldIngredient))
                EVT_CALL(SwitchMessage, MSG_Peach_00E8)
            EVT_ELSE
                EVT_CALL(CloseMessage)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_KKJ19_CanTakeIngredients, TRUE)
    EVT_WAIT(5)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_AddIngredient) = {
    EVT_IF_EQ(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DONE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_SWITCH(AB_KKJ19_CurrentBakeStep)
        EVT_CASE_EQ(BAKE_STEP_ADD_SUGAR_AND_EGGS)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(ITEM_BAKING_SUGAR)
                    EVT_SET(AF_KKJ19_AddedSugar, TRUE)
                EVT_CASE_EQ(ITEM_BAKING_EGG)
                    EVT_SET(AF_KKJ19_AddedEgg, TRUE)
                EVT_CASE_DEFAULT
                    EVT_SET(AF_KKJ19_AddedNothingWrong, FALSE)
            EVT_END_SWITCH
            EVT_IF_EQ(AB_KKJ19_BakeStepProgress, 0)
                EVT_CALL(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
                EVT_CALL(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
            EVT_END_IF
            EVT_IF_GT(AB_KKJ19_BakeStepProgress, 1)
                EVT_SET(AF_KKJ19_AddedNothingWrong, FALSE)
            EVT_END_IF
        EVT_CASE_EQ(BAKE_STEP_ADD_FLOUR_AND_BUTTER)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(ITEM_BAKING_FLOUR)
                    EVT_SET(AF_KKJ19_AddedFlour, TRUE)
                EVT_CASE_EQ(ITEM_BAKING_BUTTER)
                    EVT_SET(AF_KKJ19_AddedButter, TRUE)
                EVT_CASE_DEFAULT
                    EVT_SET(AF_KKJ19_AddedNothingWrong, FALSE)
            EVT_END_SWITCH
            EVT_IF_GT(AB_KKJ19_BakeStepProgress, 1)
                EVT_SET(AF_KKJ19_AddedNothingWrong, FALSE)
            EVT_END_IF
        EVT_CASE_EQ(BAKE_STEP_DECORATING)
            EVT_SWITCH(AB_KKJ19_BakeStepProgress)
                EVT_CASE_EQ(0)
                    EVT_IF_NE(LVar0, ITEM_BAKING_CREAM)
                        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
                    EVT_END_IF
                EVT_CASE_EQ(1)
                    EVT_IF_NE(LVar0, ITEM_BAKING_STRAWBERRY)
                        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
                    EVT_END_IF
                EVT_CASE_DEFAULT
                    EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
            EVT_END_SWITCH
            EVT_CALL(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(ITEM_BAKING_STRAWBERRY)
                    EVT_IF_EQ(AB_KKJ19_AddedIcing, FALSE)
                        EVT_CALL(MakeItemEntity, ITEM_CAKE_WITH_BERRIES, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
                        EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
                    EVT_ELSE
                        EVT_CALL(MakeItemEntity, ITEM_CAKE_DONE, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
                        EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
                    EVT_END_IF
                    EVT_SET(AB_KKJ19_AddedBerries, TRUE)
                EVT_CASE_DEFAULT
                    EVT_CALL(MakeItemEntity, ITEM_CAKE_WITH_ICING, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
                    EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
                    EVT_SET(AB_KKJ19_AddedIcing, TRUE)
                    EVT_SET(AB_KKJ19_AddedBerries, FALSE)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_ADD(AB_KKJ19_BakeStepProgress, 1)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindInteractTriggers) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_AddIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o118, EVT_PTR(N(BakingIngredientsList)), 0, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o101, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o102, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o103, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o105, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o106, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o107, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o108, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o114, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o109, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o110, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenOverDoor) = {
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g33, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseOverDoor) = {
    EVT_CALL(MakeLerp, 90, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g33, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickupFinalCake) = {
    EVT_IF_EQ(AB_KKJ19_AddedBerries, FALSE)
        EVT_SET(LVar0, PEACH_BAKING_CAKE_WITH_ICING)
    EVT_ELSE
        EVT_IF_EQ(AB_KKJ19_AddedIcing, FALSE)
            EVT_SET(LVar0, PEACH_BAKING_CAKE_WITH_BERRIES)
        EVT_ELSE
            EVT_SET(LVar0, PEACH_BAKING_COMPLETE_CAKE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    EVT_CALL(N(SetHeldBakingItem), LVar0)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_SET(AF_KKJ_FinishedBakingCake, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindCakePickup) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PickupFinalCake)), TRIGGER_WALL_PRESS_A, COLLIDER_o189, 1, 0)
    EVT_RETURN
    EVT_END
};

Vec3f N(FetchBookPath)[] = {
    {  440.0,    25.0,  -30.0 },
    {  480.0,    60.0,  -60.0 },
    {  550.0,    50.0,  -90.0 },
    {  590.0,    40.0, -110.0 },
    {  630.0,   100.0, -124.0 },
};

EvtScript N(EVS_FocusCam_Twink) = {
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-4.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_PeachAndTwink) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
    // get average position of peach and twink
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_ADD(LVar1, LVar4)
    EVT_DIV(LVar1, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_Oven) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 130, 0, -100)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 130, 0, -100)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_Table) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 330, 0, -80)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 330, 0, -80)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Twink_FlyToPlayer) = {
    EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 1)
    EVT_CALL(SetNpcVar, NPC_Twink, 1, 0)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, LVar3)
        EVT_ADD(LVar0, 40)
    EVT_ELSE
        EVT_SUB(LVar0, 40)
    EVT_END_IF
    EVT_ADD(LVar1, 30)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 15 * DT, -5, EASING_LINEAR)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Twink_FlyToHighPos) = {
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 0, -5, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoorWithCake) = {
    EVT_IF_EQ(AF_KKJ_FinishedBakingCake, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_IF_EQ(AB_KKJ19_CurrentBakeStep, CAKE_TYPE_DONE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00C1)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BE)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_SET(LVar0, kkj_19_ENTRY_0)
        EVT_SET(LVar1, COLLIDER_ttse)
        EVT_SET(LVar2, MODEL_o95)
        EVT_SET(LVar3, DOOR_SWING_IN)
        EVT_EXEC(ExitSingleDoor)
        EVT_WAIT(17)
        EVT_CALL(GotoMap, EVT_PTR("kkj_18"), kkj_18_ENTRY_0)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

enum {
    // starting
    LBL_TRY_RESUME                  = 0,
    // (1) add sugar & eggs
    LBL_ADD_SUGAR_EGGS              = 10,
    LBL_ADD_SUGAR_EGGS_WAITING      = 15,
    // (2) mix it
    LBL_MIX_FIRST                   = 20,
    LBL_MIX_RESUME                  = 21,
    // (3) add flour & butter
    LBL_ADD_FLOUR_BUTTER_FIRST      = 60,
    LBL_ADD_FLOUR_BUTTER_RESUME     = 61,
    LBL_ADD_FLOUR_BUTTER_WAITING    = 65,
    // (4) baking
    LBL_BAKE_FIRST                  = 30,
    LBL_BAKE_RESUME                 = 31,
    // (5) decorating
    LBL_DECORATE_FIRST              = 40,
    LBL_DECORATE_RESUME             = 41,
    LBL_DECORATE_WAITING            = 45,
    // outcomes
    LBL_FINISHED                    = 50,
    LBL_START_OVER                  = 99,
};

EvtScript N(EVS_EnterKitchen_FirstTime) = {
    EVT_SET(LVar0, kkj_19_ENTRY_0)
    EVT_SET(LVar2, MODEL_o95)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0))
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 440, 25, -30, 0, -5, EASING_LINEAR)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 5)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, 400, -30, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), 0, EVT_FLOAT(300.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00B9)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 630, 85, -140)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 112, -200)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 610, -60)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(LoadPath, 60 * DT, EVT_PTR(N(FetchBookPath)), ARRAY_COUNT(N(FetchBookPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BA)
    EVT_CALL(EnableModel, MODEL_o128, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TakeBook)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 300, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 440, 25, -30, 0, -5, EASING_LINEAR)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_IdleBook)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00BB)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00BC)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00BD)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_SET(AB_KKJ_CompletedBakeStep, CAKE_TYPE_BEGUN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterKitchen_TryAgain) = {
    EVT_CALL(EnableModel, MODEL_o128, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ArmsCrossedIdle)
    EVT_CALL(SetPlayerPos, 400, 0, -30)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 440, 25, -30)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 300, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00C2)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_00C3)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(ContinueSpeech, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 0, MSG_Peach_00C4)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_IdleBook)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageBaking) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(EnableModel, MODEL_o46, FALSE)
    EVT_CALL(EnableModel, MODEL_o50, FALSE)
    EVT_EXEC_WAIT(N(EVS_SetCookwareOnTable))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoorWithCake)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    EVT_EXEC(N(EVS_BindInteractTriggers))
    EVT_IF_EQ(AB_KKJ_CompletedBakeStep, CAKE_TYPE_NONE)
        EVT_EXEC_WAIT(N(EVS_EnterKitchen_FirstTime))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_EnterKitchen_TryAgain))
    EVT_END_IF

    // start of cooking process
    EVT_LABEL(LBL_TRY_RESUME)
    EVT_SET(AF_KKJ_FinishedBakingCake, FALSE)
    EVT_SET(AF_KKJ19_FailedBakingTask, FALSE)
    EVT_SET(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
    EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 1)
    EVT_CALL(SetNpcVar, NPC_Twink, 1, 0)
    EVT_IF_EQ(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_MIX)
        // resume mixing
        EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00C5)
        EVT_EXEC_WAIT(N(EVS_FocusCam_Table))
        EVT_CALL(InterpPlayerYaw, 270, 5)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00C6)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        EVT_WAIT(20 * DT)
        EVT_EXEC(N(EVS_Twink_FlyToHighPos))
        EVT_GOTO(LBL_MIX_RESUME)
    EVT_END_IF
    EVT_IF_EQ(AB_KKJ_CompletedBakeStep, CAKE_TYPE_MIXED)
        // resume adding flour & butter
        EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00C7)
        EVT_EXEC_WAIT(N(EVS_FocusCam_Table))
        EVT_CALL(InterpPlayerYaw, 270, 5)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00C8)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        EVT_WAIT(20 * DT)
        EVT_GOTO(LBL_ADD_FLOUR_BUTTER_RESUME)
    EVT_END_IF
    EVT_IF_EQ(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_BAKE)
        // resume baking
        EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00C9)
        EVT_EXEC_WAIT(N(EVS_FocusCam_Table))
        EVT_CALL(InterpPlayerYaw, 270, 5)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00CA)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        EVT_WAIT(20 * DT)
        EVT_EXEC(N(EVS_Twink_FlyToHighPos))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(func_802D1270, LVar0, -74, EVT_FLOAT(2.0 / DT))
        EVT_CALL(func_802D1270, 287, -74, EVT_FLOAT(2.0 / DT))
        EVT_GOTO(LBL_BAKE_RESUME)
    EVT_END_IF
    EVT_IF_EQ(AB_KKJ_CompletedBakeStep, CAKE_TYPE_BAKED)
        // resume decorating
        EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00CB)
        EVT_EXEC_WAIT(N(EVS_FocusCam_Table))
        EVT_CALL(InterpPlayerYaw, 270, 5)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00CC)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        EVT_WAIT(20)
        EVT_THREAD
            EVT_EXEC_WAIT(N(EVS_Twink_FlyToHighPos))
            EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            EVT_CALL(SetNpcVar, NPC_Twink, 1, 1)
        EVT_END_THREAD
        EVT_SET(LVarA, 1)
        EVT_GOTO(LBL_DECORATE_RESUME)
    EVT_END_IF

    // step 1: add sugar & eggs
    EVT_LABEL(LBL_ADD_SUGAR_EGGS)
    EVT_SET(AB_KKJ19_CurrentBakeStep, BAKE_STEP_ADD_SUGAR_AND_EGGS)
    EVT_SET(AB_KKJ19_BakeStepProgress, 0)
    EVT_SET(AF_KKJ19_CanTakeIngredients, TRUE)
    EVT_SET(AF_KKJ19_AddedSugar, FALSE)
    EVT_SET(AF_KKJ19_AddedEgg, FALSE)
    EVT_SET(AF_KKJ19_AddedNothingWrong, TRUE)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00D1)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_SET(LVarA, 1)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_Twink_FlyToHighPos))
        EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
        EVT_CALL(SetNpcVar, NPC_Twink, 1, 1)
    EVT_END_THREAD
    // wait for peach to tell twink shes done
    EVT_LABEL(LBL_ADD_SUGAR_EGGS_WAITING)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_IF_EQ(LVarA, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            EVT_CALL(SetNpcVar, NPC_Twink, 1, 1)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetNpcVar, NPC_Twink, 0, 1)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_Twink, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_EXEC_WAIT(N(EVS_Twink_FlyToPlayer))
        EVT_EXEC_WAIT(N(EVS_FocusCam_PeachAndTwink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00D2)
        EVT_CALL(ShowChoice, MSG_Choice_0029)
        EVT_IF_EQ(LVar0, 0)
            EVT_IF_EQ(AB_KKJ19_BakeStepProgress, 0)
                EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BF)
                EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
                EVT_SET(LVarA, 0)
                EVT_GOTO(LBL_ADD_SUGAR_EGGS_WAITING)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00D3)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
            EVT_SET(LVarA, 0)
            EVT_GOTO(LBL_ADD_SUGAR_EGGS_WAITING)
        EVT_END_IF
    EVT_IF_EQ(LVar0, 2)
        EVT_GOTO(LBL_START_OVER)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_ReturnHeldIngredient))
    EVT_SET(LVar0, 0)
    EVT_ADD(LVar0, AF_KKJ19_AddedSugar)
    EVT_ADD(LVar0, AF_KKJ19_AddedEgg)
    EVT_ADD(LVar0, AF_KKJ19_AddedNothingWrong)
    EVT_IF_NE(LVar0, 3)
        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
    EVT_END_IF
    EVT_IF_EQ(AF_KKJ19_FailedBakingTask, FALSE)
        EVT_SET(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_MIX)
    EVT_END_IF

    // step 2: mix the ingredients
    EVT_LABEL(LBL_MIX_FIRST)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10)
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00D4)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_EXEC(N(EVS_Twink_FlyToHighPos))
    // resume failed step from here
    EVT_LABEL(LBL_MIX_RESUME)
    EVT_SET(AB_KKJ19_CurrentBakeStep, BAKE_STEP_MIXING)
    EVT_SET(AB_KKJ19_BakeStepProgress, 0)
    EVT_SET(AF_KKJ19_CanTakeIngredients, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, LVar0, -74, 0)
    EVT_CALL(PlayerMoveTo, 287, -74, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00D5)
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
    EVT_EXEC_GET_TID(N(EVS_UpdatePeachMixingAnimations), LVarA)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_STIRRING_CAKE, 0, 8)
    EVT_CALL(PlaySound, SOUND_GENERAL_WHISTLE)
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(0.2 / DT), 0, 250, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_END_THREAD
    EVT_CALL(N(RunMixingMinigame), MIXING_TIME_IN_FRAMES)
    EVT_CALL(PlaySound, SOUND_GENERAL_WHISTLE)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_KILL_THREAD(LVarA)
    EVT_IF_LT(LVar0, MIXING_REQUIRED_INPUTS)
        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
    EVT_END_IF
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_END_THREAD
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 337, 35, -74, 30 * DT, -5, EASING_LINEAR)
    EVT_WAIT(10 * DT)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_FocusCam_PeachAndTwink))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
        EVT_CALL(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00D6)
    EVT_CALL(ShowChoice, MSG_Choice_002B)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(EndSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00D7)
        EVT_CALL(ShowChoice, MSG_Choice_002A)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(EndSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5)
        EVT_ELSE
            EVT_GOTO(LBL_START_OVER)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(AF_KKJ19_FailedBakingTask, FALSE)
        EVT_SET(AB_KKJ_CompletedBakeStep, CAKE_TYPE_MIXED)
    EVT_END_IF

    // step 3: add flour and butter
    EVT_LABEL(LBL_ADD_FLOUR_BUTTER_FIRST)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00D8)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    // resume failed step from here
    EVT_LABEL(LBL_ADD_FLOUR_BUTTER_RESUME)
    EVT_SET(AB_KKJ19_CurrentBakeStep, BAKE_STEP_ADD_FLOUR_AND_BUTTER)
    EVT_SET(AB_KKJ19_BakeStepProgress, 0)
    EVT_SET(AF_KKJ19_CanTakeIngredients, TRUE)
    EVT_SET(AF_KKJ19_AddedFlour, FALSE)
    EVT_SET(AF_KKJ19_AddedButter, FALSE)
    EVT_SET(AF_KKJ19_AddedNothingWrong, TRUE)
    EVT_SET(LVarA, 1)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_Twink_FlyToHighPos))
        EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
        EVT_CALL(SetNpcVar, NPC_Twink, 1, 1)
    EVT_END_THREAD
    // wait for peach to tell twink shes done
    EVT_LABEL(LBL_ADD_FLOUR_BUTTER_WAITING)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_IF_EQ(LVarA, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            EVT_CALL(SetNpcVar, NPC_Twink, 1, 1)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetNpcVar, NPC_Twink, 0, 1)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_Twink, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_EXEC_WAIT(N(EVS_Twink_FlyToPlayer))
        EVT_EXEC_WAIT(N(EVS_FocusCam_PeachAndTwink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00D9)
        EVT_CALL(ShowChoice, MSG_Choice_0029)
        EVT_IF_EQ(LVar0, 0)
            EVT_IF_EQ(AB_KKJ19_BakeStepProgress, 0)
                EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BF)
                EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
                EVT_SET(LVarA, 0)
                EVT_GOTO(LBL_ADD_FLOUR_BUTTER_WAITING)
            EVT_ELSE
                EVT_CALL(EndSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DA)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
            EVT_SET(LVarA, 0)
            EVT_GOTO(LBL_ADD_FLOUR_BUTTER_WAITING)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 2)
            EVT_GOTO(LBL_START_OVER)
        EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_ReturnHeldIngredient))
    EVT_SET(LVar0, 0)
    EVT_ADD(LVar0, AF_KKJ19_AddedFlour)
    EVT_ADD(LVar0, AF_KKJ19_AddedButter)
    EVT_ADD(LVar0, AF_KKJ19_AddedNothingWrong)
    EVT_IF_NE(LVar0, 3)
        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
    EVT_END_IF
    EVT_IF_EQ(AF_KKJ19_FailedBakingTask, FALSE)
        EVT_SET(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_BAKE)
    EVT_END_IF

    // step 4: baking
    EVT_LABEL(LBL_BAKE_FIRST)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00DB)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_EXEC(N(EVS_Twink_FlyToHighPos))
    // resume failed step from here
    EVT_LABEL(LBL_BAKE_RESUME)
    EVT_SET(AB_KKJ19_CurrentBakeStep, BAKE_STEP_BAKING)
    EVT_SET(AF_KKJ19_CanTakeIngredients, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, LVar0, -74, 0)
    EVT_CALL(PlayerMoveTo, 287, -74, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
    EVT_WAIT(10 * DT)
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_MixingFull)
    EVT_WAIT(40 * DT)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_CAKE_MIXED)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0 / DT))
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 337, 35, -74, 0, -5, EASING_LINEAR)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, 190, -70, 0)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_CALL(PlayerMoveTo, 190, 35, 0)
    EVT_CALL(PlayerMoveTo, 240, 35, 0)
    EVT_CALL(InterpPlayerYaw, 350, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_PourBatter)
    EVT_WAIT(20 * DT)
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    EVT_CALL(MakeItemEntity, ITEM_CAKE_BATTER, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
    EVT_WAIT(10 * DT)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(MakeItemEntity, ITEM_CAKE_BOWL, 250, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(AB_KKJ19_CookwareItemIdx, LVar0)
    EVT_WAIT(40 * DT)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00DC)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(InterpPlayerYaw, 315, 0)
    EVT_WAIT(10)
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_CAKE_BATTER)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(10)
    EVT_EXEC(N(EVS_FocusCam_Oven))
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 190, 60, -100, 50 * DT, -5, EASING_LINEAR)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, 190, 30, 0)
    EVT_CALL(PlayerMoveTo, 190, -100, 0)
    EVT_CALL(PlayerMoveTo, 125, -100, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DD)
    EVT_CALL(InterpPlayerYaw, 315, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(N(AwaitPlayerPressATimer))
    EVT_EXEC_WAIT(N(EVS_OpenOverDoor))
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(MakeItemEntity, ITEM_CAKE_BATTER, 100, 5, -135, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
    EVT_SET(LVar0, -135)
    EVT_LOOP(30)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetItemPos, AB_KKJ19_CakeItemIdx, 100, 5, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC_WAIT(N(EVS_CloseOverDoor))
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAt, SOUND_START_OVEN_TIMER, SOUND_SPACE_DEFAULT, 100, 22, -178)
    EVT_WAIT(20 * DT)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(PlaySoundAt, SOUND_OVEN_TIMER_TICKING, SOUND_SPACE_DEFAULT, 100, 22, -178)
    EVT_CALL(N(AwaitPlayerPressATimer))
    EVT_CALL(StopSound, SOUND_OVEN_TIMER_TICKING)
    EVT_CALL(PlaySoundAt, SOUND_DING, SOUND_SPACE_DEFAULT, 100, 22, -178)
    EVT_WAIT(10 * DT)
    // check baking time
    EVT_IF_LT(LVar0, BAKING_TIME_MIN_FRAMES)
        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
    EVT_END_IF
    EVT_IF_GT(LVar0, BAKING_TIME_MAX_FRAMES)
        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_OpenOverDoor))
    EVT_SET(LVar0, -165)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_ADD(LVar0, 1)
        EVT_CALL(SetItemPos, AB_KKJ19_CakeItemIdx, 100, 5, LVar0)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_CAKE_BATTER)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_EXEC_WAIT(N(EVS_CloseOverDoor))
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_EXEC_WAIT(N(EVS_FocusCam_PeachAndTwink))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DE)
    EVT_CALL(ShowChoice, MSG_Choice_002B)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DF)
        EVT_CALL(ShowChoice, MSG_Choice_002A)
        EVT_IF_NE(LVar0, 0)
            EVT_GOTO(LBL_START_OVER)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00E0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 287, 0, -74)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 287, 0, -74)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_EXEC(N(EVS_Twink_FlyToHighPos))
    EVT_CALL(PlayerMoveTo, 287, -74, 100)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(MakeItemEntity, ITEM_CAKE_BATTER, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(RemoveItemEntity, LVar0)
    EVT_CALL(MakeItemEntity, ITEM_CAKE_BARE, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(AB_KKJ19_CakeItemIdx, LVar0)
    EVT_WAIT(10 * DT)
    EVT_IF_EQ(AF_KKJ19_FailedBakingTask, FALSE)
        EVT_SET(AB_KKJ_CompletedBakeStep, CAKE_TYPE_BAKED)
    EVT_END_IF

    // step 5: decorating
    EVT_LABEL(LBL_DECORATE_FIRST)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Twink))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00E1)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_SET(LVarA, 0)
    // resume failed step from here
    EVT_LABEL(LBL_DECORATE_RESUME)
    EVT_SET(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DECORATING)
    EVT_SET(AB_KKJ19_BakeStepProgress, 0)
    EVT_SET(AF_KKJ19_CanTakeIngredients, TRUE)
    EVT_SET(AB_KKJ19_AddedIcing, FALSE)
    EVT_SET(AB_KKJ19_AddedBerries, FALSE)
    // wait for peach to tell twink shes done
    EVT_LABEL(LBL_DECORATE_WAITING)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_IF_EQ(LVarA, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            EVT_CALL(SetNpcVar, NPC_Twink, 1, 1)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetNpcVar, NPC_Twink, 0, 1)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_Twink, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_EXEC_WAIT(N(EVS_Twink_FlyToPlayer))
        EVT_EXEC_WAIT(N(EVS_FocusCam_PeachAndTwink))
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00E2)
        EVT_CALL(ShowChoice, MSG_Choice_0029)
        EVT_IF_EQ(LVar0, 0)
            // chose 'done'
            EVT_IF_EQ(AB_KKJ19_BakeStepProgress, 0)
                EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00C0)
                EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
                EVT_SET(LVarA, 0)
                EVT_GOTO(LBL_DECORATE_WAITING)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVar0, 1)
            // chose 'not done'
            EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00E3)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
            EVT_SET(LVarA, 0)
            EVT_GOTO(LBL_DECORATE_WAITING)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 2)
            // chose 'start over'
            EVT_GOTO(LBL_START_OVER)
        EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_ReturnHeldIngredient))
    EVT_IF_EQ(AB_KKJ19_AddedBerries, FALSE)
        EVT_SET(AF_KKJ19_FailedBakingTask, TRUE)
    EVT_END_IF
    EVT_IF_EQ(AF_KKJ19_FailedBakingTask, FALSE)
        EVT_SET(AB_KKJ_CompletedBakeStep, CAKE_TYPE_DONE)
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Delighted)
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_ShoutJoy, ANIM_Twink_ShoutJoy, 0, MSG_Peach_00E4)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)

    // cake ready for gourmet guy (but not necessarily succcesful)
    EVT_LABEL(LBL_FINISHED)
    EVT_SET(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DONE)
    EVT_SET(AF_KKJ19_CanTakeIngredients, FALSE)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_EXEC(N(EVS_BindCakePickup))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN

    // starting over
    EVT_LABEL(LBL_START_OVER)
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00CD)
    EVT_CALL(N(FadeScreenToBlack))
    EVT_EXEC_WAIT(N(EVS_ReturnHeldIngredient))
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
    EVT_IF_NE(AB_KKJ19_CurrentBakeStep, BAKE_STEP_BAKING)
        EVT_CALL(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetCookwareOnTable))
    EVT_CALL(SetNpcPos, NPC_PARTNER, 440, 25, -30)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SetPlayerPos, 400, 0, -30)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 350, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(N(FadeScreenFromBlack))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00CE)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_00CF)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(ContinueSpeech, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 0, MSG_Peach_00D0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_IdleBook)
    EVT_GOTO(LBL_TRY_RESUME)
    EVT_END
};
