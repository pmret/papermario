.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ActorExists
/* 19C73C 8026DE5C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19C740 8026DE60 AFB20018 */  sw    $s2, 0x18($sp)
/* 19C744 8026DE64 0080902D */  daddu $s2, $a0, $zero
/* 19C748 8026DE68 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19C74C 8026DE6C AFB3001C */  sw    $s3, 0x1c($sp)
/* 19C750 8026DE70 AFB10014 */  sw    $s1, 0x14($sp)
/* 19C754 8026DE74 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C758 8026DE78 8E51000C */  lw    $s1, 0xc($s2)
/* 19C75C 8026DE7C 3C13800E */  lui   $s3, 0x800e
/* 19C760 8026DE80 8E73C14C */  lw    $s3, -0x3eb4($s3)
/* 19C764 8026DE84 8E250000 */  lw    $a1, ($s1)
/* 19C768 8026DE88 0C0B1EAF */  jal   get_variable
/* 19C76C 8026DE8C 26310004 */   addiu $s1, $s1, 4
/* 19C770 8026DE90 0040802D */  daddu $s0, $v0, $zero
/* 19C774 8026DE94 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C778 8026DE98 16020002 */  bne   $s0, $v0, .L8026DEA4
/* 19C77C 8026DE9C 00000000 */   nop   
/* 19C780 8026DEA0 8E500148 */  lw    $s0, 0x148($s2)
.L8026DEA4:
/* 19C784 8026DEA4 0C09A75B */  jal   get_actor
/* 19C788 8026DEA8 0200202D */   daddu $a0, $s0, $zero
/* 19C78C 8026DEAC 0002302B */  sltu  $a2, $zero, $v0
/* 19C790 8026DEB0 24020100 */  addiu $v0, $zero, 0x100
/* 19C794 8026DEB4 16020003 */  bne   $s0, $v0, .L8026DEC4
/* 19C798 8026DEB8 00000000 */   nop   
/* 19C79C 8026DEBC 52600001 */  beql  $s3, $zero, .L8026DEC4
/* 19C7A0 8026DEC0 0000302D */   daddu $a2, $zero, $zero
.L8026DEC4:
/* 19C7A4 8026DEC4 8E250000 */  lw    $a1, ($s1)
/* 19C7A8 8026DEC8 0C0B2026 */  jal   set_variable
/* 19C7AC 8026DECC 0240202D */   daddu $a0, $s2, $zero
/* 19C7B0 8026DED0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19C7B4 8026DED4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19C7B8 8026DED8 8FB20018 */  lw    $s2, 0x18($sp)
/* 19C7BC 8026DEDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 19C7C0 8026DEE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C7C4 8026DEE4 24020002 */  addiu $v0, $zero, 2
/* 19C7C8 8026DEE8 03E00008 */  jr    $ra
/* 19C7CC 8026DEEC 27BD0028 */   addiu $sp, $sp, 0x28
