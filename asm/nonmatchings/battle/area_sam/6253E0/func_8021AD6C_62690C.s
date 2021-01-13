.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021AD6C_62690C
/* 62690C 8021AD6C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 626910 8021AD70 AFB10014 */  sw        $s1, 0x14($sp)
/* 626914 8021AD74 0080882D */  daddu     $s1, $a0, $zero
/* 626918 8021AD78 AFBF0020 */  sw        $ra, 0x20($sp)
/* 62691C 8021AD7C AFB3001C */  sw        $s3, 0x1c($sp)
/* 626920 8021AD80 AFB20018 */  sw        $s2, 0x18($sp)
/* 626924 8021AD84 AFB00010 */  sw        $s0, 0x10($sp)
/* 626928 8021AD88 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 62692C 8021AD8C 8E30000C */  lw        $s0, 0xc($s1)
/* 626930 8021AD90 8E050000 */  lw        $a1, ($s0)
/* 626934 8021AD94 0C0B1EAF */  jal       get_variable
/* 626938 8021AD98 26100004 */   addiu    $s0, $s0, 4
/* 62693C 8021AD9C 3C036666 */  lui       $v1, 0x6666
/* 626940 8021ADA0 34636667 */  ori       $v1, $v1, 0x6667
/* 626944 8021ADA4 00430018 */  mult      $v0, $v1
/* 626948 8021ADA8 000217C3 */  sra       $v0, $v0, 0x1f
/* 62694C 8021ADAC 3C0140C9 */  lui       $at, 0x40c9
/* 626950 8021ADB0 34210FD0 */  ori       $at, $at, 0xfd0
/* 626954 8021ADB4 44810000 */  mtc1      $at, $f0
/* 626958 8021ADB8 00003810 */  mfhi      $a3
/* 62695C 8021ADBC 00071883 */  sra       $v1, $a3, 2
/* 626960 8021ADC0 00621823 */  subu      $v1, $v1, $v0
/* 626964 8021ADC4 44836000 */  mtc1      $v1, $f12
/* 626968 8021ADC8 00000000 */  nop
/* 62696C 8021ADCC 46806320 */  cvt.s.w   $f12, $f12
/* 626970 8021ADD0 46006302 */  mul.s     $f12, $f12, $f0
/* 626974 8021ADD4 00000000 */  nop
/* 626978 8021ADD8 3C0143B4 */  lui       $at, 0x43b4
/* 62697C 8021ADDC 44810000 */  mtc1      $at, $f0
/* 626980 8021ADE0 3C014100 */  lui       $at, 0x4100
/* 626984 8021ADE4 44811000 */  mtc1      $at, $f2
/* 626988 8021ADE8 46006303 */  div.s     $f12, $f12, $f0
/* 62698C 8021ADEC 46026302 */  mul.s     $f12, $f12, $f2
/* 626990 8021ADF0 00000000 */  nop
/* 626994 8021ADF4 8E120000 */  lw        $s2, ($s0)
/* 626998 8021ADF8 26100004 */  addiu     $s0, $s0, 4
/* 62699C 8021ADFC 8E130000 */  lw        $s3, ($s0)
/* 6269A0 8021AE00 0C00A85B */  jal       sin_rad
/* 6269A4 8021AE04 8E100004 */   lw       $s0, 4($s0)
/* 6269A8 8021AE08 0220202D */  daddu     $a0, $s1, $zero
/* 6269AC 8021AE0C 3C014120 */  lui       $at, 0x4120
/* 6269B0 8021AE10 44811000 */  mtc1      $at, $f2
/* 6269B4 8021AE14 0240282D */  daddu     $a1, $s2, $zero
/* 6269B8 8021AE18 46020502 */  mul.s     $f20, $f0, $f2
/* 6269BC 8021AE1C 00000000 */  nop
/* 6269C0 8021AE20 0C0B2026 */  jal       set_variable
/* 6269C4 8021AE24 0000302D */   daddu    $a2, $zero, $zero
/* 6269C8 8021AE28 0220202D */  daddu     $a0, $s1, $zero
/* 6269CC 8021AE2C 4600A10D */  trunc.w.s $f4, $f20
/* 6269D0 8021AE30 44062000 */  mfc1      $a2, $f4
/* 6269D4 8021AE34 0C0B2026 */  jal       set_variable
/* 6269D8 8021AE38 0260282D */   daddu    $a1, $s3, $zero
/* 6269DC 8021AE3C 0220202D */  daddu     $a0, $s1, $zero
/* 6269E0 8021AE40 0200282D */  daddu     $a1, $s0, $zero
/* 6269E4 8021AE44 0C0B2026 */  jal       set_variable
/* 6269E8 8021AE48 0000302D */   daddu    $a2, $zero, $zero
/* 6269EC 8021AE4C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6269F0 8021AE50 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6269F4 8021AE54 8FB20018 */  lw        $s2, 0x18($sp)
/* 6269F8 8021AE58 8FB10014 */  lw        $s1, 0x14($sp)
/* 6269FC 8021AE5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 626A00 8021AE60 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 626A04 8021AE64 24020002 */  addiu     $v0, $zero, 2
/* 626A08 8021AE68 03E00008 */  jr        $ra
/* 626A0C 8021AE6C 27BD0030 */   addiu    $sp, $sp, 0x30
