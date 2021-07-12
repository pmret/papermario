.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409D4_A64A64
/* A64A64 802409D4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A64A68 802409D8 AFB30034 */  sw        $s3, 0x34($sp)
/* A64A6C 802409DC 0080982D */  daddu     $s3, $a0, $zero
/* A64A70 802409E0 AFBF0038 */  sw        $ra, 0x38($sp)
/* A64A74 802409E4 AFB20030 */  sw        $s2, 0x30($sp)
/* A64A78 802409E8 AFB1002C */  sw        $s1, 0x2c($sp)
/* A64A7C 802409EC AFB00028 */  sw        $s0, 0x28($sp)
/* A64A80 802409F0 8E700148 */  lw        $s0, 0x148($s3)
/* A64A84 802409F4 0C00EABB */  jal       get_npc_unsafe
/* A64A88 802409F8 86040008 */   lh       $a0, 8($s0)
/* A64A8C 802409FC 0040902D */  daddu     $s2, $v0, $zero
/* A64A90 80240A00 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A64A94 80240A04 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A64A98 80240A08 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A64A9C 80240A0C 8E220000 */  lw        $v0, ($s1)
/* A64AA0 80240A10 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A64AA4 80240A14 8C460028 */  lw        $a2, 0x28($v0)
/* A64AA8 80240A18 0C00A7B5 */  jal       dist2D
/* A64AAC 80240A1C 8C470030 */   lw       $a3, 0x30($v0)
/* A64AB0 80240A20 24020001 */  addiu     $v0, $zero, 1
/* A64AB4 80240A24 AE02006C */  sw        $v0, 0x6c($s0)
/* A64AB8 80240A28 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A64ABC 80240A2C 8E0200CC */  lw        $v0, 0xcc($s0)
/* A64AC0 80240A30 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A64AC4 80240A34 8E230000 */  lw        $v1, ($s1)
/* A64AC8 80240A38 8C420020 */  lw        $v0, 0x20($v0)
/* A64ACC 80240A3C AE420028 */  sw        $v0, 0x28($s2)
/* A64AD0 80240A40 8C660028 */  lw        $a2, 0x28($v1)
/* A64AD4 80240A44 8C670030 */  lw        $a3, 0x30($v1)
/* A64AD8 80240A48 0C00A720 */  jal       atan2
/* A64ADC 80240A4C E7A00024 */   swc1     $f0, 0x24($sp)
/* A64AE0 80240A50 8E420000 */  lw        $v0, ($s2)
/* A64AE4 80240A54 3C013DCC */  lui       $at, 0x3dcc
/* A64AE8 80240A58 3421CCCD */  ori       $at, $at, 0xcccd
/* A64AEC 80240A5C 44811000 */  mtc1      $at, $f2
/* A64AF0 80240A60 2403FFFD */  addiu     $v1, $zero, -3
/* A64AF4 80240A64 E640000C */  swc1      $f0, 0xc($s2)
/* A64AF8 80240A68 00431024 */  and       $v0, $v0, $v1
/* A64AFC 80240A6C AE420000 */  sw        $v0, ($s2)
/* A64B00 80240A70 30420008 */  andi      $v0, $v0, 8
/* A64B04 80240A74 E6420054 */  swc1      $f2, 0x54($s2)
/* A64B08 80240A78 E6420058 */  swc1      $f2, 0x58($s2)
/* A64B0C 80240A7C 1440001B */  bnez      $v0, .L80240AEC
/* A64B10 80240A80 E642005C */   swc1     $f2, 0x5c($s2)
/* A64B14 80240A84 27A6001C */  addiu     $a2, $sp, 0x1c
/* A64B18 80240A88 27A70020 */  addiu     $a3, $sp, 0x20
/* A64B1C 80240A8C 27A20024 */  addiu     $v0, $sp, 0x24
/* A64B20 80240A90 C6420038 */  lwc1      $f2, 0x38($s2)
/* A64B24 80240A94 C640003C */  lwc1      $f0, 0x3c($s2)
/* A64B28 80240A98 3C014348 */  lui       $at, 0x4348
/* A64B2C 80240A9C 44813000 */  mtc1      $at, $f6
/* A64B30 80240AA0 46000021 */  cvt.d.s   $f0, $f0
/* A64B34 80240AA4 E7A20018 */  swc1      $f2, 0x18($sp)
/* A64B38 80240AA8 3C014059 */  lui       $at, 0x4059
/* A64B3C 80240AAC 44811800 */  mtc1      $at, $f3
/* A64B40 80240AB0 44801000 */  mtc1      $zero, $f2
/* A64B44 80240AB4 C6440040 */  lwc1      $f4, 0x40($s2)
/* A64B48 80240AB8 46220000 */  add.d     $f0, $f0, $f2
/* A64B4C 80240ABC E7A60024 */  swc1      $f6, 0x24($sp)
/* A64B50 80240AC0 E7A40020 */  swc1      $f4, 0x20($sp)
/* A64B54 80240AC4 46200020 */  cvt.s.d   $f0, $f0
/* A64B58 80240AC8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A64B5C 80240ACC AFA20010 */  sw        $v0, 0x10($sp)
/* A64B60 80240AD0 8E440080 */  lw        $a0, 0x80($s2)
/* A64B64 80240AD4 0C0372DF */  jal       npc_raycast_down_sides
/* A64B68 80240AD8 27A50018 */   addiu    $a1, $sp, 0x18
/* A64B6C 80240ADC 10400004 */  beqz      $v0, .L80240AF0
/* A64B70 80240AE0 2402000B */   addiu    $v0, $zero, 0xb
/* A64B74 80240AE4 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A64B78 80240AE8 E640003C */  swc1      $f0, 0x3c($s2)
.L80240AEC:
/* A64B7C 80240AEC 2402000B */  addiu     $v0, $zero, 0xb
.L80240AF0:
/* A64B80 80240AF0 A640008E */  sh        $zero, 0x8e($s2)
/* A64B84 80240AF4 AE620070 */  sw        $v0, 0x70($s3)
/* A64B88 80240AF8 8FBF0038 */  lw        $ra, 0x38($sp)
/* A64B8C 80240AFC 8FB30034 */  lw        $s3, 0x34($sp)
/* A64B90 80240B00 8FB20030 */  lw        $s2, 0x30($sp)
/* A64B94 80240B04 8FB1002C */  lw        $s1, 0x2c($sp)
/* A64B98 80240B08 8FB00028 */  lw        $s0, 0x28($sp)
/* A64B9C 80240B0C 03E00008 */  jr        $ra
/* A64BA0 80240B10 27BD0040 */   addiu    $sp, $sp, 0x40
