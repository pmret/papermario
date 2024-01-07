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
    EVT_SET_CONST(LVarA, ITEM_INSECTICIDE_HERB)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Throw)
    EVT_CALL(PlaySound, SOUND_THROW)
    EVT_WAIT(3)
    EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(modelCommandList)))
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_CALL(MultiplyByActorScale, LVar0)
    EVT_CALL(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 20)
    EVT_SET(LVar4, 42)
    EVT_SET(LVar5, 5)
    EVT_CALL(MultiplyVec3ByActorScale, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(18)
            EVT_ADD(LVar0, -60)
            EVT_CALL(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(0.8))
    EVT_ADD(LVar2, 5)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 18)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0)
    EVT_SUB(LVar0, 10)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0)
    EVT_ADD(LVar0, 20)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(N(func_802A12E0_72AA30), LVar0, LVar1, LVar2)
        EVT_WAIT(3)
        EVT_CALL(N(func_802A12E0_72AA30), LVar0, LVar1, LVar2)
        EVT_WAIT(3)
        EVT_CALL(N(func_802A12E0_72AA30), LVar0, LVar1, LVar2)
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(N(func_802A123C_72A98C))
    EVT_CALL(DeleteVirtualEntity, LVarA)
    EVT_IF_EQ(LVar9, 0)
        EVT_CALL(ItemDamageEnemy, LVar0, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ELSE
        EVT_CALL(InitTargetIterator)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(N(func_802A1280_72A9D0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
