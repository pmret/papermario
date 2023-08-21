#include "nok_02.h"
#include "sprite/player.h"

#include "world/common/npc/Koopa_Wander.inc.c"
#include "world/common/npc/KoopaWithoutShell_Patrol.inc.c"
#include "world/common/npc/Koopa.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/KoloradoWife.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/npc/KoopaKoot.inc.c"
#include "world/common/npc/Bobomb.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/atomic/MarioSalute.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Kolorado)[] = {
    ITEM_LETTER_TO_KOLORADO, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH1_0097, MSG_CH1_0098, MSG_CH1_0099, MSG_CH1_009A,
        EVT_PTR(N(LetterList_Kolorado)))
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

EvtScript N(EVS_DoNothing) = {
    EVT_RETURN
    EVT_END
};

#include "../common/GetIntoShell.inc.c"

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_NpcInteract_Kooper) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
        EVT_SET(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00B4, 160, 40)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -180)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 375)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, EVT_FLOAT(-5.5))

#if VERSION_PAL
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4 / DT))
#else
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 4)
#endif
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(SetGroupVisibility, MODEL_g111, MODEL_GROUP_VISIBLE)
        EVT_THREAD
            EVT_WAIT(10 * DT)
            EVT_CALL(PlaySoundAt, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT, 0, 0, -180)
            EVT_CALL(MakeLerp, 0, 90, 15, EASING_COS_FAST_OVERSHOOT)
            EVT_LABEL(10)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(10)
                EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(PlayerMoveTo, -25, -130, 10 * DT)
            EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(N(SwitchToPartner), 1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(NpcMoveTo, NPC_PARTNER, -55, -130, 15 * DT)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kooper, 0)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcPos, NPC_Kooper, 0, 0, -207)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        EVT_WAIT(35 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Run)
        EVT_THREAD
            EVT_LOOP(30 * DT)
                EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(NpcMoveTo, NPC_Kooper, 0, -148, 20 * DT)
        EVT_THREAD
            EVT_CALL(MakeLerp, 90, 0, 30, EASING_COS_IN_OUT)
            EVT_LABEL(20)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(20)
                EVT_END_IF
            EVT_CALL(PlaySoundAt, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT, 0, 0, -180)
            EVT_CALL(SetGroupVisibility, MODEL_g111, MODEL_GROUP_HIDDEN)
        EVT_END_THREAD
        EVT_CALL(NpcMoveTo, NPC_Kooper, 25, -130, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        EVT_CALL(NpcFacePlayer, NPC_Kooper, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_WAIT(10 * DT)
        EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Celebrate, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B5)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
        EVT_WAIT(15 * DT)
        EVT_CALL(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Celebrate)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        EVT_CALL(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
#if VERSION_PAL
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(6 / DT), 30, EVT_FLOAT(225.0), EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
#else
        EVT_CALL(AdjustCam, CAM_DEFAULT, 6, 30, EVT_FLOAT(225.0), EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
#endif
        EVT_WAIT(5 * DT)
        EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B6)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Bow)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        EVT_CALL(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
#if VERSION_PAL
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4 / DT), -30, EVT_FLOAT(225.0), EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
#else
        EVT_CALL(AdjustCam, CAM_DEFAULT, 4, -30, EVT_FLOAT(225.0), EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
#endif
        EVT_WAIT(10 * DT)
        EVT_THREAD
            EVT_WAIT(3 * DT)
            EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EVT_END_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH1_00B7)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, EVT_FLOAT(375.0), EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
        EVT_WAIT(10 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
        EVT_WAIT(10 * DT)
        EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B8)
        EVT_CALL(BindNpcInteract, NPC_Kooper, EVT_PTR(N(EVS_NpcInteract_Kooper)))
        EVT_THREAD
#if VERSION_PAL
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
#else
        EVT_CALL(ResetCam, CAM_DEFAULT, 3)
#endif
        EVT_END_THREAD
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00BA)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00BB)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MeetKooper) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_Kooper))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FuzzyBoss_PlayerEntersKoopersHouse) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(MF_FuzzyBossTaunt, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MF_FuzzyBossTaunt, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_FuzzyBoss, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 0, MSG_CH1_00B9)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_FuzzyBoss, ANIM_Fuzzy_Walk)
    EVT_CALL(GetNpcPos, NPC_FuzzyBoss, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarA)
    EVT_ADD(LVarD, -5)
    EVT_LABEL(10)
        EVT_THREAD
            EVT_CALL(SetNpcJumpscale, NPC_KoopersShell, 2)
            EVT_CALL(NpcJump0, NPC_KoopersShell, LVarD, 0, LVarC, 12 * DT)
        EVT_END_THREAD
        EVT_WAIT(1)
        EVT_CALL(SetNpcJumpscale, NPC_FuzzyBoss, 2)
        EVT_CALL(PlaySoundAtNpc, NPC_FuzzyBoss, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_FuzzyBoss, LVarA, 0, LVarC, 12 * DT)
        EVT_CALL(IsPlayerWithin, 0, -400, 130, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, -514)
    EVT_SET(LVarE, 15 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_KoopersShell, 2)
        EVT_CALL(NpcJump0, NPC_KoopersShell, LVarB, LVarC, LVarD, LVarE)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcJumpscale, NPC_FuzzyBoss, 2)
    EVT_CALL(PlaySoundAtNpc, NPC_FuzzyBoss, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_FuzzyBoss, LVarB, LVarC, LVarD, LVarE)
    EVT_CALL(SetNpcFlagBits, NPC_FuzzyBoss, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_KoopersShell, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_FuzzyBoss, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

Vec2i N(FuzzyJumpPath1)[] = {
    { -466,  103 },
    { -441,  213 },
    { -385,  285 },
    { -302,  324 },
    { -250,  428 },
    { -158,  451 },
    {  -45,  485 },
    {   62,  428 },
    {  214,  424 },
    {  324,  295 },
    {  416,  193 },
    {  293,  123 },
    {  181,   63 },
    {   95,   57 },
    {  -14,   16 },
    { -161,   56 },
    { -317,   81 },
    { -401,   73 },
};

Vec2i N(FuzzyJumpPath2)[] = {
    {  416,  193 },
    {  324,  295 },
    {  214,  424 },
    {   62,  428 },
    {  -45,  485 },
    { -158,  451 },
    { -250,  428 },
    { -302,  324 },
    { -385,  285 },
    { -441,  213 },
    { -466,  103 },
    { -401,   73 },
    { -317,   81 },
    { -161,   56 },
    {  -14,   16 },
    {   95,   57 },
    {  181,   63 },
    {  293,  123 },
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
        EVT_LOOP(18)
            EVT_SET(LVar1, 0)
            EVT_BUF_READ2(LVar0, LVar2)
            EVT_CALL(RandInt, 10, LVar3)
            EVT_ADD(LVar3, 15)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
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
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(100)
        EVT_IF_EQ(AF_NOK_13, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(100)
        EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, 438, 150, 155)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, 438, 0, 150, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, 402, 0, 160, 15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, 384, 0, 160, 7)
    EVT_LABEL(0)
        EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath2)))
        EVT_LOOP(18)
            EVT_SET(LVar1, 0)
            EVT_BUF_READ2(LVar0, LVar2)
            EVT_CALL(RandInt, 9, LVar3)
            EVT_ADD(LVar3, 13)
            EVT_MULF(LVar0, EVT_FLOAT(0.9))
            EVT_MULF(LVar2, EVT_FLOAT(0.9))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, LVar3)
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

