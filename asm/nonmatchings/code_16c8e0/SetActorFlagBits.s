.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorFlagBits
/* 19B76C 8026CE8C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19B770 8026CE90 AFB20018 */  sw    $s2, 0x18($sp)
/* 19B774 8026CE94 0080902D */  daddu $s2, $a0, $zero
/* 19B778 8026CE98 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19B77C 8026CE9C AFB10014 */  sw    $s1, 0x14($sp)
/* 19B780 8026CEA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B784 8026CEA4 8E50000C */  lw    $s0, 0xc($s2)
/* 19B788 8026CEA8 8E050000 */  lw    $a1, ($s0)
/* 19B78C 8026CEAC 0C0B1EAF */  jal   get_variable
/* 19B790 8026CEB0 26100004 */   addiu $s0, $s0, 4
/* 19B794 8026CEB4 0040882D */  daddu $s1, $v0, $zero
/* 19B798 8026CEB8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B79C 8026CEBC 16220002 */  bne   $s1, $v0, .L8026CEC8
/* 19B7A0 8026CEC0 0240202D */   daddu $a0, $s2, $zero
/* 19B7A4 8026CEC4 8E510148 */  lw    $s1, 0x148($s2)
.L8026CEC8:
/* 19B7A8 8026CEC8 8E050004 */  lw    $a1, 4($s0)
/* 19B7AC 8026CECC 0C0B1EAF */  jal   get_variable
/* 19B7B0 8026CED0 8E120000 */   lw    $s2, ($s0)
/* 19B7B4 8026CED4 0220202D */  daddu $a0, $s1, $zero
/* 19B7B8 8026CED8 0C09A75B */  jal   get_actor
/* 19B7BC 8026CEDC 0040802D */   daddu $s0, $v0, $zero
/* 19B7C0 8026CEE0 12000004 */  beqz  $s0, .L8026CEF4
/* 19B7C4 8026CEE4 0040202D */   daddu $a0, $v0, $zero
/* 19B7C8 8026CEE8 8C820000 */  lw    $v0, ($a0)
/* 19B7CC 8026CEEC 0809B3C0 */  j     .L8026CF00
/* 19B7D0 8026CEF0 00521025 */   or    $v0, $v0, $s2

.L8026CEF4:
/* 19B7D4 8026CEF4 8C820000 */  lw    $v0, ($a0)
/* 19B7D8 8026CEF8 00121827 */  nor   $v1, $zero, $s2
/* 19B7DC 8026CEFC 00431024 */  and   $v0, $v0, $v1
.L8026CF00:
/* 19B7E0 8026CF00 AC820000 */  sw    $v0, ($a0)
/* 19B7E4 8026CF04 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19B7E8 8026CF08 8FB20018 */  lw    $s2, 0x18($sp)
/* 19B7EC 8026CF0C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B7F0 8026CF10 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B7F4 8026CF14 24020002 */  addiu $v0, $zero, 2
/* 19B7F8 8026CF18 03E00008 */  jr    $ra
/* 19B7FC 8026CF1C 27BD0020 */   addiu $sp, $sp, 0x20

