#ifndef _NPC_H_
#define _NPC_H_

#include "common.h"
#include "map.h" // TODO move npc-related structs here

/// The default Npc::onUpdate and Npc::onRender callback.
void STUB_npc_callback(void);

void npc_dyn_entity_draw_no_op(void);

void mtx_ident_mirror_y(Matrix4f mtx);

void clear_npcs(void);

/// Points the current NPC list to the world or battle lists depending on game state.
void init_npc_list(void);

/// Iterates over the NPC list, doing absolutely nothing.
/// Presumably did something once upon a time but got commented out.
void npc_iter_no_op(void);

s32 _create_npc(NpcBlueprint* blueprint, NpcAnimID** animList, s32 skipLoadingAnims);

s32 _create_npc_basic(NpcBlueprint* blueprint);

void _create_npc_standard(NpcBlueprint* blueprint, NpcAnimID** animList);

void _create_npc_partner(NpcBlueprint* blueprint);

void free_npc_by_index(s32 listIndex);

void free_npc(Npc* npc);

Npc* get_npc_by_index(s32 listIndex);

void npc_do_world_collision(Npc* npc);

void npc_do_other_npc_collision(Npc* npc);

/// @returns TRUE if a collision occurred
s32 npc_do_player_collision(Npc* npc);

void npc_do_gravity(Npc* npc);

s32 func_800397E8(Npc* npc, f32 arg1);

/// Updates all NPCs.
void update_npcs(void);

f32 npc_get_render_yaw();

void appendGfx_npc(Npc* npc);

/// Renders all NPCs.
void render_npcs(void);

void npc_move_heading(Npc* npc, f32 speed, f32 yaw);

Npc* get_npc_unsafe(NpcID npcID);

/// @returns NULL if not found
Npc* get_npc_safe(NpcID npcID);

void enable_npc_shadow(Npc* npc);

void disable_npc_shadow(Npc* npc);

void update_npc_blur(Npc* npc);

void appendGfx_npc_blur(Npc* npc);

void npc_enable_collisions(void);

void npc_disable_collisions(void);

void func_8003B1A8(void);

void npc_reload_all(void);

void set_npc_yaw(Npc* npc, f32 yaw);

void npc_set_palswap_mode_A(Npc* npc, s32 arg1);

void npc_set_palswap_mode_B(Npc* npc, s32 arg1);

void func_8003B420(Npc* npc);

s32 npc_set_palswap_1();

s32 npc_set_palswap_2();

void npc_draw_with_palswap(Npc* npc, s32 arg1, s32 arg2);

void npc_draw_palswap_mode_0(Npc* npc, s32 arg1, s32 arg2);

s32 npc_draw_palswap_mode_1();

s32 npc_blend_palette_colors();

s32 npc_draw_palswap_mode_2();

s32 npc_draw_palswap_mode_4();

void npc_set_decoration(Npc* npc, s32 idx, s32 decorationType);

void npc_remove_decoration(Npc* npc, s32 idx);

s32 npc_update_decorations(Npc* npc);

void npc__remove_decoration(Npc* npc, s32 idx);

void npc_reset_current_decoration(Npc* npc, s32 idx);

void npc_update_decoration_none(Npc* npc, s32 idx);

void npc_remove_decoration_none(Npc* npc, s32 idx);

void npc_update_decoration_bowser_aura(Npc* npc, s32 idx);

void npc_remove_decoration_bowser_aura(Npc* npc, s32 idx);

void npc_update_decoration_sweat(Npc* npc, s32 idx);

void npc_remove_decoration_sweat(Npc* npc, s32 idx);

void npc_update_decoration_seeing_stars(Npc* npc, s32 idx);

void npc_remove_decoration_seeing_stars(Npc* npc, s32 idx);

void npc_update_decoration_glow_in_front(Npc* npc, s32 idx);

void npc_remove_decoration_glow_in_front(Npc* npc, s32 idx);

void npc_update_decoration_glow_behind(Npc* npc, s32 idx);

void npc_remove_decoration_glow_behind(Npc* npc, s32 idx);

void npc_update_decoration_charged(Npc* npc, s32 idx);

void npc_remove_decoration_charged(Npc* npc, s32 idx);

void npc__reset_current_decoration(Npc* npc, s32 idx);

