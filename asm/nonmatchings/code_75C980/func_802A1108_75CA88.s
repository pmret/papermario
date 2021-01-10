.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1108_75CA88
/* 75CA88 802A1108 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 75CA8C 802A110C AFB1001C */  sw        $s1, 0x1c($sp)
/* 75CA90 802A1110 0080882D */  daddu     $s1, $a0, $zero
/* 75CA94 802A1114 AFBF0024 */  sw        $ra, 0x24($sp)
/* 75CA98 802A1118 AFB20020 */  sw        $s2, 0x20($sp)
/* 75CA9C 802A111C AFB00018 */  sw        $s0, 0x18($sp)
/* 75CAA0 802A1120 8E30000C */  lw        $s0, 0xc($s1)
/* 75CAA4 802A1124 8E050000 */  lw        $a1, ($s0)
/* 75CAA8 802A1128 0C0B1EAF */  jal       get_variable
/* 75CAAC 802A112C 26100004 */   addiu    $s0, $s0, 4
/* 75CAB0 802A1130 8E050000 */  lw        $a1, ($s0)
/* 75CAB4 802A1134 26100004 */  addiu     $s0, $s0, 4
/* 75CAB8 802A1138 0220202D */  daddu     $a0, $s1, $zero
/* 75CABC 802A113C 0C0B1EAF */  jal       get_variable
/* 75CAC0 802A1140 0040902D */   daddu    $s2, $v0, $zero
/* 75CAC4 802A1144 0220202D */  daddu     $a0, $s1, $zero
/* 75CAC8 802A1148 8E050000 */  lw        $a1, ($s0)
/* 75CACC 802A114C 0C0B1EAF */  jal       get_variable
/* 75CAD0 802A1150 0040802D */   daddu    $s0, $v0, $zero
/* 75CAD4 802A1154 24040001 */  addiu     $a0, $zero, 1
/* 75CAD8 802A1158 44921000 */  mtc1      $s2, $f2
/* 75CADC 802A115C 00000000 */  nop       
/* 75CAE0 802A1160 468010A0 */  cvt.s.w   $f2, $f2
/* 75CAE4 802A1164 44051000 */  mfc1      $a1, $f2
/* 75CAE8 802A1168 44901000 */  mtc1      $s0, $f2
/* 75CAEC 802A116C 00000000 */  nop       
/* 75CAF0 802A1170 468010A0 */  cvt.s.w   $f2, $f2
/* 75CAF4 802A1174 44061000 */  mfc1      $a2, $f2
/* 75CAF8 802A1178 44821000 */  mtc1      $v0, $f2
/* 75CAFC 802A117C 00000000 */  nop       
/* 75CB00 802A1180 468010A0 */  cvt.s.w   $f2, $f2
/* 75CB04 802A1184 3C013F80 */  lui       $at, 0x3f80
/* 75CB08 802A1188 44810000 */  mtc1      $at, $f0
/* 75CB0C 802A118C 44071000 */  mfc1      $a3, $f2
/* 75CB10 802A1190 2403003C */  addiu     $v1, $zero, 0x3c
/* 75CB14 802A1194 AFA30014 */  sw        $v1, 0x14($sp)
/* 75CB18 802A1198 0C01C634 */  jal       func_800718D0
/* 75CB1C 802A119C E7A00010 */   swc1     $f0, 0x10($sp)
/* 75CB20 802A11A0 3C04802A */  lui       $a0, %hi(D_802A2C50)
/* 75CB24 802A11A4 24842C50 */  addiu     $a0, $a0, %lo(D_802A2C50)
/* 75CB28 802A11A8 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 75CB2C 802A11AC 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 75CB30 802A11B0 AC800000 */  sw        $zero, ($a0)
/* 75CB34 802A11B4 82020097 */  lb        $v0, 0x97($s0)
/* 75CB38 802A11B8 92030097 */  lbu       $v1, 0x97($s0)
/* 75CB3C 802A11BC 18400003 */  blez      $v0, .L802A11CC
/* 75CB40 802A11C0 0200882D */   daddu    $s1, $s0, $zero
/* 75CB44 802A11C4 24020001 */  addiu     $v0, $zero, 1
/* 75CB48 802A11C8 AC820000 */  sw        $v0, ($a0)
.L802A11CC:
/* 75CB4C 802A11CC 24620002 */  addiu     $v0, $v1, 2
/* 75CB50 802A11D0 A2020097 */  sb        $v0, 0x97($s0)
/* 75CB54 802A11D4 00021600 */  sll       $v0, $v0, 0x18
/* 75CB58 802A11D8 00021603 */  sra       $v0, $v0, 0x18
/* 75CB5C 802A11DC 28420064 */  slti      $v0, $v0, 0x64
/* 75CB60 802A11E0 14400003 */  bnez      $v0, .L802A11F0
/* 75CB64 802A11E4 3C03EFFF */   lui      $v1, 0xefff
/* 75CB68 802A11E8 24020063 */  addiu     $v0, $zero, 0x63
/* 75CB6C 802A11EC A2020097 */  sb        $v0, 0x97($s0)
.L802A11F0:
/* 75CB70 802A11F0 3463FFFF */  ori       $v1, $v1, 0xffff
/* 75CB74 802A11F4 8E240000 */  lw        $a0, ($s1)
/* 75CB78 802A11F8 3C052000 */  lui       $a1, 0x2000
/* 75CB7C 802A11FC A2200096 */  sb        $zero, 0x96($s1)
/* 75CB80 802A1200 00852025 */  or        $a0, $a0, $a1
/* 75CB84 802A1204 00832024 */  and       $a0, $a0, $v1
/* 75CB88 802A1208 AE240000 */  sw        $a0, ($s1)
/* 75CB8C 802A120C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 75CB90 802A1210 8FB20020 */  lw        $s2, 0x20($sp)
/* 75CB94 802A1214 8FB1001C */  lw        $s1, 0x1c($sp)
/* 75CB98 802A1218 8FB00018 */  lw        $s0, 0x18($sp)
/* 75CB9C 802A121C 24020002 */  addiu     $v0, $zero, 2
/* 75CBA0 802A1220 03E00008 */  jr        $ra
/* 75CBA4 802A1224 27BD0028 */   addiu    $sp, $sp, 0x28
