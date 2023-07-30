#include "sam_11.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnIceShards)) {
    EffectInstance* effect;
    f32 a5;
    f32 posZ;
    f32 posX;
    f32 t1;
    f32 t2;
    s32 i;

    for (i = 0; i < 24; i++) {
        posX = t1 = ((i % 6) * 40) - 100;
        posZ = t2 = ((i / 6) * 40) - 100;

        a5 = 0.0f; // TODO required to match;
        posX += 0.0f;
        posZ += 250.0f;

        t1 *= 0.1;
        t2 *= 0.1;

        effect = fx_ice_shard(i & 1, posX, -10.0f, posZ, 2.0 * ((i & 3) + 1.0), ((i & 3) * 4) + 30);

        a5 = 4.0f;
        effect->data.iceShard->animFrame = 0.0f;
        effect->data.iceShard->animRate = (rand_int(10) * 0.2) + 0.1;
        effect->data.iceShard->rot = i * 35;
        effect->data.iceShard->angularVel = rand_int(10) - 5;
        effect->data.iceShard->vel.x = t1;
        effect->data.iceShard->vel.y = a5;
        effect->data.iceShard->vel.z = t2;
        effect->data.iceShard->gravAccel = -0.1f;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241FB0_D3C580)) {
    script->varTable[10] = 0;
    if (gCollisionStatus.curFloor == COLLIDER_suimen) {
        script->varTable[10] = 1;
    }
    if (gCollisionStatus.lastTouchedFloor == COLLIDER_suimen) {
        script->varTable[10] = 1;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetDraggingPlayerPosY)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x = playerStatus->pos.x;
    f32 y = playerStatus->pos.y + 10.0f;
    f32 z = playerStatus->pos.z;
    f32 hitDepth = 40.0f;

    npc_raycast_down_sides(0, &x, &y, &z, &hitDepth);
    playerStatus->pos.x = x;
    playerStatus->pos.y = y;
    playerStatus->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetBombetteExplodeGround)) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner = get_npc_safe(NPC_PARTNER);
    s32 colliderID = NO_COLLIDER;

    if (gCollisionStatus.bombetteExploded >= 0) {
        f32 depth = 11.0f;
        f32 x = partner->pos.x;
        f32 y = partner->pos.y + depth;
        f32 z = partner->pos.z;

        depth = 12.0f;
        if (npc_raycast_down_around(partner->collisionChannel, &x, &y, &z, &depth,
            partner->yaw, partner->collisionDiameter) && depth <= 12.0f)
        {
            colliderID = NpcHitQueryColliderID;
        }
    }
    evt_set_variable(script, *args++, colliderID);
    return ApiStatus_DONE2;
}

s32 N(IcebergBobbingOffsets)[] = {
    0,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,  1,
    0, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1,
    0x8000,
};

