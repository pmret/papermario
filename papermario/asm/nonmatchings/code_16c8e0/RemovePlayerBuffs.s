.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemovePlayerBuffs
/* 19DD2C 8026F44C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19DD30 8026F450 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19DD34 8026F454 8C82000C */  lw    $v0, 0xc($a0)
/* 19DD38 8026F458 0C099D15 */  jal   remove_player_buffs
/* 19DD3C 8026F45C 8C440000 */   lw    $a0, ($v0)
/* 19DD40 8026F460 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19DD44 8026F464 24020002 */  addiu $v0, $zero, 2
/* 19DD48 8026F468 03E00008 */  jr    $ra
/* 19DD4C 8026F46C 27BD0018 */   addiu $sp, $sp, 0x18

