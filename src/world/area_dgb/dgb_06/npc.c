#include "dgb_06.h"

#include "world/common/npc/Boo.inc.c"

EvtScript N(EVS_NpcInteract_Boo) = {
    IfEq(AF_DGB06_Boo_Dialogue, false)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00F0)
        Set(AF_DGB06_Boo_Dialogue, true)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00F1)
        Set(AF_DGB06_Boo_Dialogue, false)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo) = {
    IfGe(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo)))
    Return
    End
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
