.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024031C_879EFC
/* 879EFC 8024031C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 879F00 80240320 AFBF0010 */  sw        $ra, 0x10($sp)
/* 879F04 80240324 8C82000C */  lw        $v0, 0xc($a0)
/* 879F08 80240328 0C0B1EAF */  jal       evt_get_variable
/* 879F0C 8024032C 8C450000 */   lw       $a1, ($v0)
/* 879F10 80240330 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* 879F14 80240334 0040202D */   daddu    $a0, $v0, $zero
/* 879F18 80240338 8FBF0010 */  lw        $ra, 0x10($sp)
/* 879F1C 8024033C 24020002 */  addiu     $v0, $zero, 2
/* 879F20 80240340 03E00008 */  jr        $ra
/* 879F24 80240344 27BD0018 */   addiu    $sp, $sp, 0x18
