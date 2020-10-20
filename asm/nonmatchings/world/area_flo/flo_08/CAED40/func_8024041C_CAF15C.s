.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_CAF15C
/* CAF15C 8024041C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CAF160 80240420 AFBF0010 */  sw        $ra, 0x10($sp)
/* CAF164 80240424 8C82000C */  lw        $v0, 0xc($a0)
/* CAF168 80240428 0C0B1EAF */  jal       get_variable
/* CAF16C 8024042C 8C450000 */   lw       $a1, ($v0)
/* CAF170 80240430 0C03AC5A */  jal       func_800EB168
/* CAF174 80240434 0040202D */   daddu    $a0, $v0, $zero
/* CAF178 80240438 8FBF0010 */  lw        $ra, 0x10($sp)
/* CAF17C 8024043C 24020002 */  addiu     $v0, $zero, 2
/* CAF180 80240440 03E00008 */  jr        $ra
/* CAF184 80240444 27BD0018 */   addiu    $sp, $sp, 0x18
