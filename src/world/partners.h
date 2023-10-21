#ifndef _WORLD_PARTNERS_H
#define _WORLD_PARTNERS_H

typedef void (*PartnerFunc)(Npc* partner);
typedef s32 (*PartnerBoolFunc)(Npc* partner);
typedef s32 (*PartnerTesHitFunc)(Npc* partner, Npc* enemy);

typedef struct WorldPartner {
    /* 0x00 */ void* dmaStart;
    /* 0x04 */ void* dmaEnd;
    /* 0x08 */ void* dmaDest; ///< Always `0x802BD100`
    /* 0x0C */ s32 isFlying;
    /* 0x10 */ PartnerFunc init;
    /* 0x14 */ EvtScript* takeOut;
    /* 0x18 */ EvtScript* update;
    /* 0x1C */ EvtScript* useAbility;
    /* 0x20 */ EvtScript* putAway;
    /* 0x24 */ s32 idle;
    /* 0x28 */ PartnerTesHitFunc testFirstStrike;
    /* 0x2C */ PartnerBoolFunc canUseAbility;
    /* 0x30 */ PartnerBoolFunc canPlayerOpenMenus;
    /* 0x34 */ PartnerFunc preBattle;
    /* 0x38 */ PartnerFunc postBattle;
    /* 0x3C */ EvtScript* onEnterMap;
} WorldPartner; // size = 0x40

extern Npc* wPartnerNpc; // wPartnerNpc

s32 partner_init_get_out(Npc*);
s32 partner_get_out(Npc*);
s32 partner_init_put_away(Npc* partner);
s32 partner_put_away(Npc* partner);
s32 partner_can_use_ability(void);
s32 partner_use_ability(void);
void partner_do_player_collision(Npc* partner);
void partner_walking_follow_player(Npc* partner);
s32 func_800EA52C(s32);
s32 partner_force_player_flip_done(void);
void partner_suspend_ability_script(void);
void partner_resume_ability_script(void);
void partner_enable_input(void);

#endif
