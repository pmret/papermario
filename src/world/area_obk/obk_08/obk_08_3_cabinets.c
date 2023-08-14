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
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_SET(LVarA, ANIM_WorldGoombario_Run)
            EVT_SET(LVarB, ANIM_WorldGoombario_Idle)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_SET(LVarA, ANIM_WorldKooper_Run)
            EVT_SET(LVarB, ANIM_WorldKooper_Idle)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_SET(LVarA, ANIM_WorldBombette_Run)
            EVT_SET(LVarB, ANIM_WorldBombette_Idle)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_SET(LVarA, ANIM_WorldParakarry_Run)
            EVT_SET(LVarB, ANIM_WorldParakarry_Idle)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_SET(LVarA, ANIM_WorldBow_Run)
            EVT_SET(LVarB, ANIM_WorldBow_Idle)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_SET(LVarA, ANIM_WorldWatt_Run)
            EVT_SET(LVarB, ANIM_WorldWatt_Idle)
        EVT_CASE_EQ(PARTNER_SUSHIE)
            EVT_SET(LVarA, ANIM_WorldSushie_Run)
            EVT_SET(LVarB, ANIM_WorldSushie_Idle)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_SET(LVarA, ANIM_WorldLakilester_Run)
            EVT_SET(LVarB, ANIM_WorldLakilester_Idle)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CrushPlayer) = {
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_EXEC_WAIT(N(EVS_GetPartnerInUseAnims))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, LVarA)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -93, LVar2, 15)
        EVT_EXEC_WAIT(N(EVS_GetPartnerInUseAnims))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, LVarB)
        EVT_WAIT(15)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(8)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_WAIT(13)
    EVT_CALL(GetPlayerPos, MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    EVT_CALL(N(KnockdownCreate), SPR_Mario1, 37) //TODO hardcoded player raster ID
    EVT_CALL(N(KnockdownSetPos), MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerPos, 0, 1000, 0) // unusual dispose location
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(KnockdownSetRot), LVar0, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_ADD(MV_KnockdownPosY, 3)
    EVT_CALL(N(KnockdownSetPos), MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    EVT_CALL(N(DamagePlayer1HP))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RestorePlayer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(15)
    EVT_SUB(MV_KnockdownPosY, 3)
    EVT_CALL(N(KnockdownSetPos), MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    EVT_CALL(MakeLerp, 90, 0, 15, EASING_QUADRATIC_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(KnockdownSetRot), LVar0, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(N(KnockdownDestroy))
    EVT_CALL(SetPlayerPos, MV_KnockdownPosX, MV_KnockdownPosY, MV_KnockdownPosZ)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW3_ShakeHeadHard)
    EVT_WAIT(25)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu2, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 120, 15, EASING_QUARTIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t_1, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_t_2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MiddleCabinet_CloseDoors) = {
    EVT_CALL(MakeLerp, 120, 0, 15, EASING_QUARTIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_t_1, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_t_2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu2, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_MiddleCabinet) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(DeleteTrigger, MV_Trigger_NearCabinet)
        EVT_CALL(DeleteTrigger, MV_Trigger_MidCabinet)
        EVT_CALL(DeleteTrigger, MV_Trigger_FarCabinet)
        EVT_EXEC(N(EVS_Scene_BoosUnleashed))
        EVT_EXEC_WAIT(N(EVS_MiddleCabinet_OpenDoors))
        EVT_SET(AF_OBK08_KeepAwayStarted, TRUE)
        EVT_WAIT(50)
        EVT_EXEC_WAIT(N(EVS_MiddleCabinet_CloseDoors))
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(InterruptUsePartner)
        EVT_EXEC_WAIT(N(EVS_MiddleCabinet_OpenDoors))
        EVT_WAIT(20)
        EVT_EXEC_WAIT(N(EVS_MiddleCabinet_CloseDoors))
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_NearCabinet) = {
    EVT_LABEL(3)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_LOOP(3)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu1, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        EVT_CALL(RotateModel, MODEL_tansu1, -1, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(RotateModel, MODEL_tansu1, 0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu1, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        EVT_CALL(TranslateModel, MODEL_tansu1, 0, 0, 100)
        EVT_CALL(RotateModel, MODEL_tansu1, 1, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_tansu1, 0, 0, -100)
        EVT_WAIT(2)
        EVT_CALL(RotateModel, MODEL_tansu1, 0, 1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_CrushPlayer))
    EVT_CALL(MakeLerp, 0, -90, 30, EASING_QUARTIC_IN)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_tansu1, LVar0, 0, 0, 1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_tansu1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o372)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu1, SOUND_OBK_CABINET_CRASH, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_USE_BUF(EVT_PTR(N(DustEmitters_NearCabinet)))
    EVT_LOOP(16)
        EVT_BUF_READ2(LVar0, LVar1)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 2, LVar0, 0, LVar1, 0)
    EVT_END_LOOP
    EVT_WAIT(60)
    EVT_CALL(MakeLerp, -90, 0, 10, EASING_LINEAR)
    EVT_LABEL(15)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_tansu1, LVar0, 0, 0, 1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_tansu1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o372)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(15)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_RestorePlayer))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_FarCabinet) = {
    EVT_LABEL(5)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_LOOP(5)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu3, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        EVT_CALL(RotateModel, MODEL_tansu3, -1, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(RotateModel, MODEL_tansu3, 0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu3, SOUND_OBK_CHECK_CABINET, SOUND_SPACE_DEFAULT)
        EVT_CALL(TranslateModel, MODEL_tansu3, 0, 0, 100)
        EVT_CALL(RotateModel, MODEL_tansu3, 1, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_tansu3, 0, 0, -100)
        EVT_WAIT(2)
        EVT_CALL(RotateModel, MODEL_tansu3, 0, 1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_CrushPlayer))
    EVT_CALL(MakeLerp, 0, -90, 30, EASING_QUARTIC_IN)
    EVT_LABEL(20)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_tansu3, LVar0, 0, 0, 1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_tansu3)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o373)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tansu3, SOUND_OBK_CABINET_CRASH, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_USE_BUF(EVT_PTR(N(DustEmitters_FarCabinet)))
    EVT_LOOP(16)
        EVT_BUF_READ2(LVar0, LVar1)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 2, LVar0, 0, LVar1, 0)
    EVT_END_LOOP
    EVT_WAIT(60)
    EVT_CALL(MakeLerp, -90, 0, 10, EASING_LINEAR)
    EVT_LABEL(25)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_tansu3, LVar0, 0, 0, 1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_tansu3)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o373)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(25)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_RestorePlayer))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupCabinets) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_tansu1, MODEL_tansu1)
    EVT_CALL(ParentColliderToModel, COLLIDER_o372, MODEL_tansu1)
    EVT_CALL(ParentColliderToModel, COLLIDER_tansu3, MODEL_tansu3)
    EVT_CALL(ParentColliderToModel, COLLIDER_o373, MODEL_tansu3)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_NearCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu1, 1, MV_Trigger_NearCabinet)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_MiddleCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu2, 1, MV_Trigger_MidCabinet)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_FarCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu3, 1, MV_Trigger_FarCabinet)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindCabinetTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_NearCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu1, 1, MV_Trigger_NearCabinet)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_MiddleCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu2, 1, MV_Trigger_MidCabinet)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_FarCabinet)), TRIGGER_WALL_PRESS_A, COLLIDER_tansu3, 1, MV_Trigger_FarCabinet)
    EVT_RETURN
    EVT_END
};
