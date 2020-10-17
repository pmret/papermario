#include "code_190B20.h"

INCLUDE_ASM(s32, "code_190B20", create_target_list);

void player_create_target_list(Actor* actor) {
    create_target_list(actor, 0);
}

void enemy_create_target_list(Actor* actor) {
    create_target_list(actor, 1);
}

INCLUDE_ASM(s32, "code_190B20", func_80263064);

INCLUDE_ASM(s32, "code_190B20", func_80263230);

INCLUDE_ASM(s32, "code_190B20", func_8026324C);

INCLUDE_ASM(s32, "code_190B20", func_80263268);

INCLUDE_ASM(s32, "code_190B20", func_80263300);

INCLUDE_ASM(s32, "code_190B20", func_802633E8);

INCLUDE_ASM(s32, "code_190B20", func_80263434);

INCLUDE_ASM(s32, "code_190B20", func_80263464);

INCLUDE_ASM(s32, "code_190B20", func_802634B8);

INCLUDE_ASM(s32, "code_190B20", func_802636E4);

INCLUDE_ASM(s32, "code_190B20", func_80263914);

INCLUDE_ASM(s32, "code_190B20", count_power_plus);

INCLUDE_ASM(s32, "code_190B20", deduct_current_move_fp);

INCLUDE_ASM(s32, "code_190B20", func_80263C60);

INCLUDE_ASM(s32, "code_190B20", func_80263CC4);

INCLUDE_ASM(s32, "code_190B20", set_animation);

INCLUDE_ASM(s32, "code_190B20", func_80263E08);

INCLUDE_ASM(s32, "code_190B20", set_animation_rate);

void set_actor_yaw(s32 actorId, s32 yaw) {
    get_actor(actorId)->yaw = yaw;
}

void set_part_yaw(s32 actorID, s32 partIndex, s32 value) {
    get_actor_part(get_actor(actorID), partIndex)->yaw = value;
}

INCLUDE_ASM(s32, "code_190B20", func_80263FE8);

INCLUDE_ASM(s32, "code_190B20", func_80264084);

INCLUDE_ASM(s32, "code_190B20", add_xz_vec3f);

INCLUDE_ASM(s32, "code_190B20", add_xz_vec3f_copy1);

INCLUDE_ASM(s32, "code_190B20", add_xz_vec3f_copy2);

INCLUDE_ASM(s32, "code_190B20", play_movement_dust_effects);

ActorPart* get_actor_part(Actor* actor, s32 partIndex) {
    ActorPart* part = &actor->partsTable[0];

    if (partIndex < 0 || part->nextPart == NULL) {
        return part;
    }

    while (part != NULL) {
        if (part->staticData->index == partIndex) {
            return part;
        }
        part = part->nextPart;
    }

    return NULL;
}

INCLUDE_ASM(s32, "code_190B20", load_player_actor);

INCLUDE_ASM(s32, "code_190B20", load_partner_actor);

INCLUDE_ASM(s32, "code_190B20", create_actor);

INCLUDE_ASM(s32, "code_190B20", func_80265CE8);

INCLUDE_ASM(s32, "code_190B20", func_80265D44);

#ifdef NON_MATCHING
typedef struct {
    Element element;
    s32 defense;
} DefenseTableEntry;

s32 lookup_defense(DefenseTableEntry* defenseTable, Element elementKey) {
    DefenseTableEntry* row;
    s32 normalDefense = 0;

    for (row = defenseTable; row->element != Element_END; row++) {
        if (row->element == Element_NORMAL) {
            normalDefense = row->defense;
        }

        if (row->element == elementKey) {
            return row->defense;
        }
    }

    // Fall back to normal defense if given element is not specified in table
    return normalDefense;
}
#else
INCLUDE_ASM(s32, "code_190B20", lookup_defense);
#endif

INCLUDE_ASM(s32, "code_190B20", lookup_status_chance); // exactly (?) the same as lookup_defense

INCLUDE_ASM(s32, "code_190B20", lookup_status_duration_mod); // exactly (?) the same as lookup_defense

INCLUDE_ASM(s32, "code_190B20", inflict_status);

s32 inflict_partner_ko(Actor* target, s32 statusTypeKey, s32 duration) {
    if (statusTypeKey == Status_DAZE) {
        if (statusTypeKey != target->koStatus) {
            inflict_status(target, Status_DAZE);
            play_sound(0x2107);
        } else {
            target->koDuration += duration;
            if (target->koDuration > 9) {
                target->koDuration = 9;
            }
        }
    }

    return TRUE;
}

