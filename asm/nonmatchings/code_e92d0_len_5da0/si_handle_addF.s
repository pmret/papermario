.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_addF
/* 0EA434 802C5A84 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EA438 802C5A88 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA43C 802C5A8C 0080802D */  daddu $s0, $a0, $zero
/* 0EA440 802C5A90 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA444 802C5A94 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA448 802C5A98 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0EA44C 802C5A9C 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA450 802C5AA0 8C450004 */  lw    $a1, 4($v0)
/* 0EA454 802C5AA4 0C0B210B */  jal   get_float_variable
/* 0EA458 802C5AA8 8C510000 */   lw    $s1, ($v0)
/* 0EA45C 802C5AAC 46000506 */  mov.s $f20, $f0
/* 0EA460 802C5AB0 0200202D */  daddu $a0, $s0, $zero
/* 0EA464 802C5AB4 0C0B210B */  jal   get_float_variable
/* 0EA468 802C5AB8 0220282D */   daddu $a1, $s1, $zero
/* 0EA46C 802C5ABC 4600A500 */  add.s $f20, $f20, $f0
/* 0EA470 802C5AC0 0200202D */  daddu $a0, $s0, $zero
/* 0EA474 802C5AC4 4406A000 */  mfc1  $a2, $f20
/* 0EA478 802C5AC8 0C0B2190 */  jal   set_float_variable
/* 0EA47C 802C5ACC 0220282D */   daddu $a1, $s1, $zero
/* 0EA480 802C5AD0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA484 802C5AD4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA488 802C5AD8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA48C 802C5ADC D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0EA490 802C5AE0 24020002 */  addiu $v0, $zero, 2
/* 0EA494 802C5AE4 03E00008 */  jr    $ra
/* 0EA498 802C5AE8 27BD0028 */   addiu $sp, $sp, 0x28

