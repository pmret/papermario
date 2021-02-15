.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024159C_D8E7EC
/* D8E7EC 8024159C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8E7F0 802415A0 AFB10014 */  sw        $s1, 0x14($sp)
/* D8E7F4 802415A4 0080882D */  daddu     $s1, $a0, $zero
/* D8E7F8 802415A8 AFBF001C */  sw        $ra, 0x1c($sp)
/* D8E7FC 802415AC AFB20018 */  sw        $s2, 0x18($sp)
/* D8E800 802415B0 AFB00010 */  sw        $s0, 0x10($sp)
/* D8E804 802415B4 8E300148 */  lw        $s0, 0x148($s1)
/* D8E808 802415B8 86040008 */  lh        $a0, 8($s0)
/* D8E80C 802415BC 0C00EABB */  jal       get_npc_unsafe
/* D8E810 802415C0 00A0902D */   daddu    $s2, $a1, $zero
/* D8E814 802415C4 8E230078 */  lw        $v1, 0x78($s1)
/* D8E818 802415C8 24630001 */  addiu     $v1, $v1, 1
/* D8E81C 802415CC AE230078 */  sw        $v1, 0x78($s1)
/* D8E820 802415D0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* D8E824 802415D4 8C840000 */  lw        $a0, ($a0)
/* D8E828 802415D8 0064182A */  slt       $v1, $v1, $a0
/* D8E82C 802415DC 14600002 */  bnez      $v1, .L802415E8
/* D8E830 802415E0 0040282D */   daddu    $a1, $v0, $zero
/* D8E834 802415E4 AE200078 */  sw        $zero, 0x78($s1)
.L802415E8:
/* D8E838 802415E8 8E0200CC */  lw        $v0, 0xcc($s0)
/* D8E83C 802415EC 8C420004 */  lw        $v0, 4($v0)
/* D8E840 802415F0 ACA20028 */  sw        $v0, 0x28($a1)
/* D8E844 802415F4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* D8E848 802415F8 8C42007C */  lw        $v0, 0x7c($v0)
/* D8E84C 802415FC 04410004 */  bgez      $v0, .L80241610
/* D8E850 80241600 00000000 */   nop
/* D8E854 80241604 C6400000 */  lwc1      $f0, ($s2)
/* D8E858 80241608 0809058C */  j         .L80241630
/* D8E85C 8024160C E4A00018 */   swc1     $f0, 0x18($a1)
.L80241610:
/* D8E860 80241610 3C018024 */  lui       $at, %hi(D_80243FE8_D91238)
/* D8E864 80241614 D4223FE8 */  ldc1      $f2, %lo(D_80243FE8_D91238)($at)
/* D8E868 80241618 44820000 */  mtc1      $v0, $f0
/* D8E86C 8024161C 00000000 */  nop
/* D8E870 80241620 46800021 */  cvt.d.w   $f0, $f0
/* D8E874 80241624 46220003 */  div.d     $f0, $f0, $f2
/* D8E878 80241628 46200020 */  cvt.s.d   $f0, $f0
/* D8E87C 8024162C E4A00018 */  swc1      $f0, 0x18($a1)
.L80241630:
/* D8E880 80241630 24020001 */  addiu     $v0, $zero, 1
/* D8E884 80241634 AE220070 */  sw        $v0, 0x70($s1)
/* D8E888 80241638 8FBF001C */  lw        $ra, 0x1c($sp)
/* D8E88C 8024163C 8FB20018 */  lw        $s2, 0x18($sp)
/* D8E890 80241640 8FB10014 */  lw        $s1, 0x14($sp)
/* D8E894 80241644 8FB00010 */  lw        $s0, 0x10($sp)
/* D8E898 80241648 03E00008 */  jr        $ra
/* D8E89C 8024164C 27BD0020 */   addiu    $sp, $sp, 0x20
