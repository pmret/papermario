.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_D3009C
/* D3009C 8024041C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D300A0 80240420 AFBF0010 */  sw        $ra, 0x10($sp)
/* D300A4 80240424 8C82000C */  lw        $v0, 0xc($a0)
/* D300A8 80240428 0C0B1EAF */  jal       get_variable
/* D300AC 8024042C 8C450000 */   lw       $a1, ($v0)
/* D300B0 80240430 0C03AC5A */  jal       func_800EB168
/* D300B4 80240434 0040202D */   daddu    $a0, $v0, $zero
/* D300B8 80240438 8FBF0010 */  lw        $ra, 0x10($sp)
/* D300BC 8024043C 24020002 */  addiu     $v0, $zero, 2
/* D300C0 80240440 03E00008 */  jr        $ra
/* D300C4 80240444 27BD0018 */   addiu    $sp, $sp, 0x18
