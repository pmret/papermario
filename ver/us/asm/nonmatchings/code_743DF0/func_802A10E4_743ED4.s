.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_743ED4
/* 743ED4 802A10E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 743ED8 802A10E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 743EDC 802A10EC 0080902D */  daddu     $s2, $a0, $zero
/* 743EE0 802A10F0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 743EE4 802A10F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 743EE8 802A10F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 743EEC 802A10FC 0C09A75B */  jal       get_actor
/* 743EF0 802A1100 8E440148 */   lw       $a0, 0x148($s2)
/* 743EF4 802A1104 0C09A75B */  jal       get_actor
/* 743EF8 802A1108 84440428 */   lh       $a0, 0x428($v0)
/* 743EFC 802A110C 24030063 */  addiu     $v1, $zero, 0x63
/* 743F00 802A1110 AE430084 */  sw        $v1, 0x84($s2)
/* 743F04 802A1114 8C420008 */  lw        $v0, 8($v0)
/* 743F08 802A1118 9051001E */  lbu       $s1, 0x1e($v0)
/* 743F0C 802A111C 0C03A752 */  jal       is_ability_active
/* 743F10 802A1120 0000202D */   daddu    $a0, $zero, $zero
/* 743F14 802A1124 54400001 */  bnel      $v0, $zero, .L802A112C
/* 743F18 802A1128 26310007 */   addiu    $s1, $s1, 7
.L802A112C:
/* 743F1C 802A112C 3C10802A */  lui       $s0, %hi(D_802A2730_745520)
/* 743F20 802A1130 26102730 */  addiu     $s0, $s0, %lo(D_802A2730_745520)
/* 743F24 802A1134 8E030000 */  lw        $v1, ($s0)
/* 743F28 802A1138 00710018 */  mult      $v1, $s1
/* 743F2C 802A113C 00001812 */  mflo      $v1
/* 743F30 802A1140 3C0251EB */  lui       $v0, 0x51eb
/* 743F34 802A1144 3442851F */  ori       $v0, $v0, 0x851f
/* 743F38 802A1148 00620018 */  mult      $v1, $v0
/* 743F3C 802A114C 24040064 */  addiu     $a0, $zero, 0x64
/* 743F40 802A1150 00031FC3 */  sra       $v1, $v1, 0x1f
/* 743F44 802A1154 00003010 */  mfhi      $a2
/* 743F48 802A1158 00061143 */  sra       $v0, $a2, 5
/* 743F4C 802A115C 00431023 */  subu      $v0, $v0, $v1
/* 743F50 802A1160 0C00A67F */  jal       rand_int
/* 743F54 802A1164 AE020000 */   sw       $v0, ($s0)
/* 743F58 802A1168 8E030000 */  lw        $v1, ($s0)
/* 743F5C 802A116C 0062182A */  slt       $v1, $v1, $v0
/* 743F60 802A1170 54600001 */  bnel      $v1, $zero, .L802A1178
/* 743F64 802A1174 AE400084 */   sw       $zero, 0x84($s2)
.L802A1178:
/* 743F68 802A1178 8FBF001C */  lw        $ra, 0x1c($sp)
/* 743F6C 802A117C 8FB20018 */  lw        $s2, 0x18($sp)
/* 743F70 802A1180 8FB10014 */  lw        $s1, 0x14($sp)
/* 743F74 802A1184 8FB00010 */  lw        $s0, 0x10($sp)
/* 743F78 802A1188 24020002 */  addiu     $v0, $zero, 2
/* 743F7C 802A118C 03E00008 */  jr        $ra
/* 743F80 802A1190 27BD0020 */   addiu    $sp, $sp, 0x20
