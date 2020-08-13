.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel deduct_current_move_fp
/* 1924A8 80263BC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1924AC 80263BCC 3C04800E */  lui   $a0, 0x800e
/* 1924B0 80263BD0 2484C070 */  addiu $a0, $a0, -0x3f90
/* 1924B4 80263BD4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1924B8 80263BD8 AFB20018 */  sw    $s2, 0x18($sp)
/* 1924BC 80263BDC AFB10014 */  sw    $s1, 0x14($sp)
/* 1924C0 80263BE0 AFB00010 */  sw    $s0, 0x10($sp)
/* 1924C4 80263BE4 8483017C */  lh    $v1, 0x17c($a0)
/* 1924C8 80263BE8 3C128011 */  lui   $s2, 0x8011
/* 1924CC 80263BEC 2652F290 */  addiu $s2, $s2, -0xd70
/* 1924D0 80263BF0 00031080 */  sll   $v0, $v1, 2
/* 1924D4 80263BF4 00431021 */  addu  $v0, $v0, $v1
/* 1924D8 80263BF8 00021080 */  sll   $v0, $v0, 2
/* 1924DC 80263BFC 3C108009 */  lui   $s0, 0x8009
/* 1924E0 80263C00 02028021 */  addu  $s0, $s0, $v0
/* 1924E4 80263C04 8210F071 */  lb    $s0, -0xf8f($s0)
/* 1924E8 80263C08 8C9100D8 */  lw    $s1, 0xd8($a0)
/* 1924EC 80263C0C 1200000B */  beqz  $s0, .L80263C3C
/* 1924F0 80263C10 0220202D */   daddu $a0, $s1, $zero
/* 1924F4 80263C14 0C099CAB */  jal   heroes_is_ability_active
/* 1924F8 80263C18 24050018 */   addiu $a1, $zero, 0x18
/* 1924FC 80263C1C 02028023 */  subu  $s0, $s0, $v0
/* 192500 80263C20 0220202D */  daddu $a0, $s1, $zero
/* 192504 80263C24 0C099CAB */  jal   heroes_is_ability_active
/* 192508 80263C28 24050026 */   addiu $a1, $zero, 0x26
/* 19250C 80263C2C 00021040 */  sll   $v0, $v0, 1
/* 192510 80263C30 02028023 */  subu  $s0, $s0, $v0
/* 192514 80263C34 5A000001 */  blezl $s0, .L80263C3C
/* 192518 80263C38 24100001 */   addiu $s0, $zero, 1
.L80263C3C:
/* 19251C 80263C3C 92420005 */  lbu   $v0, 5($s2)
/* 192520 80263C40 00501023 */  subu  $v0, $v0, $s0
/* 192524 80263C44 A2420005 */  sb    $v0, 5($s2)
/* 192528 80263C48 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19252C 80263C4C 8FB20018 */  lw    $s2, 0x18($sp)
/* 192530 80263C50 8FB10014 */  lw    $s1, 0x14($sp)
/* 192534 80263C54 8FB00010 */  lw    $s0, 0x10($sp)
/* 192538 80263C58 03E00008 */  jr    $ra
/* 19253C 80263C5C 27BD0020 */   addiu $sp, $sp, 0x20

