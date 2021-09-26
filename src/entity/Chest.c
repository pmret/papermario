#include "common.h"
#include "effects.h"

// size unknown
typedef struct Chest {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
    /* 0x04 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s8 unk_30;
    /* 0x31 */ char unk_31[3];
    /* 0x34 */ s32 unk_34;
} Chest;

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
    Chest* data = (Chest*)entity->dataBuf;
    if ((data->unk_00 != 0xFFFF) && (get_global_flag(data->unk_00) != 0)) {
        entity->flags |= 0x4000;
        data->unk_10 = -1;
        data->unk_08 = -28.7f;
        set_entity_commandlist(entity, &D_802EAD7C);
    }
}

void entity_Chest_idle(Entity* entity) {
    f32 rotation;
    f32 angle; // angle from the Chest to the Player
    Chest* data;
    PlayerStatus* playerStatus = &gPlayerStatus;

    rotation = clamp_angle(180.0f - entity->rotation.y);
    angle = fabsf(rotation - clamp_angle(atan2(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z)));
    if ((!(playerStatus->animFlags & 1)) &&
        (!(entity->collisionFlags & 1)) &&
        ((angle <= 40.0f) || (angle >= 320.0f))) {
        entity->flags |= 0x1000;
        if ((playerStatus->animFlags & 0x10) && (entity->collisionFlags & 8)) {
            exec_entity_commandlist(entity);
            data = (Chest*)entity->dataBuf;
            data->unk_04 = 0;
            entity->flags &= ~0x1000;
            if (data->unk_10 != 0) {
                disable_player_input();
            }
            func_800EF3E4();
        }
    } else {
        entity->flags &= ~0x1000;
    }
}

void entity_Chest_begin_opening(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    data->unk_06 = 10;
    data->unk_08 = 0;
    data->unk_05 = 0;
    data->unk_02 = 40;
    sfx_play_sound(467);
}

INCLUDE_ASM(s32, "entity/Chest", entity_Chest_open);

void entity_Chest_close(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    f32 delta;

    switch (data->unk_04) {
        case 0:
            data->unk_0C = 0.0f;
            data->unk_04++;
            // fallthrough
        case 1:
            data->unk_0C += 5.0f;
            if (data->unk_0C >= 180.0f) {
                data->unk_0C = 180.0f;
                data->unk_04++;
            }
            delta = 2.6f * sin_rad(data->unk_0C * TAU / 360.0f);
            data->unk_08 += delta;
            break;
        case 2:
            data->unk_0C += 1.0f;
            if (data->unk_0C >= 185.0f) {
                data->unk_0C = 185.0f;
                data->unk_06 = 10;
                data->unk_04++;
            }
            delta = 2.0f * sin_rad(data->unk_0C * TAU / 360.0f);
            data->unk_08 += delta;
            break;
        case 3:
            data->unk_06--;
            if (data->unk_06 == 0) {
                data->unk_04++;
                entity->flags |= 0x4000;
            }
            break;
        case 4:
            break;
    }
}

INCLUDE_ASM(s32, "entity/Chest", entity_GiantChest_hide_effect);

