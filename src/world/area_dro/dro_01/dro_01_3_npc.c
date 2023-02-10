#include "dro_01.h"
#include "sprite/npc/Musician.h"
#include "sprite/npc/ChuckQuizmo.h"

#include "world/common/npc/Dryite_Wander.inc.c"
#include "world/common/npc/Dryite_Patrol.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"

#include "world/common/npc/Mouser.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"
MAP_STATIC_PAD(1,post_quizmo); // or pre_key_item?

#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/util/MonitorPlayerOrbiting.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_CHAIN_LITTLE_MOUSER,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_ShopOwner) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Mouser_ShopOwner, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle,
        ITEM_LETTER_CHAIN_LITTLE_MOUSER, ITEM_LETTER_CHAIN_FRANKY,
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
     //@bug this dialogue was probably supposed to cycle 0 --> 1 --> 2 --> 3 --> 0 ...
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
#include "npc_shop_owner.c"

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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Mouser_01),
        .yaw = 90,
        .drops = MOUSER_DROPS,
        .animations = MOUSER_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_DRO_Greeter,
    },
    {
        .id = NPC_Dryite_01,
        .settings = &N(NpcSettings_Dryite_Wander),
        .pos = { -235.0f, 0.0f, 160.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Dryite_01),
        .yaw = 90,
        .drops = DRYITE_DROPS,
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
        .animations = DRYITE_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DryiteA,
    },
    {
        .id = NPC_Dryite_02,
        .settings = &N(NpcSettings_Dryite),
        .pos = { -380.0f, 0.0f, -15.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Dryite_02),
        .yaw = 61,
        .drops = DRYITE_DROPS,
        .animations = DRYITE_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DryiteD,
    },
    {
        .id = NPC_Dryite_03,
        .settings = &N(NpcSettings_Dryite),
        .pos = { 195.0f, 0.0f, -75.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_HintDryite),
        .yaw = 74,
        .drops = DRYITE_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DryiteB,
    },
    {
        .id = NPC_Dryite_04,
        .settings = &N(NpcSettings_Dryite),
        .pos = { 225.0f, 0.0f, -83.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Dryite_04),
        .yaw = 257,
        .drops = DRYITE_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DryiteC,
    },
    {
        .id = NPC_ArtistToad,
        .settings = &N(NpcSettings_Dryite),
        .pos = { 285.0f, 0.0f, -274.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Composer),
        .yaw = 271,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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
        .id = NPC_Mouser_ShopOwner,
        .settings = &N(NpcSettings_Mouser),
        .pos = { 31.0f, 0.0f, -374.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ShopOwner),
        .yaw = 180,
        .drops = MOUSER_DROPS,
        .animations = MOUSER_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_DRO_ShopOwner,
    },
    {
        .id = NPC_ChuckQuizmo,
        .settings = &N(NpcSettings_ChuckQuizmo),
        .pos = { -400.0f, 0.0f, 100.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .initVarCount = 1,
        .initVar = { .bytes = { 0, QUIZ_AREA_DRO, QUIZ_COUNT_DRO, QUIZ_MAP_DRO_01 }},
        .yaw = 263,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_DojoGrad),
        .drops = DRYITE_DROPS,
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
        .animations = DRYITE_BROWN_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DojoGraduate,
    },
    {
        .id = NPC_Dryite_06,
        .settings = &N(NpcSettings_Dryite_Patrol),
        .pos = { 40.0f, 0.0f, 105.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Dryite_06),
        .drops = DRYITE_DROPS,
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
        .animations = DRYITE_BROWN_ANIMS,
        .tattle = MSG_NpcTattle_DRO_WorriedDryite,
    },
};

StaticNpc N(ThreeSisterNPCs)[] = {
    {
        .id = NPC_ThreeSisters_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -141.0f, 0.0f, -18.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .yaw = 62,
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_ThreeSisters_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -124.0f, 0.0f, -61.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .yaw = 63,
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_ThreeSisters_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -80.0f, 0.0f, -35.0f },
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .yaw = 244,
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
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
