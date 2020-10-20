.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241628_A8E0A8
/* A8E0A8 80241628 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E0AC 8024162C AFBF0010 */  sw        $ra, 0x10($sp)
/* A8E0B0 80241630 0C03A631 */  jal       func_800E98C4
/* A8E0B4 80241634 00000000 */   nop      
/* A8E0B8 80241638 0C03A6DB */  jal       sync_status_menu
/* A8E0BC 8024163C 00000000 */   nop      
/* A8E0C0 80241640 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E0C4 80241644 24020002 */  addiu     $v0, $zero, 2
/* A8E0C8 80241648 03E00008 */  jr        $ra
/* A8E0CC 8024164C 27BD0018 */   addiu    $sp, $sp, 0x18
