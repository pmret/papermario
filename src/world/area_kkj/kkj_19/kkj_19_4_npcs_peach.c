#include "kkj_19.h"

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcInteract_Twink) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Twink) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 20, 20)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Twink)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Twink)))
    EVT_RETURN
    EVT_END
};

// normally, you cant interact with your partner, so a dummy npc is created to allow it
NpcData N(NpcData_Twink) = {
    .id = NPC_Twink,
    .pos = { 0.0f, -500.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_CANT_INTERACT,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
};

NpcGroupList N(PeachNPCs) = {
    NPC_GROUP(N(NpcData_Twink)),
    {}
};
