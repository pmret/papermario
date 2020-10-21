.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242710_8B2780
/* 8B2780 80242710 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 8B2784 80242714 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 8B2788 80242718 80430002 */  lb        $v1, 2($v0)
/* 8B278C 8024271C 80420003 */  lb        $v0, 3($v0)
/* 8B2790 80242720 00621826 */  xor       $v1, $v1, $v0
/* 8B2794 80242724 2C630001 */  sltiu     $v1, $v1, 1
/* 8B2798 80242728 24020002 */  addiu     $v0, $zero, 2
/* 8B279C 8024272C 03E00008 */  jr        $ra
/* 8B27A0 80242730 AC830084 */   sw       $v1, 0x84($a0)
