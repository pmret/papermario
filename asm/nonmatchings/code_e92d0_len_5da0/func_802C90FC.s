.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C90FC
/* EDAAC 802C90FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDAB0 802C9100 AFB20018 */  sw        $s2, 0x18($sp)
/* EDAB4 802C9104 0080902D */  daddu     $s2, $a0, $zero
/* EDAB8 802C9108 AFBF001C */  sw        $ra, 0x1c($sp)
/* EDABC 802C910C AFB10014 */  sw        $s1, 0x14($sp)
/* EDAC0 802C9110 AFB00010 */  sw        $s0, 0x10($sp)
/* EDAC4 802C9114 8E50000C */  lw        $s0, 0xc($s2)
/* EDAC8 802C9118 8E050000 */  lw        $a1, ($s0)
/* EDACC 802C911C 0C0B1EAF */  jal       get_variable
/* EDAD0 802C9120 26100004 */   addiu    $s0, $s0, 4
/* EDAD4 802C9124 8E050000 */  lw        $a1, ($s0)
/* EDAD8 802C9128 26100004 */  addiu     $s0, $s0, 4
/* EDADC 802C912C 0240202D */  daddu     $a0, $s2, $zero
/* EDAE0 802C9130 0C0B1EAF */  jal       get_variable
/* EDAE4 802C9134 0040882D */   daddu    $s1, $v0, $zero
/* EDAE8 802C9138 0240202D */  daddu     $a0, $s2, $zero
/* EDAEC 802C913C 8E050000 */  lw        $a1, ($s0)
/* EDAF0 802C9140 0C0B1EAF */  jal       get_variable
/* EDAF4 802C9144 0040902D */   daddu    $s2, $v0, $zero
/* EDAF8 802C9148 0220202D */  daddu     $a0, $s1, $zero
/* EDAFC 802C914C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* EDB00 802C9150 0040802D */   daddu    $s0, $v0, $zero
/* EDB04 802C9154 0C046B4C */  jal       get_model_from_list_index
/* EDB08 802C9158 0040202D */   daddu    $a0, $v0, $zero
/* EDB0C 802C915C 0040882D */  daddu     $s1, $v0, $zero
/* EDB10 802C9160 0220202D */  daddu     $a0, $s1, $zero
/* EDB14 802C9164 0240282D */  daddu     $a1, $s2, $zero
/* EDB18 802C9168 0C046F1F */  jal       func_8011BC7C
/* EDB1C 802C916C 0200302D */   daddu    $a2, $s0, $zero
/* EDB20 802C9170 2402FFFF */  addiu     $v0, $zero, -1
/* EDB24 802C9174 12420004 */  beq       $s2, $v0, .L802C9188
/* EDB28 802C9178 00000000 */   nop      
/* EDB2C 802C917C 96220000 */  lhu       $v0, ($s1)
/* EDB30 802C9180 34420010 */  ori       $v0, $v0, 0x10
/* EDB34 802C9184 A6220000 */  sh        $v0, ($s1)
.L802C9188:
/* EDB38 802C9188 8FBF001C */  lw        $ra, 0x1c($sp)
/* EDB3C 802C918C 8FB20018 */  lw        $s2, 0x18($sp)
/* EDB40 802C9190 8FB10014 */  lw        $s1, 0x14($sp)
/* EDB44 802C9194 8FB00010 */  lw        $s0, 0x10($sp)
/* EDB48 802C9198 24020002 */  addiu     $v0, $zero, 2
/* EDB4C 802C919C 03E00008 */  jr        $ra
/* EDB50 802C91A0 27BD0020 */   addiu    $sp, $sp, 0x20
