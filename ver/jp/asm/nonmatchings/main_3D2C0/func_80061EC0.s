.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061EC0
/* 3D2C0 80061EC0 03E00008 */  jr        $ra
/* 3D2C4 80061EC4 46006004 */   sqrt.s   $f0, $f12
/* 3D2C8 80061EC8 00000000 */  nop
/* 3D2CC 80061ECC 00000000 */  nop
