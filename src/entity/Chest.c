#include "common.h"
#include "effects.h"
#include "ld_addrs.h"
#include "entity.h"
#include "sprite/player.h"

#if VERSION_JP // TODO remove once segments are split
extern Addr entity_model_Chest_ROM_END;
extern Addr entity_model_Chest_ROM_START;
#endif

extern EntityScript Entity_Chest_ScriptOpened;

extern Gfx Entity_Chest_RenderBox[];
extern Gfx Entity_Chest_RenderLid[];
extern Mtx Entity_Chest_LidMtx;

EvtScript Entity_Chest_AdjustCam_ISK = {
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, 0, -195, -358, -555)
        Call(SetPanTarget, 0, LVar0, LVar1, LVar2)
        Call(SetCamDistance, 0, Float(290.0))
        Call(SetCamPitch, 0, Float(20.0), Float(-10.0))
        Call(SetCamSpeed, 0, Float(8.0))
        Call(PanToTarget, 0, 0, 1)
        Call(WaitForCam, 0, Float(1.0))
    EndThread
    Return
    End
};

EvtScript Entity_Chest_ResetCam_ISK = {
    Thread
        Call(ResetCam, 0, 3)
    EndThread
    Return
    End
};

EvtScript Entity_Chest_AdjustCam_TIK = {
    Thread
        Call(AdjustCam, 0, Float(8.0), 0, Float(300.0), Float(17.5), Float(-9.5))
    EndThread
    Return
    End
};

EvtScript Entity_Chest_AdjustCam_KZN = {
    Thread
        Call(AdjustCam, 0, Float(8.0), 0, Float(210.0), Float(21.0), Float(-16.0))
    EndThread
    Return
    End
};

EvtScript Entity_Chest_ResetCam_Default = {
    Thread
        Call(ResetCam, 0, 3)
    EndThread
    Return
    End
};

void entity_Chest_adjust_camera(Entity* entity) {
    s16 areaID;
    EvtScript* script;

    areaID = gGameStatusPtr->areaID;
    script = NULL;
    if (areaID == AREA_ISK) {
        script = &Entity_Chest_AdjustCam_ISK;
    } else if (areaID == AREA_TIK) {
        script = &Entity_Chest_AdjustCam_TIK;
    } else if (areaID == AREA_KZN) {
        script = &Entity_Chest_AdjustCam_KZN;
    }
    if (script != NULL) {
        start_script(script, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
    }
}

void entity_Chest_reset_camera(Entity* entity) {
    s16 areaID;
    EvtScript* script;

    areaID = gGameStatusPtr->areaID;
    script = NULL;
    if (areaID == AREA_ISK) {
        script = &Entity_Chest_ResetCam_ISK;
    } else {
        script = &Entity_Chest_ResetCam_Default;
    }
    start_script(script, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
}

void entity_Chest_setupGfx(s32 entityIndex) {
    Gfx* gfxPos = gMainGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);
    ChestData* data = entity->dataBuf.chest;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* gfx;

    guRotateF(sp58, data->lidAngle, 1.0f, 0.0f, 0.0f);
    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &Entity_Chest_LidMtx));
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = ENTITY_ADDR(entity, Gfx*, Entity_Chest_RenderLid);
    gSPDisplayList(gfxPos++, gfx);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);
    gMainGfxPos = gfxPos;
}

void entity_Chest_check_opened(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    if ((data->gameFlagIndex != 0xFFFF) && (get_global_flag(data->gameFlagIndex) != 0)) {
        entity->flags |= ENTITY_FLAG_4000;
        data->itemID = -1;
        data->lidAngle = -28.7f;
        set_entity_commandlist(entity, Entity_Chest_ScriptOpened);
    }
}

void entity_Chest_idle(Entity* entity) {
    f32 rotation;
    f32 angle; // angle from the Chest to the Player
    ChestData* data;
    PlayerStatus* playerStatus = &gPlayerStatus;

    rotation = clamp_angle(180.0f - entity->rot.y);
    angle = fabsf(rotation - clamp_angle(atan2(entity->pos.x, entity->pos.z, playerStatus->pos.x, playerStatus->pos.z)));
    if ((!(playerStatus->animFlags & PA_FLAG_USING_WATT)) &&
        (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) &&
        ((angle <= 40.0f) || (angle >= 320.0f))) {
        entity->flags |= ENTITY_FLAG_SHOWS_INSPECT_PROMPT;
        if ((playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) && (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_WALL)) {
            exec_entity_commandlist(entity);
            data = entity->dataBuf.chest;
            data->state = 0;
            entity->flags &= ~ENTITY_FLAG_SHOWS_INSPECT_PROMPT;
            if (data->itemID != 0) {
                disable_player_input();
            }
            func_800EF3E4();
        }
    } else {
        entity->flags &= ~ENTITY_FLAG_SHOWS_INSPECT_PROMPT;
    }
}

