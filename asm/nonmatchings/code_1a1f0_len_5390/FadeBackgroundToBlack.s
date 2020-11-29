.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel FadeBackgroundToBlack
/* 1A300 8003EF00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A304 8003EF04 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A308 8003EF08 0080802D */  daddu     $s0, $a0, $zero
/* 1A30C 8003EF0C 10A0000E */  beqz      $a1, .L8003EF48
/* 1A310 8003EF10 AFBF0014 */   sw       $ra, 0x14($sp)
/* 1A314 8003EF14 0C04760B */  jal       func_8011D82C
/* 1A318 8003EF18 24040001 */   addiu    $a0, $zero, 1
/* 1A31C 8003EF1C 0000202D */  daddu     $a0, $zero, $zero
/* 1A320 8003EF20 0080282D */  daddu     $a1, $a0, $zero
/* 1A324 8003EF24 0080302D */  daddu     $a2, $a0, $zero
/* 1A328 8003EF28 0080382D */  daddu     $a3, $a0, $zero
/* 1A32C 8003EF2C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 1A330 8003EF30 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 1A334 8003EF34 24030001 */  addiu     $v1, $zero, 1
/* 1A338 8003EF38 0C046F97 */  jal       set_background_color_blend
/* 1A33C 8003EF3C A0430000 */   sb       $v1, ($v0)
/* 1A340 8003EF40 24020019 */  addiu     $v0, $zero, 0x19
/* 1A344 8003EF44 AE020070 */  sw        $v0, 0x70($s0)
.L8003EF48:
/* 1A348 8003EF48 0000202D */  daddu     $a0, $zero, $zero
/* 1A34C 8003EF4C 0080282D */  daddu     $a1, $a0, $zero
/* 1A350 8003EF50 0080302D */  daddu     $a2, $a0, $zero
/* 1A354 8003EF54 8E030070 */  lw        $v1, 0x70($s0)
/* 1A358 8003EF58 24020019 */  addiu     $v0, $zero, 0x19
/* 1A35C 8003EF5C 00431023 */  subu      $v0, $v0, $v1
/* 1A360 8003EF60 00023880 */  sll       $a3, $v0, 2
/* 1A364 8003EF64 00E23821 */  addu      $a3, $a3, $v0
/* 1A368 8003EF68 00073840 */  sll       $a3, $a3, 1
/* 1A36C 8003EF6C 0C046F97 */  jal       set_background_color_blend
/* 1A370 8003EF70 30E700FE */   andi     $a3, $a3, 0xfe
/* 1A374 8003EF74 8E020070 */  lw        $v0, 0x70($s0)
/* 1A378 8003EF78 2442FFFF */  addiu     $v0, $v0, -1
/* 1A37C 8003EF7C AE020070 */  sw        $v0, 0x70($s0)
/* 1A380 8003EF80 2C420001 */  sltiu     $v0, $v0, 1
/* 1A384 8003EF84 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1A388 8003EF88 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A38C 8003EF8C 00021040 */  sll       $v0, $v0, 1
/* 1A390 8003EF90 03E00008 */  jr        $ra
/* 1A394 8003EF94 27BD0018 */   addiu    $sp, $sp, 0x18
