#include "machi.h"

EvtScript N(EVS_GoombaKing_Init) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_GoombaKing) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_GoombaKing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_GoombaKing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_GoombaKing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GoombaKing) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_GoombaKing) = {
    .defaultAnim = ANIM_GoombaKing_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_GoombaKing),
    .onInteract = &N(EVS_NpcInteract_GoombaKing),
    .ai = &N(EVS_NpcAI_GoombaKing),
    .onHit = &N(EVS_NpcHit_GoombaKing),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};
