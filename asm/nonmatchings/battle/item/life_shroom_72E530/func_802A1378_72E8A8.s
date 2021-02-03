.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1378_72E8A8
/* 72E8A8 802A1378 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 72E8AC 802A137C AFB1001C */  sw        $s1, 0x1c($sp)
/* 72E8B0 802A1380 0080882D */  daddu     $s1, $a0, $zero
/* 72E8B4 802A1384 AFBF0028 */  sw        $ra, 0x28($sp)
/* 72E8B8 802A1388 AFB30024 */  sw        $s3, 0x24($sp)
/* 72E8BC 802A138C AFB20020 */  sw        $s2, 0x20($sp)
/* 72E8C0 802A1390 AFB00018 */  sw        $s0, 0x18($sp)
/* 72E8C4 802A1394 8E30000C */  lw        $s0, 0xc($s1)
/* 72E8C8 802A1398 8E050000 */  lw        $a1, ($s0)
/* 72E8CC 802A139C 0C0B1EAF */  jal       get_variable
/* 72E8D0 802A13A0 26100004 */   addiu    $s0, $s0, 4
/* 72E8D4 802A13A4 8E050000 */  lw        $a1, ($s0)
/* 72E8D8 802A13A8 26100004 */  addiu     $s0, $s0, 4
/* 72E8DC 802A13AC 0220202D */  daddu     $a0, $s1, $zero
/* 72E8E0 802A13B0 0C0B1EAF */  jal       get_variable
/* 72E8E4 802A13B4 0040982D */   daddu    $s3, $v0, $zero
/* 72E8E8 802A13B8 8E050000 */  lw        $a1, ($s0)
/* 72E8EC 802A13BC 26100004 */  addiu     $s0, $s0, 4
/* 72E8F0 802A13C0 0220202D */  daddu     $a0, $s1, $zero
/* 72E8F4 802A13C4 0C0B1EAF */  jal       get_variable
/* 72E8F8 802A13C8 0040902D */   daddu    $s2, $v0, $zero
/* 72E8FC 802A13CC 0220202D */  daddu     $a0, $s1, $zero
/* 72E900 802A13D0 8E050000 */  lw        $a1, ($s0)
/* 72E904 802A13D4 0C0B1EAF */  jal       get_variable
/* 72E908 802A13D8 0040802D */   daddu    $s0, $v0, $zero
/* 72E90C 802A13DC 44930000 */  mtc1      $s3, $f0
/* 72E910 802A13E0 00000000 */  nop
/* 72E914 802A13E4 46800020 */  cvt.s.w   $f0, $f0
/* 72E918 802A13E8 44050000 */  mfc1      $a1, $f0
/* 72E91C 802A13EC 44920000 */  mtc1      $s2, $f0
/* 72E920 802A13F0 00000000 */  nop
/* 72E924 802A13F4 46800020 */  cvt.s.w   $f0, $f0
/* 72E928 802A13F8 44060000 */  mfc1      $a2, $f0
/* 72E92C 802A13FC 44900000 */  mtc1      $s0, $f0
/* 72E930 802A1400 00000000 */  nop
/* 72E934 802A1404 46800020 */  cvt.s.w   $f0, $f0
/* 72E938 802A1408 44070000 */  mfc1      $a3, $f0
/* 72E93C 802A140C 0000202D */  daddu     $a0, $zero, $zero
/* 72E940 802A1410 0C01C424 */  jal       func_80071090
/* 72E944 802A1414 AFA20010 */   sw       $v0, 0x10($sp)
/* 72E948 802A1418 8FBF0028 */  lw        $ra, 0x28($sp)
/* 72E94C 802A141C 8FB30024 */  lw        $s3, 0x24($sp)
/* 72E950 802A1420 8FB20020 */  lw        $s2, 0x20($sp)
/* 72E954 802A1424 8FB1001C */  lw        $s1, 0x1c($sp)
/* 72E958 802A1428 8FB00018 */  lw        $s0, 0x18($sp)
/* 72E95C 802A142C 24020002 */  addiu     $v0, $zero, 2
/* 72E960 802A1430 03E00008 */  jr        $ra
/* 72E964 802A1434 27BD0030 */   addiu    $sp, $sp, 0x30
