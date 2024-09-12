#include "kmr_23.h"
#include "effects.h"
#include "include_asset.h"

void func_80240DA4_9087D4(void);

typedef struct EndChapter {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 yaw;
    /* 0x14 */ f32 angularVelocity;
    /* 0x18 */ f32 startYaw;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 stopAccelerating;
    /* 0x22 */ s16 chapter;
    /* 0x24 */ s16 screenWhiteness;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ EffectInstance* spiritCardEffect;
    /* 0x2C */ EffectInstance* chapterChangeEffect;
} EndChapter;

#include "world/common/npc/StarSpirit.h"

NpcSettings N(NpcSettings_StarSpirit) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

AnimID N(StarSpiritAnimations)[][2] = {
    { ANIM_WorldEldstar_Idle,   ANIM_WorldEldstar_Back },
    { ANIM_WorldMamar_Idle,     ANIM_WorldMamar_Back },
    { ANIM_WorldSkolar_Idle,    ANIM_WorldSkolar_Back },
    { ANIM_WorldMuskular_Idle,  ANIM_WorldMuskular_Back },
    { ANIM_WorldMisstar_Idle,   ANIM_WorldMisstar_Back },
    { ANIM_WorldKlevar_Idle,    ANIM_WorldKlevar_Back },
    { ANIM_WorldKalmar_Idle,    ANIM_WorldKalmar_Back },
};

s32 imgPadding = 0;

INCLUDE_IMG("world/area_kmr/kmr_23/window_ul.png", kmr_23_window_ul_img);
INCLUDE_IMG("world/area_kmr/kmr_23/window_ur.png", kmr_23_window_ur_img);
INCLUDE_IMG("world/area_kmr/kmr_23/window_ll.png", kmr_23_window_ll_img);
INCLUDE_IMG("world/area_kmr/kmr_23/window_lr.png", kmr_23_window_lr_img);

s32 D_802417C8_9091F8 = 0;

s32 D_802417CC_9091FC = 0;

s32 D_802417D0_909200 = 0;

s32 D_802417D0_909204 = 0;

WindowStyleCustom D_802417D8_909208 = {
    .background = {
        .imgData = NULL,
    },
    .corners = {
        .imgData = N(window_ul_img),
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 8, 8 },
        .size2 = { 8, 8 },
        .size3 = { 8, 8 },
        .size4 = { 8, 8 },
    },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_2B, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_2C, G_CC_PASS2),
    .color1 = { 224, 224, 224, 255 },
    .color2 = { 0, 0, 0, 255},
};

