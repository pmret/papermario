.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10C8_75E698
/* 75E698 802A10C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 75E69C 802A10CC AFB1001C */  sw        $s1, 0x1c($sp)
/* 75E6A0 802A10D0 0080882D */  daddu     $s1, $a0, $zero
/* 75E6A4 802A10D4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 75E6A8 802A10D8 AFB20020 */  sw        $s2, 0x20($sp)
/* 75E6AC 802A10DC AFB00018 */  sw        $s0, 0x18($sp)
/* 75E6B0 802A10E0 8E30000C */  lw        $s0, 0xc($s1)
/* 75E6B4 802A10E4 8E050000 */  lw        $a1, ($s0)
/* 75E6B8 802A10E8 0C0B1EAF */  jal       get_variable
/* 75E6BC 802A10EC 26100004 */   addiu    $s0, $s0, 4
/* 75E6C0 802A10F0 8E050000 */  lw        $a1, ($s0)
/* 75E6C4 802A10F4 26100004 */  addiu     $s0, $s0, 4
/* 75E6C8 802A10F8 0220202D */  daddu     $a0, $s1, $zero
/* 75E6CC 802A10FC 0C0B1EAF */  jal       get_variable
/* 75E6D0 802A1100 0040902D */   daddu    $s2, $v0, $zero
/* 75E6D4 802A1104 0220202D */  daddu     $a0, $s1, $zero
/* 75E6D8 802A1108 8E050000 */  lw        $a1, ($s0)
/* 75E6DC 802A110C 0C0B1EAF */  jal       get_variable
/* 75E6E0 802A1110 0040802D */   daddu    $s0, $v0, $zero
/* 75E6E4 802A1114 24040002 */  addiu     $a0, $zero, 2
/* 75E6E8 802A1118 44921000 */  mtc1      $s2, $f2
/* 75E6EC 802A111C 00000000 */  nop       
/* 75E6F0 802A1120 468010A0 */  cvt.s.w   $f2, $f2
/* 75E6F4 802A1124 44051000 */  mfc1      $a1, $f2
/* 75E6F8 802A1128 44901000 */  mtc1      $s0, $f2
/* 75E6FC 802A112C 00000000 */  nop       
/* 75E700 802A1130 468010A0 */  cvt.s.w   $f2, $f2
/* 75E704 802A1134 44061000 */  mfc1      $a2, $f2
/* 75E708 802A1138 44821000 */  mtc1      $v0, $f2
/* 75E70C 802A113C 00000000 */  nop       
/* 75E710 802A1140 468010A0 */  cvt.s.w   $f2, $f2
/* 75E714 802A1144 3C013F80 */  lui       $at, 0x3f80
/* 75E718 802A1148 44810000 */  mtc1      $at, $f0
/* 75E71C 802A114C 44071000 */  mfc1      $a3, $f2
/* 75E720 802A1150 2403003C */  addiu     $v1, $zero, 0x3c
/* 75E724 802A1154 AFA30014 */  sw        $v1, 0x14($sp)
/* 75E728 802A1158 0C01C634 */  jal       func_800718D0
/* 75E72C 802A115C E7A00010 */   swc1     $f0, 0x10($sp)
/* 75E730 802A1160 3C04802A */  lui       $a0, %hi(D_802A4350)
/* 75E734 802A1164 24844350 */  addiu     $a0, $a0, %lo(D_802A4350)
/* 75E738 802A1168 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 75E73C 802A116C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 75E740 802A1170 AC800000 */  sw        $zero, ($a0)
/* 75E744 802A1174 82020096 */  lb        $v0, 0x96($s0)
/* 75E748 802A1178 92030096 */  lbu       $v1, 0x96($s0)
/* 75E74C 802A117C 18400003 */  blez      $v0, .L802A118C
/* 75E750 802A1180 0200882D */   daddu    $s1, $s0, $zero
/* 75E754 802A1184 24020001 */  addiu     $v0, $zero, 1
/* 75E758 802A1188 AC820000 */  sw        $v0, ($a0)
.L802A118C:
/* 75E75C 802A118C 24620003 */  addiu     $v0, $v1, 3
/* 75E760 802A1190 A2020096 */  sb        $v0, 0x96($s0)
/* 75E764 802A1194 00021600 */  sll       $v0, $v0, 0x18
/* 75E768 802A1198 00021603 */  sra       $v0, $v0, 0x18
/* 75E76C 802A119C 28420064 */  slti      $v0, $v0, 0x64
/* 75E770 802A11A0 14400003 */  bnez      $v0, .L802A11B0
/* 75E774 802A11A4 3C03DFFF */   lui      $v1, 0xdfff
/* 75E778 802A11A8 24020063 */  addiu     $v0, $zero, 0x63
/* 75E77C 802A11AC A2020096 */  sb        $v0, 0x96($s0)
.L802A11B0:
/* 75E780 802A11B0 3463FFFF */  ori       $v1, $v1, 0xffff
/* 75E784 802A11B4 8E240000 */  lw        $a0, ($s1)
/* 75E788 802A11B8 3C051000 */  lui       $a1, 0x1000
/* 75E78C 802A11BC A2200097 */  sb        $zero, 0x97($s1)
/* 75E790 802A11C0 00852025 */  or        $a0, $a0, $a1
/* 75E794 802A11C4 00832024 */  and       $a0, $a0, $v1
/* 75E798 802A11C8 AE240000 */  sw        $a0, ($s1)
/* 75E79C 802A11CC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 75E7A0 802A11D0 8FB20020 */  lw        $s2, 0x20($sp)
/* 75E7A4 802A11D4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 75E7A8 802A11D8 8FB00018 */  lw        $s0, 0x18($sp)
/* 75E7AC 802A11DC 24020002 */  addiu     $v0, $zero, 2
/* 75E7B0 802A11E0 03E00008 */  jr        $ra
/* 75E7B4 802A11E4 27BD0028 */   addiu    $sp, $sp, 0x28
