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

MobileAISettings N(AISettings_Dryite_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Dryite_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Dryite_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Dryite_Wander) = {
    .height = 26,
    .radius = 23,
    .ai = &N(EVS_NpcAI_Dryite_Wander),
    .level = 99,
    .actionFlags = 16,
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Dryite_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Dryite_Patrol) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_Dryite_Patrol)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Dryite_Patrol) = {
    .height = 26,
    .radius = 23,
    .ai = &N(EVS_NpcAI_Dryite_Patrol),
    .level = 99,
    .actionFlags = 16,
};

NpcSettings N(NpcSettings_GenericDryite) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

NpcSettings N(NpcSettings_Mouser) = {
    .height = 22,
    .radius = 25,
    .level = 99,
};

NpcSettings N(NpcSettings_ThreeSisters) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,pre_key_item); // or post-quizmo?
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/util/MonitorPlayerOrbiting.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER19,
    ITEM_NONE
};

EvtScript N(EVS_ShopOwner_LetterDelivery) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Mouser_02, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle,
        ITEM_LETTER19, ITEM_LETTER12,
        MSG_CH2_0089, MSG_CH2_008A, MSG_CH2_008B, MSG_CH2_008C,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser_01) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0062)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(AB_DRO_0)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_005F)
            EVT_ADD(AB_DRO_0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0060)
            EVT_ADD(AB_DRO_0, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0061)
            EVT_SUB(AB_DRO_0, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_GE(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
                EVT_IF_EQ(AB_DRO_1, 2)
                    EVT_SET(AB_DRO_1, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SWITCH(AB_DRO_1)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0063)
                    EVT_ADD(AB_DRO_1, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0064)
                    EVT_ADD(AB_DRO_1, 1)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0065)
                    EVT_SET(AB_DRO_1, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0066)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0067)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_02) = {
    EVT_SWITCH(AB_DRO_2)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0068)
            EVT_ADD(AB_DRO_2, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0069)
            EVT_ADD(AB_DRO_2, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_006A)
            EVT_ADD(AB_DRO_2, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_006B)
            EVT_SET(AB_DRO_2, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_02)))
    EVT_RETURN
    EVT_END
};

#include "npc_hint_dryite.c"
#include "npc_hint_dryite_companion.c"
#include "npc_composer.c"

API_CALLABLE(N(AwaitPlayerApproachShop)) {
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

EvtScript N(EVS_NpcIdle_ShopOwner) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_LEFT_SHOP)
            EVT_CALL(N(AwaitPlayerApproachShop), 16, 190, -134, -131)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -180)
            EVT_EXEC_WAIT(N(EVS_OpenShopDoor))
            EVT_WAIT(10)
            EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 32, 0, -67)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, -210)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, 20, -12)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(20)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, -23, -105, 20)
            EVT_WAIT(10)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 65, 0)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_CloseShopDoor))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 37, -27, 20)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 142, 0, -67)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 62, -6, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 103, 11, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
            EVT_CALL(EnableNpcBlur, NPC_SELF, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_174, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 554, -12, 20)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_WAIT(30)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(GB_StoryProgress, STORY_CH2_SHADY_MOUSE_LEFT_SHOP)
        EVT_CASE_LT(STORY_CH2_SPOKE_WITH_SHEEK)
        EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
            EVT_CALL(EnableNpcBlur, NPC_SELF, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_174, 0)
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
            EVT_CALL(EnableNpcBlur, NPC_SELF, FALSE)
            EVT_SET(GB_StoryProgress, STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -375)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShopOwner) = {
    EVT_IF_EQ(AB_DRO_4, 4)
        EVT_IF_EQ(AB_DRO_5, 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
            EVT_EXEC_WAIT(N(EVS_ShopOwner_LetterDelivery))
            EVT_IF_NE(LVarC, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(ItemShopInteract)
    EVT_EXEC_WAIT(N(EVS_ShopOwner_LetterDelivery))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShopOwner) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShopOwner)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShopOwner)))
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

