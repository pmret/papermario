.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osPackRequestData
/* 03D1D0 80061DD0 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 03D1D4 80061DD4 00802821 */  addu  $a1, $a0, $zero
/* 03D1D8 80061DD8 2406000E */  addiu $a2, $zero, 0xe
/* 03D1DC 80061DDC 3C02800B */  lui   $v0, 0x800b
/* 03D1E0 80061DE0 24420F08 */  addiu $v0, $v0, 0xf08
.L80061DE4:
/* 03D1E4 80061DE4 AC400000 */  sw    $zero, ($v0)
/* 03D1E8 80061DE8 24C6FFFF */  addiu $a2, $a2, -1
/* 03D1EC 80061DEC 04C1FFFD */  bgez  $a2, .L80061DE4
/* 03D1F0 80061DF0 2442FFFC */   addiu $v0, $v0, -4
/* 03D1F4 80061DF4 3C03800B */  lui   $v1, 0x800b
/* 03D1F8 80061DF8 24630F0C */  addiu $v1, $v1, 0xf0c
/* 03D1FC 80061DFC 2467FFC4 */  addiu $a3, $v1, -0x3c
/* 03D200 80061E00 3C04800A */  lui   $a0, 0x800a
/* 03D204 80061E04 9084A606 */  lbu   $a0, -0x59fa($a0)
/* 03D208 80061E08 00003021 */  addu  $a2, $zero, $zero
/* 03D20C 80061E0C 24020001 */  addiu $v0, $zero, 1
/* 03D210 80061E10 AC620000 */  sw    $v0, ($v1)
/* 03D214 80061E14 240300FF */  addiu $v1, $zero, 0xff
/* 03D218 80061E18 24020001 */  addiu $v0, $zero, 1
/* 03D21C 80061E1C A3A20001 */  sb    $v0, 1($sp)
/* 03D220 80061E20 24020003 */  addiu $v0, $zero, 3
/* 03D224 80061E24 A3A30000 */  sb    $v1, ($sp)
/* 03D228 80061E28 A3A20002 */  sb    $v0, 2($sp)
/* 03D22C 80061E2C A3A50003 */  sb    $a1, 3($sp)
/* 03D230 80061E30 A3A30004 */  sb    $v1, 4($sp)
/* 03D234 80061E34 A3A30005 */  sb    $v1, 5($sp)
/* 03D238 80061E38 A3A30006 */  sb    $v1, 6($sp)
/* 03D23C 80061E3C 1880000F */  blez  $a0, .L80061E7C
/* 03D240 80061E40 A3A30007 */   sb    $v1, 7($sp)
.L80061E44:
/* 03D244 80061E44 8BA20000 */  lwl   $v0, ($sp)
/* 03D248 80061E48 9BA20003 */  lwr   $v0, 3($sp)
/* 03D24C 80061E4C 8BA30004 */  lwl   $v1, 4($sp)
/* 03D250 80061E50 9BA30007 */  lwr   $v1, 7($sp)
/* 03D254 80061E54 A8E20000 */  swl   $v0, ($a3)
/* 03D258 80061E58 B8E20003 */  swr   $v0, 3($a3)
/* 03D25C 80061E5C A8E30004 */  swl   $v1, 4($a3)
/* 03D260 80061E60 B8E30007 */  swr   $v1, 7($a3)
/* 03D264 80061E64 3C02800A */  lui   $v0, 0x800a
/* 03D268 80061E68 9042A606 */  lbu   $v0, -0x59fa($v0)
/* 03D26C 80061E6C 24C60001 */  addiu $a2, $a2, 1
/* 03D270 80061E70 00C2102A */  slt   $v0, $a2, $v0
/* 03D274 80061E74 1440FFF3 */  bnez  $v0, .L80061E44
/* 03D278 80061E78 24E70008 */   addiu $a3, $a3, 8
.L80061E7C:
/* 03D27C 80061E7C 240200FE */  addiu $v0, $zero, 0xfe
/* 03D280 80061E80 A0E20000 */  sb    $v0, ($a3)
/* 03D284 80061E84 03E00008 */  jr    $ra
/* 03D288 80061E88 27BD0010 */   addiu $sp, $sp, 0x10

/* 03D28C 80061E8C 00000000 */  nop   