void entity_Chest_begin_opening(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    data->postLidAnimDelay = 10;
    data->lidAngle = 0.0f;
    data->openState = 0;
    data->giveItemTimer = 40;
    sfx_play_sound(SOUND_OPEN_CHEST);
}

void entity_Chest_open(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    f32 temp;

    switch (data->openState) {
        case 0:
            data->postLidAnimDelay--;
            data->lidAngle -= 1.0f;
            if (data->lidAngle < -2.0f) {
                data->lidAngle = -2.0f;
            }

            if (data->postLidAnimDelay == 0) {
                data->postLidAnimDelay = 8;
                data->openState++;
            }
            break;
        case 1:
            data->postLidAnimDelay--;
            if (data->postLidAnimDelay == 0) {
                data->lidAnimInterpPhase = 0.0f;
                data->openState++;
            }
            break;
        case 2:
            data->lidAnimInterpPhase += 4.0f;
            if (data->lidAnimInterpPhase >= 180.0f) {
                data->openState++;
            }
            temp = sin_rad(DEG_TO_RAD(data->lidAnimInterpPhase)) * 3.0f;
            data->lidAngle -= temp;
            break;
        case 3:
            data->lidAnimInterpPhase += 1.0f;
            if (data->lidAnimInterpPhase >= 190.0f) {
                data->postLidAnimDelay = 10;
                data->openState++;
            }
            temp = sin_rad(DEG_TO_RAD(data->lidAnimInterpPhase)) * 2.0f;
            data->lidAngle -= temp;
            break;
        case 4:
            data->postLidAnimDelay--;
            if (data->postLidAnimDelay == 0) {
                if (data->unk_07 != 0) {
                    exec_entity_commandlist(entity);
                } else {
                    data->openState++;
                }
            }
            break;
        case 5:
            break;

    }
}

void entity_Chest_close(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    f32 delta;

    switch (data->state) {
        case 0:
            data->lidAnimInterpPhase = 0.0f;
            data->state++;
            // fallthrough
        case 1:
            data->lidAnimInterpPhase += 5.0f;
            if (data->lidAnimInterpPhase >= 180.0f) {
                data->lidAnimInterpPhase = 180.0f;
                data->state++;
            }
            delta = 2.6f * sin_rad(DEG_TO_RAD(data->lidAnimInterpPhase));
            data->lidAngle += delta;
            break;
        case 2:
            data->lidAnimInterpPhase += 1.0f;
            if (data->lidAnimInterpPhase >= 185.0f) {
                data->lidAnimInterpPhase = 185.0f;
                data->postLidAnimDelay = 10;
                data->state++;
            }
            delta = 2.0f * sin_rad(DEG_TO_RAD(data->lidAnimInterpPhase));
            data->lidAngle += delta;
            break;
        case 3:
            data->postLidAnimDelay--;
            if (data->postLidAnimDelay == 0) {
                data->state++;
                entity->flags |= ENTITY_FLAG_4000;
            }
            break;
        case 4:
            break;
    }
}

void entity_GiantChest_hide_effect(Entity* entity) {
    ChestData* chest = entity->dataBuf.chest;
    EffectInstance* effect = chest->gotItemEffect;

    if (effect != NULL) {
        effect->data.gotItemOutline->timeLeft = 10;
    }
}

