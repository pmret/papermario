.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1108_761A28
/* 761A28 802A1108 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 761A2C 802A110C AFB1001C */  sw        $s1, 0x1c($sp)
/* 761A30 802A1110 0080882D */  daddu     $s1, $a0, $zero
/* 761A34 802A1114 AFBF0024 */  sw        $ra, 0x24($sp)
/* 761A38 802A1118 AFB20020 */  sw        $s2, 0x20($sp)
/* 761A3C 802A111C AFB00018 */  sw        $s0, 0x18($sp)
/* 761A40 802A1120 8E30000C */  lw        $s0, 0xc($s1)
/* 761A44 802A1124 8E050000 */  lw        $a1, ($s0)
/* 761A48 802A1128 0C0B1EAF */  jal       get_variable
/* 761A4C 802A112C 26100004 */   addiu    $s0, $s0, 4
/* 761A50 802A1130 8E050000 */  lw        $a1, ($s0)
/* 761A54 802A1134 26100004 */  addiu     $s0, $s0, 4
/* 761A58 802A1138 0220202D */  daddu     $a0, $s1, $zero
/* 761A5C 802A113C 0C0B1EAF */  jal       get_variable
/* 761A60 802A1140 0040902D */   daddu    $s2, $v0, $zero
/* 761A64 802A1144 0220202D */  daddu     $a0, $s1, $zero
/* 761A68 802A1148 8E050000 */  lw        $a1, ($s0)
/* 761A6C 802A114C 0C0B1EAF */  jal       get_variable
/* 761A70 802A1150 0040802D */   daddu    $s0, $v0, $zero
/* 761A74 802A1154 24040002 */  addiu     $a0, $zero, 2
/* 761A78 802A1158 44921000 */  mtc1      $s2, $f2
/* 761A7C 802A115C 00000000 */  nop       
/* 761A80 802A1160 468010A0 */  cvt.s.w   $f2, $f2
/* 761A84 802A1164 44051000 */  mfc1      $a1, $f2
/* 761A88 802A1168 44901000 */  mtc1      $s0, $f2
/* 761A8C 802A116C 00000000 */  nop       
/* 761A90 802A1170 468010A0 */  cvt.s.w   $f2, $f2
/* 761A94 802A1174 44061000 */  mfc1      $a2, $f2
/* 761A98 802A1178 44821000 */  mtc1      $v0, $f2
/* 761A9C 802A117C 00000000 */  nop       
/* 761AA0 802A1180 468010A0 */  cvt.s.w   $f2, $f2
/* 761AA4 802A1184 3C013F80 */  lui       $at, 0x3f80
/* 761AA8 802A1188 44810000 */  mtc1      $at, $f0
/* 761AAC 802A118C 44071000 */  mfc1      $a3, $f2
/* 761AB0 802A1190 2403003C */  addiu     $v1, $zero, 0x3c
/* 761AB4 802A1194 AFA30014 */  sw        $v1, 0x14($sp)
/* 761AB8 802A1198 0C01C634 */  jal       func_800718D0
/* 761ABC 802A119C E7A00010 */   swc1     $f0, 0x10($sp)
/* 761AC0 802A11A0 3C04802A */  lui       $a0, %hi(D_802A2C20)
/* 761AC4 802A11A4 24842C20 */  addiu     $a0, $a0, %lo(D_802A2C20)
/* 761AC8 802A11A8 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 761ACC 802A11AC 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 761AD0 802A11B0 AC800000 */  sw        $zero, ($a0)
/* 761AD4 802A11B4 82020097 */  lb        $v0, 0x97($s0)
/* 761AD8 802A11B8 92030097 */  lbu       $v1, 0x97($s0)
/* 761ADC 802A11BC 18400003 */  blez      $v0, .L802A11CC
/* 761AE0 802A11C0 0200882D */   daddu    $s1, $s0, $zero
/* 761AE4 802A11C4 24020001 */  addiu     $v0, $zero, 1
/* 761AE8 802A11C8 AC820000 */  sw        $v0, ($a0)
.L802A11CC:
/* 761AEC 802A11CC 24620003 */  addiu     $v0, $v1, 3
/* 761AF0 802A11D0 A2020097 */  sb        $v0, 0x97($s0)
/* 761AF4 802A11D4 00021600 */  sll       $v0, $v0, 0x18
/* 761AF8 802A11D8 00021603 */  sra       $v0, $v0, 0x18
/* 761AFC 802A11DC 28420064 */  slti      $v0, $v0, 0x64
/* 761B00 802A11E0 14400003 */  bnez      $v0, .L802A11F0
/* 761B04 802A11E4 3C03EFFF */   lui      $v1, 0xefff
/* 761B08 802A11E8 24020063 */  addiu     $v0, $zero, 0x63
/* 761B0C 802A11EC A2020097 */  sb        $v0, 0x97($s0)
.L802A11F0:
/* 761B10 802A11F0 3463FFFF */  ori       $v1, $v1, 0xffff
/* 761B14 802A11F4 8E240000 */  lw        $a0, ($s1)
/* 761B18 802A11F8 3C052000 */  lui       $a1, 0x2000
/* 761B1C 802A11FC A2200096 */  sb        $zero, 0x96($s1)
/* 761B20 802A1200 00852025 */  or        $a0, $a0, $a1
/* 761B24 802A1204 00832024 */  and       $a0, $a0, $v1
/* 761B28 802A1208 AE240000 */  sw        $a0, ($s1)
/* 761B2C 802A120C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 761B30 802A1210 8FB20020 */  lw        $s2, 0x20($sp)
/* 761B34 802A1214 8FB1001C */  lw        $s1, 0x1c($sp)
/* 761B38 802A1218 8FB00018 */  lw        $s0, 0x18($sp)
/* 761B3C 802A121C 24020002 */  addiu     $v0, $zero, 2
/* 761B40 802A1220 03E00008 */  jr        $ra
/* 761B44 802A1224 27BD0028 */   addiu    $sp, $sp, 0x28
