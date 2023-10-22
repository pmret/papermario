#include "mac_05.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Whale) = {
    .height = 24,
    .radius = 48,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Kolorado.inc.c"

NpcSettings N(NpcSettings_JrTroopa_01) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

NpcSettings N(NpcSettings_Unused1) = {
    .height = 48,
    .radius = 32,
    .level = ACTOR_LEVEL_NONE,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(Fishmael_LetterList)[] = {
    ITEM_LETTER_CHAIN_FISHMAEL, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Fishmael) = {
    EVT_CALL(N(LetterDelivery_Init), NPC_Fishmael,
        ANIM_Fishmael_Talk, ANIM_Fishmael_Idle,
        ITEM_LETTER_CHAIN_FISHMAEL, ITEM_LETTER_CHAIN_KOOVER_2,
        MSG_MAC_Port_0064, MSG_MAC_Port_0065,
        MSG_MAC_Port_0066, MSG_MAC_Port_0067,
        EVT_PTR(N(Fishmael_LetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(Kolorado_LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    EVT_CALL(N(LetterDelivery_Init), NPC_Kolorado,
        ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_MAC_Port_0085, MSG_MAC_Port_0086,
        MSG_MAC_Port_0087, MSG_MAC_Port_0088,
        EVT_PTR(N(Kolorado_LetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Artifact)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactReward_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008E)
    EVT_GIVE_STAR_PIECE()
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008F)
    EVT_SET(GF_SBK_GaveArtifactToKolorado, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ArtifactPrompt_Kolorado) = {
    EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_ARTIFACT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_MAC_44, FALSE)
        EVT_SET(AF_MAC_44, TRUE)
        EVT_IF_EQ(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(LVar0, MSG_MAC_Port_0089)
        EVT_ELSE
            EVT_SET(LVar0, MSG_MAC_Port_008A)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Port_008B)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Artifact)))
    EVT_SET(LVar1, 1)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_GE(1)
            EVT_EXEC_WAIT(N(EVS_ArtifactReward_Kolorado))
            EVT_BREAK_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008C)
            EVT_SET(LVar0, EVT_PTR(N(ItemList_Artifact)))
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
            EVT_SWITCH(LVar0)
                EVT_CASE_GE(1)
                    EVT_EXEC_WAIT(N(EVS_ArtifactReward_Kolorado))
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008D)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_80242A90_854C00)) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    s32 outVarX = *args++;
    s32 outVarY = *args++;
    s32 outVarZ = *args++;
    Npc* npc = get_npc_safe(NPC_Whale);
    f32 posX, posY, posZ;
    f32 radius, angle;

    switch (mode) {
        case 0:
            radius = 55.0f;
            break;
        case 1:
            radius = 85.0f;
            break;
        case 2:
            radius = 25.0f;
            break;
        case 3:
            posX = -295.0f;
            posY = -10.0f;
            posZ = 400.0f;
            break;
        case 4:
            posX = -285.0f;
            posY = -10.0f;
            posZ = 380.0f;
            break;
        default:
            posX = -295.0f;
            posY = -10.0f;
            posZ = 420.0f;
            break;
    }
    if (mode < 3) {
        angle = -npc->yaw;
        posX = npc->pos.x + 30.0f + sin_deg(angle) * radius;
        posZ = npc->pos.z + cos_deg(angle) * radius;
        posY = npc->pos.y + 50.0f;
    }
    evt_set_float_variable(script, outVarX, posX);
    evt_set_float_variable(script, outVarY, posY);
    evt_set_float_variable(script, outVarZ, posZ);
    return ApiStatus_DONE2;
}

