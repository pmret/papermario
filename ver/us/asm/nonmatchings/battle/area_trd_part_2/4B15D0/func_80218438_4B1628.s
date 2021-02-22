.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218438_4B1628
/* 4B1628 80218438 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B162C 8021843C AFB10014 */  sw        $s1, 0x14($sp)
/* 4B1630 80218440 0080882D */  daddu     $s1, $a0, $zero
/* 4B1634 80218444 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4B1638 80218448 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4B163C 8021844C AFB20018 */  sw        $s2, 0x18($sp)
/* 4B1640 80218450 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1644 80218454 8E30000C */  lw        $s0, 0xc($s1)
/* 4B1648 80218458 8E050000 */  lw        $a1, ($s0)
/* 4B164C 8021845C 0C0B1EAF */  jal       get_variable
/* 4B1650 80218460 26100004 */   addiu    $s0, $s0, 4
/* 4B1654 80218464 8E050000 */  lw        $a1, ($s0)
/* 4B1658 80218468 26100004 */  addiu     $s0, $s0, 4
/* 4B165C 8021846C 0220202D */  daddu     $a0, $s1, $zero
/* 4B1660 80218470 0C0B1EAF */  jal       get_variable
/* 4B1664 80218474 0040982D */   daddu    $s3, $v0, $zero
/* 4B1668 80218478 8E050000 */  lw        $a1, ($s0)
/* 4B166C 8021847C 26100004 */  addiu     $s0, $s0, 4
/* 4B1670 80218480 0220202D */  daddu     $a0, $s1, $zero
/* 4B1674 80218484 0C0B1EAF */  jal       get_variable
/* 4B1678 80218488 0040902D */   daddu    $s2, $v0, $zero
/* 4B167C 8021848C 0220202D */  daddu     $a0, $s1, $zero
/* 4B1680 80218490 8E050000 */  lw        $a1, ($s0)
/* 4B1684 80218494 0C0B1EAF */  jal       get_variable
/* 4B1688 80218498 0040802D */   daddu    $s0, $v0, $zero
/* 4B168C 8021849C 24040006 */  addiu     $a0, $zero, 6
/* 4B1690 802184A0 3C058023 */  lui       $a1, %hi(D_80236040)
/* 4B1694 802184A4 24A56040 */  addiu     $a1, $a1, %lo(D_80236040)
/* 4B1698 802184A8 44930000 */  mtc1      $s3, $f0
/* 4B169C 802184AC 00000000 */  nop
/* 4B16A0 802184B0 46800020 */  cvt.s.w   $f0, $f0
/* 4B16A4 802184B4 E4A00028 */  swc1      $f0, 0x28($a1)
/* 4B16A8 802184B8 44920000 */  mtc1      $s2, $f0
/* 4B16AC 802184BC 00000000 */  nop
/* 4B16B0 802184C0 46800020 */  cvt.s.w   $f0, $f0
/* 4B16B4 802184C4 0040382D */  daddu     $a3, $v0, $zero
/* 4B16B8 802184C8 3C014120 */  lui       $at, 0x4120
/* 4B16BC 802184CC 44811000 */  mtc1      $at, $f2
/* 4B16C0 802184D0 3C063F80 */  lui       $a2, 0x3f80
/* 4B16C4 802184D4 46020001 */  sub.s     $f0, $f0, $f2
/* 4B16C8 802184D8 44901000 */  mtc1      $s0, $f2
/* 4B16CC 802184DC 00000000 */  nop
/* 4B16D0 802184E0 468010A0 */  cvt.s.w   $f2, $f2
/* 4B16D4 802184E4 E4A20030 */  swc1      $f2, 0x30($a1)
/* 4B16D8 802184E8 0C01C4B4 */  jal       func_800712D0
/* 4B16DC 802184EC E4A0002C */   swc1     $f0, 0x2c($a1)
/* 4B16E0 802184F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4B16E4 802184F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4B16E8 802184F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 4B16EC 802184FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B16F0 80218500 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B16F4 80218504 24020002 */  addiu     $v0, $zero, 2
/* 4B16F8 80218508 03E00008 */  jr        $ra
/* 4B16FC 8021850C 27BD0028 */   addiu    $sp, $sp, 0x28
