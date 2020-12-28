.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218114_5CE7A4
/* 5CE7A4 80218114 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5CE7A8 80218118 AFB20018 */  sw        $s2, 0x18($sp)
/* 5CE7AC 8021811C 0080902D */  daddu     $s2, $a0, $zero
/* 5CE7B0 80218120 AFBF0028 */  sw        $ra, 0x28($sp)
/* 5CE7B4 80218124 AFB50024 */  sw        $s5, 0x24($sp)
/* 5CE7B8 80218128 AFB40020 */  sw        $s4, 0x20($sp)
/* 5CE7BC 8021812C AFB3001C */  sw        $s3, 0x1c($sp)
/* 5CE7C0 80218130 AFB10014 */  sw        $s1, 0x14($sp)
/* 5CE7C4 80218134 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CE7C8 80218138 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5CE7CC 8021813C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CE7D0 80218140 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CE7D4 80218144 8E50000C */  lw        $s0, 0xc($s2)
/* 5CE7D8 80218148 8E140000 */  lw        $s4, ($s0)
/* 5CE7DC 8021814C 26100004 */  addiu     $s0, $s0, 4
/* 5CE7E0 80218150 0C0B1EAF */  jal       get_variable
/* 5CE7E4 80218154 0280282D */   daddu    $a1, $s4, $zero
/* 5CE7E8 80218158 0040982D */  daddu     $s3, $v0, $zero
/* 5CE7EC 8021815C 8E150000 */  lw        $s5, ($s0)
/* 5CE7F0 80218160 26100004 */  addiu     $s0, $s0, 4
/* 5CE7F4 80218164 8E050000 */  lw        $a1, ($s0)
/* 5CE7F8 80218168 26100004 */  addiu     $s0, $s0, 4
/* 5CE7FC 8021816C 0C0B210B */  jal       get_float_variable
/* 5CE800 80218170 0240202D */   daddu    $a0, $s2, $zero
/* 5CE804 80218174 8E050000 */  lw        $a1, ($s0)
/* 5CE808 80218178 26100004 */  addiu     $s0, $s0, 4
/* 5CE80C 8021817C 0240202D */  daddu     $a0, $s2, $zero
/* 5CE810 80218180 0C0B210B */  jal       get_float_variable
/* 5CE814 80218184 46000606 */   mov.s    $f24, $f0
/* 5CE818 80218188 8E050000 */  lw        $a1, ($s0)
/* 5CE81C 8021818C 26100004 */  addiu     $s0, $s0, 4
/* 5CE820 80218190 0240202D */  daddu     $a0, $s2, $zero
/* 5CE824 80218194 0C0B1EAF */  jal       get_variable
/* 5CE828 80218198 46000506 */   mov.s    $f20, $f0
/* 5CE82C 8021819C 8E050000 */  lw        $a1, ($s0)
/* 5CE830 802181A0 26100004 */  addiu     $s0, $s0, 4
/* 5CE834 802181A4 0240202D */  daddu     $a0, $s2, $zero
/* 5CE838 802181A8 0C0B1EAF */  jal       get_variable
/* 5CE83C 802181AC 0040882D */   daddu    $s1, $v0, $zero
/* 5CE840 802181B0 0240202D */  daddu     $a0, $s2, $zero
/* 5CE844 802181B4 8E050000 */  lw        $a1, ($s0)
/* 5CE848 802181B8 0C0B210B */  jal       get_float_variable
/* 5CE84C 802181BC 0040802D */   daddu    $s0, $v0, $zero
/* 5CE850 802181C0 3C014334 */  lui       $at, 0x4334
/* 5CE854 802181C4 44811000 */  mtc1      $at, $f2
/* 5CE858 802181C8 3C014049 */  lui       $at, 0x4049
/* 5CE85C 802181CC 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CE860 802181D0 44812000 */  mtc1      $at, $f4
/* 5CE864 802181D4 46020003 */  div.s     $f0, $f0, $f2
/* 5CE868 802181D8 46040582 */  mul.s     $f22, $f0, $f4
/* 5CE86C 802181DC 00000000 */  nop       
/* 5CE870 802181E0 4618A501 */  sub.s     $f20, $f20, $f24
/* 5CE874 802181E4 3C013F00 */  lui       $at, 0x3f00
/* 5CE878 802181E8 44810000 */  mtc1      $at, $f0
/* 5CE87C 802181EC 00000000 */  nop       
/* 5CE880 802181F0 4600A502 */  mul.s     $f20, $f20, $f0
/* 5CE884 802181F4 00000000 */  nop       
/* 5CE888 802181F8 12000007 */  beqz      $s0, .L80218218
/* 5CE88C 802181FC 0233102A */   slt      $v0, $s1, $s3
/* 5CE890 80218200 10400005 */  beqz      $v0, .L80218218
/* 5CE894 80218204 0240202D */   daddu    $a0, $s2, $zero
/* 5CE898 80218208 0220982D */  daddu     $s3, $s1, $zero
/* 5CE89C 8021820C 0280282D */  daddu     $a1, $s4, $zero
/* 5CE8A0 80218210 0C0B2026 */  jal       set_variable
/* 5CE8A4 80218214 0220302D */   daddu    $a2, $s1, $zero
.L80218218:
/* 5CE8A8 80218218 3C014049 */  lui       $at, 0x4049
/* 5CE8AC 8021821C 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CE8B0 80218220 44810000 */  mtc1      $at, $f0
/* 5CE8B4 80218224 44936000 */  mtc1      $s3, $f12
/* 5CE8B8 80218228 00000000 */  nop       
/* 5CE8BC 8021822C 46806320 */  cvt.s.w   $f12, $f12
/* 5CE8C0 80218230 46006302 */  mul.s     $f12, $f12, $f0
/* 5CE8C4 80218234 00000000 */  nop       
/* 5CE8C8 80218238 44910000 */  mtc1      $s1, $f0
/* 5CE8CC 8021823C 00000000 */  nop       
/* 5CE8D0 80218240 46800020 */  cvt.s.w   $f0, $f0
/* 5CE8D4 80218244 46006303 */  div.s     $f12, $f12, $f0
/* 5CE8D8 80218248 0C00A874 */  jal       cos_rad
/* 5CE8DC 8021824C 46166300 */   add.s    $f12, $f12, $f22
/* 5CE8E0 80218250 4600A002 */  mul.s     $f0, $f20, $f0
/* 5CE8E4 80218254 00000000 */  nop       
/* 5CE8E8 80218258 4614C080 */  add.s     $f2, $f24, $f20
/* 5CE8EC 8021825C 46001081 */  sub.s     $f2, $f2, $f0
/* 5CE8F0 80218260 0240202D */  daddu     $a0, $s2, $zero
/* 5CE8F4 80218264 44061000 */  mfc1      $a2, $f2
/* 5CE8F8 80218268 0C0B2190 */  jal       set_float_variable
/* 5CE8FC 8021826C 02A0282D */   daddu    $a1, $s5, $zero
/* 5CE900 80218270 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CE904 80218274 8FB50024 */  lw        $s5, 0x24($sp)
/* 5CE908 80218278 8FB40020 */  lw        $s4, 0x20($sp)
/* 5CE90C 8021827C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5CE910 80218280 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CE914 80218284 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CE918 80218288 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CE91C 8021828C D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5CE920 80218290 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CE924 80218294 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CE928 80218298 24020002 */  addiu     $v0, $zero, 2
/* 5CE92C 8021829C 03E00008 */  jr        $ra
/* 5CE930 802182A0 27BD0048 */   addiu    $sp, $sp, 0x48
