#include "common.h"

// TODO: replace usages of these with proper constants
extern f64 D_802EB1D0; // 0.09
extern f64 D_802EB1D8; // 0.045
extern f64 D_802EB1E0; // 0.18
extern f64 D_802EB1E8; // 0.09
extern f64 D_802EB1F0; // 1.2
extern f64 D_802EB1F8; // 0.3
extern f64 D_802EB200; // 1.2
extern f64 D_802EB208; // 0.3

//display list func
INCLUDE_ASM(s32, "code_104940_len_dc0", func_802E30C0);

void func_802E31B0(Entity* entity) {
    func_80072230(0, entity->position.x, entity->position.y, entity->position.z, 1.0f, 0x3C);
}

f32 func_802E31EC(Entity* entity) {

    if ((get_entity_type(entity->listIndex) - 24) < 3) {
        entity->scale.y = 0.23f;
        entity->scale.x = 1.04f;
        entity->scale.z = 1.04f;
        entity->position.y += 18.0f;
    } else {
        entity->scale.y = 0.46f;
        entity->scale.x = 2.08f;
        entity->scale.z = 2.08f;
        entity->position.y += 18.0f;
    }
}

void func_802E328C(Entity* entity) {

    if ((get_entity_type(entity->listIndex) - 24) < 3) {
        entity->scale.x -= D_802EB1D0;
        entity->scale.z -= D_802EB1D0;
        entity->scale.y += D_802EB1D8;
        entity->position.y -= 3.0f;
    } else {
        entity->scale.x -= D_802EB1E0;
        entity->scale.z -= D_802EB1E0;
        entity->scale.y += D_802EB1E8;
        entity->position.y -= 3.0f;
    }
    func_802E3650(entity);
}

INCLUDE_ASM(s32, "code_104940_len_dc0", func_802E3370);

s32 func_802E3650(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    s32 ret = 0;

    if (func_80112B20() != 0) {
        if (entity->flags & 0x200000) {
            ret = 1;
            func_802E3370(entity);
            if (temp->unk_10 != -1) {
                ItemEntity* itemEntity = get_item_entity(temp->unk_10);
                itemEntity->position.y = entity->position.y + 4.0f;
            }
        }
    }

    return ret;
}

void entity_init_Hammer23Block_normal(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    f32 posY;

    temp->unk_10 = -1;
    temp->unk_14 = entity->position.y;
    temp->unk_0E = -1;
    entity->flags &= ~0x200000;
}

void func_802E3714(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    temp->unk_18 = 90.0f;
}

void func_802E3728(Entity* entity) {
    f64 temp_f20;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    func_802E3A00(entity);
    temp_f20 = entity->position.y;
    entity->position.y = temp_f20 + ((f64)sin_rad((temp->unk_18 * 6.28318f) / 360.0f) * 2);
    temp->unk_18 += 60.0f;
    if (temp->unk_18 > 450.0f) {
        temp->unk_18 = clamp_angle(temp->unk_18);
        func_8010FD68(entity);
    }
}

void func_802E37E4(Entity* entity) {
    f64 temp_f20;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    func_802E3A00(entity);
    temp_f20 = entity->position.y;
    entity->position.y = temp_f20 + ((f64)sin_rad((temp->unk_18 * 6.28318f) / 360.0f));
    temp->unk_18 += 60.0f;
    if (temp->unk_18 >= 360.0f) {
        temp->unk_18 = 0.0f;
        entity->position.y = temp->unk_14;
        func_8010FD68(entity);
    }
}

void func_802E3898(Entity* entity) {
    struct802E3650* temp;

    entity_init_Hammer23Block_normal(entity);
    temp = (struct802E3650*)entity->dataBuf;
    temp->unk_04 = 0xA;
    temp->unk_06 = 0x7B;
    temp->unk_0A = 0xFFFF;
}

extern s32 D_802E9E54;
extern StaticEntityData D_802EA07C;

void func_802E38D8(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    s32 phi_v1;
    s32 phi_v0;

    if (temp->unk_04 > 0) {
        if (temp->unk_04 == 10) {
            phi_v1 = 21;
            phi_v0 = temp->unk_0A;
        } else {
            phi_v1 = 20;
            phi_v0 = 0;
        }
        make_item_entity_nodelay(0x157, entity->position.x, entity->position.y + 28.0, entity->position.z, phi_v1, phi_v0);
        temp->unk_04 -= 1;
    }

    if ((temp->unk_04 == 0) || (temp->unk_06 == 0)) {
        temp->unk_03 = 1;
        func_8010FBC0(get_entity_by_index(create_entity(&D_802EA07C, entity->position.x, entity->position.y, entity->position.z,
                                          entity->rotation.y, 0x80000000)), &D_802E9E54);
        entity->flags |= 0x20000020;
    }
}

