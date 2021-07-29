.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024034C_C6847C
/* C6847C 8024034C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C68480 80240350 AFBF0010 */  sw        $ra, 0x10($sp)
/* C68484 80240354 8C82000C */  lw        $v0, 0xc($a0)
/* C68488 80240358 0C0B1EAF */  jal       get_variable
/* C6848C 8024035C 8C450000 */   lw       $a1, ($v0)
/* C68490 80240360 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* C68494 80240364 0040202D */   daddu    $a0, $v0, $zero
/* C68498 80240368 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6849C 8024036C 24020002 */  addiu     $v0, $zero, 2
/* C684A0 80240370 03E00008 */  jr        $ra
/* C684A4 80240374 27BD0018 */   addiu    $sp, $sp, 0x18
