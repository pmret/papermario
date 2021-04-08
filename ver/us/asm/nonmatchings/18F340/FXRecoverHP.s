.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel FXRecoverHP
/* 190488 80261BA8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 19048C 80261BAC AFB1001C */  sw        $s1, 0x1c($sp)
/* 190490 80261BB0 0080882D */  daddu     $s1, $a0, $zero
/* 190494 80261BB4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 190498 80261BB8 AFB30024 */  sw        $s3, 0x24($sp)
/* 19049C 80261BBC AFB20020 */  sw        $s2, 0x20($sp)
/* 1904A0 80261BC0 AFB00018 */  sw        $s0, 0x18($sp)
/* 1904A4 80261BC4 8E30000C */  lw        $s0, 0xc($s1)
/* 1904A8 80261BC8 8E050000 */  lw        $a1, ($s0)
/* 1904AC 80261BCC 0C0B1EAF */  jal       get_variable
/* 1904B0 80261BD0 26100004 */   addiu    $s0, $s0, 4
/* 1904B4 80261BD4 8E050000 */  lw        $a1, ($s0)
/* 1904B8 80261BD8 26100004 */  addiu     $s0, $s0, 4
/* 1904BC 80261BDC 0220202D */  daddu     $a0, $s1, $zero
/* 1904C0 80261BE0 0C0B1EAF */  jal       get_variable
/* 1904C4 80261BE4 0040982D */   daddu    $s3, $v0, $zero
/* 1904C8 80261BE8 8E050000 */  lw        $a1, ($s0)
/* 1904CC 80261BEC 26100004 */  addiu     $s0, $s0, 4
/* 1904D0 80261BF0 0220202D */  daddu     $a0, $s1, $zero
/* 1904D4 80261BF4 0C0B1EAF */  jal       get_variable
/* 1904D8 80261BF8 0040902D */   daddu    $s2, $v0, $zero
/* 1904DC 80261BFC 0220202D */  daddu     $a0, $s1, $zero
/* 1904E0 80261C00 8E050000 */  lw        $a1, ($s0)
/* 1904E4 80261C04 0C0B1EAF */  jal       get_variable
/* 1904E8 80261C08 0040802D */   daddu    $s0, $v0, $zero
/* 1904EC 80261C0C 44930000 */  mtc1      $s3, $f0
/* 1904F0 80261C10 00000000 */  nop
/* 1904F4 80261C14 46800020 */  cvt.s.w   $f0, $f0
/* 1904F8 80261C18 44050000 */  mfc1      $a1, $f0
/* 1904FC 80261C1C 44920000 */  mtc1      $s2, $f0
/* 190500 80261C20 00000000 */  nop
/* 190504 80261C24 46800020 */  cvt.s.w   $f0, $f0
/* 190508 80261C28 44060000 */  mfc1      $a2, $f0
/* 19050C 80261C2C 44900000 */  mtc1      $s0, $f0
/* 190510 80261C30 00000000 */  nop
/* 190514 80261C34 46800020 */  cvt.s.w   $f0, $f0
/* 190518 80261C38 44070000 */  mfc1      $a3, $f0
/* 19051C 80261C3C 0000202D */  daddu     $a0, $zero, $zero
/* 190520 80261C40 0C01C424 */  jal       func_80071090
/* 190524 80261C44 AFA20010 */   sw       $v0, 0x10($sp)
/* 190528 80261C48 8FBF0028 */  lw        $ra, 0x28($sp)
/* 19052C 80261C4C 8FB30024 */  lw        $s3, 0x24($sp)
/* 190530 80261C50 8FB20020 */  lw        $s2, 0x20($sp)
/* 190534 80261C54 8FB1001C */  lw        $s1, 0x1c($sp)
/* 190538 80261C58 8FB00018 */  lw        $s0, 0x18($sp)
/* 19053C 80261C5C 24020002 */  addiu     $v0, $zero, 2
/* 190540 80261C60 03E00008 */  jr        $ra
/* 190544 80261C64 27BD0030 */   addiu    $sp, $sp, 0x30
