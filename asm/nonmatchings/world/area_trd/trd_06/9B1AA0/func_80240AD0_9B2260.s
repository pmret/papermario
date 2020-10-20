.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD0_9B2260
/* 9B2260 80240AD0 3C038024 */  lui       $v1, 0x8024
/* 9B2264 80240AD4 246351F0 */  addiu     $v1, $v1, 0x51f0
/* 9B2268 80240AD8 24020001 */  addiu     $v0, $zero, 1
/* 9B226C 80240ADC AC62000C */  sw        $v0, 0xc($v1)
/* 9B2270 80240AE0 24020002 */  addiu     $v0, $zero, 2
/* 9B2274 80240AE4 03E00008 */  jr        $ra
/* 9B2278 80240AE8 AC600010 */   sw       $zero, 0x10($v1)
/* 9B227C 80240AEC 00000000 */  nop       
