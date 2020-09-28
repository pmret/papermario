.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_actor_shadows
/* 16CCE4 8023E404 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 16CCE8 8023E408 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 16CCEC 8023E40C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 16CCF0 8023E410 30420001 */  andi      $v0, $v0, 1
/* 16CCF4 8023E414 10400005 */  beqz      $v0, .L8023E42C
/* 16CCF8 8023E418 AFBF0010 */   sw       $ra, 0x10($sp)
/* 16CCFC 8023E41C 0C0957D7 */  jal       update_enemy_shadows
/* 16CD00 8023E420 00000000 */   nop      
/* 16CD04 8023E424 0C0957EB */  jal       update_hero_shadows
/* 16CD08 8023E428 00000000 */   nop      
.L8023E42C:
/* 16CD0C 8023E42C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 16CD10 8023E430 03E00008 */  jr        $ra
/* 16CD14 8023E434 27BD0018 */   addiu    $sp, $sp, 0x18
