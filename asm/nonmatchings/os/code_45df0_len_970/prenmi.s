.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel prenmi
/* 04623C 8006AE3C 8F5B0118 */  lw    $k1, 0x118($k0)
/* 046240 8006AE40 2401EFFF */  addiu $at, $zero, -0x1001
/* 046244 8006AE44 0361D824 */  and   $k1, $k1, $at
/* 046248 8006AE48 AF5B0118 */  sw    $k1, 0x118($k0)
/* 04624C 8006AE4C 3C098009 */  lui   $t1, 0x8009
/* 046250 8006AE50 252958FC */  addiu $t1, $t1, 0x58fc
/* 046254 8006AE54 8D2A0000 */  lw    $t2, ($t1)
/* 046258 8006AE58 11400004 */  beqz  $t2, .L8006AE6C
/* 04625C 8006AE5C 00000000 */   nop   
/* 046260 8006AE60 2401EFFF */  addiu $at, $zero, -0x1001
/* 046264 8006AE64 10000026 */  b     .L8006AF00
/* 046268 8006AE68 02018024 */   and   $s0, $s0, $at
