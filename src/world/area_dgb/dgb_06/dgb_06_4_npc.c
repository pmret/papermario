#include "dgb_06.h"

#include "world/common/npc/Boo.inc.c"

EvtScript N(EVS_NpcInteract_Boo) = {
    EVT_IF_EQ(AF_DGB06_Boo_Dialogue, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00F0)
        EVT_SET(AF_DGB06_Boo_Dialogue, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00F1)
        EVT_SET(AF_DGB06_Boo_Dialogue, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Boo) = {
    .id = NPC_Boo,
    .pos = { -300.0f, 10.0f, 150.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Boo),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_HidingBoo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Boo)),
    {}
};
