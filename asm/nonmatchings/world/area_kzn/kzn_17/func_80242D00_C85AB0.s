.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D00_C887B0
/* C887B0 80242D00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C887B4 80242D04 AFBF0010 */  sw        $ra, 0x10($sp)
/* C887B8 80242D08 0C03A8CD */  jal       subtract_hp
/* C887BC 80242D0C 24040001 */   addiu    $a0, $zero, 1
/* C887C0 80242D10 8FBF0010 */  lw        $ra, 0x10($sp)
/* C887C4 80242D14 24020002 */  addiu     $v0, $zero, 2
/* C887C8 80242D18 03E00008 */  jr        $ra
/* C887CC 80242D1C 27BD0018 */   addiu    $sp, $sp, 0x18
