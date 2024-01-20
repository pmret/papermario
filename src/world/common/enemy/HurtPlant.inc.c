#include "HurtPlant.h"
#include "sprite/player.h"

EvtScript N(EVS_NpcAI_HurtPlant) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_HurtPlant_Anim01)
    Call(SetSelfVar, 0, 0)
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Wait(1)
        Goto(0)
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, TRUE)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_HurtPlant_Anim08)
    Wait(15)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_HURT_PLANT_SHRIEK, SOUND_SPACE_DEFAULT)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Wait(5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_HurtPlant_Anim02)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(StartBattle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_HurtPlant) = {
    Call(SetSelfVar, 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_HurtPlant) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_HurtPlant)))
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_HurtPlant) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_HURT_PLANT,
    .onInteract = &N(EVS_NpcInteract_HurtPlant),
    .ai = &N(EVS_NpcAI_HurtPlant),
    .onDefeat = &N(EVS_NpcDefeat_HurtPlant),
};

AnimID N(ExtraAnims_HurtPlant)[] = {
    ANIM_HurtPlant_Anim00,
    ANIM_HurtPlant_Anim01,
    ANIM_HurtPlant_Anim02,
    ANIM_HurtPlant_Anim08,
    ANIM_LIST_END
};

#define HURT_PLANT_NPC_DATA \
    .settings = &N(NpcSettings_HurtPlant), \
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_400000, \
    .drops = HURT_PLANT_DROPS, \
    .animations = HURT_PLANT_ANIMS, \
    .extraAnimations = N(ExtraAnims_HurtPlant), \
    .tattle = MSG_NpcTattle_HeartPlant, \