void entity_GiantChest_open(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    ChestData* chest = entity->dataBuf.chest;
    f32 cosFwd;
    f32 sinFwd;
    f32 cosRight;
    f32 sinRight;
    f32 theta;
    f32 giveItemLerpAlpha;
    f32 horizontalOffset;
    f32 dy;
    f32 depthOffset;
    f32 intermediateTheta;
    f32 radius;

    if (chest->itemID != 0) {
        set_item_entity_position(chest->itemEntityIndex, chest->itemEntityPos.x, chest->itemEntityPos.y, chest->itemEntityPos.z);
    }
    entity_Chest_open(entity);

    switch (chest->state) {
        case 0:
            chest->giveItemTimer--;
            if (chest->giveItemTimer == 0) {
                chest->giveItemRadiusInterpPhase = 0.0f;
                chest->state++;
                chest->giveItemHeightInterpPhase = 20.0f;
                chest->itemVelY = 8.0f;
            }
            break;
        case 1:
            chest->itemEntityPos.y += chest->itemVelY;
            chest->itemVelY -= 0.7;
            if (chest->itemVelY <= 2.0f) {
                chest->itemVelY = 6.0f;
                chest->state++;
            }
            break;
        case 2:
            if (chest->giveItemHeightInterpPhase < 140.0f) {
                chest->itemEntityPos.y += cos_rad(DEG_TO_RAD(chest->giveItemHeightInterpPhase)) * 3.0f;
            } else {
                dy = (chest->itemEntityPos.y - playerStatus->pos.y - 30.0f) * 0.25f;
                if (dy <= 0.4) {
                    dy = 0.4f;
                }
                chest->itemEntityPos.y -= dy;
            }
            giveItemLerpAlpha = sin_rad(DEG_TO_RAD(chest->giveItemRadiusInterpPhase));
            theta = intermediateTheta = clamp_angle(atan2(entity->pos.x, entity->pos.z, playerStatus->pos.x, playerStatus->pos.z));

            if (gGameStatusPtr->areaID == AREA_KZN) {
                radius = 3.0f;
            } else {
                radius = 4.0f;
            }

            theta *= TAU;
            theta = theta / 360.0f;
            chest->itemEntityPos.x += (radius * sin_rad(theta) * giveItemLerpAlpha);
            chest->itemEntityPos.z -= (radius * cos_rad(theta) * giveItemLerpAlpha);
            chest->giveItemRadiusInterpPhase += 8.0f;
            if (chest->giveItemRadiusInterpPhase >= 180.0f) {
                chest->giveItemRadiusInterpPhase = 180.0f;
            }
            chest->giveItemHeightInterpPhase += 13.0f;
            if (chest->giveItemHeightInterpPhase >= 180.0f){
                chest->giveItemTimer = 7;
                chest->giveItemHeightInterpPhase = 180.0f;
                chest->state++;
                if (chest->itemID != 0) {
                    suggest_player_anim_always_forward(ANIM_MarioW1_Lift);
                    sin_cos_rad(DEG_TO_RAD(90.0f - gCameras[CAM_DEFAULT].curYaw), &sinRight, &cosRight);
                    sin_cos_rad(DEG_TO_RAD(180.0f - gCameras[CAM_DEFAULT].curYaw), &sinFwd, &cosFwd);
                    horizontalOffset = 0.0f;
                    depthOffset = 4.0f;
                    //RadialFlowOut
                    fx_radial_shimmer(0, chest->itemEntityPos.x + horizontalOffset * sinRight - depthOffset * sinFwd,
                              chest->itemEntityPos.y + 12.0f, chest->itemEntityPos.z - cosRight * horizontalOffset + cosFwd * depthOffset, 1.0f, 0x64);
                    //GotItemOutline
                    fx_got_item_outline(0, chest->itemEntityPos.x + horizontalOffset * sinRight - sinFwd * depthOffset,
                              chest->itemEntityPos.y + 12.0f, chest->itemEntityPos.z - cosRight * horizontalOffset + cosFwd * depthOffset, 1.0f, &chest->gotItemEffect);
                }
            }
            break;
        case 3:
            chest->giveItemTimer--;
            if (chest->giveItemTimer == 0) {
                exec_entity_commandlist(entity);
                chest->state = 0;
            }
            break;
    }
}

