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
    Call(N(LetterDelivery_Init), NPC_Fishmael,
        ANIM_Fishmael_Talk, ANIM_Fishmael_Idle,
        ITEM_LETTER_CHAIN_FISHMAEL, ITEM_LETTER_CHAIN_KOOVER_2,
        MSG_MAC_Port_0064, MSG_MAC_Port_0065,
        MSG_MAC_Port_0066, MSG_MAC_Port_0067,
        Ref(N(Fishmael_LetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

s32 N(Kolorado_LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    Call(N(LetterDelivery_Init), NPC_Kolorado,
        ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_MAC_Port_0085, MSG_MAC_Port_0086,
        MSG_MAC_Port_0087, MSG_MAC_Port_0088,
        Ref(N(Kolorado_LetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

s32 N(ItemList_Artifact)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactReward_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008E)
    EVT_GIVE_STAR_PIECE()
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008F)
    Set(GF_SBK_GaveArtifactToKolorado, TRUE)
    Return
    End
};

EvtScript N(EVS_ArtifactPrompt_Kolorado) = {
    IfEq(GF_SBK_GaveArtifactToKolorado, TRUE)
        Return
    EndIf
    Call(FindKeyItem, ITEM_ARTIFACT, LVar0)
    IfEq(LVar0, -1)
        Return
    EndIf
    IfEq(AF_MAC_44, FALSE)
        Set(AF_MAC_44, TRUE)
        IfEq(GF_SBK_KeptArtifactFromKolorado, FALSE)
            Set(GF_SBK_KeptArtifactFromKolorado, FALSE)
            Set(LVar0, MSG_MAC_Port_0089)
        Else
            Set(LVar0, MSG_MAC_Port_008A)
        EndIf
    Else
        Set(LVar0, MSG_MAC_Port_008B)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    Set(LVar0, Ref(N(ItemList_Artifact)))
    Set(LVar1, 1)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseGe(1)
            ExecWait(N(EVS_ArtifactReward_Kolorado))
            BreakSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008C)
            Set(LVar0, Ref(N(ItemList_Artifact)))
            Set(LVar1, 1)
            ExecWait(N(EVS_ChooseKeyItem))
            Switch(LVar0)
                CaseGe(1)
                    ExecWait(N(EVS_ArtifactReward_Kolorado))
                CaseDefault
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_008D)
            EndSwitch
    EndSwitch
    Return
    End
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
    Call(N(func_80242C78_854DE8), LVar0)
    Return
    End
};

EvtScript N(D_802484F8_85A668) = {
    Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    IfEq(LVar0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Else
        Call(SetCamSpeed, CAM_DEFAULT, 1)
    EndIf
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, 1)
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 100)
            Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
            Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Else
            Set(LVar3, LVar0)
            Sub(LVar3, 100)
            Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
            Sub(LVar0, LVar3)
            Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(D_802486EC_85A85C) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar4, LVar4)
        IfGt(LVar0, -150)
            Call(GetPlayerPos, LVar0, LVar4, LVar4)
            Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Else
            Set(LVar3, LVar0)
            Sub(LVar3, -150)
            Call(GetPlayerPos, LVar0, LVar4, LVar4)
            Sub(LVar0, LVar3)
            Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_Whale, LVar0, LVar4, LVar4)
            IfLt(LVar0, -150)
                Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Else
                Call(SetCamTarget, CAM_DEFAULT, -150, LVar1, LVar2)
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_80248878) = {
    Set(GB_StoryProgress, STORY_CH5_DEFEATED_FUZZIPEDE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -120, 24, 375)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(20)
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_009F)
    Wait(20)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Shout)
    Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 475)
    Call(SetCamSpeed, CAM_DEFAULT, 3)
    Wait(10)
    Thread
        Call(SetPlayerJumpscale, Float(0.5))
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Call(SetPlayerPos, -120, 24, 375)
        Call(PlaySoundAtPlayer, SOUND_WHALE_EJECT, SOUND_SPACE_DEFAULT)
        Call(PlayerJump1, -310, -10, 372, 80)
        Call(SetPlayerActionState, ACTION_STATE_LAND)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Thread
        Wait(5)
        Call(SetNpcPos, NPC_PARTNER, -120, 24, 375)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
        Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_WHALE_EJECT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_PARTNER, -345, 0, 372, 80)
        Call(ClearPartnerMoveHistory, NPC_PARTNER)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EndThread
    Thread
        Wait(10)
        Call(SetNpcPos, NPC_Fuzzipede, -120, 24, 375)
        Call(SetNpcJumpscale, NPC_Fuzzipede, Float(0.5))
        Call(PlaySoundAtNpc, NPC_Fuzzipede, SOUND_WHALE_EJECT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzipede, -280, -10, 372, 90)
        Call(NpcFaceNpc, NPC_Fuzzipede, NPC_Whale, 0)
    EndThread
    Wait(50)
    Thread
        Wait(15)
        Call(SetNpcJumpscale, NPC_Kolorado, Float(0.1))
        Call(NpcJump0, NPC_Kolorado, -380, -10, 372, 20)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
    EndThread
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
    Wait(60)
    Call(NpcFacePlayer, NPC_Kolorado, 0)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Fuzzipede, 0)
    Call(NpcFaceNpc, NPC_Fuzzipede, NPC_Whale, 0)
    Call(PlayerFaceNpc, NPC_Fuzzipede, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, 3)
    Call(GetNpcPos, NPC_Fuzzipede, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 5, MSG_MAC_Port_00A0)
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00A1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 475)
    Call(SetCamPosA, CAM_DEFAULT, Float(-63.5), 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-5.0))
    Call(SpeakToNpc, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, NPC_Whale, MSG_MAC_Port_00A2)
    Call(NpcFacePlayer, NPC_Fuzzipede, 0)
    Wait(10)
    Call(EndSpeech, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0)
    Wait(10)
    Call(SetNpcJumpscale, NPC_Fuzzipede, 1)
    Call(GetNpcPos, NPC_Fuzzipede, LVar0, LVar1, LVar2)
    Call(FadeOutMusic, 0, 3000)
    Loop(10)
        Add(LVar2, -60)
        Call(PlaySoundAtNpc, NPC_Fuzzipede, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzipede, LVar0, LVar1, LVar2, 10)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Fuzzipede, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Fuzzipede, 0)
        Call(PlayerFaceNpc, NPC_Fuzzipede, FALSE)
    EndLoop
    Call(SetNpcPos, NPC_Fuzzipede, NPC_DISPOSE_LOCATION)
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00A3)
    Call(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-7.0))
    Wait(5)
    Thread
        Wait(5)
        Call(NpcFacePlayer, NPC_Kolorado, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Kolorado, 0)
        Call(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_00A4)
    Call(SetCamSpeed, CAM_DEFAULT, 3)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_PARTNER, 0)
        Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EndThread
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Port_00A5)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_MAC_Port_00A6)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_MAC_Port_00A7)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_MAC_Port_00A8)
        CaseEq(PARTNER_BOW)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_MAC_Port_00A9)
        CaseEq(PARTNER_WATT)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_MAC_Port_00AA)
    EndSwitch
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 475)
    Call(SetCamPosA, CAM_DEFAULT, Float(-63.5), 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-5.0))
    Wait(5)
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00AB)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
    Thread
        Wait(100)
        Call(SetCamSpeed, CAM_DEFAULT, 1)
    EndThread
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(EnablePartnerAI)
    Return
    End
};

