.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel osFlashSectorErase
/* 3D2C0 80061EC0 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 3D2C4 80061EC4 3C03800D */  lui       $v1, %hi(D_800D58B0)
/* 3D2C8 80061EC8 246358B0 */  addiu     $v1, $v1, %lo(D_800D58B0)
/* 3D2CC 80061ECC 3C024B00 */  lui       $v0, (0x4B000000 >> 16)
/* 3D2D0 80061ED0 00823025 */  or        $a2, $a0, $v0
/* 3D2D4 80061ED4 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D2D8 80061ED8 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D2DC 80061EDC 00602021 */  addu      $a0, $v1, $zero
/* 3D2E0 80061EE0 27A20040 */  addiu     $v0, $sp, 0x40
/* 3D2E4 80061EE4 AFB20068 */  sw        $s2, 0x68($sp)
/* 3D2E8 80061EE8 00409021 */  addu      $s2, $v0, $zero
/* 3D2EC 80061EEC 27A20058 */  addiu     $v0, $sp, 0x58
/* 3D2F0 80061EF0 AFB10064 */  sw        $s1, 0x64($sp)
/* 3D2F4 80061EF4 00408821 */  addu      $s1, $v0, $zero
/* 3D2F8 80061EF8 AFB3006C */  sw        $s3, 0x6C($sp)
/* 3D2FC 80061EFC 00609821 */  addu      $s3, $v1, $zero
/* 3D300 80061F00 AFB00060 */  sw        $s0, 0x60($sp)
/* 3D304 80061F04 3C100001 */  lui       $s0, (0x10000 >> 16)
/* 3D308 80061F08 AFBF0070 */  sw        $ra, 0x70($sp)
/* 3D30C 80061F0C 0C018534 */  jal       osEPiWriteIo
/* 3D310 80061F10 00B02825 */   or       $a1, $a1, $s0
/* 3D314 80061F14 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D318 80061F18 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D31C 80061F1C 02602021 */  addu      $a0, $s3, $zero
/* 3D320 80061F20 3C067800 */  lui       $a2, (0x78000000 >> 16)
/* 3D324 80061F24 0C018534 */  jal       osEPiWriteIo
/* 3D328 80061F28 00B02825 */   or       $a1, $a1, $s0
/* 3D32C 80061F2C 02402021 */  addu      $a0, $s2, $zero
/* 3D330 80061F30 02202821 */  addu      $a1, $s1, $zero
/* 3D334 80061F34 0C0198FC */  jal       osCreateMesgQueue
/* 3D338 80061F38 24060001 */   addiu    $a2, $zero, 0x1
.LPAL_80061F3C:
/* 3D33C 80061F3C 00004021 */  addu      $t0, $zero, $zero
/* 3D340 80061F40 00004821 */  addu      $t1, $zero, $zero
/* 3D344 80061F44 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D348 80061F48 24060000 */  addiu     $a2, $zero, 0x0
/* 3D34C 80061F4C 3C070008 */  lui       $a3, (0x8F0D1 >> 16)
/* 3D350 80061F50 34E7F0D1 */  ori       $a3, $a3, (0x8F0D1 & 0xFFFF)
/* 3D354 80061F54 AFA80010 */  sw        $t0, 0x10($sp)
/* 3D358 80061F58 AFA90014 */  sw        $t1, 0x14($sp)
/* 3D35C 80061F5C AFB20018 */  sw        $s2, 0x18($sp)
/* 3D360 80061F60 0C019C70 */  jal       osSetTimer
/* 3D364 80061F64 AFB1001C */   sw       $s1, 0x1C($sp)
/* 3D368 80061F68 02402021 */  addu      $a0, $s2, $zero
/* 3D36C 80061F6C 02202821 */  addu      $a1, $s1, $zero
/* 3D370 80061F70 0C019958 */  jal       osRecvMesg
/* 3D374 80061F74 24060001 */   addiu    $a2, $zero, 0x1
/* 3D378 80061F78 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D37C 80061F7C 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D380 80061F80 02602021 */  addu      $a0, $s3, $zero
/* 3D384 80061F84 0C01854C */  jal       osEPiReadIo
/* 3D388 80061F88 27A6005C */   addiu    $a2, $sp, 0x5C
/* 3D38C 80061F8C 8FA2005C */  lw        $v0, 0x5C($sp)
/* 3D390 80061F90 30420002 */  andi      $v0, $v0, 0x2
/* 3D394 80061F94 1440FFE9 */  bnez      $v0, .LPAL_80061F3C
/* 3D398 80061F98 02602021 */   addu     $a0, $s3, $zero
/* 3D39C 80061F9C 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D3A0 80061FA0 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D3A4 80061FA4 0C01854C */  jal       osEPiReadIo
/* 3D3A8 80061FA8 27A6005C */   addiu    $a2, $sp, 0x5C
/* 3D3AC 80061FAC 0C01B1E4 */  jal       func_PAL_8006C790
/* 3D3B0 80061FB0 00000000 */   nop
/* 3D3B4 80061FB4 8FA4005C */  lw        $a0, 0x5C($sp)
/* 3D3B8 80061FB8 308200FF */  andi      $v0, $a0, 0xFF
/* 3D3BC 80061FBC 38430008 */  xori      $v1, $v0, 0x8
/* 3D3C0 80061FC0 2C630001 */  sltiu     $v1, $v1, 0x1
/* 3D3C4 80061FC4 38420048 */  xori      $v0, $v0, 0x48
/* 3D3C8 80061FC8 2C420001 */  sltiu     $v0, $v0, 0x1
/* 3D3CC 80061FCC 00621825 */  or        $v1, $v1, $v0
/* 3D3D0 80061FD0 14600005 */  bnez      $v1, .LPAL_80061FE8
/* 3D3D4 80061FD4 00001021 */   addu     $v0, $zero, $zero
/* 3D3D8 80061FD8 30820008 */  andi      $v0, $a0, 0x8
/* 3D3DC 80061FDC 14400002 */  bnez      $v0, .LPAL_80061FE8
/* 3D3E0 80061FE0 00001021 */   addu     $v0, $zero, $zero
/* 3D3E4 80061FE4 2402FFFF */  addiu     $v0, $zero, -0x1
.LPAL_80061FE8:
/* 3D3E8 80061FE8 8FBF0070 */  lw        $ra, 0x70($sp)
/* 3D3EC 80061FEC 8FB3006C */  lw        $s3, 0x6C($sp)
/* 3D3F0 80061FF0 8FB20068 */  lw        $s2, 0x68($sp)
/* 3D3F4 80061FF4 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D3F8 80061FF8 8FB00060 */  lw        $s0, 0x60($sp)
/* 3D3FC 80061FFC 03E00008 */  jr        $ra
/* 3D400 80062000 27BD0078 */   addiu    $sp, $sp, 0x78
/* 3D404 80062004 00000000 */  nop
/* 3D408 80062008 00000000 */  nop
/* 3D40C 8006200C 00000000 */  nop
