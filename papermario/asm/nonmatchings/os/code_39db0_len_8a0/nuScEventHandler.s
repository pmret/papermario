.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuScEventHandler
/* 03A3A8 8005EFA8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03A3AC 8005EFAC AFB1001C */  sw    $s1, 0x1c($sp)
/* 03A3B0 8005EFB0 3C11800E */  lui   $s1, 0x800e
/* 03A3B4 8005EFB4 2631A4B4 */  addiu $s1, $s1, -0x5b4c
/* 03A3B8 8005EFB8 AFB40028 */  sw    $s4, 0x28($sp)
/* 03A3BC 8005EFBC 2414029A */  addiu $s4, $zero, 0x29a
/* 03A3C0 8005EFC0 AFB30024 */  sw    $s3, 0x24($sp)
/* 03A3C4 8005EFC4 2413029D */  addiu $s3, $zero, 0x29d
/* 03A3C8 8005EFC8 AFB20020 */  sw    $s2, 0x20($sp)
/* 03A3CC 8005EFCC 24120001 */  addiu $s2, $zero, 1
/* 03A3D0 8005EFD0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 03A3D4 8005EFD4 AFB00018 */  sw    $s0, 0x18($sp)
/* 03A3D8 8005EFD8 3C018009 */  lui   $at, 0x8009
/* 03A3DC 8005EFDC AC203B94 */  sw    $zero, 0x3b94($at)
.L8005EFE0:
/* 03A3E0 8005EFE0 0220202D */  daddu $a0, $s1, $zero
.L8005EFE4:
/* 03A3E4 8005EFE4 27A50010 */  addiu $a1, $sp, 0x10
.L8005EFE8:
/* 03A3E8 8005EFE8 0C0195BC */  jal   osRecvMesg
/* 03A3EC 8005EFEC 24060001 */   addiu $a2, $zero, 1
/* 03A3F0 8005EFF0 8FA20010 */  lw    $v0, 0x10($sp)
/* 03A3F4 8005EFF4 10540005 */  beq   $v0, $s4, .L8005F00C
/* 03A3F8 8005EFF8 00000000 */   nop   
/* 03A3FC 8005EFFC 1053001D */  beq   $v0, $s3, .L8005F074
/* 03A400 8005F000 0220202D */   daddu $a0, $s1, $zero
/* 03A404 8005F004 08017BFA */  j     .L8005EFE8
/* 03A408 8005F008 27A50010 */   addiu $a1, $sp, 0x10

.L8005F00C:
/* 03A40C 8005F00C 3C028009 */  lui   $v0, 0x8009
/* 03A410 8005F010 8C423B94 */  lw    $v0, 0x3b94($v0)
/* 03A414 8005F014 24420001 */  addiu $v0, $v0, 1
/* 03A418 8005F018 3C018009 */  lui   $at, 0x8009
/* 03A41C 8005F01C AC223B94 */  sw    $v0, 0x3b94($at)
/* 03A420 8005F020 0C017C30 */  jal   nuScEventBroadcast
/* 03A424 8005F024 2624FF8C */   addiu $a0, $s1, -0x74
/* 03A428 8005F028 3C02800A */  lui   $v0, 0x800a
/* 03A42C 8005F02C 9042A5B0 */  lbu   $v0, -0x5a50($v0)
/* 03A430 8005F030 1040FFEC */  beqz  $v0, .L8005EFE4
/* 03A434 8005F034 0220202D */   daddu $a0, $s1, $zero
/* 03A438 8005F038 12000003 */  beqz  $s0, .L8005F048
/* 03A43C 8005F03C 34420002 */   ori   $v0, $v0, 2
/* 03A440 8005F040 08017BF9 */  j     .L8005EFE4
/* 03A444 8005F044 2610FFFF */   addiu $s0, $s0, -1

.L8005F048:
/* 03A448 8005F048 3C01800A */  lui   $at, 0x800a
/* 03A44C 8005F04C 0C01A98C */  jal   osAfterPreNMI
/* 03A450 8005F050 A022A5B0 */   sb    $v0, -0x5a50($at)
/* 03A454 8005F054 3C013F80 */  lui   $at, 0x3f80
/* 03A458 8005F058 44816000 */  mtc1  $at, $f12
/* 03A45C 8005F05C 0C019BF4 */  jal   osViSetYScale
/* 03A460 8005F060 00000000 */   nop   
/* 03A464 8005F064 0C019CE0 */  jal   osViBlack
/* 03A468 8005F068 24040001 */   addiu $a0, $zero, 1
/* 03A46C 8005F06C 08017BF9 */  j     .L8005EFE4
/* 03A470 8005F070 0220202D */   daddu $a0, $s1, $zero

.L8005F074:
/* 03A474 8005F074 3C01800A */  lui   $at, 0x800a
/* 03A478 8005F078 A032A5B0 */  sb    $s2, -0x5a50($at)
/* 03A47C 8005F07C 0C017C30 */  jal   nuScEventBroadcast
/* 03A480 8005F080 2624FF8E */   addiu $a0, $s1, -0x72
/* 03A484 8005F084 3C028009 */  lui   $v0, 0x8009
/* 03A488 8005F088 8C423B80 */  lw    $v0, 0x3b80($v0)
/* 03A48C 8005F08C 10400003 */  beqz  $v0, .L8005F09C
/* 03A490 8005F090 00000000 */   nop   
/* 03A494 8005F094 0040F809 */  jalr  $v0
/* 03A498 8005F098 00000000 */  nop   
.L8005F09C:
/* 03A49C 8005F09C 92220608 */  lbu   $v0, 0x608($s1)
/* 03A4A0 8005F0A0 8E230604 */  lw    $v1, 0x604($s1)
/* 03A4A4 8005F0A4 00021042 */  srl   $v0, $v0, 1
/* 03A4A8 8005F0A8 14600002 */  bnez  $v1, .L8005F0B4
/* 03A4AC 8005F0AC 0043001B */   divu  $zero, $v0, $v1
/* 03A4B0 8005F0B0 0007000D */  break 7
.L8005F0B4:
/* 03A4B4 8005F0B4 00001012 */  mflo  $v0
/* 03A4B8 8005F0B8 08017BF8 */  j     .L8005EFE0
/* 03A4BC 8005F0BC 2450FFFD */   addiu $s0, $v0, -3

