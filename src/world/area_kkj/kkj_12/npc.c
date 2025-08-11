#include "kkj_12.h"
#include "sprite/player.h"

#include "../common/Searchlights.inc.c"

#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/PreventNextPeachDisguise.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

API_CALLABLE(N(DisableLightSource1)) {
    gSpriteShadingProfile->sources[1].flags = LIGHT_SOURCE_DISABLED;
    return ApiStatus_DONE2;
}

#include "world/common/enemy/Clubba.h"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"
#include "world/common/npc/Dummy.inc.c"

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim02,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim05,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim07,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim09,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_WorldKoopatrol_Anim1B,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Clubba)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim05,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim13,
    ANIM_WorldClubba_Anim14,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    Call(DisablePlayerInput, true)
    Call(N(GetPeachDisguise), LVar0)
    IfEq(LVar0, PEACH_DISGUISE_CLUBBA)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0143)
    Else
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0141)
            Call(SetSelfVar, 0, 1)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0142)
            Call(SetSelfVar, 0, 0)
        EndIf
    EndIf
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopatrol_02) = {
    Call(DisablePlayerInput, true)
    Call(N(GetPeachDisguise), LVar0)
    IfEq(LVar0, PEACH_DISGUISE_CLUBBA)
        Call(AdjustCam, CAM_DEFAULT, Float(5.0 / DT), 0, Float(350.0), Float(15.0), Float(-7.0))
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0147)
        Thread
            Loop(0)
                Call(PlayerFaceNpc, NPC_Koopatrol_02, false)
                Wait(1)
                IfEq(GF_KKJ12_TrickedGuard, true)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
        Call(SetNpcSpeed, NPC_SELF, Float(2.0 / DT))
        Call(NpcMoveTo, NPC_SELF, 1050, 0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0148)
        Call(NpcMoveTo, NPC_SELF, 900, 0, 0)
        Call(SetNpcPos, NPC_SELF, 0, -500, 0)
        Set(GF_KKJ12_TrickedGuard, true)
        BindTrigger(Ref(N(EVS_ExitDoors_kkj_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
        Call(DisablePlayerInput, false)
        Return
    EndIf
    IfEq(GF_KKJ11_TrickedGuard, false)
        Call(AdjustCam, CAM_DEFAULT, Float(5.0 / DT), 0, Float(350.0), Float(15.0), Float(-7.0))
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0144)
        Wait(10 * DT)
        Set(LVar0, ITEM_PEACH_KEY)
        Call(ShowGotItem, LVar0, true, 0)
        Call(AddKeyItem, LVar0)
        Set(GF_KKJ11_TrickedGuard, true)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0145)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 16, MSG_Peach_0146)
    EndIf
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_CapturePeach) = {
    Call(DisablePlayerInput, true)
    Call(N(PreventNextPeachDisguise))
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(NpcFacePlayer, NPC_SELF, 5)
    Wait(20)
    Call(PlayerFaceNpc, NPC_SELF, false)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0174)
    Call(N(ApproachPlayer100Units), NPC_SELF, LVar3, LVar0, LVar2)
    IfNe(LVar3, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim07)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0175)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    Wait(20)
    Call(GotoMapSpecial, Ref("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    Wait(100)
    Call(DisablePlayerInput, false)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    Thread
        Set(LVar2, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, MODEL_o694, 0)
            IfEq(LVar2, 0)
                Call(N(GetPeachDisguise), LVar1)
                IfEq(LVar1, PEACH_DISGUISE_NONE)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, true)
                    IfNe(LVar0, 0)
                        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                        Set(LVar2, 1)
                    EndIf
                Else
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, false)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, 900, 0, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 900, 0, 800, 0)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 800, 0, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 800, 0, 900, 0)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    Thread
        Set(LVar2, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, MODEL_o695, 1)
            IfEq(LVar2, 0)
                Call(N(GetPeachDisguise), LVar1)
                IfEq(LVar1, PEACH_DISGUISE_NONE)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, true)
                    IfNe(LVar0, 0)
                        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                        Set(LVar2, 1)
                    EndIf
                Else
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, false)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    Call(SetNpcPos, NPC_SELF, 800, 110, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    IfNe(GF_KKJ12_TrickedGuard, false)
        Call(EnableModel, MODEL_o695, false)
        Call(N(DisableLightSource1))
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    Call(SetNpcPos, NPC_SELF, 1170, 110, 0)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_02)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_02)))
    Return
    End
};

NpcData N(NpcData_Koopatrol_01)[] = {
    {
        .id = NPC_Koopatrol_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_01),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_02),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Clubba,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol_01)),
    {}
};
