#include "dgb_00.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(PlaySentinelSounds)) {
    Npc* npc = get_npc_unsafe(get_enemy(NPC_Sentinel)->npcID);

    sfx_adjust_env_sound_pos(SOUND_LRAW_SENTINEL_ALARM, SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}

#include "world/common/npc/Boo.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Sentinel.h"

EvtScript N(EVS_SetDoorRots) = {
    Set(LVar3, 0)
    Sub(LVar3, LVar2)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliwt, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_deiliwt, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_d2, LVar0, 0, LVar2, 0)
        Call(RotateModel, MODEL_d1, LVar0, 0, LVar3, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_CloseDoors) = {
    Set(LVar3, 0)
    Sub(LVar3, LVar2)
    Call(MakeLerp, 80, 0, 12, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_d2, LVar0, 0, LVar2, 0)
        Call(RotateModel, MODEL_d1, LVar0, 0, LVar3, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deiliwt, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_deiliwt, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_AdvanceBoo1) = {
    Call(GetNpcPos, NPC_Boo_01, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(NpcMoveTo, NPC_Boo_01, LVar0, LVar2, 46 * DT)
    Return
    End
};

EvtScript N(EVS_AdvanceBoo2) = {
    Call(GetNpcPos, NPC_Boo_02, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(NpcMoveTo, NPC_Boo_02, LVar0, LVar2, 50 * DT)
    Return
    End
};

EvtScript N(EVS_AdvanceBoo3) = {
    Call(GetNpcPos, NPC_Boo_03, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(NpcMoveTo, NPC_Boo_03, LVar0, LVar2, 53 * DT)
    Return
    End
};

EvtScript N(EVS_AdvanceBoo4) = {
    Call(GetNpcPos, NPC_Boo_04, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(NpcMoveTo, NPC_Boo_04, LVar0, LVar2, 46 * DT)
    Return
    End
};

EvtScript N(EVS_AdvanceBoo5) = {
    Call(GetNpcPos, NPC_Boo_05, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(NpcMoveTo, NPC_Boo_05, LVar0, LVar2, 50 * DT)
    Return
    End
};

EvtScript N(EVS_AdvanceBoo6) = {
    Call(GetNpcPos, NPC_Boo_06, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(NpcMoveTo, NPC_Boo_06, LVar0, LVar2, 53 * DT)
    Return
    End
};

EvtScript N(EVS_AdvanceBooPhalanx) = {
    Exec(N(EVS_AdvanceBoo1))
    Exec(N(EVS_AdvanceBoo2))
    Exec(N(EVS_AdvanceBoo3))
    Exec(N(EVS_AdvanceBoo4))
    Exec(N(EVS_AdvanceBoo5))
    Exec(N(EVS_AdvanceBoo6))
    Return
    End
};

EvtScript N(EVS_BraceDoor1) = {
    Call(SetNpcJumpscale, NPC_Boo_01, Float(-0.2))
    Call(NpcJump0, NPC_Boo_01, 257, 30, -90, 5 * DT)
    Call(EnableNpcShadow, NPC_Boo_01, FALSE)
    Call(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    Return
    End
};

EvtScript N(EVS_BraceDoor2) = {
    Call(SetNpcJumpscale, NPC_Boo_02, Float(-0.3))
    Call(NpcJump0, NPC_Boo_02, 272, 112, -81, 12 * DT)
    Call(EnableNpcShadow, NPC_Boo_02, FALSE)
    Call(SetNpcAnimation, NPC_Boo_02, ANIM_Boo_Tan_Flail)
    Return
    End
};

EvtScript N(EVS_BraceDoor3) = {
    Call(SetNpcJumpscale, NPC_Boo_03, Float(-0.4))
    Call(NpcJump0, NPC_Boo_03, 237, 120, -118, 10 * DT)
    Call(EnableNpcShadow, NPC_Boo_03, FALSE)
    Call(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Flail)
    Return
    End
};

EvtScript N(EVS_BraceDoor4) = {
    Call(SetNpcJumpscale, NPC_Boo_04, Float(-0.3))
    Call(NpcJump0, NPC_Boo_04, 280, 60, -79, 8 * DT)
    Call(EnableNpcShadow, NPC_Boo_04, FALSE)
    Call(SetNpcAnimation, NPC_Boo_04, ANIM_Boo_Tan_Flail)
    Return
    End
};

EvtScript N(EVS_BraceDoor5) = {
    Call(SetNpcJumpscale, NPC_Boo_05, Float(-0.4))
    Call(NpcJump0, NPC_Boo_05, 250, 81, -97, 9 * DT)
    Call(EnableNpcShadow, NPC_Boo_05, FALSE)
    Call(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Flail)
    Return
    End
};

EvtScript N(EVS_BraceDoor6) = {
    Call(SetNpcJumpscale, NPC_Boo_06, Float(-0.5))
    Call(NpcJump0, NPC_Boo_06, 227, 43, -123, 15 * DT)
    Call(EnableNpcShadow, NPC_Boo_06, FALSE)
    Call(SetNpcAnimation, NPC_Boo_06, ANIM_Boo_Tan_Flail)
    Return
    End
};

EvtScript N(EVS_BoosBraceDoor) = {
    Exec(N(EVS_BraceDoor2))
    Exec(N(EVS_BraceDoor3))
    Exec(N(EVS_BraceDoor4))
    Exec(N(EVS_BraceDoor5))
    Exec(N(EVS_BraceDoor6))
    Return
    End
};

EvtScript N(EVS_LeaderBooShivering) = {
    Call(GetNpcPos, NPC_Boo_01, LVar0, LVar1, LVar2)
    Loop(0)
        Call(RandInt, 5, LVarA)
        Add(LVarA, 2)
        Set(LVarB, 0)
        Label(10)
        Set(LVar3, LVar0)
        Add(LVar3, 1)
        Call(SetNpcPos, NPC_Boo_01, LVar3, LVar1, LVar2)
        Wait(1)
        Set(LVar3, LVar0)
        Add(LVar3, -1)
        Call(SetNpcPos, NPC_Boo_01, LVar3, LVar1, LVar2)
        Wait(1)
        Add(LVarB, 1)
        IfLt(LVarB, LVarA)
            Goto(10)
        EndIf
        Call(RandInt, 10, LVarA)
        Add(LVarA, 10)
        Wait(LVarA)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TubbaTaunting) = {
    SetGroup(EVT_GROUP_EF)
    Loop(0)
        Call(RandInt, 50 * DT, LVar0)
        Add(LVar0, 80 * DT)
        Wait(LVar0)
        IfEq(MV_PreventTaunting, FALSE)
            Call(DisablePlayerInput, TRUE)
            Call(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
            Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
            Call(ShowMessageAtScreenPos, MSG_CH3_00EF, 160, 40)
            Call(DisablePlayerInput, FALSE)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_BoosApproachManor) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerPos, 350, 10, -150)
    Call(InterpPlayerYaw, 270, 1)
    Call(SetNpcPos, NPC_PARTNER, 350, 10, -150)
    Call(EnablePartnerAI)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar0, 175)
    Set(LVar1, 0)
    Set(LVar2, -75)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(40 * DT)
    Call(SetNpcPos, NPC_Boo_01, -60, 10, -70)
    Call(SetNpcPos, NPC_Boo_02, -100, 10, -110)
    Call(SetNpcPos, NPC_Boo_03, -140, 10, -150)
    Call(SetNpcPos, NPC_Boo_04, -100, 10, -30)
    Call(SetNpcPos, NPC_Boo_05, -140, 10, -70)
    Call(SetNpcPos, NPC_Boo_06, -180, 10, -100)
    ExecWait(N(EVS_AdvanceBooPhalanx))
    Wait(60 * DT)
    Call(InterpNpcYaw, NPC_Boo_01, 270, 1)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00DB)
    Call(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00DC)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00DD)
    Call(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
    Wait(10 * DT)
    Call(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
    Call(InterpNpcYaw, NPC_Boo_01, 90, 1)
    Call(ShowMessageAtScreenPos, MSG_CH3_00DE, 160, 40)
    Call(SetPlayerPos, 350, 10, -150)
    Call(InterpPlayerYaw, 270, 1)
    Call(SetNpcPos, NPC_PARTNER, 350, 10, -150)
    Set(LVar2, 1)
    ExecWait(N(EVS_SetDoorRots))
    Return
    End
};

EvtScript N(EVS_Scene_EscapeFromTubba) = {
    Call(SetPlayerSpeed, Float(8.0 / DT))
    Call(PlayerMoveTo, 184, -44, 0)
    Call(PlaySoundAtNpc, NPC_Boo_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_04, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_05, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Boo_06, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Boo_01, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_02, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_03, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_04, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_05, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Boo_06, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(50 * DT)
    Set(LVar2, 1)
    Exec(N(EVS_CloseDoors))
    Exec(N(EVS_BoosBraceDoor))
    Wait(20 * DT)
    Call(SetCamType, CAM_DEFAULT, 6, TRUE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(6.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-15.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecGetTID(N(EVS_LeaderBooShivering), LVarA)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00DF)
    KillThread(LVarA)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00E0)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00E1)
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00E2)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00E3)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00E4)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00E5)
        CaseEq(PARTNER_BOW)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00E6)
    EndSwitch
    Call(EnablePartnerAI)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(6.0 / DT))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
    Wait(5 * DT)
    Call(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
    Call(ShowMessageAtScreenPos, MSG_CH3_00E7, 160, 40)
    ExecWait(N(EVS_BraceDoor1))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 5, MSG_CH3_00E8)
    Call(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    Exec(N(EVS_TubbaTaunting))
    Set(GB_StoryProgress, STORY_CH3_ESCAPED_TUBBAS_MANOR)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetBoosBracingDoor) = {
    Call(SetNpcPos, NPC_Boo_01, 246, 30, -110)
    Call(SetNpcPos, NPC_Boo_02, 276, 120, -80)
    Call(SetNpcPos, NPC_Boo_03, 216, 120, -140)
    Call(SetNpcPos, NPC_Boo_04, 276, 60, -80)
    Call(SetNpcPos, NPC_Boo_05, 246, 90, -110)
    Call(SetNpcPos, NPC_Boo_06, 216, 60, -130)
    Call(InterpNpcYaw, NPC_Boo_01, 70, 1)
    Call(InterpNpcYaw, NPC_Boo_02, 99, 1)
    Call(InterpNpcYaw, NPC_Boo_03, 93, 1)
    Call(InterpNpcYaw, NPC_Boo_04, 74, 1)
    Call(InterpNpcYaw, NPC_Boo_05, 78, 1)
    Call(InterpNpcYaw, NPC_Boo_06, 81, 1)
    Call(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    Call(SetNpcAnimation, NPC_Boo_02, ANIM_Boo_Tan_Flail)
    Call(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Flail)
    Call(SetNpcAnimation, NPC_Boo_04, ANIM_Boo_Tan_Flail)
    Call(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Flail)
    Call(SetNpcAnimation, NPC_Boo_06, ANIM_Boo_Tan_Flail)
    Call(EnableNpcShadow, NPC_Boo_01, FALSE)
    Call(EnableNpcShadow, NPC_Boo_02, FALSE)
    Call(EnableNpcShadow, NPC_Boo_03, FALSE)
    Call(EnableNpcShadow, NPC_Boo_04, FALSE)
    Call(EnableNpcShadow, NPC_Boo_05, FALSE)
    Call(EnableNpcShadow, NPC_Boo_06, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_01) = {
    Set(MV_PreventTaunting, TRUE)
    Call(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 5, MSG_CH3_00E9)
    Call(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(AdjustCam, CAM_DEFAULT, Float(6.0), 0, Float(-275.0), Float(15.0), Float(-6.0))
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00EA)
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
        CaseEq(PARTNER_KOOPER)
            Call(AdjustCam, CAM_DEFAULT, Float(6.0), 0, Float(-275.0), Float(15.0), Float(-6.0))
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00EB)
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
        CaseEq(PARTNER_BOMBETTE)
            Call(AdjustCam, CAM_DEFAULT, Float(6.0), 0, Float(-275.0), Float(15.0), Float(-6.0))
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00EC)
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
        CaseEq(PARTNER_PARAKARRY)
            Call(AdjustCam, CAM_DEFAULT, Float(6.0), 0, Float(-275.0), Float(15.0), Float(-6.0))
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00ED)
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
        CaseEq(PARTNER_BOW)
            Call(AdjustCam, CAM_DEFAULT, Float(6.0), 0, Float(-275.0), Float(15.0), Float(-6.0))
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00EE)
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
    EndSwitch
    Call(EnablePartnerAI)
    Set(MV_PreventTaunting, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    Return
    End
};

