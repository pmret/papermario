#include "kkj_18.h"

#include "world/common/npc/GourmetGuy.inc.c"
#include "world/common/npc/Dummy.inc.c"

#include "world/common/enemy/Kammy.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"

EvtScript N(EVS_NpcIdle_GourmetGuy) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_EXEC(N(EVS_ManageGourmetGuyScenes))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_GourmetGuy_Excited) = {
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_00A1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_GourmetGuy_Scold) = {
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_00A6)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GourmetGuy) = {
    EVT_CALL(EnableGroup, MODEL_g12, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g15, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcPos, NPC_SELF, 120, 0, -20)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_IF_EQ(AF_KKJ_FinishedBakingCake, FALSE)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GourmetGuy_Excited)))
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GourmetGuy_Scold)))
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GourmetGuy)))
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy_Knife, ANIM_GourmetGuy_Knife)
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_GourmetGuy_Knife, FALSE)
    EVT_CALL(SetNpcPos, NPC_GourmetGuy_Knife, 60, 40, -15)
    EVT_CALL(SetNpcYaw, NPC_GourmetGuy_Knife, 270)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy_Fork, ANIM_GourmetGuy_Fork)
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_GourmetGuy_Fork, FALSE)
    EVT_CALL(SetNpcPos, NPC_GourmetGuy_Fork, 125, 40, -15)
    EVT_CALL(SetNpcYaw, NPC_GourmetGuy_Fork, 270)
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_GourmetGuy)[] = {
    ANIM_GourmetGuy_Idle,
    ANIM_GourmetGuy_Walk,
    ANIM_GourmetGuy_Panic,
    ANIM_GourmetGuy_Talk,
    ANIM_GourmetGuy_Eat,
    ANIM_GourmetGuy_SpitOut,
    ANIM_GourmetGuy_Surprise,
    ANIM_GourmetGuy_TalkSurprise,
    ANIM_GourmetGuy_Leap,
    ANIM_GourmetGuy_Inspect,
    ANIM_GourmetGuy_Knife,
    ANIM_GourmetGuy_Fork,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim01,
    ANIM_WorldKammy_Anim02,
    ANIM_WorldKammy_Anim04,
    ANIM_WorldKammy_Anim05,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_LIST_END
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Kammy,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Kammy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KAMMY_ANIMS,
        .extraAnimations = N(ExtraAnims_Kammy),
    },
    {
        .id = NPC_Koopatrol_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_GourmetGuy,
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_GourmetGuy),
        .settings = &N(NpcSettings_GourmetGuy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GOURMET_GUY_ANIMS,
        .extraAnimations = N(ExtraAnims_GourmetGuy),
    },
    {
        .id = NPC_GourmetGuy_Knife,
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GOURMET_GUY_ANIMS,
        .extraAnimations = N(ExtraAnims_GourmetGuy),
    },
    {
        .id = NPC_GourmetGuy_Fork,
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GOURMET_GUY_ANIMS,
        .extraAnimations = N(ExtraAnims_GourmetGuy),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    {}
};
