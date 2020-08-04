.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuGfxTaskMgrInit
/* 007F38 8002CB38 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 007F3C 8002CB3C 24020008 */  addiu $v0, $zero, 8
/* 007F40 8002CB40 3C01800A */  lui   $at, 0x800a
/* 007F44 8002CB44 A422C514 */  sh    $v0, -0x3aec($at)
/* 007F48 8002CB48 24020004 */  addiu $v0, $zero, 4
/* 007F4C 8002CB4C 3C01800A */  lui   $at, 0x800a
/* 007F50 8002CB50 A422C516 */  sh    $v0, -0x3aea($at)
/* 007F54 8002CB54 3C02800A */  lui   $v0, 0x800a
/* 007F58 8002CB58 2442A618 */  addiu $v0, $v0, -0x59e8
/* 007F5C 8002CB5C AFBF0038 */  sw    $ra, 0x38($sp)
/* 007F60 8002CB60 AFB70034 */  sw    $s7, 0x34($sp)
/* 007F64 8002CB64 AFB60030 */  sw    $s6, 0x30($sp)
/* 007F68 8002CB68 AFB5002C */  sw    $s5, 0x2c($sp)
/* 007F6C 8002CB6C AFB40028 */  sw    $s4, 0x28($sp)
/* 007F70 8002CB70 AFB30024 */  sw    $s3, 0x24($sp)
/* 007F74 8002CB74 AFB20020 */  sw    $s2, 0x20($sp)
/* 007F78 8002CB78 AFB1001C */  sw    $s1, 0x1c($sp)
/* 007F7C 8002CB7C AFB00018 */  sw    $s0, 0x18($sp)
/* 007F80 8002CB80 AC400000 */  sw    $zero, ($v0)
/* 007F84 8002CB84 0C017D00 */  jal   nuGfxDisplayOff
/* 007F88 8002CB88 0000902D */   daddu $s2, $zero, $zero
/* 007F8C 8002CB8C 3C10800A */  lui   $s0, 0x800a
/* 007F90 8002CB90 2610C518 */  addiu $s0, $s0, -0x3ae8
/* 007F94 8002CB94 0200202D */  daddu $a0, $s0, $zero
/* 007F98 8002CB98 24050005 */  addiu $a1, $zero, 5
/* 007F9C 8002CB9C 3C068003 */  lui   $a2, 0x8003
/* 007FA0 8002CBA0 24C6CA40 */  addiu $a2, $a2, -0x35c0
/* 007FA4 8002CBA4 3C02800A */  lui   $v0, 0x800a
/* 007FA8 8002CBA8 2442E6D0 */  addiu $v0, $v0, -0x1930
/* 007FAC 8002CBAC AFA20010 */  sw    $v0, 0x10($sp)
/* 007FB0 8002CBB0 2402003C */  addiu $v0, $zero, 0x3c
/* 007FB4 8002CBB4 0000382D */  daddu $a3, $zero, $zero
/* 007FB8 8002CBB8 0C019798 */  jal   osCreateThread
/* 007FBC 8002CBBC AFA20014 */   sw    $v0, 0x14($sp)
/* 007FC0 8002CBC0 0C019808 */  jal   osStartThread
/* 007FC4 8002CBC4 0200202D */   daddu $a0, $s0, $zero
/* 007FC8 8002CBC8 3C17800E */  lui   $s7, 0x800e
/* 007FCC 8002CBCC 26F7AC90 */  addiu $s7, $s7, -0x5370
/* 007FD0 8002CBD0 24160001 */  addiu $s6, $zero, 1
/* 007FD4 8002CBD4 3C13800E */  lui   $s3, 0x800e
/* 007FD8 8002CBD8 26739780 */  addiu $s3, $s3, -0x6880
/* 007FDC 8002CBDC 24150100 */  addiu $s5, $zero, 0x100
/* 007FE0 8002CBE0 24141000 */  addiu $s4, $zero, 0x1000
/* 007FE4 8002CBE4 3C02800E */  lui   $v0, 0x800e
/* 007FE8 8002CBE8 24429278 */  addiu $v0, $v0, -0x6d88
/* 007FEC 8002CBEC 0040802D */  daddu $s0, $v0, $zero
/* 007FF0 8002CBF0 26110058 */  addiu $s1, $s0, 0x58
.L8002CBF4:
/* 007FF4 8002CBF4 3C04B000 */  lui   $a0, 0xb000
/* 007FF8 8002CBF8 34840B70 */  ori   $a0, $a0, 0xb70
/* 007FFC 8002CBFC 3C05B000 */  lui   $a1, 0xb000
/* 008000 8002CC00 34A50C70 */  ori   $a1, $a1, 0xc70
/* 008004 8002CC04 0260302D */  daddu $a2, $s3, $zero
/* 008008 8002CC08 AE110000 */  sw    $s1, ($s0)
/* 00800C 8002CC0C AE170050 */  sw    $s7, 0x50($s0)
/* 008010 8002CC10 AE160010 */  sw    $s6, 0x10($s0)
/* 008014 8002CC14 0C00A5CF */  jal   dma_copy
/* 008018 8002CC18 AE000014 */   sw    $zero, 0x14($s0)
/* 00801C 8002CC1C 24020800 */  addiu $v0, $zero, 0x800
/* 008020 8002CC20 AE02002C */  sw    $v0, 0x2c($s0)
/* 008024 8002CC24 3C02800E */  lui   $v0, 0x800e
/* 008028 8002CC28 2442A040 */  addiu $v0, $v0, -0x5fc0
/* 00802C 8002CC2C AE020030 */  sw    $v0, 0x30($s0)
/* 008030 8002CC30 24020400 */  addiu $v0, $zero, 0x400
/* 008034 8002CC34 AE020034 */  sw    $v0, 0x34($s0)
/* 008038 8002CC38 3C02800C */  lui   $v0, 0x800c
/* 00803C 8002CC3C 244291D0 */  addiu $v0, $v0, -0x6e30
/* 008040 8002CC40 AE020038 */  sw    $v0, 0x38($s0)
/* 008044 8002CC44 3C02800E */  lui   $v0, 0x800e
/* 008048 8002CC48 244291D0 */  addiu $v0, $v0, -0x6e30
/* 00804C 8002CC4C AE02003C */  sw    $v0, 0x3c($s0)
/* 008050 8002CC50 3C02800C */  lui   $v0, 0x800c
/* 008054 8002CC54 24428590 */  addiu $v0, $v0, -0x7a70
/* 008058 8002CC58 AE020048 */  sw    $v0, 0x48($s0)
/* 00805C 8002CC5C 24020C10 */  addiu $v0, $zero, 0xc10
/* 008060 8002CC60 AE130018 */  sw    $s3, 0x18($s0)
/* 008064 8002CC64 AE15001C */  sw    $s5, 0x1c($s0)
/* 008068 8002CC68 AE140024 */  sw    $s4, 0x24($s0)
/* 00806C 8002CC6C AE02004C */  sw    $v0, 0x4c($s0)
/* 008070 8002CC70 26100058 */  addiu $s0, $s0, 0x58
/* 008074 8002CC74 26520001 */  addiu $s2, $s2, 1
/* 008078 8002CC78 2E42000A */  sltiu $v0, $s2, 0xa
/* 00807C 8002CC7C 1440FFDD */  bnez  $v0, .L8002CBF4
/* 008080 8002CC80 26310058 */   addiu $s1, $s1, 0x58
/* 008084 8002CC84 3C02800E */  lui   $v0, 0x800e
/* 008088 8002CC88 24429278 */  addiu $v0, $v0, -0x6d88
/* 00808C 8002CC8C AC420318 */  sw    $v0, 0x318($v0)
/* 008090 8002CC90 8FBF0038 */  lw    $ra, 0x38($sp)
/* 008094 8002CC94 8FB70034 */  lw    $s7, 0x34($sp)
/* 008098 8002CC98 8FB60030 */  lw    $s6, 0x30($sp)
/* 00809C 8002CC9C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0080A0 8002CCA0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0080A4 8002CCA4 8FB30024 */  lw    $s3, 0x24($sp)
/* 0080A8 8002CCA8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0080AC 8002CCAC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0080B0 8002CCB0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0080B4 8002CCB4 3C01800A */  lui   $at, 0x800a
/* 0080B8 8002CCB8 AC22C510 */  sw    $v0, -0x3af0($at)
/* 0080BC 8002CCBC 03E00008 */  jr    $ra
/* 0080C0 8002CCC0 27BD0040 */   addiu $sp, $sp, 0x40

