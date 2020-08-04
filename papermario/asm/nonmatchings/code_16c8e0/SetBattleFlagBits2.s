.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetBattleFlagBits2
/* 19B6AC 8026CDCC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19B6B0 8026CDD0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19B6B4 8026CDD4 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B6B8 8026CDD8 8C82000C */  lw    $v0, 0xc($a0)
/* 19B6BC 8026CDDC 8C450004 */  lw    $a1, 4($v0)
/* 19B6C0 8026CDE0 0C0B1EAF */  jal   get_variable
/* 19B6C4 8026CDE4 8C500000 */   lw    $s0, ($v0)
/* 19B6C8 8026CDE8 10400007 */  beqz  $v0, .L8026CE08
/* 19B6CC 8026CDEC 00102027 */   nor   $a0, $zero, $s0
/* 19B6D0 8026CDF0 3C03800E */  lui   $v1, 0x800e
/* 19B6D4 8026CDF4 2463C070 */  addiu $v1, $v1, -0x3f90
/* 19B6D8 8026CDF8 8C620004 */  lw    $v0, 4($v1)
/* 19B6DC 8026CDFC 00501025 */  or    $v0, $v0, $s0
/* 19B6E0 8026CE00 0809B387 */  j     .L8026CE1C
/* 19B6E4 8026CE04 AC620004 */   sw    $v0, 4($v1)

.L8026CE08:
/* 19B6E8 8026CE08 3C02800E */  lui   $v0, 0x800e
/* 19B6EC 8026CE0C 2442C070 */  addiu $v0, $v0, -0x3f90
/* 19B6F0 8026CE10 8C430004 */  lw    $v1, 4($v0)
/* 19B6F4 8026CE14 00641824 */  and   $v1, $v1, $a0
/* 19B6F8 8026CE18 AC430004 */  sw    $v1, 4($v0)
.L8026CE1C:
/* 19B6FC 8026CE1C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19B700 8026CE20 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B704 8026CE24 24020002 */  addiu $v0, $zero, 2
/* 19B708 8026CE28 03E00008 */  jr    $ra
/* 19B70C 8026CE2C 27BD0018 */   addiu $sp, $sp, 0x18

