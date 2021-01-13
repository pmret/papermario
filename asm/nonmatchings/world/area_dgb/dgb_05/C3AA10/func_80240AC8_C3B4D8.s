.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AC8_C3B4D8
/* C3B4D8 80240AC8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C3B4DC 80240ACC AFB20020 */  sw        $s2, 0x20($sp)
/* C3B4E0 80240AD0 0080902D */  daddu     $s2, $a0, $zero
/* C3B4E4 80240AD4 AFBF0028 */  sw        $ra, 0x28($sp)
/* C3B4E8 80240AD8 AFB30024 */  sw        $s3, 0x24($sp)
/* C3B4EC 80240ADC AFB1001C */  sw        $s1, 0x1c($sp)
/* C3B4F0 80240AE0 AFB00018 */  sw        $s0, 0x18($sp)
/* C3B4F4 80240AE4 8E510148 */  lw        $s1, 0x148($s2)
/* C3B4F8 80240AE8 00A0982D */  daddu     $s3, $a1, $zero
/* C3B4FC 80240AEC 86240008 */  lh        $a0, 8($s1)
/* C3B500 80240AF0 0C00EABB */  jal       get_npc_unsafe
/* C3B504 80240AF4 00C0802D */   daddu    $s0, $a2, $zero
/* C3B508 80240AF8 0200202D */  daddu     $a0, $s0, $zero
/* C3B50C 80240AFC 0040802D */  daddu     $s0, $v0, $zero
/* C3B510 80240B00 AFA00010 */  sw        $zero, 0x10($sp)
/* C3B514 80240B04 8E660024 */  lw        $a2, 0x24($s3)
/* C3B518 80240B08 8E670028 */  lw        $a3, 0x28($s3)
/* C3B51C 80240B0C 0C01242D */  jal       func_800490B4
/* C3B520 80240B10 0220282D */   daddu    $a1, $s1, $zero
/* C3B524 80240B14 1040000C */  beqz      $v0, .L80240B48
/* C3B528 80240B18 00000000 */   nop
/* C3B52C 80240B1C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C3B530 80240B20 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3B534 80240B24 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3B538 80240B28 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3B53C 80240B2C 8C460028 */  lw        $a2, 0x28($v0)
/* C3B540 80240B30 0C00A720 */  jal       atan2
/* C3B544 80240B34 8C470030 */   lw       $a3, 0x30($v0)
/* C3B548 80240B38 2402000C */  addiu     $v0, $zero, 0xc
/* C3B54C 80240B3C E600000C */  swc1      $f0, 0xc($s0)
/* C3B550 80240B40 080902F9 */  j         .L80240BE4
/* C3B554 80240B44 AE420070 */   sw       $v0, 0x70($s2)
.L80240B48:
/* C3B558 80240B48 9602008E */  lhu       $v0, 0x8e($s0)
/* C3B55C 80240B4C 2442FFFF */  addiu     $v0, $v0, -1
/* C3B560 80240B50 A602008E */  sh        $v0, 0x8e($s0)
/* C3B564 80240B54 00021400 */  sll       $v0, $v0, 0x10
/* C3B568 80240B58 1C400022 */  bgtz      $v0, .L80240BE4
/* C3B56C 80240B5C 00000000 */   nop
/* C3B570 80240B60 8E420074 */  lw        $v0, 0x74($s2)
/* C3B574 80240B64 2442FFFF */  addiu     $v0, $v0, -1
/* C3B578 80240B68 18400014 */  blez      $v0, .L80240BBC
/* C3B57C 80240B6C AE420074 */   sw       $v0, 0x74($s2)
/* C3B580 80240B70 C600000C */  lwc1      $f0, 0xc($s0)
/* C3B584 80240B74 3C014334 */  lui       $at, 0x4334
/* C3B588 80240B78 44816000 */  mtc1      $at, $f12
/* C3B58C 80240B7C 0C00A6C9 */  jal       clamp_angle
/* C3B590 80240B80 460C0300 */   add.s    $f12, $f0, $f12
/* C3B594 80240B84 E600000C */  swc1      $f0, 0xc($s0)
/* C3B598 80240B88 8E640008 */  lw        $a0, 8($s3)
/* C3B59C 80240B8C 000417C2 */  srl       $v0, $a0, 0x1f
/* C3B5A0 80240B90 00822021 */  addu      $a0, $a0, $v0
/* C3B5A4 80240B94 00042043 */  sra       $a0, $a0, 1
/* C3B5A8 80240B98 0C00A67F */  jal       rand_int
/* C3B5AC 80240B9C 24840001 */   addiu    $a0, $a0, 1
/* C3B5B0 80240BA0 8E630008 */  lw        $v1, 8($s3)
/* C3B5B4 80240BA4 000327C2 */  srl       $a0, $v1, 0x1f
/* C3B5B8 80240BA8 00641821 */  addu      $v1, $v1, $a0
/* C3B5BC 80240BAC 00031843 */  sra       $v1, $v1, 1
/* C3B5C0 80240BB0 00621821 */  addu      $v1, $v1, $v0
/* C3B5C4 80240BB4 080902F9 */  j         .L80240BE4
/* C3B5C8 80240BB8 A603008E */   sh       $v1, 0x8e($s0)
.L80240BBC:
/* C3B5CC 80240BBC 8E250088 */  lw        $a1, 0x88($s1)
/* C3B5D0 80240BC0 24020028 */  addiu     $v0, $zero, 0x28
/* C3B5D4 80240BC4 14A20003 */  bne       $a1, $v0, .L80240BD4
/* C3B5D8 80240BC8 24020032 */   addiu    $v0, $zero, 0x32
/* C3B5DC 80240BCC 080902F7 */  j         .L80240BDC
/* C3B5E0 80240BD0 24020014 */   addiu    $v0, $zero, 0x14
.L80240BD4:
/* C3B5E4 80240BD4 14A20003 */  bne       $a1, $v0, .L80240BE4
/* C3B5E8 80240BD8 24020019 */   addiu    $v0, $zero, 0x19
.L80240BDC:
/* C3B5EC 80240BDC A602008E */  sh        $v0, 0x8e($s0)
/* C3B5F0 80240BE0 AE450070 */  sw        $a1, 0x70($s2)
.L80240BE4:
/* C3B5F4 80240BE4 8FBF0028 */  lw        $ra, 0x28($sp)
/* C3B5F8 80240BE8 8FB30024 */  lw        $s3, 0x24($sp)
/* C3B5FC 80240BEC 8FB20020 */  lw        $s2, 0x20($sp)
/* C3B600 80240BF0 8FB1001C */  lw        $s1, 0x1c($sp)
/* C3B604 80240BF4 8FB00018 */  lw        $s0, 0x18($sp)
/* C3B608 80240BF8 03E00008 */  jr        $ra
/* C3B60C 80240BFC 27BD0030 */   addiu    $sp, $sp, 0x30
