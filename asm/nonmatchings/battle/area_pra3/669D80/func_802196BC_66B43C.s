.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802196BC_66B43C
/* 66B43C 802196BC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66B440 802196C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B444 802196C4 0080882D */  daddu     $s1, $a0, $zero
/* 66B448 802196C8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 66B44C 802196CC AFB3001C */  sw        $s3, 0x1c($sp)
/* 66B450 802196D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 66B454 802196D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B458 802196D8 8E30000C */  lw        $s0, 0xc($s1)
/* 66B45C 802196DC 8E050000 */  lw        $a1, ($s0)
/* 66B460 802196E0 0C0B1EAF */  jal       get_variable
/* 66B464 802196E4 26100004 */   addiu    $s0, $s0, 4
/* 66B468 802196E8 8E050000 */  lw        $a1, ($s0)
/* 66B46C 802196EC 26100004 */  addiu     $s0, $s0, 4
/* 66B470 802196F0 0220202D */  daddu     $a0, $s1, $zero
/* 66B474 802196F4 0C0B1EAF */  jal       get_variable
/* 66B478 802196F8 0040982D */   daddu    $s3, $v0, $zero
/* 66B47C 802196FC 8E050000 */  lw        $a1, ($s0)
/* 66B480 80219700 26100004 */  addiu     $s0, $s0, 4
/* 66B484 80219704 0220202D */  daddu     $a0, $s1, $zero
/* 66B488 80219708 0C0B1EAF */  jal       get_variable
/* 66B48C 8021970C 0040902D */   daddu    $s2, $v0, $zero
/* 66B490 80219710 0220202D */  daddu     $a0, $s1, $zero
/* 66B494 80219714 8E050000 */  lw        $a1, ($s0)
/* 66B498 80219718 0C0B1EAF */  jal       get_variable
/* 66B49C 8021971C 0040802D */   daddu    $s0, $v0, $zero
/* 66B4A0 80219720 44936000 */  mtc1      $s3, $f12
/* 66B4A4 80219724 00000000 */  nop       
/* 66B4A8 80219728 46806320 */  cvt.s.w   $f12, $f12
/* 66B4AC 8021972C 44927000 */  mtc1      $s2, $f14
/* 66B4B0 80219730 00000000 */  nop       
/* 66B4B4 80219734 468073A0 */  cvt.s.w   $f14, $f14
/* 66B4B8 80219738 44900000 */  mtc1      $s0, $f0
/* 66B4BC 8021973C 00000000 */  nop       
/* 66B4C0 80219740 46800020 */  cvt.s.w   $f0, $f0
/* 66B4C4 80219744 44060000 */  mfc1      $a2, $f0
/* 66B4C8 80219748 0C0B5D18 */  jal       func_802D7460
/* 66B4CC 8021974C 0040382D */   daddu    $a3, $v0, $zero
/* 66B4D0 80219750 8FBF0020 */  lw        $ra, 0x20($sp)
/* 66B4D4 80219754 8FB3001C */  lw        $s3, 0x1c($sp)
/* 66B4D8 80219758 8FB20018 */  lw        $s2, 0x18($sp)
/* 66B4DC 8021975C 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B4E0 80219760 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B4E4 80219764 24020002 */  addiu     $v0, $zero, 2
/* 66B4E8 80219768 03E00008 */  jr        $ra
/* 66B4EC 8021976C 27BD0028 */   addiu    $sp, $sp, 0x28
