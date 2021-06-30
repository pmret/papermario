.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218630_58C920
/* 58C920 80218630 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 58C924 80218634 AFB10024 */  sw        $s1, 0x24($sp)
/* 58C928 80218638 0080882D */  daddu     $s1, $a0, $zero
/* 58C92C 8021863C AFBF0028 */  sw        $ra, 0x28($sp)
/* 58C930 80218640 AFB00020 */  sw        $s0, 0x20($sp)
/* 58C934 80218644 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 58C938 80218648 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 58C93C 8021864C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 58C940 80218650 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 58C944 80218654 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 58C948 80218658 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 58C94C 8021865C 8E30000C */  lw        $s0, 0xc($s1)
/* 58C950 80218660 8E050000 */  lw        $a1, ($s0)
/* 58C954 80218664 0C0B210B */  jal       get_float_variable
/* 58C958 80218668 26100004 */   addiu    $s0, $s0, 4
/* 58C95C 8021866C 8E050000 */  lw        $a1, ($s0)
/* 58C960 80218670 26100004 */  addiu     $s0, $s0, 4
/* 58C964 80218674 0220202D */  daddu     $a0, $s1, $zero
/* 58C968 80218678 0C0B210B */  jal       get_float_variable
/* 58C96C 8021867C 46000786 */   mov.s    $f30, $f0
/* 58C970 80218680 8E050000 */  lw        $a1, ($s0)
/* 58C974 80218684 26100004 */  addiu     $s0, $s0, 4
/* 58C978 80218688 0220202D */  daddu     $a0, $s1, $zero
/* 58C97C 8021868C 0C0B210B */  jal       get_float_variable
/* 58C980 80218690 46000506 */   mov.s    $f20, $f0
/* 58C984 80218694 8E050000 */  lw        $a1, ($s0)
/* 58C988 80218698 26100004 */  addiu     $s0, $s0, 4
/* 58C98C 8021869C 0220202D */  daddu     $a0, $s1, $zero
/* 58C990 802186A0 0C0B210B */  jal       get_float_variable
/* 58C994 802186A4 46000706 */   mov.s    $f28, $f0
/* 58C998 802186A8 8E050000 */  lw        $a1, ($s0)
/* 58C99C 802186AC 26100004 */  addiu     $s0, $s0, 4
/* 58C9A0 802186B0 0220202D */  daddu     $a0, $s1, $zero
/* 58C9A4 802186B4 0C0B210B */  jal       get_float_variable
/* 58C9A8 802186B8 46000686 */   mov.s    $f26, $f0
/* 58C9AC 802186BC 8E050000 */  lw        $a1, ($s0)
/* 58C9B0 802186C0 26100004 */  addiu     $s0, $s0, 4
/* 58C9B4 802186C4 0220202D */  daddu     $a0, $s1, $zero
/* 58C9B8 802186C8 0C0B210B */  jal       get_float_variable
/* 58C9BC 802186CC 46000606 */   mov.s    $f24, $f0
/* 58C9C0 802186D0 0220202D */  daddu     $a0, $s1, $zero
/* 58C9C4 802186D4 8E050000 */  lw        $a1, ($s0)
/* 58C9C8 802186D8 0C0B1EAF */  jal       get_variable
/* 58C9CC 802186DC 46000586 */   mov.s    $f22, $f0
/* 58C9D0 802186E0 8E240148 */  lw        $a0, 0x148($s1)
/* 58C9D4 802186E4 0C09A75B */  jal       get_actor
/* 58C9D8 802186E8 0040802D */   daddu    $s0, $v0, $zero
/* 58C9DC 802186EC 4600A521 */  cvt.d.s   $f20, $f20
/* 58C9E0 802186F0 4405F000 */  mfc1      $a1, $f30
/* 58C9E4 802186F4 3C014014 */  lui       $at, 0x4014
/* 58C9E8 802186F8 44810800 */  mtc1      $at, $f1
/* 58C9EC 802186FC 44800000 */  mtc1      $zero, $f0
/* 58C9F0 80218700 4407E000 */  mfc1      $a3, $f28
/* 58C9F4 80218704 4620A500 */  add.d     $f20, $f20, $f0
/* 58C9F8 80218708 0000202D */  daddu     $a0, $zero, $zero
/* 58C9FC 8021870C AFB0001C */  sw        $s0, 0x1c($sp)
/* 58CA00 80218710 4620A520 */  cvt.s.d   $f20, $f20
/* 58CA04 80218714 4406A000 */  mfc1      $a2, $f20
/* 58CA08 80218718 0040802D */  daddu     $s0, $v0, $zero
/* 58CA0C 8021871C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 58CA10 80218720 E7B80014 */  swc1      $f24, 0x14($sp)
/* 58CA14 80218724 0C01BFD4 */  jal       playFX_12
/* 58CA18 80218728 E7B60018 */   swc1     $f22, 0x18($sp)
/* 58CA1C 8021872C 0040202D */  daddu     $a0, $v0, $zero
/* 58CA20 80218730 82030210 */  lb        $v1, 0x210($s0)
/* 58CA24 80218734 2402000A */  addiu     $v0, $zero, 0xa
/* 58CA28 80218738 14620007 */  bne       $v1, $v0, .L80218758
/* 58CA2C 8021873C 00000000 */   nop
/* 58CA30 80218740 8C82000C */  lw        $v0, 0xc($a0)
/* 58CA34 80218744 3C013ECC */  lui       $at, 0x3ecc
/* 58CA38 80218748 3421CCCD */  ori       $at, $at, 0xcccd
/* 58CA3C 8021874C 44810000 */  mtc1      $at, $f0
/* 58CA40 80218750 00000000 */  nop
/* 58CA44 80218754 E4400028 */  swc1      $f0, 0x28($v0)
.L80218758:
/* 58CA48 80218758 8FBF0028 */  lw        $ra, 0x28($sp)
/* 58CA4C 8021875C 8FB10024 */  lw        $s1, 0x24($sp)
/* 58CA50 80218760 8FB00020 */  lw        $s0, 0x20($sp)
/* 58CA54 80218764 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 58CA58 80218768 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 58CA5C 8021876C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 58CA60 80218770 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 58CA64 80218774 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 58CA68 80218778 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 58CA6C 8021877C 24020002 */  addiu     $v0, $zero, 2
/* 58CA70 80218780 03E00008 */  jr        $ra
/* 58CA74 80218784 27BD0060 */   addiu    $sp, $sp, 0x60
