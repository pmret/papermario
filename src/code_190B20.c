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

INCLUDE_ASM(s32, "code_190B20", lookup_defense);

INCLUDE_ASM(s32, "code_190B20", lookup_status_chance);

INCLUDE_ASM(s32, "code_190B20", lookup_status_duration_mod);

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

INCLUDE_ASM(s32, "code_190B20", add_part_decoration);

INCLUDE_ASM(s32, "code_190B20", add_actor_decoration);

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

void create_part_shadow_by_ptr(UNK_TYPE unused, ActorPart* part) {
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
