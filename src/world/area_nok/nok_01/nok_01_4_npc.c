#include "nok_01.h"

MobileAISettings N(D_80243600_9C89E0) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = -1,
};

#include "world/common/enemy/ai/GuardAI.inc.c"

EvtScript N(EVS_NpcAI_KoopaWithoutShell_01) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80243600_9C89E0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_KoopaWithoutShell_01) = {
    .height = 36,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_KoopaWithoutShell_01),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

MobileAISettings N(D_8024367C_9C8A5C) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Koopa_01) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_8024367C_9C8A5C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Koopa_01) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_Koopa_01),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

s32 N(missing_802436F8_36F8)[] = {
    0x00000000, 0x002A0018, 0x00000000, 0x00000000, 0x802436AC, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00230018, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x002A0018, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00630000, 
};

NpcSettings N(NpcSettings_Koopa_02) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_Fuzzy_01) = {
    .height = 20,
    .radius = 22,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Toad) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

s32 N(missing_80243800_3800)[] = {
    0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 
};

NpcSettings N(NpcSettings_Bombomb_01) = {
    .height = 23,
    .radius = 20,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/KeyItemChoice.inc.c"


#include "world/common/complete/LetterDelivery.inc.c"

s32 N(D_80248E14_9CE1F4)[] = {
    ITEM_LETTER14, ITEM_NONE
};

EvtScript N(D_80248E1C_9CE1FC) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle,
        ITEM_LETTER14, ITEM_LETTER15,
        MSG_CH1_0009, MSG_CH1_000A, MSG_CH1_000B, MSG_CH1_000C,
        EVT_PTR(N(D_80248E14_9CE1F4)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(D_80248E6C_9CE24C)[] = {
    ITEM_LETTER16, ITEM_NONE
};

EvtScript N(D_80248E74_9CE254) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle,
        ITEM_LETTER16, ITEM_LETTER17,
        MSG_CH1_000D, MSG_CH1_000E, MSG_CH1_000F, MSG_CH1_0010,
        EVT_PTR(N(D_80248E6C_9CE24C)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(D_80248EC4_9CE2A4)[] = {
    ITEM_LETTER03, ITEM_NONE
};

EvtScript N(D_80248ECC_9CE2AC) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle,
        ITEM_LETTER03, ITEM_NONE,
        MSG_CH1_0039, MSG_CH1_003A, MSG_CH1_003B, MSG_CH1_003C,
        EVT_PTR(N(D_80248EC4_9CE2A4)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248F1C_9CE2FC) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_8024243C_9C781C)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    f32 angle = clamp_angle((get_npc_safe(npcID)->yaw + 180.0f) - gCameras[gCurrentCameraID].currentYaw);
    s32 outVal;

    outVal = FALSE;
    if (angle > 270.0f || angle < 90.0f) {
        outVal = TRUE;
    }

    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(N(func_802426A4_9C7A84)) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f20;
    f32 temp_f22;
    f32 f3;

    temp_f22 = evt_get_variable(script, *args++);
    temp_f20 = evt_get_variable(script, *args++);
    f3 = evt_get_variable(script, *args++);

    fx_explosion(0, temp_f22, temp_f20 + 15.0f, f3);
    exec_ShakeCam1(0, 0, 20);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248F90_9CE370) = {
    EVT_CALL(GetNpcYaw, LVar4, LVar1)
    EVT_SET(LVar2, 30)
    EVT_IF_GT(LVar1, 151)
        EVT_IF_LE(LVar1, 331)
            EVT_SET(LVar2, -30)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, LVar2)
        EVT_CALL(SetNpcRotation, LVar3, 0, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_80249060_9CE440)[] = {
    -255, 399, -100, 430, -91, 475, 0, 470, 
    56, 470, 120, 470, 200, 473, 250, 400, 
    308, 362, 370, 280, 446, 236, 444, 110, 
    448, 53, 330, 60, 273, 74, 200, 80, 
    135, 108, 30, 140, -47, 185, -100, 240, 
    -170, 324, -210, 360, 
};

s32 N(D_80249110_9CE4F0)[] = {
    -170, 324, -100, 240, -47, 185, 30, 140, 
    135, 108, 200, 80, 273, 74, 330, 60, 
    448, 53, 444, 110, 446, 236, 370, 280, 
    308, 362, 250, 400, 200, 473, 120, 470, 
    56, 470, 0, 470, -91, 475, -100, 430, 
    -255, 399, -210, 360, 
};

EvtScript N(EVS_NpcIdle_Fuzzy_02) = {
    EVT_LABEL(100)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_WAIT(8)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(D_80249060_9CE440)))
    EVT_SET(LVar1, 200)
    EVT_BUF_READ2(LVar0, LVar2)
    EVT_CALL(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(D_80249060_9CE440)))
    EVT_LOOP(22)
        EVT_SET(LVar1, 0)
        EVT_BUF_READ2(LVar0, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_332, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Fuzzy_02) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 25)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar2, -40)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    EVT_ADD(LVar0, 30)
    EVT_ADD(LVar2, -30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Anim09)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 13)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar2, -20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 11)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar2, -10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 9)
    EVT_ADD(LVar0, 80)
    EVT_ADD(LVar2, -80)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Run)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Fuzzy_02) = {
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Fuzzy_02)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Fuzzy_03) = {
    EVT_LABEL(100)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_WAIT(8)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(D_80249110_9CE4F0)))
    EVT_SET(LVar1, 200)
    EVT_BUF_READ2(LVar0, LVar2)
    EVT_MULF(LVar0, EVT_FLOAT(0.9))
    EVT_MULF(LVar2, EVT_FLOAT(0.9))
    EVT_CALL(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(D_80249110_9CE4F0)))
    EVT_LOOP(22)
        EVT_SET(LVar1, 0)
        EVT_BUF_READ2(LVar0, LVar2)
        EVT_CALL(RandInt, 9, LVar3)
        EVT_ADD(LVar3, 13)
        EVT_MULF(LVar0, EVT_FLOAT(0.9))
        EVT_MULF(LVar2, EVT_FLOAT(0.9))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_333, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Fuzzy_03) = {
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Fuzzy_02)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_06) = {
    EVT_EXEC_WAIT(ItemShopInteract)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_06)))
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(func_802D286C, 0x00000800)
    EVT_CALL(func_802D2520, 0x00010002, 5, 7, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001D)
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
    EVT_CALL(func_802D2520, 0x00010002, 0, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -380, 0, 5)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -325, 79, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_EXEC_WAIT(N(D_80248ECC_9CE2AC))
    EVT_EXEC_WAIT(N(D_80248F1C_9CE2FC))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ToadHouseKeeper))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_RETURN
    EVT_END
};

