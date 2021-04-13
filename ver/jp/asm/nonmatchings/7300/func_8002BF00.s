.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BF00
/* 7300 8002BF00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7304 8002BF04 3402B71B */  ori       $v0, $zero, 0xb71b
/* 7308 8002BF08 00820018 */  mult      $a0, $v0
/* 730C 8002BF0C 0000202D */  daddu     $a0, $zero, $zero
/* 7310 8002BF10 0000282D */  daddu     $a1, $zero, $zero
/* 7314 8002BF14 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7318 8002BF18 AFB10014 */  sw        $s1, 0x14($sp)
/* 731C 8002BF1C AFB00010 */  sw        $s0, 0x10($sp)
/* 7320 8002BF20 00008010 */  mfhi      $s0
/* 7324 8002BF24 00008812 */  mflo      $s1
/* 7328 8002BF28 0C0198C0 */  jal       func_80066300
/* 732C 8002BF2C 00000000 */   nop
.L8002BF30:
/* 7330 8002BF30 0C01989C */  jal       func_80066270
/* 7334 8002BF34 00000000 */   nop
/* 7338 8002BF38 0040202D */  daddu     $a0, $v0, $zero
/* 733C 8002BF3C 0060282D */  daddu     $a1, $v1, $zero
/* 7340 8002BF40 0090102B */  sltu      $v0, $a0, $s0
/* 7344 8002BF44 1440FFFA */  bnez      $v0, .L8002BF30
/* 7348 8002BF48 00000000 */   nop
/* 734C 8002BF4C 16040003 */  bne       $s0, $a0, .L8002BF5C
/* 7350 8002BF50 00B1102B */   sltu     $v0, $a1, $s1
/* 7354 8002BF54 1440FFF6 */  bnez      $v0, .L8002BF30
/* 7358 8002BF58 00000000 */   nop
.L8002BF5C:
/* 735C 8002BF5C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7360 8002BF60 8FB10014 */  lw        $s1, 0x14($sp)
/* 7364 8002BF64 8FB00010 */  lw        $s0, 0x10($sp)
/* 7368 8002BF68 03E00008 */  jr        $ra
/* 736C 8002BF6C 27BD0020 */   addiu    $sp, $sp, 0x20
