.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_781A04
/* 781A04 802A10E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 781A08 802A10E8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 781A0C 802A10EC 0080882D */  daddu     $s1, $a0, $zero
/* 781A10 802A10F0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 781A14 802A10F4 AFB20020 */  sw        $s2, 0x20($sp)
/* 781A18 802A10F8 AFB00018 */  sw        $s0, 0x18($sp)
/* 781A1C 802A10FC 8E30000C */  lw        $s0, 0xc($s1)
/* 781A20 802A1100 8E050000 */  lw        $a1, ($s0)
/* 781A24 802A1104 0C0B1EAF */  jal       get_variable
/* 781A28 802A1108 26100004 */   addiu    $s0, $s0, 4
/* 781A2C 802A110C 8E050000 */  lw        $a1, ($s0)
/* 781A30 802A1110 26100004 */  addiu     $s0, $s0, 4
/* 781A34 802A1114 0220202D */  daddu     $a0, $s1, $zero
/* 781A38 802A1118 0C0B1EAF */  jal       get_variable
/* 781A3C 802A111C 0040902D */   daddu    $s2, $v0, $zero
/* 781A40 802A1120 0220202D */  daddu     $a0, $s1, $zero
/* 781A44 802A1124 8E050000 */  lw        $a1, ($s0)
/* 781A48 802A1128 0C0B1EAF */  jal       get_variable
/* 781A4C 802A112C 0040802D */   daddu    $s0, $v0, $zero
/* 781A50 802A1130 8E2300AC */  lw        $v1, 0xac($s1)
/* 781A54 802A1134 1460000F */  bnez      $v1, .L802A1174
/* 781A58 802A1138 0000202D */   daddu    $a0, $zero, $zero
/* 781A5C 802A113C 44920000 */  mtc1      $s2, $f0
/* 781A60 802A1140 00000000 */  nop       
/* 781A64 802A1144 46800020 */  cvt.s.w   $f0, $f0
/* 781A68 802A1148 44050000 */  mfc1      $a1, $f0
/* 781A6C 802A114C 44900000 */  mtc1      $s0, $f0
/* 781A70 802A1150 00000000 */  nop       
/* 781A74 802A1154 46800020 */  cvt.s.w   $f0, $f0
/* 781A78 802A1158 44060000 */  mfc1      $a2, $f0
/* 781A7C 802A115C 44820000 */  mtc1      $v0, $f0
/* 781A80 802A1160 00000000 */  nop       
/* 781A84 802A1164 46800020 */  cvt.s.w   $f0, $f0
/* 781A88 802A1168 44070000 */  mfc1      $a3, $f0
/* 781A8C 802A116C 080A8469 */  j         .L802A11A4
/* 781A90 802A1170 24040001 */   addiu    $a0, $zero, 1
.L802A1174:
/* 781A94 802A1174 44920000 */  mtc1      $s2, $f0
/* 781A98 802A1178 00000000 */  nop       
/* 781A9C 802A117C 46800020 */  cvt.s.w   $f0, $f0
/* 781AA0 802A1180 44050000 */  mfc1      $a1, $f0
/* 781AA4 802A1184 44900000 */  mtc1      $s0, $f0
/* 781AA8 802A1188 00000000 */  nop       
/* 781AAC 802A118C 46800020 */  cvt.s.w   $f0, $f0
/* 781AB0 802A1190 44060000 */  mfc1      $a2, $f0
/* 781AB4 802A1194 44820000 */  mtc1      $v0, $f0
/* 781AB8 802A1198 00000000 */  nop       
/* 781ABC 802A119C 46800020 */  cvt.s.w   $f0, $f0
/* 781AC0 802A11A0 44070000 */  mfc1      $a3, $f0
.L802A11A4:
/* 781AC4 802A11A4 0C01C2D4 */  jal       func_80070B50
/* 781AC8 802A11A8 AFA00010 */   sw       $zero, 0x10($sp)
/* 781ACC 802A11AC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 781AD0 802A11B0 8FB20020 */  lw        $s2, 0x20($sp)
/* 781AD4 802A11B4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 781AD8 802A11B8 8FB00018 */  lw        $s0, 0x18($sp)
/* 781ADC 802A11BC 24020002 */  addiu     $v0, $zero, 2
/* 781AE0 802A11C0 03E00008 */  jr        $ra
/* 781AE4 802A11C4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 781AE8 802A11C8 00000000 */  nop       
/* 781AEC 802A11CC 00000000 */  nop       
