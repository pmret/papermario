.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_04_UnkFunc16
/* 9A9B48 80241758 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A9B4C 8024175C AFB10014 */  sw        $s1, 0x14($sp)
/* 9A9B50 80241760 0080882D */  daddu     $s1, $a0, $zero
/* 9A9B54 80241764 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A9B58 80241768 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A9B5C 8024176C AFB00010 */  sw        $s0, 0x10($sp)
/* 9A9B60 80241770 8E300148 */  lw        $s0, 0x148($s1)
/* 9A9B64 80241774 86040008 */  lh        $a0, 8($s0)
/* 9A9B68 80241778 0C00EABB */  jal       get_npc_unsafe
/* 9A9B6C 8024177C 00A0902D */   daddu    $s2, $a1, $zero
/* 9A9B70 80241780 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 9A9B74 80241784 8E240078 */  lw        $a0, 0x78($s1)
/* 9A9B78 80241788 8C630000 */  lw        $v1, ($v1)
/* 9A9B7C 8024178C 0083182A */  slt       $v1, $a0, $v1
/* 9A9B80 80241790 10600013 */  beqz      $v1, .L802417E0
/* 9A9B84 80241794 0040302D */   daddu    $a2, $v0, $zero
/* 9A9B88 80241798 00041040 */  sll       $v0, $a0, 1
/* 9A9B8C 8024179C 00441021 */  addu      $v0, $v0, $a0
/* 9A9B90 802417A0 00022880 */  sll       $a1, $v0, 2
.L802417A4:
/* 9A9B94 802417A4 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 9A9B98 802417A8 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* 9A9B9C 802417AC 00A31021 */  addu      $v0, $a1, $v1
/* 9A9BA0 802417B0 C4400008 */  lwc1      $f0, 8($v0)
/* 9A9BA4 802417B4 46800020 */  cvt.s.w   $f0, $f0
/* 9A9BA8 802417B8 4602003E */  c.le.s    $f0, $f2
/* 9A9BAC 802417BC 00000000 */  nop
/* 9A9BB0 802417C0 45020003 */  bc1fl     .L802417D0
/* 9A9BB4 802417C4 24840001 */   addiu    $a0, $a0, 1
/* 9A9BB8 802417C8 080905F8 */  j         .L802417E0
/* 9A9BBC 802417CC AE240078 */   sw       $a0, 0x78($s1)
.L802417D0:
/* 9A9BC0 802417D0 8C620000 */  lw        $v0, ($v1)
/* 9A9BC4 802417D4 0082102A */  slt       $v0, $a0, $v0
/* 9A9BC8 802417D8 1440FFF2 */  bnez      $v0, .L802417A4
/* 9A9BCC 802417DC 24A5000C */   addiu    $a1, $a1, 0xc
.L802417E0:
/* 9A9BD0 802417E0 C6400000 */  lwc1      $f0, ($s2)
/* 9A9BD4 802417E4 E4C00018 */  swc1      $f0, 0x18($a2)
/* 9A9BD8 802417E8 8E0200CC */  lw        $v0, 0xcc($s0)
/* 9A9BDC 802417EC 8C420004 */  lw        $v0, 4($v0)
/* 9A9BE0 802417F0 ACC20028 */  sw        $v0, 0x28($a2)
/* 9A9BE4 802417F4 24020001 */  addiu     $v0, $zero, 1
/* 9A9BE8 802417F8 AE200074 */  sw        $zero, 0x74($s1)
/* 9A9BEC 802417FC AE220070 */  sw        $v0, 0x70($s1)
/* 9A9BF0 80241800 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A9BF4 80241804 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A9BF8 80241808 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A9BFC 8024180C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A9C00 80241810 03E00008 */  jr        $ra
/* 9A9C04 80241814 27BD0020 */   addiu    $sp, $sp, 0x20
