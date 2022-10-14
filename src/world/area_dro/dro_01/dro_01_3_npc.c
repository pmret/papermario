#include "dro_01.h"
#include "effects.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/Musician.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/WorldParakarry.h"

typedef struct Unk_Struct_1 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    void (*unk_14)(struct Unk_Struct_1*, s32);
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 lastPlayerX;
    f32 lastPlayerZ;
    f32 unk_34;
    s32 unk_38;
} Unk_Struct_1;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    void (*unk_14)(Unk_Struct_1*, s32);
} Unk_Struct_2;

void N(func_802430C8_95E2C8)(Unk_Struct_1* ptr, s32 arg1);

MobileAISettings N(npcAISettings_80245010) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80245040) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_80245010)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80245060) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_80245040),
    .level = 99,
    .actionFlags = 16,
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(npcAISettings_8024508C) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802450BC) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_8024508C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Dryite_06) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_802450BC),
    .level = 99,
    .actionFlags = 16,
};

NpcSettings N(npcSettings_80245108) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

NpcSettings N(npcSettings_80245134) = {
    .height = 22,
    .radius = 25,
    .level = 99,
};

NpcSettings N(NpcSettings_ThreeSisters) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_8024518C) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,pre_key_item); // or post-quizmo?
#include "world/common/complete/KeyItemChoice.inc.c"

API_CALLABLE(N(func_80242858_95DA58)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Unk_Struct_2* temp_s1 = (Unk_Struct_2*) evt_get_variable(script, *script->ptrReadPos);
    Unk_Struct_1* ptr;
    s32 atan_res1, atan_res2;
    s32 clamp;
    s32 dist;

    if (isInitialCall) {
        script->functionTempPtr[1] = heap_malloc(0x3C);
        ptr = script->functionTempPtr[1];
        ptr->unk_00 = temp_s1->unk_00;
        ptr->unk_04 = temp_s1->unk_04;
        ptr->unk_08 = temp_s1->unk_08;
        ptr->unk_0C = temp_s1->unk_0C;
        ptr->unk_10 = temp_s1->unk_10;
        ptr->unk_14 = temp_s1->unk_14;
        ptr->unk_18 = 0;
        ptr->unk_1C = 0;
        ptr->unk_20 = 0;
        ptr->unk_24 = 0;
        ptr->unk_28 = 0;
        ptr->lastPlayerX = 0;
        ptr->lastPlayerZ = 0;
        ptr->unk_34 = 0;
        ptr->unk_38 = 0;
    }

    ptr = script->functionTempPtr[1];
    switch (ptr->unk_20) {
        case 0:
            dist = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (dist < ptr->unk_0C) {
                ptr->unk_24 = playerStatus->position.x;
                ptr->unk_28 = playerStatus->position.z;
                ptr->unk_20++;
            }
            break;

        case 1:
            dist = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (dist < ptr->unk_0C) {
                atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->unk_24, ptr->unk_28);
                atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                ptr->unk_34 = signF(clamp);
                ptr->unk_20++;
                break;
            }
            ptr->unk_20 = 0;
            break;

        case 2:
            dist = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (dist < ptr->unk_0C) {
                atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->lastPlayerX, ptr->lastPlayerZ);
                atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                if (ptr->unk_34 == signF(clamp)) {
                    atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->unk_24, ptr->unk_28);
                    atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                    clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                    if (fabsf(clamp) > 90.0f) {
                        if (ptr->unk_14 != NULL) {
                            ptr->unk_14(ptr, 0);
                        }
                        ptr->unk_18 = ptr->unk_18 + fabsf(clamp);
                        ptr->unk_20++;
                    }
                    break;
                }
            }
            ptr->unk_20 = 0;
            break;

        case 3:
            dist = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (dist < ptr->unk_10) {
                atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->lastPlayerX, ptr->lastPlayerZ);
                atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                if (ptr->unk_34 != signF(clamp)) {
                    if (ptr->unk_14 != NULL) {
                        ptr->unk_14(ptr, 3);
                    }
                    ptr->unk_20++;
                } else {
                    ptr->unk_18 = ptr->unk_18 + fabsf(clamp);
                    ptr->unk_1C = ptr->unk_18 / 360;
                    if (ptr->unk_1C != ptr->unk_38) {
                        if (ptr->unk_14 != NULL) {
                            ptr->unk_14(ptr, 1);
                        }
                        ptr->unk_38 = ptr->unk_1C;
                    }
                }
                if (ptr->unk_14 != NULL) {
                    ptr->unk_14(ptr, 2);
                }
            } else {
                if (ptr->unk_14 != NULL) {
                    ptr->unk_14(ptr, 4);
                }
                ptr->unk_20++;
            }
            break;

        case 4:
            ptr->unk_18 = 0.0f;
            ptr->unk_1C = 0;
            ptr->unk_38 = 0;
            ptr->unk_20 = 0;
            break;
    }

    ptr->lastPlayerX = playerStatus->position.x;
    ptr->lastPlayerZ = playerStatus->position.z;

    return ApiStatus_BLOCK;
}

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(D_80248088_963288)[] = {
    ITEM_LETTER19, ITEM_NONE
};

