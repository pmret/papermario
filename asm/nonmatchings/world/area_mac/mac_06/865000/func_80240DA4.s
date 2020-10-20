.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA4
/* 8658E4 80240DA4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8658E8 80240DA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 8658EC 80240DAC 0080882D */  daddu     $s1, $a0, $zero
/* 8658F0 80240DB0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8658F4 80240DB4 AFB20018 */  sw        $s2, 0x18($sp)
/* 8658F8 80240DB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8658FC 80240DBC F7B60028 */  sdc1      $f22, 0x28($sp)
/* 865900 80240DC0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 865904 80240DC4 8E30000C */  lw        $s0, 0xc($s1)
/* 865908 80240DC8 8E050000 */  lw        $a1, ($s0)
/* 86590C 80240DCC 0C0B1EAF */  jal       get_variable
/* 865910 80240DD0 26100004 */   addiu    $s0, $s0, 4
/* 865914 80240DD4 8E050000 */  lw        $a1, ($s0)
/* 865918 80240DD8 26100004 */  addiu     $s0, $s0, 4
/* 86591C 80240DDC 0220202D */  daddu     $a0, $s1, $zero
/* 865920 80240DE0 0C0B210B */  jal       get_float_variable
/* 865924 80240DE4 0040902D */   daddu    $s2, $v0, $zero
/* 865928 80240DE8 8E050000 */  lw        $a1, ($s0)
/* 86592C 80240DEC 26100004 */  addiu     $s0, $s0, 4
/* 865930 80240DF0 0220202D */  daddu     $a0, $s1, $zero
/* 865934 80240DF4 0C0B210B */  jal       get_float_variable
/* 865938 80240DF8 46000586 */   mov.s    $f22, $f0
/* 86593C 80240DFC 0220202D */  daddu     $a0, $s1, $zero
/* 865940 80240E00 8E050000 */  lw        $a1, ($s0)
/* 865944 80240E04 0C0B210B */  jal       get_float_variable
/* 865948 80240E08 46000506 */   mov.s    $f20, $f0
/* 86594C 80240E0C 8E42000C */  lw        $v0, 0xc($s2)
/* 865950 80240E10 E4560008 */  swc1      $f22, 8($v0)
/* 865954 80240E14 8E42000C */  lw        $v0, 0xc($s2)
/* 865958 80240E18 E454000C */  swc1      $f20, 0xc($v0)
/* 86595C 80240E1C 8E43000C */  lw        $v1, 0xc($s2)
/* 865960 80240E20 E4600010 */  swc1      $f0, 0x10($v1)
/* 865964 80240E24 8FBF001C */  lw        $ra, 0x1c($sp)
/* 865968 80240E28 8FB20018 */  lw        $s2, 0x18($sp)
/* 86596C 80240E2C 8FB10014 */  lw        $s1, 0x14($sp)
/* 865970 80240E30 8FB00010 */  lw        $s0, 0x10($sp)
/* 865974 80240E34 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 865978 80240E38 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 86597C 80240E3C 24020002 */  addiu     $v0, $zero, 2
/* 865980 80240E40 03E00008 */  jr        $ra
/* 865984 80240E44 27BD0030 */   addiu    $sp, $sp, 0x30