/// Finds the closest NPC to a given point within a radius. Ignores Y position.
///
/// NPCs with NPC_FLAG_PARTICLE set are ignored.
/// See also npc_find_closest_simple(), which requires that NPC_FLAG_PARTICLE be set.
///
/// @param x        X position
/// @param y        Y position (unused)
/// @param z        Z position
/// @param radius   No NPCs further than this distance will be considered
///
/// @returns NULL if there are no NPCs within radius
Npc* npc_find_closest(f32 x, f32 y, f32 z, f32 radius);

/// Finds the closest simple-hitbox NPC to a given point within a radius. Ignores Y position.
///
/// Only NPCs with NPC_FLAG_PARTICLE set are considered.
/// See also npc_find_closest(), which requires that NPC_FLAG_PARTICLE be unset.
///
/// @param x        X position
/// @param y        Y position (unused)
/// @param z        Z position
/// @param radius   No NPCs further than this distance will be considered
///
/// @returns NULL if there are no NPCs within radius
Npc* npc_find_closest_simple(f32 x, f32 y, f32 z, f32 radius);

//s32 npc_find_standing_on_entity();

s32 npc_get_collider_below(Npc* npc);

void func_8003D3BC(Npc* npc);

void func_8003D624(Npc* npc, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_8003D660(Npc* npc, s32 arg1);

void func_8003D788(Npc* npc, s32 arg1);

void func_8003DA38(Npc* npc, s32 arg1);

s32 func_8003DC38();

void func_8003DFA0(Npc* npc);

s32 func_8003E0D4();

void func_8003E1D0(Npc* npc);

/// Duplicate of set_defeated().
void COPY_set_defeated(s32 mapID, s32 encounterID);

void init_encounter_status(void);

void clear_encounter_status(void);

void func_8003E50C(void);

void func_8003E514(s8 arg0);

void update_encounters(void);

void draw_encounter_ui(void);

void draw_first_strike_ui(void);

void npc_dyn_entity_draw_no_op(void);

void make_npcs(s8 flags, s8 mapID, s32* npcGroupList);

s32 kill_encounter(Enemy* enemy);

void kill_enemy(Enemy* enemy);

/// Binds the specified ai script to the specified enemy
///
/// @param enemy               pointer to the enemy to bind the script to
/// @param aiScriptBytecode    pointer to the script to be bound.
s32 bind_enemy_ai(Enemy* enemy, EvtSource* aiScriptBytecode);

/// Binds the specified auxillary script to the specified enemy
///
/// @param enemy               pointer to the enemy to bind the script to
/// @param auxScriptBytecode   pointer to the script to be bound.
s32 bind_enemy_aux(Enemy* enemy, EvtSource* auxScriptBytecode);

/// Binds the specified interact script to the specified enemy
///
/// @param enemy                    pointer to the enemy to bind the script to
/// @param interactScriptBytecode   pointer to the script to be bound.
s32 bind_enemy_interact(Enemy* enemy, EvtSource* interactScriptBytecode);

/// Binds the specified ai script to the npc matching the specified npcId
///
/// @param npcID           ID of the desired npc
/// @param npcAiBytecode   pointer to the script to be bound.
void bind_npc_ai(s32 npcID, EvtSource* npcAiBytecode);

/// Binds the specified auxillary script to the npc matching the specified npcId
///
/// @param npcID           ID of the desired npc
/// @param npcAuxBytecode  pointer to the script to be bound.
void bind_npc_aux(s32 npcID, EvtSource* npcAuxBytecode);

/// Binds the specified interact script to the npc matching the specified npcId
///
/// @param npcID                ID of the desired npc
/// @param npcInteractBytecode  pointer to the script to be bound.
void bind_npc_interact(s32 npcID, EvtSource* npcInteractBytecode);

/// Looks for an enemy matching the specified npcID.
///
/// @param npcID   ID of the npc bound to the desired enemy.
///
/// @returns pointer to Enemy struct, if one is found. If one is not found, a panic occurs.
Enemy* get_enemy(NpcID npcID);

/// Same as get_enemy(), with the exception of always returning a value if an enemy is not found.
///
/// @param npcID   ID of the npc bound to the desired enemy.
///
/// @returns pointer to Enemy struct, if one is found. Otherwise, NULL.
Enemy* get_enemy_safe(s32 npcID);

#endif
