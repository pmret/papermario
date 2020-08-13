.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80054D74
/* 030174 80054D74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 030178 80054D78 30840010 */  andi  $a0, $a0, 0x10
/* 03017C 80054D7C 14800003 */  bnez  $a0, .L80054D8C
/* 030180 80054D80 AFBF0010 */   sw    $ra, 0x10($sp)
/* 030184 80054D84 08015367 */  j     .L80054D9C
/* 030188 80054D88 0000102D */   daddu $v0, $zero, $zero

.L80054D8C:
/* 03018C 80054D8C 3C04800A */  lui   $a0, 0x800a
/* 030190 80054D90 8C84A640 */  lw    $a0, -0x59c0($a0)
/* 030194 80054D94 0C012E79 */  jal   func_8004B9E4
/* 030198 80054D98 00000000 */   nop   
.L80054D9C:
/* 03019C 80054D9C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0301A0 80054DA0 03E00008 */  jr    $ra
/* 0301A4 80054DA4 27BD0018 */   addiu $sp, $sp, 0x18

