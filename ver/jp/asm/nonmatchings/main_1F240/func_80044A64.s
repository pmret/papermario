.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044A64
/* 1FE64 80044A64 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1FE68 80044A68 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FE6C 80044A6C 0080982D */  daddu     $s3, $a0, $zero
/* 1FE70 80044A70 AFB40020 */  sw        $s4, 0x20($sp)
/* 1FE74 80044A74 24140002 */  addiu     $s4, $zero, 2
/* 1FE78 80044A78 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1FE7C 80044A7C AFB20018 */  sw        $s2, 0x18($sp)
/* 1FE80 80044A80 AFB10014 */  sw        $s1, 0x14($sp)
/* 1FE84 80044A84 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FE88 80044A88 8E70000C */  lw        $s0, 0xc($s3)
/* 1FE8C 80044A8C 8E710148 */  lw        $s1, 0x148($s3)
/* 1FE90 80044A90 8E050000 */  lw        $a1, ($s0)
/* 1FE94 80044A94 0C0B1EAF */  jal       func_802C7ABC
/* 1FE98 80044A98 26100004 */   addiu    $s0, $s0, 4
/* 1FE9C 80044A9C 0040902D */  daddu     $s2, $v0, $zero
/* 1FEA0 80044AA0 8E050000 */  lw        $a1, ($s0)
/* 1FEA4 80044AA4 0C0B1EAF */  jal       func_802C7ABC
/* 1FEA8 80044AA8 0260202D */   daddu    $a0, $s3, $zero
/* 1FEAC 80044AAC 0040802D */  daddu     $s0, $v0, $zero
/* 1FEB0 80044AB0 2402FFFF */  addiu     $v0, $zero, -1
/* 1FEB4 80044AB4 12220011 */  beq       $s1, $v0, .L80044AFC
/* 1FEB8 80044AB8 0260182D */   daddu    $v1, $s3, $zero
/* 1FEBC 80044ABC 12420004 */  beq       $s2, $v0, .L80044AD0
/* 1FEC0 80044AC0 00000000 */   nop
/* 1FEC4 80044AC4 86220008 */  lh        $v0, 8($s1)
/* 1FEC8 80044AC8 1452000C */  bne       $v0, $s2, .L80044AFC
/* 1FECC 80044ACC 00000000 */   nop
.L80044AD0:
/* 1FED0 80044AD0 86320008 */  lh        $s2, 8($s1)
.L80044AD4:
/* 1FED4 80044AD4 8C620064 */  lw        $v0, 0x64($v1)
/* 1FED8 80044AD8 10400003 */  beqz      $v0, .L80044AE8
/* 1FEDC 80044ADC 00000000 */   nop
/* 1FEE0 80044AE0 080112B5 */  j         .L80044AD4
/* 1FEE4 80044AE4 0040182D */   daddu    $v1, $v0, $zero
.L80044AE8:
/* 1FEE8 80044AE8 8E220044 */  lw        $v0, 0x44($s1)
/* 1FEEC 80044AEC 50620007 */  beql      $v1, $v0, .L80044B0C
/* 1FEF0 80044AF0 241400FF */   addiu    $s4, $zero, 0xff
/* 1FEF4 80044AF4 080112C3 */  j         .L80044B0C
/* 1FEF8 80044AF8 00000000 */   nop
.L80044AFC:
/* 1FEFC 80044AFC 0C00FA6A */  jal       func_8003E9A8
/* 1FF00 80044B00 0240202D */   daddu    $a0, $s2, $zero
/* 1FF04 80044B04 0040882D */  daddu     $s1, $v0, $zero
/* 1FF08 80044B08 8E220044 */  lw        $v0, 0x44($s1)
.L80044B0C:
/* 1FF0C 80044B0C 10400003 */  beqz      $v0, .L80044B1C
/* 1FF10 80044B10 00000000 */   nop
/* 1FF14 80044B14 0C0B102B */  jal       func_802C40AC
/* 1FF18 80044B18 8E24005C */   lw       $a0, 0x5c($s1)
.L80044B1C:
/* 1FF1C 80044B1C 1200000D */  beqz      $s0, .L80044B54
/* 1FF20 80044B20 0200202D */   daddu    $a0, $s0, $zero
/* 1FF24 80044B24 2405000A */  addiu     $a1, $zero, 0xa
/* 1FF28 80044B28 0000302D */  daddu     $a2, $zero, $zero
/* 1FF2C 80044B2C 0C0B0CF8 */  jal       func_802C33E0
/* 1FF30 80044B30 AE24002C */   sw       $a0, 0x2c($s1)
/* 1FF34 80044B34 0040182D */  daddu     $v1, $v0, $zero
/* 1FF38 80044B38 AE230044 */  sw        $v1, 0x44($s1)
/* 1FF3C 80044B3C 8C620144 */  lw        $v0, 0x144($v1)
/* 1FF40 80044B40 AE22005C */  sw        $v0, 0x5c($s1)
/* 1FF44 80044B44 AC710148 */  sw        $s1, 0x148($v1)
/* 1FF48 80044B48 AC72014C */  sw        $s2, 0x14c($v1)
/* 1FF4C 80044B4C 92620004 */  lbu       $v0, 4($s3)
/* 1FF50 80044B50 A0620004 */  sb        $v0, 4($v1)
.L80044B54:
/* 1FF54 80044B54 0280102D */  daddu     $v0, $s4, $zero
/* 1FF58 80044B58 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1FF5C 80044B5C 8FB40020 */  lw        $s4, 0x20($sp)
/* 1FF60 80044B60 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1FF64 80044B64 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FF68 80044B68 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FF6C 80044B6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FF70 80044B70 03E00008 */  jr        $ra
/* 1FF74 80044B74 27BD0028 */   addiu    $sp, $sp, 0x28
