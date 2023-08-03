#include "sam_04.h"
#include "effects.h"

#include "world/common/npc/Penguin.h"

NpcSettings N(NpcSettings_Snowman) = {
    .height = 60,
    .radius = 40,
    .level = 99,
};

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

s32 N(BucketList)[] = {
    ITEM_SNOWMAN_BUCKET,
    ITEM_NONE
};

s32 N(ScarfList)[] = {
    ITEM_SNOWMAN_SCARF,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Snowman_01) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Snowman_02) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Snowman_04) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Snowman_05) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Scarf) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FindKeyItem, ITEM_SNOWMAN_SCARF, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(-1)
            EVT_CASE_DEFAULT
                EVT_SET(GF_SAM04_PlacedScarf, TRUE)
                EVT_CALL(RemoveKeyItemAt, LVar1)
                EVT_CALL(EnableModel, CLONED_MODEL(11), TRUE)
                EVT_IF_EQ(GF_SAM04_PlacedBucket, TRUE)
                    EVT_CALL(GetNpcPos, NPC_Snowman_03, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar1, 30)
                    EVT_ADD(LVar2, 20)
                    EVT_CALL(PlaySoundAt, SOUND_2043, 0, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
                    EVT_WAIT(20)
                    EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                    EVT_SET(LVar0, 0)
                    EVT_EXEC_WAIT(N(EVS_Scene_SnowmenSpeak))
                EVT_END_IF
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EVT_END_IF
    EVT_UNBIND
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Snowman_03) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Scarf)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(ScarfList)), 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Bucket) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FindKeyItem, ITEM_SNOWMAN_BUCKET, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(-1)
            EVT_CASE_DEFAULT
                EVT_SET(GF_SAM04_PlacedBucket, TRUE)
                EVT_CALL(RemoveKeyItemAt, LVar1)
                EVT_CALL(EnableModel, MODEL_baketu, TRUE)
                EVT_IF_EQ(GF_SAM04_PlacedScarf, TRUE)
                    EVT_CALL(GetNpcPos, NPC_Snowman_06, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar1, 60)
                    EVT_ADD(LVar2, 20)
                    EVT_CALL(PlaySoundAt, SOUND_2043, 0, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
                    EVT_WAIT(20)
                    EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                    EVT_SET(LVar0, 1)
                    EVT_EXEC_WAIT(N(EVS_Scene_SnowmenSpeak))
                EVT_END_IF
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EVT_END_IF
    EVT_UNBIND
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Snowman_06) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Bucket)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(BucketList)), 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Snowman_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Snowman_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Snowman_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Snowman_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Snowman_05) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Snowman_06) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Snowman_01) = {
EVT_END_IF
EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Snowman_01)))
EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Snowman_01)))
EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
EVT_RETURN
EVT_END
};

EvtScript N(EVS_NpcInit_Snowman_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Snowman_02)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Snowman_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Snowman_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Snowman_03)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Snowman_03)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Snowman_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Snowman_04)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Snowman_04)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Snowman_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Snowman_05)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Snowman_05)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Snowman_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Snowman_06)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Snowman_06)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dummy) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Snowmen)[] = {
    {
        .id = NPC_Snowman_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Snowman_01),
        .settings = &N(NpcSettings_Snowman),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_Snowman,
    },
    {
        .id = NPC_Snowman_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Snowman_02),
        .settings = &N(NpcSettings_Snowman),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_Snowman,
    },
    {
        .id = NPC_Snowman_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Snowman_03),
        .settings = &N(NpcSettings_Snowman),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_Snowman,
    },
    {
        .id = NPC_Snowman_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Snowman_04),
        .settings = &N(NpcSettings_Snowman),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_Snowman,
    },
    {
        .id = NPC_Snowman_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Snowman_05),
        .settings = &N(NpcSettings_Snowman),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_Snowman,
    },
    {
        .id = NPC_Snowman_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Snowman_06),
        .settings = &N(NpcSettings_Snowman),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_Snowman,
    },
};

NpcData N(NpcData_Dummy) = {
    .id = NPC_LetterDummy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Dummy),
    .settings = &N(NpcSettings_Snowman),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = PENGUIN_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Snowmen)),
    NPC_GROUP(N(NpcData_Dummy)),
    {}
};
