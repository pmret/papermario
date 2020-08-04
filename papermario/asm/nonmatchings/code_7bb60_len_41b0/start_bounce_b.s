.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel start_bounce_b
/* 07F53C 800E608C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07F540 800E6090 AFBF0010 */  sw    $ra, 0x10($sp)
/* 07F544 800E6094 0C039769 */  jal   set_action_state
/* 07F548 800E6098 24040004 */   addiu $a0, $zero, 4
/* 07F54C 800E609C 3C048011 */  lui   $a0, 0x8011
/* 07F550 800E60A0 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 07F554 800E60A4 3C014100 */  lui   $at, 0x4100
/* 07F558 800E60A8 44810000 */  mtc1  $at, $f0
/* 07F55C 800E60AC 3C01BF80 */  lui   $at, 0xbf80
/* 07F560 800E60B0 44811000 */  mtc1  $at, $f2
/* 07F564 800E60B4 8C820000 */  lw    $v0, ($a0)
/* 07F568 800E60B8 3C030080 */  lui   $v1, 0x80
/* 07F56C 800E60BC AC800078 */  sw    $zero, 0x78($a0)
/* 07F570 800E60C0 AC80007C */  sw    $zero, 0x7c($a0)
/* 07F574 800E60C4 00431025 */  or    $v0, $v0, $v1
/* 07F578 800E60C8 E4800070 */  swc1  $f0, 0x70($a0)
/* 07F57C 800E60CC E4820074 */  swc1  $f2, 0x74($a0)
/* 07F580 800E60D0 AC820000 */  sw    $v0, ($a0)
/* 07F584 800E60D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07F588 800E60D8 03E00008 */  jr    $ra
/* 07F58C 800E60DC 27BD0018 */   addiu $sp, $sp, 0x18

