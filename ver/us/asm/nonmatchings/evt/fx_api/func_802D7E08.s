.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7E08
/* FC7B8 802D7E08 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* FC7BC 802D7E0C AFB10024 */  sw        $s1, 0x24($sp)
/* FC7C0 802D7E10 0080882D */  daddu     $s1, $a0, $zero
/* FC7C4 802D7E14 AFBF0034 */  sw        $ra, 0x34($sp)
/* FC7C8 802D7E18 AFB40030 */  sw        $s4, 0x30($sp)
/* FC7CC 802D7E1C AFB3002C */  sw        $s3, 0x2c($sp)
/* FC7D0 802D7E20 AFB20028 */  sw        $s2, 0x28($sp)
/* FC7D4 802D7E24 AFB00020 */  sw        $s0, 0x20($sp)
/* FC7D8 802D7E28 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* FC7DC 802D7E2C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* FC7E0 802D7E30 F7B80048 */  sdc1      $f24, 0x48($sp)
/* FC7E4 802D7E34 F7B60040 */  sdc1      $f22, 0x40($sp)
/* FC7E8 802D7E38 F7B40038 */  sdc1      $f20, 0x38($sp)
/* FC7EC 802D7E3C 8E30000C */  lw        $s0, 0xc($s1)
/* FC7F0 802D7E40 8E050000 */  lw        $a1, ($s0)
/* FC7F4 802D7E44 0C0B1EAF */  jal       evt_get_variable
/* FC7F8 802D7E48 26100004 */   addiu    $s0, $s0, 4
/* FC7FC 802D7E4C 8E050000 */  lw        $a1, ($s0)
/* FC800 802D7E50 26100004 */  addiu     $s0, $s0, 4
/* FC804 802D7E54 0220202D */  daddu     $a0, $s1, $zero
/* FC808 802D7E58 0C0B1EAF */  jal       evt_get_variable
/* FC80C 802D7E5C 0040982D */   daddu    $s3, $v0, $zero
/* FC810 802D7E60 8E050000 */  lw        $a1, ($s0)
/* FC814 802D7E64 26100004 */  addiu     $s0, $s0, 4
/* FC818 802D7E68 0220202D */  daddu     $a0, $s1, $zero
/* FC81C 802D7E6C 0C0B210B */  jal       evt_get_float_variable
/* FC820 802D7E70 0040A02D */   daddu    $s4, $v0, $zero
/* FC824 802D7E74 8E050000 */  lw        $a1, ($s0)
/* FC828 802D7E78 26100004 */  addiu     $s0, $s0, 4
/* FC82C 802D7E7C 0220202D */  daddu     $a0, $s1, $zero
/* FC830 802D7E80 0C0B1EAF */  jal       evt_get_variable
/* FC834 802D7E84 46000706 */   mov.s    $f28, $f0
/* FC838 802D7E88 8E050000 */  lw        $a1, ($s0)
/* FC83C 802D7E8C 26100004 */  addiu     $s0, $s0, 4
/* FC840 802D7E90 0220202D */  daddu     $a0, $s1, $zero
/* FC844 802D7E94 0C0B210B */  jal       evt_get_float_variable
/* FC848 802D7E98 0040902D */   daddu    $s2, $v0, $zero
/* FC84C 802D7E9C 8E050000 */  lw        $a1, ($s0)
/* FC850 802D7EA0 26100004 */  addiu     $s0, $s0, 4
/* FC854 802D7EA4 0220202D */  daddu     $a0, $s1, $zero
/* FC858 802D7EA8 0C0B210B */  jal       evt_get_float_variable
/* FC85C 802D7EAC 46000686 */   mov.s    $f26, $f0
/* FC860 802D7EB0 8E050000 */  lw        $a1, ($s0)
/* FC864 802D7EB4 26100004 */  addiu     $s0, $s0, 4
/* FC868 802D7EB8 0220202D */  daddu     $a0, $s1, $zero
/* FC86C 802D7EBC 0C0B210B */  jal       evt_get_float_variable
/* FC870 802D7EC0 46000606 */   mov.s    $f24, $f0
/* FC874 802D7EC4 8E050000 */  lw        $a1, ($s0)
/* FC878 802D7EC8 26100004 */  addiu     $s0, $s0, 4
/* FC87C 802D7ECC 0220202D */  daddu     $a0, $s1, $zero
/* FC880 802D7ED0 0C0B210B */  jal       evt_get_float_variable
/* FC884 802D7ED4 46000586 */   mov.s    $f22, $f0
/* FC888 802D7ED8 0220202D */  daddu     $a0, $s1, $zero
/* FC88C 802D7EDC 8E050000 */  lw        $a1, ($s0)
/* FC890 802D7EE0 0C0B1EAF */  jal       evt_get_variable
/* FC894 802D7EE4 46000506 */   mov.s    $f20, $f0
/* FC898 802D7EE8 12400006 */  beqz      $s2, .L802D7F04
/* FC89C 802D7EEC 0040802D */   daddu    $s0, $v0, $zero
/* FC8A0 802D7EF0 24020001 */  addiu     $v0, $zero, 1
/* FC8A4 802D7EF4 12420014 */  beq       $s2, $v0, .L802D7F48
/* FC8A8 802D7EF8 4600D206 */   mov.s    $f8, $f26
/* FC8AC 802D7EFC 080B5FF2 */  j         .L802D7FC8
/* FC8B0 802D7F00 4600C006 */   mov.s    $f0, $f24
.L802D7F04:
/* FC8B4 802D7F04 3C055555 */  lui       $a1, 0x5555
/* FC8B8 802D7F08 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* FC8BC 802D7F0C 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* FC8C0 802D7F10 948200B0 */  lhu       $v0, 0xb0($a0)
/* FC8C4 802D7F14 34A55556 */  ori       $a1, $a1, 0x5556
/* FC8C8 802D7F18 00021400 */  sll       $v0, $v0, 0x10
/* FC8CC 802D7F1C 00021C03 */  sra       $v1, $v0, 0x10
/* FC8D0 802D7F20 00650018 */  mult      $v1, $a1
/* FC8D4 802D7F24 C4880028 */  lwc1      $f8, 0x28($a0)
/* FC8D8 802D7F28 C4860030 */  lwc1      $f6, 0x30($a0)
/* FC8DC 802D7F2C C482002C */  lwc1      $f2, 0x2c($a0)
/* FC8E0 802D7F30 00031840 */  sll       $v1, $v1, 1
/* FC8E4 802D7F34 00004010 */  mfhi      $t0
/* FC8E8 802D7F38 000217C3 */  sra       $v0, $v0, 0x1f
/* FC8EC 802D7F3C 01021023 */  subu      $v0, $t0, $v0
/* FC8F0 802D7F40 080B5FE5 */  j         .L802D7F94
/* FC8F4 802D7F44 00650018 */   mult     $v1, $a1
.L802D7F48:
/* FC8F8 802D7F48 0220202D */  daddu     $a0, $s1, $zero
/* FC8FC 802D7F4C 0C0B36B0 */  jal       resolve_npc
/* FC900 802D7F50 0260282D */   daddu    $a1, $s3, $zero
/* FC904 802D7F54 0040282D */  daddu     $a1, $v0, $zero
/* FC908 802D7F58 10A00025 */  beqz      $a1, .L802D7FF0
/* FC90C 802D7F5C 3C045555 */   lui      $a0, 0x5555
/* FC910 802D7F60 94A200A8 */  lhu       $v0, 0xa8($a1)
/* FC914 802D7F64 34845556 */  ori       $a0, $a0, 0x5556
/* FC918 802D7F68 00021400 */  sll       $v0, $v0, 0x10
/* FC91C 802D7F6C 00021C03 */  sra       $v1, $v0, 0x10
/* FC920 802D7F70 00640018 */  mult      $v1, $a0
/* FC924 802D7F74 C4A80038 */  lwc1      $f8, 0x38($a1)
/* FC928 802D7F78 C4A60040 */  lwc1      $f6, 0x40($a1)
/* FC92C 802D7F7C C4A2003C */  lwc1      $f2, 0x3c($a1)
/* FC930 802D7F80 00031840 */  sll       $v1, $v1, 1
/* FC934 802D7F84 00004010 */  mfhi      $t0
/* FC938 802D7F88 000217C3 */  sra       $v0, $v0, 0x1f
/* FC93C 802D7F8C 01021023 */  subu      $v0, $t0, $v0
/* FC940 802D7F90 00640018 */  mult      $v1, $a0
.L802D7F94:
/* FC944 802D7F94 00021400 */  sll       $v0, $v0, 0x10
/* FC948 802D7F98 00021403 */  sra       $v0, $v0, 0x10
/* FC94C 802D7F9C 44822000 */  mtc1      $v0, $f4
/* FC950 802D7FA0 00000000 */  nop
/* FC954 802D7FA4 46802120 */  cvt.s.w   $f4, $f4
/* FC958 802D7FA8 00031FC3 */  sra       $v1, $v1, 0x1f
/* FC95C 802D7FAC 00004010 */  mfhi      $t0
/* FC960 802D7FB0 01031823 */  subu      $v1, $t0, $v1
/* FC964 802D7FB4 44830000 */  mtc1      $v1, $f0
/* FC968 802D7FB8 00000000 */  nop
/* FC96C 802D7FBC 46800020 */  cvt.s.w   $f0, $f0
/* FC970 802D7FC0 080B5FF4 */  j         .L802D7FD0
/* FC974 802D7FC4 46001000 */   add.s    $f0, $f2, $f0
.L802D7FC8:
/* FC978 802D7FC8 4600B186 */  mov.s     $f6, $f22
/* FC97C 802D7FCC 4600A106 */  mov.s     $f4, $f20
.L802D7FD0:
/* FC980 802D7FD0 44054000 */  mfc1      $a1, $f8
/* FC984 802D7FD4 44060000 */  mfc1      $a2, $f0
/* FC988 802D7FD8 44073000 */  mfc1      $a3, $f6
/* FC98C 802D7FDC 0280202D */  daddu     $a0, $s4, $zero
/* FC990 802D7FE0 E7A40010 */  swc1      $f4, 0x10($sp)
/* FC994 802D7FE4 E7BC0014 */  swc1      $f28, 0x14($sp)
/* FC998 802D7FE8 0C01C1E4 */  jal       fx_sweat
/* FC99C 802D7FEC AFB00018 */   sw       $s0, 0x18($sp)
.L802D7FF0:
/* FC9A0 802D7FF0 24020002 */  addiu     $v0, $zero, 2
/* FC9A4 802D7FF4 8FBF0034 */  lw        $ra, 0x34($sp)
/* FC9A8 802D7FF8 8FB40030 */  lw        $s4, 0x30($sp)
/* FC9AC 802D7FFC 8FB3002C */  lw        $s3, 0x2c($sp)
/* FC9B0 802D8000 8FB20028 */  lw        $s2, 0x28($sp)
/* FC9B4 802D8004 8FB10024 */  lw        $s1, 0x24($sp)
/* FC9B8 802D8008 8FB00020 */  lw        $s0, 0x20($sp)
/* FC9BC 802D800C D7BC0058 */  ldc1      $f28, 0x58($sp)
/* FC9C0 802D8010 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* FC9C4 802D8014 D7B80048 */  ldc1      $f24, 0x48($sp)
/* FC9C8 802D8018 D7B60040 */  ldc1      $f22, 0x40($sp)
/* FC9CC 802D801C D7B40038 */  ldc1      $f20, 0x38($sp)
/* FC9D0 802D8020 03E00008 */  jr        $ra
/* FC9D4 802D8024 27BD0060 */   addiu    $sp, $sp, 0x60
