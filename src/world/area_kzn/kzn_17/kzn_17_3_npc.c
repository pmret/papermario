#include "kzn_17.h"

#include "world/common/npc/Kolorado.inc.c"

#include "world/common/enemy/PutridPiranha.inc.c"
#include "world/common/enemy/SpikeTop.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado1, NPC_Kolorado,
    ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_PROMPT(Kolorado2, NPC_Kolorado,
    ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E8, MSG_CH5_00E9, MSG_CH5_00EA, MSG_CH5_00EB,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

Vec3f N(KoloradoThrownPath)[] = {
    {  447.0,     0.0,   39.0 },
    {  432.0,     5.0,   47.0 },
    {  427.0,    20.0,   55.0 },
    {  432.0,     5.0,   62.0 },
    {  447.0,     0.0,   70.0 },
};

EvtScript N(EVS_Kolorado_TrompPanic) = {
    EVT_CALL(SetNpcPos, NPC_Kolorado, 447, 0, 39)
    EVT_CALL(SetNpcYaw, NPC_Kolorado, 270)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_TrompImpact) = {
    EVT_CALL(SetEnemyFlagBits, NPC_Kolorado, ENEMY_FLAG_400000, 1)
    EVT_CALL(SetNpcRotationPivot, NPC_Kolorado, 13)
    EVT_CALL(SetNpcRotation, NPC_Kolorado, 0, 0, 250)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_HurtStill)
    EVT_CALL(SetNpcImgFXParams, NPC_Kolorado, IMGFX_SET_WAVY, EVT_FLOAT(3.0), EVT_FLOAT(3.0), 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Kolorado, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(SetNpcCollisionSize, NPC_Kolorado, 20, 24)
        EVT_CALL(LoadPath, 30, EVT_PTR(N(KoloradoThrownPath)), ARRAY_COUNT(N(KoloradoThrownPath)), EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kolorado, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_HurtStill, ANIM_Kolorado_HurtStill, 5, MSG_CH5_00F9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_HurtInit) = {
    EVT_CALL(SetNpcPos, NPC_Kolorado, 447, 0, 70)
    EVT_CALL(SetNpcYaw, NPC_Kolorado, 270)
    EVT_CALL(SetEnemyFlagBits, NPC_Kolorado, ENEMY_FLAG_400000, 1)
    EVT_CALL(SetNpcRotationPivot, NPC_Kolorado, 13)
    EVT_CALL(SetNpcRotation, NPC_Kolorado, 0, 0, 250)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_HurtStill)
    EVT_CALL(SetNpcImgFXParams, NPC_Kolorado, IMGFX_SET_WAVY, EVT_FLOAT(3.0), EVT_FLOAT(3.0), 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 605)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00F7, 160, 40)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 290, 0, 30)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(NpcMoveTo, NPC_SELF, 640, 80, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00F8)
    EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_AT_DEAD_END)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00FC)
        EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado1))
        EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_HurtStill, 5, MSG_CH5_00FA)
        EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado2))
        EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_KOLORADO_AT_DEAD_END)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
            EVT_RETURN
        EVT_CASE_LT(STORY_CH5_HIDDEN_PASSAGE_OPEN)
            EVT_CALL(SetNpcPos, NPC_SELF, 640, 0, 80)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
            EVT_RETURN
        EVT_CASE_EQ(STORY_CH5_HIDDEN_PASSAGE_OPEN)
            EVT_CALL(SetNpcCollisionSize, NPC_Kolorado, 20, 24)
            EVT_EXEC(N(EVS_Kolorado_HurtInit))
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Piranha)[] = {
    {
        .id = NPC_Piranha,
        .pos = { -325.0f, 0.0f, 150.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -325, 0, 150 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { -390, 0, 130 },
                .detectSize = { 270, 130 },
            }
        },
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = PUTRID_PIRANHA_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox)
};

NpcData N(NpcData_SpikeTop) = {
    .id = NPC_SpikeTop,
    .pos = { -450.0f, 0.0f, 100.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -450, 0, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -450, 0, 100 },
            .detectSize = { 270, 130 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Piranha), BTL_KZN_FORMATION_14, BTL_KZN_STAGE_00),
    NPC_GROUP(N(NpcData_SpikeTop), BTL_KZN_FORMATION_0D, BTL_KZN_STAGE_00),
    {}
};
