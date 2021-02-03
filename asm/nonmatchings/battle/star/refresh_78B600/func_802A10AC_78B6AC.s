.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10AC_78B6AC
/* 78B6AC 802A10AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 78B6B0 802A10B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 78B6B4 802A10B4 0080882D */  daddu     $s1, $a0, $zero
/* 78B6B8 802A10B8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 78B6BC 802A10BC AFB20028 */  sw        $s2, 0x28($sp)
/* 78B6C0 802A10C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 78B6C4 802A10C4 8E30000C */  lw        $s0, 0xc($s1)
/* 78B6C8 802A10C8 8E050000 */  lw        $a1, ($s0)
/* 78B6CC 802A10CC 0C0B1EAF */  jal       get_variable
/* 78B6D0 802A10D0 26100004 */   addiu    $s0, $s0, 4
/* 78B6D4 802A10D4 8E050000 */  lw        $a1, ($s0)
/* 78B6D8 802A10D8 26100004 */  addiu     $s0, $s0, 4
/* 78B6DC 802A10DC 0220202D */  daddu     $a0, $s1, $zero
/* 78B6E0 802A10E0 0C0B1EAF */  jal       get_variable
/* 78B6E4 802A10E4 0040902D */   daddu    $s2, $v0, $zero
/* 78B6E8 802A10E8 0220202D */  daddu     $a0, $s1, $zero
/* 78B6EC 802A10EC 8E050000 */  lw        $a1, ($s0)
/* 78B6F0 802A10F0 0C0B1EAF */  jal       get_variable
/* 78B6F4 802A10F4 0040802D */   daddu    $s0, $v0, $zero
/* 78B6F8 802A10F8 24040005 */  addiu     $a0, $zero, 5
/* 78B6FC 802A10FC 44921000 */  mtc1      $s2, $f2
/* 78B700 802A1100 00000000 */  nop
/* 78B704 802A1104 468010A0 */  cvt.s.w   $f2, $f2
/* 78B708 802A1108 44051000 */  mfc1      $a1, $f2
/* 78B70C 802A110C 44901000 */  mtc1      $s0, $f2
/* 78B710 802A1110 00000000 */  nop
/* 78B714 802A1114 468010A0 */  cvt.s.w   $f2, $f2
/* 78B718 802A1118 44061000 */  mfc1      $a2, $f2
/* 78B71C 802A111C 44821000 */  mtc1      $v0, $f2
/* 78B720 802A1120 00000000 */  nop
/* 78B724 802A1124 468010A0 */  cvt.s.w   $f2, $f2
/* 78B728 802A1128 3C014248 */  lui       $at, 0x4248
/* 78B72C 802A112C 44810000 */  mtc1      $at, $f0
/* 78B730 802A1130 44071000 */  mfc1      $a3, $f2
/* 78B734 802A1134 24030028 */  addiu     $v1, $zero, 0x28
/* 78B738 802A1138 AFA30018 */  sw        $v1, 0x18($sp)
/* 78B73C 802A113C 2403001E */  addiu     $v1, $zero, 0x1e
/* 78B740 802A1140 AFA3001C */  sw        $v1, 0x1c($sp)
/* 78B744 802A1144 E7A00010 */  swc1      $f0, 0x10($sp)
/* 78B748 802A1148 0C01C154 */  jal       func_80070550
/* 78B74C 802A114C E7A00014 */   swc1     $f0, 0x14($sp)
/* 78B750 802A1150 8FBF002C */  lw        $ra, 0x2c($sp)
/* 78B754 802A1154 8FB20028 */  lw        $s2, 0x28($sp)
/* 78B758 802A1158 8FB10024 */  lw        $s1, 0x24($sp)
/* 78B75C 802A115C 8FB00020 */  lw        $s0, 0x20($sp)
/* 78B760 802A1160 24020002 */  addiu     $v0, $zero, 2
/* 78B764 802A1164 03E00008 */  jr        $ra
/* 78B768 802A1168 27BD0030 */   addiu    $sp, $sp, 0x30
