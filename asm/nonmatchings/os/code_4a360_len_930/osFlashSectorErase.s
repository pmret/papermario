.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osFlashSectorErase
/* 04A824 8006F424 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04A828 8006F428 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04A82C 8006F42C AFA40020 */  sw    $a0, 0x20($sp)
/* 04A830 8006F430 3C04800B */  lui   $a0, 0x800b
/* 04A834 8006F434 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A838 8006F438 3C05800B */  lui   $a1, 0x800b
/* 04A83C 8006F43C 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A840 8006F440 3C010001 */  lui   $at, 1
/* 04A844 8006F444 00A17025 */  or    $t6, $a1, $at
/* 04A848 8006F448 01C02825 */  or    $a1, $t6, $zero
/* 04A84C 8006F44C 8FA60020 */  lw    $a2, 0x20($sp)
/* 04A850 8006F450 3C014B00 */  lui   $at, 0x4b00
/* 04A854 8006F454 00C17825 */  or    $t7, $a2, $at
/* 04A858 8006F458 01E03025 */  or    $a2, $t7, $zero
/* 04A85C 8006F45C 0C018358 */  jal   osEPiWriteIo
/* 04A860 8006F460 00000000 */   nop   
/* 04A864 8006F464 3C04800B */  lui   $a0, 0x800b
/* 04A868 8006F468 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A86C 8006F46C 3C05800B */  lui   $a1, 0x800b
/* 04A870 8006F470 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A874 8006F474 3C010001 */  lui   $at, 1
/* 04A878 8006F478 00A1C025 */  or    $t8, $a1, $at
/* 04A87C 8006F47C 03002825 */  or    $a1, $t8, $zero
/* 04A880 8006F480 3C067800 */  lui   $a2, 0x7800
/* 04A884 8006F484 0C018358 */  jal   osEPiWriteIo
/* 04A888 8006F488 00000000 */   nop   
.L8006F48C:
/* 04A88C 8006F48C 3C04800B */  lui   $a0, 0x800b
/* 04A890 8006F490 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A894 8006F494 3C05800B */  lui   $a1, 0x800b
/* 04A898 8006F498 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A89C 8006F49C 27A6001C */  addiu $a2, $sp, 0x1c
/* 04A8A0 8006F4A0 0C018370 */  jal   osEPiReadIo
/* 04A8A4 8006F4A4 00000000 */   nop   
/* 04A8A8 8006F4A8 8FB9001C */  lw    $t9, 0x1c($sp)
/* 04A8AC 8006F4AC 00000000 */  nop   
/* 04A8B0 8006F4B0 33280002 */  andi  $t0, $t9, 2
/* 04A8B4 8006F4B4 24010002 */  addiu $at, $zero, 2
/* 04A8B8 8006F4B8 1101FFF4 */  beq   $t0, $at, .L8006F48C
/* 04A8BC 8006F4BC 00000000 */   nop   
/* 04A8C0 8006F4C0 3C04800B */  lui   $a0, 0x800b
/* 04A8C4 8006F4C4 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A8C8 8006F4C8 3C05800B */  lui   $a1, 0x800b
/* 04A8CC 8006F4CC 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A8D0 8006F4D0 27A6001C */  addiu $a2, $sp, 0x1c
/* 04A8D4 8006F4D4 0C018370 */  jal   osEPiReadIo
/* 04A8D8 8006F4D8 00000000 */   nop   
/* 04A8DC 8006F4DC 0C01BCA7 */  jal   osFlashClearStatus
/* 04A8E0 8006F4E0 00000000 */   nop   
/* 04A8E4 8006F4E4 8FA9001C */  lw    $t1, 0x1c($sp)
/* 04A8E8 8006F4E8 00000000 */  nop   
/* 04A8EC 8006F4EC 312A00FF */  andi  $t2, $t1, 0xff
/* 04A8F0 8006F4F0 24010008 */  addiu $at, $zero, 8
/* 04A8F4 8006F4F4 11410008 */  beq   $t2, $at, .L8006F518
/* 04A8F8 8006F4F8 00000000 */   nop   
/* 04A8FC 8006F4FC 24010048 */  addiu $at, $zero, 0x48
/* 04A900 8006F500 11410005 */  beq   $t2, $at, .L8006F518
/* 04A904 8006F504 00000000 */   nop   
/* 04A908 8006F508 312B0008 */  andi  $t3, $t1, 8
/* 04A90C 8006F50C 24010008 */  addiu $at, $zero, 8
/* 04A910 8006F510 15610006 */  bne   $t3, $at, .L8006F52C
/* 04A914 8006F514 00000000 */   nop   
.L8006F518:
/* 04A918 8006F518 00001025 */  or    $v0, $zero, $zero
/* 04A91C 8006F51C 10000008 */  b     .L8006F540
/* 04A920 8006F520 00000000 */   nop   
/* 04A924 8006F524 10000004 */  b     .L8006F538
/* 04A928 8006F528 00000000 */   nop   
.L8006F52C:
/* 04A92C 8006F52C 2402FFFF */  addiu $v0, $zero, -1
/* 04A930 8006F530 10000003 */  b     .L8006F540
/* 04A934 8006F534 00000000 */   nop   
.L8006F538:
/* 04A938 8006F538 10000001 */  b     .L8006F540
/* 04A93C 8006F53C 00000000 */   nop   
.L8006F540:
/* 04A940 8006F540 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04A944 8006F544 27BD0020 */  addiu $sp, $sp, 0x20
/* 04A948 8006F548 03E00008 */  jr    $ra
/* 04A94C 8006F54C 00000000 */   nop   