EvtScript N(D_802496C0_85B830) = {
    Call(SetPlayerAnimation, ANIM_Mario1_Jump)
    Wait(5)
    Call(SetPlayerAnimation, ANIM_Mario1_Fall)
    Return
    End
};

EvtScript N(EVS_802496FC) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(InterpPlayerYaw, 270, 0)
    Set(LVar0, 1)
    ExecGetTID(N(D_802484F8_85A668), LVarA)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Set(LVar0, 0)
    ExecGetTID(N(D_802484D8_85A648), LVarB)
    Set(LVar0, 1)
    ExecGetTID(N(D_802484D8_85A648), LVarC)
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        Set(LVar0, 2)
        ExecGetTID(N(D_802484D8_85A648), LVarD)
    EndIf
    Call(N(func_80242E84_854FF4), 2)
    KillThread(LVarB)
    KillThread(LVarC)
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        KillThread(LVarD)
    EndIf
    Wait(1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt9, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Run)
        Call(N(func_80242A90_854C00), 5, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_Kolorado, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(SetNpcJumpscale, NPC_Kolorado, Float(1.0))
        Call(NpcJump0, NPC_Kolorado, LVar0, LVar1, LVar2, 20)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
    EndIf
    Call(N(func_80242A90_854C00), 3, LVar0, LVar1, LVar2)
    Exec(N(D_802496C0_85B830))
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, LVar0, LVar1, LVar2, 20)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    Call(N(func_80242A90_854C00), 4, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 20)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tt9, COLLIDER_FLAGS_UPPER_MASK)
    KillThread(LVarA)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_TalkSad)
    Call(InterpNpcYaw, NPC_Whale, 270, 60)
    Thread
        Call(SetNpcJumpscale, NPC_Whale, 0)
        Call(NpcJump0, NPC_Whale, -220, 10, 372, 20)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_SUSHIE_JOINED_PARTY, STORY_CH5_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
                Call(SetNpcVar, NPC_JrTroopa_01, 0, 1)
            EndIf
        CaseEq(STORY_CH5_TRADED_VASE_FOR_SEED)
            Call(SetNpcVar, NPC_Kolorado, 0, 1)
    EndSwitch
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(EnablePartnerAI)
    Return
    End
};

