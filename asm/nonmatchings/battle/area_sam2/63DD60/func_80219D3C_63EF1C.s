.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219D3C_63EF1C
/* 63EF1C 80219D3C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 63EF20 80219D40 AFB10014 */  sw        $s1, 0x14($sp)
/* 63EF24 80219D44 0080882D */  daddu     $s1, $a0, $zero
/* 63EF28 80219D48 AFBF0020 */  sw        $ra, 0x20($sp)
/* 63EF2C 80219D4C AFB3001C */  sw        $s3, 0x1c($sp)
/* 63EF30 80219D50 AFB20018 */  sw        $s2, 0x18($sp)
/* 63EF34 80219D54 AFB00010 */  sw        $s0, 0x10($sp)
/* 63EF38 80219D58 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 63EF3C 80219D5C 8E30000C */  lw        $s0, 0xc($s1)
/* 63EF40 80219D60 8E050000 */  lw        $a1, ($s0)
/* 63EF44 80219D64 0C0B1EAF */  jal       get_variable
/* 63EF48 80219D68 26100004 */   addiu    $s0, $s0, 4
/* 63EF4C 80219D6C 3C036666 */  lui       $v1, 0x6666
/* 63EF50 80219D70 34636667 */  ori       $v1, $v1, 0x6667
/* 63EF54 80219D74 00430018 */  mult      $v0, $v1
/* 63EF58 80219D78 000217C3 */  sra       $v0, $v0, 0x1f
/* 63EF5C 80219D7C 3C0140C9 */  lui       $at, 0x40c9
/* 63EF60 80219D80 34210FD0 */  ori       $at, $at, 0xfd0
/* 63EF64 80219D84 44810000 */  mtc1      $at, $f0
/* 63EF68 80219D88 00003810 */  mfhi      $a3
/* 63EF6C 80219D8C 00071883 */  sra       $v1, $a3, 2
/* 63EF70 80219D90 00621823 */  subu      $v1, $v1, $v0
/* 63EF74 80219D94 44836000 */  mtc1      $v1, $f12
/* 63EF78 80219D98 00000000 */  nop
/* 63EF7C 80219D9C 46806320 */  cvt.s.w   $f12, $f12
/* 63EF80 80219DA0 46006302 */  mul.s     $f12, $f12, $f0
/* 63EF84 80219DA4 00000000 */  nop
/* 63EF88 80219DA8 3C0143B4 */  lui       $at, 0x43b4
/* 63EF8C 80219DAC 44810000 */  mtc1      $at, $f0
/* 63EF90 80219DB0 3C014100 */  lui       $at, 0x4100
/* 63EF94 80219DB4 44811000 */  mtc1      $at, $f2
/* 63EF98 80219DB8 46006303 */  div.s     $f12, $f12, $f0
/* 63EF9C 80219DBC 46026302 */  mul.s     $f12, $f12, $f2
/* 63EFA0 80219DC0 00000000 */  nop
/* 63EFA4 80219DC4 8E120000 */  lw        $s2, ($s0)
/* 63EFA8 80219DC8 26100004 */  addiu     $s0, $s0, 4
/* 63EFAC 80219DCC 8E130000 */  lw        $s3, ($s0)
/* 63EFB0 80219DD0 0C00A85B */  jal       sin_rad
/* 63EFB4 80219DD4 8E100004 */   lw       $s0, 4($s0)
/* 63EFB8 80219DD8 0220202D */  daddu     $a0, $s1, $zero
/* 63EFBC 80219DDC 3C014120 */  lui       $at, 0x4120
/* 63EFC0 80219DE0 44811000 */  mtc1      $at, $f2
/* 63EFC4 80219DE4 0240282D */  daddu     $a1, $s2, $zero
/* 63EFC8 80219DE8 46020502 */  mul.s     $f20, $f0, $f2
/* 63EFCC 80219DEC 00000000 */  nop
/* 63EFD0 80219DF0 0C0B2026 */  jal       set_variable
/* 63EFD4 80219DF4 0000302D */   daddu    $a2, $zero, $zero
/* 63EFD8 80219DF8 0220202D */  daddu     $a0, $s1, $zero
/* 63EFDC 80219DFC 4600A10D */  trunc.w.s $f4, $f20
/* 63EFE0 80219E00 44062000 */  mfc1      $a2, $f4
/* 63EFE4 80219E04 0C0B2026 */  jal       set_variable
/* 63EFE8 80219E08 0260282D */   daddu    $a1, $s3, $zero
/* 63EFEC 80219E0C 0220202D */  daddu     $a0, $s1, $zero
/* 63EFF0 80219E10 0200282D */  daddu     $a1, $s0, $zero
/* 63EFF4 80219E14 0C0B2026 */  jal       set_variable
/* 63EFF8 80219E18 0000302D */   daddu    $a2, $zero, $zero
/* 63EFFC 80219E1C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 63F000 80219E20 8FB3001C */  lw        $s3, 0x1c($sp)
/* 63F004 80219E24 8FB20018 */  lw        $s2, 0x18($sp)
/* 63F008 80219E28 8FB10014 */  lw        $s1, 0x14($sp)
/* 63F00C 80219E2C 8FB00010 */  lw        $s0, 0x10($sp)
/* 63F010 80219E30 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 63F014 80219E34 24020002 */  addiu     $v0, $zero, 2
/* 63F018 80219E38 03E00008 */  jr        $ra
/* 63F01C 80219E3C 27BD0030 */   addiu    $sp, $sp, 0x30
