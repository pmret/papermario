.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241440
/* 8ED260 80241440 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED264 80241444 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED268 80241448 0C03AE18 */  jal       partner_resume_ability_script
/* 8ED26C 8024144C 00000000 */   nop      
/* 8ED270 80241450 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED274 80241454 24020002 */  addiu     $v0, $zero, 2
/* 8ED278 80241458 03E00008 */  jr        $ra
/* 8ED27C 8024145C 27BD0018 */   addiu    $sp, $sp, 0x18