// maybe a duplicate, not sure if the NPCs are the same
API_CALLABLE(N(func_80242C78_854DE8)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc0 = get_npc_safe(NPC_Whale);
    Npc* npc1;
    Npc* partner;
    f32 forward, radius;
    f32 x, y, z;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        switch (script->functionTemp[0]) {
            case 0:
                script->functionTemp[1] = 55;
                break;
            case 1:
                script->functionTemp[1] = 85;
                break;
            default:
                script->functionTemp[1] = 25;
               break;
        }
    }

    radius = script->functionTemp[1];
    forward = -npc0->yaw;
    x = npc0->pos.x + 30.0f + sin_deg(forward) * radius;
    z = npc0->pos.z + cos_deg(forward) * radius;
    y = npc0->pos.y + 50.0f;

    switch (script->functionTemp[0]) {
        case 0:
            gPlayerStatus.pos.x = x;
            gPlayerStatus.pos.y = y;
            gPlayerStatus.pos.z = z;
            npc0->colliderPos.x = npc0->pos.x;
            npc0->colliderPos.y = npc0->pos.y;
            npc0->colliderPos.z = npc0->pos.z;
            npc0->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
        case 1:
            partner = get_npc_safe(NPC_PARTNER);
            if (partner == NULL) {
                return ApiStatus_DONE2;
            }
            partner->pos.x = x;
            partner->pos.y = y;
            partner->pos.z = z;
            partner->colliderPos.x = partner->pos.x;
            partner->colliderPos.y = partner->pos.y;
            partner->colliderPos.z = partner->pos.z;
            partner->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
        case 2:
            npc1 = get_npc_safe(NPC_Kolorado);
            npc1->pos.x = x;
            npc1->pos.y = y;
            npc1->pos.z = z;
            npc1->colliderPos.x = npc1->pos.x;
            npc1->colliderPos.y = npc1->pos.y;
            npc1->colliderPos.z = npc1->pos.z;
            npc1->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80242E84_854FF4)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(NPC_Whale);

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        if (script->functionTemp[0] == 0) {
            script->functionTemp[2] = 0;
            script->functionTemp[1] = 90;
        } else {
            script->functionTemp[2] = 10;
            script->functionTemp[1] = 290;
            npc->pos.x = 650.0f;
            npc->pos.y = -30.0f;
            npc->pos.z = 372.0f;
        }
    }

    switch (script->functionTemp[2]) {
        case 0:
            npc->curAnim = ANIM_Kolorado_Idle;
            npc->yaw -= 1.0f;
            npc->pos.x += 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 1;
                script->functionTemp[1] = 200;
            }
            break;
        case 1:
            if (evt_get_variable(NULL, MF_Unk_01)) {
                npc->pos.x += 3.0f;
                script->functionTemp[1]--;
                if (script->functionTemp[1] <= 0) {
                    return ApiStatus_DONE1;
                }
            }
            break;
        case 10:
            npc->yaw = 270.0f;
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 11;
                script->functionTemp[1] = 90;
            }
            break;
        case 11:
            npc->yaw -= 1.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                return ApiStatus_DONE1;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(D_802484D8_85A648) = {
    EVT_CALL(N(func_80242C78_854DE8), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802484F8_85A668) = {
    EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_ELSE
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 100)
            EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_ELSE
            EVT_SET(LVar3, LVar0)
            EVT_SUB(LVar3, 100)
            EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, LVar3)
            EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802486EC_85A85C) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar4, LVar4)
        EVT_IF_GT(LVar0, -150)
            EVT_CALL(GetPlayerPos, LVar0, LVar4, LVar4)
            EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_ELSE
            EVT_SET(LVar3, LVar0)
            EVT_SUB(LVar3, -150)
            EVT_CALL(GetPlayerPos, LVar0, LVar4, LVar4)
            EVT_SUB(LVar0, LVar3)
            EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar4, LVar4)
            EVT_IF_LT(LVar0, -150)
                EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_ELSE
                EVT_CALL(SetCamTarget, CAM_DEFAULT, -150, LVar1, LVar2)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80248878) = {
    EVT_SET(GB_StoryProgress, STORY_CH5_DEFEATED_FUZZIPEDE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -120, 24, 375)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_009F)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Shout)
    EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 475)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_CALL(SetPlayerPos, -120, 24, 375)
        EVT_CALL(PlaySoundAtPlayer, SOUND_WHALE_EJECT, SOUND_SPACE_DEFAULT)
        EVT_CALL(PlayerJump1, -310, -10, 372, 80)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -120, 24, 375)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_WHALE_EJECT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_PARTNER, -345, 0, 372, 80)
        EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcPos, NPC_Fuzzipede, -120, 24, 375)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzipede, EVT_FLOAT(0.5))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzipede, SOUND_WHALE_EJECT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzipede, -280, -10, 372, 90)
        EVT_CALL(NpcFaceNpc, NPC_Fuzzipede, NPC_Whale, 0)
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetNpcJumpscale, NPC_Kolorado, EVT_FLOAT(0.1))
        EVT_CALL(NpcJump0, NPC_Kolorado, -380, -10, 372, 20)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
    EVT_WAIT(60)
    EVT_CALL(NpcFacePlayer, NPC_Kolorado, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Fuzzipede, 0)
    EVT_CALL(NpcFaceNpc, NPC_Fuzzipede, NPC_Whale, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Fuzzipede, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(GetNpcPos, NPC_Fuzzipede, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 5, MSG_MAC_Port_00A0)
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00A1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 475)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-63.5), 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-5.0))
    EVT_CALL(SpeakToNpc, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, NPC_Whale, MSG_MAC_Port_00A2)
    EVT_CALL(NpcFacePlayer, NPC_Fuzzipede, 0)
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzipede, 1)
    EVT_CALL(GetNpcPos, NPC_Fuzzipede, LVar0, LVar1, LVar2)
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_LOOP(10)
        EVT_ADD(LVar2, -60)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzipede, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzipede, LVar0, LVar1, LVar2, 10)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Fuzzipede, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Fuzzipede, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Fuzzipede, FALSE)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Fuzzipede, NPC_DISPOSE_LOCATION)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00A3)
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-7.0))
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFacePlayer, NPC_Kolorado, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kolorado, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_00A4)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_PARTNER, 0)
        EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Port_00A5)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_MAC_Port_00A6)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_MAC_Port_00A7)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_MAC_Port_00A8)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_MAC_Port_00A9)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_MAC_Port_00AA)
    EVT_END_SWITCH
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 475)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-63.5), 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-5.0))
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00AB)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
    EVT_THREAD
        EVT_WAIT(100)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802496C0_85B830) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fall)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802496FC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(D_802484F8_85A668), LVarA)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_SET(LVar0, 0)
    EVT_EXEC_GET_TID(N(D_802484D8_85A648), LVarB)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(D_802484D8_85A648), LVarC)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_SET(LVar0, 2)
        EVT_EXEC_GET_TID(N(D_802484D8_85A648), LVarD)
    EVT_END_IF
    EVT_CALL(N(func_80242E84_854FF4), 2)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_KILL_THREAD(LVarD)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt9, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Run)
        EVT_CALL(N(func_80242A90_854C00), 5, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_Kolorado, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcJumpscale, NPC_Kolorado, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_Kolorado, LVar0, LVar1, LVar2, 20)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
    EVT_END_IF
    EVT_CALL(N(func_80242A90_854C00), 3, LVar0, LVar1, LVar2)
    EVT_EXEC(N(D_802496C0_85B830))
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_CALL(N(func_80242A90_854C00), 4, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tt9, COLLIDER_FLAGS_UPPER_MASK)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_TalkSad)
    EVT_CALL(InterpNpcYaw, NPC_Whale, 270, 60)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Whale, 0)
        EVT_CALL(NpcJump0, NPC_Whale, -220, 10, 372, 20)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_SUSHIE_JOINED_PARTY, STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_Defeated_JrTroopa4, FALSE)
                EVT_CALL(SetNpcVar, NPC_JrTroopa_01, 0, 1)
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH5_TRADED_VASE_FOR_SEED)
            EVT_CALL(SetNpcVar, NPC_Kolorado, 0, 1)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80249C34_85BDA4) = {
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_CALL(PlayerJump1, -310, -10, 372, 30)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, -345, -10, 372, 30)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80249D80_85BEF0) = {
    EVT_WAIT(20)
    EVT_CALL(PlayerMoveTo, -285, 485, 40)
    EVT_CALL(PlayerMoveTo, -310, 372, 20)
    EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, -345, 372, 30)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/GetFloorCollider.inc.c"

