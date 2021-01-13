.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel crash_delay_msec
/* 7340 8002BF40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7344 8002BF44 3402B71B */  ori       $v0, $zero, 0xb71b
/* 7348 8002BF48 00820018 */  mult      $a0, $v0
/* 734C 8002BF4C 0000202D */  daddu     $a0, $zero, $zero
/* 7350 8002BF50 0000282D */  daddu     $a1, $zero, $zero
/* 7354 8002BF54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7358 8002BF58 AFB10014 */  sw        $s1, 0x14($sp)
/* 735C 8002BF5C AFB00010 */  sw        $s0, 0x10($sp)
/* 7360 8002BF60 00008010 */  mfhi      $s0
/* 7364 8002BF64 00008812 */  mflo      $s1
/* 7368 8002BF68 0C0198CC */  jal       osSetTime
/* 736C 8002BF6C 00000000 */   nop
.L8002BF70:
/* 7370 8002BF70 0C0198A8 */  jal       osGetTime
/* 7374 8002BF74 00000000 */   nop
/* 7378 8002BF78 0040202D */  daddu     $a0, $v0, $zero
/* 737C 8002BF7C 0060282D */  daddu     $a1, $v1, $zero
/* 7380 8002BF80 0090102B */  sltu      $v0, $a0, $s0
/* 7384 8002BF84 1440FFFA */  bnez      $v0, .L8002BF70
/* 7388 8002BF88 00000000 */   nop
/* 738C 8002BF8C 16040003 */  bne       $s0, $a0, .L8002BF9C
/* 7390 8002BF90 00B1102B */   sltu     $v0, $a1, $s1
/* 7394 8002BF94 1440FFF6 */  bnez      $v0, .L8002BF70
/* 7398 8002BF98 00000000 */   nop
.L8002BF9C:
/* 739C 8002BF9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 73A0 8002BFA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 73A4 8002BFA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 73A8 8002BFA8 03E00008 */  jr        $ra
/* 73AC 8002BFAC 27BD0020 */   addiu    $sp, $sp, 0x20
