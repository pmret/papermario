.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel firstnmi
.L8006AE6C:
/* 04626C 8006AE6C 240A0001 */  addiu $t2, $zero, 1
/* 046270 8006AE70 AD2A0000 */  sw    $t2, ($t1)
/* 046274 8006AE74 0C01ABDF */  jal   send_mesg
/* 046278 8006AE78 24040070 */   addiu $a0, $zero, 0x70
/* 04627C 8006AE7C 2401EFFF */  addiu $at, $zero, -0x1001
/* 046280 8006AE80 02018024 */  and   $s0, $s0, $at
/* 046284 8006AE84 3C0A8009 */  lui   $t2, 0x8009
/* 046288 8006AE88 8D4A4658 */  lw    $t2, 0x4658($t2)
/* 04628C 8006AE8C 8D5B0118 */  lw    $k1, 0x118($t2)
/* 046290 8006AE90 2401EFFF */  addiu $at, $zero, -0x1001
/* 046294 8006AE94 0361D824 */  and   $k1, $k1, $at
/* 046298 8006AE98 10000019 */  b     .L8006AF00
/* 04629C 8006AE9C AD5B0118 */   sw    $k1, 0x118($t2)
