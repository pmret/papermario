.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel restart_script
/* 0E86B4 802C3D04 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E86B8 802C3D08 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E86BC 802C3D0C 0080802D */  daddu $s0, $a0, $zero
/* 0E86C0 802C3D10 2402FFFF */  addiu $v0, $zero, -1
/* 0E86C4 802C3D14 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E86C8 802C3D18 A2020006 */  sb    $v0, 6($s0)
/* 0E86CC 802C3D1C A2020007 */  sb    $v0, 7($s0)
/* 0E86D0 802C3D20 8E02015C */  lw    $v0, 0x15c($s0)
/* 0E86D4 802C3D24 3C013F80 */  lui   $at, 0x3f80
/* 0E86D8 802C3D28 44810000 */  mtc1  $at, $f0
/* 0E86DC 802C3D2C A2000002 */  sb    $zero, 2($s0)
/* 0E86E0 802C3D30 3C01802E */  lui   $at, 0x802e
/* 0E86E4 802C3D34 C4229CA8 */  lwc1  $f2, -0x6358($at)
/* 0E86E8 802C3D38 AE000154 */  sw    $zero, 0x154($s0)
/* 0E86EC 802C3D3C AE000154 */  sw    $zero, 0x154($s0)
/* 0E86F0 802C3D40 AE000158 */  sw    $zero, 0x158($s0)
/* 0E86F4 802C3D44 AE020008 */  sw    $v0, 8($s0)
/* 0E86F8 802C3D48 AE020164 */  sw    $v0, 0x164($s0)
/* 0E86FC 802C3D4C E6000150 */  swc1  $f0, 0x150($s0)
/* 0E8700 802C3D50 0C0B0C52 */  jal   find_script_labels
/* 0E8704 802C3D54 E6020150 */   swc1  $f2, 0x150($s0)
/* 0E8708 802C3D58 0C0B0CE4 */  jal   func_802C3390
/* 0E870C 802C3D5C 0200202D */   daddu $a0, $s0, $zero
/* 0E8710 802C3D60 0200102D */  daddu $v0, $s0, $zero
/* 0E8714 802C3D64 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E8718 802C3D68 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E871C 802C3D6C 03E00008 */  jr    $ra
/* 0E8720 802C3D70 27BD0018 */   addiu $sp, $sp, 0x18

