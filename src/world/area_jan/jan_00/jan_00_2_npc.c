#include "jan_00.h"
#include "effects.h"
#include "npc.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Kolorado_01) = {
    .height = 24,
    .radius = 48,
    .level = 99,
};

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/JrTroopa.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH5_001D, MSG_CH5_001E, MSG_CH5_001F, MSG_CH5_0020,
        EVT_PTR(N(LetterList)))
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

API_CALLABLE(func_80240B4C_B2108C) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s1 = evt_get_variable(script, *args++);
    Npc* npc;
    f32 temp_f20;
    f32 var_f22;
    f32 x, y, z;
    s32 outX, outY, outZ;

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;

    outX = *args++;
    outY = *args++;
    outZ = *args++;
    npc = get_npc_safe(NPC_Whale);

    switch (temp_s1) {
        case 0:
            var_f22 = 130.0f;
            break;
        case 1:
            var_f22 = 160.0f;
            break;
        case 2:
            var_f22 = 100.0f;
            break;
        default:
            var_f22 = 80.0f;
            break;
    }
    if (temp_s1 < 4) {
        temp_f20 = -npc->yaw;
        x = npc->pos.x + 30.0f + sin_deg(temp_f20) * var_f22;
        z = npc->pos.z + cos_deg(temp_f20) * var_f22;
        y = npc->pos.y + 50.0f;
    }
    evt_set_float_variable(script, outX, x);
    evt_set_float_variable(script, outY, y);
    evt_set_float_variable(script, outZ, z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240CF8_B21238)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc0 = get_npc_safe(NPC_Whale);
    Npc* npc1;
    Npc* partner;
    f32 theta;
    f32 x, y, z;
    f32 temp_f22;

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
    temp_f22 = script->functionTemp[1];
    theta = -npc0->yaw;
    x = ((npc0->pos.x + 30.0f) - 75.0f) + (sin_deg(theta) * temp_f22);
    z = npc0->pos.z + (cos_deg(theta) * temp_f22);
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
            npc1 = get_npc_safe(NPC_Kolorado_02);
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

