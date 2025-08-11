#include "flo_03.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Dayzee) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Petunia) = {
    .height = 56,
    .radius = 40,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/GiveReward.inc.c"

Vec3i N(BurrowLocations_Mole_01)[] = {
    { -100, 0, 210 },
    { -160, 0, 285 },
    {  -35, 0, 305 },
};

Vec3i N(BurrowLocations_Mole_02)[] = {
    { -190, 0,  80 },
    { -130, 0,   0 },
    {  -70, 0, -60 },
};

Vec3i N(BurrowLocations_Mole_03)[] = {
    {  75, 0,  -15 },
    {  35, 0, -100 },
    { 130, 0,    0 },
};

Vec3i N(BurrowLocations_Mole_04)[] = {
    { 115, 0,  180 },
    {  85, 0,  290 },
    { 145, 0,  140 },
};

EvtScript N(EVS_Scene_SunReturns) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetNpcYaw, NPC_Petunia, 90)
    Call(GetNpcPos, NPC_Petunia, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.5))
    Call(SetCamPosA, CAM_DEFAULT, -27, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(SpeakToPlayer, NPC_Petunia, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_00C8)
    Call(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Dance)
    Wait(10)
    Call(GotoMap, Ref("flo_18"), flo_18_ENTRY_1)
    Wait(100)
    Return
    End
};