API_CALLABLE(N(CreateEndChapterData)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(NPC_StarSpirit);
    EndChapter* data;
    s32 backFacing;

    if (isInitialCall) {
        data = heap_malloc(sizeof(*data));
        script->userData = data;
        evt_set_variable(script, MV_EndChapterDataPtr, (s32) data);
        data->chapter = evt_get_variable(script, *args++);
        data->pos.x = evt_get_float_variable(script, *args++);
        data->pos.y = evt_get_float_variable(script, *args++);
        data->pos.z = evt_get_float_variable(script, *args++);
        data->yaw = 0.0f;
        data->unk1C = 0;
        data->screenWhiteness = 0;
        data->unk1E = FALSE;
        npc->alpha = 0;
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        data->spiritCardEffect = fx_spirit_card(1, data->pos.x, data->pos.y, data->pos.z, 1.0f, 0);
        data->spiritCardEffect->data.spiritCard->chapter = data->chapter;
        data->spiritCardEffect->data.spiritCard->unk_20 = 0;
        set_curtain_draw_callback(func_80240DA4_9087D4);
    }
    data = script->userData;
    npc->pos.x = data->pos.x;
    npc->pos.y = data->pos.y;
    npc->pos.z = data->pos.z + 10.0f;
    npc->rot.y = data->yaw;
    backFacing = FALSE;
    if (!evt_get_variable(script, MF_Unk_0B)) {
        if ((data->yaw > 90.0f) && (data->yaw < 270.0f)) {
            backFacing = TRUE;
        }
        npc->curAnim = N(StarSpiritAnimations)[data->chapter][backFacing];
    }

    if (data->spiritCardEffect != NULL) {
        data->spiritCardEffect->data.spiritCard->yaw = data->yaw;
        data->spiritCardEffect->data.spiritCard->pos.x = data->pos.x - 2.0f;
        data->spiritCardEffect->data.spiritCard->pos.y = data->pos.y + 15.0f;
        data->spiritCardEffect->data.spiritCard->pos.z = data->pos.z;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AddCardAngularVelocity)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);

    if (isInitialCall) {
        data->stopAccelerating = FALSE;
        data->angularVelocity = evt_get_float_variable(script, *args++);
    }

    if (!data->stopAccelerating) {
        data->yaw = clamp_angle(data->yaw + data->angularVelocity);
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AccelerateCardSpin)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* data;
    s32 duration;

    if (isInitialCall) {
        script->functionTempF[1] = evt_get_float_variable(script, *args++);
        duration = script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
        script->functionTempF[1] = script->functionTempF[1] / duration;
    }

    data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);
    data->angularVelocity += script->functionTempF[1];

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[2]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(MakeCardFloatUpward)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->varTable[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
    }

    data->pos.y = update_lerp(script->varTable[0],
        script->functionTemp[1], script->functionTemp[2],
        script->functionTemp[0], script->functionTemp[3]);

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[3]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(ShowRadialShimmer)) {
    Bytecode* args = script->ptrReadPos;
    f32 scale = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);

    fx_radial_shimmer(0xE, data->pos.x, data->pos.y + 16.0f, data->pos.z, scale, duration);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FadeInSpiritNpc)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(NPC_StarSpirit);
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = evt_get_variable(script, *args++);
    }

    npc->alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, script->functionTemp[0], script->functionTemp[1]);

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[1]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(FlashScreenWhite)) {
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);
    EffectInstance* effect;

    enum FunctionState {
        FADE_TO_WHITE   = 0,
        HOLD_WHITE      = 1,
        BACK_TO_NORMAL  = 2,
    };

    if (isInitialCall) {
        script->functionTemp[0] = FADE_TO_WHITE;
    }

    switch(script->functionTemp[0]) {
        case FADE_TO_WHITE:
            set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
            set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, data->screenWhiteness);
            if (data->screenWhiteness == 255) {
                data->spiritCardEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
                data->spiritCardEffect = NULL;
                gCameras->bgColor[0] = 208;
                gCameras->bgColor[1] = 208;
                gCameras->bgColor[2] = 208;
                script->functionTemp[0] = HOLD_WHITE;
                script->functionTemp[1] = 15;
            } else {
                data->screenWhiteness += 50;
                if (data->screenWhiteness > 255) {
                    data->screenWhiteness = 255;
                }
            }
            break;
        case HOLD_WHITE:
            script->functionTemp[1]--;
            if (script->functionTemp[1] == -1) {
                script->functionTemp[0] = BACK_TO_NORMAL;
            }
            break;
        case BACK_TO_NORMAL:
            set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, data->screenWhiteness);
            if (data->screenWhiteness == 0) {
                set_curtain_scale_goal(1.0f);
                return ApiStatus_DONE1;
            }
            data->screenWhiteness -= 20;
            if (data->screenWhiteness < 0) {
                data->screenWhiteness = 0;
            }
            break;
        }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SpinDownStarSpirit)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        data->stopAccelerating = TRUE;
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        data->startYaw = data->yaw;
    }

    data->yaw = clamp_angle(update_lerp(EASING_QUADRATIC_OUT,
        data->startYaw, script->functionTemp[1],
        script->functionTemp[0], script->functionTemp[2]));

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[2]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(EndOfChapterBounceIn)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* endChatper = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);
    s32 posY;

    if (isInitialCall) {
        endChatper->chapterChangeEffect = fx_chapter_change(gGameStatusPtr->entryID + 10, 40, 0, 0, 1.0f, 0);
        script->functionTemp[0] = 0;
        script->varTable[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
    }

    posY = update_lerp(EASING_COS_BOUNCE,
        script->functionTemp[1], script->functionTemp[2],
        script->functionTemp[0], script->functionTemp[3]);
    endChatper->chapterChangeEffect->data.chapterChange->chapterPos.x = script->varTable[0];
    endChatper->chapterChangeEffect->data.chapterChange->chapterPos.y = posY;
    endChatper->chapterChangeEffect->data.chapterChange->endOfPos.x = script->varTable[0];
    endChatper->chapterChangeEffect->data.chapterChange->endOfPos.y = posY;

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[3]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(EndOfChapterSplitApart)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);
    s32 leftDx, rightDx;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->varTable[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
    }

    leftDx = update_lerp(EASING_LINEAR, 0.0f, (script->functionTemp[2] / 2) + 8, script->functionTemp[0], script->functionTemp[3]);
    rightDx = update_lerp(EASING_LINEAR, 0.0f, (script->functionTemp[2] / 2), script->functionTemp[0], script->functionTemp[3]);
    data->chapterChangeEffect->data.chapterChange->chapterPos.x = script->varTable[0] - leftDx;
    data->chapterChangeEffect->data.chapterChange->chapterPos.y = script->functionTemp[1];
    data->chapterChangeEffect->data.chapterChange->endOfPos.x = script->varTable[0] + rightDx;
    data->chapterChangeEffect->data.chapterChange->endOfPos.y = script->functionTemp[1];

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[3]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(func_80240BB4_9085E4)) {
    Bytecode* args = script->ptrReadPos;
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
        data->unk1E = TRUE;
    }

    data->unk0C = update_lerp(EASING_LINEAR,
        script->functionTemp[1], script->functionTemp[2],
        script->functionTemp[0], script->functionTemp[3]);

    script->functionTemp[0]++;
    if (script->functionTemp[0] < script->functionTemp[3]) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(AwaitConfirmInput)) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80240CA8_9086D8)) {
    EndChapter* data = (EndChapter*) evt_get_variable(script, MV_EndChapterDataPtr);
    fx_misc_particles(2, data->pos.x, data->pos.y, data->pos.z, 70.0f, 20.0f, 1.5f, 20, 15);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ShowMessagesInFrontOfCurtains)) {
    EndChapter* data = (EndChapter*) evt_get_variable(NULL, MV_EndChapterDataPtr);
    data->unk1E = TRUE;
    gOverrideFlags |= GLOBAL_OVERRIDES_MESSAGES_OVER_CURTAINS;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ShowMessagesBehindCurtains)) {
    EndChapter* data = (EndChapter*) evt_get_variable(NULL, MV_EndChapterDataPtr);
    data->unk1E = FALSE;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_MESSAGES_OVER_CURTAINS;
    return ApiStatus_DONE2;
}

