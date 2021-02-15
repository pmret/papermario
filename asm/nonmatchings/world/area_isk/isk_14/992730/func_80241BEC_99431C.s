.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BEC_99431C
/* 99431C 80241BEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 994320 80241BF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 994324 80241BF4 0080882D */  daddu     $s1, $a0, $zero
/* 994328 80241BF8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 99432C 80241BFC AFB20018 */  sw        $s2, 0x18($sp)
/* 994330 80241C00 AFB00010 */  sw        $s0, 0x10($sp)
/* 994334 80241C04 8E30000C */  lw        $s0, 0xc($s1)
/* 994338 80241C08 8E050000 */  lw        $a1, ($s0)
/* 99433C 80241C0C 0C0B210B */  jal       get_float_variable
/* 994340 80241C10 26100004 */   addiu    $s0, $s0, 4
/* 994344 80241C14 8E050000 */  lw        $a1, ($s0)
/* 994348 80241C18 26100004 */  addiu     $s0, $s0, 4
/* 99434C 80241C1C 4600010D */  trunc.w.s $f4, $f0
/* 994350 80241C20 44122000 */  mfc1      $s2, $f4
/* 994354 80241C24 0C0B210B */  jal       get_float_variable
/* 994358 80241C28 0220202D */   daddu    $a0, $s1, $zero
/* 99435C 80241C2C 8E050000 */  lw        $a1, ($s0)
/* 994360 80241C30 4600010D */  trunc.w.s $f4, $f0
/* 994364 80241C34 44102000 */  mfc1      $s0, $f4
/* 994368 80241C38 0C0B210B */  jal       get_float_variable
/* 99436C 80241C3C 0220202D */   daddu    $a0, $s1, $zero
/* 994370 80241C40 3C038024 */  lui       $v1, %hi(mim_06_UnkDurationCheck)
/* 994374 80241C44 24632AC0 */  addiu     $v1, $v1, %lo(mim_06_UnkDurationCheck)
/* 994378 80241C48 44921000 */  mtc1      $s2, $f2
/* 99437C 80241C4C 00000000 */  nop
/* 994380 80241C50 468010A0 */  cvt.s.w   $f2, $f2
/* 994384 80241C54 E4620010 */  swc1      $f2, 0x10($v1)
/* 994388 80241C58 44901000 */  mtc1      $s0, $f2
/* 99438C 80241C5C 00000000 */  nop
/* 994390 80241C60 468010A0 */  cvt.s.w   $f2, $f2
/* 994394 80241C64 4600010D */  trunc.w.s $f4, $f0
/* 994398 80241C68 44022000 */  mfc1      $v0, $f4
/* 99439C 80241C6C 00000000 */  nop
/* 9943A0 80241C70 44820000 */  mtc1      $v0, $f0
/* 9943A4 80241C74 00000000 */  nop
/* 9943A8 80241C78 46800020 */  cvt.s.w   $f0, $f0
/* 9943AC 80241C7C E4620014 */  swc1      $f2, 0x14($v1)
/* 9943B0 80241C80 E4600018 */  swc1      $f0, 0x18($v1)
/* 9943B4 80241C84 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9943B8 80241C88 8FB20018 */  lw        $s2, 0x18($sp)
/* 9943BC 80241C8C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9943C0 80241C90 8FB00010 */  lw        $s0, 0x10($sp)
/* 9943C4 80241C94 24020002 */  addiu     $v0, $zero, 2
/* 9943C8 80241C98 03E00008 */  jr        $ra
/* 9943CC 80241C9C 27BD0020 */   addiu    $sp, $sp, 0x20
