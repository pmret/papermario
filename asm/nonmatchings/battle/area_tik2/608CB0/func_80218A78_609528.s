.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A78_609528
/* 609528 80218A78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 60952C 80218A7C AFB10014 */  sw        $s1, 0x14($sp)
/* 609530 80218A80 0080882D */  daddu     $s1, $a0, $zero
/* 609534 80218A84 AFBF0020 */  sw        $ra, 0x20($sp)
/* 609538 80218A88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 60953C 80218A8C AFB20018 */  sw        $s2, 0x18($sp)
/* 609540 80218A90 AFB00010 */  sw        $s0, 0x10($sp)
/* 609544 80218A94 8E30000C */  lw        $s0, 0xc($s1)
/* 609548 80218A98 8E050000 */  lw        $a1, ($s0)
/* 60954C 80218A9C 0C0B1EAF */  jal       get_variable
/* 609550 80218AA0 26100004 */   addiu    $s0, $s0, 4
/* 609554 80218AA4 8E050000 */  lw        $a1, ($s0)
/* 609558 80218AA8 26100004 */  addiu     $s0, $s0, 4
/* 60955C 80218AAC 0220202D */  daddu     $a0, $s1, $zero
/* 609560 80218AB0 0C0B1EAF */  jal       get_variable
/* 609564 80218AB4 0040982D */   daddu    $s3, $v0, $zero
/* 609568 80218AB8 8E050000 */  lw        $a1, ($s0)
/* 60956C 80218ABC 26100004 */  addiu     $s0, $s0, 4
/* 609570 80218AC0 0220202D */  daddu     $a0, $s1, $zero
/* 609574 80218AC4 0C0B1EAF */  jal       get_variable
/* 609578 80218AC8 0040902D */   daddu    $s2, $v0, $zero
/* 60957C 80218ACC 0220202D */  daddu     $a0, $s1, $zero
/* 609580 80218AD0 8E050000 */  lw        $a1, ($s0)
/* 609584 80218AD4 0C0B1EAF */  jal       get_variable
/* 609588 80218AD8 0040802D */   daddu    $s0, $v0, $zero
/* 60958C 80218ADC 44936000 */  mtc1      $s3, $f12
/* 609590 80218AE0 00000000 */  nop       
/* 609594 80218AE4 46806320 */  cvt.s.w   $f12, $f12
/* 609598 80218AE8 44927000 */  mtc1      $s2, $f14
/* 60959C 80218AEC 00000000 */  nop       
/* 6095A0 80218AF0 468073A0 */  cvt.s.w   $f14, $f14
/* 6095A4 80218AF4 44900000 */  mtc1      $s0, $f0
/* 6095A8 80218AF8 00000000 */  nop       
/* 6095AC 80218AFC 46800020 */  cvt.s.w   $f0, $f0
/* 6095B0 80218B00 44060000 */  mfc1      $a2, $f0
/* 6095B4 80218B04 0C0B5D18 */  jal       func_802D7460
/* 6095B8 80218B08 0040382D */   daddu    $a3, $v0, $zero
/* 6095BC 80218B0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6095C0 80218B10 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6095C4 80218B14 8FB20018 */  lw        $s2, 0x18($sp)
/* 6095C8 80218B18 8FB10014 */  lw        $s1, 0x14($sp)
/* 6095CC 80218B1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6095D0 80218B20 24020002 */  addiu     $v0, $zero, 2
/* 6095D4 80218B24 03E00008 */  jr        $ra
/* 6095D8 80218B28 27BD0028 */   addiu    $sp, $sp, 0x28
