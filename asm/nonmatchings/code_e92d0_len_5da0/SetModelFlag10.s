.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetModelFlag10
/* EDA2C 802C907C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDA30 802C9080 AFB10014 */  sw        $s1, 0x14($sp)
/* EDA34 802C9084 0080882D */  daddu     $s1, $a0, $zero
/* EDA38 802C9088 AFBF0018 */  sw        $ra, 0x18($sp)
/* EDA3C 802C908C AFB00010 */  sw        $s0, 0x10($sp)
/* EDA40 802C9090 8E30000C */  lw        $s0, 0xc($s1)
/* EDA44 802C9094 8E050000 */  lw        $a1, ($s0)
/* EDA48 802C9098 0C0B1EAF */  jal       get_variable
/* EDA4C 802C909C 26100004 */   addiu    $s0, $s0, 4
/* EDA50 802C90A0 0220202D */  daddu     $a0, $s1, $zero
/* EDA54 802C90A4 8E050000 */  lw        $a1, ($s0)
/* EDA58 802C90A8 0C0B1EAF */  jal       get_variable
/* EDA5C 802C90AC 0040802D */   daddu    $s0, $v0, $zero
/* EDA60 802C90B0 0200202D */  daddu     $a0, $s0, $zero
/* EDA64 802C90B4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* EDA68 802C90B8 0040802D */   daddu    $s0, $v0, $zero
/* EDA6C 802C90BC 0C046B4C */  jal       get_model_from_list_index
/* EDA70 802C90C0 0040202D */   daddu    $a0, $v0, $zero
/* EDA74 802C90C4 12000004 */  beqz      $s0, .L802C90D8
/* EDA78 802C90C8 0040182D */   daddu    $v1, $v0, $zero
/* EDA7C 802C90CC 94620000 */  lhu       $v0, ($v1)
/* EDA80 802C90D0 080B2438 */  j         .L802C90E0
/* EDA84 802C90D4 34420010 */   ori      $v0, $v0, 0x10
.L802C90D8:
/* EDA88 802C90D8 94620000 */  lhu       $v0, ($v1)
/* EDA8C 802C90DC 3042FFEF */  andi      $v0, $v0, 0xffef
.L802C90E0:
/* EDA90 802C90E0 A4620000 */  sh        $v0, ($v1)
/* EDA94 802C90E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDA98 802C90E8 8FB10014 */  lw        $s1, 0x14($sp)
/* EDA9C 802C90EC 8FB00010 */  lw        $s0, 0x10($sp)
/* EDAA0 802C90F0 24020002 */  addiu     $v0, $zero, 2
/* EDAA4 802C90F4 03E00008 */  jr        $ra
/* EDAA8 802C90F8 27BD0020 */   addiu    $sp, $sp, 0x20
