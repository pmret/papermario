.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80110790
/* 0A6E90 80110790 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A6E94 80110794 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A6E98 80110798 0080802D */  daddu $s0, $a0, $zero
/* 0A6E9C 8011079C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0A6EA0 801107A0 0C04417A */  jal   get_entity_by_index
/* 0A6EA4 801107A4 AFB10014 */   sw    $s1, 0x14($sp)
/* 0A6EA8 801107A8 0040882D */  daddu $s1, $v0, $zero
/* 0A6EAC 801107AC 8E240040 */  lw    $a0, 0x40($s1)
/* 0A6EB0 801107B0 10800003 */  beqz  $a0, .L801107C0
/* 0A6EB4 801107B4 00000000 */   nop   
/* 0A6EB8 801107B8 0C00AB4B */  jal   heap_free
/* 0A6EBC 801107BC 00000000 */   nop   
.L801107C0:
/* 0A6EC0 801107C0 8E220000 */  lw    $v0, ($s1)
/* 0A6EC4 801107C4 30420008 */  andi  $v0, $v0, 8
/* 0A6EC8 801107C8 14400005 */  bnez  $v0, .L801107E0
/* 0A6ECC 801107CC 00000000 */   nop   
/* 0A6ED0 801107D0 0C048B7F */  jal   func_80122DFC
/* 0A6ED4 801107D4 86240014 */   lh    $a0, 0x14($s1)
/* 0A6ED8 801107D8 080441FC */  j     .L801107F0
/* 0A6EDC 801107DC 00000000 */   nop   

.L801107E0:
/* 0A6EE0 801107E0 0C047FF8 */  jal   func_8011FFE0
/* 0A6EE4 801107E4 86240014 */   lh    $a0, 0x14($s1)
/* 0A6EE8 801107E8 0C04790E */  jal   func_8011E438
/* 0A6EEC 801107EC 0040202D */   daddu $a0, $v0, $zero
.L801107F0:
/* 0A6EF0 801107F0 8E240038 */  lw    $a0, 0x38($s1)
/* 0A6EF4 801107F4 0C0445F7 */  jal   func_801117DC
/* 0A6EF8 801107F8 00000000 */   nop   
/* 0A6EFC 801107FC 86240016 */  lh    $a0, 0x16($s1)
/* 0A6F00 80110800 04800007 */  bltz  $a0, .L80110820
/* 0A6F04 80110804 00000000 */   nop   
/* 0A6F08 80110808 0C044181 */  jal   get_shadow_by_index
/* 0A6F0C 8011080C 00000000 */   nop   
/* 0A6F10 80110810 8C430000 */  lw    $v1, ($v0)
/* 0A6F14 80110814 3C041000 */  lui   $a0, 0x1000
/* 0A6F18 80110818 00641825 */  or    $v1, $v1, $a0
/* 0A6F1C 8011081C AC430000 */  sw    $v1, ($v0)
.L80110820:
/* 0A6F20 80110820 3C118015 */  lui   $s1, 0x8015
/* 0A6F24 80110824 26311470 */  addiu $s1, $s1, 0x1470
/* 0A6F28 80110828 8E220000 */  lw    $v0, ($s1)
/* 0A6F2C 8011082C 00108080 */  sll   $s0, $s0, 2
/* 0A6F30 80110830 02021021 */  addu  $v0, $s0, $v0
/* 0A6F34 80110834 0C00AB4B */  jal   heap_free
/* 0A6F38 80110838 8C440000 */   lw    $a0, ($v0)
/* 0A6F3C 8011083C 8E220000 */  lw    $v0, ($s1)
/* 0A6F40 80110840 02028021 */  addu  $s0, $s0, $v0
/* 0A6F44 80110844 AE000000 */  sw    $zero, ($s0)
/* 0A6F48 80110848 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A6F4C 8011084C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A6F50 80110850 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A6F54 80110854 03E00008 */  jr    $ra
/* 0A6F58 80110858 27BD0020 */   addiu $sp, $sp, 0x20

