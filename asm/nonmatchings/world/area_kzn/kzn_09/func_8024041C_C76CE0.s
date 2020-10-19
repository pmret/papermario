.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_C770FC
/* C770FC 8024041C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C77100 80240420 AFBF0010 */  sw        $ra, 0x10($sp)
/* C77104 80240424 8C82000C */  lw        $v0, 0xc($a0)
/* C77108 80240428 0C0B1EAF */  jal       get_variable
/* C7710C 8024042C 8C450000 */   lw       $a1, ($v0)
/* C77110 80240430 0C03AC5A */  jal       func_800EB168
/* C77114 80240434 0040202D */   daddu    $a0, $v0, $zero
/* C77118 80240438 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7711C 8024043C 24020002 */  addiu     $v0, $zero, 2
/* C77120 80240440 03E00008 */  jr        $ra
/* C77124 80240444 27BD0018 */   addiu    $sp, $sp, 0x18
