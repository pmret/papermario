.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218560_5B1A10
/* 5B1A10 80218560 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5B1A14 80218564 AFB10024 */  sw        $s1, 0x24($sp)
/* 5B1A18 80218568 0080882D */  daddu     $s1, $a0, $zero
/* 5B1A1C 8021856C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5B1A20 80218570 AFB00020 */  sw        $s0, 0x20($sp)
/* 5B1A24 80218574 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5B1A28 80218578 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5B1A2C 8021857C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5B1A30 80218580 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5B1A34 80218584 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5B1A38 80218588 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5B1A3C 8021858C 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1A40 80218590 8E050000 */  lw        $a1, ($s0)
/* 5B1A44 80218594 0C0B210B */  jal       get_float_variable
/* 5B1A48 80218598 26100004 */   addiu    $s0, $s0, 4
/* 5B1A4C 8021859C 8E050000 */  lw        $a1, ($s0)
/* 5B1A50 802185A0 26100004 */  addiu     $s0, $s0, 4
/* 5B1A54 802185A4 0220202D */  daddu     $a0, $s1, $zero
/* 5B1A58 802185A8 0C0B210B */  jal       get_float_variable
/* 5B1A5C 802185AC 46000786 */   mov.s    $f30, $f0
/* 5B1A60 802185B0 8E050000 */  lw        $a1, ($s0)
/* 5B1A64 802185B4 26100004 */  addiu     $s0, $s0, 4
/* 5B1A68 802185B8 0220202D */  daddu     $a0, $s1, $zero
/* 5B1A6C 802185BC 0C0B210B */  jal       get_float_variable
/* 5B1A70 802185C0 46000506 */   mov.s    $f20, $f0
/* 5B1A74 802185C4 8E050000 */  lw        $a1, ($s0)
/* 5B1A78 802185C8 26100004 */  addiu     $s0, $s0, 4
/* 5B1A7C 802185CC 0220202D */  daddu     $a0, $s1, $zero
/* 5B1A80 802185D0 0C0B210B */  jal       get_float_variable
/* 5B1A84 802185D4 46000706 */   mov.s    $f28, $f0
/* 5B1A88 802185D8 8E050000 */  lw        $a1, ($s0)
/* 5B1A8C 802185DC 26100004 */  addiu     $s0, $s0, 4
/* 5B1A90 802185E0 0220202D */  daddu     $a0, $s1, $zero
/* 5B1A94 802185E4 0C0B210B */  jal       get_float_variable
/* 5B1A98 802185E8 46000686 */   mov.s    $f26, $f0
/* 5B1A9C 802185EC 8E050000 */  lw        $a1, ($s0)
/* 5B1AA0 802185F0 26100004 */  addiu     $s0, $s0, 4
/* 5B1AA4 802185F4 0220202D */  daddu     $a0, $s1, $zero
/* 5B1AA8 802185F8 0C0B210B */  jal       get_float_variable
/* 5B1AAC 802185FC 46000606 */   mov.s    $f24, $f0
/* 5B1AB0 80218600 0220202D */  daddu     $a0, $s1, $zero
/* 5B1AB4 80218604 8E050000 */  lw        $a1, ($s0)
/* 5B1AB8 80218608 0C0B1EAF */  jal       get_variable
/* 5B1ABC 8021860C 46000586 */   mov.s    $f22, $f0
/* 5B1AC0 80218610 8E240148 */  lw        $a0, 0x148($s1)
/* 5B1AC4 80218614 0C09A75B */  jal       get_actor
/* 5B1AC8 80218618 0040802D */   daddu    $s0, $v0, $zero
/* 5B1ACC 8021861C 4600A521 */  cvt.d.s   $f20, $f20
/* 5B1AD0 80218620 4405F000 */  mfc1      $a1, $f30
/* 5B1AD4 80218624 3C014014 */  lui       $at, 0x4014
/* 5B1AD8 80218628 44810800 */  mtc1      $at, $f1
/* 5B1ADC 8021862C 44800000 */  mtc1      $zero, $f0
/* 5B1AE0 80218630 4407E000 */  mfc1      $a3, $f28
/* 5B1AE4 80218634 4620A500 */  add.d     $f20, $f20, $f0
/* 5B1AE8 80218638 0000202D */  daddu     $a0, $zero, $zero
/* 5B1AEC 8021863C AFB0001C */  sw        $s0, 0x1c($sp)
/* 5B1AF0 80218640 4620A520 */  cvt.s.d   $f20, $f20
/* 5B1AF4 80218644 4406A000 */  mfc1      $a2, $f20
/* 5B1AF8 80218648 0040802D */  daddu     $s0, $v0, $zero
/* 5B1AFC 8021864C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 5B1B00 80218650 E7B80014 */  swc1      $f24, 0x14($sp)
/* 5B1B04 80218654 0C01BFD4 */  jal       func_8006FF50
/* 5B1B08 80218658 E7B60018 */   swc1     $f22, 0x18($sp)
/* 5B1B0C 8021865C 0040202D */  daddu     $a0, $v0, $zero
/* 5B1B10 80218660 82030210 */  lb        $v1, 0x210($s0)
/* 5B1B14 80218664 2402000A */  addiu     $v0, $zero, 0xa
/* 5B1B18 80218668 14620007 */  bne       $v1, $v0, .L80218688
/* 5B1B1C 8021866C 00000000 */   nop      
/* 5B1B20 80218670 8C82000C */  lw        $v0, 0xc($a0)
/* 5B1B24 80218674 3C013ECC */  lui       $at, 0x3ecc
/* 5B1B28 80218678 3421CCCD */  ori       $at, $at, 0xcccd
/* 5B1B2C 8021867C 44810000 */  mtc1      $at, $f0
/* 5B1B30 80218680 00000000 */  nop       
/* 5B1B34 80218684 E4400028 */  swc1      $f0, 0x28($v0)
.L80218688:
/* 5B1B38 80218688 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B1B3C 8021868C 8FB10024 */  lw        $s1, 0x24($sp)
/* 5B1B40 80218690 8FB00020 */  lw        $s0, 0x20($sp)
/* 5B1B44 80218694 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5B1B48 80218698 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5B1B4C 8021869C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5B1B50 802186A0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5B1B54 802186A4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5B1B58 802186A8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5B1B5C 802186AC 24020002 */  addiu     $v0, $zero, 2
/* 5B1B60 802186B0 03E00008 */  jr        $ra
/* 5B1B64 802186B4 27BD0060 */   addiu    $sp, $sp, 0x60
