.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261478
/* 18FD58 80261478 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 18FD5C 8026147C AFB1001C */  sw        $s1, 0x1c($sp)
/* 18FD60 80261480 0080882D */  daddu     $s1, $a0, $zero
/* 18FD64 80261484 AFBF0024 */  sw        $ra, 0x24($sp)
/* 18FD68 80261488 AFB20020 */  sw        $s2, 0x20($sp)
/* 18FD6C 8026148C AFB00018 */  sw        $s0, 0x18($sp)
/* 18FD70 80261490 8E30000C */  lw        $s0, 0xc($s1)
/* 18FD74 80261494 8E050000 */  lw        $a1, ($s0)
/* 18FD78 80261498 0C0B1EAF */  jal       get_variable
/* 18FD7C 8026149C 26100004 */   addiu    $s0, $s0, 4
/* 18FD80 802614A0 8E050000 */  lw        $a1, ($s0)
/* 18FD84 802614A4 26100004 */  addiu     $s0, $s0, 4
/* 18FD88 802614A8 0220202D */  daddu     $a0, $s1, $zero
/* 18FD8C 802614AC 0C0B1EAF */  jal       get_variable
/* 18FD90 802614B0 0040902D */   daddu    $s2, $v0, $zero
/* 18FD94 802614B4 0220202D */  daddu     $a0, $s1, $zero
/* 18FD98 802614B8 8E050000 */  lw        $a1, ($s0)
/* 18FD9C 802614BC 0C0B1EAF */  jal       get_variable
/* 18FDA0 802614C0 0040802D */   daddu    $s0, $v0, $zero
/* 18FDA4 802614C4 44921000 */  mtc1      $s2, $f2
/* 18FDA8 802614C8 00000000 */  nop
/* 18FDAC 802614CC 468010A0 */  cvt.s.w   $f2, $f2
/* 18FDB0 802614D0 2403000F */  addiu     $v1, $zero, 0xf
/* 18FDB4 802614D4 02038021 */  addu      $s0, $s0, $v1
/* 18FDB8 802614D8 44051000 */  mfc1      $a1, $f2
/* 18FDBC 802614DC 44901000 */  mtc1      $s0, $f2
/* 18FDC0 802614E0 00000000 */  nop
/* 18FDC4 802614E4 468010A0 */  cvt.s.w   $f2, $f2
/* 18FDC8 802614E8 44061000 */  mfc1      $a2, $f2
/* 18FDCC 802614EC 44821000 */  mtc1      $v0, $f2
/* 18FDD0 802614F0 00000000 */  nop
/* 18FDD4 802614F4 468010A0 */  cvt.s.w   $f2, $f2
/* 18FDD8 802614F8 3C0140A0 */  lui       $at, 0x40a0
/* 18FDDC 802614FC 44810000 */  mtc1      $at, $f0
/* 18FDE0 80261500 44071000 */  mfc1      $a3, $f2
/* 18FDE4 80261504 24040009 */  addiu     $a0, $zero, 9
/* 18FDE8 80261508 AFA30014 */  sw        $v1, 0x14($sp)
/* 18FDEC 8026150C 0C01C5D4 */  jal       func_80071750
/* 18FDF0 80261510 E7A00010 */   swc1     $f0, 0x10($sp)
/* 18FDF4 80261514 8FBF0024 */  lw        $ra, 0x24($sp)
/* 18FDF8 80261518 8FB20020 */  lw        $s2, 0x20($sp)
/* 18FDFC 8026151C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18FE00 80261520 8FB00018 */  lw        $s0, 0x18($sp)
/* 18FE04 80261524 24020002 */  addiu     $v0, $zero, 2
/* 18FE08 80261528 03E00008 */  jr        $ra
/* 18FE0C 8026152C 27BD0028 */   addiu    $sp, $sp, 0x28
