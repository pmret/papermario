#include "mac_01.h"
#include "effects.h"
#include "hud_element.h"

extern s32 D_80262F68;
extern PopupMenu D_80262C38;
extern IconHudScriptPair gItemHudScripts[];
extern EvtScript N(D_8025BB80_81C400);
extern EvtScript N(D_8025BAE0_81C360);
extern EvtScript N(D_8025BDDC_81C65C);
extern EvtScript N(D_80250414_810C94);

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/enemy/complete/ShyGuy_NoAI.inc.c"

NpcSettings N(NpcSettings_Ninji) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/npc/Twink.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/Bubulb.inc.c"

NpcSettings N(NpcSettings_Parakarry) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

extern IMG_BIN N(toad_house_blanket_img)[];
#include "mac_01_toad_house_blanket_skeleton.c"
#include "world/area_mac/mac_01/toad_house_blanket.vtx.inc.c"
#include "world/area_mac/mac_01/toad_house_blanket.gfx.inc.c"
#include "world/area_mac/mac_01/toad_house_blanket.png.inc.c"
#include "mac_01_toad_house_blanket_anim.c"

#include "world/common/todo/UnkFoldFunc.inc.c"

API_CALLABLE(N(func_80243380_803C00)) {
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

API_CALLABLE(N(func_80243494_803D14)) {
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    func_8013A854(temp_v0->foldID);
    free_worker(temp_v0->entityID);
    heap_free(temp_v0);
    evt_set_variable(script, MapVar(10), NULL);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243500_803D80)) {
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

API_CALLABLE(N(func_802435C0_803E40)) {
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

API_CALLABLE(N(func_80243680_803F00)) {
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

API_CALLABLE(N(func_80243740_803FC0)) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    return ApiStatus_DONE2;
}

#include "world/common/atomic/ToadHouse.inc.c"

EvtScript N(D_8024D3CC_80DC4C) = {
    EVT_CALL(EnableModel, LVar4, FALSE)
    EVT_CALL(EnableModel, LVar5, TRUE)
    EVT_CALL(RotateModel, LVar6, 0, 0, 0, 1)
    EVT_CALL(RotateModel, LVar7, 0, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D444_80DCC4) = {
    EVT_SET(LVar9, LVar7)
    EVT_SET(LVar8, LVar6)
    EVT_SET(LVar7, LVar5)
    EVT_SET(LVar6, LVar4)
    EVT_WAIT(70)
    EVT_CALL(EnableModel, LVar6, FALSE)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, TRUE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, EASING_CUBIC_IN)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LVar8, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, LVar9, LVar0, 0, 0, -1)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LVar7, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_10) = {
    EVT_CALL(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    EVT_EXEC_WAIT(N(D_8025BAE0_81C360))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVarA, LVar2)
    EVT_SET(LVarB, LVar3)
    EVT_CALL(N(ToadHouse_DoesPlayerNeedSleep))
    EVT_IF_EQ(LVar1, 0)
        EVT_SET(LVar8, LVar0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar8)
    EVT_CALL(ShowChoice, MSG_Choice_0006)
    EVT_WAIT(3)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar9)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVarA)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(N(ToadHouse_DisableStatusMenu))
    EVT_IF_NE(LVar4, 0)
        EVT_EXEC(N(D_8024D444_80DCC4))
    EVT_END_IF
    EVT_CALL(N(ToadHouse_PutPartnerAway), LVarA)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(D_8025BB80_81C400))
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 60, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(FullyRestoreHPandFP)
        EVT_CALL(FullyRestoreSP)
        EVT_IF_NE(LVar4, 0)
            EVT_EXEC(N(D_8024D3CC_80DC4C))
        EVT_END_IF
        EVT_CALL(N(ToadHouse_GetPartnerBackOut), LVarA)
        EVT_WAIT(45)
        EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(105)
    EVT_EXEC_WAIT(N(D_8025BDDC_81C65C))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVarB)
    EVT_CALL(N(ToadHouse_ShowStatusMenu))
    EVT_RETURN
    EVT_END
};

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

#include "world/common/todo/GetPlayerCoins.inc.c"

