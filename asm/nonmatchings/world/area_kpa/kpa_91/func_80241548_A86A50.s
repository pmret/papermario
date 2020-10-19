.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241548_A87F98
/* A87F98 80241548 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A87F9C 8024154C AFBF0010 */  sw        $ra, 0x10($sp)
/* A87FA0 80241550 0C03A631 */  jal       func_800E98C4
/* A87FA4 80241554 00000000 */   nop      
/* A87FA8 80241558 0C03A6DB */  jal       sync_status_menu
/* A87FAC 8024155C 00000000 */   nop      
/* A87FB0 80241560 8FBF0010 */  lw        $ra, 0x10($sp)
/* A87FB4 80241564 24020002 */  addiu     $v0, $zero, 2
/* A87FB8 80241568 03E00008 */  jr        $ra
/* A87FBC 8024156C 27BD0018 */   addiu    $sp, $sp, 0x18
