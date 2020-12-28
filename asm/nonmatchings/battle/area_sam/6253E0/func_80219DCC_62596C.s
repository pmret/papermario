.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219DCC_62596C
/* 62596C 80219DCC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 625970 80219DD0 AFB10014 */  sw        $s1, 0x14($sp)
/* 625974 80219DD4 0080882D */  daddu     $s1, $a0, $zero
/* 625978 80219DD8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 62597C 80219DDC AFB3001C */  sw        $s3, 0x1c($sp)
/* 625980 80219DE0 AFB20018 */  sw        $s2, 0x18($sp)
/* 625984 80219DE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 625988 80219DE8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 62598C 80219DEC 8E30000C */  lw        $s0, 0xc($s1)
/* 625990 80219DF0 8E050000 */  lw        $a1, ($s0)
/* 625994 80219DF4 0C0B1EAF */  jal       get_variable
/* 625998 80219DF8 26100004 */   addiu    $s0, $s0, 4
/* 62599C 80219DFC 3C036666 */  lui       $v1, 0x6666
/* 6259A0 80219E00 34636667 */  ori       $v1, $v1, 0x6667
/* 6259A4 80219E04 00430018 */  mult      $v0, $v1
/* 6259A8 80219E08 000217C3 */  sra       $v0, $v0, 0x1f
/* 6259AC 80219E0C 3C0140C9 */  lui       $at, 0x40c9
/* 6259B0 80219E10 34210FD0 */  ori       $at, $at, 0xfd0
/* 6259B4 80219E14 44810000 */  mtc1      $at, $f0
/* 6259B8 80219E18 00003810 */  mfhi      $a3
/* 6259BC 80219E1C 00071883 */  sra       $v1, $a3, 2
/* 6259C0 80219E20 00621823 */  subu      $v1, $v1, $v0
/* 6259C4 80219E24 44836000 */  mtc1      $v1, $f12
/* 6259C8 80219E28 00000000 */  nop       
/* 6259CC 80219E2C 46806320 */  cvt.s.w   $f12, $f12
/* 6259D0 80219E30 46006302 */  mul.s     $f12, $f12, $f0
/* 6259D4 80219E34 00000000 */  nop       
/* 6259D8 80219E38 3C0143B4 */  lui       $at, 0x43b4
/* 6259DC 80219E3C 44810000 */  mtc1      $at, $f0
/* 6259E0 80219E40 3C014100 */  lui       $at, 0x4100
/* 6259E4 80219E44 44811000 */  mtc1      $at, $f2
/* 6259E8 80219E48 46006303 */  div.s     $f12, $f12, $f0
/* 6259EC 80219E4C 46026302 */  mul.s     $f12, $f12, $f2
/* 6259F0 80219E50 00000000 */  nop       
/* 6259F4 80219E54 8E120000 */  lw        $s2, ($s0)
/* 6259F8 80219E58 26100004 */  addiu     $s0, $s0, 4
/* 6259FC 80219E5C 8E130000 */  lw        $s3, ($s0)
/* 625A00 80219E60 0C00A85B */  jal       sin_rad
/* 625A04 80219E64 8E100004 */   lw       $s0, 4($s0)
/* 625A08 80219E68 0220202D */  daddu     $a0, $s1, $zero
/* 625A0C 80219E6C 3C014120 */  lui       $at, 0x4120
/* 625A10 80219E70 44811000 */  mtc1      $at, $f2
/* 625A14 80219E74 0240282D */  daddu     $a1, $s2, $zero
/* 625A18 80219E78 46020502 */  mul.s     $f20, $f0, $f2
/* 625A1C 80219E7C 00000000 */  nop       
/* 625A20 80219E80 0C0B2026 */  jal       set_variable
/* 625A24 80219E84 0000302D */   daddu    $a2, $zero, $zero
/* 625A28 80219E88 0220202D */  daddu     $a0, $s1, $zero
/* 625A2C 80219E8C 4600A10D */  trunc.w.s $f4, $f20
/* 625A30 80219E90 44062000 */  mfc1      $a2, $f4
/* 625A34 80219E94 0C0B2026 */  jal       set_variable
/* 625A38 80219E98 0260282D */   daddu    $a1, $s3, $zero
/* 625A3C 80219E9C 0220202D */  daddu     $a0, $s1, $zero
/* 625A40 80219EA0 0200282D */  daddu     $a1, $s0, $zero
/* 625A44 80219EA4 0C0B2026 */  jal       set_variable
/* 625A48 80219EA8 0000302D */   daddu    $a2, $zero, $zero
/* 625A4C 80219EAC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 625A50 80219EB0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 625A54 80219EB4 8FB20018 */  lw        $s2, 0x18($sp)
/* 625A58 80219EB8 8FB10014 */  lw        $s1, 0x14($sp)
/* 625A5C 80219EBC 8FB00010 */  lw        $s0, 0x10($sp)
/* 625A60 80219EC0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 625A64 80219EC4 24020002 */  addiu     $v0, $zero, 2
/* 625A68 80219EC8 03E00008 */  jr        $ra
/* 625A6C 80219ECC 27BD0030 */   addiu    $sp, $sp, 0x30