API_CALLABLE(N(func_802440FC_80497C)) {
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

API_CALLABLE(N(func_802441EC_804A6C)) {
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

API_CALLABLE(N(func_80244308_804B88)) {
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
API_CALLABLE(N(func_802443E0_804C60)) {
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
API_CALLABLE(N(func_802446AC_804F2C)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO effect may be wrong
    effect->data.energyOrbWave->unk_1C++;
    return ApiStatus_DONE2;
}

#include "world/common/util/CheckPositionRelativeToPlane.inc.c"

API_CALLABLE(N(func_802447E0_805060)) {
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

API_CALLABLE(N(func_80244848_8050C8)) {
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

API_CALLABLE(N(func_802448A0_805120)) {
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

API_CALLABLE(N(func_80244984_805204)) {
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

API_CALLABLE(N(func_802449F8_805278)) {
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

void N(func_80244B98_805418)(void) {
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
API_CALLABLE(N(func_80244CC0_805540)) {
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

API_CALLABLE(N(func_80244E10_805690)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    set_item_entity_position(
        gGameStatusPtr->shopItemEntities[idx].index,
        script->varTable[0], script->varTable[1], script->varTable[2] + 6
    );
    return ApiStatus_DONE2;
}

s32 N(D_8024E1EC_80EA6C)[] = {
    ITEM_LETTER01,
    ITEM_NONE
};

EvtScript N(D_8024E1F4_80EA74) = {
    EVT_CALL(N(LetterDelivery_Init), 0, 0x00A50004, 0x00A50001, 54, 0, 0x00030043, 0x00030044, 0x00030045, 0x00030046, EVT_PTR(N(D_8024E1EC_80EA6C)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E244_80EAC4) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_GIVE_STAR_PIECE()
        EVT_CALL(InterpNpcYaw, NPC_Merlon, 135, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_8024E2C0_80EB40)[] = {
    ITEM_LETTER09,
    ITEM_NONE 
};

EvtScript N(D_8024E2C8_80EB48) = {
    EVT_CALL(N(LetterDelivery_Init), 18, 0x00A80004, 0x00A80001, 62, 0, 0x00030078, 0x00030079, 0x0003007A, 0x0003007B, EVT_PTR(N(D_8024E2C0_80EB40)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E318_80EB98) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_8024E37C_80EBFC)[] = {
    ITEM_LETTER25,
    ITEM_NONE 
};

EvtScript N(D_8024E384_80EC04) = {
    EVT_CALL(N(LetterDelivery_Init), 19, 0x00B60008, 0x00B60001, 84, 0, 0x000300E0, 0x000300E1, 0x000300E2, 0x000300E3, EVT_PTR(N(D_8024E37C_80EBFC)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E3D4_80EC54) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_8024E438_80ECB8)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE 
};

EvtScript N(D_8024E440_80ECC0) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E8)
    EVT_GIVE_STAR_PIECE()
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E9)
    EVT_SET(GF_SBK_GaveArtifactToKolorado, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E4DC_80ED5C) = {
    EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_ARTIFACT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_MAC_44, FALSE)
        EVT_SET(AF_MAC_44, TRUE)
        EVT_IF_EQ(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(LVar0, 0x000300E4)
        EVT_ELSE
            EVT_SET(LVar0, 0x000300E5)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, 0x000300E5)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    EVT_SET(LVar0, EVT_PTR(N(D_8024E438_80ECB8)))
    EVT_SET(LVar1, 19)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_GE(1)
            EVT_EXEC_WAIT(N(D_8024E440_80ECC0))
            EVT_BREAK_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E6)
            EVT_SET(LVar0, EVT_PTR(N(D_8024E438_80ECB8)))
            EVT_SET(LVar1, 19)
            EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
            EVT_SWITCH(LVar0)
                EVT_CASE_GE(1)
                    EVT_EXEC_WAIT(N(D_8024E440_80ECC0))
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E7)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E6F8_80EF78) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_B0000021, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E740_80EFC0) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, -80, 30, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E7F0_80F070) = {
    EVT_CALL(MakeLerp, -80, 0, 30, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E8A0_80F120) = {
    EVT_CALL(EnableModel, MODEL_mirrorball, TRUE)
    EVT_SET(LVar0, 328)
    EVT_SET(LVar1, 0)
    EVT_LOOP(50)
        EVT_ADD(LVar0, -2)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(ArrayVar(6), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(150)
        EVT_ADD(LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 6)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(ArrayVar(6), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADD(LVar0, 2)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_mirrorball, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024EC64_80F4E4) = {
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_RaiseArms)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_207, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), -1)
    EVT_SET(ArrayVar(1), LVarF)
    EVT_WAIT(30)
    EVT_SET(ArrayVar(6), 0)
    EVT_EXEC(N(D_8024E8A0_80F120))
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(func_802440FC_80497C))
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(GetCamDistance, CAM_DEFAULT, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, EVT_FLOAT(284.6))
    EVT_ELSE
        EVT_SETF(LVar0, EVT_FLOAT(-284.6))
    EVT_END_IF
    EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar0)
    EVT_CALL(GetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    EVT_SETF(LVar1, EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(ArrayVar(6), 1)
    EVT_PLAY_EFFECT(EFFECT_MERLIN_HOUSE_STARS, 0, -298, 21, -330)
    EVT_SET(ArrayVar(2), LVarF)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(3), LVarF)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(4), LVarF)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(5), LVarF)
    EVT_THREAD
        EVT_CALL(N(func_802443E0_804C60))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_208, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 3, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(30)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_208, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 3, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(func_802441EC_804A6C))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_208, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(70)
    EVT_CALL(func_802D7B10, ArrayVar(2))
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_607, 0, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_802446AC_804F2C), ArrayVar(1))
    EVT_WAIT(15)
    EVT_CALL(func_802D7B10, ArrayVar(1))
    EVT_THREAD
        EVT_CALL(N(func_80244308_804B88))
    EVT_END_THREAD
    EVT_WAIT(46)
    EVT_SET(ArrayVar(6), 2)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024F27C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0036)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0039)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetPlayerCoins))
    EVT_IF_LT(LVar0, 5)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003A)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AddCoin, -5)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0037)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Gather1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Gather1, ANIM_Merlon_Gather1, 0, MSG_MAC_Plaza_0038)
    EVT_EXEC(N(EVS_80246824))
    EVT_WAIT(20)
    EVT_IF_EQ(MV_Unk_0C, 0)
        EVT_MALLOC_ARRAY(20, MV_Unk_0C)
    EVT_END_IF
    EVT_USE_ARRAY(MV_Unk_0C)
    EVT_EXEC_WAIT(N(D_8024EC64_80F4E4))
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_80246850))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MerlonHint_0000)
        EVT_CASE_LT(STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
            EVT_SET(LVar0, MSG_MerlonHint_0001)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0002)
        EVT_CASE_LT(STORY_CH1_SPOTTED_BY_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MerlonHint_0003)
        EVT_CASE_LT(STORY_CH1_BOMBETTE_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0004)
        EVT_CASE_LT(STORY_CH1_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_0005)
        EVT_CASE_LT(STORY_CH2_PARAKARRY_JOINED_PARTY)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_0006)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MerlonHint_0007)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH2_ARRIVED_AT_DRY_DRY_DESERT)
            EVT_SET(LVar0, MSG_MerlonHint_0008)
        EVT_CASE_LT(STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
            EVT_SET(LVar0, MSG_MerlonHint_0009)
        EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
            EVT_SET(LVar0, MSG_MerlonHint_000A)
        EVT_CASE_LT(STORY_CH2_BOUGHT_SECRET_ITEMS)
            EVT_SET(LVar0, MSG_MerlonHint_000B)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_SET(LVar0, MSG_MerlonHint_000C)
        EVT_CASE_LT(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            EVT_SET(LVar0, MSG_MerlonHint_000D)
        EVT_CASE_LT(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            EVT_SET(LVar0, MSG_MerlonHint_000E)
        EVT_CASE_LT(STORY_CH2_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_000F)
        EVT_CASE_LT(STORY_UNUSED_FFFFFFCC)
            EVT_SET(LVar0, MSG_MerlonHint_0010)
        EVT_CASE_LT(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            EVT_SET(LVar0, MSG_MerlonHint_0011)
        EVT_CASE_LT(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            EVT_SET(LVar0, MSG_MerlonHint_0012)
        EVT_CASE_LT(STORY_CH3_ENTERED_BOOS_MANSION)
            EVT_SET(LVar0, MSG_MerlonHint_0013)
        EVT_CASE_LT(STORY_CH3_GOT_WEIGHT)
            EVT_SET(LVar0, MSG_MerlonHint_0014)
        EVT_CASE_LT(STORY_CH3_WEIGHED_DOWN_CHANDELIER)
            EVT_SET(LVar0, MSG_MerlonHint_0015)
        EVT_CASE_LT(STORY_CH3_GOT_BOO_PORTRAIT)
            EVT_SET(LVar0, MSG_MerlonHint_0016)
        EVT_CASE_LT(STORY_CH3_BOW_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0017)
        EVT_CASE_LT(STORY_CH3_ARRIVED_AT_TUBBAS_MANOR)
            EVT_SET(LVar0, MSG_MerlonHint_0018)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_IF_EQ(GF_DGB06_Chest_CastleKey1, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_0019)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_IF_EQ(GF_DGB12_Chest_CastleKey1, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_001A)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_IF_EQ(GF_DGB16_Item_CastleKey1, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_001B)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LVar0, MSG_MerlonHint_001C)
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_001D)
        EVT_CASE_LT(STORY_CH4_FOUND_HIDDEN_DOOR)
            EVT_SET(LVar0, MSG_MerlonHint_001E)
        EVT_CASE_LT(STORY_CH4_GOT_STOREROOM_KEY)
            EVT_SET(LVar0, MSG_MerlonHint_001F)
        EVT_CASE_LT(STORY_CH4_GOT_TOY_TRAIN)
            EVT_SET(LVar0, MSG_MerlonHint_0020)
        EVT_CASE_LT(STORY_CH4_RETURNED_TOY_TRAIN)
            EVT_SET(LVar0, MSG_MerlonHint_0021)
        EVT_CASE_LT(STORY_CH4_GOT_FRYING_PAN)
            EVT_SET(LVar0, MSG_MerlonHint_0022)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MerlonHint_0023)
        EVT_CASE_LT(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            EVT_SET(LVar0, MSG_MerlonHint_0024)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_SET(LVar0, MSG_MerlonHint_0025)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_SET(LVar0, MSG_MerlonHint_0026)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0027)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_0028)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MerlonHint_0029)
        EVT_CASE_LT(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_SET(LVar0, MSG_MerlonHint_002A)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_SET(LVar0, MSG_MerlonHint_002B)
        EVT_CASE_LT(STORY_CH5_SUSHIE_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_002C)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_002D)
        EVT_CASE_LT(STORY_CH5_MOVED_RAVEN_STATUE)
            EVT_SET(LVar0, MSG_MerlonHint_002E)
        EVT_CASE_LT(STORY_CH5_RAFAEL_LEFT_NEST)
            EVT_SET(LVar0, MSG_MerlonHint_002F)
        EVT_CASE_LT(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            EVT_SET(LVar0, MSG_MerlonHint_0030)
        EVT_CASE_LT(STORY_CH5_GOT_ULTRA_HAMMER)
            EVT_SET(LVar0, MSG_MerlonHint_0031)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_0032)
        EVT_CASE_LT(STORY_CH5_TRADED_VASE_FOR_SEED)
            EVT_SET(LVar0, MSG_MerlonHint_0033)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MerlonHint_0034)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_SET(LVar0, MSG_MerlonHint_0035)
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_SET(LVar0, MSG_MerlonHint_0036)
        EVT_CASE_RANGE(STORY_CH6_GOT_FERTILE_SOIL, STORY_CH6_GOT_WATER_STONE)
            EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, FALSE)
                EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, FALSE)
                    EVT_SET(LVar0, MSG_MerlonHint_0037)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MerlonHint_0038)
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LVar0, MSG_MerlonHint_0039)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_SET(LVar0, MSG_MerlonHint_003A)
        EVT_CASE_LT(STORY_CH6_GREW_MAGIC_BEANSTALK)
            EVT_SET(LVar0, MSG_MerlonHint_003B)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_003C)
        EVT_CASE_LT(STORY_CH7_ARRIVED_AT_SHIVER_CITY)
            EVT_SET(LVar0, MSG_MerlonHint_003D)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SET(LVar0, MSG_MerlonHint_003E)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_SCARF)
            EVT_SET(LVar0, MSG_MerlonHint_003F)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_BUCKET)
            EVT_SET(LVar0, MSG_MerlonHint_0040)
        EVT_CASE_LT(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            EVT_SET(LVar0, MSG_MerlonHint_0041)
        EVT_CASE_LT(STORY_CH7_GOT_STAR_STONE)
            EVT_SET(LVar0, MSG_MerlonHint_0042)
        EVT_CASE_LT(STORY_CH7_ARRIVED_AT_CRYSTAL_PALACE)
            EVT_SET(LVar0, MSG_MerlonHint_0043)
        EVT_CASE_LT(STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            EVT_SET(LVar0, MSG_MerlonHint_0044)
        EVT_CASE_LT(STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
            EVT_SET(LVar0, MSG_MerlonHint_0045)
        EVT_CASE_LT(STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
            EVT_SET(LVar0, MSG_MerlonHint_0046)
        EVT_CASE_LT(STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
            EVT_SET(LVar0, MSG_MerlonHint_0047)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_0048)
        EVT_CASE_LT(STORY_CH8_REACHED_STAR_HAVEN)
            EVT_SET(LVar0, MSG_MerlonHint_0049)
        EVT_CASE_LT(STORY_CH8_REACHED_BOWSERS_CASTLE)
            EVT_SET(LVar0, MSG_MerlonHint_004A)
        EVT_CASE_LT(STORY_CH8_REACHED_PEACHS_CASTLE)
            EVT_IF_NE(GB_KPA81_BowserDoorState, 2)
                EVT_SET(LVar0, MSG_MerlonHint_004B)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_IF_NE(GB_KPA82_BowserDoorState, 1)
                EVT_SET(LVar0, MSG_MerlonHint_004C)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LVar0, MSG_MerlonHint_004D)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MerlonHint_004E)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, LVar0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024FE24_8106A4) = {
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ACTION_STATE_TORNADO_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ACTION_STATE_TORNADO_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_ADD(GB_MAC01_Merlon_SpinJumpCount, 1)
    EVT_IF_LT(GB_MAC01_Merlon_SpinJumpCount, 3)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(CheckPositionRelativeToPlane), -380, -245, -225, -408)
    EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
        EVT_SET(LVar2, -232)
        EVT_SET(LVar4, -331)
    EVT_ELSE
        EVT_SET(LVar2, -297)
        EVT_SET(LVar4, -393)
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_QUICK_CHANGE, LVar2, 220, LVar4, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_MAC01_Item_QuickChange)
    EVT_WAIT(35)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Run)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Merlon, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 5, MSG_MAC_Plaza_0041)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0042)
    EVT_SET(GF_MAC01_QuickChangeDropped, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8025023C) = {
    EVT_IF_EQ(GF_MAC01_QuickChangeDropped, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(D_8024FE24_8106A4)), TRIGGER_FLOOR_TOUCH, COLLIDER_dr_yuka, 1, 0)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_QUICK_CHANGE, -232, 20, -331, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC01_Item_QuickChange)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802502AC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_IF_EQ(GF_MAC01_Merlon_Shoo2, TRUE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001E, 160, 40)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_RETURN
            EVT_END_IF
            EVT_IF_EQ(GF_MAC01_Merlon_Shoo1, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001C, 160, 40)
                EVT_SET(GF_MAC01_Merlon_Shoo1, TRUE)
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001D, 160, 40)
                EVT_SET(GF_MAC01_Merlon_Shoo2, TRUE)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH0_MET_STAR_SPIRITS)
            EVT_IF_EQ(GF_MAC01_Merlon_Shoo3, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001F, 160, 40)
                EVT_SET(GF_MAC01_Merlon_Shoo3, TRUE)
            EVT_ELSE
                EVT_EXEC_WAIT(N(D_80250414_810C94))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250414_810C94) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_0020, 160, 40)
    EVT_CALL(SetGroupEnabled, MODEL_dr_in, 1)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_CALL(MakeLerp, 0, -80, 15, EASING_COS_FAST_OVERSHOOT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetPlayerFlagBits, PS_FLAGS_NO_FLIPPING, TRUE)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_FallBack)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump1, -222, 20, -158, 8)
        EVT_WAIT(5)
        EVT_CALL(SetPlayerFlagBits, PS_FLAGS_NO_FLIPPING, FALSE)
        EVT_CALL(N(func_80243380_803C00), 1, 37)
        EVT_CALL(N(func_80243500_803D80), -215, 20, -158)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerPos, -215, 1000, -158)
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(func_802435C0_803E40), LVar0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(N(func_80243500_803D80), -215, 21, -158)
        EVT_CALL(PlaySoundAtPlayer, SOUND_162, 0)
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(SetNpcPos, NPC_Merlon, -241, 20, -270)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, -168, -198, 20)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(GetAngleToPlayer, NPC_Merlon, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Merlon, LVar0, 5)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0021)
    EVT_CALL(N(func_80243500_803D80), -215, 20, -158)
    EVT_CALL(MakeLerp, 90, 0, 15, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_802435C0_803E40), LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, -222, 20, -158)
    EVT_CALL(N(func_80243494_803D14))
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 15)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0022)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
        EVT_CALL(NpcMoveTo, NPC_Merlon, -275, -305, 30)
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
        EVT_CALL(SetNpcPos, NPC_Merlon, -337, 20, -360)
        EVT_CALL(SetNpcYaw, NPC_Merlon, 135)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -168, -198, 20)
    EVT_CALL(PlayerMoveTo, -275, -305, 30)
    EVT_EXEC(N(D_8024E7F0_80F070))
    EVT_WAIT(5)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -240, 20, -284)
    EVT_CALL(N(func_802447E0_805060))
    EVT_THREAD
        EVT_SET(LVarF, 53)
        EVT_SET(LVar0, 0)
        EVT_CALL(N(func_802448A0_805120))
    EVT_END_THREAD
    EVT_CALL(RotateGroup, MODEL_off_kabe, 180, 0, 1, 0)
    EVT_SET(MF_MusicMixTrigger1, TRUE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 20, -280)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30)
    EVT_CALL(N(func_80244848_8050C8))
    EVT_CALL(InterpNpcYaw, NPC_Merlon, 135, 5)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0023)
    EVT_CALL(N(func_802447E0_805060))
    EVT_WAIT(60)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001D)
    EVT_THREAD
        EVT_CALL(N(func_80244848_8050C8))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0024)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001E)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001C)
    EVT_WAIT(50)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0025)
    EVT_SET(GB_StoryProgress, STORY_CH1_SPOKE_WITH_MERLIN)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_THREAD
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(AwaitPlayerLeave, -280, -300, 40)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250D14_811594) = {
    EVT_CALL(AwaitPlayerApproach, -130, -110, 150)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_8000000, 1)
    EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_100 | NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(NpcMoveTo, NPC_Merlon, 0, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_Merlon, 410, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Merlon, 410, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_8000000, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_100 | NPC_FLAG_GRAVITY, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250DFC_81167C) = {
    EVT_CALL(SetNpcVar, NPC_Merlon, 0, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(4.0))
        EVT_CALL(NpcMoveTo, NPC_Merlon, 410, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Merlon, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_0029)
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_002A)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar0, 410)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), 410, 0, 0, 320, 15, -6)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 460, 0, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_002B)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 480, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlayerFaceNpc, NPC_DarkToad_01, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Dismiss, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_002C)
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Dismiss, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_002D)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 410, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_002E)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_Merlon, SOUND_209, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Gather1)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 12, LVar0, LVar1, LVar2, 1, 50)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_RaiseArms)
    EVT_WAIT(5)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, 1, 20)
    EVT_ADD(LVar1, 180)
    EVT_CALL(PlayerFaceNpc, NPC_DarkToad_01, FALSE)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), 480, 0, 0, 320, 15, -6)
    EVT_CALL(PushSong, 82, 0)
    EVT_THREAD
        EVT_SET(MF_Unk_14, FALSE)
        EVT_WAIT(5)
        EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Anim0B, ANIM_KoopaBros_Red_Anim0B, 5, MSG_MAC_Plaza_002F)
        EVT_SET(MF_Unk_14, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_20A, 0)
        EVT_CALL(GetNpcPos, NPC_DarkToad_01, LVar3, LVar4, LVar5)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        EVT_CALL(SetNpcAnimation, NPC_DarkToad_01, ANIM_DarkToad_Red_Hurt)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_2049, 0)
        EVT_CALL(GetNpcPos, NPC_DarkToad_01, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcPos, NPC_DarkToad_01, LVar3, -1000, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_01, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Anim0B)
        EVT_CALL(NpcJump0, NPC_KoopaBros_01, LVar3, LVar4, LVar5, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_20A, 0)
        EVT_CALL(GetNpcPos, NPC_DarkToad_02, LVar3, LVar4, LVar5)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        EVT_CALL(SetNpcAnimation, NPC_DarkToad_02, ANIM_DarkToad_Black_Hurt)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_02, SOUND_2049, 0)
        EVT_CALL(GetNpcPos, NPC_DarkToad_02, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcPos, NPC_DarkToad_02, LVar3, -1000, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_02, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Anim0B)
        EVT_CALL(NpcJump0, NPC_KoopaBros_02, LVar3, LVar4, LVar5, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_20A, 0)
        EVT_CALL(GetNpcPos, NPC_DarkToad_03, LVar3, LVar4, LVar5)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        EVT_CALL(SetNpcAnimation, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Hurt)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_03, SOUND_2049, 0)
        EVT_CALL(GetNpcPos, NPC_DarkToad_03, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcPos, NPC_DarkToad_03, LVar3, -1000, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_03, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_03, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Anim0B)
        EVT_CALL(NpcJump0, NPC_KoopaBros_03, LVar3, LVar4, LVar5, 10)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_20A, 0)
    EVT_CALL(GetNpcPos, NPC_DarkToad_04, LVar3, LVar4, LVar5)
    EVT_ADD(LVar5, 5)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
    EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
    EVT_CALL(SetNpcAnimation, NPC_DarkToad_04, ANIM_DarkToad_Green_Hurt)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_04, SOUND_2049, 0)
    EVT_CALL(GetNpcPos, NPC_DarkToad_04, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcPos, NPC_DarkToad_04, LVar3, -1000, LVar2)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_04, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_04, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Anim0B)
    EVT_CALL(NpcJump0, NPC_KoopaBros_04, LVar3, LVar4, LVar5, 10)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_LOOP(0)
        EVT_IF_EQ(MF_Unk_14, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Anim04)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0030)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Anim14, ANIM_KoopaBros_Red_Anim04, 0, MSG_MAC_Plaza_0031)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Anim14, ANIM_KoopaBros_Red_Anim04, 5, MSG_MAC_Plaza_0032)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_02, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_03, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_04, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Anim03)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_174, 0)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(8.0))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, 700, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_02, EVT_FLOAT(8.0))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, 700, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_03, EVT_FLOAT(8.0))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_03, 700, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros_04, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_04, 700, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(PopSong)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 410, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0033)
    EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(3.0))
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, LVar3, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0034)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(ResetCam, CAM_DEFAULT, 2)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -150)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Merlon, 133, 0)
    EVT_CALL(SetNpcPos, NPC_Merlon, -337, 20, -360)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
    EVT_SET(AF_MAC_0E, FALSE)
    EVT_SET(AF_MAC_0F, FALSE)
    EVT_SET(AF_MAC_10, FALSE)
    EVT_SET(AF_MAC_11, FALSE)
    EVT_SET(AF_MAC_12, FALSE)
    EVT_SET(AF_MAC_13, FALSE)
    EVT_SET(AF_MAC_14, FALSE)
    EVT_CALL(RemoveEncounter, NPC_KoopaBros_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Merlon) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_IF_EQ(GF_MAC01_Merlon_HintFromDarkToads, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0026)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0027)
                EVT_SET(GB_StoryProgress, STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
                EVT_CHILD_THREAD
                    EVT_LOOP(0)
                        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CHILD_THREAD
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_100, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(4.0))
                EVT_CALL(NpcMoveTo, NPC_Merlon, -350, -280, 0)
                EVT_CALL(NpcMoveTo, NPC_Merlon, -230, -270, 0)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_100, FALSE)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_OPEN, 0)
                EVT_CALL(MakeLerp, 0, -80, 15, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(NpcMoveTo, NPC_Merlon, -163, -217, 0)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(MakeLerp, -80, 0, 15, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_CLOSE, 0)
                EVT_CALL(SetNpcPos, NPC_SELF, -150, 10, -160)
                EVT_CALL(SetNpcYaw, NPC_Merlon, 90)
                EVT_EXEC(N(D_80250D14_811594))
            EVT_END_IF
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0028)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0035)
        EVT_CASE_EQ(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_004C)
        EVT_CASE_GE(STORY_CH3_GOT_SUPER_BOOTS)
            EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                EVT_SET(LVar0, 0x0003003E)
                EVT_IF_GE(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
                        EVT_SET(LVar0, 0x0003003D)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, LVar0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(GetNpcPos, NPC_Merlon, LVar3, LVar4, LVar5)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_ADDF(LVar0, LVar3)
                EVT_ADDF(LVar1, LVar4)
                EVT_ADDF(LVar2, LVar5)
                EVT_DIVF(LVar0, EVT_FLOAT(2.0))
                EVT_DIVF(LVar1, EVT_FLOAT(2.0))
                EVT_DIVF(LVar2, EVT_FLOAT(2.0))
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003F)
                EVT_THREAD
                    EVT_LOOP(0)
                        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
                        EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, TRUE)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_100, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_Merlon, -170, -225, 0)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                EVT_CALL(SetGroupEnabled, MODEL_dr_in, 1)
                EVT_EXEC_WAIT(N(D_8024E740_80EFC0))
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_Merlon, -265, -300, 0)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                EVT_EXEC_WAIT(N(D_8024E7F0_80F070))
                EVT_CALL(SetGroupEnabled, MODEL_dr_in, 0)
                EVT_SET(GF_MAC01_Merlon_HeardAboutDream, TRUE)
                EVT_CALL(InterpNpcYaw, NPC_Merlon, 133, 0)
                EVT_CALL(SetNpcPos, NPC_Merlon, -337, 20, -360)
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_100, FALSE)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                EVT_RETURN
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_QuickChangeDropped, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0040)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_003B)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_003B)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(D_8024E1F4_80EA74))
    EVT_EXEC_WAIT(N(D_8024E244_80EAC4))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Merlon) = {
    EVT_CALL(InterpNpcYaw, NPC_SELF, 133, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_CALL(SetNpcPos, NPC_SELF, 410, 0, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_RANGE(STORY_CH6_RETURNED_TO_TOAD_TOWN, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_GE(STORY_CH3_GOT_SUPER_BOOTS)
            EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                EVT_CALL(SetNpcPos, NPC_Merlon, -135, 20, -250)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Think)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
            EVT_ELSE
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Merlon)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_DarkToad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_004D)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_004E)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Talk, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_004F)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Talk, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_0050)
        EVT_CASE_LT(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, 300, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_0051)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_0052)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Talk, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_0053)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Talk, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_0054)
            EVT_SET(GF_MAC01_Merlon_HintFromDarkToads, TRUE)
            EVT_CALL(ResetCam, CAM_DEFAULT, 5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_DarkToad_01) = {
    EVT_LOOP(0)
        EVT_IF_GE(GB_StoryProgress, STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_SET(LVar0, 0)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_SWITCH(LVar1)
                EVT_CASE_GE(460)
                    EVT_ADD(LVar0, 1)
            EVT_END_SWITCH
            EVT_SWITCH(LVar3)
                EVT_CASE_RANGE(-50, 70)
                    EVT_ADD(LVar0, 1)
            EVT_END_SWITCH
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(PartnerCanUseAbility, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(D_80250DFC_81167C))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DarkToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_DarkToad_01)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_DarkToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DarkToad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_DarkToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80252EB0) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Ninji, -278, 20, -376)
    EVT_CALL(SetNpcYaw, NPC_Ninji, 0)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -276, -305, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0047)
    EVT_CALL(NpcFacePlayer, NPC_Ninji, 5)
    EVT_WAIT(15)
    EVT_CALL(GetNpcPos, NPC_Ninji, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, 4, LVar0, LVar1, LVar2, 250, 15, -9)
    EVT_CALL(SpeakToPlayer, NPC_Ninji, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_MAC_Plaza_0048)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0049)
    EVT_CALL(ResetCam, CAM_DEFAULT, 5)
    EVT_CALL(SpeakToPlayer, NPC_Ninji, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_MAC_Plaza_004A)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Ninji, ANIM_Ninji_Walk)
        EVT_CALL(NpcMoveTo, NPC_Ninji, -230, -260, 0)
        EVT_CALL(NpcMoveTo, NPC_Ninji, -185, -194, 0)
        EVT_CALL(SetNpcPos, NPC_Ninji, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_004B)
    EVT_SET(GB_StoryProgress, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Merlon) = {
    .defaultAnim = ANIM_Merlon_Idle,
    .height = 36,
    .radius = 32,
    .level = 99,
};

