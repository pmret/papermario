#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "entity.h"
#include "ld_addrs.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_egg_missile

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_71CF1C)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_smoke_ring(0, x, y, z);
    fx_explosion(0, x, y + 20, z);

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

static s32 _pad = 0;

#include "battle/move/item/egg_missile1.png.h"
#include "battle/move/item/egg_missile1.png.inc.c"
#include "battle/move/item/egg_missile1.pal.inc.c"

#include "battle/move/item/egg_missile2.png.h"
#include "battle/move/item/egg_missile2.png.inc.c"
#include "battle/move/item/egg_missile2.pal.inc.c"

#include "battle/move/item/egg_missile3.png.h"
#include "battle/move/item/egg_missile3.png.inc.c"
#include "battle/move/item/egg_missile3.pal.inc.c"

#include "battle/move/item/egg_missile4.png.h"
#include "battle/move/item/egg_missile4.png.inc.c"
#include "battle/move/item/egg_missile4.pal.inc.c"

Vtx N(EggMissileVtx)[] = {
    { .v = {{ -16, -16, 0 }, FALSE, { 0,    0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  -16, 0 }, FALSE, { 1024, 0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  15,  0 }, FALSE, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    { .v = {{ -16, 15,  0 }, FALSE, { 0,    1024 }, { 0, 0, 0, 255 }}},
};

Gfx N(Frame1Gfx)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile1_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile1_png, G_IM_FMT_CI, battle_item_egg_missile1_png_width, battle_item_egg_missile1_png_height, 0, 0, battle_item_egg_missile1_png_width - 1, battle_item_egg_missile1_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(EggMissileVtx), ARRAY_COUNT(N(EggMissileVtx)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(Frame2Gfx)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile2_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile2_png, G_IM_FMT_CI, battle_item_egg_missile2_png_width, 0, 0, 0, battle_item_egg_missile2_png_width - 1, battle_item_egg_missile2_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(EggMissileVtx), ARRAY_COUNT(N(EggMissileVtx)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(Frame3Gfx)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile3_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile3_png, G_IM_FMT_CI, battle_item_egg_missile3_png_width, 0, 0, 0, battle_item_egg_missile3_png_width - 1, battle_item_egg_missile3_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(EggMissileVtx), ARRAY_COUNT(N(EggMissileVtx)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(Frame4Gfx)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile4_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile4_png, G_IM_FMT_CI, battle_item_egg_missile4_png_width, 0, 0, 0, battle_item_egg_missile4_png_width - 1, battle_item_egg_missile4_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(EggMissileVtx), ARRAY_COUNT(N(EggMissileVtx)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript N(EMS_EggMissile) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(Frame1Gfx), 2)
    ems_Draw(N(Frame2Gfx), 2)
    ems_Draw(N(Frame3Gfx), 2)
    ems_Restart
    ems_End
};

EntityModelScript unusedModelScript = STANDARD_ENTITY_MODEL_SCRIPT(N(Frame4Gfx), RENDER_MODE_ALPHATEST);

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_EGG_MISSILE)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Throw)
    EVT_CALL(PlaySound, SOUND_THROW)
    EVT_WAIT(3)
    EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(EMS_EggMissile)))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 42)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(18)
            EVT_ADD(LVar0, 60)
            EVT_CALL(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(1.0))
    EVT_ADD(LVar2, 5)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 18)
    EVT_CALL(DeleteVirtualEntity, LVarA)
    EVT_CALL(PlaySound, SOUND_EGG_MISSILE_BLAST)
    EVT_CALL(N(func_802A123C_71CF1C), LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(StartRumble, BTL_RUMBLE_HIT_EXTREME)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.75))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.45))
    EVT_END_THREAD
    EVT_CALL(GetItemPower, ITEM_EGG_MISSILE, LVar0, LVar1)
    EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
