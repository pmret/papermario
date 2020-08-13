.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel MakeLerp
/* 0F8F60 802D45B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8F64 802D45B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8F68 802D45B8 0080882D */  daddu $s1, $a0, $zero
/* 0F8F6C 802D45BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8F70 802D45C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8F74 802D45C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F8F78 802D45C8 8E050000 */  lw    $a1, ($s0)
/* 0F8F7C 802D45CC 0C0B1EAF */  jal   get_variable
/* 0F8F80 802D45D0 26100004 */   addiu $s0, $s0, 4
/* 0F8F84 802D45D4 AE2200B4 */  sw    $v0, 0xb4($s1)
/* 0F8F88 802D45D8 8E050000 */  lw    $a1, ($s0)
/* 0F8F8C 802D45DC 26100004 */  addiu $s0, $s0, 4
/* 0F8F90 802D45E0 0C0B1EAF */  jal   get_variable
/* 0F8F94 802D45E4 0220202D */   daddu $a0, $s1, $zero
/* 0F8F98 802D45E8 AE2200B8 */  sw    $v0, 0xb8($s1)
/* 0F8F9C 802D45EC 8E050000 */  lw    $a1, ($s0)
/* 0F8FA0 802D45F0 26100004 */  addiu $s0, $s0, 4
/* 0F8FA4 802D45F4 0C0B1EAF */  jal   get_variable
/* 0F8FA8 802D45F8 0220202D */   daddu $a0, $s1, $zero
/* 0F8FAC 802D45FC AE2200C0 */  sw    $v0, 0xc0($s1)
/* 0F8FB0 802D4600 8E050000 */  lw    $a1, ($s0)
/* 0F8FB4 802D4604 0C0B1EAF */  jal   get_variable
/* 0F8FB8 802D4608 0220202D */   daddu $a0, $s1, $zero
/* 0F8FBC 802D460C AE2200B0 */  sw    $v0, 0xb0($s1)
/* 0F8FC0 802D4610 AE2000BC */  sw    $zero, 0xbc($s1)
/* 0F8FC4 802D4614 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F8FC8 802D4618 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8FCC 802D461C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8FD0 802D4620 24020002 */  addiu $v0, $zero, 2
/* 0F8FD4 802D4624 03E00008 */  jr    $ra
/* 0F8FD8 802D4628 27BD0020 */   addiu $sp, $sp, 0x20

