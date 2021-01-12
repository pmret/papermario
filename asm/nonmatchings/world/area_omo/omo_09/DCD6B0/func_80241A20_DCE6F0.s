.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A20_DCE6F0
/* DCE6F0 80241A20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCE6F4 80241A24 AFB10014 */  sw        $s1, 0x14($sp)
/* DCE6F8 80241A28 0080882D */  daddu     $s1, $a0, $zero
/* DCE6FC 80241A2C AFBF001C */  sw        $ra, 0x1c($sp)
/* DCE700 80241A30 AFB20018 */  sw        $s2, 0x18($sp)
/* DCE704 80241A34 AFB00010 */  sw        $s0, 0x10($sp)
/* DCE708 80241A38 8E300148 */  lw        $s0, 0x148($s1)
/* DCE70C 80241A3C 86040008 */  lh        $a0, 8($s0)
/* DCE710 80241A40 0C00EABB */  jal       get_npc_unsafe
/* DCE714 80241A44 00A0902D */   daddu    $s2, $a1, $zero
/* DCE718 80241A48 8E0300D0 */  lw        $v1, 0xd0($s0)
/* DCE71C 80241A4C 8E240078 */  lw        $a0, 0x78($s1)
/* DCE720 80241A50 8C630000 */  lw        $v1, ($v1)
/* DCE724 80241A54 0083182A */  slt       $v1, $a0, $v1
/* DCE728 80241A58 10600013 */  beqz      $v1, .L80241AA8
/* DCE72C 80241A5C 0040302D */   daddu    $a2, $v0, $zero
/* DCE730 80241A60 00041040 */  sll       $v0, $a0, 1
/* DCE734 80241A64 00441021 */  addu      $v0, $v0, $a0
/* DCE738 80241A68 00022880 */  sll       $a1, $v0, 2
.L80241A6C:
/* DCE73C 80241A6C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* DCE740 80241A70 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* DCE744 80241A74 00A31021 */  addu      $v0, $a1, $v1
/* DCE748 80241A78 C4400008 */  lwc1      $f0, 8($v0)
/* DCE74C 80241A7C 46800020 */  cvt.s.w   $f0, $f0
/* DCE750 80241A80 4602003E */  c.le.s    $f0, $f2
/* DCE754 80241A84 00000000 */  nop
/* DCE758 80241A88 45020003 */  bc1fl     .L80241A98
/* DCE75C 80241A8C 24840001 */   addiu    $a0, $a0, 1
/* DCE760 80241A90 080906AA */  j         .L80241AA8
/* DCE764 80241A94 AE240078 */   sw       $a0, 0x78($s1)
.L80241A98:
/* DCE768 80241A98 8C620000 */  lw        $v0, ($v1)
/* DCE76C 80241A9C 0082102A */  slt       $v0, $a0, $v0
/* DCE770 80241AA0 1440FFF2 */  bnez      $v0, .L80241A6C
/* DCE774 80241AA4 24A5000C */   addiu    $a1, $a1, 0xc
.L80241AA8:
/* DCE778 80241AA8 C6400000 */  lwc1      $f0, ($s2)
/* DCE77C 80241AAC E4C00018 */  swc1      $f0, 0x18($a2)
/* DCE780 80241AB0 8E0200CC */  lw        $v0, 0xcc($s0)
/* DCE784 80241AB4 8C420004 */  lw        $v0, 4($v0)
/* DCE788 80241AB8 ACC20028 */  sw        $v0, 0x28($a2)
/* DCE78C 80241ABC 24020001 */  addiu     $v0, $zero, 1
/* DCE790 80241AC0 AE200074 */  sw        $zero, 0x74($s1)
/* DCE794 80241AC4 AE220070 */  sw        $v0, 0x70($s1)
/* DCE798 80241AC8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DCE79C 80241ACC 8FB20018 */  lw        $s2, 0x18($sp)
/* DCE7A0 80241AD0 8FB10014 */  lw        $s1, 0x14($sp)
/* DCE7A4 80241AD4 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE7A8 80241AD8 03E00008 */  jr        $ra
/* DCE7AC 80241ADC 27BD0020 */   addiu    $sp, $sp, 0x20