EvtScript N(EVS_NpcInit_MiscFuzzy1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MiscFuzzy1)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MiscFuzzy1)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MiscFuzzy2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MiscFuzzy2)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MiscFuzzy2)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_Later) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MiscFuzzy2)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MiscFuzzy2)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakBlock_DropShell) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_NOK02_RecoveredShellB, TRUE)
    EVT_CALL(BindNpcAI, NPC_Koopa_02, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcJump0, NPC_KoopaShell_02, 227, 0, 247, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaShell_02, SOUND_ITEM_BOUNCE, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlayerFaceNpc, NPC_KoopaShell_02, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_Koopa_02, NPC_KoopaShell_02, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Happy)
    EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_KoopaShell_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Run)
    EVT_CALL(NpcMoveTo, NPC_Koopa_02, LVar0, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlayerFaceNpc, NPC_Koopa_02, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Koopa_02, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, NPC_KoopaShell_02)
    EVT_SET(LVar4, NPC_Koopa_02)
    EVT_EXEC(N(EVS_GetIntoShell))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_KoopaShell_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Happy)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Happy, ANIM_Koopa_Idle, 0, MSG_CH1_005E)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "npcs_crisis.inc.c"
#include "npcs_normal.inc.c"

EvtScript N(EVS_AnimateDoor_KoloradoHouse) = {
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 15, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, 80, 0, 15, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoloradoWife_FetchFromHouse) = {
    EVT_CALL(EnableModel, MODEL_g98, TRUE)
    EVT_CALL(EnableGroup, MODEL_g109, TRUE)
    EVT_CALL(EnableGroup, MODEL_g47, TRUE)
    EVT_SET(LVarA, MODEL_g42)
    EVT_SET(LVar9, COLLIDER_o310)
    EVT_EXEC(N(EVS_AnimateDoor_KoloradoHouse))
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -314, -94, 10)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -304, -161, 20)
    EVT_WAIT(100)
    EVT_EXEC(N(EVS_AnimateDoor_KoloradoHouse))
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -308, -102, 20)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -338, -85, 20)
    EVT_CALL(NpcFacePlayer, NPC_KoloradoWife, 0)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife, ANIM_KoloradoWife_Idle)
    EVT_CALL(EnableModel, MODEL_g98, FALSE)
    EVT_CALL(EnableGroup, MODEL_g109, FALSE)
    EVT_CALL(EnableGroup, MODEL_g47, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoloradoWife_FetchFromOffice) = {
    EVT_SET(LVarA, MODEL_g41)
    EVT_SET(LVar9, COLLIDER_o314)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -277, -186, 20)
    EVT_EXEC(N(EVS_AnimateDoor_KoloradoHouse))
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -265, -261, 20)
    EVT_WAIT(100)
    EVT_EXEC(N(EVS_AnimateDoor_KoloradoHouse))
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -277, -186, 20)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife, -328, -180, 20)
    EVT_CALL(NpcFacePlayer, NPC_KoloradoWife, 0)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife, ANIM_KoloradoWife_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoloradoWife_FetchKoopaLegends) = {
    EVT_CALL(SetNpcFlagBits, NPC_KoloradoWife, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0090)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife, ANIM_KoloradoWife_Walk)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_EXEC_WAIT(N(EVS_KoloradoWife_FetchFromHouse))
    EVT_ELSE
        EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
            EVT_EXEC_WAIT(N(EVS_KoloradoWife_FetchFromHouse))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_KoloradoWife_FetchFromOffice))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0091)
    EVT_GIVE_KEY_REWARD(ITEM_KOOT_KOOPA_LEGENDS)
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0092)
    EVT_CALL(SetNpcFlagBits, NPC_KoloradoWife, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoloradoWife) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_IF_EQ(GF_NOK02_KoloradoWife_FuzzyComplaint, FALSE)
                EVT_SET(GF_NOK02_KoloradoWife_FuzzyComplaint, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0088)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0089)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008A)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008C)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008D)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008E)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008F)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008F)
    EVT_END_SWITCH
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH1_2)
        EVT_IF_EQ(GF_NOK02_Gift_KoopaLegends, FALSE)
            EVT_SET(GF_NOK02_Gift_KoopaLegends, TRUE)
            EVT_EXEC_WAIT(N(EVS_MarioSalute))
            EVT_EXEC_WAIT(N(EVS_KoloradoWife_FetchKoopaLegends))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoloradoWife) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoloradoWife)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, -338, 0, -85)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -338, 0, -85)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaKoot) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoopaKoot)))
    EVT_EXEC(N(EVS_SetupKootFavors))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -25, 10, -50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 25, 0, -50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoloradoWife_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -150, 0, -50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Crisis)[] = {
    {
        .id = NPC_Koopa_01,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -109, 0, 191 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -109, 0, 191 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_01_Crisis),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaC,
    },
    {
        .id = NPC_FuzzyThief,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Fuzzy_Thief),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KoopaShell_01,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaShell_01_Crisis),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Koopa_02,
        .pos = { 192.0f, 0.0f, 152.0f },
        .yaw = 0,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 199, 0, 152 },
                    { 107, 0, 152 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 192, 0, 152 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_02_Crisis),
        .settings = &N(NpcSettings_KoopaWithoutShell_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_WITHOUT_SHELL_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaD,
    },
    {
        .id = NPC_KoopaShell_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaShell_02_Crisis),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Kooper,
        .pos = { 20.0f, 0.0f, -145.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Kooper),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPER_ANIMS,
        .tattle = MSG_NpcTattle_NOK_Kooper,
    },
    {
        .id = NPC_FuzzyBoss,
        .pos = { 12.0f, 10.0f, -351.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FuzzyBoss),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KoopersShell,
        .pos = { 12.0f, 0.0f, -351.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_KoopersShell),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPER_ANIMS,
    },
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_MiscFuzzy1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_MiscFuzzy1),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_MiscFuzzy2,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_MiscFuzzy2),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Normal)[] = {
    {
        .id = NPC_Koopa_01,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -124, 0, 250 },
                .wanderSize = { 80 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -85, 0, 260 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_01_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaC,
    },
    {
        .id = NPC_Koopa_02,
        .pos = { 200.0f, 0.0f, 117.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 200, 0, 117 },
                .wanderSize = { 50, 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 170 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_02_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaD,
    },
    {
        .id = NPC_Bobomb_01,
        .pos = { 0.0f, 0.0f, -333.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Bobomb_01),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = BOBOMB_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombD,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { -7.0f, 0.0f, -285.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bobomb_02),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombE,
    },
    {
        .id = NPC_Bobomb_03,
        .pos = { 47.0f, 0.0f, -140.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Bobomb_03),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombF,
    },
    {
        .id = NPC_Kolorado,
        .pos = { -240.0f, 0.0f, -70.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

NpcData N(NpcData_Fuzzy_Later) = {
    .id = NPC_Fuzzy_Later,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy_Later),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Shared)[] = {
    {
        .id = NPC_KoopaKoot,
        .pos = { 330.0f, 0.0f, -100.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaKoot),
        .settings = &N(NpcSettings_KoopaKoot),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_KOOT_ANIMS,
        .tattle = MSG_NpcTattle_KoopaKoot,
    },
    {
        .id = NPC_KoloradoWife,
        .pos = { -328.0f, 0.0f, -180.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoloradoWife),
        .settings = &N(NpcSettings_KoloradoWife),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_WIFE_ANIMS,
        .tattle = MSG_NpcTattle_KoloradoWife,
    },
    {
        .id = NPC_Koopa_03,
        .pos = { -307.0f, 0.0f, 97.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Koopa_03),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_SenseOfJustice,
    },
    {
        .id = NPC_Koopa_04,
        .pos = { 285.0f, 0.0f, 223.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 240, 0, 175 },
                    { 350, 0, 250 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_04),
        .settings = &N(NpcSettings_KoopaWithoutShell_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_PrettyMellow,
    },
};

NpcData N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Parakarry,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopa_Epilogue),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
    },
    {
        .id = NPC_Bombette,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bombette_Epilogue),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldBombette_Idle,
            .walk   = ANIM_WorldBombette_Walk,
            .run    = ANIM_WorldBombette_Walk,
            .chase  = ANIM_WorldBombette_Walk,
            .anim_4 = ANIM_WorldBombette_Walk,
            .anim_5 = ANIM_WorldBombette_Walk,
            .death  = ANIM_WorldBombette_Still,
            .hit    = ANIM_WorldBombette_Still,
            .anim_8 = ANIM_WorldBombette_Still,
            .anim_9 = ANIM_WorldBombette_Still,
            .anim_A = ANIM_WorldBombette_Still,
            .anim_B = ANIM_WorldBombette_Still,
            .anim_C = ANIM_WorldBombette_Still,
            .anim_D = ANIM_WorldBombette_Still,
            .anim_E = ANIM_WorldBombette_Still,
            .anim_F = ANIM_WorldBombette_Still,
        },
    },
    {
        .id = NPC_KoloradoWife_Epilogue,
        .pos = { -328.0f, 0.0f, -180.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoloradoWife_Epilogue),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = KOLORADO_WIFE_ANIMS,
        .tattle = MSG_NpcTattle_KoloradoWife,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 300.0f, 0.0f, 330.0f },
    .yaw = 270,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_NOK, QUIZ_COUNT_NOK, QUIZ_MAP_NOK_02 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(CrisisNPCs) = {
    NPC_GROUP(N(NpcData_Crisis)),
    NPC_GROUP(N(NpcData_Shared)),
    NPC_GROUP(N(NpcData_Fuzzy_01)),
    NPC_GROUP(N(NpcData_Fuzzy_02)),
    {}
};

NpcGroupList N(NormalNPCs) = {
    NPC_GROUP(N(NpcData_Normal)),
    NPC_GROUP(N(NpcData_Shared)),
    NPC_GROUP(N(NpcData_Fuzzy_Later)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Epilogue)),
    {}
};