EvtScript N(EVS_UpdateIceberg) = {
    EVT_CALL(RandInt, 10, LVar0)
    EVT_WAIT(LVar0)
    EVT_USE_BUF(EVT_PTR(N(IcebergBobbingOffsets)))
    EVT_LOOP(0)
        EVT_BUF_READ1(LVar0)
        EVT_IF_EQ(LVar0, 0x8000)
            EVT_CALL(RandInt, 10, LVar0)
            EVT_WAIT(LVar0)
            EVT_USE_BUF(EVT_PTR(N(IcebergBobbingOffsets)))
            EVT_BUF_READ1(LVar0)
        EVT_END_IF
        EVT_CALL(TranslateModel, LVarA, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupIcebergs) = {
    EVT_SET(LVarA, MODEL_o773)
    EVT_EXEC(N(EVS_UpdateIceberg))
    EVT_SET(LVarA, MODEL_o775)
    EVT_EXEC(N(EVS_UpdateIceberg))
    EVT_SET(LVarA, MODEL_o777)
    EVT_EXEC(N(EVS_UpdateIceberg))
    EVT_SET(LVarA, MODEL_o778)
    EVT_EXEC(N(EVS_UpdateIceberg))
    EVT_SET(LVarA, MODEL_o779)
    EVT_EXEC(N(EVS_UpdateIceberg))
    EVT_SET(LVarA, MODEL_o780)
    EVT_EXEC(N(EVS_UpdateIceberg))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DamageFrozenPond_Before) = {
    EVT_IF_EQ(MV_CantDamagePond, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_CantDamagePond, TRUE)
    EVT_ADD(GB_SAM11_FrozenPondDamage, 1)
    EVT_SWITCH(GB_SAM11_FrozenPondDamage)
        EVT_CASE_EQ(1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_suimen, SOUND_389, 0)
            EVT_CALL(EnableModel, MODEL_ice01, FALSE)
            EVT_CALL(EnableModel, MODEL_ice02, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Run)
            EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar7, LVar8, LVar9)
            EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(9.0))
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            EVT_CALL(GetAngleToNPC, NPC_PenguinPatrol, LVar0)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(40.0), LVar0)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar1, LVar3, 0)
            EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B6)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar7, LVar9, 0)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(2)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_suimen, SOUND_38A, 0)
            EVT_CALL(EnableModel, MODEL_ice02, FALSE)
            EVT_CALL(EnableModel, MODEL_ice03, TRUE)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(PlaySoundAtNpc, NPC_PenguinPatrol, SOUND_397, 0)
            EVT_END_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Run)
            EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar7, LVar8, LVar9)
            EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(9.0))
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            EVT_CALL(GetAngleToNPC, NPC_PenguinPatrol, LVar0)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(40.0), LVar0)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar1, LVar3, 0)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B7)
            EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
            EVT_THREAD
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(PlaySoundAtPlayer, SOUND_398, 0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                EVT_SET(MF_Unk_01, FALSE)
                EVT_LOOP(0)
                    EVT_IF_EQ(MF_Unk_01, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_CALL(GetAngleToPlayer, NPC_PenguinPatrol, LVar0)
                    EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar1, LVar2, LVar3)
                    EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVar0)
                    EVT_CALL(SetPlayerPos, LVar1, 0, LVar3)
                    EVT_CALL(N(SetDraggingPlayerPosY))
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(3.8))
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -450, 0, 0)
            EVT_SET(MF_Unk_01, TRUE)
            EVT_CALL(StopSound, SOUND_398)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Surprise)
            EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B8)
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 45)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
            EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, 270, 0)
            EVT_WAIT(10)
            EVT_ADD(LVar0, -20)
            EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtNpc, NPC_PenguinPatrol, SOUND_390, 0)
            EVT_THREAD
                EVT_SET(MV_ThrownOut, 1)
                EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                EVT_CALL(PlayerJump1, -680, 50, 0, 30)
            EVT_END_THREAD
            EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
            EVT_WAIT(15)
            EVT_SET(GB_SAM11_FrozenPondDamage, 0)
            EVT_CALL(GotoMap, EVT_PTR("sam_02"), sam_02_ENTRY_3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlastPond_Before) = {
    EVT_CALL(N(GetBombetteExplodeGround), LVar0)
    EVT_IF_NE(LVar0, COLLIDER_suimen)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, -280)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar0, 280)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar2, -60)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar2, 460)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_DamageFrozenPond_Before))
    EVT_WAIT(60)
    EVT_SET(MV_CantDamagePond, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TouchPond_Before) = {
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_IF_NE(LVar0, ACTION_STATE_TORNADO_POUND)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_DamageFrozenPond_Before))
    EVT_LABEL(0)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_SET(MV_CantDamagePond, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DamageFrozenPond_After) = {
    EVT_IF_EQ(MV_CantDamagePond, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_CantDamagePond, TRUE)
    EVT_ADD(GB_SAM11_FrozenPondDamage, 1)
    EVT_IF_NE(GB_SAM11_FrozenPondDamage, 3)
        EVT_SWITCH(GB_SAM11_FrozenPondDamage)
            EVT_CASE_EQ(1)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_suimen, SOUND_389, 0)
                EVT_CALL(EnableModel, MODEL_ice01, FALSE)
                EVT_CALL(EnableModel, MODEL_ice02, TRUE)
            EVT_CASE_EQ(2)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_suimen, SOUND_38A, 0)
                EVT_CALL(EnableModel, MODEL_ice02, FALSE)
                EVT_CALL(EnableModel, MODEL_ice03, TRUE)
        EVT_END_SWITCH
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
    EVT_CALL(IsPlayerWithin, 0, 210, 240, LVarA)
    EVT_IF_EQ(LVarA, 1)
        EVT_THREAD
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.5))
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
            EVT_CALL(PlayerJump1, 247, 0, 225, 30)
            EVT_CALL(PlayerJump1, 257, 0, 225, 8)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT(1)
            EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_302, 0)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.5))
            EVT_CALL(NpcJump1, NPC_PARTNER, 265, 0, 225, 30)
            EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_162, 0)
            EVT_CALL(NpcJump1, NPC_PARTNER, 275, 0, 225, 8)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_LOOP(30)
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar1, LVar5)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar1, LVar5)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_38B, 0, 0, 60, 220)
    EVT_CALL(N(SpawnIceShards))
    EVT_CALL(EnableModel, MODEL_ice03, FALSE)
    EVT_CALL(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_VISIBLE)
    EVT_CALL(EnableGroup, MODEL_sui, TRUE)
    EVT_CALL(EnableGroup, MODEL_g279, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o583, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,   60,   60, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_LoadPondAnimation))
    EVT_WAIT(60)
    EVT_CALL(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_HIDDEN)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitp, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o356, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilitp, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o356, COLLIDER_FLAG_80000)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitp, COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_80000)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suimen, SURFACE_TYPE_WATER)
    EVT_EXEC(N(EVS_SetupIcebergs))
    EVT_SET(GB_SAM11_FrozenPondDamage, 4)
    EVT_SET(GB_StoryProgress, STORY_CH7_SHATTERED_FROZEN_POND)
    EVT_IF_EQ(LVarA, 1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_DustOff)
        EVT_WAIT(7)
        EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, 0)
        EVT_WAIT(15)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlastPond_After) = {
    EVT_CALL(N(GetBombetteExplodeGround), LVar0)
    EVT_IF_NE(LVar0, COLLIDER_suimen)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, -280)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar0, 280)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar2, -60)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar2, 460)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_DamageFrozenPond_After))
    EVT_WAIT(60)
    EVT_SET(MV_CantDamagePond, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TouchPond_After) = {
    EVT_IF_EQ(GB_SAM11_FrozenPondDamage, 4)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_IF_NE(LVar0, ACTION_STATE_TORNADO_POUND)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_DamageFrozenPond_After))
    EVT_LABEL(0)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_SET(MV_CantDamagePond, FALSE)
    EVT_RETURN
    EVT_END
};

