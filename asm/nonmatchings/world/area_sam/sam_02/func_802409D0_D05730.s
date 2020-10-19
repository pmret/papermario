.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409D0_D06100
/* D06100 802409D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D06104 802409D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D06108 802409D8 0C03AE18 */  jal       partner_resume_ability_script
/* D0610C 802409DC 00000000 */   nop      
/* D06110 802409E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06114 802409E4 24020002 */  addiu     $v0, $zero, 2
/* D06118 802409E8 03E00008 */  jr        $ra
/* D0611C 802409EC 27BD0018 */   addiu    $sp, $sp, 0x18
