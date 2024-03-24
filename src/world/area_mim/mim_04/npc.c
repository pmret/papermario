#include "mim_04.h"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

#include "world/common/npc/Bubulb.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_NpcInteract_Bubulb) = {
    IfEq(GF_MIM04_Gift_MagicalSeed3, FALSE)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Green_PopUp)
        Wait(45)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Green_Idle)
        Call(SetNpcCollisionSize, NPC_SELF, 45, 26)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH3_000F)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED3)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH3_0010)
        Set(GF_MIM04_Gift_MagicalSeed3, TRUE)
        Call(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MIM_Bubulb_Revealed)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
                Set(LVar0, MSG_CH3_0011)
                Set(LVar1, MSG_CH3_0012)
            CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
                Set(LVar0, MSG_CH3_0013)
                Set(LVar1, MSG_CH3_0014)
            CaseDefault
                Set(LVar0, MSG_CH3_0015)
                Set(LVar1, MSG_CH3_0016)
        EndSwitch
        IfEq(AF_MIM04_Bubulb_DialogueToggle, FALSE)
            Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, LVar0)
            Set(AF_MIM04_Bubulb_DialogueToggle, TRUE)
        Else
            Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, LVar1)
            Set(AF_MIM04_Bubulb_DialogueToggle, FALSE)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb)))
    IfEq(GF_MIM04_Gift_MagicalSeed3, FALSE)
        Call(SetNpcCollisionSize, NPC_SELF, 25, 25)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Green_BuriedIdle)
        Call(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MIM_Bubulb_Hidden)
    EndIf
    Return
    End
};

NpcData N(NpcData_Fuzzy) = {
    .id = NPC_Fuzzy,
    .pos = { 240.0f, 0.0f, -240.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 240, 0, -240 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 240, 0, -240 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Bubulb) = {
    .id = NPC_Bubulb,
    .pos = { 0.0f, 32.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bubulb),
    .settings = &N(NpcSettings_Bubulb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BUBULB_GREEN_ANIMS,
    .tattle = MSG_NpcTattle_MIM_Bubulb_Revealed,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy), BTL_MIM_FORMATION_04, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_Bubulb)),
    {}
};
