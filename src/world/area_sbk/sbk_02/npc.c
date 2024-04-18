#include "sbk_02.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_NpcIdle_Mamar) = {
    Loop(0)
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

API_CALLABLE(N(UpgradeStarPowerCh2)) {
    set_max_star_power(2);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_RescuedMamar) = {
    Call(DisablePartnerAI, 0)
    Call(func_802CF56C, 2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -50)
    Set(LVar4, LVar1)
    Add(LVar4, 26)
    Call(SetNpcPos, NPC_Mamar, LVar3, LVar4, LVar2)
    Call(PlayerFaceNpc, NPC_Mamar, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, SPEECH_FLAG_200, MSG_CH2_00EB)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, 18, -9)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Mamar, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableNpcAI, NPC_Mamar, FALSE)
    Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Leap)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar1)
    Add(LVar1, 50)
    Add(LVar2, 10)
    Add(LVar3, 30)
    Loop(5)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        Wait(6 * DT)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        Wait(6 * DT)
    EndLoop
    Wait(20 * DT)
    Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    Call(EnableNpcAI, NPC_Mamar, TRUE)
    Call(N(UpgradeStarPowerCh2))
    Call(ShowMessageAtScreenPos, MSG_Menus_0192, 160, 40)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, SPEECH_FLAG_200, MSG_CH2_00EC)
    Wait(10 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Mamar, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, SPEECH_FLAG_200, MSG_CH2_00ED)
    Call(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Thread
        Loop(25)
            Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            Wait(4 * DT)
        EndLoop
    EndThread
    Thread
        Set(LVar2, 0)
        Set(LVar3, 1800)
        Call(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Mamar, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_Mamar, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 180)
        Call(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_Mamar, LVar2, LVar0, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Mamar, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_Mamar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(90 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
    Exec(N(EVS_SetupMusic))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Mamar) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, sbk_02_ENTRY_5)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Mamar)))
        Exec(N(EVS_Scene_RescuedMamar))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

API_CALLABLE(N(CheckTradeEventTime)) {
    s32 timeElapsed = (gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600;
    script->varTable[0] = timeElapsed < script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTradeEventItemCount)) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_TradingToad) = {
    Set(LVar0, 5)
    Call(N(CheckTradeEventTime))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00EE)
        Wait(10)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Set(GF_TradingEvent2_Active, FALSE)
        Return
    EndIf
    Call(N(GetTradeEventItemCount))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00EF)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F0)
    EVT_CHOOSE_ANY_CONSUMABLE(2)
    Switch(LVar0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F4)
            Return
        CaseEq(ITEM_NUTTY_CAKE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F1)
            EVT_GIVE_CONSUMABLE_REWARD(ITEM_MAPLE_SUPER)
            Wait(10)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F2)
            Wait(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Set(GF_TradingEvent2_Active, FALSE)
            Add(GB_TradingEvent_Count, 1)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F3)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TradingToad) = {
    IfNe(GF_TradingEvent2_Active, FALSE)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TradingToad)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Mamar) = {
    .id = NPC_Mamar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Mamar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = MAMAR_ANIMS,
};

NpcData N(NpcData_TradingToad) = {
    .id = NPC_TradingToad,
    .pos = { 0.0f, 2.0f, 150.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_TradingToad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Toad_Pink_Idle,
        .walk   = ANIM_Toad_Pink_Walk,
        .run    = ANIM_Toad_Pink_Run,
        .chase  = ANIM_Toad_Pink_Run,
        .anim_4 = ANIM_Toad_Pink_Idle,
        .anim_5 = ANIM_Toad_Pink_Idle,
        .death  = ANIM_Toad_Pink_Idle,
        .hit    = ANIM_Toad_Pink_Disappointed,
        .anim_8 = ANIM_Toad_Pink_Run,
        .anim_9 = ANIM_Toad_Pink_Run,
        .anim_A = ANIM_Toad_Pink_Run,
        .anim_B = ANIM_Toad_Pink_Run,
        .anim_C = ANIM_Toad_Pink_Run,
        .anim_D = ANIM_Toad_Pink_Run,
        .anim_E = ANIM_Toad_Pink_Run,
        .anim_F = ANIM_Toad_Pink_Run,
    },
    .tattle = MSG_NpcTattle_PrizeToad,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Mamar)),
    NPC_GROUP(N(NpcData_TradingToad)),
    {}
};