API_CALLABLE(N(func_802430B4_855224)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(-4);
    s32 outVal = -1;

    if (gCollisionStatus.bombetteExploded >= 0) {
        f32 temp = 11.0f;
        f32 x = npc->pos.x;
        f32 y = npc->pos.y + temp;
        f32 z = npc->pos.z;

        temp = 12.0f;
        if (npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &temp, npc->yaw, npc->collisionDiameter) &&
            temp <= 12.0f)
        {
            outVal = NpcHitQueryColliderID;
        }
    }
    evt_set_variable(script, *args++, outVal);
    return ApiStatus_DONE2;
}

EvtScript N(D_80249E84_85BFF4) = {
    EVT_SET(LVarA, 0)
    EVT_LOOP(0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_EQ(LVar0, 29)
            EVT_SET(LVar5, 0)
            EVT_CALL(GetPlayerActionState, LVar1)
            EVT_IF_EQ(LVar1, ACTION_STATE_HAMMER)
                EVT_ADD(LVar5, 1)
            EVT_END_IF
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_CALL(GetPlayerTargetYaw, LVar3)
            EVT_IF_LT(LVar3, 180)
                EVT_IF_GT(LVar2, -60)
                    EVT_ADD(LVar5, 1)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_GT(LVar2, -40)
                    EVT_ADD(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LVar5, 2)
                EVT_IF_EQ(LVarA, 2)
                    EVT_SET(LFlag0, TRUE)
                    EVT_RETURN
                EVT_ELSE
                    EVT_CALL(DisablePlayerInput, TRUE)
                    EVT_LOOP(0)
                        EVT_WAIT(1)
                        EVT_CALL(GetPlayerActionState, LVar1)
                        EVT_IF_EQ(LVar1, ACTION_STATE_IDLE)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                    EVT_WAIT(10)
                    EVT_THREAD
                        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
                        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
                        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
                        EVT_CALL(PlayerJump1, LVar2, LVar3, LVar4, 10)
                        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                    EVT_END_THREAD
                    EVT_CALL(PlaySoundAt, SOUND_WHALE_JIGGLE, SOUND_SPACE_DEFAULT, 0, 0, 480)
                    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Panic)
                    EVT_WAIT(10)
                    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
                    EVT_CALL(DisablePlayerInput, FALSE)
                    EVT_ADD(LVarA, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LVar1, ACTION_STATE_SPIN_POUND)
                EVT_SET(LFlag0, TRUE)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(func_802430B4_855224), LVar2)
        EVT_IF_EQ(LVar2, 29)
            EVT_IF_EQ(LVar0, 29)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A1F8_85C368) = {
    EVT_EXEC_WAIT(N(D_80249E84_85BFF4))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAt, SOUND_WHALE_JIGGLE, SOUND_SPACE_DEFAULT, 0, 0, 480)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Panic)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC_GET_TID(N(D_802486EC_85A85C), LVarA)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_EXEC(N(D_80249C34_85BDA4))
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Run)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Run, ANIM_Kolorado_Run, 5, MSG_MAC_Port_0090)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_EXEC(N(D_80249D80_85BEF0))
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
    EVT_CALL(MakeLerp, 480, 372, 50, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcPos, NPC_Whale, -73, -53, LVar0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(MakeLerp, -73, -220, 50, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcPos, NPC_Whale, LVar0, -53, 372)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, -53, 10, 50, EASING_COS_IN_OUT)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcPos, NPC_Whale, -220, LVar0, 372)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_HurtStill)
    EVT_WAIT(50)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Talk)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kolorado, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0091)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 475)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-63.5), 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-5.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_80244314))
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Talk, 5, MSG_MAC_Port_0092)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-7.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kolorado, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0093)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 475)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-63.5), 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-5.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_0094)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-7.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Whale, FALSE)
    EVT_END_THREAD
    EVT_SET(GB_StoryProgress, STORY_CH5_WHALE_MOUTH_OPEN)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
    EVT_WAIT(50)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_FUZZIPEDE)
        EVT_IF_GE(GB_StoryProgress, STORY_CH5_WHALE_MOUTH_OPEN)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_ENTERED_WHALE)
                EVT_CALL(GetNpcAnimation, NPC_Whale, LVar0)
                EVT_IF_EQ(LVar0, ANIM_Kolorado_Yell)
                    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
                    EVT_WAIT(15)
                EVT_END_IF
                EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
                EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Talk, 5, MSG_MAC_Port_0097)
                EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
                EVT_WAIT(30)
                EVT_RETURN
            EVT_ELSE
                EVT_CALL(GetNpcAnimation, NPC_Whale, LVar0)
                EVT_IF_EQ(LVar0, ANIM_Kolorado_Yell)
                    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
                    EVT_WAIT(15)
                EVT_END_IF
                EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
                EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Talk, 5, MSG_MAC_Port_0098)
                EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
                EVT_WAIT(30)
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00B0)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00B2)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(EndSpeech, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5)
    EVT_END_IF
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, -220, -30, 372, 20)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_TalkSad)
    EVT_CALL(InterpNpcYaw, NPC_Whale, 180, 60)
    EVT_SET(LVar0, 0)
    EVT_EXEC(N(D_802484F8_85A668))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt9, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(N(func_80242A90_854C00), 0, LVar0, LVar1, LVar2)
    EVT_EXEC(N(D_802496C0_85B830))
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_THREAD
        EVT_CALL(N(func_80242C78_854DE8), 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar3, LVar5, 10)
    EVT_CALL(N(func_80242A90_854C00), 1, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_THREAD
        EVT_CALL(N(func_80242C78_854DE8), 1)
    EVT_END_THREAD
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Talk, 0, MSG_MAC_Port_00AD)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Run)
        EVT_CALL(NpcMoveTo, NPC_Kolorado, LVar3, LVar5, 20)
        EVT_CALL(N(func_80242A90_854C00), 2, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_Kolorado, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcJumpscale, NPC_Kolorado, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_Kolorado, LVar0, LVar1, LVar2, 20)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
        EVT_THREAD
            EVT_CALL(N(func_80242C78_854DE8), 2)
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00AE)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Shout)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Idle)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00B1)
    EVT_END_IF
    EVT_SET(MF_Unk_01, FALSE)
    EVT_THREAD
        EVT_CALL(N(func_80242E84_854FF4), 0)
        EVT_CALL(GotoMap, EVT_PTR("mac_06"), mac_06_ENTRY_0)
    EVT_END_THREAD
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00AF)
        EVT_SET(MF_Unk_01, TRUE)
    EVT_ELSE
        EVT_SET(MF_Unk_01, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_CALL(SetNpcFlagBits, NPC_Whale, NPC_FLAG_HAS_NO_SPRITE, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Whale, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_CALL(InterpNpcYaw, NPC_Whale, 270, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_Whale, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira_atari, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_Whale, 0, -60, 290)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira_atari, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_WHALE_MOUTH_OPEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Run)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira_atari, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetNpcPos, NPC_Whale, -73, -53, 480)
        EVT_EXEC(N(D_8024A1F8_85C368))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_05_ENTRY_2)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Talk)
        EVT_CALL(SetNpcPos, NPC_Whale, -220, 10, 372)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_FUZZIPEDE)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Talk)
        EVT_CALL(SetNpcPos, NPC_Whale, -220, 10, 372)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
    EVT_CALL(SetNpcPos, NPC_Whale, -220, 10, 372)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar1, -10)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.5))
    EVT_CALL(NpcMoveTo, NPC_SELF, -335, 400, 10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_00B3)
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(PlayerMoveTo, -340, 380, 20 * DT)
        EVT_CALL(InterpPlayerYaw, 45, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, -280, 280, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -340, 70, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -260, -140, 0)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(7.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, 150, -140, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
    EVT_IF_EQ(GF_MAC01_Defeated_JrTroopa4, FALSE)
        EVT_CALL(SetNpcVar, NPC_JrTroopa_01, 0, 1)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_WHALE_MOUTH_OPEN)
            EVT_IF_EQ(AF_MAC_38, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0083)
                EVT_SET(AF_MAC_38, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0084)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0095)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(30)
            EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0096)
        EVT_CASE_LT(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_00AC)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_ArtifactPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_CALL(SetNpcPos, NPC_SELF, -380, -10, 372)
            EVT_CALL(NpcFaceNpc, NPC_SELF, NPC_Whale, 0)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
        EVT_CASE_EQ(STORY_CH5_TRADED_VASE_FOR_SEED)
            EVT_CALL(SetSelfVar, 0, 0)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_802431B0_855320)) {
    Npc* npc = get_npc_safe(NPC_JrTroopa_01);
    f32 x = npc->pos.x + 20.0f;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z - 15.0f;

    if (y < 0.0f) {
        fx_rising_bubble(0, x, y, z, 0.0f);
        sfx_adjust_env_sound_pos(SOUND_LRAW_JR_TROOPA_SWIM, SOUND_SPACE_DEFAULT, x, y, z);
    }
    return ApiStatus_DONE2;
}