EvtScript N(D_80249C34_85BDA4) = {
    Thread
        Call(SetPlayerJumpscale, Float(1.0))
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Call(PlayerJump1, -310, -10, 372, 30)
        Call(SetPlayerActionState, ACTION_STATE_LAND)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
        Call(NpcJump0, NPC_PARTNER, -345, -10, 372, 30)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(ClearPartnerMoveHistory, NPC_PARTNER)
        Call(EnablePartnerAI)
    EndThread
    Return
    End
};

EvtScript N(D_80249D80_85BEF0) = {
    Wait(20)
    Call(PlayerMoveTo, -285, 485, 40)
    Call(PlayerMoveTo, -310, 372, 20)
    Call(PlayerFaceNpc, NPC_Whale, FALSE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(NpcMoveTo, NPC_PARTNER, -345, 372, 30)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, Float(1.0))
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(EnablePartnerAI)
    Return
    End
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
    Set(LVarA, 0)
    Loop(0)
        Call(N(GetFloorCollider), LVar0)
        IfEq(LVar0, 29)
            Set(LVar5, 0)
            Call(GetPlayerActionState, LVar1)
            IfEq(LVar1, ACTION_STATE_HAMMER)
                Add(LVar5, 1)
            EndIf
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            Call(GetPlayerTargetYaw, LVar3)
            IfLt(LVar3, 180)
                IfGt(LVar2, -60)
                    Add(LVar5, 1)
                EndIf
            Else
                IfGt(LVar2, -40)
                    Add(LVar5, 1)
                EndIf
            EndIf
            IfEq(LVar5, 2)
                IfEq(LVarA, 2)
                    Set(LFlag0, TRUE)
                    Return
                Else
                    Call(DisablePlayerInput, TRUE)
                    Loop(0)
                        Wait(1)
                        Call(GetPlayerActionState, LVar1)
                        IfEq(LVar1, ACTION_STATE_IDLE)
                            BreakLoop
                        EndIf
                    EndLoop
                    Wait(10)
                    Thread
                        Call(SetPlayerJumpscale, Float(1.0))
                        Call(GetPlayerPos, LVar2, LVar3, LVar4)
                        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
                        Call(PlayerJump1, LVar2, LVar3, LVar4, 10)
                        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                    EndThread
                    Call(PlaySoundAt, SOUND_WHALE_JIGGLE, SOUND_SPACE_DEFAULT, 0, 0, 480)
                    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Panic)
                    Wait(10)
                    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
                    Call(DisablePlayerInput, FALSE)
                    Add(LVarA, 1)
                EndIf
            EndIf
            IfEq(LVar1, ACTION_STATE_SPIN_POUND)
                Set(LFlag0, TRUE)
                Return
            EndIf
        EndIf
        Call(N(func_802430B4_855224), LVar2)
        IfEq(LVar2, 29)
            IfEq(LVar0, 29)
                Set(LFlag0, TRUE)
            EndIf
            Return
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(D_8024A1F8_85C368) = {
    ExecWait(N(D_80249E84_85BFF4))
    Call(DisablePlayerInput, TRUE)
    Wait(10)
    Call(PlaySoundAt, SOUND_WHALE_JIGGLE, SOUND_SPACE_DEFAULT, 0, 0, 480)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Panic)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    ExecGetTID(N(D_802486EC_85A85C), LVarA)
    IfEq(LFlag0, TRUE)
        Exec(N(D_80249C34_85BDA4))
    EndIf
    Wait(10)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Run)
    Wait(20)
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Run, ANIM_Kolorado_Run, 5, MSG_MAC_Port_0090)
    IfEq(LFlag0, FALSE)
        Exec(N(D_80249D80_85BEF0))
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
    Call(MakeLerp, 480, 372, 50, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(SetNpcPos, NPC_Whale, -73, -53, LVar0)
    IfEq(LVar1, 1)
        Wait(1)
        Goto(0)
    EndIf
    Call(MakeLerp, -73, -220, 50, EASING_COS_IN_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(SetNpcPos, NPC_Whale, LVar0, -53, 372)
    IfEq(LVar1, 1)
        Wait(1)
        Goto(1)
    EndIf
    Wait(20)
    Call(MakeLerp, -53, 10, 50, EASING_COS_IN_OUT)
    Label(2)
    Call(UpdateLerp)
    Call(SetNpcPos, NPC_Whale, -220, LVar0, 372)
    IfEq(LVar1, 1)
        Wait(1)
        Goto(2)
    EndIf
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_HurtStill)
    Wait(50)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Talk)
    KillThread(LVarA)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Kolorado, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Kolorado, 0)
        Call(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0091)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 475)
    Call(SetCamPosA, CAM_DEFAULT, Float(-63.5), 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-5.0))
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Exec(N(EVS_80244314))
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Talk, 5, MSG_MAC_Port_0092)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Kolorado, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-7.0))
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Kolorado, 0)
        Call(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0093)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Whale, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 475)
    Call(SetCamPosA, CAM_DEFAULT, Float(-63.5), 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-5.0))
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_0094)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Kolorado, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-7.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Thread
        Wait(5)
        Call(NpcFaceNpc, NPC_Kolorado, NPC_Whale, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Whale, 0)
        Call(PlayerFaceNpc, NPC_Whale, FALSE)
    EndThread
    Set(GB_StoryProgress, STORY_CH5_WHALE_MOUTH_OPEN)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
    Wait(50)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_FUZZIPEDE)
        IfGe(GB_StoryProgress, STORY_CH5_WHALE_MOUTH_OPEN)
            IfLt(GB_StoryProgress, STORY_CH5_ENTERED_WHALE)
                Call(GetNpcAnimation, NPC_Whale, LVar0)
                IfEq(LVar0, ANIM_Kolorado_Yell)
                    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
                    Wait(15)
                EndIf
                Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
                Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Talk, 5, MSG_MAC_Port_0097)
                Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
                Wait(30)
                Return
            Else
                Call(GetNpcAnimation, NPC_Whale, LVar0)
                IfEq(LVar0, ANIM_Kolorado_Yell)
                    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
                    Wait(15)
                EndIf
                Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
                Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Talk, 5, MSG_MAC_Port_0098)
                Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
                Wait(30)
                Return
            EndIf
        Else
            Return
        EndIf
    EndIf
    Call(DisablePlayerPhysics, TRUE)
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00B0)
    Call(ShowChoice, MSG_Choice_0010)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00B2)
        Call(DisablePlayerPhysics, FALSE)
        Return
    Else
        Call(EndSpeech, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5)
    EndIf
    Call(SetNpcJumpscale, NPC_SELF, 0)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, -220, -30, 372, 20)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_TalkSad)
    Call(InterpNpcYaw, NPC_Whale, 180, 60)
    Set(LVar0, 0)
    Exec(N(D_802484F8_85A668))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt9, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(N(func_80242A90_854C00), 0, LVar0, LVar1, LVar2)
    Exec(N(D_802496C0_85B830))
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, LVar0, LVar1, LVar2, 20)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 90, 0)
    Thread
        Call(N(func_80242C78_854DE8), 0)
    EndThread
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    Call(NpcMoveTo, NPC_PARTNER, LVar3, LVar5, 10)
    Call(N(func_80242A90_854C00), 1, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 20)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Thread
        Call(N(func_80242C78_854DE8), 1)
    EndThread
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Talk, 0, MSG_MAC_Port_00AD)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Run)
        Call(NpcMoveTo, NPC_Kolorado, LVar3, LVar5, 20)
        Call(N(func_80242A90_854C00), 2, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_Kolorado, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(SetNpcJumpscale, NPC_Kolorado, Float(1.0))
        Call(NpcJump0, NPC_Kolorado, LVar0, LVar1, LVar2, 20)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
        Thread
            Call(N(func_80242C78_854DE8), 2)
        EndThread
        Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00AE)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Shout)
        Wait(30)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Idle)
    Else
        Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00B1)
    EndIf
    Set(MF_Unk_01, FALSE)
    Thread
        Call(N(func_80242E84_854FF4), 0)
        Call(GotoMap, Ref("mac_06"), mac_06_ENTRY_0)
    EndThread
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_MAC_Port_00AF)
        Set(MF_Unk_01, TRUE)
    Else
        Set(MF_Unk_01, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Call(SetNpcFlagBits, NPC_Whale, NPC_FLAG_HAS_NO_SPRITE, TRUE)
    Call(SetNpcFlagBits, NPC_Whale, NPC_FLAG_HAS_SHADOW, FALSE)
    Call(InterpNpcYaw, NPC_Whale, 270, 0)
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Call(SetNpcPos, NPC_Whale, NPC_DISPOSE_LOCATION)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira_atari, COLLIDER_FLAGS_UPPER_MASK)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        Call(SetNpcPos, NPC_Whale, 0, -60, 290)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_WalkSad)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira_atari, COLLIDER_FLAGS_UPPER_MASK)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH5_WHALE_MOUTH_OPEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Run)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira_atari, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetNpcPos, NPC_Whale, -73, -53, 480)
        Exec(N(D_8024A1F8_85C368))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_05_ENTRY_2)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Talk)
        Call(SetNpcPos, NPC_Whale, -220, 10, 372)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_FUZZIPEDE)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Talk)
        Call(SetNpcPos, NPC_Whale, -220, 10, 372)
        Return
    EndIf
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Still)
    Call(SetNpcPos, NPC_Whale, -220, 10, 372)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Call(DisablePlayerInput, TRUE)
    Loop(0)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        IfEq(LVar1, -10)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    Call(SetNpcSpeed, NPC_SELF, Float(1.5))
    Call(NpcMoveTo, NPC_SELF, -335, 400, 10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_00B3)
    Thread
        Wait(15 * DT)
        Call(PlayerMoveTo, -340, 380, 20 * DT)
        Call(InterpPlayerYaw, 45, 0)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(8.0 / DT))
    Call(NpcMoveTo, NPC_SELF, -280, 280, 0)
    Call(NpcMoveTo, NPC_SELF, -340, 70, 0)
    Call(NpcMoveTo, NPC_SELF, -260, -140, 0)
    Call(SetNpcSpeed, NPC_SELF, Float(7.0 / DT))
    Call(NpcMoveTo, NPC_SELF, 150, -140, 0)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
    IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
        Call(SetNpcVar, NPC_JrTroopa_01, 0, 1)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_WHALE_MOUTH_OPEN)
            IfEq(AF_MAC_38, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0083)
                Set(AF_MAC_38, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0084)
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0095)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Wait(10)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(30)
            Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_0096)
        CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Port_00AC)
    EndSwitch
    ExecWait(N(EVS_ArtifactPrompt_Kolorado))
    ExecWait(N(EVS_LetterPrompt_Kolorado))
    ExecWait(N(EVS_LetterReward_Kolorado))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            Call(SetNpcPos, NPC_SELF, -380, -10, 372)
            Call(NpcFaceNpc, NPC_SELF, NPC_Whale, 0)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
        CaseEq(STORY_CH5_TRADED_VASE_FOR_SEED)
            Call(SetSelfVar, 0, 0)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
        CaseDefault
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(EnableNpcShadow, NPC_SELF, FALSE)
    EndSwitch
    Return
    End
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
    Loop(0)
        Call(N(func_802431B0_855320))
        Wait(5)
    EndLoop
    Return
    End
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
    Call(SetSelfVar, 0, 0)
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Wait(45)
    Exec(N(EVS_80244298))
    Call(PlaySound, SOUND_LOOP_JR_TROOPA_SWIM)
    ExecGetTID(N(D_8024BCBC_85DE2C), LVar9)
    Call(SetNpcPos, NPC_SELF, 150, -30, 490)
    Wait(5)
    Thread
        Call(InterpPlayerYaw, 90, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
        Wait(20)
        Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
        Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EndThread
    Call(ShowMessageAtScreenPos, MSG_MAC_Port_00B4, 160, 40)
    Call(UseSettingsFrom, CAM_DEFAULT, -100, -10, 490)
    Call(SetPanTarget, CAM_DEFAULT, -100, -10, 490)
    Call(SetCamDistance, CAM_DEFAULT, 700)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Call(NpcMoveTo, NPC_SELF, -40, 490, 0)
    KillThread(LVar9)
    Call(StopSound, SOUND_LOOP_JR_TROOPA_SWIM)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SPLASH, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o236, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.5))
    Call(NpcJump0, NPC_SELF, -100, -10, 490, 15)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_OutOfBreath)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kujira, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o236, COLLIDER_FLAGS_UPPER_MASK)
    Wait(10)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-7.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_OutOfBreath, 0, MSG_MAC_Port_00B5)
    Call(SetCamDistance, CAM_DEFAULT, 225)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_OutOfBreath, 0, MSG_MAC_Port_00B6)
    Call(SetPanTarget, CAM_DEFAULT, -250, -10, 490)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Walk)
    Call(NpcMoveTo, NPC_SELF, -255, 490, 75)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_OutOfBreath)
    Wait(10)
    Thread
        Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_RunBack, ANIM_JrTroopa_RunBack, 0, MSG_MAC_Port_00B7)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_RunBack)
    Wait(15)
    Thread
        Call(N(func_80243254_8553C4), -1, LVar0, LVar2)
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 45)
    EndThread
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_JrTroopa_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_MAC_Port_00BD)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_JrTroopa_01) = {
    Call(DisablePartnerAI, 0)
    Set(GF_MAC01_Defeated_JrTroopa4, TRUE)
    Call(SetPlayerPos, -340, -10, 380)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, -360, LVar1, 390)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcPos, NPC_SELF, -300, -10, 380)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_JrTroopa_02, LVar0, LVar1, LVar2)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(SetNpcYaw, NPC_JrTroopa_02, 270)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Defeated)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 0, MSG_MAC_Port_00BE)
    Call(FadeOutMusic, 0, 2000)
    Call(EnablePartnerAI)
    Return
    End
};

