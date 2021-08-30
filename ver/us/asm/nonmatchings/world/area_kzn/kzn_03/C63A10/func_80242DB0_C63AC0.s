.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DB0_C63AC0
/* C63AC0 80242DB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C63AC4 80242DB4 AFB1001C */  sw        $s1, 0x1c($sp)
/* C63AC8 80242DB8 0080882D */  daddu     $s1, $a0, $zero
/* C63ACC 80242DBC AFBF0020 */  sw        $ra, 0x20($sp)
/* C63AD0 80242DC0 AFB00018 */  sw        $s0, 0x18($sp)
/* C63AD4 80242DC4 8E30000C */  lw        $s0, 0xc($s1)
/* C63AD8 80242DC8 8E020000 */  lw        $v0, ($s0)
/* C63ADC 80242DCC 1040001B */  beqz      $v0, .L80242E3C
/* C63AE0 80242DD0 26100004 */   addiu    $s0, $s0, 4
/* C63AE4 80242DD4 8E050000 */  lw        $a1, ($s0)
/* C63AE8 80242DD8 0C0B1EAF */  jal       evt_get_variable
/* C63AEC 80242DDC 26100004 */   addiu    $s0, $s0, 4
/* C63AF0 80242DE0 AE220070 */  sw        $v0, 0x70($s1)
/* C63AF4 80242DE4 8E050000 */  lw        $a1, ($s0)
/* C63AF8 80242DE8 26100004 */  addiu     $s0, $s0, 4
/* C63AFC 80242DEC 0C0B1EAF */  jal       evt_get_variable
/* C63B00 80242DF0 0220202D */   daddu    $a0, $s1, $zero
/* C63B04 80242DF4 AE220074 */  sw        $v0, 0x74($s1)
/* C63B08 80242DF8 8E050000 */  lw        $a1, ($s0)
/* C63B0C 80242DFC 0C0B1EAF */  jal       evt_get_variable
/* C63B10 80242E00 0220202D */   daddu    $a0, $s1, $zero
/* C63B14 80242E04 24040168 */  addiu     $a0, $zero, 0x168
/* C63B18 80242E08 0000282D */  daddu     $a1, $zero, $zero
/* C63B1C 80242E0C C6200070 */  lwc1      $f0, 0x70($s1)
/* C63B20 80242E10 46800020 */  cvt.s.w   $f0, $f0
/* C63B24 80242E14 C6220074 */  lwc1      $f2, 0x74($s1)
/* C63B28 80242E18 468010A0 */  cvt.s.w   $f2, $f2
/* C63B2C 80242E1C 44060000 */  mfc1      $a2, $f0
/* C63B30 80242E20 44071000 */  mfc1      $a3, $f2
/* C63B34 80242E24 44820000 */  mtc1      $v0, $f0
/* C63B38 80242E28 00000000 */  nop
/* C63B3C 80242E2C 46800020 */  cvt.s.w   $f0, $f0
/* C63B40 80242E30 AE220078 */  sw        $v0, 0x78($s1)
/* C63B44 80242E34 0C05267B */  jal       sfx_adjust_env_sound_pos
/* C63B48 80242E38 E7A00010 */   swc1     $f0, 0x10($sp)
.L80242E3C:
/* C63B4C 80242E3C 8FBF0020 */  lw        $ra, 0x20($sp)
/* C63B50 80242E40 8FB1001C */  lw        $s1, 0x1c($sp)
/* C63B54 80242E44 8FB00018 */  lw        $s0, 0x18($sp)
/* C63B58 80242E48 24020002 */  addiu     $v0, $zero, 2
/* C63B5C 80242E4C 03E00008 */  jr        $ra
/* C63B60 80242E50 27BD0028 */   addiu    $sp, $sp, 0x28
