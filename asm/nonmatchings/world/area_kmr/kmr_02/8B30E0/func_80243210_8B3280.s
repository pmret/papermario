.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243210_8B3280
/* 8B3280 80243210 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B3284 80243214 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B3288 80243218 0C03AE18 */  jal       partner_resume_ability_script
/* 8B328C 8024321C 00000000 */   nop      
/* 8B3290 80243220 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B3294 80243224 24020002 */  addiu     $v0, $zero, 2
/* 8B3298 80243228 03E00008 */  jr        $ra
/* 8B329C 8024322C 27BD0018 */   addiu    $sp, $sp, 0x18
