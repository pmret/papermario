.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241610_D31290
/* D31290 80241610 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D31294 80241614 AFB10014 */  sw        $s1, 0x14($sp)
/* D31298 80241618 0080882D */  daddu     $s1, $a0, $zero
/* D3129C 8024161C AFBF001C */  sw        $ra, 0x1c($sp)
/* D312A0 80241620 AFB20018 */  sw        $s2, 0x18($sp)
/* D312A4 80241624 AFB00010 */  sw        $s0, 0x10($sp)
/* D312A8 80241628 8E30000C */  lw        $s0, 0xc($s1)
/* D312AC 8024162C 8E050000 */  lw        $a1, ($s0)
/* D312B0 80241630 0C0B1EAF */  jal       get_variable
/* D312B4 80241634 26100004 */   addiu    $s0, $s0, 4
/* D312B8 80241638 8E050000 */  lw        $a1, ($s0)
/* D312BC 8024163C 26100004 */  addiu     $s0, $s0, 4
/* D312C0 80241640 0220202D */  daddu     $a0, $s1, $zero
/* D312C4 80241644 0C0B1EAF */  jal       get_variable
/* D312C8 80241648 0040902D */   daddu    $s2, $v0, $zero
/* D312CC 8024164C 0220202D */  daddu     $a0, $s1, $zero
/* D312D0 80241650 8E050000 */  lw        $a1, ($s0)
/* D312D4 80241654 0C0B1EAF */  jal       get_variable
/* D312D8 80241658 0040802D */   daddu    $s0, $v0, $zero
/* D312DC 8024165C 44926000 */  mtc1      $s2, $f12
/* D312E0 80241660 00000000 */  nop
/* D312E4 80241664 46806320 */  cvt.s.w   $f12, $f12
/* D312E8 80241668 44820000 */  mtc1      $v0, $f0
/* D312EC 8024166C 00000000 */  nop
/* D312F0 80241670 46800020 */  cvt.s.w   $f0, $f0
/* D312F4 80241674 44060000 */  mfc1      $a2, $f0
/* D312F8 80241678 44907000 */  mtc1      $s0, $f14
/* D312FC 8024167C 00000000 */  nop
/* D31300 80241680 0C01BE3C */  jal       func_8006F8F0
/* D31304 80241684 468073A0 */   cvt.s.w  $f14, $f14
/* D31308 80241688 8FBF001C */  lw        $ra, 0x1c($sp)
/* D3130C 8024168C 8FB20018 */  lw        $s2, 0x18($sp)
/* D31310 80241690 8FB10014 */  lw        $s1, 0x14($sp)
/* D31314 80241694 8FB00010 */  lw        $s0, 0x10($sp)
/* D31318 80241698 24020002 */  addiu     $v0, $zero, 2
/* D3131C 8024169C 03E00008 */  jr        $ra
/* D31320 802416A0 27BD0020 */   addiu    $sp, $sp, 0x20
