.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E60C
/* 17CEEC 8024E60C 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17CEF0 8024E610 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17CEF4 8024E614 03E00008 */  jr        $ra
/* 17CEF8 8024E618 00000000 */   nop      
