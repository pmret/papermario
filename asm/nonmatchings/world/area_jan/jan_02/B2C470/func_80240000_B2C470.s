.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B2C470
/* B2C470 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2C474 80240004 0000202D */  daddu     $a0, $zero, $zero
/* B2C478 80240008 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2C47C 8024000C 0C052AC3 */  jal       func_8014AB0C
/* B2C480 80240010 0080282D */   daddu    $a1, $a0, $zero
/* B2C484 80240014 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2C488 80240018 24020002 */  addiu     $v0, $zero, 2
/* B2C48C 8024001C 03E00008 */  jr        $ra
/* B2C490 80240020 27BD0018 */   addiu    $sp, $sp, 0x18
/* B2C494 80240024 00000000 */  nop       
/* B2C498 80240028 00000000 */  nop       
/* B2C49C 8024002C 00000000 */  nop       
