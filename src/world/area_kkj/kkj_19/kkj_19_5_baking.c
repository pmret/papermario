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
    Switch(AB_KKJ_CompletedBakeStep)
        CaseEq(CAKE_TYPE_NONE)
            Call(MakeItemEntity, ITEM_CAKE_BOWL, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CookwareItemIdx, LVar0)
            Call(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CakeItemIdx, LVar0)
        CaseEq(CAKE_TYPE_BEGUN)
            Call(MakeItemEntity, ITEM_CAKE_BOWL, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CookwareItemIdx, LVar0)
            Call(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CakeItemIdx, LVar0)
        CaseEq(CAKE_TYPE_READY_TO_MIX)
            Call(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CookwareItemIdx, LVar0)
            Call(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CakeItemIdx, LVar0)
        CaseEq(CAKE_TYPE_MIXED)
            Call(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CookwareItemIdx, LVar0)
            Call(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CakeItemIdx, LVar0)
        CaseEq(CAKE_TYPE_READY_TO_BAKE)
            Call(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CookwareItemIdx, LVar0)
            Call(MakeItemEntity, ITEM_CAKE_PAN, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CakeItemIdx, LVar0)
        CaseEq(CAKE_TYPE_BAKED)
            Call(MakeItemEntity, ITEM_CAKE_BARE, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CakeItemIdx, LVar0)
            Call(MakeItemEntity, ITEM_CAKE_BOWL, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
            Set(AB_KKJ19_CookwareItemIdx, LVar0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UpdatePeachMixingAnimations) = {
    Call(SetPlayerAnimation, ANIM_Peach2_Mixing1)
    Set(LVar0, 0)
    Loop(0)
        Switch(AB_KKJ19_BakeStepProgress)
            CaseEq(MIXING_ANIM_IDLE)
                // increment the animation on next MIXING_ANIM_NEXT
                Set(LVar1, 0)
            CaseEq(MIXING_ANIM_NEXT)
                IfEq(LVar1, 0)
                    // increment the animation
                    Switch(LVar0)
                        CaseEq(0)
                            Call(SetPlayerAnimation, ANIM_Peach2_Mixing1)
                            Set(LVar0, 1)
                        CaseEq(1)
                            Call(SetPlayerAnimation, ANIM_Peach2_Mixing2)
                            Set(LVar0, 2)
                        CaseEq(2)
                            Call(SetPlayerAnimation, ANIM_Peach2_Mixing3)
                            Set(LVar0, 3)
                        CaseEq(3)
                            Call(SetPlayerAnimation, ANIM_Peach2_Mixing4)
                            Set(LVar0, 0)
                    EndSwitch
                    Set(LVar1, 1)
                Else
                    // wait until next MIXING_ANIM_NEXT to increment the animation
                    Set(LVar1, 0)
                EndIf
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ReturnHeldIngredient) = {
    IfNe(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
        Call(FindKeyItem, AB_KKJ19_HeldIngredient, LVar0)
        Call(RemoveKeyItemAt, LVar0)
        Set(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
        Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_TakeIngredient) = {
    IfEq(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DONE)
        Return
    EndIf
    // get itemID of current station
    Call(N(GetFloorCollider), LVar0)
    Switch(LVar0)
        CaseEq(COLLIDER_o101)
            Set(LVar0, ITEM_BAKING_SUGAR)
        CaseEq(COLLIDER_o102)
            Set(LVar0, ITEM_BAKING_SALT)
        CaseEq(COLLIDER_o103)
            Set(LVar0, ITEM_BAKING_EGG)
        CaseEq(COLLIDER_o105)
            Set(LVar0, ITEM_BAKING_STRAWBERRY)
        CaseEq(COLLIDER_o106)
            Set(LVar0, ITEM_BAKING_CREAM)
        CaseEq(COLLIDER_o107)
            Set(LVar0, ITEM_BAKING_BUTTER)
        CaseEq(COLLIDER_o108)
            Set(LVar0, ITEM_BAKING_CLEANSER)
        CaseEq(COLLIDER_o114)
            Set(LVar0, ITEM_BAKING_WATER)
        CaseEq(COLLIDER_o109)
            Set(LVar0, ITEM_BAKING_FLOUR)
        CaseEq(COLLIDER_o110)
            Set(LVar0, ITEM_BAKING_MILK)
        CaseDefault
            Return
    EndSwitch
    Call(DisablePlayerInput, TRUE)
    Set(AF_KKJ19_CanTakeIngredients, FALSE)
    Wait(5)
    Set(LVarA, LVar0)
    Set(LVarB, LVar0)
    IfEq(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
        // picking up an ingredient while not holding any
        Call(N(GetItemNameRaw), LVarA)
        Call(SetMessageText, LVarA, 0)
        Call(N(GetFloorCollider), LVar0)
        Switch(LVar0)
            CaseEq(COLLIDER_o101)
                Set(LVar0, PEACH_BAKING_SUGAR)
            CaseEq(COLLIDER_o102)
                Set(LVar0, PEACH_BAKING_SALT)
            CaseEq(COLLIDER_o103)
                Set(LVar0, PEACH_BAKING_EGG)
            CaseEq(COLLIDER_o105)
                Set(LVar0, PEACH_BAKING_STRAWBERRY)
            CaseEq(COLLIDER_o106)
                Set(LVar0, PEACH_BAKING_CREAM)
            CaseEq(COLLIDER_o107)
                Set(LVar0, PEACH_BAKING_BUTTER)
            CaseEq(COLLIDER_o108)
                Set(LVar0, PEACH_BAKING_CLEANSER)
            CaseEq(COLLIDER_o114)
                Set(LVar0, PEACH_BAKING_WATER)
            CaseEq(COLLIDER_o109)
                Set(LVar0, PEACH_BAKING_FLOUR)
            CaseEq(COLLIDER_o110)
                Set(LVar0, PEACH_BAKING_MILK)
        EndSwitch
        Call(N(SetHeldBakingItem), LVar0)
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
        Set(AB_KKJ19_HeldIngredient, LVarB)
        Call(AddKeyItem, LVarB)
        Call(ShowMessageAtScreenPos, MSG_Peach_00E7, 160, 40)
    Else
        // exchanging held ingredient for current station
        Call(FindKeyItem, LVar0, LVar1)
        IfEq(LVar1, -1)
            Set(LVar9, AB_KKJ19_HeldIngredient)
            Call(N(GetItemNameRaw), LVar9)
            Call(N(GetItemNameRaw), LVarA)
            Call(SetMessageText, LVar9, 0)
            Call(SetMessageText, LVarA, 1)
            Call(ShowMessageAtScreenPos, MSG_Peach_00E9, 160, 40)
            Call(ShowChoice, MSG_Choice_002B)
            IfEq(LVar0, 0)
                ExecWait(N(EVS_ReturnHeldIngredient))
                Call(N(GetFloorCollider), LVar0)
                Switch(LVar0)
                    CaseEq(COLLIDER_o101)
                        Set(LVar0, PEACH_BAKING_SUGAR)
                    CaseEq(COLLIDER_o102)
                        Set(LVar0, PEACH_BAKING_SALT)
                    CaseEq(COLLIDER_o103)
                        Set(LVar0, PEACH_BAKING_EGG)
                    CaseEq(COLLIDER_o105)
                        Set(LVar0, PEACH_BAKING_STRAWBERRY)
                    CaseEq(COLLIDER_o106)
                        Set(LVar0, PEACH_BAKING_CREAM)
                    CaseEq(COLLIDER_o107)
                        Set(LVar0, PEACH_BAKING_BUTTER)
                    CaseEq(COLLIDER_o108)
                        Set(LVar0, PEACH_BAKING_CLEANSER)
                    CaseEq(COLLIDER_o114)
                        Set(LVar0, PEACH_BAKING_WATER)
                    CaseEq(COLLIDER_o109)
                        Set(LVar0, PEACH_BAKING_FLOUR)
                    CaseEq(COLLIDER_o110)
                        Set(LVar0, PEACH_BAKING_MILK)
                EndSwitch
                Call(N(SetHeldBakingItem), LVar0)
                Call(SetPlayerActionState, ACTION_STATE_IDLE)
                Set(AB_KKJ19_HeldIngredient, LVarB)
                Call(AddKeyItem, LVarB)
                Call(SwitchMessage, MSG_Peach_00EA)
            Else
                Call(CloseMessage)
            EndIf
        Else
            // placing ingredient back at its station
            Call(N(GetItemNameRaw), LVarA)
            Call(SetMessageText, LVarA, 0)
            Call(ShowMessageAtScreenPos, MSG_Peach_00E6, 160, 40)
            Call(ShowChoice, MSG_Choice_002B)
            IfEq(LVar0, 0)
                ExecWait(N(EVS_ReturnHeldIngredient))
                Call(SwitchMessage, MSG_Peach_00E8)
            Else
                Call(CloseMessage)
            EndIf
        EndIf
    EndIf
    Set(AF_KKJ19_CanTakeIngredients, TRUE)
    Wait(5)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_AddIngredient) = {
    IfEq(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DONE)
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(ShowKeyChoicePopup)
    Set(LVar2, LVar0)
    Switch(LVar2)
        CaseEq(0)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
    EndSwitch
    Call(RemoveKeyItemAt, LVar1)
    Set(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
    Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Switch(AB_KKJ19_CurrentBakeStep)
        CaseEq(BAKE_STEP_ADD_SUGAR_AND_EGGS)
            Switch(LVar0)
                CaseEq(ITEM_BAKING_SUGAR)
                    Set(AF_KKJ19_AddedSugar, TRUE)
                CaseEq(ITEM_BAKING_EGG)
                    Set(AF_KKJ19_AddedEgg, TRUE)
                CaseDefault
                    Set(AF_KKJ19_AddedNothingWrong, FALSE)
            EndSwitch
            IfEq(AB_KKJ19_BakeStepProgress, 0)
                Call(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
                Call(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
                Set(AB_KKJ19_CookwareItemIdx, LVar0)
            EndIf
            IfGt(AB_KKJ19_BakeStepProgress, 1)
                Set(AF_KKJ19_AddedNothingWrong, FALSE)
            EndIf
        CaseEq(BAKE_STEP_ADD_FLOUR_AND_BUTTER)
            Switch(LVar0)
                CaseEq(ITEM_BAKING_FLOUR)
                    Set(AF_KKJ19_AddedFlour, TRUE)
                CaseEq(ITEM_BAKING_BUTTER)
                    Set(AF_KKJ19_AddedButter, TRUE)
                CaseDefault
                    Set(AF_KKJ19_AddedNothingWrong, FALSE)
            EndSwitch
            IfGt(AB_KKJ19_BakeStepProgress, 1)
                Set(AF_KKJ19_AddedNothingWrong, FALSE)
            EndIf
        CaseEq(BAKE_STEP_DECORATING)
            Switch(AB_KKJ19_BakeStepProgress)
                CaseEq(0)
                    IfNe(LVar0, ITEM_BAKING_CREAM)
                        Set(AF_KKJ19_FailedBakingTask, TRUE)
                    EndIf
                CaseEq(1)
                    IfNe(LVar0, ITEM_BAKING_STRAWBERRY)
                        Set(AF_KKJ19_FailedBakingTask, TRUE)
                    EndIf
                CaseDefault
                    Set(AF_KKJ19_FailedBakingTask, TRUE)
            EndSwitch
            Call(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
            Switch(LVar0)
                CaseEq(ITEM_BAKING_STRAWBERRY)
                    IfEq(AB_KKJ19_AddedIcing, FALSE)
                        Call(MakeItemEntity, ITEM_CAKE_WITH_BERRIES, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
                        Set(AB_KKJ19_CakeItemIdx, LVar0)
                    Else
                        Call(MakeItemEntity, ITEM_CAKE_DONE, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
                        Set(AB_KKJ19_CakeItemIdx, LVar0)
                    EndIf
                    Set(AB_KKJ19_AddedBerries, TRUE)
                CaseDefault
                    Call(MakeItemEntity, ITEM_CAKE_WITH_ICING, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
                    Set(AB_KKJ19_CakeItemIdx, LVar0)
                    Set(AB_KKJ19_AddedIcing, TRUE)
                    Set(AB_KKJ19_AddedBerries, FALSE)
            EndSwitch
    EndSwitch
    Add(AB_KKJ19_BakeStepProgress, 1)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_BindInteractTriggers) = {
    BindPadlock(Ref(N(EVS_ItemPrompt_AddIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o118, Ref(N(BakingIngredientsList)), 0, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o101, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o102, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o103, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o105, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o106, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o107, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o108, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o114, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o109, 1, 0)
    BindTrigger(Ref(N(EVS_TakeIngredient)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o110, 1, 0)
    Return
    End
};

EvtScript N(EVS_OpenOverDoor) = {
    Call(MakeLerp, 0, 90, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g33, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseOverDoor) = {
    Call(MakeLerp, 90, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g33, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_PickupFinalCake) = {
    IfEq(AB_KKJ19_AddedBerries, FALSE)
        Set(LVar0, PEACH_BAKING_CAKE_WITH_ICING)
    Else
        IfEq(AB_KKJ19_AddedIcing, FALSE)
            Set(LVar0, PEACH_BAKING_CAKE_WITH_BERRIES)
        Else
            Set(LVar0, PEACH_BAKING_COMPLETE_CAKE)
        EndIf
    EndIf
    Call(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    Call(N(SetHeldBakingItem), LVar0)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Set(AF_KKJ_FinishedBakingCake, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_BindCakePickup) = {
    BindTrigger(Ref(N(EVS_PickupFinalCake)), TRIGGER_WALL_PRESS_A, COLLIDER_o189, 1, 0)
    Return
    End
};

Vec3f N(FetchBookPath)[] = {
    {  440.0,    25.0,  -30.0 },
    {  480.0,    60.0,  -60.0 },
    {  550.0,    50.0,  -90.0 },
    {  590.0,    40.0, -110.0 },
    {  630.0,   100.0, -124.0 },
};

EvtScript N(EVS_FocusCam_Twink) = {
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-4.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_PeachAndTwink) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
    // get average position of peach and twink
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Add(LVar1, LVar4)
    Div(LVar1, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_Oven) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 130, 0, -100)
    Call(SetPanTarget, CAM_DEFAULT, 130, 0, -100)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-13.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_Table) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 330, 0, -80)
    Call(SetPanTarget, CAM_DEFAULT, 330, 0, -80)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_Twink_FlyToPlayer) = {
    Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 1)
    Call(SetNpcVar, NPC_Twink, 1, 0)
    Call(GetNpcPos, NPC_PARTNER, LVar3, LVar1, LVar2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, LVar3)
        Add(LVar0, 40)
    Else
        Sub(LVar0, 40)
    EndIf
    Add(LVar1, 30)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 15 * DT, -5, EASING_LINEAR)
    Call(NpcFacePlayer, NPC_PARTNER, 5)
    Return
    End
};

EvtScript N(EVS_Twink_FlyToHighPos) = {
    Call(SetNpcSpeed, NPC_PARTNER, Float(2.0 / DT))
    Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 0, -5, EASING_LINEAR)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 5)
    Return
    End
};

EvtScript N(EVS_ExitDoorWithCake) = {
    IfEq(AF_KKJ_FinishedBakingCake, FALSE)
        Call(DisablePlayerInput, TRUE)
        IfEq(AB_KKJ19_CurrentBakeStep, CAKE_TYPE_DONE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00C1)
        Else
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BE)
        EndIf
        Call(DisablePlayerInput, FALSE)
    Else
        Set(LVar0, kkj_19_ENTRY_0)
        Set(LVar1, COLLIDER_ttse)
        Set(LVar2, MODEL_o95)
        Set(LVar3, DOOR_SWING_IN)
        Exec(ExitSingleDoor)
        Wait(17)
        Call(GotoMap, Ref("kkj_18"), kkj_18_ENTRY_0)
        Wait(100)
    EndIf
    Return
    End
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
    Set(LVar0, kkj_19_ENTRY_0)
    Set(LVar2, MODEL_o95)
    Set(LVar3, DOOR_SWING_IN)
    ExecWait(EnterSingleDoor)
    Thread
        Call(SetNpcSpeed, NPC_PARTNER, Float(2.0))
        Call(NpcFlyTo, NPC_PARTNER, 440, 25, -30, 0, -5, EASING_LINEAR)
        Call(NpcFacePlayer, NPC_PARTNER, 5)
    EndThread
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, 400, -30, 0)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
    Wait(60 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(InterpPlayerYaw, 90, 5)
    Call(AdjustCam, CAM_DEFAULT, Float(4.0 / DT), 0, Float(300.0), Float(17.0), Float(-7.0))
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00B9)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Thread
        Wait(30 * DT)
        Call(SetPanTarget, CAM_DEFAULT, 630, 85, -140)
        Call(SetCamDistance, CAM_DEFAULT, 200)
        Call(SetCamPosA, CAM_DEFAULT, 112, -200)
        Call(SetCamPosB, CAM_DEFAULT, 610, -60)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(InterpNpcYaw, NPC_PARTNER, 90, 5)
    Wait(10 * DT)
    Call(LoadPath, 60 * DT, Ref(N(FetchBookPath)), ARRAY_COUNT(N(FetchBookPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(InterpNpcYaw, NPC_PARTNER, 270, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BA)
    Call(EnableModel, MODEL_o128, FALSE)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TakeBook)
    Wait(30 * DT)
    Thread
        Wait(10 * DT)
        Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, 300, Float(17.0), Float(-7.0))
    EndThread
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0 / DT))
    Call(NpcFlyTo, NPC_PARTNER, 440, 25, -30, 0, -5, EASING_LINEAR)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_IdleBook)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00BB)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00BC)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00BD)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Set(AB_KKJ_CompletedBakeStep, CAKE_TYPE_BEGUN)
    Return
    End
};

EvtScript N(EVS_EnterKitchen_TryAgain) = {
    Call(EnableModel, MODEL_o128, FALSE)
    Call(SetPlayerAnimation, ANIM_Peach2_ArmsCrossedIdle)
    Call(SetPlayerPos, 400, 0, -30)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetNpcPos, NPC_PARTNER, 440, 25, -30)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, 300, Float(17.0), Float(-7.0))
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00C2)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_00C3)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(ContinueSpeech, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 0, MSG_Peach_00C4)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_IdleBook)
    Return
    End
};