EvtScript N(D_8024BCBC_85DE2C) = {
    EVT_LOOP(0)
        EVT_CALL(N(func_802431B0_855320))
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_80243254_8553C4)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar0 = *args++;
    s32 outVar1 = *args++;
    Npc* npc = resolve_npc(script, npcID);
    f32 theta;
    f32 x;
    f32 z;

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    theta = clamp_angle(atan2(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z));
    x = playerStatus->pos.x + (sin_deg(theta) * 40.0f);
    z = playerStatus->pos.z - (cos_deg(theta) * 40.0f);
    evt_set_variable(script, outVar0, x);
    evt_set_variable(script, outVar1, z);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_JrTroopa_01) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(45)
    EVT_EXEC(N(EVS_80244298))
    EVT_CALL(PlaySound, SOUND_LOOP_JR_TROOPA_SWIM)
    EVT_EXEC_GET_TID(N(D_8024BCBC_85DE2C), LVar9)
    EVT_CALL(SetNpcPos, NPC_SELF, 150, -30, 490)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
        EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Port_00B4, 160, 40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, -10, 490)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, -10, 490)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 700)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, -40, 490, 0)
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(StopSound, SOUND_LOOP_JR_TROOPA_SWIM)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SPLASH, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o236, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.5))
    EVT_CALL(NpcJump0, NPC_SELF, -100, -10, 490, 15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_OutOfBreath)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o236, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-7.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_OutOfBreath, 0, MSG_MAC_Port_00B5)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 225)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_OutOfBreath, 0, MSG_MAC_Port_00B6)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, -10, 490)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Walk)
    EVT_CALL(NpcMoveTo, NPC_SELF, -255, 490, 75)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_OutOfBreath)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_RunBack, ANIM_JrTroopa_RunBack, 0, MSG_MAC_Port_00B7)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_RunBack)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(N(func_80243254_8553C4), -1, LVar0, LVar2)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 45)
    EVT_END_THREAD
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_JrTroopa_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_MAC_Port_00BD)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_JrTroopa_01) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET(GF_MAC01_Defeated_JrTroopa4, TRUE)
    EVT_CALL(SetPlayerPos, -340, -10, 380)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -360, LVar1, 390)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetNpcPos, NPC_SELF, -300, -10, 380)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_JrTroopa_02, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(SetNpcYaw, NPC_JrTroopa_02, 270)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Defeated)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 0, MSG_MAC_Port_00BE)
    EVT_CALL(FadeOutMusic, 0, 2000)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_JrTroopa_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_MAC_Port_00BD)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_JrTroopa_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_JrTroopa_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa_02) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_JrTroopa_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Fuzzipede1) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_004E)
                EVT_SET(LVar1, MSG_MAC_Port_005B)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_004F)
                EVT_SET(LVar1, MSG_MAC_Port_005C)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0050)
            EVT_SET(LVar1, MSG_MAC_Port_005D)
    EVT_END_SWITCH
    EVT_CALL(SpeakToNpc, NPC_Fishmael, ANIM_Fishmael_Talk, ANIM_Fishmael_Idle, 0, NPC_Fuzzipede, LVar0)
    EVT_CALL(SpeakToNpc, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, NPC_Fishmael, LVar1)
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Fishmael))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Fishmael) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0051)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0052)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0053)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_0054)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0055)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_0056)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0057)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_0058)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0059)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_005A)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Fishmael_Talk, ANIM_Fishmael_Idle, 0, LVar0)
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Fishmael))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Fuzzipede2) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_005E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_005F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0060)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_0061)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0062)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_0063)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fishmael) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 38, 38)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Fuzzipede1)))
    EVT_ELSE
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 0)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Fishmael)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzipede) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Fuzzipede1)))
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_DEFAULT
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, -575, 40, 120)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Fuzzipede2)))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_001A)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_001B)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_001C)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_001D)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_001E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_001F)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_0020)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0021)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_0022)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0023)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_0024)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0025)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_0026)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0027)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0028)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0029)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_002A)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_002B)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_002C)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_002D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_002E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_002F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0030)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_0031)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0032)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_0033)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0034)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0035)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0036)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0037)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0038)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0039)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_003A)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_003B)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_003C)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_003D)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_003E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_003F)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_0040)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_06)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_07) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0041)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0042)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0043)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0044)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0045)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0046)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_0047)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0048)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_0049)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_004A)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_004B)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_004C)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_004D)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_07) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_07)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bartender) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0000)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0001)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0002)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0003)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0004)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0005)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_0006)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0007)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_0008)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0009)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_000A)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_000B)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_000C)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bartender_Talk, ANIM_Bartender_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bartender) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bartender)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_000D)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_000E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_000F)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Port_0010)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Port_0011)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0012)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Port_0013)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0014)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Port_0015)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Port_0016)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Port_0017)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Port_0018)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Port_0019)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_RETURN
    EVT_END
};

