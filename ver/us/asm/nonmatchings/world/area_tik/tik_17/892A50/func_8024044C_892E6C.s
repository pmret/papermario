.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024044C_892E6C
/* 892E6C 8024044C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 892E70 80240450 AFBF0010 */  sw        $ra, 0x10($sp)
/* 892E74 80240454 8C82000C */  lw        $v0, 0xc($a0)
/* 892E78 80240458 0C0B1EAF */  jal       get_variable
/* 892E7C 8024045C 8C450000 */   lw       $a1, ($v0)
/* 892E80 80240460 0C03AC5A */  jal       switch_to_partner
/* 892E84 80240464 0040202D */   daddu    $a0, $v0, $zero
/* 892E88 80240468 8FBF0010 */  lw        $ra, 0x10($sp)
/* 892E8C 8024046C 24020002 */  addiu     $v0, $zero, 2
/* 892E90 80240470 03E00008 */  jr        $ra
/* 892E94 80240474 27BD0018 */   addiu    $sp, $sp, 0x18