EvtScript N(80248090) = {
    EVT_CALL(N(LetterDelivery_Init), 6, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 76, 69,
        MSG_CH2_0089, MSG_CH2_008A, MSG_CH2_008B, MSG_CH2_008C, EVT_PTR(N(D_80248088_963288)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802480E0) = {
    EVT_IF_GE(GB_StoryProgress, -53)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0062)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(AreaByte(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_005F)
            EVT_ADD(AreaByte(0), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0060)
            EVT_ADD(AreaByte(0), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0061)
            EVT_SUB(AreaByte(0), 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802481F8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802480E0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024821C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_GE(GB_StoryProgress, -64)
                EVT_IF_EQ(AreaByte(1), 2)
                    EVT_SET(AreaByte(1), 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SWITCH(AreaByte(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0063)
                    EVT_ADD(AreaByte(1), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0064)
                    EVT_ADD(AreaByte(1), 1)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0065)
                    EVT_SET(AreaByte(1), 0)
            EVT_END_SWITCH
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0066)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0067)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802483A8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024821C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802483CC) = {
    EVT_SWITCH(AreaByte(2))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0068)
            EVT_ADD(AreaByte(2), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0069)
            EVT_ADD(AreaByte(2), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_006A)
            EVT_ADD(AreaByte(2), 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_006B)
            EVT_SET(AreaByte(2), 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802484E0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802483CC)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80248504) = {
    EVT_LOOP(0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_EQ(LVar0, 8)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, 3, 0)
    EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0078)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, 3, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_ADDF(LVar0, LVar3)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_DIVF(LVar0, EVT_FLOAT(2.0))
    EVT_DIVF(LVar1, EVT_FLOAT(2.0))
    EVT_DIVF(LVar2, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(-300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0079)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007A)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(N(func_80243084_95E284))
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

Unk_Struct_2 N(D_8024884C_963A4C) = {
    0x0000007D,
    0x00000000, 0xFFFFFFD6, 0x0000004B, 0x0000004B, N(func_802430C8_95E2C8),
};

EvtScript N(interact_80248864) = {
    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, 1)
        EVT_IF_EQ(GF_DRO01_HeardHintAboutSpinningRoof, 1)
            EVT_CALL(N(func_802431B4_95E3B4))
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(1), 0)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006C)
                EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006D)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006E)
                EVT_SET(AreaFlag(1), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006F)
                EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0070)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0071)
                EVT_SET(AreaFlag(1), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0072)
            EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0073)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0074)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0075)
            EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0076)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0077)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80248AE4) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248864)))
    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, 1)
        EVT_THREAD
            EVT_CALL(N(func_80242858_95DA58), EVT_PTR(N(D_8024884C_963A4C)))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80248BA0) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFaceNpc, 3, 4, 1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(N(func_802431FC_95E3FC))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.5))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), FALSE)
    EVT_WAIT(5)
    EVT_CALL(GetNpcYaw, -1, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80248CC8) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248BA0)))
    EVT_RETURN
    EVT_END
};

s32 N(D_80248D4C_963F4C)[] = {
    0x00000067, 0x00000000,
};

