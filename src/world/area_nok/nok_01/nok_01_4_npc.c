#include "nok_01.h"
#include "sprite/player.h"

#include "world/common/enemy/ai/GuardAI.inc.c"

#include "world/common/npc/KoopaWithoutShell_Wander.inc.c"
#include "world/common/npc/Koopa_Wander.inc.c"

NpcSettings N(NpcSettings_Unused2) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Unused3) = {
    .height = 42,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Koopa.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Bobomb.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LettersKoover1)[] = {
    ITEM_LETTER_CHAIN_KOOVER_1, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Koover1) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle,
        ITEM_LETTER_CHAIN_KOOVER_1, ITEM_LETTER_CHAIN_FISHMAEL,
        MSG_CH1_0009, MSG_CH1_000A, MSG_CH1_000B, MSG_CH1_000C,
        EVT_PTR(N(LettersKoover1)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(LettersKoover2)[] = {
    ITEM_LETTER_CHAIN_KOOVER_2, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Koover2) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle,
        ITEM_LETTER_CHAIN_KOOVER_2, ITEM_LETTER_CHAIN_MR_E,
        MSG_CH1_000D, MSG_CH1_000E, MSG_CH1_000F, MSG_CH1_0010,
        EVT_PTR(N(LettersKoover2)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(LettersMortT)[] = {
    ITEM_LETTER_TO_MORT_T, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_MortT) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_MortT, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle,
        ITEM_LETTER_TO_MORT_T, ITEM_NONE,
        MSG_CH1_0039, MSG_CH1_003A, MSG_CH1_003B, MSG_CH1_003C,
        EVT_PTR(N(LettersMortT)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_MortT) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(IsNpcFacingRight)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Npc* npc = get_npc_safe(npcID);
    f32 angle = clamp_angle((npc->yaw + 180.0f) - gCameras[gCurrentCameraID].curYaw);
    s32 outVal;

    outVal = FALSE;
    if (angle > 270.0f || angle < 90.0f) {
        outVal = TRUE;
    }

    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(N(SpawnExplosionEffect)) {
    Bytecode* args = script->ptrReadPos;
    f32 posY;
    f32 posX;
    f32 posZ;

    posX = evt_get_variable(script, *args++);
    posY = evt_get_variable(script, *args++);
    posZ = evt_get_variable(script, *args++);

    fx_explosion(0, posX, posY + 15.0f, posZ);
    exec_ShakeCam1(0, 0, 20);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DoNothing) = {
    EVT_RETURN
    EVT_END
};

#include "../common/GetIntoShell.inc.c"

Vec2i N(FuzzyJumpPath1)[] = {
    { -255,  399 },
    { -100,  430 },
    {  -91,  475 },
    {    0,  470 },
    {   56,  470 },
    {  120,  470 },
    {  200,  473 },
    {  250,  400 },
    {  308,  362 },
    {  370,  280 },
    {  446,  236 },
    {  444,  110 },
    {  448,   53 },
    {  330,   60 },
    {  273,   74 },
    {  200,   80 },
    {  135,  108 },
    {   30,  140 },
    {  -47,  185 },
    { -100,  240 },
    { -170,  324 },
    { -210,  360 },
};

Vec2i N(FuzzyJumpPath2)[] = {
    { -170,  324 },
    { -100,  240 },
    {  -47,  185 },
    {   30,  140 },
    {  135,  108 },
    {  200,   80 },
    {  273,   74 },
    {  330,   60 },
    {  448,   53 },
    {  444,  110 },
    {  446,  236 },
    {  370,  280 },
    {  308,  362 },
    {  250,  400 },
    {  200,  473 },
    {  120,  470 },
    {   56,  470 },
    {    0,  470 },
    {  -91,  475 },
    { -100,  430 },
    { -255,  399 },
    { -210,  360 },
};

EvtScript N(EVS_NpcIdle_MiscFuzzy1) = {
    EVT_LABEL(100)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_WAIT(8)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath1)))
    EVT_SET(LVar1, 200)
    EVT_BUF_READ2(LVar0, LVar2)
    EVT_CALL(SetNpcPos, NPC_MiscFuzzy1, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath1)))
    EVT_LOOP(22)
        EVT_SET(LVar1, 0)
        EVT_BUF_READ2(LVar0, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_MiscFuzzy1, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_MiscFuzzy1, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MiscFuzzyFlee) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 25)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar2, -40)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    EVT_ADD(LVar0, 30)
    EVT_ADD(LVar2, -30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Anim09)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 13)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar2, -20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 11)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar2, -10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 9)
    EVT_ADD(LVar0, 80)
    EVT_ADD(LVar2, -80)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Run)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_MiscFuzzy1) = {
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_MiscFuzzyFlee)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MiscFuzzy2) = {
    EVT_LABEL(100)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_WAIT(8)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath2)))
    EVT_SET(LVar1, 200)
    EVT_BUF_READ2(LVar0, LVar2)
    EVT_MULF(LVar0, EVT_FLOAT(0.9))
    EVT_MULF(LVar2, EVT_FLOAT(0.9))
    EVT_CALL(SetNpcPos, NPC_MiscFuzzy2, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath2)))
    EVT_LOOP(22)
        EVT_SET(LVar1, 0)
        EVT_BUF_READ2(LVar0, LVar2)
        EVT_CALL(RandInt, 9, LVar3)
        EVT_ADD(LVar3, 13)
        EVT_MULF(LVar0, EVT_FLOAT(0.9))
        EVT_MULF(LVar2, EVT_FLOAT(0.9))
        EVT_CALL(PlaySoundAtNpc, NPC_MiscFuzzy2, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_MiscFuzzy2, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_MiscFuzzy2) = {
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_MiscFuzzyFlee)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_ShopOwner) = {
    EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_ShopOwner) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_ShopOwner)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar1, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH1_0035)
        EVT_SET(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, MSG_CH1_0033)
    EVT_SET(LVar8, MSG_CH1_0034)
    EVT_SET(LVar1, MSG_CH1_0036)
    EVT_SET(LVar2, MSG_CH1_0037)
    EVT_SET(LVar3, MSG_CH1_0038)
    EVT_SET(LVar4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(func_802D1270, -311, 85, EVT_FLOAT(3.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 34, -8)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 220)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, -200, 53)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, -401, 50)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, -2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(func_802D1270, -334, 70, EVT_FLOAT(3.0))
    EVT_CALL(func_802D1270, -385, -6, EVT_FLOAT(3.0))
    EVT_WAIT(1)
    EVT_CALL(InterpPlayerYaw, 160, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(63)
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
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -380, 0, 5)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -325, 79, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MortT) = {
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_MortT))
    EVT_EXEC_WAIT(N(EVS_LetterReward_MortT))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ToadHouseKeeper))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MortT) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MortT)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RelaxedKoopa) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_IF_EQ(AF_NOK01_Dialogue_RelaxedKoopa, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0021)
            EVT_SET(AF_NOK01_Dialogue_RelaxedKoopa, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0022)
            EVT_SET(AF_NOK01_Dialogue_RelaxedKoopa, FALSE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0023)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(AB_NOK_0)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0024)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0025)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0026)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_RelaxedKoopa, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0027)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "npcs_crisis.inc.c"

