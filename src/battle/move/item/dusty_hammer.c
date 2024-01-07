#include "common.h"
#include "script_api/battle.h"
#include "entity.h"
#include "ld_addrs.h"
#include "sprite/player.h"
#include "include_asset.h"

#define NAMESPACE battle_item_dusty_hammer

#include "battle/common/move/ItemRefund.inc.c"
#include "battle/common/move/UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/move/item/dusty_hammer.png.h"
INCLUDE_IMG("battle/move/item/dusty_hammer.png", battle_item_dusty_hammer_png);
INCLUDE_PAL("battle/move/item/dusty_hammer.pal", battle_item_dusty_hammer_pal);

Vtx N(DustyHammerVtx)[] = {
    { .v = {{ -16, -16, 0 }, FALSE, { 0,    0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  -16, 0 }, FALSE, { 1024, 0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  15,  0 }, FALSE, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    { .v = {{ -16, 15,  0 }, FALSE, { 0,    1024 }, { 0, 0, 0, 255 }}},
};

Gfx N(DustyHammerGfx)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_dusty_hammer_pal),
    gsDPLoadTextureTile_4b(battle_item_dusty_hammer_png, G_IM_FMT_CI, battle_item_dusty_hammer_png_width, battle_item_dusty_hammer_png_height, 0, 0, battle_item_dusty_hammer_png_width - 1, battle_item_dusty_hammer_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(DustyHammerVtx), ARRAY_COUNT(N(DustyHammerVtx)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript N(EMS_DustyHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(DustyHammerGfx), RENDER_MODE_ALPHATEST);

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_DUSTY_HAMMER)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Throw)
    EVT_CALL(PlaySound, SOUND_THROW)
    EVT_WAIT(3)
    EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(EMS_DustyHammer)))
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
    EVT_CALL(GetItemPower, ITEM_DUSTY_HAMMER, LVar3, LVar4)
    EVT_CALL(ApplyShrinkFromOwner, LVar3)
    EVT_CALL(ItemDamageEnemy, LVar9, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, LVar3, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar1, 10)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 10)
    EVT_CALL(DeleteVirtualEntity, LVarA)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
