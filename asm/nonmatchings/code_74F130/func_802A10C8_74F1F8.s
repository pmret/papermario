.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10C8_74F1F8
/* 74F1F8 802A10C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 74F1FC 802A10CC AFB1001C */  sw        $s1, 0x1c($sp)
/* 74F200 802A10D0 0080882D */  daddu     $s1, $a0, $zero
/* 74F204 802A10D4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 74F208 802A10D8 AFB20020 */  sw        $s2, 0x20($sp)
/* 74F20C 802A10DC AFB00018 */  sw        $s0, 0x18($sp)
/* 74F210 802A10E0 8E30000C */  lw        $s0, 0xc($s1)
/* 74F214 802A10E4 8E050000 */  lw        $a1, ($s0)
/* 74F218 802A10E8 0C0B1EAF */  jal       get_variable
/* 74F21C 802A10EC 26100004 */   addiu    $s0, $s0, 4
/* 74F220 802A10F0 8E050000 */  lw        $a1, ($s0)
/* 74F224 802A10F4 26100004 */  addiu     $s0, $s0, 4
/* 74F228 802A10F8 0220202D */  daddu     $a0, $s1, $zero
/* 74F22C 802A10FC 0C0B1EAF */  jal       get_variable
/* 74F230 802A1100 0040902D */   daddu    $s2, $v0, $zero
/* 74F234 802A1104 0220202D */  daddu     $a0, $s1, $zero
/* 74F238 802A1108 8E050000 */  lw        $a1, ($s0)
/* 74F23C 802A110C 0C0B1EAF */  jal       get_variable
/* 74F240 802A1110 0040802D */   daddu    $s0, $v0, $zero
/* 74F244 802A1114 0000202D */  daddu     $a0, $zero, $zero
/* 74F248 802A1118 44921000 */  mtc1      $s2, $f2
/* 74F24C 802A111C 00000000 */  nop
/* 74F250 802A1120 468010A0 */  cvt.s.w   $f2, $f2
/* 74F254 802A1124 44051000 */  mfc1      $a1, $f2
/* 74F258 802A1128 44901000 */  mtc1      $s0, $f2
/* 74F25C 802A112C 00000000 */  nop
/* 74F260 802A1130 468010A0 */  cvt.s.w   $f2, $f2
/* 74F264 802A1134 44061000 */  mfc1      $a2, $f2
/* 74F268 802A1138 44821000 */  mtc1      $v0, $f2
/* 74F26C 802A113C 00000000 */  nop
/* 74F270 802A1140 468010A0 */  cvt.s.w   $f2, $f2
/* 74F274 802A1144 3C013F80 */  lui       $at, 0x3f80
/* 74F278 802A1148 44810000 */  mtc1      $at, $f0
/* 74F27C 802A114C 44071000 */  mfc1      $a3, $f2
/* 74F280 802A1150 2403003C */  addiu     $v1, $zero, 0x3c
/* 74F284 802A1154 AFA30014 */  sw        $v1, 0x14($sp)
/* 74F288 802A1158 0C01C634 */  jal       func_800718D0
/* 74F28C 802A115C E7A00010 */   swc1     $f0, 0x10($sp)
/* 74F290 802A1160 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 74F294 802A1164 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 74F298 802A1168 92020096 */  lbu       $v0, 0x96($s0)
/* 74F29C 802A116C 24420001 */  addiu     $v0, $v0, 1
/* 74F2A0 802A1170 A2020096 */  sb        $v0, 0x96($s0)
/* 74F2A4 802A1174 00021600 */  sll       $v0, $v0, 0x18
/* 74F2A8 802A1178 00021603 */  sra       $v0, $v0, 0x18
/* 74F2AC 802A117C 28420064 */  slti      $v0, $v0, 0x64
/* 74F2B0 802A1180 14400003 */  bnez      $v0, .L802A1190
/* 74F2B4 802A1184 0200882D */   daddu    $s1, $s0, $zero
/* 74F2B8 802A1188 24020063 */  addiu     $v0, $zero, 0x63
/* 74F2BC 802A118C A2020096 */  sb        $v0, 0x96($s0)
.L802A1190:
/* 74F2C0 802A1190 3C03DFFF */  lui       $v1, 0xdfff
/* 74F2C4 802A1194 3463FFFF */  ori       $v1, $v1, 0xffff
/* 74F2C8 802A1198 8E240000 */  lw        $a0, ($s1)
/* 74F2CC 802A119C 3C051000 */  lui       $a1, 0x1000
/* 74F2D0 802A11A0 A2200097 */  sb        $zero, 0x97($s1)
/* 74F2D4 802A11A4 00852025 */  or        $a0, $a0, $a1
/* 74F2D8 802A11A8 00832024 */  and       $a0, $a0, $v1
/* 74F2DC 802A11AC AE240000 */  sw        $a0, ($s1)
/* 74F2E0 802A11B0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 74F2E4 802A11B4 8FB20020 */  lw        $s2, 0x20($sp)
/* 74F2E8 802A11B8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 74F2EC 802A11BC 8FB00018 */  lw        $s0, 0x18($sp)
/* 74F2F0 802A11C0 24020002 */  addiu     $v0, $zero, 2
/* 74F2F4 802A11C4 03E00008 */  jr        $ra
/* 74F2F8 802A11C8 27BD0028 */   addiu    $sp, $sp, 0x28
