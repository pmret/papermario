.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C0C
/* 9C5FEC 80240C0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C5FF0 80240C10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C5FF4 80240C14 0C03AE18 */  jal       partner_resume_ability_script
/* 9C5FF8 80240C18 00000000 */   nop      
/* 9C5FFC 80240C1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6000 80240C20 24020002 */  addiu     $v0, $zero, 2
/* 9C6004 80240C24 03E00008 */  jr        $ra
/* 9C6008 80240C28 27BD0018 */   addiu    $sp, $sp, 0x18
