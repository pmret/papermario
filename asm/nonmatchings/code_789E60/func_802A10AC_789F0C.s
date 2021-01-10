.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10AC_789F0C
/* 789F0C 802A10AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 789F10 802A10B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 789F14 802A10B4 0080882D */  daddu     $s1, $a0, $zero
/* 789F18 802A10B8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 789F1C 802A10BC AFB20028 */  sw        $s2, 0x28($sp)
/* 789F20 802A10C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 789F24 802A10C4 8E30000C */  lw        $s0, 0xc($s1)
/* 789F28 802A10C8 8E050000 */  lw        $a1, ($s0)
/* 789F2C 802A10CC 0C0B1EAF */  jal       get_variable
/* 789F30 802A10D0 26100004 */   addiu    $s0, $s0, 4
/* 789F34 802A10D4 8E050000 */  lw        $a1, ($s0)
/* 789F38 802A10D8 26100004 */  addiu     $s0, $s0, 4
/* 789F3C 802A10DC 0220202D */  daddu     $a0, $s1, $zero
/* 789F40 802A10E0 0C0B1EAF */  jal       get_variable
/* 789F44 802A10E4 0040902D */   daddu    $s2, $v0, $zero
/* 789F48 802A10E8 0220202D */  daddu     $a0, $s1, $zero
/* 789F4C 802A10EC 8E050000 */  lw        $a1, ($s0)
/* 789F50 802A10F0 0C0B1EAF */  jal       get_variable
/* 789F54 802A10F4 0040802D */   daddu    $s0, $v0, $zero
/* 789F58 802A10F8 24040005 */  addiu     $a0, $zero, 5
/* 789F5C 802A10FC 44921000 */  mtc1      $s2, $f2
/* 789F60 802A1100 00000000 */  nop       
/* 789F64 802A1104 468010A0 */  cvt.s.w   $f2, $f2
/* 789F68 802A1108 44051000 */  mfc1      $a1, $f2
/* 789F6C 802A110C 44901000 */  mtc1      $s0, $f2
/* 789F70 802A1110 00000000 */  nop       
/* 789F74 802A1114 468010A0 */  cvt.s.w   $f2, $f2
/* 789F78 802A1118 44061000 */  mfc1      $a2, $f2
/* 789F7C 802A111C 44821000 */  mtc1      $v0, $f2
/* 789F80 802A1120 00000000 */  nop       
/* 789F84 802A1124 468010A0 */  cvt.s.w   $f2, $f2
/* 789F88 802A1128 3C014248 */  lui       $at, 0x4248
/* 789F8C 802A112C 44810000 */  mtc1      $at, $f0
/* 789F90 802A1130 44071000 */  mfc1      $a3, $f2
/* 789F94 802A1134 24030028 */  addiu     $v1, $zero, 0x28
/* 789F98 802A1138 AFA30018 */  sw        $v1, 0x18($sp)
/* 789F9C 802A113C 2403001E */  addiu     $v1, $zero, 0x1e
/* 789FA0 802A1140 AFA3001C */  sw        $v1, 0x1c($sp)
/* 789FA4 802A1144 E7A00010 */  swc1      $f0, 0x10($sp)
/* 789FA8 802A1148 0C01C154 */  jal       func_80070550
/* 789FAC 802A114C E7A00014 */   swc1     $f0, 0x14($sp)
/* 789FB0 802A1150 8FBF002C */  lw        $ra, 0x2c($sp)
/* 789FB4 802A1154 8FB20028 */  lw        $s2, 0x28($sp)
/* 789FB8 802A1158 8FB10024 */  lw        $s1, 0x24($sp)
/* 789FBC 802A115C 8FB00020 */  lw        $s0, 0x20($sp)
/* 789FC0 802A1160 24020002 */  addiu     $v0, $zero, 2
/* 789FC4 802A1164 03E00008 */  jr        $ra
/* 789FC8 802A1168 27BD0030 */   addiu    $sp, $sp, 0x30
