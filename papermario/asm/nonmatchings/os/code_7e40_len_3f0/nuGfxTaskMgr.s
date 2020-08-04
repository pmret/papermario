.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuGfxTaskMgr
/* 007E40 8002CA40 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 007E44 8002CA44 3C04800E */  lui   $a0, 0x800e
/* 007E48 8002CA48 2484AC90 */  addiu $a0, $a0, -0x5370
/* 007E4C 8002CA4C 3C05800A */  lui   $a1, 0x800a
/* 007E50 8002CA50 24A5E6D0 */  addiu $a1, $a1, -0x1930
/* 007E54 8002CA54 24060008 */  addiu $a2, $zero, 8
/* 007E58 8002CA58 AFBF0028 */  sw    $ra, 0x28($sp)
/* 007E5C 8002CA5C AFB30024 */  sw    $s3, 0x24($sp)
/* 007E60 8002CA60 AFB20020 */  sw    $s2, 0x20($sp)
/* 007E64 8002CA64 AFB1001C */  sw    $s1, 0x1c($sp)
/* 007E68 8002CA68 0C019560 */  jal   osCreateMesgQueue
/* 007E6C 8002CA6C AFB00018 */   sw    $s0, 0x18($sp)
/* 007E70 8002CA70 24130004 */  addiu $s3, $zero, 4
/* 007E74 8002CA74 24120008 */  addiu $s2, $zero, 8
/* 007E78 8002CA78 3C11800A */  lui   $s1, 0x800a
/* 007E7C 8002CA7C 2631A5F8 */  addiu $s1, $s1, -0x5a08
/* 007E80 8002CA80 3C10800A */  lui   $s0, 0x800a
/* 007E84 8002CA84 2610A618 */  addiu $s0, $s0, -0x59e8
.L8002CA88:
/* 007E88 8002CA88 3C04800E */  lui   $a0, 0x800e
/* 007E8C 8002CA8C 2484AC90 */  addiu $a0, $a0, -0x5370
/* 007E90 8002CA90 27A50010 */  addiu $a1, $sp, 0x10
/* 007E94 8002CA94 0C0195BC */  jal   osRecvMesg
/* 007E98 8002CA98 24060001 */   addiu $a2, $zero, 1
/* 007E9C 8002CA9C 8FA40010 */  lw    $a0, 0x10($sp)
/* 007EA0 8002CAA0 8C820054 */  lw    $v0, 0x54($a0)
/* 007EA4 8002CAA4 84420000 */  lh    $v0, ($v0)
/* 007EA8 8002CAA8 10530005 */  beq   $v0, $s3, .L8002CAC0
/* 007EAC 8002CAAC 00000000 */   nop   
/* 007EB0 8002CAB0 10520012 */  beq   $v0, $s2, .L8002CAFC
/* 007EB4 8002CAB4 00000000 */   nop   
/* 007EB8 8002CAB8 0800B2A2 */  j     .L8002CA88
/* 007EBC 8002CABC 00000000 */   nop   

.L8002CAC0:
/* 007EC0 8002CAC0 3C028007 */  lui   $v0, 0x8007
/* 007EC4 8002CAC4 8C4273F4 */  lw    $v0, 0x73f4($v0)
/* 007EC8 8002CAC8 10400003 */  beqz  $v0, .L8002CAD8
/* 007ECC 8002CACC 00000000 */   nop   
/* 007ED0 8002CAD0 0040F809 */  jalr  $v0
/* 007ED4 8002CAD4 00000000 */  nop   
.L8002CAD8:
/* 007ED8 8002CAD8 8E220000 */  lw    $v0, ($s1)
/* 007EDC 8002CADC 30420080 */  andi  $v0, $v0, 0x80
/* 007EE0 8002CAE0 1040000C */  beqz  $v0, .L8002CB14
/* 007EE4 8002CAE4 00000000 */   nop   
/* 007EE8 8002CAE8 0C019CE0 */  jal   osViBlack
/* 007EEC 8002CAEC 0000202D */   daddu $a0, $zero, $zero
/* 007EF0 8002CAF0 24020001 */  addiu $v0, $zero, 1
/* 007EF4 8002CAF4 0800B2C5 */  j     .L8002CB14
/* 007EF8 8002CAF8 AE220000 */   sw    $v0, ($s1)

.L8002CAFC:
/* 007EFC 8002CAFC 3C028007 */  lui   $v0, 0x8007
/* 007F00 8002CB00 8C4273F8 */  lw    $v0, 0x73f8($v0)
/* 007F04 8002CB04 10400003 */  beqz  $v0, .L8002CB14
/* 007F08 8002CB08 00000000 */   nop   
/* 007F0C 8002CB0C 0040F809 */  jalr  $v0
/* 007F10 8002CB10 00000000 */  nop   
.L8002CB14:
/* 007F14 8002CB14 0C018250 */  jal   osSetIntMask
/* 007F18 8002CB18 24040001 */   addiu $a0, $zero, 1
/* 007F1C 8002CB1C 8E030000 */  lw    $v1, ($s0)
/* 007F20 8002CB20 0040202D */  daddu $a0, $v0, $zero
/* 007F24 8002CB24 2463FFFF */  addiu $v1, $v1, -1
/* 007F28 8002CB28 0C018250 */  jal   osSetIntMask
/* 007F2C 8002CB2C AE030000 */   sw    $v1, ($s0)
/* 007F30 8002CB30 0800B2A2 */  j     .L8002CA88
/* 007F34 8002CB34 00000000 */   nop   

