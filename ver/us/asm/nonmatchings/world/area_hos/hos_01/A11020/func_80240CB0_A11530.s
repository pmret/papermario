.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CB0_A11530
/* A11530 80240CB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A11534 80240CB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A11538 80240CB8 8C82000C */  lw        $v0, 0xc($a0)
/* A1153C 80240CBC 0C0B1EAF */  jal       get_variable
/* A11540 80240CC0 8C450000 */   lw       $a1, ($v0)
/* A11544 80240CC4 0C03AC5A */  jal       switch_to_partner
/* A11548 80240CC8 0040202D */   daddu    $a0, $v0, $zero
/* A1154C 80240CCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A11550 80240CD0 24020002 */  addiu     $v0, $zero, 2
/* A11554 80240CD4 03E00008 */  jr        $ra
/* A11558 80240CD8 27BD0018 */   addiu    $sp, $sp, 0x18