EvtScript N(EVS_NpcInteract_DojoGrad) = {
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
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_DojoGrad)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_06) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009F)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_06)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(PassiveNPCs)[] = {
    {
        .id = NPC_Mouser_01,
        .settings = &N(NpcSettings_Mouser),
        .pos = { -332.0f, 0.0f, 188.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Mouser_01),
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
        .settings = &N(NpcSettings_Dryite_Wander),
        .pos = { -235.0f, 0.0f, 160.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Dryite_01),
        .yaw = 90,
        .drops = {
		    .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -235, 0, 160 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
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
        .settings = &N(NpcSettings_GenericDryite),
        .pos = { -380.0f, 0.0f, -15.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Dryite_02),
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
        .settings = &N(NpcSettings_GenericDryite),
        .pos = { 195.0f, 0.0f, -75.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_HintDryite),
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
        .settings = &N(NpcSettings_GenericDryite),
        .pos = { 225.0f, 0.0f, -83.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Dryite_04),
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
        .settings = &N(NpcSettings_GenericDryite),
        .pos = { 285.0f, 0.0f, -274.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Composer),
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
        .settings = &N(NpcSettings_Mouser),
        .pos = { 31.0f, 0.0f, -374.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_ShopOwner),
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
        .initVar = { .bytes = { 0, QUIZ_AREA_DRO, QUIZ_COUNT_DRO, QUIZ_MAP_DRO_01 }},
        .yaw = 263,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    },
    {
        .id = NPC_Dryite_05,
        .settings = &N(NpcSettings_Dryite_Wander),
        .pos = { -120.0f, 0.0f, 134.0f },
        .yaw = 257,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_DojoGrad),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -120, 0, 134 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Dryite_Brown_Idle,
            .walk   = ANIM_Dryite_Brown_Walk,
            .run    = ANIM_Dryite_Brown_Run,
            .chase  = ANIM_Dryite_Brown_Run,
            .anim_4 = ANIM_Dryite_Brown_Idle,
            .anim_5 = ANIM_Dryite_Brown_Idle,
            .death  = ANIM_Dryite_Brown_Still,
            .hit    = ANIM_Dryite_Brown_Still,
            .anim_8 = ANIM_Dryite_Brown_Idle,
            .anim_9 = ANIM_Dryite_Brown_Idle,
            .anim_A = ANIM_Dryite_Brown_Idle,
            .anim_B = ANIM_Dryite_Brown_Idle,
            .anim_C = ANIM_Dryite_Brown_Idle,
            .anim_D = ANIM_Dryite_Brown_Idle,
            .anim_E = ANIM_Dryite_Brown_Idle,
            .anim_F = ANIM_Dryite_Brown_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DojoGraduate,
    },
    {
        .id = NPC_Dryite_06,
        .settings = &N(NpcSettings_Dryite_Patrol),
        .pos = { 40.0f, 0.0f, 105.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Dryite_06),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 40, 0, 105 },
                    { -30, 0, 125 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Dryite_Brown_Idle,
            .walk   = ANIM_Dryite_Brown_Walk,
            .run    = ANIM_Dryite_Brown_Run,
            .chase  = ANIM_Dryite_Brown_Run,
            .anim_4 = ANIM_Dryite_Brown_Idle,
            .anim_5 = ANIM_Dryite_Brown_Idle,
            .death  = ANIM_Dryite_Brown_Still,
            .hit    = ANIM_Dryite_Brown_Still,
            .anim_8 = ANIM_Dryite_Brown_Idle,
            .anim_9 = ANIM_Dryite_Brown_Idle,
            .anim_A = ANIM_Dryite_Brown_Idle,
            .anim_B = ANIM_Dryite_Brown_Idle,
            .anim_C = ANIM_Dryite_Brown_Idle,
            .anim_D = ANIM_Dryite_Brown_Idle,
            .anim_E = ANIM_Dryite_Brown_Idle,
            .anim_F = ANIM_Dryite_Brown_Idle,
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
