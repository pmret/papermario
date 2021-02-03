.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A113C_7379CC
/* 7379CC 802A113C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7379D0 802A1140 AFB00010 */  sw        $s0, 0x10($sp)
/* 7379D4 802A1144 0080802D */  daddu     $s0, $a0, $zero
/* 7379D8 802A1148 24040016 */  addiu     $a0, $zero, 0x16
/* 7379DC 802A114C AFBF0014 */  sw        $ra, 0x14($sp)
/* 7379E0 802A1150 0C03A752 */  jal       is_ability_active
/* 7379E4 802A1154 AE000084 */   sw       $zero, 0x84($s0)
/* 7379E8 802A1158 10400002 */  beqz      $v0, .L802A1164
/* 7379EC 802A115C 24020001 */   addiu    $v0, $zero, 1
/* 7379F0 802A1160 AE020084 */  sw        $v0, 0x84($s0)
.L802A1164:
/* 7379F4 802A1164 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 7379F8 802A1168 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 7379FC 802A116C 30421000 */  andi      $v0, $v0, 0x1000
/* 737A00 802A1170 10400002 */  beqz      $v0, .L802A117C
/* 737A04 802A1174 24020001 */   addiu    $v0, $zero, 1
/* 737A08 802A1178 AE020084 */  sw        $v0, 0x84($s0)
.L802A117C:
/* 737A0C 802A117C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 737A10 802A1180 8FB00010 */  lw        $s0, 0x10($sp)
/* 737A14 802A1184 24020002 */  addiu     $v0, $zero, 2
/* 737A18 802A1188 03E00008 */  jr        $ra
/* 737A1C 802A118C 27BD0018 */   addiu    $sp, $sp, 0x18
