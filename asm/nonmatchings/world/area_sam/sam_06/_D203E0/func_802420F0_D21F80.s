.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802420F0_D21F80
/* D21F80 802420F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21F84 802420F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21F88 802420F8 0C03AE18 */  jal       partner_resume_ability_script
/* D21F8C 802420FC 00000000 */   nop      
/* D21F90 80242100 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21F94 80242104 24020002 */  addiu     $v0, $zero, 2
/* D21F98 80242108 03E00008 */  jr        $ra
/* D21F9C 8024210C 27BD0018 */   addiu    $sp, $sp, 0x18
