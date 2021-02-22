.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000
/* 415D90 802A1000 240200FF */  addiu     $v0, $zero, 0xff
/* 415D94 802A1004 3C01802B */  lui       $at, %hi(D_802AD006)
/* 415D98 802A1008 A422D006 */  sh        $v0, %lo(D_802AD006)($at)
/* 415D9C 802A100C 3C01802B */  lui       $at, %hi(D_802AD008)
/* 415DA0 802A1010 A422D008 */  sh        $v0, %lo(D_802AD008)($at)
/* 415DA4 802A1014 2402FFFF */  addiu     $v0, $zero, -1
/* 415DA8 802A1018 3C01802B */  lui       $at, %hi(D_802AD000)
/* 415DAC 802A101C A020D000 */  sb        $zero, %lo(D_802AD000)($at)
/* 415DB0 802A1020 3C01802B */  lui       $at, %hi(D_802AD068)
/* 415DB4 802A1024 A022D068 */  sb        $v0, %lo(D_802AD068)($at)
/* 415DB8 802A1028 03E00008 */  jr        $ra
/* 415DBC 802A102C 00000000 */   nop
