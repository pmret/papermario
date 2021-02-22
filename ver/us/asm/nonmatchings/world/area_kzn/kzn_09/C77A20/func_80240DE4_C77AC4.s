.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE4_C77AC4
/* C77AC4 80240DE4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C77AC8 80240DE8 AFB1001C */  sw        $s1, 0x1c($sp)
/* C77ACC 80240DEC 0080882D */  daddu     $s1, $a0, $zero
/* C77AD0 80240DF0 AFBF0020 */  sw        $ra, 0x20($sp)
/* C77AD4 80240DF4 AFB00018 */  sw        $s0, 0x18($sp)
/* C77AD8 80240DF8 8E30000C */  lw        $s0, 0xc($s1)
/* C77ADC 80240DFC 8E020000 */  lw        $v0, ($s0)
/* C77AE0 80240E00 1040001B */  beqz      $v0, .L80240E70
/* C77AE4 80240E04 26100004 */   addiu    $s0, $s0, 4
/* C77AE8 80240E08 8E050000 */  lw        $a1, ($s0)
/* C77AEC 80240E0C 0C0B1EAF */  jal       get_variable
/* C77AF0 80240E10 26100004 */   addiu    $s0, $s0, 4
/* C77AF4 80240E14 AE220070 */  sw        $v0, 0x70($s1)
/* C77AF8 80240E18 8E050000 */  lw        $a1, ($s0)
/* C77AFC 80240E1C 26100004 */  addiu     $s0, $s0, 4
/* C77B00 80240E20 0C0B1EAF */  jal       get_variable
/* C77B04 80240E24 0220202D */   daddu    $a0, $s1, $zero
/* C77B08 80240E28 AE220074 */  sw        $v0, 0x74($s1)
/* C77B0C 80240E2C 8E050000 */  lw        $a1, ($s0)
/* C77B10 80240E30 0C0B1EAF */  jal       get_variable
/* C77B14 80240E34 0220202D */   daddu    $a0, $s1, $zero
/* C77B18 80240E38 24040185 */  addiu     $a0, $zero, 0x185
/* C77B1C 80240E3C 0000282D */  daddu     $a1, $zero, $zero
/* C77B20 80240E40 C6200070 */  lwc1      $f0, 0x70($s1)
/* C77B24 80240E44 46800020 */  cvt.s.w   $f0, $f0
/* C77B28 80240E48 C6220074 */  lwc1      $f2, 0x74($s1)
/* C77B2C 80240E4C 468010A0 */  cvt.s.w   $f2, $f2
/* C77B30 80240E50 44060000 */  mfc1      $a2, $f0
/* C77B34 80240E54 44071000 */  mfc1      $a3, $f2
/* C77B38 80240E58 44820000 */  mtc1      $v0, $f0
/* C77B3C 80240E5C 00000000 */  nop
/* C77B40 80240E60 46800020 */  cvt.s.w   $f0, $f0
/* C77B44 80240E64 AE220078 */  sw        $v0, 0x78($s1)
/* C77B48 80240E68 0C05267B */  jal       func_801499EC
/* C77B4C 80240E6C E7A00010 */   swc1     $f0, 0x10($sp)
.L80240E70:
/* C77B50 80240E70 8FBF0020 */  lw        $ra, 0x20($sp)
/* C77B54 80240E74 8FB1001C */  lw        $s1, 0x1c($sp)
/* C77B58 80240E78 8FB00018 */  lw        $s0, 0x18($sp)
/* C77B5C 80240E7C 24020002 */  addiu     $v0, $zero, 2
/* C77B60 80240E80 03E00008 */  jr        $ra
/* C77B64 80240E84 27BD0028 */   addiu    $sp, $sp, 0x28
