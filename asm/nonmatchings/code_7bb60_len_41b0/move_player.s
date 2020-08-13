.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel move_player
/* 07BC28 800E2778 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07BC2C 800E277C 44861000 */  mtc1  $a2, $f2
/* 07BC30 800E2780 3C068011 */  lui   $a2, 0x8011
/* 07BC34 800E2784 24C6EFC8 */  addiu $a2, $a2, -0x1038
/* 07BC38 800E2788 AFBF0010 */  sw    $ra, 0x10($sp)
/* 07BC3C 800E278C 8CC20000 */  lw    $v0, ($a2)
/* 07BC40 800E2790 34424000 */  ori   $v0, $v0, 0x4000
/* 07BC44 800E2794 ACC20000 */  sw    $v0, ($a2)
/* 07BC48 800E2798 8CC20004 */  lw    $v0, 4($a2)
/* 07BC4C 800E279C 3C030040 */  lui   $v1, 0x40
/* 07BC50 800E27A0 ACC500A0 */  sw    $a1, 0xa0($a2)
/* 07BC54 800E27A4 A4C40012 */  sh    $a0, 0x12($a2)
/* 07BC58 800E27A8 00431024 */  and   $v0, $v0, $v1
/* 07BC5C 800E27AC 14400009 */  bnez  $v0, .L800E27D4
/* 07BC60 800E27B0 E4C20054 */   swc1  $f2, 0x54($a2)
/* 07BC64 800E27B4 C4C00058 */  lwc1  $f0, 0x58($a2)
/* 07BC68 800E27B8 4602003C */  c.lt.s $f0, $f2
/* 07BC6C 800E27BC 00000000 */  nop   
/* 07BC70 800E27C0 45000002 */  bc1f  .L800E27CC
/* 07BC74 800E27C4 24040001 */   addiu $a0, $zero, 1
/* 07BC78 800E27C8 24040002 */  addiu $a0, $zero, 2
.L800E27CC:
/* 07BC7C 800E27CC 0C039769 */  jal   set_action_state
/* 07BC80 800E27D0 00000000 */   nop   
.L800E27D4:
/* 07BC84 800E27D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07BC88 800E27D8 03E00008 */  jr    $ra
/* 07BC8C 800E27DC 27BD0018 */   addiu $sp, $sp, 0x18

