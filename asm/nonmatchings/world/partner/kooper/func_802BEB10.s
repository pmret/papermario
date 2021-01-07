.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BEB10
/* 31CB30 802BEB10 3C02802C */  lui       $v0, %hi(D_802BEC54)
/* 31CB34 802BEB14 8C42EC54 */  lw        $v0, %lo(D_802BEC54)($v0)
/* 31CB38 802BEB18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31CB3C 802BEB1C 10400005 */  beqz      $v0, .L802BEB34
/* 31CB40 802BEB20 AFBF0010 */   sw       $ra, 0x10($sp)
/* 31CB44 802BEB24 0C03BD17 */  jal       clear_partner_move_history
/* 31CB48 802BEB28 00000000 */   nop      
/* 31CB4C 802BEB2C 0C03ACC5 */  jal       partner_use_ability
/* 31CB50 802BEB30 00000000 */   nop      
.L802BEB34:
/* 31CB54 802BEB34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31CB58 802BEB38 03E00008 */  jr        $ra
/* 31CB5C 802BEB3C 27BD0018 */   addiu    $sp, $sp, 0x18
