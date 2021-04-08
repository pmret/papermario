.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F2E8
/* 4A6E8 8006F2E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A6EC 8006F2EC AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A6F0 8006F2F0 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A6F4 8006F2F4 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A6F8 8006F2F8 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A6FC 8006F2FC 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A700 8006F300 3C010001 */  lui       $at, 1
/* 4A704 8006F304 00A17025 */  or        $t6, $a1, $at
/* 4A708 8006F308 01C02825 */  or        $a1, $t6, $zero
/* 4A70C 8006F30C 3C063C00 */  lui       $a2, 0x3c00
/* 4A710 8006F310 0C01834C */  jal       osEPiWriteIo
/* 4A714 8006F314 00000000 */   nop
/* 4A718 8006F318 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A71C 8006F31C 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A720 8006F320 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A724 8006F324 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A728 8006F328 3C010001 */  lui       $at, 1
/* 4A72C 8006F32C 00A17825 */  or        $t7, $a1, $at
/* 4A730 8006F330 01E02825 */  or        $a1, $t7, $zero
/* 4A734 8006F334 3C067800 */  lui       $a2, 0x7800
/* 4A738 8006F338 0C01834C */  jal       osEPiWriteIo
/* 4A73C 8006F33C 00000000 */   nop
.L8006F340:
/* 4A740 8006F340 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A744 8006F344 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A748 8006F348 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A74C 8006F34C 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A750 8006F350 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A754 8006F354 0C018364 */  jal       osEPiReadIo
/* 4A758 8006F358 00000000 */   nop
/* 4A75C 8006F35C 8FB8001C */  lw        $t8, 0x1c($sp)
/* 4A760 8006F360 00000000 */  nop
/* 4A764 8006F364 33190002 */  andi      $t9, $t8, 2
/* 4A768 8006F368 24010002 */  addiu     $at, $zero, 2
/* 4A76C 8006F36C 1321FFF4 */  beq       $t9, $at, .L8006F340
/* 4A770 8006F370 00000000 */   nop
/* 4A774 8006F374 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A778 8006F378 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A77C 8006F37C 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A780 8006F380 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A784 8006F384 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A788 8006F388 0C018364 */  jal       osEPiReadIo
/* 4A78C 8006F38C 00000000 */   nop
/* 4A790 8006F390 0C01BC9F */  jal       func_8006F27C
/* 4A794 8006F394 00000000 */   nop
/* 4A798 8006F398 8FA8001C */  lw        $t0, 0x1c($sp)
/* 4A79C 8006F39C 00000000 */  nop
/* 4A7A0 8006F3A0 310900FF */  andi      $t1, $t0, 0xff
/* 4A7A4 8006F3A4 24010008 */  addiu     $at, $zero, 8
/* 4A7A8 8006F3A8 11210008 */  beq       $t1, $at, .L8006F3CC
/* 4A7AC 8006F3AC 00000000 */   nop
/* 4A7B0 8006F3B0 24010048 */  addiu     $at, $zero, 0x48
/* 4A7B4 8006F3B4 11210005 */  beq       $t1, $at, .L8006F3CC
/* 4A7B8 8006F3B8 00000000 */   nop
/* 4A7BC 8006F3BC 310A0008 */  andi      $t2, $t0, 8
/* 4A7C0 8006F3C0 24010008 */  addiu     $at, $zero, 8
/* 4A7C4 8006F3C4 15410006 */  bne       $t2, $at, .L8006F3E0
/* 4A7C8 8006F3C8 00000000 */   nop
.L8006F3CC:
/* 4A7CC 8006F3CC 00001025 */  or        $v0, $zero, $zero
/* 4A7D0 8006F3D0 10000008 */  b         .L8006F3F4
/* 4A7D4 8006F3D4 00000000 */   nop
/* 4A7D8 8006F3D8 10000004 */  b         .L8006F3EC
/* 4A7DC 8006F3DC 00000000 */   nop
.L8006F3E0:
/* 4A7E0 8006F3E0 2402FFFF */  addiu     $v0, $zero, -1
/* 4A7E4 8006F3E4 10000003 */  b         .L8006F3F4
/* 4A7E8 8006F3E8 00000000 */   nop
.L8006F3EC:
/* 4A7EC 8006F3EC 10000001 */  b         .L8006F3F4
/* 4A7F0 8006F3F0 00000000 */   nop
.L8006F3F4:
/* 4A7F4 8006F3F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A7F8 8006F3F8 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A7FC 8006F3FC 03E00008 */  jr        $ra
/* 4A800 8006F400 00000000 */   nop
