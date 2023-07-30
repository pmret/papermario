#include "common.h"
#include "sprite/npc/WorldParakarry.h"

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"

enum DeliveryResult {
    DELIVERY_NOT_POSSIBLE   = 0,
    DELIVERY_REJECTED       = 1,
    DELIVERY_ACCEPTED       = 2,
};

BSS s32 N(LetterDelivery_SavedNpcAnim);

API_CALLABLE(N(LetterDelivery_Init)) {
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

API_CALLABLE(N(LetterDelivery_CalcLetterPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 varX = *args++;
    f32 x = evt_get_variable(script, varX);
    s32 varY = *args++;
    f32 y = evt_get_variable(script, varY);
    s32 varZ = *args++;
    f32 z = evt_get_variable(script, varZ);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    f32 currentCamYaw = clamp_angle(gCameras[gCurrentCameraID].curYaw + 180.0f);

    add_vec2D_polar(&x, &z, 15.0f, partner->yaw);
    add_vec2D_polar(&x, &z, 10.0f, currentCamYaw);

    evt_set_variable(script, varX, x);
    evt_set_variable(script, varY, y);
    evt_set_variable(script, varZ, z);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(LetterDelivery_SaveNpcAnim)) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    N(LetterDelivery_SavedNpcAnim) = npc->curAnim;
    npc->curAnim = script->varTable[4];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(LetterDelivery_RestoreNpcAnim)) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    npc->curAnim = N(LetterDelivery_SavedNpcAnim);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_LetterDelivery_CarryLetter) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        EVT_CALL(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
        EVT_CALL(SetItemPos, LVar0, LVar3, LVar4, LVar5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterDelivery_ItemPrompt) = {
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
            EVT_BITWISE_OR_CONST(LVar0, VIS_GROUP_5 << 16)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_EXEC_GET_TID(N(EVS_LetterDelivery_CarryLetter), LVarA)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Walk)
            EVT_CALL(GetAngleBetweenNPCs, LVar9, NPC_PARTNER, LVarB)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            EVT_CALL(GetNpcPos, LVar9, LVar6, LVar7, LVar8)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
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
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_WAIT(5)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowLetterChoice) = {
    EVT_SET(LVar0, LVarB)
    EVT_SET(LVar1, LVar2)
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(EVS_LetterDelivery_ItemPrompt), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

// returns DeliveryResult on LVarC
EvtScript N(EVS_DoLetterDelivery) = {
    EVT_SET(LVarC, DELIVERY_NOT_POSSIBLE)
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
            EVT_EXEC_WAIT(N(EVS_ShowLetterChoice))
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(-1)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar8)
                    EVT_CALL(EnablePartnerAI)
                    EVT_SET(LVarC, DELIVERY_REJECTED)
                EVT_CASE_DEFAULT
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar9)
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(SpeakToPlayer, LVar2, LVar3, LVar4, 0, LVarA)
                    EVT_END_IF
                    EVT_CALL(EnablePartnerAI)
                    EVT_IF_NE(LVar6, ITEM_NONE)
                        EVT_GIVE_KEY_REWARD(LVar6)
                    EVT_END_IF
                    EVT_SET(LVarC, DELIVERY_ACCEPTED)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(LetterDelivery_RestoreNpcAnim))
    EVT_RETURN
    EVT_END
};

#define EVT_LETTER_PROMPT(npcName, npcID, animTalk, animIdle, msg1, msg2, ms3, msg4, itemID, itemList) \
    EvtScript N(EVS_LetterPrompt_##npcName) = { \
        EVT_CALL(N(LetterDelivery_Init), \
            npcID, animTalk, animIdle, \
            itemID, ITEM_NONE, \
            msg1, msg2, ms3, msg4, \
            EVT_PTR(itemList)) \
        EVT_EXEC_WAIT(N(EVS_DoLetterDelivery)) \
        EVT_RETURN \
        EVT_END \
    }

#define EVT_LETTER_REWARD(npcName) \
    EvtScript N(EVS_LetterReward_##npcName) = { \
        EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED) \
            EVT_GIVE_STAR_PIECE() \
        EVT_END_IF \
        EVT_RETURN \
        EVT_END \
    }

#define EVT_LETTER_CHECK(npcName) \
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_##npcName)) \
    EVT_EXEC_WAIT(N(EVS_LetterReward_##npcName))
