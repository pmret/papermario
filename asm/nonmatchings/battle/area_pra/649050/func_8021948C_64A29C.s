.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021948C_64A29C
/* 64A29C 8021948C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 64A2A0 80219490 AFB3001C */  sw        $s3, 0x1c($sp)
/* 64A2A4 80219494 0080982D */  daddu     $s3, $a0, $zero
/* 64A2A8 80219498 AFBF0020 */  sw        $ra, 0x20($sp)
/* 64A2AC 8021949C AFB20018 */  sw        $s2, 0x18($sp)
/* 64A2B0 802194A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 64A2B4 802194A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 64A2B8 802194A8 8E70000C */  lw        $s0, 0xc($s3)
/* 64A2BC 802194AC 8E050000 */  lw        $a1, ($s0)
/* 64A2C0 802194B0 0C0B1EAF */  jal       get_variable
/* 64A2C4 802194B4 26100004 */   addiu    $s0, $s0, 4
/* 64A2C8 802194B8 0040882D */  daddu     $s1, $v0, $zero
/* 64A2CC 802194BC 8E050000 */  lw        $a1, ($s0)
/* 64A2D0 802194C0 26100004 */  addiu     $s0, $s0, 4
/* 64A2D4 802194C4 0C0B1EAF */  jal       get_variable
/* 64A2D8 802194C8 0260202D */   daddu    $a0, $s3, $zero
/* 64A2DC 802194CC 0040902D */  daddu     $s2, $v0, $zero
/* 64A2E0 802194D0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 64A2E4 802194D4 16220002 */  bne       $s1, $v0, .L802194E0
/* 64A2E8 802194D8 00000000 */   nop      
/* 64A2EC 802194DC 8E710148 */  lw        $s1, 0x148($s3)
.L802194E0:
/* 64A2F0 802194E0 0C09A75B */  jal       get_actor
/* 64A2F4 802194E4 0220202D */   daddu    $a0, $s1, $zero
/* 64A2F8 802194E8 0040202D */  daddu     $a0, $v0, $zero
/* 64A2FC 802194EC 0C099117 */  jal       get_actor_part
/* 64A300 802194F0 0240282D */   daddu    $a1, $s2, $zero
/* 64A304 802194F4 8C440078 */  lw        $a0, 0x78($v0)
/* 64A308 802194F8 0C099791 */  jal       lookup_defense
/* 64A30C 802194FC 24050001 */   addiu    $a1, $zero, 1
/* 64A310 80219500 0260202D */  daddu     $a0, $s3, $zero
/* 64A314 80219504 8E050000 */  lw        $a1, ($s0)
/* 64A318 80219508 0C0B2026 */  jal       set_variable
/* 64A31C 8021950C 0040302D */   daddu    $a2, $v0, $zero
/* 64A320 80219510 8FBF0020 */  lw        $ra, 0x20($sp)
/* 64A324 80219514 8FB3001C */  lw        $s3, 0x1c($sp)
/* 64A328 80219518 8FB20018 */  lw        $s2, 0x18($sp)
/* 64A32C 8021951C 8FB10014 */  lw        $s1, 0x14($sp)
/* 64A330 80219520 8FB00010 */  lw        $s0, 0x10($sp)
/* 64A334 80219524 24020002 */  addiu     $v0, $zero, 2
/* 64A338 80219528 03E00008 */  jr        $ra
/* 64A33C 8021952C 27BD0028 */   addiu    $sp, $sp, 0x28
