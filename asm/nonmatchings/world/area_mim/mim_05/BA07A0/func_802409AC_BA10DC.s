.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409AC_BA10DC
/* BA10DC 802409AC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BA10E0 802409B0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA10E4 802409B4 0080982D */  daddu     $s3, $a0, $zero
/* BA10E8 802409B8 AFBF0040 */  sw        $ra, 0x40($sp)
/* BA10EC 802409BC AFB20038 */  sw        $s2, 0x38($sp)
/* BA10F0 802409C0 AFB10034 */  sw        $s1, 0x34($sp)
/* BA10F4 802409C4 AFB00030 */  sw        $s0, 0x30($sp)
/* BA10F8 802409C8 8E720148 */  lw        $s2, 0x148($s3)
/* BA10FC 802409CC 00A0882D */  daddu     $s1, $a1, $zero
/* BA1100 802409D0 86440008 */  lh        $a0, 8($s2)
/* BA1104 802409D4 0C00EABB */  jal       get_npc_unsafe
/* BA1108 802409D8 00C0802D */   daddu    $s0, $a2, $zero
/* BA110C 802409DC 0200202D */  daddu     $a0, $s0, $zero
/* BA1110 802409E0 0240282D */  daddu     $a1, $s2, $zero
/* BA1114 802409E4 AFA00010 */  sw        $zero, 0x10($sp)
/* BA1118 802409E8 8E26000C */  lw        $a2, 0xc($s1)
/* BA111C 802409EC 8E270010 */  lw        $a3, 0x10($s1)
/* BA1120 802409F0 0C01242D */  jal       func_800490B4
/* BA1124 802409F4 0040882D */   daddu    $s1, $v0, $zero
/* BA1128 802409F8 10400024 */  beqz      $v0, .L80240A8C
/* BA112C 802409FC 0220202D */   daddu    $a0, $s1, $zero
/* BA1130 80240A00 24050322 */  addiu     $a1, $zero, 0x322
/* BA1134 80240A04 0C012530 */  jal       func_800494C0
/* BA1138 80240A08 0000302D */   daddu    $a2, $zero, $zero
/* BA113C 80240A0C 0000202D */  daddu     $a0, $zero, $zero
/* BA1140 80240A10 0220282D */  daddu     $a1, $s1, $zero
/* BA1144 80240A14 0000302D */  daddu     $a2, $zero, $zero
/* BA1148 80240A18 2410000A */  addiu     $s0, $zero, 0xa
/* BA114C 80240A1C 862300A8 */  lh        $v1, 0xa8($s1)
/* BA1150 80240A20 3C013F80 */  lui       $at, 0x3f80
/* BA1154 80240A24 44810000 */  mtc1      $at, $f0
/* BA1158 80240A28 3C014000 */  lui       $at, 0x4000
/* BA115C 80240A2C 44811000 */  mtc1      $at, $f2
/* BA1160 80240A30 3C01C1A0 */  lui       $at, 0xc1a0
/* BA1164 80240A34 44812000 */  mtc1      $at, $f4
/* BA1168 80240A38 44833000 */  mtc1      $v1, $f6
/* BA116C 80240A3C 00000000 */  nop       
/* BA1170 80240A40 468031A0 */  cvt.s.w   $f6, $f6
/* BA1174 80240A44 44073000 */  mfc1      $a3, $f6
/* BA1178 80240A48 27A20028 */  addiu     $v0, $sp, 0x28
/* BA117C 80240A4C AFB0001C */  sw        $s0, 0x1c($sp)
/* BA1180 80240A50 AFA20020 */  sw        $v0, 0x20($sp)
/* BA1184 80240A54 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA1188 80240A58 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA118C 80240A5C 0C01BFA4 */  jal       fx_emote
/* BA1190 80240A60 E7A40018 */   swc1     $f4, 0x18($sp)
/* BA1194 80240A64 0220202D */  daddu     $a0, $s1, $zero
/* BA1198 80240A68 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BA119C 80240A6C 0C012530 */  jal       func_800494C0
/* BA11A0 80240A70 3C060020 */   lui      $a2, 0x20
/* BA11A4 80240A74 8E4200CC */  lw        $v0, 0xcc($s2)
/* BA11A8 80240A78 8C420020 */  lw        $v0, 0x20($v0)
/* BA11AC 80240A7C AE220028 */  sw        $v0, 0x28($s1)
/* BA11B0 80240A80 9642008E */  lhu       $v0, 0x8e($s2)
/* BA11B4 80240A84 A622008E */  sh        $v0, 0x8e($s1)
/* BA11B8 80240A88 AE700070 */  sw        $s0, 0x70($s3)
.L80240A8C:
/* BA11BC 80240A8C 8FBF0040 */  lw        $ra, 0x40($sp)
/* BA11C0 80240A90 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA11C4 80240A94 8FB20038 */  lw        $s2, 0x38($sp)
/* BA11C8 80240A98 8FB10034 */  lw        $s1, 0x34($sp)
/* BA11CC 80240A9C 8FB00030 */  lw        $s0, 0x30($sp)
/* BA11D0 80240AA0 03E00008 */  jr        $ra
/* BA11D4 80240AA4 27BD0048 */   addiu    $sp, $sp, 0x48