EvtScript N(EVS_ManageBaking) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(EnableModel, MODEL_o46, FALSE)
    Call(EnableModel, MODEL_o50, FALSE)
    ExecWait(N(EVS_SetCookwareOnTable))
    BindTrigger(Ref(N(EVS_ExitDoorWithCake)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    Exec(N(EVS_BindInteractTriggers))
    IfEq(AB_KKJ_CompletedBakeStep, CAKE_TYPE_NONE)
        ExecWait(N(EVS_EnterKitchen_FirstTime))
    Else
        ExecWait(N(EVS_EnterKitchen_TryAgain))
    EndIf

    // start of cooking process
    Label(LBL_TRY_RESUME)
    Set(AF_KKJ_FinishedBakingCake, FALSE)
    Set(AF_KKJ19_FailedBakingTask, FALSE)
    Set(AB_KKJ19_HeldIngredient, PEACH_BAKING_NONE)
    Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 1)
    Call(SetNpcVar, NPC_Twink, 1, 0)
    IfEq(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_MIX)
        // resume mixing
        ExecWait(N(EVS_FocusCam_Twink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00C5)
        ExecWait(N(EVS_FocusCam_Table))
        Call(InterpPlayerYaw, 270, 5)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00C6)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        Wait(20 * DT)
        Exec(N(EVS_Twink_FlyToHighPos))
        Goto(LBL_MIX_RESUME)
    EndIf
    IfEq(AB_KKJ_CompletedBakeStep, CAKE_TYPE_MIXED)
        // resume adding flour & butter
        ExecWait(N(EVS_FocusCam_Twink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00C7)
        ExecWait(N(EVS_FocusCam_Table))
        Call(InterpPlayerYaw, 270, 5)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00C8)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        Wait(20 * DT)
        Goto(LBL_ADD_FLOUR_BUTTER_RESUME)
    EndIf
    IfEq(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_BAKE)
        // resume baking
        ExecWait(N(EVS_FocusCam_Twink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00C9)
        ExecWait(N(EVS_FocusCam_Table))
        Call(InterpPlayerYaw, 270, 5)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00CA)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        Wait(20 * DT)
        Exec(N(EVS_Twink_FlyToHighPos))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(func_802D1270, LVar0, -74, Float(2.0 / DT))
        Call(func_802D1270, 287, -74, Float(2.0 / DT))
        Goto(LBL_BAKE_RESUME)
    EndIf
    IfEq(AB_KKJ_CompletedBakeStep, CAKE_TYPE_BAKED)
        // resume decorating
        ExecWait(N(EVS_FocusCam_Twink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00CB)
        ExecWait(N(EVS_FocusCam_Table))
        Call(InterpPlayerYaw, 270, 5)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00CC)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
        Wait(10)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        Wait(20)
        Thread
            ExecWait(N(EVS_Twink_FlyToHighPos))
            Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            Call(SetNpcVar, NPC_Twink, 1, 1)
        EndThread
        Set(LVarA, 1)
        Goto(LBL_DECORATE_RESUME)
    EndIf

    // step 1: add sugar & eggs
    Label(LBL_ADD_SUGAR_EGGS)
    Set(AB_KKJ19_CurrentBakeStep, BAKE_STEP_ADD_SUGAR_AND_EGGS)
    Set(AB_KKJ19_BakeStepProgress, 0)
    Set(AF_KKJ19_CanTakeIngredients, TRUE)
    Set(AF_KKJ19_AddedSugar, FALSE)
    Set(AF_KKJ19_AddedEgg, FALSE)
    Set(AF_KKJ19_AddedNothingWrong, TRUE)
    ExecWait(N(EVS_FocusCam_Twink))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00D1)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    Wait(10)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Set(LVarA, 1)
    Thread
        ExecWait(N(EVS_Twink_FlyToHighPos))
        Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
        Call(SetNpcVar, NPC_Twink, 1, 1)
    EndThread
    // wait for peach to tell twink shes done
    Label(LBL_ADD_SUGAR_EGGS_WAITING)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
        IfEq(LVarA, 0)
            Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            Call(SetNpcVar, NPC_Twink, 1, 1)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetNpcVar, NPC_Twink, 0, 1)
        Loop(0)
            Wait(1)
            Call(GetNpcVar, NPC_Twink, 0, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(DisablePlayerInput, TRUE)
        ExecWait(N(EVS_Twink_FlyToPlayer))
        ExecWait(N(EVS_FocusCam_PeachAndTwink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00D2)
        Call(ShowChoice, MSG_Choice_0029)
        IfEq(LVar0, 0)
            IfEq(AB_KKJ19_BakeStepProgress, 0)
                Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BF)
                Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
                Set(LVarA, 0)
                Goto(LBL_ADD_SUGAR_EGGS_WAITING)
            EndIf
        EndIf
        IfEq(LVar0, 1)
            Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00D3)
            Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
            Set(LVarA, 0)
            Goto(LBL_ADD_SUGAR_EGGS_WAITING)
        EndIf
    IfEq(LVar0, 2)
        Goto(LBL_START_OVER)
    EndIf
    ExecWait(N(EVS_ReturnHeldIngredient))
    Set(LVar0, 0)
    Add(LVar0, AF_KKJ19_AddedSugar)
    Add(LVar0, AF_KKJ19_AddedEgg)
    Add(LVar0, AF_KKJ19_AddedNothingWrong)
    IfNe(LVar0, 3)
        Set(AF_KKJ19_FailedBakingTask, TRUE)
    EndIf
    IfEq(AF_KKJ19_FailedBakingTask, FALSE)
        Set(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_MIX)
    EndIf

    // step 2: mix the ingredients
    Label(LBL_MIX_FIRST)
    ExecWait(N(EVS_FocusCam_Twink))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10)
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00D4)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    Wait(10)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(ResetCam, CAM_DEFAULT, Float(2.0))
    Exec(N(EVS_Twink_FlyToHighPos))
    // resume failed step from here
    Label(LBL_MIX_RESUME)
    Set(AB_KKJ19_CurrentBakeStep, BAKE_STEP_MIXING)
    Set(AB_KKJ19_BakeStepProgress, 0)
    Set(AF_KKJ19_CanTakeIngredients, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, LVar0, -74, 0)
    Call(PlayerMoveTo, 287, -74, 0)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00D5)
    Call(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
    ExecGetTID(N(EVS_UpdatePeachMixingAnimations), LVarA)
    Wait(10 * DT)
    Call(SetMusicTrack, 0, SONG_STIRRING_CAKE, 0, 8)
    Call(PlaySound, SOUND_GENERAL_WHISTLE)
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(0.2 / DT), 0, 250, Float(17.0), Float(-7.0))
    EndThread
    Call(N(RunMixingMinigame), MIXING_TIME_IN_FRAMES)
    Call(PlaySound, SOUND_GENERAL_WHISTLE)
    Call(FadeOutMusic, 0, 500)
    KillThread(LVarA)
    IfLt(LVar0, MIXING_REQUIRED_INPUTS)
        Set(AF_KKJ19_FailedBakingTask, TRUE)
    EndIf
    Wait(10 * DT)
    Thread
        Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    EndThread
    Call(NpcFlyTo, NPC_PARTNER, 337, 35, -74, 30 * DT, -5, EASING_LINEAR)
    Wait(10 * DT)
    Exec(N(EVS_SetupMusic))
    ExecWait(N(EVS_FocusCam_PeachAndTwink))
    Thread
        Call(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
        Call(MakeItemEntity, ITEM_CAKE_MIXED, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(AB_KKJ19_CookwareItemIdx, LVar0)
    EndThread
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00D6)
    Call(ShowChoice, MSG_Choice_002B)
    IfEq(LVar0, 0)
        Call(EndSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5)
    Else
        Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00D7)
        Call(ShowChoice, MSG_Choice_002A)
        IfEq(LVar0, 0)
            Call(EndSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5)
        Else
            Goto(LBL_START_OVER)
        EndIf
    EndIf
    IfEq(AF_KKJ19_FailedBakingTask, FALSE)
        Set(AB_KKJ_CompletedBakeStep, CAKE_TYPE_MIXED)
    EndIf

    // step 3: add flour and butter
    Label(LBL_ADD_FLOUR_BUTTER_FIRST)
    ExecWait(N(EVS_FocusCam_Twink))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 5, MSG_Peach_00D8)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    // resume failed step from here
    Label(LBL_ADD_FLOUR_BUTTER_RESUME)
    Set(AB_KKJ19_CurrentBakeStep, BAKE_STEP_ADD_FLOUR_AND_BUTTER)
    Set(AB_KKJ19_BakeStepProgress, 0)
    Set(AF_KKJ19_CanTakeIngredients, TRUE)
    Set(AF_KKJ19_AddedFlour, FALSE)
    Set(AF_KKJ19_AddedButter, FALSE)
    Set(AF_KKJ19_AddedNothingWrong, TRUE)
    Set(LVarA, 1)
    Thread
        ExecWait(N(EVS_Twink_FlyToHighPos))
        Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
        Call(SetNpcVar, NPC_Twink, 1, 1)
    EndThread
    // wait for peach to tell twink shes done
    Label(LBL_ADD_FLOUR_BUTTER_WAITING)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
        IfEq(LVarA, 0)
            Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            Call(SetNpcVar, NPC_Twink, 1, 1)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetNpcVar, NPC_Twink, 0, 1)
        Loop(0)
            Wait(1)
            Call(GetNpcVar, NPC_Twink, 0, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(DisablePlayerInput, TRUE)
        ExecWait(N(EVS_Twink_FlyToPlayer))
        ExecWait(N(EVS_FocusCam_PeachAndTwink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00D9)
        Call(ShowChoice, MSG_Choice_0029)
        IfEq(LVar0, 0)
            IfEq(AB_KKJ19_BakeStepProgress, 0)
                Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00BF)
                Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
                Set(LVarA, 0)
                Goto(LBL_ADD_FLOUR_BUTTER_WAITING)
            Else
                Call(EndSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5)
            EndIf
        EndIf
        IfEq(LVar0, 1)
            Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DA)
            Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
            Set(LVarA, 0)
            Goto(LBL_ADD_FLOUR_BUTTER_WAITING)
        EndIf
        IfEq(LVar0, 2)
            Goto(LBL_START_OVER)
        EndIf
    ExecWait(N(EVS_ReturnHeldIngredient))
    Set(LVar0, 0)
    Add(LVar0, AF_KKJ19_AddedFlour)
    Add(LVar0, AF_KKJ19_AddedButter)
    Add(LVar0, AF_KKJ19_AddedNothingWrong)
    IfNe(LVar0, 3)
        Set(AF_KKJ19_FailedBakingTask, TRUE)
    EndIf
    IfEq(AF_KKJ19_FailedBakingTask, FALSE)
        Set(AB_KKJ_CompletedBakeStep, CAKE_TYPE_READY_TO_BAKE)
    EndIf

    // step 4: baking
    Label(LBL_BAKE_FIRST)
    ExecWait(N(EVS_FocusCam_Twink))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00DB)
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Exec(N(EVS_Twink_FlyToHighPos))
    // resume failed step from here
    Label(LBL_BAKE_RESUME)
    Set(AB_KKJ19_CurrentBakeStep, BAKE_STEP_BAKING)
    Set(AF_KKJ19_CanTakeIngredients, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, LVar0, -74, 0)
    Call(PlayerMoveTo, 287, -74, 0)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
    Wait(10 * DT)
    Call(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
    Call(SetPlayerAnimation, ANIM_Peach2_MixingFull)
    Wait(40 * DT)
    Call(N(SetHeldBakingItem), PEACH_BAKING_CAKE_MIXED)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(10 * DT)
    Thread
        Call(SetNpcSpeed, NPC_PARTNER, Float(2.0 / DT))
        Call(NpcFlyTo, NPC_PARTNER, 337, 35, -74, 0, -5, EASING_LINEAR)
    EndThread
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, 190, -70, 0)
    Call(InterpPlayerYaw, 90, 1)
    Call(PlayerMoveTo, 190, 35, 0)
    Call(PlayerMoveTo, 240, 35, 0)
    Call(InterpPlayerYaw, 350, 5)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach3_PourBatter)
    Wait(20 * DT)
    Call(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    Call(MakeItemEntity, ITEM_CAKE_BATTER, 230, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(AB_KKJ19_CakeItemIdx, LVar0)
    Wait(10 * DT)
    Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(MakeItemEntity, ITEM_CAKE_BOWL, 250, 16, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(AB_KKJ19_CookwareItemIdx, LVar0)
    Wait(40 * DT)
    ExecWait(N(EVS_FocusCam_Twink))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00DC)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Call(InterpPlayerYaw, 315, 0)
    Wait(10)
    Call(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    Call(N(SetHeldBakingItem), PEACH_BAKING_CAKE_BATTER)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(10)
    Exec(N(EVS_FocusCam_Oven))
    Thread
        Call(NpcFlyTo, NPC_PARTNER, 190, 60, -100, 50 * DT, -5, EASING_LINEAR)
    EndThread
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, 190, 30, 0)
    Call(PlayerMoveTo, 190, -100, 0)
    Call(PlayerMoveTo, 125, -100, 0)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DD)
    Call(InterpPlayerYaw, 315, 5)
    Wait(10 * DT)
    Call(N(AwaitPlayerPressATimer))
    ExecWait(N(EVS_OpenOverDoor))
    Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(MakeItemEntity, ITEM_CAKE_BATTER, 100, 5, -135, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(AB_KKJ19_CakeItemIdx, LVar0)
    Set(LVar0, -135)
    Loop(30)
        Sub(LVar0, 1)
        Call(SetItemPos, AB_KKJ19_CakeItemIdx, 100, 5, LVar0)
        Wait(1)
    EndLoop
    ExecWait(N(EVS_CloseOverDoor))
    Wait(10 * DT)
    Call(PlaySoundAt, SOUND_START_OVEN_TIMER, SOUND_SPACE_DEFAULT, 100, 22, -178)
    Wait(20 * DT)
    Call(FadeOutMusic, 0, 500)
    Call(PlaySoundAt, SOUND_OVEN_TIMER_TICKING, SOUND_SPACE_DEFAULT, 100, 22, -178)
    Call(N(AwaitPlayerPressATimer))
    Call(StopSound, SOUND_OVEN_TIMER_TICKING)
    Call(PlaySoundAt, SOUND_DING, SOUND_SPACE_DEFAULT, 100, 22, -178)
    Wait(10 * DT)
    // check baking time
    IfLt(LVar0, BAKING_TIME_MIN_FRAMES)
        Set(AF_KKJ19_FailedBakingTask, TRUE)
    EndIf
    IfGt(LVar0, BAKING_TIME_MAX_FRAMES)
        Set(AF_KKJ19_FailedBakingTask, TRUE)
    EndIf
    Exec(N(EVS_SetupMusic))
    ExecWait(N(EVS_OpenOverDoor))
    Set(LVar0, -165)
    Loop(30)
        Wait(1)
        Add(LVar0, 1)
        Call(SetItemPos, AB_KKJ19_CakeItemIdx, 100, 5, LVar0)
    EndLoop
    Call(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    Call(N(SetHeldBakingItem), PEACH_BAKING_CAKE_BATTER)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    ExecWait(N(EVS_CloseOverDoor))
    Wait(10 * DT)
    Call(InterpPlayerYaw, 90, 5)
    ExecWait(N(EVS_FocusCam_PeachAndTwink))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DE)
    Call(ShowChoice, MSG_Choice_002B)
    IfNe(LVar0, 0)
        Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00DF)
        Call(ShowChoice, MSG_Choice_002A)
        IfNe(LVar0, 0)
            Goto(LBL_START_OVER)
        EndIf
    EndIf
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00E0)
    Call(UseSettingsFrom, CAM_DEFAULT, 287, 0, -74)
    Call(SetPanTarget, CAM_DEFAULT, 287, 0, -74)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Exec(N(EVS_Twink_FlyToHighPos))
    Call(PlayerMoveTo, 287, -74, 100)
    Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(MakeItemEntity, ITEM_CAKE_BATTER, 287, 16, -40, ITEM_SPAWN_MODE_DECORATION, 0)
    Wait(30 * DT)
    Call(RemoveItemEntity, LVar0)
    Call(MakeItemEntity, ITEM_CAKE_BARE, 287, 20, -30, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(AB_KKJ19_CakeItemIdx, LVar0)
    Wait(10 * DT)
    IfEq(AF_KKJ19_FailedBakingTask, FALSE)
        Set(AB_KKJ_CompletedBakeStep, CAKE_TYPE_BAKED)
    EndIf

    // step 5: decorating
    Label(LBL_DECORATE_FIRST)
    ExecWait(N(EVS_FocusCam_Twink))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ReadBook, ANIM_Twink_IdleBook, 0, MSG_Peach_00E1)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_CloseBook)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Set(LVarA, 0)
    // resume failed step from here
    Label(LBL_DECORATE_RESUME)
    Set(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DECORATING)
    Set(AB_KKJ19_BakeStepProgress, 0)
    Set(AF_KKJ19_CanTakeIngredients, TRUE)
    Set(AB_KKJ19_AddedIcing, FALSE)
    Set(AB_KKJ19_AddedBerries, FALSE)
    // wait for peach to tell twink shes done
    Label(LBL_DECORATE_WAITING)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
        IfEq(LVarA, 0)
            Call(SetEnemyFlagBits, NPC_Twink, ENEMY_FLAG_CANT_INTERACT, 0)
            Call(SetNpcVar, NPC_Twink, 1, 1)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetNpcVar, NPC_Twink, 0, 1)
        Loop(0)
            Wait(1)
            Call(GetNpcVar, NPC_Twink, 0, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(DisablePlayerInput, TRUE)
        ExecWait(N(EVS_Twink_FlyToPlayer))
        ExecWait(N(EVS_FocusCam_PeachAndTwink))
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00E2)
        Call(ShowChoice, MSG_Choice_0029)
        IfEq(LVar0, 0)
            // chose 'done'
            IfEq(AB_KKJ19_BakeStepProgress, 0)
                Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00C0)
                Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
                Set(LVarA, 0)
                Goto(LBL_DECORATE_WAITING)
            EndIf
        EndIf
        IfEq(LVar0, 1)
            // chose 'not done'
            Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00E3)
            Call(NpcFlyTo, NPC_PARTNER, 390, 50, -70, 15, -5, EASING_LINEAR)
            Set(LVarA, 0)
            Goto(LBL_DECORATE_WAITING)
        EndIf
        IfEq(LVar0, 2)
            // chose 'start over'
            Goto(LBL_START_OVER)
        EndIf
    ExecWait(N(EVS_ReturnHeldIngredient))
    IfEq(AB_KKJ19_AddedBerries, FALSE)
        Set(AF_KKJ19_FailedBakingTask, TRUE)
    EndIf
    IfEq(AF_KKJ19_FailedBakingTask, FALSE)
        Set(AB_KKJ_CompletedBakeStep, CAKE_TYPE_DONE)
    EndIf
    Call(SetPlayerAnimation, ANIM_Peach2_Delighted)
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_ShoutJoy, ANIM_Twink_ShoutJoy, 0, MSG_Peach_00E4)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)

    // cake ready for gourmet guy (but not necessarily succcesful)
    Label(LBL_FINISHED)
    Set(AB_KKJ19_CurrentBakeStep, BAKE_STEP_DONE)
    Set(AF_KKJ19_CanTakeIngredients, FALSE)
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Exec(N(EVS_BindCakePickup))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return

    // starting over
    Label(LBL_START_OVER)
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_00CD)
    Call(N(FadeScreenToBlack))
    ExecWait(N(EVS_ReturnHeldIngredient))
    Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(RemoveItemEntity, AB_KKJ19_CookwareItemIdx)
    IfNe(AB_KKJ19_CurrentBakeStep, BAKE_STEP_BAKING)
        Call(RemoveItemEntity, AB_KKJ19_CakeItemIdx)
    EndIf
    ExecWait(N(EVS_SetCookwareOnTable))
    Call(SetNpcPos, NPC_PARTNER, 440, 25, -30)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SetPlayerPos, 400, 0, -30)
    Call(InterpPlayerYaw, 90, 0)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, 350, Float(17.0), Float(-7.0))
    Wait(10 * DT)
    Call(N(FadeScreenFromBlack))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00CE)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_00CF)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(ContinueSpeech, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 0, MSG_Peach_00D0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_OpenBook)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_IdleBook)
    Goto(LBL_TRY_RESUME)
    End
};
