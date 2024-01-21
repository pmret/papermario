#include "tst_04.h"

API_CALLABLE(N(DisableOwnerShadow)) {
    disable_npc_shadow(get_npc_unsafe(script->owner1.enemy->npcID));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAuxAI_Goompa) = {
    Call(N(DisableOwnerShadow))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcAux_Goompa) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_Goompa) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_Goompa) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goompa) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Goompa) = {
    Return
    End
};

NpcSettings N(NpcSettings_Goompa) = {
    .defaultAnim = ANIM_Goompa_Talk,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Goompa),
    .onInteract = &N(EVS_NpcInteract_Goompa),
    .ai = &N(EVS_NpcAI_Goompa),
    .onHit = &N(EVS_NpcHit_Goompa),
    .aux = &N(EVS_NpcAux_Goompa),
    .onDefeat = &N(EVS_NpcDefeat_Goompa),
    .unk_24 = 200,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
};

NpcData N(NpcData_GoombaFamily) = {
    .id = NPC_Goompa,
    .pos = { 80.0f, 40.0f, -84.0f },
    .yaw = 0,
    .settings = &N(NpcSettings_Goompa),
    .flags = ENEMY_FLAG_GRAVITY,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GoombaFamily)),
    {}
};
