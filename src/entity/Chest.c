#include "common.h"
#include "effects.h"

void entity_Chest_open(Entity* entity);

#define CHEST_POST_ANIM_DELAY_TIME  10

// size unknown
typedef struct ChestData {
    /* 0x00 */ u16 gameFlagIndex;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 state;
    /* 0x04 */ s8 unk_05;
    /* 0x06 */ s8 postAnimateDelay;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ f32 lidAngle;
    /* 0x0C */ f32 lidOpenInterpPhase;
    /* 0x10 */ s32 itemID;
    /* 0x14 */ s32 itemEntityIndex;
    /* 0x18 */ Vec3f itemEntityPos;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s8 unk_30;
    /* 0x31 */ char unk_31[3];
    /* 0x34 */ s32 unk_34;
} ChestData;

extern s32 D_802EAD7C;
// requires data migration
#ifdef NON_MATCHING
extern Script D_802EAB30;
extern Script D_802EAC40;
extern Script D_802EAC84;

void entity_Chest_adjust_camera(void) {
    Areas areaID;
    Script* script;

    areaID = gGameStatusPtr->areaID;
    script = NULL;
    if (areaID == AREA_ISK) {
        script = &D_802EAB30;
    } else if (areaID == AREA_TIK) {
        script = &D_802EAC40;
    } else if (areaID == AREA_KZN) {
        script = &D_802EAC84;
    }
    if (script != NULL) {
        start_script(script, 10, 32);
    }
}
#else
INCLUDE_ASM(s32, "entity/Chest", entity_Chest_adjust_camera);
#endif

// requires data migration
INCLUDE_ASM(s32, "entity/Chest", entity_Chest_reset_camera);

s32 entity_Chest_setupGfx(void);
INCLUDE_ASM(s32, "entity/Chest", entity_Chest_setupGfx);

void entity_Chest_check_opened(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    if ((data->gameFlagIndex != 0xFFFF) && (get_global_flag(data->gameFlagIndex) != 0)) {
        entity->flags |= ENTITY_FLAGS_4000;
        data->itemID = -1;
        data->lidAngle = -28.7f;
        set_entity_commandlist(entity, &D_802EAD7C);
    }
}

void entity_Chest_idle(Entity* entity) {
    f32 rotation;
    f32 angle; // angle from the Chest to the Player
    ChestData* data;
    PlayerStatus* playerStatus = &gPlayerStatus;

    rotation = clamp_angle(180.0f - entity->rotation.y);
    angle = fabsf(rotation - clamp_angle(atan2(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z)));
    if ((!(playerStatus->animFlags & 1)) &&
        (!(entity->collisionFlags & 1)) &&
        ((angle <= 40.0f) || (angle >= 320.0f))) {
        entity->flags |= ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
        if ((playerStatus->animFlags & 0x10) && (entity->collisionFlags & 8)) {
            exec_entity_commandlist(entity);
            data = (ChestData*)entity->dataBuf;
            data->state = 0;
            entity->flags &= ~ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
            if (data->itemID != 0) {
                disable_player_input();
            }
            func_800EF3E4();
        }
    } else {
        entity->flags &= ~ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
    }
}

void entity_Chest_begin_opening(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    data->postAnimateDelay = CHEST_POST_ANIM_DELAY_TIME;
    data->lidAngle = 0.0f;
    data->unk_05 = 0;
    data->unk_02 = 40;
    sfx_play_sound(467);
}

INCLUDE_ASM(s32, "entity/Chest", entity_Chest_open);

void entity_Chest_close(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    f32 delta;

    switch (data->state) {
        case 0:
            data->lidOpenInterpPhase = 0.0f;
            data->state++;
            // fallthrough
        case 1:
            data->lidOpenInterpPhase += 5.0f;
            if (data->lidOpenInterpPhase >= 180.0f) {
                data->lidOpenInterpPhase = 180.0f;
                data->state++;
            }
            delta = 2.6f * sin_rad(data->lidOpenInterpPhase * TAU / 360.0f);
            data->lidAngle += delta;
            break;
        case 2:
            data->lidOpenInterpPhase += 1.0f;
            if (data->lidOpenInterpPhase >= 185.0f) {
                data->lidOpenInterpPhase = 185.0f;
                data->postAnimateDelay = CHEST_POST_ANIM_DELAY_TIME;
                data->state++;
            }
            delta = 2.0f * sin_rad(data->lidOpenInterpPhase * TAU / 360.0f);
            data->lidAngle += delta;
            break;
        case 3:
            data->postAnimateDelay--;
            if (data->postAnimateDelay == 0) {
                data->state++;
                entity->flags |= ENTITY_FLAGS_4000;
            }
            break;
        case 4:
            break;
    }
}

INCLUDE_ASM(s32, "entity/Chest", entity_GiantChest_hide_effect);

