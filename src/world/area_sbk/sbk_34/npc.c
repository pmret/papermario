#include "sbk_34.h"

NpcSettings N(NpcSettings_Nomadimouse) = {
    .height = 22,
    .radius = 25,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Nomadimouse)[] = {
    ITEM_LETTER_TO_NOMADIMOUSE,
    ITEM_NONE
};

EvtScript N(EVS_Nomadimouse_LetterDelivery) = {
    Call(N(LetterDelivery_Init),
        NPC_Nomadimouse, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle,
        ITEM_LETTER_TO_NOMADIMOUSE, ITEM_NONE,
        MSG_CH2_005B, MSG_CH2_005C, MSG_CH2_005D, MSG_CH2_005E,
        Ref(N(LetterList_Nomadimouse)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Nomadimouse) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Nomadimouse) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
            IfEq(GF_SBK34_Met_Nomadimouse, FALSE)
                Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(250.0), Float(15.0), Float(-6.0))
                Call(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0056)
                Set(GF_SBK34_Met_Nomadimouse, TRUE)
                Call(ResetCam, CAM_DEFAULT, 4)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0057)
            EndIf
        CaseLt(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            IfEq(GF_SBK34_Met_Nomadimouse, FALSE)
                Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(250.0), Float(15.0), Float(-6.0))
                Call(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0058)
                Set(GF_SBK34_Met_Nomadimouse, TRUE)
                Call(ResetCam, CAM_DEFAULT, 4)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0059)
            EndIf
        CaseGe(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_005A)
    EndSwitch
    ExecWait(N(EVS_Nomadimouse_LetterDelivery))
    ExecWait(N(EVS_LetterReward_Nomadimouse))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Nomadimouse) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Nomadimouse)))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Nomadimouse_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Sack) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Nomadimouse_Sack)
    Return
    End
};

NpcData N(NpcData_Nomadimouse)[] = {
    {
        .id = NPC_Nomadimouse,
        .pos = { 114.0f, 0.0f, -50.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Nomadimouse),
        .settings = &N(NpcSettings_Nomadimouse),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Nomadimouse_Idle,
            .walk   = ANIM_Nomadimouse_Idle,
            .run    = ANIM_Nomadimouse_Idle,
            .chase  = ANIM_Nomadimouse_Idle,
            .anim_4 = ANIM_Nomadimouse_Idle,
            .anim_5 = ANIM_Nomadimouse_Idle,
            .death  = ANIM_Nomadimouse_Idle,
            .hit    = ANIM_Nomadimouse_Idle,
            .anim_8 = ANIM_Nomadimouse_Idle,
            .anim_9 = ANIM_Nomadimouse_Idle,
            .anim_A = ANIM_Nomadimouse_Idle,
            .anim_B = ANIM_Nomadimouse_Idle,
            .anim_C = ANIM_Nomadimouse_Idle,
            .anim_D = ANIM_Nomadimouse_Idle,
            .anim_E = ANIM_Nomadimouse_Idle,
            .anim_F = ANIM_Nomadimouse_Idle,
        },
        .tattle = MSG_NpcTattle_SBK_Nomadimouse,
    },
    {
        .id = NPC_Sack,
        .pos = { 134.0f, 0.0f, -50.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Sack),
        .settings = &N(NpcSettings_Nomadimouse),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Nomadimouse_Idle,
            .walk   = ANIM_Nomadimouse_Idle,
            .run    = ANIM_Nomadimouse_Idle,
            .chase  = ANIM_Nomadimouse_Idle,
            .anim_4 = ANIM_Nomadimouse_Idle,
            .anim_5 = ANIM_Nomadimouse_Idle,
            .death  = ANIM_Nomadimouse_Idle,
            .hit    = ANIM_Nomadimouse_Idle,
            .anim_8 = ANIM_Nomadimouse_Idle,
            .anim_9 = ANIM_Nomadimouse_Idle,
            .anim_A = ANIM_Nomadimouse_Idle,
            .anim_B = ANIM_Nomadimouse_Idle,
            .anim_C = ANIM_Nomadimouse_Idle,
            .anim_D = ANIM_Nomadimouse_Idle,
            .anim_E = ANIM_Nomadimouse_Idle,
            .anim_F = ANIM_Nomadimouse_Idle,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Nomadimouse)),
    {}
};
