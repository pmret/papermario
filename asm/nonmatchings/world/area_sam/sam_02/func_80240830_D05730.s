.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240830_D05F60
/* D05F60 80240830 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D05F64 80240834 AFBF0010 */  sw        $ra, 0x10($sp)
/* D05F68 80240838 0C03A625 */  jal       func_800E9894
/* D05F6C 8024083C 00000000 */   nop      
/* D05F70 80240840 8FBF0010 */  lw        $ra, 0x10($sp)
/* D05F74 80240844 24020002 */  addiu     $v0, $zero, 2
/* D05F78 80240848 03E00008 */  jr        $ra
/* D05F7C 8024084C 27BD0018 */   addiu    $sp, $sp, 0x18
