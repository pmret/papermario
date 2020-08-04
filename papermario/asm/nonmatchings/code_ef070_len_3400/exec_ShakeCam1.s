.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel exec_ShakeCam1
/* 0EFF1C 802CB56C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EFF20 802CB570 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EFF24 802CB574 0080802D */  daddu $s0, $a0, $zero
/* 0EFF28 802CB578 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EFF2C 802CB57C 00A0882D */  daddu $s1, $a1, $zero
/* 0EFF30 802CB580 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EFF34 802CB584 00C0902D */  daddu $s2, $a2, $zero
/* 0EFF38 802CB588 3C04802E */  lui   $a0, 0x802e
/* 0EFF3C 802CB58C 24849CB0 */  addiu $a0, $a0, -0x6350
/* 0EFF40 802CB590 24050001 */  addiu $a1, $zero, 1
/* 0EFF44 802CB594 0000302D */  daddu $a2, $zero, $zero
/* 0EFF48 802CB598 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EFF4C 802CB59C 0C0B0D74 */  jal   start_script_in_group
/* 0EFF50 802CB5A0 24070004 */   addiu $a3, $zero, 4
/* 0EFF54 802CB5A4 AC500084 */  sw    $s0, 0x84($v0)
/* 0EFF58 802CB5A8 AC510088 */  sw    $s1, 0x88($v0)
/* 0EFF5C 802CB5AC AC52008C */  sw    $s2, 0x8c($v0)
/* 0EFF60 802CB5B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EFF64 802CB5B4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EFF68 802CB5B8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EFF6C 802CB5BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EFF70 802CB5C0 03E00008 */  jr    $ra
/* 0EFF74 802CB5C4 27BD0020 */   addiu $sp, $sp, 0x20

