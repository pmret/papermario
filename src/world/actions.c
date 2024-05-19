#include "common.h"
#include "ld_addrs.h"
#include "actions.h"

#include "sprite/npc/WorldClubba.h"
#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/HammerBros.h"

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

#if VERSION_JP // TODO remove once segments are split
extern Addr world_action_idle_ROM_START;
extern Addr world_action_idle_ROM_END;
extern Addr world_action_walk_ROM_START;
extern Addr world_action_walk_ROM_END;
extern Addr world_action_jump_ROM_START;
extern Addr world_action_jump_ROM_END;
extern Addr world_action_land_ROM_START;
extern Addr world_action_land_ROM_END;
extern Addr world_action_misc_ROM_START;
extern Addr world_action_misc_ROM_END;
extern Addr world_action_spin_jump_ROM_START;
extern Addr world_action_spin_jump_ROM_END;
extern Addr world_action_tornado_jump_ROM_START;
extern Addr world_action_tornado_jump_ROM_END;
extern Addr world_action_slide_ROM_START;
extern Addr world_action_slide_ROM_END;
extern Addr world_action_hammer_ROM_START;
extern Addr world_action_hammer_ROM_END;
extern Addr world_action_hit_fire_ROM_START;
extern Addr world_action_hit_fire_ROM_END;
extern Addr world_action_knockback_ROM_START;
extern Addr world_action_knockback_ROM_END;
extern Addr world_action_hit_lava_ROM_START;
extern Addr world_action_hit_lava_ROM_END;
extern Addr world_action_step_up_ROM_START;
extern Addr world_action_step_up_ROM_END;
extern Addr world_action_sneaky_parasol_ROM_START;
extern Addr world_action_sneaky_parasol_ROM_END;
extern Addr world_action_spin_ROM_START;
extern Addr world_action_spin_ROM_END;
extern Addr world_action_use_spinning_flower_ROM_START;
extern Addr world_action_use_spinning_flower_ROM_END;
extern Addr world_action_use_munchlesia_ROM_START;
extern Addr world_action_use_munchlesia_ROM_END;
extern Addr world_action_use_tweester_ROM_START;
extern Addr world_action_use_tweester_ROM_END;
#endif

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
f32 LastMidairPlayerVelY = 0.0;

AnimID ClubbaDisguiseExtraAnims[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim05,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim13,
    ANIM_WorldClubba_Anim14,
    ANIM_LIST_END
};

AnimID HammerBroDisguiseExtraAnims[] = {
    ANIM_HammerBros_Anim00,
    ANIM_HammerBros_Anim02,
    ANIM_HammerBros_Anim03,
    ANIM_HammerBros_Anim04,
    ANIM_HammerBros_Anim06,
    ANIM_HammerBros_Anim07,
    ANIM_HammerBros_Anim09,
    ANIM_HammerBros_Anim0A,
    ANIM_HammerBros_Anim0B,
    ANIM_HammerBros_Anim1A,
    ANIM_LIST_END
};

AnimID KoopatrolDisguiseExtraAnims[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim02,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim05,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim07,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim09,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_WorldKoopatrol_Anim1B,
    ANIM_LIST_END
};

DisguiseAnims BasicPeachDisguiseAnims[] = {
    [PEACH_DISGUISE_NONE] {
        ANIM_WorldKoopatrol_Anim01,
        ANIM_WorldKoopatrol_Anim04,
        ANIM_WorldKoopatrol_Anim06,
        ANIM_WorldKoopatrol_Anim08,
        ANIM_WorldKoopatrol_Anim00,
        ANIM_WorldKoopatrol_Anim1B
    },
    [PEACH_DISGUISE_KOOPATROL] {
        ANIM_WorldKoopatrol_Anim01,
        ANIM_WorldKoopatrol_Anim04,
        ANIM_WorldKoopatrol_Anim06,
        ANIM_WorldKoopatrol_Anim08,
        ANIM_WorldKoopatrol_Anim00,
        ANIM_WorldKoopatrol_Anim1B
    },
    [PEACH_DISGUISE_HAMMER_BROS] {
        ANIM_HammerBros_Anim03,
        ANIM_HammerBros_Anim06,
        ANIM_HammerBros_Anim09,
        ANIM_HammerBros_Anim0B,
        ANIM_HammerBros_Anim00,
        ANIM_HammerBros_Anim1A
    },
    [PEACH_DISGUISE_CLUBBA] {
        ANIM_WorldClubba_Anim02,
        ANIM_WorldClubba_Anim03,
        ANIM_WorldClubba_Anim04,
        ANIM_WorldClubba_Anim05,
        ANIM_WorldClubba_Anim00,
        ANIM_WorldClubba_Anim14
    },
};

AnimID* PeachDisguiseExtraAnims[] = {
    [PEACH_DISGUISE_NONE] KoopatrolDisguiseExtraAnims,
    [PEACH_DISGUISE_KOOPATROL] KoopatrolDisguiseExtraAnims,
    [PEACH_DISGUISE_HAMMER_BROS] HammerBroDisguiseExtraAnims,
    [PEACH_DISGUISE_CLUBBA] ClubbaDisguiseExtraAnims
};

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

extern UseItemStruct UseItemDmaArgs;

BSS s32 D_8010CD20;

s32 use_consumable(s32 invSlot) {
    Evt* script;

    D_8010CD20 = invSlot;
    invSlot = gPlayerData.invItems[invSlot];
    dma_copy(UseItemDmaArgs.dmaStart, UseItemDmaArgs.dmaEnd, world_use_item_VRAM);
    script = start_script(UseItemDmaArgs.main, EVT_PRIORITY_1, 0);
    script->varTable[10] = invSlot;
    return script->id;
}

void remove_consumable(void) {
    gPlayerData.invItems[D_8010CD20] = ITEM_NONE;
    sort_items();
}
