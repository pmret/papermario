#include "kkj_16.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Later

#include "world/common/enemy/HammerBros.inc.c"

AnimID N(ExtraAnims_HammerBros)[] = {
    ANIM_HammerBros_Anim00,
    ANIM_HammerBros_Anim02,
    ANIM_HammerBros_Anim03,
    ANIM_HammerBros_Anim04,
    ANIM_HammerBros_Anim06,
    ANIM_HammerBros_Anim07,
    ANIM_HammerBros_Anim09,
    ANIM_HammerBros_Anim0A,
    ANIM_HammerBros_Anim0B,
    ANIM_HammerBros_Anim1A,
    ANIM_LIST_END
};

#include "../common/Searchlights.inc.c"
#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/PreventNextPeachDisguise.inc.c"
#include "../common/ApproachPlayer50Units.inc.c"

EvtScript N(EVS_NpcInteract_HammerBros_01) = {
    EVT_IF_EQ(GF_KKJ16_Gift_ShootingStar, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 16, MSG_Peach_013A)
        EVT_CALL(ShowGotItem, ITEM_SHOOTING_STAR, TRUE, ITEM_PICKUP_FLAG_NO_ANIMS)
        EVT_SET(GF_KKJ16_Gift_ShootingStar, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 16, MSG_Peach_013B)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_HammerBros_02) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0136)
        EVT_CALL(SetSelfVar, 0, 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0137)
        EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_HammerBros_03) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0138)
        EVT_CALL(SetSelfVar, 0, 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0139)
        EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CapturePeach) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(PreventNextPeachDisguise))
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0174)
    EVT_CALL(N(ApproachPlayer50Units), -1, LVar3, LVar0, LVar2)
    EVT_IF_NE(LVar3, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim07)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0175)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    EVT_WAIT(20)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WatchForPlayer) = {
    EVT_LOOP(0)
        EVT_CALL(N(GetPeachDisguise), LVar1)
        EVT_IF_EQ(LVar1, PEACH_DISGUISE_NONE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
            EVT_CALL(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_HammerBros_01) = {
    EVT_EXEC(N(EVS_WatchForPlayer))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_HammerBros_02) = {
    EVT_EXEC(N(EVS_WatchForPlayer))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.7))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, 280, 50, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, 80, 50, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_HammerBros_03) = {
    EVT_EXEC(N(EVS_WatchForPlayer))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.7))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, -600, 50, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, -420, 50, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HammerBros_01) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -700, 0, 50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_HammerBros_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HammerBros_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HammerBros_02) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 180, 0, 50)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_HammerBros_02)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HammerBros_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HammerBros_03) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -510, 0, 50)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_HammerBros_03)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HammerBros_03)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Minions)[] = {
    {
        .id = NPC_HammerBros_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros_01),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
    {
        .id = NPC_HammerBros_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros_02),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
    {
        .id = NPC_HammerBros_03,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros_03),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
};

#define NAME_SUFFIX

NpcGroupList N(LaterNPCs) = {
    NPC_GROUP(N(NpcData_Minions_Later)),
    {}
};