void entity_GiantChest_give_equipment(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    f32 angle;
    s32 flagIndex;

    switch (data->itemID) {
        case ITEM_BOOTS:
            gPlayerData.bootsLevel = 0;
            break;
        case ITEM_SUPER_BOOTS:
            gPlayerData.bootsLevel = 1;
            break;
        case ITEM_ULTRA_BOOTS:
            gPlayerData.bootsLevel = 2;
            break;
        case ITEM_HAMMER:
            gPlayerData.hammerLevel = 0;
            break;
        case ITEM_SUPER_HAMMER:
            gPlayerData.hammerLevel = 1;
            break;
        case ITEM_ULTRA_HAMMER:
            gPlayerData.hammerLevel = 2;
            break;
    }

    if (data->itemID != 0) {
        angle = DEG_TO_RAD(entity->rot.y);
        data->itemEntityPos.x = entity->pos.x + (sin_rad(angle) * 10.0f);
        data->itemEntityPos.y = entity->pos.y;
        data->itemEntityPos.z = entity->pos.z + (cos_rad(angle) * 10.0f);
        data->itemEntityIndex = make_item_entity_nodelay(data->itemID,
            data->itemEntityPos.x, data->itemEntityPos.y, data->itemEntityPos.z,
            ITEM_SPAWN_MODE_DECORATION, -1);
    }

    flagIndex = data->gameFlagIndex;
    if (flagIndex <= EVT_GAME_FLAG_CUTOFF) {
        flagIndex = EVT_INDEX_OF_GAME_FLAG(flagIndex);
    }
    set_global_flag(flagIndex);
}

void entity_Chest_start_bound_script(Entity* entity) {
    entity_start_script(entity);
}

void entity_Chest_enable_player_input(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    if (data->itemID != 0) {
        enable_player_input();
    }
}

void entity_GiantChest_await_got_item(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    if (data->itemID != 0) {
        if (data->gotItemDone) {
            exec_entity_commandlist(entity);
            remove_item_entity_by_index(data->itemEntityIndex);
            suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            enable_player_input();
            data->itemID = -1;
        }
        return;
    }
    exec_entity_commandlist(entity);
}

void entity_Chest_clear_item_id(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    data->itemID = -1;
}

void entity_Chest_readargs(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    data->itemID = CreateEntityVarArgBuffer[0];
    data->gameFlagIndex = 0xFFFF;
}

void entity_GiantChest_init(Entity* entity) {
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
}

void entity_Chest_init(Entity* entity) {
    ChestData* data = entity->dataBuf.chest;
    data->unk_07 = 1;
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
    entity->scale.x = 0.56f;
    entity->scale.y = 0.56f;
    entity->scale.z = 0.56f;
}

EntityScript Entity_GiantChest_Script = {
    es_Call(entity_Chest_check_opened)
    es_SetCallback(entity_Chest_idle, 0)
    es_Call(entity_Chest_adjust_camera)
    es_Call(entity_GiantChest_give_equipment)
    es_Call(entity_Chest_begin_opening)
    es_SetCallback(entity_GiantChest_open, 0)
    es_Call(entity_Chest_start_bound_script)
    es_SetCallback(entity_GiantChest_await_got_item, 0)
    es_Call(entity_GiantChest_hide_effect)
    es_Call(entity_Chest_reset_camera)
    es_SetCallback(entity_Chest_close, 0)
    es_SetCallback(NULL, 0)
    es_Restart
    es_End
};

EntityScript Entity_Chest_ScriptOpened = {
    es_SetCallback(NULL, 0)
    es_End
};
EntityScript Entity_Chest_Script = {
    es_Call(entity_Chest_check_opened)
    es_SetCallback(entity_Chest_idle, 0)
    es_Call(entity_Chest_begin_opening)
    es_Call(entity_Chest_start_bound_script)
    es_Call(entity_Chest_clear_item_id)
    es_SetCallback(entity_Chest_open, 0)
    es_Call(entity_Chest_enable_player_input)
    es_SetCallback(entity_Chest_close, 0)
    es_SetCallback(NULL, 0)
    es_Restart
    es_End
};
EntityModelScript Entity_Chest_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_Chest_RenderBox, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_GiantChest = {
    .flags = ENTITY_FLAG_4000,
    .typeDataSize = sizeof(ChestData),
    .renderCommandList = Entity_Chest_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_GiantChest_init,
    .updateEntityScript = Entity_GiantChest_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(Chest) },
    .entityType = ENTITY_TYPE_CHEST,
    .aabbSize = { 50, 45, 46 }
};
EntityBlueprint Entity_Chest = {
    .flags = ENTITY_FLAG_8000 | ENTITY_FLAG_4000,
    .typeDataSize = sizeof(ChestData),
    .renderCommandList = Entity_Chest_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_Chest_init,
    .updateEntityScript = Entity_Chest_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(Chest) },
    .entityType = ENTITY_TYPE_CHEST,
    .aabbSize = { 28, 26, 23 }
};
