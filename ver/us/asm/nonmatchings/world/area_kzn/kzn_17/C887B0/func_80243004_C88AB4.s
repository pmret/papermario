.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243004_C88AB4
/* C88AB4 80243004 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C88AB8 80243008 AFB1001C */  sw        $s1, 0x1c($sp)
/* C88ABC 8024300C 0080882D */  daddu     $s1, $a0, $zero
/* C88AC0 80243010 AFBF0020 */  sw        $ra, 0x20($sp)
/* C88AC4 80243014 AFB00018 */  sw        $s0, 0x18($sp)
/* C88AC8 80243018 8E30000C */  lw        $s0, 0xc($s1)
/* C88ACC 8024301C 8E050000 */  lw        $a1, ($s0)
/* C88AD0 80243020 0C0B1EAF */  jal       get_variable
/* C88AD4 80243024 26100004 */   addiu    $s0, $s0, 4
/* C88AD8 80243028 AE220070 */  sw        $v0, 0x70($s1)
/* C88ADC 8024302C 8E050000 */  lw        $a1, ($s0)
/* C88AE0 80243030 26100004 */  addiu     $s0, $s0, 4
/* C88AE4 80243034 0C0B1EAF */  jal       get_variable
/* C88AE8 80243038 0220202D */   daddu    $a0, $s1, $zero
/* C88AEC 8024303C AE220074 */  sw        $v0, 0x74($s1)
/* C88AF0 80243040 8E050000 */  lw        $a1, ($s0)
/* C88AF4 80243044 0C0B1EAF */  jal       get_variable
/* C88AF8 80243048 0220202D */   daddu    $a0, $s1, $zero
/* C88AFC 8024304C 24040052 */  addiu     $a0, $zero, 0x52
/* C88B00 80243050 0000282D */  daddu     $a1, $zero, $zero
/* C88B04 80243054 C6200070 */  lwc1      $f0, 0x70($s1)
/* C88B08 80243058 46800020 */  cvt.s.w   $f0, $f0
/* C88B0C 8024305C C6220074 */  lwc1      $f2, 0x74($s1)
/* C88B10 80243060 468010A0 */  cvt.s.w   $f2, $f2
/* C88B14 80243064 44060000 */  mfc1      $a2, $f0
/* C88B18 80243068 44071000 */  mfc1      $a3, $f2
/* C88B1C 8024306C 44820000 */  mtc1      $v0, $f0
/* C88B20 80243070 00000000 */  nop
/* C88B24 80243074 46800020 */  cvt.s.w   $f0, $f0
/* C88B28 80243078 AE220078 */  sw        $v0, 0x78($s1)
/* C88B2C 8024307C 0C05267B */  jal       sfx_adjust_env_sound_pos
/* C88B30 80243080 E7A00010 */   swc1     $f0, 0x10($sp)
/* C88B34 80243084 8FBF0020 */  lw        $ra, 0x20($sp)
/* C88B38 80243088 8FB1001C */  lw        $s1, 0x1c($sp)
/* C88B3C 8024308C 8FB00018 */  lw        $s0, 0x18($sp)
/* C88B40 80243090 24020002 */  addiu     $v0, $zero, 2
/* C88B44 80243094 03E00008 */  jr        $ra
/* C88B48 80243098 27BD0028 */   addiu    $sp, $sp, 0x28
/* C88B4C 8024309C 00000000 */  nop
