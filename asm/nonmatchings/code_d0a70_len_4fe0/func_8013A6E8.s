.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A6E8
/* D0DE8 8013A6E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D0DEC 8013A6EC AFBF0010 */  sw        $ra, 0x10($sp)
/* D0DF0 8013A6F0 0C04E994 */  jal       func_8013A650
/* D0DF4 8013A6F4 00000000 */   nop
/* D0DF8 8013A6F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* D0DFC 8013A6FC 03E00008 */  jr        $ra
/* D0E00 8013A700 27BD0018 */   addiu    $sp, $sp, 0x18
