.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055FD4
/* 313D4 80055FD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 313D8 80055FD8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 313DC 80055FDC 0C0157D6 */  jal       func_80055F58
/* 313E0 80055FE0 0000302D */   daddu    $a2, $zero, $zero
/* 313E4 80055FE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 313E8 80055FE8 03E00008 */  jr        $ra
/* 313EC 80055FEC 27BD0018 */   addiu    $sp, $sp, 0x18
