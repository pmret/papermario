.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F50
/* D21DE0 80241F50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21DE4 80241F54 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21DE8 80241F58 0C03A625 */  jal       func_800E9894
/* D21DEC 80241F5C 00000000 */   nop      
/* D21DF0 80241F60 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21DF4 80241F64 24020002 */  addiu     $v0, $zero, 2
/* D21DF8 80241F68 03E00008 */  jr        $ra
/* D21DFC 80241F6C 27BD0018 */   addiu    $sp, $sp, 0x18
