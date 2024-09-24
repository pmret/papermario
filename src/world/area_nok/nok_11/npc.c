#include "nok_11.h"

#include "world/common/enemy/Goomba_Wander.inc.c"
#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/Paragoomba_Wander.inc.c"
#include "world/common/enemy/SpikedGoomba_Wander.inc.c"
#include "world/common/npc/JrTroopa.inc.c"
#include "world/common/enemy/KentCKoopa.inc.c"

#include "common/foliage.inc.c"

EvtScript N(EVS_JrTroopa_RunFX) = {
    Loop(0)
        Call(GetNpcPos, NPC_JrTroopa_01, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0)
        Wait(3)
    EndLoop
    Return
    End
};

FoliageModelList N(SceneBush_Models) = FOLIAGE_MODEL_LIST(MODEL_o125);

SearchBushConfig N(SearchBush_Scene) = {
    .bush = &N(SceneBush_Models),
};

EvtScript N(EVS_NpcIdle_JrTroopa_01) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLe(LVar0, -125)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    ChildThread
        Label(10)
            Wait(3)
            Call(PlayerFaceNpc, NPC_SELF, FALSE)
            Wait(1)
            Goto(10)
    EndChildThread
    Exec(N(EVS_PlayJrTroopaSong))
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 5, MSG_CH1_011E)
    Wait(15 * DT)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamProperties, CAM_DEFAULT, Float(90.0), -190, 0, -40, 200, Float(15.0), Float(-8.5))
    Wait(15 * DT)
    Set(LVar0, Ref(N(SearchBush_Scene)))
    Exec(N(EVS_SearchBush))
    Wait(15 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(NpcJump0, NPC_SELF, -230, 0, -157, 15 * DT)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_011F)
    Call(SetCamProperties, CAM_DEFAULT, Float(4.0 / DT), -140, 0, -40, 400, Float(15.0), Float(-5.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    Wait(10 * DT)
    Thread
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Trip)
        Call(ShowMessageAtScreenPos, MSG_CH1_0120, 160, 40)
    EndThread
    Thread
    EndThread
    Thread
        Wait(10 * DT)
        Loop(10 * DT)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            Wait(2)
        EndLoop
    EndThread
    Call(NpcMoveTo, NPC_SELF, -201, -67, 10 * DT)
    Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
    Call(NpcJump1, NPC_SELF, -191, 0, -32, 5 * DT)
    ExecGetTID(N(EVS_JrTroopa_RunFX), LVarA)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SLIDE, SOUND_SPACE_DEFAULT)
    Call(NpcMoveTo, NPC_SELF, -165, 50, 15 * DT)
    KillThread(LVarA)
    Call(StopSound, SOUND_SLIDE)
    Wait(5 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_FallHeadfirstBack)
    Wait(15 * DT)
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_WATER_SPLASH, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        PlayEffect(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, Float(0.7), 30)
        Add(LVar0, 10)
        PlayEffect(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, Float(0.7), 30)
        Wait(5 * DT)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 25)
        PlayEffect(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, Float(0.7), 30)
        Add(LVar0, 10)
        PlayEffect(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, Float(0.7), 30)
        Wait(5 * DT)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, -15)
        PlayEffect(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, Float(0.7), 30)
        Add(LVar0, 10)
        PlayEffect(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, Float(0.7), 30)
    EndThread
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.5))
    Call(NpcJump0, NPC_SELF, -165, -90, 50, 20 * DT)
    Wait(30 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SCAMPER, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ScamperBack)
    Call(SetNpcYaw, NPC_SELF, 270)
    Thread
        Wait(85 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ClimbUpBack)
    EndThread
    Call(SetNpcJumpscale, NPC_SELF, 0)
    Call(NpcJump0, NPC_SELF, -165, 0, 50, 90 * DT)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    Call(NpcMoveTo, NPC_SELF, -190, -45, 10 * DT)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_PointTapFoot)
    Call(SetCamProperties, CAM_DEFAULT, Float(90.0), -140, 0, -40, 250, Float(15.0), Float(-8.5))
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0121)
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH1_0122)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_CH1_0123)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 5, MSG_CH1_0124)
    EndSwitch
    Call(EnablePartnerAI)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0125)
    Call(ShowChoice, MSG_Choice_0013)
    Wait(10 * DT)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0126)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0127)
    EndIf
    Wait(10 * DT)
    Call(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcAI_JrTroopa_01) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_JrTroopa_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH1_012B)
    Return
    End
};

