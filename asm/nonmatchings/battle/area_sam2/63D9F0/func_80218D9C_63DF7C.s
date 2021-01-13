.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D9C_63DF7C
/* 63DF7C 80218D9C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 63DF80 80218DA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 63DF84 80218DA4 0080882D */  daddu     $s1, $a0, $zero
/* 63DF88 80218DA8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 63DF8C 80218DAC AFB3001C */  sw        $s3, 0x1c($sp)
/* 63DF90 80218DB0 AFB20018 */  sw        $s2, 0x18($sp)
/* 63DF94 80218DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 63DF98 80218DB8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 63DF9C 80218DBC 8E30000C */  lw        $s0, 0xc($s1)
/* 63DFA0 80218DC0 8E050000 */  lw        $a1, ($s0)
/* 63DFA4 80218DC4 0C0B1EAF */  jal       get_variable
/* 63DFA8 80218DC8 26100004 */   addiu    $s0, $s0, 4
/* 63DFAC 80218DCC 3C036666 */  lui       $v1, 0x6666
/* 63DFB0 80218DD0 34636667 */  ori       $v1, $v1, 0x6667
/* 63DFB4 80218DD4 00430018 */  mult      $v0, $v1
/* 63DFB8 80218DD8 000217C3 */  sra       $v0, $v0, 0x1f
/* 63DFBC 80218DDC 3C0140C9 */  lui       $at, 0x40c9
/* 63DFC0 80218DE0 34210FD0 */  ori       $at, $at, 0xfd0
/* 63DFC4 80218DE4 44810000 */  mtc1      $at, $f0
/* 63DFC8 80218DE8 00003810 */  mfhi      $a3
/* 63DFCC 80218DEC 00071883 */  sra       $v1, $a3, 2
/* 63DFD0 80218DF0 00621823 */  subu      $v1, $v1, $v0
/* 63DFD4 80218DF4 44836000 */  mtc1      $v1, $f12
/* 63DFD8 80218DF8 00000000 */  nop
/* 63DFDC 80218DFC 46806320 */  cvt.s.w   $f12, $f12
/* 63DFE0 80218E00 46006302 */  mul.s     $f12, $f12, $f0
/* 63DFE4 80218E04 00000000 */  nop
/* 63DFE8 80218E08 3C0143B4 */  lui       $at, 0x43b4
/* 63DFEC 80218E0C 44810000 */  mtc1      $at, $f0
/* 63DFF0 80218E10 3C014100 */  lui       $at, 0x4100
/* 63DFF4 80218E14 44811000 */  mtc1      $at, $f2
/* 63DFF8 80218E18 46006303 */  div.s     $f12, $f12, $f0
/* 63DFFC 80218E1C 46026302 */  mul.s     $f12, $f12, $f2
/* 63E000 80218E20 00000000 */  nop
/* 63E004 80218E24 8E120000 */  lw        $s2, ($s0)
/* 63E008 80218E28 26100004 */  addiu     $s0, $s0, 4
/* 63E00C 80218E2C 8E130000 */  lw        $s3, ($s0)
/* 63E010 80218E30 0C00A85B */  jal       sin_rad
/* 63E014 80218E34 8E100004 */   lw       $s0, 4($s0)
/* 63E018 80218E38 0220202D */  daddu     $a0, $s1, $zero
/* 63E01C 80218E3C 3C014120 */  lui       $at, 0x4120
/* 63E020 80218E40 44811000 */  mtc1      $at, $f2
/* 63E024 80218E44 0240282D */  daddu     $a1, $s2, $zero
/* 63E028 80218E48 46020502 */  mul.s     $f20, $f0, $f2
/* 63E02C 80218E4C 00000000 */  nop
/* 63E030 80218E50 0C0B2026 */  jal       set_variable
/* 63E034 80218E54 0000302D */   daddu    $a2, $zero, $zero
/* 63E038 80218E58 0220202D */  daddu     $a0, $s1, $zero
/* 63E03C 80218E5C 4600A10D */  trunc.w.s $f4, $f20
/* 63E040 80218E60 44062000 */  mfc1      $a2, $f4
/* 63E044 80218E64 0C0B2026 */  jal       set_variable
/* 63E048 80218E68 0260282D */   daddu    $a1, $s3, $zero
/* 63E04C 80218E6C 0220202D */  daddu     $a0, $s1, $zero
/* 63E050 80218E70 0200282D */  daddu     $a1, $s0, $zero
/* 63E054 80218E74 0C0B2026 */  jal       set_variable
/* 63E058 80218E78 0000302D */   daddu    $a2, $zero, $zero
/* 63E05C 80218E7C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 63E060 80218E80 8FB3001C */  lw        $s3, 0x1c($sp)
/* 63E064 80218E84 8FB20018 */  lw        $s2, 0x18($sp)
/* 63E068 80218E88 8FB10014 */  lw        $s1, 0x14($sp)
/* 63E06C 80218E8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 63E070 80218E90 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 63E074 80218E94 24020002 */  addiu     $v0, $zero, 2
/* 63E078 80218E98 03E00008 */  jr        $ra
/* 63E07C 80218E9C 27BD0030 */   addiu    $sp, $sp, 0x30
