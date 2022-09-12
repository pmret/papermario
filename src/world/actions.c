#include "common.h"
#include "ld_addrs.h"
#include "actions.h"

void action_update_idle(void);
void action_update_walk(void);
void action_update_run(void);
void action_update_land(void);
void action_update_jump(void);
void action_update_landing_on_switch(void);
void action_update_falling(void);
void action_update_step_down(void);
void action_update_step_down_land(void);
void action_update_spin_jump(void);
void action_update_tornado_jump(void);
void action_update_talk(void);
void action_update_sliding(void);
void action_update_hammer(void);
void action_update_launch(void);
void action_update_pushing_block(void);
void action_update_hit_fire(void);
void action_update_knockback(void);
void action_update_hit_lava(void);
void action_update_parasol(void);
void action_update_spin(void);
void action_update_step_up_peach(void);
void action_update_ride(void);
void action_update_step_up(void);
void action_update_first_strike(void);
void action_update_raise_arms(void);
void action_update_use_spinning_flower(void);
void action_update_use_munchlesia(void);
void action_update_use_tweester(void);
void action_update_state_23(void);

s32 PrevPlayerCamRelativeYaw = 0;
s32 D_800F7B44 = 0;
f32 D_800F7B48 = 0.0f;
s32 D_800F7B4C = 0;

f32 GravityParamsStartJump[] = { 15.7566404343f, -7.38624f, 3.44693994522f, -0.75f };
f32 GravityParamsStartFall[] = { 0.154342994094f, -0.350080013275f, -0.182262003422f, 0.0115200001746f };

 // default move speeds
f32 D_800F7B70 = 2.0f; // walk
f32 D_800F7B74 = 4.0f; // run
f32 D_800F7B78 = 32.0f; // max jump
f32 D_800F7B7C = -32.0f; // ???

s16 FootstepSoundSelector = 0;
s32 D_800F7B84[] = { 0, 0, 0};
f32 D_800F7B90 = 0.0;

AnimID ClubbaDisguiseExtraAnims[] = { 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390008, 0x00390007, 0x00390013, 0x00390014, ANIM_LIST_END };

AnimID HammerBroDisguiseExtraAnims[] = { 0x005A0000, 0x005A0002, 0x005A0003, 0x005A0004, 0x005A0006, 0x005A0007, 0x005A0009, 0x005A000A, 0x005A000B, 0x005A001A, ANIM_LIST_END };

AnimID KoopatrolDisguiseExtraAnims[] = { 0x00580000, 0x00580001, 0x00580002, 0x00580004, 0x00580005, 0x00580006, 0x00580007, 0x00580008, 0x00580009, 0x00580012, 0x00580014, 0x0058001B, ANIM_LIST_END };

DisguiseAnims BasicPeachDisguiseAnims[4] = {
    {0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000, 0x0058001B},
    {0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000, 0x0058001B},
    {0x005A0003, 0x005A0006, 0x005A0009, 0x005A000B, 0x005A0000, 0x005A001A},
    {0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390000, 0x00390014},
};

AnimID* PeachDisguiseExtraAnims[4] = { KoopatrolDisguiseExtraAnims, KoopatrolDisguiseExtraAnims, HammerBroDisguiseExtraAnims, ClubbaDisguiseExtraAnims };

#define ACTION_FILE(name) world_action_##name##_ROM_START, world_action_##name##_ROM_END

