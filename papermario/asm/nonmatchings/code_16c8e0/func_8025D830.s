.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025D830
/* 18C110 8025D830 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 18C114 8025D834 AFBF0024 */  sw    $ra, 0x24($sp)
/* 18C118 8025D838 AFB20020 */  sw    $s2, 0x20($sp)
/* 18C11C 8025D83C AFB1001C */  sw    $s1, 0x1c($sp)
/* 18C120 8025D840 AFB00018 */  sw    $s0, 0x18($sp)
/* 18C124 8025D844 8C9000C0 */  lw    $s0, 0xc0($a0)
/* 18C128 8025D848 00A0882D */  daddu $s1, $a1, $zero
/* 18C12C 8025D84C 02119021 */  addu  $s2, $s0, $s1
/* 18C130 8025D850 824308BC */  lb    $v1, 0x8bc($s2)
/* 18C134 8025D854 10600005 */  beqz  $v1, .L8025D86C
/* 18C138 8025D858 24020001 */   addiu $v0, $zero, 1
/* 18C13C 8025D85C 10620012 */  beq   $v1, $v0, .L8025D8A8
/* 18C140 8025D860 00111080 */   sll   $v0, $s1, 2
/* 18C144 8025D864 08097635 */  j     .L8025D8D4
/* 18C148 8025D868 00000000 */   nop   

.L8025D86C:
/* 18C14C 8025D86C 3C013F80 */  lui   $at, 0x3f80
/* 18C150 8025D870 44810000 */  mtc1  $at, $f0
/* 18C154 8025D874 AFA00014 */  sw    $zero, 0x14($sp)
/* 18C158 8025D878 E7A00010 */  swc1  $f0, 0x10($sp)
/* 18C15C 8025D87C 8C850058 */  lw    $a1, 0x58($a0)
/* 18C160 8025D880 8C86005C */  lw    $a2, 0x5c($a0)
/* 18C164 8025D884 8C870060 */  lw    $a3, 0x60($a0)
/* 18C168 8025D888 0C01C7CC */  jal   func_80071F30
/* 18C16C 8025D88C 24040002 */   addiu $a0, $zero, 2
/* 18C170 8025D890 00111880 */  sll   $v1, $s1, 2
/* 18C174 8025D894 02031821 */  addu  $v1, $s0, $v1
/* 18C178 8025D898 AC6208B0 */  sw    $v0, 0x8b0($v1)
/* 18C17C 8025D89C 24020001 */  addiu $v0, $zero, 1
/* 18C180 8025D8A0 08097635 */  j     .L8025D8D4
/* 18C184 8025D8A4 A24208BC */   sb    $v0, 0x8bc($s2)

.L8025D8A8:
/* 18C188 8025D8A8 02021021 */  addu  $v0, $s0, $v0
/* 18C18C 8025D8AC 8C4208B0 */  lw    $v0, 0x8b0($v0)
/* 18C190 8025D8B0 C4800058 */  lwc1  $f0, 0x58($a0)
/* 18C194 8025D8B4 8C43000C */  lw    $v1, 0xc($v0)
/* 18C198 8025D8B8 E4600004 */  swc1  $f0, 4($v1)
/* 18C19C 8025D8BC 8C43000C */  lw    $v1, 0xc($v0)
/* 18C1A0 8025D8C0 C480005C */  lwc1  $f0, 0x5c($a0)
/* 18C1A4 8025D8C4 E4600008 */  swc1  $f0, 8($v1)
/* 18C1A8 8025D8C8 8C42000C */  lw    $v0, 0xc($v0)
/* 18C1AC 8025D8CC C4800060 */  lwc1  $f0, 0x60($a0)
/* 18C1B0 8025D8D0 E440000C */  swc1  $f0, 0xc($v0)
.L8025D8D4:
/* 18C1B4 8025D8D4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 18C1B8 8025D8D8 8FB20020 */  lw    $s2, 0x20($sp)
/* 18C1BC 8025D8DC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 18C1C0 8025D8E0 8FB00018 */  lw    $s0, 0x18($sp)
/* 18C1C4 8025D8E4 03E00008 */  jr    $ra
/* 18C1C8 8025D8E8 27BD0028 */   addiu $sp, $sp, 0x28

