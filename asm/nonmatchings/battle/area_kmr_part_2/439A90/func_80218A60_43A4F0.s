.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A60_43A4F0
/* 43A4F0 80218A60 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 43A4F4 80218A64 AFB1001C */  sw        $s1, 0x1c($sp)
/* 43A4F8 80218A68 0080882D */  daddu     $s1, $a0, $zero
/* 43A4FC 80218A6C AFBF0024 */  sw        $ra, 0x24($sp)
/* 43A500 80218A70 AFB20020 */  sw        $s2, 0x20($sp)
/* 43A504 80218A74 AFB00018 */  sw        $s0, 0x18($sp)
/* 43A508 80218A78 8E30000C */  lw        $s0, 0xc($s1)
/* 43A50C 80218A7C 8E050000 */  lw        $a1, ($s0)
/* 43A510 80218A80 0C0B1EAF */  jal       get_variable
/* 43A514 80218A84 26100004 */   addiu    $s0, $s0, 4
/* 43A518 80218A88 8E050000 */  lw        $a1, ($s0)
/* 43A51C 80218A8C 26100004 */  addiu     $s0, $s0, 4
/* 43A520 80218A90 0220202D */  daddu     $a0, $s1, $zero
/* 43A524 80218A94 0C0B1EAF */  jal       get_variable
/* 43A528 80218A98 0040902D */   daddu    $s2, $v0, $zero
/* 43A52C 80218A9C 0220202D */  daddu     $a0, $s1, $zero
/* 43A530 80218AA0 8E050000 */  lw        $a1, ($s0)
/* 43A534 80218AA4 0C0B1EAF */  jal       get_variable
/* 43A538 80218AA8 0040802D */   daddu    $s0, $v0, $zero
/* 43A53C 80218AAC 44920000 */  mtc1      $s2, $f0
/* 43A540 80218AB0 00000000 */  nop       
/* 43A544 80218AB4 46800020 */  cvt.s.w   $f0, $f0
/* 43A548 80218AB8 44050000 */  mfc1      $a1, $f0
/* 43A54C 80218ABC 44900000 */  mtc1      $s0, $f0
/* 43A550 80218AC0 00000000 */  nop       
/* 43A554 80218AC4 46800020 */  cvt.s.w   $f0, $f0
/* 43A558 80218AC8 44060000 */  mfc1      $a2, $f0
/* 43A55C 80218ACC 44820000 */  mtc1      $v0, $f0
/* 43A560 80218AD0 00000000 */  nop       
/* 43A564 80218AD4 46800020 */  cvt.s.w   $f0, $f0
/* 43A568 80218AD8 44070000 */  mfc1      $a3, $f0
/* 43A56C 80218ADC 24040002 */  addiu     $a0, $zero, 2
/* 43A570 80218AE0 0C01BEB4 */  jal       fx_walk_large
/* 43A574 80218AE4 AFA00010 */   sw       $zero, 0x10($sp)
/* 43A578 80218AE8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 43A57C 80218AEC 8FB20020 */  lw        $s2, 0x20($sp)
/* 43A580 80218AF0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 43A584 80218AF4 8FB00018 */  lw        $s0, 0x18($sp)
/* 43A588 80218AF8 24020002 */  addiu     $v0, $zero, 2
/* 43A58C 80218AFC 03E00008 */  jr        $ra
/* 43A590 80218B00 27BD0028 */   addiu    $sp, $sp, 0x28
/* 43A594 80218B04 00000000 */  nop       
/* 43A598 80218B08 00000000 */  nop       
/* 43A59C 80218B0C 00000000 */  nop       
