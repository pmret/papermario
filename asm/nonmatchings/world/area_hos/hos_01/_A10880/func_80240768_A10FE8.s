.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240768_A10FE8
/* A10FE8 80240768 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A10FEC 8024076C AFBF0010 */  sw        $ra, 0x10($sp)
/* A10FF0 80240770 8C82000C */  lw        $v0, 0xc($a0)
/* A10FF4 80240774 3C068016 */  lui       $a2, 0x8016
/* A10FF8 80240778 84C6A552 */  lh        $a2, -0x5aae($a2)
/* A10FFC 8024077C 0C0B2026 */  jal       set_variable
/* A11000 80240780 8C450000 */   lw       $a1, ($v0)
/* A11004 80240784 8FBF0010 */  lw        $ra, 0x10($sp)
/* A11008 80240788 24020002 */  addiu     $v0, $zero, 2
/* A1100C 8024078C 03E00008 */  jr        $ra
/* A11010 80240790 27BD0018 */   addiu    $sp, $sp, 0x18
/* A11014 80240794 00000000 */  nop       
/* A11018 80240798 00000000 */  nop       
/* A1101C 8024079C 00000000 */  nop       
