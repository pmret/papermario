.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F27C
/* 4A67C 8006F27C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4A680 8006F280 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A684 8006F284 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A688 8006F288 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A68C 8006F28C 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A690 8006F290 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A694 8006F294 3C010001 */  lui       $at, 1
/* 4A698 8006F298 00A17025 */  or        $t6, $a1, $at
/* 4A69C 8006F29C 01C02825 */  or        $a1, $t6, $zero
/* 4A6A0 8006F2A0 3C06D200 */  lui       $a2, 0xd200
/* 4A6A4 8006F2A4 0C01834C */  jal       func_80060D30
/* 4A6A8 8006F2A8 00000000 */   nop
/* 4A6AC 8006F2AC 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A6B0 8006F2B0 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A6B4 8006F2B4 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A6B8 8006F2B8 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A6BC 8006F2BC 00003025 */  or        $a2, $zero, $zero
/* 4A6C0 8006F2C0 0C01834C */  jal       func_80060D30
/* 4A6C4 8006F2C4 00000000 */   nop
/* 4A6C8 8006F2C8 10000003 */  b         .L8006F2D8
/* 4A6CC 8006F2CC 00000000 */   nop
/* 4A6D0 8006F2D0 10000001 */  b         .L8006F2D8
/* 4A6D4 8006F2D4 00000000 */   nop
.L8006F2D8:
/* 4A6D8 8006F2D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A6DC 8006F2DC 27BD0018 */  addiu     $sp, $sp, 0x18
/* 4A6E0 8006F2E0 03E00008 */  jr        $ra
/* 4A6E4 8006F2E4 00000000 */   nop
