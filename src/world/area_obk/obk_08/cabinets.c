#include "obk_08.h"
#include "effects.h"
#include "sprite/player.h"

#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/WorldLakilester.h"

#define KNOCK_DOWN_MAP_VAR MV_Knockdown
#include "world/common/complete/KnockDownPlayer.inc.c"

API_CALLABLE(N(DamagePlayer1HP)) {
    if (gPlayerData.curHP <= 1) {
        return ApiStatus_DONE2;
    }
    gPlayerData.curHP--;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_GetPartnerInUseAnims) = {
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Set(LVarA, ANIM_WorldGoombario_Run)
            Set(LVarB, ANIM_WorldGoombario_Idle)
        CaseEq(PARTNER_KOOPER)
            Set(LVarA, ANIM_WorldKooper_Run)
            Set(LVarB, ANIM_WorldKooper_Idle)
        CaseEq(PARTNER_BOMBETTE)
            Set(LVarA, ANIM_WorldBombette_Run)
            Set(LVarB, ANIM_WorldBombette_Idle)
        CaseEq(PARTNER_PARAKARRY)
            Set(LVarA, ANIM_WorldParakarry_Run)
            Set(LVarB, ANIM_WorldParakarry_Idle)
        CaseEq(PARTNER_BOW)
            Set(LVarA, ANIM_WorldBow_Run)
            Set(LVarB, ANIM_WorldBow_Idle)
        CaseEq(PARTNER_WATT)
            Set(LVarA, ANIM_WorldWatt_Run)
            Set(LVarB, ANIM_WorldWatt_Idle)
        CaseEq(PARTNER_SUSHIE)
            Set(LVarA, ANIM_WorldSushie_Run)
            Set(LVarB, ANIM_WorldSushie_Idle)
        CaseEq(PARTNER_LAKILESTER)
            Set(LVarA, ANIM_WorldLakilester_Run)
            Set(LVarB, ANIM_WorldLakilester_Idle)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_CrushPlayer) = {
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        ExecWait(N(EVS_GetPartnerInUseAnims))
        Call(SetNpcAnimation, NPC_PARTNER, LVarA)
        Call(NpcMoveTo, NPC_PARTNER, -93, LVar2, 15)
        ExecWait(N(EVS_GetPartnerInUseAnims))
        Call(SetNpcAnimation, NPC_PARTNER, LVarB)
        Wait(15)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EndThread
    Call(DisablePlayerPhysics, TRUE)
    Wait(8)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Wait(13)
    Call(GetPlayerPos, MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    Call(N(KnockdownCreate), SPR_Mario1, 37) //TODO hardcoded player raster ID
    Call(N(KnockdownSetPos), MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    Wait(1)
    Call(SetPlayerPos, 0, 1000, 0) // unusual dispose location
    Call(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    Label(0)
    Call(UpdateLerp)
    Call(N(KnockdownSetRot), LVar0, 0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Add(MV_KnockdownPosY, 3)
    Call(N(KnockdownSetPos), MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    Call(N(DamagePlayer1HP))
    Return
    End
};

EvtScript N(EVS_RestorePlayer) = {
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 270, 0)
    Wait(15)
    Sub(MV_KnockdownPosY, 3)
    Call(N(KnockdownSetPos), MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    Call(MakeLerp, 90, 0, 15, EASING_QUADRATIC_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(N(KnockdownSetRot), LVar0, 0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Call(N(KnockdownDestroy))
    Call(SetPlayerPos, MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_MarioW3_ShakeHeadHard)
    Wait(25)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Return
    End
};

Vec2i N(DustEmitters_FarCabinet)[] = {
    { -220, -140 },
    { -220, -115 },
    { -220,  -90 },
    { -220,  -65 },
    { -220,  -40 },
    { -195,  -40 },
    { -170,  -40 },
    { -145,  -40 },
    { -120, -140 },
    { -120, -115 },
    { -120,  -90 },
    { -120,  -65 },
    { -120,  -40 },
    { -145,  -40 },
    { -170,  -40 },
    { -195,  -40 },
};

Vec2i N(DustEmitters_NearCabinet)[] = {
    { -220,  60 },
    { -220,  85 },
    { -220, 110 },
    { -220, 135 },
    { -220, 160 },
    { -195, 160 },
    { -170, 160 },
    { -145, 160 },
    { -120,  60 },
    { -120,  85 },
    { -120, 110 },
    { -120, 135 },
    { -120, 160 },
    { -145, 160 },
    { -170, 160 },
    { -195, 160 },
};

EvtScript N(EVS_MiddleCabinet_OpenDoors) = {
    Call(PlaySoundAtCollider, COLLIDER_tansu2, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 120, 15, EASING_QUARTIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_t_1, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_t_2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_MiddleCabinet_CloseDoors) = {
    Call(MakeLerp, 120, 0, 15, EASING_QUARTIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_t_1, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_t_2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tansu2, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_Interact_MiddleCabinet) = {
    IfLt(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        Call(DeleteTrigger, MV_Trigger_NearCabinet)
        Call(DeleteTrigger, MV_Trigger_MidCabinet)
        Call(DeleteTrigger, MV_Trigger_FarCabinet)
        Exec(N(EVS_Scene_BoosUnleashed))
        ExecWait(N(EVS_MiddleCabinet_OpenDoors))
        Set(AF_OBK08_KeepAwayStarted, TRUE)
        Wait(50)
        ExecWait(N(EVS_MiddleCabinet_CloseDoors))
    Else
        Call(DisablePlayerInput, TRUE)
        Call(InterruptUsePartner)
        ExecWait(N(EVS_MiddleCabinet_OpenDoors))
        Wait(20)
        ExecWait(N(EVS_MiddleCabinet_CloseDoors))
        Call(DisablePlayerInput, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_Interact_NearCabinet) = {
    Label(3)
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Loop(3)
        Call(PlaySoundAtCollider, COLLIDER_tansu1, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        Call(RotateModel, MODEL_tansu1, -1, 1, 0, 0)
        Wait(2)
        Call(RotateModel, MODEL_tansu1, 0, 1, 0, 0)
        Wait(1)
        Call(PlaySoundAtCollider, COLLIDER_tansu1, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        Call(TranslateModel, MODEL_tansu1, 0, 0, 100)
        Call(RotateModel, MODEL_tansu1, 1, 1, 0, 0)
        Call(TranslateModel, MODEL_tansu1, 0, 0, -100)
        Wait(2)
        Call(RotateModel, MODEL_tansu1, 0, 1, 0, 0)
        Wait(1)
    EndLoop
    Exec(N(EVS_CrushPlayer))
    Call(MakeLerp, 0, -90, 30, EASING_QUARTIC_IN)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_tansu1, LVar0, 0, 0, 1)
    Call(UpdateColliderTransform, COLLIDER_tansu1)
    Call(UpdateColliderTransform, COLLIDER_o372)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_tansu1, SOUND_OBK_CABINET_CRASH, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.5))
    EndThread
    UseBuf(Ref(N(DustEmitters_NearCabinet)))
    Loop(16)
        BufRead2(LVar0, LVar1)
        PlayEffect(EFFECT_LANDING_DUST, 2, LVar0, 0, LVar1, 0)
    EndLoop
    Wait(60)
    Call(MakeLerp, -90, 0, 10, EASING_LINEAR)
    Label(15)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_tansu1, LVar0, 0, 0, 1)
    Call(UpdateColliderTransform, COLLIDER_tansu1)
    Call(UpdateColliderTransform, COLLIDER_o372)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(15)
    EndIf
    ExecWait(N(EVS_RestorePlayer))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Interact_FarCabinet) = {
    Label(5)
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Loop(5)
        Call(PlaySoundAtCollider, COLLIDER_tansu3, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        Call(RotateModel, MODEL_tansu3, -1, 1, 0, 0)
        Wait(2)
        Call(RotateModel, MODEL_tansu3, 0, 1, 0, 0)
        Wait(1)
        Call(PlaySoundAtCollider, COLLIDER_tansu3, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        Call(TranslateModel, MODEL_tansu3, 0, 0, 100)
        Call(RotateModel, MODEL_tansu3, 1, 1, 0, 0)
        Call(TranslateModel, MODEL_tansu3, 0, 0, -100)
        Wait(2)
        Call(RotateModel, MODEL_tansu3, 0, 1, 0, 0)
        Wait(1)
    EndLoop
    Exec(N(EVS_CrushPlayer))
    Call(MakeLerp, 0, -90, 30, EASING_QUARTIC_IN)
    Label(20)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_tansu3, LVar0, 0, 0, 1)
    Call(UpdateColliderTransform, COLLIDER_tansu3)
    Call(UpdateColliderTransform, COLLIDER_o373)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(20)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_tansu3, SOUND_OBK_CABINET_CRASH, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.5))
    EndThread
    UseBuf(Ref(N(DustEmitters_FarCabinet)))
    Loop(16)
        BufRead2(LVar0, LVar1)
        PlayEffect(EFFECT_LANDING_DUST, 2, LVar0, 0, LVar1, 0)
    EndLoop
    Wait(60)
    Call(MakeLerp, -90, 0, 10, EASING_LINEAR)
    Label(25)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_tansu3, LVar0, 0, 0, 1)
    Call(UpdateColliderTransform, COLLIDER_tansu3)
    Call(UpdateColliderTransform, COLLIDER_o373)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(25)
    EndIf
    ExecWait(N(EVS_RestorePlayer))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupCabinets) = {
    Call(ParentColliderToModel, COLLIDER_tansu1, MODEL_tansu1)
    Call(ParentColliderToModel, COLLIDER_o372, MODEL_tansu1)
    Call(ParentColliderToModel, COLLIDER_tansu3, MODEL_tansu3)
    Call(ParentColliderToModel, COLLIDER_o373, MODEL_tansu3)
    BindTrigger(Ref(N(EVS_Interact_NearCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu1, 1, MV_Trigger_NearCabinet)
    BindTrigger(Ref(N(EVS_Interact_MiddleCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu2, 1, MV_Trigger_MidCabinet)
    BindTrigger(Ref(N(EVS_Interact_FarCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu3, 1, MV_Trigger_FarCabinet)
    Return
    End
};

EvtScript N(EVS_BindCabinetTriggers) = {
    BindTrigger(Ref(N(EVS_Interact_NearCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu1, 1, MV_Trigger_NearCabinet)
    BindTrigger(Ref(N(EVS_Interact_MiddleCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu2, 1, MV_Trigger_MidCabinet)
    BindTrigger(Ref(N(EVS_Interact_FarCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu3, 1, MV_Trigger_FarCabinet)
    Return
    End
};
