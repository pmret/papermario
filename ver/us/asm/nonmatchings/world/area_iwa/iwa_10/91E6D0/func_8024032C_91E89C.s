.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024032C_91E89C
/* 91E89C 8024032C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91E8A0 80240330 AFBF0010 */  sw        $ra, 0x10($sp)
/* 91E8A4 80240334 8C82000C */  lw        $v0, 0xc($a0)
/* 91E8A8 80240338 0C0B1EAF */  jal       get_variable
/* 91E8AC 8024033C 8C450000 */   lw       $a1, ($v0)
/* 91E8B0 80240340 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* 91E8B4 80240344 0040202D */   daddu    $a0, $v0, $zero
/* 91E8B8 80240348 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91E8BC 8024034C 24020002 */  addiu     $v0, $zero, 2
/* 91E8C0 80240350 03E00008 */  jr        $ra
/* 91E8C4 80240354 27BD0018 */   addiu    $sp, $sp, 0x18
