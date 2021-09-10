.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A8_B5E858
/* B5E858 802405A8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B5E85C 802405AC AFB10054 */  sw        $s1, 0x54($sp)
/* B5E860 802405B0 0080882D */  daddu     $s1, $a0, $zero
/* B5E864 802405B4 AFBF0058 */  sw        $ra, 0x58($sp)
/* B5E868 802405B8 AFB00050 */  sw        $s0, 0x50($sp)
/* B5E86C 802405BC F7B40060 */  sdc1      $f20, 0x60($sp)
/* B5E870 802405C0 8E30000C */  lw        $s0, 0xc($s1)
/* B5E874 802405C4 8E050000 */  lw        $a1, ($s0)
/* B5E878 802405C8 0C0B1EAF */  jal       evt_get_variable
/* B5E87C 802405CC 26100004 */   addiu    $s0, $s0, 4
/* B5E880 802405D0 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B5E884 802405D4 0040202D */   daddu    $a0, $v0, $zero
/* B5E888 802405D8 0220202D */  daddu     $a0, $s1, $zero
/* B5E88C 802405DC 8E050000 */  lw        $a1, ($s0)
/* B5E890 802405E0 0C0B210B */  jal       evt_get_float_variable
/* B5E894 802405E4 0040802D */   daddu    $s0, $v0, $zero
/* B5E898 802405E8 0200202D */  daddu     $a0, $s0, $zero
/* B5E89C 802405EC 0C046B4C */  jal       get_model_from_list_index
/* B5E8A0 802405F0 46000506 */   mov.s    $f20, $f0
/* B5E8A4 802405F4 0040802D */  daddu     $s0, $v0, $zero
/* B5E8A8 802405F8 96020000 */  lhu       $v0, ($s0)
/* B5E8AC 802405FC 30420400 */  andi      $v0, $v0, 0x400
/* B5E8B0 80240600 14400008 */  bnez      $v0, .L80240624
/* B5E8B4 80240604 00000000 */   nop
/* B5E8B8 80240608 4405A000 */  mfc1      $a1, $f20
/* B5E8BC 8024060C 0C090153 */  jal       func_8024054C_B5E7FC
/* B5E8C0 80240610 26040058 */   addiu    $a0, $s0, 0x58
/* B5E8C4 80240614 96020000 */  lhu       $v0, ($s0)
/* B5E8C8 80240618 34421400 */  ori       $v0, $v0, 0x1400
/* B5E8CC 8024061C 08090190 */  j         .L80240640
/* B5E8D0 80240620 A6020000 */   sh       $v0, ($s0)
.L80240624:
/* B5E8D4 80240624 4405A000 */  mfc1      $a1, $f20
/* B5E8D8 80240628 0C090153 */  jal       func_8024054C_B5E7FC
/* B5E8DC 8024062C 27A40010 */   addiu    $a0, $sp, 0x10
/* B5E8E0 80240630 27A40010 */  addiu     $a0, $sp, 0x10
/* B5E8E4 80240634 26050058 */  addiu     $a1, $s0, 0x58
/* B5E8E8 80240638 0C019D80 */  jal       guMtxCatF
/* B5E8EC 8024063C 00A0302D */   daddu    $a2, $a1, $zero
.L80240640:
/* B5E8F0 80240640 8FBF0058 */  lw        $ra, 0x58($sp)
/* B5E8F4 80240644 8FB10054 */  lw        $s1, 0x54($sp)
/* B5E8F8 80240648 8FB00050 */  lw        $s0, 0x50($sp)
/* B5E8FC 8024064C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B5E900 80240650 24020002 */  addiu     $v0, $zero, 2
/* B5E904 80240654 03E00008 */  jr        $ra
/* B5E908 80240658 27BD0068 */   addiu    $sp, $sp, 0x68
/* B5E90C 8024065C 00000000 */  nop