API_CALLABLE(N(HideBehindTree)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posZ, yaw, angle;
    f64 dist;

    // get a point 46 units away from the tree on the side opposite the player
    yaw = clamp_angle(atan2(-210.0f, -183.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z) + 180.0f);
    posX = -210.0f;
    posZ = -183.0f;
    add_vec2D_polar(&posX, &posZ, 46.0f, yaw);

    // run or walk to target position, based on the distance from current position
    dist = dist2D(npc->pos.x, npc->pos.z, posX, posZ);
    if (dist > 2.0) {
        f32 curAngle = clamp_angle(atan2(-210.0f, -183.0f, npc->pos.x, npc->pos.z));
        f32 targetAngle = clamp_angle(atan2(-210.0f, -183.0f, posX, posZ));
        f32 deltaAngle = curAngle - targetAngle;
        if (abs(deltaAngle) > 20) {
            angle = deltaAngle;
            if (angle >= 180.0f) {
                angle -= 360.0f;
            }
            if (angle <= -180.0f) {
                angle += 360.0f;
            }
            if (deltaAngle == angle) {
                posX = -210.0f;
                posZ = -183.0f;
                if (deltaAngle >= 0.0f) {
                    yaw = clamp_angle(curAngle - 20.0f);
                } else {
                    yaw = clamp_angle(curAngle + 20.0f);
                }
                add_vec2D_polar(&posX, &posZ, 46.0f, yaw);
            } else {
                osSyncPrintf("cccc\n");
            }
        }
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_RUN];
        npc->yaw = atan2(npc->pos.x, npc->pos.z, posX, posZ);
        npc_move_heading(npc, 2.0f, npc->yaw);
    } else if (dist > 0.2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, posX, posZ);
        npc->pos.x = posX;
        npc->pos.z = posZ;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_WALK];
    } else {
        npc->pos.x = posX;
        npc->pos.z = posZ;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAI_Dayzee) = {
    Call(N(HideBehindTree))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Dayzee) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_FLO03_Defeated_Dayzee, true)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_FocusCamBetween) = {
    Call(GetPlayerPos, LVar3, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Call(SetCamProperties, CAM_DEFAULT, LVar4, LVar0, LVar1, LVar2, 300, Float(20.0), Float(-9.5))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Petunia) = {
    ExecWait(N(EVS_PushFlowerSong))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            Set(MV_PauseBurrowing, true)
            Set(LVar4, Float(3.5))
            ExecWait(N(EVS_FocusCamBetween))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0050)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Petunia_Angry)
            Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
            Wait(20)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0051)
            Call(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim12)
            Call(SetNpcYaw, NPC_MontyMole_01, 270)
            Call(GetNpcPos, NPC_MontyMole_01, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.0))
            Call(SetCamDistance, CAM_DEFAULT, 200)
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Wait(20)
            Call(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
            Call(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim16)
            Wait(10)
            Call(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
            Call(ShowEmote, NPC_MontyMole_01, EMOTE_QUESTION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
            Call(GetNpcPos, NPC_MontyMole_02, LVar0, LVar1, LVar2)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0052)
            Call(SetNpcYaw, NPC_MontyMole_02, 90)
            Call(SetNpcPos, NPC_MontyMole_02, NPC_DISPOSE_LOCATION)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 200)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim00)
            Wait(20)
            Call(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
            Call(SetNpcPos, NPC_MontyMole_02, LVar0, LVar1, LVar2)
            Call(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
            Wait(20)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0053)
            Call(SetNpcYaw, NPC_MontyMole_03, 270)
            Call(GetNpcPos, NPC_MontyMole_03, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 200)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Wait(20)
            Call(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim14)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0054)
            Call(SetNpcYaw, NPC_MontyMole_04, 270)
            Call(GetNpcPos, NPC_MontyMole_04, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 200)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim06)
            Wait(20)
            Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim07)
            Wait(20)
            Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim08)
            Wait(20)
            Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim16)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0055)
            Call(SetNpcPos, NPC_Dayzee, -233, 0, -217)
            Call(GetNpcPos, NPC_Dayzee, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 300)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(SetNpcAnimation, NPC_Dayzee, ANIM_Dayzee_Anim0D)
            Call(PlaySoundAtNpc, NPC_Dayzee, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
            Call(ShowEmote, NPC_Dayzee, EMOTE_EXCLAMATION, 45, 30, EMOTER_NPC, 0, 0, 0, 0)
            Wait(15)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0056)
            Set(LVar4, Float(90.0))
            ExecWait(N(EVS_FocusCamBetween))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0057)
            Call(SetEnemyFlagBits, NPC_Dayzee, ENEMY_FLAG_PASSIVE, false)
            Call(SetEnemyFlagBits, NPC_MontyMole_01, ENEMY_FLAG_PASSIVE, false)
            Call(SetEnemyFlagBits, NPC_MontyMole_02, ENEMY_FLAG_PASSIVE, false)
            Call(SetEnemyFlagBits, NPC_MontyMole_03, ENEMY_FLAG_PASSIVE, false)
            Call(SetEnemyFlagBits, NPC_MontyMole_04, ENEMY_FLAG_PASSIVE, false)
            Call(BindNpcAI, NPC_Dayzee, Ref(N(EVS_NpcAI_Dayzee)))
            Set(MV_PauseBurrowing, false)
            Set(MV_NextBurrowTriggerRadius, 60)
            Set(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
        CaseEq(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            IfEq(GF_FLO03_DefeatedAll_MontyMoles, false)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0058)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Petunia_Angry)
            Else
                Set(LVar4, Float(3.5))
                ExecWait(N(EVS_FocusCamBetween))
                Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_HappyTalk, ANIM_Petunia_Dance, 0, MSG_CH6_0059)
                Call(EndSpeech, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Petunia_GiveItem)
                Wait(20)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Petunia_Idle)
                EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_BEAN)
                Wait(20)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005A)
                Call(EndSpeech, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0)
                Set(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
            EndIf
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005B)
        CaseLt(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005C)
        CaseDefault
            IfEq(AB_FLO_PetuniaDialogue, 0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005D)
                Set(AB_FLO_PetuniaDialogue, 1)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005E)
            EndIf
    EndSwitch
    Call(ResetCam, CAM_DEFAULT, Float(8.0))
    ExecWait(N(EVS_PopSong))
    Return
    End
};

