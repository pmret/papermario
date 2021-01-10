.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10A4_756824
/* 756824 802A10A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 756828 802A10A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 75682C 802A10AC 0080802D */  daddu     $s0, $a0, $zero
/* 756830 802A10B0 10A00002 */  beqz      $a1, .L802A10BC
/* 756834 802A10B4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 756838 802A10B8 AE000070 */  sw        $zero, 0x70($s0)
.L802A10BC:
/* 75683C 802A10BC 8E030070 */  lw        $v1, 0x70($s0)
/* 756840 802A10C0 10600005 */  beqz      $v1, .L802A10D8
/* 756844 802A10C4 24020001 */   addiu    $v0, $zero, 1
/* 756848 802A10C8 10620007 */  beq       $v1, $v0, .L802A10E8
/* 75684C 802A10CC 0000102D */   daddu    $v0, $zero, $zero
/* 756850 802A10D0 080A845B */  j         .L802A116C
/* 756854 802A10D4 00000000 */   nop      
.L802A10D8:
/* 756858 802A10D8 2402001E */  addiu     $v0, $zero, 0x1e
/* 75685C 802A10DC AE020074 */  sw        $v0, 0x74($s0)
/* 756860 802A10E0 24020001 */  addiu     $v0, $zero, 1
/* 756864 802A10E4 AE020070 */  sw        $v0, 0x70($s0)
.L802A10E8:
/* 756868 802A10E8 24040001 */  addiu     $a0, $zero, 1
/* 75686C 802A10EC 0000282D */  daddu     $a1, $zero, $zero
/* 756870 802A10F0 00A0302D */  daddu     $a2, $a1, $zero
/* 756874 802A10F4 0C04DF93 */  jal       func_80137E4C
/* 756878 802A10F8 00A0382D */   daddu    $a3, $a1, $zero
/* 75687C 802A10FC 24040001 */  addiu     $a0, $zero, 1
/* 756880 802A1100 0080282D */  daddu     $a1, $a0, $zero
/* 756884 802A1104 24060140 */  addiu     $a2, $zero, 0x140
/* 756888 802A1108 0C04DF93 */  jal       func_80137E4C
/* 75688C 802A110C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 756890 802A1110 3C054320 */  lui       $a1, 0x4320
/* 756894 802A1114 0C04DF69 */  jal       func_80137DA4
/* 756898 802A1118 2404000C */   addiu    $a0, $zero, 0xc
/* 75689C 802A111C 8E020074 */  lw        $v0, 0x74($s0)
/* 7568A0 802A1120 14400010 */  bnez      $v0, .L802A1164
/* 7568A4 802A1124 2442FFFF */   addiu    $v0, $v0, -1
/* 7568A8 802A1128 24040001 */  addiu     $a0, $zero, 1
/* 7568AC 802A112C 0000282D */  daddu     $a1, $zero, $zero
/* 7568B0 802A1130 00A0302D */  daddu     $a2, $a1, $zero
/* 7568B4 802A1134 0C04DF93 */  jal       func_80137E4C
/* 7568B8 802A1138 00A0382D */   daddu    $a3, $a1, $zero
/* 7568BC 802A113C 24040001 */  addiu     $a0, $zero, 1
/* 7568C0 802A1140 0080282D */  daddu     $a1, $a0, $zero
/* 7568C4 802A1144 24060140 */  addiu     $a2, $zero, 0x140
/* 7568C8 802A1148 0C04DF93 */  jal       func_80137E4C
/* 7568CC 802A114C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 7568D0 802A1150 2404000C */  addiu     $a0, $zero, 0xc
/* 7568D4 802A1154 0C04DF69 */  jal       func_80137DA4
/* 7568D8 802A1158 0000282D */   daddu    $a1, $zero, $zero
/* 7568DC 802A115C 080A845B */  j         .L802A116C
/* 7568E0 802A1160 24020002 */   addiu    $v0, $zero, 2
.L802A1164:
/* 7568E4 802A1164 AE020074 */  sw        $v0, 0x74($s0)
/* 7568E8 802A1168 0000102D */  daddu     $v0, $zero, $zero
.L802A116C:
/* 7568EC 802A116C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7568F0 802A1170 8FB00010 */  lw        $s0, 0x10($sp)
/* 7568F4 802A1174 03E00008 */  jr        $ra
/* 7568F8 802A1178 27BD0018 */   addiu    $sp, $sp, 0x18
/* 7568FC 802A117C 00000000 */  nop       
