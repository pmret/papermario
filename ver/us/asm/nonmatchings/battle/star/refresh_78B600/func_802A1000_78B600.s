.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_78B600
/* 78B600 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 78B604 802A1004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 78B608 802A1008 0080882D */  daddu     $s1, $a0, $zero
/* 78B60C 802A100C AFBF0024 */  sw        $ra, 0x24($sp)
/* 78B610 802A1010 AFB20020 */  sw        $s2, 0x20($sp)
/* 78B614 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 78B618 802A1018 8E30000C */  lw        $s0, 0xc($s1)
/* 78B61C 802A101C 8E050000 */  lw        $a1, ($s0)
/* 78B620 802A1020 0C0B1EAF */  jal       get_variable
/* 78B624 802A1024 26100004 */   addiu    $s0, $s0, 4
/* 78B628 802A1028 8E050000 */  lw        $a1, ($s0)
/* 78B62C 802A102C 26100004 */  addiu     $s0, $s0, 4
/* 78B630 802A1030 0220202D */  daddu     $a0, $s1, $zero
/* 78B634 802A1034 0C0B1EAF */  jal       get_variable
/* 78B638 802A1038 0040902D */   daddu    $s2, $v0, $zero
/* 78B63C 802A103C 0220202D */  daddu     $a0, $s1, $zero
/* 78B640 802A1040 8E050000 */  lw        $a1, ($s0)
/* 78B644 802A1044 0C0B1EAF */  jal       get_variable
/* 78B648 802A1048 0040802D */   daddu    $s0, $v0, $zero
/* 78B64C 802A104C 44921000 */  mtc1      $s2, $f2
/* 78B650 802A1050 00000000 */  nop
/* 78B654 802A1054 468010A0 */  cvt.s.w   $f2, $f2
/* 78B658 802A1058 44051000 */  mfc1      $a1, $f2
/* 78B65C 802A105C 44901000 */  mtc1      $s0, $f2
/* 78B660 802A1060 00000000 */  nop
/* 78B664 802A1064 468010A0 */  cvt.s.w   $f2, $f2
/* 78B668 802A1068 44061000 */  mfc1      $a2, $f2
/* 78B66C 802A106C 44821000 */  mtc1      $v0, $f2
/* 78B670 802A1070 00000000 */  nop
/* 78B674 802A1074 468010A0 */  cvt.s.w   $f2, $f2
/* 78B678 802A1078 3C014220 */  lui       $at, 0x4220
/* 78B67C 802A107C 44810000 */  mtc1      $at, $f0
/* 78B680 802A1080 44071000 */  mfc1      $a3, $f2
/* 78B684 802A1084 0000202D */  daddu     $a0, $zero, $zero
/* 78B688 802A1088 0C01BFBC */  jal       func_8006FEF0
/* 78B68C 802A108C E7A00010 */   swc1     $f0, 0x10($sp)
/* 78B690 802A1090 8FBF0024 */  lw        $ra, 0x24($sp)
/* 78B694 802A1094 8FB20020 */  lw        $s2, 0x20($sp)
/* 78B698 802A1098 8FB1001C */  lw        $s1, 0x1c($sp)
/* 78B69C 802A109C 8FB00018 */  lw        $s0, 0x18($sp)
/* 78B6A0 802A10A0 24020002 */  addiu     $v0, $zero, 2
/* 78B6A4 802A10A4 03E00008 */  jr        $ra
/* 78B6A8 802A10A8 27BD0028 */   addiu    $sp, $sp, 0x28
