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
    Call(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    Call(NpcMoveTo, NPC_TayceT, -186, -381, 20 * DT)
    Call(NpcMoveTo, NPC_TayceT, -220, -425, 30 * DT)
    Call(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Cooking)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Cooking, ANIM_TayceT_Cooking, 5, MSG_MAC_Bridge_000E)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_TurnBack)
    Wait(30 * DT)
    Call(SetNpcYaw, NPC_TayceT, 90)
    Call(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    Call(NpcMoveTo, NPC_TayceT, -186, -381, 20 * DT)
    Call(NpcMoveTo, NPC_TayceT, -236, -318, 20 * DT)
    Call(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Idle)
    Call(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

s32 N(ItemList_FryingPan)[] = {
    ITEM_FRYING_PAN,
    ITEM_NONE
};

EvtScript N(EVS_TayceT_FryingPanAndCake) = {
    IfEq(GF_MAC02_TayceT_HoldingCake, TRUE)
        Call(N(CheckItemsHasRoom), LVar0)
        IfNe(LVar0, 0)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
            EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
            Set(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        Else
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
            Set(GF_MAC02_TayceT_HoldingCake, TRUE)
        EndIf
        Return
    EndIf
    Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0017)
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_FryingPan))
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0018)
        CaseDefault
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_TalkHappy, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0019)
            ExecWait(N(EVS_Scene_TayceTCooking))
            Call(N(CheckItemsHasRoom), LVar0)
            IfNe(LVar0, 0)
                Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
                EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
                Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
                Set(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            Else
                Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
                Set(GF_MAC02_TayceT_HoldingCake, TRUE)
            EndIf
    EndSwitch
    Return
    End
};

s32 N(ItemList_Cookbook)[] = {
    ITEM_COOKBOOK,
    ITEM_NONE
};

