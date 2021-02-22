.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054AB0
/* 2FEB0 80054AB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2FEB4 80054AB4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2FEB8 80054AB8 0080982D */  daddu     $s3, $a0, $zero
/* 2FEBC 80054ABC AFB40020 */  sw        $s4, 0x20($sp)
/* 2FEC0 80054AC0 00A0A02D */  daddu     $s4, $a1, $zero
/* 2FEC4 80054AC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 2FEC8 80054AC8 00C0902D */  daddu     $s2, $a2, $zero
/* 2FECC 80054ACC AFB00010 */  sw        $s0, 0x10($sp)
/* 2FED0 80054AD0 00128342 */  srl       $s0, $s2, 0xd
/* 2FED4 80054AD4 AFB10014 */  sw        $s1, 0x14($sp)
/* 2FED8 80054AD8 0000882D */  daddu     $s1, $zero, $zero
/* 2FEDC 80054ADC 1200000A */  beqz      $s0, .L80054B08
/* 2FEE0 80054AE0 AFBF0024 */   sw       $ra, 0x24($sp)
/* 2FEE4 80054AE4 2610FFFF */  addiu     $s0, $s0, -1
.L80054AE8:
/* 2FEE8 80054AE8 02712021 */  addu      $a0, $s3, $s1
/* 2FEEC 80054AEC 02912821 */  addu      $a1, $s4, $s1
/* 2FEF0 80054AF0 0C017C50 */  jal       func_8005F140
/* 2FEF4 80054AF4 24062000 */   addiu    $a2, $zero, 0x2000
/* 2FEF8 80054AF8 26312000 */  addiu     $s1, $s1, 0x2000
/* 2FEFC 80054AFC 0200102D */  daddu     $v0, $s0, $zero
/* 2FF00 80054B00 1440FFF9 */  bnez      $v0, .L80054AE8
/* 2FF04 80054B04 2610FFFF */   addiu    $s0, $s0, -1
.L80054B08:
/* 2FF08 80054B08 32521FFF */  andi      $s2, $s2, 0x1fff
/* 2FF0C 80054B0C 12400004 */  beqz      $s2, .L80054B20
/* 2FF10 80054B10 02712021 */   addu     $a0, $s3, $s1
/* 2FF14 80054B14 02912821 */  addu      $a1, $s4, $s1
/* 2FF18 80054B18 0C017C50 */  jal       func_8005F140
/* 2FF1C 80054B1C 0240302D */   daddu    $a2, $s2, $zero
.L80054B20:
/* 2FF20 80054B20 8FBF0024 */  lw        $ra, 0x24($sp)
/* 2FF24 80054B24 8FB40020 */  lw        $s4, 0x20($sp)
/* 2FF28 80054B28 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2FF2C 80054B2C 8FB20018 */  lw        $s2, 0x18($sp)
/* 2FF30 80054B30 8FB10014 */  lw        $s1, 0x14($sp)
/* 2FF34 80054B34 8FB00010 */  lw        $s0, 0x10($sp)
/* 2FF38 80054B38 03E00008 */  jr        $ra
/* 2FF3C 80054B3C 27BD0028 */   addiu    $sp, $sp, 0x28