void func_802E3A00(Entity* entity) {
    u16 temp_v0;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    s16 phi_return;

    if (entity->unk_0A == 0xE) {
        if (temp->unk_04 != 0xA) {
            temp->unk_06 -= 1;
            if (temp->unk_06 < 0) {
                temp->unk_06 = 0;
                temp->unk_04 = 1;
            }
        }
    }
}

void func_802E3A48(Entity* entity) {
    s32 temp_v0;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    if ((entity->unk_06 & 0x80) != 0) {
        func_8010FD68(entity);
        return;
    }
    func_802E3A00(entity);
    func_802E3650(entity);
    if (temp->unk_03 != 0) {
        create_entity(&D_802EA07C, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
        entity->flags |= 0x20000020;
    }
}

void func_802E3B08(Entity* entity) {
    s32 temp_v0;
    u16 temp_v1;
    struct802E3650* temp = entity->dataBuf;

    if (temp->unk_0A != 0xFFFF) {
        if (get_global_flag(temp->unk_0A) != 0) {
            create_entity(&D_802EA07C, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
            entity->flags |= 0x20000020;
        }
    }
}

extern s32 D_802E9E80;

#ifdef NON_MATCHING
// tail merge + rodata
s32 func_802E3BA4(Entity* entity) {
    u8 bVar1;
    s32 bVar2;
    s32 iVar3;
    s32 uVar4;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->alpha == 0) && ((entity->unk_06 & 1) != 0)) {
        return 0;
    }

    bVar1 = entity->unk_06;
    if (bVar1 & 4) {
        s32 type = get_entity_type(entity->listIndex);
        if (type == 0xC) {
            return 0;
        }

        if (type >= 0xC) {
            if (type < 0x1b) {
                if (type > 0x14) {
                    return 0;
                }
            }
        }

        if (!(playerStatus->flags & 2)) {
            return 1;
        }
        func_8010FD68(entity);
        return 1;
    }
    if (bVar1 & 0x80) {
        func_8010FD68(entity);
        return 1;
    }

    bVar2 = FALSE;
    if (bVar1 & 1) {
        if ((playerStatus->actionState == 0xd) || (playerStatus->actionState == 0x0f)) {
            return 0;
        }

        if ((playerStatus->actionState == 0x0e) || (playerStatus->actionState == 0x10)) {
            bVar2 = TRUE;
        } else {
            return 1;
        }
    } else {
        if (!(bVar1 & 0x40)) {
            return 1;
        }
        if ((playerStatus->flags & 0x1000000) == 0) {
            return 1;
        }
    }

    switch (get_entity_type(entity->listIndex)) {
        default:
            break;
        case 0x15:
        case 0x18:
            if (bVar2) {
                if (gPlayerData.bootsLevel < 1) {
                    bVar2 = FALSE;
                }
            } else {
                if (gPlayerData.hammerLevel > -1) {
                    bVar2 = TRUE;
                }
            }
            if (!bVar2) {
                return 1;
            }
            func_8010FBC0(entity, &D_802E9E80);
            play_sound_at_position(0x14f, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x16:
        case 0x19:
            if (bVar2) {
                if (gPlayerData.bootsLevel < 2) {
                    bVar2 = FALSE;
                }
            } else if (gPlayerData.hammerLevel > 0) {
                bVar2 = TRUE;
            }
            if (!bVar2) {
                return 1;
            }
            func_8010FBC0(entity, &D_802E9E80);
            play_sound_at_position(0x150, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x17:
        case 0x1a:
            if (gPlayerData.hammerLevel < '\x02') {
                return 1;
            }
            func_8010FBC0(entity, &D_802E9E80);
            play_sound_at_position(0x151, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
            func_80110678(entity);
            func_8010FD68(entity);
            return 1;
        case 0xb:
            func_80110678(entity);
            break;
    }
    return 1;
}
#else
INCLUDE_ASM(s32, "code_104940_len_dc0", func_802E3BA4, Entity* entity);
#endif

void entity_init_Hammer1Block_normal(Entity* entity) {
    entity_init_Hammer23Block_normal(entity);
    entity->unk_3C = func_802E30C0;
}

s32 entity_init_HammerBlock_small(Entity* entity) {
    s32 temp_v0;
    struct802E3650* temp = entity->dataBuf;

    temp->unk_10 = -1;
    temp->unk_14 = entity->position.y;
    temp->unk_0E = -1;
    entity->flags &= ~0x200000;
    entity->scale.x = 0.5f;
    entity->scale.y = 0.5f;
    entity->scale.z = 0.5f;
}
