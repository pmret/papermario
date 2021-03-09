.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_800984C8
.word L8003B4AC_168AC, L8003B4BC_168BC, L8003B4CC_168CC, L8003B4DC_168DC, L8003B4EC_168EC, 0

.section .text

glabel func_8003B47C
/* 1687C 8003B47C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 16880 8003B480 AFBF0010 */  sw        $ra, 0x10($sp)
/* 16884 8003B484 808300B4 */  lb        $v1, 0xb4($a0)
/* 16888 8003B488 2C620005 */  sltiu     $v0, $v1, 5
/* 1688C 8003B48C 10400019 */  beqz      $v0, .L8003B4F4
/* 16890 8003B490 00C0382D */   daddu    $a3, $a2, $zero
/* 16894 8003B494 00031080 */  sll       $v0, $v1, 2
/* 16898 8003B498 3C01800A */  lui       $at, %hi(jtbl_800984C8)
/* 1689C 8003B49C 00220821 */  addu      $at, $at, $v0
/* 168A0 8003B4A0 8C2284C8 */  lw        $v0, %lo(jtbl_800984C8)($at)
/* 168A4 8003B4A4 00400008 */  jr        $v0
/* 168A8 8003B4A8 00000000 */   nop
glabel L8003B4AC_168AC
/* 168AC 8003B4AC 0C00ED40 */  jal       func_8003B500
/* 168B0 8003B4B0 00E0302D */   daddu    $a2, $a3, $zero
/* 168B4 8003B4B4 0800ED3D */  j         .L8003B4F4
/* 168B8 8003B4B8 00000000 */   nop
glabel L8003B4BC_168BC
/* 168BC 8003B4BC 0C00ED6D */  jal       func_8003B5B4
/* 168C0 8003B4C0 00E0302D */   daddu    $a2, $a3, $zero
/* 168C4 8003B4C4 0800ED3D */  j         .L8003B4F4
/* 168C8 8003B4C8 00000000 */   nop
glabel L8003B4CC_168CC
/* 168CC 8003B4CC 0C00EE98 */  jal       func_8003BA60
/* 168D0 8003B4D0 0000302D */   daddu    $a2, $zero, $zero
/* 168D4 8003B4D4 0800ED3D */  j         .L8003B4F4
/* 168D8 8003B4D8 00000000 */   nop
glabel L8003B4DC_168DC
/* 168DC 8003B4DC 0C00EE98 */  jal       func_8003BA60
/* 168E0 8003B4E0 24060001 */   addiu    $a2, $zero, 1
/* 168E4 8003B4E4 0800ED3D */  j         .L8003B4F4
/* 168E8 8003B4E8 00000000 */   nop
glabel L8003B4EC_168EC
/* 168EC 8003B4EC 0C00EFB6 */  jal       func_8003BED8
/* 168F0 8003B4F0 00E0302D */   daddu    $a2, $a3, $zero
.L8003B4F4:
/* 168F4 8003B4F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 168F8 8003B4F8 03E00008 */  jr        $ra
/* 168FC 8003B4FC 27BD0018 */   addiu    $sp, $sp, 0x18
