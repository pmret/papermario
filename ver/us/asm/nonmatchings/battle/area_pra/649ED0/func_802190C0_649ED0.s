.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802190C0_649ED0
/* 649ED0 802190C0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 649ED4 802190C4 AFB10024 */  sw        $s1, 0x24($sp)
/* 649ED8 802190C8 0080882D */  daddu     $s1, $a0, $zero
/* 649EDC 802190CC AFBF0028 */  sw        $ra, 0x28($sp)
/* 649EE0 802190D0 AFB00020 */  sw        $s0, 0x20($sp)
/* 649EE4 802190D4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 649EE8 802190D8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 649EEC 802190DC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 649EF0 802190E0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 649EF4 802190E4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 649EF8 802190E8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 649EFC 802190EC 8E30000C */  lw        $s0, 0xc($s1)
/* 649F00 802190F0 8E050000 */  lw        $a1, ($s0)
/* 649F04 802190F4 0C0B210B */  jal       get_float_variable
/* 649F08 802190F8 26100004 */   addiu    $s0, $s0, 4
/* 649F0C 802190FC 8E050000 */  lw        $a1, ($s0)
/* 649F10 80219100 26100004 */  addiu     $s0, $s0, 4
/* 649F14 80219104 0220202D */  daddu     $a0, $s1, $zero
/* 649F18 80219108 0C0B210B */  jal       get_float_variable
/* 649F1C 8021910C 46000786 */   mov.s    $f30, $f0
/* 649F20 80219110 8E050000 */  lw        $a1, ($s0)
/* 649F24 80219114 26100004 */  addiu     $s0, $s0, 4
/* 649F28 80219118 0220202D */  daddu     $a0, $s1, $zero
/* 649F2C 8021911C 0C0B210B */  jal       get_float_variable
/* 649F30 80219120 46000506 */   mov.s    $f20, $f0
/* 649F34 80219124 8E050000 */  lw        $a1, ($s0)
/* 649F38 80219128 26100004 */  addiu     $s0, $s0, 4
/* 649F3C 8021912C 0220202D */  daddu     $a0, $s1, $zero
/* 649F40 80219130 0C0B210B */  jal       get_float_variable
/* 649F44 80219134 46000706 */   mov.s    $f28, $f0
/* 649F48 80219138 8E050000 */  lw        $a1, ($s0)
/* 649F4C 8021913C 26100004 */  addiu     $s0, $s0, 4
/* 649F50 80219140 0220202D */  daddu     $a0, $s1, $zero
/* 649F54 80219144 0C0B210B */  jal       get_float_variable
/* 649F58 80219148 46000686 */   mov.s    $f26, $f0
/* 649F5C 8021914C 8E050000 */  lw        $a1, ($s0)
/* 649F60 80219150 26100004 */  addiu     $s0, $s0, 4
/* 649F64 80219154 0220202D */  daddu     $a0, $s1, $zero
/* 649F68 80219158 0C0B210B */  jal       get_float_variable
/* 649F6C 8021915C 46000606 */   mov.s    $f24, $f0
/* 649F70 80219160 0220202D */  daddu     $a0, $s1, $zero
/* 649F74 80219164 8E050000 */  lw        $a1, ($s0)
/* 649F78 80219168 0C0B1EAF */  jal       get_variable
/* 649F7C 8021916C 46000586 */   mov.s    $f22, $f0
/* 649F80 80219170 8E240148 */  lw        $a0, 0x148($s1)
/* 649F84 80219174 0C09A75B */  jal       get_actor
/* 649F88 80219178 0040802D */   daddu    $s0, $v0, $zero
/* 649F8C 8021917C 4600A521 */  cvt.d.s   $f20, $f20
/* 649F90 80219180 4405F000 */  mfc1      $a1, $f30
/* 649F94 80219184 3C014014 */  lui       $at, 0x4014
/* 649F98 80219188 44810800 */  mtc1      $at, $f1
/* 649F9C 8021918C 44800000 */  mtc1      $zero, $f0
/* 649FA0 80219190 4407E000 */  mfc1      $a3, $f28
/* 649FA4 80219194 4620A500 */  add.d     $f20, $f20, $f0
/* 649FA8 80219198 0000202D */  daddu     $a0, $zero, $zero
/* 649FAC 8021919C AFB0001C */  sw        $s0, 0x1c($sp)
/* 649FB0 802191A0 4620A520 */  cvt.s.d   $f20, $f20
/* 649FB4 802191A4 4406A000 */  mfc1      $a2, $f20
/* 649FB8 802191A8 0040802D */  daddu     $s0, $v0, $zero
/* 649FBC 802191AC E7BA0010 */  swc1      $f26, 0x10($sp)
/* 649FC0 802191B0 E7B80014 */  swc1      $f24, 0x14($sp)
/* 649FC4 802191B4 0C01BFD4 */  jal       playFX_12
/* 649FC8 802191B8 E7B60018 */   swc1     $f22, 0x18($sp)
/* 649FCC 802191BC 0040202D */  daddu     $a0, $v0, $zero
/* 649FD0 802191C0 82030210 */  lb        $v1, 0x210($s0)
/* 649FD4 802191C4 2402000A */  addiu     $v0, $zero, 0xa
/* 649FD8 802191C8 14620007 */  bne       $v1, $v0, .L802191E8
/* 649FDC 802191CC 00000000 */   nop
/* 649FE0 802191D0 8C82000C */  lw        $v0, 0xc($a0)
/* 649FE4 802191D4 3C013ECC */  lui       $at, 0x3ecc
/* 649FE8 802191D8 3421CCCD */  ori       $at, $at, 0xcccd
/* 649FEC 802191DC 44810000 */  mtc1      $at, $f0
/* 649FF0 802191E0 00000000 */  nop
/* 649FF4 802191E4 E4400028 */  swc1      $f0, 0x28($v0)
.L802191E8:
/* 649FF8 802191E8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 649FFC 802191EC 8FB10024 */  lw        $s1, 0x24($sp)
/* 64A000 802191F0 8FB00020 */  lw        $s0, 0x20($sp)
/* 64A004 802191F4 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 64A008 802191F8 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 64A00C 802191FC D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 64A010 80219200 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 64A014 80219204 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 64A018 80219208 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 64A01C 8021920C 24020002 */  addiu     $v0, $zero, 2
/* 64A020 80219210 03E00008 */  jr        $ra
/* 64A024 80219214 27BD0060 */   addiu    $sp, $sp, 0x60
