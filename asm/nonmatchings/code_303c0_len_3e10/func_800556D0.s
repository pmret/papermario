.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800556D0
/* 030AD0 800556D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030AD4 800556D4 AFB10014 */  sw    $s1, 0x14($sp)
/* 030AD8 800556D8 0080882D */  daddu $s1, $a0, $zero
/* 030ADC 800556DC AFBF0018 */  sw    $ra, 0x18($sp)
/* 030AE0 800556E0 0C01430C */  jal   func_80050C30
/* 030AE4 800556E4 AFB00010 */   sw    $s0, 0x10($sp)
/* 030AE8 800556E8 0040802D */  daddu $s0, $v0, $zero
/* 030AEC 800556EC 16000005 */  bnez  $s0, .L80055704
/* 030AF0 800556F0 0200102D */   daddu $v0, $s0, $zero
/* 030AF4 800556F4 0220202D */  daddu $a0, $s1, $zero
/* 030AF8 800556F8 0C014319 */  jal   func_80050C64
/* 030AFC 800556FC 24050001 */   addiu $a1, $zero, 1
/* 030B00 80055700 0200102D */  daddu $v0, $s0, $zero
.L80055704:
/* 030B04 80055704 8FBF0018 */  lw    $ra, 0x18($sp)
/* 030B08 80055708 8FB10014 */  lw    $s1, 0x14($sp)
/* 030B0C 8005570C 8FB00010 */  lw    $s0, 0x10($sp)
/* 030B10 80055710 03E00008 */  jr    $ra
/* 030B14 80055714 27BD0020 */   addiu $sp, $sp, 0x20

