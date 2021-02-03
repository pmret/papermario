.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1378_715BC8
/* 715BC8 802A1378 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 715BCC 802A137C AFB1001C */  sw        $s1, 0x1c($sp)
/* 715BD0 802A1380 0080882D */  daddu     $s1, $a0, $zero
/* 715BD4 802A1384 AFBF0028 */  sw        $ra, 0x28($sp)
/* 715BD8 802A1388 AFB30024 */  sw        $s3, 0x24($sp)
/* 715BDC 802A138C AFB20020 */  sw        $s2, 0x20($sp)
/* 715BE0 802A1390 AFB00018 */  sw        $s0, 0x18($sp)
/* 715BE4 802A1394 8E30000C */  lw        $s0, 0xc($s1)
/* 715BE8 802A1398 8E050000 */  lw        $a1, ($s0)
/* 715BEC 802A139C 0C0B1EAF */  jal       get_variable
/* 715BF0 802A13A0 26100004 */   addiu    $s0, $s0, 4
/* 715BF4 802A13A4 8E050000 */  lw        $a1, ($s0)
/* 715BF8 802A13A8 26100004 */  addiu     $s0, $s0, 4
/* 715BFC 802A13AC 0220202D */  daddu     $a0, $s1, $zero
/* 715C00 802A13B0 0C0B1EAF */  jal       get_variable
/* 715C04 802A13B4 0040982D */   daddu    $s3, $v0, $zero
/* 715C08 802A13B8 8E050000 */  lw        $a1, ($s0)
/* 715C0C 802A13BC 26100004 */  addiu     $s0, $s0, 4
/* 715C10 802A13C0 0220202D */  daddu     $a0, $s1, $zero
/* 715C14 802A13C4 0C0B1EAF */  jal       get_variable
/* 715C18 802A13C8 0040902D */   daddu    $s2, $v0, $zero
/* 715C1C 802A13CC 0220202D */  daddu     $a0, $s1, $zero
/* 715C20 802A13D0 8E050000 */  lw        $a1, ($s0)
/* 715C24 802A13D4 0C0B1EAF */  jal       get_variable
/* 715C28 802A13D8 0040802D */   daddu    $s0, $v0, $zero
/* 715C2C 802A13DC 44930000 */  mtc1      $s3, $f0
/* 715C30 802A13E0 00000000 */  nop
/* 715C34 802A13E4 46800020 */  cvt.s.w   $f0, $f0
/* 715C38 802A13E8 44050000 */  mfc1      $a1, $f0
/* 715C3C 802A13EC 44920000 */  mtc1      $s2, $f0
/* 715C40 802A13F0 00000000 */  nop
/* 715C44 802A13F4 46800020 */  cvt.s.w   $f0, $f0
/* 715C48 802A13F8 44060000 */  mfc1      $a2, $f0
/* 715C4C 802A13FC 44900000 */  mtc1      $s0, $f0
/* 715C50 802A1400 00000000 */  nop
/* 715C54 802A1404 46800020 */  cvt.s.w   $f0, $f0
/* 715C58 802A1408 44070000 */  mfc1      $a3, $f0
/* 715C5C 802A140C 0000202D */  daddu     $a0, $zero, $zero
/* 715C60 802A1410 0C01C424 */  jal       func_80071090
/* 715C64 802A1414 AFA20010 */   sw       $v0, 0x10($sp)
/* 715C68 802A1418 8FBF0028 */  lw        $ra, 0x28($sp)
/* 715C6C 802A141C 8FB30024 */  lw        $s3, 0x24($sp)
/* 715C70 802A1420 8FB20020 */  lw        $s2, 0x20($sp)
/* 715C74 802A1424 8FB1001C */  lw        $s1, 0x1c($sp)
/* 715C78 802A1428 8FB00018 */  lw        $s0, 0x18($sp)
/* 715C7C 802A142C 24020002 */  addiu     $v0, $zero, 2
/* 715C80 802A1430 03E00008 */  jr        $ra
/* 715C84 802A1434 27BD0030 */   addiu    $sp, $sp, 0x30