#include "npcs_crisis.inc.c"
#include "npcs_normal.inc.c"

StaticNpc N(NpcData_Koopa_01_Crisis)[] = {
    {
        .id = NPC_Koopa_01,
        .settings = &N(NpcSettings_Koopa_01),
        .pos = { -233.0f, 0.0f, 256.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Koopa_01_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_Greeter,
    },
    {
        .id = NPC_Fuzzy_01,
        .settings = &N(NpcSettings_Fuzzy_01),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_8 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000,
        .init = &N(EVS_NpcInit_Fuzzy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_Koopa_02,
        .settings = &N(NpcSettings_Koopa_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Koopa_02_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
    },
    {
        .id = NPC_KoopaWithoutShell_01,
        .settings = &N(NpcSettings_KoopaWithoutShell_01),
        .pos = { 50.0f, 0.0f, 300.0f },
        .yaw = 180,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoopaWithoutShell_01_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_KoopaWithoutShell_CryIdle,
            .walk   = ANIM_KoopaWithoutShell_CryRun,
            .run    = ANIM_KoopaWithoutShell_Walk,
            .chase  = ANIM_KoopaWithoutShell_CryRun,
            .anim_4 = ANIM_KoopaWithoutShell_Walk,
            .anim_5 = ANIM_KoopaWithoutShell_Walk,
            .death  = ANIM_KoopaWithoutShell_Still,
            .hit    = ANIM_KoopaWithoutShell_Still,
            .anim_8 = ANIM_KoopaWithoutShell_Still,
            .anim_9 = ANIM_KoopaWithoutShell_Still,
            .anim_A = ANIM_KoopaWithoutShell_Still,
            .anim_B = ANIM_KoopaWithoutShell_Still,
            .anim_C = ANIM_KoopaWithoutShell_Still,
            .anim_D = ANIM_KoopaWithoutShell_Still,
            .anim_E = ANIM_KoopaWithoutShell_Still,
            .anim_F = ANIM_KoopaWithoutShell_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaA,
    },
    {
        .id = NPC_Koopa_03,
        .settings = &N(NpcSettings_Koopa_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Koopa_03_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
    },
    {
        .id = NPC_KoopaWithoutShell_02,
        .settings = &N(NpcSettings_KoopaWithoutShell_01),
        .pos = { 150.0f, 0.0f, 217.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoopaWithoutShell_02_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_KoopaWithoutShell_CryIdle,
            .walk   = ANIM_KoopaWithoutShell_CryRun,
            .run    = ANIM_KoopaWithoutShell_Walk,
            .chase  = ANIM_KoopaWithoutShell_CryRun,
            .anim_4 = ANIM_KoopaWithoutShell_Walk,
            .anim_5 = ANIM_KoopaWithoutShell_Walk,
            .death  = ANIM_KoopaWithoutShell_Still,
            .hit    = ANIM_KoopaWithoutShell_Still,
            .anim_8 = ANIM_KoopaWithoutShell_Still,
            .anim_9 = ANIM_KoopaWithoutShell_Still,
            .anim_A = ANIM_KoopaWithoutShell_Still,
            .anim_B = ANIM_KoopaWithoutShell_Still,
            .anim_C = ANIM_KoopaWithoutShell_Still,
            .anim_D = ANIM_KoopaWithoutShell_Still,
            .anim_E = ANIM_KoopaWithoutShell_Still,
            .anim_F = ANIM_KoopaWithoutShell_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaB,
    },
    {
        .id = NPC_Koopa_04,
        .settings = &N(NpcSettings_Koopa_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Koopa_04_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
    },
    {
        .id = NPC_Bombomb_01,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 260.0f, 0.0f, -110.0f },
        .yaw = 82,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Bombomb_01_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombA,
    },
    {
        .id = NPC_Bombomb_02,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 270.0f, 0.0f, -160.0f },
        .yaw = 82,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Bombomb_02_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombB,
    },
};

StaticNpc N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .settings = &N(NpcSettings_Fuzzy_01),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000,
    .init = &N(EVS_NpcInit_Fuzzy_02),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

StaticNpc N(NpcData_Fuzzy_03) = {
    .id = NPC_Fuzzy_03,
    .settings = &N(NpcSettings_Fuzzy_01),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000,
    .init = &N(EVS_NpcInit_Fuzzy_03),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

StaticNpc N(NpcData_Koopa_01_Normal)[] = {
    {
        .id = NPC_Koopa_01,
        .settings = &N(NpcSettings_Koopa_01),
        .pos = { -233.0f, 0.0f, 256.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Koopa_01_Normal),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_Greeter,
    },
    {
        .id = NPC_KoopaWithoutShell_01,
        .settings = &N(NpcSettings_Koopa_01),
        .pos = { 52.0f, 0.0f, 330.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoopaWithoutShell_01_Normal),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaA,
    },
    {
        .id = NPC_KoopaWithoutShell_02,
        .settings = &N(NpcSettings_Koopa_01),
        .pos = { 110.0f, 0.0f, 240.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoopaWithoutShell_02_Normal),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaB,
    },
    {
        .id = NPC_Bombomb_01,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 236.0f, 0.0f, 251.0f },
        .yaw = 82,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Bombomb_01_Normal),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombA,
    },
    {
        .id = NPC_Bombomb_02,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 224.0f, 0.0f, 309.0f },
        .yaw = 82,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Bombomb_02_Normal),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombB,
    },
    {
        .id = NPC_Bombomb_03,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 280.0f, 0.0f, 274.0f },
        .yaw = 262,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Bombomb_03_Normal),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombC,
    },
};

