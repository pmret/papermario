.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_if_less_equal
/* 0E9778 802C4DC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E977C 802C4DCC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9780 802C4DD0 0080882D */  daddu $s1, $a0, $zero
/* 0E9784 802C4DD4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9788 802C4DD8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E978C 802C4DDC 8E30000C */  lw    $s0, 0xc($s1)
/* 0E9790 802C4DE0 8E050000 */  lw    $a1, ($s0)
/* 0E9794 802C4DE4 0C0B1EAF */  jal   get_variable
/* 0E9798 802C4DE8 26100004 */   addiu $s0, $s0, 4
/* 0E979C 802C4DEC 0220202D */  daddu $a0, $s1, $zero
/* 0E97A0 802C4DF0 8E050000 */  lw    $a1, ($s0)
/* 0E97A4 802C4DF4 0C0B1EAF */  jal   get_variable
/* 0E97A8 802C4DF8 0040802D */   daddu $s0, $v0, $zero
/* 0E97AC 802C4DFC 0050102A */  slt   $v0, $v0, $s0
/* 0E97B0 802C4E00 10400005 */  beqz  $v0, .L802C4E18
/* 0E97B4 802C4E04 24020002 */   addiu $v0, $zero, 2
/* 0E97B8 802C4E08 0C0B223F */  jal   si_skip_if
/* 0E97BC 802C4E0C 0220202D */   daddu $a0, $s1, $zero
/* 0E97C0 802C4E10 AE220008 */  sw    $v0, 8($s1)
/* 0E97C4 802C4E14 24020002 */  addiu $v0, $zero, 2
.L802C4E18:
/* 0E97C8 802C4E18 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E97CC 802C4E1C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E97D0 802C4E20 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E97D4 802C4E24 03E00008 */  jr    $ra
/* 0E97D8 802C4E28 27BD0020 */   addiu $sp, $sp, 0x20

