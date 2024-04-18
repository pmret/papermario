#include "arn_05.h"

#include "sprite/npc/WorldBow.h"

#include "world/common/enemy/TubbaBlubba.inc.c"
#include "world/common/npc/Boo_Patrol.inc.c"
#include "world/common/npc/Boo.inc.c"

EvtScript N(EVS_NpcIdle_Boo_01) = {
    Return
    End
};

API_CALLABLE(N(AwaitCDownPress)) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_C_DOWN) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_NpcInteract_Boo_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_06, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0092)
                Set(AF_ARN_06, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0093)
                Set(AF_ARN_06, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0095)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0096)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0097)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0098)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_01_Mourning) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0094)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_07, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0099)
                Set(AF_ARN_07, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009A)
                Set(AF_ARN_07, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009C)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009E)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009F)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_02_Mourning) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009B)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00A9)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            IfEq(GF_ARN05_GaveGiftAdvice, TRUE)
                IfEq(AF_ARN_09, TRUE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Wave, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AE)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B0)
                EndIf
            Else
                Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Conceal)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Conceal, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AA)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Cower)
                Call(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Cower, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AB)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Confused)
                Call(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Confused, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AC)
                Call(ShowChoice, MSG_Choice_001E)
                Switch(LVar0)
                    CaseEq(0)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Wave)
                        Call(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Wave, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AD)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Idle)
                        Set(GF_ARN05_GaveGiftAdvice, TRUE)
                        Set(AF_ARN_09, TRUE)
                    CaseEq(1)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Wave)
                        Call(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Wave, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AD)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Idle)
                        Set(GF_ARN05_GaveGiftAdvice, TRUE)
                        Set(AF_ARN_09, TRUE)
                    CaseEq(2)
                        Call(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AF)
                EndSwitch
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B1)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_08, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B3)
                Set(AF_ARN_08, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B4)
                Set(AF_ARN_08, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B6)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B7)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B8)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B9)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_05_Mourning) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B5)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    IfLt(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_01)))
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_03)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_SAW_TUBBA_EAT_BOO)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_04)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_SAW_TUBBA_EAT_BOO)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    IfLt(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_01)))
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_05)))
    Return
    End
};

NpcData N(NpcData_Boo_01)[] = {
    {
        .id = NPC_Boo_01,
        .pos = { 55.0f, 195.0f, 160.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 55, 10, 160 },
                    { 75, 10, 160 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 55, 195, 160 },
                .detectSize = { 50 },
            }
        },
        .init = &N(EVS_NpcInit_Boo_01),
        .settings = &N(NpcSettings_Boo_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .tattle = MSG_NpcTattle_ARN_BooD,
    },
    {
        .id = NPC_Boo_02,
        .pos = { 160.0f, 191.0f, 250.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo_02),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .tattle = MSG_NpcTattle_ARN_BooE,
    },
    {
        .id = NPC_Boo_03,
        .pos = { 390.0f, 190.0f, 255.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo_03),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .tattle = MSG_NpcTattle_ARN_BooF,
    },
    {
        .id = NPC_Boo_04,
        .pos = { 503.0f, 206.0f, 210.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo_04),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .tattle = MSG_NpcTattle_ARN_BooG,
    },
    {
        .id = NPC_Boo_05,
        .pos = { 350.0f, 185.0f, 197.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 350, 10, 197 },
                    { 330, 10, 197 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 350, 185, 197 },
                .detectSize = { 50 },
            }
        },
        .init = &N(EVS_NpcInit_Boo_05),
        .settings = &N(NpcSettings_Boo_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .tattle = MSG_NpcTattle_ARN_BooH,
    },
};

