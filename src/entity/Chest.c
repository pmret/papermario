#include "common.h"

// size unknown
typedef struct giantChestStruct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s8 unk_04;
    /* 0x04 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s8 unk_30;
} giantChestStruct;

extern s32 D_802EAD7C;
// requires data migration
#ifdef NON_MATCHING
extern Script D_802EAB30;
extern Script D_802EAC40;
extern Script D_802EAC84;

void entity_Chest_adjust_camera(void) {
    s16 temp_v1;
    Script* script;

    temp_v1 = gGameStatusPtr->areaID;
    script = NULL;
    if (temp_v1 == 0xB) {
        script = &D_802EAB30;
    } else if (temp_v1 == 2) {
        script = &D_802EAC40;
    } else if (temp_v1 == 0x12) {
        script = &D_802EAC84;
    }
    if (script != NULL) {
        start_script(script, 0xA, 0x20);
    }
}
#else
INCLUDE_ASM(s32, "entity/Chest", entity_Chest_adjust_camera);
#endif

// requires data migration
INCLUDE_ASM(s32, "entity/Chest", entity_Chest_reset_camera);

INCLUDE_ASM(s32, "entity/Chest", entity_Chest_setupGfx);

void entity_Chest_check_opened(Entity* entity) {
	giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
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
    giantChestStruct* data;
    PlayerStatus* playerStatus = &gPlayerStatus;

    rotation = clamp_angle(180.0f - entity->rotation.y);
    angle = fabsf(rotation - clamp_angle(atan2(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z)));
    if ((!(playerStatus->animFlags & 1)) &&
        (!(entity->collisionFlags & 1)) &&
        ((angle <= 40.0f) || (angle >= 320.0f))) {
        entity->flags |= 0x1000;
        if ((playerStatus->animFlags & 0x10) && (entity->collisionFlags & 8)) {
            exec_entity_commandlist(entity);
            data = (giantChestStruct*)entity->dataBuf;
            data->unk_04 = 0;
            entity->flags &= ~0x1000;
            if (data->unk_10 != 0) {
                disable_player_input();
            }
            func_800EF3E4();
            return;
        }
        return;
    }
    entity->flags &= ~0x1000;
}

void entity_Chest_begin_opening(Entity* entity) {
	giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
    data->unk_06 = 10;
    data->unk_08 = 0;
    data->unk_05 = 0;
    data->unk_02 = 40;
    sfx_play_sound(467);
}

INCLUDE_ASM(s32, "entity/Chest", entity_Chest_open);

// regalloc after sin_rad
#ifdef NON_MATCHING
void entity_Chest_close(Entity* entity) {
	giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
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
        data->unk_08 += 2.6f * sin_rad(data->unk_0C * 6.28318f / 360.0f);
        break;
    case 2:
        data->unk_0C += 1.0f;
        if (data->unk_0C >= 185.0f) {
            data->unk_0C = 185.0f;
            data->unk_06 = 10;
            data->unk_04++;
        }
        data->unk_08 += 2.0f * sin_rad(data->unk_0C * 6.28318f / 360.0f);
        break;
    case 3:
        data->unk_06--;
        if (data->unk_06 == 0) {
            data->unk_04++;
            entity->flags |= 0x4000;
        }
        break;
    case 4: // needed to make gcc create a jumptable
        break;
    }
}
#else
INCLUDE_ASM(s32, "entity/Chest", entity_Chest_close);
#endif

INCLUDE_ASM(s32, "entity/Chest", entity_GiantChest_hide_effect);

INCLUDE_ASM(s32, "entity/Chest", entity_GiantChest_open);

// the function itself matches, but somehow it breaks other completely unrelated files
#ifdef NON_MATCHING
void entity_GiantChest_give_equipment(Entity* entity) {
    giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
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
        angle = (entity->rotation.y * 6.28318f) / 360.0f;
        data->unk_18 = entity->position.x + (sin_rad(angle) * 10.0f);
        data->unk_1C = entity->position.y;
        data->unk_20 = entity->position.z + (cos_rad(angle) * 10.0f);
        data->unk_14 = make_item_entity_nodelay(data->unk_10, data->unk_18, data->unk_1C, data->unk_20, 1, -1);
    }

    flag = data->unk_00;
    if (flag <= (s32)0xF8D8F200) {
        flag += 0x7BFA480;
    }
    set_global_flag(flag);
}
#else
INCLUDE_ASM(void, "entity/Chest", entity_GiantChest_give_equipment);
#endif

void entity_Chest_start_bound_script(Npc* npc) {
    entity_start_script(npc);
}

void entity_Chest_enable_player_input(Entity* entity) {
	giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
    if (data->unk_10 != 0) {
        enable_player_input();
    }
}

void entity_GiantChest_await_got_item(Entity* entity) {
    giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
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
	giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
	data->unk_10 = -1;
}

void entity_Chest_readargs(Entity* entity) {
	giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
	data->unk_10 = *D_8015C7D0;
    data->unk_00 = 0xFFFF;
}

void entity_GiantChest_init(Entity* entity) {
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
}

void entity_Chest_init(Entity* entity) {
    giantChestStruct* data = (giantChestStruct*)entity->dataBuf;
    data->unk_07 = 1;
    entity_Chest_readargs(entity);
    entity->renderSetupFunc = &entity_Chest_setupGfx;
    entity->scale.x = 0.56f;
    entity->scale.y = 0.56f;
    entity->scale.z = 0.56f;
}