EvtScript N(EVS_NpcHit_JrTroopa_02) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(DisablePlayerInput, TRUE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_MAC_Port_00BD)
            Call(DisablePlayerInput, FALSE)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_JrTroopa_01)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_JrTroopa_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa_02) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_JrTroopa_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Fuzzipede1) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_004E)
                Set(LVar1, MSG_MAC_Port_005B)
            Else
                Set(LVar0, MSG_MAC_Port_004F)
                Set(LVar1, MSG_MAC_Port_005C)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0050)
            Set(LVar1, MSG_MAC_Port_005D)
    EndSwitch
    Call(SpeakToNpc, NPC_Fishmael, ANIM_Fishmael_Talk, ANIM_Fishmael_Idle, 0, NPC_Fuzzipede, LVar0)
    Call(SpeakToNpc, NPC_Fuzzipede, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, NPC_Fishmael, LVar1)
    ExecWait(N(EVS_LetterPrompt_Fishmael))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Fishmael) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_0051)
            Else
                Set(LVar0, MSG_MAC_Port_0052)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0053)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_0054)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0055)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_0056)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0057)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_0058)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0059)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_005A)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Fishmael_Talk, ANIM_Fishmael_Idle, 0, LVar0)
    ExecWait(N(EVS_LetterPrompt_Fishmael))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Fuzzipede2) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_005E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_005F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0060)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_0061)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0062)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_0063)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Fishmael) = {
    Call(SetNpcCollisionSize, NPC_SELF, 38, 38)
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Fuzzipede1)))
    Else
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 0)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Fishmael)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzipede) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Fuzzipede1)))
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseDefault
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 0)
            Call(SetNpcPos, NPC_SELF, -575, 40, 120)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Fuzzipede2)))
        CaseDefault
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_001A)
            Else
                Set(LVar0, MSG_MAC_Port_001B)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_001C)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_001D)
            Else
                Set(LVar0, MSG_MAC_Port_001E)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_001F)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_0020)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0021)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_0022)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0023)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_0024)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0025)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_0026)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_04)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_0027)
            Else
                Set(LVar0, MSG_MAC_Port_0028)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0029)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_002A)
            Else
                Set(LVar0, MSG_MAC_Port_002B)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_002C)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_002D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_002E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_002F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0030)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_0031)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0032)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_0033)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_05)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_0034)
            Else
                Set(LVar0, MSG_MAC_Port_0035)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0036)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_0037)
            Else
                Set(LVar0, MSG_MAC_Port_0038)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0039)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_003A)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_003B)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_003C)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_003D)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_003E)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_003F)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_0040)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_06)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_07) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_0041)
            Else
                Set(LVar0, MSG_MAC_Port_0042)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0043)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_0044)
            Else
                Set(LVar0, MSG_MAC_Port_0045)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0046)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_0047)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0048)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_0049)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_004A)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_004B)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_004C)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_004D)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_07) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_07)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bartender) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_0000)
            Else
                Set(LVar0, MSG_MAC_Port_0001)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0002)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_0003)
            Else
                Set(LVar0, MSG_MAC_Port_0004)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0005)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_0006)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0007)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_0008)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0009)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_000A)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_000B)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_000C)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Bartender_Talk, ANIM_Bartender_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bartender) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bartender)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Port_000D)
            Else
                Set(LVar0, MSG_MAC_Port_000E)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_000F)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Port_0010)
            Else
                Set(LVar0, MSG_MAC_Port_0011)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0012)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Port_0013)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0014)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Port_0015)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Port_0016)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Port_0017)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Port_0018)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Port_0019)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
    Return
    End
};