s32 N(D_8024D704_85F874)[] = {
    104, 0
};

EvtScript N(EVS_NpcInteract_ArtistToad) = {
    EVT_SET(GF_MAC05_Met_Simon, TRUE)
    EVT_SET(LVarA, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_IF_EQ(AF_MAC_3E, TRUE)
            EVT_SET(LVarA, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarA, 0)
        EVT_IF_EQ(AF_MAC_3D, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0070)
            EVT_SET(AF_MAC_3D, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0071)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC05_SimonGaveLyrics, FALSE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0072)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Poet_Write)
        EVT_WAIT(60)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Poet_Idle)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0073)
        EVT_CALL(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0074)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0075)
        EVT_GIVE_KEY_REWARD(ITEM_LYRICS)
        EVT_SET(GF_MAC05_SimonGaveLyrics, TRUE)
        EVT_CALL(EnablePartnerAI)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC05_SimonGotMelody, TRUE)
        EVT_IF_EQ(AF_MAC_3D, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0081)
            EVT_SET(AF_MAC_3D, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0082)
            EVT_SET(AF_MAC_3D, FALSE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_MELODY, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_IF_EQ(AF_MAC_3D, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0076)
            EVT_SET(AF_MAC_3D, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0077)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_IF_EQ(AF_MAC_3D, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0078)
            EVT_SET(AF_MAC_3D, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0079)
        EVT_END_IF
        EVT_SET(LVar0, EVT_PTR(N(D_8024D704_85F874)))
        EVT_SET(LVar1, 10)
        EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_CALL(EnablePartnerAI)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007A)
            EVT_CASE_DEFAULT
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007B)
                EVT_SET(GF_MAC05_SimonGotMelody, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_007C)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007D)
                EVT_CALL(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_007E)
                EVT_CALL(SetNpcFlagBits, NPC_Chanterelle, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_THREAD
                    EVT_CALL(PlayerMoveTo, 167, -513, 20)
                    EVT_CALL(InterpPlayerYaw, 270, 0)
                    EVT_WAIT(10)
                    EVT_CALL(EnablePartnerAI)
                    EVT_CALL(func_802CF56C, 2)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Walk)
                    EVT_CALL(NpcMoveTo, NPC_Chanterelle, 112, -511, 60)
                    EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Walk)
                    EVT_CALL(NpcMoveTo, NPC_Bartender, 70, -540, 45)
                    EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Idle)
                EVT_END_THREAD
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 112, 0, -511)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 112, 0, -511)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(InterpNpcYaw, NPC_Toad_02, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_ArtistToad, 270, 0)
                EVT_WAIT(60)
                EVT_EXEC(N(EVS_802442C4))
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Pray)
                EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Toad_Red_Disappointed)
                EVT_CALL(SetNpcAnimation, NPC_ArtistToad, ANIM_Musician_Poet_Pensive)
                EVT_WAIT(30)
                EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Talk)
                EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Still)
                EVT_WAIT(30)
                EVT_CALL(SetMusicTrack, 0, SONG_POP_DIVA_SONG, 0, 8)
                EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_StrumGuitar)
                EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                EVT_WAIT(30 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Sing)
                EVT_WAIT(150 * DT)
                EVT_WAIT(150 * DT)
                EVT_WAIT(150 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Idle)
                EVT_WAIT(40 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Toad_Red_Idle)
                EVT_CALL(SetNpcAnimation, NPC_ArtistToad, ANIM_Musician_Poet_Idle)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_WAIT(30 * DT)
                EVT_EXEC(N(EVS_802442E8))
                EVT_THREAD
                    EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Walk)
                    EVT_CALL(NpcMoveTo, NPC_Bartender, -85, -520, 40)
                    EVT_CALL(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Idle)
                    EVT_CALL(InterpNpcYaw, NPC_Bartender, 90, 0)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Walk)
                    EVT_CALL(NpcMoveTo, NPC_Chanterelle, 208, -530, 60)
                    EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                    EVT_CALL(InterpNpcYaw, NPC_Chanterelle, 270, 0)
                    EVT_CALL(InterpNpcYaw, NPC_ArtistToad, 90, 0)
                    EVT_CALL(InterpPlayerYaw, 90, 0)
                    EVT_WAIT(10)
                    EVT_CALL(func_802CF56C, 2)
                    EVT_CALL(SetNpcFlagBits, NPC_Chanterelle, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_END_THREAD
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                EVT_WAIT(60)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007F)
                EVT_CALL(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0080)
                EVT_WAIT(10)
                EVT_SET(LVar0, ITEM_ATTACK_FX_D)
                EVT_SET(LVar3, ITEM_TYPE_BADGE)
                EVT_EXEC_WAIT(N(GiveItemReward))
                EVT_CALL(AddBadge, LVar0, LVar1)
                EVT_CALL(SetTattleMessage, NPC_Chanterelle, MSG_NpcTattle_PopDiva_CanSing)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ArtistToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ArtistToad)))
    EVT_SET(AF_MAC_3D, FALSE)
    EVT_SET(AF_MAC_3E, FALSE)
    EVT_IF_EQ(GF_MAC05_Met_Simon, TRUE)
        EVT_SET(AF_MAC_3E, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_8024335C_8554CC)) {
    if (func_8014AD40() == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(D_8024E23C_8603AC) = {
    EVT_SET(AF_JAN01_TreeDrop_StarPiece, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000 | ENEMY_FLAG_CANT_INTERACT, 1)
    EVT_CALL(InterpNpcYaw, NPC_Chanterelle, 270, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_POP_DIVA_SONG, 1, 8)
    EVT_CHILD_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Sing)
        EVT_WAIT(1900)
        EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_WAIT(30)
        EVT_CALL(N(func_8024335C_8554CC))
        EVT_SET(AF_JAN01_TreeDrop_StarPiece, FALSE)
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_IF_EQ(AF_JAN01_TreeDrop_StarPiece, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_802442E8))
    EVT_CALL(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000 | ENEMY_FLAG_CANT_INTERACT, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Chanterelle) = {
    EVT_IF_EQ(GF_MAC05_SimonGaveLyrics, FALSE)
        EVT_IF_EQ(AF_MAC_3F, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0068)
            EVT_SET(AF_MAC_3F, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0069)
            EVT_SET(AF_MAC_3F, FALSE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC05_SimonGotMelody, FALSE)
        EVT_IF_EQ(AF_MAC_3F, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006A)
            EVT_SET(AF_MAC_3F, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006B)
            EVT_SET(AF_MAC_3F, FALSE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_MAC_3F, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006C)
        EVT_SET(AF_MAC_3F, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006D)
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006E)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006F)
        EVT_EXEC(N(D_8024E23C_8603AC))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Chanterelle) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Chanterelle)))
    EVT_IF_EQ(GF_MAC05_SimonGotMelody, TRUE)
        EVT_CALL(SetTattleMessage, NPC_Chanterelle, MSG_NpcTattle_PopDiva_CanSing)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(CheckTradeEventTime)) {
    script->varTable[0] = (s32) ((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTradeEventItemCount)) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_Toad_03) = {
    EVT_SET(LVar0, 7)
    EVT_CALL(N(CheckTradeEventTime))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00BF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetTradeEventItemCount))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C0)
        EVT_WAIT(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_SET(GF_TradingEvent3_Active, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 11)
    EVT_EXEC_WAIT(N(EVS_ChooseItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C5)
            EVT_RETURN
        EVT_CASE_EQ(ITEM_COCONUT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C2)
            EVT_GIVE_CONSUMABLE_REWARD(ITEM_YUMMY_MEAL)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C3)
            EVT_WAIT(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_SET(GF_TradingEvent3_Active, FALSE)
            EVT_ADD(GB_TradingEvent_Count, 1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C4)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TradeEventToad) = {
    EVT_IF_NE(GF_TradingEvent3_Active, FALSE)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toad_01) = {
    .id = NPC_Whale,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Toad_01),
    .settings = &N(NpcSettings_Whale),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_Whale,
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = COMMON_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Fishmael) = {
    .id = NPC_Fishmael,
    .pos = { 370.0f, -10.0f, -115.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Fishmael),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Fishmael_Idle,
    },
    .tattle = MSG_NpcTattle_Fishmael,
};