API_CALLABLE(N(func_80240F14_B21454)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(NPC_Whale);

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        switch (script->functionTemp[0]) {
            case 0:
                script->functionTemp[2] = 0;
                script->functionTemp[1] = 90;
                npc->pos.x = 158.0f;
                npc->pos.y = -50.0f;
                npc->pos.z = -38.0f;
                break;
            case 1:
                script->functionTemp[2] = 10;
                script->functionTemp[1] = 200;
                npc->pos.x = -442.0f;
                npc->pos.y = -50.0f;
                npc->pos.z = -38.0f;
                break;
        }
    }

    switch (script->functionTemp[2]) {
        case 0:
            npc->curAnim = 0xB60001;
            npc->yaw -= 1.0f;
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 1;
                script->functionTemp[1] = 90;
            }
            break;
        case 1:
            npc->yaw -= 1.0f;
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 2;
                script->functionTemp[1] = 120;
            }
            break;
        case 2:
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                return ApiStatus_DONE2;
            }
            break;
        case 10:
            npc->yaw = 90.0f;
            npc->pos.x += 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(func_80241134_B21674) {
    Npc* npc = get_npc_safe(NPC_JrTroopa);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z - 20.0f;

    if (y < 0.0f) {
        fx_rising_bubble(0, x, y, z, 0.0f);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(D_80242D90_B232D0) = {
    EVT_CALL(N(func_80240CF8_B21238), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242DB0_B232F0) = {
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
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar0, -300)
        EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ELSE
        EVT_SET(LVar3, LVar0)
        EVT_SUB(LVar3, -300)
        EVT_CALL(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, LVar3)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242FA8_B234E8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 310)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 310)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(5.0), EVT_FLOAT(0.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(60)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 180, 0, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.4))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_SET(LVar0, 0)
    EVT_EXEC_GET_TID(N(D_80242D90_B232D0), LVar3)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(D_80242D90_B232D0), LVar4)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_SET(LVar0, 2)
        EVT_EXEC_GET_TID(N(D_80242D90_B232D0), LVar5)
    EVT_END_IF
    EVT_CALL(N(func_80240F14_B21454), 1)
    EVT_KILL_THREAD(LVar3)
    EVT_KILL_THREAD(LVar4)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_KILL_THREAD(LVar5)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_CALL(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        EVT_CALL(NpcMoveTo, NPC_Kolorado_02, LVar0, LVar2, 10)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Thrown)
        EVT_CALL(SetNpcJumpscale, NPC_Kolorado_02, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Kolorado_02, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_Kolorado_02, 224, 0, 20, 20)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        EVT_CALL(NpcMoveTo, NPC_Kolorado_02, 290, 20, 20)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Idle)
        EVT_CALL(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 270, 0)
    EVT_END_IF
    EVT_CALL(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 224, 0, 20, 20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
    EVT_CALL(PlayerMoveTo, 260, 20, 15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 20)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_PARTNER, 224, 0, 20, 20)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_WAIT(10)
        EVT_CALL(DisablePartnerAI, 0)
    EVT_END_IF
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 230, 20, 10)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_TalkSad)
    EVT_CALL(SetNpcJumpscale, NPC_Whale, 0)
    EVT_CALL(NpcJump0, NPC_Whale, 158, -10, -38, 20)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_CH5_0000)
    EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), 0, 300, 15, EVT_FLOAT(-6.0))
        EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 90, 0)
        EVT_WAIT(20)
        EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 1, MSG_CH5_0001)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 270, 4)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 90, 4)
        EVT_WAIT(15)
        EVT_THREAD
            EVT_CALL(PlaySoundAtNpc, NPC_Kolorado_02, SOUND_32C, SOUND_SPACE_MODE_0)
            EVT_CALL(GetNpcPos, NPC_Kolorado_02, LVar0, LVar1, LVar2)
            EVT_CALL(NpcJump0, NPC_Kolorado_02, LVar0, LVar1, LVar2, 15)
            EVT_WAIT(25)
            EVT_CALL(NpcFacePlayer, NPC_Kolorado_02, 4)
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 5, MSG_CH5_0002)
        EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Idle)
        EVT_CALL(SetNpcSpeed, NPC_Kolorado_02, EVT_FLOAT(6.0))
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        EVT_CALL(NpcMoveTo, NPC_Kolorado_02, 330, 190, 0)
        EVT_CALL(SetNpcPos, NPC_Kolorado_02, NPC_DISPOSE_LOCATION)
        EVT_SET(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_SETF(LVar9, EVT_FLOAT(4.0))
    EVT_ELSE
        EVT_SETF(LVar9, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC(N(D_80245860_B25DA0))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(ResetCam, CAM_DEFAULT, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802437C4_B23D04) = {
    EVT_LABEL(0)
    EVT_CALL(GetNpcYaw, NPC_Whale, LVar0)
    EVT_CALL(InterpPlayerYaw, LVar0, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado_01) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, 0, 200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 0, 200)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC(N(D_80242FA8_B234E8))
    EVT_RETURN
    EVT_END
};

Vec3f N(D_802438E4_B23E24)[] = {
    {  290.0,     0.0,   20.0 },
    {  245.0,     6.0,  -35.0 },
    {  190.0,    10.0,  -50.0 },
};

EvtScript N(EVS_NpcInteract_Kolorado_01) = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_CH5_0003)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_CH5_0005)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EndSpeech, NPC_SELF, -1, -1, 5)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_CALL(NpcFacePlayer, NPC_Kolorado_02, 0)
    EVT_END_IF
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, 158, -50, -38, 20)
    EVT_SET(LVar0, 0)
    EVT_EXEC(N(D_80242DB0_B232F0))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 20)
    EVT_CALL(func_80240B4C_B2108C, 0, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 10)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_THREAD
        EVT_CALL(N(func_80240CF8_B21238), 0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar3, LVar5, 20)
    EVT_CALL(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 18)
    EVT_CALL(func_80240B4C_B2108C, 1, LVar0, LVar1, LVar2)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 18)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_THREAD
        EVT_CALL(N(func_80240CF8_B21238), 1)
    EVT_END_THREAD
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        EVT_CALL(LoadPath, 20, EVT_PTR(N(D_802438E4_B23E24)), ARRAY_COUNT(N(D_802438E4_B23E24)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Kolorado_02, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_80240B4C_B2108C, 2, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Thrown)
        EVT_CALL(SetNpcJumpscale, NPC_Kolorado_02, EVT_FLOAT(0.5))
        EVT_CALL(PlaySoundAtNpc, NPC_Kolorado_02, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_Kolorado_02, LVar0, LVar1, LVar2, 20)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 90, 0)
        EVT_THREAD
            EVT_CALL(N(func_80240CF8_B21238), 2)
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0007)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_IF_EQ(GF_MAC01_Defeated_JrTroopa4, TRUE)
            EVT_GOTO(90)
        EVT_END_IF
        EVT_CALL(SetNpcVar, NPC_JrTroopa, 0, 1)
        EVT_LOOP(0)
            EVT_CALL(GetNpcVar, NPC_JrTroopa, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_EXEC(N(D_802437C4_B23D04))
        EVT_CALL(N(func_80240F14_B21454), 0)
        EVT_CALL(EnableGroup, MODEL_kujira, FALSE)
    EVT_ELSE
        EVT_LABEL(90)
        EVT_EXEC(N(D_802437C4_B23D04))
        EVT_CALL(N(func_80240F14_B21454), 0)
        EVT_CALL(EnableGroup, MODEL_kujira, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("mac_06"), mac_06_ENTRY_1)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado_01) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_NO_SPRITE, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Still)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_00_ENTRY_0)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado_01)))
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado_01)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 158, -10, -38)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado_01)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0006)
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado_02) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_CALL(SetNpcPos, NPC_SELF, 290, 0, 20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado_02)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802441C8_B24708) = {
    EVT_LOOP(0)
        EVT_CALL(PlayerFaceNpc, NPC_JrTroopa, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_Kolorado_02, NPC_JrTroopa, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_JrTroopa, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, 0xFFFFFFFF, 0xFFFFFFFF, 5, MSG_CH5_0008)
    EVT_EXEC_GET_TID(N(D_802441C8_B24708), LVar9)
    EVT_CALL(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_80000055, SOUND_SPACE_MODE_0)
    EVT_THREAD
        EVT_CALL(func_80241134_B21674)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 85, 0, 320)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 85, 0, 320)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(22.5), EVT_FLOAT(-12.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(23.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 80, 90, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 0, 90)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(14.5), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.7))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(StopSound, SOUND_80000055)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SPLASH, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_SELF, 250, 0, 90, 20)
    EVT_KILL_THREAD(LVar9)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetSelfVar, 0, 2)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_OutOfBreath)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_OutOfBreath, 5, MSG_CH5_0009)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_OutOfBreath, 0, MSG_CH5_000A)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Panic)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(NpcJump0, NPC_SELF, 250, 0, 90, 10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Panic, ANIM_JrTroopa_Panic, 0, MSG_CH5_000B)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp, ANIM_JrTroopa_Charge, 0, MSG_CH5_000C)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 85, 0, 320)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 85, 0, 320)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(24.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.5))
    EVT_CALL(NpcJump0, NPC_SELF, 80, -50, 90, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SPLASH, SOUND_SPACE_MODE_0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, -20, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_80000055, SOUND_SPACE_MODE_0)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -555, -32, 0)
    EVT_END_THREAD
    EVT_WAIT(100)
    EVT_CALL(GotoMap, EVT_PTR("mac_06"), mac_06_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    EVT_IF_EQ(GF_MAC01_Defeated_JrTroopa4, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, -530, -50, 20)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Whale,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado_01),
        .settings = &N(NpcSettings_Kolorado_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Whale,
    },
    {
        .id = NPC_Kolorado_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado_02),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_JrTroopa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
    },
};

NpcData N(NpcData_HeartPlant_01) = {
    .id = NPC_HeartPlant_01,
    .pos = { 455.0f, 0.0f, 115.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_02) = {
    .id = NPC_HeartPlant_02,
    .pos = { 167.0f, 0.0f, 404.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_03) = {
    .id = NPC_HeartPlant_03,
    .pos = { 90.0f, 0.0f, 316.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_04) = {
    .id = NPC_HeartPlant_04,
    .pos = { 424.0f, 0.0f, 182.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_05) = {
    .id = NPC_HeartPlant_05,
    .pos = { 143.0f, 0.0f, 260.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    NPC_GROUP(N(NpcData_HeartPlant_01)),
    NPC_GROUP(N(NpcData_HeartPlant_02)),
    NPC_GROUP(N(NpcData_HeartPlant_03)),
    NPC_GROUP(N(NpcData_HeartPlant_04)),
    NPC_GROUP(N(NpcData_HeartPlant_05)),
    {}
};
