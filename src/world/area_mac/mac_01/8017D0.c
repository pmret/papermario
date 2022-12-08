#include "mac_01.h"
#include "model.h"
#include "hud_element.h"

extern IconHudScriptPair gItemHudScripts[];

#define CHUCK_QUIZMO_NPC_ID 5

extern s32 mac_01_ItemChoice_HasSelectedItem;
extern s32 mac_01_ItemChoice_SelectedItemID;
extern s32 D_80258404_818C84;
extern s32 D_80262F68;

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

static char* N(exit_str_0) = "flo_00";
static char* N(exit_str_1) = "kmr_22";

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/UnkFoldFunc.inc.c"

ApiStatus func_80243380_803C00(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = heap_malloc(sizeof(*temp_v0));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    temp_v0->unk_34 = gPlayerStatus.colliderHeight;
    temp_v0->unk_38 = gPlayerStatus.colliderDiameter;
    temp_v0->pos.x = gPlayerStatus.position.x;
    temp_v0->pos.y = gPlayerStatus.position.y;
    temp_v0->pos.z = gPlayerStatus.position.z;
    temp_v0->rot.x = 0.0f;
    temp_v0->rot.y = 0.0f;
    temp_v0->rot.z = 0.0f;
    temp_v0->scale.x = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.y = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.z = SPRITE_WORLD_SCALE_F;
    temp_v0->foldID = func_8013A704(1);
    temp_v0->entityID = create_worker_world(NULL, mac_01_UnkFoldFunc);
    evt_set_variable(script, MapVar(10), (s32) temp_v0);
    return ApiStatus_DONE2;
}

ApiStatus func_80243494_803D14(Evt* script, s32 isInitialCall) {
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    func_8013A854(temp_v0->foldID);
    free_worker(temp_v0->entityID);
    heap_free(temp_v0);
    evt_set_variable(script, MapVar(10), NULL);
    return ApiStatus_DONE2;
}

ApiStatus func_80243500_803D80(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->pos.x = x;
    temp_v0->pos.y = y;
    temp_v0->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_802435C0_803E40(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->rot.x = x;
    temp_v0->rot.y = y;
    temp_v0->rot.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80243680_803F00(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->scale.x = x;
    temp_v0->scale.y = y;
    temp_v0->scale.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80243740_803FC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    return ApiStatus_DONE2;
}

#include "world/common/atomic/ToadHouse.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243CD4_804554);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 mac_01_D_80262A70[];

ApiStatus func_80243D60_8045E0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_01_D_80262A70[i] = ptr[i];
        }
        mac_01_D_80262A70[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_01_D_80262A70[i] = i + 16;
            mac_01_D_80262A70[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

#include "world/common/todo/GetPlayerCoins.inc.c"

ApiStatus func_802440FC_80497C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x2B)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x2A)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x29)), -1, 3);
        set_model_env_color_parameters(255, 255, 255, 0, 0, 0);
        script->functionTemp[0] = 255;
    }
    script->functionTemp[0] -= 4;
    if (script->functionTemp[0] < 64) {
        script->functionTemp[0] = 64;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 64) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802441EC_804A6C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
        script->functionTemp[2] = 64;
        script->functionTemp[1] = 0;
    }
    if (script->functionTemp[1] == 0) {
        script->functionTemp[0] += 4;
        script->functionTemp[2] += 4;
        if (script->functionTemp[0] > 127) {
            script->functionTemp[0] = 127;
        }
        if (script->functionTemp[2] > 127) {
            script->functionTemp[2] = 127;
        }
        if (script->functionTemp[0] == 127 && (script->functionTemp[2] == script->functionTemp[0])) {
            script->functionTemp[1] = 1;
        }
    } else {
        script->functionTemp[0] -= 4;
        script->functionTemp[2] -= 4;
        if (script->functionTemp[0] < 64) {
            script->functionTemp[0] = 64;
        }
        if (script->functionTemp[2] < 0) {
            script->functionTemp[2] = 0;
        }
    }
    set_model_env_color_parameters(
        script->functionTemp[0], script->functionTemp[0], script->functionTemp[0],
        script->functionTemp[2], script->functionTemp[2], script->functionTemp[2]
    );
    if (script->functionTemp[0] == 64 && script->functionTemp[2] == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80244308_804B88(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
    }
    script->functionTemp[0] += 4;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 255) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x2B)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x2A)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x29)), -1, 0);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