StaticNpc N(NpcData_Merlon) = {
    .id = NPC_Merlon,
    .settings = &N(NpcSettings_Merlon),
    .pos = { -337.0f, 20.0f, -360.0f },
    .yaw = 30,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
    .init = &N(EVS_NpcInit_Merlon),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Merlon_Idle,
    },
    .tattle = MSG_NpcTattle_Merlon,
};

StaticNpc N(NpcData_DarkToads)[] = {
    {
        .id = NPC_DarkToad_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 505.0f, 0.0f, 5.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_DarkToad_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_DarkToad_Red_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadA,
    },
    {
        .id = NPC_DarkToad_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 530.0f, 0.0f, -35.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_DarkToad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_DarkToad_Black_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadB,
    },
    {
        .id = NPC_DarkToad_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 540.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_DarkToad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_DarkToad_Yellow_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadC,
    },
    {
        .id = NPC_DarkToad_04,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 550.0f, 0.0f, 35.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_DarkToad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_DarkToad_Green_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadD,
    },
};

s32 N(ExtraAnims_KoopaBros)[] = {
    ANIM_KoopaBros_Black_Anim03,
    ANIM_KoopaBros_Black_Anim04,
    ANIM_KoopaBros_Black_Anim0B,
    ANIM_KoopaBros_Black_Anim14,
    -1
};

