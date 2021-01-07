.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802190B0_5B2560
/* 5B2560 802190B0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5B2564 802190B4 AFB10024 */  sw        $s1, 0x24($sp)
/* 5B2568 802190B8 0080882D */  daddu     $s1, $a0, $zero
/* 5B256C 802190BC AFBF0028 */  sw        $ra, 0x28($sp)
/* 5B2570 802190C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 5B2574 802190C4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5B2578 802190C8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5B257C 802190CC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5B2580 802190D0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5B2584 802190D4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5B2588 802190D8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5B258C 802190DC 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2590 802190E0 8E050000 */  lw        $a1, ($s0)
/* 5B2594 802190E4 0C0B210B */  jal       get_float_variable
/* 5B2598 802190E8 26100004 */   addiu    $s0, $s0, 4
/* 5B259C 802190EC 8E050000 */  lw        $a1, ($s0)
/* 5B25A0 802190F0 26100004 */  addiu     $s0, $s0, 4
/* 5B25A4 802190F4 0220202D */  daddu     $a0, $s1, $zero
/* 5B25A8 802190F8 0C0B210B */  jal       get_float_variable
/* 5B25AC 802190FC 46000786 */   mov.s    $f30, $f0
/* 5B25B0 80219100 8E050000 */  lw        $a1, ($s0)
/* 5B25B4 80219104 26100004 */  addiu     $s0, $s0, 4
/* 5B25B8 80219108 0220202D */  daddu     $a0, $s1, $zero
/* 5B25BC 8021910C 0C0B210B */  jal       get_float_variable
/* 5B25C0 80219110 46000506 */   mov.s    $f20, $f0
/* 5B25C4 80219114 8E050000 */  lw        $a1, ($s0)
/* 5B25C8 80219118 26100004 */  addiu     $s0, $s0, 4
/* 5B25CC 8021911C 0220202D */  daddu     $a0, $s1, $zero
/* 5B25D0 80219120 0C0B210B */  jal       get_float_variable
/* 5B25D4 80219124 46000706 */   mov.s    $f28, $f0
/* 5B25D8 80219128 8E050000 */  lw        $a1, ($s0)
/* 5B25DC 8021912C 26100004 */  addiu     $s0, $s0, 4
/* 5B25E0 80219130 0220202D */  daddu     $a0, $s1, $zero
/* 5B25E4 80219134 0C0B210B */  jal       get_float_variable
/* 5B25E8 80219138 46000686 */   mov.s    $f26, $f0
/* 5B25EC 8021913C 8E050000 */  lw        $a1, ($s0)
/* 5B25F0 80219140 26100004 */  addiu     $s0, $s0, 4
/* 5B25F4 80219144 0220202D */  daddu     $a0, $s1, $zero
/* 5B25F8 80219148 0C0B210B */  jal       get_float_variable
/* 5B25FC 8021914C 46000606 */   mov.s    $f24, $f0
/* 5B2600 80219150 0220202D */  daddu     $a0, $s1, $zero
/* 5B2604 80219154 8E050000 */  lw        $a1, ($s0)
/* 5B2608 80219158 0C0B1EAF */  jal       get_variable
/* 5B260C 8021915C 46000586 */   mov.s    $f22, $f0
/* 5B2610 80219160 8E240148 */  lw        $a0, 0x148($s1)
/* 5B2614 80219164 0C09A75B */  jal       get_actor
/* 5B2618 80219168 0040802D */   daddu    $s0, $v0, $zero
/* 5B261C 8021916C 4600A521 */  cvt.d.s   $f20, $f20
/* 5B2620 80219170 4405F000 */  mfc1      $a1, $f30
/* 5B2624 80219174 3C014014 */  lui       $at, 0x4014
/* 5B2628 80219178 44810800 */  mtc1      $at, $f1
/* 5B262C 8021917C 44800000 */  mtc1      $zero, $f0
/* 5B2630 80219180 4407E000 */  mfc1      $a3, $f28
/* 5B2634 80219184 4620A500 */  add.d     $f20, $f20, $f0
/* 5B2638 80219188 0000202D */  daddu     $a0, $zero, $zero
/* 5B263C 8021918C AFB0001C */  sw        $s0, 0x1c($sp)
/* 5B2640 80219190 4620A520 */  cvt.s.d   $f20, $f20
/* 5B2644 80219194 4406A000 */  mfc1      $a2, $f20
/* 5B2648 80219198 0040802D */  daddu     $s0, $v0, $zero
/* 5B264C 8021919C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 5B2650 802191A0 E7B80014 */  swc1      $f24, 0x14($sp)
/* 5B2654 802191A4 0C01BFD4 */  jal       func_8006FF50
/* 5B2658 802191A8 E7B60018 */   swc1     $f22, 0x18($sp)
/* 5B265C 802191AC 0040202D */  daddu     $a0, $v0, $zero
/* 5B2660 802191B0 82030210 */  lb        $v1, 0x210($s0)
/* 5B2664 802191B4 2402000A */  addiu     $v0, $zero, 0xa
/* 5B2668 802191B8 14620007 */  bne       $v1, $v0, .L802191D8
/* 5B266C 802191BC 00000000 */   nop      
/* 5B2670 802191C0 8C82000C */  lw        $v0, 0xc($a0)
/* 5B2674 802191C4 3C013ECC */  lui       $at, 0x3ecc
/* 5B2678 802191C8 3421CCCD */  ori       $at, $at, 0xcccd
/* 5B267C 802191CC 44810000 */  mtc1      $at, $f0
/* 5B2680 802191D0 00000000 */  nop       
/* 5B2684 802191D4 E4400028 */  swc1      $f0, 0x28($v0)
.L802191D8:
/* 5B2688 802191D8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B268C 802191DC 8FB10024 */  lw        $s1, 0x24($sp)
/* 5B2690 802191E0 8FB00020 */  lw        $s0, 0x20($sp)
/* 5B2694 802191E4 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5B2698 802191E8 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5B269C 802191EC D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5B26A0 802191F0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5B26A4 802191F4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5B26A8 802191F8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5B26AC 802191FC 24020002 */  addiu     $v0, $zero, 2
/* 5B26B0 80219200 03E00008 */  jr        $ra
/* 5B26B4 80219204 27BD0060 */   addiu    $sp, $sp, 0x60
