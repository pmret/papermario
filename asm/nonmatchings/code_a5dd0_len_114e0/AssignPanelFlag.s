.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AssignPanelFlag
/* 0A8814 80112114 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A8818 80112118 AFB10014 */  sw    $s1, 0x14($sp)
/* 0A881C 8011211C 0080882D */  daddu $s1, $a0, $zero
/* 0A8820 80112120 24020001 */  addiu $v0, $zero, 1
/* 0A8824 80112124 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0A8828 80112128 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A882C 8011212C 14A2000B */  bne   $a1, $v0, .L8011215C
/* 0A8830 80112130 8E30000C */   lw    $s0, 0xc($s1)
/* 0A8834 80112134 3C048015 */  lui   $a0, 0x8015
/* 0A8838 80112138 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A883C 8011213C 0C04417A */  jal   get_entity_by_index
/* 0A8840 80112140 00000000 */   nop   
/* 0A8844 80112144 8E050000 */  lw    $a1, ($s0)
/* 0A8848 80112148 8C500040 */  lw    $s0, 0x40($v0)
/* 0A884C 8011214C 0C0B1F6A */  jal   get_variable_index
/* 0A8850 80112150 0220202D */   daddu $a0, $s1, $zero
/* 0A8854 80112154 A6020006 */  sh    $v0, 6($s0)
/* 0A8858 80112158 24020002 */  addiu $v0, $zero, 2
.L8011215C:
/* 0A885C 8011215C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A8860 80112160 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A8864 80112164 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A8868 80112168 03E00008 */  jr    $ra
/* 0A886C 8011216C 27BD0020 */   addiu $sp, $sp, 0x20