NpcData N(NpcData_Boo_01) = {
    .id = NPC_Boo_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_01),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_BraveBoo,
};

NpcData N(NpcData_Boo_02) = {
    .id = NPC_Boo_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_02),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_03) = {
    .id = NPC_Boo_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_03),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_04) = {
    .id = NPC_Boo_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_04),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_05) = {
    .id = NPC_Boo_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_05),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_06) = {
    .id = NPC_Boo_06,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_06),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

EvtScript N(EVS_Scene_ThrownOutBySentinel) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, 320, 10, -160)
    Call(PlaySound, SOUND_LRAW_SENTINEL_ALARM)
    Thread
        Loop(180)
            Call(GetNpcPos, NPC_Sentinel, LVar0, LVar1, LVar2)
            Call(N(PlaySentinelSounds))
            Wait(1)
        EndLoop
    EndThread
    Call(SetPlayerPos, 320, 50, -160)
    Call(InterpPlayerYaw, 270, 0)
    Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
    Call(SetNpcPos, NPC_Sentinel, 320, 70, -158)
    Call(InterpNpcYaw, NPC_Sentinel, 270, 0)
    Call(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim08)
    Call(UseSettingsFrom, CAM_DEFAULT, 175, 0, -35)
    Call(SetPanTarget, CAM_DEFAULT, 175, 0, -35)
    Call(SetCamDistance, CAM_DEFAULT, Float(540.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Thread
        Set(LVar2, 1)
        Exec(N(EVS_SetDoorRots))
    EndThread
    Wait(15)
    Thread
        Call(SetPlayerJumpscale, 0)
        Call(PlayerJump1, 175, 50, -35, 40)
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Wait(1)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
        Wait(85)
        Call(func_802CF56C, 2)
        Wait(1)
        Call(EnablePartnerAI)
    EndThread
    Call(NpcMoveTo, NPC_Sentinel, 175, -33, 40)
    Wait(20)
    Call(SetNpcPos, NPC_Sentinel, 175, 85, -33)
    Call(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim09)
    Wait(20)
    Call(PlaySoundAtNpc, NPC_Sentinel, SOUND_SENTINEL_PICKUP, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim02)
    Call(SetNpcPos, NPC_Sentinel, 175, 70, -33)
    Thread
        Wait(40)
        Call(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim03)
        Call(NpcMoveTo, NPC_Sentinel, 270, -120, 30)
        Call(StopSound, SOUND_LRAW_SENTINEL_ALARM)
        Call(SetNpcPos, NPC_Sentinel, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(60)
        Set(LVar2, 1)
        Exec(N(EVS_CloseDoors))
    EndThread
    Call(SetPlayerJumpscale, 0)
    Call(PlayerJump1, 175, 0, -35, 10)
    Call(PlaySoundAtNpc, NPC_Sentinel, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_MarioW2_Collapse)
    Thread
        Wait(2)
        PlayEffect(EFFECT_EMOTE, EMOTE_FRUSTRATION, 0, 175, 0, -35, 20, -20, 30, 0)
    EndThread
    Thread
        Call(SetCamDistance, CAM_DEFAULT, Float(320.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Wait(65)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        CaseEq(PARTNER_KOOPER)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        CaseEq(PARTNER_BOMBETTE)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EndSwitch
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D6)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D7)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D8)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D9)
        CaseEq(PARTNER_BOW)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00DA)
        CaseDefault
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D6)
    EndSwitch
    Call(EnablePartnerAI)
    Wait(5)
    Call(SetPlayerAnimation, ANIM_Mario1_GetUp)
    Wait(20)
    Call(SetPlayerAnimation, ANIM_Mario1_DustOff)
    Wait(7)
    Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
    Wait(8)
    Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
    Wait(15)
    Call(SetPlayerAnimation, ANIM_MarioW2_DeepExhale)
    Wait(25)
    Call(InterpPlayerYaw, 90, 0)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 45, 0)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Mario1_Jump)
    Call(SetPlayerJumpscale, 1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(PlayerJump1, LVar0, 0, LVar2, 10)
    Call(PlayerJump1, LVar0, 0, LVar2, 10)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Sentinel) = {
    Return
    End
};

NpcData N(NpcData_Sentinel) = {
    .id = NPC_Sentinel,
    .pos = { 0.0f, 0.0f, -1000.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Sentinel),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

NpcGroupList N(BooNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    NPC_GROUP(N(NpcData_Boo_06)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel)),
    {}
};
