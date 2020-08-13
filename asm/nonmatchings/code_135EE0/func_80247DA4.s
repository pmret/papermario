.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247DA4
/* 13B0E4 80247DA4 8FAA0058 */  lw    $t2, 0x58($sp)
/* 13B0E8 80247DA8 254A0001 */  addiu $t2, $t2, 1
/* 13B0EC 80247DAC AFAA0058 */  sw    $t2, 0x58($sp)
.L80247DB0:
/* 13B0F0 80247DB0 8FAB0054 */  lw    $t3, 0x54($sp)
/* 13B0F4 80247DB4 24020002 */  addiu $v0, $zero, 2
/* 13B0F8 80247DB8 156200E3 */  bne   $t3, $v0, .L80248148
/* 13B0FC 80247DBC 00000000 */   nop   
/* 13B100 80247DC0 8FAA0088 */  lw    $t2, 0x88($sp)
/* 13B104 80247DC4 154000E0 */  bnez  $t2, .L80248148
/* 13B108 80247DC8 00131400 */   sll   $v0, $s3, 0x10
/* 13B10C 80247DCC 000212C3 */  sra   $v0, $v0, 0xb
/* 13B110 80247DD0 3C0B8008 */  lui   $t3, 0x8008
/* 13B114 80247DD4 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13B118 80247DD8 004B1021 */  addu  $v0, $v0, $t3
/* 13B11C 80247DDC 9043001A */  lbu   $v1, 0x1a($v0)
/* 13B120 80247DE0 3C0A8009 */  lui   $t2, 0x8009
/* 13B124 80247DE4 254AF060 */  addiu $t2, $t2, -0xfa0
/* 13B128 80247DE8 00031080 */  sll   $v0, $v1, 2
/* 13B12C 80247DEC 00431021 */  addu  $v0, $v0, $v1
/* 13B130 80247DF0 00021080 */  sll   $v0, $v0, 2
/* 13B134 80247DF4 004A1021 */  addu  $v0, $v0, $t2
/* 13B138 80247DF8 80530012 */  lb    $s3, 0x12($v0)
/* 13B13C 80247DFC 2A62000B */  slti  $v0, $s3, 0xb
/* 13B140 80247E00 10400002 */  beqz  $v0, .L80247E0C
/* 13B144 80247E04 24150001 */   addiu $s5, $zero, 1
/* 13B148 80247E08 24150004 */  addiu $s5, $zero, 4
.L80247E0C:
/* 13B14C 80247E0C 3C04E300 */  lui   $a0, 0xe300
/* 13B150 80247E10 34841201 */  ori   $a0, $a0, 0x1201
/* 13B154 80247E14 3C05800A */  lui   $a1, 0x800a
/* 13B158 80247E18 8CA5A66C */  lw    $a1, -0x5994($a1)
/* 13B15C 80247E1C 3C02DE00 */  lui   $v0, 0xde00
/* 13B160 80247E20 00A0182D */  daddu $v1, $a1, $zero
/* 13B164 80247E24 24A50008 */  addiu $a1, $a1, 8
/* 13B168 80247E28 AC620000 */  sw    $v0, ($v1)
/* 13B16C 80247E2C 3C028027 */  lui   $v0, 0x8027
