.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407B0_CE3EA0
/* CE3EA0 802407B0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CE3EA4 802407B4 AFB20018 */  sw        $s2, 0x18($sp)
/* CE3EA8 802407B8 0080902D */  daddu     $s2, $a0, $zero
/* CE3EAC 802407BC AFBF0028 */  sw        $ra, 0x28($sp)
/* CE3EB0 802407C0 AFB50024 */  sw        $s5, 0x24($sp)
/* CE3EB4 802407C4 AFB40020 */  sw        $s4, 0x20($sp)
/* CE3EB8 802407C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* CE3EBC 802407CC AFB10014 */  sw        $s1, 0x14($sp)
/* CE3EC0 802407D0 AFB00010 */  sw        $s0, 0x10($sp)
/* CE3EC4 802407D4 F7B80040 */  sdc1      $f24, 0x40($sp)
/* CE3EC8 802407D8 F7B60038 */  sdc1      $f22, 0x38($sp)
/* CE3ECC 802407DC F7B40030 */  sdc1      $f20, 0x30($sp)
/* CE3ED0 802407E0 8E50000C */  lw        $s0, 0xc($s2)
/* CE3ED4 802407E4 8E140000 */  lw        $s4, ($s0)
/* CE3ED8 802407E8 26100004 */  addiu     $s0, $s0, 4
/* CE3EDC 802407EC 0C0B1EAF */  jal       get_variable
/* CE3EE0 802407F0 0280282D */   daddu    $a1, $s4, $zero
/* CE3EE4 802407F4 0040982D */  daddu     $s3, $v0, $zero
/* CE3EE8 802407F8 8E150000 */  lw        $s5, ($s0)
/* CE3EEC 802407FC 26100004 */  addiu     $s0, $s0, 4
/* CE3EF0 80240800 8E050000 */  lw        $a1, ($s0)
/* CE3EF4 80240804 26100004 */  addiu     $s0, $s0, 4
/* CE3EF8 80240808 0C0B210B */  jal       get_float_variable
/* CE3EFC 8024080C 0240202D */   daddu    $a0, $s2, $zero
/* CE3F00 80240810 8E050000 */  lw        $a1, ($s0)
/* CE3F04 80240814 26100004 */  addiu     $s0, $s0, 4
/* CE3F08 80240818 0240202D */  daddu     $a0, $s2, $zero
/* CE3F0C 8024081C 0C0B210B */  jal       get_float_variable
/* CE3F10 80240820 46000606 */   mov.s    $f24, $f0
/* CE3F14 80240824 8E050000 */  lw        $a1, ($s0)
/* CE3F18 80240828 26100004 */  addiu     $s0, $s0, 4
/* CE3F1C 8024082C 0240202D */  daddu     $a0, $s2, $zero
/* CE3F20 80240830 0C0B1EAF */  jal       get_variable
/* CE3F24 80240834 46000506 */   mov.s    $f20, $f0
/* CE3F28 80240838 8E050000 */  lw        $a1, ($s0)
/* CE3F2C 8024083C 26100004 */  addiu     $s0, $s0, 4
/* CE3F30 80240840 0240202D */  daddu     $a0, $s2, $zero
/* CE3F34 80240844 0C0B1EAF */  jal       get_variable
/* CE3F38 80240848 0040882D */   daddu    $s1, $v0, $zero
/* CE3F3C 8024084C 0240202D */  daddu     $a0, $s2, $zero
/* CE3F40 80240850 8E050000 */  lw        $a1, ($s0)
/* CE3F44 80240854 0C0B210B */  jal       get_float_variable
/* CE3F48 80240858 0040802D */   daddu    $s0, $v0, $zero
/* CE3F4C 8024085C 3C014334 */  lui       $at, 0x4334
/* CE3F50 80240860 44811000 */  mtc1      $at, $f2
/* CE3F54 80240864 3C014049 */  lui       $at, 0x4049
/* CE3F58 80240868 34210FD8 */  ori       $at, $at, 0xfd8
/* CE3F5C 8024086C 44812000 */  mtc1      $at, $f4
/* CE3F60 80240870 46020003 */  div.s     $f0, $f0, $f2
/* CE3F64 80240874 46040582 */  mul.s     $f22, $f0, $f4
/* CE3F68 80240878 00000000 */  nop       
/* CE3F6C 8024087C 4618A501 */  sub.s     $f20, $f20, $f24
/* CE3F70 80240880 3C013F00 */  lui       $at, 0x3f00
/* CE3F74 80240884 44810000 */  mtc1      $at, $f0
/* CE3F78 80240888 00000000 */  nop       
/* CE3F7C 8024088C 4600A502 */  mul.s     $f20, $f20, $f0
/* CE3F80 80240890 00000000 */  nop       
/* CE3F84 80240894 12000007 */  beqz      $s0, .L802408B4
/* CE3F88 80240898 0233102A */   slt      $v0, $s1, $s3
/* CE3F8C 8024089C 10400005 */  beqz      $v0, .L802408B4
/* CE3F90 802408A0 0240202D */   daddu    $a0, $s2, $zero
/* CE3F94 802408A4 0220982D */  daddu     $s3, $s1, $zero
/* CE3F98 802408A8 0280282D */  daddu     $a1, $s4, $zero
/* CE3F9C 802408AC 0C0B2026 */  jal       set_variable
/* CE3FA0 802408B0 0220302D */   daddu    $a2, $s1, $zero
.L802408B4:
/* CE3FA4 802408B4 3C014049 */  lui       $at, 0x4049
/* CE3FA8 802408B8 34210FD8 */  ori       $at, $at, 0xfd8
/* CE3FAC 802408BC 44810000 */  mtc1      $at, $f0
/* CE3FB0 802408C0 44936000 */  mtc1      $s3, $f12
/* CE3FB4 802408C4 00000000 */  nop       
/* CE3FB8 802408C8 46806320 */  cvt.s.w   $f12, $f12
/* CE3FBC 802408CC 46006302 */  mul.s     $f12, $f12, $f0
/* CE3FC0 802408D0 00000000 */  nop       
/* CE3FC4 802408D4 44910000 */  mtc1      $s1, $f0
/* CE3FC8 802408D8 00000000 */  nop       
/* CE3FCC 802408DC 46800020 */  cvt.s.w   $f0, $f0
/* CE3FD0 802408E0 46006303 */  div.s     $f12, $f12, $f0
/* CE3FD4 802408E4 0C00A874 */  jal       cos_rad
/* CE3FD8 802408E8 46166300 */   add.s    $f12, $f12, $f22
/* CE3FDC 802408EC 4600A002 */  mul.s     $f0, $f20, $f0
/* CE3FE0 802408F0 00000000 */  nop       
/* CE3FE4 802408F4 4614C080 */  add.s     $f2, $f24, $f20
/* CE3FE8 802408F8 46001081 */  sub.s     $f2, $f2, $f0
/* CE3FEC 802408FC 0240202D */  daddu     $a0, $s2, $zero
/* CE3FF0 80240900 44061000 */  mfc1      $a2, $f2
/* CE3FF4 80240904 0C0B2190 */  jal       set_float_variable
/* CE3FF8 80240908 02A0282D */   daddu    $a1, $s5, $zero
/* CE3FFC 8024090C 8FBF0028 */  lw        $ra, 0x28($sp)
/* CE4000 80240910 8FB50024 */  lw        $s5, 0x24($sp)
/* CE4004 80240914 8FB40020 */  lw        $s4, 0x20($sp)
/* CE4008 80240918 8FB3001C */  lw        $s3, 0x1c($sp)
/* CE400C 8024091C 8FB20018 */  lw        $s2, 0x18($sp)
/* CE4010 80240920 8FB10014 */  lw        $s1, 0x14($sp)
/* CE4014 80240924 8FB00010 */  lw        $s0, 0x10($sp)
/* CE4018 80240928 D7B80040 */  ldc1      $f24, 0x40($sp)
/* CE401C 8024092C D7B60038 */  ldc1      $f22, 0x38($sp)
/* CE4020 80240930 D7B40030 */  ldc1      $f20, 0x30($sp)
/* CE4024 80240934 24020002 */  addiu     $v0, $zero, 2
/* CE4028 80240938 03E00008 */  jr        $ra
/* CE402C 8024093C 27BD0048 */   addiu    $sp, $sp, 0x48
