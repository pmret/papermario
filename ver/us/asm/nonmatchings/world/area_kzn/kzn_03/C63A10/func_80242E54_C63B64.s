.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E54_C63B64
/* C63B64 80242E54 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C63B68 80242E58 AFB1001C */  sw        $s1, 0x1c($sp)
/* C63B6C 80242E5C 0080882D */  daddu     $s1, $a0, $zero
/* C63B70 80242E60 AFBF0020 */  sw        $ra, 0x20($sp)
/* C63B74 80242E64 AFB00018 */  sw        $s0, 0x18($sp)
/* C63B78 80242E68 8E30000C */  lw        $s0, 0xc($s1)
/* C63B7C 80242E6C 8E020000 */  lw        $v0, ($s0)
/* C63B80 80242E70 1040001B */  beqz      $v0, .L80242EE0
/* C63B84 80242E74 26100004 */   addiu    $s0, $s0, 4
/* C63B88 80242E78 8E050000 */  lw        $a1, ($s0)
/* C63B8C 80242E7C 0C0B1EAF */  jal       evt_get_variable
/* C63B90 80242E80 26100004 */   addiu    $s0, $s0, 4
/* C63B94 80242E84 AE220070 */  sw        $v0, 0x70($s1)
/* C63B98 80242E88 8E050000 */  lw        $a1, ($s0)
/* C63B9C 80242E8C 26100004 */  addiu     $s0, $s0, 4
/* C63BA0 80242E90 0C0B1EAF */  jal       evt_get_variable
/* C63BA4 80242E94 0220202D */   daddu    $a0, $s1, $zero
/* C63BA8 80242E98 AE220074 */  sw        $v0, 0x74($s1)
/* C63BAC 80242E9C 8E050000 */  lw        $a1, ($s0)
/* C63BB0 80242EA0 0C0B1EAF */  jal       evt_get_variable
/* C63BB4 80242EA4 0220202D */   daddu    $a0, $s1, $zero
/* C63BB8 80242EA8 24040185 */  addiu     $a0, $zero, 0x185
/* C63BBC 80242EAC 0000282D */  daddu     $a1, $zero, $zero
/* C63BC0 80242EB0 C6200070 */  lwc1      $f0, 0x70($s1)
/* C63BC4 80242EB4 46800020 */  cvt.s.w   $f0, $f0
/* C63BC8 80242EB8 C6220074 */  lwc1      $f2, 0x74($s1)
/* C63BCC 80242EBC 468010A0 */  cvt.s.w   $f2, $f2
/* C63BD0 80242EC0 44060000 */  mfc1      $a2, $f0
/* C63BD4 80242EC4 44071000 */  mfc1      $a3, $f2
/* C63BD8 80242EC8 44820000 */  mtc1      $v0, $f0
/* C63BDC 80242ECC 00000000 */  nop
/* C63BE0 80242ED0 46800020 */  cvt.s.w   $f0, $f0
/* C63BE4 80242ED4 AE220078 */  sw        $v0, 0x78($s1)
/* C63BE8 80242ED8 0C05267B */  jal       sfx_adjust_env_sound_pos
/* C63BEC 80242EDC E7A00010 */   swc1     $f0, 0x10($sp)
.L80242EE0:
/* C63BF0 80242EE0 8FBF0020 */  lw        $ra, 0x20($sp)
/* C63BF4 80242EE4 8FB1001C */  lw        $s1, 0x1c($sp)
/* C63BF8 80242EE8 8FB00018 */  lw        $s0, 0x18($sp)
/* C63BFC 80242EEC 24020002 */  addiu     $v0, $zero, 2
/* C63C00 80242EF0 03E00008 */  jr        $ra
/* C63C04 80242EF4 27BD0028 */   addiu    $sp, $sp, 0x28
