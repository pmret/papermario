.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181A0_573AC0
/* 573AC0 802181A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 573AC4 802181A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 573AC8 802181A8 0080882D */  daddu     $s1, $a0, $zero
/* 573ACC 802181AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 573AD0 802181B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 573AD4 802181B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 573AD8 802181B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 573ADC 802181BC 8E30000C */  lw        $s0, 0xc($s1)
/* 573AE0 802181C0 8E050000 */  lw        $a1, ($s0)
/* 573AE4 802181C4 0C0B1EAF */  jal       get_variable
/* 573AE8 802181C8 26100004 */   addiu    $s0, $s0, 4
/* 573AEC 802181CC 8E050000 */  lw        $a1, ($s0)
/* 573AF0 802181D0 26100004 */  addiu     $s0, $s0, 4
/* 573AF4 802181D4 0220202D */  daddu     $a0, $s1, $zero
/* 573AF8 802181D8 0C0B1EAF */  jal       get_variable
/* 573AFC 802181DC 0040982D */   daddu    $s3, $v0, $zero
/* 573B00 802181E0 8E050000 */  lw        $a1, ($s0)
/* 573B04 802181E4 26100004 */  addiu     $s0, $s0, 4
/* 573B08 802181E8 0220202D */  daddu     $a0, $s1, $zero
/* 573B0C 802181EC 0C0B1EAF */  jal       get_variable
/* 573B10 802181F0 0040902D */   daddu    $s2, $v0, $zero
/* 573B14 802181F4 0220202D */  daddu     $a0, $s1, $zero
/* 573B18 802181F8 8E050000 */  lw        $a1, ($s0)
/* 573B1C 802181FC 0C0B1EAF */  jal       get_variable
/* 573B20 80218200 0040802D */   daddu    $s0, $v0, $zero
/* 573B24 80218204 44936000 */  mtc1      $s3, $f12
/* 573B28 80218208 00000000 */  nop
/* 573B2C 8021820C 46806320 */  cvt.s.w   $f12, $f12
/* 573B30 80218210 44927000 */  mtc1      $s2, $f14
/* 573B34 80218214 00000000 */  nop
/* 573B38 80218218 468073A0 */  cvt.s.w   $f14, $f14
/* 573B3C 8021821C 44900000 */  mtc1      $s0, $f0
/* 573B40 80218220 00000000 */  nop
/* 573B44 80218224 46800020 */  cvt.s.w   $f0, $f0
/* 573B48 80218228 44060000 */  mfc1      $a2, $f0
/* 573B4C 8021822C 0C0B5D18 */  jal       func_802D7460
/* 573B50 80218230 0040382D */   daddu    $a3, $v0, $zero
/* 573B54 80218234 8FBF0020 */  lw        $ra, 0x20($sp)
/* 573B58 80218238 8FB3001C */  lw        $s3, 0x1c($sp)
/* 573B5C 8021823C 8FB20018 */  lw        $s2, 0x18($sp)
/* 573B60 80218240 8FB10014 */  lw        $s1, 0x14($sp)
/* 573B64 80218244 8FB00010 */  lw        $s0, 0x10($sp)
/* 573B68 80218248 24020002 */  addiu     $v0, $zero, 2
/* 573B6C 8021824C 03E00008 */  jr        $ra
/* 573B70 80218250 27BD0028 */   addiu    $sp, $sp, 0x28
