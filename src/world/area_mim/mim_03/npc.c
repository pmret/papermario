#include "mim_03.h"

#include "world/common/npc/Oaklie.inc.c"

EvtScript N(EVS_NpcInteract_Oaklie) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_BOW_JOINED_PARTY)
            IfEq(AF_MIM03_Oaklie_DialogueToggle, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0009)
                Set(AF_MIM03_Oaklie_DialogueToggle, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000A)
                Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
            EndIf
        CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            IfEq(AF_MIM03_Oaklie_DialogueToggle, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000B)
                Set(AF_MIM03_Oaklie_DialogueToggle, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000C)
                Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
            EndIf
        CaseGe(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            IfEq(AF_MIM03_Oaklie_DialogueToggle, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000D)
                Set(AF_MIM03_Oaklie_DialogueToggle, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000E)
                Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
            EndIf
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Oaklie)))
    Return
    End
};

NpcData N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .pos = { 0.0f, 32.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Oaklie)),
    {}
};
