.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F8_B21C38
/* B21C38 802416F8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B21C3C 802416FC AFB20018 */  sw        $s2, 0x18($sp)
/* B21C40 80241700 0080902D */  daddu     $s2, $a0, $zero
/* B21C44 80241704 AFBF0028 */  sw        $ra, 0x28($sp)
/* B21C48 80241708 AFB50024 */  sw        $s5, 0x24($sp)
/* B21C4C 8024170C AFB40020 */  sw        $s4, 0x20($sp)
/* B21C50 80241710 AFB3001C */  sw        $s3, 0x1c($sp)
/* B21C54 80241714 AFB10014 */  sw        $s1, 0x14($sp)
/* B21C58 80241718 AFB00010 */  sw        $s0, 0x10($sp)
/* B21C5C 8024171C F7B80040 */  sdc1      $f24, 0x40($sp)
/* B21C60 80241720 F7B60038 */  sdc1      $f22, 0x38($sp)
/* B21C64 80241724 F7B40030 */  sdc1      $f20, 0x30($sp)
/* B21C68 80241728 8E50000C */  lw        $s0, 0xc($s2)
/* B21C6C 8024172C 8E140000 */  lw        $s4, ($s0)
/* B21C70 80241730 26100004 */  addiu     $s0, $s0, 4
/* B21C74 80241734 0C0B1EAF */  jal       get_variable
/* B21C78 80241738 0280282D */   daddu    $a1, $s4, $zero
/* B21C7C 8024173C 0040982D */  daddu     $s3, $v0, $zero
/* B21C80 80241740 8E150000 */  lw        $s5, ($s0)
/* B21C84 80241744 26100004 */  addiu     $s0, $s0, 4
/* B21C88 80241748 8E050000 */  lw        $a1, ($s0)
/* B21C8C 8024174C 26100004 */  addiu     $s0, $s0, 4
/* B21C90 80241750 0C0B210B */  jal       get_float_variable
/* B21C94 80241754 0240202D */   daddu    $a0, $s2, $zero
/* B21C98 80241758 8E050000 */  lw        $a1, ($s0)
/* B21C9C 8024175C 26100004 */  addiu     $s0, $s0, 4
/* B21CA0 80241760 0240202D */  daddu     $a0, $s2, $zero
/* B21CA4 80241764 0C0B210B */  jal       get_float_variable
/* B21CA8 80241768 46000606 */   mov.s    $f24, $f0
/* B21CAC 8024176C 8E050000 */  lw        $a1, ($s0)
/* B21CB0 80241770 26100004 */  addiu     $s0, $s0, 4
/* B21CB4 80241774 0240202D */  daddu     $a0, $s2, $zero
/* B21CB8 80241778 0C0B1EAF */  jal       get_variable
/* B21CBC 8024177C 46000506 */   mov.s    $f20, $f0
/* B21CC0 80241780 8E050000 */  lw        $a1, ($s0)
/* B21CC4 80241784 26100004 */  addiu     $s0, $s0, 4
/* B21CC8 80241788 0240202D */  daddu     $a0, $s2, $zero
/* B21CCC 8024178C 0C0B1EAF */  jal       get_variable
/* B21CD0 80241790 0040882D */   daddu    $s1, $v0, $zero
/* B21CD4 80241794 0240202D */  daddu     $a0, $s2, $zero
/* B21CD8 80241798 8E050000 */  lw        $a1, ($s0)
/* B21CDC 8024179C 0C0B210B */  jal       get_float_variable
/* B21CE0 802417A0 0040802D */   daddu    $s0, $v0, $zero
/* B21CE4 802417A4 4618A501 */  sub.s     $f20, $f20, $f24
/* B21CE8 802417A8 3C013F00 */  lui       $at, 0x3f00
/* B21CEC 802417AC 44811000 */  mtc1      $at, $f2
/* B21CF0 802417B0 00000000 */  nop
/* B21CF4 802417B4 4602A502 */  mul.s     $f20, $f20, $f2
/* B21CF8 802417B8 00000000 */  nop
/* B21CFC 802417BC 12000008 */  beqz      $s0, .L802417E0
/* B21D00 802417C0 46000586 */   mov.s    $f22, $f0
/* B21D04 802417C4 0233102A */  slt       $v0, $s1, $s3
/* B21D08 802417C8 10400005 */  beqz      $v0, .L802417E0
/* B21D0C 802417CC 0240202D */   daddu    $a0, $s2, $zero
/* B21D10 802417D0 0220982D */  daddu     $s3, $s1, $zero
/* B21D14 802417D4 0280282D */  daddu     $a1, $s4, $zero
/* B21D18 802417D8 0C0B2026 */  jal       set_variable
/* B21D1C 802417DC 0220302D */   daddu    $a2, $s1, $zero
.L802417E0:
/* B21D20 802417E0 3C014334 */  lui       $at, 0x4334
/* B21D24 802417E4 44810000 */  mtc1      $at, $f0
/* B21D28 802417E8 44936000 */  mtc1      $s3, $f12
/* B21D2C 802417EC 00000000 */  nop
/* B21D30 802417F0 46806320 */  cvt.s.w   $f12, $f12
/* B21D34 802417F4 46006302 */  mul.s     $f12, $f12, $f0
/* B21D38 802417F8 00000000 */  nop
/* B21D3C 802417FC 44910000 */  mtc1      $s1, $f0
/* B21D40 80241800 00000000 */  nop
/* B21D44 80241804 46800020 */  cvt.s.w   $f0, $f0
/* B21D48 80241808 46006303 */  div.s     $f12, $f12, $f0
/* B21D4C 8024180C 0C00A8D4 */  jal       cos_deg
/* B21D50 80241810 46166300 */   add.s    $f12, $f12, $f22
/* B21D54 80241814 4600A002 */  mul.s     $f0, $f20, $f0
/* B21D58 80241818 00000000 */  nop
/* B21D5C 8024181C 4614C080 */  add.s     $f2, $f24, $f20
/* B21D60 80241820 46001081 */  sub.s     $f2, $f2, $f0
/* B21D64 80241824 0240202D */  daddu     $a0, $s2, $zero
/* B21D68 80241828 44061000 */  mfc1      $a2, $f2
/* B21D6C 8024182C 0C0B2190 */  jal       set_float_variable
/* B21D70 80241830 02A0282D */   daddu    $a1, $s5, $zero
/* B21D74 80241834 8FBF0028 */  lw        $ra, 0x28($sp)
/* B21D78 80241838 8FB50024 */  lw        $s5, 0x24($sp)
/* B21D7C 8024183C 8FB40020 */  lw        $s4, 0x20($sp)
/* B21D80 80241840 8FB3001C */  lw        $s3, 0x1c($sp)
/* B21D84 80241844 8FB20018 */  lw        $s2, 0x18($sp)
/* B21D88 80241848 8FB10014 */  lw        $s1, 0x14($sp)
/* B21D8C 8024184C 8FB00010 */  lw        $s0, 0x10($sp)
/* B21D90 80241850 D7B80040 */  ldc1      $f24, 0x40($sp)
/* B21D94 80241854 D7B60038 */  ldc1      $f22, 0x38($sp)
/* B21D98 80241858 D7B40030 */  ldc1      $f20, 0x30($sp)
/* B21D9C 8024185C 24020002 */  addiu     $v0, $zero, 2
/* B21DA0 80241860 03E00008 */  jr        $ra
/* B21DA4 80241864 27BD0048 */   addiu    $sp, $sp, 0x48
