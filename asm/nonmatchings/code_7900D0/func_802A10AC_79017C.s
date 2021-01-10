.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10AC_79017C
/* 79017C 802A10AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 790180 802A10B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 790184 802A10B4 0080882D */  daddu     $s1, $a0, $zero
/* 790188 802A10B8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 79018C 802A10BC AFB20028 */  sw        $s2, 0x28($sp)
/* 790190 802A10C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 790194 802A10C4 8E30000C */  lw        $s0, 0xc($s1)
/* 790198 802A10C8 8E050000 */  lw        $a1, ($s0)
/* 79019C 802A10CC 0C0B1EAF */  jal       get_variable
/* 7901A0 802A10D0 26100004 */   addiu    $s0, $s0, 4
/* 7901A4 802A10D4 8E050000 */  lw        $a1, ($s0)
/* 7901A8 802A10D8 26100004 */  addiu     $s0, $s0, 4
/* 7901AC 802A10DC 0220202D */  daddu     $a0, $s1, $zero
/* 7901B0 802A10E0 0C0B1EAF */  jal       get_variable
/* 7901B4 802A10E4 0040902D */   daddu    $s2, $v0, $zero
/* 7901B8 802A10E8 0220202D */  daddu     $a0, $s1, $zero
/* 7901BC 802A10EC 8E050000 */  lw        $a1, ($s0)
/* 7901C0 802A10F0 0C0B1EAF */  jal       get_variable
/* 7901C4 802A10F4 0040802D */   daddu    $s0, $v0, $zero
/* 7901C8 802A10F8 24040005 */  addiu     $a0, $zero, 5
/* 7901CC 802A10FC 44921000 */  mtc1      $s2, $f2
/* 7901D0 802A1100 00000000 */  nop       
/* 7901D4 802A1104 468010A0 */  cvt.s.w   $f2, $f2
/* 7901D8 802A1108 44051000 */  mfc1      $a1, $f2
/* 7901DC 802A110C 44901000 */  mtc1      $s0, $f2
/* 7901E0 802A1110 00000000 */  nop       
/* 7901E4 802A1114 468010A0 */  cvt.s.w   $f2, $f2
/* 7901E8 802A1118 44061000 */  mfc1      $a2, $f2
/* 7901EC 802A111C 44821000 */  mtc1      $v0, $f2
/* 7901F0 802A1120 00000000 */  nop       
/* 7901F4 802A1124 468010A0 */  cvt.s.w   $f2, $f2
/* 7901F8 802A1128 3C014248 */  lui       $at, 0x4248
/* 7901FC 802A112C 44810000 */  mtc1      $at, $f0
/* 790200 802A1130 44071000 */  mfc1      $a3, $f2
/* 790204 802A1134 24030028 */  addiu     $v1, $zero, 0x28
/* 790208 802A1138 AFA30018 */  sw        $v1, 0x18($sp)
/* 79020C 802A113C 2403001E */  addiu     $v1, $zero, 0x1e
/* 790210 802A1140 AFA3001C */  sw        $v1, 0x1c($sp)
/* 790214 802A1144 E7A00010 */  swc1      $f0, 0x10($sp)
/* 790218 802A1148 0C01C154 */  jal       func_80070550
/* 79021C 802A114C E7A00014 */   swc1     $f0, 0x14($sp)
/* 790220 802A1150 8FBF002C */  lw        $ra, 0x2c($sp)
/* 790224 802A1154 8FB20028 */  lw        $s2, 0x28($sp)
/* 790228 802A1158 8FB10024 */  lw        $s1, 0x24($sp)
/* 79022C 802A115C 8FB00020 */  lw        $s0, 0x20($sp)
/* 790230 802A1160 24020002 */  addiu     $v0, $zero, 2
/* 790234 802A1164 03E00008 */  jr        $ra
/* 790238 802A1168 27BD0030 */   addiu    $sp, $sp, 0x30
