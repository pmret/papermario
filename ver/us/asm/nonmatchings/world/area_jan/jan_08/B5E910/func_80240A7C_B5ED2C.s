.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A7C_B5ED2C
/* B5ED2C 80240A7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B5ED30 80240A80 AFBF0010 */  sw        $ra, 0x10($sp)
/* B5ED34 80240A84 8C82000C */  lw        $v0, 0xc($a0)
/* B5ED38 80240A88 0C0B1EAF */  jal       get_variable
/* B5ED3C 80240A8C 8C450000 */   lw       $a1, ($v0)
/* B5ED40 80240A90 0C03AC5A */  jal       switch_to_partner
/* B5ED44 80240A94 0040202D */   daddu    $a0, $v0, $zero
/* B5ED48 80240A98 8FBF0010 */  lw        $ra, 0x10($sp)
/* B5ED4C 80240A9C 24020002 */  addiu     $v0, $zero, 2
/* B5ED50 80240AA0 03E00008 */  jr        $ra
/* B5ED54 80240AA4 27BD0018 */   addiu    $sp, $sp, 0x18
