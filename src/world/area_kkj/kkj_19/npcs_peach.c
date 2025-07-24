#include "kkj_19.h"

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcInteract_Twink) = {
    Call(SetSelfVar, 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Twink) = {
    Loop(0)
        Wait(1)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 1)
            Call(NpcFacePlayer, NPC_PARTNER, 0)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, true)
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcCollisionSize, NPC_SELF, 20, 20)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Twink)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Twink)))
    Return
    End
};

// normally, you cant interact with your partner, so a dummy npc is created to allow it
NpcData N(NpcData_Twink) = {
    .id = NPC_Twink,
    .pos = { 0.0f, -500.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_CANT_INTERACT,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
};

NpcGroupList N(PeachNPCs) = {
    NPC_GROUP(N(NpcData_Twink)),
    {}
};
