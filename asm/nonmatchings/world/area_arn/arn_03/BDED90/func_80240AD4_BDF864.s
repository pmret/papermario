.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD4_BDF864
/* BDF864 80240AD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDF868 80240AD8 AFB10014 */  sw        $s1, 0x14($sp)
/* BDF86C 80240ADC 0080882D */  daddu     $s1, $a0, $zero
/* BDF870 80240AE0 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDF874 80240AE4 AFB20018 */  sw        $s2, 0x18($sp)
/* BDF878 80240AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* BDF87C 80240AEC 8E300148 */  lw        $s0, 0x148($s1)
/* BDF880 80240AF0 86040008 */  lh        $a0, 8($s0)
/* BDF884 80240AF4 0C00EABB */  jal       get_npc_unsafe
/* BDF888 80240AF8 00A0902D */   daddu    $s2, $a1, $zero
/* BDF88C 80240AFC 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BDF890 80240B00 8E240078 */  lw        $a0, 0x78($s1)
/* BDF894 80240B04 8C630000 */  lw        $v1, ($v1)
/* BDF898 80240B08 0083182A */  slt       $v1, $a0, $v1
/* BDF89C 80240B0C 10600013 */  beqz      $v1, .L80240B5C
/* BDF8A0 80240B10 0040302D */   daddu    $a2, $v0, $zero
/* BDF8A4 80240B14 00041040 */  sll       $v0, $a0, 1
/* BDF8A8 80240B18 00441021 */  addu      $v0, $v0, $a0
/* BDF8AC 80240B1C 00022880 */  sll       $a1, $v0, 2
.L80240B20:
/* BDF8B0 80240B20 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BDF8B4 80240B24 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* BDF8B8 80240B28 00A31021 */  addu      $v0, $a1, $v1
/* BDF8BC 80240B2C C4400008 */  lwc1      $f0, 8($v0)
/* BDF8C0 80240B30 46800020 */  cvt.s.w   $f0, $f0
/* BDF8C4 80240B34 4602003E */  c.le.s    $f0, $f2
/* BDF8C8 80240B38 00000000 */  nop       
/* BDF8CC 80240B3C 45020003 */  bc1fl     .L80240B4C
/* BDF8D0 80240B40 24840001 */   addiu    $a0, $a0, 1
/* BDF8D4 80240B44 080902D7 */  j         .L80240B5C
/* BDF8D8 80240B48 AE240078 */   sw       $a0, 0x78($s1)
.L80240B4C:
/* BDF8DC 80240B4C 8C620000 */  lw        $v0, ($v1)
/* BDF8E0 80240B50 0082102A */  slt       $v0, $a0, $v0
/* BDF8E4 80240B54 1440FFF2 */  bnez      $v0, .L80240B20
/* BDF8E8 80240B58 24A5000C */   addiu    $a1, $a1, 0xc
.L80240B5C:
/* BDF8EC 80240B5C C6400000 */  lwc1      $f0, ($s2)
/* BDF8F0 80240B60 E4C00018 */  swc1      $f0, 0x18($a2)
/* BDF8F4 80240B64 8E0200CC */  lw        $v0, 0xcc($s0)
/* BDF8F8 80240B68 8C420004 */  lw        $v0, 4($v0)
/* BDF8FC 80240B6C ACC20028 */  sw        $v0, 0x28($a2)
/* BDF900 80240B70 24020001 */  addiu     $v0, $zero, 1
/* BDF904 80240B74 AE200074 */  sw        $zero, 0x74($s1)
/* BDF908 80240B78 AE220070 */  sw        $v0, 0x70($s1)
/* BDF90C 80240B7C 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDF910 80240B80 8FB20018 */  lw        $s2, 0x18($sp)
/* BDF914 80240B84 8FB10014 */  lw        $s1, 0x14($sp)
/* BDF918 80240B88 8FB00010 */  lw        $s0, 0x10($sp)
/* BDF91C 80240B8C 03E00008 */  jr        $ra
/* BDF920 80240B90 27BD0020 */   addiu    $sp, $sp, 0x20