EvtScript N(EVS_NpcInit_Petunia) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Petunia)))
    IfEq(GF_FLO03_DefeatedAll_MontyMoles, false)
        Call(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Angry)
    Else
        Call(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Idle)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Dayzee) = {
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Dayzee)))
    Call(EnableNpcShadow, NPC_Dayzee, false)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            Call(SetNpcPos, NPC_Dayzee, NPC_DISPOSE_LOCATION)
        CaseDefault
            IfEq(GF_FLO03_Defeated_Dayzee, false)
                Call(SetEnemyFlagBits, NPC_Dayzee, ENEMY_FLAG_PASSIVE, false)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Dayzee)))
            Else
                Call(SetNpcPos, NPC_Dayzee, NPC_DISPOSE_LOCATION)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetupMoles) = {
    Set(MV_PauseBurrowing, false)
    Set(MV_NextBurrowTime_Mole_01, 0)
    Set(MV_NextBurrowTime_Mole_02, 0)
    Set(MV_NextBurrowTime_Mole_03, 0)
    Set(MV_NextBurrowTime_Mole_04, 0)
    Set(MV_NextBurrowTriggerRadius, 100)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_MontyMole) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            // record defeat
            Call(GetSelfNpcID, LVar0)
            Switch(LVar0)
                CaseEq(NPC_MontyMole_01)
                    Set(GF_FLO03_Defeated_MontyMoleA, true)
                CaseEq(NPC_MontyMole_02)
                    Set(GF_FLO03_Defeated_MontyMoleB, true)
                CaseEq(NPC_MontyMole_03)
                    Set(GF_FLO03_Defeated_MontyMoleC, true)
                CaseEq(NPC_MontyMole_04)
                    Set(GF_FLO03_Defeated_MontyMoleD, true)
            EndSwitch
            // count number of defeated moles
            Set(LVar0, 0)
            Add(LVar0, GF_FLO03_Defeated_MontyMoleA)
            Add(LVar0, GF_FLO03_Defeated_MontyMoleB)
            Add(LVar0, GF_FLO03_Defeated_MontyMoleC)
            Add(LVar0, GF_FLO03_Defeated_MontyMoleD)
            // end the mole-hunting minigame if all 4 are defeated
            IfNe(LVar0, 4)
                Call(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Angry)
            Else
                Call(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Idle)
                Set(GF_FLO03_DefeatedAll_MontyMoles, true)
                ExecWait(N(EVS_SetupMusic))
            EndIf
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Dark_Anim01)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Dark_Anim01)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_MontyMole) = {
    IfEq(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
        EVT_DEBUG_LOG(Ref("touch_choro\n"))
        Call(GetOwnerEncounterTrigger, LVar0)
        DebugPrintVar(LVar0)
        IfNe(LVar0, ENCOUNTER_TRIGGER_NONE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Dark_Anim05)
        EndIf
    EndIf
    Return
    End
};

#if VERSION_JP
EvtScript N(EVS_802421D4_ECB2C4) = {
    Loop(0)
        Wait(1)
        IfEq(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            BreakLoop
        EndIf
    EndLoop
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
    Return
    End
};
#endif

EvtScript N(EVS_NpcIdle_MontyMole_01) = {
    #define LV_ShouldBurrow LVar3
#if VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Loop(0)
        IfEq(MV_NextBurrowTime_Mole_01, 0)
            IfEq(AF_FLO_IsUnderground_Mole_01, true)
                Goto(0)
            EndIf
            Set(LV_ShouldBurrow, true)
        Else
            Label(0)
            Call(GetNpcPos, NPC_MontyMole_01, LVar0, LVar1, LVar2)
            Call(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EndIf
#if !VERSION_JP
        Call(GetPartnerInUse, LVar9)
        IfEq(LVar9, PARTNER_BOW)
            Set(LVar3, false)
        EndIf
#endif
        IfEq(MV_PauseBurrowing, true)
            Set(LV_ShouldBurrow, false)
        EndIf
        IfEq(LV_ShouldBurrow, true)
            IfEq(AF_FLO_IsUnderground_Mole_01, false)
                Call(SetNpcFlagBits, NPC_MontyMole_01, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Call(NpcFacePlayer, NPC_MontyMole_01, 1)
                Wait(1)
                Set(AF_FLO_IsUnderground_Mole_01, true)
                IfNe(MV_NextBurrowTime_Mole_01, 0)
                    IfLt(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        Set(LVar1, 4)
                    Else
                        Set(LVar1, 10)
                    EndIf
                    Call(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                    Call(ShowEmote, NPC_MontyMole_01, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    Wait(LVar1)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, true)
                EndIf
                Call(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim11)
                Wait(20)
                IfEq(GF_FLO03_Defeated_MontyMoleA, false)
                    Call(SetNpcPos, NPC_MontyMole_01, 0, -50, 0)
                EndIf
                Wait(45)
            EndIf
        Else
            IfEq(AF_FLO_IsUnderground_Mole_01, true)
                IfEq(GF_FLO03_Defeated_MontyMoleA, false)
                    Call(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_01)) - 1, LVar0)
                    Add(LVar0, 1)
                    UseBuf(Ref(N(BurrowLocations_Mole_01)))
                    Loop(LVar0)
                        BufRead3(LVar1, LVar2, LVar3)
                    EndLoop
                    Call(SetNpcPos, NPC_MontyMole_01, LVar1, LVar2, LVar3)
                EndIf
                Call(SetNpcFlagBits, NPC_MontyMole_01, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Set(AF_FLO_IsUnderground_Mole_01, false)
                Call(NpcFacePlayer, NPC_MontyMole_01, 1)
                Wait(1)
                Call(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim10)
                Wait(10)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, false)
                Call(RandInt, 30, LVar0)
                Add(LVar0, 60)
                Set(MV_NextBurrowTime_Mole_01, LVar0)
            Else
                IfGt(MV_NextBurrowTime_Mole_01, 0)
                    Sub(MV_NextBurrowTime_Mole_01, 1)
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_MontyMole_02) = {
     #define LV_ShouldBurrow LVar3
#if VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Loop(0)
        IfEq(MV_NextBurrowTime_Mole_02, 0)
            IfEq(AF_FLO_IsUnderground_Mole_02, true)
                Goto(0)
            EndIf
            Set(LV_ShouldBurrow, true)
        Else
            Label(0)
            Call(GetNpcPos, NPC_MontyMole_02, LVar0, LVar1, LVar2)
            Call(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EndIf
#if !VERSION_JP
        Call(GetPartnerInUse, LVar9)
        IfEq(LVar9, PARTNER_BOW)
            Set(LV_ShouldBurrow, false)
        EndIf
#endif
        IfEq(MV_PauseBurrowing, true)
            Set(LV_ShouldBurrow, false)
        EndIf
        IfEq(LV_ShouldBurrow, true)
            IfEq(AF_FLO_IsUnderground_Mole_02, false)
                Call(SetNpcFlagBits, NPC_MontyMole_02, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Call(NpcFacePlayer, NPC_MontyMole_02, 1)
                Wait(1)
                Set(AF_FLO_IsUnderground_Mole_02, true)
                IfNe(MV_NextBurrowTime_Mole_02, 0)
                    IfLt(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        Set(LVar1, 4)
                    Else
                        Set(LVar1, 10)
                    EndIf
                    Call(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                    Call(ShowEmote, NPC_MontyMole_02, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    Wait(LVar1)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, true)
                EndIf
                Call(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim11)
                Wait(20)
                IfEq(GF_FLO03_Defeated_MontyMoleB, false)
                    Call(SetNpcPos, NPC_MontyMole_02, 0, -50, 0)
                EndIf
                Wait(45)
            EndIf
        Else
            IfEq(AF_FLO_IsUnderground_Mole_02, true)
                IfEq(GF_FLO03_Defeated_MontyMoleB, false)
                    Call(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_02)) - 1, LVar0)
                    Add(LVar0, 1)
                    UseBuf(Ref(N(BurrowLocations_Mole_02)))
                    Loop(LVar0)
                        BufRead3(LVar1, LVar2, LVar3)
                    EndLoop
                    Call(SetNpcPos, NPC_MontyMole_02, LVar1, LVar2, LVar3)
                EndIf
                Call(SetNpcFlagBits, NPC_MontyMole_02, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Set(AF_FLO_IsUnderground_Mole_02, false)
                Call(NpcFacePlayer, NPC_MontyMole_02, 1)
                Wait(1)
                Call(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
                Wait(10)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, false)
                Call(RandInt, 35, LVar0)
                Add(LVar0, 55)
                Set(MV_NextBurrowTime_Mole_02, LVar0)
            Else
                IfGt(MV_NextBurrowTime_Mole_02, 0)
                    Sub(MV_NextBurrowTime_Mole_02, 1)
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_MontyMole_03) = {
    #define LV_ShouldBurrow LVar3
#if VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Loop(0)
        IfEq(MV_NextBurrowTime_Mole_03, 0)
            IfEq(AF_FLO_IsUnderground_Mole_03, true)
                Goto(0)
            EndIf
            Set(LV_ShouldBurrow, true)
        Else
            Label(0)
            Call(GetNpcPos, NPC_MontyMole_03, LVar0, LVar1, LVar2)
            Call(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EndIf
#if !VERSION_JP
        Call(GetPartnerInUse, LVar9)
        IfEq(LVar9, PARTNER_BOW)
            Set(LV_ShouldBurrow, false)
        EndIf
#endif
        IfEq(MV_PauseBurrowing, true)
            Set(LV_ShouldBurrow, false)
        EndIf
        IfEq(LV_ShouldBurrow, true)
            IfEq(AF_FLO_IsUnderground_Mole_03, false)
                Call(SetNpcFlagBits, NPC_MontyMole_03, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Call(NpcFacePlayer, NPC_MontyMole_03, 1)
                Wait(1)
                Set(AF_FLO_IsUnderground_Mole_03, true)
                IfNe(MV_NextBurrowTime_Mole_03, 0)
                    IfLt(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        Set(LVar1, 4)
                    Else
                        Set(LVar1, 10)
                    EndIf
                    Call(PlaySoundAtNpc, NPC_MontyMole_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                    Call(ShowEmote, NPC_MontyMole_03, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    Wait(LVar1)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, true)
                EndIf
                Call(PlaySoundAtNpc, NPC_MontyMole_03, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim11)
                Wait(20)
                IfEq(GF_FLO03_Defeated_MontyMoleC, false)
                    Call(SetNpcPos, NPC_MontyMole_03, 0, -50, 0)
                EndIf
                Wait(45)
            EndIf
        Else
            IfEq(AF_FLO_IsUnderground_Mole_03, true)
                IfEq(GF_FLO03_Defeated_MontyMoleC, false)
                    Call(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_03)) - 1, LVar0)
                    Add(LVar0, 1)
                    UseBuf(Ref(N(BurrowLocations_Mole_03)))
                    Loop(LVar0)
                        BufRead3(LVar1, LVar2, LVar3)
                    EndLoop
                    Call(SetNpcPos, NPC_MontyMole_03, LVar1, LVar2, LVar3)
                EndIf
                Call(SetNpcFlagBits, NPC_MontyMole_03, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Set(AF_FLO_IsUnderground_Mole_03, false)
                Call(NpcFacePlayer, NPC_MontyMole_03, 1)
                Wait(1)
                Call(PlaySoundAtNpc, NPC_MontyMole_03, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim10)
                Wait(10)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, false)
                Call(RandInt, 40, LVar0)
                Add(LVar0, 50)
                Set(MV_NextBurrowTime_Mole_03, LVar0)
            Else
                IfGt(MV_NextBurrowTime_Mole_03, 0)
                    Sub(MV_NextBurrowTime_Mole_03, 1)
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_MontyMole_04) = {
    #define LV_ShouldBurrow LVar3
#if VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Loop(0)
        IfEq(MV_NextBurrowTime_Mole_04, 0)
            IfEq(AF_FLO_IsUnderground_Mole_04, true)
                Goto(0)
            EndIf
            Set(LV_ShouldBurrow, true)
        Else
            Label(0)
            Call(GetNpcPos, NPC_MontyMole_04, LVar0, LVar1, LVar2)
            Call(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EndIf
#if !VERSION_JP
        Call(GetPartnerInUse, LVar9)
        IfEq(LVar9, PARTNER_BOW)
            Set(LV_ShouldBurrow, false)
        EndIf
#endif
        IfEq(MV_PauseBurrowing, true)
            Set(LV_ShouldBurrow, false)
        EndIf
        IfEq(LV_ShouldBurrow, true)
            IfEq(AF_FLO_IsUnderground_Mole_04, false)
                Call(SetNpcFlagBits, NPC_MontyMole_04, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Call(NpcFacePlayer, NPC_MontyMole_04, 1)
                Wait(1)
                Set(AF_FLO_IsUnderground_Mole_04, true)
                IfNe(MV_NextBurrowTime_Mole_04, 0)
                    IfLt(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        Set(LVar1, 4)
                    Else
                        Set(LVar1, 10)
                    EndIf
                    Call(PlaySoundAtNpc, NPC_MontyMole_04, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                    Call(ShowEmote, NPC_MontyMole_04, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    Wait(LVar1)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, true)
                EndIf
                Call(PlaySoundAtNpc, NPC_MontyMole_04, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim11)
                Wait(20)
                IfEq(GF_FLO03_Defeated_MontyMoleD, false)
                    Call(SetNpcPos, NPC_MontyMole_04, 0, -50, 0)
                EndIf
                Wait(45)
            EndIf
        Else
            IfEq(AF_FLO_IsUnderground_Mole_04, true)
                IfEq(GF_FLO03_Defeated_MontyMoleD, false)
                    Call(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_04)) - 1, LVar0)
                    Add(LVar0, 1)
                    UseBuf(Ref(N(BurrowLocations_Mole_04)))
                    Loop(LVar0)
                        BufRead3(LVar1, LVar2, LVar3)
                    EndLoop
                    Call(SetNpcPos, NPC_MontyMole_04, LVar1, LVar2, LVar3)
                EndIf
                Call(SetNpcFlagBits, NPC_MontyMole_04, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
                Set(AF_FLO_IsUnderground_Mole_04, false)
                Call(NpcFacePlayer, NPC_MontyMole_04, 1)
                Wait(1)
                Call(PlaySoundAtNpc, NPC_MontyMole_04, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim10)
                Wait(10)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, false)
                Call(RandInt, 45, LVar0)
                Add(LVar0, 45)
                Set(MV_NextBurrowTime_Mole_04, LVar0)
            Else
                IfGt(MV_NextBurrowTime_Mole_04, 0)
                    Sub(MV_NextBurrowTime_Mole_04, 1)
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_MontyMole_01) = {
#if !VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_MontyMole)))
    Call(EnableNpcShadow, NPC_MontyMole_01, false)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_01)))
            Call(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim10)
        CaseEq(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            IfEq(GF_FLO03_Defeated_MontyMoleA, false)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_01)))
                Call(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim10)
                Call(SetEnemyFlagBits, NPC_MontyMole_01, ENEMY_FLAG_PASSIVE, false)
            Else
                Call(SetNpcPos, NPC_MontyMole_01, NPC_DISPOSE_LOCATION)
            EndIf
        CaseDefault
            Call(SetNpcPos, NPC_MontyMole_01, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_MontyMole_02) = {
#if !VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_MontyMole)))
    Call(EnableNpcShadow, NPC_MontyMole_02, false)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_02)))
            Call(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
        CaseEq(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            IfEq(GF_FLO03_Defeated_MontyMoleB, false)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_02)))
                Call(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
                Call(SetEnemyFlagBits, NPC_MontyMole_02, ENEMY_FLAG_PASSIVE, false)
            Else
                Call(SetNpcPos, NPC_MontyMole_02, NPC_DISPOSE_LOCATION)
            EndIf
        CaseDefault
            Call(SetNpcPos, NPC_MontyMole_02, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_MontyMole_03) = {
#if !VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_MontyMole)))
    Call(EnableNpcShadow, NPC_MontyMole_03, false)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_03)))
            Call(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim10)
        CaseEq(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            IfEq(GF_FLO03_Defeated_MontyMoleC, false)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_03)))
                Call(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim10)
                Call(SetEnemyFlagBits, NPC_MontyMole_03, ENEMY_FLAG_PASSIVE, false)
            Else
                Call(SetNpcPos, NPC_MontyMole_03, NPC_DISPOSE_LOCATION)
            EndIf
        CaseDefault
            Call(SetNpcPos, NPC_MontyMole_03, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_MontyMole_04) = {
#if !VERSION_JP
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole)))
#endif
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_MontyMole)))
    Call(EnableNpcShadow, NPC_MontyMole_04, false)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_04)))
            Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim10)
        CaseEq(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            IfEq(GF_FLO03_Defeated_MontyMoleD, false)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MontyMole_04)))
                Call(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim10)
                Call(SetEnemyFlagBits, NPC_MontyMole_04, ENEMY_FLAG_PASSIVE, false)
            Else
                Call(SetNpcPos, NPC_MontyMole_04, NPC_DISPOSE_LOCATION)
            EndIf
        CaseDefault
            Call(SetNpcPos, NPC_MontyMole_04, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Petunia) = {
    .id = NPC_Petunia,
    .pos = { -30.0f, 0.0f, 100.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Petunia),
    .settings = &N(NpcSettings_Petunia),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Petunia_Idle,
        .walk   = ANIM_Petunia_Idle,
        .run    = ANIM_Petunia_Idle,
        .chase  = ANIM_Petunia_Idle,
        .anim_4 = ANIM_Petunia_Idle,
        .anim_5 = ANIM_Petunia_Idle,
        .death  = ANIM_Petunia_Idle,
        .hit    = ANIM_Petunia_Idle,
        .anim_8 = ANIM_Petunia_Idle,
        .anim_9 = ANIM_Petunia_Idle,
        .anim_A = ANIM_Petunia_Idle,
        .anim_B = ANIM_Petunia_Idle,
        .anim_C = ANIM_Petunia_Idle,
        .anim_D = ANIM_Petunia_Idle,
        .anim_E = ANIM_Petunia_Idle,
        .anim_F = ANIM_Petunia_Idle,
    },
    .tattle = MSG_NpcTattle_Petunia,
};

