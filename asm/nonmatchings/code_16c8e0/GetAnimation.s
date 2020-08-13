.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetAnimation
/* 199B18 8026B238 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199B1C 8026B23C AFB20018 */  sw    $s2, 0x18($sp)
/* 199B20 8026B240 0080902D */  daddu $s2, $a0, $zero
/* 199B24 8026B244 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199B28 8026B248 AFB10014 */  sw    $s1, 0x14($sp)
/* 199B2C 8026B24C AFB00010 */  sw    $s0, 0x10($sp)
/* 199B30 8026B250 8E51000C */  lw    $s1, 0xc($s2)
/* 199B34 8026B254 8E250000 */  lw    $a1, ($s1)
/* 199B38 8026B258 0C0B1EAF */  jal   get_variable
/* 199B3C 8026B25C 26310004 */   addiu $s1, $s1, 4
/* 199B40 8026B260 0040802D */  daddu $s0, $v0, $zero
/* 199B44 8026B264 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199B48 8026B268 16020002 */  bne   $s0, $v0, .L8026B274
/* 199B4C 8026B26C 00000000 */   nop   
/* 199B50 8026B270 8E500148 */  lw    $s0, 0x148($s2)
.L8026B274:
/* 199B54 8026B274 8E250000 */  lw    $a1, ($s1)
/* 199B58 8026B278 26310004 */  addiu $s1, $s1, 4
/* 199B5C 8026B27C 0C0B1EAF */  jal   get_variable
/* 199B60 8026B280 0240202D */   daddu $a0, $s2, $zero
/* 199B64 8026B284 0200202D */  daddu $a0, $s0, $zero
/* 199B68 8026B288 8E310000 */  lw    $s1, ($s1)
/* 199B6C 8026B28C 0C09A75B */  jal   get_actor
/* 199B70 8026B290 0040802D */   daddu $s0, $v0, $zero
/* 199B74 8026B294 0040202D */  daddu $a0, $v0, $zero
/* 199B78 8026B298 0C099117 */  jal   get_actor_part
/* 199B7C 8026B29C 0200282D */   daddu $a1, $s0, $zero
/* 199B80 8026B2A0 10400004 */  beqz  $v0, .L8026B2B4
/* 199B84 8026B2A4 0240202D */   daddu $a0, $s2, $zero
/* 199B88 8026B2A8 8C460088 */  lw    $a2, 0x88($v0)
/* 199B8C 8026B2AC 0C0B2026 */  jal   set_variable
/* 199B90 8026B2B0 0220282D */   daddu $a1, $s1, $zero
.L8026B2B4:
/* 199B94 8026B2B4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199B98 8026B2B8 8FB20018 */  lw    $s2, 0x18($sp)
/* 199B9C 8026B2BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 199BA0 8026B2C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 199BA4 8026B2C4 24020002 */  addiu $v0, $zero, 2
/* 199BA8 8026B2C8 03E00008 */  jr    $ra
/* 199BAC 8026B2CC 27BD0020 */   addiu $sp, $sp, 0x20

