.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_script_flags
/* 0E9198 802C47E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E919C 802C47EC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E91A0 802C47F0 0080882D */  daddu $s1, $a0, $zero
/* 0E91A4 802C47F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E91A8 802C47F8 00A0902D */  daddu $s2, $a1, $zero
/* 0E91AC 802C47FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E91B0 802C4800 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E91B4 802C4804 92220000 */  lbu   $v0, ($s1)
/* 0E91B8 802C4808 8E240068 */  lw    $a0, 0x68($s1)
/* 0E91BC 802C480C 00521025 */  or    $v0, $v0, $s2
/* 0E91C0 802C4810 10800003 */  beqz  $a0, .L802C4820
/* 0E91C4 802C4814 A2220000 */   sb    $v0, ($s1)
/* 0E91C8 802C4818 0C0B11FA */  jal   set_script_flags
/* 0E91CC 802C481C 00000000 */   nop   
.L802C4820:
/* 0E91D0 802C4820 0000802D */  daddu $s0, $zero, $zero
.L802C4824:
/* 0E91D4 802C4824 3C03802E */  lui   $v1, 0x802e
/* 0E91D8 802C4828 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E91DC 802C482C 00101080 */  sll   $v0, $s0, 2
/* 0E91E0 802C4830 00431021 */  addu  $v0, $v0, $v1
/* 0E91E4 802C4834 8C420000 */  lw    $v0, ($v0)
/* 0E91E8 802C4838 50400008 */  beql  $v0, $zero, .L802C485C
/* 0E91EC 802C483C 26100001 */   addiu $s0, $s0, 1
/* 0E91F0 802C4840 8C42006C */  lw    $v0, 0x6c($v0)
/* 0E91F4 802C4844 54510005 */  bnel  $v0, $s1, .L802C485C
/* 0E91F8 802C4848 26100001 */   addiu $s0, $s0, 1
/* 0E91FC 802C484C 8E24006C */  lw    $a0, 0x6c($s1)
/* 0E9200 802C4850 0C0B11FA */  jal   set_script_flags
/* 0E9204 802C4854 0240282D */   daddu $a1, $s2, $zero
/* 0E9208 802C4858 26100001 */  addiu $s0, $s0, 1
.L802C485C:
/* 0E920C 802C485C 2A020080 */  slti  $v0, $s0, 0x80
/* 0E9210 802C4860 1440FFF0 */  bnez  $v0, .L802C4824
/* 0E9214 802C4864 00000000 */   nop   
/* 0E9218 802C4868 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E921C 802C486C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E9220 802C4870 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9224 802C4874 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9228 802C4878 03E00008 */  jr    $ra
/* 0E922C 802C487C 27BD0020 */   addiu $sp, $sp, 0x20

