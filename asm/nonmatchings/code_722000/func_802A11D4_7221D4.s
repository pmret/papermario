.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11D4_7221D4
/* 7221D4 802A11D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7221D8 802A11D8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 7221DC 802A11DC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 7221E0 802A11E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7221E4 802A11E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7221E8 802A11E8 8462017A */  lh        $v0, 0x17a($v1)
/* 7221EC 802A11EC 8C6400D8 */  lw        $a0, 0xd8($v1)
/* 7221F0 802A11F0 00021140 */  sll       $v0, $v0, 5
/* 7221F4 802A11F4 3C108008 */  lui       $s0, %hi(gItemTable+0xC)
/* 7221F8 802A11F8 02028021 */  addu      $s0, $s0, $v0
/* 7221FC 802A11FC 861078EC */  lh        $s0, %lo(gItemTable+0xC)($s0)
/* 722200 802A1200 0C099CAB */  jal       heroes_is_ability_active
/* 722204 802A1204 2405001D */   addiu    $a1, $zero, 0x1d
/* 722208 802A1208 10400007 */  beqz      $v0, .L802A1228
/* 72220C 802A120C 00000000 */   nop
/* 722210 802A1210 1A000005 */  blez      $s0, .L802A1228
/* 722214 802A1214 00000000 */   nop
/* 722218 802A1218 3C04802A */  lui       $a0, %hi(D_802A1B40)
/* 72221C 802A121C 8C841B40 */  lw        $a0, %lo(D_802A1B40)($a0)
/* 722220 802A1220 0C05123D */  jal       free_icon
/* 722224 802A1224 00000000 */   nop
.L802A1228:
/* 722228 802A1228 8FBF0014 */  lw        $ra, 0x14($sp)
/* 72222C 802A122C 8FB00010 */  lw        $s0, 0x10($sp)
/* 722230 802A1230 24020002 */  addiu     $v0, $zero, 2
/* 722234 802A1234 03E00008 */  jr        $ra
/* 722238 802A1238 27BD0018 */   addiu    $sp, $sp, 0x18
