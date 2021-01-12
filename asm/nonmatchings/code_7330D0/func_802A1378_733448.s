.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1378_733448
/* 733448 802A1378 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 73344C 802A137C AFB1001C */  sw        $s1, 0x1c($sp)
/* 733450 802A1380 0080882D */  daddu     $s1, $a0, $zero
/* 733454 802A1384 AFBF0028 */  sw        $ra, 0x28($sp)
/* 733458 802A1388 AFB30024 */  sw        $s3, 0x24($sp)
/* 73345C 802A138C AFB20020 */  sw        $s2, 0x20($sp)
/* 733460 802A1390 AFB00018 */  sw        $s0, 0x18($sp)
/* 733464 802A1394 8E30000C */  lw        $s0, 0xc($s1)
/* 733468 802A1398 8E050000 */  lw        $a1, ($s0)
/* 73346C 802A139C 0C0B1EAF */  jal       get_variable
/* 733470 802A13A0 26100004 */   addiu    $s0, $s0, 4
/* 733474 802A13A4 8E050000 */  lw        $a1, ($s0)
/* 733478 802A13A8 26100004 */  addiu     $s0, $s0, 4
/* 73347C 802A13AC 0220202D */  daddu     $a0, $s1, $zero
/* 733480 802A13B0 0C0B1EAF */  jal       get_variable
/* 733484 802A13B4 0040982D */   daddu    $s3, $v0, $zero
/* 733488 802A13B8 8E050000 */  lw        $a1, ($s0)
/* 73348C 802A13BC 26100004 */  addiu     $s0, $s0, 4
/* 733490 802A13C0 0220202D */  daddu     $a0, $s1, $zero
/* 733494 802A13C4 0C0B1EAF */  jal       get_variable
/* 733498 802A13C8 0040902D */   daddu    $s2, $v0, $zero
/* 73349C 802A13CC 0220202D */  daddu     $a0, $s1, $zero
/* 7334A0 802A13D0 8E050000 */  lw        $a1, ($s0)
/* 7334A4 802A13D4 0C0B1EAF */  jal       get_variable
/* 7334A8 802A13D8 0040802D */   daddu    $s0, $v0, $zero
/* 7334AC 802A13DC 44930000 */  mtc1      $s3, $f0
/* 7334B0 802A13E0 00000000 */  nop
/* 7334B4 802A13E4 46800020 */  cvt.s.w   $f0, $f0
/* 7334B8 802A13E8 44050000 */  mfc1      $a1, $f0
/* 7334BC 802A13EC 44920000 */  mtc1      $s2, $f0
/* 7334C0 802A13F0 00000000 */  nop
/* 7334C4 802A13F4 46800020 */  cvt.s.w   $f0, $f0
/* 7334C8 802A13F8 44060000 */  mfc1      $a2, $f0
/* 7334CC 802A13FC 44900000 */  mtc1      $s0, $f0
/* 7334D0 802A1400 00000000 */  nop
/* 7334D4 802A1404 46800020 */  cvt.s.w   $f0, $f0
/* 7334D8 802A1408 44070000 */  mfc1      $a3, $f0
/* 7334DC 802A140C 0000202D */  daddu     $a0, $zero, $zero
/* 7334E0 802A1410 0C01C424 */  jal       func_80071090
/* 7334E4 802A1414 AFA20010 */   sw       $v0, 0x10($sp)
/* 7334E8 802A1418 8FBF0028 */  lw        $ra, 0x28($sp)
/* 7334EC 802A141C 8FB30024 */  lw        $s3, 0x24($sp)
/* 7334F0 802A1420 8FB20020 */  lw        $s2, 0x20($sp)
/* 7334F4 802A1424 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7334F8 802A1428 8FB00018 */  lw        $s0, 0x18($sp)
/* 7334FC 802A142C 24020002 */  addiu     $v0, $zero, 2
/* 733500 802A1430 03E00008 */  jr        $ra
/* 733504 802A1434 27BD0030 */   addiu    $sp, $sp, 0x30
