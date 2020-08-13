.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EA6A8
/* 083B58 800EA6A8 3C048011 */  lui   $a0, 0x8011
/* 083B5C 800EA6AC 8C84CFD0 */  lw    $a0, -0x3030($a0)
/* 083B60 800EA6B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 083B64 800EA6B4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 083B68 800EA6B8 0C00E228 */  jal   func_800388A0
/* 083B6C 800EA6BC 00000000 */   nop   
/* 083B70 800EA6C0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 083B74 800EA6C4 03E00008 */  jr    $ra
/* 083B78 800EA6C8 27BD0018 */   addiu $sp, $sp, 0x18

