.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A10880
/* A10880 80240000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A10884 80240004 AFB1002C */  sw        $s1, 0x2c($sp)
/* A10888 80240008 0080882D */  daddu     $s1, $a0, $zero
/* A1088C 8024000C AFBF0030 */  sw        $ra, 0x30($sp)
/* A10890 80240010 AFB00028 */  sw        $s0, 0x28($sp)
/* A10894 80240014 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A10898 80240018 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A1089C 8024001C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A108A0 80240020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* A108A4 80240024 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A108A8 80240028 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A108AC 8024002C 8E30000C */  lw        $s0, 0xc($s1)
/* A108B0 80240030 8E050000 */  lw        $a1, ($s0)
/* A108B4 80240034 0C0B210B */  jal       evt_get_float_variable
/* A108B8 80240038 26100004 */   addiu    $s0, $s0, 4
/* A108BC 8024003C 8E050000 */  lw        $a1, ($s0)
/* A108C0 80240040 26100004 */  addiu     $s0, $s0, 4
/* A108C4 80240044 0220202D */  daddu     $a0, $s1, $zero
/* A108C8 80240048 0C0B210B */  jal       evt_get_float_variable
/* A108CC 8024004C E7A00020 */   swc1     $f0, 0x20($sp)
/* A108D0 80240050 8E050000 */  lw        $a1, ($s0)
/* A108D4 80240054 26100004 */  addiu     $s0, $s0, 4
/* A108D8 80240058 0220202D */  daddu     $a0, $s1, $zero
/* A108DC 8024005C 0C0B210B */  jal       evt_get_float_variable
/* A108E0 80240060 46000786 */   mov.s    $f30, $f0
/* A108E4 80240064 8E050000 */  lw        $a1, ($s0)
/* A108E8 80240068 26100004 */  addiu     $s0, $s0, 4
/* A108EC 8024006C 0220202D */  daddu     $a0, $s1, $zero
/* A108F0 80240070 0C0B210B */  jal       evt_get_float_variable
/* A108F4 80240074 46000706 */   mov.s    $f28, $f0
/* A108F8 80240078 8E050000 */  lw        $a1, ($s0)
/* A108FC 8024007C 26100004 */  addiu     $s0, $s0, 4
/* A10900 80240080 0220202D */  daddu     $a0, $s1, $zero
/* A10904 80240084 0C0B210B */  jal       evt_get_float_variable
/* A10908 80240088 46000686 */   mov.s    $f26, $f0
/* A1090C 8024008C 8E050000 */  lw        $a1, ($s0)
/* A10910 80240090 26100004 */  addiu     $s0, $s0, 4
/* A10914 80240094 0220202D */  daddu     $a0, $s1, $zero
/* A10918 80240098 0C0B210B */  jal       evt_get_float_variable
/* A1091C 8024009C 46000606 */   mov.s    $f24, $f0
/* A10920 802400A0 8E050000 */  lw        $a1, ($s0)
/* A10924 802400A4 26100004 */  addiu     $s0, $s0, 4
/* A10928 802400A8 0220202D */  daddu     $a0, $s1, $zero
/* A1092C 802400AC 0C0B210B */  jal       evt_get_float_variable
/* A10930 802400B0 46000586 */   mov.s    $f22, $f0
/* A10934 802400B4 0220202D */  daddu     $a0, $s1, $zero
/* A10938 802400B8 8E050000 */  lw        $a1, ($s0)
/* A1093C 802400BC 0C0B210B */  jal       evt_get_float_variable
/* A10940 802400C0 46000506 */   mov.s    $f20, $f0
/* A10944 802400C4 4405F000 */  mfc1      $a1, $f30
/* A10948 802400C8 4406E000 */  mfc1      $a2, $f28
/* A1094C 802400CC 4407D000 */  mfc1      $a3, $f26
/* A10950 802400D0 C7A20020 */  lwc1      $f2, 0x20($sp)
/* A10954 802400D4 E7B80010 */  swc1      $f24, 0x10($sp)
/* A10958 802400D8 E7B60014 */  swc1      $f22, 0x14($sp)
/* A1095C 802400DC E7B40018 */  swc1      $f20, 0x18($sp)
/* A10960 802400E0 4600108D */  trunc.w.s $f2, $f2
/* A10964 802400E4 44041000 */  mfc1      $a0, $f2
/* A10968 802400E8 0C01BF8C */  jal       playFX_0F
/* A1096C 802400EC E7A0001C */   swc1     $f0, 0x1c($sp)
/* A10970 802400F0 8FBF0030 */  lw        $ra, 0x30($sp)
/* A10974 802400F4 8FB1002C */  lw        $s1, 0x2c($sp)
/* A10978 802400F8 8FB00028 */  lw        $s0, 0x28($sp)
/* A1097C 802400FC D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A10980 80240100 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A10984 80240104 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A10988 80240108 D7B80048 */  ldc1      $f24, 0x48($sp)
/* A1098C 8024010C D7B60040 */  ldc1      $f22, 0x40($sp)
/* A10990 80240110 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A10994 80240114 24020002 */  addiu     $v0, $zero, 2
/* A10998 80240118 03E00008 */  jr        $ra
/* A1099C 8024011C 27BD0068 */   addiu    $sp, $sp, 0x68
