.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243624_96C7E4
/* 96C7E4 80243624 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C7E8 80243628 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C7EC 8024362C 0C03AE18 */  jal       partner_resume_ability_script
/* 96C7F0 80243630 00000000 */   nop      
/* 96C7F4 80243634 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C7F8 80243638 24020002 */  addiu     $v0, $zero, 2
/* 96C7FC 8024363C 03E00008 */  jr        $ra
/* 96C800 80243640 27BD0018 */   addiu    $sp, $sp, 0x18
