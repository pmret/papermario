.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel resume_group_script
/* 0E8D2C 802C437C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8D30 802C4380 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8D34 802C4384 0080882D */  daddu $s1, $a0, $zero
/* 0E8D38 802C4388 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E8D3C 802C438C AFB20018 */  sw    $s2, 0x18($sp)
/* 0E8D40 802C4390 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8D44 802C4394 8E240068 */  lw    $a0, 0x68($s1)
/* 0E8D48 802C4398 10800003 */  beqz  $a0, .L802C43A8
/* 0E8D4C 802C439C 00A0902D */   daddu $s2, $a1, $zero
/* 0E8D50 802C43A0 0C0B10DF */  jal   resume_group_script
/* 0E8D54 802C43A4 00000000 */   nop   
.L802C43A8:
/* 0E8D58 802C43A8 0000802D */  daddu $s0, $zero, $zero
.L802C43AC:
/* 0E8D5C 802C43AC 3C03802E */  lui   $v1, 0x802e
/* 0E8D60 802C43B0 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8D64 802C43B4 00101080 */  sll   $v0, $s0, 2
/* 0E8D68 802C43B8 00431021 */  addu  $v0, $v0, $v1
/* 0E8D6C 802C43BC 8C440000 */  lw    $a0, ($v0)
/* 0E8D70 802C43C0 50800007 */  beql  $a0, $zero, .L802C43E0
/* 0E8D74 802C43C4 26100001 */   addiu $s0, $s0, 1
/* 0E8D78 802C43C8 8C82006C */  lw    $v0, 0x6c($a0)
/* 0E8D7C 802C43CC 54510004 */  bnel  $v0, $s1, .L802C43E0
/* 0E8D80 802C43D0 26100001 */   addiu $s0, $s0, 1
/* 0E8D84 802C43D4 0C0B10B6 */  jal   suspend_group_script
/* 0E8D88 802C43D8 0240282D */   daddu $a1, $s2, $zero
/* 0E8D8C 802C43DC 26100001 */  addiu $s0, $s0, 1
.L802C43E0:
/* 0E8D90 802C43E0 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8D94 802C43E4 1440FFF1 */  bnez  $v0, .L802C43AC
/* 0E8D98 802C43E8 00000000 */   nop   
/* 0E8D9C 802C43EC 92220004 */  lbu   $v0, 4($s1)
/* 0E8DA0 802C43F0 00521024 */  and   $v0, $v0, $s2
/* 0E8DA4 802C43F4 10400004 */  beqz  $v0, .L802C4408
/* 0E8DA8 802C43F8 00000000 */   nop   
/* 0E8DAC 802C43FC 92220000 */  lbu   $v0, ($s1)
/* 0E8DB0 802C4400 304200FD */  andi  $v0, $v0, 0xfd
/* 0E8DB4 802C4404 A2220000 */  sb    $v0, ($s1)
.L802C4408:
/* 0E8DB8 802C4408 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E8DBC 802C440C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E8DC0 802C4410 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8DC4 802C4414 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8DC8 802C4418 03E00008 */  jr    $ra
/* 0E8DCC 802C441C 27BD0020 */   addiu $sp, $sp, 0x20

