.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F48
/* B36B18 80241F48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36B1C 80241F4C AFBF0010 */  sw        $ra, 0x10($sp)
/* B36B20 80241F50 0C00EABB */  jal       get_npc_unsafe
/* B36B24 80241F54 8C84014C */   lw       $a0, 0x14c($a0)
/* B36B28 80241F58 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36B2C 80241F5C 0000102D */  daddu     $v0, $zero, $zero
/* B36B30 80241F60 03E00008 */  jr        $ra
/* B36B34 80241F64 27BD0018 */   addiu    $sp, $sp, 0x18
