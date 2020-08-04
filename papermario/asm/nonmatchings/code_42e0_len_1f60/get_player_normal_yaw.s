.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_player_normal_yaw
/* 005220 80029E20 44806000 */  mtc1  $zero, $f12
/* 005224 80029E24 3C028007 */  lui   $v0, 0x8007
/* 005228 80029E28 8C42419C */  lw    $v0, 0x419c($v0)
/* 00522C 80029E2C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 005230 80029E30 AFBF0010 */  sw    $ra, 0x10($sp)
/* 005234 80029E34 8C460128 */  lw    $a2, 0x128($v0)
/* 005238 80029E38 8C470130 */  lw    $a3, 0x130($v0)
/* 00523C 80029E3C 0C00A720 */  jal   atan2
/* 005240 80029E40 46006386 */   mov.s $f14, $f12
/* 005244 80029E44 8FBF0010 */  lw    $ra, 0x10($sp)
/* 005248 80029E48 03E00008 */  jr    $ra
/* 00524C 80029E4C 27BD0018 */   addiu $sp, $sp, 0x18

