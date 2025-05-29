#include "kkj_23.h"
#include "effects.h"
#include "sprite/player.h"

void peach_force_disguise_action(s32);

API_CALLABLE(N(SetLightningBoltColor)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 r = evt_get_variable(script, *args++);
    s32 g = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);

    effect->data.lightningBolt->outerColor.r = r;
    effect->data.lightningBolt->outerColor.g = g;
    effect->data.lightningBolt->outerColor.b = b;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ForceDisguiseLoss)) {
    peach_force_disguise_action(FALSE);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ApproachPeach) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_01, 5)
    EndThread
    Call(SetNpcVar, NPC_Koopatrol_02, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_02, 5)
        Call(SetNpcVar, NPC_Koopatrol_02, 0, 0)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Koopatrol_02, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_PickUpPeach) = {
    Thread
        Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(1)
    Loop(4)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach2_Carried)
    Sub(LVar0, 15)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway) = {
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
            Add(LVar0, 10)
            Add(LVar2, 2)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_02, 684, -52, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, 716, -48, 0)
    EndThread
    Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_OpenAndCloseTowerDoors) = {
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_LARGE_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o9, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o10, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(MakeLerp, 80, 0, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o9, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o10, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_LARGE_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_RemoveDisguise) = {
    Set(LVar0, 0)
    Set(LVar1, 45)
    Loop(10)
        Call(InterpPlayerYaw, LVar0, 0)
        Add(LVar0, LVar1)
        Add(LVar1, 4)
        Wait(1)
    EndLoop
    Call(PlaySoundAtPlayer, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
    Call(N(ForceDisguiseLoss))
    Loop(10)
        Call(InterpPlayerYaw, LVar0, 0)
        Add(LVar0, LVar1)
        Sub(LVar1, 4)
        Wait(1)
    EndLoop
    Call(InterpPlayerYaw, 90, 0)
    Return
    End
};

EvtScript N(EVS_Scene_KammyUnmasksPeach) = {
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLe(LVar0, 140)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetMusic, 0, SONG_KAMMY_KOOPA_THEME, 0, VOL_LEVEL_FULL)
    Call(SetNpcVar, NPC_Koopatrol_01, 1, 0)
    Call(SetNpcFlagBits, NPC_Koopatrol_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcPos, NPC_Kammy, -50, 0, -50)
    Exec(N(EVS_OpenAndCloseTowerDoors))
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    Call(SetNpcSpeed, NPC_Kammy, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_Kammy, 30, -50, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Thread
        Call(InterpNpcYaw, NPC_Koopatrol_01, 270, 5)
        Loop(0)
            Wait(1)
            Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            IfGt(LVar0, 140)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(func_802D1270, 190, LVar2, Float(4.0 / DT))
        Call(func_802D1270, 195, -80, Float(4.0 / DT))
        Call(func_802D1270, 190, -80, Float(4.0 / DT))
        Loop(0)
            Wait(1)
            Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            IfGt(LVar0, 190)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpPlayerYaw, 90, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, -10, -130, 20 * DT)
        Call(SetNpcSpeed, NPC_PARTNER, Float(4.0 / DT))
        Call(NpcFlyTo, NPC_PARTNER, 210, -10, -130, 0, 0, EASING_LINEAR)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 5)
        Loop(0)
            Wait(1)
            Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            IfGt(LVar0, 210)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 90, 5)
    EndThread
    Wait(30 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, -50)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, -50)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_014F)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_Kammy, MSG_Peach_0150)
    Call(SetNpcVar, NPC_Kammy, 0, 1)
    Thread
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Loop(0)
            Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Wait(1)
            Call(GetNpcVar, NPC_Kammy, 0, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    Call(NpcMoveTo, NPC_Kammy, 270, -50, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Call(SetNpcVar, NPC_Kammy, 0, 0)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_Kammy, 270, 5)
    Call(SetPanTarget, CAM_DEFAULT, 230, 0, -50)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0151)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump1, LVar0, LVar1, LVar2, 10 * DT)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0152)
    Call(InterpNpcYaw, NPC_Kammy, 90, 5)
    Wait(10 * DT)
    Call(NpcMoveTo, NPC_Kammy, 280, -50, 0)
    Call(PlaySoundAtNpc, NPC_Kammy, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Kammy, EMOTE_EXCLAMATION, -45, 15, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(InterpNpcYaw, NPC_Kammy, 270, 5)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0153)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim05)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim05, 5, MSG_Peach_0154)
    Call(PlaySoundAtNpc, NPC_Kammy, SOUND_KAMMY_SUMMON_MAGIC, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Add(LVar0, -20)
    Add(LVar1, 40)
    Add(LVar2, 27)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 50)
    Wait(60 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar2, 5)
    Call(GetNpcPos, NPC_Kammy, LVar3, LVar4, LVar5)
    Add(LVar4, 180)
    Call(PlaySoundAtPlayer, SOUND_BOWSER_LIGHTNING, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 5, 20)
    Call(N(SetLightningBoltColor), LVarF, 255, 0, 255)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SHIMMER_BURST, 1, LVar0, LVar1, LVar2, 1, 30)
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    ExecWait(N(EVS_RemoveDisguise))
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_GaspStill, ANIM_Peach2_GaspStill, 5, MSG_Peach_0155)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim05, 5, MSG_Peach_0156)
    Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    Call(NpcMoveTo, NPC_Kammy, 260, -50, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0157)
    Thread
        Loop(0)
            Call(NpcFacePlayer, NPC_Kammy, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Loop(0)
            Wait(1)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfGt(LVar0, 240)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    ExecWait(N(EVS_ApproachPeach))
    ExecWait(N(EVS_PickUpPeach))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_0158)
    ExecWait(N(EVS_CarryPeachAway))
    Wait(20 * DT)
    Call(SetNpcSpeed, NPC_PARTNER, Float(6.0))
    Call(NpcFlyTo, NPC_PARTNER, 460, -10, -130, 0, 0, EASING_LINEAR)
    Wait(60 * DT)
    Call(FadeOutMusic, 0, 1000 * DT)
    ExecWait(N(EVS_EndPeachChapter6))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
