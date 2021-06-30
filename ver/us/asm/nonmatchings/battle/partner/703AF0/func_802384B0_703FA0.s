.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802384B0_703FA0
/* 703FA0 802384B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 703FA4 802384B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 703FA8 802384B8 0080882D */  daddu     $s1, $a0, $zero
/* 703FAC 802384BC AFBF0024 */  sw        $ra, 0x24($sp)
/* 703FB0 802384C0 AFB20020 */  sw        $s2, 0x20($sp)
/* 703FB4 802384C4 AFB00018 */  sw        $s0, 0x18($sp)
/* 703FB8 802384C8 8E30000C */  lw        $s0, 0xc($s1)
/* 703FBC 802384CC 8E050000 */  lw        $a1, ($s0)
/* 703FC0 802384D0 0C0B1EAF */  jal       get_variable
/* 703FC4 802384D4 26100004 */   addiu    $s0, $s0, 4
/* 703FC8 802384D8 8E050000 */  lw        $a1, ($s0)
/* 703FCC 802384DC 26100004 */  addiu     $s0, $s0, 4
/* 703FD0 802384E0 0220202D */  daddu     $a0, $s1, $zero
/* 703FD4 802384E4 0C0B1EAF */  jal       get_variable
/* 703FD8 802384E8 0040902D */   daddu    $s2, $v0, $zero
/* 703FDC 802384EC 0220202D */  daddu     $a0, $s1, $zero
/* 703FE0 802384F0 8E050000 */  lw        $a1, ($s0)
/* 703FE4 802384F4 0C0B1EAF */  jal       get_variable
/* 703FE8 802384F8 0040802D */   daddu    $s0, $v0, $zero
/* 703FEC 802384FC 24040008 */  addiu     $a0, $zero, 8
/* 703FF0 80238500 44921000 */  mtc1      $s2, $f2
/* 703FF4 80238504 00000000 */  nop
/* 703FF8 80238508 468010A0 */  cvt.s.w   $f2, $f2
/* 703FFC 8023850C 44051000 */  mfc1      $a1, $f2
/* 704000 80238510 44901000 */  mtc1      $s0, $f2
/* 704004 80238514 00000000 */  nop
/* 704008 80238518 468010A0 */  cvt.s.w   $f2, $f2
/* 70400C 8023851C 44061000 */  mfc1      $a2, $f2
/* 704010 80238520 44821000 */  mtc1      $v0, $f2
/* 704014 80238524 00000000 */  nop
/* 704018 80238528 468010A0 */  cvt.s.w   $f2, $f2
/* 70401C 8023852C 3C013FA6 */  lui       $at, 0x3fa6
/* 704020 80238530 34216666 */  ori       $at, $at, 0x6666
/* 704024 80238534 44810000 */  mtc1      $at, $f0
/* 704028 80238538 44071000 */  mfc1      $a3, $f2
/* 70402C 8023853C 24030037 */  addiu     $v1, $zero, 0x37
/* 704030 80238540 AFA30014 */  sw        $v1, 0x14($sp)
/* 704034 80238544 0C01C2EC */  jal       playFX_33
/* 704038 80238548 E7A00010 */   swc1     $f0, 0x10($sp)
/* 70403C 8023854C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 704040 80238550 8FB20020 */  lw        $s2, 0x20($sp)
/* 704044 80238554 8FB1001C */  lw        $s1, 0x1c($sp)
/* 704048 80238558 8FB00018 */  lw        $s0, 0x18($sp)
/* 70404C 8023855C 3C018024 */  lui       $at, %hi(D_80239A0C_7054FC)
/* 704050 80238560 AC229A0C */  sw        $v0, %lo(D_80239A0C_7054FC)($at)
/* 704054 80238564 24020002 */  addiu     $v0, $zero, 2
/* 704058 80238568 03E00008 */  jr        $ra
/* 70405C 8023856C 27BD0028 */   addiu    $sp, $sp, 0x28
