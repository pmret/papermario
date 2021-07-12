.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219BA0_66B920
/* 66B920 80219BA0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 66B924 80219BA4 AFB10024 */  sw        $s1, 0x24($sp)
/* 66B928 80219BA8 0080882D */  daddu     $s1, $a0, $zero
/* 66B92C 80219BAC AFBF0028 */  sw        $ra, 0x28($sp)
/* 66B930 80219BB0 AFB00020 */  sw        $s0, 0x20($sp)
/* 66B934 80219BB4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 66B938 80219BB8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 66B93C 80219BBC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 66B940 80219BC0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 66B944 80219BC4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 66B948 80219BC8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 66B94C 80219BCC 8E30000C */  lw        $s0, 0xc($s1)
/* 66B950 80219BD0 8E050000 */  lw        $a1, ($s0)
/* 66B954 80219BD4 0C0B210B */  jal       get_float_variable
/* 66B958 80219BD8 26100004 */   addiu    $s0, $s0, 4
/* 66B95C 80219BDC 8E050000 */  lw        $a1, ($s0)
/* 66B960 80219BE0 26100004 */  addiu     $s0, $s0, 4
/* 66B964 80219BE4 0220202D */  daddu     $a0, $s1, $zero
/* 66B968 80219BE8 0C0B210B */  jal       get_float_variable
/* 66B96C 80219BEC 46000786 */   mov.s    $f30, $f0
/* 66B970 80219BF0 8E050000 */  lw        $a1, ($s0)
/* 66B974 80219BF4 26100004 */  addiu     $s0, $s0, 4
/* 66B978 80219BF8 0220202D */  daddu     $a0, $s1, $zero
/* 66B97C 80219BFC 0C0B210B */  jal       get_float_variable
/* 66B980 80219C00 46000506 */   mov.s    $f20, $f0
/* 66B984 80219C04 8E050000 */  lw        $a1, ($s0)
/* 66B988 80219C08 26100004 */  addiu     $s0, $s0, 4
/* 66B98C 80219C0C 0220202D */  daddu     $a0, $s1, $zero
/* 66B990 80219C10 0C0B210B */  jal       get_float_variable
/* 66B994 80219C14 46000706 */   mov.s    $f28, $f0
/* 66B998 80219C18 8E050000 */  lw        $a1, ($s0)
/* 66B99C 80219C1C 26100004 */  addiu     $s0, $s0, 4
/* 66B9A0 80219C20 0220202D */  daddu     $a0, $s1, $zero
/* 66B9A4 80219C24 0C0B210B */  jal       get_float_variable
/* 66B9A8 80219C28 46000686 */   mov.s    $f26, $f0
/* 66B9AC 80219C2C 8E050000 */  lw        $a1, ($s0)
/* 66B9B0 80219C30 26100004 */  addiu     $s0, $s0, 4
/* 66B9B4 80219C34 0220202D */  daddu     $a0, $s1, $zero
/* 66B9B8 80219C38 0C0B210B */  jal       get_float_variable
/* 66B9BC 80219C3C 46000606 */   mov.s    $f24, $f0
/* 66B9C0 80219C40 0220202D */  daddu     $a0, $s1, $zero
/* 66B9C4 80219C44 8E050000 */  lw        $a1, ($s0)
/* 66B9C8 80219C48 0C0B1EAF */  jal       get_variable
/* 66B9CC 80219C4C 46000586 */   mov.s    $f22, $f0
/* 66B9D0 80219C50 8E240148 */  lw        $a0, 0x148($s1)
/* 66B9D4 80219C54 0C09A75B */  jal       get_actor
/* 66B9D8 80219C58 0040802D */   daddu    $s0, $v0, $zero
/* 66B9DC 80219C5C 4600A521 */  cvt.d.s   $f20, $f20
/* 66B9E0 80219C60 4405F000 */  mfc1      $a1, $f30
/* 66B9E4 80219C64 3C014014 */  lui       $at, 0x4014
/* 66B9E8 80219C68 44810800 */  mtc1      $at, $f1
/* 66B9EC 80219C6C 44800000 */  mtc1      $zero, $f0
/* 66B9F0 80219C70 4407E000 */  mfc1      $a3, $f28
/* 66B9F4 80219C74 4620A500 */  add.d     $f20, $f20, $f0
/* 66B9F8 80219C78 0000202D */  daddu     $a0, $zero, $zero
/* 66B9FC 80219C7C AFB0001C */  sw        $s0, 0x1c($sp)
/* 66BA00 80219C80 4620A520 */  cvt.s.d   $f20, $f20
/* 66BA04 80219C84 4406A000 */  mfc1      $a2, $f20
/* 66BA08 80219C88 0040802D */  daddu     $s0, $v0, $zero
/* 66BA0C 80219C8C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 66BA10 80219C90 E7B80014 */  swc1      $f24, 0x14($sp)
/* 66BA14 80219C94 0C01BFD4 */  jal       playFX_12
/* 66BA18 80219C98 E7B60018 */   swc1     $f22, 0x18($sp)
/* 66BA1C 80219C9C 0040202D */  daddu     $a0, $v0, $zero
/* 66BA20 80219CA0 82030210 */  lb        $v1, 0x210($s0)
/* 66BA24 80219CA4 2402000A */  addiu     $v0, $zero, 0xa
/* 66BA28 80219CA8 14620007 */  bne       $v1, $v0, .L80219CC8
/* 66BA2C 80219CAC 00000000 */   nop
/* 66BA30 80219CB0 8C82000C */  lw        $v0, 0xc($a0)
/* 66BA34 80219CB4 3C013ECC */  lui       $at, 0x3ecc
/* 66BA38 80219CB8 3421CCCD */  ori       $at, $at, 0xcccd
/* 66BA3C 80219CBC 44810000 */  mtc1      $at, $f0
/* 66BA40 80219CC0 00000000 */  nop
/* 66BA44 80219CC4 E4400028 */  swc1      $f0, 0x28($v0)
.L80219CC8:
/* 66BA48 80219CC8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 66BA4C 80219CCC 8FB10024 */  lw        $s1, 0x24($sp)
/* 66BA50 80219CD0 8FB00020 */  lw        $s0, 0x20($sp)
/* 66BA54 80219CD4 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 66BA58 80219CD8 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 66BA5C 80219CDC D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 66BA60 80219CE0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 66BA64 80219CE4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 66BA68 80219CE8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 66BA6C 80219CEC 24020002 */  addiu     $v0, $zero, 2
/* 66BA70 80219CF0 03E00008 */  jr        $ra
/* 66BA74 80219CF4 27BD0060 */   addiu    $sp, $sp, 0x60
