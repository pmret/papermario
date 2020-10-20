.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241650_B36220
/* B36220 80241650 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36224 80241654 AFBF0010 */  sw        $ra, 0x10($sp)
/* B36228 80241658 0C03AE18 */  jal       partner_resume_ability_script
/* B3622C 8024165C 00000000 */   nop      
/* B36230 80241660 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36234 80241664 24020002 */  addiu     $v0, $zero, 2
/* B36238 80241668 03E00008 */  jr        $ra
/* B3623C 8024166C 27BD0018 */   addiu    $sp, $sp, 0x18
