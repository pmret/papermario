.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D40_C77A20
/* C77A20 80240D40 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C77A24 80240D44 AFB1001C */  sw        $s1, 0x1c($sp)
/* C77A28 80240D48 0080882D */  daddu     $s1, $a0, $zero
/* C77A2C 80240D4C AFBF0020 */  sw        $ra, 0x20($sp)
/* C77A30 80240D50 AFB00018 */  sw        $s0, 0x18($sp)
/* C77A34 80240D54 8E30000C */  lw        $s0, 0xc($s1)
/* C77A38 80240D58 8E020000 */  lw        $v0, ($s0)
/* C77A3C 80240D5C 1040001B */  beqz      $v0, .L80240DCC
/* C77A40 80240D60 26100004 */   addiu    $s0, $s0, 4
/* C77A44 80240D64 8E050000 */  lw        $a1, ($s0)
/* C77A48 80240D68 0C0B1EAF */  jal       get_variable
/* C77A4C 80240D6C 26100004 */   addiu    $s0, $s0, 4
/* C77A50 80240D70 AE220070 */  sw        $v0, 0x70($s1)
/* C77A54 80240D74 8E050000 */  lw        $a1, ($s0)
/* C77A58 80240D78 26100004 */  addiu     $s0, $s0, 4
/* C77A5C 80240D7C 0C0B1EAF */  jal       get_variable
/* C77A60 80240D80 0220202D */   daddu    $a0, $s1, $zero
/* C77A64 80240D84 AE220074 */  sw        $v0, 0x74($s1)
/* C77A68 80240D88 8E050000 */  lw        $a1, ($s0)
/* C77A6C 80240D8C 0C0B1EAF */  jal       get_variable
/* C77A70 80240D90 0220202D */   daddu    $a0, $s1, $zero
/* C77A74 80240D94 24040168 */  addiu     $a0, $zero, 0x168
/* C77A78 80240D98 0000282D */  daddu     $a1, $zero, $zero
/* C77A7C 80240D9C C6200070 */  lwc1      $f0, 0x70($s1)
/* C77A80 80240DA0 46800020 */  cvt.s.w   $f0, $f0
/* C77A84 80240DA4 C6220074 */  lwc1      $f2, 0x74($s1)
/* C77A88 80240DA8 468010A0 */  cvt.s.w   $f2, $f2
/* C77A8C 80240DAC 44060000 */  mfc1      $a2, $f0
/* C77A90 80240DB0 44071000 */  mfc1      $a3, $f2
/* C77A94 80240DB4 44820000 */  mtc1      $v0, $f0
/* C77A98 80240DB8 00000000 */  nop
/* C77A9C 80240DBC 46800020 */  cvt.s.w   $f0, $f0
/* C77AA0 80240DC0 AE220078 */  sw        $v0, 0x78($s1)
/* C77AA4 80240DC4 0C05267B */  jal       sfx_adjust_env_sound_pos
/* C77AA8 80240DC8 E7A00010 */   swc1     $f0, 0x10($sp)
.L80240DCC:
/* C77AAC 80240DCC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C77AB0 80240DD0 8FB1001C */  lw        $s1, 0x1c($sp)
/* C77AB4 80240DD4 8FB00018 */  lw        $s0, 0x18($sp)
/* C77AB8 80240DD8 24020002 */  addiu     $v0, $zero, 2
/* C77ABC 80240DDC 03E00008 */  jr        $ra
/* C77AC0 80240DE0 27BD0028 */   addiu    $sp, $sp, 0x28
