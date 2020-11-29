.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osFlashClearStatus
/* 4A69C 8006F29C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4A6A0 8006F2A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A6A4 8006F2A4 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4A6A8 8006F2A8 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4A6AC 8006F2AC 3C05800B */  lui       $a1, %hi(D_800B0C7C)
/* 4A6B0 8006F2B0 8CA50C7C */  lw        $a1, %lo(D_800B0C7C)($a1)
/* 4A6B4 8006F2B4 3C010001 */  lui       $at, 1
/* 4A6B8 8006F2B8 00A17025 */  or        $t6, $a1, $at
/* 4A6BC 8006F2BC 01C02825 */  or        $a1, $t6, $zero
/* 4A6C0 8006F2C0 3C06D200 */  lui       $a2, 0xd200
/* 4A6C4 8006F2C4 0C018358 */  jal       osEPiWriteIo
/* 4A6C8 8006F2C8 00000000 */   nop      
/* 4A6CC 8006F2CC 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4A6D0 8006F2D0 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4A6D4 8006F2D4 3C05800B */  lui       $a1, %hi(D_800B0C7C)
/* 4A6D8 8006F2D8 8CA50C7C */  lw        $a1, %lo(D_800B0C7C)($a1)
/* 4A6DC 8006F2DC 00003025 */  or        $a2, $zero, $zero
/* 4A6E0 8006F2E0 0C018358 */  jal       osEPiWriteIo
/* 4A6E4 8006F2E4 00000000 */   nop      
/* 4A6E8 8006F2E8 10000003 */  b         .L8006F2F8
/* 4A6EC 8006F2EC 00000000 */   nop      
/* 4A6F0 8006F2F0 10000001 */  b         .L8006F2F8
/* 4A6F4 8006F2F4 00000000 */   nop      
.L8006F2F8:
/* 4A6F8 8006F2F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A6FC 8006F2FC 27BD0018 */  addiu     $sp, $sp, 0x18
/* 4A700 8006F300 03E00008 */  jr        $ra
/* 4A704 8006F304 00000000 */   nop      
