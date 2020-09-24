.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800457F8
/* 20BF8 800457F8 24020001 */  addiu     $v0, $zero, 1
/* 20BFC 800457FC 3C01800B */  lui       $at, 0x800b
/* 20C00 80045800 A0220F22 */  sb        $v0, 0xf22($at)
/* 20C04 80045804 03E00008 */  jr        $ra
/* 20C08 80045808 24020002 */   addiu    $v0, $zero, 2
