.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C8_A88118
/* A88118 802416C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8811C 802416CC AFBF0010 */  sw        $ra, 0x10($sp)
/* A88120 802416D0 0C03AE18 */  jal       partner_resume_ability_script
/* A88124 802416D4 00000000 */   nop      
/* A88128 802416D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8812C 802416DC 24020002 */  addiu     $v0, $zero, 2
/* A88130 802416E0 03E00008 */  jr        $ra
/* A88134 802416E4 27BD0018 */   addiu    $sp, $sp, 0x18
