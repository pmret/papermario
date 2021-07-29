.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_Chest_enable_player_input
/* 10950C 802E7C8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 109510 802E7C90 AFBF0010 */  sw        $ra, 0x10($sp)
/* 109514 802E7C94 8C820040 */  lw        $v0, 0x40($a0)
/* 109518 802E7C98 8C420010 */  lw        $v0, 0x10($v0)
/* 10951C 802E7C9C 10400003 */  beqz      $v0, .L802E7CAC
/* 109520 802E7CA0 00000000 */   nop
/* 109524 802E7CA4 0C038069 */  jal       enable_player_input
/* 109528 802E7CA8 00000000 */   nop
.L802E7CAC:
/* 10952C 802E7CAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 109530 802E7CB0 03E00008 */  jr        $ra
/* 109534 802E7CB4 27BD0018 */   addiu    $sp, $sp, 0x18