EvtScript N(EVS_NpcIdle_JrTroopa_02) = {
    Loop(0)
        Call(GetNpcPos, NPC_JrTroopa_01, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcHit_JrTroopa_02) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(DisablePlayerInput, TRUE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH1_012B)
            Call(DisablePlayerInput, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_JrTroopa_01) = {
    Call(ClearDefeatedEnemies)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Defeated)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_JrTroopa_02, LVar0, LVar1, LVar2)
    Call(SetNpcCollisionSize, NPC_SELF, 24, 32)
    Call(SetNpcCollisionSize, NPC_JrTroopa_02, 24, 32)
    Set(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
    Thread
        Wait(4)
        Exec(N(EVS_SetupMusic))
    EndThread
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_JrTroopa_01)))
    Call(SetNpcFlagBits, NPC_JrTroopa_02, NPC_FLAG_INVISIBLE, TRUE)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_KentCKoopa_02) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0134)
    Return
    End
};

API_CALLABLE(N(KentCheckNotEnoughCoins)) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->coins >= 100) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(KentTakeCoins)) {
    PlayerData* playerData = &gPlayerData;

    playerData->coins -= 100;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_KentCKoopa_01) = {
    Label(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfEq(AB_NOK_2, 0)
            IfGe(LVar0, -260)
                Goto(10)
            Else
                Goto(2)
            EndIf
        Else
            IfLe(LVar0, -55)
                Goto(10)
            Else
                Goto(2)
            EndIf
        EndIf
        Label(2)
        Wait(1)
        Goto(1)
    Label(10)
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012C)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 20)
    Else
        Set(LVar0, -20)
    EndIf
    Call(AdjustCam, CAM_DEFAULT, Float(5.0), LVar0, Float(275.0), Float(17.5), Float(-12.0))
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012D)
    Label(15)
    Call(ShowCoinCounter, TRUE)
    Call(ShowChoice, MSG_Choice_0045)
    IfEq(LVar0, 0)
        Goto(30)
    EndIf
    IfEq(LVar0, 1)
        Goto(50)
    EndIf
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 20)
    Else
        Set(LVar0, -20)
    EndIf
    Call(ShowCoinCounter, FALSE)
    Call(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012E)
    Call(ShowCoinCounter, TRUE)
    Call(ShowChoice, MSG_Choice_0045)
    IfEq(LVar0, 0)
        Goto(30)
    EndIf
    IfEq(LVar0, 1)
        Goto(50)
    EndIf
    Call(ShowCoinCounter, FALSE)
    Label(20)
    Call(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0135)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 20)
    Else
        Set(LVar0, -20)
    EndIf
#if VERSION_JP
    IfEq(AF_NOK_14, 0)
        Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0136)
    Else
        Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0139)
    EndIf
#else
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0136)
#endif
    Call(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim05)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 90)
    Else
        Set(LVar0, 270)
    EndIf
    Call(InterpNpcYaw, NPC_KentCKoopa_02, LVar0, 0)
    Wait(30)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 125)
    Else
        Set(LVar0, -430)
    EndIf
    Call(NpcMoveTo, NPC_KentCKoopa_02, LVar0, -37, 40)
    Call(SetNpcPos, NPC_KentCKoopa_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Goto(100)
    Label(30)
    Call(N(KentCheckNotEnoughCoins))
    IfEq(LVar0, 1)
        Goto(40)
    EndIf
    Call(CloseMessage)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, -215)
    Else
        Set(LVar0, -100)
    EndIf
    Call(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim03)
    Call(NpcMoveTo, NPC_KentCKoopa_02, LVar0, LVar2, 20)
    Call(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim01)
    Call(N(KentTakeCoins))
    Call(ShowCoinCounter, FALSE)
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0133)
    Wait(20)
    Call(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim03)
    Call(NpcMoveTo, NPC_KentCKoopa_02, -167, -100, 20)
    Call(SetNpcFlagBits, NPC_KentCKoopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(BindNpcInteract, NPC_KentCKoopa_02, Ref(N(EVS_NpcInteract_KentCKoopa_02)))
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim01)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 270)
    Else
        Set(LVar0, 90)
    EndIf
    Call(InterpNpcYaw, NPC_KentCKoopa_02, LVar0, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0134)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Goto(100)
    Label(40)
    Call(ShowCoinCounter, FALSE)
    Call(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012F)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Exec(N(EVS_SetupMusic))
    Wait(30)
    Call(DisablePlayerInput, FALSE)
    Label(41)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfEq(AB_NOK_2, 0)
            IfGe(LVar0, -255)
                Set(LVar3, -256)
                Goto(43)
            Else
                Goto(42)
            EndIf
        Else
            IfLe(LVar0, -60)
                Set(LVar3, -59)
                Goto(43)
            Else
                Goto(42)
            EndIf
        EndIf
        Label(42)
        Wait(1)
        Goto(41)
    Label(43)
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(SetPlayerPos, LVar3, LVar1, LVar2)
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0130)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerPos, LVar3, LVar1, LVar2)
    Call(DisablePlayerInput, FALSE)
    Goto(41)
    Label(50)
    Call(ShowCoinCounter, FALSE)
    Call(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0131)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Exec(N(EVS_SetupMusic))
    Wait(30)
    Call(DisablePlayerInput, FALSE)
    Label(51)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfEq(AB_NOK_2, 0)
            IfGe(LVar0, -255)
                Set(LVar3, -256)
                Goto(53)
            Else
                Goto(52)
            EndIf
        Else
            IfLe(LVar0, -60)
                Set(LVar3, -59)
                Goto(53)
            Else
                Goto(52)
            EndIf
        EndIf
        Label(52)
        Wait(1)
        Goto(51)
    Label(53)
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    Call(SetPlayerPos, LVar3, LVar1, LVar2)
    Call(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0132)
    IfEq(AB_NOK_2, 0)
        Set(LVar0, 20)
    Else
        Set(LVar0, -20)
    EndIf
    Call(AdjustCam, CAM_DEFAULT, Float(5.0), LVar0, Float(275.0), Float(17.5), Float(-12.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerPos, LVar3, LVar1, LVar2)
    Goto(15)
    Label(100)
    Exec(N(EVS_SetupMusic))
    Wait(30)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KentCKoopa_01) = {
    Set(GF_NOK11_Defeated_KentC, TRUE)
    Call(ClearDefeatedEnemies)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KentCKoopa_02) = {
    Call(ClearDefeatedEnemies)
    Return
    End
};

