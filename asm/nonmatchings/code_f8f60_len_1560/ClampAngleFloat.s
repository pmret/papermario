.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ClampAngleFloat
/* 0FA464 802D5AB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA468 802D5AB8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA46C 802D5ABC 0080802D */  daddu $s0, $a0, $zero
/* 0FA470 802D5AC0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA474 802D5AC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA478 802D5AC8 8E11000C */  lw    $s1, 0xc($s0)
/* 0FA47C 802D5ACC 0C0B210B */  jal   get_float_variable
/* 0FA480 802D5AD0 8E250000 */   lw    $a1, ($s1)
/* 0FA484 802D5AD4 0C00A6C9 */  jal   clamp_angle
/* 0FA488 802D5AD8 46000306 */   mov.s $f12, $f0
/* 0FA48C 802D5ADC 8E250000 */  lw    $a1, ($s1)
/* 0FA490 802D5AE0 44060000 */  mfc1  $a2, $f0
/* 0FA494 802D5AE4 0C0B2190 */  jal   set_float_variable
/* 0FA498 802D5AE8 0200202D */   daddu $a0, $s0, $zero
/* 0FA49C 802D5AEC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA4A0 802D5AF0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA4A4 802D5AF4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA4A8 802D5AF8 24020002 */  addiu $v0, $zero, 2
/* 0FA4AC 802D5AFC 03E00008 */  jr    $ra
/* 0FA4B0 802D5B00 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA4B4 802D5B04 00000000 */  nop   
/* 0FA4B8 802D5B08 00000000 */  nop   
/* 0FA4BC 802D5B0C 00000000 */  nop   


