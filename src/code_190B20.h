#ifndef _CODE_190B20_H_
#define _CODE_190B20_H_

#include "common.h"
#include "code_a5dd0_len_114e0.h"

void player_create_target_list(Actor* actor);
void enemy_create_target_list(Actor* actor);

void set_actor_yaw(ActorID actorID, s32 yaw);
void set_part_yaw(ActorID actorID, s32 partIndex, s32 value);

ActorPart* get_actor_part(Actor* actor, s32 partIndex);

void add_part_decoration(ActorPart* part, s32 decorationIndex, DecorationId decorationType);
void add_actor_decoration(Actor* actor, s32 decorationIndex, DecorationId decorationType);
void remove_part_decoration(ActorPart* part, s32 decorationIndex);
void remove_actor_decoration(Actor* actor, s32 decorationIndex);

s32 heroes_is_ability_active(Actor* actor, Ability ability);

void create_part_shadow(ActorID actorID, s32 partIndex);
void remove_part_shadow(ActorID actorID, s32 partIndex);
void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part); // arg0 unused

#endif
