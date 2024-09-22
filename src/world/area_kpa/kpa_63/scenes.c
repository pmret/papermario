#include "kpa_63.h"

API_CALLABLE(N(SetPassengerPos)) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner;
    f32 x, y, z;
    f32 yBase;
    f32 angle;
    f32 radius;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        yBase = evt_get_variable(script, *args++);
        angle = evt_get_variable(script, *args++);
        switch (script->functionTemp[0]) {
            case 0:
                radius = 0.0f;
                break;
            case 1:
                radius = 5.0f;
                break;
        }
    }

    x = (sin_deg(angle) * radius) + -120.0f;
    y = yBase - 11.0f;
    z = (cos_deg(angle) * radius) + 225.0f;

    switch (script->functionTemp[0]) {
        case 0:
            gPlayerStatus.pos.x = x;
            gPlayerStatus.pos.y = y;
            gPlayerStatus.pos.z = z;
            break;
        case 1:
            partner = get_npc_safe(NPC_PARTNER);
            if (partner != NULL) {
                partner->pos.x = x;
                partner->pos.y = y;
                partner->pos.z = z;
                partner->colliderPos.x = partner->pos.x;
                partner->colliderPos.y = partner->pos.y;
                partner->colliderPos.z = partner->pos.z;
                partner->flags |= NPC_FLAG_DIRTY_SHADOW;
            }
            break;
        default:
            return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePassengers) = {
    IfEq(MV_PlayerOnBoard, TRUE)
        Call(N(SetPassengerPos), 0, LVar3, MV_Starship_Yaw)
    EndIf
    IfEq(MV_PartnerOnBoard, TRUE)
        Call(N(SetPassengerPos), 1, LVar3, MV_Starship_Yaw)
    EndIf
    Return
    End
};

EvtScript N(EVS_Starship_Update) = {
    Label(0)
    Call(MakeLerp, 0, 100, 30, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar3, LVar0)
        MulF(LVar3, Float(0.1))
        AddF(LVar3, MV_Starship_PosY)
        Call(TranslateGroup, MODEL_g55, 0, LVar3, 0)
        Call(RotateGroup, MODEL_g55, MV_Starship_Yaw, 0, 1, 0)
        Exec(N(EVS_UpdatePassengers))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 100, 0, 30, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar3, LVar0)
        MulF(LVar3, Float(0.1))
        AddF(LVar3, MV_Starship_PosY)
        Call(TranslateGroup, MODEL_g55, 0, LVar3, 0)
        Call(RotateGroup, MODEL_g55, MV_Starship_Yaw, 0, 1, 0)
        Exec(N(EVS_UpdatePassengers))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Goto(0)
    Return
    End
};

EvtScript N(EVS_Starship_Depart) = {
    Call(GetPartnerInUse, LVar9)
    IfNe(LVar9, PARTNER_NONE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(HidePlayerShadow, TRUE)
    Call(GetModelCenter, MODEL_o308)
    Add(LVar0, -5)
    Call(SetPlayerJumpscale, 0)
    Call(PlayerJump2, LVar0, LVar1, LVar2, 2)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Set(MV_PlayerOnBoard, TRUE)
    Call(InterpPlayerYaw, 225, 0)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Add(LVar2, 10)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcJumpscale, NPC_PARTNER, 1)
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 15)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Set(MV_PartnerOnBoard, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    Wait(10)
    Call(ShowMessageAtScreenPos, MSG_Menus_0188, 160, 40)
    Call(ShowChoice, MSG_Choice_000C)
    Call(CloseMessage)
    IfEq(LVar0, 1)
        Call(DisablePlayerPhysics, FALSE)
        Call(SetPlayerJumpscale, 2)
        Set(MV_PlayerOnBoard, FALSE)
        Call(PlayerJump, -50, 0, 225, 13)
        Call(HidePlayerShadow, FALSE)
        Call(SetPlayerActionState, ACTION_STATE_LAND)
        Set(MV_PartnerOnBoard, FALSE)
        Call(PartnerIsFlying, LVar0)
        IfEq(LVar0, TRUE)
            Wait(10)
            Call(SetNpcJumpscale, NPC_PARTNER, 2)
            Call(NpcJump0, NPC_PARTNER, -65, 0, 225, 13)
        EndIf
        Call(EnableNpcShadow, NPC_PARTNER, TRUE)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(SetMusicTrack, 0, SONG_STARSHIP_THEME, 1, 8)
    Thread
        Call(PlaySoundAtPlayer, SOUND_STARSHIP_TAKEOFF_SHORT, SOUND_SPACE_DEFAULT)
        Set(LVar2, MV_Starship_PosY)
        Call(MakeLerp, 0, -110, 60, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Add(LVar0, LVar2)
            Set(MV_Starship_PosY, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(50)
    Call(GotoMap, Ref("kpa_60"), kpa_60_ENTRY_5)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Starship_Arrive) = {
    Set(MV_Starship_PosY, -100)
    Set(MV_Starship_Yaw, 180)
    Set(MV_PlayerOnBoard, TRUE)
    Set(MV_PartnerOnBoard, TRUE)
    Call(InterpPlayerYaw, 90, 0)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, -120, 0, 230)
    Call(SetPanTarget, CAM_DEFAULT, -120, 0, 230)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(HidePlayerShadow, FALSE)
    Call(EnableNpcShadow, NPC_PARTNER, TRUE)
    ExecGetTID(N(EVS_UpdatePassengers), LVar9)
    Call(PlaySoundAtPlayer, SOUND_STARSHIP_ARRIVE, SOUND_SPACE_DEFAULT)
    Thread
        Call(MakeLerp, -100, 0, 60, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_PosY, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(20)
    Thread
        Call(InterpPlayerYaw, 270, 40)
    EndThread
    Call(MakeLerp, 180, 0, 60, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_Starship_Yaw, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar9)
    Call(SetPlayerJumpscale, 2)
    Set(MV_PlayerOnBoard, FALSE)
    Call(PlayerJump, -50, 0, 225, 13)
    Call(HidePlayerShadow, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Set(MV_PartnerOnBoard, FALSE)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, TRUE)
        Wait(10)
        Call(SetNpcJumpscale, NPC_PARTNER, 2)
        Call(NpcJump0, NPC_PARTNER, -65, 0, 225, 13)
    EndIf
    Call(EnableNpcShadow, NPC_PARTNER, TRUE)
    Call(EnablePartnerAI)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Wait(10)
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        Set(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
    EndIf
    Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    Thread
        Wait(30)
        Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
    EndThread
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupStarship) = {
    Exec(N(EVS_Starship_Update))
    Call(ParentColliderToModel, COLLIDER_o400, MODEL_o308)
    Loop(0)
        Call(UpdateColliderTransform, COLLIDER_o400)
        Wait(1)
    EndLoop
    Return
    End
};
