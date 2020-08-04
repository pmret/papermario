.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel lookup_status_chance
/* 194778 80265E98 0080182D */  daddu $v1, $a0, $zero
/* 19477C 80265E9C 8C620000 */  lw    $v0, ($v1)
/* 194780 80265EA0 1040000F */  beqz  $v0, .L80265EE0
/* 194784 80265EA4 0000302D */   daddu $a2, $zero, $zero
/* 194788 80265EA8 24070002 */  addiu $a3, $zero, 2
/* 19478C 80265EAC 24840004 */  addiu $a0, $a0, 4
/* 194790 80265EB0 8C620000 */  lw    $v0, ($v1)
.L80265EB4:
/* 194794 80265EB4 14470002 */  bne   $v0, $a3, .L80265EC0
/* 194798 80265EB8 00000000 */   nop   
/* 19479C 80265EBC 8C860000 */  lw    $a2, ($a0)
.L80265EC0:
/* 1947A0 80265EC0 14450004 */  bne   $v0, $a1, .L80265ED4
/* 1947A4 80265EC4 24630008 */   addiu $v1, $v1, 8
/* 1947A8 80265EC8 8C860000 */  lw    $a2, ($a0)
/* 1947AC 80265ECC 03E00008 */  jr    $ra
/* 1947B0 80265ED0 00C0102D */   daddu $v0, $a2, $zero

.L80265ED4:
/* 1947B4 80265ED4 8C620000 */  lw    $v0, ($v1)
/* 1947B8 80265ED8 1440FFF6 */  bnez  $v0, .L80265EB4
/* 1947BC 80265EDC 24840008 */   addiu $a0, $a0, 8
.L80265EE0:
/* 1947C0 80265EE0 00C0102D */  daddu $v0, $a2, $zero
/* 1947C4 80265EE4 03E00008 */  jr    $ra
/* 1947C8 80265EE8 00000000 */   nop   

