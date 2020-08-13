.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel battle_heap_create
/* 0060A0 8002ACA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0060A4 8002ACA4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0060A8 8002ACA8 3C050002 */  lui   $a1, 2
/* 0060AC 8002ACAC 3C04803E */  lui   $a0, 0x803e
/* 0060B0 8002ACB0 2484A800 */  addiu $a0, $a0, -0x5800
/* 0060B4 8002ACB4 0C00A40C */  jal   _heap_create
/* 0060B8 8002ACB8 34A55800 */   ori   $a1, $a1, 0x5800
/* 0060BC 8002ACBC 0040202D */  daddu $a0, $v0, $zero
/* 0060C0 8002ACC0 2402FFFF */  addiu $v0, $zero, -1
/* 0060C4 8002ACC4 0040182D */  daddu $v1, $v0, $zero
/* 0060C8 8002ACC8 54830001 */  bnel  $a0, $v1, .L8002ACD0
/* 0060CC 8002ACCC 0000102D */   daddu $v0, $zero, $zero
.L8002ACD0:
/* 0060D0 8002ACD0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0060D4 8002ACD4 03E00008 */  jr    $ra
/* 0060D8 8002ACD8 27BD0018 */   addiu $sp, $sp, 0x18