EvtScript N(interact_80248D54) = {
    EVT_IF_EQ(GF_DRO01_Gift_Melody, 1)
        EVT_CALL(FindKeyItem, ITEM_MELODY, LVar0)
        EVT_IF_NE(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0084)
            EVT_RETURN
        EVT_ELSE
            EVT_IF_EQ(GF_DRO01_Gift_ToldComposerAboutMelody, 0)
                EVT_IF_LT(GB_StoryProgress, 88)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0085)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
                    EVT_WAIT(30)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0086)
                    EVT_SET(GF_DRO01_Gift_ToldComposerAboutMelody, 1)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007C)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007D)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007E)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007F)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0080)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0081)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(LVar0, EVT_PTR(N(D_80248D4C_963F4C)))
    EVT_SET(LVar1, 5)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0082)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Composer_Write)
            EVT_WAIT(60)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Composer_Idle)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0083)
            EVT_SET(LVar0, 104)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(GiveKeyReward))
            EVT_CALL(AddKeyItem, ITEM_MELODY)
            EVT_SET(GF_DRO01_Gift_Melody, 1)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80249168) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248D54)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8024918C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-67)
            EVT_CALL(N(func_80243350_95E550), 16, 190, -134, -131)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -180)
            EVT_EXEC_WAIT(N(EVS_OpenShopDoor))
            EVT_WAIT(10)
            EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
            EVT_CALL(UseSettingsFrom, 0, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, 0, 32, 0, -67)
            EVT_CALL(SetCamDistance, 0, -210)
            EVT_CALL(SetCamPitch, 0, 20, -12)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_WAIT(20)
            EVT_CALL(UseSettingsFrom, 0, LVarA, LVarB, LVarC)
            EVT_CALL(SetCamDistance, 0, -350)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.8))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, -23, -105, 20)
            EVT_WAIT(10)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 65, 0)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_CloseShopDoor))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 37, -27, 20)
            EVT_CALL(UseSettingsFrom, 0, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, 0, 142, 0, -67)
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 62, -6, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 103, 11, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
            EVT_CALL(EnableNpcBlur, -1, 1)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, 372, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 554, -12, 20)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_WAIT(30)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, 0, 0, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(GB_StoryProgress, -67)
        EVT_CASE_LT(-66)
        EVT_CASE_LT(-65)
            EVT_CALL(EnableNpcBlur, -1, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, 372, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, 470, 0, 18)
            EVT_CALL(NpcMoveTo, NPC_SELF, 287, 9, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 102, -14, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, -32, -96, 20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_EXEC_WAIT(N(EVS_OpenShopDoor))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 20, -375, 30)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_EXEC_WAIT(N(EVS_CloseShopDoor))
            EVT_CALL(EnableNpcBlur, -1, 0)
            EVT_SET(GB_StoryProgress, -65)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -375)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249750) = {
    EVT_IF_EQ(AreaByte(4), 4)
        EVT_IF_EQ(AreaByte(5), 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
            EVT_EXEC_WAIT(N(80248090))
            EVT_IF_NE(LVarC, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(0x80284054)
    EVT_EXEC_WAIT(N(80248090))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024981C) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024918C)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249750)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters) = {
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_008E)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_008F)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_0090)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802498E8) = {
    EVT_CALL(FindKeyItem, ITEM_FIRST_DEGREE_CARD, LVar1)
    EVT_CALL(FindKeyItem, ITEM_SECOND_DEGREE_CARD, LVar2)
    EVT_CALL(FindKeyItem, ITEM_THIRD_DEGREE_CARD, LVar3)
    EVT_CALL(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, LVar4)
    EVT_CALL(FindKeyItem, ITEM_DIPLOMA, LVar5)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009A)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009B)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar3, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009C)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar4, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009D)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar5, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009E)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_0099)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DojoGrad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802498E8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249AE0) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009F)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80249B10) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249AE0)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(PassiveNPCs)[] = {
    {
        .id = NPC_Mouser_01,
        .settings = &N(npcSettings_80245134),
        .pos = { -332.0f, 0.0f, 188.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802481F8),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Run,
            ANIM_Mouser_Blue_Run,
            ANIM_Mouser_Blue_Run,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_Greeter,
    },
    {
        .id = NPC_Dryite_01,
        .settings = &N(npcSettings_80245060),
        .pos = { -235.0f, 0.0f, 160.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802483A8),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { -235, 0, 160, 30, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Walk,
            ANIM_Dryite_Yellow_Run,
            ANIM_Dryite_Yellow_Run,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Still,
            ANIM_Dryite_Yellow_Still,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteA,
    },
    {
        .id = NPC_Dryite_02,
        .settings = &N(npcSettings_80245108),
        .pos = { -380.0f, 0.0f, -15.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802484E0),
        .yaw = 61,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Walk,
            ANIM_Dryite_Blue_Run,
            ANIM_Dryite_Blue_Run,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Still,
            ANIM_Dryite_Blue_Still,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteD,
    },
    {
        .id = NPC_Dryite_03,
        .settings = &N(npcSettings_80245108),
        .pos = { 195.0f, 0.0f, -75.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248AE4),
        .yaw = 74,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Walk,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteB,
    },
    {
        .id = NPC_Dryite_04,
        .settings = &N(npcSettings_80245108),
        .pos = { 225.0f, 0.0f, -83.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248CC8),
        .yaw = 257,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Walk,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteC,
    },
    {
        .id = NPC_ArtistToad,
        .settings = &N(npcSettings_80245108),
        .pos = { 285.0f, 0.0f, -274.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249168),
        .yaw = 271,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Musician_Composer_Idle,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
        },
        .tattle = MSG_NpcTattle_Composer,
    },
    {
        .id = NPC_Mouser_02,
        .settings = &N(npcSettings_80245134),
        .pos = { 31.0f, 0.0f, -374.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024981C),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Run,
            ANIM_Mouser_Purple_Run,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_ShopOwner,
    },
    {
        .id = NPC_ChuckQuizmo,
        .settings = &N(Quizmo_NpcSettings),
        .pos = { -400.0f, 0.0f, 100.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .initVarCount = 1,
        .initVar = { .value = 0x00030200 },
        .yaw = 263,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_ChuckQuizmo_Idle,
            ANIM_ChuckQuizmo_Walk,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Idle,
            ANIM_ChuckQuizmo_Idle,
            ANIM_ChuckQuizmo_Still,
            ANIM_ChuckQuizmo_Still,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
        },
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
    {
        .id = NPC_Dryite_05,
        .settings = &N(npcSettings_80245060),
        .pos = { -120.0f, 0.0f, 134.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_DojoGrad),
        .yaw = 257,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { -120, 0, 134, 40, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Walk,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DojoGraduate,
    },
    {
        .id = NPC_Dryite_06,
        .settings = &N(NpcSettings_Dryite_06),
        .pos = { 40.0f, 0.0f, 105.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249B10),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { 2, 40, 0, 105, -30, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Walk,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_WorriedDryite,
    },
};

StaticNpc N(ThreeSisterNPCs)[] = {
    {
        .id = NPC_ThreeSisters_01,
        .settings = &N(NpcSettings_ThreeSisters),
        .pos = { -141.0f, 0.0f, -18.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .yaw = 62,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Walk,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_ThreeSisters_02,
        .settings = &N(NpcSettings_ThreeSisters),
        .pos = { -124.0f, 0.0f, -61.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .yaw = 63,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Walk,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_ThreeSisters_03,
        .settings = &N(NpcSettings_ThreeSisters),
        .pos = { -80.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .yaw = 244,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Walk,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidC,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(PassiveNPCs)),
    {},
};

NpcGroupList N(Chapter3NPCs) = {
    NPC_GROUP(N(PassiveNPCs)),
    NPC_GROUP(N(ThreeSisterNPCs)),
    {},
};


API_CALLABLE(N(func_80243084_95E284)) {
    PlayerData* playerData = &gPlayerData;

    playerData->droTreeOrbitTime = playerData->frameCounter;
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetFloorCollider.inc.c"

void N(func_802430C8_95E2C8)(Unk_Struct_1* ptr, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (arg1) {
        case 2:
            if (ptr->unk_1C >= 6) {
                if (fabsf(get_clamped_angle_diff(atan2(125.0f, -42.0f, 152.0f, -61.0f), atan2(125.0f, -42.0f, playerStatus->position.x,
                                                 playerStatus->position.z))) < 30.0f) {
                    start_script(&N(80248504), EVT_PRIORITY_1, 0);
                    ptr->unk_20 = 4;
                }
            }
            break;

        case 0:
        case 1:
        case 3:
        case 4:
            break;
    }
}

API_CALLABLE(N(func_802431B4_95E3B4)) {
    PlayerData* playerData = &gPlayerData;
    s32 val = (playerData->frameCounter - playerData->droTreeOrbitTime) / 3600;

    if (val < 30) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802431FC_95E3FC)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);
    s32 rand;
    f32 temp_f22;
    f32 temp_f24;

    temp_f24 = atan2(183.0f, -75.0f, playerStatus->position.x, playerStatus->position.z);
    temp_f22 = atan2(183.0f, -75.0f, npc->pos.x, npc->pos.z);
    temp_f24 = get_clamped_angle_diff(temp_f22, temp_f24);
    rand = rand_int(10) + 30;
    if (temp_f24 < 0.0f) {
        temp_f22 += rand;
    } else {
        temp_f22 -= rand;
    }
    rand = rand_int(20) + 30;
    script->varTable[0] = (sin_deg(temp_f22) * rand) + 183.0f;
    script->varTable[1] = -75.0f - (cos_deg(temp_f22) * rand);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243350_95E550)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_variable(script, *args++);
    f32 temp_f0 = (var4 - var2) / (var3 - var1);

    if (playerStatus->position.z < ((temp_f0 * playerStatus->position.x) + (var2 - (temp_f0 * var1)))) {
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_BLOCK;
}
