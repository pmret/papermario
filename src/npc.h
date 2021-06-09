#ifndef _NPC_H_
#define _NPC_H_

#include "common.h"
#include "map.h" // TODO move npc-related structs here

/// The default Npc::onUpdate and Npc::onRender callback.
void npc_callback_no_op(void);

void npc_dyn_entity_draw_no_op(void);

void npc_mtx_ident_mirror_y(Matrix4f mtx);

void npc_list_clear(void);

/// Points the current NPC list to the world or battle lists depending on game state.
void npc_list_update_current(void);

/// Iterates over the NPC list, doing absolutely nothing.
/// Presumably did something once upon a time but got commented out.
void npc_iter_no_op(void);

s32 npc_create(NpcBlueprint* blueprint, NpcAnimID** animList, s32 skipLoadingAnims);

void npc_create_basic(NpcBlueprint* blueprint);

void npc_create_standard(NpcBlueprint* blueprint, NpcAnimID** animList);

void npc_create_partner(NpcBlueprint* blueprint);

void npc_free_by_index(s32 listIndex);

void npc_free(Npc* npc);

Npc* get_npc_by_index(s32 listIndex);

void npc_do_world_collision(Npc* npc);

void npc_do_other_npc_collision(Npc* npc);

/// @returns TRUE if a collision occurred
s32 npc_do_player_collision(Npc* npc);

void npc_do_gravity(Npc* npc);

s32 func_800397E8();

/// Updates all NPCs.
void npc_list_update(void);

s32 func_80039DA4();

void npc_appendGfx(Npc* npc);

/// Renders all NPCs.
void npc_list_render(void);

void npc_move_heading(Npc* npc, f32 speed, f32 yaw);

Npc* get_npc_unsafe(NpcID npcID);

/// @returns NULL if not found
Npc* get_npc_safe(NpcID npcID);

void enable_npc_shadow(Npc* npc);

void disable_npc_shadow(Npc* npc);

void update_npc_blur(Npc* npc);

void appendGfx_npc_blur(Npc* npc);

void func_8003B184(void);

void func_8003B198(void);

void func_8003B1A8(void);

void func_8003B1B0(void);

void set_npc_yaw(Npc* npc, f32 yaw);

void func_8003B3D0(Npc* npc, s32 arg1);

void func_8003B3F8(Npc* npc, s32 arg1);

void func_8003B420(Npc* npc);

s32 func_8003B44C();

s32 func_8003B464();

void func_8003B47C(Npc* npc, s32 arg1, s32 arg2);

void func_8003B500(Npc* npc, s32 arg1, s32 arg2);

s32 func_8003B5B4();

s32 func_8003B96C();

s32 func_8003BA60();

s32 func_8003BED8();

void func_8003C3D8(Npc* npc, s32 idx, s8 decorationType);

void func_8003C428(Npc* npc, s32 idx);

s32 npc_update_decorations(Npc* npc);

void func_8003C53C(Npc* npc, s32 idx);

void func_8003C61C(Npc* npc, s32 idx);

void func_8003C658(Npc* npc, s32 idx);

void func_8003C660(Npc* npc, s32 idx);

void func_8003C668(Npc* npc, s32 idx);

void func_8003C78C(Npc* npc, s32 idx);

void func_8003C7A8(Npc* npc, s32 idx);

void func_8003C8AC(Npc* npc, s32 idx);

void func_8003C8B4(Npc* npc, s32 idx);

void func_8003C984(Npc* npc, s32 idx);

void func_8003C9A8(Npc* npc, s32 idx);

void func_8003CB20(Npc* npc, s32 idx);

void func_8003CB44(Npc* npc, s32 idx);

void func_8003CC8C(Npc* npc, s32 idx);

void func_8003CCB0(Npc* npc, s32 idx);

void func_8003CFA0(void);

void func_8003CFA8(Npc* npc, s32 idx);

/// Finds the closest NPC to a given point within a radius. Ignores Y position.
///
/// NPCs with NPC_FLAG_PARTICLE set are ignored.
/// See also npc_find_near_simple(), which requires that NPC_FLAG_PARTICLE be set.
///
/// @param x        X position
/// @param y        Y position (unused)
/// @param z        Z position
/// @param radius   No NPCs further than this distance will be considered
///
/// @returns NULL if there are no NPCs within radius
Npc* npc_find_near(f32 x, f32 y, f32 z, f32 radius);

/// Finds the closest simple-hitbox NPC to a given point within a radius. Ignores Y position.
///
/// Only NPCs with NPC_FLAG_PARTICLE set are considered.
/// See also npc_find_near(), which requires that NPC_FLAG_PARTICLE be unset.
///
/// @param x        X position
/// @param y        Y position (unused)
/// @param z        Z position
/// @param radius   No NPCs further than this distance will be considered
///
/// @returns NULL if there are no NPCs within radius
Npc* npc_find_near_simple(f32 x, f32 y, f32 z, f32 radius);

//s32 func_8003D1D4();

s32 func_8003D2F8(Npc* npc);

void func_8003D3BC(Npc* npc);

void func_8003D624(Npc* npc, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_8003D660(Npc* npc, s32 arg1);

void func_8003D788(Npc* npc, s32 arg1);

void func_8003DA38(Npc* npc, s32 arg1);

s32 func_8003DC38();

s32 func_8003DFA0();

s32 func_8003E0D4();

s32 func_8003E1D0();

/// Duplicate of set_defeated().
void COPY_set_defeated(s32 mapID, s32 encounterID);

void func_8003E338(void);

void clear_encounter_status(void);

void func_8003E50C(void);

void func_8003E514(s8 arg0);

void update_counters(void);

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
s32 bind_enemy_ai(Enemy* enemy, Script* aiScriptBytecode);

/// Binds the specified auxillary script to the specified enemy
///
/// @param enemy               pointer to the enemy to bind the script to
/// @param auxScriptBytecode   pointer to the script to be bound.
s32 bind_enemy_aux(Enemy* enemy, Script* auxScriptBytecode);

/// Binds the specified interact script to the specified enemy
///
/// @param enemy                    pointer to the enemy to bind the script to
/// @param interactScriptBytecode   pointer to the script to be bound.
s32 bind_enemy_interact(Enemy* enemy, Script* interactScriptBytecode);

/// Binds the specified ai script to the npc matching the specified npcId
///
/// @param npcID           ID of the desired npc
/// @param npcAiBytecode   pointer to the script to be bound.
void bind_npc_ai(s32 npcID, Script* npcAiBytecode);

/// Binds the specified auxillary script to the npc matching the specified npcId
///
/// @param npcID           ID of the desired npc
/// @param npcAuxBytecode  pointer to the script to be bound.
void bind_npc_aux(s32 npcID, Script* npcAuxBytecode);

/// Binds the specified interact script to the npc matching the specified npcId
///
/// @param npcID                ID of the desired npc
/// @param npcInteractBytecode  pointer to the script to be bound.
void bind_npc_interact(s32 npcID, Script* npcInteractBytecode);

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
