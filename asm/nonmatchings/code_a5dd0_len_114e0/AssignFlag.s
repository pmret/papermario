.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AssignFlag
/* 0A87B8 801120B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A87BC 801120BC AFB10014 */  sw    $s1, 0x14($sp)
/* 0A87C0 801120C0 0080882D */  daddu $s1, $a0, $zero
/* 0A87C4 801120C4 24020001 */  addiu $v0, $zero, 1
/* 0A87C8 801120C8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0A87CC 801120CC AFB00010 */  sw    $s0, 0x10($sp)
/* 0A87D0 801120D0 14A2000B */  bne   $a1, $v0, .L80112100
/* 0A87D4 801120D4 8E30000C */   lw    $s0, 0xc($s1)
/* 0A87D8 801120D8 3C048015 */  lui   $a0, 0x8015
/* 0A87DC 801120DC 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A87E0 801120E0 0C04417A */  jal   get_entity_by_index
/* 0A87E4 801120E4 00000000 */   nop   
/* 0A87E8 801120E8 8E050000 */  lw    $a1, ($s0)
/* 0A87EC 801120EC 8C500040 */  lw    $s0, 0x40($v0)
/* 0A87F0 801120F0 0C0B1F6A */  jal   get_variable_index
/* 0A87F4 801120F4 0220202D */   daddu $a0, $s1, $zero
/* 0A87F8 801120F8 A6020000 */  sh    $v0, ($s0)
/* 0A87FC 801120FC 24020002 */  addiu $v0, $zero, 2
.L80112100:
/* 0A8800 80112100 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A8804 80112104 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A8808 80112108 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A880C 8011210C 03E00008 */  jr    $ra
/* 0A8810 80112110 27BD0020 */   addiu $sp, $sp, 0x20

