.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel DisablePulseStone
/* 0F7458 802D2AA8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F745C 802D2AAC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F7460 802D2AB0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7464 802D2AB4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7468 802D2AB8 8C82000C */  lw    $v0, 0xc($a0)
/* 0F746C 802D2ABC 3C108011 */  lui   $s0, 0x8011
/* 0F7470 802D2AC0 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 0F7474 802D2AC4 8C450000 */  lw    $a1, ($v0)
/* 0F7478 802D2AC8 0C0B1EAF */  jal   get_variable
/* 0F747C 802D2ACC 0200882D */   daddu $s1, $s0, $zero
/* 0F7480 802D2AD0 10400005 */  beqz  $v0, .L802D2AE8
/* 0F7484 802D2AD4 2403FF7F */   addiu $v1, $zero, -0x81
/* 0F7488 802D2AD8 8E020004 */  lw    $v0, 4($s0)
/* 0F748C 802D2ADC 00431024 */  and   $v0, $v0, $v1
/* 0F7490 802D2AE0 080B4ABD */  j     .L802D2AF4
/* 0F7494 802D2AE4 AE020004 */   sw    $v0, 4($s0)

.L802D2AE8:
/* 0F7498 802D2AE8 8E220004 */  lw    $v0, 4($s1)
/* 0F749C 802D2AEC 34420080 */  ori   $v0, $v0, 0x80
/* 0F74A0 802D2AF0 AE220004 */  sw    $v0, 4($s1)
.L802D2AF4:
/* 0F74A4 802D2AF4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F74A8 802D2AF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F74AC 802D2AFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F74B0 802D2B00 24020002 */  addiu $v0, $zero, 2
/* 0F74B4 802D2B04 03E00008 */  jr    $ra
/* 0F74B8 802D2B08 27BD0020 */   addiu $sp, $sp, 0x20

