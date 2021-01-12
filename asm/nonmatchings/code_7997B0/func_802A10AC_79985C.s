.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10AC_79985C
/* 79985C 802A10AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 799860 802A10B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 799864 802A10B4 0080882D */  daddu     $s1, $a0, $zero
/* 799868 802A10B8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 79986C 802A10BC AFB20028 */  sw        $s2, 0x28($sp)
/* 799870 802A10C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 799874 802A10C4 8E30000C */  lw        $s0, 0xc($s1)
/* 799878 802A10C8 8E050000 */  lw        $a1, ($s0)
/* 79987C 802A10CC 0C0B1EAF */  jal       get_variable
/* 799880 802A10D0 26100004 */   addiu    $s0, $s0, 4
/* 799884 802A10D4 8E050000 */  lw        $a1, ($s0)
/* 799888 802A10D8 26100004 */  addiu     $s0, $s0, 4
/* 79988C 802A10DC 0220202D */  daddu     $a0, $s1, $zero
/* 799890 802A10E0 0C0B1EAF */  jal       get_variable
/* 799894 802A10E4 0040902D */   daddu    $s2, $v0, $zero
/* 799898 802A10E8 0220202D */  daddu     $a0, $s1, $zero
/* 79989C 802A10EC 8E050000 */  lw        $a1, ($s0)
/* 7998A0 802A10F0 0C0B1EAF */  jal       get_variable
/* 7998A4 802A10F4 0040802D */   daddu    $s0, $v0, $zero
/* 7998A8 802A10F8 24040005 */  addiu     $a0, $zero, 5
/* 7998AC 802A10FC 44921000 */  mtc1      $s2, $f2
/* 7998B0 802A1100 00000000 */  nop       
/* 7998B4 802A1104 468010A0 */  cvt.s.w   $f2, $f2
/* 7998B8 802A1108 44051000 */  mfc1      $a1, $f2
/* 7998BC 802A110C 44901000 */  mtc1      $s0, $f2
/* 7998C0 802A1110 00000000 */  nop       
/* 7998C4 802A1114 468010A0 */  cvt.s.w   $f2, $f2
/* 7998C8 802A1118 44061000 */  mfc1      $a2, $f2
/* 7998CC 802A111C 44821000 */  mtc1      $v0, $f2
/* 7998D0 802A1120 00000000 */  nop       
/* 7998D4 802A1124 468010A0 */  cvt.s.w   $f2, $f2
/* 7998D8 802A1128 3C014248 */  lui       $at, 0x4248
/* 7998DC 802A112C 44810000 */  mtc1      $at, $f0
/* 7998E0 802A1130 44071000 */  mfc1      $a3, $f2
/* 7998E4 802A1134 24030028 */  addiu     $v1, $zero, 0x28
/* 7998E8 802A1138 AFA30018 */  sw        $v1, 0x18($sp)
/* 7998EC 802A113C 2403001E */  addiu     $v1, $zero, 0x1e
/* 7998F0 802A1140 AFA3001C */  sw        $v1, 0x1c($sp)
/* 7998F4 802A1144 E7A00010 */  swc1      $f0, 0x10($sp)
/* 7998F8 802A1148 0C01C154 */  jal       func_80070550
/* 7998FC 802A114C E7A00014 */   swc1     $f0, 0x14($sp)
/* 799900 802A1150 8FBF002C */  lw        $ra, 0x2c($sp)
/* 799904 802A1154 8FB20028 */  lw        $s2, 0x28($sp)
/* 799908 802A1158 8FB10024 */  lw        $s1, 0x24($sp)
/* 79990C 802A115C 8FB00020 */  lw        $s0, 0x20($sp)
/* 799910 802A1160 24020002 */  addiu     $v0, $zero, 2
/* 799914 802A1164 03E00008 */  jr        $ra
/* 799918 802A1168 27BD0030 */   addiu    $sp, $sp, 0x30
