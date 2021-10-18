#include "insecticide_herb.h"
#include "effects.h"
#include "ld_addrs.h"
#include "battle/item/insecticide_herb.png.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72A98C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target = get_actor(enemy->targetActorID);

    script->varTable[9] = target->actorType == 49;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1280_72A9D0)(Evt* script, s32 isInitialCall) {
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target;

    sfx_play_sound_at_position(0x231, 0, enemy->state.goalPos.x, enemy->state.goalPos.y, enemy->state.goalPos.z);
    target = get_actor(enemy->targetActorID);
    dispatch_event_actor(target, 0x39);

    return ApiStatus_DONE2;
}

typedef struct N(temp) {
    char unk_00[0xC];
    EffectInstanceDataThing* unk_0C;
} N(temp);

ApiStatus N(func_802A12E0_72AA30)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 a = evt_get_variable(script, *args++);
    f32 b = evt_get_variable(script, *args++);
    f32 c = evt_get_variable(script, *args++);
    struct N(temp)* effect;

    a += rand_int(20) - 10;
    b += rand_int(10) - 5;

    effect = (struct N(temp)*)playFX_6F(0, a, b, c, 1.0f, 30);

    effect->unk_0C->unk_18 = 0xF4;
    effect->unk_0C->unk_1C = 0xF4;
    effect->unk_0C->unk_20 = 0xDC;
    effect->unk_0C->unk_28 = 0xD2;
    effect->unk_0C->unk_2C = 0xD2;
    effect->unk_0C->unk_30 = 0xBE;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/item/insecticide_herb.png.inc.c"
#include "battle/item/insecticide_herb.pal.inc.c"

Vtx N(model)[] = {
    { .v = { -16, -16, 0, FALSE, 0,    0,    0, 0, 0, 255 } },
    { .v = { 15,  -16, 0, FALSE, 1024, 0,    0, 0, 0, 255 } },
    { .v = { 15,  15,  0, FALSE, 1024, 1024, 0, 0, 0, 255 } },
    { .v = { -16, 15,  0, FALSE, 0,    1024, 0, 0, 0, 255 } },
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

s32 N(modelCommandList)[] = {
    0x00000004, 0x0000000D, 0x00000001, sizeof(N(displayList)) / sizeof(s32), &N(displayList), 0x00000002, 0x00000000,
};

EvtSource script = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000087)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THROW)
    EVT_CALL(PlaySound, SOUND_THROW)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(CreateVirtualEntity, EVT_VAR(10), EVT_PTR(N(modelCommandList)))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(1.0))
    EVT_CALL(MultiplyByActorScale, EVT_VAR(0))
    EVT_CALL(SetVirtualEntityScale, EVT_VAR(10), EVT_VAR(0), EVT_VAR(0), EVT_VAR(0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(3), 20)
    EVT_SET(EVT_VAR(4), 42)
    EVT_SET(EVT_VAR(5), 5)
    EVT_CALL(MultiplyVec3ByActorScale, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_ADD(EVT_VAR(0), EVT_VAR(3))
    EVT_ADD(EVT_VAR(1), EVT_VAR(4))
    EVT_ADD(EVT_VAR(2), EVT_VAR(5))
    EVT_CALL(SetVirtualEntityPosition, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(18)
            EVT_ADD(EVT_VAR(0), -60)
            EVT_CALL(SetVirtualEntityRotation, EVT_VAR(10), 0, 0, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetVirtualEntityJumpGravity, EVT_VAR(10), EVT_FIXED(0.8))
    EVT_ADD(EVT_VAR(2), 5)
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 18)
    EVT_CALL(PlayEffect, 0x7, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_SUB(EVT_VAR(0), 10)
    EVT_CALL(PlayEffect, 0x7, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ADD(EVT_VAR(0), 20)
    EVT_CALL(PlayEffect, 0x7, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(N(func_802A12E0_72AA30), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(3)
        EVT_CALL(N(func_802A12E0_72AA30), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(3)
        EVT_CALL(N(func_802A12E0_72AA30), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(N(func_802A123C_72A98C))
    EVT_CALL(DeleteVirtualEntity, EVT_VAR(10))
    EVT_IF_EQ(EVT_VAR(9), 0)
        EVT_CALL(ItemDamageEnemy, EVT_VAR(0), 0, 0, 0, 32)
    EVT_ELSE
        EVT_CALL(InitTargetIterator)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(N(func_802A1280_72A9D0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
