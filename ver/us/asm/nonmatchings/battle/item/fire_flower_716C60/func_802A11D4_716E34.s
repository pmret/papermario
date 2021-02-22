.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11D4_716E34
/* 716E34 802A11D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 716E38 802A11D8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 716E3C 802A11DC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 716E40 802A11E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 716E44 802A11E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 716E48 802A11E8 8462017A */  lh        $v0, 0x17a($v1)
/* 716E4C 802A11EC 8C6400D8 */  lw        $a0, 0xd8($v1)
/* 716E50 802A11F0 00021140 */  sll       $v0, $v0, 5
/* 716E54 802A11F4 3C108008 */  lui       $s0, %hi(gItemTable+0xC)
/* 716E58 802A11F8 02028021 */  addu      $s0, $s0, $v0
/* 716E5C 802A11FC 861078EC */  lh        $s0, %lo(gItemTable+0xC)($s0)
/* 716E60 802A1200 0C099CAB */  jal       heroes_is_ability_active
/* 716E64 802A1204 2405001D */   addiu    $a1, $zero, 0x1d
/* 716E68 802A1208 10400007 */  beqz      $v0, .L802A1228
/* 716E6C 802A120C 00000000 */   nop
/* 716E70 802A1210 1A000005 */  blez      $s0, .L802A1228
/* 716E74 802A1214 00000000 */   nop
/* 716E78 802A1218 3C04802A */  lui       $a0, %hi(D_802A1D70)
/* 716E7C 802A121C 8C841D70 */  lw        $a0, %lo(D_802A1D70)($a0)
/* 716E80 802A1220 0C05123D */  jal       free_icon
/* 716E84 802A1224 00000000 */   nop
.L802A1228:
/* 716E88 802A1228 8FBF0014 */  lw        $ra, 0x14($sp)
/* 716E8C 802A122C 8FB00010 */  lw        $s0, 0x10($sp)
/* 716E90 802A1230 24020002 */  addiu     $v0, $zero, 2
/* 716E94 802A1234 03E00008 */  jr        $ra
/* 716E98 802A1238 27BD0018 */   addiu    $sp, $sp, 0x18
