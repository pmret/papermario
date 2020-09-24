.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_npc_ai
/* 19E84 8003EA84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19E88 8003EA88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19E8C 8003EA8C 0080982D */  daddu     $s3, $a0, $zero
/* 19E90 8003EA90 AFB40020 */  sw        $s4, 0x20($sp)
/* 19E94 8003EA94 00A0A02D */  daddu     $s4, $a1, $zero
/* 19E98 8003EA98 AFB20018 */  sw        $s2, 0x18($sp)
/* 19E9C 8003EA9C 3C12800B */  lui       $s2, 0x800b
/* 19EA0 8003EAA0 26520F10 */  addiu     $s2, $s2, 0xf10
/* 19EA4 8003EAA4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19EA8 8003EAA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 19EAC 8003EAAC AFB00010 */  sw        $s0, 0x10($sp)
/* 19EB0 8003EAB0 8242001C */  lb        $v0, 0x1c($s2)
/* 19EB4 8003EAB4 1840001E */  blez      $v0, .L8003EB30
/* 19EB8 8003EAB8 0000802D */   daddu    $s0, $zero, $zero
/* 19EBC 8003EABC 0240882D */  daddu     $s1, $s2, $zero
.L8003EAC0:
/* 19EC0 8003EAC0 8E260028 */  lw        $a2, 0x28($s1)
/* 19EC4 8003EAC4 50C00015 */  beql      $a2, $zero, .L8003EB1C
/* 19EC8 8003EAC8 26310004 */   addiu    $s1, $s1, 4
/* 19ECC 8003EACC 8CC20000 */  lw        $v0, ($a2)
/* 19ED0 8003EAD0 18400011 */  blez      $v0, .L8003EB18
/* 19ED4 8003EAD4 0000282D */   daddu    $a1, $zero, $zero
/* 19ED8 8003EAD8 00C0182D */  daddu     $v1, $a2, $zero
.L8003EADC:
/* 19EDC 8003EADC 8C640004 */  lw        $a0, 4($v1)
/* 19EE0 8003EAE0 10800008 */  beqz      $a0, .L8003EB04
/* 19EE4 8003EAE4 00000000 */   nop      
/* 19EE8 8003EAE8 84820008 */  lh        $v0, 8($a0)
/* 19EEC 8003EAEC 14530005 */  bne       $v0, $s3, .L8003EB04
/* 19EF0 8003EAF0 00000000 */   nop      
/* 19EF4 8003EAF4 0C00FA53 */  jal       bind_enemy_ai
/* 19EF8 8003EAF8 0280282D */   daddu    $a1, $s4, $zero
/* 19EFC 8003EAFC 0800FAC7 */  j         .L8003EB1C
/* 19F00 8003EB00 26310004 */   addiu    $s1, $s1, 4
.L8003EB04:
/* 19F04 8003EB04 8CC20000 */  lw        $v0, ($a2)
/* 19F08 8003EB08 24A50001 */  addiu     $a1, $a1, 1
/* 19F0C 8003EB0C 00A2102A */  slt       $v0, $a1, $v0
/* 19F10 8003EB10 1440FFF2 */  bnez      $v0, .L8003EADC
/* 19F14 8003EB14 24630004 */   addiu    $v1, $v1, 4
.L8003EB18:
/* 19F18 8003EB18 26310004 */  addiu     $s1, $s1, 4
.L8003EB1C:
/* 19F1C 8003EB1C 8242001C */  lb        $v0, 0x1c($s2)
/* 19F20 8003EB20 26100001 */  addiu     $s0, $s0, 1
/* 19F24 8003EB24 0202102A */  slt       $v0, $s0, $v0
/* 19F28 8003EB28 1440FFE5 */  bnez      $v0, .L8003EAC0
/* 19F2C 8003EB2C 00000000 */   nop      
.L8003EB30:
/* 19F30 8003EB30 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19F34 8003EB34 8FB40020 */  lw        $s4, 0x20($sp)
/* 19F38 8003EB38 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19F3C 8003EB3C 8FB20018 */  lw        $s2, 0x18($sp)
/* 19F40 8003EB40 8FB10014 */  lw        $s1, 0x14($sp)
/* 19F44 8003EB44 8FB00010 */  lw        $s0, 0x10($sp)
/* 19F48 8003EB48 03E00008 */  jr        $ra
/* 19F4C 8003EB4C 27BD0028 */   addiu    $sp, $sp, 0x28
