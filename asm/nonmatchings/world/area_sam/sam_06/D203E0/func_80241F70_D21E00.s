.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F70_D21E00
/* D21E00 80241F70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21E04 80241F74 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21E08 80241F78 0C03A631 */  jal       func_800E98C4
/* D21E0C 80241F7C 00000000 */   nop      
/* D21E10 80241F80 0C03A6DB */  jal       sync_status_menu
/* D21E14 80241F84 00000000 */   nop      
/* D21E18 80241F88 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21E1C 80241F8C 24020002 */  addiu     $v0, $zero, 2
/* D21E20 80241F90 03E00008 */  jr        $ra
/* D21E24 80241F94 27BD0018 */   addiu    $sp, $sp, 0x18
