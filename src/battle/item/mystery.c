#include "mystery.h"
#include "effects.h"
#include "ld_addrs.h"
#include "battle/item/mystery.png.h"

#include "ItemRefund.inc.c"

#ifdef NON_MATCHING

extern s32 D_802A25E4;
extern HudElement* D_802A25C8;
extern s32 D_802A25EC;

void N(func_802A123C_72C7EC)(void) {
    s32 i;
    HudElement** ptr;
    s32 var;
    s32* var2;

    if (D_802A25E4 < 6) {
        if (D_802A25E4 > 0) {
            draw_box(0, 7, 0x6A, 0x56, 0, 0x24, 0x24, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 108, 90, 139, 118);

            ptr = &D_802A25C8;
            for (i = 0; i < 7; i++) {
                var2 = *ptr;
                var = (D_802A25EC / 100) - 0x68;
                ptr++;
                set_hud_element_render_pos(var2, 0x7C, (i * 0x1A) - var);
                draw_hud_element_3(var2);
            }

            var2 = D_802A25C8;
            var = (D_802A25EC / 100) - 0x68;
            set_hud_element_render_pos(var2, 0x7C, (i * 0x1A) - var);
            draw_hud_element_3(var2);
        }
    }
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/mystery", battle_item_mystery_func_802A123C_72C7EC, Evt* script,
            s32 isInitialCall);
#endif

#ifdef NON_MATCHING

extern s32 D_802A25E4;
extern s32 D_802A25E8;
extern s32 D_802A25EC;
extern s32 D_802A25F0;
extern s32 D_802A25F4;
extern s32 D_802A25F8;
extern s16** D_802A25FC;
extern HudElement** D_802A25C8;
extern struct N(tempStc) D_8008A680[100];

ApiStatus N(func_802A13E4_72C994)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        D_802A25E4 = 0;
    }

    switch (D_802A25E4) {
        case 0: {
            s32* tablePtr;
            s32 i;
            f32 t0;
            f32 t1;
            HudElement* icon;
            HudElement** iconPtr;
            struct N(tempStc)* ic;
            StaticItem* itemTable;

            D_802A25F8 = create_generic_entity_frontUI(NULL, func_802A123C_72C7EC);
            D_802A25EC = rand_int(18200);
            D_802A25F0 = 1000;
            tablePtr = &D_802A25FC;
            *tablePtr = N(D_802A227C_72D82C);

            if (battleStatus->unk_432 > 0) {
                get_screen_overlay_params(1, &t0, &t1);
                if (t1 >= 215.0f) {
                    *tablePtr = N(D_802A229C_72D84C);
                }
            }

            i = 0;
            ic = &D_8008A680;
            itemTable = gItemTable;
            iconPtr = &D_802A25C8;
            for (; i < 7; i++, iconPtr++) {
                icon = create_hud_element(ic[itemTable[D_802A25FC[i]].iconID].iconId);
                *iconPtr = icon;
                set_hud_element_flags(icon, 0x80);
            }
            D_802A25E4 = 1;
        }
        break;

        case 1: {
            s32* ECptr = &D_802A25EC;
            s32* F0ptr = &D_802A25F0;

            *ECptr += *F0ptr;
            if (*ECptr / 100 > 181) {
                s32* test = ECptr;
                *test -= 0x4718;
            }

            if (*F0ptr > 400) {
                *F0ptr -= 10;
            } else if (*F0ptr > 100) {
                *F0ptr -= 5;
            } else {
                *F0ptr -= 1;
            }

            if (D_802A25F0 < 10) {
                D_802A25E8 = D_802A25EC / 100;
                if (D_802A25E8 % 26 < 13) {
                    if (rand_int(100) < 80) {
                        D_802A25E4 = 2;
                    } else {
                        D_802A25E4 = 3;
                    }
                } else if (rand_int(100) < 60) {
                    D_802A25E4 = 3;
                } else {
                    D_802A25E4 = 2;
                }
            }
        }
        break;

        case 2: {
            s32* E8ptr = &D_802A25E8;
            s32 a, b, c, d;

            d = *E8ptr % 26;
            a = d;
            c = a + 3;
            if (c < 0) {
                c = a + 6;
            }
            d = c >> 2;
            *E8ptr -= d;
            D_802A25EC = *E8ptr * 100;
            if (d == 0) {
                D_802A25E4 = 4;
            }
        }
        break;

        case 3: {
            s32* E8ptr = &D_802A25E8;
            s32 a, b, c, d;

            d = *E8ptr % 26;
            if (d == 0) {
                D_802A25E4 = 4;
                break;
            }
            a = d;
            b = 26;
            b -= a;
            c = b + 3;
            if (c < 0) {
                c = b + 6;
            }
            c = c >> 2;
            *E8ptr += c;
            D_802A25EC = *E8ptr * 100;
        }
        break;

        case 4: {
            D_802A25F4 = 20;
            D_802A25E4 = 5;
        }
        break;

        case 5: {
            s32* F4ptr = &D_802A25F4;
            s32 i;
            s16 g;
            HudElement** iconPtr;

            if (*F4ptr != 0) {
                *F4ptr -= 1;
                break;
            }
            iconPtr = &D_802A25C8;
            i = D_802A25E8 / 26;
            g = D_802A25FC[i];
            battleStatus->selectedItemID = g;
            script->varTable[0] = g;
            free_generic_entity(D_802A25F8);
            for (i = 0; i < 7; i++) {
                free_hud_element(*iconPtr++);
            }
        }
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/mystery", battle_item_mystery_func_802A13E4_72C994, Evt* script,
            s32 isInitialCall);
#endif

ApiStatus N(func_802A188C_72CE3C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_18(2, a, b, c, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

static s32 _pad = 0;

#include "battle/item/mystery.png.inc.c"
#include "battle/item/mystery.pal.inc.c"

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

s32 N(modelCommandList)[] = {
    0x00000004, 0x0000000D, 0x00000001, sizeof(N(displayList)) / sizeof(s32), &N(displayList), 0x00000002, 0x00000000,
};

s32 N(D_802A227C_72D82C)[8] = {
    0x0000008A, 0x0000008C, 0x00000080, 0x00000088,
    0x0000009A, 0x00000082, 0x00000085, 0x0000008A
};

s32 N(D_802A229C_72D84C)[8] = {
    0x0000008A, 0x0000008C, 0x00000085, 0x00000088,
    0x0000008A, 0x0000008C, 0x00000085, 0x0000008A
};

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000096)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_THREAD
        EVT_WAIT_FRAMES(220)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_3F3)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_368)
    EVT_CALL(N(func_802A13E4_72C994))
    EVT_WAIT_FRAMES(2)
    EVT_IF_NE(EVT_VAR(0), 133)
        EVT_JUMP(EVT_PTR(UseMystery))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(CreateVirtualEntity, EVT_VAR(10), EVT_PTR(N(modelCommandList)))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 150)
    EVT_CALL(SetVirtualEntityPosition, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetOwnerTarget, 0, 0)
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
    EVT_CALL(SetVirtualEntityJumpGravity, EVT_VAR(10), EVT_FIXED(0.6))
    EVT_ADD(EVT_VAR(2), 5)
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 12)
    EVT_THREAD
        EVT_ADD(EVT_VAR(0), 60)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 16)
        EVT_CALL(DeleteVirtualEntity, EVT_VAR(10))
    EVT_END_THREAD
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(func_802A188C_72CE3C), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetBattleFlagBits, 32, 1)
    EVT_CALL(DispatchDamagePlayerEvent, 1, EVENT_HIT)
    EVT_RETURN
    EVT_END
};
