.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_spirits_rescued
/* 006240 8002AE40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006244 8002AE44 0000202D */  daddu $a0, $zero, $zero
/* 006248 8002AE48 3C05F5DE */  lui   $a1, 0xf5de
/* 00624C 8002AE4C 34A50180 */  ori   $a1, $a1, 0x180
/* 006250 8002AE50 AFBF0018 */  sw    $ra, 0x18($sp)
/* 006254 8002AE54 AFB10014 */  sw    $s1, 0x14($sp)
/* 006258 8002AE58 0C0B1EAF */  jal   get_variable
/* 00625C 8002AE5C AFB00010 */   sw    $s0, 0x10($sp)
/* 006260 8002AE60 24110007 */  addiu $s1, $zero, 7
/* 006264 8002AE64 0000202D */  daddu $a0, $zero, $zero
/* 006268 8002AE68 2405FFB3 */  addiu $a1, $zero, -0x4d
/* 00626C 8002AE6C 0C0B1EAF */  jal   get_variable
/* 006270 8002AE70 0040802D */   daddu $s0, $v0, $zero
/* 006274 8002AE74 0202102A */  slt   $v0, $s0, $v0
/* 006278 8002AE78 10400003 */  beqz  $v0, .L8002AE88
/* 00627C 8002AE7C 0000202D */   daddu $a0, $zero, $zero
/* 006280 8002AE80 0800ABCA */  j     .L8002AF28
/* 006284 8002AE84 0000882D */   daddu $s1, $zero, $zero

.L8002AE88:
/* 006288 8002AE88 0C0B1EAF */  jal   get_variable
/* 00628C 8002AE8C 2405FFC9 */   addiu $a1, $zero, -0x37
/* 006290 8002AE90 0202102A */  slt   $v0, $s0, $v0
/* 006294 8002AE94 10400003 */  beqz  $v0, .L8002AEA4
/* 006298 8002AE98 0000202D */   daddu $a0, $zero, $zero
/* 00629C 8002AE9C 0800ABCA */  j     .L8002AF28
/* 0062A0 8002AEA0 24110001 */   addiu $s1, $zero, 1

.L8002AEA4:
/* 0062A4 8002AEA4 0C0B1EAF */  jal   get_variable
/* 0062A8 8002AEA8 2405FFF1 */   addiu $a1, $zero, -0xf
/* 0062AC 8002AEAC 0202102A */  slt   $v0, $s0, $v0
/* 0062B0 8002AEB0 10400003 */  beqz  $v0, .L8002AEC0
/* 0062B4 8002AEB4 0000202D */   daddu $a0, $zero, $zero
/* 0062B8 8002AEB8 0800ABCA */  j     .L8002AF28
/* 0062BC 8002AEBC 24110002 */   addiu $s1, $zero, 2

.L8002AEC0:
/* 0062C0 8002AEC0 0C0B1EAF */  jal   get_variable
/* 0062C4 8002AEC4 24050005 */   addiu $a1, $zero, 5
/* 0062C8 8002AEC8 0202102A */  slt   $v0, $s0, $v0
/* 0062CC 8002AECC 10400003 */  beqz  $v0, .L8002AEDC
/* 0062D0 8002AED0 0000202D */   daddu $a0, $zero, $zero
/* 0062D4 8002AED4 0800ABCA */  j     .L8002AF28
/* 0062D8 8002AED8 24110003 */   addiu $s1, $zero, 3

.L8002AEDC:
/* 0062DC 8002AEDC 0C0B1EAF */  jal   get_variable
/* 0062E0 8002AEE0 24050025 */   addiu $a1, $zero, 0x25
/* 0062E4 8002AEE4 0202102A */  slt   $v0, $s0, $v0
/* 0062E8 8002AEE8 10400003 */  beqz  $v0, .L8002AEF8
/* 0062EC 8002AEEC 0000202D */   daddu $a0, $zero, $zero
/* 0062F0 8002AEF0 0800ABCA */  j     .L8002AF28
/* 0062F4 8002AEF4 24110004 */   addiu $s1, $zero, 4

.L8002AEF8:
/* 0062F8 8002AEF8 0C0B1EAF */  jal   get_variable
/* 0062FC 8002AEFC 24050039 */   addiu $a1, $zero, 0x39
/* 006300 8002AF00 0202102A */  slt   $v0, $s0, $v0
/* 006304 8002AF04 10400003 */  beqz  $v0, .L8002AF14
/* 006308 8002AF08 0000202D */   daddu $a0, $zero, $zero
/* 00630C 8002AF0C 0800ABCA */  j     .L8002AF28
/* 006310 8002AF10 24110005 */   addiu $s1, $zero, 5

.L8002AF14:
/* 006314 8002AF14 0C0B1EAF */  jal   get_variable
/* 006318 8002AF18 24050057 */   addiu $a1, $zero, 0x57
/* 00631C 8002AF1C 0202102A */  slt   $v0, $s0, $v0
/* 006320 8002AF20 54400001 */  bnel  $v0, $zero, .L8002AF28
/* 006324 8002AF24 24110006 */   addiu $s1, $zero, 6
.L8002AF28:
/* 006328 8002AF28 0220102D */  daddu $v0, $s1, $zero
/* 00632C 8002AF2C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 006330 8002AF30 8FB10014 */  lw    $s1, 0x14($sp)
/* 006334 8002AF34 8FB00010 */  lw    $s0, 0x10($sp)
/* 006338 8002AF38 03E00008 */  jr    $ra
/* 00633C 8002AF3C 27BD0020 */   addiu $sp, $sp, 0x20

