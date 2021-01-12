.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_npc_interact
/* 1A01C 8003EC1C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A020 8003EC20 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1A024 8003EC24 0080982D */  daddu     $s3, $a0, $zero
/* 1A028 8003EC28 AFB40020 */  sw        $s4, 0x20($sp)
/* 1A02C 8003EC2C 00A0A02D */  daddu     $s4, $a1, $zero
/* 1A030 8003EC30 AFB20018 */  sw        $s2, 0x18($sp)
/* 1A034 8003EC34 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 1A038 8003EC38 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
/* 1A03C 8003EC3C AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A040 8003EC40 AFB10014 */  sw        $s1, 0x14($sp)
/* 1A044 8003EC44 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A048 8003EC48 8242001C */  lb        $v0, 0x1c($s2)
/* 1A04C 8003EC4C 1840001E */  blez      $v0, .L8003ECC8
/* 1A050 8003EC50 0000802D */   daddu    $s0, $zero, $zero
/* 1A054 8003EC54 0240882D */  daddu     $s1, $s2, $zero
.L8003EC58:
/* 1A058 8003EC58 8E260028 */  lw        $a2, 0x28($s1)
/* 1A05C 8003EC5C 50C00015 */  beql      $a2, $zero, .L8003ECB4
/* 1A060 8003EC60 26310004 */   addiu    $s1, $s1, 4
/* 1A064 8003EC64 8CC20000 */  lw        $v0, ($a2)
/* 1A068 8003EC68 18400011 */  blez      $v0, .L8003ECB0
/* 1A06C 8003EC6C 0000282D */   daddu    $a1, $zero, $zero
/* 1A070 8003EC70 00C0182D */  daddu     $v1, $a2, $zero
.L8003EC74:
/* 1A074 8003EC74 8C640004 */  lw        $a0, 4($v1)
/* 1A078 8003EC78 10800008 */  beqz      $a0, .L8003EC9C
/* 1A07C 8003EC7C 00000000 */   nop
/* 1A080 8003EC80 84820008 */  lh        $v0, 8($a0)
/* 1A084 8003EC84 14530005 */  bne       $v0, $s3, .L8003EC9C
/* 1A088 8003EC88 00000000 */   nop
/* 1A08C 8003EC8C 0C00FA87 */  jal       bind_enemy_interact
/* 1A090 8003EC90 0280282D */   daddu    $a1, $s4, $zero
/* 1A094 8003EC94 0800FB2D */  j         .L8003ECB4
/* 1A098 8003EC98 26310004 */   addiu    $s1, $s1, 4
.L8003EC9C:
/* 1A09C 8003EC9C 8CC20000 */  lw        $v0, ($a2)
/* 1A0A0 8003ECA0 24A50001 */  addiu     $a1, $a1, 1
/* 1A0A4 8003ECA4 00A2102A */  slt       $v0, $a1, $v0
/* 1A0A8 8003ECA8 1440FFF2 */  bnez      $v0, .L8003EC74
/* 1A0AC 8003ECAC 24630004 */   addiu    $v1, $v1, 4
.L8003ECB0:
/* 1A0B0 8003ECB0 26310004 */  addiu     $s1, $s1, 4
.L8003ECB4:
/* 1A0B4 8003ECB4 8242001C */  lb        $v0, 0x1c($s2)
/* 1A0B8 8003ECB8 26100001 */  addiu     $s0, $s0, 1
/* 1A0BC 8003ECBC 0202102A */  slt       $v0, $s0, $v0
/* 1A0C0 8003ECC0 1440FFE5 */  bnez      $v0, .L8003EC58
/* 1A0C4 8003ECC4 00000000 */   nop
.L8003ECC8:
/* 1A0C8 8003ECC8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A0CC 8003ECCC 8FB40020 */  lw        $s4, 0x20($sp)
/* 1A0D0 8003ECD0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A0D4 8003ECD4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A0D8 8003ECD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A0DC 8003ECDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A0E0 8003ECE0 03E00008 */  jr        $ra
/* 1A0E4 8003ECE4 27BD0028 */   addiu    $sp, $sp, 0x28
