.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219830_66B5B0
/* 66B5B0 80219830 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 66B5B4 80219834 AFB10024 */  sw        $s1, 0x24($sp)
/* 66B5B8 80219838 0080882D */  daddu     $s1, $a0, $zero
/* 66B5BC 8021983C AFBF0028 */  sw        $ra, 0x28($sp)
/* 66B5C0 80219840 AFB00020 */  sw        $s0, 0x20($sp)
/* 66B5C4 80219844 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 66B5C8 80219848 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 66B5CC 8021984C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 66B5D0 80219850 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 66B5D4 80219854 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 66B5D8 80219858 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 66B5DC 8021985C 8E30000C */  lw        $s0, 0xc($s1)
/* 66B5E0 80219860 8E050000 */  lw        $a1, ($s0)
/* 66B5E4 80219864 0C0B210B */  jal       get_float_variable
/* 66B5E8 80219868 26100004 */   addiu    $s0, $s0, 4
/* 66B5EC 8021986C 8E050000 */  lw        $a1, ($s0)
/* 66B5F0 80219870 26100004 */  addiu     $s0, $s0, 4
/* 66B5F4 80219874 0220202D */  daddu     $a0, $s1, $zero
/* 66B5F8 80219878 0C0B210B */  jal       get_float_variable
/* 66B5FC 8021987C 46000786 */   mov.s    $f30, $f0
/* 66B600 80219880 8E050000 */  lw        $a1, ($s0)
/* 66B604 80219884 26100004 */  addiu     $s0, $s0, 4
/* 66B608 80219888 0220202D */  daddu     $a0, $s1, $zero
/* 66B60C 8021988C 0C0B210B */  jal       get_float_variable
/* 66B610 80219890 46000506 */   mov.s    $f20, $f0
/* 66B614 80219894 8E050000 */  lw        $a1, ($s0)
/* 66B618 80219898 26100004 */  addiu     $s0, $s0, 4
/* 66B61C 8021989C 0220202D */  daddu     $a0, $s1, $zero
/* 66B620 802198A0 0C0B210B */  jal       get_float_variable
/* 66B624 802198A4 46000706 */   mov.s    $f28, $f0
/* 66B628 802198A8 8E050000 */  lw        $a1, ($s0)
/* 66B62C 802198AC 26100004 */  addiu     $s0, $s0, 4
/* 66B630 802198B0 0220202D */  daddu     $a0, $s1, $zero
/* 66B634 802198B4 0C0B210B */  jal       get_float_variable
/* 66B638 802198B8 46000686 */   mov.s    $f26, $f0
/* 66B63C 802198BC 8E050000 */  lw        $a1, ($s0)
/* 66B640 802198C0 26100004 */  addiu     $s0, $s0, 4
/* 66B644 802198C4 0220202D */  daddu     $a0, $s1, $zero
/* 66B648 802198C8 0C0B210B */  jal       get_float_variable
/* 66B64C 802198CC 46000606 */   mov.s    $f24, $f0
/* 66B650 802198D0 0220202D */  daddu     $a0, $s1, $zero
/* 66B654 802198D4 8E050000 */  lw        $a1, ($s0)
/* 66B658 802198D8 0C0B1EAF */  jal       get_variable
/* 66B65C 802198DC 46000586 */   mov.s    $f22, $f0
/* 66B660 802198E0 8E240148 */  lw        $a0, 0x148($s1)
/* 66B664 802198E4 0C09A75B */  jal       get_actor
/* 66B668 802198E8 0040802D */   daddu    $s0, $v0, $zero
/* 66B66C 802198EC 4600A521 */  cvt.d.s   $f20, $f20
/* 66B670 802198F0 4405F000 */  mfc1      $a1, $f30
/* 66B674 802198F4 3C014014 */  lui       $at, 0x4014
/* 66B678 802198F8 44810800 */  mtc1      $at, $f1
/* 66B67C 802198FC 44800000 */  mtc1      $zero, $f0
/* 66B680 80219900 4407E000 */  mfc1      $a3, $f28
/* 66B684 80219904 4620A500 */  add.d     $f20, $f20, $f0
/* 66B688 80219908 0000202D */  daddu     $a0, $zero, $zero
/* 66B68C 8021990C AFB0001C */  sw        $s0, 0x1c($sp)
/* 66B690 80219910 4620A520 */  cvt.s.d   $f20, $f20
/* 66B694 80219914 4406A000 */  mfc1      $a2, $f20
/* 66B698 80219918 0040802D */  daddu     $s0, $v0, $zero
/* 66B69C 8021991C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 66B6A0 80219920 E7B80014 */  swc1      $f24, 0x14($sp)
/* 66B6A4 80219924 0C01BFD4 */  jal       func_8006FF50
/* 66B6A8 80219928 E7B60018 */   swc1     $f22, 0x18($sp)
/* 66B6AC 8021992C 0040202D */  daddu     $a0, $v0, $zero
/* 66B6B0 80219930 82030210 */  lb        $v1, 0x210($s0)
/* 66B6B4 80219934 2402000A */  addiu     $v0, $zero, 0xa
/* 66B6B8 80219938 14620007 */  bne       $v1, $v0, .L80219958
/* 66B6BC 8021993C 00000000 */   nop      
/* 66B6C0 80219940 8C82000C */  lw        $v0, 0xc($a0)
/* 66B6C4 80219944 3C013ECC */  lui       $at, 0x3ecc
/* 66B6C8 80219948 3421CCCD */  ori       $at, $at, 0xcccd
/* 66B6CC 8021994C 44810000 */  mtc1      $at, $f0
/* 66B6D0 80219950 00000000 */  nop       
/* 66B6D4 80219954 E4400028 */  swc1      $f0, 0x28($v0)
.L80219958:
/* 66B6D8 80219958 8FBF0028 */  lw        $ra, 0x28($sp)
/* 66B6DC 8021995C 8FB10024 */  lw        $s1, 0x24($sp)
/* 66B6E0 80219960 8FB00020 */  lw        $s0, 0x20($sp)
/* 66B6E4 80219964 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 66B6E8 80219968 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 66B6EC 8021996C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 66B6F0 80219970 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 66B6F4 80219974 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 66B6F8 80219978 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 66B6FC 8021997C 24020002 */  addiu     $v0, $zero, 2
/* 66B700 80219980 03E00008 */  jr        $ra
/* 66B704 80219984 27BD0060 */   addiu    $sp, $sp, 0x60
