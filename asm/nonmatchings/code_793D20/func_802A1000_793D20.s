.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_793D20
/* 793D20 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 793D24 802A1004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 793D28 802A1008 0080882D */  daddu     $s1, $a0, $zero
/* 793D2C 802A100C AFBF0024 */  sw        $ra, 0x24($sp)
/* 793D30 802A1010 AFB20020 */  sw        $s2, 0x20($sp)
/* 793D34 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 793D38 802A1018 8E30000C */  lw        $s0, 0xc($s1)
/* 793D3C 802A101C 8E050000 */  lw        $a1, ($s0)
/* 793D40 802A1020 0C0B1EAF */  jal       get_variable
/* 793D44 802A1024 26100004 */   addiu    $s0, $s0, 4
/* 793D48 802A1028 8E050000 */  lw        $a1, ($s0)
/* 793D4C 802A102C 26100004 */  addiu     $s0, $s0, 4
/* 793D50 802A1030 0220202D */  daddu     $a0, $s1, $zero
/* 793D54 802A1034 0C0B1EAF */  jal       get_variable
/* 793D58 802A1038 0040902D */   daddu    $s2, $v0, $zero
/* 793D5C 802A103C 0220202D */  daddu     $a0, $s1, $zero
/* 793D60 802A1040 8E050000 */  lw        $a1, ($s0)
/* 793D64 802A1044 0C0B1EAF */  jal       get_variable
/* 793D68 802A1048 0040802D */   daddu    $s0, $v0, $zero
/* 793D6C 802A104C 44921000 */  mtc1      $s2, $f2
/* 793D70 802A1050 00000000 */  nop       
/* 793D74 802A1054 468010A0 */  cvt.s.w   $f2, $f2
/* 793D78 802A1058 44051000 */  mfc1      $a1, $f2
/* 793D7C 802A105C 44901000 */  mtc1      $s0, $f2
/* 793D80 802A1060 00000000 */  nop       
/* 793D84 802A1064 468010A0 */  cvt.s.w   $f2, $f2
/* 793D88 802A1068 44061000 */  mfc1      $a2, $f2
/* 793D8C 802A106C 44821000 */  mtc1      $v0, $f2
/* 793D90 802A1070 00000000 */  nop       
/* 793D94 802A1074 468010A0 */  cvt.s.w   $f2, $f2
/* 793D98 802A1078 3C014220 */  lui       $at, 0x4220
/* 793D9C 802A107C 44810000 */  mtc1      $at, $f0
/* 793DA0 802A1080 44071000 */  mfc1      $a3, $f2
/* 793DA4 802A1084 0000202D */  daddu     $a0, $zero, $zero
/* 793DA8 802A1088 0C01BFBC */  jal       func_8006FEF0
/* 793DAC 802A108C E7A00010 */   swc1     $f0, 0x10($sp)
/* 793DB0 802A1090 8FBF0024 */  lw        $ra, 0x24($sp)
/* 793DB4 802A1094 8FB20020 */  lw        $s2, 0x20($sp)
/* 793DB8 802A1098 8FB1001C */  lw        $s1, 0x1c($sp)
/* 793DBC 802A109C 8FB00018 */  lw        $s0, 0x18($sp)
/* 793DC0 802A10A0 24020002 */  addiu     $v0, $zero, 2
/* 793DC4 802A10A4 03E00008 */  jr        $ra
/* 793DC8 802A10A8 27BD0028 */   addiu    $sp, $sp, 0x28
