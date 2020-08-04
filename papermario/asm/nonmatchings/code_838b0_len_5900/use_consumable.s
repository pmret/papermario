.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel use_consumable
/* 0838B0 800EA400 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0838B4 800EA404 AFB10014 */  sw    $s1, 0x14($sp)
/* 0838B8 800EA408 0080882D */  daddu $s1, $a0, $zero
/* 0838BC 800EA40C AFB00010 */  sw    $s0, 0x10($sp)
/* 0838C0 800EA410 3C108010 */  lui   $s0, 0x8010
/* 0838C4 800EA414 26108010 */  addiu $s0, $s0, -0x7ff0
/* 0838C8 800EA418 3C06802C */  lui   $a2, 0x802c
/* 0838CC 800EA41C 24C60000 */  addiu $a2, $a2, 0
/* 0838D0 800EA420 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0838D4 800EA424 8E040000 */  lw    $a0, ($s0)
/* 0838D8 800EA428 8E050004 */  lw    $a1, 4($s0)
/* 0838DC 800EA42C 00111040 */  sll   $v0, $s1, 1
/* 0838E0 800EA430 3C018011 */  lui   $at, 0x8011
/* 0838E4 800EA434 AC31CD20 */  sw    $s1, -0x32e0($at)
/* 0838E8 800EA438 3C118011 */  lui   $s1, 0x8011
/* 0838EC 800EA43C 02228821 */  addu  $s1, $s1, $v0
/* 0838F0 800EA440 8631F444 */  lh    $s1, -0xbbc($s1)
/* 0838F4 800EA444 0C00A5CF */  jal   dma_copy
/* 0838F8 800EA448 00000000 */   nop   
/* 0838FC 800EA44C 24050001 */  addiu $a1, $zero, 1
/* 083900 800EA450 8E040008 */  lw    $a0, 8($s0)
/* 083904 800EA454 0C0B0CF8 */  jal   start_script
/* 083908 800EA458 0000302D */   daddu $a2, $zero, $zero
/* 08390C 800EA45C 0040182D */  daddu $v1, $v0, $zero
/* 083910 800EA460 8C620144 */  lw    $v0, 0x144($v1)
/* 083914 800EA464 AC7100AC */  sw    $s1, 0xac($v1)
/* 083918 800EA468 8FBF0018 */  lw    $ra, 0x18($sp)
/* 08391C 800EA46C 8FB10014 */  lw    $s1, 0x14($sp)
/* 083920 800EA470 8FB00010 */  lw    $s0, 0x10($sp)
/* 083924 800EA474 03E00008 */  jr    $ra
/* 083928 800EA478 27BD0020 */   addiu $sp, $sp, 0x20

