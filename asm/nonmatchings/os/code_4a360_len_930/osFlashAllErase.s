.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osFlashAllErase
/* 4A708 8006F308 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A70C 8006F30C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A710 8006F310 3C04800B */  lui       $a0, 0x800b
/* 4A714 8006F314 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4A718 8006F318 3C05800B */  lui       $a1, 0x800b
/* 4A71C 8006F31C 8CA50C7C */  lw        $a1, 0xc7c($a1)
/* 4A720 8006F320 3C010001 */  lui       $at, 1
/* 4A724 8006F324 00A17025 */  or        $t6, $a1, $at
/* 4A728 8006F328 01C02825 */  or        $a1, $t6, $zero
/* 4A72C 8006F32C 3C063C00 */  lui       $a2, 0x3c00
/* 4A730 8006F330 0C018358 */  jal       osEPiWriteIo
/* 4A734 8006F334 00000000 */   nop      
/* 4A738 8006F338 3C04800B */  lui       $a0, 0x800b
/* 4A73C 8006F33C 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4A740 8006F340 3C05800B */  lui       $a1, 0x800b
/* 4A744 8006F344 8CA50C7C */  lw        $a1, 0xc7c($a1)
/* 4A748 8006F348 3C010001 */  lui       $at, 1
/* 4A74C 8006F34C 00A17825 */  or        $t7, $a1, $at
/* 4A750 8006F350 01E02825 */  or        $a1, $t7, $zero
/* 4A754 8006F354 3C067800 */  lui       $a2, 0x7800
/* 4A758 8006F358 0C018358 */  jal       osEPiWriteIo
/* 4A75C 8006F35C 00000000 */   nop      
.L8006F360:
/* 4A760 8006F360 3C04800B */  lui       $a0, 0x800b
/* 4A764 8006F364 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4A768 8006F368 3C05800B */  lui       $a1, 0x800b
/* 4A76C 8006F36C 8CA50C7C */  lw        $a1, 0xc7c($a1)
/* 4A770 8006F370 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A774 8006F374 0C018370 */  jal       osEPiReadIo
/* 4A778 8006F378 00000000 */   nop      
/* 4A77C 8006F37C 8FB8001C */  lw        $t8, 0x1c($sp)
/* 4A780 8006F380 00000000 */  nop       
/* 4A784 8006F384 33190002 */  andi      $t9, $t8, 2
/* 4A788 8006F388 24010002 */  addiu     $at, $zero, 2
/* 4A78C 8006F38C 1321FFF4 */  beq       $t9, $at, .L8006F360
/* 4A790 8006F390 00000000 */   nop      
/* 4A794 8006F394 3C04800B */  lui       $a0, 0x800b
/* 4A798 8006F398 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4A79C 8006F39C 3C05800B */  lui       $a1, 0x800b
/* 4A7A0 8006F3A0 8CA50C7C */  lw        $a1, 0xc7c($a1)
/* 4A7A4 8006F3A4 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A7A8 8006F3A8 0C018370 */  jal       osEPiReadIo
/* 4A7AC 8006F3AC 00000000 */   nop      
/* 4A7B0 8006F3B0 0C01BCA7 */  jal       osFlashClearStatus
/* 4A7B4 8006F3B4 00000000 */   nop      
/* 4A7B8 8006F3B8 8FA8001C */  lw        $t0, 0x1c($sp)
/* 4A7BC 8006F3BC 00000000 */  nop       
/* 4A7C0 8006F3C0 310900FF */  andi      $t1, $t0, 0xff
/* 4A7C4 8006F3C4 24010008 */  addiu     $at, $zero, 8
/* 4A7C8 8006F3C8 11210008 */  beq       $t1, $at, .L8006F3EC
/* 4A7CC 8006F3CC 00000000 */   nop      
/* 4A7D0 8006F3D0 24010048 */  addiu     $at, $zero, 0x48
/* 4A7D4 8006F3D4 11210005 */  beq       $t1, $at, .L8006F3EC
/* 4A7D8 8006F3D8 00000000 */   nop      
/* 4A7DC 8006F3DC 310A0008 */  andi      $t2, $t0, 8
/* 4A7E0 8006F3E0 24010008 */  addiu     $at, $zero, 8
/* 4A7E4 8006F3E4 15410006 */  bne       $t2, $at, .L8006F400
/* 4A7E8 8006F3E8 00000000 */   nop      
.L8006F3EC:
/* 4A7EC 8006F3EC 00001025 */  or        $v0, $zero, $zero
/* 4A7F0 8006F3F0 10000008 */  b         .L8006F414
/* 4A7F4 8006F3F4 00000000 */   nop      
/* 4A7F8 8006F3F8 10000004 */  b         .L8006F40C
/* 4A7FC 8006F3FC 00000000 */   nop      
.L8006F400:
/* 4A800 8006F400 2402FFFF */  addiu     $v0, $zero, -1
/* 4A804 8006F404 10000003 */  b         .L8006F414
/* 4A808 8006F408 00000000 */   nop      
.L8006F40C:
/* 4A80C 8006F40C 10000001 */  b         .L8006F414
/* 4A810 8006F410 00000000 */   nop      
.L8006F414:
/* 4A814 8006F414 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A818 8006F418 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A81C 8006F41C 03E00008 */  jr        $ra
/* 4A820 8006F420 00000000 */   nop      
