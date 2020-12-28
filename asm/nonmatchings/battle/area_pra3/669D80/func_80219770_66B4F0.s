.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219770_66B4F0
/* 66B4F0 80219770 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66B4F4 80219774 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B4F8 80219778 0080882D */  daddu     $s1, $a0, $zero
/* 66B4FC 8021977C AFBF0020 */  sw        $ra, 0x20($sp)
/* 66B500 80219780 AFB3001C */  sw        $s3, 0x1c($sp)
/* 66B504 80219784 AFB20018 */  sw        $s2, 0x18($sp)
/* 66B508 80219788 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B50C 8021978C 8E30000C */  lw        $s0, 0xc($s1)
/* 66B510 80219790 8E050000 */  lw        $a1, ($s0)
/* 66B514 80219794 0C0B1EAF */  jal       get_variable
/* 66B518 80219798 26100004 */   addiu    $s0, $s0, 4
/* 66B51C 8021979C 8E050000 */  lw        $a1, ($s0)
/* 66B520 802197A0 26100004 */  addiu     $s0, $s0, 4
/* 66B524 802197A4 0220202D */  daddu     $a0, $s1, $zero
/* 66B528 802197A8 0C0B1EAF */  jal       get_variable
/* 66B52C 802197AC 0040982D */   daddu    $s3, $v0, $zero
/* 66B530 802197B0 8E050000 */  lw        $a1, ($s0)
/* 66B534 802197B4 26100004 */  addiu     $s0, $s0, 4
/* 66B538 802197B8 0220202D */  daddu     $a0, $s1, $zero
/* 66B53C 802197BC 0C0B1EAF */  jal       get_variable
/* 66B540 802197C0 0040902D */   daddu    $s2, $v0, $zero
/* 66B544 802197C4 0220202D */  daddu     $a0, $s1, $zero
/* 66B548 802197C8 8E050000 */  lw        $a1, ($s0)
/* 66B54C 802197CC 0C0B1EAF */  jal       get_variable
/* 66B550 802197D0 0040802D */   daddu    $s0, $v0, $zero
/* 66B554 802197D4 44936000 */  mtc1      $s3, $f12
/* 66B558 802197D8 00000000 */  nop       
/* 66B55C 802197DC 46806320 */  cvt.s.w   $f12, $f12
/* 66B560 802197E0 44927000 */  mtc1      $s2, $f14
/* 66B564 802197E4 00000000 */  nop       
/* 66B568 802197E8 468073A0 */  cvt.s.w   $f14, $f14
/* 66B56C 802197EC 44900000 */  mtc1      $s0, $f0
/* 66B570 802197F0 00000000 */  nop       
/* 66B574 802197F4 46800020 */  cvt.s.w   $f0, $f0
/* 66B578 802197F8 44060000 */  mfc1      $a2, $f0
/* 66B57C 802197FC 0C0B5D30 */  jal       func_802D74C0
/* 66B580 80219800 0040382D */   daddu    $a3, $v0, $zero
/* 66B584 80219804 8FBF0020 */  lw        $ra, 0x20($sp)
/* 66B588 80219808 8FB3001C */  lw        $s3, 0x1c($sp)
/* 66B58C 8021980C 8FB20018 */  lw        $s2, 0x18($sp)
/* 66B590 80219810 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B594 80219814 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B598 80219818 24020002 */  addiu     $v0, $zero, 2
/* 66B59C 8021981C 03E00008 */  jr        $ra
/* 66B5A0 80219820 27BD0028 */   addiu    $sp, $sp, 0x28
/* 66B5A4 80219824 00000000 */  nop       
/* 66B5A8 80219828 00000000 */  nop       
/* 66B5AC 8021982C 00000000 */  nop       