s32 N(D_8024D704_85F874)[] = {
    104, 0
};

EvtScript N(EVS_NpcInteract_ArtistToad) = {
    Set(GF_MAC05_Met_Simon, TRUE)
    Set(LVarA, 0)
    IfGe(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        IfEq(AF_MAC_3E, TRUE)
            Set(LVarA, 1)
        EndIf
    EndIf
    IfEq(LVarA, 0)
        IfEq(AF_MAC_3D, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0070)
            Set(AF_MAC_3D, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0071)
        EndIf
        Return
    EndIf
    IfEq(GF_MAC05_SimonGaveLyrics, FALSE)
        Call(DisablePartnerAI, 0)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0072)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Musician_Poet_Write)
        Wait(60)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Musician_Poet_Idle)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0073)
        Call(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0074)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0075)
        EVT_GIVE_KEY_REWARD(ITEM_LYRICS)
        Set(GF_MAC05_SimonGaveLyrics, TRUE)
        Call(EnablePartnerAI)
        Return
    EndIf
    IfEq(GF_MAC05_SimonGotMelody, TRUE)
        IfEq(AF_MAC_3D, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0081)
            Set(AF_MAC_3D, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0082)
            Set(AF_MAC_3D, FALSE)
        EndIf
        Return
    EndIf
    Call(FindKeyItem, ITEM_MELODY, LVar0)
    IfEq(LVar0, -1)
        IfEq(AF_MAC_3D, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0076)
            Set(AF_MAC_3D, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0077)
        EndIf
    Else
        Call(DisablePartnerAI, 0)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        IfEq(AF_MAC_3D, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0078)
            Set(AF_MAC_3D, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_0079)
        EndIf
        Set(LVar0, Ref(N(D_8024D704_85F874)))
        Set(LVar1, 10)
        ExecWait(N(EVS_ChooseKeyItem))
        Switch(LVar0)
            CaseEq(-1)
                Call(EnablePartnerAI)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007A)
            CaseDefault
                Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007B)
                Set(GF_MAC05_SimonGotMelody, TRUE)
                Call(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_007C)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007D)
                Call(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_007E)
                Call(SetNpcFlagBits, NPC_Chanterelle, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Thread
                    Call(PlayerMoveTo, 167, -513, 20)
                    Call(InterpPlayerYaw, 270, 0)
                    Wait(10)
                    Call(EnablePartnerAI)
                    Call(func_802CF56C, 2)
                EndThread
                Thread
                    Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Walk)
                    Call(NpcMoveTo, NPC_Chanterelle, 112, -511, 60)
                    Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                EndThread
                Thread
                    Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Walk)
                    Call(NpcMoveTo, NPC_Bartender, 70, -540, 45)
                    Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Idle)
                EndThread
                Call(UseSettingsFrom, CAM_DEFAULT, 112, 0, -511)
                Call(SetPanTarget, CAM_DEFAULT, 112, 0, -511)
                Call(SetCamDistance, CAM_DEFAULT, Float(320.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(InterpNpcYaw, NPC_Toad_02, 90, 0)
                Call(InterpNpcYaw, NPC_ArtistToad, 270, 0)
                Wait(60)
                Exec(N(EVS_802442C4))
                Call(SetPlayerAnimation, ANIM_Mario1_Pray)
                Call(SetNpcAnimation, NPC_Toad_02, ANIM_Toad_Red_Disappointed)
                Call(SetNpcAnimation, NPC_ArtistToad, ANIM_Musician_Poet_Pensive)
                Wait(30)
                Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Talk)
                Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Still)
                Wait(30)
                Call(SetMusicTrack, 0, SONG_POP_DIVA_SONG, 0, 8)
                Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_StrumGuitar)
                Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                Wait(30 * DT)
                Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Sing)
                Wait(150 * DT)
                Wait(150 * DT)
                Wait(150 * DT)
                Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Idle)
                Wait(40 * DT)
                Call(SetNpcAnimation, NPC_Toad_02, ANIM_Toad_Red_Idle)
                Call(SetNpcAnimation, NPC_ArtistToad, ANIM_Musician_Poet_Idle)
                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                Wait(30 * DT)
                Exec(N(EVS_802442E8))
                Thread
                    Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Walk)
                    Call(NpcMoveTo, NPC_Bartender, -85, -520, 40)
                    Call(SetNpcAnimation, NPC_Bartender, ANIM_Bartender_Idle)
                    Call(InterpNpcYaw, NPC_Bartender, 90, 0)
                EndThread
                Thread
                    Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Walk)
                    Call(NpcMoveTo, NPC_Chanterelle, 208, -530, 60)
                    Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
                    Call(InterpNpcYaw, NPC_Chanterelle, 270, 0)
                    Call(InterpNpcYaw, NPC_ArtistToad, 90, 0)
                    Call(InterpPlayerYaw, 90, 0)
                    Wait(10)
                    Call(func_802CF56C, 2)
                    Call(SetNpcFlagBits, NPC_Chanterelle, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EndThread
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 0)
                Wait(60)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 0, MSG_MAC_Port_007F)
                Call(SpeakToPlayer, NPC_Chanterelle, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0080)
                Wait(10)
                Set(LVar0, ITEM_ATTACK_FX_D)
                Set(LVar3, ITEM_TYPE_BADGE)
                ExecWait(N(GiveItemReward))
                Call(AddBadge, LVar0, LVar1)
                Call(SetTattleMessage, NPC_Chanterelle, MSG_NpcTattle_PopDiva_CanSing)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_ArtistToad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ArtistToad)))
    Set(AF_MAC_3D, FALSE)
    Set(AF_MAC_3E, FALSE)
    IfEq(GF_MAC05_Met_Simon, TRUE)
        Set(AF_MAC_3E, TRUE)
    EndIf
    Return
    End
};

