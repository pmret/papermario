.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10A4_74AE34
/* 74AE34 802A10A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 74AE38 802A10A8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 74AE3C 802A10AC 0080882D */  daddu     $s1, $a0, $zero
/* 74AE40 802A10B0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 74AE44 802A10B4 AFB20020 */  sw        $s2, 0x20($sp)
/* 74AE48 802A10B8 AFB00018 */  sw        $s0, 0x18($sp)
/* 74AE4C 802A10BC 8E30000C */  lw        $s0, 0xc($s1)
/* 74AE50 802A10C0 8E050000 */  lw        $a1, ($s0)
/* 74AE54 802A10C4 0C0B1EAF */  jal       get_variable
/* 74AE58 802A10C8 26100004 */   addiu    $s0, $s0, 4
/* 74AE5C 802A10CC 8E050000 */  lw        $a1, ($s0)
/* 74AE60 802A10D0 26100004 */  addiu     $s0, $s0, 4
/* 74AE64 802A10D4 0220202D */  daddu     $a0, $s1, $zero
/* 74AE68 802A10D8 0C0B1EAF */  jal       get_variable
/* 74AE6C 802A10DC 0040902D */   daddu    $s2, $v0, $zero
/* 74AE70 802A10E0 0220202D */  daddu     $a0, $s1, $zero
/* 74AE74 802A10E4 8E050000 */  lw        $a1, ($s0)
/* 74AE78 802A10E8 0C0B1EAF */  jal       get_variable
/* 74AE7C 802A10EC 0040802D */   daddu    $s0, $v0, $zero
/* 74AE80 802A10F0 8E2300AC */  lw        $v1, 0xac($s1)
/* 74AE84 802A10F4 14600013 */  bnez      $v1, .L802A1144
/* 74AE88 802A10F8 0040382D */   daddu    $a3, $v0, $zero
/* 74AE8C 802A10FC 2642001E */  addiu     $v0, $s2, 0x1e
/* 74AE90 802A1100 44821000 */  mtc1      $v0, $f2
/* 74AE94 802A1104 00000000 */  nop
/* 74AE98 802A1108 468010A0 */  cvt.s.w   $f2, $f2
/* 74AE9C 802A110C 26020019 */  addiu     $v0, $s0, 0x19
/* 74AEA0 802A1110 44051000 */  mfc1      $a1, $f2
/* 74AEA4 802A1114 44821000 */  mtc1      $v0, $f2
/* 74AEA8 802A1118 00000000 */  nop
/* 74AEAC 802A111C 468010A0 */  cvt.s.w   $f2, $f2
/* 74AEB0 802A1120 44061000 */  mfc1      $a2, $f2
/* 74AEB4 802A1124 44871000 */  mtc1      $a3, $f2
/* 74AEB8 802A1128 00000000 */  nop
/* 74AEBC 802A112C 468010A0 */  cvt.s.w   $f2, $f2
/* 74AEC0 802A1130 3C014234 */  lui       $at, 0x4234
/* 74AEC4 802A1134 44810000 */  mtc1      $at, $f0
/* 74AEC8 802A1138 44071000 */  mfc1      $a3, $f2
/* 74AECC 802A113C 080A8462 */  j         .L802A1188
/* 74AED0 802A1140 24040001 */   addiu    $a0, $zero, 1
.L802A1144:
/* 74AED4 802A1144 2642001E */  addiu     $v0, $s2, 0x1e
/* 74AED8 802A1148 44821000 */  mtc1      $v0, $f2
/* 74AEDC 802A114C 00000000 */  nop
/* 74AEE0 802A1150 468010A0 */  cvt.s.w   $f2, $f2
/* 74AEE4 802A1154 26020019 */  addiu     $v0, $s0, 0x19
/* 74AEE8 802A1158 44051000 */  mfc1      $a1, $f2
/* 74AEEC 802A115C 44821000 */  mtc1      $v0, $f2
/* 74AEF0 802A1160 00000000 */  nop
/* 74AEF4 802A1164 468010A0 */  cvt.s.w   $f2, $f2
/* 74AEF8 802A1168 44061000 */  mfc1      $a2, $f2
/* 74AEFC 802A116C 44871000 */  mtc1      $a3, $f2
/* 74AF00 802A1170 00000000 */  nop
/* 74AF04 802A1174 468010A0 */  cvt.s.w   $f2, $f2
/* 74AF08 802A1178 3C014234 */  lui       $at, 0x4234
/* 74AF0C 802A117C 44810000 */  mtc1      $at, $f0
/* 74AF10 802A1180 44071000 */  mfc1      $a3, $f2
/* 74AF14 802A1184 0000202D */  daddu     $a0, $zero, $zero
.L802A1188:
/* 74AF18 802A1188 0C01C2D4 */  jal       func_80070B50
/* 74AF1C 802A118C E7A00010 */   swc1     $f0, 0x10($sp)
/* 74AF20 802A1190 8FBF0024 */  lw        $ra, 0x24($sp)
/* 74AF24 802A1194 8FB20020 */  lw        $s2, 0x20($sp)
/* 74AF28 802A1198 8FB1001C */  lw        $s1, 0x1c($sp)
/* 74AF2C 802A119C 8FB00018 */  lw        $s0, 0x18($sp)
/* 74AF30 802A11A0 24020002 */  addiu     $v0, $zero, 2
/* 74AF34 802A11A4 03E00008 */  jr        $ra
/* 74AF38 802A11A8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 74AF3C 802A11AC 00000000 */  nop
