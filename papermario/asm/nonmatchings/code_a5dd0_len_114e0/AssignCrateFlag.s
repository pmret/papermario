.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AssignCrateFlag
/* 0A8870 80112170 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A8874 80112174 AFB10014 */  sw    $s1, 0x14($sp)
/* 0A8878 80112178 0080882D */  daddu $s1, $a0, $zero
/* 0A887C 8011217C 24020001 */  addiu $v0, $zero, 1
/* 0A8880 80112180 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0A8884 80112184 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A8888 80112188 14A2000B */  bne   $a1, $v0, .L801121B8
/* 0A888C 8011218C 8E30000C */   lw    $s0, 0xc($s1)
/* 0A8890 80112190 3C048015 */  lui   $a0, 0x8015
/* 0A8894 80112194 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A8898 80112198 0C04417A */  jal   get_entity_by_index
/* 0A889C 8011219C 00000000 */   nop   
/* 0A88A0 801121A0 8E050000 */  lw    $a1, ($s0)
/* 0A88A4 801121A4 8C500040 */  lw    $s0, 0x40($v0)
/* 0A88A8 801121A8 0C0B1F6A */  jal   get_variable_index
/* 0A88AC 801121AC 0220202D */   daddu $a0, $s1, $zero
/* 0A88B0 801121B0 A6020004 */  sh    $v0, 4($s0)
/* 0A88B4 801121B4 24020002 */  addiu $v0, $zero, 2
.L801121B8:
/* 0A88B8 801121B8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A88BC 801121BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A88C0 801121C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A88C4 801121C4 03E00008 */  jr    $ra
/* 0A88C8 801121C8 27BD0020 */   addiu $sp, $sp, 0x20

