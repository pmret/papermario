.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel HasKeyItem
/* 0FB34C 802D699C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB350 802D69A0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB354 802D69A4 0080882D */  daddu $s1, $a0, $zero
/* 0FB358 802D69A8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FB35C 802D69AC AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB360 802D69B0 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB364 802D69B4 8E050000 */  lw    $a1, ($s0)
/* 0FB368 802D69B8 0C0B1EAF */  jal   get_variable
/* 0FB36C 802D69BC 26100004 */   addiu $s0, $s0, 4
/* 0FB370 802D69C0 0040202D */  daddu $a0, $v0, $zero
/* 0FB374 802D69C4 0000302D */  daddu $a2, $zero, $zero
/* 0FB378 802D69C8 3C038011 */  lui   $v1, 0x8011
/* 0FB37C 802D69CC 2463F290 */  addiu $v1, $v1, -0xd70
/* 0FB380 802D69D0 8E050000 */  lw    $a1, ($s0)
.L802D69D4:
/* 0FB384 802D69D4 84620074 */  lh    $v0, 0x74($v1)
/* 0FB388 802D69D8 50440006 */  beql  $v0, $a0, .L802D69F4
/* 0FB38C 802D69DC 0220202D */   daddu $a0, $s1, $zero
/* 0FB390 802D69E0 24C60001 */  addiu $a2, $a2, 1
/* 0FB394 802D69E4 28C20020 */  slti  $v0, $a2, 0x20
/* 0FB398 802D69E8 1440FFFA */  bnez  $v0, .L802D69D4
/* 0FB39C 802D69EC 24630002 */   addiu $v1, $v1, 2
/* 0FB3A0 802D69F0 0220202D */  daddu $a0, $s1, $zero
.L802D69F4:
/* 0FB3A4 802D69F4 0C0B2026 */  jal   set_variable
/* 0FB3A8 802D69F8 28C60020 */   slti  $a2, $a2, 0x20
/* 0FB3AC 802D69FC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FB3B0 802D6A00 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB3B4 802D6A04 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB3B8 802D6A08 24020002 */  addiu $v0, $zero, 2
/* 0FB3BC 802D6A0C 03E00008 */  jr    $ra
/* 0FB3C0 802D6A10 27BD0020 */   addiu $sp, $sp, 0x20

