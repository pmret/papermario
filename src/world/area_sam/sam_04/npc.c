#include "sam_04.h"
#include "effects.h"

#include "world/common/npc/Penguin.h"

NpcSettings N(NpcSettings_Snowman) = {
    .height = 60,
    .radius = 40,
    .level = ACTOR_LEVEL_NONE,
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
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Snowman_02) = {
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Snowman_04) = {
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Snowman_05) = {
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Scarf) = {
    Call(DisablePlayerInput, TRUE)
    Call(FindKeyItem, ITEM_SNOWMAN_SCARF, LVar0)
    IfNe(LVar0, -1)
        Call(ShowKeyChoicePopup)
        Call(CloseChoicePopup)
        Switch(LVar0)
            CaseEq(0)
            CaseEq(-1)
            CaseDefault
                Set(GF_SAM04_PlacedScarf, TRUE)
                Call(RemoveKeyItemAt, LVar1)
                Call(EnableModel, CLONED_MODEL(11), TRUE)
                IfEq(GF_SAM04_PlacedBucket, TRUE)
                    Call(GetNpcPos, NPC_Snowman_03, LVar0, LVar1, LVar2)
                    Add(LVar1, 30)
                    Add(LVar2, 20)
                    Call(PlaySoundAt, SOUND_STAR_SPIRIT_CAST_A, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
                    Wait(20)
                    Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                    Set(LVar0, 0)
                    ExecWait(N(EVS_Scene_SnowmenSpeak))
                EndIf
        EndSwitch
    Else
        Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EndIf
    Unbind
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Snowman_03) = {
    BindPadlock(Ref(N(EVS_ItemPrompt_Scarf)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(ScarfList)), 0, 1)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Bucket) = {
    Call(DisablePlayerInput, TRUE)
    Call(FindKeyItem, ITEM_SNOWMAN_BUCKET, LVar0)
    IfNe(LVar0, -1)
        Call(ShowKeyChoicePopup)
        Call(CloseChoicePopup)
        Switch(LVar0)
            CaseEq(0)
            CaseEq(-1)
            CaseDefault
                Set(GF_SAM04_PlacedBucket, TRUE)
                Call(RemoveKeyItemAt, LVar1)
                Call(EnableModel, MODEL_baketu, TRUE)
                IfEq(GF_SAM04_PlacedScarf, TRUE)
                    Call(GetNpcPos, NPC_Snowman_06, LVar0, LVar1, LVar2)
                    Add(LVar1, 60)
                    Add(LVar2, 20)
                    Call(PlaySoundAt, SOUND_STAR_SPIRIT_CAST_A, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
                    Wait(20)
                    Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                    Set(LVar0, 1)
                    ExecWait(N(EVS_Scene_SnowmenSpeak))
                EndIf
        EndSwitch
    Else
        Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Snowman, 160, 40)
    EndIf
    Unbind
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Snowman_06) = {
    BindPadlock(Ref(N(EVS_ItemPrompt_Bucket)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(BucketList)), 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Snowman_01) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Snowman_02) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Snowman_03) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Snowman_04) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Snowman_05) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Snowman_06) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Snowman_01) = {
EndIf
Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Snowman_01)))
Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Snowman_01)))
Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
Call(EnableNpcShadow, NPC_SELF, FALSE)
Return
End
};

EvtScript N(EVS_NpcInit_Snowman_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Snowman_02)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Snowman_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Snowman_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Snowman_03)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Snowman_03)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Snowman_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Snowman_04)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Snowman_04)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Snowman_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Snowman_05)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Snowman_05)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Snowman_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Snowman_06)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Snowman_06)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Dummy) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = PENGUIN_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Snowmen)),
    NPC_GROUP(N(NpcData_Dummy)),
    {}
};
