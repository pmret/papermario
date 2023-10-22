#include "kzn_02.h"
#include "sprite/player.h"

#include "world/common/enemy/LavaBubble.inc.c"

#include "world/common/npc/Kolorado.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado,
    ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -825)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), 100, 350, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00EE)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_LOOP(30)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, -740, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -650, 20, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Thrown)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, -655, 20, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
    EVT_CALL(NpcJump0, NPC_SELF, -645, 20, 0, 5)
    EVT_CALL(NpcJump0, NPC_SELF, -635, 20, 0, 5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_WAIT(15)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_WAIT(10)
    EVT_EXEC(N(EVS_KoloradoSinkingPlatform))
    EVT_SET(LVar0, 2)
    EVT_LOOP(3)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        EVT_CALL(ShowSweat, NPC_Kolorado, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(NpcMoveTo, NPC_SELF, -655, 0, LVar0)
        EVT_CALL(ShowSweat, NPC_Kolorado, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_CALL(NpcMoveTo, NPC_SELF, -635, 0, LVar0)
        EVT_MUL(LVar0, 2)
    EVT_END_LOOP
    EVT_CALL(ShowSweat, NPC_Kolorado, 0, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 2)
    EVT_CALL(ShowSweat, NPC_Kolorado, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Hurt)
    EVT_CALL(ShowSweat, NPC_Kolorado, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_THREAD
        EVT_LABEL(15)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 10)
        EVT_CALL(GetSelfVar, 0, LVar3)
        EVT_IF_EQ(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TOUCH_LAVA, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, -700, 150, 0, 35)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_CALL(NpcJump0, NPC_SELF, -775, 20, -40, 40)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 2)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, -760, 50, -40, 10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_WAIT(4)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 2)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, -760, 40, -40, 10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_WAIT(4)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 4)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_00EF)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 4)
    EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_FELL_IN_LAVA)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00F0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 7)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_CALL(CloseMessage)
    EVT_LETTER_CHECK(Kolorado)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_KOLORADO_FELL_IN_LAVA)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
        EVT_CASE_LT(STORY_CH5_LAVA_STREAM_BLOCKED)
            EVT_IF_EQ(GF_KZN06_Visited, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, -760, 20, -40)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -740.0f, 20.0f, 0.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_LavaBubble) = {
    .id = NPC_LavaBubble,
    .pos = { 250.0f, 50.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 250, 50, 0 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 250, 50, 0 },
            .detectSize = { 70, 200 },
        }
    },
    .settings = &N(NpcSettings_LavaBubble),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAVA_BUBBLE_DROPS,
    .animations = LAVA_BUBBLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_LavaBubble), BTL_KZN_FORMATION_00, BTL_KZN_STAGE_02),
    {}
};
