.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415C8_DCE298
/* DCE298 802415C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCE29C 802415CC AFB10014 */  sw        $s1, 0x14($sp)
/* DCE2A0 802415D0 0080882D */  daddu     $s1, $a0, $zero
/* DCE2A4 802415D4 AFBF001C */  sw        $ra, 0x1c($sp)
/* DCE2A8 802415D8 AFB20018 */  sw        $s2, 0x18($sp)
/* DCE2AC 802415DC AFB00010 */  sw        $s0, 0x10($sp)
/* DCE2B0 802415E0 8E300148 */  lw        $s0, 0x148($s1)
/* DCE2B4 802415E4 86040008 */  lh        $a0, 8($s0)
/* DCE2B8 802415E8 0C00EABB */  jal       get_npc_unsafe
/* DCE2BC 802415EC 00A0902D */   daddu    $s2, $a1, $zero
/* DCE2C0 802415F0 8E230078 */  lw        $v1, 0x78($s1)
/* DCE2C4 802415F4 24630001 */  addiu     $v1, $v1, 1
/* DCE2C8 802415F8 AE230078 */  sw        $v1, 0x78($s1)
/* DCE2CC 802415FC 8E0400D0 */  lw        $a0, 0xd0($s0)
/* DCE2D0 80241600 8C840000 */  lw        $a0, ($a0)
/* DCE2D4 80241604 0064182A */  slt       $v1, $v1, $a0
/* DCE2D8 80241608 14600002 */  bnez      $v1, .L80241614
/* DCE2DC 8024160C 0040282D */   daddu    $a1, $v0, $zero
/* DCE2E0 80241610 AE200078 */  sw        $zero, 0x78($s1)
.L80241614:
/* DCE2E4 80241614 8E0200CC */  lw        $v0, 0xcc($s0)
/* DCE2E8 80241618 8C420004 */  lw        $v0, 4($v0)
/* DCE2EC 8024161C ACA20028 */  sw        $v0, 0x28($a1)
/* DCE2F0 80241620 8E0200D0 */  lw        $v0, 0xd0($s0)
/* DCE2F4 80241624 8C42007C */  lw        $v0, 0x7c($v0)
/* DCE2F8 80241628 04410004 */  bgez      $v0, .L8024163C
/* DCE2FC 8024162C 00000000 */   nop
/* DCE300 80241630 C6400000 */  lwc1      $f0, ($s2)
/* DCE304 80241634 08090597 */  j         .L8024165C
/* DCE308 80241638 E4A00018 */   swc1     $f0, 0x18($a1)
.L8024163C:
/* DCE30C 8024163C 3C018025 */  lui       $at, %hi(D_8024A7D8_DD74A8)
/* DCE310 80241640 D422A7D8 */  ldc1      $f2, %lo(D_8024A7D8_DD74A8)($at)
/* DCE314 80241644 44820000 */  mtc1      $v0, $f0
/* DCE318 80241648 00000000 */  nop
/* DCE31C 8024164C 46800021 */  cvt.d.w   $f0, $f0
/* DCE320 80241650 46220003 */  div.d     $f0, $f0, $f2
/* DCE324 80241654 46200020 */  cvt.s.d   $f0, $f0
/* DCE328 80241658 E4A00018 */  swc1      $f0, 0x18($a1)
.L8024165C:
/* DCE32C 8024165C 24020001 */  addiu     $v0, $zero, 1
/* DCE330 80241660 AE220070 */  sw        $v0, 0x70($s1)
/* DCE334 80241664 8FBF001C */  lw        $ra, 0x1c($sp)
/* DCE338 80241668 8FB20018 */  lw        $s2, 0x18($sp)
/* DCE33C 8024166C 8FB10014 */  lw        $s1, 0x14($sp)
/* DCE340 80241670 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE344 80241674 03E00008 */  jr        $ra
/* DCE348 80241678 27BD0020 */   addiu    $sp, $sp, 0x20
