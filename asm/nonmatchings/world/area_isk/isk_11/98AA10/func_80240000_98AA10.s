.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_98AA10
/* 98AA10 80240000 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 98AA14 80240004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 98AA18 80240008 0080882D */  daddu     $s1, $a0, $zero
/* 98AA1C 8024000C AFBF0020 */  sw        $ra, 0x20($sp)
/* 98AA20 80240010 AFB00018 */  sw        $s0, 0x18($sp)
/* 98AA24 80240014 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 98AA28 80240018 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 98AA2C 8024001C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 98AA30 80240020 8E30000C */  lw        $s0, 0xc($s1)
/* 98AA34 80240024 8E050000 */  lw        $a1, ($s0)
/* 98AA38 80240028 0C0B210B */  jal       get_float_variable
/* 98AA3C 8024002C 26100004 */   addiu    $s0, $s0, 4
/* 98AA40 80240030 8E050000 */  lw        $a1, ($s0)
/* 98AA44 80240034 26100004 */  addiu     $s0, $s0, 4
/* 98AA48 80240038 0220202D */  daddu     $a0, $s1, $zero
/* 98AA4C 8024003C 0C0B210B */  jal       get_float_variable
/* 98AA50 80240040 46000606 */   mov.s    $f24, $f0
/* 98AA54 80240044 8E050000 */  lw        $a1, ($s0)
/* 98AA58 80240048 26100004 */  addiu     $s0, $s0, 4
/* 98AA5C 8024004C 0220202D */  daddu     $a0, $s1, $zero
/* 98AA60 80240050 0C0B210B */  jal       get_float_variable
/* 98AA64 80240054 46000586 */   mov.s    $f22, $f0
/* 98AA68 80240058 0220202D */  daddu     $a0, $s1, $zero
/* 98AA6C 8024005C 8E050000 */  lw        $a1, ($s0)
/* 98AA70 80240060 0C0B1EAF */  jal       get_variable
/* 98AA74 80240064 46000506 */   mov.s    $f20, $f0
/* 98AA78 80240068 4405C000 */  mfc1      $a1, $f24
/* 98AA7C 8024006C 4406B000 */  mfc1      $a2, $f22
/* 98AA80 80240070 4407A000 */  mfc1      $a3, $f20
/* 98AA84 80240074 0000202D */  daddu     $a0, $zero, $zero
/* 98AA88 80240078 0C01C094 */  jal       func_80070250
/* 98AA8C 8024007C AFA20010 */   sw       $v0, 0x10($sp)
/* 98AA90 80240080 8FBF0020 */  lw        $ra, 0x20($sp)
/* 98AA94 80240084 8FB1001C */  lw        $s1, 0x1c($sp)
/* 98AA98 80240088 8FB00018 */  lw        $s0, 0x18($sp)
/* 98AA9C 8024008C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 98AAA0 80240090 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 98AAA4 80240094 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 98AAA8 80240098 24020002 */  addiu     $v0, $zero, 2
/* 98AAAC 8024009C 03E00008 */  jr        $ra
/* 98AAB0 802400A0 27BD0040 */   addiu    $sp, $sp, 0x40
/* 98AAB4 802400A4 00000000 */  nop
/* 98AAB8 802400A8 00000000 */  nop
/* 98AABC 802400AC 00000000 */  nop
