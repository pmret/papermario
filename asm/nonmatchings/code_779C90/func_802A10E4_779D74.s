.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_779D74
/* 779D74 802A10E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 779D78 802A10E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 779D7C 802A10EC 0080902D */  daddu     $s2, $a0, $zero
/* 779D80 802A10F0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 779D84 802A10F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 779D88 802A10F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 779D8C 802A10FC 0C09A75B */  jal       get_actor
/* 779D90 802A1100 8E440148 */   lw       $a0, 0x148($s2)
/* 779D94 802A1104 0C09A75B */  jal       get_actor
/* 779D98 802A1108 84440428 */   lh       $a0, 0x428($v0)
/* 779D9C 802A110C 24030063 */  addiu     $v1, $zero, 0x63
/* 779DA0 802A1110 AE430084 */  sw        $v1, 0x84($s2)
/* 779DA4 802A1114 8C420008 */  lw        $v0, 8($v0)
/* 779DA8 802A1118 9051001E */  lbu       $s1, 0x1e($v0)
/* 779DAC 802A111C 0C03A752 */  jal       is_ability_active
/* 779DB0 802A1120 0000202D */   daddu    $a0, $zero, $zero
/* 779DB4 802A1124 54400001 */  bnel      $v0, $zero, .L802A112C
/* 779DB8 802A1128 26310007 */   addiu    $s1, $s1, 7
.L802A112C:
/* 779DBC 802A112C 3C10802A */  lui       $s0, %hi(D_802A26D0)
/* 779DC0 802A1130 261026D0 */  addiu     $s0, $s0, %lo(D_802A26D0)
/* 779DC4 802A1134 8E030000 */  lw        $v1, ($s0)
/* 779DC8 802A1138 00710018 */  mult      $v1, $s1
/* 779DCC 802A113C 00001812 */  mflo      $v1
/* 779DD0 802A1140 3C0251EB */  lui       $v0, 0x51eb
/* 779DD4 802A1144 3442851F */  ori       $v0, $v0, 0x851f
/* 779DD8 802A1148 00620018 */  mult      $v1, $v0
/* 779DDC 802A114C 24040064 */  addiu     $a0, $zero, 0x64
/* 779DE0 802A1150 00031FC3 */  sra       $v1, $v1, 0x1f
/* 779DE4 802A1154 00003010 */  mfhi      $a2
/* 779DE8 802A1158 00061143 */  sra       $v0, $a2, 5
/* 779DEC 802A115C 00431023 */  subu      $v0, $v0, $v1
/* 779DF0 802A1160 0C00A67F */  jal       rand_int
/* 779DF4 802A1164 AE020000 */   sw       $v0, ($s0)
/* 779DF8 802A1168 8E030000 */  lw        $v1, ($s0)
/* 779DFC 802A116C 0062182A */  slt       $v1, $v1, $v0
/* 779E00 802A1170 54600001 */  bnel      $v1, $zero, .L802A1178
/* 779E04 802A1174 AE400084 */   sw       $zero, 0x84($s2)
.L802A1178:
/* 779E08 802A1178 8FBF001C */  lw        $ra, 0x1c($sp)
/* 779E0C 802A117C 8FB20018 */  lw        $s2, 0x18($sp)
/* 779E10 802A1180 8FB10014 */  lw        $s1, 0x14($sp)
/* 779E14 802A1184 8FB00010 */  lw        $s0, 0x10($sp)
/* 779E18 802A1188 24020002 */  addiu     $v0, $zero, 2
/* 779E1C 802A118C 03E00008 */  jr        $ra
