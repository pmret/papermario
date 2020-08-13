.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80038880
/* 013C80 80038880 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 013C84 80038884 0000282D */  daddu $a1, $zero, $zero
/* 013C88 80038888 AFBF0010 */  sw    $ra, 0x10($sp)
/* 013C8C 8003888C 0C00E166 */  jal   func_80038598
/* 013C90 80038890 24060001 */   addiu $a2, $zero, 1
/* 013C94 80038894 8FBF0010 */  lw    $ra, 0x10($sp)
/* 013C98 80038898 03E00008 */  jr    $ra
/* 013C9C 8003889C 27BD0018 */   addiu $sp, $sp, 0x18

