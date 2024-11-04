#include "omo_06.h"

#include "world/common/npc/TrainToad.inc.c"

EvtScript N(EVS_NpcInteract_Conductor) = {
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(D_80244B10_DBC420))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Conductor) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Conductor)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_TrainToad) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_GOT_FRYING_PAN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0023)
        CaseLt(STORY_CH4_GOT_TAYCE_TS_CAKE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0024)
        CaseLt(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0025)
        CaseLt(STORY_CH4_PULLED_SWITCH_SWITCH)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0026)
        CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0027)
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0028)
        CaseLt(STORY_CH4_DEFEATED_GENERAL_GUY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0029)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_002A)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TrainToad)))
    Return
    End
};

NpcData N(NpcSettings_Toads)[] = {
    {
        .id = NPC_Conductor,
        .pos = { 50.0f, 50.0f, 45.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Conductor),
        .settings = &N(NpcSettings_TrainToad),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = TRAIN_CONDUCTOR_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
    {
        .id = NPC_TrainToad,
        .pos = { 55.0f, 0.0f, 240.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad),
        .settings = &N(NpcSettings_TrainToad),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_PINK_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcSettings_Toads)),
    {}
};
