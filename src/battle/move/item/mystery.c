#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "entity.h"
#include "ld_addrs.h"
#include "include_asset.h"

#define NAMESPACE battle_item_mystery

#include "battle/common/move/ItemRefund.inc.c"

#include "battle/common/move/UseItem.inc.c"

static s32 _pad = 0;

#include "battle/move/item/mystery.png.h"
INCLUDE_IMG("battle/move/item/mystery.png", battle_item_mystery_png);
INCLUDE_PAL("battle/move/item/mystery.pal", battle_item_mystery_pal);

Vtx N(model)[] = {
    { .v = {{ -16, -16, 0 }, FALSE, { 0,    0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  -16, 0 }, FALSE, { 1024, 0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  15,  0 }, FALSE, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    { .v = {{ -16, 15,  0 }, FALSE, { 0,    1024 }, { 0, 0, 0, 255 }}},
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
    gsDPLoadTLUT_pal16(0, battle_item_mystery_pal),
    gsDPLoadTextureTile_4b(battle_item_mystery_png, G_IM_FMT_CI, battle_item_mystery_png_width, battle_item_mystery_png_height, 0, 0, battle_item_mystery_png_width - 1, battle_item_mystery_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript N(modelCommandList) = STANDARD_ENTITY_MODEL_SCRIPT(N(displayList), RENDER_MODE_ALPHATEST);

s32 N(D_802A227C_72D82C)[8] = {
    ITEM_MUSHROOM,
    ITEM_SUPER_SHROOM,
    ITEM_FIRE_FLOWER,
    ITEM_STONE_CAP,
    ITEM_DIZZY_DIAL,
    ITEM_THUNDER_RAGE,
    ITEM_PEBBLE,
    ITEM_MUSHROOM
};

s32 N(D_802A229C_72D84C)[8] = {
    ITEM_MUSHROOM,
    ITEM_SUPER_SHROOM,
    ITEM_PEBBLE,
    ITEM_STONE_CAP,
    ITEM_MUSHROOM,
    ITEM_SUPER_SHROOM,
    ITEM_PEBBLE,
    ITEM_MUSHROOM
};

extern IconHudScriptPair gItemHudScripts[];

BSS s32 D_802A25C4; // unused?
BSS s32 D_802A25C8[7];
BSS s32 D_802A25E4;
BSS s32 D_802A25E8;
BSS s32 D_802A25EC;
BSS s32 D_802A25F0;
BSS s32 D_802A25F4;
BSS s32 D_802A25F8;
BSS s32* D_802A25FC;

void N(func_802A123C_72C7EC(void)) {
    s32 var_s3;
    s32 id;
    s32 i;

    if (D_802A25E4 < 6) {
        if (D_802A25E4 > 0) {
            draw_box(0, WINDOW_STYLE_7, 106, 86, 0, 36, 36, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 108, 90, 139, 118);

            for (i = 0; i < ARRAY_COUNT(D_802A25C8); i++) {
                id = D_802A25C8[i];
                hud_element_set_render_pos(id, 124, (i * 26) + 104 - (D_802A25EC / 100));
                hud_element_draw_without_clipping(id);
            }
            id = D_802A25C8[0];
            hud_element_set_render_pos(id, 124, (i * 26) + 104 - (D_802A25EC / 100));
            hud_element_draw_without_clipping(id);
        }
    }
}

API_CALLABLE(N(func_802A13E4_72C994)) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 temp_a0_4;
    s32 temp_v1_3;
    s32 var_v0_2;
    s32 var_v0_3;
    HudElemID hid;
    s32 i;

    if (isInitialCall) {
        D_802A25E4 = 0;
    }

    switch (D_802A25E4) {
        case 0:
            D_802A25F8 = create_worker_frontUI(NULL, N(func_802A123C_72C7EC));
            D_802A25EC = rand_int(18200);
            D_802A25F0 = 1000;
            D_802A25FC = N(D_802A227C_72D82C);

            if (battleStatus->darknessMode > BTL_DARKNESS_STATE_NONE) {
                u8 type;
                f32 zoom;

                get_screen_overlay_params(SCREEN_LAYER_BACK, &type, &zoom);
                if (zoom >= 215.0f) {
                    D_802A25FC = N(D_802A229C_72D84C);
                }
            }

            for (i = 0; i < ARRAY_COUNT(D_802A25C8); i++) {
                hid = hud_element_create(gItemHudScripts[gItemTable[D_802A25FC[i]].hudElemID].enabled);
                D_802A25C8[i] = hid;
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80);
            }
            D_802A25E4 = 1;
            return ApiStatus_BLOCK;
        case 1:
            D_802A25EC += D_802A25F0;
            if (D_802A25EC / 100 >= 182) {
                D_802A25EC -= 18200;
            }

            if (D_802A25F0 > 400) {
                D_802A25F0 -= 10;
            } else if (D_802A25F0 > 100) {
                D_802A25F0 -= 5;
            } else {
                D_802A25F0 -= 1;
            }

            if (D_802A25F0 < 10) {
                D_802A25E8 = D_802A25EC / 100;

                if (((D_802A25EC / 100) % 26) < 13) {
                    if (rand_int(100) < 80) {
                        D_802A25E4 = 2;
                    } else {
                        D_802A25E4 = 3;
                    }
                    break;
                }

                if (rand_int(100) < 60) {
                    D_802A25E4 = 3;
                } else {
                    D_802A25E4 = 2;
                }
            }
            break;
        case 2:
            temp_a0_4 = D_802A25E8 % 26;
            var_v0_2 = temp_a0_4 + 3;
            if (var_v0_2 < 0) {
                var_v0_2 += 3;
            }
            temp_a0_4 = var_v0_2 >> 2;
            D_802A25E8 -= temp_a0_4;
            D_802A25EC = D_802A25E8 * 100;
            if (temp_a0_4 == 0) {
                D_802A25E4 = 4;
            }
            break;
        case 3:
            temp_v1_3 = D_802A25E8 % 26;
            if (temp_v1_3 == 0) {
                D_802A25E4 = 4;
                break;
            }
            temp_a0_4 = 26 - temp_v1_3;
            var_v0_3 = temp_a0_4 + 3;
            if (var_v0_3 < 0) {
                var_v0_3 += 3;
            }
            temp_a0_4 = var_v0_3 >> 2;
            D_802A25E8 += temp_a0_4;
            D_802A25EC = D_802A25E8 * 100;
            break;
        case 4:
            D_802A25F4 = 20;
            D_802A25E4 = 5;
            break;
        case 5:
            if (D_802A25F4 != 0) {
                D_802A25F4--;
                break;
            }

            var_v0_3 = i = D_802A25E8 / 26; // use of i required to match
            battleStatus->moveArgument = D_802A25FC[D_802A25E8 / 26];
            script->varTable[0] = battleStatus->moveArgument;
            free_worker(D_802A25F8);
            for (i = 0; i < ARRAY_COUNT(D_802A25C8); i++) {
                hud_element_free(D_802A25C8[i]);
            }
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802A188C_72CE3C)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_damage_stars(FX_DAMAGE_STARS_2, a, b, c, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_MYSTERY)
    ExecWait(N(UseItemWithEffect))
    Thread
        Wait(220)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_DING)
    EndThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MYSTERY_REEL)
    Call(N(func_802A13E4_72C994))
    Wait(2)
    IfNe(LVar0, 133)
        Jump(Ref(EVS_UseMystery))
        Return
    EndIf
    Call(CreateVirtualEntity, LVarA, Ref(N(modelCommandList)))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 150)
    Call(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    Call(SetOwnerTarget, ACTOR_PLAYER, 0)
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
    Call(SetVirtualEntityJumpGravity, LVarA, Float(0.6))
    Add(LVar2, 5)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 12)
    Thread
        Add(LVar0, 60)
        Add(LVar1, 0)
        Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 16)
        Call(DeleteVirtualEntity, LVarA)
    EndThread
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(N(func_802A188C_72CE3C), LVar0, LVar1, LVar2)
    Call(SetBattleFlagBits, BS_FLAGS1_TRIGGER_EVENTS, TRUE)
    Call(DispatchDamagePlayerEvent, 1, EVENT_HIT)
    Return
    End
};
