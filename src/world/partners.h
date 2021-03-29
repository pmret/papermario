#ifndef _WORLD_PARTNERS_H
#define _WORLD_PARTNERS_H

#include "common.h"

typedef void (*PartnerFunc)(Npc* partner);
typedef s32 (*PartnerBoolFunc)(Npc* partner);
typedef s32 (*PartnerUnkFunc)(Npc* partner, s32 arg1);

typedef struct WorldPartner {
    /* 0x00 */ void* dmaStart;
    /* 0x04 */ void* dmaEnd;
    /* 0x08 */ void* dmaDest; ///< Always `0x802BD100`
    /* 0x0C */ s32 isFlying;
    /* 0x10 */ PartnerFunc init;
    /* 0x14 */ Bytecode* takeOut;
    /* 0x18 */ Bytecode* update;
    /* 0x1C */ Bytecode* useAbility;
    /* 0x20 */ Bytecode* putAway;
    /* 0x24 */ NpcAnimID idle;
    /* 0x28 */ PartnerUnkFunc testFirstStrike;
    /* 0x2C */ PartnerBoolFunc canUseAbility;
    /* 0x30 */ PartnerBoolFunc canPlayerPause;
    /* 0x34 */ PartnerFunc preBattle;
    /* 0x38 */ PartnerFunc postBattle;
    /* 0x3C */ Bytecode* whileRiding;
} WorldPartner; // size = 0x40

extern s32 D_8010C954;
extern s32 D_8010CFC4;
extern ScriptInstance* D_8010CFD4;
extern s32 D_8010CFD8;
extern ScriptID D_8010CFDC;
extern s32 D_8010CFE0;
extern s32 D_8010CFE4;
extern s32 D_8010CFE8;

extern WorldPartner wPartners[12];
extern WorldPartner* wPartner;
extern NpcID D_8010CFD0; // wPartnerNpcIndex
extern Npc* wPartnerNpc; // wPartnerNpc

#endif
