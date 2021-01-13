.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_789E60
/* 789E60 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 789E64 802A1004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 789E68 802A1008 0080882D */  daddu     $s1, $a0, $zero
/* 789E6C 802A100C AFBF0024 */  sw        $ra, 0x24($sp)
/* 789E70 802A1010 AFB20020 */  sw        $s2, 0x20($sp)
/* 789E74 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 789E78 802A1018 8E30000C */  lw        $s0, 0xc($s1)
/* 789E7C 802A101C 8E050000 */  lw        $a1, ($s0)
/* 789E80 802A1020 0C0B1EAF */  jal       get_variable
/* 789E84 802A1024 26100004 */   addiu    $s0, $s0, 4
/* 789E88 802A1028 8E050000 */  lw        $a1, ($s0)
/* 789E8C 802A102C 26100004 */  addiu     $s0, $s0, 4
/* 789E90 802A1030 0220202D */  daddu     $a0, $s1, $zero
/* 789E94 802A1034 0C0B1EAF */  jal       get_variable
/* 789E98 802A1038 0040902D */   daddu    $s2, $v0, $zero
/* 789E9C 802A103C 0220202D */  daddu     $a0, $s1, $zero
/* 789EA0 802A1040 8E050000 */  lw        $a1, ($s0)
/* 789EA4 802A1044 0C0B1EAF */  jal       get_variable
/* 789EA8 802A1048 0040802D */   daddu    $s0, $v0, $zero
/* 789EAC 802A104C 44921000 */  mtc1      $s2, $f2
/* 789EB0 802A1050 00000000 */  nop
/* 789EB4 802A1054 468010A0 */  cvt.s.w   $f2, $f2
/* 789EB8 802A1058 44051000 */  mfc1      $a1, $f2
/* 789EBC 802A105C 44901000 */  mtc1      $s0, $f2
/* 789EC0 802A1060 00000000 */  nop
/* 789EC4 802A1064 468010A0 */  cvt.s.w   $f2, $f2
/* 789EC8 802A1068 44061000 */  mfc1      $a2, $f2
/* 789ECC 802A106C 44821000 */  mtc1      $v0, $f2
/* 789ED0 802A1070 00000000 */  nop
/* 789ED4 802A1074 468010A0 */  cvt.s.w   $f2, $f2
/* 789ED8 802A1078 3C014220 */  lui       $at, 0x4220
/* 789EDC 802A107C 44810000 */  mtc1      $at, $f0
/* 789EE0 802A1080 44071000 */  mfc1      $a3, $f2
/* 789EE4 802A1084 0000202D */  daddu     $a0, $zero, $zero
/* 789EE8 802A1088 0C01BFBC */  jal       func_8006FEF0
/* 789EEC 802A108C E7A00010 */   swc1     $f0, 0x10($sp)
/* 789EF0 802A1090 8FBF0024 */  lw        $ra, 0x24($sp)
/* 789EF4 802A1094 8FB20020 */  lw        $s2, 0x20($sp)
/* 789EF8 802A1098 8FB1001C */  lw        $s1, 0x1c($sp)
/* 789EFC 802A109C 8FB00018 */  lw        $s0, 0x18($sp)
/* 789F00 802A10A0 24020002 */  addiu     $v0, $zero, 2
/* 789F04 802A10A4 03E00008 */  jr        $ra
/* 789F08 802A10A8 27BD0028 */   addiu    $sp, $sp, 0x28
