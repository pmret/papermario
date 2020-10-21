.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241668_B857E8
/* B857E8 80241668 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B857EC 8024166C AFB10054 */  sw        $s1, 0x54($sp)
/* B857F0 80241670 0080882D */  daddu     $s1, $a0, $zero
/* B857F4 80241674 AFBF0058 */  sw        $ra, 0x58($sp)
/* B857F8 80241678 AFB00050 */  sw        $s0, 0x50($sp)
/* B857FC 8024167C F7B40060 */  sdc1      $f20, 0x60($sp)
/* B85800 80241680 8E30000C */  lw        $s0, 0xc($s1)
/* B85804 80241684 8E050000 */  lw        $a1, ($s0)
/* B85808 80241688 0C0B1EAF */  jal       get_variable
/* B8580C 8024168C 26100004 */   addiu    $s0, $s0, 4
/* B85810 80241690 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B85814 80241694 0040202D */   daddu    $a0, $v0, $zero
/* B85818 80241698 0220202D */  daddu     $a0, $s1, $zero
/* B8581C 8024169C 8E050000 */  lw        $a1, ($s0)
/* B85820 802416A0 0C0B210B */  jal       get_float_variable
/* B85824 802416A4 0040802D */   daddu    $s0, $v0, $zero
/* B85828 802416A8 0200202D */  daddu     $a0, $s0, $zero
/* B8582C 802416AC 0C046B4C */  jal       get_model_from_list_index
/* B85830 802416B0 46000506 */   mov.s    $f20, $f0
/* B85834 802416B4 0040802D */  daddu     $s0, $v0, $zero
/* B85838 802416B8 96020000 */  lhu       $v0, ($s0)
/* B8583C 802416BC 30420400 */  andi      $v0, $v0, 0x400
/* B85840 802416C0 14400008 */  bnez      $v0, .L802416E4
/* B85844 802416C4 00000000 */   nop      
/* B85848 802416C8 4405A000 */  mfc1      $a1, $f20
/* B8584C 802416CC 0C090583 */  jal       func_8024160C_B8578C
/* B85850 802416D0 26040058 */   addiu    $a0, $s0, 0x58
/* B85854 802416D4 96020000 */  lhu       $v0, ($s0)
/* B85858 802416D8 34421400 */  ori       $v0, $v0, 0x1400
/* B8585C 802416DC 080905C0 */  j         .L80241700
/* B85860 802416E0 A6020000 */   sh       $v0, ($s0)
.L802416E4:
/* B85864 802416E4 4405A000 */  mfc1      $a1, $f20
/* B85868 802416E8 0C090583 */  jal       func_8024160C_B8578C
/* B8586C 802416EC 27A40010 */   addiu    $a0, $sp, 0x10
/* B85870 802416F0 27A40010 */  addiu     $a0, $sp, 0x10
/* B85874 802416F4 26050058 */  addiu     $a1, $s0, 0x58
/* B85878 802416F8 0C019D80 */  jal       guMtxCatF
/* B8587C 802416FC 00A0302D */   daddu    $a2, $a1, $zero
.L80241700:
/* B85880 80241700 8FBF0058 */  lw        $ra, 0x58($sp)
/* B85884 80241704 8FB10054 */  lw        $s1, 0x54($sp)
/* B85888 80241708 8FB00050 */  lw        $s0, 0x50($sp)
/* B8588C 8024170C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B85890 80241710 24020002 */  addiu     $v0, $zero, 2
/* B85894 80241714 03E00008 */  jr        $ra
/* B85898 80241718 27BD0068 */   addiu    $sp, $sp, 0x68
/* B8589C 8024171C 00000000 */  nop       
