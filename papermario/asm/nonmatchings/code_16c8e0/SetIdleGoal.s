.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetIdleGoal
/* 198F0C 8026A62C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 198F10 8026A630 AFB20018 */  sw    $s2, 0x18($sp)
/* 198F14 8026A634 0080902D */  daddu $s2, $a0, $zero
/* 198F18 8026A638 AFBF001C */  sw    $ra, 0x1c($sp)
/* 198F1C 8026A63C AFB10014 */  sw    $s1, 0x14($sp)
/* 198F20 8026A640 AFB00010 */  sw    $s0, 0x10($sp)
/* 198F24 8026A644 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 198F28 8026A648 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 198F2C 8026A64C 8E50000C */  lw    $s0, 0xc($s2)
/* 198F30 8026A650 8E050000 */  lw    $a1, ($s0)
/* 198F34 8026A654 0C0B1EAF */  jal   get_variable
/* 198F38 8026A658 26100004 */   addiu $s0, $s0, 4
/* 198F3C 8026A65C 0040202D */  daddu $a0, $v0, $zero
/* 198F40 8026A660 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198F44 8026A664 14820002 */  bne   $a0, $v0, .L8026A670
/* 198F48 8026A668 00000000 */   nop   
/* 198F4C 8026A66C 8E440148 */  lw    $a0, 0x148($s2)
.L8026A670:
/* 198F50 8026A670 0C09A75B */  jal   get_actor
/* 198F54 8026A674 00000000 */   nop   
/* 198F58 8026A678 3C03FF43 */  lui   $v1, 0xff43
/* 198F5C 8026A67C 34639EB2 */  ori   $v1, $v1, 0x9eb2
/* 198F60 8026A680 8E050000 */  lw    $a1, ($s0)
/* 198F64 8026A684 14A30004 */  bne   $a1, $v1, .L8026A698
/* 198F68 8026A688 245100C8 */   addiu $s1, $v0, 0xc8
/* 198F6C 8026A68C C45600D4 */  lwc1  $f22, 0xd4($v0)
/* 198F70 8026A690 0809A9AC */  j     .L8026A6B0
/* 198F74 8026A694 26100004 */   addiu $s0, $s0, 4

.L8026A698:
/* 198F78 8026A698 0C0B1EAF */  jal   get_variable
/* 198F7C 8026A69C 0240202D */   daddu $a0, $s2, $zero
/* 198F80 8026A6A0 4482B000 */  mtc1  $v0, $f22
/* 198F84 8026A6A4 00000000 */  nop   
/* 198F88 8026A6A8 4680B5A0 */  cvt.s.w $f22, $f22
/* 198F8C 8026A6AC 26100004 */  addiu $s0, $s0, 4
.L8026A6B0:
/* 198F90 8026A6B0 3C02FF43 */  lui   $v0, 0xff43
/* 198F94 8026A6B4 8E050000 */  lw    $a1, ($s0)
/* 198F98 8026A6B8 34429EB2 */  ori   $v0, $v0, 0x9eb2
/* 198F9C 8026A6BC 14A20004 */  bne   $a1, $v0, .L8026A6D0
/* 198FA0 8026A6C0 3C02FF43 */   lui   $v0, 0xff43
/* 198FA4 8026A6C4 C6340010 */  lwc1  $f20, 0x10($s1)
/* 198FA8 8026A6C8 0809A9BA */  j     .L8026A6E8
/* 198FAC 8026A6CC 00000000 */   nop   

.L8026A6D0:
/* 198FB0 8026A6D0 0C0B1EAF */  jal   get_variable
/* 198FB4 8026A6D4 0240202D */   daddu $a0, $s2, $zero
/* 198FB8 8026A6D8 4482A000 */  mtc1  $v0, $f20
/* 198FBC 8026A6DC 00000000 */  nop   
/* 198FC0 8026A6E0 4680A520 */  cvt.s.w $f20, $f20
/* 198FC4 8026A6E4 3C02FF43 */  lui   $v0, 0xff43
.L8026A6E8:
/* 198FC8 8026A6E8 8E050004 */  lw    $a1, 4($s0)
/* 198FCC 8026A6EC 34429EB2 */  ori   $v0, $v0, 0x9eb2
/* 198FD0 8026A6F0 14A20004 */  bne   $a1, $v0, .L8026A704
/* 198FD4 8026A6F4 00000000 */   nop   
/* 198FD8 8026A6F8 C6200014 */  lwc1  $f0, 0x14($s1)
/* 198FDC 8026A6FC 0809A9C7 */  j     .L8026A71C
/* 198FE0 8026A700 E636000C */   swc1  $f22, 0xc($s1)

.L8026A704:
/* 198FE4 8026A704 0C0B1EAF */  jal   get_variable
/* 198FE8 8026A708 0240202D */   daddu $a0, $s2, $zero
/* 198FEC 8026A70C 44820000 */  mtc1  $v0, $f0
/* 198FF0 8026A710 00000000 */  nop   
/* 198FF4 8026A714 46800020 */  cvt.s.w $f0, $f0
/* 198FF8 8026A718 E636000C */  swc1  $f22, 0xc($s1)
.L8026A71C:
/* 198FFC 8026A71C E6340010 */  swc1  $f20, 0x10($s1)
/* 199000 8026A720 E6200014 */  swc1  $f0, 0x14($s1)
/* 199004 8026A724 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199008 8026A728 8FB20018 */  lw    $s2, 0x18($sp)
/* 19900C 8026A72C 8FB10014 */  lw    $s1, 0x14($sp)
/* 199010 8026A730 8FB00010 */  lw    $s0, 0x10($sp)
/* 199014 8026A734 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 199018 8026A738 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 19901C 8026A73C 24020002 */  addiu $v0, $zero, 2
/* 199020 8026A740 03E00008 */  jr    $ra
/* 199024 8026A744 27BD0030 */   addiu $sp, $sp, 0x30

