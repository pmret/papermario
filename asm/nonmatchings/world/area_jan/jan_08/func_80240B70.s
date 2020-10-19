.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B70
/* B5EE20 80240B70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B5EE24 80240B74 AFBF0010 */  sw        $ra, 0x10($sp)
/* B5EE28 80240B78 8C82000C */  lw        $v0, 0xc($a0)
/* B5EE2C 80240B7C 0C0B1EAF */  jal       get_variable
/* B5EE30 80240B80 8C450000 */   lw       $a1, ($v0)
/* B5EE34 80240B84 0040202D */  daddu     $a0, $v0, $zero
/* B5EE38 80240B88 8C830000 */  lw        $v1, ($a0)
/* B5EE3C 80240B8C 34630010 */  ori       $v1, $v1, 0x10
/* B5EE40 80240B90 AC830000 */  sw        $v1, ($a0)
/* B5EE44 80240B94 8FBF0010 */  lw        $ra, 0x10($sp)
/* B5EE48 80240B98 24020002 */  addiu     $v0, $zero, 2
/* B5EE4C 80240B9C 03E00008 */  jr        $ra
/* B5EE50 80240BA0 27BD0018 */   addiu    $sp, $sp, 0x18
