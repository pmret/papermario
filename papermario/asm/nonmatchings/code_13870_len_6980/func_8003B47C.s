.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003B47C
/* 01687C 8003B47C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 016880 8003B480 AFBF0010 */  sw    $ra, 0x10($sp)
/* 016884 8003B484 808300B4 */  lb    $v1, 0xb4($a0)
/* 016888 8003B488 2C620005 */  sltiu $v0, $v1, 5
/* 01688C 8003B48C 10400019 */  beqz  $v0, .L8003B4F4
/* 016890 8003B490 00C0382D */   daddu $a3, $a2, $zero
/* 016894 8003B494 00031080 */  sll   $v0, $v1, 2
/* 016898 8003B498 3C01800A */  lui   $at, 0x800a
/* 01689C 8003B49C 00220821 */  addu  $at, $at, $v0
/* 0168A0 8003B4A0 8C2284C8 */  lw    $v0, -0x7b38($at)
/* 0168A4 8003B4A4 00400008 */  jr    $v0
/* 0168A8 8003B4A8 00000000 */   nop   
/* 0168AC 8003B4AC 0C00ED40 */  jal   func_8003B500
/* 0168B0 8003B4B0 00E0302D */   daddu $a2, $a3, $zero
/* 0168B4 8003B4B4 0800ED3D */  j     .L8003B4F4
/* 0168B8 8003B4B8 00000000 */   nop   

/* 0168BC 8003B4BC 0C00ED6D */  jal   func_8003B5B4
/* 0168C0 8003B4C0 00E0302D */   daddu $a2, $a3, $zero
/* 0168C4 8003B4C4 0800ED3D */  j     .L8003B4F4
/* 0168C8 8003B4C8 00000000 */   nop   

/* 0168CC 8003B4CC 0C00EE98 */  jal   func_8003BA60
/* 0168D0 8003B4D0 0000302D */   daddu $a2, $zero, $zero
/* 0168D4 8003B4D4 0800ED3D */  j     .L8003B4F4
/* 0168D8 8003B4D8 00000000 */   nop   

/* 0168DC 8003B4DC 0C00EE98 */  jal   func_8003BA60
/* 0168E0 8003B4E0 24060001 */   addiu $a2, $zero, 1
/* 0168E4 8003B4E4 0800ED3D */  j     .L8003B4F4
/* 0168E8 8003B4E8 00000000 */   nop   

/* 0168EC 8003B4EC 0C00EFB6 */  jal   func_8003BED8
/* 0168F0 8003B4F0 00E0302D */   daddu $a2, $a3, $zero
.L8003B4F4:
/* 0168F4 8003B4F4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0168F8 8003B4F8 03E00008 */  jr    $ra
/* 0168FC 8003B4FC 27BD0018 */   addiu $sp, $sp, 0x18