API_CALLABLE(N(func_8024335C_8554CC)) {
    if (func_8014AD40() == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(D_8024E23C_8603AC) = {
    Set(AF_JAN01_TreeDrop_StarPiece, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_400000 | ENEMY_FLAG_CANT_INTERACT, 1)
    Call(InterpNpcYaw, NPC_Chanterelle, 270, 0)
    Call(SetMusicTrack, 0, SONG_POP_DIVA_SONG, 1, 8)
    ChildThread
        Wait(30)
        Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Sing)
        Wait(1900)
        Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
    EndChildThread
    ChildThread
        Wait(30)
        Call(N(func_8024335C_8554CC))
        Set(AF_JAN01_TreeDrop_StarPiece, FALSE)
    EndChildThread
    Loop(0)
        IfEq(AF_JAN01_TreeDrop_StarPiece, FALSE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Exec(N(EVS_802442E8))
    Call(SetNpcAnimation, NPC_Chanterelle, ANIM_Chanterelle_Idle)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_400000 | ENEMY_FLAG_CANT_INTERACT, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Chanterelle) = {
    IfEq(GF_MAC05_SimonGaveLyrics, FALSE)
        IfEq(AF_MAC_3F, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0068)
            Set(AF_MAC_3F, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_0069)
            Set(AF_MAC_3F, FALSE)
        EndIf
        Return
    EndIf
    IfEq(GF_MAC05_SimonGotMelody, FALSE)
        IfEq(AF_MAC_3F, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006A)
            Set(AF_MAC_3F, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006B)
            Set(AF_MAC_3F, FALSE)
        EndIf
        Return
    EndIf
    IfEq(AF_MAC_3F, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006C)
        Set(AF_MAC_3F, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006D)
    EndIf
    Call(ShowChoice, MSG_Choice_000D)
    IfNe(LVar0, 0)
        Call(ContinueSpeech, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006E)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 0, MSG_MAC_Port_006F)
        Exec(N(D_8024E23C_8603AC))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Chanterelle) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Chanterelle)))
    IfEq(GF_MAC05_SimonGotMelody, TRUE)
        Call(SetTattleMessage, NPC_Chanterelle, MSG_NpcTattle_PopDiva_CanSing)
    EndIf
    Return
    End
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
    Set(LVar0, 7)
    Call(N(CheckTradeEventTime))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00BF)
        Return
    EndIf
    Call(N(GetTradeEventItemCount))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C0)
        Wait(10)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Set(GF_TradingEvent3_Active, FALSE)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C1)
    Set(LVar0, 0)
    Set(LVar1, 11)
    ExecWait(N(EVS_ChooseItem))
    Switch(LVar0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C5)
            Return
        CaseEq(ITEM_COCONUT)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C2)
            EVT_GIVE_CONSUMABLE_REWARD(ITEM_YUMMY_MEAL)
            Wait(10)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C3)
            Wait(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Set(GF_TradingEvent3_Active, FALSE)
            Add(GB_TradingEvent_Count, 1)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Port_00C4)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TradeEventToad) = {
    IfNe(GF_TradingEvent3_Active, FALSE)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_03)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
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
