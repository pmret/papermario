#include "osr_02.h"

#include "world/common/todo/GetPeachDisguise.inc.c"

#include "world/common/enemy/Clubba.inc.c"

AnimID N(ExtraAnims_Clubba)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim05,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim13,
    ANIM_WorldClubba_Anim14,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcInteract_Clubba) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(CancelMessage)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim08)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim02)
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar1, MSG_Peach_014A)
        EVT_CASE_EQ(3)
            EVT_SET(LVar1, MSG_Peach_014B)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, MSG_Peach_014C)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Anim05, ANIM_WorldClubba_Anim02, 16, LVar1)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Clubba) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(AwaitPlayerApproach, LVar1, LVar3, 85)
            EVT_THREAD
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Anim07, ANIM_WorldClubba_Anim07, 5, MSG_Peach_0149)
            EVT_END_THREAD
            EVT_CALL(SetSelfVar, 0, 1)
        EVT_ELSE
            EVT_CALL(AwaitPlayerLeave, LVar1, LVar3, 90)
            EVT_CALL(CancelMessage)
            EVT_CALL(SetSelfVar, 0, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_CALL(SetNpcPos, NPC_SELF, -40, 20, -170)
    EVT_CALL(SetNpcYaw, NPC_SELF, 200)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Clubba)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Clubba)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Clubba) = {
    .id = NPC_Clubba,
    .pos = { -70.0f, 0.0f, -100.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Clubba),
    .settings = &N(NpcSettings_Clubba),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = CLUBBA_ANIMS,
    .extraAnimations = N(ExtraAnims_Clubba),
};

NpcGroupList N(PeachNPCs) = {
    NPC_GROUP(N(NpcData_Clubba)),
    {}
};
