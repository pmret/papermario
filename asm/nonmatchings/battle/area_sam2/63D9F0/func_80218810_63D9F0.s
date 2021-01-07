.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218810_63D9F0
/* 63D9F0 80218810 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 63D9F4 80218814 AFB10024 */  sw        $s1, 0x24($sp)
/* 63D9F8 80218818 0080882D */  daddu     $s1, $a0, $zero
/* 63D9FC 8021881C AFBF0028 */  sw        $ra, 0x28($sp)
/* 63DA00 80218820 AFB00020 */  sw        $s0, 0x20($sp)
/* 63DA04 80218824 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 63DA08 80218828 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 63DA0C 8021882C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 63DA10 80218830 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 63DA14 80218834 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 63DA18 80218838 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 63DA1C 8021883C 8E30000C */  lw        $s0, 0xc($s1)
/* 63DA20 80218840 8E050000 */  lw        $a1, ($s0)
/* 63DA24 80218844 0C0B210B */  jal       get_float_variable
/* 63DA28 80218848 26100004 */   addiu    $s0, $s0, 4
/* 63DA2C 8021884C 8E050000 */  lw        $a1, ($s0)
/* 63DA30 80218850 26100004 */  addiu     $s0, $s0, 4
/* 63DA34 80218854 0220202D */  daddu     $a0, $s1, $zero
/* 63DA38 80218858 0C0B210B */  jal       get_float_variable
/* 63DA3C 8021885C 46000786 */   mov.s    $f30, $f0
/* 63DA40 80218860 8E050000 */  lw        $a1, ($s0)
/* 63DA44 80218864 26100004 */  addiu     $s0, $s0, 4
/* 63DA48 80218868 0220202D */  daddu     $a0, $s1, $zero
/* 63DA4C 8021886C 0C0B210B */  jal       get_float_variable
/* 63DA50 80218870 46000506 */   mov.s    $f20, $f0
/* 63DA54 80218874 8E050000 */  lw        $a1, ($s0)
/* 63DA58 80218878 26100004 */  addiu     $s0, $s0, 4
/* 63DA5C 8021887C 0220202D */  daddu     $a0, $s1, $zero
/* 63DA60 80218880 0C0B210B */  jal       get_float_variable
/* 63DA64 80218884 46000706 */   mov.s    $f28, $f0
/* 63DA68 80218888 8E050000 */  lw        $a1, ($s0)
/* 63DA6C 8021888C 26100004 */  addiu     $s0, $s0, 4
/* 63DA70 80218890 0220202D */  daddu     $a0, $s1, $zero
/* 63DA74 80218894 0C0B210B */  jal       get_float_variable
/* 63DA78 80218898 46000686 */   mov.s    $f26, $f0
/* 63DA7C 8021889C 8E050000 */  lw        $a1, ($s0)
/* 63DA80 802188A0 26100004 */  addiu     $s0, $s0, 4
/* 63DA84 802188A4 0220202D */  daddu     $a0, $s1, $zero
/* 63DA88 802188A8 0C0B210B */  jal       get_float_variable
/* 63DA8C 802188AC 46000606 */   mov.s    $f24, $f0
/* 63DA90 802188B0 0220202D */  daddu     $a0, $s1, $zero
/* 63DA94 802188B4 8E050000 */  lw        $a1, ($s0)
/* 63DA98 802188B8 0C0B1EAF */  jal       get_variable
/* 63DA9C 802188BC 46000586 */   mov.s    $f22, $f0
/* 63DAA0 802188C0 8E240148 */  lw        $a0, 0x148($s1)
/* 63DAA4 802188C4 0C09A75B */  jal       get_actor
/* 63DAA8 802188C8 0040802D */   daddu    $s0, $v0, $zero
/* 63DAAC 802188CC 4600A521 */  cvt.d.s   $f20, $f20
/* 63DAB0 802188D0 4405F000 */  mfc1      $a1, $f30
/* 63DAB4 802188D4 3C014014 */  lui       $at, 0x4014
/* 63DAB8 802188D8 44810800 */  mtc1      $at, $f1
/* 63DABC 802188DC 44800000 */  mtc1      $zero, $f0
/* 63DAC0 802188E0 4407E000 */  mfc1      $a3, $f28
/* 63DAC4 802188E4 4620A500 */  add.d     $f20, $f20, $f0
/* 63DAC8 802188E8 0000202D */  daddu     $a0, $zero, $zero
/* 63DACC 802188EC AFB0001C */  sw        $s0, 0x1c($sp)
/* 63DAD0 802188F0 4620A520 */  cvt.s.d   $f20, $f20
/* 63DAD4 802188F4 4406A000 */  mfc1      $a2, $f20
/* 63DAD8 802188F8 0040802D */  daddu     $s0, $v0, $zero
/* 63DADC 802188FC E7BA0010 */  swc1      $f26, 0x10($sp)
/* 63DAE0 80218900 E7B80014 */  swc1      $f24, 0x14($sp)
/* 63DAE4 80218904 0C01BFD4 */  jal       func_8006FF50
/* 63DAE8 80218908 E7B60018 */   swc1     $f22, 0x18($sp)
/* 63DAEC 8021890C 0040202D */  daddu     $a0, $v0, $zero
/* 63DAF0 80218910 82030210 */  lb        $v1, 0x210($s0)
/* 63DAF4 80218914 2402000A */  addiu     $v0, $zero, 0xa
/* 63DAF8 80218918 14620007 */  bne       $v1, $v0, .L80218938
/* 63DAFC 8021891C 00000000 */   nop      
/* 63DB00 80218920 8C82000C */  lw        $v0, 0xc($a0)
/* 63DB04 80218924 3C013ECC */  lui       $at, 0x3ecc
/* 63DB08 80218928 3421CCCD */  ori       $at, $at, 0xcccd
/* 63DB0C 8021892C 44810000 */  mtc1      $at, $f0
/* 63DB10 80218930 00000000 */  nop       
/* 63DB14 80218934 E4400028 */  swc1      $f0, 0x28($v0)
.L80218938:
/* 63DB18 80218938 8FBF0028 */  lw        $ra, 0x28($sp)
/* 63DB1C 8021893C 8FB10024 */  lw        $s1, 0x24($sp)
/* 63DB20 80218940 8FB00020 */  lw        $s0, 0x20($sp)
/* 63DB24 80218944 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 63DB28 80218948 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 63DB2C 8021894C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 63DB30 80218950 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 63DB34 80218954 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 63DB38 80218958 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 63DB3C 8021895C 24020002 */  addiu     $v0, $zero, 2
/* 63DB40 80218960 03E00008 */  jr        $ra
/* 63DB44 80218964 27BD0060 */   addiu    $sp, $sp, 0x60
