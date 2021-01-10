.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_79BFA0
/* 79BFA0 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 79BFA4 802A1004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 79BFA8 802A1008 0080882D */  daddu     $s1, $a0, $zero
/* 79BFAC 802A100C AFBF0024 */  sw        $ra, 0x24($sp)
/* 79BFB0 802A1010 AFB20020 */  sw        $s2, 0x20($sp)
/* 79BFB4 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 79BFB8 802A1018 8E30000C */  lw        $s0, 0xc($s1)
/* 79BFBC 802A101C 8E050000 */  lw        $a1, ($s0)
/* 79BFC0 802A1020 0C0B1EAF */  jal       get_variable
/* 79BFC4 802A1024 26100004 */   addiu    $s0, $s0, 4
/* 79BFC8 802A1028 8E050000 */  lw        $a1, ($s0)
/* 79BFCC 802A102C 26100004 */  addiu     $s0, $s0, 4
/* 79BFD0 802A1030 0220202D */  daddu     $a0, $s1, $zero
/* 79BFD4 802A1034 0C0B1EAF */  jal       get_variable
/* 79BFD8 802A1038 0040902D */   daddu    $s2, $v0, $zero
/* 79BFDC 802A103C 0220202D */  daddu     $a0, $s1, $zero
/* 79BFE0 802A1040 8E050000 */  lw        $a1, ($s0)
/* 79BFE4 802A1044 0C0B1EAF */  jal       get_variable
/* 79BFE8 802A1048 0040802D */   daddu    $s0, $v0, $zero
/* 79BFEC 802A104C 44921000 */  mtc1      $s2, $f2
/* 79BFF0 802A1050 00000000 */  nop       
/* 79BFF4 802A1054 468010A0 */  cvt.s.w   $f2, $f2
/* 79BFF8 802A1058 44051000 */  mfc1      $a1, $f2
/* 79BFFC 802A105C 44901000 */  mtc1      $s0, $f2
/* 79C000 802A1060 00000000 */  nop       
/* 79C004 802A1064 468010A0 */  cvt.s.w   $f2, $f2
/* 79C008 802A1068 44061000 */  mfc1      $a2, $f2
/* 79C00C 802A106C 44821000 */  mtc1      $v0, $f2
/* 79C010 802A1070 00000000 */  nop       
/* 79C014 802A1074 468010A0 */  cvt.s.w   $f2, $f2
/* 79C018 802A1078 3C014220 */  lui       $at, 0x4220
/* 79C01C 802A107C 44810000 */  mtc1      $at, $f0
/* 79C020 802A1080 44071000 */  mfc1      $a3, $f2
/* 79C024 802A1084 0000202D */  daddu     $a0, $zero, $zero
/* 79C028 802A1088 0C01BFBC */  jal       func_8006FEF0
/* 79C02C 802A108C E7A00010 */   swc1     $f0, 0x10($sp)
/* 79C030 802A1090 8FBF0024 */  lw        $ra, 0x24($sp)
/* 79C034 802A1094 8FB20020 */  lw        $s2, 0x20($sp)
/* 79C038 802A1098 8FB1001C */  lw        $s1, 0x1c($sp)
/* 79C03C 802A109C 8FB00018 */  lw        $s0, 0x18($sp)
/* 79C040 802A10A0 24020002 */  addiu     $v0, $zero, 2
/* 79C044 802A10A4 03E00008 */  jr        $ra
/* 79C048 802A10A8 27BD0028 */   addiu    $sp, $sp, 0x28
