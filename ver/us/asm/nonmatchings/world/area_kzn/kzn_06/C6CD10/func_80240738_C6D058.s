.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240738_C6D058
/* C6D058 80240738 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C6D05C 8024073C AFBF001C */  sw        $ra, 0x1c($sp)
/* C6D060 80240740 AFB20018 */  sw        $s2, 0x18($sp)
/* C6D064 80240744 AFB10014 */  sw        $s1, 0x14($sp)
/* C6D068 80240748 AFB00010 */  sw        $s0, 0x10($sp)
/* C6D06C 8024074C 8C82000C */  lw        $v0, 0xc($a0)
/* C6D070 80240750 0C0B1EAF */  jal       get_variable
/* C6D074 80240754 8C450000 */   lw       $a1, ($v0)
/* C6D078 80240758 0040902D */  daddu     $s2, $v0, $zero
/* C6D07C 8024075C 12400013 */  beqz      $s2, .L802407AC
/* C6D080 80240760 26510002 */   addiu    $s1, $s2, 2
/* C6D084 80240764 96420000 */  lhu       $v0, ($s2)
/* C6D088 80240768 1040001D */  beqz      $v0, .L802407E0
/* C6D08C 8024076C 0000802D */   daddu    $s0, $zero, $zero
.L80240770:
/* C6D090 80240770 96240000 */  lhu       $a0, ($s1)
/* C6D094 80240774 0C046C04 */  jal       get_model_list_index_from_tree_index
/* C6D098 80240778 26100001 */   addiu    $s0, $s0, 1
/* C6D09C 8024077C 0C046B4C */  jal       get_model_from_list_index
/* C6D0A0 80240780 0040202D */   daddu    $a0, $v0, $zero
/* C6D0A4 80240784 0040202D */  daddu     $a0, $v0, $zero
/* C6D0A8 80240788 2405FFFF */  addiu     $a1, $zero, -1
/* C6D0AC 8024078C 0C046F1F */  jal       set_mdl_custom_gfx_set
/* C6D0B0 80240790 0000302D */   daddu    $a2, $zero, $zero
/* C6D0B4 80240794 96420000 */  lhu       $v0, ($s2)
/* C6D0B8 80240798 0202102A */  slt       $v0, $s0, $v0
/* C6D0BC 8024079C 1440FFF4 */  bnez      $v0, .L80240770
/* C6D0C0 802407A0 26310002 */   addiu    $s1, $s1, 2
/* C6D0C4 802407A4 080901F8 */  j         .L802407E0
/* C6D0C8 802407A8 00000000 */   nop
.L802407AC:
/* C6D0CC 802407AC 3C118015 */  lui       $s1, %hi(gCurrentModelListPtr)
/* C6D0D0 802407B0 8E3112CC */  lw        $s1, %lo(gCurrentModelListPtr)($s1)
/* C6D0D4 802407B4 0000802D */  daddu     $s0, $zero, $zero
.L802407B8:
/* C6D0D8 802407B8 8E240000 */  lw        $a0, ($s1)
/* C6D0DC 802407BC 50800005 */  beql      $a0, $zero, .L802407D4
/* C6D0E0 802407C0 26100001 */   addiu    $s0, $s0, 1
/* C6D0E4 802407C4 2405FFFF */  addiu     $a1, $zero, -1
/* C6D0E8 802407C8 0C046F1F */  jal       set_mdl_custom_gfx_set
/* C6D0EC 802407CC 0000302D */   daddu    $a2, $zero, $zero
/* C6D0F0 802407D0 26100001 */  addiu     $s0, $s0, 1
.L802407D4:
/* C6D0F4 802407D4 2A020100 */  slti      $v0, $s0, 0x100
/* C6D0F8 802407D8 1440FFF7 */  bnez      $v0, .L802407B8
/* C6D0FC 802407DC 26310004 */   addiu    $s1, $s1, 4
.L802407E0:
/* C6D100 802407E0 8FBF001C */  lw        $ra, 0x1c($sp)
/* C6D104 802407E4 8FB20018 */  lw        $s2, 0x18($sp)
/* C6D108 802407E8 8FB10014 */  lw        $s1, 0x14($sp)
/* C6D10C 802407EC 8FB00010 */  lw        $s0, 0x10($sp)
/* C6D110 802407F0 24020002 */  addiu     $v0, $zero, 2
/* C6D114 802407F4 03E00008 */  jr        $ra
/* C6D118 802407F8 27BD0020 */   addiu    $sp, $sp, 0x20