NpcData N(NpcData_Dayzee) = {
    .id = NPC_Dayzee,
    .pos = { -233.0f, 0.0f, -217.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Dayzee),
    .settings = &N(NpcSettings_Dayzee),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Dayzee_Anim01,
        .walk   = ANIM_Dayzee_Anim02,
        .run    = ANIM_Dayzee_Anim03,
        .chase  = ANIM_Dayzee_Anim03,
        .anim_4 = ANIM_Dayzee_Anim01,
        .anim_5 = ANIM_Dayzee_Anim01,
        .death  = ANIM_Dayzee_Anim08,
        .hit    = ANIM_Dayzee_Anim08,
        .anim_8 = ANIM_Dayzee_Anim06,
        .anim_9 = ANIM_Dayzee_Anim07,
        .anim_A = ANIM_Dayzee_Anim01,
        .anim_B = ANIM_Dayzee_Anim01,
        .anim_C = ANIM_Dayzee_Anim01,
        .anim_D = ANIM_Dayzee_Anim01,
        .anim_E = ANIM_Dayzee_Anim01,
        .anim_F = ANIM_Dayzee_Anim01,
    },
};

NpcData N(NpcData_MontyMole_01) = {
    .id = NPC_MontyMole_01,
    .pos = { -100.0f, 0.0f, 210.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_MontyMole_01),
    .settings = &N(NpcSettings_Dayzee),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcData N(NpcData_MontyMole_02) = {
    .id = NPC_MontyMole_02,
    .pos = { -130.0f, 0.0f, 0.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_MontyMole_02),
    .settings = &N(NpcSettings_Dayzee),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcData N(NpcData_MontyMole_03) = {
    .id = NPC_MontyMole_03,
    .pos = { 75.0f, 0.0f, 20.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_MontyMole_03),
    .settings = &N(NpcSettings_Dayzee),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcData N(NpcData_MontyMole_04) = {
    .id = NPC_MontyMole_04,
    .pos = { 71.0f, 0.0f, 200.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_MontyMole_04),
    .settings = &N(NpcSettings_Dayzee),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

// dead formation IDs differ from the current
NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Petunia)),
    NPC_GROUP(N(NpcData_Dayzee), 0x1A0F, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_01), 0x1B02, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_02), 0x1B01, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_03), 0x1B03, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_04), 0x1B04, BTL_FLO2_STAGE_01),
    {}
};