void func_80240DA4_9087D4(void) {
    s32 fullWidth = 226;
    s32 fullHeight = 70;
    s32 baseX = SCREEN_WIDTH / 2 - fullWidth / 2;
    s32 baseY = 100;
    EndChapter* data = (EndChapter*) evt_get_variable(NULL, MV_EndChapterDataPtr);

    switch (D_802417C8_9091F8) {
        case 0:
            if (data->unk1E) {
                D_802417C8_9091F8 = 1;
            }
            break;
        case 1:
            D_802417CC_9091FC += 20;
            D_802417D0_909200 += 5;
            if (D_802417CC_9091FC >= fullWidth) {
                D_802417CC_9091FC = fullWidth;
            }
            if (D_802417D0_909200 >= fullHeight) {
                D_802417D0_909200 = fullHeight;
            }
            if (D_802417CC_9091FC == fullWidth && D_802417D0_909200 == fullHeight) {
                D_802417C8_9091F8 = 2;
            }
            break;
        case 2:
            if (!data->unk1E) {
               D_802417C8_9091F8 = 3;
            }
            break;
        case 3:
            D_802417CC_9091FC -= 20;
            D_802417D0_909200 -= 5;
            if (D_802417CC_9091FC < 0) {
                D_802417CC_9091FC = 0;
            }
            if (D_802417D0_909200 < 0) {
                D_802417D0_909200 = 0;
            }
            if (D_802417CC_9091FC == 0 && D_802417D0_909200 == 0) {
                D_802417C8_9091F8 = 4;
            }
            break;
        case 4:
            break;
    }

    if (D_802417CC_9091FC != 0 && D_802417D0_909200 != 0) {
        f64 ulx = baseX + (fullWidth * 0.5) - (D_802417CC_9091FC * 0.5);
        f64 uly = baseY + (fullHeight * 0.5) - (D_802417D0_909200 * 0.5);
        f64 lrx = baseX + (fullWidth * 0.5) + (D_802417CC_9091FC * 0.5);
        f64 lry = baseY + (fullHeight * 0.5) + (D_802417D0_909200 * 0.5);
        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
        draw_box(DRAW_FLAG_NO_CLIP, &D_802417D8_909208, ulx, uly, 0, D_802417CC_9091FC, D_802417D0_909200, 180, 0, 1.0f, 1.0f,
                 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, 320, 240, NULL);
    }
}