StaticNpc N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoopaBros_Black_Anim04,
            .walk   = ANIM_KoopaBros_Black_Anim02,
            .run    = ANIM_KoopaBros_Black_Anim03,
            .chase  = ANIM_KoopaBros_Black_Anim03,
            .anim_4 = ANIM_KoopaBros_Black_Anim04,
            .anim_5 = ANIM_KoopaBros_Black_Anim04,
            .death  = ANIM_KoopaBros_Black_Anim0A,
            .hit    = ANIM_KoopaBros_Black_Anim0A,
            .anim_8 = ANIM_KoopaBros_Black_Anim03,
            .anim_9 = ANIM_KoopaBros_Black_Anim03,
            .anim_A = ANIM_KoopaBros_Black_Anim03,
            .anim_B = ANIM_KoopaBros_Black_Anim03,
            .anim_C = ANIM_KoopaBros_Black_Anim03,
            .anim_D = ANIM_KoopaBros_Black_Anim03,
            .anim_E = ANIM_KoopaBros_Black_Anim03,
            .anim_F = ANIM_KoopaBros_Black_Anim03,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBros_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoopaBros_Red_Anim04,
            .walk   = ANIM_KoopaBros_Red_Anim02,
            .run    = ANIM_KoopaBros_Red_Anim03,
            .chase  = ANIM_KoopaBros_Red_Anim03,
            .anim_4 = ANIM_KoopaBros_Red_Anim04,
            .anim_5 = ANIM_KoopaBros_Red_Anim04,
            .death  = ANIM_KoopaBros_Red_Anim0A,
            .hit    = ANIM_KoopaBros_Red_Anim0A,
            .anim_8 = ANIM_KoopaBros_Red_Anim03,
            .anim_9 = ANIM_KoopaBros_Red_Anim03,
            .anim_A = ANIM_KoopaBros_Red_Anim03,
            .anim_B = ANIM_KoopaBros_Red_Anim03,
            .anim_C = ANIM_KoopaBros_Red_Anim03,
            .anim_D = ANIM_KoopaBros_Red_Anim03,
            .anim_E = ANIM_KoopaBros_Red_Anim03,
            .anim_F = ANIM_KoopaBros_Red_Anim03,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBros_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoopaBros_Yellow_Anim04,
            .walk   = ANIM_KoopaBros_Yellow_Anim02,
            .run    = ANIM_KoopaBros_Yellow_Anim03,
            .chase  = ANIM_KoopaBros_Yellow_Anim03,
            .anim_4 = ANIM_KoopaBros_Yellow_Anim04,
            .anim_5 = ANIM_KoopaBros_Yellow_Anim04,
            .death  = ANIM_KoopaBros_Yellow_Anim0A,
            .hit    = ANIM_KoopaBros_Yellow_Anim0A,
            .anim_8 = ANIM_KoopaBros_Yellow_Anim03,
            .anim_9 = ANIM_KoopaBros_Yellow_Anim03,
            .anim_A = ANIM_KoopaBros_Yellow_Anim03,
            .anim_B = ANIM_KoopaBros_Yellow_Anim03,
            .anim_C = ANIM_KoopaBros_Yellow_Anim03,
            .anim_D = ANIM_KoopaBros_Yellow_Anim03,
            .anim_E = ANIM_KoopaBros_Yellow_Anim03,
            .anim_F = ANIM_KoopaBros_Yellow_Anim03,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBros_04,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoopaBros_Green_Anim04,
            .walk   = ANIM_KoopaBros_Green_Anim02,
            .run    = ANIM_KoopaBros_Green_Anim03,
            .chase  = ANIM_KoopaBros_Green_Anim03,
            .anim_4 = ANIM_KoopaBros_Green_Anim04,
            .anim_5 = ANIM_KoopaBros_Green_Anim04,
            .death  = ANIM_KoopaBros_Green_Anim0A,
            .hit    = ANIM_KoopaBros_Green_Anim0A,
            .anim_8 = ANIM_KoopaBros_Green_Anim03,
            .anim_9 = ANIM_KoopaBros_Green_Anim03,
            .anim_A = ANIM_KoopaBros_Green_Anim03,
            .anim_B = ANIM_KoopaBros_Green_Anim03,
            .anim_C = ANIM_KoopaBros_Green_Anim03,
            .anim_D = ANIM_KoopaBros_Green_Anim03,
            .anim_E = ANIM_KoopaBros_Green_Anim03,
            .anim_F = ANIM_KoopaBros_Green_Anim03,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
};

StaticNpc N(NpcData_Ninji) = {
    .id = NPC_Ninji,
    .settings = &N(NpcSettings_Ninji),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Ninji_Idle,
        .walk   = ANIM_Ninji_Walk,
        .run    = ANIM_Ninji_Idle,
        .chase  = ANIM_Ninji_Idle,
        .anim_4 = ANIM_Ninji_Idle,
        .anim_5 = ANIM_Ninji_Idle,
        .death  = ANIM_Ninji_Idle,
        .hit    = ANIM_Ninji_Idle,
        .anim_8 = ANIM_Ninji_Idle,
        .anim_9 = ANIM_Ninji_Idle,
        .anim_A = ANIM_Ninji_Idle,
        .anim_B = ANIM_Ninji_Idle,
        .anim_C = ANIM_Ninji_Idle,
        .anim_D = ANIM_Ninji_Idle,
        .anim_E = ANIM_Ninji_Idle,
        .anim_F = ANIM_Ninji_Idle,
    },
    .tattle = MSG_NpcTattle_MAC_PowerHungryToadKid,
};

EvtScript N(EVS_NpcInteract_Toad_01_A) = {
    EVT_IF_EQ(GF_MAC01_Met_Rowf_Early, FALSE)
        EVT_SET(GF_MAC01_Met_Rowf_Early, TRUE)
        EVT_SET(AF_MAC_41, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0000)
    EVT_ELSE
        EVT_IF_EQ(AF_MAC_41, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0001)
        EVT_ELSE
            EVT_SET(AF_MAC_41, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Think, 0, MSG_MAC_Plaza_0002)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01_B) = {
    EVT_SET(LVar0, GF_MAC01_RowfBadgeAvailableA)
    EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableB)
    EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableC)
    EVT_IF_EQ(LVar0, 3)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
            EVT_SET(LVar1, 0x00030005)
        EVT_ELSE
            EVT_CALL(N(func_80244984_805204))
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar1, 0x00030006)
            EVT_ELSE
                EVT_SET(LVar1, 0x00030005)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, LVar1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Met_Rowf_Late, FALSE)
        EVT_SET(GF_MAC01_Met_Rowf_Late, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0003)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0004)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80254858_8150D8)[] = {
    ITEM_CALCULATOR,
    ITEM_NONE 
};

EvtScript N(EVS_NpcInteract_Toad_01_C) = {
    EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_000A)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0008)
    EVT_SET(LVar0, EVT_PTR(N(D_80254858_8150D8)))
    EVT_SET(LVar1, 1)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_000B)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0009)
            EVT_WAIT(10)
            EVT_SET(LVar0, ITEM_I_SPY)
            EVT_SET(LVar3, 2)
            EVT_EXEC_WAIT(N(GiveKeyReward))
            EVT_CALL(AddBadge, LVar0, LVar1)
            EVT_SET(GF_MAC01_CalculatorReturned, TRUE)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0011)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02_A) = {
    EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02_B) = {
    EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0014)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02_C) = {
    EVT_CALL(N(func_80244984_805204))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000F)
    EVT_ELSE
        EVT_SET(LVar0, GF_MAC01_RowfBadgeAvailableA)
        EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableB)
        EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableC)
        EVT_IF_EQ(LVar0, 3)
            EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000E)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000D)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02_D) = {
    EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0012)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0010)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_01) = {
    EVT_CALL(SetNpcPos, NPC_Toad_01, -250, 0, 295)
    EVT_LABEL(0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Still)
    EVT_CALL(NpcMoveTo, NPC_Toad_01, -260, 281, 4)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Walk)
    EVT_CALL(NpcMoveTo, NPC_Toad_01, -410, 281, 60)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Idle)
    EVT_CALL(RotateGroup, MODEL_jutan2, 60, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Toad_01, -407, 0, 281)
    EVT_CALL(RotateGroup, MODEL_jutan2, 40, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Toad_01, -404, 0, 281)
    EVT_CALL(RotateGroup, MODEL_jutan2, 20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Toad_01, -401, 0, 281)
    EVT_CALL(RotateGroup, MODEL_jutan2, 0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Still)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_Toad_02, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Think)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_WaveOff)
            EVT_WAIT(1)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Idle)
            EVT_WAIT(20)
        EVT_END_LOOP
        EVT_LOOP(3)
            EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_WaveOff)
            EVT_WAIT(1)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Idle)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Still)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Idle)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Walk)
    EVT_CALL(NpcMoveTo, NPC_Toad_01, -250, 295, 60)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Idle)
    EVT_WAIT(3)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_WaveOff)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Cheer)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Still)
    EVT_CALL(InterpNpcYaw, NPC_Toad_02, -90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Talk)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Still)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Think)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Talk)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Talk)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Idle)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_jutan2, LVar0, 0, 0, 1)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(ShowEmote, NPC_Toad_02, EMOTE_SHOCK, -45, 20, TRUE, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Still)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Rowf_Still)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_02_C) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -225, 0, 330)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_SET(LVar0, 0)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_LT(LVar1, 50)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_SWITCH(LVar3)
            EVT_CASE_RANGE(280, 380)
                EVT_ADD(LVar0, 1)
        EVT_END_SWITCH
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0013)
    EVT_THREAD
        EVT_CALL(func_802D1270, -280, 330, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, -305, 330, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0014)
    EVT_SET(GF_MAC01_Met_Rhuff, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_02_D) = {
    EVT_SET(LVar0, EVT_FLOAT(53.0))
    EVT_SET(LVar1, EVT_FLOAT(-192.0))
    EVT_SET(LVar2, EVT_FLOAT(-300.0))
    EVT_SET(LVar3, EVT_FLOAT(425.0))
    EVT_CALL(GetNpcPointer, NPC_Toad_02, LVar7)
    EVT_LOOP(0)
        EVT_CALL(N(func_802449F8_805278))
        EVT_CALL(SetNpcPos, NPC_Toad_02, LVar4, 0, LVar5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_802555AC_815E2C)[] = {
    600, 0, 598, 0, 595, 0, 590, 0, 
    583, 0, 574, 0, 562, 0, 547, 0, 
    529, 0, 509, 0, 489, 0, 469, 0, 
    449, 0, 429, 0, 409, 0, 389, 0, 
    369, 0, 349, 0, 329, 0, 309, 0, 
    289, 0, 269, 0, 249, 0, 229, 0, 
    209, 0, 189, 0, 169, 0, 149, 0, 
    129, 0, 109, 0, 89, 0, 69, 0, 
    49, 0, 29, 0, 9, 0, -11, -11, 
    -16, -16, -18, -18, -19, -19, -19, -19, 
    -19, -19, -19, -19, -15, -15, -5, -5, 
    2, 2, 3, 3, 1, 1, 0, 0, 
    0, 0, 0, 0, 
};

EvtScript N(D_8025573C_815FBC) = {
    EVT_SET(MF_Unk_0B, TRUE)
    EVT_CALL(SetNpcYaw, NPC_Toad_01, 270)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_A9, 0, -220, 37, 271)
        EVT_CALL(MakeLerp, 0, -220, 30, EASING_COS_BOUNCE)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_omote, LVar0, 1, 0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(4)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -120, 10, EASING_COS_SLOW_OVERSHOOT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_omote2, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 100, 5, EASING_COS_SLOW_OVERSHOOT)
        EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_ura, 0, 0, LVar0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(EnableModel, MODEL_ju_1, TRUE)
    EVT_CALL(N(func_80244CC0_805540))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o295, SOUND_AA, 0)
    EVT_USE_BUF(EVT_PTR(N(D_802555AC_815E2C)))
    EVT_LOOP(50)
        EVT_BUF_READ2(LVar0, MV_Unk_00)
        EVT_CALL(RotateGroup, MODEL_jutan2, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_SET(MV_Unk_01, LVar0)
        EVT_CALL(RotateGroup, MODEL_jutan1, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(200.0))
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(ScaleGroup, MODEL_jutan2, LVar0, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(NpcJump0, NPC_Toad_01, -213, 6, 256, 16)
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80255B30_8163B0) = {
    EVT_SET(MF_Unk_0B, FALSE)
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(NpcJump0, NPC_Toad_01, -220, -54, 261, 16)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o295, SOUND_AC, 0)
        EVT_CALL(MakeLerp, 0, 600, 50, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_jutan2, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_SET(MV_Unk_01, LVar0)
        EVT_CALL(RotateGroup, MODEL_jutan1, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(200.0))
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(ScaleGroup, MODEL_jutan2, LVar0, 1, LVar0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(EnableModel, MODEL_ju_1, FALSE)
        EVT_CALL(N(UnkMachiFunc))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(MakeLerp, -220, 0, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_omote, LVar0, 1, 0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_AB, 0, -220, 37, 271)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(MakeLerp, -120, 0, 10, EASING_COS_IN_OUT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_omote2, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 0, 5, EASING_COS_IN_OUT)
        EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_ura, 0, 0, LVar0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(31)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80255F60_8167E0) = {
    EVT_IF_GE(MV_Unk_0D, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(MV_Unk_0E, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MF_Unk_0B, TRUE)
    EVT_SET(MV_Unk_0D, 1)
    EVT_EXEC_WAIT(N(D_8025573C_815FBC))
    EVT_SET(MV_Unk_0D, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80255FEC_81686C) = {
    EVT_IF_EQ(MV_Unk_0D, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_Unk_0E, 1)
    EVT_SET(MF_Unk_0B, FALSE)
    EVT_LABEL(10)
    EVT_IF_EQ(MV_Unk_0D, 1)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(MV_Unk_0E, 2)
    EVT_EXEC_WAIT(N(D_80255B30_8163B0))
    EVT_SET(MV_Unk_0D, 0)
    EVT_SET(MV_Unk_0E, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_SET(MV_Unk_0D, 0)
    EVT_SET(MV_Unk_0E, 0)
    EVT_SET(AF_MAC_40, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_JR_TROOPA)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01_A)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_01)))
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01_B)))
            EVT_SET(AF_MAC_40, TRUE)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01_B)))
                EVT_SET(AF_MAC_40, TRUE)
            EVT_ELSE
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01_C)))
                EVT_CALL(SetNpcPos, NPC_Toad_01, -250, 0, 295)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(AF_MAC_41, FALSE)
    EVT_CALL(SetModelFlags, MODEL_ju_2, 512, FALSE)
    EVT_CALL(EnableGroup, MODEL_jutan1, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(RotateGroup, MODEL_jutan1, 60, 0, 1, 0)
    EVT_CALL(RotateGroup, MODEL_jutan2, 0, 0, 1, 0)
    EVT_CALL(ScaleGroup, MODEL_jutan2, EVT_FLOAT(1.3), 1, EVT_FLOAT(1.3))
    EVT_SET(MV_Unk_01, 60)
    EVT_CALL(MakeLocalVertexCopy, 0, MODEL_ju_1, TRUE)
    EVT_CALL(SetCustomGfxBuilders, 0, EVT_PTR(N(func_80244B98_805418)), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_ju_1, 0, -1)
    EVT_IF_EQ(AF_MAC_40, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(D_80255F60_8167E0)), TRIGGER_FLOOR_TOUCH, COLLIDER_roten, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(D_80255FEC_81686C)), TRIGGER_FLOOR_TOUCH, COLLIDER_o444, 1, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Toad_01, 1)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetModelFlags, MODEL_b1, 4, FALSE)
        EVT_CALL(SetModelFlags, MODEL_b2, 4, FALSE)
        EVT_CALL(SetModelFlags, MODEL_b3, 4, FALSE)
        EVT_CALL(N(UnkMachiFunc))
        EVT_LABEL(0)
        EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, FALSE)
            EVT_CALL(GetModelCenter, MODEL_b3)
            EVT_CALL(N(func_80244E10_805690), 0)
        EVT_END_IF
        EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, FALSE)
            EVT_CALL(GetModelCenter, MODEL_b2)
            EVT_CALL(N(func_80244E10_805690), 1)
        EVT_END_IF
        EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, FALSE)
            EVT_CALL(GetModelCenter, MODEL_b1)
            EVT_CALL(N(func_80244E10_805690), 2)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(SetNpcScale, NPC_Toad_02, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(0.75))
    EVT_CALL(SetNpcPos, NPC_Toad_02, -230, 0, 320)
    EVT_CALL(InterpNpcYaw, NPC_Toad_02, -90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Toad_02, ANIM_Rowf_Idle)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_JR_TROOPA)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02_A)))
        EVT_CASE_LT(STORY_CH2_BEGAN_PEACH_MISSION)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02_B)))
            EVT_IF_EQ(GF_MAC01_Met_Rhuff, FALSE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_02_C)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -305, 0, 330)
                EVT_CALL(SetNpcYaw, NPC_SELF, 90)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02_C)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_02_D)))
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02_C)))
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_02_D)))
            EVT_ELSE
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02_D)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80256684_816F04)[] = {
    ANIM_Rowf_Still,
    ANIM_Rowf_Idle,
    ANIM_Rowf_Walk,
    ANIM_Rowf_Talk,
    ANIM_Rowf_Cheer,
    ANIM_Rowf_Think,
    ANIM_Rowf_WaveOff,
    -1
};

