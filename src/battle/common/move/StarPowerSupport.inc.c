#include "common.h"
#include "script_api/battle.h"
#include "model.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(SpawnStarSparkleFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_0, x, y, z, 40.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnWishSparkleFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_stars_shimmer(5, x, y, z, 50.0f, 50.0f, 40, 30);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnStarSpiritArriveFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_0, x, y, z, 30.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnStarSpiritDepartFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_misc_particles(4, x, y, z, 20.0f, 20.0f, 1.0f, 10, 15);
    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundDarken.inc.c"

API_CALLABLE(N(FadeBackgroundDarkenForBeam)) {
    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        script->functionTemp[0] = 0;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] += 10;

    if (script->functionTemp[0] >= 230) {
        mdl_set_shroud_tint_params(0, 0, 0, 230);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "common/FadeBackgroundLighten.inc.c"

API_CALLABLE(N(SetPartnerWishAnim)) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 wishAnimIdx = evt_get_variable(script, *args++);
    AnimID anim = PartnerWishAnims[playerData->curPartner][wishAnimIdx];

    set_actor_anim(ACTOR_PARTNER, 0, anim);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetStarSpiritSize)) {
    Npc* npc = get_npc_unsafe(NPC_BTL_SPIRIT);

    npc->collisionHeight = 32;
    npc->collisionDiameter = 32;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_StarPower_WishForSpirit) = {
    Call(GetOwnerID, LVarA)
    IfEq(LVarA, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 16)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerRunToGoal, 0)
        Wait(8)
        Call(PlaySound, SOUND_BEGIN_WISH)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
        Call(N(FadeBackgroundDarken))
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Pray)
        Wait(10)
        Call(PlaySound, SOUND_WISH_ASCENDING)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
        Wait(30)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
        Wait(10)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_WALK)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 16)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(RunToGoal, ACTOR_PARTNER, 0, false)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
        Wait(8)
        Call(PlaySound, SOUND_BEGIN_WISH)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_PRAY)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
        Call(N(FadeBackgroundDarken))
        Wait(20)
        Call(PlaySound, SOUND_WISH_ASCENDING)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_PRAY)
        Wait(10)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
        Wait(30)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_StarPower_WishForBeam) = {
    Call(GetOwnerID, LVarA)
    IfEq(LVarA, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 16)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerRunToGoal, 0)
        Wait(8)
        Call(PlaySound, SOUND_BEGIN_WISH)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
        Call(N(FadeBackgroundDarkenForBeam))
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Pray)
        Wait(10)
        Call(PlaySound, SOUND_WISH_ASCENDING)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
        Wait(30)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
        Wait(10)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_WALK)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 16)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(RunToGoal, ACTOR_PARTNER, 0, false)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
        Wait(8)
        Call(PlaySound, SOUND_BEGIN_WISH)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_PRAY)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
        Call(N(FadeBackgroundDarkenForBeam))
        Wait(20)
        Call(PlaySound, SOUND_WISH_ASCENDING)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_PRAY)
        Wait(10)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
        Wait(30)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_StarPower_SpiritSummoned) = {
    Wait(8)
    Call(SetForegroundModelsVisible, false)
    Call(UseBattleCamPresetImmediately, BTL_CAM_STAR_SPIRIT)
    Call(MoveBattleCamOver, 1)
    Call(PlaySound, SOUND_STAR_SPIRIT_APPEAR_A)
    Call(CreateNpc, NPC_BTL_SPIRIT, LVar0)
    Call(N(SetStarSpiritSize))
    Call(SetNpcFlagBits, NPC_BTL_SPIRIT, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, true)
    Call(SetNpcPos, NPC_BTL_SPIRIT, -75, 150, 0)
    Call(SetNpcDecoration, NPC_BTL_SPIRIT, 0, NPC_DECORATION_WHITE_GLOW_BEHIND)
    Call(N(SpawnStarSpiritArriveFX), -75, 167, 0)
    Wait(10)
    Call(EnableNpcBlur, NPC_BTL_SPIRIT, true)
    Set(LVar0, 0)
    Loop(8)
        Add(LVar0, 67)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Wait(10)
    Call(EnableNpcBlur, NPC_BTL_SPIRIT, false)
    Thread
        Wait(10)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
    EndThread
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 50)
    Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 30, 0, EASING_COS_IN_OUT)
    Call(SetForegroundModelsVisible, true)
    Return
    End
};

EvtScript N(EVS_StarPower_SpiritDeparts) = {
    Call(GetOwnerID, LVarA)
    IfEq(LVarA, ACTOR_PLAYER)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(PlaySound, SOUND_STAR_SPIRIT_DEPART_3)
        Thread
            Loop(5)
                Wait(6)
                Call(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
                Call(N(SpawnStarSpiritDepartFX), LVar0, LVar1, LVar2)
            EndLoop
        EndThread
        Call(EnableNpcBlur, NPC_BTL_SPIRIT, true)
        Thread
            Set(LVar2, 0)
            Set(LVar3, 720)
            Call(MakeLerp, LVar2, LVar3, 30, EASING_CUBIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        Call(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
        Add(LVar1, 60)
        Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        Add(LVar1, 140)
        Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        Wait(10)
        Call(EnableNpcBlur, NPC_BTL_SPIRIT, false)
        Call(DeleteNpc, NPC_BTL_SPIRIT)
    Else
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(PlaySound, SOUND_STAR_SPIRIT_DEPART_1)
        Thread
            Loop(5)
                Wait(6)
                Call(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
                Call(N(SpawnStarSpiritDepartFX), LVar0, LVar1, LVar2)
            EndLoop
        EndThread
        Call(EnableNpcBlur, NPC_BTL_SPIRIT, true)
        Thread
            Set(LVar2, 0)
            Set(LVar3, 720)
            Call(MakeLerp, LVar2, LVar3, 30, EASING_CUBIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        Call(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
        Add(LVar1, 60)
        Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        Add(LVar1, 140)
        Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        Wait(10)
        Call(EnableNpcBlur, NPC_BTL_SPIRIT, false)
        Call(DeleteNpc, NPC_BTL_SPIRIT)
    EndIf
    Return
    End
};

EvtScript N(EVS_StarPower_EndWish) = {
    Call(GetOwnerID, LVarA)
    IfEq(LVarA, ACTOR_PLAYER)
        Call(N(FadeBackgroundLighten))
        Wait(15)
        Call(SetGoalToHome, ACTOR_PLAYER)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        Call(PlayerRunToGoal, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Else
        Call(N(FadeBackgroundLighten))
        Wait(15)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_RETURN)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
    EndIf
    Return
    End
};