// @bug radius is f32 here, should be s32
BombTriggerF N(BombTrigger_Pond) = {
    .pos = { 0.0f, -10.0f, 220.0f },
    .radius = 300.0
};

EvtScript N(EVS_SetupPond) = {
    EVT_CALL(EnableGroup, MODEL_sui, FALSE)
    EVT_CALL(EnableGroup, MODEL_g279, FALSE)
    EVT_CALL(EnableModel, MODEL_ice00, FALSE)
    EVT_CALL(EnableModel, MODEL_ice01, FALSE)
    EVT_CALL(EnableModel, MODEL_ice02, FALSE)
    EVT_CALL(EnableModel, MODEL_ice03, FALSE)
    EVT_CALL(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_HIDDEN)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_SHATTERED_FROZEN_POND)
        EVT_SWITCH(GB_SAM11_FrozenPondDamage)
            EVT_CASE_EQ(0)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(EnableModel, MODEL_ice01, TRUE)
            EVT_CASE_EQ(1)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(EnableModel, MODEL_ice02, TRUE)
            EVT_CASE_EQ(2)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(EnableModel, MODEL_ice03, TRUE)
            EVT_CASE_EQ(3)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_VISIBLE)
            EVT_CASE_EQ(4)
                EVT_CALL(EnableGroup, MODEL_sui, TRUE)
                EVT_CALL(EnableGroup, MODEL_g279, TRUE)
                EVT_CALL(EnableTexPanning, MODEL_o583, TRUE)
                EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,   60,   60, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
                    EVT_EXEC(N(EVS_UpdateTexturePan))
                EVT_END_THREAD
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
                EVT_EXEC(N(EVS_SetupIcebergs))
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_sui, TRUE)
        EVT_CALL(EnableGroup, MODEL_g279, TRUE)
        EVT_CALL(EnableTexPanning, MODEL_o583, TRUE)
        EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,   60,   60, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
            EVT_EXEC(N(EVS_UpdateTexturePan))
        EVT_END_THREAD
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
        EVT_EXEC(N(EVS_SetupIcebergs))
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastPond_Before)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombTrigger_Pond)), 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TouchPond_Before)), TRIGGER_FLOOR_TOUCH, COLLIDER_suimen, 1, 0)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastPond_After)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombTrigger_Pond)), 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TouchPond_After)), TRIGGER_FLOOR_TOUCH, COLLIDER_suimen, 1, 0)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_SHATTERED_FROZEN_POND)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitp, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o356, SURFACE_TYPE_DOCK_WALL)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilitp, SURFACE_TYPE_DOCK_WALL)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o356, COLLIDER_FLAG_80000)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitp, COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_80000)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