EvtScript N(EVS_Scene_EndOfChapter) = {
    Thread
        Set(MF_Unk_0B, FALSE)
        Call(GetEntryID, LVar0)
        Call(GetNpcPos, NPC_StarSpirit, LVar1, LVar2, LVar3)
        Call(N(CreateEndChapterData), LVar0, LVar1, LVar2, LVar3)
    EndThread
    Wait(1)
    Thread
        Call(N(AddCardAngularVelocity), 10 / DT)
    EndThread
    Thread
        Call(N(AccelerateCardSpin), 20, 150 * DT)
    EndThread
    Call(N(MakeCardFloatUpward), 5, 0, 60, 150 * DT)
    Wait(30)
    Call(N(ShowRadialShimmer), 1, 120 * DT)
    Call(N(FadeInSpiritNpc), 60 * DT)
    Wait(30 * DT)
    Call(N(FlashScreenWhite))
    Call(N(SpinDownStarSpirit), 1800, 100 * DT)
#if VERSION_JP
    Call(N(EndOfChapterBounceIn), 64, 0, 55, 60)
#else
    Call(N(EndOfChapterBounceIn), 36, 0, 55, 60)
#endif
    Thread
        Call(N(AddCardAngularVelocity), 0)
    EndThread
    Wait(60 * DT)
    Set(MF_Unk_0B, TRUE)
    Wait(1)
    Call(SetNpcAnimation, NPC_StarSpirit, ENEMY_ANIM_8)
    Call(N(ShowMessagesInFrontOfCurtains))
    Wait(16)
    Call(GetEntryID, LVar0)
    Set(LVar1, MSG_Menus_01A5)
    Switch(LVar0)
        CaseEq(kmr_23_ENTRY_0)
#if VERSION_JP
            Set(LVar1, MSG_Menus_JP_01C8)
#else
            Set(LVar1, MSG_Menus_01A5)
#endif
        CaseEq(kmr_23_ENTRY_1)
            Set(LVar1, MSG_Menus_01A6)
        CaseEq(kmr_23_ENTRY_2)
            Set(LVar1, MSG_Menus_01A7)
        CaseEq(kmr_23_ENTRY_3)
            Set(LVar1, MSG_Menus_01A8)
        CaseEq(kmr_23_ENTRY_4)
            Set(LVar1, MSG_Menus_01A9)
        CaseEq(kmr_23_ENTRY_5)
            Set(LVar1, MSG_Menus_01AA)
        CaseEq(kmr_23_ENTRY_6)
            Set(LVar1, MSG_Menus_01AB)
    EndSwitch
    Call(ShowMessageAtScreenPos, LVar1, 160, 40)
    Call(N(ShowMessagesBehindCurtains))
    Wait(15 * DT)
    Set(AF_JAN01_TreeDrop_StarPiece, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar_01) = {
    Call(SetNpcScale, NPC_SELF, Float(0.85), Float(0.85), Float(0.85))
    Call(SetNpcPos, NPC_SELF, 0, 0, 20)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Exec(N(EVS_Scene_EndOfChapter))
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar_02) = {
    Call(SetNpcAnimation, NPC_SELF, ENEMY_ANIM_8)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 0)
    Call(SetNpcPos, NPC_SELF, 0, 94, 0)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

NpcData N(NpcData_Eldstar)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
    },
};

NpcData N(NpcData_Mamar)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
    },
};

NpcData N(NpcData_Skolar)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
};

NpcData N(NpcData_Muskular)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
};

NpcData N(NpcData_Misstar)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
    },
};

NpcData N(NpcData_Klevar)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
    },
};

NpcData N(NpcData_Kalmar)[] = {
    {
        .id = NPC_StarSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
    {
        .id = NPC_AuxSpirit,
        .pos = { -40.0f, 96.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
};

NpcGroupList N(NpcGroup_Eldstar) = {
    NPC_GROUP(N(NpcData_Eldstar)),
    {}
};

NpcGroupList N(NpcGroup_Mamar) = {
    NPC_GROUP(N(NpcData_Mamar)),
    {}
};

NpcGroupList N(NpcGroup_Skolar) = {
    NPC_GROUP(N(NpcData_Skolar)),
    {}
};

NpcGroupList N(NpcGroup_Muskular) = {
    NPC_GROUP(N(NpcData_Muskular)),
    {}
};

NpcGroupList N(NpcGroup_Misstar) = {
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};

NpcGroupList N(NpcGroup_Klevar) = {
    NPC_GROUP(N(NpcData_Klevar)),
    {}
};

NpcGroupList N(NpcGroup_Kalmar) = {
    NPC_GROUP(N(NpcData_Kalmar)),
    {}
};