EvtScript N(EVS_TayceT_RequestCookbook) = {
    IfEq(AF_MAC_01, FALSE)
        Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001D)
        Set(AF_MAC_01, TRUE)
    Else
        Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001E)
        Set(AF_MAC_01, FALSE)
    EndIf
    Set(LVar0, Ref(N(ItemList_Cookbook)))
    Set(LVar1, 0)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001F)
        CaseDefault
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0020)
            Set(GF_MAC02_TayceT_HasCookbook, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TayceT_Cook) = {
    #define LABEL_CHOOSE_FIRST 1
    #define LABEL_CHOOSE_SECOND 2
    #define LABEL_CONFIRM_ONE 5
    #define LABEL_COOK 6
    #define LABEL_DONE 9

   // greeting and opening choice
    Call(DisablePlayerInput, TRUE)
    IfEq(GF_MAC02_Met_TayceT, FALSE)
        Set(GF_MAC02_Met_TayceT, TRUE)
        Set(AF_MAC_01, TRUE)
        Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0000)
    Else
        IfEq(AF_MAC_01, FALSE)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0001)
            Set(AF_MAC_01, TRUE)
        Else
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0002)
        EndIf
    EndIf
    Call(N(GetItemCount), LVar0)
    IfLe(LVar0, 0)
        Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0003)
        Goto(LABEL_DONE)
    EndIf
    Call(ShowChoice, MSG_Choice_0010)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
        Goto(LABEL_DONE)
    EndIf
    Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0005)

   // choose the first ingredient
    Label(LABEL_CHOOSE_FIRST)
    Set(LVar3, 0)
    Call(N(TayceT_MakeItemList))
    EVT_CHOOSE_CONSUMABLE_FROM(N(TayceT_ItemChoiceList), 0)
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0006)
            Call(ShowChoice, MSG_Choice_0009)
            IfEq(LVar0, 0)
                Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                Goto(LABEL_DONE)
            EndIf
            Call(CloseMessage)
            Set(LVar3, 1)
        CaseDefault
            Set(LVar8, LVar0)
            Call(AddItem, LVar0, LVar1)
    EndSwitch
    IfEq(LVar3, 1)
        Goto(LABEL_CHOOSE_FIRST)
    EndIf
    IfEq(GF_MAC02_TayceT_HasCookbook, FALSE)
        Goto(LABEL_CONFIRM_ONE)
    EndIf
    Call(N(GetItemCount), LVar0)
    IfLt(LVar0, 2)
        Goto(LABEL_CONFIRM_ONE)
    EndIf
    Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0007)
    Call(ShowChoice, MSG_Choice_0010)
    Call(CloseMessage)
    IfEq(LVar0, 1)
        Goto(LABEL_CONFIRM_ONE)
    EndIf

    // choose the second ingredient
    Label(LABEL_CHOOSE_SECOND)
    Call(RemoveItem, LVar8, LVar0)
    Set(LVar3, 0)
    Call(N(TayceT_MakeItemList))
    EVT_CHOOSE_CONSUMABLE_FROM(N(TayceT_ItemChoiceList), 0)
    Call(AddItem, LVar8, LVar1)
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0008)
            Call(ShowChoice, MSG_Choice_0008)
            IfEq(LVar0, 0)
                Call(CloseMessage)
                Goto(LABEL_CONFIRM_ONE)
            EndIf
            IfEq(LVar0, 2)
                Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                Goto(LABEL_DONE)
            EndIf
            Call(CloseMessage)
            Set(LVar3, 1)
        CaseDefault
            Set(LVar9, LVar0)
            Call(AddItem, LVar0, LVar1)
            IfEq(LVar8, LVar9)
                Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0009)
                Set(LVar3, 1)
            EndIf
    EndSwitch
    IfEq(LVar3, 1)
        Goto(LABEL_CHOOSE_SECOND)
    EndIf

    // confirm cooking with two ingredients
    // no label here, but this position would be LABEL_CONFIRM_TWO
    Set(LVar0, LVar8)
    Call(N(GetItemName), LVar0)
    Call(SetMessageText, LVar0, 0)
    Set(LVar1, LVar9)
    Call(N(GetItemName), LVar1)
    Call(SetMessageText, LVar1, 1)
    Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000B)
    Call(ShowChoice, MSG_Choice_0010)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        Goto(LABEL_DONE)
    EndIf
    Call(N(GetCookResultForDoubleRecipe), LVar6, LVar7, LVar8, LVar9)
    Call(RemoveItem, LVar8, LVar0)
    Call(RemoveItem, LVar9, LVar0)
    Goto(LABEL_COOK)

    // confirm cooking with one ingredient
    Label(LABEL_CONFIRM_ONE)
    Set(LVar0, LVar8)
    Call(N(GetItemName), LVar0)
    Call(SetMessageText, LVar0, 0)
    Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000A)
    Call(ShowChoice, MSG_Choice_0010)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        Goto(LABEL_DONE)
    EndIf
    Call(N(GetCookResultForSingleRecipe), LVar6, LVar7, LVar8, GF_MAC02_TayceT_HasCookbook)
    Call(RemoveItem, LVar8, LVar0)

    // the actual cooking animation and reaction message
    Label(LABEL_COOK)
    Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000D)
    ExecWait(N(EVS_Scene_TayceTCooking))
    Switch(LVar7)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0012)
        CaseEq(2)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000F)
        CaseEq(3)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0010)
        CaseEq(4)
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0013)
        CaseDefault
            Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0011)
    EndSwitch
    Call(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0014)
    Call(N(SetRecipeDiscovered), LVar6)
    EVT_GIVE_CONSUMABLE_REWARD_ALT(LVar6)
    Call(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0015)

    // end the script
    Label(LABEL_DONE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_TayceT) = {
    IfGe(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        IfLt(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            ExecWait(N(EVS_TayceT_FryingPanAndCake))
            Return
        EndIf
    EndIf
    Call(FindKeyItem, ITEM_COOKBOOK, LVar0)
    IfEq(LVar0, -1)
        ExecWait(N(EVS_TayceT_Cook))
    Else
        ExecWait(N(EVS_TayceT_RequestCookbook))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_TayceT) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TayceT)))
    Call(InterpNpcYaw, NPC_SELF, 45, 0)
    Call(SetNpcPos, NPC_SELF, -236, 20, -318)
    Call(SetNpcAnimation, NPC_SELF, ANIM_TayceT_Idle)
    IfGe(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        IfLt(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            IfNe(GF_MAC02_TayceT_HoldingCake, TRUE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_TayceT_IdleSad)
                Return
            EndIf
        EndIf
    EndIf
    Set(AF_MAC_01, FALSE)
    Return
    End
};
