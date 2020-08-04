.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetNpcVar
/* 0207BC 800453BC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0207C0 800453C0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0207C4 800453C4 0080982D */  daddu $s3, $a0, $zero
/* 0207C8 800453C8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0207CC 800453CC AFB40020 */  sw    $s4, 0x20($sp)
/* 0207D0 800453D0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0207D4 800453D4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0207D8 800453D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0207DC 800453DC 8E70000C */  lw    $s0, 0xc($s3)
/* 0207E0 800453E0 8E720148 */  lw    $s2, 0x148($s3)
/* 0207E4 800453E4 8E050000 */  lw    $a1, ($s0)
/* 0207E8 800453E8 0C0B1EAF */  jal   get_variable
/* 0207EC 800453EC 26100004 */   addiu $s0, $s0, 4
/* 0207F0 800453F0 0040882D */  daddu $s1, $v0, $zero
/* 0207F4 800453F4 8E050000 */  lw    $a1, ($s0)
/* 0207F8 800453F8 26100004 */  addiu $s0, $s0, 4
/* 0207FC 800453FC 0C0B1EAF */  jal   get_variable
/* 020800 80045400 0260202D */   daddu $a0, $s3, $zero
/* 020804 80045404 0040A02D */  daddu $s4, $v0, $zero
/* 020808 80045408 2402FFFF */  addiu $v0, $zero, -1
/* 02080C 8004540C 16220002 */  bne   $s1, $v0, .L80045418
/* 020810 80045410 8E100000 */   lw    $s0, ($s0)
/* 020814 80045414 86510008 */  lh    $s1, 8($s2)
.L80045418:
/* 020818 80045418 0C00FB3A */  jal   get_enemy
/* 02081C 8004541C 0220202D */   daddu $a0, $s1, $zero
/* 020820 80045420 0260202D */  daddu $a0, $s3, $zero
/* 020824 80045424 00141880 */  sll   $v1, $s4, 2
/* 020828 80045428 00431021 */  addu  $v0, $v0, $v1
/* 02082C 8004542C 8C46006C */  lw    $a2, 0x6c($v0)
/* 020830 80045430 0C0B2026 */  jal   set_variable
/* 020834 80045434 0200282D */   daddu $a1, $s0, $zero
/* 020838 80045438 8FBF0024 */  lw    $ra, 0x24($sp)
/* 02083C 8004543C 8FB40020 */  lw    $s4, 0x20($sp)
/* 020840 80045440 8FB3001C */  lw    $s3, 0x1c($sp)
/* 020844 80045444 8FB20018 */  lw    $s2, 0x18($sp)
/* 020848 80045448 8FB10014 */  lw    $s1, 0x14($sp)
/* 02084C 8004544C 8FB00010 */  lw    $s0, 0x10($sp)
/* 020850 80045450 24020002 */  addiu $v0, $zero, 2
/* 020854 80045454 03E00008 */  jr    $ra
/* 020858 80045458 27BD0028 */   addiu $sp, $sp, 0x28

