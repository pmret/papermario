.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240850_D05F80
/* D05F80 80240850 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D05F84 80240854 AFBF0010 */  sw        $ra, 0x10($sp)
/* D05F88 80240858 0C03A631 */  jal       func_800E98C4
/* D05F8C 8024085C 00000000 */   nop      
/* D05F90 80240860 0C03A6DB */  jal       sync_status_menu
/* D05F94 80240864 00000000 */   nop      
/* D05F98 80240868 8FBF0010 */  lw        $ra, 0x10($sp)
/* D05F9C 8024086C 24020002 */  addiu     $v0, $zero, 2
/* D05FA0 80240870 03E00008 */  jr        $ra
/* D05FA4 80240874 27BD0018 */   addiu    $sp, $sp, 0x18
