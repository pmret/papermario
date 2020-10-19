.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024240C_C3893C
/* C3893C 8024240C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C38940 80242410 AFBF0010 */  sw        $ra, 0x10($sp)
/* C38944 80242414 8C82000C */  lw        $v0, 0xc($a0)
/* C38948 80242418 0C0B1EAF */  jal       get_variable
/* C3894C 8024241C 8C450000 */   lw       $a1, ($v0)
/* C38950 80242420 0C0B95A4 */  jal       func_802E5690
/* C38954 80242424 0040202D */   daddu    $a0, $v0, $zero
/* C38958 80242428 8FBF0010 */  lw        $ra, 0x10($sp)
/* C3895C 8024242C 24020002 */  addiu     $v0, $zero, 2
/* C38960 80242430 03E00008 */  jr        $ra
/* C38964 80242434 27BD0018 */   addiu    $sp, $sp, 0x18
