.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel bind_npc_interact
/* 01A01C 8003EC1C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 01A020 8003EC20 AFB3001C */  sw    $s3, 0x1c($sp)
/* 01A024 8003EC24 0080982D */  daddu $s3, $a0, $zero
/* 01A028 8003EC28 AFB40020 */  sw    $s4, 0x20($sp)
/* 01A02C 8003EC2C 00A0A02D */  daddu $s4, $a1, $zero
/* 01A030 8003EC30 AFB20018 */  sw    $s2, 0x18($sp)
/* 01A034 8003EC34 3C12800B */  lui   $s2, 0x800b
/* 01A038 8003EC38 26520F10 */  addiu $s2, $s2, 0xf10
/* 01A03C 8003EC3C AFBF0024 */  sw    $ra, 0x24($sp)
/* 01A040 8003EC40 AFB10014 */  sw    $s1, 0x14($sp)
/* 01A044 8003EC44 AFB00010 */  sw    $s0, 0x10($sp)
/* 01A048 8003EC48 8242001C */  lb    $v0, 0x1c($s2)
/* 01A04C 8003EC4C 1840001E */  blez  $v0, .L8003ECC8
/* 01A050 8003EC50 0000802D */   daddu $s0, $zero, $zero
/* 01A054 8003EC54 0240882D */  daddu $s1, $s2, $zero
.L8003EC58:
/* 01A058 8003EC58 8E260028 */  lw    $a2, 0x28($s1)
/* 01A05C 8003EC5C 50C00015 */  beql  $a2, $zero, .L8003ECB4
/* 01A060 8003EC60 26310004 */   addiu $s1, $s1, 4
/* 01A064 8003EC64 8CC20000 */  lw    $v0, ($a2)
/* 01A068 8003EC68 18400011 */  blez  $v0, .L8003ECB0
/* 01A06C 8003EC6C 0000282D */   daddu $a1, $zero, $zero
/* 01A070 8003EC70 00C0182D */  daddu $v1, $a2, $zero
.L8003EC74:
/* 01A074 8003EC74 8C640004 */  lw    $a0, 4($v1)
/* 01A078 8003EC78 10800008 */  beqz  $a0, .L8003EC9C
/* 01A07C 8003EC7C 00000000 */   nop   
/* 01A080 8003EC80 84820008 */  lh    $v0, 8($a0)
/* 01A084 8003EC84 14530005 */  bne   $v0, $s3, .L8003EC9C
/* 01A088 8003EC88 00000000 */   nop   
/* 01A08C 8003EC8C 0C00FA87 */  jal   bind_enemy_interact
/* 01A090 8003EC90 0280282D */   daddu $a1, $s4, $zero
/* 01A094 8003EC94 0800FB2D */  j     .L8003ECB4
/* 01A098 8003EC98 26310004 */   addiu $s1, $s1, 4

.L8003EC9C:
/* 01A09C 8003EC9C 8CC20000 */  lw    $v0, ($a2)
/* 01A0A0 8003ECA0 24A50001 */  addiu $a1, $a1, 1
/* 01A0A4 8003ECA4 00A2102A */  slt   $v0, $a1, $v0
/* 01A0A8 8003ECA8 1440FFF2 */  bnez  $v0, .L8003EC74
/* 01A0AC 8003ECAC 24630004 */   addiu $v1, $v1, 4
.L8003ECB0:
/* 01A0B0 8003ECB0 26310004 */  addiu $s1, $s1, 4
.L8003ECB4:
/* 01A0B4 8003ECB4 8242001C */  lb    $v0, 0x1c($s2)
/* 01A0B8 8003ECB8 26100001 */  addiu $s0, $s0, 1
/* 01A0BC 8003ECBC 0202102A */  slt   $v0, $s0, $v0
/* 01A0C0 8003ECC0 1440FFE5 */  bnez  $v0, .L8003EC58
/* 01A0C4 8003ECC4 00000000 */   nop   
.L8003ECC8:
/* 01A0C8 8003ECC8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 01A0CC 8003ECCC 8FB40020 */  lw    $s4, 0x20($sp)
/* 01A0D0 8003ECD0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 01A0D4 8003ECD4 8FB20018 */  lw    $s2, 0x18($sp)
/* 01A0D8 8003ECD8 8FB10014 */  lw    $s1, 0x14($sp)
/* 01A0DC 8003ECDC 8FB00010 */  lw    $s0, 0x10($sp)
/* 01A0E0 8003ECE0 03E00008 */  jr    $ra
/* 01A0E4 8003ECE4 27BD0028 */   addiu $sp, $sp, 0x28

