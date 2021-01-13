.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188D0_5B1D80
/* 5B1D80 802188D0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5B1D84 802188D4 AFB10024 */  sw        $s1, 0x24($sp)
/* 5B1D88 802188D8 0080882D */  daddu     $s1, $a0, $zero
/* 5B1D8C 802188DC AFBF0028 */  sw        $ra, 0x28($sp)
/* 5B1D90 802188E0 AFB00020 */  sw        $s0, 0x20($sp)
/* 5B1D94 802188E4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5B1D98 802188E8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5B1D9C 802188EC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5B1DA0 802188F0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5B1DA4 802188F4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5B1DA8 802188F8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5B1DAC 802188FC 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1DB0 80218900 8E050000 */  lw        $a1, ($s0)
/* 5B1DB4 80218904 0C0B210B */  jal       get_float_variable
/* 5B1DB8 80218908 26100004 */   addiu    $s0, $s0, 4
/* 5B1DBC 8021890C 8E050000 */  lw        $a1, ($s0)
/* 5B1DC0 80218910 26100004 */  addiu     $s0, $s0, 4
/* 5B1DC4 80218914 0220202D */  daddu     $a0, $s1, $zero
/* 5B1DC8 80218918 0C0B210B */  jal       get_float_variable
/* 5B1DCC 8021891C 46000786 */   mov.s    $f30, $f0
/* 5B1DD0 80218920 8E050000 */  lw        $a1, ($s0)
/* 5B1DD4 80218924 26100004 */  addiu     $s0, $s0, 4
/* 5B1DD8 80218928 0220202D */  daddu     $a0, $s1, $zero
/* 5B1DDC 8021892C 0C0B210B */  jal       get_float_variable
/* 5B1DE0 80218930 46000506 */   mov.s    $f20, $f0
/* 5B1DE4 80218934 8E050000 */  lw        $a1, ($s0)
/* 5B1DE8 80218938 26100004 */  addiu     $s0, $s0, 4
/* 5B1DEC 8021893C 0220202D */  daddu     $a0, $s1, $zero
/* 5B1DF0 80218940 0C0B210B */  jal       get_float_variable
/* 5B1DF4 80218944 46000706 */   mov.s    $f28, $f0
/* 5B1DF8 80218948 8E050000 */  lw        $a1, ($s0)
/* 5B1DFC 8021894C 26100004 */  addiu     $s0, $s0, 4
/* 5B1E00 80218950 0220202D */  daddu     $a0, $s1, $zero
/* 5B1E04 80218954 0C0B210B */  jal       get_float_variable
/* 5B1E08 80218958 46000686 */   mov.s    $f26, $f0
/* 5B1E0C 8021895C 8E050000 */  lw        $a1, ($s0)
/* 5B1E10 80218960 26100004 */  addiu     $s0, $s0, 4
/* 5B1E14 80218964 0220202D */  daddu     $a0, $s1, $zero
/* 5B1E18 80218968 0C0B210B */  jal       get_float_variable
/* 5B1E1C 8021896C 46000606 */   mov.s    $f24, $f0
/* 5B1E20 80218970 0220202D */  daddu     $a0, $s1, $zero
/* 5B1E24 80218974 8E050000 */  lw        $a1, ($s0)
/* 5B1E28 80218978 0C0B1EAF */  jal       get_variable
/* 5B1E2C 8021897C 46000586 */   mov.s    $f22, $f0
/* 5B1E30 80218980 8E240148 */  lw        $a0, 0x148($s1)
/* 5B1E34 80218984 0C09A75B */  jal       get_actor
/* 5B1E38 80218988 0040802D */   daddu    $s0, $v0, $zero
/* 5B1E3C 8021898C 4600A521 */  cvt.d.s   $f20, $f20
/* 5B1E40 80218990 4405F000 */  mfc1      $a1, $f30
/* 5B1E44 80218994 3C014014 */  lui       $at, 0x4014
/* 5B1E48 80218998 44810800 */  mtc1      $at, $f1
/* 5B1E4C 8021899C 44800000 */  mtc1      $zero, $f0
/* 5B1E50 802189A0 4407E000 */  mfc1      $a3, $f28
/* 5B1E54 802189A4 4620A500 */  add.d     $f20, $f20, $f0
/* 5B1E58 802189A8 0000202D */  daddu     $a0, $zero, $zero
/* 5B1E5C 802189AC AFB0001C */  sw        $s0, 0x1c($sp)
/* 5B1E60 802189B0 4620A520 */  cvt.s.d   $f20, $f20
/* 5B1E64 802189B4 4406A000 */  mfc1      $a2, $f20
/* 5B1E68 802189B8 0040802D */  daddu     $s0, $v0, $zero
/* 5B1E6C 802189BC E7BA0010 */  swc1      $f26, 0x10($sp)
/* 5B1E70 802189C0 E7B80014 */  swc1      $f24, 0x14($sp)
/* 5B1E74 802189C4 0C01BFD4 */  jal       func_8006FF50
/* 5B1E78 802189C8 E7B60018 */   swc1     $f22, 0x18($sp)
/* 5B1E7C 802189CC 0040202D */  daddu     $a0, $v0, $zero
/* 5B1E80 802189D0 82030210 */  lb        $v1, 0x210($s0)
/* 5B1E84 802189D4 2402000A */  addiu     $v0, $zero, 0xa
/* 5B1E88 802189D8 14620007 */  bne       $v1, $v0, .L802189F8
/* 5B1E8C 802189DC 00000000 */   nop
/* 5B1E90 802189E0 8C82000C */  lw        $v0, 0xc($a0)
/* 5B1E94 802189E4 3C013ECC */  lui       $at, 0x3ecc
/* 5B1E98 802189E8 3421CCCD */  ori       $at, $at, 0xcccd
/* 5B1E9C 802189EC 44810000 */  mtc1      $at, $f0
/* 5B1EA0 802189F0 00000000 */  nop
/* 5B1EA4 802189F4 E4400028 */  swc1      $f0, 0x28($v0)
.L802189F8:
/* 5B1EA8 802189F8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B1EAC 802189FC 8FB10024 */  lw        $s1, 0x24($sp)
/* 5B1EB0 80218A00 8FB00020 */  lw        $s0, 0x20($sp)
/* 5B1EB4 80218A04 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5B1EB8 80218A08 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5B1EBC 80218A0C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5B1EC0 80218A10 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5B1EC4 80218A14 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5B1EC8 80218A18 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5B1ECC 80218A1C 24020002 */  addiu     $v0, $zero, 2
/* 5B1ED0 80218A20 03E00008 */  jr        $ra
/* 5B1ED4 80218A24 27BD0060 */   addiu    $sp, $sp, 0x60
