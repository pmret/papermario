#ifndef _TUTANKOOPA_COMMON_H_
#define _TUTANKOOPA_COMMON_H_

enum N(BattleCommon) {
    ACTOR_TUTANKOOPA    = ACTOR_ENEMY0,
    ACTOR_CHOMP         = ACTOR_ENEMY1,
    AVAR_Tutankoopa_Stunned         = 8,  // actor var for Tutankoopa
    AVAR_Tutankoopa_NextSummonTime  = 12, // actor var for Tutankoopa to signal chomp has died
};

#endif // _TUTANKOOPA_COMMON_H_
