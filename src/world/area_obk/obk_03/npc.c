#include "obk_03.h"

#include "world/common/npc/Boo.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Igor)[] = {
    ITEM_LETTER_TO_IGOR,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Igor) = {
    Call(N(LetterDelivery_Init),
        NPC_Igor, ANIM_Boo_Talk, ANIM_Boo_Idle,
        ITEM_LETTER_TO_IGOR, ITEM_NONE,
        MSG_CH3_005D, MSG_CH3_005E, MSG_CH3_005F, MSG_CH3_0060,
        Ref(N(LetterList_Igor)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Igor) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Igor) = {
    IfGe(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        ExecWait(EVS_ShopOwnerDialog)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_005C)
    EndIf
    ExecWait(N(EVS_LetterPrompt_Igor))
    ExecWait(N(EVS_LetterReward_Igor))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Igor) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Igor)))
    Return
    End
};

NpcData N(NpcData_Igor) = {
    .id = NPC_Igor,
    .pos = { 43.0f, -200.0f, -9.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Igor),
    .settings = &N(NpcSettings_Boo),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
    .tattle = MSG_NpcTattle_OBK_ShopOwner,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Igor)),
    {}
};
