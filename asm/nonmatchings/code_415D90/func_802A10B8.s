.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10B8
/* 415E48 802A10B8 3C02802B */  lui       $v0, %hi(D_802AD0AC)
/* 415E4C 802A10BC 8C42D0AC */  lw        $v0, %lo(D_802AD0AC)($v0)
/* 415E50 802A10C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 415E54 802A10C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 415E58 802A10C8 0000802D */  daddu     $s0, $zero, $zero
/* 415E5C 802A10CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 415E60 802A10D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 415E64 802A10D4 18400010 */  blez      $v0, .L802A1118
/* 415E68 802A10D8 AFB10014 */   sw       $s1, 0x14($sp)
/* 415E6C 802A10DC 3C12802B */  lui       $s2, %hi(D_802AD028)
/* 415E70 802A10E0 2652D028 */  addiu     $s2, $s2, %lo(D_802AD028)
/* 415E74 802A10E4 3C11802B */  lui       $s1, %hi(D_802AD010)
/* 415E78 802A10E8 2631D010 */  addiu     $s1, $s1, %lo(D_802AD010)
.L802A10EC:
/* 415E7C 802A10EC 8E240000 */  lw        $a0, ($s1)
/* 415E80 802A10F0 0C05123D */  jal       free_icon
/* 415E84 802A10F4 26310004 */   addiu    $s1, $s1, 4
/* 415E88 802A10F8 8E440000 */  lw        $a0, ($s2)
/* 415E8C 802A10FC 0C05123D */  jal       free_icon
/* 415E90 802A1100 26100001 */   addiu    $s0, $s0, 1
/* 415E94 802A1104 3C02802B */  lui       $v0, %hi(D_802AD0AC)
/* 415E98 802A1108 8C42D0AC */  lw        $v0, %lo(D_802AD0AC)($v0)
/* 415E9C 802A110C 0202102A */  slt       $v0, $s0, $v0
/* 415EA0 802A1110 1440FFF6 */  bnez      $v0, .L802A10EC
/* 415EA4 802A1114 26520004 */   addiu    $s2, $s2, 4
.L802A1118:
/* 415EA8 802A1118 3C04802B */  lui       $a0, %hi(D_802AD040)
/* 415EAC 802A111C 8C84D040 */  lw        $a0, %lo(D_802AD040)($a0)
/* 415EB0 802A1120 0C05123D */  jal       free_icon
/* 415EB4 802A1124 00000000 */   nop
/* 415EB8 802A1128 3C04802B */  lui       $a0, %hi(D_802AD044)
/* 415EBC 802A112C 8C84D044 */  lw        $a0, %lo(D_802AD044)($a0)
/* 415EC0 802A1130 0C05123D */  jal       free_icon
/* 415EC4 802A1134 00000000 */   nop
/* 415EC8 802A1138 3C04802B */  lui       $a0, %hi(D_802AD048)
/* 415ECC 802A113C 8C84D048 */  lw        $a0, %lo(D_802AD048)($a0)
/* 415ED0 802A1140 0C05123D */  jal       free_icon
/* 415ED4 802A1144 00000000 */   nop
/* 415ED8 802A1148 3C04802B */  lui       $a0, %hi(D_802AD04C)
/* 415EDC 802A114C 8C84D04C */  lw        $a0, %lo(D_802AD04C)($a0)
/* 415EE0 802A1150 0C05123D */  jal       free_icon
/* 415EE4 802A1154 00000000 */   nop
/* 415EE8 802A1158 3C04802B */  lui       $a0, %hi(D_802AD05C)
/* 415EEC 802A115C 8C84D05C */  lw        $a0, %lo(D_802AD05C)($a0)
/* 415EF0 802A1160 0C05123D */  jal       free_icon
/* 415EF4 802A1164 00000000 */   nop
/* 415EF8 802A1168 3C04802B */  lui       $a0, %hi(D_802AD050)
/* 415EFC 802A116C 8C84D050 */  lw        $a0, %lo(D_802AD050)($a0)
/* 415F00 802A1170 0C05123D */  jal       free_icon
/* 415F04 802A1174 00000000 */   nop
/* 415F08 802A1178 3C04802B */  lui       $a0, %hi(D_802AD054)
/* 415F0C 802A117C 8C84D054 */  lw        $a0, %lo(D_802AD054)($a0)
/* 415F10 802A1180 0C05123D */  jal       free_icon
/* 415F14 802A1184 00000000 */   nop
/* 415F18 802A1188 3C04802B */  lui       $a0, %hi(D_802AD058)
/* 415F1C 802A118C 8C84D058 */  lw        $a0, %lo(D_802AD058)($a0)
/* 415F20 802A1190 0C05123D */  jal       free_icon
/* 415F24 802A1194 00000000 */   nop
/* 415F28 802A1198 8FBF001C */  lw        $ra, 0x1c($sp)
/* 415F2C 802A119C 8FB20018 */  lw        $s2, 0x18($sp)
/* 415F30 802A11A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 415F34 802A11A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 415F38 802A11A8 03E00008 */  jr        $ra
/* 415F3C 802A11AC 27BD0020 */   addiu    $sp, $sp, 0x20
