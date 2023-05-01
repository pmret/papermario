.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel osFlashReadId
/* 3D1C0 80061DC0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3D1C4 80061DC4 AFB40028 */  sw        $s4, 0x28($sp)
/* 3D1C8 80061DC8 0080A021 */  addu      $s4, $a0, $zero
/* 3D1CC 80061DCC AFB5002C */  sw        $s5, 0x2C($sp)
/* 3D1D0 80061DD0 00A0A821 */  addu      $s5, $a1, $zero
/* 3D1D4 80061DD4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D1D8 80061DD8 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3D1DC 80061DDC AFB30024 */  sw        $s3, 0x24($sp)
/* 3D1E0 80061DE0 AFB20020 */  sw        $s2, 0x20($sp)
/* 3D1E4 80061DE4 AFB1001C */  sw        $s1, 0x1C($sp)
/* 3D1E8 80061DE8 0C01B1BC */  jal       func_PAL_8006C6F0
/* 3D1EC 80061DEC AFB00018 */   sw       $s0, 0x18($sp)
/* 3D1F0 80061DF0 3C13800D */  lui       $s3, %hi(D_800D58B0)
/* 3D1F4 80061DF4 267358B0 */  addiu     $s3, $s3, %lo(D_800D58B0)
/* 3D1F8 80061DF8 02602021 */  addu      $a0, $s3, $zero
/* 3D1FC 80061DFC 3C02800D */  lui       $v0, %hi(D_800D58BC)
/* 3D200 80061E00 8C4258BC */  lw        $v0, %lo(D_800D58BC)($v0)
/* 3D204 80061E04 3C06E100 */  lui       $a2, (0xE1000000 >> 16)
/* 3D208 80061E08 3C050001 */  lui       $a1, (0x10000 >> 16)
/* 3D20C 80061E0C 0C018534 */  jal       osEPiWriteIo
/* 3D210 80061E10 00452825 */   or       $a1, $v0, $a1
/* 3D214 80061E14 3C10800B */  lui       $s0, %hi(D_800B0438)
/* 3D218 80061E18 26100438 */  addiu     $s0, $s0, %lo(D_800B0438)
/* 3D21C 80061E1C 02002021 */  addu      $a0, $s0, $zero
/* 3D220 80061E20 3C11800B */  lui       $s1, %hi(D_800AF3A2)
/* 3D224 80061E24 2631F3A2 */  addiu     $s1, $s1, %lo(D_800AF3A2)
/* 3D228 80061E28 3C12800D */  lui       $s2, %hi(D_800D59B0)
/* 3D22C 80061E2C 265259B0 */  addiu     $s2, $s2, %lo(D_800D59B0)
/* 3D230 80061E30 24020008 */  addiu     $v0, $zero, 0x8
/* 3D234 80061E34 A2200000 */  sb        $zero, 0x0($s1)
/* 3D238 80061E38 3C01800B */  lui       $at, %hi(D_800AF3A4)
/* 3D23C 80061E3C AC32F3A4 */  sw        $s2, %lo(D_800AF3A4)($at)
/* 3D240 80061E40 3C01800B */  lui       $at, %hi(D_800AF3A8)
/* 3D244 80061E44 AC30F3A8 */  sw        $s0, %lo(D_800AF3A8)($at)
/* 3D248 80061E48 3C01800B */  lui       $at, %hi(D_800AF3AC)
/* 3D24C 80061E4C AC20F3AC */  sw        $zero, %lo(D_800AF3AC)($at)
/* 3D250 80061E50 3C01800B */  lui       $at, %hi(D_800AF3B0)
/* 3D254 80061E54 AC22F3B0 */  sw        $v0, %lo(D_800AF3B0)($at)
/* 3D258 80061E58 0C018964 */  jal       osInvalDCache
/* 3D25C 80061E5C 24050010 */   addiu    $a1, $zero, 0x10
/* 3D260 80061E60 02602021 */  addu      $a0, $s3, $zero
/* 3D264 80061E64 2625FFFE */  addiu     $a1, $s1, -0x2
/* 3D268 80061E68 0C018564 */  jal       osEPiStartDma
/* 3D26C 80061E6C 00003021 */   addu     $a2, $zero, $zero
/* 3D270 80061E70 02402021 */  addu      $a0, $s2, $zero
/* 3D274 80061E74 00002821 */  addu      $a1, $zero, $zero
/* 3D278 80061E78 0C019958 */  jal       osRecvMesg
/* 3D27C 80061E7C 24060001 */   addiu    $a2, $zero, 0x1
/* 3D280 80061E80 8E020000 */  lw        $v0, 0x0($s0)
/* 3D284 80061E84 AE820000 */  sw        $v0, 0x0($s4)
/* 3D288 80061E88 3C02800B */  lui       $v0, %hi(D_800B043C)
/* 3D28C 80061E8C 8C42043C */  lw        $v0, %lo(D_800B043C)($v0)
/* 3D290 80061E90 AEA20000 */  sw        $v0, 0x0($s5)
/* 3D294 80061E94 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3D298 80061E98 8FB5002C */  lw        $s5, 0x2C($sp)
/* 3D29C 80061E9C 8FB40028 */  lw        $s4, 0x28($sp)
/* 3D2A0 80061EA0 8FB30024 */  lw        $s3, 0x24($sp)
/* 3D2A4 80061EA4 8FB20020 */  lw        $s2, 0x20($sp)
/* 3D2A8 80061EA8 8FB1001C */  lw        $s1, 0x1C($sp)
/* 3D2AC 80061EAC 8FB00018 */  lw        $s0, 0x18($sp)
/* 3D2B0 80061EB0 03E00008 */  jr        $ra
/* 3D2B4 80061EB4 27BD0038 */   addiu    $sp, $sp, 0x38
/* 3D2B8 80061EB8 00000000 */  nop
/* 3D2BC 80061EBC 00000000 */  nop