EvtScript N(EVS_NpcInit_RelaxedKoopa) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RelaxedKoopa)))
    EVT_CALL(SetNpcPos, NPC_RelaxedKoopa, 333, 17, -162)
    EVT_CALL(InterpNpcYaw, NPC_RelaxedKoopa, 180, 0)
    EVT_CALL(SetNpcAnimation, NPC_RelaxedKoopa, ANIM_Koopa_LeanBack)
    EVT_RETURN
    EVT_END
};

#include "npcs_normal.inc.c"

NpcData N(NpcData_Crisis)[] = {
    {
        .id = NPC_Koover,
        .pos = { -233.0f, 0.0f, 256.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -233, 0, 256 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -233, 0, 256 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koover_Crisis),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_Greeter,
    },
    {
        .id = NPC_FuzzyWithShell,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_FuzzyWithShell),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KooversShell,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KooversShell),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Koopa_02,
        .pos = { 50.0f, 0.0f, 300.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 50, 0, 325 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 52, 0, 330 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_02_Crisis),
        .settings = &N(NpcSettings_KoopaWithoutShell_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_WITHOUT_SHELL_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaA,
    },
    {
        .id = NPC_KoopaShell_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaShell_02),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Koopa_03,
        .pos = { 150.0f, 0.0f, 217.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = OVERRIDE_MOVEMENT_SPEED(3.0f),
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 175, 0, 225 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 150, 0, 217 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_03_Crisis),
        .settings = &N(NpcSettings_KoopaWithoutShell_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_WITHOUT_SHELL_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaB,
    },
    {
        .id = NPC_KoopaShell_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaShell_03),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Bobomb_01,
        .pos = { 260.0f, 0.0f, -110.0f },
        .yaw = 82,
        .init = &N(EVS_NpcInit_Bobomb_01_Crisis),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_RED_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombA,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { 270.0f, 0.0f, -160.0f },
        .yaw = 82,
        .init = &N(EVS_NpcInit_Bobomb_02_Crisis),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_RED_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombB,
    },
};

