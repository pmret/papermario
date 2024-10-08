#include "machi.h"

EvtScript N(EVS_GoombaKing_Init) = {
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_GoombaKing) = {
    Call(SetNpcScale, NPC_SELF, Float(0.5), Float(0.5), Float(0.5))
    Return
    End
};

EvtScript N(EVS_NpcInteract_GoombaKing) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_GoombaKing) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_GoombaKing) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GoombaKing) = {
    Return
    End
};

NpcSettings N(NpcSettings_GoombaKing) = {
    .defaultAnim = ANIM_GoombaKing_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_GoombaKing),
    .onInteract = &N(EVS_NpcInteract_GoombaKing),
    .ai = &N(EVS_NpcAI_GoombaKing),
    .onHit = &N(EVS_NpcHit_GoombaKing),
    .flags = BASE_PASSIVE_FLAGS,
};
