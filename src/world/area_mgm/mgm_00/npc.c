#include "mgm_00.h"

#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

API_CALLABLE(N(GetAvailableGamesCount)) {
    s32 numGames = 0;

    if (find_item(ITEM_GOLD_CREDIT) >= 0) {
        numGames = 2;
    } else if (find_item(ITEM_SILVER_CREDIT) >= 0) {
        numGames = 1;
    }

    evt_set_variable(script, LVar5, numGames);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_RaisePipe_JumpAttack) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -25, 0, -155)
    Call(SetPanTarget, CAM_DEFAULT, -25, 0, -155)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.2))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5)
    Call(PlaySoundWithVolume, SOUND_GROW, 0)
    Call(EnableModel, MODEL_o5, TRUE)
    Set(LVar0, -30)
    Loop(30)
        Add(LVar0, 1)
        Call(TranslateModel, MODEL_o5, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(TranslateModel, MODEL_o5, 0, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o5, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deili2, COLLIDER_FLAGS_UPPER_MASK)
    BindTrigger(Ref(N(EVS_OnEnterPipe_JumpAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili2, 1, 0)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_RaisePipe_SmashAttack) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 95, 0, -155)
    Call(SetPanTarget, CAM_DEFAULT, 95, 0, -155)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.2))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5)
    Call(PlaySoundWithVolume, SOUND_GROW, 0)
    Call(EnableModel, MODEL_o9, TRUE)
    Set(LVar0, -30)
    Loop(30)
        Add(LVar0, 1)
        Call(TranslateModel, MODEL_o9, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(TranslateModel, MODEL_o9, 0, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o9, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deili3, COLLIDER_FLAGS_UPPER_MASK)
    BindTrigger(Ref(N(EVS_OnEnterPipe_SmashAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili3, 1, 0)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_SetCamera_RaisePipe) = {
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.2))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_RedToad) = {
    Call(N(GetAvailableGamesCount))
    Set(LVar6, 0)
    Set(LVar7, 0)
    IfEq(GF_MGM_Unlocked_JumpAttack, FALSE)
        Switch(LVar5)
            CaseEq(0)
            CaseEq(1)
                Set(LVar6, 1)
                Set(LVar7, 1)
            CaseEq(2)
                Set(LVar6, 1)
                Set(LVar7, 3)
        EndSwitch
    Else
        IfEq(GF_MGM_Unlocked_SmashAttack, FALSE)
            IfLe(LVar5, 1)
                Set(LVar6, 2)
            Else
                Set(LVar6, 3)
                Set(LVar7, 2)
            EndIf
        Else
            Set(LVar6, 4)
        EndIf
    EndIf
    IfEq(GF_MGM00_Met_Receptionist, FALSE)
        Set(GF_MGM00_Met_Receptionist, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0012)
    Else
        Switch(LVar6)
            CaseEq(0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0013)
                Return
            CaseEq(1)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0014)
            CaseEq(2)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0015)
                Return
            CaseEq(3)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0016)
            CaseEq(4)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0017)
                Return
        EndSwitch
    EndIf
    Switch(LVar7)
        CaseEq(0)
            Call(EndSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 5)
        CaseEq(1)
            Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0018)
        CaseEq(2)
            Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0019)
        CaseEq(3)
            Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_001A)
    EndSwitch
    Switch(LVar7)
        CaseEq(0)
        CaseEq(1)
            Set(GF_MGM_Unlocked_JumpAttack, TRUE)
            ExecWait(N(EVS_RaisePipe_JumpAttack))
            ExecWait(N(EVS_SetCamera_RaisePipe))
        CaseEq(2)
            Set(GF_MGM_Unlocked_SmashAttack, TRUE)
            ExecWait(N(EVS_RaisePipe_SmashAttack))
            ExecWait(N(EVS_SetCamera_RaisePipe))
        CaseEq(3)
            Set(GF_MGM_Unlocked_JumpAttack, TRUE)
            Set(GF_MGM_Unlocked_SmashAttack, TRUE)
            ExecWait(N(EVS_RaisePipe_JumpAttack))
            Wait(10)
            ExecWait(N(EVS_RaisePipe_SmashAttack))
            ExecWait(N(EVS_SetCamera_RaisePipe))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_RedToad) = {
    Call(SetNpcCollisionSize, NPC_SELF, 32, 75)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RedToad)))
    Return
    End
};

NpcData N(NpcData_RedToad) = {
    .id = NPC_RedToad,
    .pos = { -213.0f, 12.0f, -180.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_RedToad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_MGM_PlayroomReceptionist,
};

EvtScript N(EVS_NpcInteract_GreenToad) = {
    Call(N(GetAvailableGamesCount))
    Switch(LVar5)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0025)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0026)
        CaseDefault
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0027)
                Call(SetSelfVar, 0, 1)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0028)
                Call(SetSelfVar, 0, 0)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_GreenToad) = {
    Call(SetSelfVar, 0, 0)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GreenToad)))
    Return
    End
};

NpcData N(NpcData_GreenToad) = {
    .id = NPC_GreenToad,
    .pos = { -88.0f, 0.0f, -95.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points = {
                { -100, 0, -95 },
                { -70, 0, -95 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_GreenToad),
    .settings = &N(NpcSettings_Toad_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_GREEN_ANIMS,
    .tattle = MSG_NpcTattle_MGM_PlayroomCustomer,
};

EvtScript N(EVS_NpcInteract_BlueToad) = {
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseLt(25)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_0029)
        CaseLt(50)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_002A)
        CaseLt(75)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_002B)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_002C)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_BlueToad) = {
    Call(RandInt, 100, LVar0)
    Call(SetSelfVar, 0, LVar0)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_BlueToad)))
    Return
    End
};

NpcData N(NpcData_BlueToad) = {
    .id = NPC_BlueToad,
    .pos = { 46.0f, 0.0f, -205.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points = {
                { 25, 0, -205 },
                { 75, 0, -205 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BlueToad),
    .settings = &N(NpcSettings_Toad_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_BLUE_ANIMS,
    .tattle = MSG_NpcTattle_MGM_BestPlayroomCustomer,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RedToad)),
    NPC_GROUP(N(NpcData_GreenToad)),
    NPC_GROUP(N(NpcData_BlueToad)),
    {}
};
