.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel resume_group_script_index
/* 0E8F20 802C4570 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8F24 802C4574 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8F28 802C4578 0080882D */  daddu $s1, $a0, $zero
/* 0E8F2C 802C457C AFB20018 */  sw    $s2, 0x18($sp)
/* 0E8F30 802C4580 00A0902D */  daddu $s2, $a1, $zero
/* 0E8F34 802C4584 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8F38 802C4588 0000802D */  daddu $s0, $zero, $zero
/* 0E8F3C 802C458C AFBF001C */  sw    $ra, 0x1c($sp)
.L802C4590:
/* 0E8F40 802C4590 3C03802E */  lui   $v1, 0x802e
/* 0E8F44 802C4594 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8F48 802C4598 00101080 */  sll   $v0, $s0, 2
/* 0E8F4C 802C459C 00431021 */  addu  $v0, $v0, $v1
/* 0E8F50 802C45A0 8C440000 */  lw    $a0, ($v0)
/* 0E8F54 802C45A4 50800007 */  beql  $a0, $zero, .L802C45C4
/* 0E8F58 802C45A8 26100001 */   addiu $s0, $s0, 1
/* 0E8F5C 802C45AC 8C820144 */  lw    $v0, 0x144($a0)
/* 0E8F60 802C45B0 54510004 */  bnel  $v0, $s1, .L802C45C4
/* 0E8F64 802C45B4 26100001 */   addiu $s0, $s0, 1
/* 0E8F68 802C45B8 0C0B10DF */  jal   resume_group_script
/* 0E8F6C 802C45BC 0240282D */   daddu $a1, $s2, $zero
/* 0E8F70 802C45C0 26100001 */  addiu $s0, $s0, 1
.L802C45C4:
/* 0E8F74 802C45C4 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8F78 802C45C8 1440FFF1 */  bnez  $v0, .L802C4590
/* 0E8F7C 802C45CC 00000000 */   nop   
/* 0E8F80 802C45D0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E8F84 802C45D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E8F88 802C45D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8F8C 802C45DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8F90 802C45E0 03E00008 */  jr    $ra
/* 0E8F94 802C45E4 27BD0020 */   addiu $sp, $sp, 0x20

