#include "obk_03.h"

#include "world/common/npc/Boo.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Igor)[] = {
    ITEM_LETTER_TO_IGOR,
    ITEM_NONE
};

EvtScript N(EVS_LetterCheck_Igor) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Igor, ANIM_Boo_Talk, ANIM_Boo_Idle,
        ITEM_LETTER_TO_IGOR, ITEM_NONE,
        MSG_CH3_005D, MSG_CH3_005E, MSG_CH3_005F, MSG_CH3_0060,
        EVT_PTR(N(LetterList_Igor)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Igor) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Igor) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        EVT_EXEC_WAIT(ItemShopInteract)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_005C)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_LetterCheck_Igor))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Igor))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Igor) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Igor)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Igor) = {
    .id = NPC_Igor,
    .settings = &N(NpcSettings_Boo),
    .pos = { 43.0f, -200.0f, -9.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Igor),
    .drops = BOO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
    .tattle = MSG_NpcTattle_OBK_ShopOwner,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Igor)),
    {}
};