void entity_GiantChest_open(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    ChestData* chest = (ChestData*)entity->dataBuf;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 theta;
    f32 delta;
    f32 zero;
    f32 dy;
    f32 four;
    f32 intermediateTheta;
    f32 phi_f22;

    if (chest->itemID != 0) {
        set_item_entity_position(chest->itemEntityIndex, chest->itemEntityPos.x, chest->itemEntityPos.y, chest->itemEntityPos.z);
    }
    entity_Chest_open(entity);

    switch (chest->state) {
        case 0:
            chest->unk_02--;
            if (chest->unk_02 == 0) {
                chest->unk_24 = 0.0f;
                chest->state++;
                chest->unk_28 = 20.0f;
                chest->unk_2C = 8.0f;
            }
            break;
        case 1:
            chest->itemEntityPos.y += chest->unk_2C;
            chest->unk_2C -= 0.7;
            if (chest->unk_2C <= 2.0f) {
                chest->unk_2C = 6.0f;
                chest->state++;
            }
            break;
        case 2:
            if (chest->unk_28 < 140.0f) {
                chest->itemEntityPos.y += cos_rad(chest->unk_28 * TAU / 360.0f) * 3.0f;
            } else {
                dy = (chest->itemEntityPos.y - playerStatus->position.y - 30.0f) * 0.25f;
                if (dy <= 0.4) {
                    dy = 0.4f;
                }
                chest->itemEntityPos.y -= dy;
            }
            delta = sin_rad(chest->unk_24 * TAU / 360.0f);
            theta = intermediateTheta = clamp_angle(atan2(entity->position.x, entity->position.z,
                                                          playerStatus->position.x, playerStatus->position.z));

            if (gGameStatusPtr->areaID == AREA_KZN) {
                phi_f22 = 3.0f;
            } else {
                phi_f22 = 4.0f;
            }

            theta *= TAU;
            theta = theta / 360.0f;
            chest->itemEntityPos.x += (phi_f22 * sin_rad(theta) * delta);
            chest->itemEntityPos.z -= (phi_f22 * cos_rad(theta) * delta);
            chest->unk_24 += 8.0f;
            if (chest->unk_24 >= 180.0f) {
                chest->unk_24 = 180.0f;
            }
            chest->unk_28 += 13.0f;
            if (chest->unk_28 >= 180.0f){
                chest->unk_02 = 7;
                chest->unk_28 = 180.0f;
                chest->state++;
                if (chest->itemID != 0) {
                    suggest_player_anim_setUnkFlag(0x6000C);
                    sin_cos_rad((90.0f - gCameras->currentYaw) * TAU / 360.0f, &sp18, &sp1C);
                    sin_cos_rad((180.0f - gCameras->currentYaw) * TAU / 360.0f, &sp20, &sp24);
                    zero = 0.0f;
                    four = 4.0f;
                    playFX_33(0, chest->itemEntityPos.x + zero * sp18 - sp20 * four,
                              chest->itemEntityPos.y + 12.0f, chest->itemEntityPos.z - sp1C * zero + sp24 * four, 1.0f, 0x64);
                    playFX_1B(0, chest->itemEntityPos.x + zero * sp18 - sp20 * four,
                              chest->itemEntityPos.y + 12.0f, chest->itemEntityPos.z - sp1C * zero + sp24 * four, 1.0f, &chest->unk_34);
                }
            }
            break;
        case 3:
            chest->unk_02--;
            if (chest->unk_02 == 0) {
                exec_entity_commandlist(entity);
                chest->state = 0;
            }
            break;
    }
}

void entity_GiantChest_give_equipment(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    f32 angle;
    s32 flag;

    switch (data->itemID) {
    	case 1:
    	    gPlayerData.bootsLevel = 0;
    	    break;
    	case 2:
    	    gPlayerData.bootsLevel = 1;
    	    break;
    	case 3:
    	    gPlayerData.bootsLevel = 2;
    	    break;
    	case 4:
    	    gPlayerData.hammerLevel = 0;
    	    break;
    	case 5:
    	    gPlayerData.hammerLevel = 1;
    	    break;
    	case 6:
    	    gPlayerData.hammerLevel = 2;
    	    break;
    }

    if (data->itemID != 0) {
        angle = (entity->rotation.y * TAU) / 360.0f;
        data->itemEntityPos.x = entity->position.x + (sin_rad(angle) * 10.0f);
        data->itemEntityPos.y = entity->position.y;
        data->itemEntityPos.z = entity->position.z + (cos_rad(angle) * 10.0f);
        data->itemEntityIndex = make_item_entity_nodelay(data->itemID, data->itemEntityPos.x, data->itemEntityPos.y, data->itemEntityPos.z, 1, -1);
    }

    flag = data->gameFlagIndex;
    if (flag <= EVT_SAVE_FLAG(10000000)) {
        flag += 130000000;
    }
    set_global_flag(flag);
}

void entity_Chest_start_bound_script(Entity* entity) {
    entity_start_script(entity);
}

void entity_Chest_enable_player_input(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    if (data->itemID != 0) {
        enable_player_input();
    }
}

void entity_GiantChest_await_got_item(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    if (data->itemID != 0) {
        if (data->unk_30 != 0) {
            exec_entity_commandlist(entity);
            remove_item_entity_by_index(data->itemEntityIndex);
            suggest_player_anim_clearUnkFlag(0x10002);
            enable_player_input();
            data->itemID = -1;
        }
        return;
    }
    exec_entity_commandlist(entity);
}

void entity_Chest_clear_item_id(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    data->itemID = -1;
}

void entity_Chest_readargs(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    data->itemID = *CreateEntityVarArgBuffer;
    data->gameFlagIndex = 0xFFFF;
}

void entity_GiantChest_init(Entity* entity) {
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
}

void entity_Chest_init(Entity* entity) {
    ChestData* data = (ChestData*)entity->dataBuf;
    data->unk_07 = 1;
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
    entity->scale.x = 0.56f;
    entity->scale.y = 0.56f;
    entity->scale.z = 0.56f;
}
