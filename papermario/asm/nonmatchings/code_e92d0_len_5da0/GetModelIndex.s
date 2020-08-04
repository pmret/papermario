.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetModelIndex
/* 0ED83C 802C8E8C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0ED840 802C8E90 AFB10014 */  sw    $s1, 0x14($sp)
/* 0ED844 802C8E94 0080882D */  daddu $s1, $a0, $zero
/* 0ED848 802C8E98 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0ED84C 802C8E9C AFB00010 */  sw    $s0, 0x10($sp)
/* 0ED850 802C8EA0 8E30000C */  lw    $s0, 0xc($s1)
/* 0ED854 802C8EA4 8E050000 */  lw    $a1, ($s0)
/* 0ED858 802C8EA8 0C0B1EAF */  jal   get_variable
/* 0ED85C 802C8EAC 26100004 */   addiu $s0, $s0, 4
/* 0ED860 802C8EB0 8E100000 */  lw    $s0, ($s0)
/* 0ED864 802C8EB4 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0ED868 802C8EB8 0040202D */   daddu $a0, $v0, $zero
/* 0ED86C 802C8EBC 0220202D */  daddu $a0, $s1, $zero
/* 0ED870 802C8EC0 0040302D */  daddu $a2, $v0, $zero
/* 0ED874 802C8EC4 0C0B2026 */  jal   set_variable
/* 0ED878 802C8EC8 0200282D */   daddu $a1, $s0, $zero
/* 0ED87C 802C8ECC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0ED880 802C8ED0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0ED884 802C8ED4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0ED888 802C8ED8 24020002 */  addiu $v0, $zero, 2
/* 0ED88C 802C8EDC 03E00008 */  jr    $ra
/* 0ED890 802C8EE0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0ED894 802C8EE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0ED898 802C8EE8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0ED89C 802C8EEC 8C82000C */  lw    $v0, 0xc($a0)
/* 0ED8A0 802C8EF0 0C0B1EAF */  jal   get_variable
/* 0ED8A4 802C8EF4 8C450000 */   lw    $a1, ($v0)
/* 0ED8A8 802C8EF8 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0ED8AC 802C8EFC 0040202D */   daddu $a0, $v0, $zero
/* 0ED8B0 802C8F00 0C046B4C */  jal   get_model_from_list_index
/* 0ED8B4 802C8F04 0040202D */   daddu $a0, $v0, $zero
/* 0ED8B8 802C8F08 0040202D */  daddu $a0, $v0, $zero
/* 0ED8BC 802C8F0C 94830000 */  lhu   $v1, ($a0)
/* 0ED8C0 802C8F10 3063FBFF */  andi  $v1, $v1, 0xfbff
/* 0ED8C4 802C8F14 A4830000 */  sh    $v1, ($a0)
/* 0ED8C8 802C8F18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0ED8CC 802C8F1C 24020002 */  addiu $v0, $zero, 2
/* 0ED8D0 802C8F20 03E00008 */  jr    $ra
/* 0ED8D4 802C8F24 27BD0018 */   addiu $sp, $sp, 0x18

