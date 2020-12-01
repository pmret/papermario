.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C68_E07FC8
/* E07FC8 80242C68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E07FCC 80242C6C AFBF0010 */  sw        $ra, 0x10($sp)
/* E07FD0 80242C70 8C82000C */  lw        $v0, 0xc($a0)
/* E07FD4 80242C74 0C0B1EAF */  jal       get_variable
/* E07FD8 80242C78 8C450000 */   lw       $a1, ($v0)
/* E07FDC 80242C7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* E07FE0 80242C80 3C018024 */  lui       $at, %hi(D_80245D34)
/* E07FE4 80242C84 AC225D34 */  sw        $v0, %lo(D_80245D34)($at)
/* E07FE8 80242C88 24020002 */  addiu     $v0, $zero, 2
/* E07FEC 80242C8C 03E00008 */  jr        $ra
/* E07FF0 80242C90 27BD0018 */   addiu    $sp, $sp, 0x18
