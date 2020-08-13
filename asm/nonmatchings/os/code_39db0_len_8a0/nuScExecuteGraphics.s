.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuScExecuteGraphics
/* 03A114 8005ED14 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03A118 8005ED18 AFB00018 */  sw    $s0, 0x18($sp)
/* 03A11C 8005ED1C 3C10800E */  lui   $s0, 0x800e
/* 03A120 8005ED20 2610A47C */  addiu $s0, $s0, -0x5b84
/* 03A124 8005ED24 AFB1001C */  sw    $s1, 0x1c($sp)
/* 03A128 8005ED28 27B10014 */  addiu $s1, $sp, 0x14
/* 03A12C 8005ED2C AFBF0020 */  sw    $ra, 0x20($sp)
/* 03A130 8005ED30 0200202D */  daddu $a0, $s0, $zero
.L8005ED34:
/* 03A134 8005ED34 27A50010 */  addiu $a1, $sp, 0x10
/* 03A138 8005ED38 0C0195BC */  jal   osRecvMesg
/* 03A13C 8005ED3C 24060001 */   addiu $a2, $zero, 1
/* 03A140 8005ED40 3C02800A */  lui   $v0, 0x800a
/* 03A144 8005ED44 9042A5B0 */  lbu   $v0, -0x5a50($v0)
/* 03A148 8005ED48 30420002 */  andi  $v0, $v0, 2
/* 03A14C 8005ED4C 14400032 */  bnez  $v0, .L8005EE18
/* 03A150 8005ED50 00000000 */   nop   
/* 03A154 8005ED54 0C017C48 */  jal   nuScWaitTaskReady
/* 03A158 8005ED58 8FA40010 */   lw    $a0, 0x10($sp)
/* 03A15C 8005ED5C 0C018250 */  jal   osSetIntMask
/* 03A160 8005ED60 24040001 */   addiu $a0, $zero, 1
/* 03A164 8005ED64 8E030634 */  lw    $v1, 0x634($s0)
/* 03A168 8005ED68 1060000C */  beqz  $v1, .L8005ED9C
/* 03A16C 8005ED6C 0040202D */   daddu $a0, $v0, $zero
/* 03A170 8005ED70 8FA20010 */  lw    $v0, 0x10($sp)
/* 03A174 8005ED74 0C018250 */  jal   osSetIntMask
/* 03A178 8005ED78 AE020638 */   sw    $v0, 0x638($s0)
/* 03A17C 8005ED7C 260400E0 */  addiu $a0, $s0, 0xe0
/* 03A180 8005ED80 27A50014 */  addiu $a1, $sp, 0x14
/* 03A184 8005ED84 0C0195BC */  jal   osRecvMesg
/* 03A188 8005ED88 24060001 */   addiu $a2, $zero, 1
/* 03A18C 8005ED8C 0C018250 */  jal   osSetIntMask
/* 03A190 8005ED90 24040001 */   addiu $a0, $zero, 1
/* 03A194 8005ED94 0040202D */  daddu $a0, $v0, $zero
/* 03A198 8005ED98 AE000638 */  sw    $zero, 0x638($s0)
.L8005ED9C:
/* 03A19C 8005ED9C 0C018250 */  jal   osSetIntMask
/* 03A1A0 8005EDA0 00000000 */   nop   
/* 03A1A4 8005EDA4 0C018250 */  jal   osSetIntMask
/* 03A1A8 8005EDA8 24040001 */   addiu $a0, $zero, 1
/* 03A1AC 8005EDAC 8FA30010 */  lw    $v1, 0x10($sp)
/* 03A1B0 8005EDB0 0040202D */  daddu $a0, $v0, $zero
/* 03A1B4 8005EDB4 0C018250 */  jal   osSetIntMask
/* 03A1B8 8005EDB8 AE030630 */   sw    $v1, 0x630($s0)
/* 03A1BC 8005EDBC 8FA40010 */  lw    $a0, 0x10($sp)
/* 03A1C0 8005EDC0 0C019684 */  jal   osSpTaskLoad
/* 03A1C4 8005EDC4 24840010 */   addiu $a0, $a0, 0x10
/* 03A1C8 8005EDC8 8FA40010 */  lw    $a0, 0x10($sp)
/* 03A1CC 8005EDCC 0C019707 */  jal   osSpTaskStartGo
/* 03A1D0 8005EDD0 24840010 */   addiu $a0, $a0, 0x10
/* 03A1D4 8005EDD4 26040070 */  addiu $a0, $s0, 0x70
/* 03A1D8 8005EDD8 0220282D */  daddu $a1, $s1, $zero
/* 03A1DC 8005EDDC 0C0195BC */  jal   osRecvMesg
/* 03A1E0 8005EDE0 24060001 */   addiu $a2, $zero, 1
/* 03A1E4 8005EDE4 0C018250 */  jal   osSetIntMask
/* 03A1E8 8005EDE8 24040001 */   addiu $a0, $zero, 1
/* 03A1EC 8005EDEC 0040202D */  daddu $a0, $v0, $zero
/* 03A1F0 8005EDF0 0C018250 */  jal   osSetIntMask
/* 03A1F4 8005EDF4 AE000630 */   sw    $zero, 0x630($s0)
/* 03A1F8 8005EDF8 8FA20010 */  lw    $v0, 0x10($sp)
/* 03A1FC 8005EDFC 8C420008 */  lw    $v0, 8($v0)
/* 03A200 8005EE00 30420002 */  andi  $v0, $v0, 2
/* 03A204 8005EE04 14400004 */  bnez  $v0, .L8005EE18
/* 03A208 8005EE08 260400A8 */   addiu $a0, $s0, 0xa8
/* 03A20C 8005EE0C 0220282D */  daddu $a1, $s1, $zero
/* 03A210 8005EE10 0C0195BC */  jal   osRecvMesg
/* 03A214 8005EE14 24060001 */   addiu $a2, $zero, 1
.L8005EE18:
/* 03A218 8005EE18 8FA50010 */  lw    $a1, 0x10($sp)
/* 03A21C 8005EE1C 8CA40050 */  lw    $a0, 0x50($a1)
/* 03A220 8005EE20 0C019608 */  jal   osSendMesg
/* 03A224 8005EE24 24060001 */   addiu $a2, $zero, 1
/* 03A228 8005EE28 08017B4D */  j     .L8005ED34
/* 03A22C 8005EE2C 0200202D */   daddu $a0, $s0, $zero