Action PlayerActionsTable[] = {
    [ACTION_STATE_IDLE]                 { action_update_idle, ACTION_FILE(idle), TRUE },
    [ACTION_STATE_WALK]                 { action_update_walk, ACTION_FILE(walk), TRUE },
    [ACTION_STATE_RUN]                  { action_update_run, ACTION_FILE(walk), TRUE },
    [ACTION_STATE_JUMP]                 { action_update_jump, ACTION_FILE(jump), TRUE },
    [ACTION_STATE_BOUNCE]               { action_update_jump, ACTION_FILE(jump), TRUE },
    [ACTION_STATE_HOP]                  { action_update_jump, ACTION_FILE(jump), FALSE },
    [ACTION_STATE_LAUNCH]               { action_update_jump, ACTION_FILE(jump), FALSE },
    [ACTION_STATE_LANDING_ON_SWITCH]    { action_update_landing_on_switch, ACTION_FILE(jump), FALSE },
    [ACTION_STATE_FALLING]              { action_update_falling, ACTION_FILE(jump), TRUE },
    [ACTION_STATE_STEP_DOWN]            { action_update_step_down, ACTION_FILE(jump), TRUE },
    [ACTION_STATE_LAND]                 { action_update_land, ACTION_FILE(land), TRUE },
    [ACTION_STATE_STEP_DOWN_LAND]       { action_update_step_down_land, ACTION_FILE(land), TRUE },
    [ACTION_STATE_TALK]                 { action_update_talk, ACTION_FILE(misc), TRUE },
    [ACTION_STATE_SPIN_JUMP]            { action_update_spin_jump, ACTION_FILE(spin_jump), FALSE },
    [ACTION_STATE_SPIN_POUND]           { action_update_spin_jump, ACTION_FILE(spin_jump), FALSE },
    [ACTION_STATE_TORNADO_JUMP]         { action_update_tornado_jump, ACTION_FILE(tornado_jump), FALSE },
    [ACTION_STATE_TORNADO_POUND]        { action_update_tornado_jump, ACTION_FILE(tornado_jump), FALSE },
    [ACTION_STATE_SLIDING]              { action_update_sliding, ACTION_FILE(slide), FALSE },
    [ACTION_STATE_HAMMER]               { action_update_hammer, ACTION_FILE(hammer), FALSE },
    [ACTION_STATE_13]                   { action_update_launch, ACTION_FILE(misc), TRUE },
    [ACTION_STATE_PUSHING_BLOCK]        { action_update_pushing_block, ACTION_FILE(misc), FALSE },
    [ACTION_STATE_HIT_FIRE]             { action_update_hit_fire, ACTION_FILE(hit_fire), FALSE },
    [ACTION_STATE_KNOCKBACK]            { action_update_knockback, ACTION_FILE(knockback), FALSE },
    [ACTION_STATE_HIT_LAVA]             { action_update_hit_lava, ACTION_FILE(hit_lava), FALSE },
    [ACTION_STATE_STEP_UP_PEACH]        { action_update_step_up_peach, ACTION_FILE(step_up), TRUE },
    [ACTION_STATE_USE_SNEAKY_PARASOL]   { action_update_parasol, ACTION_FILE(sneaky_parasol), TRUE },
    [ACTION_STATE_SPIN]                 { action_update_spin, ACTION_FILE(spin), FALSE },
    [ACTION_STATE_ENEMY_FIRST_STRIKE]   { action_update_first_strike, ACTION_FILE(misc), FALSE },
    [ACTION_STATE_RAISE_ARMS]           { action_update_raise_arms, ACTION_FILE(misc), FALSE },
    [ACTION_STATE_USE_SPINNING_FLOWER]  { action_update_use_spinning_flower, ACTION_FILE(use_spinning_flower), FALSE },
    [ACTION_STATE_USE_MUNCHLESIA]       { action_update_use_munchlesia, ACTION_FILE(use_munchlesia), FALSE },
    [ACTION_STATE_USE_TWEESTER]         { action_update_use_tweester, ACTION_FILE(use_tweester), FALSE },
    [ACTION_STATE_BOUNCE_OFF_SWITCH]    { action_update_launch, ACTION_FILE(misc), TRUE },
    [ACTION_STATE_RIDE]                 { action_update_ride, ACTION_FILE(misc), FALSE },
    [ACTION_STATE_STEP_UP]              { action_update_step_up, ACTION_FILE(step_up), TRUE },
    [ACTION_STATE_23]                   { action_update_state_23, ACTION_FILE(misc), FALSE },
    [ACTION_STATE_24]                   { action_update_launch, ACTION_FILE(misc), FALSE },
    //@bug function does not exist in world_action_walk, causes jump to middle of action_update_run and crashes
    [ACTION_STATE_INVALID_25]           { action_update_launch, ACTION_FILE(walk), FALSE },
    [ACTION_STATE_USE_SPRING]           { action_update_launch, ACTION_FILE(misc), TRUE },
};
