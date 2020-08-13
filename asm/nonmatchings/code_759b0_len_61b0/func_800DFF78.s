.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800DFF78
/* 079428 800DFF78 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07942C 800DFF7C AFB00010 */  sw    $s0, 0x10($sp)
/* 079430 800DFF80 3C108011 */  lui   $s0, 0x8011
/* 079434 800DFF84 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 079438 800DFF88 AFBF0014 */  sw    $ra, 0x14($sp)
/* 07943C 800DFF8C 0C037F52 */  jal   func_800DFD48
/* 079440 800DFF90 00000000 */   nop   
/* 079444 800DFF94 0040182D */  daddu $v1, $v0, $zero
/* 079448 800DFF98 2402FFFF */  addiu $v0, $zero, -1
/* 07944C 800DFF9C 10620007 */  beq   $v1, $v0, .L800DFFBC
/* 079450 800DFFA0 00000000 */   nop   
/* 079454 800DFFA4 8E020000 */  lw    $v0, ($s0)
/* 079458 800DFFA8 AE0300B8 */  sw    $v1, 0xb8($s0)
/* 07945C 800DFFAC 3C031000 */  lui   $v1, 0x1000
/* 079460 800DFFB0 A60000BC */  sh    $zero, 0xbc($s0)
/* 079464 800DFFB4 00431025 */  or    $v0, $v0, $v1
/* 079468 800DFFB8 AE020000 */  sw    $v0, ($s0)
.L800DFFBC:
/* 07946C 800DFFBC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 079470 800DFFC0 8FB00010 */  lw    $s0, 0x10($sp)
/* 079474 800DFFC4 03E00008 */  jr    $ra
/* 079478 800DFFC8 27BD0018 */   addiu $sp, $sp, 0x18

