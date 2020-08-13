.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuContMgrInit
/* 03B910 80060510 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B914 80060514 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B918 80060518 0C01823C */  jal   nuContDataUnLock
/* 03B91C 8006051C 00000000 */   nop   
/* 03B920 80060520 3C04800B */  lui   $a0, 0x800b
/* 03B924 80060524 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03B928 80060528 3C05800B */  lui   $a1, 0x800b
/* 03B92C 8006052C 24A5E6D0 */  addiu $a1, $a1, -0x1930
/* 03B930 80060530 0C019560 */  jal   osCreateMesgQueue
/* 03B934 80060534 24060001 */   addiu $a2, $zero, 1
/* 03B938 80060538 3C04800E */  lui   $a0, 0x800e
/* 03B93C 8006053C 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03B940 80060540 3C05800B */  lui   $a1, 0x800b
/* 03B944 80060544 24A5E6D4 */  addiu $a1, $a1, -0x192c
/* 03B948 80060548 0C019560 */  jal   osCreateMesgQueue
/* 03B94C 8006054C 24060001 */   addiu $a2, $zero, 1
/* 03B950 80060550 3C048009 */  lui   $a0, 0x8009
/* 03B954 80060554 0C0180FC */  jal   nuSiCallBackAdd
/* 03B958 80060558 24843D38 */   addiu $a0, $a0, 0x3d38
/* 03B95C 8006055C 0C018248 */  jal   nuContQueryRead
/* 03B960 80060560 00000000 */   nop   
/* 03B964 80060564 24050001 */  addiu $a1, $zero, 1
/* 03B968 80060568 0000302D */  daddu $a2, $zero, $zero
/* 03B96C 8006056C 0000202D */  daddu $a0, $zero, $zero
/* 03B970 80060570 24070005 */  addiu $a3, $zero, 5
/* 03B974 80060574 3C01800A */  lui   $at, 0x800a
/* 03B978 80060578 AC20A614 */  sw    $zero, -0x59ec($at)
/* 03B97C 8006057C 00041880 */  sll   $v1, $a0, 2
.L80060580:
/* 03B980 80060580 3C02800B */  lui   $v0, 0x800b
/* 03B984 80060584 00431021 */  addu  $v0, $v0, $v1
/* 03B988 80060588 90421B7F */  lbu   $v0, 0x1b7f($v0)
/* 03B98C 8006058C 5440000F */  bnel  $v0, $zero, .L800605CC
/* 03B990 80060590 24840001 */   addiu $a0, $a0, 1
/* 03B994 80060594 3C02800B */  lui   $v0, 0x800b
/* 03B998 80060598 00431021 */  addu  $v0, $v0, $v1
/* 03B99C 8006059C 94421B7C */  lhu   $v0, 0x1b7c($v0)
/* 03B9A0 800605A0 30421F07 */  andi  $v0, $v0, 0x1f07
/* 03B9A4 800605A4 54470008 */  bnel  $v0, $a3, .L800605C8
/* 03B9A8 800605A8 00052840 */   sll   $a1, $a1, 1
/* 03B9AC 800605AC 3C02800A */  lui   $v0, 0x800a
/* 03B9B0 800605B0 8C42A614 */  lw    $v0, -0x59ec($v0)
/* 03B9B4 800605B4 00C53025 */  or    $a2, $a2, $a1
/* 03B9B8 800605B8 24420001 */  addiu $v0, $v0, 1
/* 03B9BC 800605BC 3C01800A */  lui   $at, 0x800a
/* 03B9C0 800605C0 AC22A614 */  sw    $v0, -0x59ec($at)
/* 03B9C4 800605C4 00052840 */  sll   $a1, $a1, 1
.L800605C8:
/* 03B9C8 800605C8 24840001 */  addiu $a0, $a0, 1
.L800605CC:
/* 03B9CC 800605CC 28820004 */  slti  $v0, $a0, 4
/* 03B9D0 800605D0 1440FFEB */  bnez  $v0, .L80060580
/* 03B9D4 800605D4 00041880 */   sll   $v1, $a0, 2
/* 03B9D8 800605D8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B9DC 800605DC 30C200FF */  andi  $v0, $a2, 0xff
/* 03B9E0 800605E0 03E00008 */  jr    $ra
/* 03B9E4 800605E4 27BD0018 */   addiu $sp, $sp, 0x18