// identical to hos_06 func
// TODO may not be motionBlurFlame
ApiStatus func_802443E0_804C60(Evt* script, s32 isInitialCall) {
    EffectInstance* effects[3];
    Matrix4f sp28, sp68;
    f32 tx;
    f32 ty;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f30;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 180;
        script->functionTempPtr[1] = (EffectInstance*) evt_get_variable(script, ArrayVar(3));
        script->functionTempPtr[2] = (EffectInstance*) evt_get_variable(script, ArrayVar(4));
        script->functionTempPtr[3] = (EffectInstance*) evt_get_variable(script, ArrayVar(5));
    }

    effects[0] = script->functionTempPtr[1];
    effects[1] = script->functionTempPtr[2];
    effects[2] = script->functionTempPtr[3];
    temp_f30 = (sin_deg(script->functionTemp[0]) * 10.0f) + 10.0f;
    temp_f28 = (sin_deg(script->functionTemp[0]) * 25.0f) + 10.0f;
    temp_f24 = script->functionTemp[0] * 10;

    for (i = 0; i < ARRAY_COUNT(effects); i++) {
        guRotateF(sp28, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guRotateF(sp68, i * 120, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp68, sp28, sp28);
        tx = temp_f30 * sin_deg(temp_f24);
        ty = temp_f28 * cos_deg(temp_f24);
        guTranslateF(sp68, tx, ty, 0.0f);
        guMtxCatF(sp68, sp28, sp28);
        effects[i]->data.motionBlurFlame->pos.x = sp28[3][0];
        effects[i]->data.motionBlurFlame->pos.y = sp28[3][1];
        effects[i]->data.motionBlurFlame->pos.z = sp28[3][2];
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 16) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            effects[i]->data.motionBlurFlame->unk_4C = script->functionTemp[0];
        }
    }

    if (script->functionTemp[0] < 0) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            remove_effect(effects[i]);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

// identical to hos_06 func
ApiStatus func_802446AC_804F2C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO effect may be wrong
    effect->data.energyOrbWave->unk_1C++;
    return ApiStatus_DONE2;
}

#include "world/common/util/CheckPositionRelativeToPlane.inc.c"

ApiStatus func_802447E0_805060(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 10;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80244848_8050C8(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}

ApiStatus func_802448A0_805120(Evt* script, s32 isInitialCall) {
    s32 alpha;

    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            func_8011B950(script->varTable[15], -1, 1, 1);
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 32;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = 255 - script->functionTemp[0];
    }

    set_background_color_blend(0, 0, 0, alpha);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 3) {
            func_8011B950(script->varTable[15], -1, 0, 1);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80244984_805204(Evt* script, s32 isInitialCall) {
    s32 flagBase = GameFlag(1664);
    s32 count = 0;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (evt_get_variable(NULL, flagBase + i) == 0) {
            count++;
        }
    }
    script->varTable[0] = count;
    return ApiStatus_DONE2;
}

ApiStatus func_802449F8_805278(Evt* script, s32 isInitialCall) {
    s32 temp_s3 = -evt_get_variable(NULL, MapVar(1));
    s32 temp_s4 = evt_get_variable(NULL, MapVar(0));
    Npc* npc = script->varTablePtr[7];
    Enemy* enemy = get_enemy(2);
    f32 theta = (temp_s3 / 180.0f) * PI;
    f32 sinTheta = sin_rad(theta);
    f32 cosTheta = cos_rad(theta);
    f32 vt0 = script->varTable[0];
    f32 vt1 = script->varTable[1];

    script->varTable[4] = script->varTable[2] + (s32) ((vt0 * cosTheta) - (vt1 * sinTheta));
    script->varTable[5] = script->varTable[3] + (s32) ((vt0 * sinTheta) + (vt1 * cosTheta));

    if (temp_s3 == 0) {
        npc->currentAnim = 0xA70001;
        enemy->flags &= ~ENEMY_FLAGS_8000000;
    } else {
        npc->currentAnim = 0xA70002;
        enemy->flags |= ENEMY_FLAGS_8000000;
    }

    if (temp_s3 == -60) {
        npc->flags |= NPC_FLAG_2;
    } else {
        npc->flags &= ~NPC_FLAG_2;
    }

    if (temp_s4 != 0) {
        npc->currentAnim = 0xA70006;
    }
    return ApiStatus_DONE2;
}

