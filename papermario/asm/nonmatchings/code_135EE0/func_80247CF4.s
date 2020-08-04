.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247CF4
/* 13B034 80247CF4 004A1021 */  addu  $v0, $v0, $t2
/* 13B038 80247CF8 08091F4B */  j     func_80247D2C
/* 13B03C 80247CFC 8C450004 */   lw    $a1, 4($v0)

.L80247D00:
/* 13B040 80247D00 00131400 */  sll   $v0, $s3, 0x10
.L80247D04:
/* 13B044 80247D04 000212C3 */  sra   $v0, $v0, 0xb
/* 13B048 80247D08 3C0B8008 */  lui   $t3, 0x8008
/* 13B04C 80247D0C 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13B050 80247D10 004B1021 */  addu  $v0, $v0, $t3
/* 13B054 80247D14 84420004 */  lh    $v0, 4($v0)
/* 13B058 80247D18 3C0A8009 */  lui   $t2, 0x8009
/* 13B05C 80247D1C 254AA680 */  addiu $t2, $t2, -0x5980
/* 13B060 80247D20 000210C0 */  sll   $v0, $v0, 3
/* 13B064 80247D24 004A1021 */  addu  $v0, $v0, $t2
/* 13B068 80247D28 8C450000 */  lw    $a1, ($v0)
