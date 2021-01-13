.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B14_EB9964
/* EB9964 80240B14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB9968 80240B18 AFB10014 */  sw        $s1, 0x14($sp)
/* EB996C 80240B1C 0080882D */  daddu     $s1, $a0, $zero
/* EB9970 80240B20 AFBF001C */  sw        $ra, 0x1c($sp)
/* EB9974 80240B24 AFB20018 */  sw        $s2, 0x18($sp)
/* EB9978 80240B28 AFB00010 */  sw        $s0, 0x10($sp)
/* EB997C 80240B2C 8E300148 */  lw        $s0, 0x148($s1)
/* EB9980 80240B30 86040008 */  lh        $a0, 8($s0)
/* EB9984 80240B34 0C00F92F */  jal       func_8003E4BC
/* EB9988 80240B38 00A0902D */   daddu    $s2, $a1, $zero
/* EB998C 80240B3C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EB9990 80240B40 8E240078 */  lw        $a0, 0x78($s1)
/* EB9994 80240B44 8C630000 */  lw        $v1, ($v1)
/* EB9998 80240B48 0083182A */  slt       $v1, $a0, $v1
/* EB999C 80240B4C 10600013 */  beqz      $v1, .L80240B9C
/* EB99A0 80240B50 0040302D */   daddu    $a2, $v0, $zero
/* EB99A4 80240B54 00041040 */  sll       $v0, $a0, 1
/* EB99A8 80240B58 00441021 */  addu      $v0, $v0, $a0
/* EB99AC 80240B5C 00022880 */  sll       $a1, $v0, 2
.L80240B60:
/* EB99B0 80240B60 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EB99B4 80240B64 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* EB99B8 80240B68 00A31021 */  addu      $v0, $a1, $v1
/* EB99BC 80240B6C C4400008 */  lwc1      $f0, 8($v0)
/* EB99C0 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* EB99C4 80240B74 4602003E */  c.le.s    $f0, $f2
/* EB99C8 80240B78 00000000 */  nop
/* EB99CC 80240B7C 45020003 */  bc1fl     .L80240B8C
/* EB99D0 80240B80 24840001 */   addiu    $a0, $a0, 1
/* EB99D4 80240B84 080902E7 */  j         .L80240B9C
/* EB99D8 80240B88 AE240078 */   sw       $a0, 0x78($s1)
.L80240B8C:
/* EB99DC 80240B8C 8C620000 */  lw        $v0, ($v1)
/* EB99E0 80240B90 0082102A */  slt       $v0, $a0, $v0
/* EB99E4 80240B94 1440FFF2 */  bnez      $v0, .L80240B60
/* EB99E8 80240B98 24A5000C */   addiu    $a1, $a1, 0xc
.L80240B9C:
/* EB99EC 80240B9C C6400000 */  lwc1      $f0, ($s2)
/* EB99F0 80240BA0 E4C00018 */  swc1      $f0, 0x18($a2)
/* EB99F4 80240BA4 8E0200CC */  lw        $v0, 0xcc($s0)
/* EB99F8 80240BA8 8C420004 */  lw        $v0, 4($v0)
/* EB99FC 80240BAC ACC20028 */  sw        $v0, 0x28($a2)
/* EB9A00 80240BB0 24020001 */  addiu     $v0, $zero, 1
/* EB9A04 80240BB4 AE200074 */  sw        $zero, 0x74($s1)
/* EB9A08 80240BB8 AE220070 */  sw        $v0, 0x70($s1)
/* EB9A0C 80240BBC 8FBF001C */  lw        $ra, 0x1c($sp)
/* EB9A10 80240BC0 8FB20018 */  lw        $s2, 0x18($sp)
/* EB9A14 80240BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* EB9A18 80240BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* EB9A1C 80240BCC 03E00008 */  jr        $ra
/* EB9A20 80240BD0 27BD0020 */   addiu    $sp, $sp, 0x20