void func_80244B98_805418(void) {
    s32 temp_s0 = evt_get_variable(NULL, MapVar(0));
    Vtx* sp10;
    Vtx* sp14;
    s32 numCopied;
    s32 i;

    mdl_get_copied_vertices(0, &sp10, &sp14, &numCopied);

    for (i = 0; i < numCopied; i++) {
        if (sp10[i].v.ob[0] == -0x4E) {
            Vtx* v14 = &sp14[i];

            if (sp10[i].v.ob[1] == 0) {
                v14->v.ob[1] = sp10[i].v.ob[1] - (temp_s0 / 4);
            } else {
                v14->v.ob[1] = sp10[i].v.ob[1] + (temp_s0 / 4);
            }
        } else if (sp10[i].v.ob[0] == -0x10) {
            Vtx* v14 = &sp14[i];

            if (sp10[i].v.ob[1] == 0) {
                v14->v.ob[1] = sp10[i].v.ob[1] - (temp_s0 / 4);
            } else {
                v14->v.ob[1] = sp10[i].v.ob[1] + (temp_s0 / 4);
            }
        }
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));
}

// flag clearing counterpart of UnkMachiFunc
ApiStatus func_80244CC0_805540(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableA) == 0) {
        clear_item_entity_flags(gGameStatusPtr->shopItemEntities[0].index, ITEM_ENTITY_FLAGS_40);
    }
    if (evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableB) == 0) {
        clear_item_entity_flags(gGameStatusPtr->shopItemEntities[1].index, ITEM_ENTITY_FLAGS_40);
    }
    if (evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableC) == 0) {
        clear_item_entity_flags(gGameStatusPtr->shopItemEntities[2].index, ITEM_ENTITY_FLAGS_40);
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkMachiFunc.inc.c"

ApiStatus func_80244E10_805690(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    set_item_entity_position(
        gGameStatusPtr->shopItemEntities[idx].index,
        script->varTable[0], script->varTable[1], script->varTable[2] + 6
    );
    return ApiStatus_DONE2;
}

typedef struct UnkMac01 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} UnkMac01; // size = 0x14
// same as UnkMac00 ?

extern UnkMac01 D_80256ADC_81735C[19];
extern UnkMac01 D_80256AEC_81736C[];
extern PopupMenu D_80262C38;

ApiStatus func_80244E90_805710(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 var_s2 = -1;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80256ADC_81735C); i++) {
        if (playerData->partners[D_80256ADC_81735C[i].unk_00].enabled &&
            (evt_get_variable(NULL, GameFlag(153 + i)) != 0))
        {
            if (evt_get_variable(NULL, GameFlag(172 + i)) == 0) {
                var_s2 = 1;
                break;
            } else {
                var_s2 = 0;
            }
        }
    }
    script->varTable[0] = var_s2;
    return ApiStatus_DONE2;
}

s32 func_80244F5C_8057DC(s32 arg0) {
    s32 ret = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80256ADC_81735C); i++) {
        if (D_80256ADC_81735C[i].unk_00 == arg0 && evt_get_variable(NULL, GameFlag(153 + i)) != 0) {
            if (ret == 0) {
                ret = 1;
            }
            if (evt_get_variable(NULL, GameFlag(172 + i)) == 0) {
                ret = 2;
                break;
            }
        }
    }
    return ret;
}

