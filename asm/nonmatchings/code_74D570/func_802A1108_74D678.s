.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1108_74D678
/* 74D678 802A1108 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 74D67C 802A110C AFB1001C */  sw        $s1, 0x1c($sp)
/* 74D680 802A1110 0080882D */  daddu     $s1, $a0, $zero
/* 74D684 802A1114 AFBF0024 */  sw        $ra, 0x24($sp)
/* 74D688 802A1118 AFB20020 */  sw        $s2, 0x20($sp)
/* 74D68C 802A111C AFB00018 */  sw        $s0, 0x18($sp)
/* 74D690 802A1120 8E30000C */  lw        $s0, 0xc($s1)
/* 74D694 802A1124 8E050000 */  lw        $a1, ($s0)
/* 74D698 802A1128 0C0B1EAF */  jal       get_variable
/* 74D69C 802A112C 26100004 */   addiu    $s0, $s0, 4
/* 74D6A0 802A1130 8E050000 */  lw        $a1, ($s0)
/* 74D6A4 802A1134 26100004 */  addiu     $s0, $s0, 4
/* 74D6A8 802A1138 0220202D */  daddu     $a0, $s1, $zero
/* 74D6AC 802A113C 0C0B1EAF */  jal       get_variable
/* 74D6B0 802A1140 0040902D */   daddu    $s2, $v0, $zero
/* 74D6B4 802A1144 0220202D */  daddu     $a0, $s1, $zero
/* 74D6B8 802A1148 8E050000 */  lw        $a1, ($s0)
/* 74D6BC 802A114C 0C0B1EAF */  jal       get_variable
/* 74D6C0 802A1150 0040802D */   daddu    $s0, $v0, $zero
/* 74D6C4 802A1154 0000202D */  daddu     $a0, $zero, $zero
/* 74D6C8 802A1158 44921000 */  mtc1      $s2, $f2
/* 74D6CC 802A115C 00000000 */  nop
/* 74D6D0 802A1160 468010A0 */  cvt.s.w   $f2, $f2
/* 74D6D4 802A1164 44051000 */  mfc1      $a1, $f2
/* 74D6D8 802A1168 44901000 */  mtc1      $s0, $f2
/* 74D6DC 802A116C 00000000 */  nop
/* 74D6E0 802A1170 468010A0 */  cvt.s.w   $f2, $f2
/* 74D6E4 802A1174 44061000 */  mfc1      $a2, $f2
/* 74D6E8 802A1178 44821000 */  mtc1      $v0, $f2
/* 74D6EC 802A117C 00000000 */  nop
/* 74D6F0 802A1180 468010A0 */  cvt.s.w   $f2, $f2
/* 74D6F4 802A1184 3C013F80 */  lui       $at, 0x3f80
/* 74D6F8 802A1188 44810000 */  mtc1      $at, $f0
/* 74D6FC 802A118C 44071000 */  mfc1      $a3, $f2
/* 74D700 802A1190 2403003C */  addiu     $v1, $zero, 0x3c
/* 74D704 802A1194 AFA30014 */  sw        $v1, 0x14($sp)
/* 74D708 802A1198 0C01C634 */  jal       func_800718D0
/* 74D70C 802A119C E7A00010 */   swc1     $f0, 0x10($sp)
/* 74D710 802A11A0 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 74D714 802A11A4 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 74D718 802A11A8 92020097 */  lbu       $v0, 0x97($s0)
/* 74D71C 802A11AC 24420001 */  addiu     $v0, $v0, 1
/* 74D720 802A11B0 A2020097 */  sb        $v0, 0x97($s0)
/* 74D724 802A11B4 00021600 */  sll       $v0, $v0, 0x18
/* 74D728 802A11B8 00021603 */  sra       $v0, $v0, 0x18
/* 74D72C 802A11BC 28420064 */  slti      $v0, $v0, 0x64
/* 74D730 802A11C0 14400003 */  bnez      $v0, .L802A11D0
/* 74D734 802A11C4 0200882D */   daddu    $s1, $s0, $zero
/* 74D738 802A11C8 24020063 */  addiu     $v0, $zero, 0x63
/* 74D73C 802A11CC A2020097 */  sb        $v0, 0x97($s0)
.L802A11D0:
/* 74D740 802A11D0 3C03EFFF */  lui       $v1, 0xefff
/* 74D744 802A11D4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 74D748 802A11D8 8E240000 */  lw        $a0, ($s1)
/* 74D74C 802A11DC 3C052000 */  lui       $a1, 0x2000
/* 74D750 802A11E0 A2200096 */  sb        $zero, 0x96($s1)
/* 74D754 802A11E4 00852025 */  or        $a0, $a0, $a1
/* 74D758 802A11E8 00832024 */  and       $a0, $a0, $v1
/* 74D75C 802A11EC AE240000 */  sw        $a0, ($s1)
/* 74D760 802A11F0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 74D764 802A11F4 8FB20020 */  lw        $s2, 0x20($sp)
/* 74D768 802A11F8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 74D76C 802A11FC 8FB00018 */  lw        $s0, 0x18($sp)
/* 74D770 802A1200 24020002 */  addiu     $v0, $zero, 2
/* 74D774 802A1204 03E00008 */  jr        $ra
/* 74D778 802A1208 27BD0028 */   addiu    $sp, $sp, 0x28
