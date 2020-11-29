.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F4
/* 16F2D4 802409F4 3C088011 */  lui       $t0, %hi(gPlayerStatus)
/* 16F2D8 802409F8 2508EFC8 */  addiu     $t0, $t0, %lo(gPlayerStatus)
/* 16F2DC 802409FC 0000382D */  daddu     $a3, $zero, $zero
/* 16F2E0 80240A00 3C04800B */  lui       $a0, %hi(gCameras)
/* 16F2E4 80240A04 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 16F2E8 80240A08 3C06802A */  lui       $a2, %hi(D_8029DA50)
/* 16F2EC 80240A0C 24C6DA50 */  addiu     $a2, $a2, %lo(D_8029DA50)
.L80240A10:
/* 16F2F0 80240A10 00C0182D */  daddu     $v1, $a2, $zero
/* 16F2F4 80240A14 0080102D */  daddu     $v0, $a0, $zero
/* 16F2F8 80240A18 24850550 */  addiu     $a1, $a0, 0x550
.L80240A1C:
/* 16F2FC 80240A1C 8C490000 */  lw        $t1, ($v0)
/* 16F300 80240A20 8C4A0004 */  lw        $t2, 4($v0)
/* 16F304 80240A24 8C4B0008 */  lw        $t3, 8($v0)
/* 16F308 80240A28 8C4C000C */  lw        $t4, 0xc($v0)
/* 16F30C 80240A2C AC690000 */  sw        $t1, ($v1)
/* 16F310 80240A30 AC6A0004 */  sw        $t2, 4($v1)
/* 16F314 80240A34 AC6B0008 */  sw        $t3, 8($v1)
/* 16F318 80240A38 AC6C000C */  sw        $t4, 0xc($v1)
/* 16F31C 80240A3C 24420010 */  addiu     $v0, $v0, 0x10
/* 16F320 80240A40 1445FFF6 */  bne       $v0, $a1, .L80240A1C
/* 16F324 80240A44 24630010 */   addiu    $v1, $v1, 0x10
/* 16F328 80240A48 8C490000 */  lw        $t1, ($v0)
/* 16F32C 80240A4C 8C4A0004 */  lw        $t2, 4($v0)
/* 16F330 80240A50 AC690000 */  sw        $t1, ($v1)
/* 16F334 80240A54 AC6A0004 */  sw        $t2, 4($v1)
/* 16F338 80240A58 24840558 */  addiu     $a0, $a0, 0x558
/* 16F33C 80240A5C 24E70001 */  addiu     $a3, $a3, 1
/* 16F340 80240A60 28E20004 */  slti      $v0, $a3, 4
/* 16F344 80240A64 1440FFEA */  bnez      $v0, .L80240A10
/* 16F348 80240A68 24C60558 */   addiu    $a2, $a2, 0x558
/* 16F34C 80240A6C C5000028 */  lwc1      $f0, 0x28($t0)
/* 16F350 80240A70 C502002C */  lwc1      $f2, 0x2c($t0)
/* 16F354 80240A74 C5040030 */  lwc1      $f4, 0x30($t0)
/* 16F358 80240A78 3C01C47A */  lui       $at, %hi(D_C479EFB0)
/* 16F35C 80240A7C 44813000 */  mtc1      $at, $f6
/* 16F360 80240A80 AD000028 */  sw        $zero, 0x28($t0)
/* 16F364 80240A84 AD000030 */  sw        $zero, 0x30($t0)
/* 16F368 80240A88 3C01802A */  lui       $at, %hi(D_8029EFB0)
/* 16F36C 80240A8C E420EFB0 */  swc1      $f0, %lo(D_C479EFB0)($at)
/* 16F370 80240A90 3C01802A */  lui       $at, %hi(D_8029EFB4)
/* 16F374 80240A94 E422EFB4 */  swc1      $f2, %lo(D_8029EFB4)($at)
/* 16F378 80240A98 3C01802A */  lui       $at, %hi(D_8029EFB8)
/* 16F37C 80240A9C E424EFB8 */  swc1      $f4, %lo(D_8029EFB8)($at)
/* 16F380 80240AA0 03E00008 */  jr        $ra
/* 16F384 80240AA4 E506002C */   swc1     $f6, 0x2c($t0)
