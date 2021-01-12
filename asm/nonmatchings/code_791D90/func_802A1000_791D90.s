.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_791D90
/* 791D90 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 791D94 802A1004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 791D98 802A1008 0080882D */  daddu     $s1, $a0, $zero
/* 791D9C 802A100C AFBF0024 */  sw        $ra, 0x24($sp)
/* 791DA0 802A1010 AFB20020 */  sw        $s2, 0x20($sp)
/* 791DA4 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 791DA8 802A1018 8E30000C */  lw        $s0, 0xc($s1)
/* 791DAC 802A101C 8E050000 */  lw        $a1, ($s0)
/* 791DB0 802A1020 0C0B1EAF */  jal       get_variable
/* 791DB4 802A1024 26100004 */   addiu    $s0, $s0, 4
/* 791DB8 802A1028 8E050000 */  lw        $a1, ($s0)
/* 791DBC 802A102C 26100004 */  addiu     $s0, $s0, 4
/* 791DC0 802A1030 0220202D */  daddu     $a0, $s1, $zero
/* 791DC4 802A1034 0C0B1EAF */  jal       get_variable
/* 791DC8 802A1038 0040902D */   daddu    $s2, $v0, $zero
/* 791DCC 802A103C 0220202D */  daddu     $a0, $s1, $zero
/* 791DD0 802A1040 8E050000 */  lw        $a1, ($s0)
/* 791DD4 802A1044 0C0B1EAF */  jal       get_variable
/* 791DD8 802A1048 0040802D */   daddu    $s0, $v0, $zero
/* 791DDC 802A104C 44921000 */  mtc1      $s2, $f2
/* 791DE0 802A1050 00000000 */  nop
/* 791DE4 802A1054 468010A0 */  cvt.s.w   $f2, $f2
/* 791DE8 802A1058 44051000 */  mfc1      $a1, $f2
/* 791DEC 802A105C 44901000 */  mtc1      $s0, $f2
/* 791DF0 802A1060 00000000 */  nop
/* 791DF4 802A1064 468010A0 */  cvt.s.w   $f2, $f2
/* 791DF8 802A1068 44061000 */  mfc1      $a2, $f2
/* 791DFC 802A106C 44821000 */  mtc1      $v0, $f2
/* 791E00 802A1070 00000000 */  nop
/* 791E04 802A1074 468010A0 */  cvt.s.w   $f2, $f2
/* 791E08 802A1078 3C014220 */  lui       $at, 0x4220
/* 791E0C 802A107C 44810000 */  mtc1      $at, $f0
/* 791E10 802A1080 44071000 */  mfc1      $a3, $f2
/* 791E14 802A1084 0000202D */  daddu     $a0, $zero, $zero
/* 791E18 802A1088 0C01BFBC */  jal       func_8006FEF0
/* 791E1C 802A108C E7A00010 */   swc1     $f0, 0x10($sp)
/* 791E20 802A1090 8FBF0024 */  lw        $ra, 0x24($sp)
/* 791E24 802A1094 8FB20020 */  lw        $s2, 0x20($sp)
/* 791E28 802A1098 8FB1001C */  lw        $s1, 0x1c($sp)
/* 791E2C 802A109C 8FB00018 */  lw        $s0, 0x18($sp)
/* 791E30 802A10A0 24020002 */  addiu     $v0, $zero, 2
/* 791E34 802A10A4 03E00008 */  jr        $ra
/* 791E38 802A10A8 27BD0028 */   addiu    $sp, $sp, 0x28