ApiStatus func_80245018_805898(Evt* script, s32 isInitialCall) {
    D_80262F68 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80245028_8058A8(Evt* script, s32 isInitialCall) {
    PopupMenu* menu = &D_80262C38;
    PartnerPopupProperties* temp_s2;
    PlayerData* playerData = &gPlayerData;
    s32 partnerID;
    s32 cond;
    s32 numEntries;
    s32 i;

    if (isInitialCall) {
        numEntries = 0;

        for (i = 1; i < 12; i++) {
            partnerID = D_8008EEC0[i];
            if (playerData->partners[partnerID].enabled && partnerID != PARTNER_GOOMPA) {
                temp_s2 = &gPartnerPopupProperties[partnerID];
                cond = func_80244F5C_8057DC(partnerID);
                if (cond) {
                    menu->ptrIcon[numEntries] = wPartnerHudScripts[partnerID];
                    menu->userIndex[numEntries] = partnerID;
                    menu->enabled[numEntries] = TRUE;
                    menu->nameMsg[numEntries] = temp_s2->nameMsg;
                    menu->descMsg[numEntries] = temp_s2->worldDescMsg;
                    menu->value[numEntries] = playerData->partners[partnerID].level;
                    if (cond == TRUE) {
                        menu->enabled[numEntries] = FALSE;
                        menu->ptrIcon[numEntries] = wDisabledPartnerHudScripts[partnerID];
                    }
                    numEntries++;
                }
            }
        }
        menu->popupType = POPUP_MENU_D;
        menu->numEntries = numEntries;
        menu->initialPos = D_80262F68;
        create_popup_menu(menu);
        status_menu_respond_to_changes();
        close_status_menu();
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 20) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1] == 0xFF) {
        script->varTable[1] = -1;
        return ApiStatus_DONE2;
    }
    partnerID = menu->userIndex[script->functionTemp[1] - 1];
    script->varTable[1] = partnerID; // TODO required to match (use of partnerID temp)
    D_80262F68 = script->functionTemp[1] - 1;
    return ApiStatus_DONE2;
}

ApiStatus func_8024522C_805AAC(Evt* script, s32 isInitialCall) {
    s32 vt10 = script->varTable[10];
    PopupMenu* menu = &D_80262C38;
    IconHudScriptPair* scriptPair;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 numEntries;
    u32 i;

    if (isInitialCall) {
        numEntries = 0;

        for (i = 0; i < ARRAY_COUNT(D_80256ADC_81735C); i++) {
            temp_s0 = evt_get_variable(NULL, GameFlag(153 + i));
            temp_a0 = evt_get_variable(NULL, GameFlag(172 + i));
            if (temp_s0 != 0 && vt10 == D_80256ADC_81735C[i].unk_00) {
                scriptPair = &gItemHudScripts[gItemTable[84].hudElemID];
                menu->userIndex[numEntries] = i;
                menu->nameMsg[numEntries] = D_80256ADC_81735C[i].unk_08;
                menu->descMsg[numEntries] = D_80256ADC_81735C[i].unk_0C;
                menu->value[numEntries] = 0;
                if (temp_a0 != 0) {
                    menu->ptrIcon[numEntries] = scriptPair->disabled;
                    menu->enabled[numEntries] = FALSE;
                } else {
                    menu->ptrIcon[numEntries] = scriptPair->enabled;
                    menu->enabled[numEntries] = TRUE;
                }
                numEntries++;
            }
        }
        menu->popupType = 8;
        menu->numEntries = numEntries;
        menu->initialPos = 0;
        create_popup_menu(menu);
        status_menu_respond_to_changes();
        close_status_menu();
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 20) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1] == 0xFF) {
        script->varTable[1] = -1;
        return ApiStatus_DONE2;
    }
    temp_a1 = menu->userIndex[script->functionTemp[1] - 1];
    script->varTable[1] = temp_a1;
    script->varTable[0] = D_80256AEC_81736C[temp_a1].unk_00;
    evt_set_variable(NULL, GameFlag(temp_a1 + 172), 1);
    return ApiStatus_DONE2;
}

ApiStatus func_80245440_805CC0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->currentPartner == script->varTable[10]) {
        script->varTable[1] = 0;
        return ApiStatus_DONE2;
    }

    switch_to_partner(script->varTable[10]);
    script->varTable[1] = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_80245488_805D08(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80258404_818C84 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_802454B4_805D34(void) {
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80258404_818C84 & 0xFF);
}

ApiStatus func_80245504_805D84(Evt* script, s32 isInitialCall) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_8024552C_805DAC(Evt* script, s32 isInitialCall) {
    repartner_set_tether_distance();
    return ApiStatus_DONE2;
}
