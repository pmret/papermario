.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel BindIdle
/* 1A7374 80278A94 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A7378 80278A98 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A737C 80278A9C 0080882D */  daddu $s1, $a0, $zero
/* 1A7380 80278AA0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A7384 80278AA4 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A7388 80278AA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A738C 80278AAC 8E30000C */  lw    $s0, 0xc($s1)
/* 1A7390 80278AB0 8E050000 */  lw    $a1, ($s0)
/* 1A7394 80278AB4 0C0B1EAF */  jal   get_variable
/* 1A7398 80278AB8 26100004 */   addiu $s0, $s0, 4
/* 1A739C 80278ABC 0040902D */  daddu $s2, $v0, $zero
/* 1A73A0 80278AC0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A73A4 80278AC4 16420002 */  bne   $s2, $v0, .L80278AD0
/* 1A73A8 80278AC8 00000000 */   nop   
/* 1A73AC 80278ACC 8E320148 */  lw    $s2, 0x148($s1)
.L80278AD0:
/* 1A73B0 80278AD0 8E050000 */  lw    $a1, ($s0)
/* 1A73B4 80278AD4 0C0B1EAF */  jal   get_variable
/* 1A73B8 80278AD8 0220202D */   daddu $a0, $s1, $zero
/* 1A73BC 80278ADC 0240202D */  daddu $a0, $s2, $zero
/* 1A73C0 80278AE0 0C09A75B */  jal   get_actor
/* 1A73C4 80278AE4 0040882D */   daddu $s1, $v0, $zero
/* 1A73C8 80278AE8 0040802D */  daddu $s0, $v0, $zero
/* 1A73CC 80278AEC 8E0201D0 */  lw    $v0, 0x1d0($s0)
/* 1A73D0 80278AF0 10400006 */  beqz  $v0, .L80278B0C
/* 1A73D4 80278AF4 0220202D */   daddu $a0, $s1, $zero
/* 1A73D8 80278AF8 8E0401E0 */  lw    $a0, 0x1e0($s0)
/* 1A73DC 80278AFC 0C0B102B */  jal   kill_script_by_ID
/* 1A73E0 80278B00 00000000 */   nop   
/* 1A73E4 80278B04 AE0001D0 */  sw    $zero, 0x1d0($s0)
/* 1A73E8 80278B08 0220202D */  daddu $a0, $s1, $zero
.L80278B0C:
/* 1A73EC 80278B0C 2405000A */  addiu $a1, $zero, 0xa
/* 1A73F0 80278B10 0000302D */  daddu $a2, $zero, $zero
/* 1A73F4 80278B14 0C0B0CF8 */  jal   start_script
/* 1A73F8 80278B18 AE0401C0 */   sw    $a0, 0x1c0($s0)
/* 1A73FC 80278B1C 0040182D */  daddu $v1, $v0, $zero
/* 1A7400 80278B20 AE0301D0 */  sw    $v1, 0x1d0($s0)
/* 1A7404 80278B24 8C640144 */  lw    $a0, 0x144($v1)
/* 1A7408 80278B28 AE0401E0 */  sw    $a0, 0x1e0($s0)
/* 1A740C 80278B2C AC720148 */  sw    $s2, 0x148($v1)
/* 1A7410 80278B30 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A7414 80278B34 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A7418 80278B38 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A741C 80278B3C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A7420 80278B40 24020002 */  addiu $v0, $zero, 2
/* 1A7424 80278B44 03E00008 */  jr    $ra
/* 1A7428 80278B48 27BD0020 */   addiu $sp, $sp, 0x20

