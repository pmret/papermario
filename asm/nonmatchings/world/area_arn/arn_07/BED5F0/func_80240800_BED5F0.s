.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240800_BED5F0
/* BED5F0 80240800 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BED5F4 80240804 AFB00010 */  sw        $s0, 0x10($sp)
/* BED5F8 80240808 0080802D */  daddu     $s0, $a0, $zero
/* BED5FC 8024080C 3C05FE36 */  lui       $a1, 0xfe36
/* BED600 80240810 AFBF0014 */  sw        $ra, 0x14($sp)
/* BED604 80240814 0C0B210B */  jal       get_float_variable
/* BED608 80240818 34A53C80 */   ori      $a1, $a1, 0x3c80
/* BED60C 8024081C 46000086 */  mov.s     $f2, $f0
/* BED610 80240820 3C018024 */  lui       $at, %hi(D_80247940)
/* BED614 80240824 D4247940 */  ldc1      $f4, %lo(D_80247940)($at)
/* BED618 80240828 46001021 */  cvt.d.s   $f0, $f2
/* BED61C 8024082C 4620203E */  c.le.d    $f4, $f0
/* BED620 80240830 00000000 */  nop
/* BED624 80240834 45000003 */  bc1f      .L80240844
/* BED628 80240838 0200202D */   daddu    $a0, $s0, $zero
/* BED62C 8024083C 46240001 */  sub.d     $f0, $f0, $f4
/* BED630 80240840 462000A0 */  cvt.s.d   $f2, $f0
.L80240844:
/* BED634 80240844 3C05FE36 */  lui       $a1, 0xfe36
/* BED638 80240848 44061000 */  mfc1      $a2, $f2
/* BED63C 8024084C 0C0B2190 */  jal       set_float_variable
/* BED640 80240850 34A53C80 */   ori      $a1, $a1, 0x3c80
/* BED644 80240854 8FBF0014 */  lw        $ra, 0x14($sp)
/* BED648 80240858 8FB00010 */  lw        $s0, 0x10($sp)
/* BED64C 8024085C 24020002 */  addiu     $v0, $zero, 2
/* BED650 80240860 03E00008 */  jr        $ra
/* BED654 80240864 27BD0018 */   addiu    $sp, $sp, 0x18
/* BED658 80240868 00000000 */  nop
/* BED65C 8024086C 00000000 */  nop