// just jumps around the map; can be hit for a coin
NpcData N(NpcData_MiscFuzzy1) = {
    .id = NPC_MiscFuzzy1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_MiscFuzzy1),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

// just jumps around the map; can be hit for a coin
NpcData N(NpcData_MiscFuzzy2) = {
    .id = NPC_MiscFuzzy2,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_MiscFuzzy2),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Normal)[] = {
    {
        .id = NPC_Koover,
        .pos = { -233.0f, 0.0f, 256.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -233, 0, 256 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -233, 0, 256 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koover_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_Greeter,
    },
    {
        .id = NPC_Koopa_02,
        .pos = { 52.0f, 0.0f, 330.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 50, 0, 325 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 52, 0, 330 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_02_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaA,
    },
    {
        .id = NPC_Koopa_03,
        .pos = { 110.0f, 0.0f, 240.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 110, 0, 240 },
                .wanderSize = { 45 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 150, 0, 217 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_03_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaB,
    },
    {
        .id = NPC_Bobomb_01,
        .pos = { 236.0f, 0.0f, 251.0f },
        .yaw = 82,
        .init = &N(EVS_NpcInit_Bobomb_01_Normal),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_RED_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombA,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { 224.0f, 0.0f, 309.0f },
        .yaw = 82,
        .init = &N(EVS_NpcInit_Bobomb_02_Normal),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_RED_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombB,
    },
    {
        .id = NPC_Bobomb_03,
        .pos = { 280.0f, 0.0f, 274.0f },
        .yaw = 262,
        .init = &N(EVS_NpcInit_Bobomb_03_Normal),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_RED_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombC,
    },
};

NpcData N(NpcData_Shared)[] = {
    {
        .id = NPC_MortT,
        .pos = { -268.0f, 10.0f, 68.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_MortT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_NOK_ToadHouseToad,
    },
    {
        .id = NPC_Koopa_ShopOwner,
        .pos = { -73.0f, 0.0f, -338.0f },
        .yaw = 157,
        .init = &N(EVS_NpcInit_Koopa_ShopOwner),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_ShopOwner,
    },
    {
        .id = NPC_RelaxedKoopa,
        .pos = { 337.0f, 17.0f, -162.0f },
        .yaw = 262,
        .init = &N(EVS_NpcInit_RelaxedKoopa),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_RadioLover,
    },
    {
        .id = NPC_ChuckQuizmo,
        .pos = { 356.0f, 0.0f, 166.0f },
        .yaw = 270,
        .initVarCount = 1,
        .initVar = { .bytes = { 0, QUIZ_AREA_NOK, QUIZ_COUNT_NOK, QUIZ_MAP_NOK_01 }},
        .settings = &N(NpcSettings_ChuckQuizmo),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = QUIZMO_ANIMS,
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
};

NpcGroupList N(CrisisNPCs) = {
    NPC_GROUP(N(NpcData_Crisis)),
    NPC_GROUP(N(NpcData_Shared)),
    NPC_GROUP(N(NpcData_MiscFuzzy1)),
    NPC_GROUP(N(NpcData_MiscFuzzy2)),
    {}
};

NpcGroupList N(NormalNPCs) = {
    NPC_GROUP(N(NpcData_Normal)),
    NPC_GROUP(N(NpcData_Shared)),
    {}
};
