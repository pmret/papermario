.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel BindNpcAI
/* 01FE78 80044A78 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 01FE7C 80044A7C AFB00010 */  sw    $s0, 0x10($sp)
/* 01FE80 80044A80 0080802D */  daddu $s0, $a0, $zero
/* 01FE84 80044A84 AFB50024 */  sw    $s5, 0x24($sp)
/* 01FE88 80044A88 24150002 */  addiu $s5, $zero, 2
/* 01FE8C 80044A8C AFBF0028 */  sw    $ra, 0x28($sp)
/* 01FE90 80044A90 AFB40020 */  sw    $s4, 0x20($sp)
/* 01FE94 80044A94 AFB3001C */  sw    $s3, 0x1c($sp)
/* 01FE98 80044A98 AFB20018 */  sw    $s2, 0x18($sp)
/* 01FE9C 80044A9C AFB10014 */  sw    $s1, 0x14($sp)
/* 01FEA0 80044AA0 8E11000C */  lw    $s1, 0xc($s0)
/* 01FEA4 80044AA4 8E120148 */  lw    $s2, 0x148($s0)
/* 01FEA8 80044AA8 8E250000 */  lw    $a1, ($s1)
/* 01FEAC 80044AAC 0C0B1EAF */  jal   get_variable
/* 01FEB0 80044AB0 26310004 */   addiu $s1, $s1, 4
/* 01FEB4 80044AB4 0040982D */  daddu $s3, $v0, $zero
/* 01FEB8 80044AB8 8E250000 */  lw    $a1, ($s1)
/* 01FEBC 80044ABC 0C0B1EAF */  jal   get_variable
/* 01FEC0 80044AC0 0200202D */   daddu $a0, $s0, $zero
/* 01FEC4 80044AC4 0040A02D */  daddu $s4, $v0, $zero
/* 01FEC8 80044AC8 2402FFFF */  addiu $v0, $zero, -1
/* 01FECC 80044ACC 12420011 */  beq   $s2, $v0, .L80044B14
/* 01FED0 80044AD0 00000000 */   nop   
/* 01FED4 80044AD4 12620004 */  beq   $s3, $v0, .L80044AE8
/* 01FED8 80044AD8 00000000 */   nop   
/* 01FEDC 80044ADC 86420008 */  lh    $v0, 8($s2)
/* 01FEE0 80044AE0 1453000C */  bne   $v0, $s3, .L80044B14
/* 01FEE4 80044AE4 00000000 */   nop   
.L80044AE8:
/* 01FEE8 80044AE8 86530008 */  lh    $s3, 8($s2)
.L80044AEC:
/* 01FEEC 80044AEC 8E020064 */  lw    $v0, 0x64($s0)
/* 01FEF0 80044AF0 10400003 */  beqz  $v0, .L80044B00
/* 01FEF4 80044AF4 00000000 */   nop   
/* 01FEF8 80044AF8 080112BB */  j     .L80044AEC
/* 01FEFC 80044AFC 0040802D */   daddu $s0, $v0, $zero

.L80044B00:
/* 01FF00 80044B00 8E42003C */  lw    $v0, 0x3c($s2)
/* 01FF04 80044B04 52020006 */  beql  $s0, $v0, .L80044B20
/* 01FF08 80044B08 241500FF */   addiu $s5, $zero, 0xff
/* 01FF0C 80044B0C 080112C8 */  j     .L80044B20
/* 01FF10 80044B10 00000000 */   nop   

.L80044B14:
/* 01FF14 80044B14 0C00FB3A */  jal   get_enemy
/* 01FF18 80044B18 0260202D */   daddu $a0, $s3, $zero
/* 01FF1C 80044B1C 0040902D */  daddu $s2, $v0, $zero
.L80044B20:
/* 01FF20 80044B20 8E420000 */  lw    $v0, ($s2)
/* 01FF24 80044B24 30420001 */  andi  $v0, $v0, 1
/* 01FF28 80044B28 10400002 */  beqz  $v0, .L80044B34
/* 01FF2C 80044B2C 2411000B */   addiu $s1, $zero, 0xb
/* 01FF30 80044B30 2411000A */  addiu $s1, $zero, 0xa
.L80044B34:
/* 01FF34 80044B34 8E42003C */  lw    $v0, 0x3c($s2)
/* 01FF38 80044B38 10400005 */  beqz  $v0, .L80044B50
/* 01FF3C 80044B3C 0280202D */   daddu $a0, $s4, $zero
/* 01FF40 80044B40 8E440054 */  lw    $a0, 0x54($s2)
/* 01FF44 80044B44 0C0B102B */  jal   kill_script_by_ID
/* 01FF48 80044B48 00000000 */   nop   
/* 01FF4C 80044B4C 0280202D */  daddu $a0, $s4, $zero
.L80044B50:
/* 01FF50 80044B50 2405000A */  addiu $a1, $zero, 0xa
/* 01FF54 80044B54 24020064 */  addiu $v0, $zero, 0x64
/* 01FF58 80044B58 0000302D */  daddu $a2, $zero, $zero
/* 01FF5C 80044B5C AE4200C8 */  sw    $v0, 0xc8($s2)
/* 01FF60 80044B60 0C0B0CF8 */  jal   start_script
/* 01FF64 80044B64 AE440024 */   sw    $a0, 0x24($s2)
/* 01FF68 80044B68 0040802D */  daddu $s0, $v0, $zero
/* 01FF6C 80044B6C AE50003C */  sw    $s0, 0x3c($s2)
/* 01FF70 80044B70 8E030144 */  lw    $v1, 0x144($s0)
/* 01FF74 80044B74 02A0102D */  daddu $v0, $s5, $zero
/* 01FF78 80044B78 AE430054 */  sw    $v1, 0x54($s2)
/* 01FF7C 80044B7C AE120148 */  sw    $s2, 0x148($s0)
/* 01FF80 80044B80 AE13014C */  sw    $s3, 0x14c($s0)
/* 01FF84 80044B84 A2110004 */  sb    $s1, 4($s0)
/* 01FF88 80044B88 8FBF0028 */  lw    $ra, 0x28($sp)
/* 01FF8C 80044B8C 8FB50024 */  lw    $s5, 0x24($sp)
/* 01FF90 80044B90 8FB40020 */  lw    $s4, 0x20($sp)
/* 01FF94 80044B94 8FB3001C */  lw    $s3, 0x1c($sp)
/* 01FF98 80044B98 8FB20018 */  lw    $s2, 0x18($sp)
/* 01FF9C 80044B9C 8FB10014 */  lw    $s1, 0x14($sp)
/* 01FFA0 80044BA0 8FB00010 */  lw    $s0, 0x10($sp)
/* 01FFA4 80044BA4 03E00008 */  jr    $ra
/* 01FFA8 80044BA8 27BD0030 */   addiu $sp, $sp, 0x30

