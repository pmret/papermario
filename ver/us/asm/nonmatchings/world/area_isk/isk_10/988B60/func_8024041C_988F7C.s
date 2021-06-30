.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_988F7C
/* 988F7C 8024041C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 988F80 80240420 AFBF0010 */  sw        $ra, 0x10($sp)
/* 988F84 80240424 8C82000C */  lw        $v0, 0xc($a0)
/* 988F88 80240428 0C0B1EAF */  jal       get_variable
/* 988F8C 8024042C 8C450000 */   lw       $a1, ($v0)
/* 988F90 80240430 0C03AC5A */  jal       switch_to_partner
/* 988F94 80240434 0040202D */   daddu    $a0, $v0, $zero
/* 988F98 80240438 8FBF0010 */  lw        $ra, 0x10($sp)
/* 988F9C 8024043C 24020002 */  addiu     $v0, $zero, 2
/* 988FA0 80240440 03E00008 */  jr        $ra
/* 988FA4 80240444 27BD0018 */   addiu    $sp, $sp, 0x18
