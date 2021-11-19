#include "common.h"

extern unkPartnerStruct* D_802BEB60_31CB80;
s32 entity_interacts_with_current_partner(s32);
s32 test_item_entity_position(f32, f32, f32, f32);
s32 partner_get_out(s32);
s32 partner_init_get_out(s32);
s32 partner_init_put_away(s32);
s32 partner_put_away(s32);    
extern s32 D_802BEC68;
extern s32 D_802BEC6C;
extern s32 D_802BEC54;
extern s32 D_802BEB40_31CB60;
extern f64 D_802BEC38_31CC58;
extern f64 D_802BEC40_31CC60;

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD100_31B120);
/*
s32 func_802BD100_31B120(void) {

    if (D_8010C978 >= 0) {
        if (D_8010C978 & 0x4000) {
            return entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
        }
    }

    return 0;
}
*/

void func_802BD144_31B164(void) {
    if ((D_8010C978 >= 0) && (D_8010C978 & 0x4000)) {
        entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
    }
}

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD17C_31B19C);

/*
s32 func_802BD17C_31B19C(Npc* npc) {
    D_802BEC68 = test_item_entity_position(npc->pos.x, npc->pos.y, npc->pos.z, npc->collisionRadius);
    
    if (D_802BEC68 >= 0) {
        D_802BEC6C = 1;
        gOverrideFlags |= 0x40;
        set_item_entity_flags(D_802BEC68, 0x200000);
        return 1;
    }
    return 0;
}
*/

void func_802BD200_31B220(Npc* npc) {
    npc->collisionHeight = 0x25;
    npc->collisionRadius = 0x18;
    npc->unk_80 = 0x00010000;
    D_802BEC54 = 0;
}

//INCLUDE_ASM(s32, "world/partner/kooper", func_802BD228_31B248);


s32 func_802BD228_31B248(Evt* script, s32 isInitialCall) {
    s32 npc = script->owner2.npcID;

    if (isInitialCall != 0) {
        partner_init_get_out(npc);
    }

    if (partner_get_out(npc)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_802BD260_31B280(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;
    Entity* entity;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BEB60_31CB80, sizeof(*D_802BEB60_31CB80));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[2]++;
    entity = D_8010C954;
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }

    switch (D_802BEB60_31CB80->unk_04) {
        case 0:
            D_802BEB60_31CB80->unk_04 = 1;
            D_802BEB60_31CB80->unk_08 = npc->flags;
            D_802BEB60_31CB80->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BEB60_31CB80->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BEB60_31CB80->unk_14 = 6.0f;
            D_802BEB60_31CB80->unk_18 = 50.0f;
            D_802BEB60_31CB80->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BEB60_31CB80->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BEB60_31CB80->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BEB60_31CB80->unk_0C);

            D_802BEB60_31CB80->unk_10 = clamp_angle(D_802BEB60_31CB80->unk_10 - D_802BEB60_31CB80->unk_14);
            if (D_802BEB60_31CB80->unk_0C > 20.0f) {
                D_802BEB60_31CB80->unk_0C--;
            } else if (D_802BEB60_31CB80->unk_0C < 19.0f) {
                D_802BEB60_31CB80->unk_0C++;
            }

            tempY = sin_rad((D_802BEB60_31CB80->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BEB60_31CB80->unk_18 += 3.0f;

            if (D_802BEB60_31CB80->unk_18 > 150.0f) {
                D_802BEB60_31CB80->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BEB60_31CB80->unk_10);
            D_802BEB60_31CB80->unk_14 += 0.8;
            if (D_802BEB60_31CB80->unk_14 > 40.0f) {
                D_802BEB60_31CB80->unk_14 = 40.0f;
            }

            if (--D_802BEB60_31CB80->unk_00 == 0) {
                D_802BEB60_31CB80->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BEB60_31CB80->unk_08;
            D_802BEB60_31CB80->unk_00 = 0x1E;
            D_802BEB60_31CB80->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BEB60_31CB80->unk_00 == 0) {
                D_802BEB60_31CB80->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

//INCLUDE_ASM(s32, "world/partner/kooper", func_802BD5F4_31B614);
void func_802BD5F4_31B614(Npc* npc) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        npc->flags = D_802BEB60_31CB80->unk_08;
        D_802BEB60_31CB80->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD638_31B658);

s32 func_802BE7E0_31C800(Evt* script, s32 isInitialCall) {
    s32 npc = script->owner2.npcID;

    if (isInitialCall) {
        partner_init_put_away(npc);
    }

    if (partner_put_away(npc)) {
        return 1;
    } else {
        return 0;
    }
}

INCLUDE_ASM(s32, "world/partner/kooper", func_802BE818_31C838);
/*
s32 func_802BE818_31C838(Npc *npcKooper, Npc *npc2) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 *temp_a1;
    f32 *temp_a2;
    f32 *temp_a3;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f8;

    if ((D_802BEB40_31CB60 != 0) && (temp_f22 = npcKooper->pos.x, temp_f24 = npcKooper->pos.z, temp_f30 = npc2->pos.x, temp_f8 = npc2->pos.z, sp30 = temp_f8, sp34 = (f32) npc2->collisionHeight, sp3C = (f32) npcKooper->collisionHeight, sp2C = npc2->pos.y, sp38 = npcKooper->pos.y, temp_f28 = (f32) ((f64) npc2->collisionRadius * D_802BEC38_31CC58), temp_f26 = (f32) ((f64) npcKooper->collisionRadius * D_802BEC40_31CC60), temp_f20 = atan2(temp_f30, temp_f8, temp_f22, temp_f24), temp_f0 = dist2D(temp_f30, sp30, temp_f22, temp_f24), temp_a2 = &sp24, temp_a3 = &sp28, temp_a1 = &sp20, sp20 = npcKooper->pos.x, sp24 = npcKooper->pos.y, sp28 = npcKooper->pos.z, (npc_test_move_taller_with_slipping(0, temp_a1, temp_a2, temp_a3, temp_f0, temp_f20, sp3C, temp_f26 + temp_f28) == 0)) && !((sp2C + sp34) < sp38) && !((sp38 + sp3C) < sp2C) && (temp_f22_2 = temp_f30 - temp_f22, temp_f24_2 = sp30 - temp_f24, !(((temp_f26 * temp_f26) + (temp_f28 * temp_f28)) <= ((temp_f22_2 * temp_f22_2) + (temp_f24_2 * temp_f24_2))))) {
        D_802BEB40_31CB60 = 2;
        return 1;
    }
    return 0;
}
*/

INCLUDE_ASM(s32, "world/partner/kooper", func_802BEA24_31CA44);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BEB10_31CB30);
