// Tacye T cooking implementation.
// Expects Tayce T's NPC ID to be available as enum member NPC_TayceT.

#include "common.h"
#include "gcc/string.h"

typedef struct CookingResult {
    /* 00 */ s32 quality;
    /* 04 */ s32 itemID;
} CookingResult; // size = 0x8

typedef struct ExtraCookingPair {
    /* 00 */ s32 inputA;
    /* 04 */ s32 inputB;
    /* 04 */ s32 output;
} ExtraCookingPair; // size = 0x8

enum CookingResultQuality {
    QUALITY_BAD     = 0,
    QUALITY_OK      = 1,
    QUALITY_GOOD    = 2,
    QUALITY_GREAT   = 3,
    QUALITY_ODD     = 4,
};

#include "recipes.inc.c"

API_CALLABLE(N(GetCookResultForSingleRecipe)) {
    Bytecode* args = script->ptrReadPos;
    s32 hasCookbook;
    s32 inputItem;
    s32 outVarItemID;
    s32 outVarQuality;
    s32 resultItemID;
    s32 resultQuality;
    s32 i;

    outVarItemID = *args++;
    outVarQuality = *args++;
    inputItem = evt_get_variable(script, *args++);
    hasCookbook = evt_get_variable(script, *args++);

    if (inputItem == ITEM_MYSTERY) {
        if (rand_int(1000) < 500) {
            resultItemID = ITEM_MISTAKE;
            resultQuality = 0;
        } else {
            i = rand_int(10000) % ARRAY_COUNT(MysteryResultOptions);
            resultItemID = MysteryResultOptions[i];
            resultQuality = 4;
        }
    } else {
        for (i = 0; i < NUM_INGREDIENTS; i++) {
            if (CookingIngredients[i] == inputItem) {
                break;
            }
        }
        if (i < NUM_INGREDIENTS) {
            if (hasCookbook) {
                i = SingleRecipesWithCookbook[i];
            } else {
                i = SingleRecipesWithoutCookbook[i];
            }
        } else {
            i = 0;
        }
        resultQuality = CookingResults[i].quality;
        resultItemID = CookingResults[i].itemID;
    }
    evt_set_variable(script, outVarItemID, resultItemID);
    evt_set_variable(script, outVarQuality, resultQuality);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetCookResultForDoubleRecipe)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVarItemID = *args++;
    s32 outVarQuality = *args++;
    s32 inputItemA = evt_get_variable(script, *args++);
    s32 inputItemB = evt_get_variable(script, *args++);
    ExtraCookingPair* extraList;
    s32 resultItemID, resultQuality;
    s32 inputIdxA, inputIdxB;
    s32 recipeIdx;
    s32 resultIdx;
    s32 i;

    // get ingredient enum values
    for (inputIdxA = 0; inputIdxA < NUM_INGREDIENTS; inputIdxA++) {
        if (CookingIngredients[inputIdxA] == inputItemA) {
            break;
        }
    }
    for (inputIdxB = 0; inputIdxB < NUM_INGREDIENTS; inputIdxB++) {
        if (CookingIngredients[inputIdxB] == inputItemB) {
            break;
        }
    }
    // check the recipe matrix
    resultIdx = 0;
    if ((inputIdxA < NUM_INGREDIENTS) && (inputIdxB < NUM_INGREDIENTS)) {
        if (inputIdxA < inputIdxB) {
            recipeIdx = inputIdxB + (inputIdxA * NUM_INGREDIENTS);
        } else {
            recipeIdx = inputIdxA + (inputIdxB * NUM_INGREDIENTS);
        }
        resultIdx = DoubleRecipesMatrix[recipeIdx];
    }
    if (resultIdx < 0) {
        resultIdx = 0;
    }
    // if the matrix was mistake or not in range, check the extra recipes
    if (resultIdx == 0) {
        for (i = 0; i < ARRAY_COUNT(ExtraDoubleRecipes); i++) {
            if (((ExtraDoubleRecipes[i].inputA == inputItemA) && (ExtraDoubleRecipes[i].inputB == inputItemB))
             || ((ExtraDoubleRecipes[i].inputA == inputItemB) && (ExtraDoubleRecipes[i].inputB == inputItemA))) {
                resultIdx = ExtraDoubleRecipes[i].output;
            }
        }
    }
    resultItemID = CookingResults[resultIdx].itemID;
    resultQuality = CookingResults[resultIdx].quality;
    evt_set_variable(script, outVarItemID, resultItemID);
    evt_set_variable(script, outVarQuality, resultQuality);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRecipeDiscovered)) {
    s32 cookedItems[ARRAY_COUNT(CookableItemIDs)];
    s32 cookedFlags[ARRAY_COUNT(CookableDiscoveredFlags)];
    s32 cookedItemID;
    s32 i;

    cookedItemID = evt_get_variable(script, *script->ptrReadPos);
    memcpy(cookedItems, CookableItemIDs, sizeof(CookableItemIDs));
    memcpy(cookedFlags, CookableDiscoveredFlags, sizeof(CookableDiscoveredFlags));

    for (i = 0; i < ARRAY_COUNT(CookableItemIDs); i++) {
        if (cookedItemID == cookedItems[i]) {
            evt_set_variable(NULL, cookedFlags[i], TRUE);
            break;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetItemCount)) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_count());
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckItemsHasRoom)) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_empty_count());
    return ApiStatus_DONE2;
}