NpcSettings N(NpcSettings_Toad_01) = {
    .height = 36,
    .radius = 24,
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_Toad_02) = {
    .height = 27,
    .radius = 18,
    .flags = ENEMY_FLAGS_1,
};

StaticNpc N(NpcData_Toad_01)[] = {
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_01),
        .pos = { -213.0f, -54.0f, 256.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(D_80256684_816F04),
        .tattle = MSG_NpcTattle_Rowf,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_02),
        .pos = { -250.0f, 0.0f, 263.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(D_80256684_816F04),
        .tattle = MSG_NpcTattle_Rhuff,
    },
};

typedef struct PostOfficeEntry {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} PostOfficeEntry; // size = 0x14
// same as UnkMac00 ?

PostOfficeEntry N(D_80256ADC_81735C)[] = {
    { 1, 84, MSG_Document_Letter_Goombario2_From, MSG_Document_Letter_Goombario2_Desc, MSG_Document_Letter_Goombario2_Body },
    { 1, 84, MSG_Document_Letter_Goombario1_From, MSG_Document_Letter_Goombario1_Desc, MSG_Document_Letter_Goombario1_Body },
    { 1, 84, MSG_Document_Letter_Goombario3_From, MSG_Document_Letter_Goombario3_Desc, MSG_Document_Letter_Goombario3_Body },
    { 2, 84, 0x00200027, 0x00200028, 0x00200029 },
    { 2, 84, 0x00200024, 0x00200025, 0x00200026 },
    { 2, 84, 0x00200021, 0x00200022, 0x00200023 },
    { 3, 84, 0x0020002D, 0x0020002E, 0x0020002F },
    { 3, 84, 0x00200030, 0x00200031, 0x00200032 },
    { 3, 84, 0x0020002A, 0x0020002B, 0x0020002C },
    { 4, 84, 0x00200033, 0x00200034, 0x00200035 },
    { 4, 84, 0x00200036, 0x00200037, 0x00200038 },
    { 9, 84, 0x00200039, 0x0020003A, 0x0020003B },
    { 9, 84, 0x0020003C, 0x0020003D, 0x0020003E },
    { 6, 84, 0x0020003F, 0x00200040, 0x00200041 },
    { 6, 84, 0x00200042, 0x00200043, 0x00200044 },
    { 7, 84, 0x00200048, 0x00200049, 0x0020004A },
    { 7, 84, 0x00200045, 0x00200046, 0x00200047 },
    { 8, 84, 0x0020004E, 0x0020004F, 0x00200050 },
    { 8, 84, 0x0020004B, 0x0020004C, 0x0020004D },
};

API_CALLABLE(N(func_80244E90_805710)) {
    PlayerData* playerData = &gPlayerData;
    s32 var_s2 = -1;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(D_80256ADC_81735C)); i++) {
        if (playerData->partners[N(D_80256ADC_81735C)[i].unk_00].enabled &&
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

    for (i = 0; i < ARRAY_COUNT(N(D_80256ADC_81735C)); i++) {
        if (N(D_80256ADC_81735C)[i].unk_00 == arg0 && evt_get_variable(NULL, GameFlag(153 + i)) != 0) {
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

API_CALLABLE(N(func_80245018_805898)) {
    D_80262F68 = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80245028_8058A8)) {
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

API_CALLABLE(N(func_8024522C_805AAC)) {
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

        for (i = 0; i < ARRAY_COUNT(N(D_80256ADC_81735C)); i++) {
            temp_s0 = evt_get_variable(NULL, GameFlag(153 + i));
            temp_a0 = evt_get_variable(NULL, GameFlag(172 + i));
            if (temp_s0 != 0 && vt10 == N(D_80256ADC_81735C)[i].unk_00) {
                scriptPair = &gItemHudScripts[gItemTable[84].hudElemID];
                menu->userIndex[numEntries] = i;
                menu->nameMsg[numEntries] = N(D_80256ADC_81735C)[i].unk_08;
                menu->descMsg[numEntries] = N(D_80256ADC_81735C)[i].unk_0C;
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
    if (script->functionTemp[1] == 255) {
        script->varTable[1] = -1;
        return ApiStatus_DONE2;
    }
    temp_a1 = menu->userIndex[script->functionTemp[1] - 1];
    script->varTable[1] = temp_a1;
    script->varTable[0] = N(D_80256ADC_81735C)[temp_a1].unk_10;
    evt_set_variable(NULL, GameFlag(temp_a1 + 172), 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80245440_805CC0)) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->currentPartner == script->varTable[10]) {
        script->varTable[1] = 0;
        return ApiStatus_DONE2;
    }

    switch_to_partner(script->varTable[10]);
    script->varTable[1] = 1;
    return ApiStatus_DONE2;
}

s32 N(ItemList_Mailbag)[] = {
    ITEM_MAILBAG,
    ITEM_NONE
};

EvtScript N(EVS_ItemPrompt_Mailbag) = {
    EVT_CALL(FindKeyItem, ITEM_MAILBAG, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0060)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0061)
        EVT_SET(LVar0, EVT_PTR(N(ItemList_Mailbag)))
        EVT_SET(LVar1, 3)
        EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0063)
            EVT_CASE_DEFAULT
                EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0062)
                EVT_SET(GF_MAC01_MailbagReturned, TRUE)
                EVT_WAIT(10)
                EVT_GIVE_STAR_PIECE()
                EVT_WAIT(10)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03_A) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
            EVT_EXEC_WAIT(N(EVS_ItemPrompt_Mailbag))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Met_Postmaster, FALSE)
        EVT_SET(GF_MAC01_Met_Postmaster, TRUE)
        EVT_CALL(N(func_80244E90_805710))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_RETURN
            EVT_CASE_EQ(1)
                EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0055)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(N(func_80244E90_805710))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_RETURN
            EVT_CASE_EQ(0)
                EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0057)
            EVT_CASE_EQ(1)
                EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0056)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(N(func_80245018_805898))
    EVT_LABEL(0)
    EVT_CALL(N(func_80245028_8058A8))
    EVT_WAIT(5)
    EVT_IF_EQ(LVar1, -1)
        EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0059)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(99)
        EVT_ELSE
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVarA, LVar1)
    EVT_CALL(N(func_8024522C_805AAC))
    EVT_WAIT(5)
    EVT_IF_EQ(LVar1, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(func_80245440_805CC0))
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 1)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005C)
    EVT_CALL(ShowMessageAtScreenPos, LVar0, 160, 40)
    EVT_WAIT(5)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005A)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_CALL(CloseMessage)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(99)
    EVT_IF_EQ(GF_MAC01_CheckedForLetters, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005D)
        EVT_SET(GF_MAC01_CheckedForLetters, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005E)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03_B) = {
    EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_Outro_0043)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 36, 42)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03_B)))
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03_A)))
    EVT_END_SWITCH
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        EVT_SET(GF_MAC01_UnlockedLetter_01, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        EVT_SET(GF_MAC01_UnlockedLetter_00, TRUE)
    EVT_END_IF
    EVT_SET(GF_MAC01_UnlockedLetter_02, TRUE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_SET(GF_MAC01_UnlockedLetter_05, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_SET(GF_MAC01_UnlockedLetter_04, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        EVT_SET(GF_MAC01_UnlockedLetter_03, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        EVT_SET(GF_MAC01_UnlockedLetter_08, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        EVT_SET(GF_MAC01_UnlockedLetter_06, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
        EVT_SET(GF_MAC01_UnlockedLetter_07, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_SET(GF_MAC01_UnlockedLetter_09, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_IWA00_Whacka_HitCount, 2)
        EVT_SET(GF_MAC01_UnlockedLetter_0A, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        EVT_SET(GF_MAC01_UnlockedLetter_0B, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_SET(GF_MAC01_UnlockedLetter_0C, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_SET(GF_MAC01_UnlockedLetter_0D, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        EVT_SET(GF_MAC01_UnlockedLetter_0E, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
        EVT_SET(GF_MAC01_UnlockedLetter_10, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_REACHED_STAR_HAVEN)
        EVT_SET(GF_MAC01_UnlockedLetter_0F, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        EVT_SET(GF_MAC01_UnlockedLetter_12, TRUE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_SET(GF_MAC01_UnlockedLetter_11, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Parakarry) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_MAC_Plaza_0064)
    EVT_RETURN
    EVT_END
};

s32 N(D_80257598_817E18)[] = {
    ANIM_WorldParakarry_Still,
    ANIM_WorldParakarry_Idle,
    ANIM_WorldParakarry_Talk,
    -1
};

EvtScript N(EVS_NpcInit_Parakarry) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 37, 26)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Parakarry)))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802575F8_817E78) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_MAILBAG, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(140)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802576EC_817F6C) = {
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, 357, 20, -440)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_EXEC(N(D_802575F8_817E78))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(60)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, 247, 20, -440, 20)
    EVT_SET(LVar0, 6)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 180, -410, 20)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 150, -333, 8)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, 0, -1000, 0)
    EVT_SET(GF_MAC01_MailbagStolen, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80257844) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC01_MailbagStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Postmaster_Talk, ANIM_Postmaster_IdleAlt, 0, MSG_MAC_Plaza_005F)
    EVT_EXEC(N(D_802576EC_817F6C))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80257900_818180) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_MinhT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, 4, LVar0, LVar1, LVar2, 300, 16, -8)
    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_006F)
    EVT_CALL(ResetCam, CAM_DEFAULT, 4)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_03) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 170, 27, 380)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 180, 27, 280, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 220, 250, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 310, 27, 250, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 350, 280, 15)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 360, 27, 380, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 300, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 230, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 170, 380, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_04) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 350, 27, 280)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 360, 27, 380, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 300, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 230, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 170, 380, 15)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 180, 27, 280, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 220, 250, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 310, 27, 250, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 350, 280, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy_03) = {
    EVT_SET(LVarA, GF_MAC01_ChasedShyGuysFromGardenA)
    EVT_ADD(LVarA, GF_MAC01_ChasedShyGuysFromGardenB)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 27, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(ShowSweat, -1, 1, -45, 1, 0, 0, 0, 0, 20)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_SET(LVar0, -1)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVar9)
    EVT_CALL(NpcMoveTo, NPC_SELF, 160, 400, 0)
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(LVarA, 2)
        EVT_EXEC(N(D_80257900_818180))
    EVT_END_IF
    EVT_CALL(ShowSweat, -1, 1, -45, 1, 0, 0, 0, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 110, 20, 420, 0)
    EVT_CALL(ShowSweat, -1, 1, -45, 1, 0, 0, 0, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 40, 0, 450, 0)
    EVT_CALL(ShowSweat, -1, 1, -45, 1, 0, 0, 0, 0, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -30, 550, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -30, 700, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80258004_818884) = {
    EVT_SET(LVar0, 1)
    EVT_CALL(GetOwnerEncounterTrigger, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LE(LVar1, 50)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar3, 80)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203E, 0)
    EVT_SET(LVar0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy_03) = {
    EVT_EXEC_WAIT(N(D_80258004_818884))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_MAC01_ChasedShyGuysFromGardenA, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_03)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy_04) = {
    EVT_EXEC_WAIT(N(D_80258004_818884))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_MAC01_ChasedShyGuysFromGardenB, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_03)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_03) = {
    EVT_IF_EQ(GF_MAC01_ChasedShyGuysFromGardenA, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_03)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy_03)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_04) = {
    EVT_IF_EQ(GF_MAC01_ChasedShyGuysFromGardenB, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_04)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy_04)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_EPILOGUE)
        EVT_SET(LVar0, 0x00010045)
    EVT_ELSE
        EVT_SET(LVar0, 0x00030077)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_STAR_SPRIT_DEPARTED, STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SetNpcPos, NPC_SELF, 200, 20, 500)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
        EVT_CASE_EQ(STORY_EPILOGUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 230, 30, 400)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80258404_818C84) = 0;

