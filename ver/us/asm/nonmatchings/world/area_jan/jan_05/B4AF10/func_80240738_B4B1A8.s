.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240738_B4B1A8
/* B4B1A8 80240738 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B4B1AC 8024073C AFB10054 */  sw        $s1, 0x54($sp)
/* B4B1B0 80240740 0080882D */  daddu     $s1, $a0, $zero
/* B4B1B4 80240744 AFBF0058 */  sw        $ra, 0x58($sp)
/* B4B1B8 80240748 AFB00050 */  sw        $s0, 0x50($sp)
/* B4B1BC 8024074C F7B40060 */  sdc1      $f20, 0x60($sp)
/* B4B1C0 80240750 8E30000C */  lw        $s0, 0xc($s1)
/* B4B1C4 80240754 8E050000 */  lw        $a1, ($s0)
/* B4B1C8 80240758 0C0B1EAF */  jal       evt_get_variable
/* B4B1CC 8024075C 26100004 */   addiu    $s0, $s0, 4
/* B4B1D0 80240760 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B4B1D4 80240764 0040202D */   daddu    $a0, $v0, $zero
/* B4B1D8 80240768 0220202D */  daddu     $a0, $s1, $zero
/* B4B1DC 8024076C 8E050000 */  lw        $a1, ($s0)
/* B4B1E0 80240770 0C0B210B */  jal       evt_get_float_variable
/* B4B1E4 80240774 0040802D */   daddu    $s0, $v0, $zero
/* B4B1E8 80240778 0200202D */  daddu     $a0, $s0, $zero
/* B4B1EC 8024077C 0C046B4C */  jal       get_model_from_list_index
/* B4B1F0 80240780 46000506 */   mov.s    $f20, $f0
/* B4B1F4 80240784 0040802D */  daddu     $s0, $v0, $zero
/* B4B1F8 80240788 96020000 */  lhu       $v0, ($s0)
/* B4B1FC 8024078C 30420400 */  andi      $v0, $v0, 0x400
/* B4B200 80240790 14400008 */  bnez      $v0, .L802407B4
/* B4B204 80240794 00000000 */   nop
/* B4B208 80240798 4405A000 */  mfc1      $a1, $f20
/* B4B20C 8024079C 0C0901B7 */  jal       func_802406DC_B4B14C
/* B4B210 802407A0 26040058 */   addiu    $a0, $s0, 0x58
/* B4B214 802407A4 96020000 */  lhu       $v0, ($s0)
/* B4B218 802407A8 34421400 */  ori       $v0, $v0, 0x1400
/* B4B21C 802407AC 080901F4 */  j         .L802407D0
/* B4B220 802407B0 A6020000 */   sh       $v0, ($s0)
.L802407B4:
/* B4B224 802407B4 4405A000 */  mfc1      $a1, $f20
/* B4B228 802407B8 0C0901B7 */  jal       func_802406DC_B4B14C
/* B4B22C 802407BC 27A40010 */   addiu    $a0, $sp, 0x10
/* B4B230 802407C0 27A40010 */  addiu     $a0, $sp, 0x10
/* B4B234 802407C4 26050058 */  addiu     $a1, $s0, 0x58
/* B4B238 802407C8 0C019D80 */  jal       guMtxCatF
/* B4B23C 802407CC 00A0302D */   daddu    $a2, $a1, $zero
.L802407D0:
/* B4B240 802407D0 8FBF0058 */  lw        $ra, 0x58($sp)
/* B4B244 802407D4 8FB10054 */  lw        $s1, 0x54($sp)
/* B4B248 802407D8 8FB00050 */  lw        $s0, 0x50($sp)
/* B4B24C 802407DC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B4B250 802407E0 24020002 */  addiu     $v0, $zero, 2
/* B4B254 802407E4 03E00008 */  jr        $ra
/* B4B258 802407E8 27BD0068 */   addiu    $sp, $sp, 0x68
/* B4B25C 802407EC 00000000 */  nop
