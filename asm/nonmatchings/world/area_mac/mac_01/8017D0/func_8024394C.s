.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024394C
/* 8041CC 8024394C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8041D0 80243950 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8041D4 80243954 0C03AE18 */  jal       partner_resume_ability_script
/* 8041D8 80243958 00000000 */   nop      
/* 8041DC 8024395C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8041E0 80243960 24020002 */  addiu     $v0, $zero, 2
/* 8041E4 80243964 03E00008 */  jr        $ra
/* 8041E8 80243968 27BD0018 */   addiu    $sp, $sp, 0x18
