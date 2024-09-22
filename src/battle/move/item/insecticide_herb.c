#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "entity.h"
#include "ld_addrs.h"
#include "sprite/player.h"
#include "include_asset.h"

#define NAMESPACE battle_item_insecticide_herb

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_72A98C)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target = get_actor(enemy->targetActorID);

    script->varTable[9] = target->actorType == 49;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A1280_72A9D0)) {
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target;

    sfx_play_sound_at_position(SOUND_DAMAGE_STARS, SOUND_SPACE_DEFAULT, enemy->state.goalPos.x, enemy->state.goalPos.y, enemy->state.goalPos.z);
    target = get_actor(enemy->targetActorID);
    dispatch_event_actor(target, EVENT_SCARE_AWAY);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A12E0_72AA30)) {
    Bytecode* args = script->ptrReadPos;
    f32 a = evt_get_variable(script, *args++);
    f32 b = evt_get_variable(script, *args++);
    f32 c = evt_get_variable(script, *args++);
    EffectInstance* effect;

    a += rand_int(20) - 10;
    b += rand_int(10) - 5;

    effect = fx_cold_breath(0, a, b, c, 1.0f, 30);

    effect->data.coldBreath->primCol.r = 244;
    effect->data.coldBreath->primCol.g = 244;
    effect->data.coldBreath->primCol.b = 220;
    effect->data.coldBreath->envCol.r = 210;
    effect->data.coldBreath->envCol.g = 210;
    effect->data.coldBreath->envCol.b = 190;

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/move/item/insecticide_herb.png.h"
INCLUDE_IMG("battle/move/item/insecticide_herb.png", battle_item_insecticide_herb_png);
INCLUDE_PAL("battle/move/item/insecticide_herb.pal", battle_item_insecticide_herb_pal);

Vtx N(model)[] = {
    { .v = { .ob = {-16, -16, 0}, FALSE, .tc = {0,    0},    .cn = {0, 0, 0, 255} } },
    { .v = { .ob = {15,  -16, 0}, FALSE, .tc = {1024, 0},    .cn = {0, 0, 0, 255} } },
    { .v = { .ob = {15,  15,  0}, FALSE, .tc = {1024, 1024}, .cn = {0, 0, 0, 255} } },
    { .v = { .ob = {-16, 15,  0}, FALSE, .tc = {0,    1024}, .cn = {0, 0, 0, 255} } },
};

Gfx N(displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_insecticide_herb_pal),
    gsDPLoadTextureTile_4b(battle_item_insecticide_herb_png, G_IM_FMT_CI, battle_item_insecticide_herb_png_width, battle_item_insecticide_herb_png_height, 0, 0, battle_item_insecticide_herb_png_width - 1, battle_item_insecticide_herb_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript N(modelCommandList) = STANDARD_ENTITY_MODEL_SCRIPT(N(displayList), RENDER_MODE_ALPHATEST);


EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_INSECTICIDE_HERB)
    ExecWait(N(UseItemWithEffect))
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 15)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Throw)
    Call(PlaySound, SOUND_THROW)
    Wait(3)
    Call(CreateVirtualEntity, LVarA, Ref(N(modelCommandList)))
    SetF(LVar0, Float(1.0))
    Call(MultiplyByActorScale, LVar0)
    Call(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar3, 20)
    Set(LVar4, 42)
    Set(LVar5, 5)
    Call(MultiplyVec3ByActorScale, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Call(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Loop(18)
            Add(LVar0, -60)
            Call(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetVirtualEntityJumpGravity, LVarA, Float(0.8))
    Add(LVar2, 5)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 18)
    PlayEffect(EFFECT_WALKING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0)
    Sub(LVar0, 10)
    PlayEffect(EFFECT_WALKING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0)
    Add(LVar0, 20)
    PlayEffect(EFFECT_WALKING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0)
    Thread
        Call(N(func_802A12E0_72AA30), LVar0, LVar1, LVar2)
        Wait(3)
        Call(N(func_802A12E0_72AA30), LVar0, LVar1, LVar2)
        Wait(3)
        Call(N(func_802A12E0_72AA30), LVar0, LVar1, LVar2)
    EndThread
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(N(func_802A123C_72A98C))
    Call(DeleteVirtualEntity, LVarA)
    IfEq(LVar9, 0)
        Call(ItemDamageEnemy, LVar0, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
    Else
        Call(InitTargetIterator)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(N(func_802A1280_72A9D0))
    EndIf
    ExecWait(N(PlayerGoHome))
    Return
    End
};
