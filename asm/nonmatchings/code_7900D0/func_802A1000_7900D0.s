.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_7900D0
/* 7900D0 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7900D4 802A1004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7900D8 802A1008 0080882D */  daddu     $s1, $a0, $zero
/* 7900DC 802A100C AFBF0024 */  sw        $ra, 0x24($sp)
/* 7900E0 802A1010 AFB20020 */  sw        $s2, 0x20($sp)
/* 7900E4 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 7900E8 802A1018 8E30000C */  lw        $s0, 0xc($s1)
/* 7900EC 802A101C 8E050000 */  lw        $a1, ($s0)
/* 7900F0 802A1020 0C0B1EAF */  jal       get_variable
/* 7900F4 802A1024 26100004 */   addiu    $s0, $s0, 4
/* 7900F8 802A1028 8E050000 */  lw        $a1, ($s0)
/* 7900FC 802A102C 26100004 */  addiu     $s0, $s0, 4
/* 790100 802A1030 0220202D */  daddu     $a0, $s1, $zero
/* 790104 802A1034 0C0B1EAF */  jal       get_variable
/* 790108 802A1038 0040902D */   daddu    $s2, $v0, $zero
/* 79010C 802A103C 0220202D */  daddu     $a0, $s1, $zero
/* 790110 802A1040 8E050000 */  lw        $a1, ($s0)
/* 790114 802A1044 0C0B1EAF */  jal       get_variable
/* 790118 802A1048 0040802D */   daddu    $s0, $v0, $zero
/* 79011C 802A104C 44921000 */  mtc1      $s2, $f2
/* 790120 802A1050 00000000 */  nop
/* 790124 802A1054 468010A0 */  cvt.s.w   $f2, $f2
/* 790128 802A1058 44051000 */  mfc1      $a1, $f2
/* 79012C 802A105C 44901000 */  mtc1      $s0, $f2
/* 790130 802A1060 00000000 */  nop
/* 790134 802A1064 468010A0 */  cvt.s.w   $f2, $f2
/* 790138 802A1068 44061000 */  mfc1      $a2, $f2
/* 79013C 802A106C 44821000 */  mtc1      $v0, $f2
/* 790140 802A1070 00000000 */  nop
/* 790144 802A1074 468010A0 */  cvt.s.w   $f2, $f2
/* 790148 802A1078 3C014220 */  lui       $at, 0x4220
/* 79014C 802A107C 44810000 */  mtc1      $at, $f0
/* 790150 802A1080 44071000 */  mfc1      $a3, $f2
/* 790154 802A1084 0000202D */  daddu     $a0, $zero, $zero
/* 790158 802A1088 0C01BFBC */  jal       func_8006FEF0
/* 79015C 802A108C E7A00010 */   swc1     $f0, 0x10($sp)
/* 790160 802A1090 8FBF0024 */  lw        $ra, 0x24($sp)
/* 790164 802A1094 8FB20020 */  lw        $s2, 0x20($sp)
/* 790168 802A1098 8FB1001C */  lw        $s1, 0x1c($sp)
/* 79016C 802A109C 8FB00018 */  lw        $s0, 0x18($sp)
/* 790170 802A10A0 24020002 */  addiu     $v0, $zero, 2
/* 790174 802A10A4 03E00008 */  jr        $ra
/* 790178 802A10A8 27BD0028 */   addiu    $sp, $sp, 0x28