API_CALLABLE(N(func_80245488_805D08)) {
    Bytecode* args = script->ptrReadPos;

    N(D_80258404_818C84) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(func_802454B4_805D34)(void) {
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_80258404_818C84) & 0xFF);
}

API_CALLABLE(N(func_80245504_805D84)) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024552C_805DAC)) {
    repartner_set_tether_distance();
    return ApiStatus_DONE2;
}

EvtScript N(D_80258408_818C88) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_pica, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_pica, 4, -1)
    EVT_CALL(SetCustomGfxBuilders, 4, EVT_PTR(N(func_802454B4_805D34)), 0)
    EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_80245488_805D08), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80258504_818D84) = {
    EVT_SET(LVar1, 255)
    EVT_LOOP(LVar0)
        EVT_LOOP(15)
            EVT_ADD(LVar1, -5)
            EVT_CALL(N(func_80245488_805D08), LVar1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(15)
            EVT_ADD(LVar1, 5)
            EVT_CALL(N(func_80245488_805D08), LVar1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802585B8_818E38) = {
    EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_80245488_805D08), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_pica, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80258684_818F04) = {
    EVT_CALL(SetCamProperties, CAM_DEFAULT, 1, 266, 27, 373, 300, 15, -6)
    EVT_EXEC(N(EVS_802468F8))
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 0, 266, 50, 338, 1, LVar9)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_2A2, 0)
    EVT_EXEC_WAIT(N(D_80258408_818C88))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, 266, 50, 338, 100, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, 240, 50, 338, 100, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, 292, 50, 338, 100, 0)
    EVT_END_THREAD
    EVT_SET(LVar0, 3)
    EVT_EXEC_GET_TID(N(D_80258504_818D84), LVar2)
    EVT_WAIT(30)
    EVT_CALL(EnableModel, MODEL_r_door, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_2A3, 0)
    EVT_CALL(MakeLerp, 0, 0x00000BF4, 80, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_r_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_r_door, FALSE)
    EVT_CALL(EnableGroup, MODEL_to_flo, TRUE)
    EVT_CALL(func_802D7B10, LVar9)
    EVT_CALL(PlaySoundAt, SOUND_2A4, 0, 266, 50, 338)
    EVT_LOOP(3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 5, 266, 50, 338, 1, 20)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVar2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_WAIT(N(D_802585B8_818E38))
    EVT_CALL(ResetCam, CAM_DEFAULT, 1)
    EVT_EXEC(N(D_80246770_806FF0))
    EVT_RETURN
    EVT_END
};

s32 N(missing_80258A4C_18A4C)[] = {
    ITEM_LETTER09,
    ITEM_NONE 
};

s32 N(ItemList_MagicalSeeds)[] = {
    ITEM_MAGICAL_SEED1,
    ITEM_MAGICAL_SEED2,
    ITEM_MAGICAL_SEED3,
    ITEM_MAGICAL_SEED4,
    ITEM_NONE 
};

