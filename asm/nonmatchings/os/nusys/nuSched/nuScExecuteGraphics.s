.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuScExecuteGraphics
/* 3A114 8005ED14 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A118 8005ED18 AFB00018 */  sw        $s0, 0x18($sp)
/* 3A11C 8005ED1C 3C10800E */  lui       $s0, %hi(D_800DA47C)
/* 3A120 8005ED20 2610A47C */  addiu     $s0, $s0, %lo(D_800DA47C)
/* 3A124 8005ED24 AFB1001C */  sw        $s1, 0x1c($sp)
/* 3A128 8005ED28 27B10014 */  addiu     $s1, $sp, 0x14
/* 3A12C 8005ED2C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A130 8005ED30 0200202D */  daddu     $a0, $s0, $zero
.L8005ED34:
/* 3A134 8005ED34 27A50010 */  addiu     $a1, $sp, 0x10
/* 3A138 8005ED38 0C0195BC */  jal       osRecvMesg
/* 3A13C 8005ED3C 24060001 */   addiu    $a2, $zero, 1
/* 3A140 8005ED40 3C02800A */  lui       $v0, %hi(D_8009A5B0)
/* 3A144 8005ED44 9042A5B0 */  lbu       $v0, %lo(D_8009A5B0)($v0)
/* 3A148 8005ED48 30420002 */  andi      $v0, $v0, 2
/* 3A14C 8005ED4C 14400032 */  bnez      $v0, .L8005EE18
/* 3A150 8005ED50 00000000 */   nop
/* 3A154 8005ED54 0C017C48 */  jal       nuScWaitTaskReady
/* 3A158 8005ED58 8FA40010 */   lw       $a0, 0x10($sp)
/* 3A15C 8005ED5C 0C018250 */  jal       osSetIntMask
/* 3A160 8005ED60 24040001 */   addiu    $a0, $zero, 1
/* 3A164 8005ED64 8E030634 */  lw        $v1, 0x634($s0)
/* 3A168 8005ED68 1060000C */  beqz      $v1, .L8005ED9C
/* 3A16C 8005ED6C 0040202D */   daddu    $a0, $v0, $zero
/* 3A170 8005ED70 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A174 8005ED74 0C018250 */  jal       osSetIntMask
/* 3A178 8005ED78 AE020638 */   sw       $v0, 0x638($s0)
/* 3A17C 8005ED7C 260400E0 */  addiu     $a0, $s0, 0xe0
/* 3A180 8005ED80 27A50014 */  addiu     $a1, $sp, 0x14
/* 3A184 8005ED84 0C0195BC */  jal       osRecvMesg
/* 3A188 8005ED88 24060001 */   addiu    $a2, $zero, 1
/* 3A18C 8005ED8C 0C018250 */  jal       osSetIntMask
/* 3A190 8005ED90 24040001 */   addiu    $a0, $zero, 1
/* 3A194 8005ED94 0040202D */  daddu     $a0, $v0, $zero
/* 3A198 8005ED98 AE000638 */  sw        $zero, 0x638($s0)
.L8005ED9C:
/* 3A19C 8005ED9C 0C018250 */  jal       osSetIntMask
/* 3A1A0 8005EDA0 00000000 */   nop
/* 3A1A4 8005EDA4 0C018250 */  jal       osSetIntMask
/* 3A1A8 8005EDA8 24040001 */   addiu    $a0, $zero, 1
/* 3A1AC 8005EDAC 8FA30010 */  lw        $v1, 0x10($sp)
/* 3A1B0 8005EDB0 0040202D */  daddu     $a0, $v0, $zero
/* 3A1B4 8005EDB4 0C018250 */  jal       osSetIntMask
/* 3A1B8 8005EDB8 AE030630 */   sw       $v1, 0x630($s0)
/* 3A1BC 8005EDBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 3A1C0 8005EDC0 0C019684 */  jal       osSpTaskLoad
/* 3A1C4 8005EDC4 24840010 */   addiu    $a0, $a0, 0x10
/* 3A1C8 8005EDC8 8FA40010 */  lw        $a0, 0x10($sp)
/* 3A1CC 8005EDCC 0C019707 */  jal       osSpTaskStartGo
/* 3A1D0 8005EDD0 24840010 */   addiu    $a0, $a0, 0x10
/* 3A1D4 8005EDD4 26040070 */  addiu     $a0, $s0, 0x70
/* 3A1D8 8005EDD8 0220282D */  daddu     $a1, $s1, $zero
/* 3A1DC 8005EDDC 0C0195BC */  jal       osRecvMesg
/* 3A1E0 8005EDE0 24060001 */   addiu    $a2, $zero, 1
/* 3A1E4 8005EDE4 0C018250 */  jal       osSetIntMask
/* 3A1E8 8005EDE8 24040001 */   addiu    $a0, $zero, 1
/* 3A1EC 8005EDEC 0040202D */  daddu     $a0, $v0, $zero
/* 3A1F0 8005EDF0 0C018250 */  jal       osSetIntMask
/* 3A1F4 8005EDF4 AE000630 */   sw       $zero, 0x630($s0)
/* 3A1F8 8005EDF8 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A1FC 8005EDFC 8C420008 */  lw        $v0, 8($v0)
/* 3A200 8005EE00 30420002 */  andi      $v0, $v0, 2
/* 3A204 8005EE04 14400004 */  bnez      $v0, .L8005EE18
/* 3A208 8005EE08 260400A8 */   addiu    $a0, $s0, 0xa8
/* 3A20C 8005EE0C 0220282D */  daddu     $a1, $s1, $zero
/* 3A210 8005EE10 0C0195BC */  jal       osRecvMesg
/* 3A214 8005EE14 24060001 */   addiu    $a2, $zero, 1
.L8005EE18:
/* 3A218 8005EE18 8FA50010 */  lw        $a1, 0x10($sp)
/* 3A21C 8005EE1C 8CA40050 */  lw        $a0, 0x50($a1)
/* 3A220 8005EE20 0C019608 */  jal       osSendMesg
/* 3A224 8005EE24 24060001 */   addiu    $a2, $zero, 1
/* 3A228 8005EE28 08017B4D */  j         .L8005ED34
/* 3A22C 8005EE2C 0200202D */   daddu    $a0, $s0, $zero
