.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA0_9943D0
/* 9943D0 80241CA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9943D4 80241CA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9943D8 80241CA8 0080882D */  daddu     $s1, $a0, $zero
/* 9943DC 80241CAC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9943E0 80241CB0 AFB20018 */  sw        $s2, 0x18($sp)
/* 9943E4 80241CB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9943E8 80241CB8 8E30000C */  lw        $s0, 0xc($s1)
/* 9943EC 80241CBC 8E050000 */  lw        $a1, ($s0)
/* 9943F0 80241CC0 0C0B210B */  jal       get_float_variable
/* 9943F4 80241CC4 26100004 */   addiu    $s0, $s0, 4
/* 9943F8 80241CC8 8E050000 */  lw        $a1, ($s0)
/* 9943FC 80241CCC 26100004 */  addiu     $s0, $s0, 4
/* 994400 80241CD0 4600010D */  trunc.w.s $f4, $f0
/* 994404 80241CD4 44122000 */  mfc1      $s2, $f4
/* 994408 80241CD8 0C0B210B */  jal       get_float_variable
/* 99440C 80241CDC 0220202D */   daddu    $a0, $s1, $zero
/* 994410 80241CE0 8E050000 */  lw        $a1, ($s0)
/* 994414 80241CE4 4600010D */  trunc.w.s $f4, $f0
/* 994418 80241CE8 44102000 */  mfc1      $s0, $f4
/* 99441C 80241CEC 0C0B210B */  jal       get_float_variable
/* 994420 80241CF0 0220202D */   daddu    $a0, $s1, $zero
/* 994424 80241CF4 3C038024 */  lui       $v1, %hi(mim_06_UnkDurationCheck)
/* 994428 80241CF8 24632AC0 */  addiu     $v1, $v1, %lo(mim_06_UnkDurationCheck)
/* 99442C 80241CFC 44921000 */  mtc1      $s2, $f2
/* 994430 80241D00 00000000 */  nop
/* 994434 80241D04 468010A0 */  cvt.s.w   $f2, $f2
/* 994438 80241D08 E462001C */  swc1      $f2, 0x1c($v1)
/* 99443C 80241D0C 44901000 */  mtc1      $s0, $f2
/* 994440 80241D10 00000000 */  nop
/* 994444 80241D14 468010A0 */  cvt.s.w   $f2, $f2
/* 994448 80241D18 4600010D */  trunc.w.s $f4, $f0
/* 99444C 80241D1C 44022000 */  mfc1      $v0, $f4
/* 994450 80241D20 00000000 */  nop
/* 994454 80241D24 44820000 */  mtc1      $v0, $f0
/* 994458 80241D28 00000000 */  nop
/* 99445C 80241D2C 46800020 */  cvt.s.w   $f0, $f0
/* 994460 80241D30 E4620020 */  swc1      $f2, 0x20($v1)
/* 994464 80241D34 E4600024 */  swc1      $f0, 0x24($v1)
/* 994468 80241D38 8FBF001C */  lw        $ra, 0x1c($sp)
/* 99446C 80241D3C 8FB20018 */  lw        $s2, 0x18($sp)
/* 994470 80241D40 8FB10014 */  lw        $s1, 0x14($sp)
/* 994474 80241D44 8FB00010 */  lw        $s0, 0x10($sp)
/* 994478 80241D48 24020002 */  addiu     $v0, $zero, 2
/* 99447C 80241D4C 03E00008 */  jr        $ra
/* 994480 80241D50 27BD0020 */   addiu    $sp, $sp, 0x20
/* 994484 80241D54 00000000 */  nop
/* 994488 80241D58 00000000 */  nop
/* 99448C 80241D5C 00000000 */  nop
