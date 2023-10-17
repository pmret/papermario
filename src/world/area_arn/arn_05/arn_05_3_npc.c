#include "arn_05.h"

#include "sprite/npc/WorldBow.h"

#include "world/common/enemy/TubbaBlubba.inc.c"
#include "world/common/npc/Boo_Patrol.inc.c"
#include "world/common/npc/Boo.inc.c"

EvtScript N(EVS_NpcIdle_Boo_01) = {
    EVT_RETURN
    EVT_END
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
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_06, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0092)
                EVT_SET(AF_ARN_06, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0093)
                EVT_SET(AF_ARN_06, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0095)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0096)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0097)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0098)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_01_Mourning) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0094)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_07, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0099)
                EVT_SET(AF_ARN_07, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009A)
                EVT_SET(AF_ARN_07, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009C)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009E)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009F)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_02_Mourning) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_009B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00A9)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_ARN05_GaveGiftAdvice, TRUE)
                EVT_IF_EQ(AF_ARN_09, TRUE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Wave, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AE)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Conceal)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Conceal, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AA)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Cower)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Cower, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AB)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Confused)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Confused, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AC)
                EVT_CALL(ShowChoice, MSG_Choice_001E)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Wave)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Wave, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AD)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Idle)
                        EVT_SET(GF_ARN05_GaveGiftAdvice, TRUE)
                        EVT_SET(AF_ARN_09, TRUE)
                    EVT_CASE_EQ(1)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Wave)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Wave, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AD)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Idle)
                        EVT_SET(GF_ARN05_GaveGiftAdvice, TRUE)
                        EVT_SET(AF_ARN_09, TRUE)
                    EVT_CASE_EQ(2)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00AF)
                EVT_END_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B1)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_08, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B3)
                EVT_SET(AF_ARN_08, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B4)
                EVT_SET(AF_ARN_08, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B6)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B7)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B8)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B9)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_05_Mourning) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00B5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_01)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_03)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_SAW_TUBBA_EAT_BOO)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_04)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_SAW_TUBBA_EAT_BOO)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_01)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_05)))
    EVT_RETURN
    EVT_END
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
    EVT_LOOP(LVar0)
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.5))
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_TubbaRaid) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_Boo_03, 1)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Boo_03, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_Boo_03, LVar0, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_SUB(LVar0, LVar3)
    EVT_SUB(LVar0, 50)
    EVT_SUB(LVar1, LVar4)
    EVT_SUB(LVar2, LVar5)
    EVT_CALL(GetNpcPos, NPC_Boo_03, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, LVar0)
    EVT_SUB(LVar4, LVar1)
    EVT_SUB(LVar5, LVar2)
    EVT_CALL(NpcMoveTo, NPC_Boo_03, LVar3, LVar5, 30)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00A0)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT, 450, 200, 160)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(0.8))
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_05, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Boo_01, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_02, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_03, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_05, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Boo_03, 90, 1)
    EVT_CALL(InterpNpcYaw, NPC_Boo_05, 90, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySound, SOUND_BOO_APPEAR_A)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(20 * DT)
        EVT_SUBF(LVar0, EVT_FLOAT(240.0 / (s32) (20 * DT)))
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Boo_01, 420, 300, 220)
    EVT_CALL(SetNpcPos, NPC_Boo_02, 460, 250, 210)
    EVT_CALL(SetNpcPos, NPC_Boo_05, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, NPC_Boo_01, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_02, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_05, FALSE)
    EVT_CALL(PlaySound, SOUND_BOO_VANISH_A)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(20 * DT)
        EVT_ADDF(LVar0, EVT_FLOAT(240.0 / (s32) (20 * DT)))
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 0, MSG_CH3_00A1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_BOW)
        EVT_CALL(N(SwitchToPartner), PARTNER_BOW)
        EVT_THREAD
            EVT_SET(MV_Unk_00, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_00A2, 160, 40)
            EVT_SET(MV_Unk_00, 1)
        EVT_END_THREAD
        EVT_WAIT(50 * DT)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
        EVT_CALL(EnablePartnerAI)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_EQ(MV_Unk_00, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00A3)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(5 * DT)
    EVT_CALL(N(AwaitCDownPress))
    EVT_CALL(CloseMessage)
    EVT_CALL(ForceUsePartner)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 1, 8)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -40, 206)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 530, 206)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 426, 190, 194)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_Tubba, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_Tubba, EVT_FLOAT(2.5 / DT))
    EVT_CALL(SetNpcPos, NPC_Tubba, 675, 200, 180)
    EVT_CALL(NpcFaceNpc, NPC_Boo_01, NPC_Tubba, 1)
    EVT_CALL(NpcFaceNpc, NPC_Boo_02, NPC_Tubba, 1)
    EVT_CALL(SetNpcPos, NPC_Boo_03, 272, 190, 214)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Boo_01, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_02, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_BOO_APPEAR_A)
        EVT_WAIT(20 * DT)
        EVT_SETF(LVar0, EVT_FLOAT(240.0))
        EVT_LOOP(20 * DT)
            EVT_SUBF(LVar0, EVT_FLOAT(240.0 / (s32) (20 * DT)))
            EVT_CALL(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_CALL(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Boo_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Boo_02, NPC_DISPOSE_LOCATION)
        EVT_WAIT(10 * DT)
    EVT_END_THREAD
    EVT_SET(LVar0, 4)
    EVT_EXEC(N(EVS_TubbaWalking))
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
    EVT_CALL(NpcMoveTo, NPC_Tubba, 550, 196, 0)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 375)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -40, 206)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 530, 206)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 426, 190, 194)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_SET(MV_Unk_01, 0)
    EVT_THREAD
        EVT_SET(LVar0, 7)
        EVT_EXEC(N(EVS_TubbaWalking))
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
        EVT_CALL(NpcMoveTo, NPC_Tubba, 370, 220, 0)
        EVT_CALL(GetNpcPos, NPC_Boo_03, LVar0, LVar1, LVar2)
        EVT_CALL(NpcMoveTo, NPC_Tubba, 330, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
        EVT_SET(MV_Unk_01, 1)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 375)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -40, 206)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 530, 206)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 240, 169, 206)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 0, MSG_CH3_00A4)
    EVT_WAIT(15 * DT)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_Unk_01, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFaceNpc, NPC_Boo_03, NPC_Tubba, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Boo_03, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00A5)
    EVT_CALL(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Cower)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1E)
    EVT_CALL(SetNpcJumpscale, NPC_Boo_03, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump1, NPC_Boo_03, 265, 206, 212, 3 * DT)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim1E, ANIM_WorldTubba_Anim1E, 5, MSG_CH3_00A6)
    EVT_CALL(SetNpcPos, NPC_Boo_03, 303, 237, 228)
    EVT_CALL(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Flail)
    EVT_CALL(EnableNpcShadow, NPC_Boo_03, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1F)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-17.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -40, 206)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 530, 206)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 280, 169, 206)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(50 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_TUBBA_GULP, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcPos, NPC_Boo_03, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim20)
    EVT_WAIT(80 * DT)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 375)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -40, 206)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 530, 206)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 240, 169, 206)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim21, ANIM_WorldTubba_Anim06, 5, MSG_CH3_00A7)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim21)
    EVT_CALL(GetNpcPos, NPC_Tubba, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -50)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    EVT_CALL(InterpNpcYaw, NPC_Tubba, 90, 1)
    EVT_WAIT(30 * DT)
    EVT_SET(LVar0, 7)
    EVT_EXEC(N(EVS_TubbaWalking))
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
    EVT_CALL(NpcMoveTo, NPC_Tubba, 370, 220, 0)
    EVT_CALL(NpcMoveTo, NPC_Tubba, 550, 196, 0)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    EVT_CALL(SetNpcPos, NPC_Tubba, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_Tubba, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Boo_01, 3)
    EVT_CALL(SetNpcPos, NPC_Boo_01, 55, 195, 160)
    EVT_CALL(SetNpcPos, NPC_Boo_02, 160, 191, 250)
    EVT_CALL(SetNpcPos, NPC_Boo_05, 350, 185, 197)
    EVT_CALL(EnableNpcShadow, NPC_Boo_01, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_02, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_05, TRUE)
    EVT_CALL(PlaySound, SOUND_BOO_VANISH_A)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(20 * DT)
        EVT_ADDF(LVar0, EVT_FLOAT(250.0 / (s32) (20 * DT)))
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcImgFXParams, NPC_Boo_01, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Boo_02, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Boo_05, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00A8)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupTubbaRaid) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        EVT_CALL(SetNpcPos, NPC_Boo_03, 330, 184, 240)
        EVT_LOOP(0)
            EVT_SET(LVarA, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_GE(LVar2, 110)
                EVT_IF_GE(LVar0, 220)
                    EVT_SET(LVarA, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LVarA, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(InterruptUsePartner)
        EVT_EXEC_WAIT(N(EVS_Scene_TubbaRaid))
        EVT_CALL(BindNpcInteract, NPC_Boo_01, EVT_PTR(N(EVS_NpcInteract_Boo_01_Mourning)))
        EVT_CALL(BindNpcInteract, NPC_Boo_02, EVT_PTR(N(EVS_NpcInteract_Boo_02_Mourning)))
        EVT_CALL(BindNpcInteract, NPC_Boo_05, EVT_PTR(N(EVS_NpcInteract_Boo_05_Mourning)))
        EVT_SET(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_SAW_TUBBA_EAT_BOO)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -60)
    EVT_SET(LVar4, LVar0)
    EVT_ADD(LVar4, 60)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(0.1))
        EVT_ADDF(LVar6, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, LVar6)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
        EVT_CALL(RandInt, 5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(0.1))
        EVT_ADDF(LVar6, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, LVar6)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar4, LVar2, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_07) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_08) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_09) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
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
