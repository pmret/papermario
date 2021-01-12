.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11D4_71E824
/* 71E824 802A11D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 71E828 802A11D8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 71E82C 802A11DC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 71E830 802A11E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 71E834 802A11E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 71E838 802A11E8 8462017A */  lh        $v0, 0x17a($v1)
/* 71E83C 802A11EC 8C6400D8 */  lw        $a0, 0xd8($v1)
/* 71E840 802A11F0 00021140 */  sll       $v0, $v0, 5
/* 71E844 802A11F4 3C108008 */  lui       $s0, %hi(gItemTable+0xC)
/* 71E848 802A11F8 02028021 */  addu      $s0, $s0, $v0
/* 71E84C 802A11FC 861078EC */  lh        $s0, %lo(gItemTable+0xC)($s0)
/* 71E850 802A1200 0C099CAB */  jal       heroes_is_ability_active
/* 71E854 802A1204 2405001D */   addiu    $a1, $zero, 0x1d
/* 71E858 802A1208 10400007 */  beqz      $v0, .L802A1228
/* 71E85C 802A120C 00000000 */   nop      
/* 71E860 802A1210 1A000005 */  blez      $s0, .L802A1228
/* 71E864 802A1214 00000000 */   nop      
/* 71E868 802A1218 3C04802A */  lui       $a0, %hi(D_802A3F50)
/* 71E86C 802A121C 8C843F50 */  lw        $a0, %lo(D_802A3F50)($a0)
/* 71E870 802A1220 0C05123D */  jal       free_icon
/* 71E874 802A1224 00000000 */   nop      
.L802A1228:
/* 71E878 802A1228 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71E87C 802A122C 8FB00010 */  lw        $s0, 0x10($sp)
/* 71E880 802A1230 24020002 */  addiu     $v0, $zero, 2
/* 71E884 802A1234 03E00008 */  jr        $ra
/* 71E888 802A1238 27BD0018 */   addiu    $sp, $sp, 0x18
