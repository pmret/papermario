.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A54_DB2D14
/* DB2D14 80240A54 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DB2D18 80240A58 AFB3002C */  sw        $s3, 0x2c($sp)
/* DB2D1C 80240A5C 0080982D */  daddu     $s3, $a0, $zero
/* DB2D20 80240A60 AFBF0030 */  sw        $ra, 0x30($sp)
/* DB2D24 80240A64 AFB20028 */  sw        $s2, 0x28($sp)
/* DB2D28 80240A68 AFB10024 */  sw        $s1, 0x24($sp)
/* DB2D2C 80240A6C AFB00020 */  sw        $s0, 0x20($sp)
/* DB2D30 80240A70 8E710148 */  lw        $s1, 0x148($s3)
/* DB2D34 80240A74 86240008 */  lh        $a0, 8($s1)
/* DB2D38 80240A78 0C00EABB */  jal       get_npc_unsafe
/* DB2D3C 80240A7C 00A0902D */   daddu    $s2, $a1, $zero
/* DB2D40 80240A80 8E440004 */  lw        $a0, 4($s2)
/* DB2D44 80240A84 0040802D */  daddu     $s0, $v0, $zero
/* DB2D48 80240A88 00041FC2 */  srl       $v1, $a0, 0x1f
/* DB2D4C 80240A8C 00832021 */  addu      $a0, $a0, $v1
/* DB2D50 80240A90 00042043 */  sra       $a0, $a0, 1
/* DB2D54 80240A94 0C00A67F */  jal       rand_int
/* DB2D58 80240A98 24840001 */   addiu    $a0, $a0, 1
/* DB2D5C 80240A9C 8E430004 */  lw        $v1, 4($s2)
/* DB2D60 80240AA0 000327C2 */  srl       $a0, $v1, 0x1f
/* DB2D64 80240AA4 00641821 */  addu      $v1, $v1, $a0
/* DB2D68 80240AA8 00031843 */  sra       $v1, $v1, 1
/* DB2D6C 80240AAC 00621821 */  addu      $v1, $v1, $v0
/* DB2D70 80240AB0 A603008E */  sh        $v1, 0x8e($s0)
/* DB2D74 80240AB4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DB2D78 80240AB8 C6000040 */  lwc1      $f0, 0x40($s0)
/* DB2D7C 80240ABC C4640000 */  lwc1      $f4, ($v1)
/* DB2D80 80240AC0 46802120 */  cvt.s.w   $f4, $f4
/* DB2D84 80240AC4 C4620008 */  lwc1      $f2, 8($v1)
/* DB2D88 80240AC8 468010A0 */  cvt.s.w   $f2, $f2
/* DB2D8C 80240ACC E7A00010 */  swc1      $f0, 0x10($sp)
/* DB2D90 80240AD0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB2D94 80240AD4 44061000 */  mfc1      $a2, $f2
/* DB2D98 80240AD8 C440000C */  lwc1      $f0, 0xc($v0)
/* DB2D9C 80240ADC 46800020 */  cvt.s.w   $f0, $f0
/* DB2DA0 80240AE0 E7A00014 */  swc1      $f0, 0x14($sp)
/* DB2DA4 80240AE4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB2DA8 80240AE8 44052000 */  mfc1      $a1, $f4
/* DB2DAC 80240AEC C4400010 */  lwc1      $f0, 0x10($v0)
/* DB2DB0 80240AF0 46800020 */  cvt.s.w   $f0, $f0
/* DB2DB4 80240AF4 E7A00018 */  swc1      $f0, 0x18($sp)
/* DB2DB8 80240AF8 8C640018 */  lw        $a0, 0x18($v1)
/* DB2DBC 80240AFC 0C0123F5 */  jal       is_point_within_region
/* DB2DC0 80240B00 8E070038 */   lw       $a3, 0x38($s0)
/* DB2DC4 80240B04 1040000E */  beqz      $v0, .L80240B40
/* DB2DC8 80240B08 00000000 */   nop
/* DB2DCC 80240B0C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB2DD0 80240B10 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DB2DD4 80240B14 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DB2DD8 80240B18 C4460000 */  lwc1      $f6, ($v0)
/* DB2DDC 80240B1C 468031A0 */  cvt.s.w   $f6, $f6
/* DB2DE0 80240B20 44063000 */  mfc1      $a2, $f6
/* DB2DE4 80240B24 C4460008 */  lwc1      $f6, 8($v0)
/* DB2DE8 80240B28 468031A0 */  cvt.s.w   $f6, $f6
/* DB2DEC 80240B2C 44073000 */  mfc1      $a3, $f6
/* DB2DF0 80240B30 0C00A720 */  jal       atan2
/* DB2DF4 80240B34 00000000 */   nop
/* DB2DF8 80240B38 080902DC */  j         .L80240B70
/* DB2DFC 80240B3C E600000C */   swc1     $f0, 0xc($s0)
.L80240B40:
/* DB2E00 80240B40 0C00A67F */  jal       rand_int
/* DB2E04 80240B44 2404003C */   addiu    $a0, $zero, 0x3c
/* DB2E08 80240B48 C60C000C */  lwc1      $f12, 0xc($s0)
/* DB2E0C 80240B4C 44820000 */  mtc1      $v0, $f0
/* DB2E10 80240B50 00000000 */  nop
/* DB2E14 80240B54 46800020 */  cvt.s.w   $f0, $f0
/* DB2E18 80240B58 46006300 */  add.s     $f12, $f12, $f0
/* DB2E1C 80240B5C 3C0141F0 */  lui       $at, 0x41f0
/* DB2E20 80240B60 44810000 */  mtc1      $at, $f0
/* DB2E24 80240B64 0C00A6C9 */  jal       clamp_angle
/* DB2E28 80240B68 46006301 */   sub.s    $f12, $f12, $f0
/* DB2E2C 80240B6C E600000C */  swc1      $f0, 0xc($s0)
.L80240B70:
/* DB2E30 80240B70 8E2200CC */  lw        $v0, 0xcc($s1)
/* DB2E34 80240B74 8C420004 */  lw        $v0, 4($v0)
/* DB2E38 80240B78 AE020028 */  sw        $v0, 0x28($s0)
/* DB2E3C 80240B7C AE600074 */  sw        $zero, 0x74($s3)
/* DB2E40 80240B80 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB2E44 80240B84 8C420014 */  lw        $v0, 0x14($v0)
/* DB2E48 80240B88 04410004 */  bgez      $v0, .L80240B9C
/* DB2E4C 80240B8C 00000000 */   nop
/* DB2E50 80240B90 C6400000 */  lwc1      $f0, ($s2)
/* DB2E54 80240B94 080902EF */  j         .L80240BBC
/* DB2E58 80240B98 E6000018 */   swc1     $f0, 0x18($s0)
.L80240B9C:
/* DB2E5C 80240B9C 3C018024 */  lui       $at, %hi(D_802455F0)
/* DB2E60 80240BA0 D42255F0 */  ldc1      $f2, %lo(D_802455F0)($at)
/* DB2E64 80240BA4 44820000 */  mtc1      $v0, $f0
/* DB2E68 80240BA8 00000000 */  nop
/* DB2E6C 80240BAC 46800021 */  cvt.d.w   $f0, $f0
/* DB2E70 80240BB0 46220003 */  div.d     $f0, $f0, $f2
/* DB2E74 80240BB4 46200020 */  cvt.s.d   $f0, $f0
/* DB2E78 80240BB8 E6000018 */  swc1      $f0, 0x18($s0)
.L80240BBC:
/* DB2E7C 80240BBC C600003C */  lwc1      $f0, 0x3c($s0)
/* DB2E80 80240BC0 3C014059 */  lui       $at, 0x4059
/* DB2E84 80240BC4 44811800 */  mtc1      $at, $f3
/* DB2E88 80240BC8 44801000 */  mtc1      $zero, $f2
/* DB2E8C 80240BCC 46000021 */  cvt.d.s   $f0, $f0
/* DB2E90 80240BD0 46220002 */  mul.d     $f0, $f0, $f2
/* DB2E94 80240BD4 00000000 */  nop
/* DB2E98 80240BD8 24020001 */  addiu     $v0, $zero, 1
/* DB2E9C 80240BDC 4620018D */  trunc.w.d $f6, $f0
/* DB2EA0 80240BE0 E626007C */  swc1      $f6, 0x7c($s1)
/* DB2EA4 80240BE4 AE620070 */  sw        $v0, 0x70($s3)
/* DB2EA8 80240BE8 8FBF0030 */  lw        $ra, 0x30($sp)
/* DB2EAC 80240BEC 8FB3002C */  lw        $s3, 0x2c($sp)
/* DB2EB0 80240BF0 8FB20028 */  lw        $s2, 0x28($sp)
/* DB2EB4 80240BF4 8FB10024 */  lw        $s1, 0x24($sp)
/* DB2EB8 80240BF8 8FB00020 */  lw        $s0, 0x20($sp)
/* DB2EBC 80240BFC 03E00008 */  jr        $ra
/* DB2EC0 80240C00 27BD0038 */   addiu    $sp, $sp, 0x38
