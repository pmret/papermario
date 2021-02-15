.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189A0_58CC90
/* 58CC90 802189A0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 58CC94 802189A4 AFB10024 */  sw        $s1, 0x24($sp)
/* 58CC98 802189A8 0080882D */  daddu     $s1, $a0, $zero
/* 58CC9C 802189AC AFBF0028 */  sw        $ra, 0x28($sp)
/* 58CCA0 802189B0 AFB00020 */  sw        $s0, 0x20($sp)
/* 58CCA4 802189B4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 58CCA8 802189B8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 58CCAC 802189BC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 58CCB0 802189C0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 58CCB4 802189C4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 58CCB8 802189C8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 58CCBC 802189CC 8E30000C */  lw        $s0, 0xc($s1)
/* 58CCC0 802189D0 8E050000 */  lw        $a1, ($s0)
/* 58CCC4 802189D4 0C0B210B */  jal       get_float_variable
/* 58CCC8 802189D8 26100004 */   addiu    $s0, $s0, 4
/* 58CCCC 802189DC 8E050000 */  lw        $a1, ($s0)
/* 58CCD0 802189E0 26100004 */  addiu     $s0, $s0, 4
/* 58CCD4 802189E4 0220202D */  daddu     $a0, $s1, $zero
/* 58CCD8 802189E8 0C0B210B */  jal       get_float_variable
/* 58CCDC 802189EC 46000786 */   mov.s    $f30, $f0
/* 58CCE0 802189F0 8E050000 */  lw        $a1, ($s0)
/* 58CCE4 802189F4 26100004 */  addiu     $s0, $s0, 4
/* 58CCE8 802189F8 0220202D */  daddu     $a0, $s1, $zero
/* 58CCEC 802189FC 0C0B210B */  jal       get_float_variable
/* 58CCF0 80218A00 46000506 */   mov.s    $f20, $f0
/* 58CCF4 80218A04 8E050000 */  lw        $a1, ($s0)
/* 58CCF8 80218A08 26100004 */  addiu     $s0, $s0, 4
/* 58CCFC 80218A0C 0220202D */  daddu     $a0, $s1, $zero
/* 58CD00 80218A10 0C0B210B */  jal       get_float_variable
/* 58CD04 80218A14 46000706 */   mov.s    $f28, $f0
/* 58CD08 80218A18 8E050000 */  lw        $a1, ($s0)
/* 58CD0C 80218A1C 26100004 */  addiu     $s0, $s0, 4
/* 58CD10 80218A20 0220202D */  daddu     $a0, $s1, $zero
/* 58CD14 80218A24 0C0B210B */  jal       get_float_variable
/* 58CD18 80218A28 46000686 */   mov.s    $f26, $f0
/* 58CD1C 80218A2C 8E050000 */  lw        $a1, ($s0)
/* 58CD20 80218A30 26100004 */  addiu     $s0, $s0, 4
/* 58CD24 80218A34 0220202D */  daddu     $a0, $s1, $zero
/* 58CD28 80218A38 0C0B210B */  jal       get_float_variable
/* 58CD2C 80218A3C 46000606 */   mov.s    $f24, $f0
/* 58CD30 80218A40 0220202D */  daddu     $a0, $s1, $zero
/* 58CD34 80218A44 8E050000 */  lw        $a1, ($s0)
/* 58CD38 80218A48 0C0B1EAF */  jal       get_variable
/* 58CD3C 80218A4C 46000586 */   mov.s    $f22, $f0
/* 58CD40 80218A50 8E240148 */  lw        $a0, 0x148($s1)
/* 58CD44 80218A54 0C09A75B */  jal       get_actor
/* 58CD48 80218A58 0040802D */   daddu    $s0, $v0, $zero
/* 58CD4C 80218A5C 4600A521 */  cvt.d.s   $f20, $f20
/* 58CD50 80218A60 4405F000 */  mfc1      $a1, $f30
/* 58CD54 80218A64 3C014014 */  lui       $at, 0x4014
/* 58CD58 80218A68 44810800 */  mtc1      $at, $f1
/* 58CD5C 80218A6C 44800000 */  mtc1      $zero, $f0
/* 58CD60 80218A70 4407E000 */  mfc1      $a3, $f28
/* 58CD64 80218A74 4620A500 */  add.d     $f20, $f20, $f0
/* 58CD68 80218A78 0000202D */  daddu     $a0, $zero, $zero
/* 58CD6C 80218A7C AFB0001C */  sw        $s0, 0x1c($sp)
/* 58CD70 80218A80 4620A520 */  cvt.s.d   $f20, $f20
/* 58CD74 80218A84 4406A000 */  mfc1      $a2, $f20
/* 58CD78 80218A88 0040802D */  daddu     $s0, $v0, $zero
/* 58CD7C 80218A8C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 58CD80 80218A90 E7B80014 */  swc1      $f24, 0x14($sp)
/* 58CD84 80218A94 0C01BFD4 */  jal       func_8006FF50
/* 58CD88 80218A98 E7B60018 */   swc1     $f22, 0x18($sp)
/* 58CD8C 80218A9C 0040202D */  daddu     $a0, $v0, $zero
/* 58CD90 80218AA0 82030210 */  lb        $v1, 0x210($s0)
/* 58CD94 80218AA4 2402000A */  addiu     $v0, $zero, 0xa
/* 58CD98 80218AA8 14620007 */  bne       $v1, $v0, .L80218AC8
/* 58CD9C 80218AAC 00000000 */   nop
/* 58CDA0 80218AB0 8C82000C */  lw        $v0, 0xc($a0)
/* 58CDA4 80218AB4 3C013ECC */  lui       $at, 0x3ecc
/* 58CDA8 80218AB8 3421CCCD */  ori       $at, $at, 0xcccd
/* 58CDAC 80218ABC 44810000 */  mtc1      $at, $f0
/* 58CDB0 80218AC0 00000000 */  nop
/* 58CDB4 80218AC4 E4400028 */  swc1      $f0, 0x28($v0)
.L80218AC8:
/* 58CDB8 80218AC8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 58CDBC 80218ACC 8FB10024 */  lw        $s1, 0x24($sp)
/* 58CDC0 80218AD0 8FB00020 */  lw        $s0, 0x20($sp)
/* 58CDC4 80218AD4 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 58CDC8 80218AD8 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 58CDCC 80218ADC D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 58CDD0 80218AE0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 58CDD4 80218AE4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 58CDD8 80218AE8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 58CDDC 80218AEC 24020002 */  addiu     $v0, $zero, 2
/* 58CDE0 80218AF0 03E00008 */  jr        $ra
/* 58CDE4 80218AF4 27BD0060 */   addiu    $sp, $sp, 0x60
