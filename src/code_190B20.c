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

INCLUDE_ASM(ActorPart*, "code_190B20", get_actor_part, Actor* actor, s32 partIndex);

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

INCLUDE_ASM(s32, "code_190B20", inflict_partner_ko);

INCLUDE_ASM(s32, "code_190B20", get_defense);

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

INCLUDE_ASM(s32, "code_190B20", remove_player_buffs);

INCLUDE_ASM(s32, "code_190B20", func_8026777C);

INCLUDE_ASM(s32, "code_190B20", func_8026787C);

INCLUDE_ASM(s32, "code_190B20", func_80267A3C);

INCLUDE_ASM(s32, "code_190B20", reset_all_actor_sounds);

INCLUDE_ASM(s32, "code_190B20", hide_foreground_models_unchecked);

INCLUDE_ASM(s32, "code_190B20", show_foreground_models_unchecked);

INCLUDE_ASM(s32, "code_190B20", hide_foreground_models);

INCLUDE_ASM(s32, "code_190B20", show_foreground_models);

INCLUDE_ASM(s32, "code_190B20", StartRumbleWithParams);

INCLUDE_ASM(s32, "code_190B20", start_rumble_type);

