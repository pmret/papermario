.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FE58
/* 2B258 8004FE58 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2B25C 8004FE5C AFB3001C */  sw        $s3, 0x1c($sp)
/* 2B260 8004FE60 0080982D */  daddu     $s3, $a0, $zero
/* 2B264 8004FE64 AFB20018 */  sw        $s2, 0x18($sp)
/* 2B268 8004FE68 00A0902D */  daddu     $s2, $a1, $zero
/* 2B26C 8004FE6C AFBF0020 */  sw        $ra, 0x20($sp)
/* 2B270 8004FE70 AFB10014 */  sw        $s1, 0x14($sp)
/* 2B274 8004FE74 AFB00010 */  sw        $s0, 0x10($sp)
/* 2B278 8004FE78 966500D4 */  lhu       $a1, 0xd4($s3)
/* 2B27C 8004FE7C 8E640064 */  lw        $a0, 0x64($s3)
/* 2B280 8004FE80 92620170 */  lbu       $v0, 0x170($s3)
/* 2B284 8004FE84 926300D6 */  lbu       $v1, 0xd6($s3)
/* 2B288 8004FE88 0043102B */  sltu      $v0, $v0, $v1
/* 2B28C 8004FE8C 10400005 */  beqz      $v0, .L8004FEA4
/* 2B290 8004FE90 00A42821 */   addu     $a1, $a1, $a0
/* 2B294 8004FE94 92630170 */  lbu       $v1, 0x170($s3)
/* 2B298 8004FE98 00031040 */  sll       $v0, $v1, 1
/* 2B29C 8004FE9C 00431021 */  addu      $v0, $v0, $v1
/* 2B2A0 8004FEA0 00A22821 */  addu      $a1, $a1, $v0
.L8004FEA4:
/* 2B2A4 8004FEA4 8E420000 */  lw        $v0, ($s2)
/* 2B2A8 8004FEA8 AE420008 */  sw        $v0, 8($s2)
/* 2B2AC 8004FEAC 90A20000 */  lbu       $v0, ($a1)
/* 2B2B0 8004FEB0 90A30001 */  lbu       $v1, 1($a1)
/* 2B2B4 8004FEB4 8E640064 */  lw        $a0, 0x64($s3)
/* 2B2B8 8004FEB8 00021200 */  sll       $v0, $v0, 8
/* 2B2BC 8004FEBC 00431021 */  addu      $v0, $v0, $v1
/* 2B2C0 8004FEC0 00441021 */  addu      $v0, $v0, $a0
/* 2B2C4 8004FEC4 AE420000 */  sw        $v0, ($s2)
/* 2B2C8 8004FEC8 90A20002 */  lbu       $v0, 2($a1)
/* 2B2CC 8004FECC 9243004D */  lbu       $v1, 0x4d($s2)
/* 2B2D0 8004FED0 1060001B */  beqz      $v1, .L8004FF40
/* 2B2D4 8004FED4 A2420058 */   sb       $v0, 0x58($s2)
/* 2B2D8 8004FED8 92500052 */  lbu       $s0, 0x52($s2)
/* 2B2DC 8004FEDC 92420053 */  lbu       $v0, 0x53($s2)
/* 2B2E0 8004FEE0 A240004D */  sb        $zero, 0x4d($s2)
/* 2B2E4 8004FEE4 0202102B */  sltu      $v0, $s0, $v0
/* 2B2E8 8004FEE8 10400015 */  beqz      $v0, .L8004FF40
/* 2B2EC 8004FEEC AE40002C */   sw       $zero, 0x2c($s2)
/* 2B2F0 8004FEF0 001010C0 */  sll       $v0, $s0, 3
/* 2B2F4 8004FEF4 00501021 */  addu      $v0, $v0, $s0
/* 2B2F8 8004FEF8 000210C0 */  sll       $v0, $v0, 3
/* 2B2FC 8004FEFC 24511320 */  addiu     $s1, $v0, 0x1320
.L8004FF00:
/* 2B300 8004FF00 8E620000 */  lw        $v0, ($s3)
/* 2B304 8004FF04 00512021 */  addu      $a0, $v0, $s1
/* 2B308 8004FF08 90830045 */  lbu       $v1, 0x45($a0)
/* 2B30C 8004FF0C 92620234 */  lbu       $v0, 0x234($s3)
/* 2B310 8004FF10 14620006 */  bne       $v1, $v0, .L8004FF2C
/* 2B314 8004FF14 00000000 */   nop
/* 2B318 8004FF18 8C82001C */  lw        $v0, 0x1c($a0)
/* 2B31C 8004FF1C 10400003 */  beqz      $v0, .L8004FF2C
/* 2B320 8004FF20 00000000 */   nop
/* 2B324 8004FF24 0C014D5D */  jal       func_80053574
/* 2B328 8004FF28 320500FF */   andi     $a1, $s0, 0xff
.L8004FF2C:
/* 2B32C 8004FF2C 92420053 */  lbu       $v0, 0x53($s2)
/* 2B330 8004FF30 26100001 */  addiu     $s0, $s0, 1
/* 2B334 8004FF34 0202102B */  sltu      $v0, $s0, $v0
/* 2B338 8004FF38 1440FFF1 */  bnez      $v0, .L8004FF00
/* 2B33C 8004FF3C 26310048 */   addiu    $s1, $s1, 0x48
.L8004FF40:
/* 2B340 8004FF40 9242004E */  lbu       $v0, 0x4e($s2)
/* 2B344 8004FF44 10400006 */  beqz      $v0, .L8004FF60
/* 2B348 8004FF48 0260202D */   daddu    $a0, $s3, $zero
/* 2B34C 8004FF4C 0240282D */  daddu     $a1, $s2, $zero
/* 2B350 8004FF50 A240004E */  sb        $zero, 0x4e($s2)
/* 2B354 8004FF54 92660171 */  lbu       $a2, 0x171($s3)
/* 2B358 8004FF58 0C01414E */  jal       func_80050538
/* 2B35C 8004FF5C 24070090 */   addiu    $a3, $zero, 0x90
.L8004FF60:
/* 2B360 8004FF60 A6400046 */  sh        $zero, 0x46($s2)
/* 2B364 8004FF64 A2400048 */  sb        $zero, 0x48($s2)
/* 2B368 8004FF68 A240004C */  sb        $zero, 0x4c($s2)
/* 2B36C 8004FF6C A6400038 */  sh        $zero, 0x38($s2)
/* 2B370 8004FF70 A2400056 */  sb        $zero, 0x56($s2)
/* 2B374 8004FF74 AE400024 */  sw        $zero, 0x24($s2)
/* 2B378 8004FF78 A2400057 */  sb        $zero, 0x57($s2)
/* 2B37C 8004FF7C 92620235 */  lbu       $v0, 0x235($s3)
/* 2B380 8004FF80 A242005B */  sb        $v0, 0x5b($s2)
/* 2B384 8004FF84 8FBF0020 */  lw        $ra, 0x20($sp)
/* 2B388 8004FF88 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2B38C 8004FF8C 8FB20018 */  lw        $s2, 0x18($sp)
/* 2B390 8004FF90 8FB10014 */  lw        $s1, 0x14($sp)
/* 2B394 8004FF94 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B398 8004FF98 03E00008 */  jr        $ra
/* 2B39C 8004FF9C 27BD0028 */   addiu    $sp, $sp, 0x28
