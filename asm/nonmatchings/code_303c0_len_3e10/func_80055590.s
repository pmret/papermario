.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80055590
/* 030990 80055590 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030994 80055594 AFB10014 */  sw    $s1, 0x14($sp)
/* 030998 80055598 0080882D */  daddu $s1, $a0, $zero
/* 03099C 8005559C AFB20018 */  sw    $s2, 0x18($sp)
/* 0309A0 800555A0 00A0902D */  daddu $s2, $a1, $zero
/* 0309A4 800555A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0309A8 800555A8 0C01430C */  jal   func_80050C30
/* 0309AC 800555AC AFB00010 */   sw    $s0, 0x10($sp)
/* 0309B0 800555B0 0040802D */  daddu $s0, $v0, $zero
/* 0309B4 800555B4 16000005 */  bnez  $s0, .L800555CC
/* 0309B8 800555B8 0200102D */   daddu $v0, $s0, $zero
/* 0309BC 800555BC 0220202D */  daddu $a0, $s1, $zero
/* 0309C0 800555C0 0C0143A1 */  jal   func_80050E84
/* 0309C4 800555C4 0240282D */   daddu $a1, $s2, $zero
/* 0309C8 800555C8 0200102D */  daddu $v0, $s0, $zero
.L800555CC:
/* 0309CC 800555CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0309D0 800555D0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0309D4 800555D4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0309D8 800555D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0309DC 800555DC 03E00008 */  jr    $ra
/* 0309E0 800555E0 27BD0020 */   addiu $sp, $sp, 0x20

