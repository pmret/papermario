.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetModelFlag10
/* 0EDA2C 802C907C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDA30 802C9080 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDA34 802C9084 0080882D */  daddu $s1, $a0, $zero
/* 0EDA38 802C9088 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EDA3C 802C908C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDA40 802C9090 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDA44 802C9094 8E050000 */  lw    $a1, ($s0)
/* 0EDA48 802C9098 0C0B1EAF */  jal   get_variable
/* 0EDA4C 802C909C 26100004 */   addiu $s0, $s0, 4
/* 0EDA50 802C90A0 0220202D */  daddu $a0, $s1, $zero
/* 0EDA54 802C90A4 8E050000 */  lw    $a1, ($s0)
/* 0EDA58 802C90A8 0C0B1EAF */  jal   get_variable
/* 0EDA5C 802C90AC 0040802D */   daddu $s0, $v0, $zero
/* 0EDA60 802C90B0 0200202D */  daddu $a0, $s0, $zero
/* 0EDA64 802C90B4 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EDA68 802C90B8 0040802D */   daddu $s0, $v0, $zero
/* 0EDA6C 802C90BC 0C046B4C */  jal   get_model_from_list_index
/* 0EDA70 802C90C0 0040202D */   daddu $a0, $v0, $zero
/* 0EDA74 802C90C4 12000004 */  beqz  $s0, .L802C90D8
/* 0EDA78 802C90C8 0040182D */   daddu $v1, $v0, $zero
/* 0EDA7C 802C90CC 94620000 */  lhu   $v0, ($v1)
/* 0EDA80 802C90D0 080B2438 */  j     .L802C90E0
/* 0EDA84 802C90D4 34420010 */   ori   $v0, $v0, 0x10

.L802C90D8:
/* 0EDA88 802C90D8 94620000 */  lhu   $v0, ($v1)
/* 0EDA8C 802C90DC 3042FFEF */  andi  $v0, $v0, 0xffef
.L802C90E0:
/* 0EDA90 802C90E0 A4620000 */  sh    $v0, ($v1)
/* 0EDA94 802C90E4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EDA98 802C90E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDA9C 802C90EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDAA0 802C90F0 24020002 */  addiu $v0, $zero, 2
/* 0EDAA4 802C90F4 03E00008 */  jr    $ra
/* 0EDAA8 802C90F8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EDAAC 802C90FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDAB0 802C9100 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EDAB4 802C9104 0080902D */  daddu $s2, $a0, $zero
/* 0EDAB8 802C9108 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EDABC 802C910C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDAC0 802C9110 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDAC4 802C9114 8E50000C */  lw    $s0, 0xc($s2)
/* 0EDAC8 802C9118 8E050000 */  lw    $a1, ($s0)
/* 0EDACC 802C911C 0C0B1EAF */  jal   get_variable
/* 0EDAD0 802C9120 26100004 */   addiu $s0, $s0, 4
/* 0EDAD4 802C9124 8E050000 */  lw    $a1, ($s0)
/* 0EDAD8 802C9128 26100004 */  addiu $s0, $s0, 4
/* 0EDADC 802C912C 0240202D */  daddu $a0, $s2, $zero
/* 0EDAE0 802C9130 0C0B1EAF */  jal   get_variable
/* 0EDAE4 802C9134 0040882D */   daddu $s1, $v0, $zero
/* 0EDAE8 802C9138 0240202D */  daddu $a0, $s2, $zero
/* 0EDAEC 802C913C 8E050000 */  lw    $a1, ($s0)
/* 0EDAF0 802C9140 0C0B1EAF */  jal   get_variable
/* 0EDAF4 802C9144 0040902D */   daddu $s2, $v0, $zero
/* 0EDAF8 802C9148 0220202D */  daddu $a0, $s1, $zero
/* 0EDAFC 802C914C 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EDB00 802C9150 0040802D */   daddu $s0, $v0, $zero
/* 0EDB04 802C9154 0C046B4C */  jal   get_model_from_list_index
/* 0EDB08 802C9158 0040202D */   daddu $a0, $v0, $zero
/* 0EDB0C 802C915C 0040882D */  daddu $s1, $v0, $zero
/* 0EDB10 802C9160 0220202D */  daddu $a0, $s1, $zero
/* 0EDB14 802C9164 0240282D */  daddu $a1, $s2, $zero
/* 0EDB18 802C9168 0C046F1F */  jal   func_8011BC7C
/* 0EDB1C 802C916C 0200302D */   daddu $a2, $s0, $zero
/* 0EDB20 802C9170 2402FFFF */  addiu $v0, $zero, -1
/* 0EDB24 802C9174 12420004 */  beq   $s2, $v0, .L802C9188
/* 0EDB28 802C9178 00000000 */   nop   
/* 0EDB2C 802C917C 96220000 */  lhu   $v0, ($s1)
/* 0EDB30 802C9180 34420010 */  ori   $v0, $v0, 0x10
/* 0EDB34 802C9184 A6220000 */  sh    $v0, ($s1)
.L802C9188:
/* 0EDB38 802C9188 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EDB3C 802C918C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EDB40 802C9190 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDB44 802C9194 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDB48 802C9198 24020002 */  addiu $v0, $zero, 2
/* 0EDB4C 802C919C 03E00008 */  jr    $ra
/* 0EDB50 802C91A0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EDB54 802C91A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDB58 802C91A8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDB5C 802C91AC 0080882D */  daddu $s1, $a0, $zero
/* 0EDB60 802C91B0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EDB64 802C91B4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDB68 802C91B8 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDB6C 802C91BC 8E050000 */  lw    $a1, ($s0)
/* 0EDB70 802C91C0 0C0B1EAF */  jal   get_variable
/* 0EDB74 802C91C4 26100004 */   addiu $s0, $s0, 4
/* 0EDB78 802C91C8 0220202D */  daddu $a0, $s1, $zero
/* 0EDB7C 802C91CC 8E050000 */  lw    $a1, ($s0)
/* 0EDB80 802C91D0 0C0B1EAF */  jal   get_variable
/* 0EDB84 802C91D4 0040802D */   daddu $s0, $v0, $zero
/* 0EDB88 802C91D8 0200202D */  daddu $a0, $s0, $zero
/* 0EDB8C 802C91DC 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EDB90 802C91E0 0040802D */   daddu $s0, $v0, $zero
/* 0EDB94 802C91E4 0C046B4C */  jal   get_model_from_list_index
/* 0EDB98 802C91E8 0040202D */   daddu $a0, $v0, $zero
/* 0EDB9C 802C91EC A05000A9 */  sb    $s0, 0xa9($v0)
/* 0EDBA0 802C91F0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EDBA4 802C91F4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDBA8 802C91F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDBAC 802C91FC 24020002 */  addiu $v0, $zero, 2
/* 0EDBB0 802C9200 03E00008 */  jr    $ra
/* 0EDBB4 802C9204 27BD0020 */   addiu $sp, $sp, 0x20

