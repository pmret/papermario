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
    Call(RandInt, 10, LVar0)
    Wait(LVar0)
    UseBuf(Ref(N(IcebergBobbingOffsets)))
    Loop(0)
        BufRead1(LVar0)
        IfEq(LVar0, 0x8000)
            Call(RandInt, 10, LVar0)
            Wait(LVar0)
            UseBuf(Ref(N(IcebergBobbingOffsets)))
            BufRead1(LVar0)
        EndIf
        Call(TranslateModel, LVarA, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupIcebergs) = {
    Set(LVarA, MODEL_o773)
    Exec(N(EVS_UpdateIceberg))
    Set(LVarA, MODEL_o775)
    Exec(N(EVS_UpdateIceberg))
    Set(LVarA, MODEL_o777)
    Exec(N(EVS_UpdateIceberg))
    Set(LVarA, MODEL_o778)
    Exec(N(EVS_UpdateIceberg))
    Set(LVarA, MODEL_o779)
    Exec(N(EVS_UpdateIceberg))
    Set(LVarA, MODEL_o780)
    Exec(N(EVS_UpdateIceberg))
    Return
    End
};

EvtScript N(EVS_DamageFrozenPond_Before) = {
    IfEq(MV_CantDamagePond, TRUE)
        Return
    EndIf
    Set(MV_CantDamagePond, TRUE)
    Add(GB_SAM11_FrozenPondDamage, 1)
    Switch(GB_SAM11_FrozenPondDamage)
        CaseEq(1)
            Call(DisablePlayerInput, TRUE)
            Call(PlaySoundAtCollider, COLLIDER_suimen, SOUND_SAM_POND_CRACK_1, 0)
            Call(EnableModel, MODEL_ice01, FALSE)
            Call(EnableModel, MODEL_ice02, TRUE)
            Call(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Run)
            Call(GetNpcPos, NPC_PenguinPatrol, LVar7, LVar8, LVar9)
            Call(SetNpcSpeed, NPC_PenguinPatrol, Float(9.0))
            Call(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            Call(GetAngleToNPC, NPC_PenguinPatrol, LVar0)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Call(AddVectorPolar, LVar1, LVar3, Float(40.0), LVar0)
            Call(NpcMoveTo, NPC_PenguinPatrol, LVar1, LVar3, 0)
            Call(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
            Call(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B6)
            Call(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            Call(NpcMoveTo, NPC_PenguinPatrol, LVar7, LVar9, 0)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            Call(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
            Call(DisablePlayerInput, FALSE)
        CaseEq(2)
            Call(DisablePlayerInput, TRUE)
            Call(InterruptUsePartner)
            Call(PlaySoundAtCollider, COLLIDER_suimen, SOUND_SAM_POND_CRACK_2, 0)
            Call(EnableModel, MODEL_ice02, FALSE)
            Call(EnableModel, MODEL_ice03, TRUE)
            Thread
                Wait(10)
                Call(PlaySoundAtNpc, NPC_PenguinPatrol, SOUND_PENGUIN_WHISTLE, SOUND_SPACE_DEFAULT)
            EndThread
            Call(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Run)
            Call(GetNpcPos, NPC_PenguinPatrol, LVar7, LVar8, LVar9)
            Call(SetNpcSpeed, NPC_PenguinPatrol, Float(9.0))
            Call(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            Call(GetAngleToNPC, NPC_PenguinPatrol, LVar0)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Call(AddVectorPolar, LVar1, LVar3, Float(40.0), LVar0)
            Call(NpcMoveTo, NPC_PenguinPatrol, LVar1, LVar3, 0)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            Call(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
            Call(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B7)
            Call(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Call(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
            Thread
                Call(DisablePlayerPhysics, TRUE)
                Call(PlaySoundAtPlayer, SOUND_DRAG_PLAYER, SOUND_SPACE_DEFAULT)
                Call(InterpPlayerYaw, 90, 0)
                Call(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                Set(MF_Unk_01, FALSE)
                Loop(0)
                    IfEq(MF_Unk_01, TRUE)
                        BreakLoop
                    EndIf
                    Call(GetAngleToPlayer, NPC_PenguinPatrol, LVar0)
                    Call(GetNpcPos, NPC_PenguinPatrol, LVar1, LVar2, LVar3)
                    Call(AddVectorPolar, LVar1, LVar3, Float(20.0), LVar0)
                    Call(SetPlayerPos, LVar1, 0, LVar3)
                    Call(N(SetDraggingPlayerPosY))
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetNpcSpeed, NPC_PenguinPatrol, Float(3.8))
            Call(NpcMoveTo, NPC_PenguinPatrol, -207, 110, 0)
            Call(NpcMoveTo, NPC_PenguinPatrol, -450, 0, 0)
            Set(MF_Unk_01, TRUE)
            Call(StopSound, SOUND_DRAG_PLAYER)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            Call(SetPlayerAnimation, ANIM_MarioW2_Surprise)
            Call(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B8)
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar0, 45)
            Call(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
            Call(InterpNpcYaw, NPC_PenguinPatrol, 270, 0)
            Wait(10)
            Add(LVar0, -20)
            Call(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
            Wait(10)
            Call(PlaySoundAtNpc, NPC_PenguinPatrol, SOUND_TOSS_PLAYER, SOUND_SPACE_DEFAULT)
            Thread
                Set(MV_ThrownOut, 1)
                Call(SetPlayerJumpscale, Float(1.0))
                Call(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                Call(PlayerJump1, -680, 50, 0, 30)
            EndThread
            Call(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
            Call(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
            Wait(15)
            Set(GB_SAM11_FrozenPondDamage, 0)
            Call(GotoMap, Ref("sam_02"), sam_02_ENTRY_3)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_BlastPond_Before) = {
    Call(N(GetBombetteExplodeGround), LVar0)
    IfNe(LVar0, COLLIDER_suimen)
        Return
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLe(LVar0, -280)
        Return
    EndIf
    IfGe(LVar0, 280)
        Return
    EndIf
    IfLe(LVar2, -60)
        Return
    EndIf
    IfGe(LVar2, 460)
        Return
    EndIf
    ExecWait(N(EVS_DamageFrozenPond_Before))
    Wait(60)
    Set(MV_CantDamagePond, FALSE)
    Return
    End
};

EvtScript N(EVS_TouchPond_Before) = {
    Call(GetPlayerActionState, LVar0)
    IfNe(LVar0, ACTION_STATE_SPIN_POUND)
        IfNe(LVar0, ACTION_STATE_TORNADO_POUND)
            Return
        EndIf
    EndIf
    ExecWait(N(EVS_DamageFrozenPond_Before))
    Label(0)
        Call(GetPlayerActionState, LVar0)
        Wait(1)
        IfNe(LVar0, ACTION_STATE_IDLE)
            Goto(0)
        EndIf
    Set(MV_CantDamagePond, FALSE)
    Return
    End
};

EvtScript N(EVS_DamageFrozenPond_After) = {
    IfEq(MV_CantDamagePond, TRUE)
        Return
    EndIf
    Set(MV_CantDamagePond, TRUE)
    Add(GB_SAM11_FrozenPondDamage, 1)
    IfNe(GB_SAM11_FrozenPondDamage, 3)
        Switch(GB_SAM11_FrozenPondDamage)
            CaseEq(1)
                Call(PlaySoundAtCollider, COLLIDER_suimen, SOUND_SAM_POND_CRACK_1, 0)
                Call(EnableModel, MODEL_ice01, FALSE)
                Call(EnableModel, MODEL_ice02, TRUE)
            CaseEq(2)
                Call(PlaySoundAtCollider, COLLIDER_suimen, SOUND_SAM_POND_CRACK_2, 0)
                Call(EnableModel, MODEL_ice02, FALSE)
                Call(EnableModel, MODEL_ice03, TRUE)
        EndSwitch
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
    Call(IsPlayerWithin, 0, 210, 240, LVarA)
    IfEq(LVarA, 1)
        Thread
            Call(SetPlayerJumpscale, Float(1.5))
            Call(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
            Call(PlayerJump1, 247, 0, 225, 30)
            Call(PlayerJump1, 257, 0, 225, 8)
        EndThread
        Thread
            Call(DisablePartnerAI, 0)
            Wait(1)
            Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_FALL_LONG, SOUND_SPACE_DEFAULT)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(1.5))
            Call(NpcJump1, NPC_PARTNER, 265, 0, 225, 30)
            Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_TRIP, SOUND_SPACE_DEFAULT)
            Call(NpcJump1, NPC_PARTNER, 275, 0, 225, 8)
            Call(EnablePartnerAI)
        EndThread
        Thread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Loop(30)
                Call(GetPlayerPos, LVar3, LVar4, LVar5)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar1, LVar5)
                Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar1, LVar5)
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Wait(1)
            EndLoop
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
        EndThread
    EndIf
    Call(PlaySoundAt, SOUND_SAM_POND_SHATTER, SOUND_SPACE_DEFAULT, 0, 60, 220)
    Call(N(SpawnIceShards))
    Call(EnableModel, MODEL_ice03, FALSE)
    Call(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_VISIBLE)
    Call(EnableGroup, MODEL_sui, TRUE)
    Call(EnableGroup, MODEL_g279, TRUE)
    Call(EnableTexPanning, MODEL_o583, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,   60,   60, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Exec(N(EVS_LoadPondAnimation))
    Wait(60)
    Call(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_HIDDEN)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitp, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o356, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilitp, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o356, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitp, COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suimen, SURFACE_TYPE_WATER)
    Exec(N(EVS_SetupIcebergs))
    Set(GB_SAM11_FrozenPondDamage, 4)
    Set(GB_StoryProgress, STORY_CH7_SHATTERED_FROZEN_POND)
    IfEq(LVarA, 1)
        Call(SetPlayerAnimation, ANIM_Mario1_DustOff)
        Wait(7)
        Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
        Wait(8)
        Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
        Wait(15)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Wait(1)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BlastPond_After) = {
    Call(N(GetBombetteExplodeGround), LVar0)
    IfNe(LVar0, COLLIDER_suimen)
        Return
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLe(LVar0, -280)
        Return
    EndIf
    IfGe(LVar0, 280)
        Return
    EndIf
    IfLe(LVar2, -60)
        Return
    EndIf
    IfGe(LVar2, 460)
        Return
    EndIf
    ExecWait(N(EVS_DamageFrozenPond_After))
    Wait(60)
    Set(MV_CantDamagePond, FALSE)
    Return
    End
};

EvtScript N(EVS_TouchPond_After) = {
    IfEq(GB_SAM11_FrozenPondDamage, 4)
        Return
    EndIf
    Call(GetPlayerActionState, LVar0)
    IfNe(LVar0, ACTION_STATE_SPIN_POUND)
        IfNe(LVar0, ACTION_STATE_TORNADO_POUND)
            Return
        EndIf
    EndIf
    ExecWait(N(EVS_DamageFrozenPond_After))
    Label(0)
        Call(GetPlayerActionState, LVar0)
        Wait(1)
        IfNe(LVar0, ACTION_STATE_IDLE)
            Goto(0)
        EndIf
    Set(MV_CantDamagePond, FALSE)
    Return
    End
};

// @bug radius is f32 here, should be s32
BombTriggerF N(BombTrigger_Pond) = {
    .pos = { 0.0f, -10.0f, 220.0f },
    .radius = 300.0
};

EvtScript N(EVS_SetupPond) = {
    Call(EnableGroup, MODEL_sui, FALSE)
    Call(EnableGroup, MODEL_g279, FALSE)
    Call(EnableModel, MODEL_ice00, FALSE)
    Call(EnableModel, MODEL_ice01, FALSE)
    Call(EnableModel, MODEL_ice02, FALSE)
    Call(EnableModel, MODEL_ice03, FALSE)
    Call(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_HIDDEN)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
    IfLt(GB_StoryProgress, STORY_CH7_SHATTERED_FROZEN_POND)
        Switch(GB_SAM11_FrozenPondDamage)
            CaseEq(0)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                Call(EnableModel, MODEL_ice01, TRUE)
            CaseEq(1)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                Call(EnableModel, MODEL_ice02, TRUE)
            CaseEq(2)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                Call(EnableModel, MODEL_ice03, TRUE)
            CaseEq(3)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ike, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetGroupVisibility, MODEL_ice04, MODEL_GROUP_VISIBLE)
            CaseEq(4)
                Call(EnableGroup, MODEL_sui, TRUE)
                Call(EnableGroup, MODEL_g279, TRUE)
                Call(EnableTexPanning, MODEL_o583, TRUE)
                Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,   60,   60, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
                    Exec(N(EVS_UpdateTexturePan))
                EndThread
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
                Exec(N(EVS_SetupIcebergs))
        EndSwitch
    Else
        Call(EnableGroup, MODEL_sui, TRUE)
        Call(EnableGroup, MODEL_g279, TRUE)
        Call(EnableTexPanning, MODEL_o583, TRUE)
        Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,   60,   60, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
            Exec(N(EVS_UpdateTexturePan))
        EndThread
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o657, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o658, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o660, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o661, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o662, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o663, COLLIDER_FLAGS_UPPER_MASK)
        Exec(N(EVS_SetupIcebergs))
    EndIf
    IfLt(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
        BindTrigger(Ref(N(EVS_BlastPond_Before)), TRIGGER_POINT_BOMB, Ref(N(BombTrigger_Pond)), 1, 0)
        BindTrigger(Ref(N(EVS_TouchPond_Before)), TRIGGER_FLOOR_TOUCH, COLLIDER_suimen, 1, 0)
    Else
        BindTrigger(Ref(N(EVS_BlastPond_After)), TRIGGER_POINT_BOMB, Ref(N(BombTrigger_Pond)), 1, 0)
        BindTrigger(Ref(N(EVS_TouchPond_After)), TRIGGER_FLOOR_TOUCH, COLLIDER_suimen, 1, 0)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH7_SHATTERED_FROZEN_POND)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitp, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o356, SURFACE_TYPE_DOCK_WALL)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilitp, SURFACE_TYPE_DOCK_WALL)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o356, COLLIDER_FLAG_DOCK_WALL)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitp, COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_DOCK_WALL)
    EndIf
    Return
    End
};