EvtScript N(EVS_TubbaWalking) = {
    Loop(LVar0)
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_TubbaRaid) = {
    Call(DisablePlayerInput, TRUE)
    Call(NpcFacePlayer, NPC_Boo_03, 1)
    Call(PlaySoundAtNpc, NPC_Boo_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Boo_03, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(GetNpcPos, NPC_Boo_03, LVar0, LVar1, LVar2)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Sub(LVar0, LVar3)
    Sub(LVar0, 50)
    Sub(LVar1, LVar4)
    Sub(LVar2, LVar5)
    Call(GetNpcPos, NPC_Boo_03, LVar3, LVar4, LVar5)
    Sub(LVar3, LVar0)
    Sub(LVar4, LVar1)
    Sub(LVar5, LVar2)
    Call(NpcMoveTo, NPC_Boo_03, LVar3, LVar5, 30)
    Call(SetCamType, CAM_DEFAULT, 6, TRUE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00A0)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT, 450, 200, 160)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(0.8))
    Call(PlaySoundAtNpc, NPC_Boo_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_05, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Boo_01, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_02, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_03, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_05, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(FadeOutMusic, 0, 500)
    Call(ClearAmbientSounds, 250)
    Wait(20 * DT)
    Call(InterpNpcYaw, NPC_Boo_03, 90, 1)
    Call(InterpNpcYaw, NPC_Boo_05, 90, 1)
    Wait(20 * DT)
    Call(PlaySound, SOUND_BOO_APPEAR_A)
    SetF(LVar0, Float(240.0))
    Loop(20 * DT)
        SubF(LVar0, Float(240.0 / (s32) (20 * DT)))
        Call(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_Boo_01, 420, 300, 220)
    Call(SetNpcPos, NPC_Boo_02, 460, 250, 210)
    Call(SetNpcPos, NPC_Boo_05, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_Boo_01, FALSE)
    Call(EnableNpcShadow, NPC_Boo_02, FALSE)
    Call(EnableNpcShadow, NPC_Boo_05, FALSE)
    Call(PlaySound, SOUND_BOO_VANISH_A)
    SetF(LVar0, Float(0.0))
    Loop(20 * DT)
        AddF(LVar0, Float(240.0 / (s32) (20 * DT)))
        Call(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 0, MSG_CH3_00A1)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_BOW)
        Call(N(SwitchToPartner), PARTNER_BOW)
        Thread
            Set(MV_Unk_00, 0)
            Call(ShowMessageAtScreenPos, MSG_CH3_00A2, 160, 40)
            Set(MV_Unk_00, 1)
        EndThread
        Wait(50 * DT)
        Call(DisablePartnerAI, 0)
        Call(SetNpcYaw, NPC_PARTNER, 90)
        Call(EnablePartnerAI)
        Loop(0)
            Wait(1)
            IfEq(MV_Unk_00, 1)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00A3)
    Call(EnablePartnerAI)
    Call(InterpPlayerYaw, 90, 0)
    Wait(5 * DT)
    Call(N(AwaitCDownPress))
    Call(CloseMessage)
    Call(ForceUsePartner)
    Wait(60 * DT)
    Call(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 1, 8)
    Call(SetCamType, CAM_DEFAULT, 6, TRUE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.5))
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPosA, CAM_DEFAULT, -40, 206)
    Call(SetCamPosB, CAM_DEFAULT, 530, 206)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 426, 190, 194)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcFlagBits, NPC_Tubba, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcSpeed, NPC_Tubba, Float(2.5 / DT))
    Call(SetNpcPos, NPC_Tubba, 675, 200, 180)
    Call(NpcFaceNpc, NPC_Boo_01, NPC_Tubba, 1)
    Call(NpcFaceNpc, NPC_Boo_02, NPC_Tubba, 1)
    Call(SetNpcPos, NPC_Boo_03, 272, 190, 214)
    Call(PlaySoundAtNpc, NPC_Boo_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Boo_01, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_02, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Thread
        Call(PlaySound, SOUND_BOO_APPEAR_A)
        Wait(20 * DT)
        SetF(LVar0, Float(240.0))
        Loop(20 * DT)
            SubF(LVar0, Float(240.0 / (s32) (20 * DT)))
            Call(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Call(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
        EndLoop
        Call(SetNpcPos, NPC_Boo_01, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Boo_02, NPC_DISPOSE_LOCATION)
        Wait(10 * DT)
    EndThread
    Set(LVar0, 4)
    Exec(N(EVS_TubbaWalking))
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
    Call(NpcMoveTo, NPC_Tubba, 550, 196, 0)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.5))
    Call(SetCamDistance, CAM_DEFAULT, 375)
    Call(SetCamPosA, CAM_DEFAULT, -40, 206)
    Call(SetCamPosB, CAM_DEFAULT, 530, 206)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 426, 190, 194)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30 * DT)
    Set(MV_Unk_01, 0)
    Thread
        Set(LVar0, 7)
        Exec(N(EVS_TubbaWalking))
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
        Call(NpcMoveTo, NPC_Tubba, 370, 220, 0)
        Call(GetNpcPos, NPC_Boo_03, LVar0, LVar1, LVar2)
        Call(NpcMoveTo, NPC_Tubba, 330, LVar2, 0)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
        Set(MV_Unk_01, 1)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.5))
    Call(SetCamDistance, CAM_DEFAULT, 375)
    Call(SetCamPosA, CAM_DEFAULT, -40, 206)
    Call(SetCamPosB, CAM_DEFAULT, 530, 206)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 240, 169, 206)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 0, MSG_CH3_00A4)
    Wait(15 * DT)
    Loop(0)
        Wait(1)
        IfEq(MV_Unk_01, 1)
            BreakLoop
        EndIf
    EndLoop
    Call(NpcFaceNpc, NPC_Boo_03, NPC_Tubba, 1)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00A5)
    Call(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Cower)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1E)
    Call(SetNpcJumpscale, NPC_Boo_03, Float(0.0))
    Call(NpcJump1, NPC_Boo_03, 265, 206, 212, 3 * DT)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim1E, ANIM_WorldTubba_Anim1E, 5, MSG_CH3_00A6)
    Call(SetNpcPos, NPC_Boo_03, 303, 237, 228)
    Call(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Flail)
    Call(EnableNpcShadow, NPC_Boo_03, FALSE)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1F)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-17.0))
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPosA, CAM_DEFAULT, -40, 206)
    Call(SetCamPosB, CAM_DEFAULT, 530, 206)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 280, 169, 206)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Wait(50 * DT)
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_TUBBA_GULP, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(40 * DT)
    Call(SetNpcPos, NPC_Boo_03, NPC_DISPOSE_LOCATION)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim20)
    Wait(80 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.5))
    Call(SetCamDistance, CAM_DEFAULT, 375)
    Call(SetCamPosA, CAM_DEFAULT, -40, 206)
    Call(SetCamPosB, CAM_DEFAULT, 530, 206)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 240, 169, 206)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim21, ANIM_WorldTubba_Anim06, 5, MSG_CH3_00A7)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim21)
    Call(GetNpcPos, NPC_Tubba, LVar0, LVar1, LVar2)
    Add(LVar0, -50)
    Add(LVar1, 50)
    Add(LVar2, 10)
    PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 10)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    Call(InterpNpcYaw, NPC_Tubba, 90, 1)
    Wait(30 * DT)
    Set(LVar0, 7)
    Exec(N(EVS_TubbaWalking))
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
    Call(NpcMoveTo, NPC_Tubba, 370, 220, 0)
    Call(NpcMoveTo, NPC_Tubba, 550, 196, 0)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    Call(SetNpcPos, NPC_Tubba, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_Tubba, NPC_FLAG_GRAVITY, FALSE)
    Call(NpcFacePlayer, NPC_Boo_01, 3)
    Call(SetNpcPos, NPC_Boo_01, 55, 195, 160)
    Call(SetNpcPos, NPC_Boo_02, 160, 191, 250)
    Call(SetNpcPos, NPC_Boo_05, 350, 185, 197)
    Call(EnableNpcShadow, NPC_Boo_01, TRUE)
    Call(EnableNpcShadow, NPC_Boo_02, TRUE)
    Call(EnableNpcShadow, NPC_Boo_05, TRUE)
    Call(PlaySound, SOUND_BOO_VANISH_A)
    SetF(LVar0, Float(0.0))
    Loop(20 * DT)
        AddF(LVar0, Float(250.0 / (s32) (20 * DT)))
        Call(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcImgFXParams, NPC_Boo_01, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Boo_02, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Boo_05, IMGFX_CLEAR, 0, 0, 0, 0)
    Wait(10 * DT)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00A8)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupTubbaRaid) = {
    IfLt(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        Call(SetNpcPos, NPC_Boo_03, 330, 184, 240)
        Loop(0)
            Set(LVarA, 0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfGe(LVar2, 110)
                IfGe(LVar0, 220)
                    Set(LVarA, 1)
                EndIf
            EndIf
            IfEq(LVarA, 1)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(InterruptUsePartner)
        ExecWait(N(EVS_Scene_TubbaRaid))
        Call(BindNpcInteract, NPC_Boo_01, Ref(N(EVS_NpcInteract_Boo_01_Mourning)))
        Call(BindNpcInteract, NPC_Boo_02, Ref(N(EVS_NpcInteract_Boo_02_Mourning)))
        Call(BindNpcInteract, NPC_Boo_05, Ref(N(EVS_NpcInteract_Boo_05_Mourning)))
        Set(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        Exec(N(EVS_SetupMusic))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba) = {
    IfGe(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

AnimID N(ExtraAnims_Tubba)[] = {
    ANIM_WorldTubba_Anim06,
    ANIM_WorldTubba_Anim09,
    ANIM_WorldTubba_Anim1E,
    ANIM_WorldTubba_Anim1F,
    ANIM_WorldTubba_Anim20,
    ANIM_WorldTubba_Anim21,
    ANIM_LIST_END
};

NpcData N(NpcData_Tubba) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Tubba),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TUBBA_ANIMS,
    .extraAnimations = N(ExtraAnims_Tubba),
};

EvtScript N(EVS_NpcIdle_Boo_06) = {
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -60)
    Set(LVar4, LVar0)
    Add(LVar4, 60)
    Loop(0)
        Call(RandInt, 5, LVar5)
        SetF(LVar6, LVar5)
        MulF(LVar6, Float(0.1))
        AddF(LVar6, Float(0.8))
        Call(SetNpcSpeed, NPC_SELF, LVar6)
        Call(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
        Call(RandInt, 5, LVar5)
        SetF(LVar6, LVar5)
        MulF(LVar6, Float(0.1))
        AddF(LVar6, Float(0.8))
        Call(SetNpcSpeed, NPC_SELF, LVar6)
        Call(NpcMoveTo, NPC_SELF, LVar4, LVar2, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_07) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_08) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_09) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

NpcData N(NpcData_Boo_06)[] = {
    {
        .id = NPC_Boo_06,
        .pos = { 36.0f, 277.0f, 140.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_06),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_07,
        .pos = { 200.0f, 275.0f, 182.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_07),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_08,
        .pos = { 379.0f, 300.0f, 192.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_08),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_09,
        .pos = { 525.0f, 286.0f, 178.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_09),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_Tubba)),
    NPC_GROUP(N(NpcData_Boo_01)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_Tubba)),
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_06)),
    {}
};
