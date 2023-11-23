#include "sam_06.h"
#include "model.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Wander.inc.c"

MobileAISettings N(AISettings_Ninji_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Ninji_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Ninji_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Ninji_Wander) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Ninji_Wander),
};

MobileAISettings N(AISettings_ShiverToad_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShiverToad_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_ShiverToad_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ShiverToad_Wander) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_ShiverToad_Wander),
};

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/npc/StarSpirit_Wander.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

NpcSettings N(NpcSettings_Ninji_Stationary) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_ShiverToad_Stationary) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/GiveReward.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#if VERSION_PAL
#include "sprite/npc/ShiverToad.h"
#define TOADHOUSE_ANIM_TALK ANIM_ShiverToad_Red_Talk
#define TOADHOUSE_ANIM_IDLE ANIM_ShiverToad_Red_Idle
#endif

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_FrostT)[] = {
    ITEM_LETTER_CHAIN_FROST_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_FrostT) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_ShiverToad_03, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle,
        ITEM_LETTER_CHAIN_FROST_T, ITEM_LETTER_CHAIN_GOOMPAPA_2,
        MSG_CH7_00FE, MSG_CH7_00FF, MSG_CH7_0100, MSG_CH7_0101,
        EVT_PTR(N(LetterList_FrostT)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Merle) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F4)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F5)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_SAM06_Merle_HeardLongerMessage, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F6)
                EVT_SET(GF_SAM06_Merle_HeardLongerMessage, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F7)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Merle_CarryScarf) = {
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 15)
        EVT_CALL(GetNpcYaw, NPC_Merle, LVar3)
        EVT_IF_GE(LVar3, 90)
            EVT_IF_LE(LVar3, 270)
                EVT_ADD(LVar2, 10)
            EVT_ELSE
                EVT_ADD(LVar2, -10)
            EVT_END_IF
        EVT_ELSE
            EVT_ADD(LVar2, -10)
        EVT_END_IF
        EVT_CALL(SetItemPos, MV_ScarfItemID, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Merle_HandOverScarf) = {
    EVT_SET(LVar4, 10)
    EVT_LOOP(10)
        EVT_CALL(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 15)
        EVT_CALL(GetNpcYaw, NPC_Merle, LVar3)
        EVT_IF_GE(LVar3, 90)
            EVT_IF_LE(LVar3, 270)
                EVT_ADD(LVar2, LVar4)
            EVT_ELSE
                EVT_SUB(LVar2, LVar4)
            EVT_END_IF
        EVT_ELSE
            EVT_SUB(LVar2, LVar4)
        EVT_END_IF
        EVT_CALL(SetItemPos, MV_ScarfItemID, LVar0, LVar1, LVar2)
        EVT_ADD(LVar4, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Merle_Greeting) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_WAIT(1)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_LAKILESTER)
        EVT_CALL(InterruptUsePartner)
        EVT_CALL(WaitForPlayerTouchingFloor)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, -240, 300, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Merle, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00E9)
    EVT_CALL(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EA)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 0, 300)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, 0, 300)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Merle, -110, 300, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EVT_CALL(GetAngleToPlayer, NPC_Merle, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Merle, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EB)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(AF_SAM_05, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(MF_MerleReady, FALSE)
    EVT_THREAD
        EVT_CALL(BindNpcInteract, NPC_Merle, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Merle, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(2.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Merle, -78, 287, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Merle, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_Merle, -25, 20, 253, 17)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(NpcJump0, NPC_Merle, -40, 45, 188, 17)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(NpcMoveTo, NPC_Merle, -90, 190, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        EVT_SET(MF_MerleReady, TRUE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Merle_WaitingOnHill) = {
    EVT_LABEL(60)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, ACTION_STATE_JUMP)
        EVT_GOTO(60)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ACTION_STATE_FALLING)
        EVT_GOTO(60)
    EVT_END_IF
    EVT_IF_LT(LVar1, -60)
        EVT_GOTO(60)
    EVT_END_IF
    EVT_IF_LT(LVar2, 20)
        EVT_GOTO(60)
    EVT_END_IF
    EVT_IF_GT(LVar3, 300)
        EVT_GOTO(60)
    EVT_END_IF
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_LAKILESTER)
        EVT_CALL(InterruptUsePartner)
        EVT_CALL(WaitForPlayerTouchingFloor)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_MerleReady, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerFaceNpc, NPC_Merle, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EC)
    EVT_SET(GB_StoryProgress, STORY_CH7_MERLE_APOLOGIZED)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(MF_MerleReady, FALSE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(NpcMoveTo, NPC_Merle, -110, 145, 0)
        EVT_CALL(NpcJump0, NPC_Merle, -131, 60, 91, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(NpcJump0, NPC_Merle, -117, 90, 7, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(NpcMoveTo, NPC_Merle, 0, -143, 0)
        EVT_CALL(InterpNpcYaw, NPC_Merle, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        EVT_SET(MF_MerleReady, TRUE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_80242538_D223C8)) {
    s32 alpha;

    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 32;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = 255 - script->functionTemp[0];
    }

    mdl_set_shroud_tint_params(0, 0, 0, alpha);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 3) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_NONE, TRUE);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Scene_Merle_EnterHouse) = {
    EVT_CALL(AwaitPlayerApproach, 0, -140, 60)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_LAKILESTER)
        EVT_CALL(InterruptUsePartner)
        EVT_CALL(WaitForPlayerTouchingFloor)
    EVT_END_IF
    EVT_CALL(WaitForPlayerTouchingFloor)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_MerleReady, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MF_MerleReady, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00ED)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Merle, 27, -120, 0)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 15, -90, 0)
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_OUT)
    EVT_LABEL(70)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(70)
        EVT_END_IF
    EVT_SET(AF_SAM_Snowing, FALSE)
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(4.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Merle, 0, -330, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.8 / DT))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k_d1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k_d2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlayerMoveTo, 0, -200, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVarF, MODEL_k)
        EVT_CALL(SetNpcFlagBits, NPC_Merle, NPC_FLAG_HIDING, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_StarKid_03, NPC_FLAG_HIDING, TRUE)
        EVT_CALL(N(func_80242538_D223C8))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
        EVT_LABEL(71)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_km_yane, LVar0, 0, 0, 1)
            EVT_CALL(RotateGroup, MODEL_km_sita, LVar0, 0, 0, -1)
            EVT_SET(LVar2, 90)
            EVT_SUB(LVar2, LVar0)
            EVT_CALL(RotateModel, MODEL_km_doa, LVar2, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(71)
            EVT_END_IF
        EVT_CALL(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_HIDDEN)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 0, -240, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k_d1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k_d2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(GetAngleToPlayer, NPC_Merle, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Merle, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EE)
    EVT_CALL(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(200.7), EVT_FLOAT(-321.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(0.7), EVT_FLOAT(-321.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(21.0), EVT_FLOAT(-14.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EF)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(200.7), EVT_FLOAT(-250.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(0.7), EVT_FLOAT(-250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(21.0), EVT_FLOAT(-14.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(2.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    EVT_EXEC_GET_TID(N(EVS_Merle_CarryScarf), LVarA)
    EVT_CALL(NpcMoveTo, NPC_Merle, 0, -275, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_EXEC_GET_TID(N(EVS_Merle_HandOverScarf), LVarA)
    EVT_WAIT(20 * DT)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetItemPos, MV_ScarfItemID, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_GIVE_KEY_REWARD(ITEM_SNOWMAN_SCARF)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F1)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(200.7), EVT_FLOAT(-321.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(0.7), EVT_FLOAT(-321.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.7))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(2.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merle, 0, -330, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EVT_CALL(GetAngleToPlayer, NPC_Merle, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Merle, LVar0, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(BindNpcInteract, NPC_Merle, EVT_PTR(N(EVS_NpcInteract_Merle)))
    EVT_CALL(SetNpcFlagBits, NPC_Merle, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Merle) = {
    EVT_WAIT(3)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
        EVT_EXEC_WAIT(N(EVS_Scene_Merle_Greeting))
        EVT_EXEC_WAIT(N(EVS_Scene_Merle_WaitingOnHill))
        EVT_EXEC_WAIT(N(EVS_Scene_Merle_EnterHouse))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
        EVT_CALL(SetNpcPos, NPC_Merle, -90, 45, 190)
        EVT_CALL(InterpNpcYaw, NPC_Merle, 270, 0)
        EVT_SET(MF_MerleReady, TRUE)
        EVT_EXEC_WAIT(N(EVS_Scene_Merle_WaitingOnHill))
        EVT_EXEC_WAIT(N(EVS_Scene_Merle_EnterHouse))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_MERLE_APOLOGIZED)
        EVT_CALL(SetNpcPos, NPC_Merle, 0, 90, -143)
        EVT_CALL(InterpNpcYaw, NPC_Merle, 270, 0)
        EVT_SET(MF_MerleReady, TRUE)
        EVT_EXEC_WAIT(N(EVS_Scene_Merle_EnterHouse))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Merle_OneLastThing) = {
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -28, -80, 0)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 0, -100, 0)
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    EVT_CALL(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_VISIBLE)
    EVT_CALL(SetNpcPos, NPC_Merle, 0, 90, -180)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merle, 40, -140, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EVT_CALL(MakeLerp, 90, 0, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerFaceNpc, NPC_Merle, FALSE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Merle, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F3)
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(SetNpcSpeed, NPC_Merle, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merle, 0, -180, 0)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Merle, 0, -300, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 90, 0, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(3)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(3)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(AF_SAM_05, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShiverToad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Red_Talk, ANIM_ShiverToad_Red_Idle, 0, MSG_CH7_00F8)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Red_Talk, ANIM_ShiverToad_Red_Idle, 0, MSG_CH7_00F9)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShiverToad_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Blue_Talk, ANIM_ShiverToad_Blue_Idle, 0, MSG_CH7_00FA)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Blue_Talk, ANIM_ShiverToad_Blue_Idle, 0, MSG_CH7_00FB)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShiverToad_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle, 0, MSG_CH7_00FC)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle, 0, MSG_CH7_00FD)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_FrostT))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Ninji_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0102)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0103)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Ninji_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0104)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0105)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Ninji_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0106)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0107)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Ninji_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0114)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0115)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0108)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0109)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010A)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_03) = {
    EVT_IF_EQ(GF_SAM06_FoundSidewaysStarKid, FALSE)
        EVT_SET(GF_SAM06_FoundSidewaysStarKid, TRUE)
        EVT_CALL(MakeLerp, 90, 360, 20, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010C)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010D)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010E)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010F)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0110)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0111)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0112)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0113)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_CH7_0116)
    EVT_SET(LVar8, MSG_CH7_0117)
    EVT_SET(LVar1, MSG_CH7_0118)
    EVT_SET(LVar2, MSG_CH7_0119)
    EVT_SET(LVar3, MSG_CH7_011A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -336, -48, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, EVT_FLOAT(40.0))
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(50.0), EVT_FLOAT(-16.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(111.0))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-92.0), EVT_FLOAT(94.0))
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-318.1), EVT_FLOAT(-35.5))
        EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(-641.0), EVT_FLOAT(122.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -347, -114, 0)
    EVT_CALL(InterpPlayerYaw, 229, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(81)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(PlayerMoveTo, -347, -114, 0)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -309, -16, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Merle) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Merle)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Merle)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_SCARF)
            EVT_CALL(SetNpcPos, NPC_SELF, -200, 0, 300)
        EVT_CASE_GE(STORY_CH7_GOT_SNOWMAN_SCARF)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 90, -300)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 180, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShiverToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShiverToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShiverToad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShiverToad_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShiverToad_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShiverToad_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Ninji_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Ninji_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Ninji_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Ninji_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Ninji_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Ninji_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Ninji_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Ninji_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_03)))
    EVT_IF_EQ(GF_SAM06_FoundSidewaysStarKid, FALSE)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 90, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_06)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShiverToad_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Merle)[] = {
    {
        .id = NPC_Merle,
        .pos = { 0.0f, 90.0f, -300.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Merle),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merle_Idle,
            .walk   = ANIM_Merle_Idle,
            .run    = ANIM_Merle_Idle,
            .chase  = ANIM_Merle_Idle,
            .anim_4 = ANIM_Merle_Idle,
            .anim_5 = ANIM_Merle_Idle,
            .death  = ANIM_Merle_Idle,
            .hit    = ANIM_Merle_Idle,
            .anim_8 = ANIM_Merle_Idle,
            .anim_9 = ANIM_Merle_Idle,
            .anim_A = ANIM_Merle_Idle,
            .anim_B = ANIM_Merle_Idle,
            .anim_C = ANIM_Merle_Idle,
            .anim_D = ANIM_Merle_Idle,
            .anim_E = ANIM_Merle_Idle,
            .anim_F = ANIM_Merle_Idle,
        },
        .tattle = MSG_NpcTattle_Merle,
    },
    {
        .id = NPC_ShiverToad_01,
        .pos = { -376.0f, 60.0f, 112.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ShiverToad_01),
        .settings = &N(NpcSettings_ShiverToad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Red_Idle,
            .walk   = ANIM_ShiverToad_Red_Walk,
            .run    = ANIM_ShiverToad_Red_Idle,
            .chase  = ANIM_ShiverToad_Red_Idle,
            .anim_4 = ANIM_ShiverToad_Red_Idle,
            .anim_5 = ANIM_ShiverToad_Red_Idle,
            .death  = ANIM_ShiverToad_Red_Idle,
            .hit    = ANIM_ShiverToad_Red_Idle,
            .anim_8 = ANIM_ShiverToad_Red_Idle,
            .anim_9 = ANIM_ShiverToad_Red_Idle,
            .anim_A = ANIM_ShiverToad_Red_Idle,
            .anim_B = ANIM_ShiverToad_Red_Idle,
            .anim_C = ANIM_ShiverToad_Red_Idle,
            .anim_D = ANIM_ShiverToad_Red_Idle,
            .anim_E = ANIM_ShiverToad_Red_Idle,
            .anim_F = ANIM_ShiverToad_Red_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_ShiverToadA,
    },
    {
        .id = NPC_ShiverToad_02,
        .pos = { 208.0f, 80.0f, 150.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 208, 80, 150 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_ShiverToad_02),
        .settings = &N(NpcSettings_ShiverToad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Blue_Idle,
            .walk   = ANIM_ShiverToad_Blue_Walk,
            .run    = ANIM_ShiverToad_Blue_Idle,
            .chase  = ANIM_ShiverToad_Blue_Idle,
            .anim_4 = ANIM_ShiverToad_Blue_Idle,
            .anim_5 = ANIM_ShiverToad_Blue_Idle,
            .death  = ANIM_ShiverToad_Blue_Idle,
            .hit    = ANIM_ShiverToad_Blue_Idle,
            .anim_8 = ANIM_ShiverToad_Blue_Idle,
            .anim_9 = ANIM_ShiverToad_Blue_Idle,
            .anim_A = ANIM_ShiverToad_Blue_Idle,
            .anim_B = ANIM_ShiverToad_Blue_Idle,
            .anim_C = ANIM_ShiverToad_Blue_Idle,
            .anim_D = ANIM_ShiverToad_Blue_Idle,
            .anim_E = ANIM_ShiverToad_Blue_Idle,
            .anim_F = ANIM_ShiverToad_Blue_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_ShiverToadB,
    },
    {
        .id = NPC_ShiverToad_03,
        .pos = { 127.0f, 0.0f, 445.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_ShiverToad_03),
        .settings = &N(NpcSettings_ShiverToad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Green_Idle,
            .walk   = ANIM_ShiverToad_Green_Walk,
            .run    = ANIM_ShiverToad_Green_Idle,
            .chase  = ANIM_ShiverToad_Green_Idle,
            .anim_4 = ANIM_ShiverToad_Green_Idle,
            .anim_5 = ANIM_ShiverToad_Green_Idle,
            .death  = ANIM_ShiverToad_Green_Idle,
            .hit    = ANIM_ShiverToad_Green_Idle,
            .anim_8 = ANIM_ShiverToad_Green_Idle,
            .anim_9 = ANIM_ShiverToad_Green_Idle,
            .anim_A = ANIM_ShiverToad_Green_Idle,
            .anim_B = ANIM_ShiverToad_Green_Idle,
            .anim_C = ANIM_ShiverToad_Green_Idle,
            .anim_D = ANIM_ShiverToad_Green_Idle,
            .anim_E = ANIM_ShiverToad_Green_Idle,
            .anim_F = ANIM_ShiverToad_Green_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_ShiverToadC,
    },
    {
        .id = NPC_Ninji_01,
        .pos = { -99.0f, 90.0f, -90.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -99, 90, -90 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Ninji_01),
        .settings = &N(NpcSettings_Ninji_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiA,
    },
    {
        .id = NPC_Ninji_02,
        .pos = { -48.0f, 0.0f, 400.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -48, 0, 400 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Ninji_02),
        .settings = &N(NpcSettings_Ninji_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiB,
    },
    {
        .id = NPC_Ninji_03,
        .pos = { 239.0f, 50.0f, 315.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Ninji_03),
        .settings = &N(NpcSettings_Ninji_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiC,
    },
    {
        .id = NPC_Ninji_04,
        .pos = { 390.0f, 80.0f, 50.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Ninji_04),
        .settings = &N(NpcSettings_Ninji_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiD,
    },
    {
        .id = NPC_StarKid_01,
        .pos = { -166.0f, 10.0f, 390.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -166, 10, 390 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_StarKid_01),
        .settings = &N(NpcSettings_StarKid_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidA,
    },
    {
        .id = NPC_StarKid_02,
        .pos = { 3.0f, 60.0f, 137.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_02),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidB,
    },
    {
        .id = NPC_StarKid_03,
        .pos = { 120.0f, 100.0f, -210.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarKid_03),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_PranksterStarKid,
    },
    {
        .id = NPC_StarKid_04,
        .pos = { 369.0f, 90.0f, 9.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_04),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_BabyStarKid,
    },
    {
        .id = NPC_StarKid_05,
        .pos = { 405.0f, 90.0f, -19.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_05),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidC,
    },
    {
        .id = NPC_StarKid_06,
        .pos = { 364.0f, 90.0f, -47.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_06),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidD,
    },
    {
        .id = NPC_ShiverToad_04,
        .pos = { -274.0f, 60.0f, -28.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_ShiverToad_04),
        .settings = &N(NpcSettings_ShiverToad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Red_Idle,
            .walk   = ANIM_ShiverToad_Red_Walk,
            .run    = ANIM_ShiverToad_Red_Idle,
            .chase  = ANIM_ShiverToad_Red_Idle,
            .anim_4 = ANIM_ShiverToad_Red_Idle,
            .anim_5 = ANIM_ShiverToad_Red_Idle,
            .death  = ANIM_ShiverToad_Red_Idle,
            .hit    = ANIM_ShiverToad_Red_Idle,
            .anim_8 = ANIM_ShiverToad_Red_Idle,
            .anim_9 = ANIM_ShiverToad_Red_Idle,
            .anim_A = ANIM_ShiverToad_Red_Idle,
            .anim_B = ANIM_ShiverToad_Red_Idle,
            .anim_C = ANIM_ShiverToad_Red_Idle,
            .anim_D = ANIM_ShiverToad_Red_Idle,
            .anim_E = ANIM_ShiverToad_Red_Idle,
            .anim_F = ANIM_ShiverToad_Red_Idle,
        },
        .tattle = MSG_NpcTattle_SAM06_ToadHouseToad,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Merle), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    {}
};