void entity_GiantChest_open(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Chest* chest = entity->dataBuf;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 theta;
    f32 delta;
    f32 zero;
    f32 temp_f4;
    f32 four;
    f32 intermediateTheta;
    f32 phi_f22;

    if (chest->unk_10 != 0) {
        set_item_entity_position(chest->unk_14, chest->unk_18, chest->unk_1C, chest->unk_20);
    }
    entity_Chest_open(entity);

    switch (chest->unk_04) {
        case 0:
            chest->unk_02--;
            if (chest->unk_02 == 0) {
                chest->unk_24 = 0.0f;
                chest->unk_04++;
                chest->unk_28 = 20.0f;
                chest->unk_2C = 8.0f;
            }
            break;
        case 1:
            chest->unk_1C += chest->unk_2C;
            chest->unk_2C -= 0.7;
            if (chest->unk_2C <= 2.0f) {
                chest->unk_2C = 6.0f;
                chest->unk_04++;
            }
            break;
        case 2:
            if (chest->unk_28 < 140.0f) {
                chest->unk_1C += cos_rad(chest->unk_28 * TAU / 360.0f) * 3.0f;
            } else {
                temp_f4 = (chest->unk_1C - playerStatus->position.y - 30.0f) * 0.25f;
                if (temp_f4 <= 0.4) {
                    temp_f4 = 0.4f;
                }
                chest->unk_1C -= temp_f4;
            }
            delta = sin_rad(chest->unk_24 * TAU / 360.0f);
            theta = intermediateTheta = clamp_angle(atan2(entity->position.x, entity->position.z,
                                                          playerStatus->position.x, playerStatus->position.z));

            if (gGameStatusPtr->areaID == 0x12) {
                phi_f22 = 3.0f;
            } else {
                phi_f22 = 4.0f;
            }

            theta *= TAU;
            theta = theta / 360.0f;
            chest->unk_18 += (phi_f22 * sin_rad(theta) * delta);
            chest->unk_20 -= (phi_f22 * cos_rad(theta) * delta);
            chest->unk_24 += 8.0f;
            if (chest->unk_24 >= 180.0f) {
                chest->unk_24 = 180.0f;
            }
            chest->unk_28 += 13.0f;
            if (chest->unk_28 >= 180.0f){
                chest->unk_02 = 7;
                chest->unk_28 = 180.0f;
                chest->unk_04++;
                if (chest->unk_10 != 0) {
                    suggest_player_anim_setUnkFlag(0x6000C);
                    sin_cos_rad((90.0f - gCameras->currentYaw) * TAU / 360.0f, &sp18, &sp1C);
                    sin_cos_rad((180.0f - gCameras->currentYaw) * TAU / 360.0f, &sp20, &sp24);
                    zero = 0.0f;
                    four = 4.0f;
                    playFX_33(0, chest->unk_18 + zero * sp18 - sp20 * four,
                              chest->unk_1C + 12.0f, chest->unk_20 - sp1C * zero + sp24 * four, 1.0f, 0x64);
                    playFX_1B(0, chest->unk_18 + zero * sp18 - sp20 * four,
                              chest->unk_1C + 12.0f, chest->unk_20 - sp1C * zero + sp24 * four, 1.0f, &chest->unk_34);
                }
            }
            break;
        case 3:
            chest->unk_02--;
            if (chest->unk_02 == 0) {
                exec_entity_commandlist(entity);
                chest->unk_04 = 0;
            }
            break;
    }
}

// the function itself matches, but somehow it breaks other completely unrelated files
#ifdef NON_MATCHING
void entity_GiantChest_give_equipment(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    f32 angle;
    s32 flag;

    switch (data->unk_10) {
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

    if (data->unk_10 != 0) {
        angle = (entity->rotation.y * TAU) / 360.0f;
        data->unk_18 = entity->position.x + (sin_rad(angle) * 10.0f);
        data->unk_1C = entity->position.y;
        data->unk_20 = entity->position.z + (cos_rad(angle) * 10.0f);
        data->unk_14 = make_item_entity_nodelay(data->unk_10, data->unk_18, data->unk_1C, data->unk_20, 1, -1);
    }

    flag = data->unk_00;
    if (flag <= EVT_SAVE_FLAG(10000000)) {
        flag += 130000000;
    }
    set_global_flag(flag);
}
#else
INCLUDE_ASM(void, "entity/Chest", entity_GiantChest_give_equipment);
#endif

void entity_Chest_start_bound_script(Entity* entity) {
    entity_start_script(entity);
}

void entity_Chest_enable_player_input(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    if (data->unk_10 != 0) {
        enable_player_input();
    }
}

void entity_GiantChest_await_got_item(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    if (data->unk_10 != 0) {
        if (data->unk_30 != 0) {
            exec_entity_commandlist(entity);
            remove_item_entity_by_index(data->unk_14);
            suggest_player_anim_clearUnkFlag(0x10002);
            enable_player_input();
            data->unk_10 = -1;
        }
        return;
    }
    exec_entity_commandlist(entity);
}

void entity_Chest_clear_item_id(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    data->unk_10 = -1;
}

void entity_Chest_readargs(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    data->unk_10 = *D_8015C7D0;
    data->unk_00 = 0xFFFF;
}

void entity_GiantChest_init(Entity* entity) {
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
}

void entity_Chest_init(Entity* entity) {
    Chest* data = (Chest*)entity->dataBuf;
    data->unk_07 = 1;
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
    entity->scale.x = 0.56f;
    entity->scale.y = 0.56f;
    entity->scale.z = 0.56f;
}
