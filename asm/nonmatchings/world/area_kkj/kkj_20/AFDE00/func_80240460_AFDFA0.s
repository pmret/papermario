.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240460_AFDFA0
/* AFDFA0 80240460 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFDFA4 80240464 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFDFA8 80240468 0C03AE18 */  jal       partner_resume_ability_script
/* AFDFAC 8024046C 00000000 */   nop      
/* AFDFB0 80240470 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFDFB4 80240474 24020002 */  addiu     $v0, $zero, 2
/* AFDFB8 80240478 03E00008 */  jr        $ra
/* AFDFBC 8024047C 27BD0018 */   addiu    $sp, $sp, 0x18
