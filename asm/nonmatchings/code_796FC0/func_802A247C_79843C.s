.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A247C_79843C
/* 79843C 802A247C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 798440 802A2480 AFB00010 */  sw        $s0, 0x10($sp)
/* 798444 802A2484 0080802D */  daddu     $s0, $a0, $zero
/* 798448 802A2488 10A00003 */  beqz      $a1, .L802A2498
/* 79844C 802A248C AFBF0014 */   sw       $ra, 0x14($sp)
/* 798450 802A2490 240200E6 */  addiu     $v0, $zero, 0xe6
/* 798454 802A2494 AE020070 */  sw        $v0, 0x70($s0)
.L802A2498:
/* 798458 802A2498 0000202D */  daddu     $a0, $zero, $zero
/* 79845C 802A249C 0080282D */  daddu     $a1, $a0, $zero
/* 798460 802A24A0 92070073 */  lbu       $a3, 0x73($s0)
/* 798464 802A24A4 0C046F97 */  jal       set_background_color_blend
/* 798468 802A24A8 0080302D */   daddu    $a2, $a0, $zero
/* 79846C 802A24AC 8E020070 */  lw        $v0, 0x70($s0)
/* 798470 802A24B0 2442FFFB */  addiu     $v0, $v0, -5
/* 798474 802A24B4 AE020070 */  sw        $v0, 0x70($s0)
/* 798478 802A24B8 284200C9 */  slti      $v0, $v0, 0xc9
/* 79847C 802A24BC 14400003 */  bnez      $v0, .L802A24CC
/* 798480 802A24C0 0000202D */   daddu    $a0, $zero, $zero
/* 798484 802A24C4 080A8938 */  j         .L802A24E0
/* 798488 802A24C8 0000102D */   daddu    $v0, $zero, $zero
.L802A24CC:
/* 79848C 802A24CC 0080282D */  daddu     $a1, $a0, $zero
/* 798490 802A24D0 0080302D */  daddu     $a2, $a0, $zero
/* 798494 802A24D4 0C046F97 */  jal       set_background_color_blend
/* 798498 802A24D8 240700C8 */   addiu    $a3, $zero, 0xc8
/* 79849C 802A24DC 24020002 */  addiu     $v0, $zero, 2
.L802A24E0:
/* 7984A0 802A24E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7984A4 802A24E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7984A8 802A24E8 03E00008 */  jr        $ra
/* 7984AC 802A24EC 27BD0018 */   addiu    $sp, $sp, 0x18