AnimID N(ExtraAnims_Fuzzipede)[] = {
    ANIM_Fuzzipede_Anim00,
    ANIM_Fuzzipede_Anim04,
    ANIM_Fuzzipede_Anim08,
    ANIM_Fuzzipede_Anim0A,
    ANIM_Fuzzipede_Anim24,
    ANIM_LIST_END
};

NpcData N(NpcData_Fuzzipede) = {
    .id = NPC_Fuzzipede,
    .pos = { 320.0f, -10.0f, -115.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Fuzzipede),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Fuzzipede_Anim04,
    },
    .extraAnimations = N(ExtraAnims_Fuzzipede),
    .tattle = MSG_NpcTattle_Fuzzipede,
};

AnimID N(ExtraAnims_JrTroopa)[] = {
    ANIM_JrTroopa_Still,
    ANIM_JrTroopa_PointStill,
    ANIM_JrTroopa_Idle,
    ANIM_JrTroopa_OutOfBreath,
    ANIM_JrTroopa_Walk,
    ANIM_JrTroopa_Charge,
    ANIM_JrTroopa_ChargeArmsUp,
    ANIM_JrTroopa_ChargeTripped,
    ANIM_JrTroopa_RunBack,
    ANIM_JrTroopa_Defeated,
    ANIM_JrTroopa_TiredTalk,
    ANIM_JrTroopa_PointTalk,
    ANIM_LIST_END
};

