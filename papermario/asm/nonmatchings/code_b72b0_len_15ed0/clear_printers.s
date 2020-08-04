.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_printers
/* 0B9D74 80123674 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B9D78 80123678 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B9D7C 8012367C 0000802D */  daddu $s0, $zero, $zero
/* 0B9D80 80123680 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B9D84 80123684 3C118015 */  lui   $s1, 0x8015
/* 0B9D88 80123688 26314C30 */  addiu $s1, $s1, 0x4c30
/* 0B9D8C 8012368C AFBF0018 */  sw    $ra, 0x18($sp)
.L80123690:
/* 0B9D90 80123690 0220202D */  daddu $a0, $s1, $zero
/* 0B9D94 80123694 0000282D */  daddu $a1, $zero, $zero
/* 0B9D98 80123698 0C0495A9 */  jal   initialize_printer
/* 0B9D9C 8012369C 00A0302D */   daddu $a2, $a1, $zero
/* 0B9DA0 801236A0 26100001 */  addiu $s0, $s0, 1
/* 0B9DA4 801236A4 2A020003 */  slti  $v0, $s0, 3
/* 0B9DA8 801236A8 1440FFF9 */  bnez  $v0, .L80123690
/* 0B9DAC 801236AC 26310558 */   addiu $s1, $s1, 0x558
/* 0B9DB0 801236B0 24100002 */  addiu $s0, $zero, 2
/* 0B9DB4 801236B4 3C028015 */  lui   $v0, 0x8015
/* 0B9DB8 801236B8 24425C78 */  addiu $v0, $v0, 0x5c78
/* 0B9DBC 801236BC 3C018015 */  lui   $at, 0x8015
/* 0B9DC0 801236C0 AC2012D8 */  sw    $zero, 0x12d8($at)
/* 0B9DC4 801236C4 3C018015 */  lui   $at, 0x8015
/* 0B9DC8 801236C8 AC20130C */  sw    $zero, 0x130c($at)
.L801236CC:
/* 0B9DCC 801236CC A0400000 */  sb    $zero, ($v0)
/* 0B9DD0 801236D0 2610FFFF */  addiu $s0, $s0, -1
/* 0B9DD4 801236D4 0601FFFD */  bgez  $s0, .L801236CC
/* 0B9DD8 801236D8 2442FFE0 */   addiu $v0, $v0, -0x20
/* 0B9DDC 801236DC 3C018015 */  lui   $at, 0x8015
/* 0B9DE0 801236E0 AC201338 */  sw    $zero, 0x1338($at)
/* 0B9DE4 801236E4 3C018015 */  lui   $at, 0x8015
/* 0B9DE8 801236E8 A42012E4 */  sh    $zero, 0x12e4($at)
/* 0B9DEC 801236EC 0C048DCD */  jal   load_font
/* 0B9DF0 801236F0 0000202D */   daddu $a0, $zero, $zero
/* 0B9DF4 801236F4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0B9DF8 801236F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B9DFC 801236FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B9E00 80123700 03E00008 */  jr    $ra
/* 0B9E04 80123704 27BD0020 */   addiu $sp, $sp, 0x20

