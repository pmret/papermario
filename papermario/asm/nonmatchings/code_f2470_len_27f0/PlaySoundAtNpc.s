.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlaySoundAtNpc
/* 0F4B5C 802D01AC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F4B60 802D01B0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F4B64 802D01B4 0080882D */  daddu $s1, $a0, $zero
/* 0F4B68 802D01B8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F4B6C 802D01BC AFB20020 */  sw    $s2, 0x20($sp)
/* 0F4B70 802D01C0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F4B74 802D01C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F4B78 802D01C8 8E050000 */  lw    $a1, ($s0)
/* 0F4B7C 802D01CC 0C0B1EAF */  jal   get_variable
/* 0F4B80 802D01D0 26100004 */   addiu $s0, $s0, 4
/* 0F4B84 802D01D4 8E050000 */  lw    $a1, ($s0)
/* 0F4B88 802D01D8 26100004 */  addiu $s0, $s0, 4
/* 0F4B8C 802D01DC 0220202D */  daddu $a0, $s1, $zero
/* 0F4B90 802D01E0 0C0B1EAF */  jal   get_variable
/* 0F4B94 802D01E4 0040902D */   daddu $s2, $v0, $zero
/* 0F4B98 802D01E8 0220202D */  daddu $a0, $s1, $zero
/* 0F4B9C 802D01EC 8E050000 */  lw    $a1, ($s0)
/* 0F4BA0 802D01F0 0C0B1EAF */  jal   get_variable
/* 0F4BA4 802D01F4 0040802D */   daddu $s0, $v0, $zero
/* 0F4BA8 802D01F8 0220202D */  daddu $a0, $s1, $zero
/* 0F4BAC 802D01FC 0240282D */  daddu $a1, $s2, $zero
/* 0F4BB0 802D0200 0C0B36B0 */  jal   func_802CDAC0
/* 0F4BB4 802D0204 0040882D */   daddu $s1, $v0, $zero
/* 0F4BB8 802D0208 10400007 */  beqz  $v0, .L802D0228
/* 0F4BBC 802D020C 0200202D */   daddu $a0, $s0, $zero
/* 0F4BC0 802D0210 C4400040 */  lwc1  $f0, 0x40($v0)
/* 0F4BC4 802D0214 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0F4BC8 802D0218 8C460038 */  lw    $a2, 0x38($v0)
/* 0F4BCC 802D021C 8C47003C */  lw    $a3, 0x3c($v0)
/* 0F4BD0 802D0220 0C052757 */  jal   play_sound_at_position
/* 0F4BD4 802D0224 0220282D */   daddu $a1, $s1, $zero
.L802D0228:
/* 0F4BD8 802D0228 24020002 */  addiu $v0, $zero, 2
/* 0F4BDC 802D022C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F4BE0 802D0230 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F4BE4 802D0234 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F4BE8 802D0238 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F4BEC 802D023C 03E00008 */  jr    $ra
/* 0F4BF0 802D0240 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F4BF4 802D0244 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4BF8 802D0248 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F4BFC 802D024C 0080882D */  daddu $s1, $a0, $zero
/* 0F4C00 802D0250 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F4C04 802D0254 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F4C08 802D0258 8E30000C */  lw    $s0, 0xc($s1)
/* 0F4C0C 802D025C 8E050000 */  lw    $a1, ($s0)
/* 0F4C10 802D0260 0C0B1EAF */  jal   get_variable
/* 0F4C14 802D0264 26100004 */   addiu $s0, $s0, 4
/* 0F4C18 802D0268 0220202D */  daddu $a0, $s1, $zero
/* 0F4C1C 802D026C 8E050000 */  lw    $a1, ($s0)
/* 0F4C20 802D0270 0C0B1EAF */  jal   get_variable
/* 0F4C24 802D0274 0040802D */   daddu $s0, $v0, $zero
/* 0F4C28 802D0278 0220202D */  daddu $a0, $s1, $zero
/* 0F4C2C 802D027C 0200282D */  daddu $a1, $s0, $zero
/* 0F4C30 802D0280 0C0B36B0 */  jal   func_802CDAC0
/* 0F4C34 802D0284 0040802D */   daddu $s0, $v0, $zero
/* 0F4C38 802D0288 A05000AA */  sb    $s0, 0xaa($v0)
/* 0F4C3C 802D028C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F4C40 802D0290 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F4C44 802D0294 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F4C48 802D0298 24020002 */  addiu $v0, $zero, 2
/* 0F4C4C 802D029C 03E00008 */  jr    $ra
/* 0F4C50 802D02A0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F4C54 802D02A4 00000000 */  nop   
/* 0F4C58 802D02A8 00000000 */  nop   
/* 0F4C5C 802D02AC 00000000 */  nop   

.set reorder
