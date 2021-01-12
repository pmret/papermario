.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219A1C_63EBFC
/* 63EBFC 80219A1C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 63EC00 80219A20 AFB10014 */  sw        $s1, 0x14($sp)
/* 63EC04 80219A24 0080882D */  daddu     $s1, $a0, $zero
/* 63EC08 80219A28 AFBF0020 */  sw        $ra, 0x20($sp)
/* 63EC0C 80219A2C AFB3001C */  sw        $s3, 0x1c($sp)
/* 63EC10 80219A30 AFB20018 */  sw        $s2, 0x18($sp)
/* 63EC14 80219A34 AFB00010 */  sw        $s0, 0x10($sp)
/* 63EC18 80219A38 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 63EC1C 80219A3C 8E30000C */  lw        $s0, 0xc($s1)
/* 63EC20 80219A40 8E050000 */  lw        $a1, ($s0)
/* 63EC24 80219A44 0C0B1EAF */  jal       get_variable
/* 63EC28 80219A48 26100004 */   addiu    $s0, $s0, 4
/* 63EC2C 80219A4C 3C036666 */  lui       $v1, 0x6666
/* 63EC30 80219A50 34636667 */  ori       $v1, $v1, 0x6667
/* 63EC34 80219A54 00430018 */  mult      $v0, $v1
/* 63EC38 80219A58 000217C3 */  sra       $v0, $v0, 0x1f
/* 63EC3C 80219A5C 3C0140C9 */  lui       $at, 0x40c9
/* 63EC40 80219A60 34210FD0 */  ori       $at, $at, 0xfd0
/* 63EC44 80219A64 44810000 */  mtc1      $at, $f0
/* 63EC48 80219A68 00003810 */  mfhi      $a3
/* 63EC4C 80219A6C 00071883 */  sra       $v1, $a3, 2
/* 63EC50 80219A70 00621823 */  subu      $v1, $v1, $v0
/* 63EC54 80219A74 44836000 */  mtc1      $v1, $f12
/* 63EC58 80219A78 00000000 */  nop
/* 63EC5C 80219A7C 46806320 */  cvt.s.w   $f12, $f12
/* 63EC60 80219A80 46006302 */  mul.s     $f12, $f12, $f0
/* 63EC64 80219A84 00000000 */  nop
/* 63EC68 80219A88 3C0143B4 */  lui       $at, 0x43b4
/* 63EC6C 80219A8C 44810000 */  mtc1      $at, $f0
/* 63EC70 80219A90 3C014100 */  lui       $at, 0x4100
/* 63EC74 80219A94 44811000 */  mtc1      $at, $f2
/* 63EC78 80219A98 46006303 */  div.s     $f12, $f12, $f0
/* 63EC7C 80219A9C 46026302 */  mul.s     $f12, $f12, $f2
/* 63EC80 80219AA0 00000000 */  nop
/* 63EC84 80219AA4 8E120000 */  lw        $s2, ($s0)
/* 63EC88 80219AA8 26100004 */  addiu     $s0, $s0, 4
/* 63EC8C 80219AAC 8E130000 */  lw        $s3, ($s0)
/* 63EC90 80219AB0 0C00A85B */  jal       sin_rad
/* 63EC94 80219AB4 8E100004 */   lw       $s0, 4($s0)
/* 63EC98 80219AB8 0220202D */  daddu     $a0, $s1, $zero
/* 63EC9C 80219ABC 3C014120 */  lui       $at, 0x4120
/* 63ECA0 80219AC0 44811000 */  mtc1      $at, $f2
/* 63ECA4 80219AC4 0240282D */  daddu     $a1, $s2, $zero
/* 63ECA8 80219AC8 46020502 */  mul.s     $f20, $f0, $f2
/* 63ECAC 80219ACC 00000000 */  nop
/* 63ECB0 80219AD0 0C0B2026 */  jal       set_variable
/* 63ECB4 80219AD4 0000302D */   daddu    $a2, $zero, $zero
/* 63ECB8 80219AD8 0220202D */  daddu     $a0, $s1, $zero
/* 63ECBC 80219ADC 4600A10D */  trunc.w.s $f4, $f20
/* 63ECC0 80219AE0 44062000 */  mfc1      $a2, $f4
/* 63ECC4 80219AE4 0C0B2026 */  jal       set_variable
/* 63ECC8 80219AE8 0260282D */   daddu    $a1, $s3, $zero
/* 63ECCC 80219AEC 0220202D */  daddu     $a0, $s1, $zero
/* 63ECD0 80219AF0 0200282D */  daddu     $a1, $s0, $zero
/* 63ECD4 80219AF4 0C0B2026 */  jal       set_variable
/* 63ECD8 80219AF8 0000302D */   daddu    $a2, $zero, $zero
/* 63ECDC 80219AFC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 63ECE0 80219B00 8FB3001C */  lw        $s3, 0x1c($sp)
/* 63ECE4 80219B04 8FB20018 */  lw        $s2, 0x18($sp)
/* 63ECE8 80219B08 8FB10014 */  lw        $s1, 0x14($sp)
/* 63ECEC 80219B0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 63ECF0 80219B10 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 63ECF4 80219B14 24020002 */  addiu     $v0, $zero, 2
/* 63ECF8 80219B18 03E00008 */  jr        $ra
/* 63ECFC 80219B1C 27BD0030 */   addiu    $sp, $sp, 0x30