s32 get_defense(Actor* actor, s32* defenseTable, s32 elementFlags) {
    s32 defense;
    s32 minDefense = 0xFF;

    if (defenseTable != NULL) {
        if (elementFlags & 2) {
            defense = lookup_defense(defenseTable, Element_FIRE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 4) {
            defense = lookup_defense(defenseTable, Element_WATER);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 8) {
            defense = lookup_defense(defenseTable, Element_ICE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        // Element_MYSTERY missing?
        if (elementFlags & 0x10) {
            defense = lookup_defense(defenseTable, Element_MAGIC);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x40) {
            defense = lookup_defense(defenseTable, Element_HAMMER);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x80) {
            defense = lookup_defense(defenseTable, Element_JUMP);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x100) {
            defense = lookup_defense(defenseTable, Element_COSMIC);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x200) {
            defense = lookup_defense(defenseTable, Element_BLAST);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x20) {
            defense = lookup_defense(defenseTable, Element_SHOCK);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x800) {
            defense = lookup_defense(defenseTable, Element_QUAKE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x40000) {
            defense = lookup_defense(defenseTable, Element_THROW);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
    }

    // If no element flags were set, fall back to normal defense.
    if (minDefense == 0xFF) {
        defense = lookup_defense(defenseTable, Element_NORMAL);
        if (defense < 0xFF) {
            minDefense = defense;
        }
    }

    if (elementFlags & 0x8000000) { // "ignore defense" flag
        if (minDefense == 99) {
            // Immune
            minDefense = 999;
        } else if (minDefense > 0) {
            minDefense = 0;
        }
    }

    return minDefense;
}

INCLUDE_ASM(s32, "code_190B20", func_802664DC);

INCLUDE_ASM(s32, "code_190B20", show_damage_popup);

INCLUDE_ASM(s32, "code_190B20", func_80266684);

INCLUDE_ASM(s32, "code_190B20", func_802666E4);

INCLUDE_ASM(s32, "code_190B20", func_802667F0);

INCLUDE_ASM(s32, "code_190B20", func_80266970);

INCLUDE_ASM(s32, "code_190B20", func_80266978);

INCLUDE_ASM(s32, "code_190B20", func_80266ADC);

INCLUDE_ASM(s32, "code_190B20", func_80266AF8);

INCLUDE_ASM(s32, "code_190B20", func_80266B14);

INCLUDE_ASM(s32, "code_190B20", try_inflict_status);

INCLUDE_ASM(s32, "code_190B20", inflict_status_set_duration);

INCLUDE_ASM(s32, "code_190B20", func_80266D6C);

INCLUDE_ASM(s32, "code_190B20", func_80266DAC);

INCLUDE_ASM(s32, "code_190B20", func_80266E14);

INCLUDE_ASM(s32, "code_190B20", func_80266E40);

INCLUDE_ASM(s32, "code_190B20", func_80266EA8);

INCLUDE_ASM(s32, "code_190B20", func_80266EE8);

INCLUDE_ASM(s32, "code_190B20", func_80266F60);

INCLUDE_ASM(s32, "code_190B20", func_80266F8C);

INCLUDE_ASM(s32, "code_190B20", func_80266FD8);

INCLUDE_ASM(s32, "code_190B20", func_80267018);

INCLUDE_ASM(s32, "code_190B20", func_8026709C);

INCLUDE_ASM(s32, "code_190B20", func_802670C8);

#ifdef NON_MATCHING
// Register allocation issues (decorationIndex is placed in s2 for seemingly no reason?).
// Should be easy to clean up once DecorationTable is more understood
void add_part_decoration(ActorPart* part, s32 decorationIndex, DecorationId decorationType) {
    if (part->idleAnimations && (part->flags & 2) == 0) {
        DecorationTable* decoration = &part->decorationTable->unk_00[decorationIndex];
        _remove_part_decoration(part, decorationIndex);
        decoration->decorationType[0] = decorationType;
        decoration->unk_8BA = 1;
        decoration->unk_8BC = 0;
        func_8025CEC8(part);
    }
}
#else
INCLUDE_ASM(void, "code_190B20", add_part_decoration, ActorPart* part, s32 decorationIndex,
            DecorationId decorationType);
#endif

void add_actor_decoration(Actor* actor, s32 decorationIndex, DecorationId decorationType) {
    ActorPart* part;
    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if ((part->flags & 0x100001) == 0 && part->idleAnimations && (part->flags & 2) == 0) {
            add_part_decoration(part, decorationIndex, decorationType);
        }
    }
}

void remove_part_decoration(ActorPart* part, s32 decorationIndex) {
    _remove_part_decoration(part, decorationIndex);
}

void remove_actor_decoration(Actor* actor, s32 decorationIndex) {
    ActorPart* part;
    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if ((part->flags & 0x100001) == 0 && part->idleAnimations && (part->flags & 2) == 0) {
            remove_part_decoration(part, decorationIndex);
        }
    }
}

s32 heroes_is_ability_active(Actor* actor, Ability ability) {
    s32 actorGenus = actor->actorID & 0x700;
    s32 hasAbility = FALSE;

    if (actorGenus != 0x100) {
        // Separate ifs required to match
        if (actorGenus <= 0x100) {
            if (actorGenus == 0 && (gBattleStatus.flags2 & 0x40) == 0) {
                hasAbility = is_ability_active(ability);
            }
        }
    } else {
        hasAbility = is_partner_ability_active(ability);
    }

    return hasAbility;
}

void create_part_shadow(s32 actorId, s32 partIndex) {
    ActorPart* part = get_actor_part(get_actor(actorId), partIndex);

    part->flags &= ~4;
    part->shadow = create_shadow_type(0, part->currentPos.x, part->currentPos.y, part->currentPos.z);
    part->shadowScale = part->size[0] / 24.0;
}

void remove_part_shadow(s32 actorId, s32 partIndex) {
    ActorPart* part = get_actor_part(get_actor(actorId), partIndex);

    part->flags |= 4;
    func_80112328(part->shadow);
}

void create_part_shadow_by_ptr(UNK_TYPE arg0, ActorPart* part) {
    part->flags &= ~4;
    part->shadow = create_shadow_type(0, part->currentPos.x, part->currentPos.y, part->currentPos.z);
    part->shadowScale = part->size[0] / 24.0;
}

void func_80071A50(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);
void func_80071C30(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);

void remove_player_buffs(PlayerBuff buffs) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    ActorPart* playerPartsTable = player->partsTable;

    if (buffs & 1) {
        battleStatus->jumpCharge = 0;
        battleStatus->flags1 &= ~0x20000000;
    }
    if (buffs & 2) {
        battleStatus->hammerCharge = 0;
        battleStatus->flags1 &= ~0x10000000;
    }
    if (buffs & 8) {
        player->stoneDuration = 0;
        player->stoneStatus = 0;
    }
    if (buffs & 0x10) {
        battleStatus->hustleTurns = 0;
        battleStatus->flags1 &= ~0x04000000;
    }
    if ((buffs & 0x20) && (player->staticStatus != 0)) {
        player->staticDuration = 0;
        player->staticStatus = 0;
        func_800479A0(player->unk_436);
    }
    if ((buffs & 0x40) && (player->transStatus != 0)) {
        player->transDuration = 0;
        player->transStatus = 0;
        playerPartsTable->flags &= ~0x100;
        func_80047AA8(player->unk_436);
    }
    if ((buffs & 0x200) && (battleStatus->waterBlockTurnsLeft != 0)) {
        battleStatus->waterBlockTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_10 = 0;
        battleStatus->unk_A0[0] |= 0x10;

        func_80071A50(1, player->currentPos.x, player->currentPos.y + 18.0f, player->currentPos.z + 5.0f, 1.5f, 0xA);
        func_80071C30(0, player->currentPos.x - 10.0f, player->currentPos.y + 5.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
        func_80071C30(0, player->currentPos.x - 15.0f, player->currentPos.y + 32.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
        func_80071C30(1, player->currentPos.x + 15.0f, player->currentPos.y + 22.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);

        battleStatus->unk_A0 = NULL;
        play_sound(0x299);
    }
    if ((buffs & 0x100) && (battleStatus->turboChargeTurnsLeft != 0)) {
        battleStatus->turboChargeTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_24 = 0;
    }
    if ((buffs & 0x80) && (battleStatus->cloudNineTurnsLeft != 0)) {
        battleStatus->cloudNineTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_1A = 0;
        remove_effect(battleStatus->cloudNineEffect);
        battleStatus->cloudNineEffect = 0;
    }

    if ((partner != NULL) && (buffs & 0x10000)) {
        BattleStatus* bs = &gBattleStatus;

        partner->isGlowing = FALSE;
        bs->flags1 &= ~0x40000000;
    }
}

INCLUDE_ASM(s32, "code_190B20", func_8026777C);

INCLUDE_ASM(s32, "code_190B20", func_8026787C);

INCLUDE_ASM(s32, "code_190B20", func_80267A3C);

INCLUDE_ASM(s32, "code_190B20", reset_all_actor_sounds);

void hide_foreground_models_unsafe(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= 2;
            }
        }
    }
}

void show_foreground_models_unsafe(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~2;
            }
        }
    }
}

void hide_foreground_models(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id < 0) {
                break;
            } else {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= 2;
            }

        }
    }
}

void show_foreground_models(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id < 0) {
                break;
            } else {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~2;
            }
        }
    }
}

ApiStatus StartRumbleWithParams(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    start_rumble(get_variable(script, *args++), get_variable(script, *args++));

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_190B20", start_rumble_type);