static s32 N(TayceT_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];

API_CALLABLE(N(TayceT_MakeItemList)) {
    s32 i;

    for (i = 0; i < ITEM_NUM_CONSUMABLES; i++) {
        N(TayceT_ItemChoiceList)[i] = i + ITEM_FIRST_CONSUMABLE;
    }
    N(TayceT_ItemChoiceList)[i] = ITEM_NONE;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_TayceTCooking) = {
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -220, -425, 30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Cooking)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Cooking, ANIM_TayceT_Cooking, 5, MSG_MAC_Bridge_000E)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_TurnBack)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcYaw, NPC_TayceT, 90)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -236, -318, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_FryingPan)[] = {
    ITEM_FRYING_PAN,
    ITEM_NONE
};

EvtScript N(EVS_TayceT_FryingPanAndCake) = {
    EVT_IF_EQ(GF_MAC02_TayceT_HoldingCake, TRUE)
        EVT_CALL(N(CheckItemsHasRoom), LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
            EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
            EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
            EVT_SET(GF_MAC02_TayceT_HoldingCake, TRUE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0017)
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_FryingPan))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0018)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_TalkHappy, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0019)
            EVT_EXEC_WAIT(N(EVS_Scene_TayceTCooking))
            EVT_CALL(N(CheckItemsHasRoom), LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
                EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
                EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
                EVT_SET(GF_MAC02_TayceT_HoldingCake, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Cookbook)[] = {
    ITEM_COOKBOOK,
    ITEM_NONE
};

EvtScript N(EVS_TayceT_RequestCookbook) = {
    EVT_IF_EQ(AF_MAC_01, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001D)
        EVT_SET(AF_MAC_01, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001E)
        EVT_SET(AF_MAC_01, FALSE)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Cookbook)))
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001F)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0020)
            EVT_SET(GF_MAC02_TayceT_HasCookbook, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TayceT_Cook) = {
    #define LABEL_CHOOSE_FIRST 1
    #define LABEL_CHOOSE_SECOND 2
    #define LABEL_CONFIRM_ONE 5
    #define LABEL_COOK 6
    #define LABEL_DONE 9

   // greeting and opening choice
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_MAC02_Met_TayceT, FALSE)
        EVT_SET(GF_MAC02_Met_TayceT, TRUE)
        EVT_SET(AF_MAC_01, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0000)
    EVT_ELSE
        EVT_IF_EQ(AF_MAC_01, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0001)
            EVT_SET(AF_MAC_01, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0002)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(GetItemCount), LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0003)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0005)

   // choose the first ingredient
    EVT_LABEL(LABEL_CHOOSE_FIRST)
    EVT_SET(LVar3, 0)
    EVT_CALL(N(TayceT_MakeItemList))
    EVT_CHOOSE_CONSUMABLE_FROM(N(TayceT_ItemChoiceList), 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0006)
            EVT_CALL(ShowChoice, MSG_Choice_0009)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                EVT_GOTO(LABEL_DONE)
            EVT_END_IF
            EVT_CALL(CloseMessage)
            EVT_SET(LVar3, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar8, LVar0)
            EVT_CALL(AddItem, LVar0, LVar1)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar3, 1)
        EVT_GOTO(LABEL_CHOOSE_FIRST)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC02_TayceT_HasCookbook, FALSE)
        EVT_GOTO(LABEL_CONFIRM_ONE)
    EVT_END_IF
    EVT_CALL(N(GetItemCount), LVar0)
    EVT_IF_LT(LVar0, 2)
        EVT_GOTO(LABEL_CONFIRM_ONE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0007)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_CALL(CloseMessage)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(LABEL_CONFIRM_ONE)
    EVT_END_IF

    // choose the second ingredient
    EVT_LABEL(LABEL_CHOOSE_SECOND)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_SET(LVar3, 0)
    EVT_CALL(N(TayceT_MakeItemList))
    EVT_CHOOSE_CONSUMABLE_FROM(N(TayceT_ItemChoiceList), 0)
    EVT_CALL(AddItem, LVar8, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0008)
            EVT_CALL(ShowChoice, MSG_Choice_0008)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(CloseMessage)
                EVT_GOTO(LABEL_CONFIRM_ONE)
            EVT_END_IF
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                EVT_GOTO(LABEL_DONE)
            EVT_END_IF
            EVT_CALL(CloseMessage)
            EVT_SET(LVar3, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar9, LVar0)
            EVT_CALL(AddItem, LVar0, LVar1)
            EVT_IF_EQ(LVar8, LVar9)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0009)
                EVT_SET(LVar3, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_EQ(LVar3, 1)
        EVT_GOTO(LABEL_CHOOSE_SECOND)
    EVT_END_IF

    // confirm cooking with two ingredients
    // no label here, but this position would be LABEL_CONFIRM_TWO
    EVT_SET(LVar0, LVar8)
    EVT_CALL(N(GetItemName), LVar0)
    EVT_CALL(SetMessageText, LVar0, 0)
    EVT_SET(LVar1, LVar9)
    EVT_CALL(N(GetItemName), LVar1)
    EVT_CALL(SetMessageText, LVar1, 1)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000B)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(N(GetCookResultForDoubleRecipe), LVar6, LVar7, LVar8, LVar9)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_CALL(RemoveItem, LVar9, LVar0)
    EVT_GOTO(LABEL_COOK)

    // confirm cooking with one ingredient
    EVT_LABEL(LABEL_CONFIRM_ONE)
    EVT_SET(LVar0, LVar8)
    EVT_CALL(N(GetItemName), LVar0)
    EVT_CALL(SetMessageText, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000A)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(N(GetCookResultForSingleRecipe), LVar6, LVar7, LVar8, GF_MAC02_TayceT_HasCookbook)
    EVT_CALL(RemoveItem, LVar8, LVar0)

    // the actual cooking animation and reaction message
    EVT_LABEL(LABEL_COOK)
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000D)
    EVT_EXEC_WAIT(N(EVS_Scene_TayceTCooking))
    EVT_SWITCH(LVar7)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0012)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000F)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0010)
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0013)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0011)
    EVT_END_SWITCH
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0014)
    EVT_CALL(N(SetRecipeDiscovered), LVar6)
    EVT_GIVE_CONSUMABLE_REWARD_ALT(LVar6)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0015)

    // end the script
    EVT_LABEL(LABEL_DONE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TayceT) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_EXEC_WAIT(N(EVS_TayceT_FryingPanAndCake))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_COOKBOOK, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_EXEC_WAIT(N(EVS_TayceT_Cook))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_TayceT_RequestCookbook))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TayceT) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TayceT)))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 45, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, -236, 20, -318)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_Idle)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_IF_NE(GF_MAC02_TayceT_HoldingCake, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_IdleSad)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_MAC_01, FALSE)
    EVT_RETURN
    EVT_END
};
