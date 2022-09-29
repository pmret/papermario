#include "common.h"

//TODO remove
extern s32 N(LetterDelivery_SavedNpcAnim);

s32** N(varStash) = NULL;

//TODO temporarily moved from #include "world/common/StashVars.inc.c" to suppresse warnings
ApiStatus N(StashVars)(Evt* script, s32 isInitialCall) {
    //static s32** varTable = NULL;
    s32 i;

    if (N(varStash) == NULL) {
        N(varStash) = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            N(varStash)[i] = (s32*) script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = (s32) N(varStash)[i];
        }

        heap_free(N(varStash));
        N(varStash) = NULL;
    }

    return ApiStatus_DONE2;
}


EvtScript N(Delivery_ShowGotStarPiece) = {
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244A44) = {
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0x10)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

static s32 N(KeyItemChoiceList)[ITEM_NUM_KEYS + 2];
//static s32 N(LetterDelivery_SavedNpcAnim);

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

s32 N(HasLetterChoiceResult) = FALSE;
s32 N(LetterChoiceResult) = ITEM_NONE;

ApiStatus N(AwaitLetterChoiceResult)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(HasLetterChoiceResult) = FALSE;
    }

    if (N(HasLetterChoiceResult)) {
        N(HasLetterChoiceResult) = FALSE;
        evt_set_variable(script, *args++, N(LetterChoiceResult));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(SetLetterChoiceResult)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(LetterChoiceResult) = evt_get_variable(script, *args++);
    N(HasLetterChoiceResult) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(BuildKeyItemChoiceList)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != ITEM_NONE; i++) {
            N(KeyItemChoiceList)[i] = allowedItemList[i];
        }
        N(KeyItemChoiceList)[i] = ITEM_NONE;
    } else {
        for (i = 0; i < ITEM_NUM_KEYS; i++) {
            N(KeyItemChoiceList)[i] = ITEM_FIRST_KEY + i;
            N(KeyItemChoiceList)[ITEM_NUM_KEYS] = ITEM_NONE; // vanilla oddity -- should be after the loop!
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_Init)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->varTable[2] = evt_get_variable(script, *args++);
    script->varTable[3] = evt_get_variable(script, *args++);
    script->varTable[4] = evt_get_variable(script, *args++);
    script->varTable[5] = evt_get_variable(script, *args++);
    script->varTable[6] = evt_get_variable(script, *args++);
    script->varTable[7] = evt_get_variable(script, *args++);
    script->varTable[8] = evt_get_variable(script, *args++);
    script->varTable[9] = evt_get_variable(script, *args++);
    script->varTable[10] = evt_get_variable(script, *args++);
    script->varTable[11] = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_CalcLetterPos)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 varX = *args++;
    f32 x = evt_get_variable(script, varX);
    s32 varY = *args++;
    f32 y = evt_get_variable(script, varY);
    s32 varZ = *args++;
    f32 z = evt_get_variable(script, varZ);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    f32 currentCamYaw = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);

    add_vec2D_polar(&x, &z, 15.0f, partner->yaw);
    add_vec2D_polar(&x, &z, 10.0f, currentCamYaw);

    evt_set_variable(script, varX, x);
    evt_set_variable(script, varY, y);
    evt_set_variable(script, varZ, z);

    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_SaveNpcAnim)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    N(LetterDelivery_SavedNpcAnim) = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_RestoreNpcAnim)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    npc->currentAnim = N(LetterDelivery_SavedNpcAnim);
    return ApiStatus_DONE2;
}

EvtScript N(D_802452BC_C7BF9C) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_BITWISE_OR_CONST(LVar0, 0x00050000)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_SWITCH
    EVT_CALL(N(SetLetterChoiceResult), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

// unused
EvtScript N(EVS_80245400) = {
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(D_802452BC_C7BF9C), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(AwaitLetterChoiceResult), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245450_C7C130) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        EVT_CALL(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
        EVT_CALL(SetItemPos, LVar0, LVar3, LVar4, LVar5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802454D0_C7C1B0) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            EVT_CALL(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
            EVT_BITWISE_OR_CONST(LVar0, 0x00050000)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_EXEC_GET_TID(N(D_80245450_C7C130), LVarA)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Walk)
            EVT_CALL(GetAngleBetweenNPCs, LVar9, NPC_PARTNER, LVarB)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            EVT_CALL(GetNpcPos, LVar9, LVar6, LVar7, LVar8)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, TRUE)
            EVT_IF_LE(LVarB, 180)
                EVT_ADD(LVar6, 20)
            EVT_ELSE
                EVT_ADD(LVar6, -20)
            EVT_END_IF
            EVT_ADD(LVar7, 10)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
            EVT_CALL(NpcJump1, NPC_PARTNER, LVar6, LVar7, LVar8, 20)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(RemoveItemEntity, LVar0)
            EVT_WAIT(20)
            EVT_CALL(GetNpcYaw, NPC_PARTNER, LVarA)
            EVT_ADD(LVarA, 180)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
            EVT_WAIT(5)
            EVT_CALL(NpcJump1, NPC_PARTNER, LVar3, LVar4, LVar5, 20)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Idle)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, LVar9, 0)
            EVT_WAIT(5)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_WAIT(5)
    EVT_END_SWITCH
    EVT_CALL(N(SetLetterChoiceResult), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802457F4_C7C4D4) = {
    EVT_SET(LVar0, LVarB)
    EVT_SET(LVar1, LVar2)
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(D_802454D0_C7C1B0), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(AwaitLetterChoiceResult), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(DoLetterDelivery) = {
    EVT_SET(LVarC, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_PARAKARRY_JOINED_PARTY)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(LetterDelivery_SaveNpcAnim))
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(FindKeyItem, LVar5, LVar1)
    EVT_IF_EQ(LVar0, PARTNER_PARAKARRY)
        EVT_IF_NE(LVar1, -1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(PlayerFaceNpc, LVar2, FALSE)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, LVar2, LVarD, LVar0, LVarE)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVarD, LVarE, LVarF)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
            EVT_ADD(LVar0, 10)
            EVT_CALL(NpcJump1, NPC_PARTNER, LVarD, LVar0, LVarF, 10)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, LVar2, LVar7)
            EVT_CALL(EnablePartnerAI)
            EVT_EXEC_WAIT(N(D_802457F4_C7C4D4))
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(-1)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar8)
                    EVT_CALL(EnablePartnerAI)
                    EVT_SET(LVarC, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar9)
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(SpeakToPlayer, LVar2, LVar3, LVar4, 0, LVarA)
                    EVT_END_IF
                    EVT_CALL(EnablePartnerAI)
                    EVT_IF_NE(LVar6, 0)
                        EVT_SET(LVar0, LVar6)
                        EVT_SET(LVar1, 1)
                        EVT_EXEC_WAIT(N(Delivery_ShowGotStarPiece))
                        EVT_CALL(AddKeyItem, LVar6)
                    EVT_END_IF
                    EVT_SET(LVarC, 2)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(LetterDelivery_RestoreNpcAnim))
    EVT_RETURN
    EVT_END
};
