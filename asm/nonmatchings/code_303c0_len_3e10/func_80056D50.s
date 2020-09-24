.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056D50
/* 32150 80056D50 3C028008 */  lui       $v0, 0x8008
/* 32154 80056D54 03E00008 */  jr        $ra
/* 32158 80056D58 84428E5A */   lh       $v0, -0x71a6($v0)
