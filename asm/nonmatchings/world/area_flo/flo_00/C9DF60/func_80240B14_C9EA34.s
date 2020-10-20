.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B14_C9EA34
/* C9EA34 80240B14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9EA38 80240B18 AFB10014 */  sw        $s1, 0x14($sp)
/* C9EA3C 80240B1C 0080882D */  daddu     $s1, $a0, $zero
/* C9EA40 80240B20 AFBF001C */  sw        $ra, 0x1c($sp)
/* C9EA44 80240B24 AFB20018 */  sw        $s2, 0x18($sp)
/* C9EA48 80240B28 AFB00010 */  sw        $s0, 0x10($sp)
/* C9EA4C 80240B2C 8E300148 */  lw        $s0, 0x148($s1)
/* C9EA50 80240B30 86040008 */  lh        $a0, 8($s0)
/* C9EA54 80240B34 0C00EABB */  jal       get_npc_unsafe
/* C9EA58 80240B38 00A0902D */   daddu    $s2, $a1, $zero
/* C9EA5C 80240B3C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* C9EA60 80240B40 8E240078 */  lw        $a0, 0x78($s1)
/* C9EA64 80240B44 8C630000 */  lw        $v1, ($v1)
/* C9EA68 80240B48 0083182A */  slt       $v1, $a0, $v1
/* C9EA6C 80240B4C 10600013 */  beqz      $v1, .L80240B9C
/* C9EA70 80240B50 0040302D */   daddu    $a2, $v0, $zero
/* C9EA74 80240B54 00041040 */  sll       $v0, $a0, 1
/* C9EA78 80240B58 00441021 */  addu      $v0, $v0, $a0
/* C9EA7C 80240B5C 00022880 */  sll       $a1, $v0, 2
.L80240B60:
/* C9EA80 80240B60 8E0300D0 */  lw        $v1, 0xd0($s0)
/* C9EA84 80240B64 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* C9EA88 80240B68 00A31021 */  addu      $v0, $a1, $v1
/* C9EA8C 80240B6C C4400008 */  lwc1      $f0, 8($v0)
/* C9EA90 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* C9EA94 80240B74 4602003E */  c.le.s    $f0, $f2
/* C9EA98 80240B78 00000000 */  nop       
/* C9EA9C 80240B7C 45020003 */  bc1fl     .L80240B8C
/* C9EAA0 80240B80 24840001 */   addiu    $a0, $a0, 1
/* C9EAA4 80240B84 080902E7 */  j         .L80240B9C
/* C9EAA8 80240B88 AE240078 */   sw       $a0, 0x78($s1)
.L80240B8C:
/* C9EAAC 80240B8C 8C620000 */  lw        $v0, ($v1)
/* C9EAB0 80240B90 0082102A */  slt       $v0, $a0, $v0
/* C9EAB4 80240B94 1440FFF2 */  bnez      $v0, .L80240B60
/* C9EAB8 80240B98 24A5000C */   addiu    $a1, $a1, 0xc
.L80240B9C:
/* C9EABC 80240B9C C6400000 */  lwc1      $f0, ($s2)
/* C9EAC0 80240BA0 E4C00018 */  swc1      $f0, 0x18($a2)
/* C9EAC4 80240BA4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C9EAC8 80240BA8 8C420004 */  lw        $v0, 4($v0)
/* C9EACC 80240BAC ACC20028 */  sw        $v0, 0x28($a2)
/* C9EAD0 80240BB0 24020001 */  addiu     $v0, $zero, 1
/* C9EAD4 80240BB4 AE200074 */  sw        $zero, 0x74($s1)
/* C9EAD8 80240BB8 AE220070 */  sw        $v0, 0x70($s1)
/* C9EADC 80240BBC 8FBF001C */  lw        $ra, 0x1c($sp)
/* C9EAE0 80240BC0 8FB20018 */  lw        $s2, 0x18($sp)
/* C9EAE4 80240BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* C9EAE8 80240BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* C9EAEC 80240BCC 03E00008 */  jr        $ra
/* C9EAF0 80240BD0 27BD0020 */   addiu    $sp, $sp, 0x20
