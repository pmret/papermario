.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10AC_79706C
/* 79706C 802A10AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 797070 802A10B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 797074 802A10B4 0080882D */  daddu     $s1, $a0, $zero
/* 797078 802A10B8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 79707C 802A10BC AFB20028 */  sw        $s2, 0x28($sp)
/* 797080 802A10C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 797084 802A10C4 8E30000C */  lw        $s0, 0xc($s1)
/* 797088 802A10C8 8E050000 */  lw        $a1, ($s0)
/* 79708C 802A10CC 0C0B1EAF */  jal       get_variable
/* 797090 802A10D0 26100004 */   addiu    $s0, $s0, 4
/* 797094 802A10D4 8E050000 */  lw        $a1, ($s0)
/* 797098 802A10D8 26100004 */  addiu     $s0, $s0, 4
/* 79709C 802A10DC 0220202D */  daddu     $a0, $s1, $zero
/* 7970A0 802A10E0 0C0B1EAF */  jal       get_variable
/* 7970A4 802A10E4 0040902D */   daddu    $s2, $v0, $zero
/* 7970A8 802A10E8 0220202D */  daddu     $a0, $s1, $zero
/* 7970AC 802A10EC 8E050000 */  lw        $a1, ($s0)
/* 7970B0 802A10F0 0C0B1EAF */  jal       get_variable
/* 7970B4 802A10F4 0040802D */   daddu    $s0, $v0, $zero
/* 7970B8 802A10F8 24040005 */  addiu     $a0, $zero, 5
/* 7970BC 802A10FC 44921000 */  mtc1      $s2, $f2
/* 7970C0 802A1100 00000000 */  nop
/* 7970C4 802A1104 468010A0 */  cvt.s.w   $f2, $f2
/* 7970C8 802A1108 44051000 */  mfc1      $a1, $f2
/* 7970CC 802A110C 44901000 */  mtc1      $s0, $f2
/* 7970D0 802A1110 00000000 */  nop
/* 7970D4 802A1114 468010A0 */  cvt.s.w   $f2, $f2
/* 7970D8 802A1118 44061000 */  mfc1      $a2, $f2
/* 7970DC 802A111C 44821000 */  mtc1      $v0, $f2
/* 7970E0 802A1120 00000000 */  nop
/* 7970E4 802A1124 468010A0 */  cvt.s.w   $f2, $f2
/* 7970E8 802A1128 3C014248 */  lui       $at, 0x4248
/* 7970EC 802A112C 44810000 */  mtc1      $at, $f0
/* 7970F0 802A1130 44071000 */  mfc1      $a3, $f2
/* 7970F4 802A1134 24030028 */  addiu     $v1, $zero, 0x28
/* 7970F8 802A1138 AFA30018 */  sw        $v1, 0x18($sp)
/* 7970FC 802A113C 2403001E */  addiu     $v1, $zero, 0x1e
/* 797100 802A1140 AFA3001C */  sw        $v1, 0x1c($sp)
/* 797104 802A1144 E7A00010 */  swc1      $f0, 0x10($sp)
/* 797108 802A1148 0C01C154 */  jal       func_80070550
/* 79710C 802A114C E7A00014 */   swc1     $f0, 0x14($sp)
/* 797110 802A1150 8FBF002C */  lw        $ra, 0x2c($sp)
/* 797114 802A1154 8FB20028 */  lw        $s2, 0x28($sp)
/* 797118 802A1158 8FB10024 */  lw        $s1, 0x24($sp)
/* 79711C 802A115C 8FB00020 */  lw        $s0, 0x20($sp)
/* 797120 802A1160 24020002 */  addiu     $v0, $zero, 2
/* 797124 802A1164 03E00008 */  jr        $ra
/* 797128 802A1168 27BD0030 */   addiu    $sp, $sp, 0x30
