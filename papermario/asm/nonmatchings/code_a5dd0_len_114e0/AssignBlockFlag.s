.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AssignBlockFlag
/* 0A876C 8011206C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A8770 80112070 24020001 */  addiu $v0, $zero, 1
/* 0A8774 80112074 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A8778 80112078 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A877C 8011207C 14A2000A */  bne   $a1, $v0, .L801120A8
/* 0A8780 80112080 8C83000C */   lw    $v1, 0xc($a0)
/* 0A8784 80112084 0C0B1F6A */  jal   get_variable_index
/* 0A8788 80112088 8C650000 */   lw    $a1, ($v1)
/* 0A878C 8011208C 3C048015 */  lui   $a0, 0x8015
/* 0A8790 80112090 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A8794 80112094 0C04417A */  jal   get_entity_by_index
/* 0A8798 80112098 0040802D */   daddu $s0, $v0, $zero
/* 0A879C 8011209C 8C430040 */  lw    $v1, 0x40($v0)
/* 0A87A0 801120A0 24020002 */  addiu $v0, $zero, 2
/* 0A87A4 801120A4 A470000A */  sh    $s0, 0xa($v1)
.L801120A8:
/* 0A87A8 801120A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A87AC 801120AC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A87B0 801120B0 03E00008 */  jr    $ra
/* 0A87B4 801120B4 27BD0018 */   addiu $sp, $sp, 0x18