NpcData N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .pos = { -350.0f, 0.0f, -30.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -350, 0, -30 },
            .wanderSize = { 50, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -350, 0, -30 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
};

NpcData N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .pos = { 0.0f, 60.0f, -30.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 0, 60, -30 },
            .wanderSize = { 50, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 60, -30 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = PARAGOOMBA_DROPS,
    .animations = PARAGOOMBA_ANIMS,
};

NpcData N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .pos = { 430.0f, 0.0f, -27.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 430, 0, -27 },
            .wanderSize = { 50, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 430, 0, -27 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKED_GOOMBA_DROPS,
    .animations = SPIKED_GOOMBA_ANIMS,
};

EvtScript N(EVS_NpcInit_JrTroopa_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa_01)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_JrTroopa_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_JrTroopa_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa_02) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa_02)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_JrTroopa_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Return
    End
};

NpcData N(NpcData_JrTroopa)[] = {
    {
        .id = NPC_JrTroopa_01,
        .pos = { -170.0f, 0.0f, -155.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa_01),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
    {
        .id = NPC_JrTroopa_02,
        .pos = { -170.0f, 0.0f, -155.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa_02),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
};

EvtScript N(EVS_NpcInit_KentCKoopa_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KentCKoopa_01)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_KentCKoopa_01)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetEntryID, AB_NOK_2)
    Return
    End
};

EvtScript N(EVS_NpcInit_KentCKoopa_02) = {
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_KentCKoopa_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetEntryID, LVar3)
    IfEq(LVar3, nok_11_ENTRY_0)
        Call(SetNpcYaw, NPC_SELF, 270)
    Else
        Call(SetNpcYaw, NPC_SELF, 90)
    EndIf
    Return
    End
};

NpcData N(NpcData_KentCKoopa)[] = {
    {
        .id = NPC_KentCKoopa_01,
        .pos = { -164.0f, 0.0f, -37.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KentCKoopa_01),
        .settings = &N(NpcSettings_KentCKoopa),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = KENT_C_KOOPA_ANIMS,
    },
    {
        .id = NPC_KentCKoopa_02,
        .pos = { -164.0f, 0.0f, -37.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KentCKoopa_02),
        .settings = &N(NpcSettings_KentCKoopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = KENT_C_KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_KentCKoopa,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_NOK_FORMATION_08, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_NOK_FORMATION_02, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_NOK_FORMATION_03, BTL_NOK_STAGE_01),
    {}
};

NpcGroupList N(JrTroopaNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa), BTL_KMR_3_FORMATION_03),
    {}
};

NpcGroupList N(KentCKoopaNPCs) = {
    NPC_GROUP(N(NpcData_KentCKoopa), BTL_NOK_FORMATION_18, BTL_NOK_STAGE_00),
    {}
};
