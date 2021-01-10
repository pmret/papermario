.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10AC_78D1FC
/* 78D1FC 802A10AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 78D200 802A10B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 78D204 802A10B4 0080882D */  daddu     $s1, $a0, $zero
/* 78D208 802A10B8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 78D20C 802A10BC AFB20028 */  sw        $s2, 0x28($sp)
/* 78D210 802A10C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 78D214 802A10C4 8E30000C */  lw        $s0, 0xc($s1)
/* 78D218 802A10C8 8E050000 */  lw        $a1, ($s0)
/* 78D21C 802A10CC 0C0B1EAF */  jal       get_variable
/* 78D220 802A10D0 26100004 */   addiu    $s0, $s0, 4
/* 78D224 802A10D4 8E050000 */  lw        $a1, ($s0)
/* 78D228 802A10D8 26100004 */  addiu     $s0, $s0, 4
/* 78D22C 802A10DC 0220202D */  daddu     $a0, $s1, $zero
/* 78D230 802A10E0 0C0B1EAF */  jal       get_variable
/* 78D234 802A10E4 0040902D */   daddu    $s2, $v0, $zero
/* 78D238 802A10E8 0220202D */  daddu     $a0, $s1, $zero
/* 78D23C 802A10EC 8E050000 */  lw        $a1, ($s0)
/* 78D240 802A10F0 0C0B1EAF */  jal       get_variable
/* 78D244 802A10F4 0040802D */   daddu    $s0, $v0, $zero
/* 78D248 802A10F8 24040005 */  addiu     $a0, $zero, 5
/* 78D24C 802A10FC 44921000 */  mtc1      $s2, $f2
/* 78D250 802A1100 00000000 */  nop       
/* 78D254 802A1104 468010A0 */  cvt.s.w   $f2, $f2
/* 78D258 802A1108 44051000 */  mfc1      $a1, $f2
/* 78D25C 802A110C 44901000 */  mtc1      $s0, $f2
/* 78D260 802A1110 00000000 */  nop       
/* 78D264 802A1114 468010A0 */  cvt.s.w   $f2, $f2
/* 78D268 802A1118 44061000 */  mfc1      $a2, $f2
/* 78D26C 802A111C 44821000 */  mtc1      $v0, $f2
/* 78D270 802A1120 00000000 */  nop       
/* 78D274 802A1124 468010A0 */  cvt.s.w   $f2, $f2
/* 78D278 802A1128 3C014248 */  lui       $at, 0x4248
/* 78D27C 802A112C 44810000 */  mtc1      $at, $f0
/* 78D280 802A1130 44071000 */  mfc1      $a3, $f2
/* 78D284 802A1134 24030028 */  addiu     $v1, $zero, 0x28
/* 78D288 802A1138 AFA30018 */  sw        $v1, 0x18($sp)
/* 78D28C 802A113C 2403001E */  addiu     $v1, $zero, 0x1e
/* 78D290 802A1140 AFA3001C */  sw        $v1, 0x1c($sp)
/* 78D294 802A1144 E7A00010 */  swc1      $f0, 0x10($sp)
/* 78D298 802A1148 0C01C154 */  jal       func_80070550
/* 78D29C 802A114C E7A00014 */   swc1     $f0, 0x14($sp)
/* 78D2A0 802A1150 8FBF002C */  lw        $ra, 0x2c($sp)
/* 78D2A4 802A1154 8FB20028 */  lw        $s2, 0x28($sp)
/* 78D2A8 802A1158 8FB10024 */  lw        $s1, 0x24($sp)
/* 78D2AC 802A115C 8FB00020 */  lw        $s0, 0x20($sp)
/* 78D2B0 802A1160 24020002 */  addiu     $v0, $zero, 2
/* 78D2B4 802A1164 03E00008 */  jr        $ra
/* 78D2B8 802A1168 27BD0030 */   addiu    $sp, $sp, 0x30
