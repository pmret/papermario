.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242348
/* A1D448 80242348 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D44C 8024234C AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D450 80242350 0C03AE18 */  jal       partner_resume_ability_script
/* A1D454 80242354 00000000 */   nop      
/* A1D458 80242358 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D45C 8024235C 24020002 */  addiu     $v0, $zero, 2
/* A1D460 80242360 03E00008 */  jr        $ra
/* A1D464 80242364 27BD0018 */   addiu    $sp, $sp, 0x18
