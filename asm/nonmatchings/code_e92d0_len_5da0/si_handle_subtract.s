.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_subtract
/* 0EA218 802C5868 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA21C 802C586C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA220 802C5870 0080882D */  daddu $s1, $a0, $zero
/* 0EA224 802C5874 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA228 802C5878 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA22C 802C587C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA230 802C5880 8E22000C */  lw    $v0, 0xc($s1)
/* 0EA234 802C5884 8C450004 */  lw    $a1, 4($v0)
/* 0EA238 802C5888 0C0B1EAF */  jal   get_variable
/* 0EA23C 802C588C 8C520000 */   lw    $s2, ($v0)
/* 0EA240 802C5890 0040802D */  daddu $s0, $v0, $zero
/* 0EA244 802C5894 0220202D */  daddu $a0, $s1, $zero
/* 0EA248 802C5898 0C0B1EAF */  jal   get_variable
/* 0EA24C 802C589C 0240282D */   daddu $a1, $s2, $zero
/* 0EA250 802C58A0 0220202D */  daddu $a0, $s1, $zero
/* 0EA254 802C58A4 0240282D */  daddu $a1, $s2, $zero
/* 0EA258 802C58A8 0C0B2026 */  jal   set_variable
/* 0EA25C 802C58AC 00503023 */   subu  $a2, $v0, $s0
/* 0EA260 802C58B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA264 802C58B4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA268 802C58B8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA26C 802C58BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA270 802C58C0 24020002 */  addiu $v0, $zero, 2
/* 0EA274 802C58C4 03E00008 */  jr    $ra
/* 0EA278 802C58C8 27BD0020 */   addiu $sp, $sp, 0x20