NpcData N(NpcData_JrTroopa_01)[] = {
    {
        .id = NPC_JrTroopa_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_JrTroopa_01),
        .settings = &N(NpcSettings_JrTroopa_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_JrTroopa_Idle,
            .walk   = ANIM_JrTroopa_Walk,
            .run    = ANIM_JrTroopa_Walk,
            .chase  = ANIM_JrTroopa_Walk,
            .anim_4 = ANIM_JrTroopa_Idle,
            .anim_5 = ANIM_JrTroopa_Idle,
            .death  = ANIM_JrTroopa_Idle,
            .hit    = ANIM_JrTroopa_Idle,
            .anim_8 = ANIM_JrTroopa_Idle,
            .anim_9 = ANIM_JrTroopa_Idle,
            .anim_A = ANIM_JrTroopa_Idle,
            .anim_B = ANIM_JrTroopa_Idle,
            .anim_C = ANIM_JrTroopa_Idle,
            .anim_D = ANIM_JrTroopa_Idle,
            .anim_E = ANIM_JrTroopa_Idle,
            .anim_F = ANIM_JrTroopa_Idle,
        },
        .extraAnimations = N(ExtraAnims_JrTroopa),
        .tattle = MSG_NpcTattle_JrTroopa,
    },
    {
        .id = NPC_JrTroopa_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_JrTroopa_02),
        .settings = &N(NpcSettings_JrTroopa_01),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_JrTroopa_Idle,
            .walk   = ANIM_JrTroopa_Walk,
            .run    = ANIM_JrTroopa_Walk,
            .chase  = ANIM_JrTroopa_Walk,
            .anim_4 = ANIM_JrTroopa_Idle,
            .anim_5 = ANIM_JrTroopa_Idle,
            .death  = ANIM_JrTroopa_Idle,
            .hit    = ANIM_JrTroopa_Idle,
            .anim_8 = ANIM_JrTroopa_Idle,
            .anim_9 = ANIM_JrTroopa_Idle,
            .anim_A = ANIM_JrTroopa_Idle,
            .anim_B = ANIM_JrTroopa_Idle,
            .anim_C = ANIM_JrTroopa_Idle,
            .anim_D = ANIM_JrTroopa_Idle,
            .anim_E = ANIM_JrTroopa_Idle,
            .anim_F = ANIM_JrTroopa_Idle,
        },
        .extraAnimations = N(ExtraAnims_JrTroopa),
        .tattle = MSG_NpcTattle_JrTroopa,
    },
};

NpcData N(NpcData_Toad_04)[] = {
    {
        .id = NPC_Toad_04,
        .pos = { 320.0f, 0.0f, -300.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Toad_Blue_Idle,
            .walk   = ANIM_Toad_Blue_Walk,
            .run    = ANIM_Toad_Blue_Run,
            .chase  = ANIM_Toad_Blue_Run,
            .anim_4 = ANIM_Toad_Blue_Idle,
            .anim_5 = ANIM_Toad_Blue_Idle,
            .death  = ANIM_Toad_Blue_Disappointed,
            .hit    = ANIM_Toad_Blue_Disappointed,
            .anim_8 = ANIM_Toad_Blue_Run,
            .anim_9 = ANIM_Toad_Blue_Run,
            .anim_A = ANIM_Toad_Blue_Run,
            .anim_B = ANIM_Toad_Blue_Run,
            .anim_C = ANIM_Toad_Blue_Run,
            .anim_D = ANIM_Toad_Blue_Run,
            .anim_E = ANIM_Toad_Blue_Run,
            .anim_F = ANIM_Toad_Blue_Run,
        },
        .tattle = MSG_NpcTattle_MAC_PortGuide,
    },
    {
        .id = NPC_Toad_05,
        .pos = { -330.0f, -10.0f, -90.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_05),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Toad_Blue_Idle,
            .walk   = ANIM_Toad_Blue_Walk,
            .run    = ANIM_Toad_Blue_Run,
            .chase  = ANIM_Toad_Blue_Run,
            .anim_4 = ANIM_Toad_Blue_Idle,
            .anim_5 = ANIM_Toad_Blue_Idle,
            .death  = ANIM_Toad_Blue_Disappointed,
            .hit    = ANIM_Toad_Blue_Disappointed,
            .anim_8 = ANIM_Toad_Blue_Run,
            .anim_9 = ANIM_Toad_Blue_Run,
            .anim_A = ANIM_Toad_Blue_Run,
            .anim_B = ANIM_Toad_Blue_Run,
            .anim_C = ANIM_Toad_Blue_Run,
            .anim_D = ANIM_Toad_Blue_Run,
            .anim_E = ANIM_Toad_Blue_Run,
            .anim_F = ANIM_Toad_Blue_Run,
        },
        .tattle = MSG_NpcTattle_MAC_SeaLover,
    },
    {
        .id = NPC_Toad_06,
        .pos = { -50.0f, 0.0f, -400.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_06),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_MAC_WellTraveledToad,
    },
    {
        .id = NPC_Toad_07,
        .pos = { 200.0f, 0.0f, -220.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -120, 0, -220 },
                    { 200, 0, -220 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 180, 20, -435 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_07),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .tattle = MSG_NpcTattle_MAC_SingsOffKey,
    },
};