EvtScript N(D_80258A68_8192E8) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, LVar4)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 266, 27, 373)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 266, 27, 373)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 175, 444, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 200, 27, 435, 0)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 200, 407, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 220, 420, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 200, 270, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(NpcMoveTo, NPC_SELF, 310, 420, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 330, 270, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(NpcMoveTo, NPC_SELF, 310, 420, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 330, 407, 0)
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Cheer)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2A1, 0)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_CALL(EnableModel, MODEL_o375, TRUE)
            EVT_CALL(EnableModel, MODEL_o370, TRUE)
        EVT_CASE_EQ(1)
            EVT_CALL(EnableModel, MODEL_o377, TRUE)
            EVT_CALL(EnableModel, MODEL_o372, TRUE)
        EVT_CASE_EQ(2)
            EVT_CALL(EnableModel, MODEL_o376, TRUE)
            EVT_CALL(EnableModel, MODEL_o371, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(EnableModel, MODEL_o378, TRUE)
            EVT_CALL(EnableModel, MODEL_o373, TRUE)
    EVT_END_SWITCH
    EVT_IF_NE(LVar3, 3)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 220, 420, 0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(NpcMoveTo, NPC_SELF, 310, 420, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(NpcMoveTo, NPC_SELF, 186, 425, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 175, 20, 444, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 150, 480, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
    EVT_IF_EQ(LVar3, 3)
        EVT_CALL(InterpNpcYaw, NPC_MinhT, 90, 0)
        EVT_EXEC_WAIT(N(D_80258684_818F04))
        EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0070)
        EVT_SET(GB_StoryProgress, STORY_CH6_FLOWER_GATE_OPEN)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80258FFC_81987C) = {
    EVT_IF_NE(LVar5, 0)
        EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0075)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(ItemList_MagicalSeeds)))
    EVT_SET(LVar1, 18)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_RETURN
        EVT_CASE_EQ(43)
            EVT_SET(GF_MAC01_Planted_MagicalSeed1, TRUE)
            EVT_SET(LVar4, 0x00030076)
            EVT_SET(LVar5, 0)
            EVT_EXEC_WAIT(N(D_80258A68_8192E8))
        EVT_CASE_EQ(44)
            EVT_SET(GF_MAC01_Planted_MagicalSeed2, TRUE)
            EVT_SET(LVar4, 0x00030076)
            EVT_SET(LVar5, 1)
            EVT_EXEC_WAIT(N(D_80258A68_8192E8))
        EVT_CASE_EQ(45)
            EVT_SET(GF_MAC01_Planted_MagicalSeed3, TRUE)
            EVT_SET(LVar4, 0x00030076)
            EVT_SET(LVar5, 2)
            EVT_EXEC_WAIT(N(D_80258A68_8192E8))
        EVT_CASE_EQ(46)
            EVT_SET(GF_MAC01_Planted_MagicalSeed4, TRUE)
            EVT_SET(LVar4, 0x00030076)
            EVT_SET(LVar5, 3)
            EVT_EXEC_WAIT(N(D_80258A68_8192E8))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MinhT) = {
    EVT_EXEC_WAIT(N(D_8024E2C8_80EB48))
    EVT_EXEC_WAIT(N(D_8024E318_80EB98))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar2, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x00030065)
            EVT_SET(LVar1, 0x00030065)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar2, 1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
            EVT_ADD(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
            EVT_IF_EQ(LVar0, 2)
                EVT_SET(LVar2, 1)
            EVT_ELSE
                EVT_SET(LVar0, 0x0003006D)
                EVT_SET(LVar1, 0x0003006E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_SET(LVar2, 1)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_SET(LVar0, 0x00030071)
            EVT_SET(LVar1, 0x00030071)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00030072)
            EVT_SET(LVar1, 0x00030072)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00030073)
            EVT_SET(LVar1, 0x00030073)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010042)
            EVT_SET(LVar1, 0x00010042)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar2, 1)
        EVT_SET(LVar3, GF_MAC01_Planted_MagicalSeed1)
        EVT_ADD(LVar3, GF_MAC01_Planted_MagicalSeed2)
        EVT_ADD(LVar3, GF_MAC01_Planted_MagicalSeed3)
        EVT_ADD(LVar3, GF_MAC01_Planted_MagicalSeed4)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH5_STAR_SPRIT_DEPARTED, STORY_CH5_RETURNED_TO_TOAD_TOWN)
                EVT_SET(LVar4, GF_MAC02_Gift_MagicalSeed1)
                EVT_ADD(LVar4, GF_IWA02_Gift_MagicalSeed2)
                EVT_ADD(LVar4, GF_MIM04_Gift_MagicalSeed3)
                EVT_ADD(LVar4, GF_JAN03_Gift_MagicalSeed4)
                EVT_SET(LVar5, GF_MAC01_HeardAboutBubulbs)
                EVT_IF_EQ(LVar5, 0)
                    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0074)
                    EVT_SET(GF_MAC01_HeardAboutBubulbs, TRUE)
                EVT_END_IF
                EVT_IF_NE(LVar4, 0)
                    EVT_EXEC_WAIT(N(D_80258FFC_81987C))
                    EVT_RETURN
                EVT_END_IF
                EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0075)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_SWITCH(LVar3)
            EVT_CASE_EQ(0)
                EVT_SET(LVar0, 0x00030066)
                EVT_SET(LVar1, 0x00030066)
            EVT_CASE_EQ(1)
                EVT_SET(LVar0, 0x00030068)
                EVT_SET(LVar1, 0x00030068)
            EVT_CASE_EQ(2)
                EVT_SET(LVar0, 0x0003006A)
                EVT_SET(LVar1, 0x0003006A)
            EVT_CASE_EQ(3)
                EVT_SET(LVar0, 0x0003006C)
                EVT_SET(LVar1, 0x0003006C)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_IF_EQ(AF_MAC_14, FALSE)
        EVT_SET(AF_MAC_14, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, LVar1)
        EVT_SET(AF_MAC_14, FALSE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, LVar0)
    EVT_IF_EQ(LVar2, 1)
        EVT_SET(LVar0, EVT_PTR(N(ItemList_MagicalSeeds)))
        EVT_SET(LVar1, 18)
        EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_RETURN
            EVT_CASE_EQ(-1)
                EVT_RETURN
            EVT_CASE_EQ(43)
                EVT_SET(GF_MAC01_Planted_MagicalSeed1, TRUE)
                EVT_SET(LVar4, 0x00030067)
                EVT_SET(LVar5, 0)
                EVT_EXEC_WAIT(N(D_80258A68_8192E8))
            EVT_CASE_EQ(44)
                EVT_SET(GF_MAC01_Planted_MagicalSeed2, TRUE)
                EVT_SET(LVar4, 0x00030069)
                EVT_SET(LVar5, 1)
                EVT_EXEC_WAIT(N(D_80258A68_8192E8))
            EVT_CASE_EQ(45)
                EVT_SET(GF_MAC01_Planted_MagicalSeed3, TRUE)
                EVT_SET(LVar4, 0x0003006B)
                EVT_SET(LVar5, 2)
                EVT_EXEC_WAIT(N(D_80258A68_8192E8))
            EVT_CASE_EQ(46)
                EVT_SET(LVar5, 3)
                EVT_EXEC_WAIT(N(D_80258A68_8192E8))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_MinhT) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MinhT) = {
    EVT_THREAD
        EVT_LOOP(0)
            EVT_SET(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
            EVT_ADD(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_400000, 0)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MinhT)))
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
    EVT_ADD(LVar0, 25)
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_ADD(LVar0, -50)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_ADD(LVar0, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MinhT) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_SET(GF_MAC01_ShyGuysTramplingGarden, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_400000, 1)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MinhT)))
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MinhT)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80259AD0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_CALL(GetPlayerActionState, LVar3)
    EVT_SET(LVar4, 0)
    EVT_IF_EQ(LVar3, ACTION_STATE_IDLE)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_WALK)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_RUN)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar4, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(func_80245504_805D84))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_2A2, 0)
    EVT_EXEC_WAIT(N(D_80258408_818C88))
    EVT_SET(LVar0, 3)
    EVT_EXEC_GET_TID(N(D_80258504_818D84), LVar2)
    EVT_CALL(PlayerMoveTo, 300, 370, 15)
    EVT_CALL(InterpPlayerYaw, -22, 0)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_1CF, 0)
        EVT_CALL(MakeLerp, 0, -120, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(45)
        EVT_CALL(MakeLerp, -120, 0, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_1D0, 0)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(PlayerMoveTo, 257, 300, 30)
    EVT_WAIT(60)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, 0, -500, 0)
    EVT_CALL(N(func_8024552C_805DAC))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -500, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVar2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_6A2, 0)
    EVT_EXEC_WAIT(N(D_802585B8_818E38))
    EVT_CALL(EnableGroup, MODEL_to_flo, FALSE)
    EVT_CALL(EnableGroup, MODEL_r_door, TRUE)
    EVT_CALL(MakeLerp, 180, 360, 20, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_r_door, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_r_gate, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_EQ(GF_StartedChapter6, FALSE)
        EVT_SET(GF_StartedChapter6, TRUE)
        EVT_CALL(FadeOutMusic, 0, 0x000005DC)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_6, TRANSITION_6)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), flo_00_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8025A004) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 180, 2)
    EVT_CALL(SetPlayerPos, 264, 27, 320)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 264, 27, 320)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_2A2, 0)
    EVT_EXEC_WAIT(N(D_80258408_818C88))
    EVT_SET(LVar0, 2)
    EVT_EXEC_GET_TID(N(D_80258504_818D84), LVar2)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_1CF, 0)
    EVT_CALL(MakeLerp, 0, -120, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(N(func_80245504_805D84))
    EVT_CALL(PlayerMoveTo, 264, 407, 30)
    EVT_CALL(MakeLerp, -120, 0, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_1D0, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVar2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(N(func_8024552C_805DAC))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_6A2, 0)
    EVT_EXEC_WAIT(N(D_802585B8_818E38))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8025A2F0) = {
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed1, FALSE)
        EVT_CALL(EnableModel, MODEL_o375, FALSE)
        EVT_CALL(EnableModel, MODEL_o370, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed2, FALSE)
        EVT_CALL(EnableModel, MODEL_o377, FALSE)
        EVT_CALL(EnableModel, MODEL_o372, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed3, FALSE)
        EVT_CALL(EnableModel, MODEL_o376, FALSE)
        EVT_CALL(EnableModel, MODEL_o371, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed4, FALSE)
        EVT_CALL(EnableModel, MODEL_o378, FALSE)
        EVT_CALL(EnableModel, MODEL_o373, FALSE)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_FLOWER_GATE_OPEN)
        EVT_CALL(EnableGroup, MODEL_to_flo, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_pica, FALSE)
    EVT_CALL(EnableModel, MODEL_r_door, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_04) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Plaza_007D)
    EVT_SET(GB_StoryProgress, STORY_CH0_RETURNED_TO_TOAD_TOWN)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x0003007C)
        EVT_CASE_LT(STORY_CH1_SPOKE_WITH_MERLIN)
            EVT_SET(LVar0, 0x0003007D)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0003007E)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x0003007F)
            EVT_ELSE
                EVT_SET(LVar0, 0x00030080)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00030081)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, 0x00030082)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, 0x00030083)
                EVT_ELSE
                    EVT_SET(LVar0, 0x00030084)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x00030085)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00030086)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x00030087)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00030088)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x00030089)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0003008A)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0003008B)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010046)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(SetNpcPos, NPC_SELF, -25, 0, -500)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_04)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x0003008C)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x0003008D)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0003008E)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x0003008F)
            EVT_ELSE
                EVT_SET(LVar0, 0x00030090)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00030091)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, 0x00030092)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, 0x00030093)
                EVT_ELSE
                    EVT_SET(LVar0, 0x00030094)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x00030095)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00030096)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x00030097)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00030098)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x00030099)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0003009A)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0003009B)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010047)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_05) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025AA78_81B2F8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_Toad_05, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_0048)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, 0, 580, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_05)))
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -50, 0, 580)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_05)))
        EVT_BIND_TRIGGER(EVT_PTR(N(D_8025AA78_81B2F8)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilis, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x0003009C)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x0003009D)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0003009E)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x0003009F)
            EVT_ELSE
                EVT_SET(LVar0, 0x000300A0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300A1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, 0x000300A2)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, 0x000300A3)
                EVT_ELSE
                    EVT_SET(LVar0, 0x000300A4)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000300A5)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300A6)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000300A7)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300A8)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000300A9)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300AA)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000300AB)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010049)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_06, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_06) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_06)))
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -110, 20, -380)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_06)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_07) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x000300AC)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x000300AD)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300AE)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x000300AF)
            EVT_ELSE
                EVT_SET(LVar0, 0x000300B0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300B1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, 0x000300B2)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, 0x000300B3)
                EVT_ELSE
                    EVT_SET(LVar0, 0x000300B4)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000300B5)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300B6)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000300B7)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300B8)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000300B9)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300BA)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000300BB)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0001004A)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_07) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025B110_81B990) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_Toad_07, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_Outro_004B)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, 600, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_07) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_07)))
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, 530, 0, -50)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_07)))
        EVT_BIND_TRIGGER(EVT_PTR(N(D_8025B110_81B990)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilie, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_08) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x000300BC)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x000300BD)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300BE)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x000300BF)
            EVT_ELSE
                EVT_SET(LVar0, 0x000300C0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300C1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_ShyGuysTramplingGarden, FALSE)
            EVT_ELSE
                EVT_SET(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
                EVT_ADD(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LVar0, 0x000300C2)
                EVT_ELSE
                    EVT_SET(LVar0, 0x000300C3)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000300C4)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300C5)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000300C6)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300C7)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000300C8)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300C9)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000300CA)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0001004C)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_08, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_08) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_08)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_09) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x000300CB)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x000300CC)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300CD)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x000300CE)
            EVT_ELSE
                EVT_SET(LVar0, 0x000300CF)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300D0)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, 0x000300D1)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, 0x000300D2)
                EVT_ELSE
                    EVT_SET(LVar0, 0x000300D3)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000300D4)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300D5)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000300D6)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000300D7)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000300D8)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000300D9)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000300DA)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0001004D)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_09, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_09) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_09)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025B760_81BFE0) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_CALCULATOR, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(80)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025B854_81C0D4) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar2, 200)
            EVT_IF_LT(LVar0, 50)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, -313, 0, 330)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_WAIT(21)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0007)
    EVT_EXEC(N(D_8025B760_81BFE0))
    EVT_SET(LVar0, 6)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -45, 330, 30)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -45, 710, 30)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, 0, -1000, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC01_CalculatorStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_MAC01_CalculatorStolen, TRUE)
    EVT_EXEC(N(D_8025B854_81C0D4))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_10_A) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Plaza_001A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_10_B) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_0044)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025BAE0_81C360) = {
    EVT_IF_EQ(AF_MAC_43, FALSE)
        EVT_SET(LVar0, 0x00030015)
        EVT_SET(LVar8, 0x00030016)
    EVT_ELSE
        EVT_SET(LVar0, 0x0003001B)
        EVT_SET(LVar8, 0x0003001B)
    EVT_END_IF
    EVT_SET(LVar1, 0x00030017)
    EVT_SET(LVar2, 0x00030018)
    EVT_SET(LVar3, 0x00030019)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025BB80_81C400) = {
    EVT_EXEC(N(EVS_80246924))
    EVT_CALL(PlayerMoveTo, 535, -155, 20)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 116)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 99, -58)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 495, 130)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 507, -19)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 20)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 580, -210, 20)
    EVT_CALL(InterpPlayerYaw, 263, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(func_802D286C, 0x00000800)
    EVT_CALL(func_802D2520, 0x00010002, 5, 7, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001D)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(63)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025BDDC_81C65C) = {
    EVT_EXEC(N(D_80246770_806FF0))
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(func_802D2520, 0x00010002, 0, 0, 0, 0, 0)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(SetPlayerPos, 568, 20, -186)
    EVT_CALL(PlayerMoveTo, 525, -168, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_10) = {
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, 370, 20, -150)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_10_B)))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_ChasedShyGuyFromToadHouse, FALSE)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_10_A)))
            EVT_CASE_DEFAULT
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_10)))
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_10)))
    EVT_END_IF
    EVT_SET(AF_MAC_43, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_02) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 572, 36, -226)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_WAIT(3)
        EVT_IF_EQ(MF_Unk_0F, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_END_IF
        EVT_CALL(NpcJump0, NPC_SELF, 539, 36, -242, 8)
        EVT_WAIT(2)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_WAIT(3)
        EVT_IF_EQ(MF_Unk_0F, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_END_IF
        EVT_CALL(NpcJump0, NPC_SELF, 572, 36, -226, 8)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy_02) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowSweat, -1, 1, -45, 1, 0, 0, 0, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 36, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 550, 20, -161, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit2u, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit2u, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_END_THREAD
    EVT_CALL(ShowSweat, -1, 1, -45, 1, 0, 0, 0, 0, 20)
    EVT_SET(LVar0, -1)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVarA)
    EVT_CALL(NpcMoveTo, NPC_SELF, 420, -118, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(BindNpcInteract, NPC_Toad_10, EVT_PTR(N(EVS_NpcInteract_Toad_10)))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_SET(LVar1, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 0)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(CheckPositionRelativeToPlane), 450, -190, 500, -103)
    EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_NONE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203E, 0)
    EVT_SET(GF_MAC01_ChasedShyGuyFromToadHouse, TRUE)
    EVT_SET(AF_MAC_43, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_02)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    EVT_IF_EQ(GF_MAC01_ChasedShyGuyFromToadHouse, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_02)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy_02)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(D_8025C5B0_81CE30)[] = {
    {  -80.0,   106.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {    0.0,     0.0,    0.0 },
};

Vec3f N(D_8025C5D4_81CE54)[] = {
    {    0.0,     0.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {  -70.0,   106.0,    0.0 },
};

EvtScript N(EVS_NpcIdle_Twink) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 560)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 500, -20, 0)
    EVT_CALL(WaitForPlayerMoveToComplete)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_00DB, 160, 40)
    EVT_LOOP(2)
        EVT_CALL(InterpPlayerYaw, 90, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 7)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(GetPlayerPos, LVar4, LVar5, LVar6)
    EVT_SUBF(LVar4, EVT_FLOAT(50.0))
    EVT_ADDF(LVar5, EVT_FLOAT(40.0))
    EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
    EVT_CALL(LoadPath, 35, EVT_PTR(N(D_8025C5B0_81CE30)), 3, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), -10, -300, 15, -9)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DC)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(15)
    EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DD)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002D)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), -40, -200, 15, -15)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DE)
    EVT_WAIT(5)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 35, EVT_PTR(N(D_8025C5D4_81CE54)), 3, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_ADD(LVar3, LVar6)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Twink, 0, -1000, 0)
    EVT_EXEC(N(D_80246770_806FF0))
    EVT_SET(GB_StoryProgress, STORY_CH1_RETURNED_TO_TOAD_TOWN)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Twink)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00DF)
    EVT_EXEC_WAIT(N(D_8024E4DC_80ED5C))
    EVT_EXEC_WAIT(N(D_8024E384_80EC04))
    EVT_EXEC_WAIT(N(D_8024E3D4_80EC54))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_RETURNED_TO_TOAD_TOWN, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_ELSE
                EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_8025CC80_81D500)[] = {
    ANIM_Toad_Red_Still,
    ANIM_Toad_Red_Idle,
    ANIM_Toad_Red_Walk,
    ANIM_Toad_Red_Run,
    ANIM_Toad_Red_Talk,
    -1
};

