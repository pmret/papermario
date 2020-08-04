.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel suspend_group_others
/* 0E9058 802C46A8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E905C 802C46AC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9060 802C46B0 0080882D */  daddu $s1, $a0, $zero
/* 0E9064 802C46B4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E9068 802C46B8 00A0902D */  daddu $s2, $a1, $zero
/* 0E906C 802C46BC AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9070 802C46C0 0000802D */  daddu $s0, $zero, $zero
/* 0E9074 802C46C4 AFBF001C */  sw    $ra, 0x1c($sp)
.L802C46C8:
/* 0E9078 802C46C8 3C03802E */  lui   $v1, 0x802e
/* 0E907C 802C46CC 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E9080 802C46D0 00101080 */  sll   $v0, $s0, 2
/* 0E9084 802C46D4 00431021 */  addu  $v0, $v0, $v1
/* 0E9088 802C46D8 8C440000 */  lw    $a0, ($v0)
/* 0E908C 802C46DC 50800006 */  beql  $a0, $zero, .L802C46F8
/* 0E9090 802C46E0 26100001 */   addiu $s0, $s0, 1
/* 0E9094 802C46E4 50910004 */  beql  $a0, $s1, .L802C46F8
/* 0E9098 802C46E8 26100001 */   addiu $s0, $s0, 1
/* 0E909C 802C46EC 0C0B10B6 */  jal   suspend_group_script
/* 0E90A0 802C46F0 0240282D */   daddu $a1, $s2, $zero
/* 0E90A4 802C46F4 26100001 */  addiu $s0, $s0, 1
.L802C46F8:
/* 0E90A8 802C46F8 2A020080 */  slti  $v0, $s0, 0x80
/* 0E90AC 802C46FC 1440FFF2 */  bnez  $v0, .L802C46C8
/* 0E90B0 802C4700 00000000 */   nop   
/* 0E90B4 802C4704 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E90B8 802C4708 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E90BC 802C470C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E90C0 802C4710 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E90C4 802C4714 03E00008 */  jr    $ra
/* 0E90C8 802C4718 27BD0020 */   addiu $sp, $sp, 0x20

