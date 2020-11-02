.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283A50
/* 7E48D0 80283A50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E48D4 80283A54 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E48D8 80283A58 0080902D */  daddu     $s2, $a0, $zero
/* 7E48DC 80283A5C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E48E0 80283A60 00A0802D */  daddu     $s0, $a1, $zero
/* 7E48E4 80283A64 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E48E8 80283A68 0C016AFA */  jal       get_current_map_header
/* 7E48EC 80283A6C AFB10014 */   sw       $s1, 0x14($sp)
/* 7E48F0 80283A70 0000302D */  daddu     $a2, $zero, $zero
/* 7E48F4 80283A74 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7E48F8 80283A78 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7E48FC 80283A7C 12000021 */  beqz      $s0, .L80283B04
/* 7E4900 80283A80 0040282D */   daddu    $a1, $v0, $zero
/* 7E4904 80283A84 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 7E4908 80283A88 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 7E490C 80283A8C 8482008E */  lh        $v0, 0x8e($a0)
/* 7E4910 80283A90 8CA30014 */  lw        $v1, 0x14($a1)
/* 7E4914 80283A94 00021100 */  sll       $v0, $v0, 4
/* 7E4918 80283A98 00431021 */  addu      $v0, $v0, $v1
/* 7E491C 80283A9C C4400000 */  lwc1      $f0, ($v0)
/* 7E4920 80283AA0 E6200028 */  swc1      $f0, 0x28($s1)
/* 7E4924 80283AA4 8482008E */  lh        $v0, 0x8e($a0)
/* 7E4928 80283AA8 8CA30014 */  lw        $v1, 0x14($a1)
/* 7E492C 80283AAC 00021100 */  sll       $v0, $v0, 4
/* 7E4930 80283AB0 00431021 */  addu      $v0, $v0, $v1
/* 7E4934 80283AB4 C4400008 */  lwc1      $f0, 8($v0)
/* 7E4938 80283AB8 E6200030 */  swc1      $f0, 0x30($s1)
/* 7E493C 80283ABC 8482008E */  lh        $v0, 0x8e($a0)
/* 7E4940 80283AC0 8CA30014 */  lw        $v1, 0x14($a1)
/* 7E4944 80283AC4 00021100 */  sll       $v0, $v0, 4
/* 7E4948 80283AC8 00431021 */  addu      $v0, $v0, $v1
/* 7E494C 80283ACC C4400004 */  lwc1      $f0, 4($v0)
/* 7E4950 80283AD0 4600018D */  trunc.w.s $f6, $f0
/* 7E4954 80283AD4 44023000 */  mfc1      $v0, $f6
/* 7E4958 80283AD8 00000000 */  nop       
/* 7E495C 80283ADC AE42008C */  sw        $v0, 0x8c($s2)
/* 7E4960 80283AE0 2442FFD8 */  addiu     $v0, $v0, -0x28
/* 7E4964 80283AE4 44820000 */  mtc1      $v0, $f0
/* 7E4968 80283AE8 00000000 */  nop       
/* 7E496C 80283AEC 46800020 */  cvt.s.w   $f0, $f0
/* 7E4970 80283AF0 8E220000 */  lw        $v0, ($s1)
/* 7E4974 80283AF4 3C030400 */  lui       $v1, 0x400
/* 7E4978 80283AF8 E620002C */  swc1      $f0, 0x2c($s1)
/* 7E497C 80283AFC 080A0ED2 */  j         .L80283B48
/* 7E4980 80283B00 00431025 */   or       $v0, $v0, $v1
.L80283B04:
/* 7E4984 80283B04 C622002C */  lwc1      $f2, 0x2c($s1)
/* 7E4988 80283B08 3C013F80 */  lui       $at, 0x3f80
/* 7E498C 80283B0C 44810000 */  mtc1      $at, $f0
/* 7E4990 80283B10 00000000 */  nop       
/* 7E4994 80283B14 46001080 */  add.s     $f2, $f2, $f0
/* 7E4998 80283B18 E622002C */  swc1      $f2, 0x2c($s1)
/* 7E499C 80283B1C C640008C */  lwc1      $f0, 0x8c($s2)
/* 7E49A0 80283B20 46800020 */  cvt.s.w   $f0, $f0
/* 7E49A4 80283B24 4600103C */  c.lt.s    $f2, $f0
/* 7E49A8 80283B28 00000000 */  nop       
/* 7E49AC 80283B2C 45010007 */  bc1t      .L80283B4C
/* 7E49B0 80283B30 3C03FBFF */   lui      $v1, 0xfbff
/* 7E49B4 80283B34 3463FFFF */  ori       $v1, $v1, 0xffff
/* 7E49B8 80283B38 8E220000 */  lw        $v0, ($s1)
/* 7E49BC 80283B3C 24060002 */  addiu     $a2, $zero, 2
/* 7E49C0 80283B40 E620002C */  swc1      $f0, 0x2c($s1)
/* 7E49C4 80283B44 00431024 */  and       $v0, $v0, $v1
.L80283B48:
/* 7E49C8 80283B48 AE220000 */  sw        $v0, ($s1)
.L80283B4C:
/* 7E49CC 80283B4C C6200028 */  lwc1      $f0, 0x28($s1)
/* 7E49D0 80283B50 C622002C */  lwc1      $f2, 0x2c($s1)
/* 7E49D4 80283B54 C6240030 */  lwc1      $f4, 0x30($s1)
/* 7E49D8 80283B58 3C03800B */  lui       $v1, %hi(gCameras)
/* 7E49DC 80283B5C 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 7E49E0 80283B60 E4600060 */  swc1      $f0, 0x60($v1)
/* 7E49E4 80283B64 E4620064 */  swc1      $f2, 0x64($v1)
/* 7E49E8 80283B68 E4640068 */  swc1      $f4, 0x68($v1)
/* 7E49EC 80283B6C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E49F0 80283B70 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E49F4 80283B74 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E49F8 80283B78 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E49FC 80283B7C 00C0102D */  daddu     $v0, $a2, $zero
/* 7E4A00 80283B80 03E00008 */  jr        $ra
/* 7E4A04 80283B84 27BD0020 */   addiu    $sp, $sp, 0x20