s32 N(D_8025CC98_81D518)[] = {
    ANIM_Bubulb_Pink_Idle,
    ANIM_Bubulb_Pink_EmbedIdle,
    ANIM_Bubulb_Pink_Talk,
    -1
};

StaticNpc N(NpcData_Toad_04)[] = {
    {
        .id = NPC_Toad_04,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -94.0f, 0.0f, -117.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_04),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_RunsHisMouth,
    },
    {
        .id = NPC_Toad_05,
        .settings = &N(NpcSettings_Toad_Wander),
        .pos = { -145.0f, 0.0f, -25.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_05),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_KnowsTheGossip,
    },
    {
        .id = NPC_Toad_06,
        .settings = &N(NpcSettings_Toad_Patrol),
        .pos = { 40.0f, 0.0f, -300.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_06),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 40, 0, -300 },
                    { -40, 0, -300 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_PrincessFan,
    },
    {
        .id = NPC_Toad_07,
        .settings = &N(NpcSettings_Toad_Patrol),
        .pos = { -440.0f, 0.0f, -20.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_07),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -440, 0, -20 },
                    { 350, 0, -20 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_KnowsTheRumors,
    },
    {
        .id = NPC_Toad_08,
        .settings = &N(NpcSettings_Toad_Patrol),
        .pos = { 400.0f, 20.0f, 260.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_08),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 400, 20, 260 },
                    { 490, 20, 260 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Blue_Idle,
            .walk   = ANIM_Toad_Blue_Walk,
            .run    = ANIM_Toad_Blue_Run,
            .chase  = ANIM_Toad_Blue_Run,
            .anim_4 = ANIM_Toad_Blue_Idle,
            .anim_5 = ANIM_Toad_Blue_Idle,
            .death  = ANIM_Toad_Blue_Disappointed,
            .hit    = ANIM_Toad_Blue_Disappointed,
            .anim_8 = ANIM_Toad_Blue_Run,
            .anim_9 = ANIM_Toad_Blue_Run,
            .anim_A = ANIM_Toad_Blue_Run,
            .anim_B = ANIM_Toad_Blue_Run,
            .anim_C = ANIM_Toad_Blue_Run,
            .anim_D = ANIM_Toad_Blue_Run,
            .anim_E = ANIM_Toad_Blue_Run,
            .anim_F = ANIM_Toad_Blue_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_CrushingOnMinhT,
    },
    {
        .id = NPC_Toad_09,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -380.0f, 20.0f, -100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_09),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Green_Idle,
            .walk   = ANIM_Toad_Green_Walk,
            .run    = ANIM_Toad_Green_Run,
            .chase  = ANIM_Toad_Green_Run,
            .anim_4 = ANIM_Toad_Green_Idle,
            .anim_5 = ANIM_Toad_Green_Idle,
            .death  = ANIM_Toad_Green_Disappointed,
            .hit    = ANIM_Toad_Green_Disappointed,
            .anim_8 = ANIM_Toad_Green_Run,
            .anim_9 = ANIM_Toad_Green_Run,
            .anim_A = ANIM_Toad_Green_Run,
            .anim_B = ANIM_Toad_Green_Run,
            .anim_C = ANIM_Toad_Green_Run,
            .anim_D = ANIM_Toad_Green_Run,
            .anim_E = ANIM_Toad_Green_Run,
            .anim_F = ANIM_Toad_Green_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_SeeksTheSouth,
    },
    {
        .id = NPC_Toad_10,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 488.0f, 20.0f, -174.0f },
        .yaw = 30,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_10),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .extraAnimations = N(D_8025CC80_81D500),
        .tattle = MSG_NpcTattle_MAC_ToadHouseToad,
    },
    {
        .id = NPC_Bubulb,
        .settings = &N(NpcSettings_Bubulb),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Bubulb),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Bubulb_Pink_Idle,
            .walk   = ANIM_Bubulb_Pink_Walk,
            .run    = ANIM_Bubulb_Pink_Walk,
            .chase  = ANIM_Bubulb_Pink_Idle,
            .anim_4 = ANIM_Bubulb_Pink_Idle,
            .anim_5 = ANIM_Bubulb_Pink_Idle,
            .death  = ANIM_Bubulb_Pink_Idle,
            .hit    = ANIM_Bubulb_Pink_Idle,
            .anim_8 = ANIM_Bubulb_Pink_Idle,
            .anim_9 = ANIM_Bubulb_Pink_Idle,
            .anim_A = ANIM_Bubulb_Pink_Idle,
            .anim_B = ANIM_Bubulb_Pink_Idle,
            .anim_C = ANIM_Bubulb_Pink_Idle,
            .anim_D = ANIM_Bubulb_Pink_Idle,
            .anim_E = ANIM_Bubulb_Pink_Idle,
            .anim_F = ANIM_Bubulb_Pink_Idle,
        },
        .extraAnimations = N(D_8025CC98_81D518),
        .tattle = MSG_NpcTattle_MAC_FlowerGateBubulb,
    },
    {
        .id = NPC_MinhT,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 150.0f, 20.0f, 485.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_MinhT),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_MinhT_Idle,
        },
        .tattle = MSG_NpcTattle_MinhT,
    },
    {
        .id = NPC_Toad_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 312.0f, 30.0f, -438.0f },
        .yaw = 300,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_Toad_03),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Postmaster_Idle,
        },
        .tattle = MSG_NpcTattle_Postmaster,
    },
};

StaticNpc N(NpcData_Parakarry) = {
    .id = NPC_Parakarry,
    .settings = &N(NpcSettings_Parakarry),
    .pos = { 145.0f, 20.0f, -472.0f },
    .yaw = 120,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Parakarry),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldParakarry_Idle,
        .walk   = ANIM_WorldParakarry_Walk,
        .run    = ANIM_WorldParakarry_Run,
        .chase  = ANIM_WorldParakarry_Run,
        .anim_4 = ANIM_WorldParakarry_Idle,
        .anim_5 = ANIM_WorldParakarry_Idle,
        .death  = ANIM_WorldParakarry_Still,
        .hit    = ANIM_WorldParakarry_Still,
        .anim_8 = ANIM_WorldParakarry_Idle,
        .anim_9 = ANIM_WorldParakarry_Idle,
        .anim_A = ANIM_WorldParakarry_Idle,
        .anim_B = ANIM_WorldParakarry_Idle,
        .anim_C = ANIM_WorldParakarry_Idle,
        .anim_D = ANIM_WorldParakarry_Idle,
        .anim_E = ANIM_WorldParakarry_Idle,
        .anim_F = ANIM_WorldParakarry_Idle,
    },
    .extraAnimations = N(D_80257598_817E18),
    .tattle = MSG_NpcTattle_MAC_Parakarry,
};

s32 N(D_8025E1F8_81EA78)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Talk,
    -1
};

StaticNpc N(NpcData_Twink) = {
    .id = NPC_Twink,
    .settings = &N(NpcSettings_Twink),
    .pos = { -350.0f, 20.0f, -100.0f },
    .yaw = 274,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_400000,
    .init = &N(EVS_NpcInit_Twink),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Twink_Idle,
        .walk   = ANIM_Twink_Fly,
        .run    = ANIM_Twink_Angry,
        .chase  = ANIM_Twink_Angry,
        .anim_4 = ANIM_Twink_Idle,
        .anim_5 = ANIM_Twink_Idle,
        .death  = ANIM_Twink_Idle,
        .hit    = ANIM_Twink_Idle,
        .anim_8 = ANIM_Twink_Idle,
        .anim_9 = ANIM_Twink_Idle,
        .anim_A = ANIM_Twink_Idle,
        .anim_B = ANIM_Twink_Idle,
        .anim_C = ANIM_Twink_Idle,
        .anim_D = ANIM_Twink_Idle,
        .anim_E = ANIM_Twink_Idle,
        .anim_F = ANIM_Twink_Idle,
    },
    .extraAnimations = N(D_8025E1F8_81EA78),
};

StaticNpc N(NpcData_ShyGuy_01)[] = {
    {
        .id = NPC_ShyGuy_01,
        .settings = &N(NpcSettings_ShyGuy_NoAI),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_02,
        .settings = &N(NpcSettings_ShyGuy_NoAI),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_400000 | ENEMY_FLAGS_IGNORE_TOUCH,
        .init = &N(EVS_NpcInit_ShyGuy_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_03,
        .settings = &N(NpcSettings_ShyGuy_NoAI),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_400000 | ENEMY_FLAGS_IGNORE_TOUCH,
        .init = &N(EVS_NpcInit_ShyGuy_03),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_04,
        .settings = &N(NpcSettings_ShyGuy_NoAI),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_400000 | ENEMY_FLAGS_IGNORE_TOUCH,
        .init = &N(EVS_NpcInit_ShyGuy_04),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
};

s32 N(D_8025EBB8_81F438)[] = {
    ANIM_Kolorado_Still,
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_Talk,
    -1
};

StaticNpc N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .settings = &N(NpcSettings_Kolorado),
    .pos = { 520.0f, 0.0f, -25.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .init = &N(EVS_NpcInit_Kolorado),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Kolorado_Idle,
        .walk   = ANIM_Kolorado_Walk,
        .run    = ANIM_Kolorado_Run,
        .chase  = ANIM_Kolorado_Run,
        .anim_4 = ANIM_Kolorado_Idle,
        .anim_5 = ANIM_Kolorado_Idle,
        .death  = ANIM_Kolorado_Idle,
        .hit    = ANIM_Kolorado_Idle,
        .anim_8 = ANIM_Kolorado_Idle,
        .anim_9 = ANIM_Kolorado_Idle,
        .anim_A = ANIM_Kolorado_Idle,
        .anim_B = ANIM_Kolorado_Idle,
        .anim_C = ANIM_Kolorado_Idle,
        .anim_D = ANIM_Kolorado_Idle,
        .anim_E = ANIM_Kolorado_Idle,
        .anim_F = ANIM_Kolorado_Idle,
    },
    .extraAnimations = N(D_8025EBB8_81F438),
    .tattle = MSG_NpcTattle_Kolorado,
};

StaticNpc N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .settings = &N(Quizmo_NpcSettings),
    .pos = { -440.0f, 20.0f, -140.0f },
    .yaw = 30,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_4000,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_01 }},
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_ChuckQuizmo_Idle,
        .walk   = ANIM_ChuckQuizmo_Walk,
        .run    = ANIM_ChuckQuizmo_Run,
        .chase  = ANIM_ChuckQuizmo_Run,
        .anim_4 = ANIM_ChuckQuizmo_Idle,
        .anim_5 = ANIM_ChuckQuizmo_Idle,
        .death  = ANIM_ChuckQuizmo_Still,
        .hit    = ANIM_ChuckQuizmo_Still,
        .anim_8 = ANIM_ChuckQuizmo_Run,
        .anim_9 = ANIM_ChuckQuizmo_Run,
        .anim_A = ANIM_ChuckQuizmo_Run,
        .anim_B = ANIM_ChuckQuizmo_Run,
        .anim_C = ANIM_ChuckQuizmo_Run,
        .anim_D = ANIM_ChuckQuizmo_Run,
        .anim_E = ANIM_ChuckQuizmo_Run,
        .anim_F = ANIM_ChuckQuizmo_Run,
    },
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(NpcGroup7) = {
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Toad_04)),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(NpcGroup2) = {
    NPC_GROUP(N(NpcData_Parakarry)),
    NPC_GROUP(N(NpcData_KoopaBros)),
    NPC_GROUP(N(NpcData_DarkToads)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Toad_04)),
    {}
};

NpcGroupList N(NpcGroup3) = {
    NPC_GROUP(N(NpcData_Parakarry)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Toad_04)),
    {}
};

NpcGroupList N(NpcGroup4) = {
    NPC_GROUP(N(NpcData_Twink)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Toad_04)),
    {}
};

NpcGroupList N(NpcGroup5) = {
    NPC_GROUP(N(NpcData_ShyGuy_01)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Toad_04)),
    {}
};

NpcGroupList N(NpcGroup6) = {
    NPC_GROUP(N(NpcData_Ninji)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Toad_04)),
    {}
};

