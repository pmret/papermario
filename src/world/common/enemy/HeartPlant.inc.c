#include "HeartPlant.h"

#include "world/common/todo/HeartPlant_SpawnHeart.inc.c"

extern EvtScript N(EVS_NpcInteract_HeartPlant);

EvtScript N(EVS_NpcAuxAI_HeartPlant) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 0)
    Return
    End
};

EvtScript N(EVS_HeartPlant_RebindInteractAfterDelay) = {
    Wait(45)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_HeartPlant)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_HeartPlant) = {
    Call(GetSelfVar, 1, LVar0)
    IfEq(LVar0, 0)
        Call(SetSelfVar, 1, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEART_PLANT, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HeartPlant_Anim00)
        Wait(1)
        Call(N(HeartPlant_SpawnHeart))
        Call(SetNpcAnimation, NPC_SELF, ANIM_HeartPlant_Anim01)
        Thread
            Call(BindNpcInteract, NPC_SELF, NULL)
            Exec(N(EVS_HeartPlant_RebindInteractAfterDelay))
            Wait(45)
            Call(SetSelfVar, 1, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_HeartPlant_Anim00)
        EndThread
    EndIf
    Return
    End
};

NpcSettings N(NpcSettings_HeartPlant) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_HeartPlant),
    .onInteract = &N(EVS_NpcInteract_HeartPlant),
};

#define HEART_PLANT_FLAGS \
    ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | \
    ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER
