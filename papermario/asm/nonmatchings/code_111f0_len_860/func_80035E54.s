.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80035E54
/* 011254 80035E54 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 011258 80035E58 24020004 */  addiu $v0, $zero, 4
/* 01125C 80035E5C AFB10014 */  sw    $s1, 0x14($sp)
/* 011260 80035E60 3C118007 */  lui   $s1, 0x8007
/* 011264 80035E64 2631419C */  addiu $s1, $s1, 0x419c
/* 011268 80035E68 AFB00010 */  sw    $s0, 0x10($sp)
/* 01126C 80035E6C 3C10800A */  lui   $s0, 0x800a
/* 011270 80035E70 26100940 */  addiu $s0, $s0, 0x940
/* 011274 80035E74 AFBF0018 */  sw    $ra, 0x18($sp)
/* 011278 80035E78 3C01800A */  lui   $at, 0x800a
/* 01127C 80035E7C A4200944 */  sh    $zero, 0x944($at)
/* 011280 80035E80 3C01800A */  lui   $at, 0x800a
/* 011284 80035E84 A4220946 */  sh    $v0, 0x946($at)
/* 011288 80035E88 8E230000 */  lw    $v1, ($s1)
/* 01128C 80035E8C 240200FF */  addiu $v0, $zero, 0xff
/* 011290 80035E90 A6020000 */  sh    $v0, ($s0)
/* 011294 80035E94 0C018030 */  jal   nuContRmbForceStopEnd
/* 011298 80035E98 AC600094 */   sw    $zero, 0x94($v1)
/* 01129C 80035E9C 0C04E0AB */  jal   func_801382AC
/* 0112A0 80035EA0 0200202D */   daddu $a0, $s0, $zero
/* 0112A4 80035EA4 0000202D */  daddu $a0, $zero, $zero
/* 0112A8 80035EA8 3C05F5DE */  lui   $a1, 0xf5de
/* 0112AC 80035EAC 3C03800A */  lui   $v1, 0x800a
/* 0112B0 80035EB0 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0112B4 80035EB4 8C620000 */  lw    $v0, ($v1)
/* 0112B8 80035EB8 8E260000 */  lw    $a2, ($s1)
/* 0112BC 80035EBC 34420008 */  ori   $v0, $v0, 8
/* 0112C0 80035EC0 AC620000 */  sw    $v0, ($v1)
/* 0112C4 80035EC4 80C600A9 */  lb    $a2, 0xa9($a2)
/* 0112C8 80035EC8 0C0B2026 */  jal   set_variable
/* 0112CC 80035ECC 34A50181 */   ori   $a1, $a1, 0x181
/* 0112D0 80035ED0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0112D4 80035ED4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0112D8 80035ED8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0112DC 80035EDC 3C01800A */  lui   $at, 0x800a
/* 0112E0 80035EE0 AC20A5D8 */  sw    $zero, -0x5a28($at)
/* 0112E4 80035EE4 03E00008 */  jr    $ra
/* 0112E8 80035EE8 27BD0020 */   addiu $sp, $sp, 0x20