StaticNpc N(NpcData_Toad)[] = {
    {
        .id = NPC_Toad,
        .settings = &N(NpcSettings_Toad),
        .pos = { -268.0f, 10.0f, 68.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Toad),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .tattle = MSG_NpcTattle_NOK_ToadHouseToad,
    },
    {
        .id = NPC_Koopa_06,
        .settings = &N(NpcSettings_Koopa_02),
        .pos = { -73.0f, 0.0f, -338.0f },
        .yaw = 157,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Koopa_06),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_ShopOwner,
    },
    {
        .id = NPC_Koopa_05,
        .settings = &N(NpcSettings_Koopa_02),
        .pos = { 337.0f, 17.0f, -162.0f },
        .yaw = 262,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Koopa_05_Crisis),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_RadioLover,
    },
    {
        .id = NPC_ChuckQuizmo,
        .settings = &N(NpcSettings_ChuckQuizmo),
        .pos = { 356.0f, 0.0f, 166.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .initVarCount = 1,
        .initVar = { .value = 0x00020200 },
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
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Koopa_01_Crisis)),
    NPC_GROUP(N(NpcData_Toad)),
    NPC_GROUP(N(NpcData_Fuzzy_02)),
    NPC_GROUP(N(NpcData_Fuzzy_03)),
    {}
};

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_Koopa_01_Normal)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
