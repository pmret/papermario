.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A68_C96998
/* C96998 80240A68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9699C 80240A6C 0000202D */  daddu     $a0, $zero, $zero
/* C969A0 80240A70 AFBF0010 */  sw        $ra, 0x10($sp)
/* C969A4 80240A74 0C015586 */  jal       func_80055618
/* C969A8 80240A78 24050001 */   addiu    $a1, $zero, 1
/* C969AC 80240A7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C969B0 80240A80 24020002 */  addiu     $v0, $zero, 2
/* C969B4 80240A84 03E00008 */  jr        $ra
/* C969B8 80240A88 27BD0018 */   addiu    $sp, $sp, 0x18
