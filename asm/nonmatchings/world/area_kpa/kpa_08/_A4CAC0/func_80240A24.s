.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A24
/* A4D444 80240A24 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A4D448 80240A28 AFB30034 */  sw        $s3, 0x34($sp)
/* A4D44C 80240A2C 0080982D */  daddu     $s3, $a0, $zero
/* A4D450 80240A30 AFBF0038 */  sw        $ra, 0x38($sp)
/* A4D454 80240A34 AFB20030 */  sw        $s2, 0x30($sp)
/* A4D458 80240A38 AFB1002C */  sw        $s1, 0x2c($sp)
/* A4D45C 80240A3C AFB00028 */  sw        $s0, 0x28($sp)
/* A4D460 80240A40 8E700148 */  lw        $s0, 0x148($s3)
/* A4D464 80240A44 0C00EABB */  jal       get_npc_unsafe
/* A4D468 80240A48 86040008 */   lh       $a0, 8($s0)
/* A4D46C 80240A4C 0040902D */  daddu     $s2, $v0, $zero
/* A4D470 80240A50 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A4D474 80240A54 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A4D478 80240A58 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A4D47C 80240A5C 8E220000 */  lw        $v0, ($s1)
/* A4D480 80240A60 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A4D484 80240A64 8C460028 */  lw        $a2, 0x28($v0)
/* A4D488 80240A68 0C00A7B5 */  jal       dist2D
/* A4D48C 80240A6C 8C470030 */   lw       $a3, 0x30($v0)
/* A4D490 80240A70 24020001 */  addiu     $v0, $zero, 1
/* A4D494 80240A74 AE02006C */  sw        $v0, 0x6c($s0)
/* A4D498 80240A78 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A4D49C 80240A7C 8E0200CC */  lw        $v0, 0xcc($s0)
/* A4D4A0 80240A80 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A4D4A4 80240A84 8E230000 */  lw        $v1, ($s1)
/* A4D4A8 80240A88 8C420020 */  lw        $v0, 0x20($v0)
/* A4D4AC 80240A8C AE420028 */  sw        $v0, 0x28($s2)
/* A4D4B0 80240A90 8C660028 */  lw        $a2, 0x28($v1)
/* A4D4B4 80240A94 8C670030 */  lw        $a3, 0x30($v1)
/* A4D4B8 80240A98 0C00A720 */  jal       atan2
/* A4D4BC 80240A9C E7A00024 */   swc1     $f0, 0x24($sp)
/* A4D4C0 80240AA0 8E420000 */  lw        $v0, ($s2)
/* A4D4C4 80240AA4 3C013DCC */  lui       $at, 0x3dcc
/* A4D4C8 80240AA8 3421CCCD */  ori       $at, $at, 0xcccd
/* A4D4CC 80240AAC 44811000 */  mtc1      $at, $f2
/* A4D4D0 80240AB0 2403FFFD */  addiu     $v1, $zero, -3
/* A4D4D4 80240AB4 E640000C */  swc1      $f0, 0xc($s2)
/* A4D4D8 80240AB8 00431024 */  and       $v0, $v0, $v1
/* A4D4DC 80240ABC AE420000 */  sw        $v0, ($s2)
/* A4D4E0 80240AC0 30420008 */  andi      $v0, $v0, 8
/* A4D4E4 80240AC4 E6420054 */  swc1      $f2, 0x54($s2)
/* A4D4E8 80240AC8 E6420058 */  swc1      $f2, 0x58($s2)
/* A4D4EC 80240ACC 1440001B */  bnez      $v0, .L80240B3C
/* A4D4F0 80240AD0 E642005C */   swc1     $f2, 0x5c($s2)
/* A4D4F4 80240AD4 27A6001C */  addiu     $a2, $sp, 0x1c
/* A4D4F8 80240AD8 27A70020 */  addiu     $a3, $sp, 0x20
/* A4D4FC 80240ADC 27A20024 */  addiu     $v0, $sp, 0x24
/* A4D500 80240AE0 C6420038 */  lwc1      $f2, 0x38($s2)
/* A4D504 80240AE4 C640003C */  lwc1      $f0, 0x3c($s2)
/* A4D508 80240AE8 3C014348 */  lui       $at, 0x4348
/* A4D50C 80240AEC 44813000 */  mtc1      $at, $f6
/* A4D510 80240AF0 46000021 */  cvt.d.s   $f0, $f0
/* A4D514 80240AF4 E7A20018 */  swc1      $f2, 0x18($sp)
/* A4D518 80240AF8 3C014059 */  lui       $at, 0x4059
/* A4D51C 80240AFC 44811800 */  mtc1      $at, $f3
/* A4D520 80240B00 44801000 */  mtc1      $zero, $f2
/* A4D524 80240B04 C6440040 */  lwc1      $f4, 0x40($s2)
/* A4D528 80240B08 46220000 */  add.d     $f0, $f0, $f2
/* A4D52C 80240B0C E7A60024 */  swc1      $f6, 0x24($sp)
/* A4D530 80240B10 E7A40020 */  swc1      $f4, 0x20($sp)
/* A4D534 80240B14 46200020 */  cvt.s.d   $f0, $f0
/* A4D538 80240B18 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A4D53C 80240B1C AFA20010 */  sw        $v0, 0x10($sp)
/* A4D540 80240B20 8E440080 */  lw        $a0, 0x80($s2)
/* A4D544 80240B24 0C0372DF */  jal       func_800DCB7C
/* A4D548 80240B28 27A50018 */   addiu    $a1, $sp, 0x18
/* A4D54C 80240B2C 10400004 */  beqz      $v0, .L80240B40
/* A4D550 80240B30 2402000B */   addiu    $v0, $zero, 0xb
/* A4D554 80240B34 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A4D558 80240B38 E640003C */  swc1      $f0, 0x3c($s2)
.L80240B3C:
/* A4D55C 80240B3C 2402000B */  addiu     $v0, $zero, 0xb
.L80240B40:
/* A4D560 80240B40 A640008E */  sh        $zero, 0x8e($s2)
/* A4D564 80240B44 AE620070 */  sw        $v0, 0x70($s3)
/* A4D568 80240B48 8FBF0038 */  lw        $ra, 0x38($sp)
/* A4D56C 80240B4C 8FB30034 */  lw        $s3, 0x34($sp)
/* A4D570 80240B50 8FB20030 */  lw        $s2, 0x30($sp)
/* A4D574 80240B54 8FB1002C */  lw        $s1, 0x2c($sp)
/* A4D578 80240B58 8FB00028 */  lw        $s0, 0x28($sp)
/* A4D57C 80240B5C 03E00008 */  jr        $ra
/* A4D580 80240B60 27BD0040 */   addiu    $sp, $sp, 0x40
