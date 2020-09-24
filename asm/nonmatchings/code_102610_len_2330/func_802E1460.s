.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1460
/* 102CE0 802E1460 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 102CE4 802E1464 AFB10014 */  sw        $s1, 0x14($sp)
/* 102CE8 802E1468 0080882D */  daddu     $s1, $a0, $zero
/* 102CEC 802E146C AFBF0018 */  sw        $ra, 0x18($sp)
/* 102CF0 802E1470 AFB00010 */  sw        $s0, 0x10($sp)
/* 102CF4 802E1474 8E300040 */  lw        $s0, 0x40($s1)
/* 102CF8 802E1478 96020022 */  lhu       $v0, 0x22($s0)
/* 102CFC 802E147C 2443FFFF */  addiu     $v1, $v0, -1
/* 102D00 802E1480 3042FFFF */  andi      $v0, $v0, 0xffff
/* 102D04 802E1484 10400009 */  beqz      $v0, .L802E14AC
/* 102D08 802E1488 A6030022 */   sh       $v1, 0x22($s0)
/* 102D0C 802E148C C620004C */  lwc1      $f0, 0x4c($s1)
/* 102D10 802E1490 3C01802F */  lui       $at, 0x802f
/* 102D14 802E1494 D422B000 */  ldc1      $f2, -0x5000($at)
/* 102D18 802E1498 46000021 */  cvt.d.s   $f0, $f0
/* 102D1C 802E149C 46220001 */  sub.d     $f0, $f0, $f2
/* 102D20 802E14A0 46200020 */  cvt.s.d   $f0, $f0
/* 102D24 802E14A4 080B8531 */  j         .L802E14C4
/* 102D28 802E14A8 E620004C */   swc1     $f0, 0x4c($s1)
.L802E14AC:
/* 102D2C 802E14AC 0C04419E */  jal       func_80110678
/* 102D30 802E14B0 0220202D */   daddu    $a0, $s1, $zero
/* 102D34 802E14B4 0C043F5A */  jal       func_8010FD68
/* 102D38 802E14B8 0220202D */   daddu    $a0, $s1, $zero
/* 102D3C 802E14BC 24020008 */  addiu     $v0, $zero, 8
/* 102D40 802E14C0 A6020022 */  sh        $v0, 0x22($s0)
.L802E14C4:
/* 102D44 802E14C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 102D48 802E14C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 102D4C 802E14CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 102D50 802E14D0 03E00008 */  jr        $ra
/* 102D54 802E14D4 27BD0020 */   addiu    $sp, $sp, 0x20
