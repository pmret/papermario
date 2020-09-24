.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sqrtf
/* 3D2F0 80061EF0 03E00008 */  jr        $ra
/* 3D2F4 80061EF4 46006004 */   sqrt.s   $f0, $f12
/* 3D2F8 80061EF8 00000000 */  nop       
/* 3D2FC 80061EFC 00000000 */  nop       
