.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A40C_625FAC
/* 625FAC 8021A40C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 625FB0 8021A410 AFB10014 */  sw        $s1, 0x14($sp)
/* 625FB4 8021A414 0080882D */  daddu     $s1, $a0, $zero
/* 625FB8 8021A418 AFBF0020 */  sw        $ra, 0x20($sp)
/* 625FBC 8021A41C AFB3001C */  sw        $s3, 0x1c($sp)
/* 625FC0 8021A420 AFB20018 */  sw        $s2, 0x18($sp)
/* 625FC4 8021A424 AFB00010 */  sw        $s0, 0x10($sp)
/* 625FC8 8021A428 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 625FCC 8021A42C 8E30000C */  lw        $s0, 0xc($s1)
/* 625FD0 8021A430 8E050000 */  lw        $a1, ($s0)
/* 625FD4 8021A434 0C0B1EAF */  jal       get_variable
/* 625FD8 8021A438 26100004 */   addiu    $s0, $s0, 4
/* 625FDC 8021A43C 3C036666 */  lui       $v1, 0x6666
/* 625FE0 8021A440 34636667 */  ori       $v1, $v1, 0x6667
/* 625FE4 8021A444 00430018 */  mult      $v0, $v1
/* 625FE8 8021A448 000217C3 */  sra       $v0, $v0, 0x1f
/* 625FEC 8021A44C 3C0140C9 */  lui       $at, 0x40c9
/* 625FF0 8021A450 34210FD0 */  ori       $at, $at, 0xfd0
/* 625FF4 8021A454 44810000 */  mtc1      $at, $f0
/* 625FF8 8021A458 00003810 */  mfhi      $a3
/* 625FFC 8021A45C 00071883 */  sra       $v1, $a3, 2
/* 626000 8021A460 00621823 */  subu      $v1, $v1, $v0
/* 626004 8021A464 44836000 */  mtc1      $v1, $f12
/* 626008 8021A468 00000000 */  nop
/* 62600C 8021A46C 46806320 */  cvt.s.w   $f12, $f12
/* 626010 8021A470 46006302 */  mul.s     $f12, $f12, $f0
/* 626014 8021A474 00000000 */  nop
/* 626018 8021A478 3C0143B4 */  lui       $at, 0x43b4
/* 62601C 8021A47C 44810000 */  mtc1      $at, $f0
/* 626020 8021A480 3C014100 */  lui       $at, 0x4100
/* 626024 8021A484 44811000 */  mtc1      $at, $f2
/* 626028 8021A488 46006303 */  div.s     $f12, $f12, $f0
/* 62602C 8021A48C 46026302 */  mul.s     $f12, $f12, $f2
/* 626030 8021A490 00000000 */  nop
/* 626034 8021A494 8E120000 */  lw        $s2, ($s0)
/* 626038 8021A498 26100004 */  addiu     $s0, $s0, 4
/* 62603C 8021A49C 8E130000 */  lw        $s3, ($s0)
/* 626040 8021A4A0 0C00A85B */  jal       sin_rad
/* 626044 8021A4A4 8E100004 */   lw       $s0, 4($s0)
/* 626048 8021A4A8 0220202D */  daddu     $a0, $s1, $zero
/* 62604C 8021A4AC 3C014120 */  lui       $at, 0x4120
/* 626050 8021A4B0 44811000 */  mtc1      $at, $f2
/* 626054 8021A4B4 0240282D */  daddu     $a1, $s2, $zero
/* 626058 8021A4B8 46020502 */  mul.s     $f20, $f0, $f2
/* 62605C 8021A4BC 00000000 */  nop
/* 626060 8021A4C0 0C0B2026 */  jal       set_variable
/* 626064 8021A4C4 0000302D */   daddu    $a2, $zero, $zero
/* 626068 8021A4C8 0220202D */  daddu     $a0, $s1, $zero
/* 62606C 8021A4CC 4600A10D */  trunc.w.s $f4, $f20
/* 626070 8021A4D0 44062000 */  mfc1      $a2, $f4
/* 626074 8021A4D4 0C0B2026 */  jal       set_variable
/* 626078 8021A4D8 0260282D */   daddu    $a1, $s3, $zero
/* 62607C 8021A4DC 0220202D */  daddu     $a0, $s1, $zero
/* 626080 8021A4E0 0200282D */  daddu     $a1, $s0, $zero
/* 626084 8021A4E4 0C0B2026 */  jal       set_variable
/* 626088 8021A4E8 0000302D */   daddu    $a2, $zero, $zero
/* 62608C 8021A4EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 626090 8021A4F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 626094 8021A4F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 626098 8021A4F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 62609C 8021A4FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6260A0 8021A500 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 6260A4 8021A504 24020002 */  addiu     $v0, $zero, 2
/* 6260A8 8021A508 03E00008 */  jr        $ra
/* 6260AC 8021A50C 27BD0030 */   addiu    $sp, $sp, 0x30