NpcData N(NpcData_Bartender)[] = {
    {
        .id = NPC_Bartender,
        .pos = { -85.0f, 0.0f, -520.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bartender),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bartender_Idle,
            .walk   = ANIM_Bartender_Idle,
            .run    = ANIM_Bartender_Idle,
            .chase  = ANIM_Bartender_Idle,
            .anim_4 = ANIM_Bartender_Idle,
            .anim_5 = ANIM_Bartender_Idle,
            .death  = ANIM_Bartender_Idle,
            .hit    = ANIM_Bartender_Idle,
            .anim_8 = ANIM_Bartender_Idle,
            .anim_9 = ANIM_Bartender_Idle,
            .anim_A = ANIM_Bartender_Idle,
            .anim_B = ANIM_Bartender_Idle,
            .anim_C = ANIM_Bartender_Idle,
            .anim_D = ANIM_Bartender_Idle,
            .anim_E = ANIM_Bartender_Idle,
            .anim_F = ANIM_Bartender_Idle,
        },
        .tattle = MSG_NpcTattle_Club64_Bartender,
    },
    {
        .id = NPC_Toad_02,
        .pos = { 30.0f, 0.0f, -570.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_Club64_Waiter,
    },
    {
        .id = NPC_Chanterelle,
        .pos = { 208.0f, 0.0f, -530.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Chanterelle),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Chanterelle_Idle,
            .walk   = ANIM_Chanterelle_Still,
            .run    = ANIM_Chanterelle_Still,
            .chase  = ANIM_Chanterelle_Still,
            .anim_4 = ANIM_Chanterelle_Still,
            .anim_5 = ANIM_Chanterelle_Still,
            .death  = ANIM_Chanterelle_Still,
            .hit    = ANIM_Chanterelle_Still,
            .anim_8 = ANIM_Chanterelle_Still,
            .anim_9 = ANIM_Chanterelle_Still,
            .anim_A = ANIM_Chanterelle_Still,
            .anim_B = ANIM_Chanterelle_Still,
            .anim_C = ANIM_Chanterelle_Still,
            .anim_D = ANIM_Chanterelle_Still,
            .anim_E = ANIM_Chanterelle_Still,
            .anim_F = ANIM_Chanterelle_Still,
        },
        .tattle = MSG_NpcTattle_PopDiva_CantSing,
    },
    {
        .id = NPC_ArtistToad,
        .pos = { 158.0f, 0.0f, -555.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ArtistToad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Musician_Poet_Idle,
            .walk   = ANIM_Musician_Poet_Idle,
            .run    = ANIM_Musician_Poet_Idle,
            .chase  = ANIM_Musician_Poet_Idle,
            .anim_4 = ANIM_Musician_Poet_Idle,
            .anim_5 = ANIM_Musician_Poet_Idle,
            .death  = ANIM_Musician_Poet_Idle,
            .hit    = ANIM_Musician_Poet_Idle,
            .anim_8 = ANIM_Musician_Poet_Idle,
            .anim_9 = ANIM_Musician_Poet_Idle,
            .anim_A = ANIM_Musician_Poet_Idle,
            .anim_B = ANIM_Musician_Poet_Idle,
            .anim_C = ANIM_Musician_Poet_Idle,
            .anim_D = ANIM_Musician_Poet_Idle,
            .anim_E = ANIM_Musician_Poet_Idle,
            .anim_F = ANIM_Musician_Poet_Idle,
        },
        .tattle = MSG_NpcTattle_MasterPoet,
    },
    {
        .id = NPC_TradeEventToad,
        .pos = { 92.0f, 0.0f, -500.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TradeEventToad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Toad_Pink_Idle,
            .walk   = ANIM_Toad_Pink_Walk,
            .run    = ANIM_Toad_Pink_Run,
            .chase  = ANIM_Toad_Pink_Run,
            .anim_4 = ANIM_Toad_Pink_Idle,
            .anim_5 = ANIM_Toad_Pink_Idle,
            .death  = ANIM_Toad_Pink_Idle,
            .hit    = ANIM_Toad_Pink_Disappointed,
            .anim_8 = ANIM_Toad_Pink_Run,
            .anim_9 = ANIM_Toad_Pink_Run,
            .anim_A = ANIM_Toad_Pink_Run,
            .anim_B = ANIM_Toad_Pink_Run,
            .anim_C = ANIM_Toad_Pink_Run,
            .anim_D = ANIM_Toad_Pink_Run,
            .anim_E = ANIM_Toad_Pink_Run,
            .anim_F = ANIM_Toad_Pink_Run,
        },
        .tattle = MSG_NpcTattle_PrizeToad,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 472.0f, 0.0f, -230.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_05 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_ChuckQuizmo_Idle,
        .walk   = ANIM_ChuckQuizmo_Walk,
        .run    = ANIM_ChuckQuizmo_Run,
        .chase  = ANIM_ChuckQuizmo_Run,
        .anim_4 = ANIM_ChuckQuizmo_Idle,
        .anim_5 = ANIM_ChuckQuizmo_Idle,
        .death  = ANIM_ChuckQuizmo_Still,
        .hit    = ANIM_ChuckQuizmo_Still,
        .anim_8 = ANIM_ChuckQuizmo_Run,
        .anim_9 = ANIM_ChuckQuizmo_Run,
        .anim_A = ANIM_ChuckQuizmo_Run,
        .anim_B = ANIM_ChuckQuizmo_Run,
        .anim_C = ANIM_ChuckQuizmo_Run,
        .anim_D = ANIM_ChuckQuizmo_Run,
        .anim_E = ANIM_ChuckQuizmo_Run,
        .anim_F = ANIM_ChuckQuizmo_Run,
    },
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(NpcSetA) = {
    NPC_GROUP(N(NpcData_Fuzzipede)),
    NPC_GROUP(N(NpcData_Fishmael)),
    NPC_GROUP(N(NpcData_Bartender)),
    NPC_GROUP(N(NpcData_Toad_04)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(NpcSetB) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Fuzzipede)),
    NPC_GROUP(N(NpcData_Fishmael)),
    NPC_GROUP(N(NpcData_Bartender)),
    NPC_GROUP(N(NpcData_Toad_04)),
    NPC_GROUP(N(NpcData_Toad_01)),
    {}
};

NpcGroupList N(NpcSetC) = {
    NPC_GROUP(N(NpcData_JrTroopa_01), BTL_KMR_3_FORMATION_05),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Fishmael)),
    NPC_GROUP(N(NpcData_Bartender)),
    NPC_GROUP(N(NpcData_Toad_04)),
    NPC_GROUP(N(NpcData_Toad_01)),
    {}
};
